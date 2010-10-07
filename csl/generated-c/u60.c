
/* $destdir\u60.c        Machine generated C code */

/* Signature: 00000000 07-Oct-2010 */

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
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
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
extern int force_reclaim_method;
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
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
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


/* Code for multsm */

static Lisp_Object CC_multsm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsm");
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
    stack[0] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-1] = stack[-7];
    v36 = (Lisp_Object)17; /* 1 */
    v35 = (Lisp_Object)17; /* 1 */
    v35 = cons(v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    if (equal(stack[-1], v35)) { Lisp_Object res = stack[0]; popv(10); return onevalue(res); }
    v35 = stack[0];
    stack[-8] = v35;
    v35 = stack[-8];
    if (v35 == nil) goto v38;
    v35 = stack[-8];
    v35 = qcar(v35);
    stack[-3] = v35;
    v35 = stack[-3];
    if (v35 == nil) goto v39;
    v35 = stack[-3];
    v35 = qcar(v35);
    v36 = stack[-7];
    fn = elt(env, 2); /* multsq */
    v35 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    stack[-1] = v35;
    stack[-2] = v35;
    goto v40;

v40:
    v35 = stack[-3];
    v35 = qcdr(v35);
    stack[-3] = v35;
    v35 = stack[-3];
    if (v35 == nil) goto v41;
    stack[0] = stack[-1];
    v35 = stack[-3];
    v35 = qcar(v35);
    v36 = stack[-7];
    fn = elt(env, 2); /* multsq */
    v35 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = Lrplacd(nil, stack[0], v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = stack[-1];
    v35 = qcdr(v35);
    stack[-1] = v35;
    goto v40;

v41:
    v35 = stack[-2];
    goto v42;

v42:
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    stack[-5] = v35;
    stack[-6] = v35;
    goto v43;

v43:
    v35 = stack[-8];
    v35 = qcdr(v35);
    stack[-8] = v35;
    v35 = stack[-8];
    if (v35 == nil) { Lisp_Object res = stack[-6]; popv(10); return onevalue(res); }
    stack[-4] = stack[-5];
    v35 = stack[-8];
    v35 = qcar(v35);
    stack[-3] = v35;
    v35 = stack[-3];
    if (v35 == nil) goto v44;
    v35 = stack[-3];
    v35 = qcar(v35);
    v36 = stack[-7];
    fn = elt(env, 2); /* multsq */
    v35 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    stack[-1] = v35;
    stack[-2] = v35;
    goto v45;

v45:
    v35 = stack[-3];
    v35 = qcdr(v35);
    stack[-3] = v35;
    v35 = stack[-3];
    if (v35 == nil) goto v46;
    stack[0] = stack[-1];
    v35 = stack[-3];
    v35 = qcar(v35);
    v36 = stack[-7];
    fn = elt(env, 2); /* multsq */
    v35 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = Lrplacd(nil, stack[0], v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = stack[-1];
    v35 = qcdr(v35);
    stack[-1] = v35;
    goto v45;

v46:
    v35 = stack[-2];
    goto v47;

v47:
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = Lrplacd(nil, stack[-4], v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-9];
    v35 = stack[-5];
    v35 = qcdr(v35);
    stack[-5] = v35;
    goto v43;

v44:
    v35 = qvalue(elt(env, 1)); /* nil */
    goto v47;

v39:
    v35 = qvalue(elt(env, 1)); /* nil */
    goto v42;

v38:
    v35 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v35); }
/* error exit handlers */
v37:
    popv(10);
    return nil;
}



/* Code for binomial */

static Lisp_Object CC_binomial(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v82;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binomial");
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

v83:
    v82 = stack[-2];
    v81 = (Lisp_Object)1; /* 0 */
    if (v82 == v81) goto v84;
    stack[0] = stack[-3];
    v82 = (Lisp_Object)33; /* 2 */
    v81 = stack[-2];
    v81 = times2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = (Lisp_Object)lessp2(stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v81 = v81 ? lisp_true : nil;
    env = stack[-5];
    if (v81 == nil) goto v34;
    stack[0] = stack[-3];
    v82 = stack[-3];
    v81 = stack[-2];
    v81 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-3] = stack[0];
    stack[-2] = v81;
    goto v83;

v34:
    v81 = stack[-3];
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-4] = v81;
    v82 = qvalue(elt(env, 1)); /* !_binomialn */
    v81 = stack[-3];
    if (equal(v82, v81)) goto v30;
    v81 = (Lisp_Object)17; /* 1 */
    stack[-1] = v81;
    v81 = (Lisp_Object)17; /* 1 */
    stack[0] = v81;
    goto v86;

v86:
    v82 = stack[-2];
    v81 = stack[0];
    v81 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = Lminusp(nil, v81);
    env = stack[-5];
    if (v81 == nil) goto v87;
    v81 = stack[-3];
    qvalue(elt(env, 1)) = v81; /* !_binomialn */
    goto v88;

v88:
    v81 = stack[-2];
    qvalue(elt(env, 3)) = v81; /* !_binomialk */
    v81 = stack[-1];
    qvalue(elt(env, 2)) = v81; /* !_binomialb */
    { popv(6); return onevalue(v81); }

v87:
    v82 = stack[-4];
    v81 = stack[0];
    v82 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = stack[-1];
    v82 = times2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = stack[0];
    v81 = quot2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-1] = v81;
    v81 = stack[0];
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[0] = v81;
    goto v86;

v30:
    v81 = qvalue(elt(env, 2)); /* !_binomialb */
    stack[-1] = v81;
    v82 = qvalue(elt(env, 3)); /* !_binomialk */
    v81 = stack[-2];
    v81 = (Lisp_Object)lesseq2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v81 = v81 ? lisp_true : nil;
    env = stack[-5];
    if (v81 == nil) goto v44;
    v81 = qvalue(elt(env, 3)); /* !_binomialk */
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[0] = v81;
    goto v22;

v22:
    v82 = stack[-2];
    v81 = stack[0];
    v81 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = Lminusp(nil, v81);
    env = stack[-5];
    if (!(v81 == nil)) goto v88;
    v82 = stack[-4];
    v81 = stack[0];
    v82 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = stack[-1];
    v82 = times2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = stack[0];
    v81 = quot2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-1] = v81;
    v81 = stack[0];
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[0] = v81;
    goto v22;

v44:
    v81 = qvalue(elt(env, 3)); /* !_binomialk */
    stack[-3] = v81;
    goto v89;

v89:
    stack[0] = stack[-3];
    v81 = stack[-2];
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = difference2(stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = Lminusp(nil, v81);
    env = stack[-5];
    if (!(v81 == nil)) goto v88;
    v82 = stack[-3];
    v81 = stack[-1];
    stack[0] = times2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v82 = stack[-4];
    v81 = stack[-3];
    v81 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    v81 = quot2(stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-1] = v81;
    v81 = stack[-3];
    v81 = sub1(v81);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-5];
    stack[-3] = v81;
    goto v89;

v84:
    v81 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v81); }
/* error exit handlers */
v85:
    popv(6);
    return nil;
}



/* Code for redexpp */

static Lisp_Object CC_redexpp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v93, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redexpp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v94 = v0;
/* end of prologue */
    v78 = v94;
    v78 = (consp(v78) ? nil : lisp_true);
    if (!(v78 == nil)) return onevalue(v78);
    v78 = v94;
    v93 = qcar(v78);
    v78 = qvalue(elt(env, 1)); /* !*redarithexpops!* */
    v78 = Lmemq(nil, v93, v78);
    if (!(v78 == nil)) return onevalue(v78);
    v78 = v94;
    v93 = qcar(v78);
    v78 = qvalue(elt(env, 2)); /* !*redlogexpops!* */
    v78 = Lmemq(nil, v93, v78);
    if (!(v78 == nil)) return onevalue(v78);
    v78 = v94;
    v78 = qcar(v78);
    v93 = qvalue(elt(env, 3)); /* !*redreswds!* */
    v78 = Lmemq(nil, v78, v93);
    v78 = (v78 == nil ? lisp_true : nil);
    return onevalue(v78);
}



/* Code for polyp */

static Lisp_Object CC_polyp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polyp");
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
    v132 = stack[-5];
    v131 = stack[-4];
    fn = elt(env, 10); /* my_freeof */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    if (v131 == nil) goto v79;
    v131 = qvalue(elt(env, 1)); /* t */
    { popv(8); return onevalue(v131); }

v79:
    stack[-6] = nil;
    v131 = stack[-5];
    if (!consp(v131)) goto v135;
    v131 = stack[-5];
    stack[-3] = qcar(v131);
    stack[-2] = elt(env, 2); /* expt */
    stack[-1] = elt(env, 3); /* plus */
    stack[0] = elt(env, 4); /* minus */
    v133 = elt(env, 5); /* times */
    v132 = elt(env, 6); /* quotient */
    v131 = elt(env, 7); /* df */
    v131 = list3(v133, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v131 = list3star(stack[-2], stack[-1], stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    v131 = Lmember(nil, stack[-3], v131);
    if (v131 == nil) goto v136;
    v131 = stack[-5];
    v132 = qcar(v131);
    v131 = elt(env, 3); /* plus */
    if (v132 == v131) goto v137;
    v131 = stack[-5];
    v132 = qcar(v131);
    v131 = elt(env, 5); /* times */
    if (v132 == v131) goto v137;
    v131 = stack[-5];
    v132 = qcar(v131);
    v131 = elt(env, 4); /* minus */
    if (v132 == v131) goto v44;
    v131 = stack[-5];
    v132 = qcar(v131);
    v131 = elt(env, 6); /* quotient */
    if (v132 == v131) goto v138;
    v131 = stack[-5];
    v132 = qcar(v131);
    v131 = elt(env, 2); /* expt */
    if (v132 == v131) goto v139;
    v131 = stack[-5];
    v132 = qcar(v131);
    v131 = elt(env, 7); /* df */
    if (!(v132 == v131)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v131 = stack[-5];
    v131 = qcdr(v131);
    v132 = qcar(v131);
    v131 = stack[-4];
    if (equal(v132, v131)) goto v140;
    v132 = stack[-4];
    v131 = stack[-5];
    v131 = qcdr(v131);
    v131 = qcar(v131);
    fn = elt(env, 11); /* smember */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    if (!(v131 == nil)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v133 = stack[-4];
    v131 = stack[-5];
    v131 = qcdr(v131);
    v132 = qcar(v131);
    v131 = qvalue(elt(env, 9)); /* depl!* */
    v131 = Lassoc(nil, v132, v131);
    v131 = Lmember(nil, v133, v131);
    if (!(v131 == nil)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v140:
    v131 = qvalue(elt(env, 1)); /* t */
    stack[-6] = v131;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v139:
    v131 = stack[-5];
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    v131 = qcar(v131);
    v131 = integerp(v131);
    if (v131 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v131 = stack[-5];
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    v132 = qcar(v131);
    v131 = (Lisp_Object)1; /* 0 */
    v131 = (Lisp_Object)greaterp2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = v131 ? lisp_true : nil;
    env = stack[-7];
    if (v131 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v131 = stack[-5];
    v131 = qcdr(v131);
    v132 = qcar(v131);
    v131 = stack[-4];
    v131 = CC_polyp(env, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    stack[-6] = v131;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v138:
    v132 = stack[-4];
    v131 = stack[-5];
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    v131 = qcar(v131);
    fn = elt(env, 11); /* smember */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    if (!(v131 == nil)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v133 = stack[-4];
    v131 = stack[-5];
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    v132 = qcar(v131);
    v131 = qvalue(elt(env, 9)); /* depl!* */
    v131 = Lassoc(nil, v132, v131);
    v131 = Lmember(nil, v133, v131);
    if (!(v131 == nil)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v131 = stack[-5];
    v131 = qcdr(v131);
    v132 = qcar(v131);
    v131 = stack[-4];
    v131 = CC_polyp(env, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    stack[-6] = v131;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v44:
    v131 = stack[-5];
    v131 = qcdr(v131);
    v132 = qcar(v131);
    v131 = stack[-4];
    v131 = CC_polyp(env, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    stack[-6] = v131;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v137:
    v131 = stack[-5];
    v131 = qcdr(v131);
    stack[-5] = v131;
    goto v141;

v141:
    v131 = stack[-5];
    if (v131 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v131 = stack[-5];
    v132 = qcar(v131);
    v131 = stack[-4];
    v131 = CC_polyp(env, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-7];
    stack[-6] = v131;
    if (v131 == nil) goto v2;
    v131 = stack[-5];
    v131 = qcdr(v131);
    stack[-5] = v131;
    goto v141;

v2:
    v131 = qvalue(elt(env, 8)); /* nil */
    stack[-5] = v131;
    goto v141;

v136:
    v132 = stack[-5];
    v131 = stack[-4];
    v131 = (equal(v132, v131) ? lisp_true : nil);
    stack[-6] = v131;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v135:
    v131 = qvalue(elt(env, 1)); /* t */
    stack[-6] = v131;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
/* error exit handlers */
v134:
    popv(8);
    return nil;
}



/* Code for formclear1 */

static Lisp_Object MS_CDECL CC_formclear1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v155, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclear1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclear1");
#endif
    if (stack >= stacklimit)
    {
        push3(v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v142);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v142;
    stack[-5] = v1;
    v154 = v0;
/* end of prologue */
    stack[-6] = elt(env, 1); /* list */
    stack[-3] = v154;
    v154 = stack[-3];
    if (v154 == nil) goto v34;
    v154 = stack[-3];
    v154 = qcar(v154);
    v66 = v154;
    v155 = v66;
    v154 = elt(env, 3); /* share */
    v154 = Lflagp(nil, v155, v154);
    env = stack[-7];
    if (v154 == nil) goto v128;
    v154 = v66;
    v154 = Lmkquote(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    goto v43;

v43:
    v154 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    stack[-1] = v154;
    stack[-2] = v154;
    goto v79;

v79:
    v154 = stack[-3];
    v154 = qcdr(v154);
    stack[-3] = v154;
    v154 = stack[-3];
    if (v154 == nil) goto v130;
    stack[0] = stack[-1];
    v154 = stack[-3];
    v154 = qcar(v154);
    v66 = v154;
    v155 = v66;
    v154 = elt(env, 3); /* share */
    v154 = Lflagp(nil, v155, v154);
    env = stack[-7];
    if (v154 == nil) goto v157;
    v154 = v66;
    v154 = Lmkquote(nil, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    goto v158;

v158:
    v154 = ncons(v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    v154 = Lrplacd(nil, stack[0], v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    v154 = stack[-1];
    v154 = qcdr(v154);
    stack[-1] = v154;
    goto v79;

v157:
    v155 = stack[-5];
    v154 = stack[-4];
    fn = elt(env, 4); /* form1 */
    v154 = (*qfnn(fn))(qenv(fn), 3, v66, v155, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    goto v158;

v130:
    v154 = stack[-2];
    goto v159;

v159:
    {
        Lisp_Object v10 = stack[-6];
        popv(8);
        return cons(v10, v154);
    }

v128:
    v155 = stack[-5];
    v154 = stack[-4];
    fn = elt(env, 4); /* form1 */
    v154 = (*qfnn(fn))(qenv(fn), 3, v66, v155, v154);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    goto v43;

v34:
    v154 = qvalue(elt(env, 2)); /* nil */
    goto v159;
/* error exit handlers */
v156:
    popv(8);
    return nil;
}



/* Code for remred */

static Lisp_Object CC_remred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remred");
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
    stack[-6] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    v165 = stack[-5];
    v165 = Lreverse(nil, v165);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    stack[-5] = v165;
    goto v91;

v91:
    v165 = stack[-5];
    if (v165 == nil) goto v32;
    v165 = stack[-5];
    v165 = qcar(v165);
    stack[-2] = v165;
    v165 = stack[-5];
    v165 = qcdr(v165);
    stack[-5] = v165;
    v165 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v165;
    v165 = qvalue(elt(env, 1)); /* gg */
    stack[-3] = v165;
    goto v43;

v43:
    v165 = stack[-1];
    if (v165 == nil) goto v150;
    v165 = stack[-3];
    if (v165 == nil) goto v150;
    v165 = stack[-3];
    v165 = qcar(v165);
    v166 = v165;
    v165 = stack[-3];
    v165 = qcdr(v165);
    stack[-3] = v165;
    v165 = v166;
    v166 = qcdr(v165);
    v165 = stack[-2];
    v165 = qcdr(v165);
    fn = elt(env, 4); /* dd */
    stack[0] = (*qfn2(fn))(qenv(fn), v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    v166 = stack[-4];
    v165 = (Lisp_Object)33; /* 2 */
    v165 = plus2(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    v165 = (Lisp_Object)geq2(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v165 = v165 ? lisp_true : nil;
    env = stack[-7];
    if (v165 == nil) goto v43;
    v165 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v165;
    goto v43;

v150:
    v165 = stack[-1];
    if (v165 == nil) goto v91;
    v166 = stack[-2];
    v165 = qvalue(elt(env, 1)); /* gg */
    v165 = cons(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    qvalue(elt(env, 1)) = v165; /* gg */
    goto v91;

v32:
    v165 = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = stack[-6]; /* gg */
    { popv(8); return onevalue(v165); }
/* error exit handlers */
v71:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* gg */
    popv(8);
    return nil;
}



/* Code for super_product_sq */

static Lisp_Object CC_super_product_sq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for super_product_sq");
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
    stack[-1] = v1;
    v148 = v0;
/* end of prologue */
    v146 = v148;
    v148 = elt(env, 1); /* (ext) */
    fn = elt(env, 3); /* split_ext */
    v148 = (*qfn2(fn))(qenv(fn), v146, v148);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-7];
    stack[0] = v148;
    v146 = stack[-1];
    v148 = elt(env, 1); /* (ext) */
    fn = elt(env, 3); /* split_ext */
    v148 = (*qfn2(fn))(qenv(fn), v146, v148);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-7];
    stack[-6] = v148;
    v146 = qvalue(elt(env, 2)); /* nil */
    v148 = (Lisp_Object)17; /* 1 */
    v148 = cons(v146, v148);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-7];
    v146 = v148;
    v148 = stack[0];
    stack[-5] = v148;
    goto v125;

v125:
    v148 = stack[-5];
    if (v148 == nil) { popv(8); return onevalue(v146); }
    v148 = stack[-5];
    v148 = qcar(v148);
    stack[-4] = v148;
    v148 = stack[-6];
    stack[-3] = v148;
    goto v127;

v127:
    v148 = stack[-3];
    if (v148 == nil) goto v126;
    v148 = stack[-3];
    v148 = qcar(v148);
    stack[-2] = v148;
    stack[-1] = v146;
    v148 = stack[-4];
    v146 = qcdr(v148);
    v148 = stack[-2];
    v148 = qcdr(v148);
    fn = elt(env, 4); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v146, v148);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-7];
    v148 = stack[-4];
    v146 = qcar(v148);
    v148 = stack[-2];
    v148 = qcar(v148);
    fn = elt(env, 5); /* ext_mult */
    v148 = (*qfn2(fn))(qenv(fn), v146, v148);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-7];
    fn = elt(env, 4); /* multsq */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-7];
    fn = elt(env, 6); /* addsq */
    v148 = (*qfn2(fn))(qenv(fn), stack[-1], v148);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-7];
    v146 = v148;
    v148 = stack[-3];
    v148 = qcdr(v148);
    stack[-3] = v148;
    goto v127;

v126:
    v148 = stack[-5];
    v148 = qcdr(v148);
    stack[-5] = v148;
    goto v125;
/* error exit handlers */
v174:
    popv(8);
    return nil;
}



/* Code for qqe_qadd!-inside!-at */

static Lisp_Object CC_qqe_qaddKinsideKat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qadd-inside-at");
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
    v153 = v0;
/* end of prologue */
    fn = elt(env, 3); /* rl_prepat */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[0] = v153;
    v153 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[-1] = v153;
    v153 = stack[0];
    fn = elt(env, 5); /* qqe_arg2r */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[0] = v153;
    v153 = stack[-1];
    fn = elt(env, 6); /* qqe_qadd!-inside */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    if (!(v153 == nil)) goto v92;
    v153 = stack[0];
    fn = elt(env, 6); /* qqe_qadd!-inside */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    if (!(v153 == nil)) goto v92;
    v153 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v153); }

v92:
    v153 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v153); }
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for pasf_ordrelp */

static Lisp_Object CC_pasf_ordrelp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v175, v173;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_ordrelp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v175 = v1;
    v34 = v0;
/* end of prologue */
    v173 = elt(env, 1); /* (equal neq leq lessp geq greaterp cong ncong) 
*/
    v34 = Lmemq(nil, v34, v173);
    v34 = Lmemq(nil, v175, v34);
    v34 = (v34 == nil ? lisp_true : nil);
    v34 = (v34 == nil ? lisp_true : nil);
    return onevalue(v34);
}



/* Code for ratpoly_xtothen */

static Lisp_Object CC_ratpoly_xtothen(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_xtothen");
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
    goto v91;

v91:
    v75 = stack[0];
    v74 = (Lisp_Object)1; /* 0 */
    if (v75 == v74) goto v159;
    v74 = stack[-1];
    fn = elt(env, 1); /* ratpoly_fromatom */
    v75 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v74 = stack[-2];
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    stack[-2] = v74;
    v74 = stack[0];
    v74 = sub1(v74);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    stack[0] = v74;
    goto v91;

v159:
    v74 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* ratpoly_fromatom */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v75 = v74;
    goto v84;

v84:
    v74 = stack[-2];
    if (v74 == nil) { popv(4); return onevalue(v75); }
    v74 = stack[-2];
    v74 = qcar(v74);
    fn = elt(env, 2); /* ratpoly_mult */
    v74 = (*qfn2(fn))(qenv(fn), v74, v75);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v75 = v74;
    v74 = stack[-2];
    v74 = qcdr(v74);
    stack[-2] = v74;
    goto v84;
/* error exit handlers */
v88:
    popv(4);
    return nil;
}



/* Code for mkop */

static Lisp_Object CC_mkop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v178, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkop");
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
    v149 = stack[0];
    if (v149 == nil) goto v83;
    v149 = stack[0];
    fn = elt(env, 11); /* gettype */
    v178 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v141 = v178;
    v149 = elt(env, 3); /* operator */
    if (v178 == v149) goto v97;
    v149 = v141;
    if (v149 == nil) goto v158;
    v178 = v141;
    v149 = elt(env, 8); /* (fluid global procedure scalar) */
    v149 = Lmemq(nil, v178, v149);
    if (!(v149 == nil)) goto v158;
    v178 = stack[0];
    v149 = elt(env, 3); /* operator */
    fn = elt(env, 12); /* typerr */
    v149 = (*qfn2(fn))(qenv(fn), v178, v149);
    nil = C_nil;
    if (exception_pending()) goto v170;
    goto v164;

v164:
    v149 = nil;
    { popv(3); return onevalue(v149); }

v158:
    v141 = stack[0];
    v178 = elt(env, 9); /* simpfn */
    v149 = elt(env, 10); /* simpiden */
    v149 = Lputprop(nil, 3, v141, v178, v149);
    nil = C_nil;
    if (exception_pending()) goto v170;
    goto v164;

v97:
    v149 = qvalue(elt(env, 4)); /* !*msg */
    if (v149 == nil) goto v164;
    stack[-1] = elt(env, 6); /* "***" */
    v178 = stack[0];
    v149 = elt(env, 7); /* "already defined as operator" */
    v149 = list2(v178, v149);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    fn = elt(env, 13); /* lpriw */
    v149 = (*qfn2(fn))(qenv(fn), stack[-1], v149);
    nil = C_nil;
    if (exception_pending()) goto v170;
    goto v164;

v83:
    v178 = elt(env, 1); /* "Local variable" */
    v149 = elt(env, 2); /* "operator" */
    fn = elt(env, 12); /* typerr */
    v149 = (*qfn2(fn))(qenv(fn), v178, v149);
    nil = C_nil;
    if (exception_pending()) goto v170;
    goto v164;
/* error exit handlers */
v170:
    popv(3);
    return nil;
}



/* Code for simp!:ps!: */

static Lisp_Object CC_simpTpsT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp:ps:");
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
    v83 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!:ps1 */
    v31 = (*qfn1(fn))(qenv(fn), v83);
    errexit();
    v83 = (Lisp_Object)17; /* 1 */
    return cons(v31, v83);
}



/* Code for leqgrt */

static Lisp_Object MS_CDECL CC_leqgrt(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v179;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "leqgrt");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for leqgrt");
#endif
    if (stack >= stacklimit)
    {
        push3(v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v142);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v142;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v179 = stack[-1];
    v94 = stack[0];
    v94 = (Lisp_Object)lesseq2(v179, v94);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v94 = v94 ? lisp_true : nil;
    env = stack[-3];
    if (v94 == nil) goto v84;
    v179 = stack[-2];
    v94 = stack[-1];
    v94 = Leqn(nil, v179, v94);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    goto v159;

v159:
    if (!(v94 == nil)) { popv(4); return onevalue(v94); }
    v94 = stack[0];
    v94 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v19;
    {
        Lisp_Object v42 = stack[-1];
        popv(4);
        return Lgeq(nil, v42, v94);
    }

v84:
    v94 = qvalue(elt(env, 1)); /* nil */
    goto v159;
/* error exit handlers */
v19:
    popv(4);
    return nil;
}



/* Code for transferrow */

static Lisp_Object CC_transferrow(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow");
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
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v10 = qvalue(elt(env, 2)); /* maxvar */
    v156 = stack[-2];
    v156 = plus2(v10, v156);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v10 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v156/(16/CELL)));
    v156 = (Lisp_Object)33; /* 2 */
    v10 = *(Lisp_Object *)((char *)v10 + (CELL-TAG_VECTOR) + ((int32_t)v156/(16/CELL)));
    v156 = elt(env, 3); /* plus */
    if (v10 == v156) goto v160;
    v156 = stack[-2];
    fn = elt(env, 6); /* transferrow1 */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    if (v156 == nil) goto v148;
    v10 = stack[-2];
    v156 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); /* transferrow2 */
        return (*qfn2(fn))(qenv(fn), v10, v156);
    }

v148:
    v156 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v156); }

v160:
    v156 = stack[-2];
    fn = elt(env, 6); /* transferrow1 */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    if (v156 == nil) goto v78;
    stack[-3] = qvalue(elt(env, 1)); /* codmat */
    stack[-1] = qvalue(elt(env, 2)); /* maxvar */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v10 = qvalue(elt(env, 2)); /* maxvar */
    v156 = stack[-2];
    v156 = plus2(v10, v156);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v10 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v156/(16/CELL)));
    v156 = (Lisp_Object)49; /* 3 */
    v156 = *(Lisp_Object *)((char *)v10 + (CELL-TAG_VECTOR) + ((int32_t)v156/(16/CELL)));
    v156 = plus2(stack[-1], v156);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v10 = *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)v156/(16/CELL)));
    v156 = (Lisp_Object)33; /* 2 */
    v156 = *(Lisp_Object *)((char *)v10 + (CELL-TAG_VECTOR) + ((int32_t)v156/(16/CELL)));
    v10 = elt(env, 5); /* times */
    v156 = (v156 == v10 ? lisp_true : nil);
    { popv(5); return onevalue(v156); }

v78:
    v156 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v156); }
/* error exit handlers */
v45:
    popv(5);
    return nil;
}



/* Code for weak_xautoreduce1 */

static Lisp_Object CC_weak_xautoreduce1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for weak_xautoreduce1");
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

v161:
    v157 = stack[-4];
    if (v157 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v157 = stack[-4];
    v157 = qcar(v157);
    stack[-5] = v157;
    v157 = stack[-4];
    v157 = qcdr(v157);
    stack[-4] = v157;
    v181 = stack[-5];
    v157 = stack[-3];
    fn = elt(env, 2); /* weak_xreduce */
    v157 = (*qfn2(fn))(qenv(fn), v181, v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-5] = v157;
    if (v157 == nil) goto v161;
    v157 = stack[-5];
    fn = elt(env, 3); /* xnormalise */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-5] = v157;
    v157 = stack[-3];
    stack[-2] = v157;
    goto v179;

v179:
    v157 = stack[-2];
    if (v157 == nil) goto v24;
    v157 = stack[-2];
    v157 = qcar(v157);
    stack[-1] = v157;
    v157 = stack[-5];
    fn = elt(env, 4); /* xval */
    stack[0] = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v157 = stack[-1];
    fn = elt(env, 4); /* xval */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 5); /* xdiv */
    v157 = (*qfn2(fn))(qenv(fn), stack[0], v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    if (v157 == nil) goto v75;
    v181 = stack[-1];
    v157 = stack[-4];
    v157 = cons(v181, v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-4] = v157;
    v181 = stack[-1];
    v157 = stack[-3];
    v157 = Ldelete(nil, v181, v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-3] = v157;
    goto v75;

v75:
    v157 = stack[-2];
    v157 = qcdr(v157);
    stack[-2] = v157;
    goto v179;

v24:
    stack[0] = stack[-3];
    v157 = stack[-5];
    v157 = ncons(v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v157 = Lappend(nil, stack[0], v157);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-3] = v157;
    goto v161;
/* error exit handlers */
v182:
    popv(7);
    return nil;
}



/* Code for partitinnerprod */

static Lisp_Object CC_partitinnerprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitinnerprod");
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
    v92 = stack[0];
    v92 = qcar(v92);
    fn = elt(env, 1); /* partitop */
    stack[-1] = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    fn = elt(env, 1); /* partitop */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    {
        Lisp_Object v33 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* innerprodpf */
        return (*qfn2(fn))(qenv(fn), v33, v92);
    }
/* error exit handlers */
v97:
    popv(3);
    return nil;
}



/* Code for find_bubles1_coeff */

static Lisp_Object MS_CDECL CC_find_bubles1_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, Lisp_Object v56, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "find_bubles1_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1_coeff");
#endif
    if (stack >= stacklimit)
    {
        push4(v56,v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v142,v56);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v56;
    stack[0] = v142;
    stack[-1] = v1;
    stack[-4] = v0;
/* end of prologue */

v184:
    v41 = stack[-4];
    if (v41 == nil) goto v83;
    v41 = stack[-4];
    v176 = qcar(v41);
    v41 = stack[0];
    fn = elt(env, 1); /* find_bubles1 */
    v41 = (*qfn2(fn))(qenv(fn), v176, v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    stack[-2] = v41;
    v41 = stack[-4];
    stack[-4] = qcdr(v41);
    v41 = stack[-2];
    v176 = qcdr(v41);
    v41 = stack[-1];
    stack[-1] = cons(v176, v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v41 = stack[-2];
    v41 = qcar(v41);
    if (v41 == nil) goto v152;
    v41 = stack[-2];
    v176 = qcar(v41);
    v41 = stack[-3];
    v41 = cons(v176, v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    goto v93;

v93:
    stack[-3] = v41;
    goto v184;

v152:
    v41 = stack[-3];
    goto v93;

v83:
    v176 = stack[-3];
    v41 = stack[-1];
    popv(6);
    return cons(v176, v41);
/* error exit handlers */
v72:
    popv(6);
    return nil;
}



/* Code for clogf */

static Lisp_Object CC_clogf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clogf");
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
    stack[-1] = nil;
    v21 = stack[-2];
    v20 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    stack[-3] = v20;
    v20 = stack[-3];
    stack[0] = v20;
    goto v80;

v80:
    v20 = stack[0];
    if (v20 == nil) goto v79;
    v20 = stack[0];
    v20 = qcar(v20);
    v122 = v20;
    v21 = v122;
    v20 = elt(env, 2); /* log */
    if (!consp(v21)) goto v43;
    v21 = qcar(v21);
    if (!(v21 == v20)) goto v43;
    v21 = v122;
    v20 = stack[-1];
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    stack[-1] = v20;
    goto v43;

v43:
    v20 = stack[0];
    v20 = qcdr(v20);
    stack[0] = v20;
    goto v80;

v79:
    v20 = stack[-1];
    if (v20 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v21 = stack[-3];
    v20 = stack[-1];
    fn = elt(env, 4); /* setdiff */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    stack[-3] = v20;
    v21 = stack[-3];
    v20 = stack[-1];
    v20 = Lnconc(nil, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    fn = elt(env, 5); /* setkorder */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    stack[-3] = v20;
    v20 = stack[-2];
    fn = elt(env, 6); /* reorder */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    fn = elt(env, 7); /* clogf1 */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    stack[-2] = v20;
    v20 = stack[-3];
    fn = elt(env, 5); /* setkorder */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    v20 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* reorder */
        return (*qfn1(fn))(qenv(fn), v20);
    }
/* error exit handlers */
v141:
    popv(5);
    return nil;
}



/* Code for coeffrow */

static Lisp_Object MS_CDECL CC_coeffrow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v28, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeffrow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeffrow");
#endif
    if (stack >= stacklimit)
    {
        push3(v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v142);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v142;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v137 = nil;
    goto v161;

v161:
    v28 = stack[-1];
    if (v28 == nil) goto v143;
    v28 = stack[-2];
    if (v28 == nil) goto v171;
    v28 = stack[-2];
    v28 = qcar(v28);
    v28 = qcar(v28);
    v29 = qcar(v28);
    v28 = stack[-1];
    v28 = qcar(v28);
    if (!(equal(v29, v28))) goto v171;
    v28 = stack[-2];
    v28 = qcar(v28);
    v29 = qcdr(v28);
    v28 = stack[0];
    v137 = acons(v29, v28, v137);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    v28 = stack[-2];
    v28 = qcdr(v28);
    stack[-2] = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v161;

v171:
    v29 = qvalue(elt(env, 1)); /* nil */
    v28 = (Lisp_Object)17; /* 1 */
    v137 = acons(v29, v28, v137);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-3];
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v161;

v143:
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v137);
    }
/* error exit handlers */
v144:
    popv(4);
    return nil;
}



/* Code for frlp */

static Lisp_Object CC_frlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v153, v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for frlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v153 = v0;
/* end of prologue */

v184:
    v17 = v153;
    v17 = (v17 == nil ? lisp_true : nil);
    if (!(v17 == nil)) return onevalue(v17);
    v17 = v153;
    v150 = qcar(v17);
    v17 = qvalue(elt(env, 1)); /* frlis!* */
    v17 = Lmemq(nil, v150, v17);
    if (v17 == nil) goto v84;
    v17 = v153;
    v17 = qcdr(v17);
    v153 = v17;
    goto v184;

v84:
    v17 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v17);
}



/* Code for canonical */

static Lisp_Object CC_canonical(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canonical");
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
    stack[0] = qvalue(elt(env, 1)); /* !*distribute */
    qvalue(elt(env, 1)) = nil; /* !*distribute */
    v145 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v145;
    v145 = stack[-2];
    v145 = qcar(v145);
    fn = elt(env, 5); /* simp!* */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    stack[-2] = v145;
    v145 = stack[-2];
    v145 = qcdr(v145);
    stack[-3] = v145;
    v145 = elt(env, 3); /* distribute */
    v145 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    fn = elt(env, 6); /* on */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    v145 = stack[-2];
    v145 = qcar(v145);
    fn = elt(env, 7); /* distri_pol */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    stack[-2] = v145;
    goto v173;

v173:
    v145 = stack[-2];
    if (!consp(v145)) goto v126;
    v145 = stack[-2];
    v145 = qcar(v145);
    if (!consp(v145)) goto v126;
    v145 = stack[-2];
    v145 = qcar(v145);
    v145 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    fn = elt(env, 8); /* dv_canon_monomial */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    fn = elt(env, 9); /* addf */
    v145 = (*qfn2(fn))(qenv(fn), stack[-1], v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    stack[-1] = v145;
    v145 = stack[-2];
    v145 = qcdr(v145);
    stack[-2] = v145;
    goto v173;

v126:
    v158 = stack[-1];
    v145 = stack[-2];
    fn = elt(env, 9); /* addf */
    v145 = (*qfn2(fn))(qenv(fn), v158, v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    stack[-1] = v145;
    stack[-2] = elt(env, 4); /* !*sq */
    v158 = stack[-1];
    v145 = stack[-3];
    v158 = cons(v158, v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    v145 = qvalue(elt(env, 2)); /* nil */
    v145 = list3(stack[-2], v158, v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    fn = elt(env, 5); /* simp!* */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*distribute */
    { popv(5); return onevalue(v145); }
/* error exit handlers */
v20:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*distribute */
    popv(5);
    return nil;
}



/* Code for mult!.comp!.tp!. */

static Lisp_Object MS_CDECL CC_multQcompQtpQ(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mult.comp.tp.");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mult.comp.tp.");
#endif
    if (stack >= stacklimit)
    {
        push3(v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v142);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-11] = v142;
    stack[-12] = v1;
    stack[-13] = v0;
/* end of prologue */
    stack[-14] = nil;
    stack[-10] = nil;
    stack[-9] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    v234 = stack[-13];
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v235 = v234;
    goto v18;

v18:
    v234 = v235;
    if (v234 == nil) goto v16;
    v234 = v235;
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    if (!(v234 == nil)) goto v16;
    v234 = v235;
    v234 = qcdr(v234);
    v235 = v234;
    goto v18;

v16:
    v234 = v235;
    v235 = v234;
    v234 = v235;
    if (v234 == nil) goto v128;
    v234 = v235;
    fn = elt(env, 2); /* get!-min!-degreelist */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-5] = v234;
    goto v27;

v27:
    v234 = stack[-12];
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v235 = v234;
    goto v183;

v183:
    v234 = v235;
    if (v234 == nil) goto v168;
    v234 = v235;
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    if (!(v234 == nil)) goto v168;
    v234 = v235;
    v234 = qcdr(v234);
    v235 = v234;
    goto v183;

v168:
    v234 = v235;
    v235 = v234;
    v234 = v235;
    if (v234 == nil) goto v170;
    v234 = v235;
    fn = elt(env, 2); /* get!-min!-degreelist */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-4] = v234;
    goto v149;

v149:
    v234 = stack[-13];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    stack[-13] = v234;
    v234 = stack[-12];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    stack[-12] = v234;
    v234 = stack[-13];
    stack[0] = Llength(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v234 = stack[-12];
    v234 = Llength(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    if (equal(stack[0], v234)) goto v10;
    v234 = qvalue(elt(env, 1)); /* nil */
    { popv(16); return onevalue(v234); }

v10:
    v234 = stack[-13];
    if (!(v234 == nil)) goto v63;
    stack[-2] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v235 = qvalue(elt(env, 1)); /* nil */
    v234 = qvalue(elt(env, 1)); /* nil */
    v234 = list2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    {
        Lisp_Object v237 = stack[-2];
        Lisp_Object v238 = stack[-1];
        Lisp_Object v239 = stack[0];
        popv(16);
        return list3star(v237, v238, v239, v234);
    }

v63:
    v234 = stack[-13];
    v234 = qcar(v234);
    v235 = qcar(v234);
    v234 = stack[-12];
    v234 = qcar(v234);
    v234 = qcar(v234);
    if (!(equal(v235, v234))) goto v240;
    v234 = stack[-13];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = stack[-12];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    if (!(equal(v235, v234))) goto v240;
    v234 = stack[-11];
    if (v234 == nil) goto v241;
    v234 = stack[-5];
    v235 = qcar(v234);
    v234 = stack[-4];
    v234 = qcar(v234);
    fn = elt(env, 3); /* tayexp!-difference */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    goto v113;

v113:
    stack[-3] = v234;
    v234 = stack[-13];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = stack[-5];
    v234 = qcar(v234);
    fn = elt(env, 3); /* tayexp!-difference */
    stack[0] = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v234 = stack[-12];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = stack[-4];
    v234 = qcar(v234);
    fn = elt(env, 3); /* tayexp!-difference */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    fn = elt(env, 4); /* tayexp!-min2 */
    v234 = (*qfn2(fn))(qenv(fn), stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[0] = v234;
    v234 = stack[-13];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = stack[-5];
    v234 = qcar(v234);
    fn = elt(env, 3); /* tayexp!-difference */
    stack[-1] = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v234 = stack[-12];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = stack[-4];
    v234 = qcar(v234);
    fn = elt(env, 3); /* tayexp!-difference */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    fn = elt(env, 4); /* tayexp!-min2 */
    v234 = (*qfn2(fn))(qenv(fn), stack[-1], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-6] = v234;
    v235 = stack[0];
    v234 = stack[-5];
    v234 = qcar(v234);
    fn = elt(env, 5); /* tayexp!-plus2 */
    v235 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v234 = stack[-9];
    v234 = cons(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-9] = v234;
    v235 = stack[0];
    v234 = stack[-4];
    v234 = qcar(v234);
    fn = elt(env, 5); /* tayexp!-plus2 */
    v235 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v234 = stack[-8];
    v234 = cons(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-8] = v234;
    v235 = stack[-6];
    v234 = stack[-5];
    v234 = qcar(v234);
    fn = elt(env, 5); /* tayexp!-plus2 */
    v235 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v234 = stack[-14];
    v234 = cons(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-14] = v234;
    v235 = stack[-6];
    v234 = stack[-4];
    v234 = qcar(v234);
    fn = elt(env, 5); /* tayexp!-plus2 */
    v235 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v234 = stack[-10];
    v234 = cons(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-10] = v234;
    v234 = stack[-13];
    v234 = qcar(v234);
    stack[-2] = qcar(v234);
    v234 = stack[-13];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    stack[-1] = qcar(v234);
    v235 = stack[-3];
    v234 = stack[0];
    fn = elt(env, 5); /* tayexp!-plus2 */
    stack[0] = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v235 = stack[-3];
    v234 = stack[-6];
    fn = elt(env, 5); /* tayexp!-plus2 */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v235 = list4(stack[-2], stack[-1], stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    v234 = stack[-7];
    v234 = cons(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-7] = v234;
    v234 = stack[-13];
    v234 = qcdr(v234);
    stack[-13] = v234;
    v234 = stack[-12];
    v234 = qcdr(v234);
    stack[-12] = v234;
    v234 = stack[-5];
    v234 = qcdr(v234);
    stack[-5] = v234;
    v234 = stack[-4];
    v234 = qcdr(v234);
    stack[-4] = v234;
    v234 = stack[-13];
    if (!(v234 == nil)) goto v63;
    v234 = stack[-7];
    stack[0] = Lnreverse(nil, v234);
    env = stack[-15];
    v234 = stack[-9];
    stack[-1] = Lnreverse(nil, v234);
    env = stack[-15];
    v234 = stack[-8];
    stack[-2] = Lnreverse(nil, v234);
    env = stack[-15];
    v234 = stack[-14];
    v235 = Lnreverse(nil, v234);
    env = stack[-15];
    v234 = stack[-10];
    v234 = Lnreverse(nil, v234);
    env = stack[-15];
    v234 = list2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    {
        Lisp_Object v242 = stack[0];
        Lisp_Object v243 = stack[-1];
        Lisp_Object v244 = stack[-2];
        popv(16);
        return list3star(v242, v243, v244, v234);
    }

v241:
    v234 = stack[-5];
    v235 = qcar(v234);
    v234 = stack[-4];
    v234 = qcar(v234);
    fn = elt(env, 5); /* tayexp!-plus2 */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    goto v113;

v240:
    v234 = qvalue(elt(env, 1)); /* nil */
    { popv(16); return onevalue(v234); }

v170:
    stack[0] = (Lisp_Object)1; /* 0 */
    v234 = stack[-12];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v234 = Llength(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    fn = elt(env, 6); /* nlist */
    v234 = (*qfn2(fn))(qenv(fn), stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-4] = v234;
    goto v149;

v128:
    stack[0] = (Lisp_Object)1; /* 0 */
    v234 = stack[-13];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v234 = Llength(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    fn = elt(env, 6); /* nlist */
    v234 = (*qfn2(fn))(qenv(fn), stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-15];
    stack[-5] = v234;
    goto v27;
/* error exit handlers */
v236:
    popv(16);
    return nil;
}



/* Code for qqe_length!-graph!-remove!-mark */

static Lisp_Object CC_qqe_lengthKgraphKremoveKmark(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v43, v76, v172;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_length-graph-remove-mark");
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
    v76 = v1;
    v150 = v0;
/* end of prologue */
    v172 = v150;
    goto v164;

v164:
    v150 = v172;
    if (v150 == nil) goto v143;
    v150 = v172;
    v150 = qcar(v150);
    v43 = v150;
    v150 = v76;
    v150 = Lremprop(nil, v43, v150);
    env = stack[0];
    v150 = v172;
    v150 = qcdr(v150);
    v172 = v150;
    goto v164;

v143:
    v150 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v150); }
}



/* Code for sfto_dprpartksf */

static Lisp_Object CC_sfto_dprpartksf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dprpartksf");
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
    v83 = v0;
/* end of prologue */
    stack[0] = v83;
    fn = elt(env, 1); /* sfto_dcontentf */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    {
        Lisp_Object v91 = stack[0];
        popv(2);
        fn = elt(env, 2); /* quotf */
        return (*qfn2(fn))(qenv(fn), v91, v83);
    }
/* error exit handlers */
v32:
    popv(2);
    return nil;
}



/* Code for find!-expts */

static Lisp_Object CC_findKexpts(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v9, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find-expts");
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
    v249 = stack[-2];
    if (!consp(v249)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v249 = stack[-2];
    v249 = qcar(v249);
    if (!consp(v249)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v249 = stack[-2];
    v249 = qcar(v249);
    stack[0] = qcdr(v249);
    v249 = stack[-2];
    v9 = qcdr(v249);
    v249 = stack[-1];
    v249 = CC_findKexpts(env, v9, v249);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    v249 = CC_findKexpts(env, stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[-1] = v249;
    v249 = stack[-2];
    v249 = qcar(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    stack[-2] = v249;
    v9 = stack[-2];
    v249 = elt(env, 1); /* sqrt */
    if (!consp(v9)) goto v168;
    v9 = qcar(v9);
    if (!(v9 == v249)) goto v168;
    v63 = elt(env, 2); /* expt */
    v249 = stack[-2];
    v249 = qcdr(v249);
    v9 = qcar(v249);
    v249 = elt(env, 3); /* (quotient 1 2) */
    v249 = list3(v63, v9, v249);
    nil = C_nil;
    if (exception_pending()) goto v250;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v168:
    v9 = stack[-2];
    v249 = elt(env, 2); /* expt */
    if (!consp(v9)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v9 = qcar(v9);
    if (!(v9 == v249)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v249 = stack[-2];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v9 = qcar(v249);
    v249 = elt(env, 4); /* quotient */
    if (!consp(v9)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v9 = qcar(v9);
    if (!(v9 == v249)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v249 = stack[-2];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    if (!(is_number(v249))) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v249 = stack[-2];
    v249 = qcdr(v249);
    v9 = qcar(v249);
    v249 = stack[-1];
    v249 = Lassoc(nil, v9, v249);
    stack[-3] = v249;
    v249 = stack[-3];
    if (!(v249 == nil)) goto v251;
    v249 = stack[-2];
    v249 = qcdr(v249);
    stack[0] = qcar(v249);
    v249 = elt(env, 5); /* g */
    v9 = Lgensym1(nil, v249);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    v249 = (Lisp_Object)17; /* 1 */
    v249 = list2star(stack[0], v9, v249);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[-3] = v249;
    v9 = stack[-3];
    v249 = stack[-1];
    v249 = cons(v9, v249);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[-1] = v249;
    goto v251;

v251:
    v249 = stack[-3];
    stack[0] = qcdr(v249);
    v249 = stack[-3];
    v249 = qcdr(v249);
    v9 = qcdr(v249);
    v249 = stack[-2];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    fn = elt(env, 6); /* lcm */
    v249 = (*qfn2(fn))(qenv(fn), v9, v249);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    v249 = Lrplacd(nil, stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v250;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
/* error exit handlers */
v250:
    popv(5);
    return nil;
}



/* Code for inszzzr */

static Lisp_Object CC_inszzzr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inszzzr");
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
    goto v164;

v164:
    v12 = stack[-1];
    if (v12 == nil) goto v17;
    v12 = stack[-1];
    v12 = qcar(v12);
    v11 = qcar(v12);
    v12 = stack[-2];
    v12 = qcar(v12);
    v12 = (Lisp_Object)greaterp2(v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v120;
    v12 = v12 ? lisp_true : nil;
    env = stack[-4];
    if (!(v12 == nil)) goto v17;
    v12 = stack[-1];
    v12 = qcar(v12);
    v11 = qcar(v12);
    v12 = stack[-2];
    v12 = qcar(v12);
    if (equal(v11, v12)) goto v151;
    v12 = stack[-1];
    v11 = qcar(v12);
    v12 = stack[-3];
    v12 = cons(v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    stack[-3] = v12;
    v12 = stack[-1];
    v12 = qcdr(v12);
    stack[-1] = v12;
    goto v164;

v151:
    v12 = stack[-1];
    v12 = qcar(v12);
    stack[0] = qcdr(v12);
    v12 = stack[-1];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v11 = qcar(v12);
    v12 = stack[-2];
    v12 = qcdr(v12);
    v12 = qcar(v12);
    fn = elt(env, 1); /* dm!-plus */
    v12 = (*qfn2(fn))(qenv(fn), v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    v12 = Lrplaca(nil, stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    v12 = stack[-1];
    v12 = qcar(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    fn = elt(env, 2); /* zeropp */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    if (v12 == nil) goto v233;
    v11 = stack[-3];
    v12 = stack[-1];
    v12 = qcdr(v12);
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v11, v12);
    }

v233:
    v11 = stack[-3];
    v12 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v11, v12);
    }

v17:
    stack[0] = stack[-3];
    v11 = stack[-2];
    v12 = stack[-1];
    v12 = cons(v11, v12);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    {
        Lisp_Object v231 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v231, v12);
    }
/* error exit handlers */
v120:
    popv(5);
    return nil;
}



/* Code for dsimptimes */

static Lisp_Object CC_dsimptimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v251, v255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dsimptimes");
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
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v251 = stack[-1];
    if (v251 == nil) goto v160;
    v251 = stack[-1];
    v251 = qcdr(v251);
    if (v251 == nil) goto v27;
    v251 = stack[-1];
    v255 = qcar(v251);
    v251 = stack[0];
    fn = elt(env, 8); /* dsimp */
    v251 = (*qfn2(fn))(qenv(fn), v255, v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    stack[-4] = v251;
    v251 = stack[-1];
    v255 = qcdr(v251);
    v251 = stack[0];
    v251 = CC_dsimptimes(env, v255, v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    stack[-3] = v251;
    goto v168;

v168:
    v251 = stack[-3];
    if (v251 == nil) goto v20;
    v251 = stack[-3];
    v251 = qcar(v251);
    v255 = stack[-4];
    fn = elt(env, 9); /* mappend */
    v251 = (*qfn2(fn))(qenv(fn), v255, v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    stack[-2] = v251;
    v251 = stack[-2];
    fn = elt(env, 10); /* lastpair */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    stack[-1] = v251;
    v251 = stack[-3];
    v251 = qcdr(v251);
    stack[-3] = v251;
    v251 = stack[-1];
    if (!consp(v251)) goto v168;
    else goto v183;

v183:
    v251 = stack[-3];
    if (v251 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v251 = stack[-3];
    v251 = qcar(v251);
    v255 = stack[-4];
    fn = elt(env, 9); /* mappend */
    v251 = (*qfn2(fn))(qenv(fn), v255, v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    v251 = Lrplacd(nil, stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    v251 = stack[-1];
    fn = elt(env, 10); /* lastpair */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    stack[-1] = v251;
    v251 = stack[-3];
    v251 = qcdr(v251);
    stack[-3] = v251;
    goto v183;

v20:
    v251 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v251); }

v27:
    v251 = stack[-1];
    v255 = qcar(v251);
    v251 = stack[0];
    {
        popv(6);
        fn = elt(env, 8); /* dsimp */
        return (*qfn2(fn))(qenv(fn), v255, v251);
    }

v160:
    v251 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 11); /* terpri!* */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    v251 = elt(env, 2); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 12); /* lprie */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    v251 = elt(env, 0); /* dsimptimes */
    fn = elt(env, 13); /* printty */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    v255 = elt(env, 3); /* " " */
    v251 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 14); /* lpriw */
    v251 = (*qfn2(fn))(qenv(fn), v255, v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    v251 = elt(env, 5); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v255 = v251;
    v251 = v255;
    qvalue(elt(env, 6)) = v251; /* errmsg!* */
    v251 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v251 == nil)) goto v76;
    v251 = v255;
    fn = elt(env, 12); /* lprie */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-5];
    goto v76;

v76:
    v251 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v245;
    v251 = nil;
    { popv(6); return onevalue(v251); }
/* error exit handlers */
v245:
    popv(6);
    return nil;
}



/* Code for !:pi */

static Lisp_Object CC_Tpi(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v269;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :pi");
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
    v268 = stack[-6];
    v268 = integerp(v268);
    if (v268 == nil) goto v33;
    v269 = stack[-6];
    v268 = (Lisp_Object)1; /* 0 */
    v268 = (Lisp_Object)lesseq2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v268 = v268 ? lisp_true : nil;
    env = stack[-8];
    if (!(v268 == nil)) goto v33;
    v269 = elt(env, 0); /* !:pi */
    v268 = stack[-6];
    fn = elt(env, 5); /* get!:const */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[0] = v268;
    v269 = stack[0];
    v268 = elt(env, 2); /* not_found */
    if (!(v269 == v268)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    stack[0] = (Lisp_Object)33; /* 2 */
    v269 = stack[-6];
    v268 = (Lisp_Object)49; /* 3 */
    v268 = plus2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-7] = v268;
    v269 = Lexpt(nil, stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v268 = (Lisp_Object)81; /* 5 */
    v268 = quot2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-3] = v268;
    stack[-5] = v268;
    v269 = (Lisp_Object)81; /* 5 */
    v268 = (Lisp_Object)33; /* 2 */
    v268 = Lexpt(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v268 = negate(v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-2] = v268;
    v268 = (Lisp_Object)17; /* 1 */
    stack[-4] = v268;
    goto v69;

v69:
    v269 = stack[-3];
    v268 = (Lisp_Object)1; /* 0 */
    if (v269 == v268) goto v249;
    v269 = stack[-3];
    v268 = stack[-2];
    v268 = quot2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-3] = v268;
    stack[-1] = stack[-5];
    stack[0] = stack[-3];
    v269 = stack[-4];
    v268 = (Lisp_Object)33; /* 2 */
    v268 = plus2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-4] = v268;
    v268 = quot2(stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v268 = plus2(stack[-1], v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-5] = v268;
    goto v69;

v249:
    v269 = (Lisp_Object)33; /* 2 */
    v268 = stack[-7];
    v269 = Lexpt(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v268 = (Lisp_Object)3825; /* 239 */
    v268 = quot2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-3] = v268;
    stack[0] = v268;
    v269 = (Lisp_Object)3825; /* 239 */
    v268 = (Lisp_Object)33; /* 2 */
    v268 = Lexpt(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v268 = negate(v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-2] = v268;
    v268 = (Lisp_Object)17; /* 1 */
    stack[-4] = v268;
    goto v37;

v37:
    v269 = stack[-3];
    v268 = (Lisp_Object)1; /* 0 */
    if (v269 == v268) goto v271;
    v269 = stack[-3];
    v268 = stack[-2];
    v268 = quot2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-3] = v268;
    stack[-1] = stack[0];
    stack[0] = stack[-3];
    v269 = stack[-4];
    v268 = (Lisp_Object)33; /* 2 */
    v268 = plus2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[-4] = v268;
    v268 = quot2(stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v268 = plus2(stack[-1], v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[0] = v268;
    goto v37;

v271:
    stack[-1] = elt(env, 4); /* !:rd!: */
    v269 = (Lisp_Object)257; /* 16 */
    v268 = stack[-5];
    stack[-2] = times2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v269 = (Lisp_Object)65; /* 4 */
    v268 = stack[0];
    v268 = times2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[0] = difference2(stack[-2], v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v268 = stack[-7];
    v268 = negate(v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v269 = list2star(stack[-1], stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    v268 = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    stack[0] = v268;
    v269 = elt(env, 0); /* !:pi */
    v268 = stack[0];
    fn = elt(env, 7); /* save!:const */
    v268 = (*qfn2(fn))(qenv(fn), v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }

v33:
    stack[0] = (Lisp_Object)1; /* 0 */
    v269 = elt(env, 1); /* "Invalid argument to" */
    v268 = elt(env, 0); /* !:pi */
    v268 = list2(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-8];
    {
        Lisp_Object v272 = stack[0];
        popv(9);
        fn = elt(env, 8); /* error */
        return (*qfn2(fn))(qenv(fn), v272, v268);
    }
/* error exit handlers */
v270:
    popv(9);
    return nil;
}



/* Code for dif */

static Lisp_Object CC_dif(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v266, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dif");
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
    v266 = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[0] = nil;
    fn = elt(env, 5); /* reval */
    v266 = (*qfn1(fn))(qenv(fn), v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v266 = Lexplode(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v266 = Lreverse(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-5] = v266;
    v266 = stack[-4];
    fn = elt(env, 5); /* reval */
    v266 = (*qfn1(fn))(qenv(fn), v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-1] = v266;
    v266 = stack[-1];
    v266 = Lexplode(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-1] = v266;
    goto v173;

v173:
    v266 = stack[-5];
    if (v266 == nil) goto v6;
    v266 = stack[0];
    if (!(v266 == nil)) goto v6;
    v266 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v266;
    goto v125;

v125:
    v266 = stack[-5];
    if (v266 == nil) goto v90;
    v250 = stack[-5];
    v266 = elt(env, 2); /* !` */
    if (!consp(v250)) goto v151;
    v250 = qcar(v250);
    if (!(v250 == v266)) goto v151;

v90:
    v266 = stack[-2];
    v266 = Lcompress(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v250 = v266;
    v266 = v250;
    v266 = integerp(v266);
    if (v266 == nil) goto v178;
    v266 = v250;
    v266 = integerp(v266);
    if (v266 == nil) goto v69;
    v266 = stack[-4];
    v266 = (Lisp_Object)lesseq2(v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v266 = v266 ? lisp_true : nil;
    env = stack[-6];
    if (!(v266 == nil)) goto v178;

v69:
    v250 = stack[-2];
    v266 = stack[-3];
    v266 = Lnconc(nil, v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-3] = v266;
    v250 = stack[-5];
    v266 = elt(env, 2); /* !` */
    if (!consp(v250)) goto v173;
    v250 = qcar(v250);
    if (!(v250 == v266)) goto v173;
    v250 = elt(env, 2); /* !` */
    v266 = stack[-3];
    v266 = cons(v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-3] = v266;
    v250 = elt(env, 3); /* !! */
    v266 = stack[-3];
    v266 = cons(v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-3] = v266;
    v266 = stack[-5];
    v266 = qcdr(v266);
    stack[-5] = v266;
    v266 = stack[-5];
    v266 = qcdr(v266);
    stack[-5] = v266;
    goto v173;

v178:
    v250 = stack[-1];
    v266 = stack[-3];
    v266 = Lnconc(nil, v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-3] = v266;
    v250 = elt(env, 2); /* !` */
    v266 = stack[-3];
    v266 = cons(v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-3] = v266;
    v250 = elt(env, 3); /* !! */
    v266 = stack[-3];
    v266 = cons(v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-3] = v266;
    v266 = qvalue(elt(env, 4)); /* t */
    stack[0] = v266;
    goto v69;

v151:
    v266 = stack[-5];
    v250 = qcar(v266);
    v266 = stack[-2];
    v266 = cons(v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-2] = v266;
    v266 = stack[-5];
    v266 = qcdr(v266);
    stack[-5] = v266;
    goto v125;

v6:
    v266 = stack[-5];
    v250 = Lreverse(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v266 = stack[-3];
    v266 = Lnconc(nil, v250, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v266 = Lcompress(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v35;
        popv(7);
        return Lintern(nil, v266);
/* error exit handlers */
v35:
    popv(7);
    return nil;
}



/* Code for gcdlist1 */

static Lisp_Object CC_gcdlist1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v95, v283;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdlist1");
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
    stack[0] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* reduction!-count */
    qvalue(elt(env, 1)) = nil; /* reduction!-count */
    v96 = stack[0];
    v96 = qcar(v96);
    v96 = qcdr(v96);
    stack[-4] = v96;
    stack[-2] = v96;
    v96 = stack[0];
    v96 = qcdr(v96);
    stack[-3] = v96;
    goto v79;

v79:
    v96 = stack[-3];
    if (v96 == nil) goto v92;
    v96 = stack[-3];
    v96 = qcar(v96);
    stack[-1] = v96;
    v95 = stack[-2];
    v96 = stack[-1];
    v96 = qcdr(v96);
    fn = elt(env, 4); /* vunion */
    v96 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-2] = v96;
    v95 = stack[-4];
    v96 = stack[-1];
    v96 = qcdr(v96);
    fn = elt(env, 5); /* vintersection */
    v96 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-4] = v96;
    v96 = stack[-3];
    v96 = qcdr(v96);
    stack[-3] = v96;
    goto v79;

v92:
    v96 = stack[-4];
    if (v96 == nil) goto v39;
    v96 = stack[-4];
    stack[-1] = v96;
    goto v30;

v30:
    v96 = stack[-1];
    if (v96 == nil) goto v68;
    v96 = stack[-1];
    v96 = qcar(v96);
    v95 = v96;
    v96 = stack[-2];
    fn = elt(env, 6); /* vdelete */
    v96 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-2] = v96;
    v96 = stack[-1];
    v96 = qcdr(v96);
    stack[-1] = v96;
    goto v30;

v68:
    v95 = stack[-4];
    v96 = elt(env, 3); /* lesspcdr */
    fn = elt(env, 7); /* sort */
    v96 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-4] = v96;
    v96 = stack[-4];
    v96 = qcar(v96);
    v95 = qcdr(v96);
    v96 = (Lisp_Object)17; /* 1 */
    if (v95 == v96) goto v182;
    v96 = stack[-2];
    if (v96 == nil) goto v51;
    v95 = stack[-2];
    v96 = stack[-4];
    v96 = Lappend(nil, v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 8); /* mapcarcar */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 9); /* setkorder */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-5] = v96;
    v96 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v96;
    v96 = stack[0];
    stack[-1] = v96;
    goto v285;

v285:
    v96 = stack[-1];
    if (v96 == nil) goto v286;
    v96 = stack[-1];
    v96 = qcar(v96);
    v96 = qcar(v96);
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = stack[-2];
    fn = elt(env, 8); /* mapcarcar */
    v95 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = stack[-4];
    fn = elt(env, 11); /* split!-wrt!-variables */
    v96 = (*qfnn(fn))(qenv(fn), 3, stack[0], v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-4] = v96;
    v96 = stack[-1];
    v96 = qcdr(v96);
    stack[-1] = v96;
    goto v285;

v286:
    v96 = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = stack[-4];
    stack[-5] = v96;
    v96 = stack[-5];
    if (v96 == nil) goto v287;
    v96 = stack[-5];
    v96 = qcar(v96);
    stack[-1] = v96;
    v96 = stack[-1];
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v95 = stack[-1];
    v96 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* total!-degree!-in!-powers */
    v96 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = cons(stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-3] = v96;
    stack[-4] = v96;
    goto v288;

v288:
    v96 = stack[-5];
    v96 = qcdr(v96);
    stack[-5] = v96;
    v96 = stack[-5];
    if (v96 == nil) goto v217;
    stack[-2] = stack[-3];
    v96 = stack[-5];
    v96 = qcar(v96);
    stack[-1] = v96;
    v96 = stack[-1];
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v95 = stack[-1];
    v96 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* total!-degree!-in!-powers */
    v96 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = cons(stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = Lrplacd(nil, stack[-2], v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = stack[-3];
    v96 = qcdr(v96);
    stack[-3] = v96;
    goto v288;

v217:
    v96 = stack[-4];
    goto v221;

v221:
    v96 = CC_gcdlist1(env, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v84;

v84:
    qvalue(elt(env, 1)) = stack[-6]; /* reduction!-count */
    { popv(8); return onevalue(v96); }

v287:
    v96 = qvalue(elt(env, 2)); /* nil */
    goto v221;

v51:
    v95 = stack[0];
    v96 = stack[-4];
    fn = elt(env, 13); /* gcdlist2 */
    v96 = (*qfn2(fn))(qenv(fn), v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v84;

v182:
    v95 = stack[-4];
    v96 = stack[-2];
    v96 = Lappend(nil, v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 8); /* mapcarcar */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-5] = v96;
    v96 = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-4] = v96;
    v96 = stack[0];
    stack[-3] = v96;
    v96 = stack[-3];
    if (v96 == nil) goto v253;
    v96 = stack[-3];
    v96 = qcar(v96);
    v96 = qcar(v96);
    fn = elt(env, 10); /* reorder */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v96;
    stack[-2] = v96;
    goto v44;

v44:
    v96 = stack[-3];
    v96 = qcdr(v96);
    stack[-3] = v96;
    v96 = stack[-3];
    if (v96 == nil) goto v65;
    stack[0] = stack[-1];
    v96 = stack[-3];
    v96 = qcar(v96);
    v96 = qcar(v96);
    fn = elt(env, 10); /* reorder */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = Lrplacd(nil, stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = stack[-1];
    v96 = qcdr(v96);
    stack[-1] = v96;
    goto v44;

v65:
    v96 = stack[-2];
    v283 = v96;
    goto v156;

v156:
    v95 = qvalue(elt(env, 2)); /* nil */
    v96 = stack[-5];
    fn = elt(env, 14); /* gcdlist3 */
    v96 = (*qfnn(fn))(qenv(fn), 3, v283, v95, v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v96;
    v96 = stack[-4];
    fn = elt(env, 9); /* setkorder */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v96 = stack[0];
    fn = elt(env, 10); /* reorder */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v84;

v253:
    v96 = qvalue(elt(env, 2)); /* nil */
    v283 = v96;
    goto v156;

v39:
    v96 = (Lisp_Object)17; /* 1 */
    goto v84;
/* error exit handlers */
v284:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* reduction!-count */
    popv(8);
    return nil;
}



/* Code for new_edge */

static Lisp_Object CC_new_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for new_edge");
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
    v74 = stack[-1];
    v75 = qcar(v74);
    v74 = stack[0];
    v74 = qcar(v74);
    fn = elt(env, 3); /* mk_edge_name */
    stack[-2] = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v74 = stack[-1];
    v75 = qcar(v74);
    v74 = stack[0];
    v74 = qcar(v74);
    v75 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v74 = qvalue(elt(env, 1)); /* nil */
    v74 = list3(stack[-2], v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    stack[0] = v74;
    v75 = stack[0];
    v74 = qvalue(elt(env, 2)); /* new_edge_list */
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    qvalue(elt(env, 2)) = v74; /* new_edge_list */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v88:
    popv(4);
    return nil;
}



/* Code for dp_comp */

static Lisp_Object CC_dp_comp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_comp");
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
    v41 = v1;
    v176 = v0;
/* end of prologue */
    fn = elt(env, 2); /* dp!=comp */
    v41 = (*qfn2(fn))(qenv(fn), v176, v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    stack[-4] = v41;
    v41 = stack[-4];
    if (v41 == nil) goto v33;
    v41 = stack[-4];
    v41 = qcar(v41);
    stack[0] = v41;
    v41 = stack[0];
    v41 = qcar(v41);
    fn = elt(env, 3); /* mo_deletecomp */
    v176 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v41 = stack[0];
    v41 = qcdr(v41);
    v41 = cons(v176, v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v41 = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    stack[-2] = v41;
    stack[-3] = v41;
    goto v159;

v159:
    v41 = stack[-4];
    v41 = qcdr(v41);
    stack[-4] = v41;
    v41 = stack[-4];
    if (v41 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v41 = stack[-4];
    v41 = qcar(v41);
    stack[0] = v41;
    v41 = stack[0];
    v41 = qcar(v41);
    fn = elt(env, 3); /* mo_deletecomp */
    v176 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v41 = stack[0];
    v41 = qcdr(v41);
    v41 = cons(v176, v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v41 = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v41 = Lrplacd(nil, stack[-1], v41);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v41 = stack[-2];
    v41 = qcdr(v41);
    stack[-2] = v41;
    goto v159;

v33:
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v41); }
/* error exit handlers */
v72:
    popv(6);
    return nil;
}



/* Code for pst_isolate */

static Lisp_Object CC_pst_isolate(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_isolate");
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
    v90 = v0;
/* end of prologue */
    v125 = v90;
    v90 = stack[-1];
    v90 = qcdr(v90);
    fn = elt(env, 1); /* pst_isolate1 */
    v90 = (*qfn2(fn))(qenv(fn), v125, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    fn = elt(env, 2); /* pst_reduce */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    stack[-2] = v90;
    stack[0] = stack[-2];
    v90 = stack[-1];
    v125 = qcar(v90);
    v90 = stack[-2];
    v90 = qcar(v90);
    v90 = Lappend(nil, v125, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-3];
    v90 = Lrplaca(nil, stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v94:
    popv(4);
    return nil;
}



/* Code for trailing!.coefft */

static Lisp_Object CC_trailingQcoefft(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v90, v125, v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for trailing.coefft");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v1;
    v125 = v0;
/* end of prologue */

v160:
    v38 = v125;
    if (!consp(v38)) return onevalue(v125);
    v38 = v125;
    v38 = qcar(v38);
    if (!consp(v38)) return onevalue(v125);
    v38 = v125;
    v38 = qcar(v38);
    v38 = qcar(v38);
    v77 = qcar(v38);
    v38 = v90;
    if (!(equal(v77, v38))) return onevalue(v125);
    v38 = v125;
    v38 = qcdr(v38);
    v125 = v38;
    goto v160;
}



/* Code for giquotient!: */

static Lisp_Object CC_giquotientT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v63, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giquotient:");
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
    v63 = v1;
    v60 = v0;
/* end of prologue */
    v9 = v60;
    v9 = qcdr(v9);
    v9 = qcar(v9);
    stack[-5] = v9;
    v9 = v60;
    v9 = qcdr(v9);
    v9 = qcdr(v9);
    stack[-4] = v9;
    v9 = v63;
    v9 = qcdr(v9);
    v9 = qcar(v9);
    stack[-3] = v9;
    v9 = v63;
    v9 = qcdr(v9);
    v9 = qcdr(v9);
    stack[-2] = v9;
    v63 = stack[-3];
    v9 = stack[-3];
    stack[0] = times2(v63, v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v63 = stack[-2];
    v9 = stack[-2];
    v9 = times2(v63, v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v9 = plus2(stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    stack[-1] = v9;
    v63 = stack[-5];
    v9 = stack[-3];
    stack[0] = times2(v63, v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v63 = stack[-4];
    v9 = stack[-2];
    v9 = times2(v63, v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v63 = plus2(stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v9 = stack[-1];
    v9 = Ldivide(nil, v63, v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    stack[0] = v9;
    v63 = stack[-4];
    v9 = stack[-3];
    stack[-3] = times2(v63, v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v63 = stack[-2];
    v9 = stack[-5];
    v9 = times2(v63, v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v63 = difference2(stack[-3], v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v9 = stack[-1];
    v9 = Ldivide(nil, v63, v9);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-6];
    v60 = v9;
    v9 = v60;
    v63 = qcdr(v9);
    v9 = (Lisp_Object)1; /* 0 */
    if (!(v63 == v9)) goto v246;
    v9 = stack[0];
    v63 = qcdr(v9);
    v9 = (Lisp_Object)1; /* 0 */
    if (!(v63 == v9)) goto v246;
    v63 = elt(env, 1); /* !:gi!: */
    v9 = stack[0];
    v9 = qcar(v9);
    v60 = qcar(v60);
    popv(7);
    return list2star(v63, v9, v60);

v246:
    v60 = elt(env, 1); /* !:gi!: */
    v63 = (Lisp_Object)1; /* 0 */
    v9 = (Lisp_Object)1; /* 0 */
    popv(7);
    return list2star(v60, v63, v9);
/* error exit handlers */
v62:
    popv(7);
    return nil;
}



/* Code for pickupu */

static Lisp_Object MS_CDECL CC_pickupu(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v142,
                         Lisp_Object v56, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v44, v232, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pickupu");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pickupu");
#endif
    if (stack >= stacklimit)
    {
        push3(v56,v142,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v142,v56);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v56;
    stack[-3] = v142;
    v231 = v1;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* rhs!* */
    qvalue(elt(env, 1)) = nil; /* rhs!* */
    qvalue(elt(env, 1)) = v231; /* rhs!* */
    stack[-1] = nil;
    v231 = qvalue(elt(env, 1)); /* rhs!* */
    qvalue(elt(env, 2)) = v231; /* pt */
    goto v32;

v32:
    v231 = qvalue(elt(env, 2)); /* pt */
    if (v231 == nil) goto v33;
    v231 = qvalue(elt(env, 2)); /* pt */
    v44 = qcar(v231);
    v231 = stack[-3];
    fn = elt(env, 6); /* nextu */
    v231 = (*qfn2(fn))(qenv(fn), v44, v231);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    stack[0] = v231;
    v231 = stack[0];
    if (v231 == nil) goto v92;
    v231 = stack[0];
    v44 = qcar(v231);
    v231 = qvalue(elt(env, 4)); /* lorder */
    fn = elt(env, 7); /* testord */
    v231 = (*qfn2(fn))(qenv(fn), v44, v231);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    if (v231 == nil) goto v69;
    v44 = stack[-1];
    v231 = stack[0];
    v231 = qcar(v231);
    fn = elt(env, 8); /* checkcoeffts */
    v231 = (*qfn2(fn))(qenv(fn), v44, v231);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    if (v231 == nil) goto v92;
    v44 = qvalue(elt(env, 5)); /* ulist */
    v231 = stack[0];
    fn = elt(env, 9); /* checku */
    v231 = (*qfn2(fn))(qenv(fn), v44, v231);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    if (!(v231 == nil)) goto v92;
    v231 = stack[0];
    v44 = qcar(v231);
    v231 = qvalue(elt(env, 1)); /* rhs!* */
    fn = elt(env, 10); /* checku1 */
    v231 = (*qfn2(fn))(qenv(fn), v44, v231);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    if (!(v231 == nil)) goto v69;
    v231 = stack[-2];
    if (v231 == nil) goto v166;
    v231 = stack[0];
    v61 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v232 = stack[-3];
    v231 = qvalue(elt(env, 2)); /* pt */
    v44 = qcdr(v231);
    v231 = qvalue(elt(env, 1)); /* rhs!* */
    fn = elt(env, 11); /* patchuptan */
    v231 = (*qfnn(fn))(qenv(fn), 4, v61, v232, v44, v231);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    stack[0] = v231;
    goto v166;

v166:
    v231 = stack[0];
    goto v161;

v161:
    qvalue(elt(env, 1)) = stack[-4]; /* rhs!* */
    { popv(6); return onevalue(v231); }

v69:
    v231 = qvalue(elt(env, 2)); /* pt */
    v231 = qcar(v231);
    v44 = qcdr(v231);
    v231 = stack[-1];
    v231 = cons(v44, v231);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    stack[-1] = v231;
    goto v92;

v92:
    v231 = qvalue(elt(env, 2)); /* pt */
    v231 = qcdr(v231);
    qvalue(elt(env, 2)) = v231; /* pt */
    goto v32;

v33:
    v231 = qvalue(elt(env, 3)); /* nil */
    goto v161;
/* error exit handlers */
v119:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* rhs!* */
    popv(6);
    return nil;
}



setup_type const u60_setup[] =
{
    {"multsm",                  too_few_2,      CC_multsm,     wrong_no_2},
    {"binomial",                too_few_2,      CC_binomial,   wrong_no_2},
    {"redexpp",                 CC_redexpp,     too_many_1,    wrong_no_1},
    {"polyp",                   too_few_2,      CC_polyp,      wrong_no_2},
    {"formclear1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclear1},
    {"remred",                  too_few_2,      CC_remred,     wrong_no_2},
    {"super_product_sq",        too_few_2,      CC_super_product_sq,wrong_no_2},
    {"qqe_qadd-inside-at",      CC_qqe_qaddKinsideKat,too_many_1,wrong_no_1},
    {"pasf_ordrelp",            too_few_2,      CC_pasf_ordrelp,wrong_no_2},
    {"ratpoly_xtothen",         too_few_2,      CC_ratpoly_xtothen,wrong_no_2},
    {"mkop",                    CC_mkop,        too_many_1,    wrong_no_1},
    {"simp:ps:",                CC_simpTpsT,    too_many_1,    wrong_no_1},
    {"leqgrt",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_leqgrt},
    {"transferrow",             too_few_2,      CC_transferrow,wrong_no_2},
    {"weak_xautoreduce1",       too_few_2,      CC_weak_xautoreduce1,wrong_no_2},
    {"partitinnerprod",         CC_partitinnerprod,too_many_1, wrong_no_1},
    {"find_bubles1_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles1_coeff},
    {"clogf",                   CC_clogf,       too_many_1,    wrong_no_1},
    {"coeffrow",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeffrow},
    {"frlp",                    CC_frlp,        too_many_1,    wrong_no_1},
    {"canonical",               CC_canonical,   too_many_1,    wrong_no_1},
    {"mult.comp.tp.",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_multQcompQtpQ},
    {"qqe_length-graph-remove-mark",too_few_2,  CC_qqe_lengthKgraphKremoveKmark,wrong_no_2},
    {"sfto_dprpartksf",         CC_sfto_dprpartksf,too_many_1, wrong_no_1},
    {"find-expts",              too_few_2,      CC_findKexpts, wrong_no_2},
    {"inszzzr",                 too_few_2,      CC_inszzzr,    wrong_no_2},
    {"dsimptimes",              too_few_2,      CC_dsimptimes, wrong_no_2},
    {":pi",                     CC_Tpi,         too_many_1,    wrong_no_1},
    {"dif",                     too_few_2,      CC_dif,        wrong_no_2},
    {"gcdlist1",                CC_gcdlist1,    too_many_1,    wrong_no_1},
    {"new_edge",                too_few_2,      CC_new_edge,   wrong_no_2},
    {"dp_comp",                 too_few_2,      CC_dp_comp,    wrong_no_2},
    {"pst_isolate",             too_few_2,      CC_pst_isolate,wrong_no_2},
    {"trailing.coefft",         too_few_2,      CC_trailingQcoefft,wrong_no_2},
    {"giquotient:",             too_few_2,      CC_giquotientT,wrong_no_2},
    {"pickupu",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_pickupu},
    {NULL, (one_args *)"u60", (two_args *)"5981 8875572 1184342", 0}
};

/* end of generated code */
