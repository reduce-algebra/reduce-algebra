
/* $destdir/generated-c\u17.c Machine generated C code */

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


/* Code for ibalp_isinminclause */

static Lisp_Object CC_ibalp_isinminclause(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_isinminclause");
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
    v12 = stack[-2];
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    stack[-3] = v12;
    goto v14;

v14:
    v12 = stack[-3];
    if (v12 == nil) goto v15;
    v12 = stack[0];
    if (!(v12 == nil)) goto v15;
    v12 = stack[-3];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    if (!(v12 == nil)) goto v16;
    v12 = stack[-3];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v13 = qcar(v12);
    v12 = stack[-3];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    v13 = plus2(v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v12 = stack[-1];
    v12 = Leqn(nil, v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    if (v12 == nil) goto v16;
    v12 = qvalue(elt(env, 2)); /* t */
    stack[0] = v12;
    goto v16;

v16:
    v12 = stack[-3];
    v12 = qcdr(v12);
    stack[-3] = v12;
    goto v14;

v15:
    v12 = stack[-2];
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    stack[-3] = v12;
    goto v18;

v18:
    v12 = stack[-3];
    if (v12 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v12 = stack[0];
    if (!(v12 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v12 = stack[-3];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    if (!(v12 == nil)) goto v19;
    v12 = stack[-3];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v13 = qcar(v12);
    v12 = stack[-3];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    v13 = plus2(v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v12 = stack[-1];
    v12 = Leqn(nil, v13, v12);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    if (v12 == nil) goto v19;
    v12 = qvalue(elt(env, 2)); /* t */
    stack[0] = v12;
    goto v19;

v19:
    v12 = stack[-3];
    v12 = qcdr(v12);
    stack[-3] = v12;
    goto v18;
/* error exit handlers */
v17:
    popv(5);
    return nil;
}



/* Code for convertmode1 */

static Lisp_Object MS_CDECL CC_convertmode1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v20, Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v12, v13, v44, v45, v46, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convertmode1");
#endif
    if (stack >= stacklimit)
    {
        push4(v6,v20,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v20,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v13 = v6;
    v44 = v20;
    v45 = v1;
    v46 = v0;
/* end of prologue */
    v12 = v13;
    v43 = elt(env, 1); /* real */
    if (!(v12 == v43)) goto v16;
    v43 = elt(env, 2); /* algebraic */
    v13 = v43;
    goto v16;

v16:
    v12 = v44;
    v43 = elt(env, 1); /* real */
    if (!(v12 == v43)) goto v48;
    v43 = elt(env, 2); /* algebraic */
    v44 = v43;
    goto v48;

v48:
    v12 = v44;
    v43 = v13;
    if (v12 == v43) { popv(1); return onevalue(v46); }
    v43 = v46;
    if (!(symbolp(v43))) goto v49;
    v12 = v46;
    v43 = v45;
    v43 = Latsoc(nil, v12, v43);
    v47 = v43;
    if (v43 == nil) goto v49;
    v43 = v47;
    v12 = qcdr(v43);
    v43 = elt(env, 3); /* (integer scalar real) */
    v43 = Lmemq(nil, v12, v43);
    if (!(v43 == nil)) goto v49;
    v43 = v47;
    v12 = qcdr(v43);
    v43 = v13;
    if (v12 == v43) goto v49;
    v43 = v46;
    v12 = v45;
    v13 = v44;
    v44 = v47;
    v44 = qcdr(v44);
    {
        popv(1);
        fn = elt(env, 4); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v43, v12, v13, v44);
    }

v49:
    v12 = v13;
    v43 = v44;
    v43 = get(v12, v43);
    env = stack[0];
    v47 = v43;
    if (v43 == nil) goto v50;
    v43 = v47;
    v12 = v46;
    v13 = v45;
        popv(1);
        return Lapply2(nil, 3, v43, v12, v13);

v50:
    v43 = v13;
    v12 = v44;
    fn = elt(env, 5); /* typerr */
    v43 = (*qfn2(fn))(qenv(fn), v43, v12);
    nil = C_nil;
    if (exception_pending()) goto v17;
    v43 = nil;
    { popv(1); return onevalue(v43); }
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



/* Code for setdmode */

static Lisp_Object CC_setdmode(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdmode");
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
    v76 = stack[-2];
    v75 = elt(env, 1); /* dname */
    v75 = get(v76, v75);
    env = stack[-4];
    stack[0] = v75;
    if (v75 == nil) goto v78;
    v75 = stack[0];
    stack[-2] = v75;
    goto v78;

v78:
    v76 = stack[-2];
    v75 = elt(env, 2); /* complex!-rational */
    if (v76 == v75) goto v79;
    v76 = stack[-2];
    v75 = elt(env, 6); /* complex!-rounded */
    if (v76 == v75) goto v80;
    v76 = stack[-2];
    v75 = elt(env, 8); /* tag */
    v75 = get(v76, v75);
    env = stack[-4];
    if (!(v75 == nil)) goto v81;
    stack[-3] = elt(env, 9); /* poly */
    stack[0] = (Lisp_Object)81; /* 5 */
    v77 = elt(env, 10); /* "Domain mode error:" */
    v76 = stack[-2];
    v75 = elt(env, 11); /* "is not a domain mode" */
    v75 = list3(v77, v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    fn = elt(env, 14); /* rerror */
    v75 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v75);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    goto v81;

v81:
    v76 = stack[-2];
    v75 = elt(env, 12); /* package!-name */
    v75 = get(v76, v75);
    env = stack[-4];
    stack[0] = v75;
    if (v75 == nil) goto v83;
    v75 = stack[0];
    fn = elt(env, 15); /* load!-package */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    goto v83;

v83:
    v76 = stack[-2];
    v75 = elt(env, 4); /* complex */
    if (v76 == v75) goto v84;
    v75 = qvalue(elt(env, 13)); /* !*complex */
    if (!(v75 == nil)) goto v84;
    v76 = stack[-2];
    v75 = stack[-1];
    {
        popv(5);
        fn = elt(env, 16); /* setdmode1 */
        return (*qfn2(fn))(qenv(fn), v76, v75);
    }

v84:
    v76 = stack[-2];
    v75 = stack[-1];
    {
        popv(5);
        fn = elt(env, 17); /* setcmpxmode */
        return (*qfn2(fn))(qenv(fn), v76, v75);
    }

v80:
    v75 = qvalue(elt(env, 3)); /* dmode!* */
    stack[0] = v75;
    if (v75 == nil) goto v85;
    v76 = stack[0];
    v75 = elt(env, 1); /* dname */
    v75 = get(v76, v75);
    env = stack[-4];
    stack[0] = v75;
    goto v85;

v85:
    v76 = elt(env, 4); /* complex */
    v75 = stack[-1];
    fn = elt(env, 18); /* onoff */
    v75 = (*qfn2(fn))(qenv(fn), v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    v76 = elt(env, 7); /* rounded */
    v75 = stack[-1];
    fn = elt(env, 18); /* onoff */
    v75 = (*qfn2(fn))(qenv(fn), v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v82;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v79:
    v75 = qvalue(elt(env, 3)); /* dmode!* */
    stack[0] = v75;
    if (v75 == nil) goto v86;
    v76 = stack[0];
    v75 = elt(env, 1); /* dname */
    v75 = get(v76, v75);
    env = stack[-4];
    stack[0] = v75;
    goto v86;

v86:
    v76 = elt(env, 4); /* complex */
    v75 = stack[-1];
    fn = elt(env, 18); /* onoff */
    v75 = (*qfn2(fn))(qenv(fn), v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    v76 = elt(env, 5); /* rational */
    v75 = stack[-1];
    fn = elt(env, 18); /* onoff */
    v75 = (*qfn2(fn))(qenv(fn), v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v82;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
/* error exit handlers */
v82:
    popv(5);
    return nil;
}



/* Code for physopsimp */

static Lisp_Object CC_physopsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsimp");
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
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = nil;
    v143 = stack[-6];
    if (symbolp(v143)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v143 = stack[-6];
    v143 = qcar(v143);
    stack[-7] = v143;
    v143 = stack[-6];
    v143 = qcdr(v143);
    stack[-5] = v143;
    v143 = stack[-5];
    if (v143 == nil) goto v146;
    v143 = stack[-5];
    v143 = qcar(v143);
    stack[0] = v143;
    v143 = stack[0];
    if (!(symbolp(v143))) goto v71;
    v143 = stack[0];
    fn = elt(env, 8); /* isanindex */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (!(v143 == nil)) goto v148;
    v143 = stack[0];
    fn = elt(env, 9); /* isavarindex */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (!(v143 == nil)) goto v148;

v71:
    v143 = stack[0];
    fn = elt(env, 10); /* physopsm!* */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v48;

v48:
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-2] = v143;
    stack[-3] = v143;
    goto v149;

v149:
    v143 = stack[-5];
    v143 = qcdr(v143);
    stack[-5] = v143;
    v143 = stack[-5];
    if (v143 == nil) goto v70;
    stack[-1] = stack[-2];
    v143 = stack[-5];
    v143 = qcar(v143);
    stack[0] = v143;
    v143 = stack[0];
    if (!(symbolp(v143))) goto v28;
    v143 = stack[0];
    fn = elt(env, 8); /* isanindex */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (!(v143 == nil)) goto v32;
    v143 = stack[0];
    fn = elt(env, 9); /* isavarindex */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (!(v143 == nil)) goto v32;

v28:
    v143 = stack[0];
    fn = elt(env, 10); /* physopsm!* */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v150;

v150:
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = Lrplacd(nil, stack[-1], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = stack[-2];
    v143 = qcdr(v143);
    stack[-2] = v143;
    goto v149;

v32:
    v143 = stack[0];
    goto v150;

v70:
    v143 = stack[-3];
    goto v79;

v79:
    stack[0] = v143;
    stack[-5] = stack[-7];
    v143 = stack[0];
    stack[-3] = v143;
    v143 = stack[-3];
    if (v143 == nil) goto v26;
    v143 = stack[-3];
    v143 = qcar(v143);
    v145 = v143;
    v144 = v145;
    v143 = elt(env, 2); /* !*sq */
    if (!consp(v144)) goto v151;
    v144 = qcar(v144);
    if (!(v144 == v143)) goto v151;
    v143 = v145;
    v143 = qcdr(v143);
    v143 = qcar(v143);
    fn = elt(env, 11); /* prepsqxx */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v3;

v3:
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-1] = v143;
    stack[-2] = v143;
    goto v152;

v152:
    v143 = stack[-3];
    v143 = qcdr(v143);
    stack[-3] = v143;
    v143 = stack[-3];
    if (v143 == nil) goto v153;
    stack[0] = stack[-1];
    v143 = stack[-3];
    v143 = qcar(v143);
    v145 = v143;
    v144 = v145;
    v143 = elt(env, 2); /* !*sq */
    if (!consp(v144)) goto v154;
    v144 = qcar(v144);
    if (!(v144 == v143)) goto v154;
    v143 = v145;
    v143 = qcdr(v143);
    v143 = qcar(v143);
    fn = elt(env, 11); /* prepsqxx */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    goto v155;

v155:
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = Lrplacd(nil, stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = stack[-1];
    v143 = qcdr(v143);
    stack[-1] = v143;
    goto v152;

v154:
    v143 = v145;
    goto v155;

v153:
    v143 = stack[-2];
    goto v63;

v63:
    v143 = cons(stack[-5], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-6] = v143;
    v143 = stack[-6];
    fn = elt(env, 12); /* opmtch!* */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[0] = v143;
    if (!(v143 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v143 = stack[-6];
    fn = elt(env, 13); /* scalopp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (v143 == nil) goto v82;
    v143 = stack[-7];
    fn = elt(env, 14); /* tensopp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (v143 == nil) goto v82;
    v144 = stack[-7];
    v143 = elt(env, 3); /* tensdimen */
    v143 = get(v144, v143);
    env = stack[-8];
    stack[-5] = v143;
    v143 = (Lisp_Object)17; /* 1 */
    stack[-3] = v143;
    v144 = stack[-5];
    v143 = stack[-3];
    v143 = difference2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = Lminusp(nil, v143);
    env = stack[-8];
    if (v143 == nil) goto v156;
    v143 = qvalue(elt(env, 1)); /* nil */
    goto v157;

v157:
    stack[0] = v143;
    v143 = stack[-6];
    v143 = qcdr(v143);
    v144 = Llength(nil, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = stack[-5];
    v143 = (Lisp_Object)greaterp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v143 = v143 ? lisp_true : nil;
    env = stack[-8];
    if (v143 == nil) goto v158;
    v143 = stack[-6];
    stack[-1] = qcdr(v143);
    v143 = stack[-5];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    fn = elt(env, 15); /* pnth */
    v143 = (*qfn2(fn))(qenv(fn), stack[-1], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-5] = v143;
    goto v159;

v159:
    v144 = stack[-7];
    v143 = elt(env, 4); /* symmetric */
    v143 = Lflagp(nil, v144, v143);
    env = stack[-8];
    if (v143 == nil) goto v160;
    stack[-1] = stack[-7];
    v143 = stack[0];
    fn = elt(env, 16); /* ordn */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = cons(stack[-1], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-6] = v143;
    goto v161;

v161:
    v143 = stack[-5];
    if (v143 == nil) goto v162;
    v144 = stack[-6];
    v143 = stack[-5];
    v143 = Lappend(nil, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-6] = v143;
    goto v162;

v162:
    v143 = stack[-4];
    if (v143 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v144 = elt(env, 7); /* minus */
    v143 = stack[-6];
    popv(9);
    return list2(v144, v143);

v160:
    v144 = stack[-7];
    v143 = elt(env, 5); /* antisymmetric */
    v143 = Lflagp(nil, v144, v143);
    env = stack[-8];
    if (v143 == nil) goto v163;
    v143 = stack[0];
    fn = elt(env, 17); /* repeats */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (v143 == nil) goto v164;
    v143 = (Lisp_Object)1; /* 0 */
    { popv(9); return onevalue(v143); }

v164:
    v143 = stack[0];
    fn = elt(env, 16); /* ordn */
    v144 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-1] = v144;
    v143 = stack[0];
    fn = elt(env, 18); /* permp */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (!(v143 == nil)) goto v165;
    v143 = qvalue(elt(env, 6)); /* t */
    stack[-4] = v143;
    goto v165;

v165:
    v143 = stack[-1];
    stack[0] = v143;
    v144 = stack[-7];
    v143 = stack[0];
    v143 = cons(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-6] = v143;
    goto v161;

v163:
    v144 = stack[-7];
    v143 = stack[0];
    v143 = cons(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-6] = v143;
    goto v161;

v158:
    v143 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v143;
    goto v159;

v156:
    v143 = stack[-6];
    v144 = qcdr(v143);
    v143 = stack[-3];
    fn = elt(env, 19); /* nth */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-1] = v143;
    stack[-2] = v143;
    goto v166;

v166:
    v143 = stack[-3];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[-3] = v143;
    v144 = stack[-5];
    v143 = stack[-3];
    v143 = difference2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = Lminusp(nil, v143);
    env = stack[-8];
    if (v143 == nil) goto v167;
    v143 = stack[-2];
    goto v157;

v167:
    stack[0] = stack[-1];
    v143 = stack[-6];
    v144 = qcdr(v143);
    v143 = stack[-3];
    fn = elt(env, 19); /* nth */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = Lrplacd(nil, stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = stack[-1];
    v143 = qcdr(v143);
    stack[-1] = v143;
    goto v166;

v82:
    v143 = stack[-6];
    fn = elt(env, 20); /* vecopp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (v143 == nil) goto v168;
    v143 = stack[-6];
    fn = elt(env, 21); /* listp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (v143 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v143 = stack[-6];
    v143 = qcdr(v143);
    v143 = qcar(v143);
    fn = elt(env, 22); /* putanewindex!* */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }

v168:
    v143 = stack[-6];
    fn = elt(env, 14); /* tensopp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (v143 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v143 = stack[-6];
    fn = elt(env, 21); /* listp */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    if (v143 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v143 = (Lisp_Object)17; /* 1 */
    stack[0] = v143;
    goto v169;

v169:
    v143 = stack[-6];
    v143 = qcdr(v143);
    v144 = Llength(nil, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = stack[0];
    v143 = difference2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = Lminusp(nil, v143);
    env = stack[-8];
    if (!(v143 == nil)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v143 = stack[-6];
    v144 = qcdr(v143);
    v143 = stack[0];
    fn = elt(env, 19); /* nth */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    fn = elt(env, 22); /* putanewindex!* */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    v143 = stack[0];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-8];
    stack[0] = v143;
    goto v169;

v151:
    v143 = v145;
    goto v3;

v26:
    v143 = qvalue(elt(env, 1)); /* nil */
    goto v63;

v148:
    v143 = stack[0];
    goto v48;

v146:
    v143 = qvalue(elt(env, 1)); /* nil */
    goto v79;
/* error exit handlers */
v147:
    popv(9);
    return nil;
}



/* Code for mv!-domainlist!-!+ */

static Lisp_Object CC_mvKdomainlistKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist-+");
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
    goto v94;

v94:
    v148 = stack[-1];
    if (v148 == nil) goto v173;
    v148 = stack[-1];
    v172 = qcar(v148);
    v148 = stack[0];
    v148 = qcar(v148);
    v172 = plus2(v172, v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-3];
    v148 = stack[-2];
    v148 = cons(v172, v148);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-3];
    stack[-2] = v148;
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    v148 = stack[0];
    v148 = qcdr(v148);
    stack[0] = v148;
    goto v94;

v173:
    v148 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v148);
    }
/* error exit handlers */
v8:
    popv(4);
    return nil;
}



/* Code for set!-general!-modulus */

static Lisp_Object CC_setKgeneralKmodulus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v178;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-general-modulus");
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
    v177 = stack[0];
    if (!(is_number(v177))) goto v7;
    v178 = stack[0];
    v177 = (Lisp_Object)1; /* 0 */
    if (v178 == v177) goto v7;
    v177 = qvalue(elt(env, 1)); /* current!-modulus */
    stack[-1] = v177;
    v177 = stack[0];
    qvalue(elt(env, 1)) = v177; /* current!-modulus */
    v178 = stack[0];
    v177 = (Lisp_Object)33; /* 2 */
    v177 = quot2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    qvalue(elt(env, 2)) = v177; /* modulus!/2 */
    v178 = stack[0];
    v177 = qvalue(elt(env, 3)); /* largest!-small!-modulus */
    v177 = (Lisp_Object)lesseq2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v179;
    v177 = v177 ? lisp_true : nil;
    env = stack[-2];
    if (v177 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v177 = stack[0];
    v177 = Lset_small_modulus(nil, v177);
    nil = C_nil;
    if (exception_pending()) goto v179;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v7:
    v177 = qvalue(elt(env, 1)); /* current!-modulus */
    { popv(3); return onevalue(v177); }
/* error exit handlers */
v179:
    popv(3);
    return nil;
}



/* Code for general!-modular!-expt */

static Lisp_Object CC_generalKmodularKexpt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-expt");
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

v188:
    v187 = stack[-1];
    v186 = (Lisp_Object)1; /* 0 */
    if (v187 == v186) goto v79;
    v187 = stack[0];
    v186 = (Lisp_Object)1; /* 0 */
    if (v187 == v186) goto v8;
    v187 = stack[0];
    v186 = (Lisp_Object)17; /* 1 */
    if (v187 == v186) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[0];
    v186 = qvalue(elt(env, 3)); /* current!-modulus */
    v186 = sub1(v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    v186 = (Lisp_Object)geq2(stack[-2], v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v186 = v186 ? lisp_true : nil;
    env = stack[-3];
    if (v186 == nil) goto v49;
    v186 = qvalue(elt(env, 3)); /* current!-modulus */
    fn = elt(env, 5); /* primep */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    if (v186 == nil) goto v49;
    v186 = qvalue(elt(env, 3)); /* current!-modulus */
    v186 = sub1(v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    v186 = Cremainder(stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[0] = v186;
    goto v188;

v49:
    v186 = stack[0];
    v186 = Levenp(nil, v186);
    env = stack[-3];
    if (v186 == nil) goto v190;
    v187 = stack[0];
    v186 = (Lisp_Object)33; /* 2 */
    v186 = quot2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[0] = v186;
    v187 = stack[-1];
    v186 = stack[-1];
    fn = elt(env, 6); /* general!-modular!-times */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[-1] = v186;
    goto v49;

v190:
    v186 = stack[0];
    fn = elt(env, 7); /* reverse!-num */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[0] = v186;
    v186 = (Lisp_Object)17; /* 1 */
    stack[-2] = v186;
    goto v17;

v17:
    v187 = stack[0];
    v186 = (Lisp_Object)1; /* 0 */
    v186 = (Lisp_Object)greaterp2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    v186 = v186 ? lisp_true : nil;
    env = stack[-3];
    if (v186 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v187 = stack[-2];
    v186 = stack[-2];
    fn = elt(env, 6); /* general!-modular!-times */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[-2] = v186;
    v186 = stack[0];
    v186 = Levenp(nil, v186);
    env = stack[-3];
    if (!(v186 == nil)) goto v191;
    v187 = stack[-2];
    v186 = stack[-1];
    fn = elt(env, 6); /* general!-modular!-times */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[-2] = v186;
    goto v191;

v191:
    v187 = stack[0];
    v186 = (Lisp_Object)33; /* 2 */
    v186 = quot2(v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[0] = v186;
    goto v17;

v8:
    v186 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v186); }

v79:
    v187 = stack[0];
    v186 = (Lisp_Object)1; /* 0 */
    if (v187 == v186) goto v40;
    v186 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v186); }

v40:
    v154 = elt(env, 1); /* alg */
    v187 = (Lisp_Object)1617; /* 101 */
    v186 = elt(env, 2); /* "0^0 formed" */
    {
        popv(4);
        fn = elt(env, 8); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v154, v187, v186);
    }
/* error exit handlers */
v189:
    popv(4);
    return nil;
}



/* Code for ibalp_dimcount */

static Lisp_Object CC_ibalp_dimcount(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_dimcount");
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
    v195 = v0;
/* end of prologue */
    v194 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v194;
    v194 = v195;
    stack[-1] = v194;
    goto v196;

v196:
    v194 = stack[-2];
    if (v194 == nil) goto v188;
    v194 = stack[-1];
    v194 = qcar(v194);
    v195 = v194;
    v194 = v195;
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcar(v194);
    if (v194 == nil) goto v149;
    v194 = v195;
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    stack[0] = qcdr(v194);
    v194 = v195;
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v194 = qcdr(v194);
    v195 = qcar(v194);
    v194 = elt(env, 3); /* 0.05 */
    v194 = difference2(v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-3];
    fn = elt(env, 4); /* setcar */
    v194 = (*qfn2(fn))(qenv(fn), stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-3];
    goto v79;

v79:
    v194 = stack[-1];
    v194 = qcdr(v194);
    stack[-1] = v194;
    goto v196;

v149:
    v194 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v194;
    goto v79;

v188:
    v194 = nil;
    { popv(4); return onevalue(v194); }
/* error exit handlers */
v68:
    popv(4);
    return nil;
}



/* Code for reln */

static Lisp_Object CC_reln(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reln");
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
    v197 = elt(env, 1); /* "<reln>" */
    fn = elt(env, 6); /* printout */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    v197 = elt(env, 2); /* "<" */
    v197 = Lprinc(nil, v197);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    v197 = stack[0];
    v197 = Lprinc(nil, v197);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    v197 = elt(env, 3); /* "/>" */
    v197 = Lprinc(nil, v197);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    v142 = qvalue(elt(env, 4)); /* indent */
    v197 = (Lisp_Object)49; /* 3 */
    v197 = plus2(v142, v197);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    qvalue(elt(env, 4)) = v197; /* indent */
    v197 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    v142 = qvalue(elt(env, 4)); /* indent */
    v197 = (Lisp_Object)49; /* 3 */
    v197 = difference2(v142, v197);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    qvalue(elt(env, 4)) = v197; /* indent */
    v197 = elt(env, 5); /* "</reln>" */
    fn = elt(env, 6); /* printout */
    v197 = (*qfn1(fn))(qenv(fn), v197);
    nil = C_nil;
    if (exception_pending()) goto v148;
    v197 = nil;
    { popv(3); return onevalue(v197); }
/* error exit handlers */
v148:
    popv(3);
    return nil;
}



/* Code for makeset */

static Lisp_Object CC_makeset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v38, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeset");
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
    v8 = nil;
    goto v24;

v24:
    v198 = stack[0];
    if (v198 == nil) goto v199;
    v198 = stack[0];
    v38 = qcar(v198);
    v198 = stack[0];
    v198 = qcdr(v198);
    v198 = Lmember(nil, v38, v198);
    if (v198 == nil) goto v39;
    v198 = stack[0];
    v198 = qcdr(v198);
    stack[0] = v198;
    goto v24;

v39:
    v198 = stack[0];
    v198 = qcar(v198);
    v38 = v8;
    v198 = cons(v198, v38);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-1];
    v8 = v198;
    v198 = stack[0];
    v198 = qcdr(v198);
    stack[0] = v198;
    goto v24;

v199:
    v198 = v8;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v198);
    }
/* error exit handlers */
v86:
    popv(2);
    return nil;
}



/* Code for nextcomb */

static Lisp_Object CC_nextcomb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextcomb");
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
    stack[0] = v1;
    v205 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v204 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v204; /* i */
    v204 = v205;
    v204 = qcar(v204);
    stack[-3] = v204;
    v204 = v205;
    v204 = qcdr(v204);
    stack[-1] = v204;
    v205 = stack[0];
    v204 = (Lisp_Object)1; /* 0 */
    if (v205 == v204) goto v74;
    v204 = stack[-3];
    v205 = Llength(nil, v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v204 = stack[0];
    v205 = difference2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    qvalue(elt(env, 1)) = v205; /* i */
    v204 = (Lisp_Object)1; /* 0 */
    v204 = (Lisp_Object)lessp2(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v204 = v204 ? lisp_true : nil;
    env = stack[-4];
    if (v204 == nil) goto v71;
    v204 = qvalue(elt(env, 2)); /* nil */
    v204 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v199;

v199:
    qvalue(elt(env, 1)) = stack[-2]; /* i */
    { popv(5); return onevalue(v204); }

v71:
    v205 = qvalue(elt(env, 1)); /* i */
    v204 = (Lisp_Object)1; /* 0 */
    if (v205 == v204) goto v177;
    v204 = stack[-1];
    if (v204 == nil) goto v206;
    v204 = stack[0];
    v204 = sub1(v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v204 = CC_nextcomb(env, stack[-1], v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v205 = stack[-3];
    stack[-1] = qcar(v205);
    v205 = v204;
    stack[0] = qcar(v205);
    v205 = v204;
    v205 = qcdr(v205);
    if (v205 == nil) goto v64;
    v205 = stack[-3];
    v204 = qcdr(v204);
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v207;

v207:
    v204 = acons(stack[-1], stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v199;

v64:
    v204 = stack[-3];
    v204 = qcdr(v204);
    v204 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v207;

v206:
    v204 = stack[-3];
    v204 = qcdr(v204);
    fn = elt(env, 3); /* initcomb */
    stack[-1] = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v204 = stack[0];
    v204 = sub1(v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v204 = CC_nextcomb(env, stack[-1], v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v205 = stack[-3];
    stack[-1] = qcar(v205);
    v205 = v204;
    stack[0] = qcar(v205);
    v205 = v204;
    v205 = qcdr(v205);
    if (v205 == nil) goto v57;
    v205 = stack[-3];
    v204 = qcdr(v204);
    v204 = cons(v205, v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v23;

v23:
    v204 = acons(stack[-1], stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v199;

v57:
    v204 = stack[-3];
    v204 = qcdr(v204);
    v204 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v23;

v177:
    v204 = stack[-3];
    v204 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v199;

v74:
    v204 = qvalue(elt(env, 2)); /* nil */
    v204 = ncons(v204);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    goto v199;
/* error exit handlers */
v133:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-2]; /* i */
    popv(5);
    return nil;
}



/* Code for equalreplaceby */

static Lisp_Object CC_equalreplaceby(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v196;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equalreplaceby");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v188 = v0;
/* end of prologue */
    v196 = elt(env, 1); /* replaceby */
    return cons(v196, v188);
}



/* Code for ratn */

static Lisp_Object CC_ratn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v209, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v179 = v10;
    if (v179 == nil) goto v199;
    v179 = v10;
    if (!consp(v179)) goto v140;
    v179 = v10;
    v209 = qcar(v179);
    v179 = elt(env, 1); /* !:rn!: */
    if (v209 == v179) goto v185;
    v10 = elt(env, 2); /* arnum */
    v209 = (Lisp_Object)97; /* 6 */
    v179 = elt(env, 3); /* "Illegal domain in :ar:" */
    {
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v10, v209, v179);
    }

v185:
    v179 = v10;
    v179 = qcdr(v179);
    return onevalue(v179);

v140:
    v209 = v10;
    v179 = (Lisp_Object)17; /* 1 */
    return cons(v209, v179);

v199:
    v209 = (Lisp_Object)1; /* 0 */
    v179 = (Lisp_Object)17; /* 1 */
    return cons(v209, v179);
}



/* Code for poly!-minusp */

static Lisp_Object CC_polyKminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v185;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v208 = v0;
/* end of prologue */

v7:
    v185 = v208;
    if (v185 == nil) goto v200;
    v185 = v208;
    if (!consp(v185)) goto v196;
    v185 = v208;
    v185 = qcar(v185);
    if (!consp(v185)) goto v196;
    v208 = qcar(v208);
    v208 = qcdr(v208);
    goto v7;

v196:
        return Lminusp(nil, v208);

v200:
    v208 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v208);
}



/* Code for mksq */

static Lisp_Object CC_mksq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v231, v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksq");
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
    stack[-4] = nil;
    stack[-1] = nil;
    v230 = qvalue(elt(env, 1)); /* subfg!* */
    if (v230 == nil) goto v173;
    v231 = stack[-3];
    v230 = qvalue(elt(env, 2)); /* wtl!* */
    v230 = Lassoc(nil, v231, v230);
    stack[-1] = v230;
    if (v230 == nil) goto v41;
    stack[0] = elt(env, 3); /* k!* */
    v231 = stack[-2];
    v230 = stack[-1];
    v230 = qcdr(v230);
    v230 = times2(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    v230 = CC_mksq(env, stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    stack[-1] = v230;
    v230 = qcar(v230);
    if (v230 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    else goto v41;

v41:
    v230 = stack[-3];
    if (!consp(v230)) goto v178;
    v230 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v230 == nil)) goto v234;
    v230 = stack[-3];
    v230 = qcar(v230);
    if (!(!consp(v230))) goto v234;
    v230 = stack[-3];
    v231 = qcar(v230);
    v230 = elt(env, 13); /* mksqsubfn */
    v230 = get(v231, v230);
    env = stack[-5];
    v231 = v230;
    if (v230 == nil) goto v235;
    v230 = stack[-3];
    v230 = Lapply1(nil, v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    v231 = v230;
    if (!(v230 == nil)) goto v196;

v235:
    v232 = stack[-3];
    v230 = stack[-3];
    v231 = qcar(v230);
    v230 = elt(env, 14); /* kvalue */
    v230 = get(v231, v230);
    env = stack[-5];
    v230 = Lassoc(nil, v232, v230);
    v231 = v230;
    if (!(v230 == nil)) goto v196;

v234:
    stack[0] = elt(env, 6); /* used!* */
    v230 = stack[-3];
    fn = elt(env, 16); /* fkern */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    stack[-4] = v230;
    v230 = qcdr(v230);
    v230 = qcdr(v230);
    v230 = Lmemq(nil, stack[0], v230);
    if (!(v230 == nil)) goto v199;
    v231 = stack[-4];
    v230 = elt(env, 6); /* used!* */
    fn = elt(env, 17); /* aconc */
    v230 = (*qfn2(fn))(qenv(fn), v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    goto v199;

v199:
    v230 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v230 == nil)) goto v173;
    v231 = stack[-2];
    v230 = (Lisp_Object)17; /* 1 */
    if (v231 == v230) goto v173;
    v231 = stack[-3];
    v230 = qvalue(elt(env, 7)); /* asymplis!* */
    v230 = Lassoc(nil, v231, v230);
    v231 = v230;
    if (v230 == nil) goto v13;
    v230 = v231;
    v231 = qcdr(v230);
    v230 = stack[-2];
    v230 = (Lisp_Object)lesseq2(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    v230 = v230 ? lisp_true : nil;
    env = stack[-5];
    if (v230 == nil) goto v13;
    v231 = qvalue(elt(env, 8)); /* nil */
    v230 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v231, v230);

v13:
    v231 = stack[-3];
    v230 = qvalue(elt(env, 9)); /* powlis!* */
    v230 = Lassoc(nil, v231, v230);
    v231 = v230;
    if (!(v230 == nil)) goto v135;
    v230 = stack[-3];
    if (!consp(v230)) goto v173;
    v230 = stack[-3];
    v231 = qcar(v230);
    v230 = elt(env, 10); /* (expt sqrt) */
    v230 = Lmemq(nil, v231, v230);
    if (v230 == nil) goto v173;
    v230 = stack[-3];
    v230 = qcdr(v230);
    v231 = qcar(v230);
    v230 = qvalue(elt(env, 9)); /* powlis!* */
    v230 = Lassoc(nil, v231, v230);
    v231 = v230;
    if (!(v230 == nil)) goto v135;

v173:
    v230 = stack[-4];
    if (!(v230 == nil)) goto v236;
    v230 = stack[-3];
    fn = elt(env, 16); /* fkern */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    stack[-4] = v230;
    goto v236;

v236:
    v231 = stack[-4];
    v230 = stack[-2];
    fn = elt(env, 18); /* getpower */
    v231 = (*qfn2(fn))(qenv(fn), v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    v230 = (Lisp_Object)17; /* 1 */
    v230 = cons(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    v231 = ncons(v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    v230 = (Lisp_Object)17; /* 1 */
    v230 = cons(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    stack[-4] = v230;
    v230 = stack[-1];
    if (v230 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v231 = stack[-1];
    v230 = stack[-4];
    {
        popv(6);
        fn = elt(env, 19); /* multsq */
        return (*qfn2(fn))(qenv(fn), v231, v230);
    }

v135:
    v230 = stack[-2];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    v231 = times2(v230, v231);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    v230 = (Lisp_Object)1; /* 0 */
    v230 = (Lisp_Object)lessp2(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    v230 = v230 ? lisp_true : nil;
    env = stack[-5];
    if (!(v230 == nil)) goto v173;
    v230 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 12)) = v230; /* !*sub2 */
    goto v173;

v196:
    v230 = v231;
    v230 = qcdr(v230);
    v231 = v230;
    v230 = qvalue(elt(env, 15)); /* !*resubs */
    if (!(v230 == nil)) goto v237;
    v230 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 4)) = v230; /* !*nosubs */
    goto v237;

v237:
    v230 = v231;
    fn = elt(env, 20); /* simpcar */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    stack[-4] = v230;
    v230 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 4)) = v230; /* !*nosubs */
    v231 = stack[-4];
    v230 = stack[-2];
    {
        popv(6);
        fn = elt(env, 21); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v231, v230);
    }

v178:
    v230 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v230 == nil)) goto v14;
    v231 = stack[-3];
    v230 = elt(env, 5); /* avalue */
    v230 = get(v231, v230);
    env = stack[-5];
    v231 = v230;
    if (!(v230 == nil)) goto v196;

v14:
    v230 = stack[-3];
    if (!(symbolp(v230))) goto v199;
    v230 = stack[-3];
    v231 = ncons(v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    v230 = elt(env, 6); /* used!* */
    v230 = Lflag(nil, v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-5];
    goto v199;
/* error exit handlers */
v233:
    popv(6);
    return nil;
}



/* Code for token!-number */

static Lisp_Object CC_tokenKnumber(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v256, v237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for token-number");
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
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v158 = (Lisp_Object)1; /* 0 */
    stack[-3] = v158;
    v158 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v158; /* ttype!* */
    goto v173;

v173:
    v158 = stack[-1];
    if (!(v158 == nil)) goto v142;
    v256 = stack[-4];
    v158 = elt(env, 2); /* !) */
    if (!(v256 == v158)) goto v142;

v138:
    v158 = stack[-5];
    if (v158 == nil) goto v209;
    v158 = stack[-3];
    v158 = sub1(v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-3] = v158;
    goto v209;

v209:
    fn = elt(env, 22); /* readch1 */
    v256 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-4] = v256;
    v158 = elt(env, 3); /* !. */
    if (v256 == v158) goto v72;
    v158 = stack[-4];
    v158 = Ldigitp(nil, v158);
    env = stack[-6];
    if (!(v158 == nil)) goto v173;
    v256 = stack[-1];
    v158 = elt(env, 7); /* (!0) */
    if (!(equal(v256, v158))) goto v4;
    v256 = stack[-4];
    v158 = elt(env, 8); /* x */
    if (v256 == v158) goto v15;
    v256 = stack[-4];
    v158 = elt(env, 9); /* !X */
    if (!(v256 == v158)) goto v4;

v15:
    v158 = (Lisp_Object)1; /* 0 */
    stack[-1] = v158;
    goto v223;

v223:
    fn = elt(env, 22); /* readch1 */
    v256 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-4] = v256;
    v158 = elt(env, 16); /* hexdigit */
    v158 = get(v256, v158);
    env = stack[-6];
    stack[0] = v158;
    if (v158 == nil) goto v74;
    v256 = (Lisp_Object)257; /* 16 */
    v158 = stack[-1];
    v256 = times2(v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    v158 = stack[0];
    v158 = plus2(v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-1] = v158;
    goto v223;

v74:
    v158 = stack[-5];
    if (v158 == nil) goto v214;
    v237 = elt(env, 17); /* !:dn!: */
    v256 = stack[-1];
    v158 = stack[-3];
    v158 = list2star(v237, v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    goto v258;

v258:
    qvalue(elt(env, 20)) = v158; /* nxtsym!* */
    v158 = stack[-4];
    qvalue(elt(env, 21)) = v158; /* crchar!* */
    v158 = qvalue(elt(env, 20)); /* nxtsym!* */
    { popv(7); return onevalue(v158); }

v214:
    v158 = qvalue(elt(env, 18)); /* !*adjprec */
    if (v158 == nil) goto v259;
    v237 = elt(env, 19); /* !:int!: */
    v256 = stack[-1];
    v158 = qvalue(elt(env, 15)); /* nil */
    v158 = list2star(v237, v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    goto v258;

v259:
    v158 = stack[-1];
    goto v258;

v4:
    v256 = stack[-4];
    v158 = elt(env, 10); /* !\ */
    if (v256 == v158) goto v61;
    v256 = stack[-4];
    v158 = elt(env, 11); /* e */
    if (v256 == v158) goto v71;
    v256 = stack[-4];
    v158 = elt(env, 12); /* !E */
    if (!(v256 == v158)) goto v175;

v71:
    v158 = qvalue(elt(env, 6)); /* t */
    stack[-5] = v158;
    fn = elt(env, 22); /* readch1 */
    v256 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-4] = v256;
    v158 = elt(env, 13); /* !- */
    if (v256 == v158) goto v260;
    v256 = stack[-4];
    v158 = elt(env, 14); /* !+ */
    if (v256 == v158) goto v196;
    v158 = stack[-4];
    v158 = Ldigitp(nil, v158);
    env = stack[-6];
    if (v158 == nil) goto v175;
    v158 = stack[-4];
    v158 = ncons(v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[0] = v158;
    goto v196;

v196:
    fn = elt(env, 22); /* readch1 */
    v158 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-4] = v158;
    v158 = Ldigitp(nil, v158);
    env = stack[-6];
    if (v158 == nil) goto v176;
    v256 = stack[-4];
    v158 = stack[0];
    v158 = cons(v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[0] = v158;
    goto v196;

v176:
    v158 = stack[0];
    if (!(v158 == nil)) goto v261;
    v237 = elt(env, 4); /* rlisp */
    v256 = (Lisp_Object)65; /* 4 */
    v158 = elt(env, 5); /* "Syntax error: improper number" */
    fn = elt(env, 23); /* rerror */
    v158 = (*qfnn(fn))(qenv(fn), 3, v237, v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    goto v261;

v261:
    v158 = stack[0];
    fn = elt(env, 24); /* reversip!* */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    v158 = Lcompress(nil, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[0] = v158;
    v158 = stack[-2];
    if (v158 == nil) goto v122;
    v256 = stack[-3];
    v158 = stack[0];
    v158 = difference2(v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-3] = v158;
    goto v175;

v175:
    v158 = stack[-1];
    fn = elt(env, 24); /* reversip!* */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    v158 = Lcompress(nil, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-1] = v158;
    goto v74;

v122:
    v256 = stack[-3];
    v158 = stack[0];
    v158 = plus2(v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-3] = v158;
    goto v175;

v260:
    v158 = qvalue(elt(env, 6)); /* t */
    stack[-2] = v158;
    goto v196;

v61:
    v158 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    goto v209;

v72:
    v158 = stack[-5];
    if (v158 == nil) goto v33;
    v237 = elt(env, 4); /* rlisp */
    v256 = (Lisp_Object)49; /* 3 */
    v158 = elt(env, 5); /* "Syntax error: improper number" */
    fn = elt(env, 23); /* rerror */
    v158 = (*qfnn(fn))(qenv(fn), 3, v237, v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    goto v71;

v33:
    v158 = qvalue(elt(env, 6)); /* t */
    stack[-5] = v158;
    goto v209;

v142:
    v256 = stack[-4];
    v158 = stack[-1];
    v158 = cons(v256, v158);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-6];
    stack[-1] = v158;
    goto v138;
/* error exit handlers */
v257:
    popv(7);
    return nil;
}



/* Code for ofsf_sacat */

static Lisp_Object MS_CDECL CC_ofsf_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v20, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v195, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacat");
#endif
    if (stack >= stacklimit)
    {
        push3(v20,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v34 = v20;
    v35 = v1;
    stack[0] = v0;
/* end of prologue */
    v194 = stack[0];
    v194 = qcdr(v194);
    v195 = qcar(v194);
    v194 = v35;
    v194 = qcdr(v194);
    v194 = qcar(v194);
    if (equal(v195, v194)) goto v16;
    v194 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v194); }

v16:
    v194 = stack[0];
    v194 = qcar(v194);
    v195 = v35;
    v195 = qcar(v195);
    fn = elt(env, 3); /* ofsf_sacrel */
    v194 = (*qfnn(fn))(qenv(fn), 3, v194, v195, v34);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    v34 = v194;
    v195 = v34;
    v194 = elt(env, 2); /* (drop keep keep1 keep2) */
    v194 = Lmemq(nil, v195, v194);
    if (!(v194 == nil)) { popv(2); return onevalue(v34); }
    v195 = v34;
    v194 = stack[0];
    v194 = qcdr(v194);
    v194 = qcar(v194);
    v34 = qvalue(elt(env, 1)); /* nil */
    popv(2);
    return list3(v195, v194, v34);
/* error exit handlers */
v68:
    popv(2);
    return nil;
}



/* Code for rl_updcache */

static Lisp_Object MS_CDECL CC_rl_updcache(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v228;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rl_updcache");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_updcache");
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
    v3 = qvalue(elt(env, 1)); /* rl_bbl!* */
    stack[0] = v3;
    goto v7;

v7:
    v3 = stack[0];
    if (v3 == nil) goto v39;
    v3 = stack[0];
    v3 = qcar(v3);
    v228 = v3;
    v3 = qvalue(elt(env, 2)); /* nil */
    v3 = Lset(nil, v228, v3);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    v3 = stack[0];
    v3 = qcdr(v3);
    stack[0] = v3;
    goto v7;

v39:
    v3 = qvalue(elt(env, 3)); /* rl_cid!* */
    v228 = qcar(v3);
    v3 = elt(env, 4); /* rl_params */
    v3 = get(v228, v3);
    env = stack[-1];
    stack[0] = v3;
    goto v73;

v73:
    v3 = stack[0];
    if (v3 == nil) goto v146;
    v3 = stack[0];
    v3 = qcar(v3);
    v228 = v3;
    v228 = qcar(v228);
    v3 = qcdr(v3);
    v3 = Lset(nil, v228, v3);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    v3 = stack[0];
    v3 = qcdr(v3);
    stack[0] = v3;
    goto v73;

v146:
    v3 = qvalue(elt(env, 5)); /* rl_servl!* */
    stack[0] = v3;
    goto v194;

v194:
    v3 = stack[0];
    if (v3 == nil) goto v30;
    v3 = stack[0];
    v3 = qcar(v3);
    v228 = v3;
    v3 = qvalue(elt(env, 2)); /* nil */
    v3 = Lset(nil, v228, v3);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    v3 = stack[0];
    v3 = qcdr(v3);
    stack[0] = v3;
    goto v194;

v30:
    v3 = qvalue(elt(env, 3)); /* rl_cid!* */
    v228 = qcar(v3);
    v3 = elt(env, 6); /* rl_services */
    v3 = get(v228, v3);
    env = stack[-1];
    stack[0] = v3;
    goto v28;

v28:
    v3 = stack[0];
    if (v3 == nil) goto v129;
    v3 = stack[0];
    v3 = qcar(v3);
    v228 = v3;
    v228 = qcar(v228);
    v3 = qcdr(v3);
    v3 = Lset(nil, v228, v3);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    v3 = stack[0];
    v3 = qcdr(v3);
    stack[0] = v3;
    goto v28;

v129:
    v3 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v3); }
/* error exit handlers */
v21:
    popv(2);
    return nil;
}



/* Code for add2resultbuf */

static Lisp_Object CC_add2resultbuf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v139, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2resultbuf");
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
    v18 = v1;
    stack[0] = v0;
/* end of prologue */
    v150 = v18;
    v139 = elt(env, 1); /* symbolic */
    if (v150 == v139) goto v200;
    v139 = stack[0];
    if (!(v139 == nil)) goto v42;
    v139 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v139 == nil) goto v200;
    v150 = v18;
    v139 = elt(env, 3); /* empty_list */
    if (!(v150 == v139)) goto v200;

v42:
    v139 = qvalue(elt(env, 4)); /* !*nosave!* */
    if (!(v139 == nil)) goto v200;
    v139 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v139 == nil) goto v72;
    v150 = elt(env, 6); /* ws */
    v139 = stack[0];
    fn = elt(env, 10); /* putobject */
    v18 = (*qfnn(fn))(qenv(fn), 3, v150, v139, v18);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    goto v141;

v141:
    fn = elt(env, 11); /* terminalp */
    v18 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    if (v18 == nil) goto v265;
    v150 = qvalue(elt(env, 8)); /* statcounter */
    v139 = stack[0];
    v18 = qvalue(elt(env, 9)); /* resultbuflis!* */
    v18 = acons(v150, v139, v18);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    qvalue(elt(env, 9)) = v18; /* resultbuflis!* */
    goto v265;

v265:
    v18 = nil;
    { popv(2); return onevalue(v18); }

v72:
    v18 = qvalue(elt(env, 5)); /* nil */
    v18 = ncons(v18);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    qvalue(elt(env, 7)) = v18; /* alglist!* */
    v18 = stack[0];
    qvalue(elt(env, 6)) = v18; /* ws */
    goto v141;

v200:
    v18 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v18); }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for ps!:evaluate!-next */

static Lisp_Object CC_psTevaluateKnext(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v265, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate-next");
#endif
    if (stack >= stacklimit)
    {
        push2(v20,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v20;
    v265 = v1;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v265; /* ps */
    v70 = qvalue(elt(env, 1)); /* ps */
    v265 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 3); /* ps!:getv */
    v265 = (*qfn2(fn))(qenv(fn), v70, v265);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v70 = qcar(v265);
    v265 = elt(env, 2); /* ps!:erule */
    stack[0] = get(v70, v265);
    env = stack[-4];
    v265 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:expression */
    v70 = (*qfn1(fn))(qenv(fn), v265);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v265 = stack[-2];
    v265 = list2(v70, v265);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    fn = elt(env, 5); /* apply */
    v265 = (*qfn2(fn))(qenv(fn), stack[0], v265);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    stack[-1] = v265;
    stack[0] = qvalue(elt(env, 1)); /* ps */
    v265 = stack[-1];
    fn = elt(env, 6); /* prepsqxx */
    v265 = (*qfn1(fn))(qenv(fn), v265);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    fn = elt(env, 7); /* simp!* */
    v265 = (*qfn1(fn))(qenv(fn), v265);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    stack[-1] = v265;
    fn = elt(env, 8); /* ps!:set!-term */
    v265 = (*qfnn(fn))(qenv(fn), 3, stack[0], stack[-2], v265);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-4];
    v265 = stack[-1];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v265); }
/* error exit handlers */
v194:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for take!-realpart */

static Lisp_Object CC_takeKrealpart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for take-realpart");
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
    stack[0] = v0;
/* end of prologue */
    v14 = stack[0];
    v14 = qcar(v14);
    fn = elt(env, 1); /* repartf */
    v176 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v14 = stack[0];
    v14 = qcdr(v14);
    popv(1);
    return cons(v176, v14);
/* error exit handlers */
v74:
    popv(1);
    return nil;
}



/* Code for rd!:zerop!: */

static Lisp_Object CC_rdTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:zerop:");
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
    v42 = v0;
/* end of prologue */
    v74 = v42;
    v74 = qcdr(v74);
    if (!consp(v74)) goto v7;
    v74 = v42;
    fn = elt(env, 1); /* round!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bfzerop!: */
        return (*qfn1(fn))(qenv(fn), v74);
    }

v7:
    v74 = v42;
    v74 = qcdr(v74);
    {
        popv(1);
        fn = elt(env, 3); /* ft!:zerop */
        return (*qfn1(fn))(qenv(fn), v74);
    }
/* error exit handlers */
v41:
    popv(1);
    return nil;
}



/* Code for arglist_member */

static Lisp_Object CC_arglist_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arglist_member");
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

v268:
    v170 = stack[0];
    if (!consp(v170)) goto v24;
    v197 = stack[-1];
    v170 = stack[0];
    v170 = qcar(v170);
    fn = elt(env, 2); /* mvar_member */
    v170 = (*qfn2(fn))(qenv(fn), v197, v170);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    if (!(v170 == nil)) { popv(3); return onevalue(v170); }
    v197 = stack[-1];
    v170 = stack[0];
    v170 = qcdr(v170);
    stack[-1] = v197;
    stack[0] = v170;
    goto v268;

v24:
    v170 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v170); }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for groedeletip */

static Lisp_Object CC_groedeletip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groedeletip");
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

v199:
    v139 = stack[0];
    if (v139 == nil) goto v200;
    v150 = stack[-1];
    v139 = stack[0];
    v139 = qcar(v139);
    if (!(equal(v150, v139))) goto v200;
    v139 = stack[0];
    v139 = qcdr(v139);
    stack[0] = v139;
    goto v199;

v200:
    v139 = stack[0];
    if (v139 == nil) goto v40;
    v139 = stack[0];
    stack[-2] = v139;
    goto v48;

v48:
    v139 = stack[0];
    v139 = qcdr(v139);
    if (v139 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v150 = stack[-1];
    v139 = stack[0];
    v139 = qcdr(v139);
    v139 = qcar(v139);
    if (equal(v150, v139)) goto v11;
    v139 = stack[0];
    v139 = qcdr(v139);
    stack[0] = v139;
    goto v48;

v11:
    v150 = stack[0];
    v139 = stack[0];
    v139 = qcdr(v139);
    v139 = qcdr(v139);
    fn = elt(env, 2); /* setcdr */
    v139 = (*qfn2(fn))(qenv(fn), v150, v139);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-3];
    goto v48;

v40:
    v139 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v139); }
/* error exit handlers */
v270:
    popv(4);
    return nil;
}



/* Code for freeoff */

static Lisp_Object CC_freeoff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeoff");
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

v24:
    v27 = stack[-1];
    if (!consp(v27)) goto v199;
    v27 = stack[-1];
    v27 = qcar(v27);
    if (!consp(v27)) goto v199;
    v27 = stack[-1];
    v27 = qcar(v27);
    v27 = qcar(v27);
    v27 = qcar(v27);
    fn = elt(env, 3); /* sfp */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    if (v27 == nil) goto v68;
    v27 = stack[-1];
    v27 = qcar(v27);
    v27 = qcar(v27);
    v2 = qcar(v27);
    v27 = stack[0];
    v27 = CC_freeoff(env, v2, v27);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    if (v27 == nil) goto v70;
    v27 = stack[-1];
    v27 = qcar(v27);
    v2 = qcdr(v27);
    v27 = stack[0];
    v27 = CC_freeoff(env, v2, v27);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    if (v27 == nil) goto v36;
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    goto v24;

v36:
    v27 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v27); }

v70:
    v27 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v27); }

v68:
    v27 = stack[-1];
    v27 = qcar(v27);
    v27 = qcar(v27);
    v2 = qcar(v27);
    v27 = stack[0];
    fn = elt(env, 4); /* ndepends */
    v27 = (*qfn2(fn))(qenv(fn), v2, v27);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    if (v27 == nil) goto v19;
    v27 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v27); }

v19:
    v27 = stack[-1];
    v27 = qcar(v27);
    v2 = qcdr(v27);
    v27 = stack[0];
    v27 = CC_freeoff(env, v2, v27);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-2];
    if (v27 == nil) goto v190;
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    goto v24;

v190:
    v27 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v27); }

v199:
    v27 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v27); }
/* error exit handlers */
v271:
    popv(3);
    return nil;
}



/* Code for rd!:times */

static Lisp_Object CC_rdTtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:times");
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
    v51 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (!(v51 == nil)) goto v174;
    v51 = stack[-2];
    v51 = qcdr(v51);
    if (!(!consp(v51))) goto v174;
    v51 = stack[-1];
    v51 = qcdr(v51);
    if (!(!consp(v51))) goto v174;
    v51 = stack[-2];
    v52 = qcdr(v51);
    v51 = stack[-1];
    v51 = qcdr(v51);
    fn = elt(env, 6); /* safe!-fp!-times */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[0] = v51;
    if (v51 == nil) goto v174;
    v52 = elt(env, 3); /* !:rd!: */
    v51 = stack[0];
    popv(5);
    return cons(v52, v51);

v174:
    v52 = stack[-2];
    v51 = stack[-1];
    fn = elt(env, 7); /* convprc2 */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[-3] = v51;
    v51 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v51;
    v51 = stack[-3];
    if (!consp(v51)) goto v32;
    v52 = stack[-3];
    v51 = stack[-2];
    fn = elt(env, 8); /* csl_timbf */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v10;

v10:
    {
        popv(5);
        fn = elt(env, 9); /* mkround */
        return (*qfn1(fn))(qenv(fn), v51);
    }

v32:
    stack[-1] = elt(env, 5); /* times2 */
    v51 = stack[-3];
    stack[0] = Lmkquote(nil, v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    v51 = stack[-2];
    v51 = Lmkquote(nil, v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    v52 = list3(stack[-1], stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    v51 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 10); /* errorset!* */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[0] = v51;
    v51 = stack[0];
    fn = elt(env, 11); /* errorp */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    if (v51 == nil) goto v227;
    fn = elt(env, 12); /* rndbfon */
    v51 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    v51 = stack[-3];
    v51 = Lfloatp(nil, v51);
    env = stack[-4];
    if (v51 == nil) goto v26;
    v51 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[0] = v51;
    goto v64;

v64:
    v51 = stack[-2];
    v51 = Lfloatp(nil, v51);
    env = stack[-4];
    if (v51 == nil) goto v181;
    v51 = stack[-2];
    fn = elt(env, 13); /* fl2bf */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v129;

v129:
    fn = elt(env, 8); /* csl_timbf */
    v51 = (*qfn2(fn))(qenv(fn), stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v10;

v181:
    v51 = stack[-2];
    if (!consp(v51)) goto v131;
    v51 = stack[-2];
    goto v205;

v205:
    fn = elt(env, 14); /* csl_normbf */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v129;

v131:
    v51 = stack[-2];
    v51 = integerp(v51);
    if (v51 == nil) goto v186;
    v75 = elt(env, 3); /* !:rd!: */
    v52 = stack[-2];
    v51 = (Lisp_Object)1; /* 0 */
    v51 = list2star(v75, v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v205;

v186:
    v51 = stack[-2];
    fn = elt(env, 15); /* read!:num */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v205;

v26:
    v51 = stack[-3];
    if (!consp(v51)) goto v263;
    v51 = stack[-3];
    goto v262;

v262:
    fn = elt(env, 14); /* csl_normbf */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[0] = v51;
    goto v64;

v263:
    v51 = stack[-3];
    v51 = integerp(v51);
    if (v51 == nil) goto v151;
    v75 = elt(env, 3); /* !:rd!: */
    v52 = stack[-3];
    v51 = (Lisp_Object)1; /* 0 */
    v51 = list2star(v75, v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v262;

v151:
    v51 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v262;

v227:
    v51 = stack[0];
    v51 = qcar(v51);
    goto v10;
/* error exit handlers */
v272:
    popv(5);
    return nil;
}



/* Code for physopordchk */

static Lisp_Object CC_physopordchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v11, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopordchk");
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
    v70 = v0;
/* end of prologue */
    fn = elt(env, 4); /* !*collectphysops */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-2];
    stack[-1] = v70;
    v70 = stack[0];
    fn = elt(env, 4); /* !*collectphysops */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-2];
    v9 = v70;
    v70 = stack[-1];
    if (v70 == nil) goto v41;
    v70 = v9;
    if (v70 == nil) goto v149;
    v11 = elt(env, 3); /* unit */
    v70 = stack[-1];
    v70 = Lmember(nil, v11, v70);
    if (!(v70 == nil)) goto v185;
    v11 = elt(env, 3); /* unit */
    v70 = v9;
    v70 = Lmember(nil, v11, v70);
    if (!(v70 == nil)) goto v185;
    v70 = stack[-1];
    v11 = v9;
    {
        popv(3);
        fn = elt(env, 6); /* physopordchk!* */
        return (*qfn2(fn))(qenv(fn), v70, v11);
    }

v185:
    v70 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v70); }

v149:
    v70 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v70); }

v41:
    v70 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v70); }
/* error exit handlers */
v194:
    popv(3);
    return nil;
}



/* Code for moid_member */

static Lisp_Object CC_moid_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moid_member");
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

v268:
    v170 = stack[0];
    if (v170 == nil) goto v24;
    v170 = stack[0];
    v197 = qcar(v170);
    v170 = stack[-1];
    fn = elt(env, 2); /* mo_vdivides!? */
    v170 = (*qfn2(fn))(qenv(fn), v197, v170);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    if (!(v170 == nil)) { popv(3); return onevalue(v170); }
    v197 = stack[-1];
    v170 = stack[0];
    v170 = qcdr(v170);
    stack[-1] = v197;
    stack[0] = v170;
    goto v268;

v24:
    v170 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v170); }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for simp!-prop!-order */

static Lisp_Object CC_simpKpropKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v192, v193, v177;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-order");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v192 = v1;
    v193 = v0;
/* end of prologue */

v24:
    v86 = v193;
    if (v86 == nil) goto v199;
    v86 = v193;
    v86 = qcar(v86);
    v177 = qcar(v86);
    v86 = v192;
    v86 = qcar(v86);
    v86 = qcar(v86);
    if (equal(v177, v86)) goto v15;
    v86 = v193;
    v86 = qcar(v86);
    v192 = qcar(v86);
    v86 = elt(env, 2); /* prop!* */
    if (v192 == v86) goto v40;
    v86 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v86);

v40:
    v86 = qvalue(elt(env, 3)); /* t */
    return onevalue(v86);

v15:
    v86 = v193;
    v86 = qcdr(v86);
    v193 = v86;
    v86 = v192;
    v86 = qcdr(v86);
    v192 = v86;
    goto v24;

v199:
    v86 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v86);
}



/* Code for gcdout */

static Lisp_Object CC_gcdout(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdout");
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
    v28 = qvalue(elt(env, 1)); /* !*modular */
    if (!(v28 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v28 = stack[0];
    if (v28 == nil) goto v199;
    v28 = stack[0];
    fn = elt(env, 3); /* ljet */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    fn = elt(env, 4); /* ord */
    v29 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    v28 = (Lisp_Object)1; /* 0 */
    if (v29 == v28) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v28 = stack[0];
    stack[-1] = v28;
    v28 = stack[-1];
    v28 = qcar(v28);
    v28 = qcdr(v28);
    v30 = v28;
    goto v48;

v48:
    v28 = stack[-1];
    if (v28 == nil) goto v69;
    v29 = v30;
    v28 = (Lisp_Object)17; /* 1 */
    if (v29 == v28) goto v69;
    v29 = v30;
    v28 = stack[-1];
    v28 = qcar(v28);
    v28 = qcdr(v28);
    fn = elt(env, 5); /* gcdf!* */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v254;
    env = stack[-2];
    v30 = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v48;

v69:
    v29 = v30;
    v28 = (Lisp_Object)17; /* 1 */
    if (v29 == v28) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v28 = stack[0];
    v29 = v30;
    {
        popv(3);
        fn = elt(env, 6); /* pcdiv */
        return (*qfn2(fn))(qenv(fn), v28, v29);
    }

v199:
    v28 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v28); }
/* error exit handlers */
v254:
    popv(3);
    return nil;
}



/* Code for charnump!: */

static Lisp_Object CC_charnumpT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37, v265, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for charnump:");
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
    v36 = v0;
/* end of prologue */
    stack[-6] = v36;
    stack[-5] = elt(env, 1); /* !0 */
    stack[-4] = elt(env, 2); /* !1 */
    stack[-3] = elt(env, 3); /* !2 */
    stack[-2] = elt(env, 4); /* !3 */
    stack[-1] = elt(env, 5); /* !4 */
    stack[0] = elt(env, 6); /* !5 */
    v70 = elt(env, 7); /* !6 */
    v265 = elt(env, 8); /* !7 */
    v37 = elt(env, 9); /* !8 */
    v36 = elt(env, 10); /* !9 */
    v36 = list4(v70, v265, v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    v36 = list3star(stack[-2], stack[-1], stack[0], v36);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    v36 = list3star(stack[-5], stack[-4], stack[-3], v36);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-7];
    v36 = Lmember(nil, stack[-6], v36);
    if (v36 == nil) goto v24;
    v36 = qvalue(elt(env, 11)); /* t */
    { popv(8); return onevalue(v36); }

v24:
    v36 = nil;
    { popv(8); return onevalue(v36); }
/* error exit handlers */
v35:
    popv(8);
    return nil;
}



/* Code for subf */

static Lisp_Object CC_subf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subf");
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
    stack[-7] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    stack[-4] = nil;
    v76 = qvalue(elt(env, 2)); /* nil */
    v76 = ncons(v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    qvalue(elt(env, 1)) = v76; /* alglist!* */
    v76 = stack[-6];
    if (!consp(v76)) goto v14;
    v76 = stack[-6];
    v76 = qcar(v76);
    if (!consp(v76)) goto v14;
    v76 = qvalue(elt(env, 3)); /* ncmp!* */
    if (v76 == nil) goto v255;
    v76 = stack[-6];
    fn = elt(env, 6); /* noncomexpf */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    if (v76 == nil) goto v255;
    v77 = stack[-6];
    v76 = stack[-5];
    fn = elt(env, 7); /* subf1 */
    v76 = (*qfn2(fn))(qenv(fn), v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    goto v199;

v199:
    qvalue(elt(env, 1)) = stack[-7]; /* alglist!* */
    { popv(9); return onevalue(v76); }

v255:
    v76 = stack[-5];
    stack[-3] = v76;
    v76 = stack[-3];
    if (v76 == nil) goto v10;
    v76 = stack[-3];
    v76 = qcar(v76);
    v76 = qcar(v76);
    v76 = ncons(v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    stack[-1] = v76;
    stack[-2] = v76;
    goto v71;

v71:
    v76 = stack[-3];
    v76 = qcdr(v76);
    stack[-3] = v76;
    v76 = stack[-3];
    if (v76 == nil) goto v68;
    stack[0] = stack[-1];
    v76 = stack[-3];
    v76 = qcar(v76);
    v76 = qcar(v76);
    v76 = ncons(v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = Lrplacd(nil, stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = stack[-1];
    v76 = qcdr(v76);
    stack[-1] = v76;
    goto v71;

v68:
    v76 = stack[-2];
    stack[0] = v76;
    goto v29;

v29:
    v77 = stack[-6];
    v76 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 8); /* kernord */
    v76 = (*qfn2(fn))(qenv(fn), v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    fn = elt(env, 9); /* intersection */
    v76 = (*qfn2(fn))(qenv(fn), stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = Lreverse(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    stack[0] = v76;
    v76 = stack[0];
    fn = elt(env, 10); /* setkorder */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    stack[0] = v76;
    v76 = stack[-6];
    fn = elt(env, 11); /* reorder */
    v77 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = stack[-5];
    fn = elt(env, 7); /* subf1 */
    v76 = (*qfn2(fn))(qenv(fn), v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    stack[-6] = v76;
    goto v202;

v202:
    v77 = stack[-6];
    v76 = stack[-4];
    v76 = Lmember(nil, v77, v76);
    if (!(v76 == nil)) goto v279;
    stack[-1] = elt(env, 4); /* expt */
    v76 = stack[-6];
    v76 = qcar(v76);
    fn = elt(env, 12); /* kernels */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = Latsoc(nil, stack[-1], v76);
    if (!(v76 == nil)) goto v280;
    stack[-1] = elt(env, 4); /* expt */
    v76 = stack[-6];
    v76 = qcdr(v76);
    fn = elt(env, 12); /* kernels */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = Latsoc(nil, stack[-1], v76);
    if (!(v76 == nil)) goto v280;

v279:
    v76 = stack[0];
    fn = elt(env, 10); /* setkorder */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = stack[-6];
    v76 = qcar(v76);
    fn = elt(env, 11); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = stack[-6];
    v76 = qcdr(v76);
    fn = elt(env, 11); /* reorder */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    v76 = cons(stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    goto v199;

v280:
    v76 = stack[-6];
    fn = elt(env, 13); /* prepsq */
    v77 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    stack[-1] = v77;
    v76 = qvalue(elt(env, 5)); /* varstack!* */
    v76 = Lmember(nil, v77, v76);
    if (!(v76 == nil)) goto v279;
    v77 = stack[-6];
    v76 = stack[-4];
    v76 = cons(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    stack[-4] = v76;
    v76 = stack[-1];
    fn = elt(env, 14); /* simp */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    stack[-6] = v76;
    goto v202;

v10:
    v76 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v76;
    goto v29;

v14:
    v76 = stack[-6];
    fn = elt(env, 15); /* !*d2q */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v278;
    env = stack[-8];
    goto v199;
/* error exit handlers */
v278:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-7]; /* alglist!* */
    popv(9);
    return nil;
}



/* Code for cl_simpl */

static Lisp_Object MS_CDECL CC_cl_simpl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v20, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v19, v85, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_simpl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_simpl");
#endif
    if (stack >= stacklimit)
    {
        push3(v20,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v20;
    v19 = v1;
    stack[-3] = v0;
/* end of prologue */
    v67 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v67 == nil) goto v14;
    v67 = v19;
    fn = elt(env, 6); /* cl_sitheo */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-5];
    v19 = v67;
    v85 = v19;
    v67 = elt(env, 3); /* inctheo */
    if (v85 == v67) goto v39;
    stack[-4] = elt(env, 4); /* and */
    stack[-1] = v19;
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v67 = stack[-2];
    v67 = add1(v67);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-5];
    fn = elt(env, 7); /* rl_smupdknowl */
    v67 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-1], stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-5];
    v19 = v67;
    v85 = v19;
    v67 = elt(env, 5); /* false */
    if (v85 == v67) goto v70;
    v184 = stack[-3];
    v85 = v19;
    v19 = stack[-2];
    v67 = qvalue(elt(env, 2)); /* nil */
    {
        popv(6);
        fn = elt(env, 8); /* cl_simpl1 */
        return (*qfnn(fn))(qenv(fn), 4, v184, v85, v19, v67);
    }

v70:
    v67 = elt(env, 3); /* inctheo */
    { popv(6); return onevalue(v67); }

v39:
    v67 = elt(env, 3); /* inctheo */
    { popv(6); return onevalue(v67); }

v14:
    v184 = stack[-3];
    v85 = qvalue(elt(env, 2)); /* nil */
    v19 = stack[-2];
    v67 = qvalue(elt(env, 2)); /* nil */
    {
        popv(6);
        fn = elt(env, 8); /* cl_simpl1 */
        return (*qfnn(fn))(qenv(fn), 4, v184, v85, v19, v67);
    }
/* error exit handlers */
v31:
    popv(6);
    return nil;
}



/* Code for sort!-factors */

static Lisp_Object CC_sortKfactors(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sort-factors");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v188 = v0;
/* end of prologue */
    v196 = v188;
    v188 = elt(env, 1); /* orderfactors */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v196, v188);
    }
}



/* Code for simpqg */

static Lisp_Object CC_simpqg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpqg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v188 = v0;
/* end of prologue */
    v196 = v188;
    v188 = elt(env, 1); /* qg */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v196, v188);
    }
}



/* Code for ibalp_dellit */

static Lisp_Object MS_CDECL CC_ibalp_dellit(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v20, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_dellit");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_dellit");
#endif
    if (stack >= stacklimit)
    {
        push3(v20,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v29 = v20;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    if (v29 == nil) goto v178;
    v29 = stack[-1];
    v29 = qcdr(v29);
    stack[-2] = qcdr(v29);
    v30 = stack[0];
    v29 = stack[-1];
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcar(v29);
    fn = elt(env, 1); /* delq */
    v29 = (*qfn2(fn))(qenv(fn), v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-3];
    fn = elt(env, 2); /* setcar */
    v29 = (*qfn2(fn))(qenv(fn), stack[-2], v29);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-3];
    stack[-2] = stack[0];
    v30 = stack[-1];
    v29 = stack[0];
    v29 = qcar(v29);
    fn = elt(env, 1); /* delq */
    v29 = (*qfn2(fn))(qenv(fn), v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-3];
    {
        Lisp_Object v190 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* setcar */
        return (*qfn2(fn))(qenv(fn), v190, v29);
    }

v178:
    v29 = stack[-1];
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    stack[-2] = qcdr(v29);
    v30 = stack[0];
    v29 = stack[-1];
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcar(v29);
    fn = elt(env, 1); /* delq */
    v29 = (*qfn2(fn))(qenv(fn), v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-3];
    fn = elt(env, 2); /* setcar */
    v29 = (*qfn2(fn))(qenv(fn), stack[-2], v29);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-3];
    v29 = stack[0];
    stack[-2] = qcdr(v29);
    v30 = stack[-1];
    v29 = stack[0];
    v29 = qcdr(v29);
    v29 = qcar(v29);
    fn = elt(env, 1); /* delq */
    v29 = (*qfn2(fn))(qenv(fn), v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-3];
    {
        Lisp_Object v49 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* setcar */
        return (*qfn2(fn))(qenv(fn), v49, v29);
    }
/* error exit handlers */
v276:
    popv(4);
    return nil;
}



/* Code for form */

static Lisp_Object CC_form(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v271, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form");
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
    v271 = v0;
/* end of prologue */
    v50 = v271;
    if (!consp(v50)) goto v24;
    v50 = v271;
    v152 = qcar(v50);
    v50 = elt(env, 1); /* always_nform */
    v50 = Lflagp(nil, v152, v50);
    env = stack[0];
    if (v50 == nil) goto v24;
    v50 = v271;
    {
        popv(1);
        fn = elt(env, 9); /* n_form */
        return (*qfn1(fn))(qenv(fn), v50);
    }

v24:
    v50 = qvalue(elt(env, 2)); /* !*rlisp88 */
    if (v50 == nil) goto v16;
    v152 = qvalue(elt(env, 4)); /* !*mode */
    v50 = elt(env, 5); /* symbolic */
    if (!(v152 == v50)) goto v19;
    v152 = v271;
    v50 = elt(env, 6); /* modefn */
    v50 = Lflagp(nil, v152, v50);
    env = stack[0];
    if (v50 == nil) goto v35;
    v152 = v271;
    v50 = elt(env, 5); /* symbolic */
    if (!(v152 == v50)) goto v19;

v35:
    v152 = v271;
    v50 = elt(env, 6); /* modefn */
    v50 = Lflagpcar(nil, v152, v50);
    env = stack[0];
    if (v50 == nil) goto v276;
    v50 = v271;
    v152 = qcar(v50);
    v50 = elt(env, 5); /* symbolic */
    if (!(v152 == v50)) goto v19;

v276:
    v152 = v271;
    v271 = qvalue(elt(env, 3)); /* !*vars!* */
    v50 = qvalue(elt(env, 4)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 10); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v152, v271, v50);
    }

v19:
    v271 = elt(env, 7); /* "algebraic expression" */
    v50 = elt(env, 8); /* "Rlisp88 form" */
    {
        popv(1);
        fn = elt(env, 11); /* typerr */
        return (*qfn2(fn))(qenv(fn), v271, v50);
    }

v16:
    v152 = v271;
    v271 = qvalue(elt(env, 3)); /* !*vars!* */
    v50 = qvalue(elt(env, 4)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 10); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v152, v271, v50);
    }
}



/* Code for take!-impart */

static Lisp_Object CC_takeKimpart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for take-impart");
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
    stack[0] = v0;
/* end of prologue */
    v14 = stack[0];
    v14 = qcar(v14);
    fn = elt(env, 1); /* impartf */
    v176 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v14 = stack[0];
    v14 = qcdr(v14);
    popv(1);
    return cons(v176, v14);
/* error exit handlers */
v74:
    popv(1);
    return nil;
}



/* Code for rowdel */

static Lisp_Object CC_rowdel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v270, v277;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rowdel");
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
    v207 = stack[0];
    fn = elt(env, 4); /* delhisto */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v270 = qvalue(elt(env, 2)); /* maxvar */
    v207 = stack[0];
    v207 = plus2(v270, v207);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v277 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v207/(16/CELL)));
    v270 = (Lisp_Object)1; /* 0 */
    v207 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v277 + (CELL-TAG_VECTOR) + ((int32_t)v270/(16/CELL))) = v207;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v270 = qvalue(elt(env, 2)); /* maxvar */
    v207 = stack[0];
    v207 = plus2(v270, v207);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v270 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v207/(16/CELL)));
    v207 = (Lisp_Object)65; /* 4 */
    v207 = *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v207/(16/CELL)));
    stack[0] = v207;
    goto v171;

v171:
    v207 = stack[0];
    if (v207 == nil) goto v265;
    v207 = stack[0];
    v207 = qcar(v207);
    v270 = v207;
    v270 = qcar(v270);
    v207 = qcdr(v207);
    v207 = qcar(v207);
    fn = elt(env, 5); /* downwght */
    v207 = (*qfn2(fn))(qenv(fn), v270, v207);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v207 = stack[0];
    v207 = qcdr(v207);
    stack[0] = v207;
    goto v171;

v265:
    v207 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v207); }
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for mktails */

static Lisp_Object MS_CDECL CC_mktails(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v20, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v69, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktails");
#endif
    if (stack >= stacklimit)
    {
        push3(v20,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v69 = v20;
    stack[-2] = v1;
    v266 = v0;
/* end of prologue */
    stack[0] = nil;
    v68 = v266;
    if (v68 == nil) goto v74;
    v68 = v266;
    stack[-3] = v68;
    v68 = v69;
    stack[-1] = v68;
    goto v146;

v146:
    v68 = stack[-3];
    if (v68 == nil) goto v80;
    v68 = stack[-3];
    v266 = qcar(v68);
    v69 = stack[-2];
    v68 = stack[-1];
    fn = elt(env, 2); /* mktails1 */
    v68 = (*qfnn(fn))(qenv(fn), 3, v266, v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    v69 = v68;
    v68 = v69;
    v68 = qcdr(v68);
    stack[-1] = v68;
    v68 = v69;
    v69 = qcar(v68);
    v68 = stack[0];
    v68 = Lappend(nil, v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-4];
    stack[0] = v68;
    v68 = stack[-3];
    v68 = qcdr(v68);
    stack[-3] = v68;
    goto v146;

v80:
    v69 = stack[0];
    v68 = stack[-1];
    popv(5);
    return cons(v69, v68);

v74:
    v68 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return cons(v68, v69);
/* error exit handlers */
v32:
    popv(5);
    return nil;
}



/* Code for copy!-tree */

static Lisp_Object CC_copyKtree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v273, v28, v29, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy-tree");
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
    v273 = stack[-2];
    if (v273 == nil) goto v7;
    v273 = (Lisp_Object)49; /* 3 */
    v273 = Lmkvect(nil, v273);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    stack[-3] = v273;
    v30 = stack[-3];
    v29 = (Lisp_Object)1; /* 0 */
    v28 = stack[-2];
    v273 = (Lisp_Object)1; /* 0 */
    v273 = *(Lisp_Object *)((char *)v28 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v29/(16/CELL))) = v273;
    v30 = stack[-3];
    v29 = (Lisp_Object)17; /* 1 */
    v28 = stack[-2];
    v273 = (Lisp_Object)17; /* 1 */
    v273 = *(Lisp_Object *)((char *)v28 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v29/(16/CELL))) = v273;
    v30 = stack[-3];
    v29 = (Lisp_Object)33; /* 2 */
    v28 = stack[-2];
    v273 = (Lisp_Object)33; /* 2 */
    v273 = *(Lisp_Object *)((char *)v28 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v29/(16/CELL))) = v273;
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)49; /* 3 */
    v28 = stack[-2];
    v273 = (Lisp_Object)49; /* 3 */
    v273 = *(Lisp_Object *)((char *)v28 + (CELL-TAG_VECTOR) + ((int32_t)v273/(16/CELL)));
    v273 = CC_copyKtree(env, v273);
    nil = C_nil;
    if (exception_pending()) goto v190;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v273;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v7:
    v273 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v273); }
/* error exit handlers */
v190:
    popv(5);
    return nil;
}



/* Code for red_topredbe */

static Lisp_Object CC_red_topredbe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_topredbe");
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
    v18 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    if (v18 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v18 = stack[-2];
    if (v18 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    fn = elt(env, 4); /* cali_trace */
    v139 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    v18 = (Lisp_Object)1265; /* 79 */
    v18 = (Lisp_Object)greaterp2(v139, v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v18 = v18 ? lisp_true : nil;
    env = stack[-4];
    if (v18 == nil) goto v255;
    v18 = elt(env, 1); /* " reduce " */
    v18 = Lprinc(nil, v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    v18 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    fn = elt(env, 5); /* dp_print */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    goto v255;

v255:
    v18 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    v139 = v18;
    if (v18 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    stack[-3] = stack[-2];
    v18 = v139;
    fn = elt(env, 6); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    v18 = stack[-1];
    fn = elt(env, 7); /* bas_dpecart */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    fn = elt(env, 8); /* red_divtestbe */
    v139 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    v18 = v139;
    if (v139 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v139 = stack[-1];
    fn = elt(env, 9); /* red_subst */
    v18 = (*qfn2(fn))(qenv(fn), v139, v18);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    stack[-1] = v18;
    goto v255;
/* error exit handlers */
v270:
    popv(5);
    return nil;
}



setup_type const u17_setup[] =
{
    {"ibalp_isinminclause",     too_few_2,      CC_ibalp_isinminclause,wrong_no_2},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"setdmode",                too_few_2,      CC_setdmode,   wrong_no_2},
    {"physopsimp",              CC_physopsimp,  too_many_1,    wrong_no_1},
    {"mv-domainlist-+",         too_few_2,      CC_mvKdomainlistKL,wrong_no_2},
    {"set-general-modulus",     CC_setKgeneralKmodulus,too_many_1,wrong_no_1},
    {"general-modular-expt",    too_few_2,      CC_generalKmodularKexpt,wrong_no_2},
    {"ibalp_dimcount",          CC_ibalp_dimcount,too_many_1,  wrong_no_1},
    {"reln",                    too_few_2,      CC_reln,       wrong_no_2},
    {"makeset",                 CC_makeset,     too_many_1,    wrong_no_1},
    {"nextcomb",                too_few_2,      CC_nextcomb,   wrong_no_2},
    {"equalreplaceby",          CC_equalreplaceby,too_many_1,  wrong_no_1},
    {"ratn",                    CC_ratn,        too_many_1,    wrong_no_1},
    {"poly-minusp",             CC_polyKminusp, too_many_1,    wrong_no_1},
    {"mksq",                    too_few_2,      CC_mksq,       wrong_no_2},
    {"token-number",            CC_tokenKnumber,too_many_1,    wrong_no_1},
    {"ofsf_sacat",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sacat},
    {"rl_updcache",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_updcache},
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"ps:evaluate-next",        too_few_2,      CC_psTevaluateKnext,wrong_no_2},
    {"take-realpart",           CC_takeKrealpart,too_many_1,   wrong_no_1},
    {"rd:zerop:",               CC_rdTzeropT,   too_many_1,    wrong_no_1},
    {"arglist_member",          too_few_2,      CC_arglist_member,wrong_no_2},
    {"groedeletip",             too_few_2,      CC_groedeletip,wrong_no_2},
    {"freeoff",                 too_few_2,      CC_freeoff,    wrong_no_2},
    {"rd:times",                too_few_2,      CC_rdTtimes,   wrong_no_2},
    {"physopordchk",            too_few_2,      CC_physopordchk,wrong_no_2},
    {"moid_member",             too_few_2,      CC_moid_member,wrong_no_2},
    {"simp-prop-order",         too_few_2,      CC_simpKpropKorder,wrong_no_2},
    {"gcdout",                  CC_gcdout,      too_many_1,    wrong_no_1},
    {"charnump:",               CC_charnumpT,   too_many_1,    wrong_no_1},
    {"subf",                    too_few_2,      CC_subf,       wrong_no_2},
    {"cl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_simpl},
    {"sort-factors",            CC_sortKfactors,too_many_1,    wrong_no_1},
    {"simpqg",                  CC_simpqg,      too_many_1,    wrong_no_1},
    {"ibalp_dellit",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_dellit},
    {"form",                    CC_form,        too_many_1,    wrong_no_1},
    {"take-impart",             CC_takeKimpart, too_many_1,    wrong_no_1},
    {"rowdel",                  CC_rowdel,      too_many_1,    wrong_no_1},
    {"mktails",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails},
    {"copy-tree",               CC_copyKtree,   too_many_1,    wrong_no_1},
    {"red_topredbe",            too_few_2,      CC_red_topredbe,wrong_no_2},
    {NULL, (one_args *)"u17", (two_args *)"10964 5045654 6172183", 0}
};

/* end of generated code */
