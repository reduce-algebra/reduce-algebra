
/* $destdir/generated-c\u21.c Machine generated C code */

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


/* Code for cons_ordp */

static Lisp_Object MS_CDECL CC_cons_ordp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9, v10, v11, v12;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cons_ordp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cons_ordp");
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
/* copy arguments values to proper place */
    v9 = v2;
    v10 = v1;
    v11 = v0;
/* end of prologue */

v13:
    v8 = v11;
    if (v8 == nil) goto v14;
    v8 = v10;
    if (v8 == nil) goto v15;
    v8 = v11;
    v8 = Lconsp(nil, v8);
    env = stack[0];
    if (v8 == nil) goto v16;
    v8 = v10;
    v8 = Lconsp(nil, v8);
    env = stack[0];
    if (v8 == nil) goto v17;
    v8 = v11;
    v12 = qcar(v8);
    v8 = v10;
    v8 = qcar(v8);
    if (equal(v12, v8)) goto v18;
    v8 = v11;
    v8 = qcar(v8);
    v11 = v8;
    v8 = v10;
    v8 = qcar(v8);
    v10 = v8;
    goto v13;

v18:
    v8 = v11;
    v8 = qcdr(v8);
    v11 = v8;
    v8 = v10;
    v8 = qcdr(v8);
    v10 = v8;
    goto v13;

v17:
    v8 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v8); }

v16:
    v8 = v10;
    v8 = Lconsp(nil, v8);
    env = stack[0];
    if (v8 == nil) goto v19;
    v8 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v8); }

v19:
    v8 = v9;
    v9 = v11;
        popv(1);
        return Lapply2(nil, 3, v8, v9, v10);

v15:
    v8 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v8); }

v14:
    v8 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v8); }
}



/* Code for sgn1 */

static Lisp_Object CC_sgn1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sgn1");
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
    v3 = v1;
    stack[-4] = v0;
/* end of prologue */
    v4 = stack[-4];
    if (!consp(v4)) goto v30;
    v4 = v3;
    v4 = qcar(v4);
    stack[-2] = v4;
    v4 = v3;
    v4 = qcdr(v4);
    stack[-1] = v4;
    v4 = (Lisp_Object)1; /* 0 */
    stack[-3] = v4;
    v4 = (Lisp_Object)17; /* 1 */
    stack[-5] = v4;
    v4 = stack[-4];
    v4 = qcdr(v4);
    stack[-4] = v4;
    goto v31;

v31:
    v3 = stack[-5];
    v4 = stack[-4];
    v4 = qcar(v4);
    stack[0] = times2(v3, v4);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v3 = stack[-2];
    v4 = stack[-3];
    v4 = times2(v3, v4);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    v4 = plus2(stack[0], v4);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    stack[-3] = v4;
    v3 = stack[-5];
    v4 = stack[-1];
    v4 = times2(v3, v4);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-6];
    stack[-5] = v4;
    v4 = stack[-4];
    v4 = qcdr(v4);
    stack[-4] = v4;
    if (!(v4 == nil)) goto v31;
    v4 = stack[-3];
    {
        popv(7);
        fn = elt(env, 1); /* sgn */
        return (*qfn1(fn))(qenv(fn), v4);
    }

v30:
    v4 = stack[-4];
    {
        popv(7);
        fn = elt(env, 1); /* sgn */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v32:
    popv(7);
    return nil;
}



/* Code for taydegree!< */

static Lisp_Object CC_taydegreeR(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taydegree<");
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

v38:
    v21 = stack[-2];
    v21 = qcar(v21);
    stack[-3] = v21;
    v21 = stack[-1];
    v21 = qcar(v21);
    stack[0] = v21;
    goto v16;

v16:
    v21 = stack[-3];
    v37 = qcar(v21);
    v21 = stack[0];
    v21 = qcar(v21);
    fn = elt(env, 3); /* tayexp!-greaterp */
    v21 = (*qfn2(fn))(qenv(fn), v37, v21);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    if (v21 == nil) goto v40;
    v21 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v21); }

v40:
    v21 = stack[-3];
    v37 = qcar(v21);
    v21 = stack[0];
    v21 = qcar(v21);
    fn = elt(env, 4); /* tayexp!-lessp */
    v21 = (*qfn2(fn))(qenv(fn), v37, v21);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    if (v21 == nil) goto v27;
    v21 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v21); }

v27:
    v21 = stack[-3];
    v21 = qcdr(v21);
    stack[-3] = v21;
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    v21 = stack[-3];
    if (!(v21 == nil)) goto v16;
    v21 = stack[-2];
    v21 = qcdr(v21);
    stack[-2] = v21;
    v21 = stack[-1];
    v21 = qcdr(v21);
    stack[-1] = v21;
    v21 = stack[-2];
    if (!(v21 == nil)) goto v38;
    v21 = nil;
    { popv(5); return onevalue(v21); }
/* error exit handlers */
v39:
    popv(5);
    return nil;
}



/* Code for ofsf_ordatp */

static Lisp_Object CC_ofsf_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v29, v25, v45, v46, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v1;
    v47 = v0;
/* end of prologue */
    v44 = v47;
    v44 = qcdr(v44);
    v44 = qcar(v44);
    v45 = v44;
    v44 = v46;
    v44 = qcdr(v44);
    v44 = qcar(v44);
    v25 = v44;
    v29 = v45;
    v44 = v25;
    if (equal(v29, v44)) goto v48;
    v44 = v45;
    v29 = v25;
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v44, v29);
    }

v48:
    v44 = v47;
    v44 = qcar(v44);
    v29 = v46;
    v29 = qcar(v29);
    {
        fn = elt(env, 2); /* ofsf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v44, v29);
    }
}



/* Code for begin1 */

static Lisp_Object MS_CDECL CC_begin1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "begin1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for begin1");
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
    v77 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    qvalue(elt(env, 1)) = v77; /* otime!* */
    v77 = elt(env, 2); /* gctime */
    fn = elt(env, 47); /* getd */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    if (v77 == nil) goto v81;
    v77 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    qvalue(elt(env, 3)) = v77; /* ogctime!* */
    goto v27;

v27:
    v77 = elt(env, 4); /* !*semicol!* */
    qvalue(elt(env, 5)) = v77; /* cursym!* */
    goto v13;

v13:
    fn = elt(env, 48); /* terminalp */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    if (v77 == nil) goto v82;
    v77 = qvalue(elt(env, 6)); /* !*nosave!* */
    if (!(v77 == nil)) goto v41;
    v78 = qvalue(elt(env, 7)); /* statcounter */
    v77 = (Lisp_Object)1; /* 0 */
    if (v78 == v77) goto v41;
    fn = elt(env, 49); /* add2buflis */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    goto v41;

v41:
    fn = elt(env, 50); /* update_prompt */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    goto v82;

v82:
    v77 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 6)) = v77; /* !*nosave!* */
    v77 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 9)) = v77; /* !*strind */
    v77 = qvalue(elt(env, 8)); /* nil */
    stack[-1] = v77;
    v77 = qvalue(elt(env, 10)); /* !*time */
    if (v77 == nil) goto v83;
    v77 = elt(env, 11); /* (showtime) */
    fn = elt(env, 51); /* lispeval */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    goto v83;

v83:
    v77 = qvalue(elt(env, 12)); /* !*output */
    if (v77 == nil) goto v21;
    v77 = qvalue(elt(env, 13)); /* ofl!* */
    if (!(v77 == nil)) goto v21;
    fn = elt(env, 48); /* terminalp */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    if (v77 == nil) goto v21;
    v77 = qvalue(elt(env, 14)); /* !*defn */
    if (!(v77 == nil)) goto v21;
    v77 = qvalue(elt(env, 15)); /* !*lessspace */
    if (!(v77 == nil)) goto v21;
    v77 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    goto v21;

v21:
    v77 = qvalue(elt(env, 16)); /* tslin!* */
    if (v77 == nil) goto v11;
    v77 = qvalue(elt(env, 16)); /* tslin!* */
    v77 = qcar(v77);
    qvalue(elt(env, 17)) = v77; /* !*slin */
    v77 = qvalue(elt(env, 16)); /* tslin!* */
    v77 = qcdr(v77);
    qvalue(elt(env, 18)) = v77; /* lreadfn!* */
    v77 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 16)) = v77; /* tslin!* */
    goto v11;

v11:
    v77 = qvalue(elt(env, 19)); /* initl!* */
    stack[0] = v77;
    goto v38;

v38:
    v77 = stack[0];
    if (v77 == nil) goto v84;
    v77 = stack[0];
    v77 = qcar(v77);
    fn = elt(env, 52); /* sinitl */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v77 = stack[0];
    v77 = qcdr(v77);
    stack[0] = v77;
    goto v38;

v84:
    v78 = qvalue(elt(env, 20)); /* forkeywords!* */
    v77 = elt(env, 21); /* delim */
    v77 = Lremflag(nil, v78, v77);
    env = stack[-2];
    v78 = qvalue(elt(env, 22)); /* repeatkeywords!* */
    v77 = elt(env, 21); /* delim */
    v77 = Lremflag(nil, v78, v77);
    env = stack[-2];
    v78 = qvalue(elt(env, 23)); /* whilekeywords!* */
    v77 = elt(env, 21); /* delim */
    v77 = Lremflag(nil, v78, v77);
    env = stack[-2];
    v77 = qvalue(elt(env, 24)); /* !*int */
    if (v77 == nil) goto v85;
    v77 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 25)) = v77; /* erfg!* */
    goto v85;

v85:
    v78 = qvalue(elt(env, 5)); /* cursym!* */
    v77 = elt(env, 26); /* end */
    if (v78 == v77) goto v86;
    fn = elt(env, 48); /* terminalp */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    if (v77 == nil) goto v87;
    v78 = qvalue(elt(env, 27)); /* key!* */
    v77 = elt(env, 28); /* ed */
    if (v78 == v77) goto v87;
    v77 = qvalue(elt(env, 29)); /* promptexp!* */
    fn = elt(env, 53); /* printprompt */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    goto v87;

v87:
    v78 = elt(env, 30); /* (command) */
    v77 = qvalue(elt(env, 31)); /* t */
    fn = elt(env, 54); /* errorset!* */
    v77 = (*qfn2(fn))(qenv(fn), v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    stack[0] = v77;
    fn = elt(env, 55); /* condterpri */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v77 = stack[0];
    fn = elt(env, 56); /* errorp */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    if (v77 == nil) goto v88;
    fn = elt(env, 57); /* eofcheck */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    if (!(v77 == nil)) goto v89;
    v78 = qvalue(elt(env, 38)); /* eof!* */
    v77 = (Lisp_Object)1; /* 0 */
    v77 = (Lisp_Object)greaterp2(v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    v77 = v77 ? lisp_true : nil;
    env = stack[-2];
    if (!(v77 == nil)) goto v89;
    v78 = stack[0];
    v77 = elt(env, 42); /* "BEGIN invalid" */
    if (equal(v78, v77)) goto v13;
    v77 = qvalue(elt(env, 31)); /* t */
    stack[-1] = v77;
    goto v90;

v90:
    fn = elt(env, 58); /* resetparser */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    goto v91;

v91:
    v77 = qvalue(elt(env, 31)); /* t */
    qvalue(elt(env, 25)) = v77; /* erfg!* */
    v77 = qvalue(elt(env, 24)); /* !*int */
    if (!(v77 == nil)) goto v92;
    v77 = qvalue(elt(env, 43)); /* !*errcont */
    if (!(v77 == nil)) goto v92;
    v77 = qvalue(elt(env, 31)); /* t */
    qvalue(elt(env, 14)) = v77; /* !*defn */
    v77 = qvalue(elt(env, 31)); /* t */
    qvalue(elt(env, 44)) = v77; /* !*echo */
    v77 = qvalue(elt(env, 45)); /* cmsg!* */
    if (!(v77 == nil)) goto v93;
    v77 = elt(env, 46); /* "Continuing with parsing only ..." */
    fn = elt(env, 59); /* lprie */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    goto v93;

v93:
    v77 = qvalue(elt(env, 31)); /* t */
    qvalue(elt(env, 45)) = v77; /* cmsg!* */
    goto v13;

v92:
    v77 = qvalue(elt(env, 43)); /* !*errcont */
    if (v77 == nil) goto v94;
    v77 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 25)) = v77; /* erfg!* */
    goto v13;

v94:
    v77 = stack[-1];
    fn = elt(env, 60); /* pause1 */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v79 = v77;
    v77 = v79;
    if (v77 == nil) goto v95;
    v77 = v79;
    fn = elt(env, 51); /* lispeval */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    v77 = (v77 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v77); }

v95:
    v77 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 25)) = v77; /* erfg!* */
    goto v13;

v89:
    v77 = qvalue(elt(env, 36)); /* crbuf1!* */
    if (v77 == nil) goto v96;
    v77 = elt(env, 37); /* "Closing object improperly removed. Redo edit." 
*/
    fn = elt(env, 61); /* lprim */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v77 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 36)) = v77; /* crbuf1!* */
    v77 = qvalue(elt(env, 8)); /* nil */
    { popv(3); return onevalue(v77); }

v96:
    v78 = qvalue(elt(env, 38)); /* eof!* */
    v77 = (Lisp_Object)65; /* 4 */
    v77 = (Lisp_Object)greaterp2(v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    v77 = v77 ? lisp_true : nil;
    env = stack[-2];
    if (v77 == nil) goto v97;
    v77 = elt(env, 39); /* "End-of-file read" */
    fn = elt(env, 61); /* lprim */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v77 = elt(env, 40); /* (bye) */
    {
        popv(3);
        fn = elt(env, 51); /* lispeval */
        return (*qfn1(fn))(qenv(fn), v77);
    }

v97:
    fn = elt(env, 48); /* terminalp */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    if (v77 == nil) goto v98;
    v77 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 41)) = v77; /* crbuf!* */
    v77 = qvalue(elt(env, 31)); /* t */
    qvalue(elt(env, 6)) = v77; /* !*nosave!* */
    goto v13;

v98:
    v77 = qvalue(elt(env, 8)); /* nil */
    { popv(3); return onevalue(v77); }

v88:
    v77 = stack[0];
    v77 = qcar(v77);
    stack[0] = v77;
    v77 = stack[0];
    v78 = qcar(v77);
    v77 = elt(env, 32); /* symbolic */
    if (!(v78 == v77)) goto v99;
    v77 = stack[0];
    v77 = qcdr(v77);
    v78 = qcar(v77);
    v77 = elt(env, 33); /* xmodule */
    if (!consp(v78)) goto v99;
    v78 = qcar(v78);
    if (!(v78 == v77)) goto v99;
    v77 = stack[0];
    v77 = qcdr(v77);
    v77 = qcar(v77);
    fn = elt(env, 62); /* eval */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    fn = elt(env, 63); /* xmodloop */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v79 = v77;
    goto v100;

v100:
    v77 = v79;
    if (v77 == nil) goto v13;
    v78 = v79;
    v77 = elt(env, 26); /* end */
    if (v78 == v77) goto v101;
    v78 = v79;
    v77 = elt(env, 34); /* err2 */
    if (v78 == v77) goto v90;
    v78 = v79;
    v77 = elt(env, 35); /* err3 */
    if (v78 == v77) goto v91;
    else goto v89;

v101:
    v77 = qvalue(elt(env, 8)); /* nil */
    { popv(3); return onevalue(v77); }

v99:
    v77 = stack[0];
    fn = elt(env, 64); /* begin11 */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v79 = v77;
    goto v100;

v86:
    v77 = elt(env, 26); /* end */
    fn = elt(env, 65); /* comm1 */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v77 = qvalue(elt(env, 8)); /* nil */
    { popv(3); return onevalue(v77); }

v81:
    v77 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v77; /* ogctime!* */
    goto v27;
/* error exit handlers */
v80:
    popv(3);
    return nil;
}



/* Code for vdpvevlcomp */

static Lisp_Object CC_vdpvevlcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpvevlcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v102 = v1;
    v81 = v0;
/* end of prologue */
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcar(v81);
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v102 = qcar(v102);
    {
        fn = elt(env, 1); /* dipevlcomp */
        return (*qfn2(fn))(qenv(fn), v81, v102);
    }
}



/* Code for inprinla */

static Lisp_Object MS_CDECL CC_inprinla(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprinla");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inprinla");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v112 = stack[-2];
    v111 = elt(env, 1); /* alt */
    v111 = get(v112, v111);
    env = stack[-4];
    if (!(v111 == nil)) goto v38;
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = stack[-1];
    fn = elt(env, 3); /* maprintla */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v13;

v13:
    v111 = stack[0];
    v111 = qcdr(v111);
    stack[0] = v111;
    goto v38;

v38:
    v111 = stack[0];
    if (v111 == nil) goto v48;
    v111 = stack[0];
    v111 = qcar(v111);
    if (!consp(v111)) goto v7;
    stack[-3] = stack[-2];
    v111 = stack[0];
    v111 = qcar(v111);
    v112 = qcar(v111);
    v111 = elt(env, 1); /* alt */
    v111 = Lget(nil, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    if (!(stack[-3] == v111)) goto v7;
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = stack[-1];
    fn = elt(env, 3); /* maprintla */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v13;

v7:
    v111 = stack[-2];
    fn = elt(env, 4); /* oprinla */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    v111 = stack[0];
    v111 = qcar(v111);
    fn = elt(env, 5); /* negnumberchk */
    v112 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    v111 = stack[-1];
    fn = elt(env, 3); /* maprintla */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v13;

v48:
    v111 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v111); }
/* error exit handlers */
v113:
    popv(5);
    return nil;
}



/* Code for plubf */

static Lisp_Object CC_plubf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plubf");
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
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    v53 = stack[-7];
    v53 = qcdr(v53);
    v54 = qcar(v53);
    stack[-8] = v54;
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v27;
    v53 = stack[-6];
    v53 = qcdr(v53);
    v54 = qcar(v53);
    stack[-5] = v54;
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v110;
    v53 = stack[-7];
    v53 = qcdr(v53);
    v54 = qcdr(v53);
    stack[-4] = v54;
    v53 = stack[-6];
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    stack[-3] = v53;
    v54 = difference2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    stack[-2] = v54;
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v154;
    stack[-1] = stack[-2];
    v53 = stack[-8];
    v53 = Labsval(nil, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = stack[-5];
    v53 = Labsval(nil, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = difference2(stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = plus2(stack[-1], v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    stack[-1] = v53;
    v53 = qvalue(elt(env, 2)); /* !:bprec!: */
    v53 = add1(v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    stack[0] = v53;
    v54 = stack[-1];
    v53 = stack[0];
    v53 = (Lisp_Object)greaterp2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v53 = v53 ? lisp_true : nil;
    env = stack[-9];
    if (v53 == nil) goto v155;
    v53 = stack[-7];
    goto v91;

v91:
    stack[-2] = v53;
    v53 = stack[-2];
    v53 = qcdr(v53);
    v53 = qcar(v53);
    v152 = v53;
    v54 = v152;
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v156;
    v54 = v152;
    v53 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v152 = v53;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v53 = v152;
    stack[0] = qcar(v53);
    v53 = v152;
    v54 = qcdr(v53);
    v53 = stack[-2];
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    v53 = plus2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    {
        Lisp_Object v157 = stack[-1];
        Lisp_Object v158 = stack[0];
        popv(10);
        return list2star(v157, v158, v53);
    }

v156:
    v152 = elt(env, 1); /* !:rd!: */
    v54 = (Lisp_Object)1; /* 0 */
    v53 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v152, v54, v53);

v155:
    v53 = stack[0];
    v53 = negate(v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = (Lisp_Object)lessp2(stack[-1], v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v53 = v53 ? lisp_true : nil;
    env = stack[-9];
    if (v53 == nil) goto v70;
    v53 = stack[-6];
    goto v91;

v70:
    v54 = stack[-2];
    v53 = (Lisp_Object)1; /* 0 */
    v53 = (Lisp_Object)greaterp2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v53 = v53 ? lisp_true : nil;
    env = stack[-9];
    if (v53 == nil) goto v159;
    stack[0] = elt(env, 1); /* !:rd!: */
    v54 = stack[-8];
    v53 = stack[-2];
    v54 = Lash1(nil, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = stack[-5];
    v54 = plus2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = stack[-3];
    v53 = list2star(stack[0], v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    goto v91;

v159:
    stack[0] = elt(env, 1); /* !:rd!: */
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v53 = stack[-2];
    v53 = negate(v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = Lash1(nil, stack[-3], v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v54 = plus2(stack[-1], v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = stack[-4];
    v53 = list2star(stack[0], v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    goto v91;

v154:
    stack[0] = elt(env, 1); /* !:rd!: */
    v54 = stack[-8];
    v53 = stack[-5];
    v54 = plus2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    v53 = stack[-4];
    v53 = list2star(stack[0], v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-9];
    goto v91;

v110:
    v53 = stack[-7];
    goto v91;

v27:
    v53 = stack[-6];
    goto v91;
/* error exit handlers */
v153:
    popv(10);
    return nil;
}



/* Code for mk!-numr */

static Lisp_Object MS_CDECL CC_mkKnumr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk-numr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-numr");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v23;

v23:
    v20 = stack[-1];
    v108 = stack[0];
    if (equal(v20, v108)) goto v90;
    v20 = stack[-1];
    v108 = (Lisp_Object)1; /* 0 */
    if (v20 == v108) goto v40;
    v21 = elt(env, 1); /* difference */
    v20 = stack[-2];
    v108 = stack[-1];
    v108 = list3(v21, v20, v108);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-4];
    v20 = v108;
    goto v36;

v36:
    v108 = stack[-3];
    v108 = cons(v20, v108);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-4];
    stack[-3] = v108;
    v108 = stack[-1];
    v108 = add1(v108);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-4];
    stack[-1] = v108;
    goto v23;

v40:
    v108 = stack[-2];
    v20 = v108;
    goto v36;

v90:
    v108 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v108);
    }
/* error exit handlers */
v163:
    popv(5);
    return nil;
}



/* Code for sqhorner!* */

static Lisp_Object CC_sqhornerH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqhorner*");
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
    v48 = qvalue(elt(env, 1)); /* !*horner */
    if (v48 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v165 = qvalue(elt(env, 2)); /* ordl!* */
    v48 = qvalue(elt(env, 3)); /* kord!* */
    v48 = Lappend(nil, v165, v48);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = qvalue(elt(env, 3)); /* kord!* */
    qvalue(elt(env, 3)) = v48; /* kord!* */
    v48 = stack[-1];
    v48 = qcar(v48);
    fn = elt(env, 4); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v48 = stack[-1];
    v48 = qcdr(v48);
    fn = elt(env, 4); /* reorder */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    fn = elt(env, 5); /* hornerf */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v48 = cons(stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    fn = elt(env, 6); /* hornersq */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* kord!* */
    { popv(4); return onevalue(v48); }
/* error exit handlers */
v6:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* kord!* */
    popv(4);
    return nil;
v151:
    popv(4);
    return nil;
}



/* Code for no_dum_varp */

static Lisp_Object CC_no_dum_varp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no_dum_varp");
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
    v41 = qcdr(v41);
    if (v41 == nil) goto v34;
    v41 = stack[0];
    v40 = qcdr(v41);
    v41 = elt(env, 1); /* list */
    fn = elt(env, 4); /* splitlist!: */
    v40 = (*qfn2(fn))(qenv(fn), v40, v41);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-1];
    v41 = stack[0];
    v41 = qcdr(v41);
    if (equal(v40, v41)) goto v34;
    v41 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v41); }

v34:
    v41 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v41); }
/* error exit handlers */
v48:
    popv(2);
    return nil;
}



/* Code for wureducedp */

static Lisp_Object CC_wureducedp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wureducedp");
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
    v28 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    if (!(v28 == nil)) { popv(3); return onevalue(v28); }
    v28 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    if (!(v28 == nil)) { popv(3); return onevalue(v28); }
    v28 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    if (v28 == nil) goto v40;
    v28 = qvalue(elt(env, 1)); /* nil */
    goto v167;

v167:
    fn = elt(env, 3); /* deginvar */
    v44 = (*qfn2(fn))(qenv(fn), stack[-1], v28);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v28 = stack[0];
    v28 = qcar(v28);
    v28 = qcar(v28);
    v28 = qcdr(v28);
        popv(3);
        return Llessp(nil, v44, v28);

v40:
    v28 = stack[0];
    v28 = qcar(v28);
    v28 = qcar(v28);
    v28 = qcar(v28);
    goto v167;
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for width */

static Lisp_Object CC_width(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v39, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for width");
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
    v39 = v0;
/* end of prologue */
    v169 = v39;
    v163 = elt(env, 1); /* textag */
    v163 = get(v169, v163);
    env = stack[-2];
    stack[-1] = v163;
    v163 = stack[-1];
    if (!(v163 == nil)) goto v29;
    v163 = elt(env, 2); /* "cannot find item " */
    v39 = list2(v163, v39);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-2];
    v163 = elt(env, 3); /* fatal */
    fn = elt(env, 5); /* tri!-error */
    v163 = (*qfn2(fn))(qenv(fn), v39, v163);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-2];
    goto v29;

v29:
    v39 = stack[0];
    v163 = (Lisp_Object)1; /* 0 */
    v163 = (Lisp_Object)greaterp2(v39, v163);
    nil = C_nil;
    if (exception_pending()) goto v3;
    v163 = v163 ? lisp_true : nil;
    env = stack[-2];
    if (v163 == nil) goto v24;
    v163 = stack[-1];
    v163 = qcdr(v163);
    if (v163 == nil) goto v24;
    v163 = stack[-1];
    v163 = qcdr(v163);
    stack[-1] = v163;
    v163 = stack[0];
    v163 = sub1(v163);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-2];
    stack[0] = v163;
    goto v29;

v24:
    v163 = stack[-1];
    v163 = qcar(v163);
    if (!(v163 == nil)) { popv(3); return onevalue(v163); }
    v163 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v163); }
/* error exit handlers */
v3:
    popv(3);
    return nil;
}



/* Code for cgp_ci */

static Lisp_Object CC_cgp_ci(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_ci");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v0;
/* end of prologue */
    v91 = v90;
    v90 = (Lisp_Object)97; /* 6 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v91, v90);
    }
}



/* Code for derad */

static Lisp_Object CC_derad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v178, v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derad");
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
    goto v13;

v13:
    v177 = stack[0];
    if (v177 == nil) goto v15;
    v177 = stack[0];
    v177 = qcar(v177);
    if (is_number(v177)) goto v36;
    v178 = stack[-1];
    v177 = stack[0];
    v177 = qcar(v177);
    if (equal(v178, v177)) goto v31;
    v178 = stack[-1];
    v177 = stack[0];
    v177 = qcar(v177);
    fn = elt(env, 1); /* ordp */
    v177 = (*qfn2(fn))(qenv(fn), v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    if (v177 == nil) goto v181;
    v178 = stack[-1];
    v177 = stack[0];
    v177 = cons(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    {
        Lisp_Object v182 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v182, v177);
    }

v181:
    v177 = stack[0];
    v178 = qcar(v177);
    v177 = stack[-2];
    v177 = cons(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[-2] = v177;
    v177 = stack[0];
    v177 = qcdr(v177);
    stack[0] = v177;
    goto v13;

v31:
    v177 = stack[0];
    v177 = qcdr(v177);
    if (v177 == nil) goto v183;
    v177 = stack[0];
    v177 = qcdr(v177);
    v177 = qcar(v177);
    if (!(is_number(v177))) goto v183;
    v177 = stack[0];
    v177 = qcdr(v177);
    v177 = qcar(v177);
    v178 = add1(v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    v177 = stack[0];
    v177 = qcdr(v177);
    v177 = qcdr(v177);
    v177 = list2star(stack[-1], v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    {
        Lisp_Object v68 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v68, v177);
    }

v183:
    v179 = stack[-1];
    v178 = (Lisp_Object)33; /* 2 */
    v177 = stack[0];
    v177 = qcdr(v177);
    v177 = list2star(v179, v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    {
        Lisp_Object v67 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v67, v177);
    }

v36:
    v177 = stack[0];
    v178 = qcar(v177);
    v177 = stack[-2];
    v177 = cons(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[-2] = v177;
    v177 = stack[0];
    v177 = qcdr(v177);
    stack[0] = v177;
    goto v13;

v15:
    stack[0] = stack[-2];
    v177 = stack[-1];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    {
        Lisp_Object v184 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v184, v177);
    }
/* error exit handlers */
v180:
    popv(4);
    return nil;
}



/* Code for unify */

static Lisp_Object MS_CDECL CC_unify(Lisp_Object env, int nargs,
                         Lisp_Object v33, Lisp_Object v34,
                         Lisp_Object v30, Lisp_Object v13,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v197, v126, v127, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "unify");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unify");
#endif
    if (stack >= stacklimit)
    {
        push5(v38,v13,v30,v34,v33);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v33,v34,v30,v13,v38);
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
    stack[-13] = v38;
    stack[-14] = v13;
    v197 = v30;
    v126 = v34;
    v101 = v33;
/* end of prologue */
    stack[-15] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-12] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-11] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v101; /* op */
    v101 = v126;
    qvalue(elt(env, 2)) = v101; /* r */
    v101 = v197;
    qvalue(elt(env, 3)) = v101; /* p */
    v101 = qvalue(elt(env, 2)); /* r */
    if (!(v101 == nil)) goto v81;
    v101 = qvalue(elt(env, 3)); /* p */
    if (!(v101 == nil)) goto v81;
    v197 = stack[-14];
    v101 = stack[-13];
    fn = elt(env, 14); /* resume */
    v101 = (*qfn2(fn))(qenv(fn), v197, v101);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-16];
    goto v15;

v15:
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    { popv(17); return onevalue(v101); }

v81:
    v101 = qvalue(elt(env, 2)); /* r */
    if (v101 == nil) goto v48;
    v101 = qvalue(elt(env, 3)); /* p */
    if (!(v101 == nil)) goto v160;
    v101 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 15); /* ident */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-16];
    if (!(v101 == nil)) goto v160;
    v101 = qvalue(elt(env, 2)); /* r */
    v101 = qcar(v101);
    fn = elt(env, 16); /* mgenp */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-16];
    if (!(v101 == nil)) goto v160;
    v101 = qvalue(elt(env, 5)); /* nil */
    goto v15;

v160:
    stack[0] = nil;
    stack[-8] = qvalue(elt(env, 6)); /* symm */
    qvalue(elt(env, 6)) = nil; /* symm */
    stack[-7] = qvalue(elt(env, 7)); /* comb */
    qvalue(elt(env, 7)) = nil; /* comb */
    stack[-6] = qvalue(elt(env, 8)); /* identity */
    qvalue(elt(env, 8)) = nil; /* identity */
    stack[-5] = qvalue(elt(env, 9)); /* mcontract */
    qvalue(elt(env, 9)) = nil; /* mcontract */
    stack[-4] = qvalue(elt(env, 10)); /* acontract */
    qvalue(elt(env, 10)) = nil; /* acontract */
    stack[-3] = qvalue(elt(env, 11)); /* expand */
    qvalue(elt(env, 11)) = nil; /* expand */
    stack[-2] = qvalue(elt(env, 12)); /* i */
    qvalue(elt(env, 12)) = nil; /* i */
    stack[-1] = qvalue(elt(env, 13)); /* upb */
    qvalue(elt(env, 13)) = nil; /* upb */
    v101 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v101; /* i */
    v101 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 13)) = v101; /* upb */
    v101 = qvalue(elt(env, 2)); /* r */
    v101 = qcar(v101);
    fn = elt(env, 17); /* pm!:free */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    if (v101 == nil) goto v9;
    v101 = qvalue(elt(env, 2)); /* r */
    v101 = qcar(v101);
    fn = elt(env, 18); /* genp */
    v197 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    v101 = stack[-14];
    v101 = cons(v197, v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    stack[-14] = v101;
    goto v9;

v9:
    v101 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 19); /* initarg */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    goto v199;

v199:
    v101 = stack[0];
    if (!(v101 == nil)) goto v200;
    v101 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 20); /* nextarg */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    stack[-9] = v101;
    if (v101 == nil) goto v200;
    v101 = qvalue(elt(env, 2)); /* r */
    v101 = qcar(v101);
    if (!consp(v101)) goto v73;
    v198 = qvalue(elt(env, 1)); /* op */
    v127 = qvalue(elt(env, 2)); /* r */
    v126 = stack[-9];
    v197 = stack[-14];
    v101 = stack[-13];
    fn = elt(env, 21); /* suspend */
    v101 = (*qfnn(fn))(qenv(fn), 5, v198, v127, v126, v197, v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    stack[0] = v101;
    goto v199;

v73:
    v101 = qvalue(elt(env, 2)); /* r */
    v101 = qcar(v101);
    fn = elt(env, 17); /* pm!:free */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    if (v101 == nil) goto v201;
    v101 = qvalue(elt(env, 2)); /* r */
    v197 = qcar(v101);
    v101 = stack[-9];
    v101 = qcar(v101);
    fn = elt(env, 22); /* bind */
    v101 = (*qfn2(fn))(qenv(fn), v197, v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    v101 = stack[-14];
    fn = elt(env, 23); /* chk */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    stack[-10] = v101;
    if (v101 == nil) goto v180;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v101 = qvalue(elt(env, 2)); /* r */
    v101 = qcdr(v101);
    fn = elt(env, 24); /* mval */
    v127 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    v101 = stack[-9];
    v126 = qcdr(v101);
    v197 = stack[-10];
    v101 = stack[-13];
    v101 = CC_unify(env, 5, stack[0], v127, v126, v197, v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    stack[0] = v101;
    goto v180;

v180:
    v101 = qvalue(elt(env, 2)); /* r */
    v101 = qcar(v101);
    fn = elt(env, 25); /* unbind */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    goto v199;

v201:
    v101 = qvalue(elt(env, 2)); /* r */
    v197 = qcar(v101);
    v101 = stack[-9];
    v101 = qcar(v101);
    fn = elt(env, 26); /* meq */
    v101 = (*qfn2(fn))(qenv(fn), v197, v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    if (v101 == nil) goto v199;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v101 = qvalue(elt(env, 2)); /* r */
    v101 = qcdr(v101);
    fn = elt(env, 24); /* mval */
    v127 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    v101 = stack[-9];
    v126 = qcdr(v101);
    v197 = stack[-14];
    v101 = stack[-13];
    v101 = CC_unify(env, 5, stack[0], v127, v126, v197, v101);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-16];
    stack[0] = v101;
    goto v199;

v200:
    v101 = stack[0];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    goto v15;

v48:
    v101 = elt(env, 4); /* "UNIFY:pattern over-run for function " */
    v101 = Lprinc(nil, v101);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-16];
    v101 = qvalue(elt(env, 1)); /* op */
    v101 = Lprint(nil, v101);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-16];
    v101 = qvalue(elt(env, 5)); /* nil */
    goto v15;
/* error exit handlers */
v122:
    env = stack[-16];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
v121:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
}



/* Code for lengthcdr */

static Lisp_Object CC_lengthcdr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lengthcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v30 = qcdr(v30);
        return Llength(nil, v30);
}



/* Code for negind */

static Lisp_Object CC_negind(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negind");
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

v202:
    v44 = stack[-1];
    if (v44 == nil) goto v30;
    v44 = stack[-1];
    v29 = qcar(v44);
    v44 = stack[0];
    v44 = qcar(v44);
    v44 = qcar(v44);
    v29 = plus2(v29, v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v44 = (Lisp_Object)1; /* 0 */
    v44 = (Lisp_Object)lessp2(v29, v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v44 = v44 ? lisp_true : nil;
    env = stack[-2];
    if (!(v44 == nil)) { popv(3); return onevalue(v44); }
    v44 = stack[-1];
    v29 = qcdr(v44);
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[-1] = v29;
    stack[0] = v44;
    goto v202;

v30:
    v44 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v44); }
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for tayexp!-minus */

static Lisp_Object CC_tayexpKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-minus");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v0;
/* end of prologue */
    v15 = v27;
    if (!consp(v15)) goto v34;
    v15 = v27;
    {
        fn = elt(env, 1); /* rnminus!: */
        return (*qfn1(fn))(qenv(fn), v15);
    }

v34:
    v15 = v27;
    return negate(v15);
}



/* Code for mk!+unit!+mat */

static Lisp_Object CC_mkLunitLmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+unit+mat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* gen!+can!+bas */
        return (*qfn1(fn))(qenv(fn), v13);
    }
}



/* Code for opfneval */

static Lisp_Object CC_opfneval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v97, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opfneval");
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
    stack[-2] = v0;
/* end of prologue */
    v215 = stack[-2];
    v97 = qcar(v215);
    v215 = elt(env, 1); /* remember */
    v215 = Lflagp(nil, v97, v215);
    env = stack[-5];
    if (v215 == nil) goto v128;
    v215 = stack[-2];
    v97 = qcar(v215);
    v215 = elt(env, 2); /* noval */
    v215 = Lflagp(nil, v97, v215);
    env = stack[-5];
    if (v215 == nil) goto v28;
    v215 = stack[-2];
    v215 = qcdr(v215);
    goto v109;

v109:
    stack[-4] = v215;
    v215 = stack[-4];
    if (v215 == nil) goto v106;
    v215 = stack[-4];
    v215 = qcar(v215);
    v97 = v215;
    v215 = v97;
    v215 = integerp(v215);
    if (v215 == nil) goto v154;
    v215 = v97;
    goto v108;

v108:
    v215 = ncons(v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    stack[-1] = v215;
    stack[-3] = v215;
    goto v82;

v82:
    v215 = stack[-4];
    v215 = qcdr(v215);
    stack[-4] = v215;
    v215 = stack[-4];
    if (v215 == nil) goto v8;
    stack[0] = stack[-1];
    v215 = stack[-4];
    v215 = qcar(v215);
    v97 = v215;
    v215 = v97;
    v215 = integerp(v215);
    if (v215 == nil) goto v146;
    v215 = v97;
    goto v145;

v145:
    v215 = ncons(v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v215 = Lrplacd(nil, stack[0], v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v215 = stack[-1];
    v215 = qcdr(v215);
    stack[-1] = v215;
    goto v82;

v146:
    v215 = v97;
    v215 = Lmkquote(nil, v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    goto v145;

v8:
    v215 = stack[-3];
    goto v35;

v35:
    stack[-4] = v215;
    v215 = stack[-2];
    v97 = qcar(v215);
    v215 = stack[-4];
    v216 = cons(v97, v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v215 = stack[-2];
    v97 = qcar(v215);
    v215 = elt(env, 4); /* kvalue */
    v215 = get(v97, v215);
    env = stack[-5];
    v215 = Lassoc(nil, v216, v215);
    v97 = v215;
    if (v215 == nil) goto v217;
    v215 = v97;
    v215 = qcdr(v215);
    v215 = qcar(v215);
    { popv(6); return onevalue(v215); }

v217:
    v215 = stack[-2];
    v97 = qcar(v215);
    v215 = stack[-4];
    v215 = cons(v97, v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    fn = elt(env, 5); /* lispeval */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    stack[-3] = v215;
    v215 = stack[-2];
    stack[-1] = qcar(v215);
    v215 = stack[-2];
    v97 = qcar(v215);
    v215 = elt(env, 4); /* kvalue */
    stack[0] = get(v97, v215);
    env = stack[-5];
    v215 = stack[-2];
    v97 = qcar(v215);
    v215 = stack[-4];
    v97 = cons(v97, v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v215 = stack[-3];
    fn = elt(env, 6); /* put!-kvalue */
    v215 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v97, v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v154:
    v215 = v97;
    v215 = Lmkquote(nil, v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    goto v108;

v106:
    v215 = qvalue(elt(env, 3)); /* nil */
    goto v35;

v28:
    v215 = stack[-2];
    v215 = qcdr(v215);
    fn = elt(env, 7); /* revlis */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    goto v109;

v128:
    v215 = stack[-2];
    stack[-4] = qcar(v215);
    v215 = stack[-2];
    v97 = qcar(v215);
    v215 = elt(env, 2); /* noval */
    v215 = Lflagp(nil, v97, v215);
    env = stack[-5];
    if (v215 == nil) goto v187;
    v215 = stack[-2];
    v215 = qcdr(v215);
    goto v133;

v133:
    stack[-3] = v215;
    v215 = stack[-3];
    if (v215 == nil) goto v198;
    v215 = stack[-3];
    v215 = qcar(v215);
    v215 = Lmkquote(nil, v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v215 = ncons(v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    stack[-1] = v215;
    stack[-2] = v215;
    goto v218;

v218:
    v215 = stack[-3];
    v215 = qcdr(v215);
    stack[-3] = v215;
    v215 = stack[-3];
    if (v215 == nil) goto v58;
    stack[0] = stack[-1];
    v215 = stack[-3];
    v215 = qcar(v215);
    v215 = Lmkquote(nil, v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v215 = ncons(v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v215 = Lrplacd(nil, stack[0], v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v215 = stack[-1];
    v215 = qcdr(v215);
    stack[-1] = v215;
    goto v218;

v58:
    v215 = stack[-2];
    goto v219;

v219:
    v215 = cons(stack[-4], v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* lispeval */
        return (*qfn1(fn))(qenv(fn), v215);
    }

v198:
    v215 = qvalue(elt(env, 3)); /* nil */
    goto v219;

v187:
    v215 = stack[-2];
    v215 = qcdr(v215);
    fn = elt(env, 7); /* revlis */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    goto v133;
/* error exit handlers */
v53:
    popv(6);
    return nil;
}



/* Code for dm!-gt */

static Lisp_Object CC_dmKgt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-gt");
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
    v15 = v1;
    v23 = v0;
/* end of prologue */
    fn = elt(env, 1); /* dm!-difference */
    v23 = (*qfn2(fn))(qenv(fn), v15, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !:minusp */
        return (*qfn1(fn))(qenv(fn), v23);
    }
/* error exit handlers */
v27:
    popv(1);
    return nil;
}



/* Code for expvec2a */

static Lisp_Object CC_expvec2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expvec2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v0;
/* end of prologue */
    v91 = v90;
    v90 = qvalue(elt(env, 1)); /* dipvars!* */
    {
        fn = elt(env, 2); /* expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v91, v90);
    }
}



/* Code for can_be_proved */

static Lisp_Object CC_can_be_proved(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for can_be_proved");
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

v30:
    v110 = stack[-1];
    if (v110 == nil) goto v89;
    v110 = stack[-1];
    v18 = qcar(v110);
    v110 = stack[0];
    fn = elt(env, 3); /* can_be_p */
    v110 = (*qfn2(fn))(qenv(fn), v18, v110);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-2];
    if (v110 == nil) goto v82;
    v110 = stack[-1];
    v110 = qcdr(v110);
    stack[-1] = v110;
    goto v30;

v82:
    v110 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v110); }

v89:
    v110 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v110); }
/* error exit handlers */
v168:
    popv(3);
    return nil;
}



/* Code for lastcar */

static Lisp_Object CC_lastcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v42;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lastcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v167 = v0;
/* end of prologue */

v34:
    v42 = v167;
    if (v42 == nil) goto v38;
    v42 = v167;
    v42 = qcdr(v42);
    if (v42 == nil) goto v91;
    v167 = qcdr(v167);
    goto v34;

v91:
    v167 = qcar(v167);
    return onevalue(v167);

v38:
    v167 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v167);
}



/* Code for red_tailred */

static Lisp_Object CC_red_tailred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v48, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_tailred");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v168 = v1;
    v165 = v0;
/* end of prologue */
    v48 = qvalue(elt(env, 1)); /* !*noetherian */
    if (v48 == nil) goto v35;
    v48 = v168;
    v168 = elt(env, 2); /* red_topred */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v165, v48, v168);
    }

v35:
    v48 = v168;
    v168 = elt(env, 3); /* red_topredbe */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v165, v48, v168);
    }
}



/* Code for ad_numsort */

static Lisp_Object CC_ad_numsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_numsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v0;
/* end of prologue */
    v91 = v90;
    v90 = elt(env, 1); /* lambda_l7iptc_4 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v91, v90);
    }
}



/* Code for lambda_l7iptc_4 */

static Lisp_Object CC_lambda_l7iptc_4(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l7iptc_4");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v91 = v1;
    v23 = v0;
/* end of prologue */
        return Lleq(nil, v23, v91);
}



/* Code for !:expt */

static Lisp_Object CC_Texpt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :expt");
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
    v121 = stack[-4];
    if (v121 == nil) goto v23;
    v122 = stack[-3];
    v121 = (Lisp_Object)1; /* 0 */
    if (v122 == v121) goto v48;
    v122 = stack[-3];
    v121 = (Lisp_Object)17; /* 1 */
    if (v122 == v121) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v122 = stack[-4];
    v121 = (Lisp_Object)17; /* 1 */
    if (v122 == v121) goto v161;
    v122 = stack[-3];
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)lessp2(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    v121 = v121 ? lisp_true : nil;
    env = stack[-6];
    if (v121 == nil) goto v163;
    v121 = stack[-4];
    fn = elt(env, 7); /* fieldp */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    if (v121 == nil) goto v111;
    v121 = stack[-4];
    stack[0] = v121;
    goto v149;

v149:
    v121 = stack[-3];
    v121 = negate(v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v121 = CC_Texpt(env, stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 8); /* !:recip */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v111:
    v121 = stack[-4];
    fn = elt(env, 9); /* mkratnum */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    stack[0] = v121;
    goto v149;

v163:
    v121 = stack[-4];
    if (!consp(v121)) goto v176;
    v121 = stack[-4];
    v122 = qcar(v121);
    v121 = elt(env, 4); /* expt */
    v121 = get(v122, v121);
    env = stack[-6];
    stack[-2] = v121;
    if (v121 == nil) goto v232;
    v230 = stack[-2];
    v122 = stack[-4];
    v121 = stack[-3];
        popv(7);
        return Lapply2(nil, 3, v230, v122, v121);

v232:
    v121 = stack[-4];
    v122 = qcar(v121);
    v121 = elt(env, 5); /* i2d */
    v122 = get(v122, v121);
    env = stack[-6];
    v121 = (Lisp_Object)17; /* 1 */
    v121 = Lapply1(nil, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    stack[-5] = v121;
    v121 = stack[-4];
    v122 = qcar(v121);
    v121 = elt(env, 6); /* times */
    v121 = get(v122, v121);
    env = stack[-6];
    stack[-2] = v121;
    goto v142;

v142:
    v121 = stack[-3];
    stack[-1] = v121;
    stack[0] = (Lisp_Object)33; /* 2 */
    v122 = stack[-3];
    v121 = (Lisp_Object)33; /* 2 */
    v121 = quot2(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    stack[-3] = v121;
    v121 = times2(stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v122 = difference2(stack[-1], v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    v121 = (Lisp_Object)1; /* 0 */
    if (v122 == v121) goto v126;
    v230 = stack[-2];
    v122 = stack[-4];
    v121 = stack[-5];
    v121 = Lapply2(nil, 3, v230, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    stack[-5] = v121;
    goto v126;

v126:
    v122 = stack[-3];
    v121 = (Lisp_Object)1; /* 0 */
    if (v122 == v121) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v230 = stack[-2];
    v122 = stack[-4];
    v121 = stack[-4];
    v121 = Lapply2(nil, 3, v230, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-6];
    stack[-4] = v121;
    goto v142;

v176:
    v122 = stack[-4];
    v121 = stack[-3];
        popv(7);
        return Lexpt(nil, v122, v121);

v161:
    v121 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v121); }

v48:
    v121 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v121); }

v23:
    v122 = stack[-3];
    v121 = (Lisp_Object)1; /* 0 */
    if (v122 == v121) goto v81;
    v121 = qvalue(elt(env, 3)); /* nil */
    { popv(7); return onevalue(v121); }

v81:
    v230 = elt(env, 1); /* poly */
    v122 = (Lisp_Object)177; /* 11 */
    v121 = elt(env, 2); /* "0/0 formed" */
    {
        popv(7);
        fn = elt(env, 10); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v230, v122, v121);
    }
/* error exit handlers */
v231:
    popv(7);
    return nil;
}



/* Code for diff!-over!-k!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKoverKkKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v180, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-over-k-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-over-k-mod-p");
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
    v237 = stack[-3];
    if (!consp(v237)) goto v13;
    v237 = stack[-3];
    v237 = qcar(v237);
    if (!consp(v237)) goto v13;
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v180 = qcar(v237);
    v237 = stack[-1];
    if (equal(v180, v237)) goto v41;
    v237 = stack[-3];
    v237 = qcar(v237);
    stack[-4] = qcar(v237);
    v237 = stack[-3];
    v237 = qcar(v237);
    v182 = qcdr(v237);
    v180 = stack[-2];
    v237 = stack[-1];
    stack[0] = CC_diffKoverKkKmodKp(env, 3, v182, v180, v237);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v237 = stack[-3];
    v182 = qcdr(v237);
    v180 = stack[-2];
    v237 = stack[-1];
    v237 = CC_diffKoverKkKmodKp(env, 3, v182, v180, v237);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    {
        Lisp_Object v238 = stack[-4];
        Lisp_Object v135 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v238, v135, v237);
    }

v41:
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v180 = qcdr(v237);
    v237 = (Lisp_Object)17; /* 1 */
    if (v180 == v237) goto v28;
    v180 = stack[-1];
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v237 = (Lisp_Object)((int32_t)(v237) - 0x10);
    fn = elt(env, 3); /* mksp */
    stack[-4] = (*qfn2(fn))(qenv(fn), v180, v237);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcar(v237);
    v237 = qcdr(v237);
    v180 = Lmodular_number(nil, v237);
    env = stack[-5];
    v237 = stack[-3];
    v237 = qcar(v237);
    v237 = qcdr(v237);
    fn = elt(env, 4); /* times!-mod!-p */
    v180 = (*qfn2(fn))(qenv(fn), v180, v237);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v237 = stack[-2];
    v237 = Lmodular_number(nil, v237);
    env = stack[-5];
    fn = elt(env, 5); /* quotient!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v180, v237);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v237 = stack[-3];
    v182 = qcdr(v237);
    v180 = stack[-2];
    v237 = stack[-1];
    v237 = CC_diffKoverKkKmodKp(env, 3, v182, v180, v237);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    {
        Lisp_Object v239 = stack[-4];
        Lisp_Object v240 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v239, v240, v237);
    }

v28:
    v237 = stack[-3];
    v237 = qcar(v237);
    v180 = qcdr(v237);
    v237 = stack[-2];
    v237 = Lmodular_number(nil, v237);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* quotient!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v180, v237);
    }

v13:
    v237 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v237); }
/* error exit handlers */
v87:
    popv(6);
    return nil;
}



/* Code for fac!-merge */

static Lisp_Object CC_facKmerge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fac-merge");
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
    v18 = stack[-1];
    v41 = qcar(v18);
    v18 = stack[0];
    v18 = qcar(v18);
    fn = elt(env, 1); /* multf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v41, v18);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-3];
    v18 = stack[-1];
    v41 = qcdr(v18);
    v18 = stack[0];
    v18 = qcdr(v18);
    v18 = Lappend(nil, v41, v18);
    nil = C_nil;
    if (exception_pending()) goto v165;
    {
        Lisp_Object v24 = stack[-2];
        popv(4);
        return cons(v24, v18);
    }
/* error exit handlers */
v165:
    popv(4);
    return nil;
}



/* Code for checku */

static Lisp_Object CC_checku(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v24, v31, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checku");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v1;
    v31 = v0;
/* end of prologue */

v202:
    v165 = v31;
    if (v165 == nil) goto v30;
    v165 = v24;
    v7 = qcar(v165);
    v165 = v31;
    v165 = qcar(v165);
    v165 = qcar(v165);
    v165 = (equal(v7, v165) ? lisp_true : nil);
    if (!(v165 == nil)) return onevalue(v165);
    v165 = v31;
    v31 = qcdr(v165);
    v165 = v24;
    v24 = v165;
    goto v202;

v30:
    v165 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v165);
}



/* Code for smemberlp */

static Lisp_Object CC_smemberlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemberlp");
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

v202:
    v29 = stack[0];
    if (v29 == nil) goto v30;
    v29 = stack[0];
    if (!consp(v29)) goto v23;
    v25 = stack[-1];
    v29 = stack[0];
    v29 = qcar(v29);
    v29 = CC_smemberlp(env, v25, v29);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    if (!(v29 == nil)) { popv(3); return onevalue(v29); }
    v25 = stack[-1];
    v29 = stack[0];
    v29 = qcdr(v29);
    stack[-1] = v25;
    stack[0] = v29;
    goto v202;

v23:
    v25 = stack[0];
    v29 = stack[-1];
    v29 = Lmember(nil, v25, v29);
    { popv(3); return onevalue(v29); }

v30:
    v29 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v29); }
/* error exit handlers */
v47:
    popv(3);
    return nil;
}



/* Code for ev_invlexcomp */

static Lisp_Object CC_ev_invlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v183;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_invlexcomp");
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

v202:
    v174 = stack[-1];
    if (v174 == nil) goto v89;
    v174 = stack[-1];
    v183 = qcar(v174);
    v174 = stack[0];
    v174 = qcar(v174);
    v174 = Leqn(nil, v183, v174);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-3];
    if (v174 == nil) goto v7;
    v174 = stack[-1];
    v183 = qcdr(v174);
    v174 = stack[0];
    v174 = qcdr(v174);
    stack[-1] = v183;
    stack[0] = v174;
    goto v202;

v7:
    v174 = stack[-1];
    v183 = qcdr(v174);
    v174 = stack[0];
    v174 = qcdr(v174);
    v174 = CC_ev_invlexcomp(env, v183, v174);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-3];
    stack[-2] = v174;
    v183 = stack[-2];
    v174 = (Lisp_Object)1; /* 0 */
    v174 = Leqn(nil, v183, v174);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-3];
    if (v174 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v174 = stack[0];
    v183 = qcar(v174);
    v174 = stack[-1];
    v174 = qcar(v174);
    v174 = Leqn(nil, v183, v174);
    nil = C_nil;
    if (exception_pending()) goto v241;
    if (v174 == nil) goto v150;
    v174 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v174); }

v150:
    v174 = stack[0];
    v183 = qcar(v174);
    v174 = stack[-1];
    v174 = qcar(v174);
    if (((int32_t)(v183)) > ((int32_t)(v174))) goto v32;
    v174 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v174); }

v32:
    v174 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v174); }

v89:
    v174 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v174); }
/* error exit handlers */
v241:
    popv(4);
    return nil;
}



/* Code for multi_args */

static Lisp_Object CC_multi_args(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_args");
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
    v164 = stack[0];
    if (v164 == nil) goto v30;
    v164 = stack[0];
    v164 = qcar(v164);
    fn = elt(env, 2); /* expression */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v164 = stack[0];
    v164 = qcdr(v164);
    v164 = CC_multi_args(env, v164);
    nil = C_nil;
    if (exception_pending()) goto v16;
    goto v30;

v30:
    v164 = nil;
    { popv(2); return onevalue(v164); }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for recaliasbacksubst */

static Lisp_Object CC_recaliasbacksubst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for recaliasbacksubst");
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
    stack[-3] = v1;
    stack[0] = v0;
/* end of prologue */
    v199 = stack[0];
    if (!consp(v199)) goto v164;
    v199 = stack[0];
    fn = elt(env, 2); /* constp */
    v199 = (*qfn1(fn))(qenv(fn), v199);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    if (!(v199 == nil)) goto v164;
    v199 = stack[0];
    stack[-4] = v199;
    v199 = stack[-4];
    if (v199 == nil) goto v47;
    v199 = stack[-4];
    v199 = qcar(v199);
    v146 = v199;
    v199 = stack[-3];
    v199 = CC_recaliasbacksubst(env, v146, v199);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v199 = ncons(v199);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    stack[-1] = v199;
    stack[-2] = v199;
    goto v29;

v29:
    v199 = stack[-4];
    v199 = qcdr(v199);
    stack[-4] = v199;
    v199 = stack[-4];
    if (v199 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v199 = stack[-4];
    v199 = qcar(v199);
    v146 = v199;
    v199 = stack[-3];
    v199 = CC_recaliasbacksubst(env, v146, v199);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v199 = ncons(v199);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v199 = Lrplacd(nil, stack[0], v199);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-5];
    v199 = stack[-1];
    v199 = qcdr(v199);
    stack[-1] = v199;
    goto v29;

v47:
    v199 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v199); }

v164:
    v146 = stack[0];
    v199 = stack[-3];
    v199 = Lassoc(nil, v146, v199);
    if (v199 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v146 = stack[0];
    v199 = stack[-3];
    v199 = Lassoc(nil, v146, v199);
    v199 = qcdr(v199);
    { popv(6); return onevalue(v199); }
/* error exit handlers */
v242:
    popv(6);
    return nil;
}



/* Code for matsm!* */

static Lisp_Object CC_matsmH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm*");
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
    v13 = v1;
    v38 = v0;
/* end of prologue */
    v13 = v38;
    fn = elt(env, 1); /* matsm */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* matsm!*1 */
        return (*qfn1(fn))(qenv(fn), v13);
    }
/* error exit handlers */
v89:
    popv(1);
    return nil;
}



/* Code for lispapply */

static Lisp_Object CC_lispapply(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v7, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispapply");
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
    v7 = v1;
    v151 = v0;
/* end of prologue */
    v31 = v151;
    if (!consp(v31)) goto v18;
    stack[-1] = elt(env, 1); /* rlisp */
    stack[0] = (Lisp_Object)33; /* 2 */
    v31 = elt(env, 2); /* "Apply called with non-id arg" */
    v7 = v151;
    v31 = list2(v31, v7);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    {
        Lisp_Object v44 = stack[-1];
        Lisp_Object v29 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v44, v29, v31);
    }

v18:
    v31 = v151;
    {
        popv(3);
        fn = elt(env, 4); /* apply */
        return (*qfn2(fn))(qenv(fn), v31, v7);
    }
/* error exit handlers */
v28:
    popv(3);
    return nil;
}



/* Code for l!-subst */

static Lisp_Object MS_CDECL CC_lKsubst(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "l-subst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for l-subst");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v17 = nil;
    goto v38;

v38:
    v106 = stack[0];
    if (v106 == nil) goto v90;
    v107 = stack[-1];
    v106 = stack[0];
    v106 = qcar(v106);
    if (equal(v107, v106)) goto v36;
    v106 = stack[0];
    v106 = qcar(v106);
    v107 = v17;
    v106 = cons(v106, v107);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-3];
    v17 = v106;
    v106 = stack[0];
    v106 = qcdr(v106);
    stack[0] = v106;
    goto v38;

v36:
    v106 = stack[-2];
    v107 = v17;
    v106 = cons(v106, v107);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-3];
    v17 = v106;
    v106 = stack[0];
    v106 = qcdr(v106);
    stack[0] = v106;
    goto v38;

v90:
    v106 = v17;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v106);
    }
/* error exit handlers */
v160:
    popv(4);
    return nil;
}



/* Code for !*multf */

static Lisp_Object CC_Hmultf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v302, v303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *multf");
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
    v301 = stack[-3];
    if (v301 == nil) goto v91;
    v301 = stack[-2];
    if (v301 == nil) goto v91;
    v302 = stack[-3];
    v301 = (Lisp_Object)17; /* 1 */
    if (v302 == v301) goto v16;
    v302 = stack[-2];
    v301 = (Lisp_Object)17; /* 1 */
    if (v302 == v301) goto v18;
    v301 = stack[-3];
    if (!consp(v301)) goto v106;
    v301 = stack[-3];
    v301 = qcar(v301);
    if (!consp(v301)) goto v106;
    v301 = stack[-2];
    if (!consp(v301)) goto v163;
    v301 = stack[-2];
    v301 = qcar(v301);
    if (!consp(v301)) goto v163;
    v301 = qvalue(elt(env, 2)); /* !*noncomp */
    if (v301 == nil) goto v90;
    v302 = stack[-3];
    v301 = stack[-2];
    {
        popv(6);
        fn = elt(env, 6); /* multf */
        return (*qfn2(fn))(qenv(fn), v302, v301);
    }

v90:
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    stack[0] = v301;
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    stack[-1] = v301;
    v302 = stack[0];
    v301 = stack[-1];
    if (v302 == v301) goto v304;
    v302 = stack[0];
    v301 = stack[-1];
    fn = elt(env, 7); /* ordop */
    v301 = (*qfn2(fn))(qenv(fn), v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    if (v301 == nil) goto v306;
    v301 = stack[-3];
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[0] = v301;
    v301 = stack[-3];
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[-1] = v301;
    v301 = stack[0];
    if (v301 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    if (!consp(v301)) goto v307;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = qcar(v301);
    if (!consp(v301)) goto v307;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    if (!(v302 == v301)) goto v307;
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    if (!consp(v301)) goto v307;
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = elt(env, 3); /* (expt sqrt) */
    v301 = Lmemq(nil, v302, v301);
    if (v301 == nil) goto v307;
    v301 = stack[-3];
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = (Lisp_Object)17; /* 1 */
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v302 = ncons(v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[0];
    v302 = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[-1];
    {
        popv(6);
        fn = elt(env, 8); /* addf */
        return (*qfn2(fn))(qenv(fn), v302, v301);
    }

v307:
    v301 = stack[-3];
    v301 = qcar(v301);
    v303 = qcar(v301);
    v302 = stack[0];
    v301 = stack[-1];
    {
        popv(6);
        fn = elt(env, 9); /* makeupsf */
        return (*qfnn(fn))(qenv(fn), 3, v303, v302, v301);
    }

v306:
    v302 = stack[-3];
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[0] = v301;
    v302 = stack[-3];
    v301 = stack[-2];
    v301 = qcdr(v301);
    v301 = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[-1] = v301;
    v301 = stack[0];
    if (v301 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    if (!consp(v301)) goto v198;
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = qcar(v301);
    if (!consp(v301)) goto v198;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    if (!(v302 == v301)) goto v198;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    if (!consp(v301)) goto v198;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = elt(env, 3); /* (expt sqrt) */
    v301 = Lmemq(nil, v302, v301);
    if (v301 == nil) goto v198;
    v301 = stack[-2];
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = (Lisp_Object)17; /* 1 */
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = ncons(v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v302 = CC_Hmultf(env, stack[0], v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[-1];
    {
        popv(6);
        fn = elt(env, 8); /* addf */
        return (*qfn2(fn))(qenv(fn), v302, v301);
    }

v198:
    v301 = stack[-2];
    v301 = qcar(v301);
    v303 = qcar(v301);
    v302 = stack[0];
    v301 = stack[-1];
    {
        popv(6);
        fn = elt(env, 9); /* makeupsf */
        return (*qfnn(fn))(qenv(fn), 3, v303, v302, v301);
    }

v304:
    v301 = stack[-3];
    v301 = qcar(v301);
    v302 = ncons(v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[-2];
    v301 = qcdr(v301);
    stack[-1] = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[-3];
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    fn = elt(env, 8); /* addf */
    v301 = (*qfn2(fn))(qenv(fn), stack[-1], v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[-1] = v301;
    v302 = stack[0];
    v301 = elt(env, 4); /* sqrt */
    if (!consp(v302)) goto v308;
    v302 = qcar(v302);
    if (!(v302 == v301)) goto v308;
    v301 = stack[-1];
    fn = elt(env, 10); /* squashsqrt */
    stack[-4] = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[-1] = stack[0];
    v301 = stack[-3];
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    stack[0] = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = plus2(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    fn = elt(env, 11); /* !*multfsqrt */
    v301 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    {
        Lisp_Object v309 = stack[-4];
        popv(6);
        fn = elt(env, 8); /* addf */
        return (*qfn2(fn))(qenv(fn), v309, v301);
    }

v308:
    v302 = stack[0];
    v301 = elt(env, 5); /* expt */
    if (!consp(v302)) goto v310;
    v302 = qcar(v302);
    if (!(v302 == v301)) goto v310;
    v301 = stack[0];
    v301 = qcdr(v301);
    v301 = qcdr(v301);
    v301 = qcar(v301);
    fn = elt(env, 12); /* prefix!-rational!-numberp */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    if (v301 == nil) goto v310;
    v301 = stack[-1];
    fn = elt(env, 10); /* squashsqrt */
    stack[-4] = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[-1] = stack[0];
    v301 = stack[-3];
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    stack[0] = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = plus2(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    fn = elt(env, 13); /* !*multfexpt */
    v301 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    {
        Lisp_Object v311 = stack[-4];
        popv(6);
        fn = elt(env, 8); /* addf */
        return (*qfn2(fn))(qenv(fn), v311, v301);
    }

v310:
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = plus2(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    fn = elt(env, 14); /* mkspm */
    v301 = (*qfn2(fn))(qenv(fn), stack[0], v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[0] = v301;
    v301 = stack[0];
    if (v301 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v301 = stack[-3];
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = stack[-2];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    v301 = CC_Hmultf(env, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    stack[-3] = v301;
    if (v301 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v302 = stack[0];
    v301 = (Lisp_Object)17; /* 1 */
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v302 = ncons(v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[-3];
    fn = elt(env, 6); /* multf */
    v302 = (*qfn2(fn))(qenv(fn), v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    v301 = stack[-1];
    {
        popv(6);
        fn = elt(env, 8); /* addf */
        return (*qfn2(fn))(qenv(fn), v302, v301);
    }

v163:
    stack[0] = stack[-2];
    v301 = stack[-3];
    fn = elt(env, 10); /* squashsqrt */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    {
        Lisp_Object v312 = stack[0];
        popv(6);
        fn = elt(env, 15); /* multd */
        return (*qfn2(fn))(qenv(fn), v312, v301);
    }

v106:
    stack[0] = stack[-3];
    v301 = stack[-2];
    fn = elt(env, 10); /* squashsqrt */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-5];
    {
        Lisp_Object v313 = stack[0];
        popv(6);
        fn = elt(env, 15); /* multd */
        return (*qfn2(fn))(qenv(fn), v313, v301);
    }

v18:
    v301 = stack[-3];
    {
        popv(6);
        fn = elt(env, 10); /* squashsqrt */
        return (*qfn1(fn))(qenv(fn), v301);
    }

v16:
    v301 = stack[-2];
    {
        popv(6);
        fn = elt(env, 10); /* squashsqrt */
        return (*qfn1(fn))(qenv(fn), v301);
    }

v91:
    v301 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v301); }
/* error exit handlers */
v305:
    popv(6);
    return nil;
}



/* Code for cl_flip */

static Lisp_Object CC_cl_flip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v147, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_flip");
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
    v176 = v0;
/* end of prologue */
    v147 = v176;
    v84 = elt(env, 1); /* and */
    if (v147 == v84) goto v34;
    v147 = v176;
    v84 = elt(env, 2); /* or */
    if (v147 == v84) goto v27;
    v147 = v176;
    v84 = elt(env, 3); /* all */
    if (v147 == v84) goto v35;
    v147 = v176;
    v84 = elt(env, 4); /* ex */
    if (v147 == v84) goto v165;
    v147 = v176;
    v84 = elt(env, 5); /* ball */
    if (v147 == v84) goto v25;
    v147 = v176;
    v84 = elt(env, 6); /* bex */
    if (v147 == v84) goto v160;
    v147 = v176;
    v84 = elt(env, 7); /* true */
    if (v147 == v84) goto v163;
    v147 = v176;
    v84 = elt(env, 8); /* false */
    if (v147 == v84) goto v11;
    v84 = elt(env, 9); /* "cl_flip(): don't know" */
    v147 = v176;
    v84 = list2(v84, v147);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 10); /* rederr */
        return (*qfn1(fn))(qenv(fn), v84);
    }

v11:
    v84 = elt(env, 7); /* true */
    { popv(1); return onevalue(v84); }

v163:
    v84 = elt(env, 8); /* false */
    { popv(1); return onevalue(v84); }

v160:
    v84 = elt(env, 5); /* ball */
    { popv(1); return onevalue(v84); }

v25:
    v84 = elt(env, 6); /* bex */
    { popv(1); return onevalue(v84); }

v165:
    v84 = elt(env, 3); /* all */
    { popv(1); return onevalue(v84); }

v35:
    v84 = elt(env, 4); /* ex */
    { popv(1); return onevalue(v84); }

v27:
    v84 = elt(env, 1); /* and */
    { popv(1); return onevalue(v84); }

v34:
    v84 = elt(env, 2); /* or */
    { popv(1); return onevalue(v84); }
/* error exit handlers */
v175:
    popv(1);
    return nil;
}



/* Code for simp!*sq */

static Lisp_Object CC_simpHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v0;
/* end of prologue */
    v102 = v81;
    v102 = qcdr(v102);
    v102 = qcar(v102);
    if (v102 == nil) goto v27;
    v102 = qvalue(elt(env, 1)); /* !*resimp */
    if (!(v102 == nil)) goto v27;
    v102 = v81;
    v102 = qcar(v102);
    return onevalue(v102);

v27:
    v102 = v81;
    v102 = qcar(v102);
    {
        fn = elt(env, 2); /* resimp1 */
        return (*qfn1(fn))(qenv(fn), v102);
    }
}



/* Code for get!-denom!-l */

static Lisp_Object CC_getKdenomKl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v161, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-denom-l");
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
    v161 = v0;
/* end of prologue */
    v83 = v161;
    v83 = qcar(v83);
    if (!consp(v83)) goto v34;
    v83 = v161;
    v83 = qcar(v83);
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    goto v33;

v33:
    v161 = qcdr(v161);
    stack[0] = v161;
    goto v102;

v102:
    v161 = stack[0];
    if (v161 == nil) { popv(2); return onevalue(v83); }
    v161 = stack[0];
    v161 = qcar(v161);
    v160 = v161;
    v161 = v83;
    v83 = v160;
    if (!consp(v83)) goto v166;
    v83 = v160;
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    goto v24;

v24:
    fn = elt(env, 2); /* lcmn */
    v83 = (*qfn2(fn))(qenv(fn), v161, v83);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    v161 = stack[0];
    v161 = qcdr(v161);
    stack[0] = v161;
    goto v102;

v166:
    v83 = (Lisp_Object)17; /* 1 */
    goto v24;

v34:
    v83 = (Lisp_Object)17; /* 1 */
    goto v33;
/* error exit handlers */
v186:
    popv(2);
    return nil;
}



/* Code for sfto_ucontentf1 */

static Lisp_Object CC_sfto_ucontentf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_ucontentf1");
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
    goto v38;

v38:
    v19 = stack[-1];
    if (!consp(v19)) goto v89;
    v19 = stack[-1];
    v19 = qcar(v19);
    if (!consp(v19)) goto v89;
    v19 = stack[-1];
    v19 = qcar(v19);
    v19 = qcar(v19);
    v185 = qcar(v19);
    v19 = stack[0];
    if (!(equal(v185, v19))) goto v89;
    v19 = stack[-1];
    v19 = qcar(v19);
    v185 = qcdr(v19);
    v19 = stack[-2];
    v19 = cons(v185, v19);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[-2] = v19;
    v19 = stack[-1];
    v19 = qcdr(v19);
    stack[-1] = v19;
    goto v38;

v89:
    v19 = stack[-1];
    v185 = v19;
    goto v14;

v14:
    v19 = stack[-2];
    if (v19 == nil) { popv(4); return onevalue(v185); }
    v19 = stack[-2];
    v19 = qcar(v19);
    fn = elt(env, 1); /* sfto_gcdf!* */
    v19 = (*qfn2(fn))(qenv(fn), v19, v185);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    v185 = v19;
    v19 = stack[-2];
    v19 = qcdr(v19);
    stack[-2] = v19;
    goto v14;
/* error exit handlers */
v169:
    popv(4);
    return nil;
}



/* Code for begin11 */

static Lisp_Object CC_begin11(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v338, v339;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for begin11");
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
    stack[-5] = qvalue(elt(env, 1)); /* errmsg!* */
    qvalue(elt(env, 1)) = nil; /* errmsg!* */
    stack[-3] = nil;
    stack[-2] = qvalue(elt(env, 2)); /* newrule!* */
    qvalue(elt(env, 2)) = nil; /* newrule!* */
    v339 = qvalue(elt(env, 3)); /* cursym!* */
    v338 = elt(env, 4); /* end */
    if (v339 == v338) goto v90;
    v338 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v338 == nil) goto v107;
    v338 = stack[-4];
    v339 = v338;
    goto v166;

v166:
    v338 = elt(env, 11); /* retry */
    if (!consp(v339)) goto v14;
    v339 = qcar(v339);
    if (!(v339 == v338)) goto v14;
    v338 = qvalue(elt(env, 12)); /* programl!* */
    if (v338 == nil) goto v19;
    v338 = qvalue(elt(env, 12)); /* programl!* */
    stack[-4] = v338;
    goto v14;

v14:
    v338 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (!(v338 == nil)) goto v105;
    v338 = stack[-4];
    v338 = qcar(v338);
    stack[-3] = v338;
    v338 = stack[-4];
    v338 = qcdr(v338);
    v338 = qcar(v338);
    stack[-4] = v338;
    goto v105;

v105:
    v338 = stack[-4];
    qvalue(elt(env, 14)) = v338; /* program!* */
    fn = elt(env, 47); /* eofcheck */
    v338 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    if (v338 == nil) goto v112;
    v338 = elt(env, 15); /* c */
    goto v38;

v38:
    qvalue(elt(env, 2)) = stack[-2]; /* newrule!* */
    qvalue(elt(env, 1)) = stack[-5]; /* errmsg!* */
    { popv(7); return onevalue(v338); }

v112:
    v338 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 16)) = v338; /* eof!* */
    v339 = stack[-4];
    v338 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v338 == nil) goto v242;
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v183;

v183:
    fn = elt(env, 48); /* add2inputbuf */
    v338 = (*qfn2(fn))(qenv(fn), v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = stack[-4];
    if (!consp(v338)) goto v235;
    v338 = stack[-4];
    v339 = qcar(v338);
    v338 = elt(env, 17); /* (bye quit) */
    v338 = Lmemq(nil, v339, v338);
    if (v338 == nil) goto v235;
    v338 = elt(env, 18); /* bye */
    fn = elt(env, 49); /* getd */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    if (v338 == nil) goto v85;
    v338 = stack[-4];
    fn = elt(env, 50); /* lispeval */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v338; /* !*nosave!* */
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v85:
    v338 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 19)) = v338; /* !*byeflag!* */
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v235:
    v338 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (!(v338 == nil)) goto v70;
    v339 = stack[-4];
    v338 = elt(env, 20); /* ed */
    if (!consp(v339)) goto v70;
    v339 = qcar(v339);
    if (!(v339 == v338)) goto v70;
    v338 = elt(env, 21); /* cedit */
    fn = elt(env, 49); /* getd */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    if (v338 == nil) goto v240;
    fn = elt(env, 51); /* terminalp */
    v338 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    if (v338 == nil) goto v240;
    v338 = stack[-4];
    v338 = qcdr(v338);
    fn = elt(env, 21); /* cedit */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    goto v180;

v180:
    v338 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v338; /* !*nosave!* */
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v240:
    v338 = elt(env, 22); /* "ED not supported" */
    fn = elt(env, 52); /* lprim */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    goto v180;

v70:
    v338 = qvalue(elt(env, 23)); /* !*defn */
    if (v338 == nil) goto v228;
    v338 = qvalue(elt(env, 24)); /* erfg!* */
    if (v338 == nil) goto v128;
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v128:
    v339 = qvalue(elt(env, 25)); /* key!* */
    v338 = elt(env, 26); /* ignore */
    v338 = Lflagp(nil, v339, v338);
    env = stack[-6];
    if (!(v338 == nil)) goto v228;
    v339 = stack[-4];
    v338 = elt(env, 27); /* quote */
    if (!consp(v339)) goto v341;
    v339 = qcar(v339);
    if (!(v339 == v338)) goto v341;

v228:
    v338 = qvalue(elt(env, 29)); /* !*output */
    if (v338 == nil) goto v122;
    v338 = qvalue(elt(env, 30)); /* ifl!* */
    if (v338 == nil) goto v122;
    v338 = qvalue(elt(env, 31)); /* !*echo */
    if (v338 == nil) goto v122;
    v338 = qvalue(elt(env, 32)); /* !*lessspace */
    if (!(v338 == nil)) goto v122;
    v338 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    goto v122;

v122:
    v339 = stack[-4];
    v338 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 53); /* errorset!* */
    v338 = (*qfn2(fn))(qenv(fn), v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[0] = v338;
    v338 = stack[0];
    fn = elt(env, 54); /* errorp */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    if (!(v338 == nil)) goto v216;
    v338 = qvalue(elt(env, 24)); /* erfg!* */
    if (!(v338 == nil)) goto v216;
    v338 = qvalue(elt(env, 23)); /* !*defn */
    if (v338 == nil) goto v231;
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v231:
    v338 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v338 == nil) goto v342;
    v338 = stack[0];
    v338 = qcar(v338);
    stack[0] = v338;
    v338 = stack[0];
    if (!(v338 == nil)) goto v343;
    v339 = qvalue(elt(env, 9)); /* nil */
    v338 = elt(env, 35); /* noval */
    fn = elt(env, 55); /* mkobject */
    v338 = (*qfn2(fn))(qenv(fn), v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[0] = v338;
    goto v343;

v343:
    v338 = stack[0];
    fn = elt(env, 56); /* type */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[-3] = v338;
    v338 = stack[0];
    fn = elt(env, 57); /* value */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[0] = v338;
    goto v344;

v344:
    v338 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v338 == nil) goto v345;
    v338 = stack[0];
    v339 = v338;
    goto v346;

v346:
    v338 = stack[-3];
    fn = elt(env, 58); /* add2resultbuf */
    v338 = (*qfn2(fn))(qenv(fn), v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = qvalue(elt(env, 29)); /* !*output */
    if (v338 == nil) goto v347;
    v339 = qvalue(elt(env, 36)); /* semic!* */
    v338 = elt(env, 37); /* !$ */
    if (v339 == v338) goto v286;
    v338 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v338 == nil) goto v348;
    v338 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v339 = stack[-3];
    v338 = elt(env, 35); /* noval */
    if (v339 == v338) goto v286;
    v338 = qvalue(elt(env, 38)); /* !*debug */
    if (v338 == nil) goto v279;
    v338 = elt(env, 39); /* "Value:" */
    fn = elt(env, 59); /* prin2t */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    goto v279;

v279:
    stack[-1] = elt(env, 40); /* print */
    v339 = stack[-3];
    v338 = stack[0];
    v338 = list2(v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = ncons(v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    fn = elt(env, 60); /* rapply1 */
    v338 = (*qfn2(fn))(qenv(fn), stack[-1], v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    goto v286;

v286:
    v338 = qvalue(elt(env, 10)); /* !*reduce4 */
    if (v338 == nil) goto v349;
    v339 = qvalue(elt(env, 41)); /* !*mode */
    v338 = elt(env, 35); /* noval */
    if (v339 == v338) goto v350;
    v338 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = elt(env, 46); /* "of type: " */
    v338 = Lprinc(nil, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = stack[-3];
    v338 = Lprint(nil, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    goto v350;

v350:
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v349:
    v338 = stack[0];
    fn = elt(env, 54); /* errorp */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    if (v338 == nil) goto v351;
    v338 = elt(env, 45); /* err3 */
    goto v38;

v351:
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v348:
    v339 = stack[-3];
    v338 = elt(env, 34); /* symbolic */
    if (v339 == v338) goto v352;
    v338 = stack[0];
    v338 = qcar(v338);
    if (v338 == nil) goto v286;
    stack[-1] = elt(env, 42); /* assgnpri */
    v338 = stack[0];
    v338 = qcar(v338);
    stack[0] = Lmkquote(nil, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = stack[-4];
    if (v338 == nil) goto v262;
    v339 = elt(env, 43); /* list */
    v338 = stack[-4];
    v338 = cons(v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[-4] = v338;
    goto v353;

v353:
    v338 = elt(env, 44); /* only */
    v338 = Lmkquote(nil, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v339 = list4(stack[-1], stack[0], stack[-4], v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 53); /* errorset!* */
    v338 = (*qfn2(fn))(qenv(fn), v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[0] = v338;
    goto v286;

v262:
    v338 = qvalue(elt(env, 9)); /* nil */
    stack[-4] = v338;
    goto v353;

v352:
    v338 = stack[0];
    v338 = qcar(v338);
    if (!(v338 == nil)) goto v354;
    v339 = qvalue(elt(env, 41)); /* !*mode */
    v338 = elt(env, 34); /* symbolic */
    if (!(v339 == v338)) goto v286;

v354:
    v338 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[-1] = elt(env, 40); /* print */
    v338 = stack[0];
    v338 = qcar(v338);
    v338 = Lmkquote(nil, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v339 = list2(stack[-1], v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 53); /* errorset!* */
    v338 = (*qfn2(fn))(qenv(fn), v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[0] = v338;
    goto v286;

v347:
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v345:
    v338 = stack[0];
    v338 = qcar(v338);
    v339 = v338;
    goto v346;

v342:
    v339 = stack[-3];
    v338 = elt(env, 34); /* symbolic */
    if (v339 == v338) goto v344;
    v338 = stack[-4];
    fn = elt(env, 61); /* getsetvars */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    stack[-4] = v338;
    goto v344;

v216:
    v339 = stack[-3];
    v338 = stack[-4];
    v338 = list2(v339, v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    qvalue(elt(env, 12)) = v338; /* programl!* */
    v338 = elt(env, 33); /* err2 */
    goto v38;

v341:
    v338 = stack[-4];
    if (v338 == nil) goto v101;
    v338 = stack[-4];
    fn = elt(env, 62); /* dfprint */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    goto v101;

v101:
    v339 = qvalue(elt(env, 25)); /* key!* */
    v338 = elt(env, 28); /* eval */
    v338 = Lflagp(nil, v339, v338);
    env = stack[-6];
    if (!(v338 == nil)) goto v228;
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v242:
    v338 = stack[-3];
    goto v183;

v19:
    v338 = elt(env, 13); /* "No previous expression" */
    fn = elt(env, 52); /* lprim */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v107:
    v338 = stack[-4];
    v338 = qcdr(v338);
    v338 = qcar(v338);
    v339 = v338;
    goto v166;

v90:
    fn = elt(env, 51); /* terminalp */
    v338 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    if (v338 == nil) goto v41;
    v338 = qvalue(elt(env, 5)); /* !*lisp_hook */
    if (!(v338 == nil)) goto v41;
    v338 = elt(env, 6); /* !*semicol!* */
    qvalue(elt(env, 3)) = v338; /* cursym!* */
    v338 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 8)) = v338; /* !*nosave!* */
    v338 = qvalue(elt(env, 9)); /* nil */
    goto v38;

v41:
    v338 = elt(env, 4); /* end */
    fn = elt(env, 63); /* comm1 */
    v338 = (*qfn1(fn))(qenv(fn), v338);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-6];
    v338 = elt(env, 4); /* end */
    goto v38;
/* error exit handlers */
v340:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; /* newrule!* */
    qvalue(elt(env, 1)) = stack[-5]; /* errmsg!* */
    popv(7);
    return nil;
}



/* Code for ps!:minusp!: */

static Lisp_Object CC_psTminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v33;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:minusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v0;
/* end of prologue */
    v33 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v33);
}



/* Code for getphystypeor */

static Lisp_Object CC_getphystypeor(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypeor");
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

v202:
    v102 = stack[0];
    if (!consp(v102)) goto v34;
    v102 = stack[0];
    v102 = qcar(v102);
    fn = elt(env, 2); /* getphystype */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-1];
    if (!(v102 == nil)) { popv(2); return onevalue(v102); }
    v102 = stack[0];
    v102 = qcdr(v102);
    stack[0] = v102;
    goto v202;

v34:
    v102 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v102); }
/* error exit handlers */
v167:
    popv(2);
    return nil;
}



/* Code for red_topred */

static Lisp_Object CC_red_topred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_topred");
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
    v148 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    if (v148 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v148 = stack[-1];
    if (v148 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v103 = stack[-1];
    v148 = stack[0];
    fn = elt(env, 4); /* red_topredbe */
    v148 = (*qfn2(fn))(qenv(fn), v103, v148);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[0] = v148;
    goto v18;

v18:
    v148 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v103 = v148;
    if (v148 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v148 = v103;
    fn = elt(env, 5); /* dp_lmon */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    fn = elt(env, 6); /* red_divtest */
    v148 = (*qfn2(fn))(qenv(fn), stack[-2], v148);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[-2] = v148;
    if (v148 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v103 = stack[0];
    v148 = stack[-2];
    fn = elt(env, 7); /* red_subst */
    v148 = (*qfn2(fn))(qenv(fn), v103, v148);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[-2] = v148;
    v148 = qvalue(elt(env, 2)); /* !*noetherian */
    if (!(v148 == nil)) goto v5;
    v103 = stack[-1];
    v148 = stack[0];
    fn = elt(env, 8); /* red_update */
    v148 = (*qfn2(fn))(qenv(fn), v103, v148);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[-1] = v148;
    goto v5;

v5:
    v103 = stack[-1];
    v148 = stack[-2];
    fn = elt(env, 4); /* red_topredbe */
    v148 = (*qfn2(fn))(qenv(fn), v103, v148);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[0] = v148;
    goto v18;
/* error exit handlers */
v196:
    popv(4);
    return nil;
}



setup_type const u21_setup[] =
{
    {"cons_ordp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cons_ordp},
    {"sgn1",                    too_few_2,      CC_sgn1,       wrong_no_2},
    {"taydegree<",              too_few_2,      CC_taydegreeR, wrong_no_2},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"begin1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_begin1},
    {"vdpvevlcomp",             too_few_2,      CC_vdpvevlcomp,wrong_no_2},
    {"inprinla",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprinla},
    {"plubf",                   too_few_2,      CC_plubf,      wrong_no_2},
    {"mk-numr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKnumr},
    {"sqhorner*",               CC_sqhornerH,   too_many_1,    wrong_no_1},
    {"no_dum_varp",             CC_no_dum_varp, too_many_1,    wrong_no_1},
    {"wureducedp",              too_few_2,      CC_wureducedp, wrong_no_2},
    {"width",                   too_few_2,      CC_width,      wrong_no_2},
    {"cgp_ci",                  CC_cgp_ci,      too_many_1,    wrong_no_1},
    {"derad",                   too_few_2,      CC_derad,      wrong_no_2},
    {"unify",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_unify},
    {"lengthcdr",               CC_lengthcdr,   too_many_1,    wrong_no_1},
    {"negind",                  too_few_2,      CC_negind,     wrong_no_2},
    {"tayexp-minus",            CC_tayexpKminus,too_many_1,    wrong_no_1},
    {"mk+unit+mat",             CC_mkLunitLmat, too_many_1,    wrong_no_1},
    {"opfneval",                CC_opfneval,    too_many_1,    wrong_no_1},
    {"dm-gt",                   too_few_2,      CC_dmKgt,      wrong_no_2},
    {"expvec2a",                CC_expvec2a,    too_many_1,    wrong_no_1},
    {"can_be_proved",           too_few_2,      CC_can_be_proved,wrong_no_2},
    {"lastcar",                 CC_lastcar,     too_many_1,    wrong_no_1},
    {"red_tailred",             too_few_2,      CC_red_tailred,wrong_no_2},
    {"ad_numsort",              CC_ad_numsort,  too_many_1,    wrong_no_1},
    {"lambda_l7iptc_4",         too_few_2,      CC_lambda_l7iptc_4,wrong_no_2},
    {":expt",                   too_few_2,      CC_Texpt,      wrong_no_2},
    {"diff-over-k-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKoverKkKmodKp},
    {"fac-merge",               too_few_2,      CC_facKmerge,  wrong_no_2},
    {"checku",                  too_few_2,      CC_checku,     wrong_no_2},
    {"smemberlp",               too_few_2,      CC_smemberlp,  wrong_no_2},
    {"ev_invlexcomp",           too_few_2,      CC_ev_invlexcomp,wrong_no_2},
    {"multi_args",              CC_multi_args,  too_many_1,    wrong_no_1},
    {"recaliasbacksubst",       too_few_2,      CC_recaliasbacksubst,wrong_no_2},
    {"matsm*",                  too_few_2,      CC_matsmH,     wrong_no_2},
    {"lispapply",               too_few_2,      CC_lispapply,  wrong_no_2},
    {"l-subst",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_lKsubst},
    {"*multf",                  too_few_2,      CC_Hmultf,     wrong_no_2},
    {"cl_flip",                 CC_cl_flip,     too_many_1,    wrong_no_1},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"get-denom-l",             CC_getKdenomKl, too_many_1,    wrong_no_1},
    {"sfto_ucontentf1",         too_few_2,      CC_sfto_ucontentf1,wrong_no_2},
    {"begin11",                 CC_begin11,     too_many_1,    wrong_no_1},
    {"ps:minusp:",              CC_psTminuspT,  too_many_1,    wrong_no_1},
    {"getphystypeor",           CC_getphystypeor,too_many_1,   wrong_no_1},
    {"red_topred",              too_few_2,      CC_red_topred, wrong_no_2},
    {NULL, (one_args *)"u21", (two_args *)"18385 5715053 983618", 0}
};

/* end of generated code */
