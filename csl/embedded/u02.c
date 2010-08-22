
/* $destdir/generated-c\u02.c Machine generated C code */

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


/* Code for c!:ordexn */

static Lisp_Object CC_cTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordexn");
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
    stack[-3] = nil;
    goto v22;

v22:
    v20 = stack[-1];
    if (v20 == nil) goto v23;
    v21 = stack[-2];
    v20 = stack[-1];
    v20 = qcar(v20);
    if (equal(v21, v20)) goto v24;
    v20 = stack[-2];
    v20 = Lconsp(nil, v20);
    env = stack[-4];
    if (v20 == nil) goto v25;
    v20 = stack[-1];
    v20 = qcar(v20);
    v20 = Lconsp(nil, v20);
    env = stack[-4];
    if (!(v20 == nil)) goto v24;

v25:
    v21 = stack[-2];
    v20 = stack[-1];
    v20 = qcar(v20);
    fn = elt(env, 2); /* c!:ordxp */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    if (v20 == nil) goto v27;
    v21 = stack[-2];
    v20 = stack[-3];
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v21 = Lreverse(nil, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v20 = stack[-1];
    v20 = Lappend(nil, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v28 = stack[0];
        popv(5);
        return cons(v28, v20);
    }

v27:
    v20 = stack[-1];
    v21 = qcar(v20);
    v20 = stack[-3];
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    stack[-3] = v20;
    v20 = stack[-1];
    v20 = qcdr(v20);
    stack[-1] = v20;
    v20 = stack[0];
    v20 = (v20 == nil ? lisp_true : nil);
    stack[0] = v20;
    goto v22;

v24:
    v20 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v20); }

v23:
    v21 = stack[-2];
    v20 = stack[-3];
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v20 = Lreverse(nil, v20);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v29 = stack[0];
        popv(5);
        return cons(v29, v20);
    }
/* error exit handlers */
v26:
    popv(5);
    return nil;
}



/* Code for nil2zero */

static Lisp_Object CC_nil2zero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nil2zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v31 = v30;
    if (!(v31 == nil)) return onevalue(v30);
    v30 = (Lisp_Object)1; /* 0 */
    return onevalue(v30);
}



/* Code for bczero!? */

static Lisp_Object CC_bczeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bczero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v0;
/* end of prologue */
    v34 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v34 == nil) goto v35;
    v34 = v16;
    v16 = (Lisp_Object)1; /* 0 */
        return Leqn(nil, v34, v16);

v35:
    v16 = qcar(v16);
    v16 = (v16 == nil ? lisp_true : nil);
    return onevalue(v16);
}



/* Code for xsimp */

static Lisp_Object CC_xsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xsimp");
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
    v36 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* expchk */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v37:
    popv(1);
    return nil;
}



/* Code for evzero!? */

static Lisp_Object CC_evzeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evzero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */

v42:
    v40 = v41;
    v40 = (v40 == nil ? lisp_true : nil);
    if (!(v40 == nil)) return onevalue(v40);
    v40 = v41;
    v18 = qcar(v40);
    v40 = (Lisp_Object)1; /* 0 */
    if (v18 == v40) goto v16;
    v40 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v40);

v16:
    v40 = v41;
    v40 = qcdr(v40);
    v41 = v40;
    goto v42;
}



/* Code for wedgepf2 */

static Lisp_Object CC_wedgepf2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgepf2");
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
    v50 = stack[-2];
    if (v50 == nil) goto v36;
    v50 = stack[-1];
    if (v50 == nil) goto v36;
    v50 = stack[-2];
    v12 = qcar(v50);
    v50 = stack[-1];
    v50 = qcar(v50);
    fn = elt(env, 2); /* wedget2 */
    stack[-3] = (*qfn2(fn))(qenv(fn), v12, v50);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v50 = stack[-2];
    v50 = qcar(v50);
    v12 = ncons(v50);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v50 = stack[-1];
    v50 = qcdr(v50);
    stack[0] = CC_wedgepf2(env, v12, v50);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v50 = stack[-2];
    v12 = qcdr(v50);
    v50 = stack[-1];
    v50 = CC_wedgepf2(env, v12, v50);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    fn = elt(env, 3); /* addpf */
    v50 = (*qfn2(fn))(qenv(fn), stack[0], v50);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    {
        Lisp_Object v52 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* addpf */
        return (*qfn2(fn))(qenv(fn), v52, v50);
    }

v36:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v50); }
/* error exit handlers */
v51:
    popv(5);
    return nil;
}



/* Code for makelist */

static Lisp_Object CC_makelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v0;
/* end of prologue */
    v30 = elt(env, 1); /* list */
    return cons(v30, v55);
}



/* Code for !*physopp */

static Lisp_Object CC_Hphysopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v58;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *physopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v58 = v0;
/* end of prologue */
    v57 = v58;
    if (!consp(v57)) goto v4;
    v57 = v58;
    v57 = qcar(v57);
    if (symbolp(v57)) goto v59;
    v57 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v57);

v59:
    v57 = v58;
    v57 = qcar(v57);
    v58 = elt(env, 2); /* phystype */
    return get(v57, v58);

v4:
    v57 = v58;
    if (symbolp(v57)) goto v60;
    v57 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v57);

v60:
    v57 = v58;
    v58 = elt(env, 2); /* phystype */
    return get(v57, v58);
}



/* Code for !*ssave */

static Lisp_Object CC_Hssave(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *ssave");
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
    v63 = v1;
    stack[-1] = v0;
/* end of prologue */
    v14 = qvalue(elt(env, 1)); /* !*uncached */
    if (!(v14 == nil)) goto v37;
    stack[-2] = qvalue(elt(env, 2)); /* alglist!* */
    stack[0] = v63;
    v63 = qvalue(elt(env, 3)); /* !*sub2 */
    v14 = stack[-1];
    v63 = cons(v63, v14);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v14 = qvalue(elt(env, 2)); /* alglist!* */
    v14 = qcar(v14);
    v14 = acons(stack[0], v63, v14);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v14 = Lrplaca(nil, stack[-2], v14);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v37;

v37:
    v14 = qvalue(elt(env, 4)); /* simpcount!* */
    v14 = sub1(v14);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    qvalue(elt(env, 4)) = v14; /* simpcount!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v58:
    popv(4);
    return nil;
}



/* Code for addd */

static Lisp_Object CC_addd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addd");
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
    v50 = nil;
    goto v37;

v37:
    v47 = stack[0];
    if (v47 == nil) goto v35;
    v47 = stack[0];
    if (!consp(v47)) goto v19;
    v47 = stack[0];
    v47 = qcar(v47);
    if (!consp(v47)) goto v19;
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = cons(v47, v50);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v50 = v47;
    v47 = stack[0];
    v47 = qcdr(v47);
    stack[0] = v47;
    goto v37;

v19:
    stack[-2] = v50;
    v50 = stack[-1];
    v47 = stack[0];
    fn = elt(env, 1); /* adddm */
    v47 = (*qfn2(fn))(qenv(fn), v50, v47);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    {
        Lisp_Object v67 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v67, v47);
    }

v35:
    v47 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v50, v47);
    }
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for mo_vdivides!? */

static Lisp_Object CC_mo_vdividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_vdivides?");
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
    v19 = stack[-1];
    fn = elt(env, 2); /* mo_comp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v19 = stack[0];
    fn = elt(env, 2); /* mo_comp */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v19 = Leqn(nil, stack[-2], v19);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    if (v19 == nil) goto v36;
    v24 = stack[-1];
    v19 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v24, v19);
    }

v36:
    v19 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v19); }
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for pappl0 */

static Lisp_Object CC_pappl0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl0");
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
    v33 = v1;
    v32 = v0;
/* end of prologue */
    stack[0] = v32;
    fn = elt(env, 1); /* unpkp */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    fn = elt(env, 2); /* pappl */
    v33 = (*qfn2(fn))(qenv(fn), stack[0], v33);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v33);
    }
/* error exit handlers */
v60:
    popv(2);
    return nil;
}



/* Code for !*i2mod */

static Lisp_Object CC_Hi2mod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2mod");
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
    v36 = v0;
/* end of prologue */
    fn = elt(env, 1); /* general!-modular!-number */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v37:
    popv(1);
    return nil;
}



/* Code for general!-modular!-times */

static Lisp_Object CC_generalKmodularKtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v57;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-times");
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
    v48 = v1;
    v57 = v0;
/* end of prologue */
    v57 = times2(v57, v48);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    v48 = qvalue(elt(env, 1)); /* current!-modulus */
    v48 = Cremainder(v57, v48);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    stack[0] = v48;
    v57 = stack[0];
    v48 = (Lisp_Object)1; /* 0 */
    v48 = (Lisp_Object)lessp2(v57, v48);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v48 = v48 ? lisp_true : nil;
    env = stack[-1];
    if (v48 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v57 = stack[0];
    v48 = qvalue(elt(env, 1)); /* current!-modulus */
    v48 = plus2(v57, v48);
    nil = C_nil;
    if (exception_pending()) goto v69;
    stack[0] = v48;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v69:
    popv(2);
    return nil;
}



/* Code for getpower */

static Lisp_Object CC_getpower(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getpower");
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
    v44 = stack[-1];
    v15 = qcar(v44);
    v44 = elt(env, 1); /* expt */
    if (!consp(v15)) goto v19;
    v15 = qcar(v15);
    if (!(v15 == v44)) goto v19;
    v15 = stack[0];
    v44 = (Lisp_Object)17; /* 1 */
    v44 = (Lisp_Object)greaterp2(v15, v44);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v44 = v44 ? lisp_true : nil;
    env = stack[-2];
    if (v44 == nil) goto v19;
    v44 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v44; /* !*sub2 */
    goto v19;

v19:
    v44 = stack[-1];
    v15 = qcar(v44);
    v44 = stack[0];
    popv(3);
    return cons(v15, v44);
/* error exit handlers */
v63:
    popv(3);
    return nil;
}



/* Code for cl_atfp */

static Lisp_Object CC_cl_atfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v89;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atfp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v88 = v0;
/* end of prologue */
    v87 = v88;
    if (!consp(v87)) goto v4;
    v87 = v88;
    v87 = qcar(v87);
    goto v11;

v11:
    v89 = v87;
    v88 = v89;
    v87 = elt(env, 1); /* true */
    v87 = (v88 == v87 ? lisp_true : nil);
    if (!(v87 == nil)) goto v38;
    v88 = v89;
    v87 = elt(env, 2); /* false */
    v87 = (v88 == v87 ? lisp_true : nil);
    goto v38;

v38:
    if (!(v87 == nil)) goto v32;
    v88 = v89;
    v87 = elt(env, 3); /* or */
    v87 = (v88 == v87 ? lisp_true : nil);
    if (!(v87 == nil)) goto v57;
    v88 = v89;
    v87 = elt(env, 4); /* and */
    v87 = (v88 == v87 ? lisp_true : nil);
    goto v57;

v57:
    if (!(v87 == nil)) goto v63;
    v88 = v89;
    v87 = elt(env, 5); /* not */
    v87 = (v88 == v87 ? lisp_true : nil);
    goto v63;

v63:
    if (!(v87 == nil)) goto v15;
    v88 = v89;
    v87 = elt(env, 6); /* impl */
    v87 = (v88 == v87 ? lisp_true : nil);
    if (!(v87 == nil)) goto v15;
    v88 = v89;
    v87 = elt(env, 7); /* repl */
    v87 = (v88 == v87 ? lisp_true : nil);
    if (!(v87 == nil)) goto v15;
    v88 = v89;
    v87 = elt(env, 8); /* equiv */
    v87 = (v88 == v87 ? lisp_true : nil);
    goto v15;

v15:
    if (!(v87 == nil)) goto v32;
    v88 = v89;
    v87 = elt(env, 9); /* ex */
    v87 = (v88 == v87 ? lisp_true : nil);
    if (!(v87 == nil)) goto v21;
    v88 = v89;
    v87 = elt(env, 10); /* all */
    v87 = (v88 == v87 ? lisp_true : nil);
    goto v21;

v21:
    if (!(v87 == nil)) goto v32;
    v88 = v89;
    v87 = elt(env, 11); /* bex */
    v87 = (v88 == v87 ? lisp_true : nil);
    if (!(v87 == nil)) goto v32;
    v87 = v89;
    v88 = elt(env, 12); /* ball */
    v87 = (v87 == v88 ? lisp_true : nil);
    goto v32;

v32:
    v87 = (v87 == nil ? lisp_true : nil);
    return onevalue(v87);

v4:
    v87 = v88;
    goto v11;
}



/* Code for minusf */

static Lisp_Object CC_minusf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47, v50;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusf");
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

v4:
    v46 = v47;
    if (v46 == nil) goto v22;
    v46 = v47;
    if (!consp(v46)) goto v30;
    v46 = v47;
    v46 = qcar(v46);
    if (!consp(v46)) goto v30;
    v46 = v47;
    v46 = qcar(v46);
    v46 = qcdr(v46);
    v47 = v46;
    goto v4;

v30:
    v46 = v47;
    if (!consp(v46)) goto v41;
    v46 = v47;
    v50 = qcar(v46);
    v46 = elt(env, 2); /* minusp */
    v46 = get(v50, v46);
        return Lapply1(nil, v46, v47);

v41:
    v46 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v47, v46);

v22:
    v46 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v46);
}



/* Code for sfp */

static Lisp_Object CC_sfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v35;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */
    v32 = v35;
    if (!consp(v32)) goto v4;
    v32 = v35;
    v32 = qcar(v32);
    v32 = (consp(v32) ? nil : lisp_true);
    v32 = (v32 == nil ? lisp_true : nil);
    return onevalue(v32);

v4:
    v32 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v32);
}



/* Code for subs2f */

static Lisp_Object CC_subs2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2f");
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
    v93 = qvalue(elt(env, 1)); /* simpcount!* */
    v92 = qvalue(elt(env, 2)); /* simplimit!* */
    v92 = (Lisp_Object)greaterp2(v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v9;
    v92 = v92 ? lisp_true : nil;
    env = stack[-2];
    if (v92 == nil) goto v37;
    v92 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v92; /* simpcount!* */
    v82 = elt(env, 3); /* poly */
    v93 = (Lisp_Object)337; /* 21 */
    v92 = elt(env, 4); /* "Simplification recursion too deep" */
    fn = elt(env, 9); /* rerror */
    v92 = (*qfnn(fn))(qenv(fn), 3, v82, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    goto v37;

v37:
    v92 = qvalue(elt(env, 1)); /* simpcount!* */
    v92 = add1(v92);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    qvalue(elt(env, 1)) = v92; /* simpcount!* */
    v92 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 6)) = v92; /* !*sub2 */
    v92 = stack[0];
    fn = elt(env, 10); /* subs2f1 */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    stack[-1] = v92;
    v92 = qvalue(elt(env, 6)); /* !*sub2 */
    if (!(v92 == nil)) goto v94;
    v92 = qvalue(elt(env, 7)); /* powlis1!* */
    if (!(v92 == nil)) goto v94;

v59:
    v92 = qvalue(elt(env, 1)); /* simpcount!* */
    v92 = sub1(v92);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    qvalue(elt(env, 1)) = v92; /* simpcount!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v94:
    v92 = qvalue(elt(env, 8)); /* !*resubs */
    if (v92 == nil) goto v59;
    v92 = stack[-1];
    v93 = qcar(v92);
    v92 = stack[0];
    if (!(equal(v93, v92))) goto v95;
    v92 = stack[-1];
    v93 = qcdr(v92);
    v92 = (Lisp_Object)17; /* 1 */
    if (!(v93 == v92)) goto v95;
    v92 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 6)) = v92; /* !*sub2 */
    goto v59;

v95:
    v92 = stack[-1];
    fn = elt(env, 11); /* subs2q */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    stack[-1] = v92;
    goto v59;
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for retimes */

static Lisp_Object CC_retimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retimes");
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
    stack[0] = qvalue(elt(env, 1)); /* !*bool */
    qvalue(elt(env, 1)) = nil; /* !*bool */
    fn = elt(env, 4); /* retimes1 */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    v49 = v69;
    if (v49 == nil) goto v53;
    v49 = v69;
    v49 = qcdr(v49);
    if (v49 == nil) goto v40;
    v49 = elt(env, 2); /* times */
    v69 = cons(v49, v69);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    goto v54;

v54:
    v49 = qvalue(elt(env, 1)); /* !*bool */
    if (v49 == nil) goto v4;
    v49 = elt(env, 3); /* minus */
    v69 = list2(v49, v69);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    goto v4;

v4:
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    { popv(2); return onevalue(v69); }

v40:
    v69 = qcar(v69);
    goto v54;

v53:
    v69 = (Lisp_Object)17; /* 1 */
    goto v54;
/* error exit handlers */
v90:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    popv(2);
    return nil;
}



/* Code for sinitl */

static Lisp_Object CC_sinitl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sinitl");
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
    v39 = v0;
/* end of prologue */
    stack[0] = v39;
    v17 = v39;
    v39 = elt(env, 1); /* initl */
    v39 = get(v17, v39);
    env = stack[-1];
    fn = elt(env, 2); /* eval */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v34;
    {
        Lisp_Object v23 = stack[0];
        popv(2);
        return Lset(nil, v23, v39);
    }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for aeval */

static Lisp_Object CC_aeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aeval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v0;
/* end of prologue */
    v30 = v55;
    v55 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v30, v55);
    }
}



/* Code for constp */

static Lisp_Object CC_constp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constp");
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
    v40 = v0;
/* end of prologue */
    v41 = v40;
    v41 = (is_number(v41) ? lisp_true : nil);
    if (!(v41 == nil)) { popv(1); return onevalue(v41); }
    v41 = v40;
    v41 = Lconsp(nil, v41);
    env = stack[0];
    if (v41 == nil) goto v53;
    v40 = qcar(v40);
    v41 = qvalue(elt(env, 2)); /* domainlist!* */
    v40 = Lmemq(nil, v40, v41);
    { popv(1); return onevalue(v40); }

v53:
    v40 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v40); }
}



/* Code for mval */

static Lisp_Object CC_mval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v11;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v0;
/* end of prologue */
    return onevalue(v11);
}



/* Code for evmatrixcomp1 */

static Lisp_Object MS_CDECL CC_evmatrixcomp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmatrixcomp1");
#endif
    if (stack >= stacklimit)
    {
        push3(v86,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v86;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v42:
    v92 = stack[-1];
    if (v92 == nil) goto v37;
    v82 = stack[-3];
    v92 = stack[-1];
    v93 = qcar(v92);
    v92 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* evmatrixcomp2 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v82, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v82 = stack[-2];
    v92 = stack[-1];
    v93 = qcar(v92);
    v92 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* evmatrixcomp2 */
    v92 = (*qfnn(fn))(qenv(fn), 3, v82, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v92;
    v93 = stack[-4];
    v92 = stack[0];
    v92 = Leqn(nil, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    if (v92 == nil) goto v100;
    v82 = stack[-3];
    v93 = stack[-2];
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-3] = v82;
    stack[-2] = v93;
    stack[-1] = v92;
    goto v42;

v100:
    v93 = stack[-4];
    v92 = stack[0];
    if (((int32_t)(v93)) > ((int32_t)(v92))) goto v51;
    v92 = (Lisp_Object)-15; /* -1 */
    { popv(6); return onevalue(v92); }

v51:
    v92 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v92); }

v37:
    v92 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v92); }
/* error exit handlers */
v99:
    popv(6);
    return nil;
}



/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domain*p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    v18 = v19;
    v18 = (v18 == nil ? lisp_true : nil);
    if (!(v18 == nil)) return onevalue(v18);
    v18 = v19;
    v18 = (is_number(v18) ? lisp_true : nil);
    if (!(v18 == nil)) return onevalue(v18);
    v18 = v19;
    if (!consp(v18)) goto v31;
    v18 = v19;
    v18 = qcar(v18);
    v19 = qvalue(elt(env, 2)); /* domainlist!* */
    v18 = Lmemq(nil, v18, v19);
    return onevalue(v18);

v31:
    v18 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v18);
}



/* Code for getrtypeor */

static Lisp_Object CC_getrtypeor(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtypeor");
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

v42:
    v17 = stack[0];
    if (v17 == nil) goto v4;
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 2); /* getrtype */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    if (!(v17 == nil)) { popv(2); return onevalue(v17); }
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v42;

v4:
    v17 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v17); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for adddm */

static Lisp_Object CC_adddm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v78, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adddm");
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
    v78 = v1;
    v97 = v0;
/* end of prologue */
    v95 = v97;
    if (!(!consp(v95))) goto v51;
    v95 = v78;
    if (!(!consp(v95))) goto v51;
    v95 = v97;
    v95 = plus2(v95, v78);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[0];
    v97 = v95;
    v95 = qvalue(elt(env, 1)); /* dmode!* */
    if (v95 == nil) goto v23;
    v78 = qvalue(elt(env, 1)); /* dmode!* */
    v95 = elt(env, 2); /* convert */
    v95 = Lflagp(nil, v78, v95);
    env = stack[0];
    if (v95 == nil) goto v23;
    v78 = qvalue(elt(env, 1)); /* dmode!* */
    v95 = elt(env, 3); /* i2d */
    v95 = get(v78, v95);
    env = stack[0];
    v78 = v97;
    v95 = Lapply1(nil, v95, v78);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v95);
    }

v23:
    v95 = v97;
    {
        popv(1);
        fn = elt(env, 6); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v95);
    }

v51:
    v95 = elt(env, 4); /* plus */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v97, v78, v95);
    }
/* error exit handlers */
v102:
    popv(1);
    return nil;
}



/* Code for angles!-equal */

static Lisp_Object CC_anglesKequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v85, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for angles-equal");
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
    v98 = (Lisp_Object)1; /* 0 */
    stack[-2] = v98;
    goto v38;

v38:
    v85 = stack[-1];
    v98 = stack[-2];
    v64 = *(Lisp_Object *)((char *)v85 + (CELL-TAG_VECTOR) + ((int32_t)v98/(16/CELL)));
    v85 = stack[0];
    v98 = stack[-2];
    v98 = *(Lisp_Object *)((char *)v85 + (CELL-TAG_VECTOR) + ((int32_t)v98/(16/CELL)));
    if (equal(v64, v98)) goto v53;
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v98); }

v53:
    v98 = stack[-2];
    v98 = add1(v98);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    stack[-2] = v98;
    v85 = stack[-2];
    v98 = (Lisp_Object)129; /* 8 */
    v98 = (Lisp_Object)lessp2(v85, v98);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v98 = v98 ? lisp_true : nil;
    env = stack[-3];
    if (!(v98 == nil)) goto v38;
    v98 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v98); }
/* error exit handlers */
v47:
    popv(4);
    return nil;
}



/* Code for mo!=sprod */

static Lisp_Object CC_moMsprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v84, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=sprod");
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
    v13 = nil;
    goto v22;

v22:
    v12 = stack[-1];
    if (v12 == nil) goto v54;
    v12 = stack[0];
    if (v12 == nil) goto v54;
    v12 = stack[-1];
    v84 = qcar(v12);
    v12 = stack[0];
    v12 = qcar(v12);
    v12 = fixnum_of_int((int32_t)(int_of_fixnum(v84) * int_of_fixnum(v12)));
    v84 = v13;
    v12 = cons(v12, v84);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v13 = v12;
    v12 = stack[-1];
    v12 = qcdr(v12);
    stack[-1] = v12;
    v12 = stack[0];
    v12 = qcdr(v12);
    stack[0] = v12;
    goto v22;

v54:
    v12 = (Lisp_Object)1; /* 0 */
    goto v53;

v53:
    v84 = v13;
    if (v84 == nil) { popv(3); return onevalue(v12); }
    v84 = v13;
    v84 = qcar(v84);
    v12 = (Lisp_Object)(int32_t)((int32_t)v84 + (int32_t)v12 - TAG_FIXNUM);
    v84 = v13;
    v84 = qcdr(v84);
    v13 = v84;
    goto v53;
/* error exit handlers */
v51:
    popv(3);
    return nil;
}



/* Code for sieve_pv */

static Lisp_Object CC_sieve_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v35, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sieve_pv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v1;
    v35 = v0;
/* end of prologue */
    v60 = v35;
    v35 = v32;
    v32 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* sieve_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v60, v35, v32);
    }
}



/* Code for upbve */

static Lisp_Object CC_upbve(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for upbve");
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
    v32 = stack[0];
    v32 = Lupbv(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    if (v32 == nil) goto v4;
    v32 = stack[0];
    v32 = Lupbv(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v60;
    popv(2);
    return add1(v32);

v4:
    v32 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v32); }
/* error exit handlers */
v60:
    popv(2);
    return nil;
}



/* Code for modtimes!: */

static Lisp_Object CC_modtimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modtimes:");
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
    v32 = v1;
    v35 = v0;
/* end of prologue */
    v35 = qcdr(v35);
    v32 = qcdr(v32);
    fn = elt(env, 1); /* general!-modular!-times */
    v32 = (*qfn2(fn))(qenv(fn), v35, v32);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v60:
    popv(1);
    return nil;
}



/* Code for general!-modular!-plus */

static Lisp_Object CC_generalKmodularKplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v44;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-plus");
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
    v59 = v1;
    v44 = v0;
/* end of prologue */
    v59 = plus2(v44, v59);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    stack[0] = v59;
    v44 = stack[0];
    v59 = qvalue(elt(env, 1)); /* current!-modulus */
    v59 = (Lisp_Object)geq2(v44, v59);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v59 = v59 ? lisp_true : nil;
    env = stack[-1];
    if (v59 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v44 = stack[0];
    v59 = qvalue(elt(env, 1)); /* current!-modulus */
    v59 = difference2(v44, v59);
    nil = C_nil;
    if (exception_pending()) goto v94;
    stack[0] = v59;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v94:
    popv(2);
    return nil;
}



/* Code for remainder!-in!-vector */

static Lisp_Object MS_CDECL CC_remainderKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v86, Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v123, v124, v125, v126, v127, v128, v129, v130, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "remainder-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remainder-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v11,v86,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v86,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v86;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v123 = stack[0];
    v122 = (Lisp_Object)1; /* 0 */
    if (v123 == v122) goto v33;
    v123 = stack[0];
    v122 = (Lisp_Object)-15; /* -1 */
    if (!(v123 == v122)) goto v59;
    v122 = elt(env, 1); /* "ATTEMPT TO DIVIDE BY ZERO" */
    fn = elt(env, 3); /* errorf */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    goto v59;

v59:
    v123 = stack[-1];
    v122 = stack[0];
    v122 = *(Lisp_Object *)((char *)v123 + (CELL-TAG_VECTOR) + ((int32_t)v122/(16/CELL)));
    v122 = Lmodular_reciprocal(nil, v122);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v122);
        if (w != 0) w = current_modulus - w;
        v122 = fixnum_of_int(w);
    }
    v129 = v122;
    v122 = stack[0];
    v122 = (Lisp_Object)((int32_t)(v122) - 0x10);
    v130 = v122;
    goto v84;

v84:
    v123 = stack[-2];
    v122 = stack[0];
    v123 = (Lisp_Object)(int32_t)((int32_t)v123 - (int32_t)v122 + TAG_FIXNUM);
    v131 = v123;
    v122 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v123)) < ((int32_t)(v122))) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v124 = v129;
    v123 = stack[-3];
    v122 = stack[-2];
    v122 = *(Lisp_Object *)((char *)v123 + (CELL-TAG_VECTOR) + ((int32_t)v122/(16/CELL)));
    v122 = Lmodular_times(nil, v124, v122);
    env = stack[-4];
    v128 = v122;
    v122 = (Lisp_Object)1; /* 0 */
    v127 = v122;
    goto v2;

v2:
    v123 = v130;
    v122 = v127;
    v122 = (Lisp_Object)(int32_t)((int32_t)v123 - (int32_t)v122 + TAG_FIXNUM);
    v122 = ((intptr_t)(v122) < 0 ? lisp_true : nil);
    if (v122 == nil) goto v133;
    v122 = stack[-2];
    v122 = (Lisp_Object)((int32_t)(v122) - 0x10);
    stack[-2] = v122;
    goto v134;

v134:
    v123 = stack[-2];
    v122 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v123)) < ((int32_t)(v122))) goto v84;
    v123 = stack[-3];
    v122 = stack[-2];
    v123 = *(Lisp_Object *)((char *)v123 + (CELL-TAG_VECTOR) + ((int32_t)v122/(16/CELL)));
    v122 = (Lisp_Object)1; /* 0 */
    if (!(v123 == v122)) goto v84;
    v122 = stack[-2];
    v122 = (Lisp_Object)((int32_t)(v122) - 0x10);
    stack[-2] = v122;
    goto v134;

v133:
    v126 = stack[-3];
    v123 = v127;
    v122 = v131;
    v125 = (Lisp_Object)(int32_t)((int32_t)v123 + (int32_t)v122 - TAG_FIXNUM);
    v124 = stack[-3];
    v123 = v127;
    v122 = v131;
    v122 = (Lisp_Object)(int32_t)((int32_t)v123 + (int32_t)v122 - TAG_FIXNUM);
    v124 = *(Lisp_Object *)((char *)v124 + (CELL-TAG_VECTOR) + ((int32_t)v122/(16/CELL)));
    v123 = stack[-1];
    v122 = v127;
    v123 = *(Lisp_Object *)((char *)v123 + (CELL-TAG_VECTOR) + ((int32_t)v122/(16/CELL)));
    v122 = v128;
    v122 = Lmodular_times(nil, v123, v122);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v124) + int_of_fixnum(v122);
        if (w >= current_modulus) w -= current_modulus;
        v122 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v126 + (CELL-TAG_VECTOR) + ((int32_t)v125/(16/CELL))) = v122;
    v122 = v127;
    v122 = (Lisp_Object)((int32_t)(v122) + 0x10);
    v127 = v122;
    goto v2;

v33:
    v122 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v122); }
/* error exit handlers */
v132:
    popv(5);
    return nil;
}



/* Code for powers0 */

static Lisp_Object CC_powers0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v77, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers0");
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

v42:
    v29 = stack[-1];
    if (v29 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v29 = stack[-1];
    if (!consp(v29)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v29 = stack[-1];
    v29 = qcar(v29);
    if (!consp(v29)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v29 = stack[-1];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v77 = qcar(v29);
    v29 = stack[0];
    v77 = Latsoc(nil, v77, v29);
    v29 = v77;
    if (v77 == nil) goto v137;
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = qcar(v77);
    v77 = qcdr(v77);
    v29 = qcdr(v29);
    v29 = (Lisp_Object)greaterp2(v77, v29);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v29 = v29 ? lisp_true : nil;
    env = stack[-3];
    if (v29 == nil) goto v139;
    v29 = stack[-1];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v136 = qcar(v29);
    v29 = stack[-1];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v77 = qcdr(v29);
    v29 = stack[0];
    fn = elt(env, 1); /* repasc */
    v29 = (*qfnn(fn))(qenv(fn), 3, v136, v77, v29);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    stack[0] = v29;
    goto v139;

v139:
    v29 = stack[-1];
    stack[-2] = qcdr(v29);
    v29 = stack[-1];
    v29 = qcar(v29);
    v77 = qcdr(v29);
    v29 = stack[0];
    v29 = CC_powers0(env, v77, v29);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v29;
    goto v42;

v137:
    v29 = stack[-1];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v136 = qcar(v29);
    v29 = stack[-1];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v77 = qcdr(v29);
    v29 = stack[0];
    v29 = acons(v136, v77, v29);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    stack[0] = v29;
    goto v139;
/* error exit handlers */
v138:
    popv(4);
    return nil;
}



/* Code for comfac!-to!-poly */

static Lisp_Object CC_comfacKtoKpoly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v35;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comfac-to-poly");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v35 = v32;
    v35 = qcar(v35);
    if (v35 == nil) goto v4;
    return ncons(v32);

v4:
    v32 = qcdr(v32);
    return onevalue(v32);
}



/* Code for tayexp!-plus2 */

static Lisp_Object CC_tayexpKplus2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v83, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-plus2");
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
    v83 = v0;
/* end of prologue */
    v82 = v83;
    if (!(!consp(v82))) goto v17;
    v82 = stack[0];
    if (!(!consp(v82))) goto v17;
    v82 = stack[0];
    popv(3);
    return plus2(v83, v82);

v17:
    v82 = v83;
    if (!consp(v82)) goto v18;
    v82 = stack[0];
    if (!consp(v82)) goto v14;
    v82 = stack[0];
    fn = elt(env, 1); /* rnplus!: */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v8;
    goto v23;

v23:
    v140 = v82;
    v82 = v140;
    v82 = qcdr(v82);
    v83 = qcdr(v82);
    v82 = (Lisp_Object)17; /* 1 */
    if (!(v83 == v82)) { popv(3); return onevalue(v140); }
    v82 = v140;
    v82 = qcdr(v82);
    v82 = qcar(v82);
    { popv(3); return onevalue(v82); }

v14:
    stack[-1] = v83;
    v82 = stack[0];
    fn = elt(env, 2); /* !*i2rn */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    fn = elt(env, 1); /* rnplus!: */
    v82 = (*qfn2(fn))(qenv(fn), stack[-1], v82);
    nil = C_nil;
    if (exception_pending()) goto v8;
    goto v23;

v18:
    v82 = v83;
    fn = elt(env, 2); /* !*i2rn */
    v83 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    v82 = stack[0];
    fn = elt(env, 1); /* rnplus!: */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v8;
    goto v23;
/* error exit handlers */
v8:
    popv(3);
    return nil;
}



/* Code for multsq */

static Lisp_Object CC_multsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsq");
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
    v151 = stack[-3];
    v151 = qcar(v151);
    if (v151 == nil) goto v32;
    v151 = stack[-2];
    v151 = qcar(v151);
    if (v151 == nil) goto v32;
    v151 = stack[-3];
    v152 = qcdr(v151);
    v151 = (Lisp_Object)17; /* 1 */
    if (!(v152 == v151)) goto v6;
    v151 = stack[-2];
    v152 = qcdr(v151);
    v151 = (Lisp_Object)17; /* 1 */
    if (!(v152 == v151)) goto v6;
    v151 = stack[-3];
    v152 = qcar(v151);
    v151 = stack[-2];
    v151 = qcar(v151);
    fn = elt(env, 2); /* multf */
    v152 = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v151 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v152, v151);

v6:
    v151 = stack[-3];
    v152 = qcar(v151);
    v151 = stack[-2];
    v151 = qcdr(v151);
    fn = elt(env, 3); /* gcdf */
    v151 = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-4] = v151;
    v151 = stack[-2];
    v152 = qcar(v151);
    v151 = stack[-3];
    v151 = qcdr(v151);
    fn = elt(env, 3); /* gcdf */
    v151 = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-1] = v151;
    v151 = stack[-3];
    v152 = qcar(v151);
    v151 = stack[-4];
    fn = elt(env, 4); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v151 = stack[-2];
    v152 = qcar(v151);
    v151 = stack[-1];
    fn = elt(env, 4); /* quotf */
    v151 = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    fn = elt(env, 2); /* multf */
    v151 = (*qfn2(fn))(qenv(fn), stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[0] = v151;
    v151 = stack[-3];
    v152 = qcdr(v151);
    v151 = stack[-1];
    fn = elt(env, 4); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    v151 = stack[-2];
    v152 = qcdr(v151);
    v151 = stack[-4];
    fn = elt(env, 4); /* quotf */
    v151 = (*qfn2(fn))(qenv(fn), v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    fn = elt(env, 2); /* multf */
    v151 = (*qfn2(fn))(qenv(fn), stack[-1], v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    stack[-4] = v151;
    v152 = stack[0];
    v151 = stack[-4];
    v151 = cons(v152, v151);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v151);
    }

v32:
    v152 = qvalue(elt(env, 1)); /* nil */
    v151 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v152, v151);
/* error exit handlers */
v114:
    popv(6);
    return nil;
}



/* Code for ibalp_getnewwl */

static Lisp_Object CC_ibalp_getnewwl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v120, v20, v21, v149;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getnewwl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v0;
/* end of prologue */
    v20 = nil;
    v135 = v21;
    v135 = qcar(v135);
    v149 = v135;
    goto v55;

v55:
    v135 = v149;
    if (v135 == nil) goto v53;
    v135 = v20;
    if (!(v135 == nil)) goto v53;
    v135 = v149;
    v135 = qcar(v135);
    v135 = qcdr(v135);
    v135 = qcar(v135);
    if (!(v135 == nil)) goto v34;
    v135 = v149;
    v120 = qcar(v135);
    v135 = v21;
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcar(v135);
    v135 = Lmemq(nil, v120, v135);
    if (!(v135 == nil)) goto v34;
    v135 = v149;
    v135 = qcar(v135);
    v20 = v135;
    goto v34;

v34:
    v135 = v149;
    v135 = qcdr(v135);
    v149 = v135;
    goto v55;

v53:
    v135 = v21;
    v135 = qcdr(v135);
    v135 = qcar(v135);
    v149 = v135;
    goto v47;

v47:
    v135 = v149;
    if (v135 == nil) return onevalue(v20);
    v135 = v20;
    if (!(v135 == nil)) return onevalue(v20);
    v135 = v149;
    v135 = qcar(v135);
    v135 = qcdr(v135);
    v135 = qcar(v135);
    if (!(v135 == nil)) goto v6;
    v135 = v149;
    v120 = qcar(v135);
    v135 = v21;
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcdr(v135);
    v135 = qcar(v135);
    v135 = Lmemq(nil, v120, v135);
    if (!(v135 == nil)) goto v6;
    v135 = v149;
    v135 = qcar(v135);
    v20 = v135;
    goto v6;

v6:
    v135 = v149;
    v135 = qcdr(v135);
    v149 = v135;
    goto v47;
}



/* Code for attributes */

static Lisp_Object CC_attributes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v51;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for attributes");
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
    v67 = v0;
/* end of prologue */
    v67 = Llength(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    stack[-2] = v67;
    v67 = (Lisp_Object)17; /* 1 */
    stack[0] = v67;
    goto v17;

v17:
    v51 = stack[-2];
    v67 = stack[0];
    v67 = difference2(v51, v67);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v67 = Lminusp(nil, v67);
    env = stack[-3];
    if (!(v67 == nil)) goto v94;
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    v67 = stack[0];
    v67 = add1(v67);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    stack[0] = v67;
    goto v17;

v94:
    v67 = stack[-1];
    v51 = qcar(v67);
    v67 = elt(env, 2); /* !  */
    if (v51 == v67) goto v59;
    v51 = stack[-1];
    v67 = elt(env, 3); /* (!$) */
    if (equal(v51, v67)) goto v85;
    v67 = stack[-1];
    qvalue(elt(env, 4)) = v67; /* atts */
    goto v85;

v85:
    v67 = nil;
    { popv(4); return onevalue(v67); }

v59:
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v94;
/* error exit handlers */
v6:
    popv(4);
    return nil;
}



/* Code for !:zerop */

static Lisp_Object CC_Tzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v63, v56;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :zerop");
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
    v56 = v0;
/* end of prologue */
    v14 = v56;
    if (v14 == nil) goto v4;
    v63 = v56;
    v14 = (Lisp_Object)1; /* 0 */
    if (v63 == v14) goto v4;
    v14 = v56;
    if (!consp(v14)) goto v38;
    v14 = v56;
    v63 = qcar(v14);
    v14 = elt(env, 3); /* zerop */
    v14 = get(v63, v14);
    v63 = v56;
        return Lapply1(nil, v14, v63);

v38:
    v14 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v14);

v4:
    v14 = qvalue(elt(env, 1)); /* t */
    return onevalue(v14);
}



/* Code for bcint2op */

static Lisp_Object MS_CDECL CC_bcint2op(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v77, v136, v110, v154;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bcint2op");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcint2op");
#endif
    if (stack >= stacklimit)
    {
        push3(v86,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v154 = v86;
    v136 = v1;
    v110 = v0;
/* end of prologue */
    v29 = qvalue(elt(env, 1)); /* dmode!* */
    if (!(v29 == nil)) goto v22;
    v77 = (Lisp_Object)17; /* 1 */
    v29 = v110;
    v29 = qcdr(v29);
    if (!(v77 == v29)) goto v22;
    v29 = v110;
    v29 = qcar(v29);
    v110 = v29;
    if (!(is_number(v29))) goto v22;
    v77 = (Lisp_Object)17; /* 1 */
    v29 = v136;
    v29 = qcdr(v29);
    if (!(v77 == v29)) goto v22;
    v29 = v136;
    v29 = qcar(v29);
    v136 = v29;
    if (!(is_number(v29))) goto v22;
    v77 = v154;
    v29 = elt(env, 2); /* times */
    if (v77 == v29) goto v45;
    v77 = v154;
    v29 = elt(env, 3); /* plus */
    if (v77 == v29) goto v100;
    v29 = v154;
    v77 = v110;
    v29 = Lapply2(nil, 3, v29, v77, v136);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[0];
    goto v44;

v44:
    v110 = v29;
    if (v29 == nil) goto v22;
    v77 = v110;
    v29 = (Lisp_Object)1; /* 0 */
    if (v77 == v29) goto v2;
    v29 = v110;
    v77 = v29;
    goto v81;

v81:
    v29 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v77, v29);

v2:
    v29 = qvalue(elt(env, 4)); /* nil */
    v77 = v29;
    goto v81;

v22:
    v29 = nil;
    { popv(1); return onevalue(v29); }

v100:
    v29 = v110;
    v77 = v136;
    v29 = plus2(v29, v77);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[0];
    goto v44;

v45:
    v29 = v110;
    v77 = v136;
    v29 = times2(v29, v77);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[0];
    goto v44;
/* error exit handlers */
v155:
    popv(1);
    return nil;
}



/* Code for multpfsq */

static Lisp_Object CC_multpfsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multpfsq");
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
    goto v37;

v37:
    v58 = stack[-2];
    if (v58 == nil) goto v53;
    v58 = stack[-1];
    v58 = qcar(v58);
    if (v58 == nil) goto v53;
    v58 = stack[-2];
    v58 = qcar(v58);
    stack[0] = qcar(v58);
    v58 = stack[-2];
    v58 = qcar(v58);
    v69 = qcdr(v58);
    v58 = stack[-1];
    fn = elt(env, 1); /* multsq */
    v69 = (*qfn2(fn))(qenv(fn), v69, v58);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v58 = stack[-3];
    v58 = acons(stack[0], v69, v58);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[-3] = v58;
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    goto v37;

v53:
    v58 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v58);
    }
/* error exit handlers */
v85:
    popv(5);
    return nil;
}



/* Code for prin2la */

static Lisp_Object CC_prin2la(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2la");
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
    v50 = stack[0];
    fn = elt(env, 4); /* chundexp */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    stack[0] = v50;
    v50 = stack[0];
    v50 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    stack[-1] = v50;
    v12 = qvalue(elt(env, 1)); /* ncharspr!* */
    v50 = stack[-1];
    v12 = plus2(v12, v50);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v50 = qvalue(elt(env, 2)); /* laline!* */
    v50 = (Lisp_Object)greaterp2(v12, v50);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v50 = v50 ? lisp_true : nil;
    env = stack[-2];
    if (v50 == nil) goto v55;
    v50 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v50 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v50; /* ncharspr!* */
    goto v55;

v55:
    v50 = stack[0];
    stack[0] = v50;
    goto v62;

v62:
    v50 = stack[0];
    if (v50 == nil) goto v98;
    v50 = stack[0];
    v50 = qcar(v50);
    v50 = Lprinc(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v50 = stack[0];
    v50 = qcdr(v50);
    stack[0] = v50;
    goto v62;

v98:
    v12 = qvalue(elt(env, 1)); /* ncharspr!* */
    v50 = stack[-1];
    v50 = plus2(v12, v50);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    qvalue(elt(env, 1)) = v50; /* ncharspr!* */
    v50 = nil;
    { popv(3); return onevalue(v50); }
/* error exit handlers */
v66:
    popv(3);
    return nil;
}



/* Code for collectindices */

static Lisp_Object CC_collectindices(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v57, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectindices");
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
    v57 = nil;
    v48 = stack[0];
    if (!(!consp(v48))) goto v37;
    v48 = stack[0];
    fn = elt(env, 2); /* isanindex */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    if (v48 == nil) goto v16;
    v48 = stack[0];
    popv(3);
    return ncons(v48);

v16:
    v48 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v48); }

v37:
    v48 = stack[0];
    v48 = qcar(v48);
    v58 = v48;
    v48 = stack[0];
    v48 = qcdr(v48);
    stack[0] = v48;
    stack[-1] = v57;
    v48 = v58;
    v48 = CC_collectindices(env, v48);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v48 = Lnconc(nil, stack[-1], v48);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v57 = v48;
    v48 = stack[0];
    if (v48 == nil) { popv(3); return onevalue(v57); }
    else goto v37;
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for union_edges */

static Lisp_Object CC_union_edges(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for union_edges");
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
    v19 = v0;
/* end of prologue */

v37:
    v24 = v19;
    if (v24 == nil) { popv(2); return onevalue(v18); }
    v24 = v19;
    v24 = qcdr(v24);
    stack[0] = v24;
    v19 = qcar(v19);
    fn = elt(env, 1); /* union_edge */
    v18 = (*qfn2(fn))(qenv(fn), v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    v19 = stack[0];
    goto v37;
/* error exit handlers */
v68:
    popv(2);
    return nil;
}



/* Code for aeval!* */

static Lisp_Object CC_aevalH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aeval*");
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
    stack[-1] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v35 = qvalue(elt(env, 2)); /* nil */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    qvalue(elt(env, 1)) = v35; /* alglist!* */
    v60 = stack[0];
    v35 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* reval1 */
    v35 = (*qfn2(fn))(qenv(fn), v60, v35);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    { popv(3); return onevalue(v35); }
/* error exit handlers */
v17:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    popv(3);
    return nil;
}



/* Code for mo_ecart */

static Lisp_Object CC_mo_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_ecart");
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
    v90 = stack[0];
    v90 = qcar(v90);
    if (v90 == nil) goto v4;
    v90 = stack[0];
    fn = elt(env, 3); /* mo_comp */
    v98 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v90 = qvalue(elt(env, 1)); /* cali!=degrees */
    v90 = Latsoc(nil, v98, v90);
    v98 = v90;
    v90 = v98;
    if (v90 == nil) goto v56;
    v90 = v98;
    v98 = qcdr(v90);
    v90 = stack[0];
    fn = elt(env, 4); /* mo_sum */
    v90 = (*qfn2(fn))(qenv(fn), v98, v90);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    goto v19;

v19:
    v90 = qcar(v90);
    stack[0] = qcdr(v90);
    v90 = qvalue(elt(env, 2)); /* cali!=basering */
    fn = elt(env, 5); /* ring_ecart */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    {
        Lisp_Object v25 = stack[0];
        popv(2);
        fn = elt(env, 6); /* mo!=sprod */
        return (*qfn2(fn))(qenv(fn), v25, v90);
    }

v56:
    v90 = stack[0];
    goto v19;

v4:
    v90 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v90); }
/* error exit handlers */
v64:
    popv(2);
    return nil;
}



/* Code for dless */

static Lisp_Object CC_dless(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v81, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dless");
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
    v156 = v1;
    stack[0] = v0;
/* end of prologue */
    v81 = qvalue(elt(env, 1)); /* ordering */
    v27 = elt(env, 2); /* lex */
    if (v81 == v27) goto v35;
    v27 = stack[0];
    v81 = qcar(v27);
    v27 = v156;
    v27 = qcar(v27);
    if (((int32_t)(v81)) < ((int32_t)(v27))) goto v23;
    v27 = stack[0];
    v81 = qcar(v27);
    v27 = v156;
    v27 = qcar(v27);
    if (((int32_t)(v81)) > ((int32_t)(v27))) goto v65;
    v81 = qvalue(elt(env, 1)); /* ordering */
    v27 = elt(env, 5); /* glex */
    if (v81 == v27) goto v50;
    v81 = qvalue(elt(env, 1)); /* ordering */
    v27 = elt(env, 6); /* grev */
    if (v81 == v27) goto v92;
    v27 = nil;
    { popv(3); return onevalue(v27); }

v92:
    v27 = v156;
    v27 = qcdr(v27);
    stack[-1] = Lreverse(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    v27 = stack[0];
    v27 = qcdr(v27);
    v27 = Lreverse(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    {
        Lisp_Object v2 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v2, v27);
    }

v50:
    v27 = stack[0];
    v27 = qcdr(v27);
    v81 = v156;
    v81 = qcdr(v81);
    {
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v27, v81);
    }

v65:
    v27 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v27); }

v23:
    v27 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v27); }

v35:
    v27 = stack[0];
    v81 = v156;
    {
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v27, v81);
    }
/* error exit handlers */
v148:
    popv(3);
    return nil;
}



/* Code for pv_multc */

static Lisp_Object CC_pv_multc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v99, v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_multc");
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
    v99 = stack[0];
    v8 = (Lisp_Object)1; /* 0 */
    if (v99 == v8) goto v36;
    v8 = stack[-1];
    if (v8 == nil) goto v36;
    v99 = stack[0];
    v8 = (Lisp_Object)17; /* 1 */
    if (v99 == v8) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v59;

v59:
    v8 = stack[-1];
    if (v8 == nil) goto v65;
    v8 = stack[-1];
    v8 = qcar(v8);
    v99 = qcar(v8);
    v8 = (Lisp_Object)1; /* 0 */
    if (v99 == v8) goto v57;
    v99 = stack[0];
    v8 = stack[-1];
    v8 = qcar(v8);
    v8 = qcar(v8);
    v150 = times2(v99, v8);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    v8 = stack[-1];
    v8 = qcar(v8);
    v99 = qcdr(v8);
    v8 = stack[-2];
    v8 = acons(v150, v99, v8);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-3];
    stack[-2] = v8;
    goto v57;

v57:
    v8 = stack[-1];
    v8 = qcdr(v8);
    stack[-1] = v8;
    goto v59;

v65:
    v8 = stack[-2];
        popv(4);
        return Lnreverse(nil, v8);

v36:
    v8 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v8); }
/* error exit handlers */
v156:
    popv(4);
    return nil;
}



/* Code for setkorder */

static Lisp_Object CC_setkorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v96, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setkorder");
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
    v70 = v0;
/* end of prologue */
    v23 = qvalue(elt(env, 1)); /* kord!* */
    stack[0] = v23;
    v96 = v70;
    v23 = stack[0];
    if (equal(v96, v23)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v23 = v70;
    qvalue(elt(env, 1)) = v23; /* kord!* */
    v23 = qvalue(elt(env, 2)); /* nil */
    v23 = ncons(v23);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    qvalue(elt(env, 3)) = v23; /* alglist!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for rank */

static Lisp_Object CC_rank(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rank");
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
    v29 = qvalue(elt(env, 1)); /* !*mcd */
    if (v29 == nil) goto v30;
    v29 = stack[-2];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v29 = qcdr(v29);
    { popv(5); return onevalue(v29); }

v30:
    v29 = stack[-2];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v29 = qcdr(v29);
    stack[-1] = v29;
    v29 = stack[-2];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v29 = qcar(v29);
    stack[0] = v29;
    goto v39;

v39:
    v29 = stack[-2];
    v29 = qcar(v29);
    v29 = qcar(v29);
    v29 = qcdr(v29);
    stack[-3] = v29;
    v29 = stack[-2];
    v29 = qcdr(v29);
    if (v29 == nil) goto v63;
    v29 = stack[-2];
    v29 = qcdr(v29);
    stack[-2] = v29;
    v77 = stack[-2];
    v29 = stack[0];
    fn = elt(env, 2); /* degr */
    v77 = (*qfn2(fn))(qenv(fn), v77, v29);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v29 = (Lisp_Object)1; /* 0 */
    if (!(v77 == v29)) goto v39;
    v77 = stack[-3];
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)lessp2(v77, v29);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v29 = v29 ? lisp_true : nil;
    env = stack[-4];
    if (v29 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v77 = stack[-1];
    v29 = (Lisp_Object)1; /* 0 */
    v29 = (Lisp_Object)lessp2(v77, v29);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v29 = v29 ? lisp_true : nil;
    if (v29 == nil) goto v135;
    v29 = stack[-3];
    popv(5);
    return negate(v29);

v135:
    v77 = stack[-1];
    v29 = stack[-3];
    popv(5);
    return difference2(v77, v29);

v63:
    v77 = stack[-1];
    v29 = stack[-3];
    popv(5);
    return difference2(v77, v29);
/* error exit handlers */
v138:
    popv(5);
    return nil;
}



/* Code for subs2q */

static Lisp_Object CC_subs2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v6, v5, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2q");
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
    v91 = stack[-2];
    v6 = qcar(v91);
    v91 = stack[-2];
    v91 = qcdr(v91);
    stack[-3] = v6;
    stack[-1] = v91;
    v91 = stack[-3];
    fn = elt(env, 1); /* subs2f */
    stack[0] = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v91 = stack[-1];
    fn = elt(env, 1); /* subs2f */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v95 = stack[0];
    v5 = v91;
    v91 = v95;
    v6 = qcdr(v91);
    v91 = (Lisp_Object)17; /* 1 */
    if (!(v6 == v91)) goto v84;
    v91 = v5;
    v6 = qcdr(v91);
    v91 = (Lisp_Object)17; /* 1 */
    if (!(v6 == v91)) goto v84;
    v91 = v95;
    v6 = qcar(v91);
    v91 = stack[-3];
    if (!(equal(v6, v91))) goto v84;
    v91 = v5;
    v6 = qcar(v91);
    v91 = stack[-1];
    if (equal(v6, v91)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    else goto v84;

v84:
    v91 = v95;
    v6 = v5;
    {
        popv(5);
        fn = elt(env, 2); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v91, v6);
    }
/* error exit handlers */
v7:
    popv(5);
    return nil;
}



/* Code for lto_setequalq */

static Lisp_Object CC_lto_setequalq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v83, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_setequalq");
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
    v82 = qvalue(elt(env, 1)); /* !*rlsetequalqhash */
    if (v82 == nil) goto v68;
    v83 = stack[-1];
    v82 = stack[0];
    fn = elt(env, 4); /* lto_hashequalq */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    goto v60;

v60:
    if (v82 == nil) goto v63;
    v82 = qvalue(elt(env, 3)); /* t */
    v140 = v82;
    goto v45;

v45:
    v82 = v140;
    if (v82 == nil) { popv(3); return onevalue(v140); }
    v82 = stack[-1];
    if (v82 == nil) { popv(3); return onevalue(v140); }
    v82 = stack[-1];
    v82 = qcar(v82);
    v83 = v82;
    v82 = stack[0];
    v82 = Lmemq(nil, v83, v82);
    if (v82 == nil) goto v7;
    v82 = stack[-1];
    v82 = qcdr(v82);
    stack[-1] = v82;
    goto v45;

v7:
    v82 = qvalue(elt(env, 2)); /* nil */
    v140 = v82;
    goto v45;

v63:
    v82 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v82); }

v68:
    v83 = stack[-1];
    v82 = stack[0];
    fn = elt(env, 5); /* lto_equallengthp */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    goto v60;
/* error exit handlers */
v8:
    popv(3);
    return nil;
}



/* Code for notstring */

static Lisp_Object CC_notstring(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v56, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for notstring");
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
    v63 = v0;
/* end of prologue */
    v56 = elt(env, 1); /* !  */
    fn = elt(env, 5); /* delall */
    v63 = (*qfn2(fn))(qenv(fn), v56, v63);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[0];
    v48 = v63;
    v63 = v48;
    v56 = qcar(v63);
    v63 = elt(env, 2); /* !" */
    if (v56 == v63) goto v15;
    v63 = v48;
    v63 = Lreverse(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[0];
    v56 = qcar(v63);
    v63 = elt(env, 2); /* !" */
    if (v56 == v63) goto v15;
    v63 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v63); }

v15:
    v63 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v63); }
/* error exit handlers */
v57:
    popv(1);
    return nil;
}



/* Code for evsum */

static Lisp_Object CC_evsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v78, v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evsum");
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
    v97 = nil;
    goto v54;

v54:
    v95 = stack[-1];
    if (v95 == nil) goto v22;
    v95 = stack[0];
    if (v95 == nil) goto v22;
    v95 = stack[-1];
    v78 = qcar(v95);
    v95 = stack[0];
    v95 = qcar(v95);
    v95 = (Lisp_Object)(int32_t)((int32_t)v78 + (int32_t)v95 - TAG_FIXNUM);
    v78 = v97;
    v95 = cons(v95, v78);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-2];
    v97 = v95;
    v95 = stack[-1];
    v95 = qcdr(v95);
    stack[-1] = v95;
    v95 = stack[0];
    v95 = qcdr(v95);
    stack[0] = v95;
    goto v54;

v22:
    v95 = v97;
    v95 = Lnreverse(nil, v95);
    v97 = v95;
    v95 = stack[-1];
    if (v95 == nil) goto v58;
    v78 = v97;
    v95 = stack[-1];
        popv(3);
        return Lnconc(nil, v78, v95);

v58:
    v95 = stack[0];
    if (v95 == nil) { popv(3); return onevalue(v97); }
    v78 = v97;
    v95 = stack[0];
        popv(3);
        return Lnconc(nil, v78, v95);
/* error exit handlers */
v7:
    popv(3);
    return nil;
}



/* Code for prepsqxx */

static Lisp_Object CC_prepsqxx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsqxx");
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
    v36 = v0;
/* end of prologue */
    fn = elt(env, 1); /* prepsqx */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* negnumberchk */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v37:
    popv(1);
    return nil;
}



/* Code for factorordp */

static Lisp_Object CC_factorordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v41, v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v1;
    v19 = v0;
/* end of prologue */
    v41 = v19;
    v40 = v18;
    if (v41 == v40) goto v36;
    v40 = v19;
    v41 = v18;
    {
        fn = elt(env, 2); /* worderp */
        return (*qfn2(fn))(qenv(fn), v40, v41);
    }

v36:
    v40 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v40);
}



/* Code for mkvar */

static Lisp_Object CC_mkvar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object v4, v36;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkvar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v1;
    v36 = v0;
/* end of prologue */
    return onevalue(v36);
}



/* Code for update!-pline */

static Lisp_Object MS_CDECL CC_updateKpline(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v167, v168;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "update-pline");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for update-pline");
#endif
    if (stack >= stacklimit)
    {
        push3(v86,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v168 = v86;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v167 = stack[-5];
    v166 = (Lisp_Object)1; /* 0 */
    if (!(v167 == v166)) goto v40;
    v167 = stack[-4];
    v166 = (Lisp_Object)1; /* 0 */
    if (v167 == v166) { popv(8); return onevalue(v168); }
    else goto v40;

v40:
    v166 = v168;
    stack[-6] = v166;
    v166 = stack[-6];
    if (v166 == nil) goto v44;
    v166 = stack[-6];
    v166 = qcar(v166);
    stack[0] = v166;
    v166 = stack[0];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = stack[-5];
    v168 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v166 = stack[0];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-5];
    v166 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v168 = cons(v168, v166);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    v166 = stack[0];
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-4];
    v167 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = acons(v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    stack[-2] = v166;
    stack[-3] = v166;
    goto v61;

v61:
    v166 = stack[-6];
    v166 = qcdr(v166);
    stack[-6] = v166;
    v166 = stack[-6];
    if (v166 == nil) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v166 = stack[-6];
    v166 = qcar(v166);
    stack[0] = v166;
    v166 = stack[0];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = stack[-5];
    v168 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v166 = stack[0];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-5];
    v166 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v168 = cons(v168, v166);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    v166 = stack[0];
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-4];
    v167 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = acons(v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    v166 = Lrplacd(nil, stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-7];
    v166 = stack[-2];
    v166 = qcdr(v166);
    stack[-2] = v166;
    goto v61;

v44:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v166); }
/* error exit handlers */
v108:
    popv(8);
    return nil;
}



/* Code for opmtch!* */

static Lisp_Object CC_opmtchH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtch*");
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
    v33 = v0;
/* end of prologue */
    v31 = qvalue(elt(env, 1)); /* subfg!* */
    stack[0] = v31;
    v31 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v31; /* subfg!* */
    v31 = v33;
    fn = elt(env, 3); /* opmtch */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    v33 = v31;
    v31 = stack[0];
    qvalue(elt(env, 1)) = v31; /* subfg!* */
    { popv(2); return onevalue(v33); }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for timesip */

static Lisp_Object CC_timesip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v18, v19;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for timesip");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    v18 = v19;
    v41 = elt(env, 1); /* times */
    if (!consp(v18)) goto v4;
    v18 = qcar(v18);
    if (!(v18 == v41)) goto v4;
    v41 = elt(env, 3); /* i */
    v18 = v19;
    v18 = qcdr(v18);
    v41 = Lmemq(nil, v41, v18);
    return onevalue(v41);

v4:
    v41 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v41);
}



/* Code for fs!:timestermterm */

static Lisp_Object CC_fsTtimestermterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v215, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:timestermterm");
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
    v214 = (Lisp_Object)113; /* 7 */
    v214 = Lmkvect(nil, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    stack[-8] = v214;
    v215 = stack[-7];
    v214 = (Lisp_Object)33; /* 2 */
    v214 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    stack[-4] = v214;
    v215 = stack[-6];
    v214 = (Lisp_Object)33; /* 2 */
    v214 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    stack[-3] = v214;
    v214 = (Lisp_Object)1; /* 0 */
    stack[-2] = v214;
    goto v63;

v63:
    v215 = (Lisp_Object)113; /* 7 */
    v214 = stack[-2];
    v214 = difference2(v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    v214 = Lminusp(nil, v214);
    env = stack[-9];
    if (v214 == nil) goto v90;
    v214 = (Lisp_Object)113; /* 7 */
    v214 = Lmkvect(nil, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    stack[-5] = v214;
    v214 = (Lisp_Object)1; /* 0 */
    stack[-2] = v214;
    goto v79;

v79:
    v215 = (Lisp_Object)113; /* 7 */
    v214 = stack[-2];
    v214 = difference2(v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    v214 = Lminusp(nil, v214);
    env = stack[-9];
    if (v214 == nil) goto v133;
    v215 = stack[-7];
    v214 = (Lisp_Object)1; /* 0 */
    v216 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    v215 = stack[-6];
    v214 = (Lisp_Object)1; /* 0 */
    v214 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    fn = elt(env, 5); /* multsq */
    v214 = (*qfn2(fn))(qenv(fn), v216, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    stack[0] = v214;
    v215 = stack[0];
    v214 = elt(env, 2); /* (1 . 2) */
    fn = elt(env, 5); /* multsq */
    v214 = (*qfn2(fn))(qenv(fn), v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    stack[0] = v214;
    v214 = stack[0];
    v214 = qcar(v214);
    if (v214 == nil) goto v218;
    v215 = stack[-7];
    v214 = (Lisp_Object)17; /* 1 */
    v215 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    v214 = elt(env, 3); /* sin */
    if (v215 == v214) goto v129;
    v215 = stack[-6];
    v214 = (Lisp_Object)17; /* 1 */
    v215 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    v214 = elt(env, 3); /* sin */
    if (v215 == v214) goto v219;
    v216 = elt(env, 4); /* cos */
    v215 = stack[-8];
    v214 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v216, v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    v216 = elt(env, 4); /* cos */
    v215 = stack[-5];
    v214 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v214 = (*qfnn(fn))(qenv(fn), 3, v216, v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    {
        Lisp_Object v220 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v220, v214);
    }

v219:
    v216 = elt(env, 3); /* sin */
    v215 = stack[-8];
    v214 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v216, v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    stack[-1] = elt(env, 3); /* sin */
    stack[-3] = stack[-5];
    v214 = stack[0];
    fn = elt(env, 8); /* negsq */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    fn = elt(env, 6); /* make!-term */
    v214 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-3], v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    {
        Lisp_Object v221 = stack[-2];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v221, v214);
    }

v129:
    v215 = stack[-6];
    v214 = (Lisp_Object)17; /* 1 */
    v215 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    v214 = elt(env, 3); /* sin */
    if (v215 == v214) goto v222;
    v216 = elt(env, 3); /* sin */
    v215 = stack[-8];
    v214 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v216, v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    v216 = elt(env, 3); /* sin */
    v215 = stack[-5];
    v214 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v214 = (*qfnn(fn))(qenv(fn), 3, v216, v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    {
        Lisp_Object v223 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v223, v214);
    }

v222:
    stack[-1] = elt(env, 4); /* cos */
    stack[-2] = stack[-8];
    v214 = stack[0];
    fn = elt(env, 8); /* negsq */
    v214 = (*qfn1(fn))(qenv(fn), v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-2], v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    v216 = elt(env, 4); /* cos */
    v215 = stack[-5];
    v214 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v214 = (*qfnn(fn))(qenv(fn), 3, v216, v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    {
        Lisp_Object v224 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v224, v214);
    }

v218:
    v214 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v214); }

v133:
    stack[-1] = stack[-5];
    stack[0] = stack[-2];
    v215 = stack[-4];
    v214 = stack[-2];
    v216 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    v215 = stack[-3];
    v214 = stack[-2];
    v214 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    v214 = difference2(v216, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v214;
    v214 = stack[-2];
    v214 = add1(v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    stack[-2] = v214;
    goto v79;

v90:
    stack[-1] = stack[-8];
    stack[0] = stack[-2];
    v215 = stack[-4];
    v214 = stack[-2];
    v216 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    v215 = stack[-3];
    v214 = stack[-2];
    v214 = *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL)));
    v214 = plus2(v216, v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v214;
    v214 = stack[-2];
    v214 = add1(v214);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-9];
    stack[-2] = v214;
    goto v63;
/* error exit handlers */
v217:
    popv(10);
    return nil;
}



/* Code for mo!=sum */

static Lisp_Object CC_moMsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v12, v84;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=sum");
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
    v84 = nil;
    goto v54;

v54:
    v50 = stack[-1];
    if (v50 == nil) goto v63;
    v50 = stack[0];
    if (v50 == nil) goto v63;
    v50 = stack[-1];
    v12 = qcar(v50);
    v50 = stack[0];
    v50 = qcar(v50);
    v50 = (Lisp_Object)(int32_t)((int32_t)v12 + (int32_t)v50 - TAG_FIXNUM);
    v12 = v84;
    v50 = cons(v50, v12);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-2];
    v84 = v50;
    v50 = stack[-1];
    v50 = qcdr(v50);
    stack[-1] = v50;
    v50 = stack[0];
    v50 = qcdr(v50);
    stack[0] = v50;
    goto v54;

v63:
    v50 = v84;
    v12 = Lnreverse(nil, v50);
    v50 = stack[-1];
    if (v50 == nil) goto v101;
    v50 = stack[-1];
    goto v57;

v57:
        popv(3);
        return Lappend(nil, v12, v50);

v101:
    v50 = stack[0];
    goto v57;
/* error exit handlers */
v67:
    popv(3);
    return nil;
}



/* Code for pcmult */

static Lisp_Object CC_pcmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pcmult");
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
    v92 = v0;
/* end of prologue */
    stack[-5] = v92;
    v92 = stack[-5];
    if (v92 == nil) goto v31;
    v92 = stack[-5];
    v92 = qcar(v92);
    v93 = v92;
    stack[0] = qcar(v93);
    v93 = stack[-4];
    v92 = qcdr(v92);
    fn = elt(env, 2); /* cprod */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v92 = cons(stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    stack[-2] = v92;
    stack[-3] = v92;
    goto v54;

v54:
    v92 = stack[-5];
    v92 = qcdr(v92);
    stack[-5] = v92;
    v92 = stack[-5];
    if (v92 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v92 = stack[-5];
    v92 = qcar(v92);
    v93 = v92;
    stack[0] = qcar(v93);
    v93 = stack[-4];
    v92 = qcdr(v92);
    fn = elt(env, 2); /* cprod */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v92 = cons(stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v92 = Lrplacd(nil, stack[-1], v92);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v92 = stack[-2];
    v92 = qcdr(v92);
    stack[-2] = v92;
    goto v54;

v31:
    v92 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v92); }
/* error exit handlers */
v99:
    popv(7);
    return nil;
}



/* Code for pkp */

static Lisp_Object CC_pkp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v165, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pkp");
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
    stack[-3] = nil;
    v164 = stack[0];
    if (!consp(v164)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v164 = qvalue(elt(env, 1)); /* !*ppacked */
    if (v164 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v164 = stack[0];
    v165 = Llength(nil, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v164 = (Lisp_Object)161; /* 10 */
    v164 = (Lisp_Object)geq2(v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    v164 = v164 ? lisp_true : nil;
    env = stack[-4];
    stack[-2] = v164;
    v164 = stack[0];
    stack[-1] = v164;
    goto v19;

v19:
    v164 = stack[-1];
    if (v164 == nil) goto v18;
    v164 = stack[-1];
    v164 = qcar(v164);
    stack[0] = v164;
    v164 = stack[-2];
    if (v164 == nil) goto v213;
    v165 = stack[0];
    v164 = (Lisp_Object)161; /* 10 */
    v164 = (Lisp_Object)lessp2(v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    v164 = v164 ? lisp_true : nil;
    env = stack[-4];
    if (v164 == nil) goto v83;
    v165 = stack[0];
    v164 = qvalue(elt(env, 3)); /* diglist!* */
    fn = elt(env, 5); /* dssoc */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v163 = qcar(v164);
    v165 = elt(env, 4); /* !0 */
    v164 = stack[-3];
    v164 = list2star(v163, v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    stack[-3] = v164;
    goto v63;

v63:
    v164 = stack[-1];
    v164 = qcdr(v164);
    stack[-1] = v164;
    goto v19;

v83:
    v165 = stack[0];
    v164 = (Lisp_Object)161; /* 10 */
    v164 = Ldivide(nil, v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    stack[0] = v164;
    v164 = stack[0];
    v165 = qcar(v164);
    v164 = qvalue(elt(env, 3)); /* diglist!* */
    fn = elt(env, 5); /* dssoc */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v165 = qcar(v164);
    v164 = stack[-3];
    v164 = cons(v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    stack[-3] = v164;
    v164 = stack[0];
    v165 = qcdr(v164);
    v164 = qvalue(elt(env, 3)); /* diglist!* */
    fn = elt(env, 5); /* dssoc */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v165 = qcar(v164);
    v164 = stack[-3];
    v164 = cons(v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    stack[-3] = v164;
    goto v63;

v213:
    v165 = stack[0];
    v164 = qvalue(elt(env, 3)); /* diglist!* */
    fn = elt(env, 5); /* dssoc */
    v164 = (*qfn2(fn))(qenv(fn), v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    v165 = qcar(v164);
    v164 = stack[-3];
    v164 = cons(v165, v164);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-4];
    stack[-3] = v164;
    goto v63;

v18:
    v164 = stack[-3];
    v164 = Lnreverse(nil, v164);
        popv(5);
        return Lcompress(nil, v164);
/* error exit handlers */
v112:
    popv(5);
    return nil;
}



/* Code for rnonep!: */

static Lisp_Object CC_rnonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v24, v43;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnonep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v0;
/* end of prologue */
    v19 = v43;
    v19 = qcdr(v19);
    v24 = qcar(v19);
    v19 = (Lisp_Object)17; /* 1 */
    if (v24 == v19) goto v39;
    v19 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v19);

v39:
    v19 = v43;
    v19 = qcdr(v19);
    v24 = qcdr(v19);
    v19 = (Lisp_Object)17; /* 1 */
    v19 = (v24 == v19 ? lisp_true : nil);
    return onevalue(v19);
}



/* Code for !*d2n */

static Lisp_Object CC_Hd2n(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *d2n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v31 = v30;
    if (!(v31 == nil)) return onevalue(v30);
    v30 = (Lisp_Object)1; /* 0 */
    return onevalue(v30);
}



/* Code for kernels1 */

static Lisp_Object CC_kernels1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v51, v52, v100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernels1");
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
    v52 = v1;
    v67 = v0;
/* end of prologue */

v42:
    v51 = v67;
    if (!consp(v51)) { popv(4); return onevalue(v52); }
    v51 = v67;
    v51 = qcar(v51);
    if (!consp(v51)) { popv(4); return onevalue(v52); }
    v51 = v67;
    v51 = qcar(v51);
    v51 = qcar(v51);
    v51 = qcar(v51);
    v100 = v51;
    v51 = v67;
    v51 = qcar(v51);
    stack[-2] = qcdr(v51);
    stack[-1] = qcdr(v67);
    v51 = v100;
    v67 = v52;
    v67 = Lmemq(nil, v51, v67);
    if (v67 == nil) goto v101;
    v67 = v52;
    goto v62;

v62:
    v51 = CC_kernels1(env, stack[-1], v67);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v67 = stack[-2];
    v52 = v51;
    goto v42;

v101:
    stack[0] = v52;
    v67 = v100;
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    v67 = Lappend(nil, stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    goto v62;
/* error exit handlers */
v95:
    popv(4);
    return nil;
}



/* Code for lt!* */

static Lisp_Object CC_ltH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v102, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lt*");
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
    v97 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v97 == nil)) goto v4;
    v97 = stack[-1];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v102 = qcdr(v97);
    v97 = (Lisp_Object)1; /* 0 */
    v97 = (Lisp_Object)greaterp2(v102, v97);
    nil = C_nil;
    if (exception_pending()) goto v93;
    v97 = v97 ? lisp_true : nil;
    env = stack[-3];
    if (!(v97 == nil)) goto v4;
    v97 = stack[-1];
    v97 = qcar(v97);
    stack[-2] = v97;
    v97 = stack[-1];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = qcar(v97);
    stack[0] = v97;
    goto v19;

v19:
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-1] = v97;
    v97 = stack[-1];
    if (v97 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v102 = stack[-1];
    v97 = stack[0];
    fn = elt(env, 2); /* degr */
    v102 = (*qfn2(fn))(qenv(fn), v102, v97);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    v97 = (Lisp_Object)1; /* 0 */
    if (!(v102 == v97)) goto v19;
    v137 = stack[0];
    v102 = (Lisp_Object)1; /* 0 */
    v97 = stack[-1];
    popv(4);
    return acons(v137, v102, v97);

v4:
    v97 = stack[-1];
    v97 = qcar(v97);
    { popv(4); return onevalue(v97); }
/* error exit handlers */
v93:
    popv(4);
    return nil;
}



/* Code for tayexp!-greaterp */

static Lisp_Object CC_tayexpKgreaterp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-greaterp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v1;
    v30 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* tayexp!-lessp */
        return (*qfn2(fn))(qenv(fn), v31, v30);
    }
}



/* Code for printout */

static Lisp_Object CC_printout(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for printout");
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
    v93 = qvalue(elt(env, 1)); /* !*web */
    if (!(v93 == nil)) goto v36;
    v93 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    goto v36;

v36:
    v93 = qvalue(elt(env, 1)); /* !*web */
    if (!(v93 == nil)) goto v30;
    v93 = (Lisp_Object)17; /* 1 */
    stack[-1] = v93;
    goto v41;

v41:
    v82 = qvalue(elt(env, 2)); /* indent */
    v93 = stack[-1];
    v93 = difference2(v82, v93);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v93 = Lminusp(nil, v93);
    env = stack[-2];
    if (!(v93 == nil)) goto v30;
    v93 = elt(env, 4); /* " " */
    v93 = Lprinc(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v93 = stack[-1];
    v93 = add1(v93);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    stack[-1] = v93;
    goto v41;

v30:
    v93 = stack[0];
    v93 = Lconsp(nil, v93);
    env = stack[-2];
    if (v93 == nil) goto v137;
    v93 = stack[0];
    v82 = qcar(v93);
    v93 = elt(env, 5); /* !:rd!: */
    if (v82 == v93) goto v49;
    v93 = stack[0];
    v82 = qcar(v93);
    v93 = elt(env, 6); /* !:rn!: */
    if (v82 == v93) goto v49;
    v93 = stack[0];
    v93 = Lprinc(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v9;
    goto v14;

v14:
    v93 = nil;
    { popv(3); return onevalue(v93); }

v49:
    v93 = stack[0];
    fn = elt(env, 7); /* ma_print */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v9;
    goto v14;

v137:
    v93 = stack[0];
    v93 = Lprinc(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v9;
    goto v14;
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for evcompless!? */

static Lisp_Object CC_evcomplessW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evcompless?");
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
    v17 = v1;
    v39 = v0;
/* end of prologue */
    stack[0] = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* evcomp */
    v39 = (*qfn2(fn))(qenv(fn), v17, v39);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v39 = (stack[0] == v39 ? lisp_true : nil);
    { popv(1); return onevalue(v39); }
/* error exit handlers */
v34:
    popv(1);
    return nil;
}



/* Code for peel */

static Lisp_Object CC_peel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for peel");
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
    v66 = stack[0];
    v67 = qcar(v66);
    v66 = elt(env, 1); /* (liedf innerprod) */
    v66 = Lmemq(nil, v67, v66);
    if (v66 == nil) goto v34;
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcar(v66);
    { popv(1); return onevalue(v66); }

v34:
    v66 = stack[0];
    v67 = qcar(v66);
    v66 = elt(env, 2); /* quotient */
    if (v67 == v66) goto v65;
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcar(v66);
    { popv(1); return onevalue(v66); }

v65:
    v66 = stack[0];
    v66 = qcdr(v66);
    v67 = qcar(v66);
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcar(v66);
    fn = elt(env, 3); /* worderp */
    v66 = (*qfn2(fn))(qenv(fn), v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v52;
    if (v66 == nil) goto v98;
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcar(v66);
    { popv(1); return onevalue(v66); }

v98:
    v66 = stack[0];
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = qcar(v66);
    { popv(1); return onevalue(v66); }
/* error exit handlers */
v52:
    popv(1);
    return nil;
}



/* Code for i2rd!* */

static Lisp_Object CC_i2rdH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2rd*");
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
    v36 = v0;
/* end of prologue */
    fn = elt(env, 1); /* chkint!* */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mkround */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v37:
    popv(1);
    return nil;
}



/* Code for fprin2 */

static Lisp_Object CC_fprin2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fprin2");
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
    v60 = v0;
/* end of prologue */
    v35 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*lower */
    qvalue(elt(env, 2)) = v35; /* !*lower */
    v35 = qvalue(elt(env, 3)); /* !*fortupper */
    if (v35 == nil) goto v30;
    v35 = v60;
    fn = elt(env, 4); /* prin2!-upcase */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    goto v36;

v36:
    qvalue(elt(env, 2)) = stack[0]; /* !*lower */
    { popv(2); return onevalue(v35); }

v30:
    v35 = v60;
    fn = elt(env, 5); /* prin2!-downcase */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    goto v36;
/* error exit handlers */
v39:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*lower */
    popv(2);
    return nil;
}



/* Code for listsum */

static Lisp_Object CC_listsum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v58;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listsum");
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
    goto v37;

v37:
    v57 = stack[0];
    if (v57 == nil) goto v22;
    v57 = stack[0];
    v58 = qcar(v57);
    v57 = stack[-1];
    v57 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    stack[-1] = v57;
    v57 = stack[0];
    v57 = qcdr(v57);
    stack[0] = v57;
    goto v37;

v22:
    v57 = (Lisp_Object)1; /* 0 */
    v58 = v57;
    goto v54;

v54:
    v57 = stack[-1];
    if (v57 == nil) { popv(3); return onevalue(v58); }
    v57 = stack[-1];
    v57 = qcar(v57);
    v57 = plus2(v57, v58);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v58 = v57;
    v57 = stack[-1];
    v57 = qcdr(v57);
    stack[-1] = v57;
    goto v54;
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for fs!:angle!-order */

static Lisp_Object CC_fsTangleKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v228, v213;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:angle-order");
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
    v116 = (Lisp_Object)1; /* 0 */
    stack[-4] = v116;
    v228 = stack[-3];
    v116 = (Lisp_Object)33; /* 2 */
    v116 = *(Lisp_Object *)((char *)v228 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    stack[-1] = v116;
    v228 = stack[-2];
    v116 = (Lisp_Object)33; /* 2 */
    v116 = *(Lisp_Object *)((char *)v228 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    stack[0] = v116;
    goto v62;

v62:
    v228 = stack[-1];
    v116 = stack[-4];
    v213 = *(Lisp_Object *)((char *)v228 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    v228 = stack[0];
    v116 = stack[-4];
    v116 = *(Lisp_Object *)((char *)v228 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    v116 = difference2(v213, v116);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    v213 = v116;
    v228 = v213;
    v116 = (Lisp_Object)1; /* 0 */
    if (v228 == v116) goto v85;
    v228 = v213;
    v116 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v228, v116);

v85:
    v116 = stack[-4];
    v116 = add1(v116);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-5];
    stack[-4] = v116;
    v228 = stack[-4];
    v116 = (Lisp_Object)129; /* 8 */
    v116 = (Lisp_Object)lessp2(v228, v116);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v116 = v116 ? lisp_true : nil;
    env = stack[-5];
    if (!(v116 == nil)) goto v62;
    v228 = stack[-3];
    v116 = (Lisp_Object)17; /* 1 */
    v213 = *(Lisp_Object *)((char *)v228 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    v228 = stack[-2];
    v116 = (Lisp_Object)17; /* 1 */
    v116 = *(Lisp_Object *)((char *)v228 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    if (equal(v213, v116)) goto v150;
    v228 = stack[-3];
    v116 = (Lisp_Object)17; /* 1 */
    v228 = *(Lisp_Object *)((char *)v228 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    v116 = elt(env, 2); /* sin */
    if (v228 == v116) goto v136;
    v116 = qvalue(elt(env, 3)); /* t */
    { popv(6); return onevalue(v116); }

v136:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v116); }

v150:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v116); }
/* error exit handlers */
v117:
    popv(6);
    return nil;
}



/* Code for mo!=degcomp */

static Lisp_Object CC_moMdegcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v57, v58, v69;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=degcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v1;
    v58 = v0;
/* end of prologue */

v36:
    v48 = v58;
    if (v48 == nil) goto v54;
    v48 = v58;
    v69 = qcar(v48);
    v48 = v57;
    v48 = qcar(v48);
    if (equal(v69, v48)) goto v31;
    v48 = v58;
    v48 = qcar(v48);
    v57 = qcar(v57);
    if (((int32_t)(v48)) < ((int32_t)(v57))) goto v18;
    v48 = (Lisp_Object)17; /* 1 */
    return onevalue(v48);

v18:
    v48 = (Lisp_Object)-15; /* -1 */
    return onevalue(v48);

v31:
    v48 = v58;
    v48 = qcdr(v48);
    v58 = v48;
    v48 = v57;
    v48 = qcdr(v48);
    v57 = v48;
    goto v36;

v54:
    v48 = (Lisp_Object)1; /* 0 */
    return onevalue(v48);
}



setup_type const u02_setup[] =
{
    {"c:ordexn",                too_few_2,      CC_cTordexn,   wrong_no_2},
    {"nil2zero",                CC_nil2zero,    too_many_1,    wrong_no_1},
    {"bczero?",                 CC_bczeroW,     too_many_1,    wrong_no_1},
    {"xsimp",                   CC_xsimp,       too_many_1,    wrong_no_1},
    {"evzero?",                 CC_evzeroW,     too_many_1,    wrong_no_1},
    {"wedgepf2",                too_few_2,      CC_wedgepf2,   wrong_no_2},
    {"makelist",                CC_makelist,    too_many_1,    wrong_no_1},
    {"*physopp",                CC_Hphysopp,    too_many_1,    wrong_no_1},
    {"*ssave",                  too_few_2,      CC_Hssave,     wrong_no_2},
    {"addd",                    too_few_2,      CC_addd,       wrong_no_2},
    {"mo_vdivides?",            too_few_2,      CC_mo_vdividesW,wrong_no_2},
    {"pappl0",                  too_few_2,      CC_pappl0,     wrong_no_2},
    {"*i2mod",                  CC_Hi2mod,      too_many_1,    wrong_no_1},
    {"general-modular-times",   too_few_2,      CC_generalKmodularKtimes,wrong_no_2},
    {"getpower",                too_few_2,      CC_getpower,   wrong_no_2},
    {"cl_atfp",                 CC_cl_atfp,     too_many_1,    wrong_no_1},
    {"minusf",                  CC_minusf,      too_many_1,    wrong_no_1},
    {"sfp",                     CC_sfp,         too_many_1,    wrong_no_1},
    {"subs2f",                  CC_subs2f,      too_many_1,    wrong_no_1},
    {"retimes",                 CC_retimes,     too_many_1,    wrong_no_1},
    {"sinitl",                  CC_sinitl,      too_many_1,    wrong_no_1},
    {"aeval",                   CC_aeval,       too_many_1,    wrong_no_1},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"mval",                    CC_mval,        too_many_1,    wrong_no_1},
    {"evmatrixcomp1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp1},
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"getrtypeor",              CC_getrtypeor,  too_many_1,    wrong_no_1},
    {"adddm",                   too_few_2,      CC_adddm,      wrong_no_2},
    {"angles-equal",            too_few_2,      CC_anglesKequal,wrong_no_2},
    {"mo=sprod",                too_few_2,      CC_moMsprod,   wrong_no_2},
    {"sieve_pv",                too_few_2,      CC_sieve_pv,   wrong_no_2},
    {"upbve",                   CC_upbve,       too_many_1,    wrong_no_1},
    {"modtimes:",               too_few_2,      CC_modtimesT,  wrong_no_2},
    {"general-modular-plus",    too_few_2,      CC_generalKmodularKplus,wrong_no_2},
    {"remainder-in-vector",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_remainderKinKvector},
    {"powers0",                 too_few_2,      CC_powers0,    wrong_no_2},
    {"comfac-to-poly",          CC_comfacKtoKpoly,too_many_1,  wrong_no_1},
    {"tayexp-plus2",            too_few_2,      CC_tayexpKplus2,wrong_no_2},
    {"multsq",                  too_few_2,      CC_multsq,     wrong_no_2},
    {"ibalp_getnewwl",          CC_ibalp_getnewwl,too_many_1,  wrong_no_1},
    {"attributes",              too_few_2,      CC_attributes, wrong_no_2},
    {":zerop",                  CC_Tzerop,      too_many_1,    wrong_no_1},
    {"bcint2op",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_bcint2op},
    {"multpfsq",                too_few_2,      CC_multpfsq,   wrong_no_2},
    {"prin2la",                 CC_prin2la,     too_many_1,    wrong_no_1},
    {"collectindices",          CC_collectindices,too_many_1,  wrong_no_1},
    {"union_edges",             too_few_2,      CC_union_edges,wrong_no_2},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"mo_ecart",                CC_mo_ecart,    too_many_1,    wrong_no_1},
    {"dless",                   too_few_2,      CC_dless,      wrong_no_2},
    {"pv_multc",                too_few_2,      CC_pv_multc,   wrong_no_2},
    {"setkorder",               CC_setkorder,   too_many_1,    wrong_no_1},
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"subs2q",                  CC_subs2q,      too_many_1,    wrong_no_1},
    {"lto_setequalq",           too_few_2,      CC_lto_setequalq,wrong_no_2},
    {"notstring",               CC_notstring,   too_many_1,    wrong_no_1},
    {"evsum",                   too_few_2,      CC_evsum,      wrong_no_2},
    {"prepsqxx",                CC_prepsqxx,    too_many_1,    wrong_no_1},
    {"factorordp",              too_few_2,      CC_factorordp, wrong_no_2},
    {"mkvar",                   too_few_2,      CC_mkvar,      wrong_no_2},
    {"update-pline",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_updateKpline},
    {"opmtch*",                 CC_opmtchH,     too_many_1,    wrong_no_1},
    {"timesip",                 CC_timesip,     too_many_1,    wrong_no_1},
    {"fs:timestermterm",        too_few_2,      CC_fsTtimestermterm,wrong_no_2},
    {"mo=sum",                  too_few_2,      CC_moMsum,     wrong_no_2},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"pkp",                     CC_pkp,         too_many_1,    wrong_no_1},
    {"rnonep:",                 CC_rnonepT,     too_many_1,    wrong_no_1},
    {"*d2n",                    CC_Hd2n,        too_many_1,    wrong_no_1},
    {"kernels1",                too_few_2,      CC_kernels1,   wrong_no_2},
    {"lt*",                     CC_ltH,         too_many_1,    wrong_no_1},
    {"tayexp-greaterp",         too_few_2,      CC_tayexpKgreaterp,wrong_no_2},
    {"printout",                CC_printout,    too_many_1,    wrong_no_1},
    {"evcompless?",             too_few_2,      CC_evcomplessW,wrong_no_2},
    {"peel",                    CC_peel,        too_many_1,    wrong_no_1},
    {"i2rd*",                   CC_i2rdH,       too_many_1,    wrong_no_1},
    {"fprin2",                  CC_fprin2,      too_many_1,    wrong_no_1},
    {"listsum",                 CC_listsum,     too_many_1,    wrong_no_1},
    {"fs:angle-order",          too_few_2,      CC_fsTangleKorder,wrong_no_2},
    {"mo=degcomp",              too_few_2,      CC_moMdegcomp, wrong_no_2},
    {NULL, (one_args *)"u02", (two_args *)"21026 4167654 407925", 0}
};

/* end of generated code */
