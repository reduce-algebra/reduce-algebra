
/* $destdir/generated-c\u04.c Machine generated C code */

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


/* Code for gcdfd */

static Lisp_Object CC_gcdfd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7, v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdfd");
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
    v7 = v1;
    v8 = v0;
/* end of prologue */
    v9 = qvalue(elt(env, 1)); /* dmode!* */
    v6 = elt(env, 2); /* field */
    v6 = Lflagp(nil, v9, v6);
    env = stack[0];
    if (v6 == nil) goto v10;
    v6 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v6); }

v10:
    v6 = v8;
    {
        popv(1);
        fn = elt(env, 3); /* gcdfd1 */
        return (*qfn2(fn))(qenv(fn), v6, v7);
    }
}



/* Code for pv_add */

static Lisp_Object CC_pv_add(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_add");
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
    v28 = stack[-1];
    if (v28 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v28 = stack[0];
    if (v28 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v31;

v31:
    v28 = stack[-1];
    if (!(v28 == nil)) goto v32;
    v28 = stack[0];
    if (!(v28 == nil)) goto v32;
    v28 = stack[-2];
        popv(4);
        return Lnreverse(nil, v28);

v32:
    v28 = stack[-1];
    if (v28 == nil) goto v33;
    v28 = stack[0];
    if (v28 == nil) goto v33;
    v28 = stack[-1];
    v28 = qcar(v28);
    v29 = qcdr(v28);
    v28 = stack[0];
    v28 = qcar(v28);
    v28 = qcdr(v28);
    if (!(equal(v29, v28))) goto v33;
    v28 = stack[-1];
    v28 = qcar(v28);
    v29 = qcar(v28);
    v28 = stack[0];
    v28 = qcar(v28);
    v28 = qcar(v28);
    v28 = plus2(v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    v30 = v28;
    v29 = v30;
    v28 = (Lisp_Object)1; /* 0 */
    if (v29 == v28) goto v35;
    v28 = stack[-1];
    v28 = qcar(v28);
    v29 = qcdr(v28);
    v28 = stack[-2];
    v28 = acons(v30, v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[-2] = v28;
    goto v35;

v35:
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v31;

v33:
    v28 = stack[-1];
    if (v28 == nil) goto v36;
    v28 = stack[0];
    if (!(v28 == nil)) goto v36;

v37:
    v28 = stack[-1];
    v29 = qcar(v28);
    v28 = stack[-2];
    v28 = cons(v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[-2] = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v31;

v36:
    v28 = stack[-1];
    if (v28 == nil) goto v38;
    v28 = stack[0];
    if (v28 == nil) goto v38;
    v28 = stack[-1];
    v28 = qcar(v28);
    v29 = qcdr(v28);
    v28 = stack[0];
    v28 = qcar(v28);
    v28 = qcdr(v28);
    v28 = (Lisp_Object)greaterp2(v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v28 = v28 ? lisp_true : nil;
    env = stack[-3];
    if (!(v28 == nil)) goto v37;

v38:
    v28 = stack[0];
    v29 = qcar(v28);
    v28 = stack[-2];
    v28 = cons(v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[-2] = v28;
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v31;
/* error exit handlers */
v34:
    popv(4);
    return nil;
}



/* Code for copy */

static Lisp_Object CC_copy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy");
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
    goto v44;

v44:
    v43 = stack[0];
    if (!consp(v43)) goto v45;
    v43 = stack[0];
    v43 = qcar(v43);
    v33 = CC_copy(env, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v43 = stack[-1];
    v43 = cons(v33, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    stack[-1] = v43;
    v43 = stack[0];
    v43 = qcdr(v43);
    stack[0] = v43;
    goto v44;

v45:
    v33 = stack[-1];
    v43 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v33, v43);
    }
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for fkern */

static Lisp_Object CC_fkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v62, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fkern");
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
    v17 = stack[-1];
    if (!consp(v17)) goto v45;
    v17 = stack[-1];
    v62 = qcar(v17);
    v17 = elt(env, 2); /* fkernfn */
    v17 = get(v62, v17);
    env = stack[-3];
    stack[-2] = v17;
    if (v17 == nil) goto v63;
    v62 = stack[-2];
    v17 = stack[-1];
        popv(4);
        return Lapply1(nil, v62, v17);

v63:
    v17 = stack[-1];
    v17 = qcar(v17);
    if (!consp(v17)) goto v64;
    v17 = qvalue(elt(env, 4)); /* exlist!* */
    goto v65;

v65:
    stack[0] = v17;
    v62 = stack[-1];
    v17 = stack[0];
    v17 = Lassoc(nil, v62, v17);
    stack[-2] = v17;
    if (!(v17 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v62 = stack[-1];
    v17 = qvalue(elt(env, 1)); /* nil */
    v17 = list2(v62, v17);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[-2] = v17;
    v62 = stack[-2];
    v17 = stack[0];
    fn = elt(env, 6); /* ordad */
    v17 = (*qfn2(fn))(qenv(fn), v62, v17);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[0] = v17;
    v17 = stack[-1];
    v17 = qcar(v17);
    if (!consp(v17)) goto v67;
    v17 = stack[0];
    qvalue(elt(env, 4)) = v17; /* exlist!* */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v67:
    v17 = stack[-1];
    v17 = qcar(v17);
    v62 = ncons(v17);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v17 = qvalue(elt(env, 5)); /* kprops!* */
    fn = elt(env, 7); /* union */
    v17 = (*qfn2(fn))(qenv(fn), v62, v17);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    qvalue(elt(env, 5)) = v17; /* kprops!* */
    v17 = stack[-1];
    v37 = qcar(v17);
    v62 = elt(env, 3); /* klist */
    v17 = stack[0];
    v17 = Lputprop(nil, 3, v37, v62, v17);
    nil = C_nil;
    if (exception_pending()) goto v66;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v64:
    v17 = stack[-1];
    v62 = qcar(v17);
    v17 = elt(env, 3); /* klist */
    v17 = get(v62, v17);
    env = stack[-3];
    goto v65;

v45:
    v17 = stack[-1];
    v62 = qvalue(elt(env, 1)); /* nil */
    popv(4);
    return list2(v17, v62);
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for mcharg2 */

static Lisp_Object MS_CDECL CC_mcharg2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mcharg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg2");
#endif
    if (stack >= stacklimit)
    {
        push4(v47,v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v40,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-6] = v47;
    stack[-7] = v40;
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    v81 = stack[-9];
    if (v81 == nil) { Lisp_Object res = stack[-7]; popv(12); return onevalue(res); }
    v81 = stack[-9];
    v11 = qcar(v81);
    v81 = stack[-8];
    v81 = qcar(v81);
    fn = elt(env, 2); /* mchk */
    v81 = (*qfn2(fn))(qenv(fn), v11, v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    v11 = v81;
    v81 = stack[-9];
    v81 = qcdr(v81);
    stack[-9] = v81;
    v81 = stack[-8];
    v81 = qcdr(v81);
    stack[-8] = v81;
    v81 = v11;
    stack[-10] = v81;
    goto v43;

v43:
    v81 = stack[-10];
    if (v81 == nil) goto v58;
    v81 = stack[-10];
    v81 = qcar(v81);
    stack[-2] = v81;
    stack[-1] = stack[-9];
    v12 = stack[-2];
    v11 = stack[-8];
    v81 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v12, v11, v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    v11 = stack[-7];
    v81 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v11 = (*qfn2(fn))(qenv(fn), v11, v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    v81 = stack[-6];
    v81 = CC_mcharg2(env, 4, stack[-1], stack[0], v11, v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    stack[-5] = v81;
    v81 = stack[-5];
    fn = elt(env, 5); /* lastpair */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    stack[-4] = v81;
    v81 = stack[-10];
    v81 = qcdr(v81);
    stack[-10] = v81;
    v81 = stack[-4];
    if (!consp(v81)) goto v43;
    else goto v33;

v33:
    v81 = stack[-10];
    if (v81 == nil) { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v81 = stack[-10];
    v81 = qcar(v81);
    stack[-2] = v81;
    stack[-1] = stack[-9];
    v12 = stack[-2];
    v11 = stack[-8];
    v81 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v12, v11, v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    v11 = stack[-7];
    v81 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v11 = (*qfn2(fn))(qenv(fn), v11, v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    v81 = stack[-6];
    v81 = CC_mcharg2(env, 4, stack[-1], stack[0], v11, v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    v81 = Lrplacd(nil, stack[-3], v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    v81 = stack[-4];
    fn = elt(env, 5); /* lastpair */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-11];
    stack[-4] = v81;
    v81 = stack[-10];
    v81 = qcdr(v81);
    stack[-10] = v81;
    goto v33;

v58:
    v81 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v81); }
/* error exit handlers */
v82:
    popv(12);
    return nil;
}



/* Code for subs2 */

static Lisp_Object CC_subs2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v20, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2");
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
    v20 = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v87 = qvalue(elt(env, 1)); /* subfg!* */
    if (v87 == nil) { popv(5); return onevalue(v20); }
    v87 = qvalue(elt(env, 2)); /* !*sub2 */
    if (!(v87 == nil)) goto v5;
    v87 = qvalue(elt(env, 3)); /* powlis1!* */
    if (!(v87 == nil)) goto v5;

v88:
    v87 = v20;
    fn = elt(env, 10); /* exptchksq */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v20 = v87;
    v53 = elt(env, 4); /* slash */
    v87 = elt(env, 5); /* opmtch */
    v87 = get(v53, v87);
    env = stack[-4];
    stack[0] = v87;
    v87 = qvalue(elt(env, 6)); /* !*match */
    if (!(v87 == nil)) goto v61;
    v87 = stack[0];
    if (v87 == nil) { popv(5); return onevalue(v20); }
    else goto v61;

v61:
    v87 = v20;
    v87 = qcar(v87);
    if (v87 == nil) { popv(5); return onevalue(v20); }
    v87 = qvalue(elt(env, 7)); /* !*exp */
    if (!(v87 == nil)) goto v43;
    v87 = qvalue(elt(env, 8)); /* t */
    stack[-3] = v87;
    v87 = qvalue(elt(env, 8)); /* t */
    qvalue(elt(env, 7)) = v87; /* !*exp */
    v87 = v20;
    stack[-2] = v87;
    v87 = v20;
    fn = elt(env, 11); /* resimp */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v20 = v87;
    stack[-1] = v87;
    goto v43;

v43:
    v87 = v20;
    fn = elt(env, 12); /* subs3q */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v20 = v87;
    v87 = stack[-3];
    if (v87 == nil) goto v78;
    v87 = qvalue(elt(env, 9)); /* nil */
    qvalue(elt(env, 7)) = v87; /* !*exp */
    v53 = v20;
    v87 = stack[-1];
    if (!(equal(v53, v87))) goto v78;
    v87 = stack[-2];
    v20 = v87;
    goto v78;

v78:
    v87 = stack[0];
    if (v87 == nil) { popv(5); return onevalue(v20); }
    v87 = v20;
    fn = elt(env, 13); /* subs4q */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v20 = v87;
    { popv(5); return onevalue(v20); }

v5:
    v87 = v20;
    fn = elt(env, 14); /* subs2q */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v20 = v87;
    goto v88;
/* error exit handlers */
v89:
    popv(5);
    return nil;
}



/* Code for ibalp_hassimple */

static Lisp_Object CC_ibalp_hassimple(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_hassimple");
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
    v91 = v0;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v91;
    goto v88;

v88:
    v91 = stack[0];
    if (v91 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v91 = stack[-1];
    if (!(v91 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v91 = stack[0];
    v91 = qcar(v91);
    v92 = qcar(v91);
    v91 = stack[0];
    v91 = qcar(v91);
    v91 = qcdr(v91);
    v91 = qcar(v91);
    fn = elt(env, 2); /* ibalp_commonlenisone */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (v91 == nil) goto v93;
    v91 = stack[0];
    v91 = qcar(v91);
    stack[-1] = v91;
    goto v93;

v93:
    v91 = stack[0];
    v91 = qcdr(v91);
    stack[0] = v91;
    goto v88;
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for indent!* */

static Lisp_Object CC_indentH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indent*");
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
    v46 = stack[0];
    v61 = qvalue(elt(env, 1)); /* t */
    if (!(equal(v46, v61))) goto v44;
    v46 = qvalue(elt(env, 2)); /* indent */
    v61 = qvalue(elt(env, 3)); /* ind */
    v61 = plus2(v46, v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    qvalue(elt(env, 2)) = v61; /* indent */
    goto v44;

v44:
    v61 = stack[0];
    if (!(v61 == nil)) goto v2;
    v46 = qvalue(elt(env, 2)); /* indent */
    v61 = qvalue(elt(env, 3)); /* ind */
    v61 = difference2(v46, v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    qvalue(elt(env, 2)) = v61; /* indent */
    goto v2;

v2:
    v61 = nil;
    { popv(2); return onevalue(v61); }
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for multi_isarb_compl */

static Lisp_Object CC_multi_isarb_compl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_isarb_compl");
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
    v3 = stack[0];
    v3 = Lconsp(nil, v3);
    env = stack[-1];
    if (v3 == nil) goto v44;
    v3 = stack[0];
    if (v3 == nil) goto v44;
    v3 = stack[0];
    v3 = qcar(v3);
    fn = elt(env, 2); /* isarb_compl */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    v3 = stack[0];
    v3 = qcdr(v3);
    v3 = CC_multi_isarb_compl(env, v3);
    nil = C_nil;
    if (exception_pending()) goto v7;
    goto v44;

v44:
    v3 = nil;
    { popv(2); return onevalue(v3); }
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for mcharg1 */

static Lisp_Object MS_CDECL CC_mcharg1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v113, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mcharg1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg1");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v40;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v112 = stack[-3];
    if (!(v112 == nil)) goto v5;
    v112 = stack[-2];
    if (!(v112 == nil)) goto v5;
    v112 = qvalue(elt(env, 1)); /* nil */
    popv(6);
    return ncons(v112);

v5:
    v112 = stack[-3];
    v112 = Llength(nil, v112);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    stack[-4] = v112;
    v112 = stack[-2];
    v112 = Llength(nil, v112);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    stack[0] = v112;
    v113 = stack[-1];
    v112 = elt(env, 2); /* nary */
    v112 = Lflagp(nil, v113, v112);
    env = stack[-5];
    if (v112 == nil) goto v116;
    v113 = stack[-4];
    v112 = (Lisp_Object)33; /* 2 */
    v112 = (Lisp_Object)greaterp2(v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v115;
    v112 = v112 ? lisp_true : nil;
    env = stack[-5];
    if (v112 == nil) goto v116;
    v113 = stack[-4];
    v112 = qvalue(elt(env, 3)); /* matchlength!* */
    v112 = (Lisp_Object)lesseq2(v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v115;
    v112 = v112 ? lisp_true : nil;
    env = stack[-5];
    if (v112 == nil) goto v53;
    v113 = stack[-1];
    v112 = elt(env, 4); /* symmetric */
    v112 = Lflagp(nil, v113, v112);
    env = stack[-5];
    if (v112 == nil) goto v53;
    v114 = stack[-3];
    v113 = stack[-2];
    v112 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); /* mchcomb */
        return (*qfnn(fn))(qenv(fn), 3, v114, v113, v112);
    }

v53:
    v113 = stack[0];
    v112 = (Lisp_Object)33; /* 2 */
    if (v113 == v112) goto v67;
    v112 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v112); }

v67:
    v113 = stack[-1];
    v112 = stack[-3];
    fn = elt(env, 6); /* mkbin */
    v112 = (*qfn2(fn))(qenv(fn), v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    v112 = qcdr(v112);
    stack[-3] = v112;
    v112 = (Lisp_Object)33; /* 2 */
    stack[-4] = v112;
    goto v116;

v116:
    v113 = stack[-4];
    v112 = stack[0];
    if (equal(v113, v112)) goto v37;
    v112 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v112); }

v37:
    v113 = stack[-1];
    v112 = elt(env, 4); /* symmetric */
    v112 = Lflagp(nil, v113, v112);
    env = stack[-5];
    if (v112 == nil) goto v17;
    v114 = stack[-3];
    v113 = stack[-2];
    v112 = stack[-1];
    {
        popv(6);
        fn = elt(env, 7); /* mchsarg */
        return (*qfnn(fn))(qenv(fn), 3, v114, v113, v112);
    }

v17:
    v112 = stack[-2];
    fn = elt(env, 8); /* mtp */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    if (v112 == nil) goto v117;
    v113 = stack[-2];
    v112 = stack[-3];
    fn = elt(env, 9); /* pair */
    v112 = (*qfn2(fn))(qenv(fn), v113, v112);
    nil = C_nil;
    if (exception_pending()) goto v115;
    popv(6);
    return ncons(v112);

v117:
    stack[0] = stack[-3];
    v112 = qvalue(elt(env, 1)); /* nil */
    v113 = ncons(v112);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    v112 = stack[-1];
    {
        Lisp_Object v118 = stack[0];
        Lisp_Object v119 = stack[-2];
        popv(6);
        fn = elt(env, 10); /* mcharg2 */
        return (*qfnn(fn))(qenv(fn), 4, v118, v119, v113, v112);
    }
/* error exit handlers */
v115:
    popv(6);
    return nil;
}



/* Code for fullcopy */

static Lisp_Object CC_fullcopy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fullcopy");
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
    stack[0] = nil;
    goto v44;

v44:
    v36 = stack[-5];
    v36 = Lconsp(nil, v36);
    env = stack[-7];
    if (v36 == nil) goto v88;
    v36 = stack[-5];
    v36 = qcar(v36);
    v123 = CC_fullcopy(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-7];
    v36 = stack[0];
    v36 = cons(v123, v36);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-7];
    stack[0] = v36;
    v36 = stack[-5];
    v36 = qcdr(v36);
    stack[-5] = v36;
    goto v44;

v88:
    v36 = stack[-5];
    v36 = Lsimple_vectorp(nil, v36);
    env = stack[-7];
    if (v36 == nil) goto v125;
    stack[-6] = stack[0];
    v36 = stack[-5];
    v36 = Lupbv(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-7];
    stack[-3] = v36;
    v36 = stack[-3];
    v36 = Lmkvect(nil, v36);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-7];
    stack[-4] = v36;
    v36 = (Lisp_Object)1; /* 0 */
    stack[-2] = v36;
    goto v79;

v79:
    v123 = stack[-3];
    v36 = stack[-2];
    v36 = difference2(v123, v36);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-7];
    v36 = Lminusp(nil, v36);
    env = stack[-7];
    if (v36 == nil) goto v126;
    v36 = stack[-4];
    {
        Lisp_Object v127 = stack[-6];
        popv(8);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v127, v36);
    }

v126:
    stack[-1] = stack[-4];
    stack[0] = stack[-2];
    v123 = stack[-5];
    v36 = stack[-2];
    v36 = *(Lisp_Object *)((char *)v123 + (CELL-TAG_VECTOR) + ((int32_t)v36/(16/CELL)));
    v36 = CC_fullcopy(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v36;
    v36 = stack[-2];
    v36 = add1(v36);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-7];
    stack[-2] = v36;
    goto v79;

v125:
    v123 = stack[0];
    v36 = stack[-5];
    {
        popv(8);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v123, v36);
    }
/* error exit handlers */
v124:
    popv(8);
    return nil;
}



/* Code for copy_mat */

static Lisp_Object CC_copy_mat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy_mat");
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
    goto v44;

v44:
    v33 = stack[0];
    v33 = Lconsp(nil, v33);
    env = stack[-2];
    if (v33 == nil) goto v7;
    v33 = stack[0];
    v33 = qcar(v33);
    v90 = CC_copy_mat(env, v33);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v33 = stack[-1];
    v33 = cons(v90, v33);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    stack[-1] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v44;

v7:
    v90 = stack[-1];
    v33 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v90, v33);
    }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for evlexcomp */

static Lisp_Object CC_evlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v130;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evlexcomp");
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

v44:
    v26 = stack[-1];
    if (v26 == nil) goto v131;
    v26 = stack[0];
    if (v26 == nil) goto v45;
    v26 = stack[-1];
    v130 = qcar(v26);
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = Leqn(nil, v130, v26);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-2];
    if (v26 == nil) goto v33;
    v26 = stack[-1];
    v26 = qcdr(v26);
    stack[-1] = v26;
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v44;

v33:
    v26 = stack[-1];
    v130 = qcar(v26);
    v26 = stack[0];
    v26 = qcar(v26);
    if (((int32_t)(v130)) > ((int32_t)(v26))) goto v128;
    v26 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v26); }

v128:
    v26 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v26); }

v45:
    v26 = elt(env, 1); /* (0) */
    stack[0] = v26;
    goto v44;

v131:
    v26 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v26); }
/* error exit handlers */
v59:
    popv(3);
    return nil;
}



/* Code for chundexp */

static Lisp_Object CC_chundexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chundexp");
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
    v54 = stack[-1];
    v54 = Lexplodec(nil, v54);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    stack[-1] = v54;
    v54 = stack[-1];
    stack[-2] = v54;
    v55 = stack[-1];
    v54 = elt(env, 1); /* !_ */
    if (!consp(v55)) goto v44;
    v55 = qcar(v55);
    if (!(v55 == v54)) goto v44;
    v54 = stack[-1];
    v54 = qcdr(v54);
    if (v54 == nil) goto v44;
    v55 = elt(env, 2); /* !\ */
    v54 = stack[-1];
    v54 = cons(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    stack[-1] = v54;
    goto v44;

v44:
    v54 = stack[-2];
    v54 = qcdr(v54);
    if (v54 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v54 = stack[-2];
    v54 = qcdr(v54);
    v55 = qcar(v54);
    v54 = elt(env, 1); /* !_ */
    if (!(v55 == v54)) goto v91;
    stack[0] = stack[-2];
    v55 = elt(env, 2); /* !\ */
    v54 = stack[-2];
    v54 = qcdr(v54);
    v54 = cons(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    v54 = Lrplacd(nil, stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    v54 = stack[-2];
    v54 = qcdr(v54);
    stack[-2] = v54;
    goto v91;

v91:
    v54 = stack[-2];
    v54 = qcdr(v54);
    stack[-2] = v54;
    goto v44;
/* error exit handlers */
v106:
    popv(4);
    return nil;
}



/* Code for !*physopp!* */

static Lisp_Object CC_HphysoppH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *physopp*");
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
    v88 = stack[0];
    fn = elt(env, 1); /* physopp!* */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-1];
    if (!(v88 == nil)) { popv(2); return onevalue(v88); }
    v88 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* getphystype */
        return (*qfn1(fn))(qenv(fn), v88);
    }
/* error exit handlers */
v132:
    popv(2);
    return nil;
}



/* Code for nonzero!-length */

static Lisp_Object CC_nonzeroKlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v39, v86;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonzero-length");
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
    v39 = v0;
/* end of prologue */

v85:
    v9 = v39;
    if (v9 == nil) goto v63;
    v9 = v39;
    v86 = qcar(v9);
    v9 = (Lisp_Object)1; /* 0 */
    if (v86 == v9) goto v132;
    v9 = v39;
    v9 = qcdr(v9);
    v9 = CC_nonzeroKlength(env, v9);
    errexit();
    return add1(v9);

v132:
    v9 = v39;
    v9 = qcdr(v9);
    v39 = v9;
    goto v85;

v63:
    v9 = (Lisp_Object)1; /* 0 */
    return onevalue(v9);
}



/* Code for mo_compare */

static Lisp_Object CC_mo_compare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v126, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_compare");
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
    v25 = stack[-1];
    v126 = qcdr(v25);
    v25 = stack[0];
    v25 = qcdr(v25);
    fn = elt(env, 3); /* mo!=degcomp */
    v25 = (*qfn2(fn))(qenv(fn), v126, v25);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    v35 = v25;
    v126 = v35;
    v25 = (Lisp_Object)1; /* 0 */
    if (!(v126 == v25)) { popv(3); return onevalue(v35); }
    v25 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_tag */
    v126 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    v25 = elt(env, 2); /* revlex */
    if (v126 == v25) goto v129;
    v25 = stack[-1];
    v126 = qcar(v25);
    v25 = stack[0];
    v25 = qcar(v25);
    fn = elt(env, 5); /* mo!=lexcomp */
    v25 = (*qfn2(fn))(qenv(fn), v126, v25);
    nil = C_nil;
    if (exception_pending()) goto v77;
    goto v8;

v8:
    v35 = v25;
    { popv(3); return onevalue(v35); }

v129:
    v25 = stack[-1];
    v126 = qcar(v25);
    v25 = stack[0];
    v25 = qcar(v25);
    fn = elt(env, 6); /* mo!=revlexcomp */
    v25 = (*qfn2(fn))(qenv(fn), v126, v25);
    nil = C_nil;
    if (exception_pending()) goto v77;
    goto v8;
/* error exit handlers */
v77:
    popv(3);
    return nil;
}



/* Code for cdiv */

static Lisp_Object CC_cdiv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdiv");
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
    v4 = v1;
    v5 = v0;
/* end of prologue */
    v4 = cons(v5, v4);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[0];
    fn = elt(env, 1); /* resimp */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v13;
    v4 = qcar(v4);
    { popv(1); return onevalue(v4); }
/* error exit handlers */
v13:
    popv(1);
    return nil;
}



/* Code for insert_pv */

static Lisp_Object CC_insert_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v43, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv");
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
    v128 = v0;
/* end of prologue */
    v43 = v128;
    v128 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v128 = (*qfn2(fn))(qenv(fn), v43, v128);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    v43 = v128;
    v128 = v43;
    if (v128 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v128 = v43;
    fn = elt(env, 3); /* pv_renorm */
    v33 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    v43 = stack[0];
    v128 = qvalue(elt(env, 1)); /* nil */
    {
        popv(2);
        fn = elt(env, 4); /* insert_pv1 */
        return (*qfnn(fn))(qenv(fn), 3, v33, v43, v128);
    }
/* error exit handlers */
v61:
    popv(2);
    return nil;
}



/* Code for general!-modular!-number */

static Lisp_Object CC_generalKmodularKnumber(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-number");
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
    v33 = stack[0];
    v43 = qvalue(elt(env, 1)); /* current!-modulus */
    v43 = Cremainder(v33, v43);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-1];
    stack[0] = v43;
    v33 = stack[0];
    v43 = (Lisp_Object)1; /* 0 */
    v43 = (Lisp_Object)lessp2(v33, v43);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v43 = v43 ? lisp_true : nil;
    env = stack[-1];
    if (v43 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v33 = stack[0];
    v43 = qvalue(elt(env, 1)); /* current!-modulus */
    v43 = plus2(v33, v43);
    nil = C_nil;
    if (exception_pending()) goto v61;
    stack[0] = v43;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v61:
    popv(2);
    return nil;
}



/* Code for noncomdel */

static Lisp_Object CC_noncomdel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomdel");
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
    v7 = stack[-1];
    fn = elt(env, 1); /* noncomp!* */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    if (v7 == nil) goto v134;
    v8 = stack[-1];
    v7 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* noncomdel1 */
        return (*qfn2(fn))(qenv(fn), v8, v7);
    }

v134:
    v8 = stack[-1];
    v7 = stack[0];
        popv(3);
        return Ldelete(nil, v8, v7);
/* error exit handlers */
v86:
    popv(3);
    return nil;
}



/* Code for ofsf_smwupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smwupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v91, v92, v135, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v91 = v47;
    v92 = v40;
    v135 = v1;
    v80 = v0;
/* end of prologue */
    v129 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v129 == nil) goto v7;
    v129 = v80;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v129, v135, v92, v91);
    }

v7:
    v129 = v80;
    {
        fn = elt(env, 3); /* ofsf_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v129, v135, v92, v91);
    }
}



/* Code for tayexp!-minusp */

static Lisp_Object CC_tayexpKminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v4 = v5;
    if (!consp(v4)) goto v85;
    v4 = v5;
    {
        fn = elt(env, 1); /* rnminusp!: */
        return (*qfn1(fn))(qenv(fn), v4);
    }

v85:
    v4 = v5;
        return Lminusp(nil, v4);
}



/* Code for ibalp_varlt */

static Lisp_Object CC_ibalp_varlt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlt");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v0;
/* end of prologue */
    v132 = v134;
    v134 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* ibalp_varlt1 */
        return (*qfn2(fn))(qenv(fn), v132, v134);
    }
}



/* Code for multi_isarb_int */

static Lisp_Object CC_multi_isarb_int(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_isarb_int");
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
    v3 = stack[0];
    v3 = Lconsp(nil, v3);
    env = stack[-1];
    if (v3 == nil) goto v44;
    v3 = stack[0];
    if (v3 == nil) goto v44;
    v3 = stack[0];
    v3 = qcar(v3);
    fn = elt(env, 2); /* isarb_int */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    v3 = stack[0];
    v3 = qcdr(v3);
    v3 = CC_multi_isarb_int(env, v3);
    nil = C_nil;
    if (exception_pending()) goto v7;
    goto v44;

v44:
    v3 = nil;
    { popv(2); return onevalue(v3); }
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for revlis */

static Lisp_Object CC_revlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revlis");
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
    v80 = v0;
/* end of prologue */
    stack[-3] = v80;
    v80 = stack[-3];
    if (v80 == nil) goto v132;
    v80 = stack[-3];
    v80 = qcar(v80);
    fn = elt(env, 2); /* reval */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[-1] = v80;
    stack[-2] = v80;
    goto v63;

v63:
    v80 = stack[-3];
    v80 = qcdr(v80);
    stack[-3] = v80;
    v80 = stack[-3];
    if (v80 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v80 = stack[-3];
    v80 = qcar(v80);
    fn = elt(env, 2); /* reval */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v80 = Lrplacd(nil, stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v63;

v132:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v80); }
/* error exit handlers */
v136:
    popv(5);
    return nil;
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v6, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evtdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    v3 = (Lisp_Object)1; /* 0 */
    goto v137;

v137:
    v7 = v6;
    if (v7 == nil) return onevalue(v3);
    v7 = v6;
    v7 = qcar(v7);
    v3 = (Lisp_Object)(int32_t)((int32_t)v7 + (int32_t)v3 - TAG_FIXNUM);
    v6 = qcdr(v6);
    goto v137;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsearchinlist");
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

v44:
    v86 = stack[0];
    if (v86 == nil) goto v131;
    v86 = stack[0];
    v86 = qcar(v86);
    v86 = qcdr(v86);
    v128 = qcar(v86);
    v86 = stack[-1];
    fn = elt(env, 2); /* buchvevdivides!? */
    v86 = (*qfn2(fn))(qenv(fn), v128, v86);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-2];
    if (v86 == nil) goto v7;
    v86 = stack[0];
    v86 = qcar(v86);
    { popv(3); return onevalue(v86); }

v7:
    v86 = stack[0];
    v86 = qcdr(v86);
    stack[0] = v86;
    goto v44;

v131:
    v86 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v86); }
/* error exit handlers */
v90:
    popv(3);
    return nil;
}



/* Code for find_item */

static Lisp_Object CC_find_item(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_item");
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

v138:
    v136 = stack[0];
    v136 = qcdr(v136);
    if (v136 == nil) goto v44;
    v27 = stack[-1];
    v136 = stack[0];
    v136 = qcdr(v136);
    v136 = qcar(v136);
    v136 = CC_find_item(env, v27, v136);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-2];
    if (!(v136 == nil)) { popv(3); return onevalue(v136); }
    v136 = stack[0];
    v27 = qcar(v136);
    v136 = stack[-1];
    if (equal(v27, v136)) goto v8;
    v136 = nil;
    goto v7;

v7:
    if (!(v136 == nil)) { popv(3); return onevalue(v136); }
    v27 = stack[-1];
    v136 = stack[0];
    v136 = qcdr(v136);
    v136 = qcdr(v136);
    stack[-1] = v27;
    stack[0] = v136;
    goto v138;

v8:
    v136 = stack[0];
    goto v7;

v44:
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v136); }
/* error exit handlers */
v139:
    popv(3);
    return nil;
}



/* Code for csl_timbf */

static Lisp_Object CC_csl_timbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v83, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csl_timbf");
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
    v109 = stack[-3];
    v109 = qcdr(v109);
    v83 = qcar(v109);
    v109 = stack[-2];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    v109 = times2(v83, v109);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    v84 = v109;
    v83 = v84;
    v109 = (Lisp_Object)1; /* 0 */
    if (v83 == v109) goto v93;
    v83 = v84;
    v109 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v109 = (*qfn2(fn))(qenv(fn), v83, v109);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    v84 = v109;
    stack[-4] = elt(env, 3); /* !:rd!: */
    v109 = v84;
    stack[-1] = qcar(v109);
    v109 = v84;
    stack[0] = qcdr(v109);
    v109 = stack[-3];
    v109 = qcdr(v109);
    v83 = qcdr(v109);
    v109 = stack[-2];
    v109 = qcdr(v109);
    v109 = qcdr(v109);
    v109 = plus2(v83, v109);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    v109 = plus2(stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v141;
    {
        Lisp_Object v105 = stack[-4];
        Lisp_Object v106 = stack[-1];
        popv(6);
        return list2star(v105, v106, v109);
    }

v93:
    v109 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(6); return onevalue(v109); }
/* error exit handlers */
v141:
    popv(6);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v116, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putpline");
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
    v116 = qvalue(elt(env, 1)); /* posn!* */
    v144 = stack[0];
    v144 = qcar(v144);
    v144 = qcdr(v144);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v116 + (int32_t)v144 - TAG_FIXNUM);
    v144 = qvalue(elt(env, 2)); /* nil */
    v116 = Llinelength(nil, v144);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    v144 = qvalue(elt(env, 3)); /* spare!* */
    v144 = (Lisp_Object)(int32_t)((int32_t)v116 - (int32_t)v144 + TAG_FIXNUM);
    v144 = (Lisp_Object)greaterp2(stack[-1], v144);
    nil = C_nil;
    if (exception_pending()) goto v49;
    v144 = v144 ? lisp_true : nil;
    env = stack[-2];
    if (v144 == nil) goto v136;
    v144 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    goto v136;

v136:
    v116 = qvalue(elt(env, 1)); /* posn!* */
    v144 = qvalue(elt(env, 5)); /* orig!* */
    v145 = (Lisp_Object)(int32_t)((int32_t)v116 - (int32_t)v144 + TAG_FIXNUM);
    v116 = qvalue(elt(env, 6)); /* ycoord!* */
    v144 = stack[0];
    v144 = qcar(v144);
    v144 = qcar(v144);
    fn = elt(env, 11); /* update!-pline */
    v116 = (*qfnn(fn))(qenv(fn), 3, v145, v116, v144);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    v144 = qvalue(elt(env, 7)); /* pline!* */
    v144 = Lappend(nil, v116, v144);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    qvalue(elt(env, 7)) = v144; /* pline!* */
    v116 = qvalue(elt(env, 1)); /* posn!* */
    v144 = stack[0];
    v144 = qcar(v144);
    v144 = qcdr(v144);
    v144 = (Lisp_Object)(int32_t)((int32_t)v116 + (int32_t)v144 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v144; /* posn!* */
    v145 = qvalue(elt(env, 8)); /* ymin!* */
    v144 = stack[0];
    v144 = qcdr(v144);
    v116 = qcar(v144);
    v144 = qvalue(elt(env, 6)); /* ycoord!* */
    v144 = (Lisp_Object)(int32_t)((int32_t)v116 + (int32_t)v144 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v144 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    qvalue(elt(env, 8)) = v144; /* ymin!* */
    v145 = qvalue(elt(env, 9)); /* ymax!* */
    v144 = stack[0];
    v144 = qcdr(v144);
    v116 = qcdr(v144);
    v144 = qvalue(elt(env, 6)); /* ycoord!* */
    v144 = (Lisp_Object)(int32_t)((int32_t)v116 + (int32_t)v144 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v144 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    qvalue(elt(env, 9)) = v144; /* ymax!* */
    v144 = nil;
    { popv(3); return onevalue(v144); }
/* error exit handlers */
v49:
    popv(3);
    return nil;
}



/* Code for !:plus */

static Lisp_Object CC_Tplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v140, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :plus");
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
    v140 = v1;
    v133 = v0;
/* end of prologue */
    v78 = v133;
    if (v78 == nil) { popv(1); return onevalue(v140); }
    v78 = v140;
    if (v78 == nil) { popv(1); return onevalue(v133); }
    v78 = v133;
    if (!(!consp(v78))) goto v27;
    v78 = v140;
    if (!(!consp(v78))) goto v27;
    v78 = v133;
    v78 = plus2(v78, v140);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[0];
    v133 = v78;
    v140 = v133;
    v78 = (Lisp_Object)1; /* 0 */
    if (!(v140 == v78)) { popv(1); return onevalue(v133); }
    v78 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v78); }

v27:
    v78 = elt(env, 2); /* plus */
    {
        popv(1);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v133, v140, v78);
    }
/* error exit handlers */
v24:
    popv(1);
    return nil;
}



/* Code for freeofdepl */

static Lisp_Object MS_CDECL CC_freeofdepl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "freeofdepl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofdepl");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v137:
    v92 = stack[-2];
    if (v92 == nil) goto v88;
    v135 = stack[0];
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = qcdr(v92);
    fn = elt(env, 3); /* smember */
    v92 = (*qfn2(fn))(qenv(fn), v135, v92);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    if (v92 == nil) goto v58;
    v92 = stack[-2];
    v92 = qcar(v92);
    v135 = qcar(v92);
    v92 = stack[-1];
    fn = elt(env, 3); /* smember */
    v92 = (*qfn2(fn))(qenv(fn), v135, v92);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    if (v92 == nil) goto v58;
    v92 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v92); }

v58:
    v92 = stack[-2];
    v92 = qcdr(v92);
    stack[-2] = v92;
    goto v137;

v88:
    v92 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v92); }
/* error exit handlers */
v26:
    popv(4);
    return nil;
}



/* Code for idlistp */

static Lisp_Object CC_idlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idlistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */

v138:
    v2 = v32;
    v2 = (v2 == nil ? lisp_true : nil);
    if (!(v2 == nil)) return onevalue(v2);
    v2 = v32;
    if (!consp(v2)) goto v88;
    v2 = v32;
    v2 = qcar(v2);
    if (symbolp(v2)) goto v42;
    v32 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v32);

v42:
    v32 = qcdr(v32);
    goto v138;

v88:
    v32 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v32);
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v79, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroad");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v78 = nil;
    goto v63;

v63:
    v143 = stack[0];
    if (v143 == nil) goto v134;
    v79 = stack[-2];
    v143 = stack[0];
    v143 = qcar(v143);
    if (equal(v79, v143)) goto v6;
    v143 = stack[0];
    v143 = qcar(v143);
    v79 = v78;
    v143 = cons(v143, v79);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-3];
    v78 = v143;
    v143 = stack[0];
    v143 = qcdr(v143);
    stack[0] = v143;
    goto v63;

v6:
    stack[-2] = v78;
    v79 = stack[-1];
    v143 = stack[0];
    v143 = qcdr(v143);
    v143 = Lappend(nil, v79, v143);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-3];
    {
        Lisp_Object v122 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v122, v143);
    }

v134:
    v143 = v78;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v143);
    }
/* error exit handlers */
v110:
    popv(4);
    return nil;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=ecart");
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
    goto v137;

v137:
    v80 = stack[0];
    if (v80 == nil) goto v63;
    v80 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v64 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v80 = stack[-1];
    v80 = cons(v64, v80);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    stack[-1] = v80;
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[0] = v80;
    goto v137;

v63:
    v80 = (Lisp_Object)1; /* 0 */
    v64 = v80;
    goto v131;

v131:
    v80 = stack[-1];
    if (v80 == nil) { popv(3); return onevalue(v64); }
    v80 = stack[-1];
    v80 = qcar(v80);
    v80 = Lmax2(nil, v80, v64);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    v64 = v80;
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v131;
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



/* Code for mchk */

static Lisp_Object CC_mchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchk");
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

v134:
    v187 = stack[-4];
    v186 = stack[-3];
    if (equal(v187, v186)) goto v131;
    v187 = stack[-4];
    v186 = elt(env, 2); /* !*sq */
    if (!consp(v187)) goto v61;
    v187 = qcar(v187);
    if (!(v187 == v186)) goto v61;
    v186 = stack[-4];
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 8); /* prepsqxx */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    stack[-4] = v186;
    goto v134;

v61:
    v187 = stack[-3];
    v186 = elt(env, 2); /* !*sq */
    if (!consp(v187)) goto v33;
    v187 = qcar(v187);
    if (!(v187 == v186)) goto v33;
    v186 = stack[-3];
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 8); /* prepsqxx */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    stack[-3] = v186;
    goto v134;

v33:
    v186 = stack[-3];
    if (!consp(v186)) goto v143;
    v186 = stack[-4];
    if (!consp(v186)) goto v55;
    v186 = stack[-3];
    v187 = qcar(v186);
    v186 = elt(env, 5); /* difference */
    if (v187 == v186) goto v190;
    v186 = stack[-4];
    v187 = qcar(v186);
    v186 = elt(env, 7); /* dname */
    v186 = get(v187, v186);
    env = stack[-6];
    if (!(v186 == nil)) goto v191;
    v186 = stack[-3];
    v187 = qcar(v186);
    v186 = elt(env, 7); /* dname */
    v186 = get(v187, v186);
    env = stack[-6];
    if (!(v186 == nil)) goto v191;
    v186 = stack[-4];
    v187 = qcar(v186);
    v186 = stack[-3];
    v186 = qcar(v186);
    if (v187 == v186) goto v192;
    v186 = stack[-3];
    v187 = qcar(v186);
    v186 = qvalue(elt(env, 3)); /* frlis!* */
    v186 = Lmemq(nil, v187, v186);
    if (v186 == nil) goto v193;
    v186 = stack[-4];
    v188 = qcar(v186);
    v186 = stack[-3];
    v187 = qcar(v186);
    v186 = stack[-4];
    v186 = qcdr(v186);
    stack[0] = Lsubst(nil, 3, v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = stack[-4];
    v188 = qcar(v186);
    v186 = stack[-3];
    v187 = qcar(v186);
    v186 = stack[-3];
    v186 = qcdr(v186);
    v187 = Lsubst(nil, 3, v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = stack[-4];
    v186 = qcar(v186);
    fn = elt(env, 9); /* mcharg */
    v186 = (*qfnn(fn))(qenv(fn), 3, stack[0], v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    stack[-5] = v186;
    v186 = stack[-5];
    if (v186 == nil) goto v194;
    v186 = stack[-5];
    v186 = qcar(v186);
    v187 = stack[-3];
    v188 = qcar(v187);
    v187 = stack[-4];
    v187 = qcar(v187);
    v186 = acons(v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    stack[-1] = v186;
    stack[-2] = v186;
    goto v195;

v195:
    v186 = stack[-5];
    v186 = qcdr(v186);
    stack[-5] = v186;
    v186 = stack[-5];
    if (v186 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v186 = stack[-5];
    v186 = qcar(v186);
    v187 = stack[-3];
    v188 = qcar(v187);
    v187 = stack[-4];
    v187 = qcar(v187);
    v186 = acons(v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = Lrplacd(nil, stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = stack[-1];
    v186 = qcdr(v186);
    stack[-1] = v186;
    goto v195;

v194:
    v186 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v186); }

v193:
    v186 = stack[-4];
    v187 = qcar(v186);
    v186 = elt(env, 4); /* minus */
    if (v187 == v186) goto v196;
    v187 = stack[-4];
    v186 = stack[-3];
    {
        popv(7);
        fn = elt(env, 10); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v187, v186);
    }

v196:
    v186 = stack[-4];
    v186 = qcdr(v186);
    v187 = qcar(v186);
    v186 = stack[-3];
    {
        popv(7);
        fn = elt(env, 11); /* mchkminus */
        return (*qfn2(fn))(qenv(fn), v187, v186);
    }

v192:
    v186 = stack[-4];
    v188 = qcdr(v186);
    v186 = stack[-3];
    v187 = qcdr(v186);
    v186 = stack[-4];
    v186 = qcar(v186);
    {
        popv(7);
        fn = elt(env, 9); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v188, v187, v186);
    }

v191:
    v186 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v186); }

v190:
    stack[-1] = elt(env, 6); /* plus */
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[0] = qcar(v186);
    v187 = elt(env, 4); /* minus */
    v186 = stack[-3];
    v186 = qcdr(v186);
    v186 = qcdr(v186);
    v186 = qcar(v186);
    v186 = list2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = list3(stack[-1], stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    stack[-3] = v186;
    goto v134;

v55:
    v186 = stack[-4];
    if (!(is_number(v186))) goto v197;
    v187 = stack[-4];
    v186 = (Lisp_Object)1; /* 0 */
    v186 = (Lisp_Object)lessp2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v186 = v186 ? lisp_true : nil;
    env = stack[-6];
    if (v186 == nil) goto v197;
    v187 = stack[-3];
    v186 = elt(env, 4); /* minus */
    if (!consp(v187)) goto v197;
    v187 = qcar(v187);
    if (!(v187 == v186)) goto v197;
    stack[0] = elt(env, 4); /* minus */
    v186 = stack[-4];
    v186 = negate(v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = list2(stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    stack[-4] = v186;
    goto v134;

v197:
    v187 = stack[-4];
    v186 = stack[-3];
    {
        popv(7);
        fn = elt(env, 10); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v187, v186);
    }

v143:
    v187 = stack[-3];
    v186 = qvalue(elt(env, 3)); /* frlis!* */
    v186 = Lmemq(nil, v187, v186);
    if (v186 == nil) goto v22;
    v187 = stack[-3];
    v186 = stack[-4];
    v186 = cons(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-6];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    popv(7);
    return ncons(v186);

v22:
    v186 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v186); }

v131:
    v186 = qvalue(elt(env, 1)); /* nil */
    popv(7);
    return ncons(v186);
/* error exit handlers */
v189:
    popv(7);
    return nil;
}



/* Code for pv_sort1 */

static Lisp_Object CC_pv_sort1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort1");
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

v137:
    v143 = stack[-1];
    if (v143 == nil) goto v88;
    v143 = stack[-1];
    v143 = qcar(v143);
    v79 = qcdr(v143);
    v143 = stack[0];
    v143 = qcar(v143);
    v143 = qcdr(v143);
    v143 = (Lisp_Object)lessp2(v79, v143);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v143 = v143 ? lisp_true : nil;
    env = stack[-3];
    if (v143 == nil) goto v129;
    v143 = stack[-1];
    v143 = qcdr(v143);
    stack[-2] = v143;
    v143 = stack[-1];
    v79 = qcar(v143);
    v143 = stack[0];
    v143 = cons(v79, v143);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    stack[0] = v143;
    v143 = stack[-2];
    stack[-1] = v143;
    goto v137;

v129:
    v143 = stack[-1];
    v143 = qcdr(v143);
    stack[-2] = v143;
    v143 = stack[-1];
    v79 = qcar(v143);
    v143 = stack[0];
    fn = elt(env, 1); /* pv_sort2 */
    v143 = (*qfn2(fn))(qenv(fn), v79, v143);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    stack[0] = v143;
    v143 = stack[-2];
    stack[-1] = v143;
    goto v137;

v88:
    v143 = stack[0];
        popv(4);
        return Lnreverse(nil, v143);
/* error exit handlers */
v24:
    popv(4);
    return nil;
}



/* Code for mkrn */

static Lisp_Object CC_mkrn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrn");
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

v132:
    v24 = stack[-1];
    v133 = (Lisp_Object)1; /* 0 */
    v133 = (Lisp_Object)lessp2(v24, v133);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v133 = v133 ? lisp_true : nil;
    env = stack[-4];
    if (v133 == nil) goto v3;
    v133 = stack[-2];
    v133 = negate(v133);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    stack[-2] = v133;
    v133 = stack[-1];
    v133 = negate(v133);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    stack[-1] = v133;
    goto v132;

v3:
    v24 = stack[-2];
    v133 = stack[-1];
    v133 = Lgcd(nil, v24, v133);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    stack[-3] = v133;
    stack[0] = elt(env, 1); /* !:rn!: */
    v24 = stack[-2];
    v133 = stack[-3];
    stack[-2] = quot2(v24, v133);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    v24 = stack[-1];
    v133 = stack[-3];
    v133 = quot2(v24, v133);
    nil = C_nil;
    if (exception_pending()) goto v35;
    {
        Lisp_Object v56 = stack[0];
        Lisp_Object v57 = stack[-2];
        popv(5);
        return list2star(v56, v57, v133);
    }
/* error exit handlers */
v35:
    popv(5);
    return nil;
}



/* Code for gen!-mult!-by!-const!-mod!-p */

static Lisp_Object CC_genKmultKbyKconstKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gen-mult-by-const-mod-p");
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
    v77 = stack[-2];
    if (v77 == nil) goto v44;
    v108 = stack[-1];
    v77 = (Lisp_Object)17; /* 1 */
    if (v108 == v77) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v77 = stack[-2];
    if (!consp(v77)) goto v8;
    v77 = stack[-2];
    v77 = qcar(v77);
    if (!consp(v77)) goto v8;
    v77 = stack[-2];
    v77 = qcar(v77);
    stack[-3] = qcar(v77);
    v77 = stack[-2];
    v77 = qcar(v77);
    v108 = qcdr(v77);
    v77 = stack[-1];
    stack[0] = CC_genKmultKbyKconstKmodKp(env, v108, v77);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    v77 = stack[-2];
    v108 = qcdr(v77);
    v77 = stack[-1];
    v77 = CC_genKmultKbyKconstKmodKp(env, v108, v77);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    {
        Lisp_Object v54 = stack[-3];
        Lisp_Object v55 = stack[0];
        popv(5);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v54, v55, v77);
    }

v8:
    v108 = stack[-2];
    v77 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-times */
    v77 = (*qfn2(fn))(qenv(fn), v108, v77);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v77);
    }

v44:
    v77 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v77); }
/* error exit handlers */
v23:
    popv(5);
    return nil;
}



/* Code for c!:ordexp */

static Lisp_Object CC_cTordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v129, v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v129 = v1;
    v91 = v0;
/* end of prologue */

v44:
    v65 = v91;
    if (v65 == nil) goto v131;
    v65 = v91;
    v92 = qcar(v65);
    v65 = v129;
    v65 = qcar(v65);
    if (equal(v92, v65)) goto v45;
    v65 = v91;
    v65 = qcar(v65);
    v129 = qcar(v129);
    {
        fn = elt(env, 2); /* c!:ordxp */
        return (*qfn2(fn))(qenv(fn), v65, v129);
    }

v45:
    v65 = v91;
    v65 = qcdr(v65);
    v91 = v65;
    v65 = v129;
    v65 = qcdr(v65);
    v129 = v65;
    goto v44;

v131:
    v65 = qvalue(elt(env, 1)); /* t */
    return onevalue(v65);
}



/* Code for times!-mod!-p */

static Lisp_Object CC_timesKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-mod-p");
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
    v119 = stack[-2];
    if (v119 == nil) goto v44;
    v119 = stack[-1];
    if (v119 == nil) goto v44;
    v119 = stack[-2];
    if (!consp(v119)) goto v93;
    v119 = stack[-2];
    v119 = qcar(v119);
    if (!consp(v119)) goto v93;
    v119 = stack[-1];
    if (!consp(v119)) goto v90;
    v119 = stack[-1];
    v119 = qcar(v119);
    if (!consp(v119)) goto v90;
    v119 = stack[-2];
    v119 = qcar(v119);
    v119 = qcar(v119);
    v202 = qcar(v119);
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = qcar(v119);
    v119 = qcar(v119);
    if (equal(v202, v119)) goto v83;
    v119 = stack[-2];
    v119 = qcar(v119);
    v119 = qcar(v119);
    v202 = qcar(v119);
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = qcar(v119);
    v119 = qcar(v119);
    fn = elt(env, 2); /* ordop */
    v119 = (*qfn2(fn))(qenv(fn), v202, v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    if (v119 == nil) goto v99;
    v119 = stack[-2];
    v119 = qcar(v119);
    stack[-3] = qcar(v119);
    v119 = stack[-2];
    v119 = qcar(v119);
    v202 = qcdr(v119);
    v119 = stack[-1];
    stack[0] = CC_timesKmodKp(env, v202, v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    v119 = stack[-2];
    v202 = qcdr(v119);
    v119 = stack[-1];
    v119 = CC_timesKmodKp(env, v202, v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    {
        Lisp_Object v204 = stack[-3];
        Lisp_Object v205 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v204, v205, v119);
    }

v99:
    v119 = stack[-1];
    v119 = qcar(v119);
    stack[-3] = qcar(v119);
    v202 = stack[-2];
    v119 = stack[-1];
    v119 = qcar(v119);
    v119 = qcdr(v119);
    stack[0] = CC_timesKmodKp(env, v202, v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    v202 = stack[-2];
    v119 = stack[-1];
    v119 = qcdr(v119);
    v119 = CC_timesKmodKp(env, v202, v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    {
        Lisp_Object v179 = stack[-3];
        Lisp_Object v206 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v179, v206, v119);
    }

v83:
    v119 = stack[-2];
    v202 = qcar(v119);
    v119 = stack[-1];
    fn = elt(env, 4); /* times!-term!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v202, v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    v119 = stack[-1];
    v202 = qcar(v119);
    v119 = stack[-2];
    v119 = qcdr(v119);
    fn = elt(env, 4); /* times!-term!-mod!-p */
    v119 = (*qfn2(fn))(qenv(fn), v202, v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    fn = elt(env, 5); /* plus!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    v119 = stack[-2];
    v202 = qcdr(v119);
    v119 = stack[-1];
    v119 = qcdr(v119);
    v119 = CC_timesKmodKp(env, v202, v119);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-4];
    {
        Lisp_Object v180 = stack[0];
        popv(5);
        fn = elt(env, 5); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v180, v119);
    }

v90:
    v202 = stack[-2];
    v119 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v202, v119);
    }

v93:
    v202 = stack[-1];
    v119 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v202, v119);
    }

v44:
    v119 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v119); }
/* error exit handlers */
v203:
    popv(5);
    return nil;
}



/* Code for raddf */

static Lisp_Object CC_raddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raddf");
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
    goto v137;

v137:
    v191 = stack[-2];
    if (v191 == nil) goto v4;
    v191 = stack[-1];
    if (v191 == nil) goto v2;
    v191 = stack[-2];
    if (!consp(v191)) goto v65;
    v191 = stack[-2];
    v191 = qcar(v191);
    if (!consp(v191)) goto v65;
    v191 = stack[-1];
    if (!consp(v191)) goto v122;
    v191 = stack[-1];
    v191 = qcar(v191);
    if (!consp(v191)) goto v122;
    v191 = stack[-2];
    v191 = qcar(v191);
    v211 = qcar(v191);
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcar(v191);
    if (equal(v211, v191)) goto v104;
    v191 = stack[-2];
    v191 = qcar(v191);
    v211 = qcar(v191);
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcar(v191);
    fn = elt(env, 1); /* ordpp */
    v191 = (*qfn2(fn))(qenv(fn), v211, v191);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    if (v191 == nil) goto v29;
    v191 = stack[-2];
    v211 = qcar(v191);
    v191 = stack[-3];
    v191 = cons(v211, v191);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    stack[-3] = v191;
    v191 = stack[-2];
    v191 = qcdr(v191);
    stack[-2] = v191;
    goto v137;

v29:
    v191 = stack[-1];
    v211 = qcar(v191);
    v191 = stack[-3];
    v191 = cons(v211, v191);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    stack[-3] = v191;
    v191 = stack[-1];
    v191 = qcdr(v191);
    stack[-1] = v191;
    goto v137;

v104:
    v191 = stack[-2];
    v191 = qcar(v191);
    stack[0] = qcar(v191);
    v191 = stack[-2];
    v191 = qcar(v191);
    v211 = qcdr(v191);
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v211 = CC_raddf(env, v211, v191);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    v191 = stack[-3];
    v191 = acons(stack[0], v211, v191);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    stack[-3] = v191;
    v191 = stack[-2];
    v191 = qcdr(v191);
    stack[-2] = v191;
    v191 = stack[-1];
    v191 = qcdr(v191);
    stack[-1] = v191;
    goto v137;

v122:
    stack[0] = stack[-3];
    v211 = stack[-1];
    v191 = stack[-2];
    fn = elt(env, 2); /* addd */
    v191 = (*qfn2(fn))(qenv(fn), v211, v191);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    {
        Lisp_Object v95 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v95, v191);
    }

v65:
    stack[0] = stack[-3];
    v211 = stack[-2];
    v191 = stack[-1];
    fn = elt(env, 2); /* addd */
    v191 = (*qfn2(fn))(qenv(fn), v211, v191);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-4];
    {
        Lisp_Object v96 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v96, v191);
    }

v2:
    v211 = stack[-3];
    v191 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v211, v191);
    }

v4:
    v211 = stack[-3];
    v191 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v211, v191);
    }
/* error exit handlers */
v212:
    popv(5);
    return nil;
}



/* Code for getrtype2 */

static Lisp_Object CC_getrtype2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v89, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtype2");
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
    v89 = v0;
/* end of prologue */
    v125 = v89;
    v104 = qcar(v125);
    v125 = elt(env, 1); /* rtype */
    v125 = get(v104, v125);
    env = stack[0];
    v104 = v125;
    if (v125 == nil) goto v129;
    v125 = elt(env, 2); /* rtypefn */
    v125 = get(v104, v125);
    env = stack[0];
    v104 = v125;
    if (v125 == nil) goto v129;
    v125 = v104;
    v89 = qcdr(v89);
        popv(1);
        return Lapply1(nil, v125, v89);

v129:
    v125 = v89;
    v104 = qcar(v125);
    v125 = elt(env, 2); /* rtypefn */
    v125 = get(v104, v125);
    env = stack[0];
    v104 = v125;
    if (v125 == nil) goto v122;
    v125 = v104;
    v89 = qcdr(v89);
        popv(1);
        return Lapply1(nil, v125, v89);

v122:
    v125 = v89;
    v104 = qcar(v125);
    v125 = elt(env, 3); /* matmapfn */
    v125 = Lflagp(nil, v104, v125);
    env = stack[0];
    if (v125 == nil) goto v210;
    v125 = v89;
    v125 = qcdr(v125);
    if (v125 == nil) goto v210;
    v125 = v89;
    v125 = qcdr(v125);
    v125 = qcar(v125);
    fn = elt(env, 6); /* getrtype */
    v89 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[0];
    v125 = elt(env, 4); /* matrix */
    if (!(v89 == v125)) goto v210;
    v125 = elt(env, 4); /* matrix */
    { popv(1); return onevalue(v125); }

v210:
    v125 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v125); }
/* error exit handlers */
v213:
    popv(1);
    return nil;
}



/* Code for subs3q */

static Lisp_Object CC_subs3q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3q");
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
    v31 = qvalue(elt(env, 1)); /* mchfg!* */
    stack[-2] = v31;
    v31 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v31; /* mchfg!* */
    v31 = stack[-1];
    v31 = qcar(v31);
    fn = elt(env, 3); /* subs3f */
    stack[0] = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    v31 = stack[-1];
    v31 = qcdr(v31);
    fn = elt(env, 3); /* subs3f */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    fn = elt(env, 4); /* quotsq */
    v31 = (*qfn2(fn))(qenv(fn), stack[0], v31);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    stack[-1] = v31;
    v31 = stack[-2];
    qvalue(elt(env, 1)) = v31; /* mchfg!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v3:
    popv(4);
    return nil;
}



/* Code for tayexp!-difference */

static Lisp_Object CC_tayexpKdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v105, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-difference");
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
    v105 = v0;
/* end of prologue */
    v141 = v105;
    if (!(!consp(v141))) goto v10;
    v141 = stack[0];
    if (!(!consp(v141))) goto v10;
    v141 = stack[0];
    popv(3);
    return difference2(v105, v141);

v10:
    v141 = v105;
    if (!consp(v141)) goto v7;
    v141 = stack[0];
    if (!consp(v141)) goto v65;
    v141 = stack[0];
    fn = elt(env, 1); /* rndifference!: */
    v141 = (*qfn2(fn))(qenv(fn), v105, v141);
    nil = C_nil;
    if (exception_pending()) goto v20;
    goto v94;

v94:
    v106 = v141;
    v141 = v106;
    v141 = qcdr(v141);
    v105 = qcdr(v141);
    v141 = (Lisp_Object)17; /* 1 */
    if (!(v105 == v141)) { popv(3); return onevalue(v106); }
    v141 = v106;
    v141 = qcdr(v141);
    v141 = qcar(v141);
    { popv(3); return onevalue(v141); }

v65:
    stack[-1] = v105;
    v141 = stack[0];
    fn = elt(env, 2); /* !*i2rn */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    fn = elt(env, 1); /* rndifference!: */
    v141 = (*qfn2(fn))(qenv(fn), stack[-1], v141);
    nil = C_nil;
    if (exception_pending()) goto v20;
    goto v94;

v7:
    v141 = v105;
    fn = elt(env, 2); /* !*i2rn */
    v105 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v141 = stack[0];
    fn = elt(env, 1); /* rndifference!: */
    v141 = (*qfn2(fn))(qenv(fn), v105, v141);
    nil = C_nil;
    if (exception_pending()) goto v20;
    goto v94;
/* error exit handlers */
v20:
    popv(3);
    return nil;
}



/* Code for get!+col!+nr */

static Lisp_Object CC_getLcolLnr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+col+nr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v63 = v0;
/* end of prologue */
    v63 = qcar(v63);
        return Llength(nil, v63);
}



/* Code for sqchk */

static Lisp_Object CC_sqchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v135, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqchk");
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
    v92 = v135;
    if (!consp(v92)) { popv(1); return onevalue(v135); }
    v92 = v135;
    v80 = qcar(v92);
    v92 = elt(env, 1); /* prepfn2 */
    v92 = get(v80, v92);
    env = stack[0];
    v80 = v92;
    v92 = v80;
    if (v92 == nil) goto v32;
    v92 = v80;
        popv(1);
        return Lapply1(nil, v92, v135);

v32:
    v92 = v135;
    v92 = qcar(v92);
    if (!consp(v92)) { popv(1); return onevalue(v135); }
    v92 = v135;
    {
        popv(1);
        fn = elt(env, 2); /* prepf */
        return (*qfn1(fn))(qenv(fn), v92);
    }
}



/* Code for list2string */

static Lisp_Object CC_list2string(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list2string");
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
    v13 = stack[0];
    if (v13 == nil) goto v44;
    v13 = stack[0];
    v13 = qcar(v13);
    v13 = Lprinc(nil, v13);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = CC_list2string(env, v13);
    nil = C_nil;
    if (exception_pending()) goto v41;
    goto v44;

v44:
    v13 = nil;
    { popv(2); return onevalue(v13); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for sqform */

static Lisp_Object CC_sqform(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v136, v27, v59;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqform");
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
    v136 = stack[0];
    v130 = stack[-1];
    v130 = qcar(v130);
    stack[-2] = Lapply1(nil, v136, v130);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v136 = stack[0];
    v130 = stack[-1];
    v130 = qcdr(v130);
    v130 = Lapply1(nil, v136, v130);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v59 = stack[-2];
    v27 = v130;
    v136 = v27;
    v130 = (Lisp_Object)17; /* 1 */
    if (v136 == v130) { popv(4); return onevalue(v59); }
    v130 = elt(env, 1); /* quotient */
    v136 = v59;
    popv(4);
    return list3(v130, v136, v27);
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for prepsqx */

static Lisp_Object CC_prepsqx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsqx");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* !*intstr */
    if (v4 == nil) goto v88;
    v4 = v5;
    {
        fn = elt(env, 2); /* prepsq!* */
        return (*qfn1(fn))(qenv(fn), v4);
    }

v88:
    v4 = v5;
    {
        fn = elt(env, 3); /* prepsq */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



/* Code for findrow */

static Lisp_Object CC_findrow(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v65, v129, v91;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findrow");
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
    v58 = v1;
    v65 = v0;
/* end of prologue */
    v129 = v65;
    v129 = Lconsp(nil, v129);
    env = stack[0];
    if (v129 == nil) goto v128;
    v129 = v65;
    v129 = qcar(v129);
    v91 = elt(env, 1); /* sparsemat */
    if (!(v129 == v91)) goto v128;
    v65 = qcdr(v65);
    v65 = qcar(v65);
    goto v128;

v128:
    v58 = *(Lisp_Object *)((char *)v65 + (CELL-TAG_VECTOR) + ((int32_t)v58/(16/CELL)));
    { popv(1); return onevalue(v58); }
}



/* Code for nextarg */

static Lisp_Object CC_nextarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextarg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* symm */
    if (v4 == nil) goto v88;
    v4 = v5;
    {
        fn = elt(env, 2); /* s!-nextarg */
        return (*qfn1(fn))(qenv(fn), v4);
    }

v88:
    v4 = v5;
    {
        fn = elt(env, 3); /* o!-nextarg */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



/* Code for exptchk */

static Lisp_Object CC_exptchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v24, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptchk");
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
    v133 = stack[0];
    if (!consp(v133)) goto v45;
    v133 = stack[0];
    v133 = qcar(v133);
    if (!consp(v133)) goto v45;
    v133 = stack[0];
    fn = elt(env, 2); /* comm_kernels */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    stack[-1] = v133;
    v133 = stack[-1];
    v24 = Llength(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v133 = (Lisp_Object)33; /* 2 */
    v133 = (Lisp_Object)lessp2(v24, v133);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v133 = v133 ? lisp_true : nil;
    env = stack[-2];
    if (v133 == nil) goto v130;
    v24 = stack[0];
    v133 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v24, v133);

v130:
    v110 = stack[0];
    v24 = qvalue(elt(env, 1)); /* nil */
    v133 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* exptchk0 */
        return (*qfnn(fn))(qenv(fn), 3, v110, v24, v133);
    }

v45:
    v24 = stack[0];
    v133 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v24, v133);
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for setcdr */

static Lisp_Object CC_setcdr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setcdr");
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
    v45 = v0;
/* end of prologue */
    v4 = v45;
    v45 = stack[0];
    v45 = Lrplacd(nil, v4, v45);
    nil = C_nil;
    if (exception_pending()) goto v13;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v13:
    popv(1);
    return nil;
}



/* Code for atomf */

static Lisp_Object CC_atomf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v41;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atomf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */
    v21 = v41;
    v21 = (consp(v21) ? nil : lisp_true);
    if (!(v21 == nil)) return onevalue(v21);
    v21 = v41;
    v21 = qcar(v21);
    v41 = elt(env, 1); /* indexvar */
        return Lflagp(nil, v21, v41);
}



/* Code for maxdeg */

static Lisp_Object CC_maxdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v61;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxdeg");
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

v137:
    v90 = stack[-1];
    if (v90 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v90 = stack[-1];
    v90 = qcar(v90);
    v61 = qcdr(v90);
    v90 = stack[0];
    v90 = qcdr(v90);
    v90 = (Lisp_Object)greaterp2(v61, v90);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v90 = v90 ? lisp_true : nil;
    env = stack[-2];
    if (v90 == nil) goto v86;
    v90 = stack[-1];
    v90 = qcdr(v90);
    v61 = v90;
    v90 = stack[-1];
    v90 = qcar(v90);
    stack[0] = v90;
    v90 = v61;
    stack[-1] = v90;
    goto v137;

v86:
    v90 = stack[-1];
    v90 = qcdr(v90);
    stack[-1] = v90;
    goto v137;
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for noncommuting */

static Lisp_Object CC_noncommuting(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncommuting");
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
    v133 = stack[-1];
    if (!consp(v133)) goto v88;
    v133 = stack[-1];
    v133 = qcar(v133);
    goto v131;

v131:
    stack[-1] = v133;
    v133 = stack[0];
    if (!consp(v133)) goto v10;
    v133 = stack[0];
    v133 = qcar(v133);
    goto v42;

v42:
    stack[0] = v133;
    v133 = stack[-1];
    fn = elt(env, 3); /* noncomp2 */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    if (v133 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v133 = stack[0];
    fn = elt(env, 3); /* noncomp2 */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    if (v133 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v24 = stack[-1];
    v133 = elt(env, 2); /* noncommutes */
    v133 = get(v24, v133);
    v24 = stack[0];
    v133 = Lmember(nil, v24, v133);
    stack[-2] = v133;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v10:
    v133 = stack[0];
    goto v42;

v88:
    v133 = stack[-1];
    goto v131;
/* error exit handlers */
v126:
    popv(4);
    return nil;
}



/* Code for repeatsp */

static Lisp_Object CC_repeatsp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeatsp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */

v138:
    v6 = v7;
    if (v6 == nil) goto v85;
    v6 = v7;
    v8 = qcar(v6);
    v6 = v7;
    v6 = qcdr(v6);
    v6 = Lmember(nil, v8, v6);
    if (!(v6 == nil)) return onevalue(v6);
    v6 = v7;
    v6 = qcdr(v6);
    v7 = v6;
    goto v138;

v85:
    v6 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v6);
}



/* Code for bc!=simp */

static Lisp_Object CC_bcMsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc=simp");
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
    v145 = elt(env, 1); /* cali */
    v116 = elt(env, 2); /* rules */
    v116 = get(v145, v116);
    env = stack[-5];
    stack[-4] = v116;
    v116 = stack[-4];
    if (v116 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v116 = (Lisp_Object)1; /* 0 */
    stack[0] = v116;
    v116 = stack[-4];
    stack[-2] = v116;
    goto v6;

v6:
    v116 = stack[-2];
    if (v116 == nil) goto v120;
    v145 = stack[0];
    v116 = (Lisp_Object)16001; /* 1000 */
    v116 = (Lisp_Object)lessp2(v145, v116);
    nil = C_nil;
    if (exception_pending()) goto v197;
    v116 = v116 ? lisp_true : nil;
    env = stack[-5];
    if (v116 == nil) goto v120;
    v145 = stack[-3];
    v116 = stack[-2];
    v116 = qcar(v116);
    v116 = qcar(v116);
    fn = elt(env, 5); /* qremf */
    v116 = (*qfn2(fn))(qenv(fn), v145, v116);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    stack[-1] = v116;
    v116 = stack[-1];
    v116 = qcar(v116);
    if (v116 == nil) goto v79;
    v116 = stack[-1];
    v145 = qcar(v116);
    v116 = stack[-2];
    v116 = qcar(v116);
    v116 = qcdr(v116);
    fn = elt(env, 6); /* multf */
    v145 = (*qfn2(fn))(qenv(fn), v145, v116);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    v116 = stack[-1];
    v116 = qcdr(v116);
    fn = elt(env, 7); /* addf */
    v116 = (*qfn2(fn))(qenv(fn), v145, v116);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    stack[-3] = v116;
    v116 = stack[0];
    v116 = add1(v116);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-5];
    stack[0] = v116;
    v116 = stack[-4];
    stack[-2] = v116;
    goto v6;

v79:
    v116 = stack[-2];
    v116 = qcdr(v116);
    stack[-2] = v116;
    goto v6;

v120:
    v145 = stack[0];
    v116 = (Lisp_Object)16001; /* 1000 */
    v116 = (Lisp_Object)lessp2(v145, v116);
    nil = C_nil;
    if (exception_pending()) goto v197;
    v116 = v116 ? lisp_true : nil;
    env = stack[-5];
    if (!(v116 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v116 = elt(env, 4); /* "recursion depth of bc!=simp too high" */
    fn = elt(env, 8); /* rederr */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v197;
    v116 = nil;
    { popv(6); return onevalue(v116); }
/* error exit handlers */
v197:
    popv(6);
    return nil;
}



/* Code for pv_applp */

static Lisp_Object CC_pv_applp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_applp");
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
    v201 = v0;
/* end of prologue */
    stack[-5] = v201;
    v201 = stack[-5];
    if (v201 == nil) goto v4;
    v201 = stack[-5];
    v201 = qcar(v201);
    v141 = v201;
    v201 = v141;
    stack[0] = qcar(v201);
    v201 = v141;
    v141 = qcdr(v201);
    v201 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v201 = (*qfn2(fn))(qenv(fn), v141, v201);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v201 = cons(stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v201 = ncons(v201);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    stack[-2] = v201;
    stack[-3] = v201;
    goto v88;

v88:
    v201 = stack[-5];
    v201 = qcdr(v201);
    stack[-5] = v201;
    v201 = stack[-5];
    if (v201 == nil) goto v92;
    stack[-1] = stack[-2];
    v201 = stack[-5];
    v201 = qcar(v201);
    v141 = v201;
    v201 = v141;
    stack[0] = qcar(v201);
    v201 = v141;
    v141 = qcdr(v201);
    v201 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v201 = (*qfn2(fn))(qenv(fn), v141, v201);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v201 = cons(stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v201 = ncons(v201);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v201 = Lrplacd(nil, stack[-1], v201);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-6];
    v201 = stack[-2];
    v201 = qcdr(v201);
    stack[-2] = v201;
    goto v88;

v92:
    v201 = stack[-3];
    goto v131;

v131:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v201);
    }

v4:
    v201 = qvalue(elt(env, 1)); /* nil */
    goto v131;
/* error exit handlers */
v210:
    popv(7);
    return nil;
}



/* Code for rntimes!: */

static Lisp_Object CC_rntimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rntimes:");
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
    v43 = qcdr(v43);
    v33 = qcar(v43);
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = qcar(v43);
    stack[-2] = times2(v33, v43);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v43 = stack[-1];
    v43 = qcdr(v43);
    v33 = qcdr(v43);
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = times2(v33, v43);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    {
        Lisp_Object v65 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v65, v43);
    }
/* error exit handlers */
v58:
    popv(4);
    return nil;
}



/* Code for !*modular2f */

static Lisp_Object CC_Hmodular2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v69;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *modular2f");
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

v88:
    v69 = stack[0];
    v74 = (Lisp_Object)1; /* 0 */
    if (v69 == v74) goto v63;
    v74 = qvalue(elt(env, 2)); /* !*balanced_mod */
    if (v74 == nil) goto v121;
    v69 = stack[0];
    v74 = stack[0];
    v69 = plus2(v69, v74);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v74 = qvalue(elt(env, 3)); /* current!-modulus */
    v74 = (Lisp_Object)greaterp2(v69, v74);
    nil = C_nil;
    if (exception_pending()) goto v127;
    v74 = v74 ? lisp_true : nil;
    env = stack[-2];
    if (v74 == nil) goto v126;
    stack[-1] = elt(env, 4); /* !:mod!: */
    v69 = stack[0];
    v74 = qvalue(elt(env, 3)); /* current!-modulus */
    v74 = difference2(v69, v74);
    nil = C_nil;
    if (exception_pending()) goto v127;
    {
        Lisp_Object v142 = stack[-1];
        popv(3);
        return cons(v142, v74);
    }

v126:
    v69 = stack[0];
    v74 = stack[0];
    stack[-1] = plus2(v69, v74);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v74 = qvalue(elt(env, 3)); /* current!-modulus */
    v74 = negate(v74);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v74 = (Lisp_Object)lesseq2(stack[-1], v74);
    nil = C_nil;
    if (exception_pending()) goto v127;
    v74 = v74 ? lisp_true : nil;
    env = stack[-2];
    if (v74 == nil) goto v53;
    v69 = stack[0];
    v74 = qvalue(elt(env, 3)); /* current!-modulus */
    v74 = plus2(v69, v74);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    stack[0] = v74;
    goto v88;

v53:
    v69 = elt(env, 4); /* !:mod!: */
    v74 = stack[0];
    popv(3);
    return cons(v69, v74);

v121:
    v69 = elt(env, 4); /* !:mod!: */
    v74 = stack[0];
    popv(3);
    return cons(v69, v74);

v63:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v74); }
/* error exit handlers */
v127:
    popv(3);
    return nil;
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "divide:");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divide:");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v40;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = stack[-1];
    v77 = stack[-2];
    v77 = qcdr(v77);
    v77 = qcar(v77);
    v77 = Labsval(nil, v77);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v77 = add1(v77);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v77 = plus2(stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v77 = (*qfn2(fn))(qenv(fn), stack[-3], v77);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    stack[-3] = v77;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v77 = stack[-3];
    v77 = qcdr(v77);
    v108 = qcar(v77);
    v77 = stack[-2];
    v77 = qcdr(v77);
    v77 = qcar(v77);
    stack[0] = quot2(v108, v77);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v77 = stack[-3];
    v77 = qcdr(v77);
    v108 = qcdr(v77);
    v77 = stack[-2];
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = difference2(v108, v77);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v77 = list2star(stack[-4], stack[0], v77);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    stack[-3] = v77;
    v108 = stack[-3];
    v77 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v108, v77);
    }
/* error exit handlers */
v54:
    popv(6);
    return nil;
}



/* Code for toknump */

static Lisp_Object CC_toknump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v3, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toknump");
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
    v3 = v0;
/* end of prologue */
    v2 = v3;
    v2 = (is_number(v2) ? lisp_true : nil);
    if (!(v2 == nil)) { popv(1); return onevalue(v2); }
    v6 = v3;
    v2 = elt(env, 1); /* !:dn!: */
    v2 = Leqcar(nil, v6, v2);
    env = stack[0];
    if (!(v2 == nil)) { popv(1); return onevalue(v2); }
    v2 = v3;
    v3 = elt(env, 2); /* !:int!: */
        popv(1);
        return Leqcar(nil, v2, v3);
}



/* Code for ofsf_posdefp */

static Lisp_Object CC_ofsf_posdefp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_posdefp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* !*rlpos */
    if (v4 == nil) goto v88;
    v4 = v5;
    {
        fn = elt(env, 2); /* ofsf_posdefp!-pos */
        return (*qfn1(fn))(qenv(fn), v4);
    }

v88:
    v4 = v5;
    {
        fn = elt(env, 3); /* sfto_tsqsumf */
        return (*qfn1(fn))(qenv(fn), v4);
    }
}



/* Code for praddf */

static Lisp_Object CC_praddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for praddf");
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
    v9 = stack[-1];
    v39 = qcar(v9);
    v9 = stack[0];
    v9 = qcar(v9);
    fn = elt(env, 1); /* addf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v39, v9);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v9 = stack[-1];
    v39 = qcdr(v9);
    v9 = stack[0];
    v9 = qcdr(v9);
    fn = elt(env, 1); /* addf */
    v9 = (*qfn2(fn))(qenv(fn), v39, v9);
    nil = C_nil;
    if (exception_pending()) goto v33;
    {
        Lisp_Object v90 = stack[-2];
        popv(4);
        return cons(v90, v9);
    }
/* error exit handlers */
v33:
    popv(4);
    return nil;
}



/* Code for prepd */

static Lisp_Object CC_prepd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepd");
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
    v125 = stack[0];
    if (!consp(v125)) goto v45;
    v125 = stack[0];
    v89 = qcar(v125);
    v125 = elt(env, 2); /* minusp */
    v89 = get(v89, v125);
    env = stack[-2];
    v125 = stack[0];
    v125 = Lapply1(nil, v89, v125);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    if (v125 == nil) goto v105;
    v125 = stack[0];
    fn = elt(env, 4); /* !:minus */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    fn = elt(env, 5); /* prepd1 */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v89 = v125;
    v125 = v89;
    if (v125 == nil) goto v79;
    v125 = elt(env, 1); /* minus */
    popv(3);
    return list2(v125, v89);

v79:
    v125 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v125); }

v105:
    v125 = stack[0];
    v89 = qcar(v125);
    v125 = elt(env, 3); /* prepfn */
    v89 = get(v89, v125);
    v125 = stack[0];
        popv(3);
        return Lapply1(nil, v89, v125);

v45:
    v89 = stack[0];
    v125 = (Lisp_Object)1; /* 0 */
    v125 = (Lisp_Object)lessp2(v89, v125);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v125 = v125 ? lisp_true : nil;
    env = stack[-2];
    if (v125 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); /* minus */
    v125 = stack[0];
    v125 = negate(v125);
    nil = C_nil;
    if (exception_pending()) goto v67;
    {
        Lisp_Object v120 = stack[-1];
        popv(3);
        return list2(v120, v125);
    }
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for ibalp_cequal */

static Lisp_Object CC_ibalp_cequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_cequal");
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
    v217 = stack[-5];
    v217 = qcar(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v10;
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = qcar(v217);
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v217;
    stack[-2] = v217;
    goto v5;

v5:
    v217 = stack[-3];
    v217 = qcdr(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v43;
    stack[0] = stack[-1];
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = qcar(v217);
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v217 = Lrplacd(nil, stack[0], v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    goto v5;

v43:
    v217 = stack[-2];
    goto v4;

v4:
    stack[-6] = v217;
    v217 = stack[-4];
    v217 = qcar(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v25;
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = qcar(v217);
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v217;
    stack[-2] = v217;
    goto v140;

v140:
    v217 = stack[-3];
    v217 = qcdr(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v201;
    stack[0] = stack[-1];
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = qcar(v217);
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v217 = Lrplacd(nil, stack[0], v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    goto v140;

v201:
    v217 = stack[-2];
    goto v74;

v74:
    v218 = stack[-6];
    fn = elt(env, 2); /* lto_setequalq */
    v217 = (*qfn2(fn))(qenv(fn), v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    if (v217 == nil) goto v68;
    v217 = stack[-5];
    v217 = qcdr(v217);
    v217 = qcar(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v185;
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = qcar(v217);
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v217;
    stack[-2] = v217;
    goto v16;

v16:
    v217 = stack[-3];
    v217 = qcdr(v217);
    stack[-3] = v217;
    v217 = stack[-3];
    if (v217 == nil) goto v101;
    stack[0] = stack[-1];
    v217 = stack[-3];
    v217 = qcar(v217);
    v217 = qcar(v217);
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v217 = Lrplacd(nil, stack[0], v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    goto v16;

v101:
    v217 = stack[-2];
    goto v71;

v71:
    stack[-3] = v217;
    v217 = stack[-4];
    v217 = qcdr(v217);
    v217 = qcar(v217);
    stack[-4] = v217;
    v217 = stack[-4];
    if (v217 == nil) goto v97;
    v217 = stack[-4];
    v217 = qcar(v217);
    v217 = qcar(v217);
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    stack[-1] = v217;
    stack[-2] = v217;
    goto v199;

v199:
    v217 = stack[-4];
    v217 = qcdr(v217);
    stack[-4] = v217;
    v217 = stack[-4];
    if (v217 == nil) goto v202;
    stack[0] = stack[-1];
    v217 = stack[-4];
    v217 = qcar(v217);
    v217 = qcar(v217);
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v217 = Lrplacd(nil, stack[0], v217);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-7];
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    goto v199;

v202:
    v217 = stack[-2];
    goto v176;

v176:
    v218 = stack[-3];
    {
        popv(8);
        fn = elt(env, 2); /* lto_setequalq */
        return (*qfn2(fn))(qenv(fn), v218, v217);
    }

v97:
    v217 = qvalue(elt(env, 1)); /* nil */
    goto v176;

v185:
    v217 = qvalue(elt(env, 1)); /* nil */
    goto v71;

v68:
    v217 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v217); }

v25:
    v217 = qvalue(elt(env, 1)); /* nil */
    goto v74;

v10:
    v217 = qvalue(elt(env, 1)); /* nil */
    goto v4;
/* error exit handlers */
v158:
    popv(8);
    return nil;
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v25, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powers2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers2");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v63:
    v122 = stack[-2];
    if (!consp(v122)) goto v134;
    v122 = stack[-2];
    v122 = qcar(v122);
    if (!consp(v122)) goto v134;
    v122 = stack[-2];
    v122 = qcar(v122);
    v122 = qcdr(v122);
    stack[-3] = v122;
    v122 = stack[-2];
    v126 = qcdr(v122);
    v25 = stack[-1];
    v122 = stack[0];
    v122 = CC_powers2(env, 3, v126, v25, v122);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-1] = v122;
    v122 = stack[-2];
    v122 = qcar(v122);
    v25 = qcar(v122);
    v122 = stack[0];
    v122 = cons(v25, v122);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[0] = v122;
    v122 = stack[-3];
    stack[-2] = v122;
    goto v63;

v134:
    v122 = stack[-2];
    if (v122 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v25 = stack[0];
    v122 = stack[-1];
    {
        popv(5);
        fn = elt(env, 1); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v25, v122);
    }
/* error exit handlers */
v108:
    popv(5);
    return nil;
}



/* Code for find */

static Lisp_Object CC_find(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v111, v26, v130;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v111 = v1;
    v26 = v0;
/* end of prologue */

v88:
    v130 = v111;
    v64 = nil;
    if (v130 == v64) goto v63;
    v64 = v111;
    v64 = qcar(v64);
    v26 = Lmember(nil, v64, v26);
    v64 = v111;
    v64 = qcdr(v64);
    v111 = v64;
    goto v88;

v63:
    v64 = v26;
    if (v64 == nil) goto v32;
    v64 = v26;
    v64 = qcdr(v64);
    return onevalue(v64);

v32:
    v64 = elt(env, 1); /* (stop) */
    return onevalue(v64);
}



/* Code for on1 */

static Lisp_Object CC_on1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v0;
/* end of prologue */
    v132 = v134;
    v134 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* onoff */
        return (*qfn2(fn))(qenv(fn), v132, v134);
    }
}



/* Code for rd!:onep */

static Lisp_Object CC_rdTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:onep");
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
    v61 = v0;
/* end of prologue */
    v46 = v61;
    v46 = qcdr(v46);
    if (!consp(v46)) goto v21;
    stack[0] = qvalue(elt(env, 3)); /* bfone!* */
    fn = elt(env, 4); /* bftrim!: */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    {
        Lisp_Object v129 = stack[0];
        popv(2);
        fn = elt(env, 5); /* equal!: */
        return (*qfn2(fn))(qenv(fn), v129, v61);
    }

v21:
    v46 = elt(env, 1); /* 1.0 */
    v61 = qcdr(v61);
    v61 = difference2(v46, v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v61 = Labsval(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v46 = qvalue(elt(env, 2)); /* !!fleps1 */
        popv(2);
        return Llessp(nil, v61, v46);
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



setup_type const u04_setup[] =
{
    {"gcdfd",                   too_few_2,      CC_gcdfd,      wrong_no_2},
    {"pv_add",                  too_few_2,      CC_pv_add,     wrong_no_2},
    {"copy",                    CC_copy,        too_many_1,    wrong_no_1},
    {"fkern",                   CC_fkern,       too_many_1,    wrong_no_1},
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"subs2",                   CC_subs2,       too_many_1,    wrong_no_1},
    {"ibalp_hassimple",         CC_ibalp_hassimple,too_many_1, wrong_no_1},
    {"indent*",                 CC_indentH,     too_many_1,    wrong_no_1},
    {"multi_isarb_compl",       CC_multi_isarb_compl,too_many_1,wrong_no_1},
    {"mcharg1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg1},
    {"fullcopy",                CC_fullcopy,    too_many_1,    wrong_no_1},
    {"copy_mat",                CC_copy_mat,    too_many_1,    wrong_no_1},
    {"evlexcomp",               too_few_2,      CC_evlexcomp,  wrong_no_2},
    {"chundexp",                CC_chundexp,    too_many_1,    wrong_no_1},
    {"*physopp*",               CC_HphysoppH,   too_many_1,    wrong_no_1},
    {"nonzero-length",          CC_nonzeroKlength,too_many_1,  wrong_no_1},
    {"mo_compare",              too_few_2,      CC_mo_compare, wrong_no_2},
    {"cdiv",                    too_few_2,      CC_cdiv,       wrong_no_2},
    {"insert_pv",               too_few_2,      CC_insert_pv,  wrong_no_2},
    {"general-modular-number",  CC_generalKmodularKnumber,too_many_1,wrong_no_1},
    {"noncomdel",               too_few_2,      CC_noncomdel,  wrong_no_2},
    {"ofsf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwupdknowl},
    {"tayexp-minusp",           CC_tayexpKminusp,too_many_1,   wrong_no_1},
    {"ibalp_varlt",             CC_ibalp_varlt, too_many_1,    wrong_no_1},
    {"multi_isarb_int",         CC_multi_isarb_int,too_many_1, wrong_no_1},
    {"revlis",                  CC_revlis,      too_many_1,    wrong_no_1},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"find_item",               too_few_2,      CC_find_item,  wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {":plus",                   too_few_2,      CC_Tplus,      wrong_no_2},
    {"freeofdepl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_freeofdepl},
    {"idlistp",                 CC_idlistp,     too_many_1,    wrong_no_1},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"pv_sort1",                too_few_2,      CC_pv_sort1,   wrong_no_2},
    {"mkrn",                    too_few_2,      CC_mkrn,       wrong_no_2},
    {"gen-mult-by-const-mod-p", too_few_2,      CC_genKmultKbyKconstKmodKp,wrong_no_2},
    {"c:ordexp",                too_few_2,      CC_cTordexp,   wrong_no_2},
    {"times-mod-p",             too_few_2,      CC_timesKmodKp,wrong_no_2},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"getrtype2",               CC_getrtype2,   too_many_1,    wrong_no_1},
    {"subs3q",                  CC_subs3q,      too_many_1,    wrong_no_1},
    {"tayexp-difference",       too_few_2,      CC_tayexpKdifference,wrong_no_2},
    {"get+col+nr",              CC_getLcolLnr,  too_many_1,    wrong_no_1},
    {"sqchk",                   CC_sqchk,       too_many_1,    wrong_no_1},
    {"list2string",             CC_list2string, too_many_1,    wrong_no_1},
    {"sqform",                  too_few_2,      CC_sqform,     wrong_no_2},
    {"prepsqx",                 CC_prepsqx,     too_many_1,    wrong_no_1},
    {"findrow",                 too_few_2,      CC_findrow,    wrong_no_2},
    {"nextarg",                 CC_nextarg,     too_many_1,    wrong_no_1},
    {"exptchk",                 CC_exptchk,     too_many_1,    wrong_no_1},
    {"setcdr",                  too_few_2,      CC_setcdr,     wrong_no_2},
    {"atomf",                   CC_atomf,       too_many_1,    wrong_no_1},
    {"maxdeg",                  too_few_2,      CC_maxdeg,     wrong_no_2},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"repeatsp",                CC_repeatsp,    too_many_1,    wrong_no_1},
    {"bc=simp",                 CC_bcMsimp,     too_many_1,    wrong_no_1},
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"rntimes:",                too_few_2,      CC_rntimesT,   wrong_no_2},
    {"*modular2f",              CC_Hmodular2f,  too_many_1,    wrong_no_1},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"toknump",                 CC_toknump,     too_many_1,    wrong_no_1},
    {"ofsf_posdefp",            CC_ofsf_posdefp,too_many_1,    wrong_no_1},
    {"praddf",                  too_few_2,      CC_praddf,     wrong_no_2},
    {"prepd",                   CC_prepd,       too_many_1,    wrong_no_1},
    {"ibalp_cequal",            too_few_2,      CC_ibalp_cequal,wrong_no_2},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"on1",                     CC_on1,         too_many_1,    wrong_no_1},
    {"rd:onep",                 CC_rdTonep,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u04", (two_args *)"1738 3850084 9917410", 0}
};

/* end of generated code */
