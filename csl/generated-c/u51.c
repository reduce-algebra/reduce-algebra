
/* $destdir\u51.c        Machine generated C code */

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


/* Code for nrootnn */

static Lisp_Object CC_nrootnn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nrootnn");
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
    stack[-5] = nil;
    v65 = (Lisp_Object)17; /* 1 */
    stack[0] = v65;
    v65 = (Lisp_Object)17; /* 1 */
    stack[-2] = v65;
    v66 = stack[-7];
    v65 = (Lisp_Object)1; /* 0 */
    v65 = (Lisp_Object)lessp2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v65 = v65 ? lisp_true : nil;
    env = stack[-9];
    if (v65 == nil) goto v68;
    v65 = stack[-7];
    v65 = negate(v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-7] = v65;
    v65 = stack[-6];
    v65 = Levenp(nil, v65);
    env = stack[-9];
    if (v65 == nil) goto v69;
    v65 = qvalue(elt(env, 1)); /* t */
    stack[-5] = v65;
    goto v68;

v68:
    v65 = qvalue(elt(env, 2)); /* !*primelist!* */
    stack[-8] = v65;
    goto v70;

v70:
    v65 = stack[-8];
    v65 = qcar(v65);
    stack[-1] = v65;
    v65 = stack[-8];
    v65 = qcdr(v65);
    stack[-8] = v65;
    v65 = (Lisp_Object)1; /* 0 */
    stack[-3] = v65;
    goto v71;

v71:
    v66 = stack[-7];
    v65 = stack[-1];
    v65 = Ldivide(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-4] = v65;
    v66 = qcdr(v65);
    v65 = (Lisp_Object)1; /* 0 */
    if (v66 == v65) goto v72;
    v66 = stack[-3];
    v65 = stack[-6];
    if (((int32_t)(v66)) < ((int32_t)(v65))) goto v73;
    v66 = stack[-3];
    v65 = stack[-6];
    v65 = Ldivide(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-3] = v65;
    v66 = stack[-1];
    v65 = stack[-3];
    v65 = qcar(v65);
    v65 = Lexpt(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    v65 = times2(stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[0] = v65;
    v65 = stack[-3];
    v65 = qcdr(v65);
    stack[-3] = v65;
    goto v73;

v73:
    v66 = stack[-3];
    v65 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v66)) > ((int32_t)(v65))) goto v74;
    v65 = stack[-4];
    v66 = qcar(v65);
    v65 = stack[-1];
    v65 = (Lisp_Object)lessp2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v65 = v65 ? lisp_true : nil;
    env = stack[-9];
    if (v65 == nil) goto v75;
    v66 = stack[-7];
    v65 = stack[-2];
    v65 = times2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-2] = v65;
    goto v76;

v76:
    v65 = stack[-5];
    if (v65 == nil) goto v77;
    v65 = stack[-2];
    v65 = negate(v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    stack[-2] = v65;
    goto v77;

v77:
    v66 = stack[0];
    v65 = stack[-2];
    popv(10);
    return cons(v66, v65);

v75:
    v65 = stack[-8];
    if (!(v65 == nil)) goto v70;
    v66 = (Lisp_Object)161; /* 10 */
    v65 = (Lisp_Object)321; /* 20 */
    v66 = Lexpt(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    v65 = stack[-7];
    v65 = (Lisp_Object)greaterp2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v65 = v65 ? lisp_true : nil;
    env = stack[-9];
    if (v65 == nil) goto v78;
    v66 = stack[-7];
    v65 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* mcfactor!* */
    v65 = (*qfn2(fn))(qenv(fn), v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-3] = v65;
    v65 = stack[-3];
    stack[-4] = v65;
    goto v79;

v79:
    v65 = stack[-4];
    if (v65 == nil) goto v76;
    v65 = stack[-4];
    v65 = qcar(v65);
    stack[-1] = v65;
    v65 = stack[-1];
    v66 = qcdr(v65);
    v65 = stack[-6];
    v65 = Ldivide(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-3] = v65;
    v65 = stack[-1];
    v66 = qcar(v65);
    v65 = stack[-3];
    v65 = qcar(v65);
    v66 = Lexpt(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    v65 = stack[0];
    v65 = times2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[0] = v65;
    v65 = stack[-1];
    v66 = qcar(v65);
    v65 = stack[-3];
    v65 = qcdr(v65);
    v66 = Lexpt(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    v65 = stack[-2];
    v65 = times2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-2] = v65;
    v65 = stack[-4];
    v65 = qcdr(v65);
    stack[-4] = v65;
    goto v79;

v78:
    v66 = stack[-7];
    v65 = stack[-6];
    fn = elt(env, 5); /* irootn */
    v65 = (*qfn2(fn))(qenv(fn), v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-1] = v65;
    v66 = stack[-1];
    v65 = stack[-6];
    v66 = Lexpt(nil, v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    v65 = stack[-7];
    if (equal(v66, v65)) goto v80;
    v65 = qvalue(elt(env, 3)); /* nil */
    goto v81;

v81:
    stack[-3] = v65;
    if (v65 == nil) goto v82;
    v66 = stack[0];
    v65 = stack[-3];
    v65 = times2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[0] = v65;
    goto v76;

v82:
    v66 = stack[-7];
    v65 = stack[-2];
    v65 = times2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-2] = v65;
    goto v76;

v80:
    v65 = stack[-1];
    goto v81;

v74:
    v66 = stack[-2];
    v65 = stack[-1];
    v65 = times2(v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-9];
    stack[-2] = v65;
    v65 = stack[-3];
    v65 = (Lisp_Object)((int32_t)(v65) - 0x10);
    stack[-3] = v65;
    goto v73;

v72:
    v65 = stack[-4];
    v65 = qcar(v65);
    stack[-7] = v65;
    v65 = stack[-3];
    v65 = (Lisp_Object)((int32_t)(v65) + 0x10);
    stack[-3] = v65;
    goto v71;

v69:
    v65 = (Lisp_Object)-15; /* -1 */
    stack[0] = v65;
    goto v68;
/* error exit handlers */
v67:
    popv(10);
    return nil;
}



/* Code for vp2df */

static Lisp_Object MS_CDECL CC_vp2df(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp2df");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp2df");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v83;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v62 = stack[-2];
    v61 = elt(env, 1); /* sqrt */
    if (!consp(v62)) goto v96;
    v62 = qcar(v62);
    if (!(v62 == v61)) goto v96;
    v62 = stack[-1];
    v61 = (Lisp_Object)17; /* 1 */
    v61 = (Lisp_Object)greaterp2(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v97;
    v61 = v61 ? lisp_true : nil;
    env = stack[-3];
    if (v61 == nil) goto v96;
    v59 = stack[-2];
    v62 = stack[-1];
    v61 = stack[0];
    fn = elt(env, 2); /* vp1 */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v59, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v61 = stack[0];
    fn = elt(env, 3); /* vp2 */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    {
        Lisp_Object v98 = stack[-1];
        popv(4);
        fn = elt(env, 4); /* mulpower */
        return (*qfn2(fn))(qenv(fn), v98, v61);
    }

v96:
    v59 = stack[-2];
    v62 = stack[-1];
    v61 = stack[0];
    fn = elt(env, 2); /* vp1 */
    v59 = (*qfnn(fn))(qenv(fn), 3, v59, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v62 = (Lisp_Object)17; /* 1 */
    v61 = (Lisp_Object)17; /* 1 */
    v61 = list2star(v59, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v97;
    popv(4);
    return ncons(v61);
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for multtaylor!* */

static Lisp_Object MS_CDECL CC_multtaylorH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v107, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "multtaylor*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multtaylor*");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v83;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v58 = stack[-1];
    v108 = qcar(v58);
    v58 = stack[-3];
    v58 = qcdr(v58);
    v107 = qcar(v58);
    v58 = stack[-2];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    fn = elt(env, 4); /* multtaylor1 */
    v58 = (*qfnn(fn))(qenv(fn), 3, v108, v107, v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    stack[-4] = elt(env, 1); /* taylor!* */
    v107 = v58;
    stack[0] = qcdr(v107);
    v107 = stack[-1];
    v107 = qcar(v107);
    v58 = qcar(v58);
    fn = elt(env, 5); /* replace!-next */
    stack[-1] = (*qfn2(fn))(qenv(fn), v107, v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    v58 = qvalue(elt(env, 2)); /* !*taylorkeeporiginal */
    if (v58 == nil) goto v109;
    v58 = stack[-3];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    if (v58 == nil) goto v109;
    v58 = stack[-2];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    if (v58 == nil) goto v109;
    v58 = stack[-3];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v107 = qcar(v58);
    v58 = stack[-2];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    fn = elt(env, 6); /* multsq */
    v58 = (*qfn2(fn))(qenv(fn), v107, v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    v107 = v58;
    goto v110;

v110:
    v58 = qvalue(elt(env, 3)); /* nil */
    v58 = list2(v107, v58);
    nil = C_nil;
    if (exception_pending()) goto v56;
    {
        Lisp_Object v111 = stack[-4];
        Lisp_Object v112 = stack[0];
        Lisp_Object v113 = stack[-1];
        popv(6);
        return list3star(v111, v112, v113, v58);
    }

v109:
    v58 = qvalue(elt(env, 3)); /* nil */
    v107 = v58;
    goto v110;
/* error exit handlers */
v56:
    popv(6);
    return nil;
}



/* Code for mk!+inner!+mat */

static Lisp_Object CC_mkLinnerLmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+inner+mat");
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
    v124 = v0;
/* end of prologue */
    v124 = qcdr(v124);
    stack[-7] = v124;
    v124 = stack[-7];
    if (v124 == nil) goto v125;
    v124 = stack[-7];
    v124 = qcar(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v100;
    v124 = stack[-3];
    v124 = qcar(v124);
    fn = elt(env, 4); /* simp */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-1] = v124;
    stack[-2] = v124;
    goto v127;

v127:
    v124 = stack[-3];
    v124 = qcdr(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v128;
    stack[0] = stack[-1];
    v124 = stack[-3];
    v124 = qcar(v124);
    fn = elt(env, 4); /* simp */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = Lrplacd(nil, stack[0], v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-1] = v124;
    goto v127;

v128:
    v124 = stack[-2];
    goto v129;

v129:
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-5] = v124;
    stack[-6] = v124;
    goto v130;

v130:
    v124 = stack[-7];
    v124 = qcdr(v124);
    stack[-7] = v124;
    v124 = stack[-7];
    if (v124 == nil) goto v59;
    stack[-4] = stack[-5];
    v124 = stack[-7];
    v124 = qcar(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v55;
    v124 = stack[-3];
    v124 = qcar(v124);
    fn = elt(env, 4); /* simp */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-1] = v124;
    stack[-2] = v124;
    goto v131;

v131:
    v124 = stack[-3];
    v124 = qcdr(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v132;
    stack[0] = stack[-1];
    v124 = stack[-3];
    v124 = qcar(v124);
    fn = elt(env, 4); /* simp */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = Lrplacd(nil, stack[0], v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-1] = v124;
    goto v131;

v132:
    v124 = stack[-2];
    goto v108;

v108:
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = Lrplacd(nil, stack[-4], v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v124 = stack[-5];
    v124 = qcdr(v124);
    stack[-5] = v124;
    goto v130;

v55:
    v124 = qvalue(elt(env, 1)); /* nil */
    goto v108;

v59:
    v124 = stack[-6];
    goto v133;

v133:
    stack[0] = v124;
    v124 = stack[0];
    fn = elt(env, 5); /* matrix!+p */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    if (!(v124 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v124 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v124 == nil)) goto v134;
    v124 = elt(env, 3); /* "incorrect input in mkinnermat" */
    fn = elt(env, 6); /* lprie */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    goto v134;

v134:
    v124 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v124 = nil;
    { popv(9); return onevalue(v124); }

v100:
    v124 = qvalue(elt(env, 1)); /* nil */
    goto v129;

v125:
    v124 = qvalue(elt(env, 1)); /* nil */
    goto v133;
/* error exit handlers */
v126:
    popv(9);
    return nil;
}



/* Code for makevar */

static Lisp_Object CC_makevar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makevar");
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
    v76 = v0;
/* end of prologue */
    stack[-1] = Lexplode(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v76 = stack[0];
    v76 = Lexplode(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v76 = Lnconc(nil, stack[-1], v76);
    nil = C_nil;
    if (exception_pending()) goto v125;
        popv(3);
        return Lcompress(nil, v76);
/* error exit handlers */
v125:
    popv(3);
    return nil;
}



/* Code for ofsf_simpat */

static Lisp_Object CC_ofsf_simpat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v13, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_simpat");
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
    v20 = stack[-2];
    v20 = qcar(v20);
    stack[-3] = v20;
    v20 = stack[-2];
    v20 = qcdr(v20);
    v20 = qcar(v20);
    fn = elt(env, 10); /* simp */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[-1] = v20;
    v20 = qvalue(elt(env, 1)); /* !*rlnzden */
    if (!(v20 == nil)) goto v94;
    v20 = qvalue(elt(env, 2)); /* !*rlposden */
    if (!(v20 == nil)) goto v94;
    v20 = stack[-1];
    v20 = qcdr(v20);
    if (!consp(v20)) goto v94;
    v20 = stack[-1];
    v20 = qcdr(v20);
    v20 = qcar(v20);
    if (!consp(v20)) goto v94;
    v13 = stack[-2];
    v20 = elt(env, 3); /* "atomic formula" */
    fn = elt(env, 11); /* typerr */
    v20 = (*qfn2(fn))(qenv(fn), v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v94;

v94:
    v20 = stack[-2];
    v20 = qcdr(v20);
    v20 = qcdr(v20);
    v20 = qcar(v20);
    fn = elt(env, 10); /* simp */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[0] = v20;
    v20 = qvalue(elt(env, 1)); /* !*rlnzden */
    if (!(v20 == nil)) goto v98;
    v20 = qvalue(elt(env, 2)); /* !*rlposden */
    if (!(v20 == nil)) goto v98;
    v20 = stack[0];
    v20 = qcdr(v20);
    if (!consp(v20)) goto v98;
    v20 = stack[0];
    v20 = qcdr(v20);
    v20 = qcar(v20);
    if (!consp(v20)) goto v98;
    v13 = stack[-2];
    v20 = elt(env, 3); /* "atomic formula" */
    fn = elt(env, 11); /* typerr */
    v20 = (*qfn2(fn))(qenv(fn), v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v98;

v98:
    v20 = stack[0];
    v20 = qcar(v20);
    fn = elt(env, 12); /* negf */
    v13 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v20 = stack[0];
    v20 = qcdr(v20);
    v20 = cons(v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    fn = elt(env, 13); /* addsq */
    v20 = (*qfn2(fn))(qenv(fn), stack[-1], v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[-1] = v20;
    v20 = stack[-1];
    v20 = qcar(v20);
    v13 = v20;
    v20 = qvalue(elt(env, 2)); /* !*rlposden */
    if (v20 == nil) goto v107;
    v20 = stack[-1];
    v20 = qcdr(v20);
    if (!consp(v20)) goto v107;
    v20 = stack[-1];
    v20 = qcdr(v20);
    v20 = qcar(v20);
    if (!consp(v20)) goto v107;
    v161 = stack[-3];
    v20 = qvalue(elt(env, 4)); /* nil */
    v20 = list3(v161, v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[0] = v20;
    v20 = qvalue(elt(env, 5)); /* !*rladdcond */
    if (v20 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v13 = stack[-3];
    v20 = elt(env, 6); /* (lessp leq greaterp geq) */
    v20 = Lmemq(nil, v13, v20);
    if (v20 == nil) goto v163;
    stack[-2] = elt(env, 7); /* and */
    v161 = elt(env, 8); /* greaterp */
    v20 = stack[-1];
    v13 = qcdr(v20);
    v20 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = list3(v161, v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v20 = stack[0];
    v20 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v20 = list2star(stack[-2], stack[-1], v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    goto v116;

v116:
    stack[0] = v20;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v163:
    stack[-2] = elt(env, 7); /* and */
    v161 = elt(env, 9); /* neq */
    v20 = stack[-1];
    v13 = qcdr(v20);
    v20 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = list3(v161, v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v20 = stack[0];
    v20 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v20 = list2star(stack[-2], stack[-1], v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    goto v116;

v107:
    v20 = qvalue(elt(env, 1)); /* !*rlnzden */
    if (v20 == nil) goto v14;
    v20 = stack[-1];
    v20 = qcdr(v20);
    if (!consp(v20)) goto v14;
    v20 = stack[-1];
    v20 = qcdr(v20);
    v20 = qcar(v20);
    if (!consp(v20)) goto v14;
    v161 = stack[-3];
    v20 = elt(env, 6); /* (lessp leq greaterp geq) */
    v20 = Lmemq(nil, v161, v20);
    if (v20 == nil) goto v32;
    v20 = stack[-1];
    v20 = qcdr(v20);
    fn = elt(env, 14); /* multf */
    v20 = (*qfn2(fn))(qenv(fn), v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v13 = v20;
    goto v32;

v32:
    v161 = stack[-3];
    v20 = qvalue(elt(env, 4)); /* nil */
    v20 = list3(v161, v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[0] = v20;
    v20 = qvalue(elt(env, 5)); /* !*rladdcond */
    if (v20 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    stack[-2] = elt(env, 7); /* and */
    v161 = elt(env, 9); /* neq */
    v20 = stack[-1];
    v13 = qcdr(v20);
    v20 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = list3(v161, v13, v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v20 = stack[0];
    v20 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v20 = list2star(stack[-2], stack[-1], v20);
    nil = C_nil;
    if (exception_pending()) goto v162;
    stack[0] = v20;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v14:
    v20 = stack[-3];
    v161 = qvalue(elt(env, 4)); /* nil */
    popv(5);
    return list3(v20, v13, v161);
/* error exit handlers */
v162:
    popv(5);
    return nil;
}



/* Code for repr_new */

static Lisp_Object MS_CDECL CC_repr_new(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v110, v128, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "repr_new");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_new");
#endif
    if (stack >= stacklimit)
    {
        push4(v40,v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v83,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v165 = v40;
    v110 = v83;
    v128 = v1;
    v166 = v0;
/* end of prologue */
    stack[-3] = v166;
    stack[-2] = v128;
    stack[-1] = v110;
    stack[0] = v165;
    v165 = v110;
    if (v165 == nil) goto v122;
    v165 = v110;
    v165 = qcar(v165);
    v165 = qcdr(v165);
    goto v68;

v68:
    v165 = list2(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v167;
    {
        Lisp_Object v72 = stack[-3];
        Lisp_Object v86 = stack[-2];
        Lisp_Object v96 = stack[-1];
        popv(5);
        return list3star(v72, v86, v96, v165);
    }

v122:
    v165 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v165 == nil)) goto v99;
    v165 = elt(env, 2); /* "repr_new : invalid coefficient list" */
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    fn = elt(env, 3); /* lprie */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    goto v99;

v99:
    v165 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-4];
    v165 = nil;
    goto v68;
/* error exit handlers */
v167:
    popv(5);
    return nil;
}



/* Code for bc_minus!? */

static Lisp_Object CC_bc_minusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_minus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v6);
    }
}



/* Code for updkorder */

static Lisp_Object CC_updkorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v169, v91;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for updkorder");
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
    v169 = v0;
/* end of prologue */
    v160 = qvalue(elt(env, 1)); /* kord!* */
    stack[-1] = v160;
    stack[0] = v169;
    v160 = stack[-1];
    v160 = Ldelete(nil, v169, v160);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v160 = cons(stack[0], v160);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v91 = v160;
    v169 = stack[-1];
    v160 = v91;
    if (equal(v169, v160)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v160 = v91;
    qvalue(elt(env, 1)) = v160; /* kord!* */
    v160 = qvalue(elt(env, 2)); /* nil */
    v160 = ncons(v160);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    qvalue(elt(env, 3)) = v160; /* alglist!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for groebsimpcontnormalform */

static Lisp_Object CC_groebsimpcontnormalform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsimpcontnormalform");
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
    v173 = stack[-2];
    if (v173 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v173 = stack[-2];
    v173 = qcdr(v173);
    v173 = qcdr(v173);
    v173 = qcdr(v173);
    v173 = qcar(v173);
    if (v173 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v173 = stack[-2];
    fn = elt(env, 3); /* gsugar */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[0] = v173;
    v173 = stack[-2];
    v173 = qcdr(v173);
    v173 = qcdr(v173);
    v173 = qcar(v173);
    stack[-3] = v173;
    v173 = stack[-2];
    fn = elt(env, 4); /* vdpsimpcont */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[-2] = v173;
    v157 = stack[-2];
    v173 = stack[0];
    fn = elt(env, 5); /* gsetsugar */
    v173 = (*qfn2(fn))(qenv(fn), v157, v173);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v173 = qvalue(elt(env, 1)); /* !*groebprot */
    if (v173 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v157 = stack[-3];
    v173 = stack[-2];
    v173 = qcdr(v173);
    v173 = qcdr(v173);
    v173 = qcar(v173);
    if (equal(v157, v173)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-1] = elt(env, 2); /* quotient */
    v173 = stack[-2];
    v173 = qcdr(v173);
    v173 = qcdr(v173);
    v173 = qcar(v173);
    fn = elt(env, 6); /* vbc2a */
    stack[0] = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v173 = stack[-3];
    fn = elt(env, 6); /* vbc2a */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v173 = list3(stack[-1], stack[0], v173);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    fn = elt(env, 7); /* reval */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    fn = elt(env, 8); /* groebreductionprotocol2 */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v174;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
/* error exit handlers */
v174:
    popv(5);
    return nil;
}



/* Code for xreduce1 */

static Lisp_Object MS_CDECL CC_xreduce1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v169, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xreduce1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xreduce1");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v83;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v70;

v70:
    v91 = stack[-2];
    v169 = stack[-1];
    v160 = stack[0];
    fn = elt(env, 1); /* weak_xreduce1 */
    v160 = (*qfnn(fn))(qenv(fn), 3, v91, v169, v160);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-2] = v160;
    if (v160 == nil) goto v100;
    v160 = stack[-2];
    v169 = qcar(v160);
    v160 = stack[-3];
    v160 = cons(v169, v160);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v160;
    v160 = stack[-2];
    v160 = qcdr(v160);
    stack[-2] = v160;
    goto v70;

v100:
    v160 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v160);
    }
/* error exit handlers */
v175:
    popv(5);
    return nil;
}



/* Code for partitpartdf */

static Lisp_Object CC_partitpartdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitpartdf");
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
    v93 = v0;
/* end of prologue */
    v92 = v93;
    v92 = qcdr(v92);
    if (v92 == nil) goto v6;
    stack[0] = (Lisp_Object)17; /* 1 */
    v92 = v93;
    fn = elt(env, 1); /* simppartdf0 */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-1];
    v92 = cons(stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v122;
    popv(2);
    return ncons(v92);

v6:
    v92 = v93;
    v92 = qcar(v92);
    fn = elt(env, 2); /* !*a2k */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* mknatvec */
        return (*qfn1(fn))(qenv(fn), v92);
    }
/* error exit handlers */
v122:
    popv(2);
    return nil;
}



/* Code for mk!-strand!-vertex */

static Lisp_Object CC_mkKstrandKvertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-strand-vertex");
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
    v87 = v1;
    stack[-2] = v0;
/* end of prologue */
    v84 = stack[-2];
    v88 = v87;
    v87 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* incident */
    v87 = (*qfnn(fn))(qenv(fn), 3, v84, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v88 = v87;
    v87 = v88;
    v87 = qcar(v87);
    stack[-3] = v87;
    stack[-1] = stack[-2];
    v87 = v88;
    stack[0] = qcdr(v87);
    v87 = stack[-3];
    v87 = qcar(v87);
    v87 = qcdr(v87);
    v87 = add1(v87);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    fn = elt(env, 1); /* incident */
    v87 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v88 = v87;
    v87 = v88;
    if (v87 == nil) goto v89;
    v87 = v88;
    v87 = qcar(v87);
    goto v72;

v72:
    v84 = stack[-2];
    v88 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* mk!-strand!-vertex2 */
        return (*qfnn(fn))(qenv(fn), 3, v84, v88, v87);
    }

v89:
    v88 = stack[-2];
    v87 = (Lisp_Object)1; /* 0 */
    v87 = cons(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v87 = ncons(v87);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    goto v72;
/* error exit handlers */
v60:
    popv(5);
    return nil;
}



/* Code for split!-wrt!-variables */

static Lisp_Object MS_CDECL CC_splitKwrtKvariables(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v109, v158;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-wrt-variables");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-wrt-variables");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v83;
    stack[-1] = v1;
    v109 = v0;
/* end of prologue */

v5:
    v104 = v109;
    if (v104 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v104 = stack[0];
    if (v104 == nil) goto v95;
    v104 = stack[0];
    v158 = qcar(v104);
    v104 = (Lisp_Object)17; /* 1 */
    if (v158 == v104) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else goto v95;

v95:
    v104 = v109;
    if (!consp(v104)) goto v172;
    v104 = v109;
    v104 = qcar(v104);
    if (!consp(v104)) goto v172;
    v104 = v109;
    v104 = qcar(v104);
    v104 = qcar(v104);
    v158 = qcar(v104);
    v104 = stack[-1];
    v104 = Lmember(nil, v158, v104);
    if (v104 == nil) goto v103;
    v104 = v109;
    v104 = qcdr(v104);
    stack[-2] = v104;
    v104 = v109;
    v104 = qcar(v104);
    v158 = qcdr(v104);
    v109 = stack[-1];
    v104 = stack[0];
    v104 = CC_splitKwrtKvariables(env, 3, v158, v109, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-3];
    stack[0] = v104;
    v104 = stack[-2];
    v109 = v104;
    goto v5;

v103:
    v104 = stack[0];
    popv(4);
    return cons(v109, v104);

v172:
    v104 = v109;
    v109 = Labsval(nil, v104);
    nil = C_nil;
    if (exception_pending()) goto v107;
    v104 = stack[0];
    popv(4);
    return cons(v109, v104);
/* error exit handlers */
v107:
    popv(4);
    return nil;
}



/* Code for pst_equitable */

static Lisp_Object CC_pst_equitable(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_equitable");
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
    v131 = v0;
/* end of prologue */
    v108 = v131;
    v108 = qcdr(v108);
    if (v108 == nil) { popv(4); return onevalue(v131); }
    v108 = v131;
    v108 = qcar(v108);
    stack[-1] = v108;
    v108 = v131;
    v108 = qcdr(v108);
    fn = elt(env, 1); /* pst_reduce */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v108;
    stack[0] = stack[-2];
    v131 = stack[-1];
    v108 = stack[-2];
    v108 = qcar(v108);
    v108 = Lappend(nil, v131, v108);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v108 = Lrplaca(nil, stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    goto v159;

v159:
    v108 = stack[-2];
    v108 = qcar(v108);
    stack[-1] = v108;
    stack[0] = stack[-1];
    v131 = stack[-1];
    v108 = stack[-2];
    v108 = qcdr(v108);
    fn = elt(env, 2); /* pst_equitable1 */
    v108 = (*qfn2(fn))(qenv(fn), v131, v108);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v108 = cons(stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v108;
    v108 = stack[-2];
    v108 = qcdr(v108);
    fn = elt(env, 1); /* pst_reduce */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[0] = v108;
    v108 = stack[0];
    v108 = qcar(v108);
    if (v108 == nil) goto v179;
    v131 = stack[-1];
    v108 = stack[0];
    v108 = qcar(v108);
    v131 = Lappend(nil, v131, v108);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v108 = stack[0];
    v108 = qcdr(v108);
    v108 = cons(v131, v108);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v108;
    goto v179;

v179:
    v108 = stack[0];
    v108 = qcar(v108);
    stack[0] = v108;
    v108 = stack[0];
    if (v108 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    else goto v159;
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for eval_uni_poly_q */

static Lisp_Object CC_eval_uni_poly_q(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v188, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eval_uni_poly_q");
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
    v187 = stack[-2];
    if (!consp(v187)) goto v45;
    v187 = stack[-2];
    v187 = qcar(v187);
    v188 = qcdr(v187);
    v187 = (Lisp_Object)17; /* 1 */
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    v189 = v187;
    v187 = stack[-2];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v187 = qcdr(v187);
    v188 = v187;
    v187 = stack[-2];
    v187 = qcdr(v187);
    stack[-2] = v187;
    goto v91;

v91:
    v187 = stack[-2];
    if (!consp(v187)) goto v191;
    stack[-3] = v189;
    stack[0] = stack[-1];
    v187 = stack[-2];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v187 = qcdr(v187);
    v187 = difference2(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    fn = elt(env, 2); /* exptsq */
    v187 = (*qfn2(fn))(qenv(fn), stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    v187 = stack[-2];
    v187 = qcar(v187);
    v188 = qcdr(v187);
    v187 = (Lisp_Object)17; /* 1 */
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    v187 = (*qfn2(fn))(qenv(fn), stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    v189 = v187;
    v187 = stack[-2];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v187 = qcdr(v187);
    v188 = v187;
    v187 = stack[-2];
    v187 = qcdr(v187);
    stack[-2] = v187;
    goto v91;

v191:
    stack[0] = v189;
    v187 = stack[-1];
    fn = elt(env, 2); /* exptsq */
    v187 = (*qfn2(fn))(qenv(fn), v187, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    v188 = stack[-2];
    v187 = (Lisp_Object)17; /* 1 */
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-4];
    {
        Lisp_Object v74 = stack[0];
        popv(5);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v74, v187);
    }

v45:
    v188 = stack[-2];
    v187 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v188, v187);
/* error exit handlers */
v190:
    popv(5);
    return nil;
}



/* Code for checkcoeffts */

static Lisp_Object CC_checkcoeffts(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkcoeffts");
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

v194:
    v102 = stack[-1];
    if (v102 == nil) goto v46;
    v102 = stack[-1];
    v102 = qcar(v102);
    v193 = qcar(v102);
    v102 = stack[0];
    fn = elt(env, 3); /* evaluatecoeffts */
    v102 = (*qfn2(fn))(qenv(fn), v193, v102);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-2];
    v193 = v102;
    v102 = v193;
    if (v102 == nil) goto v69;
    v102 = (Lisp_Object)1; /* 0 */
    if (v193 == v102) goto v69;
    v102 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v102); }

v69:
    v102 = stack[-1];
    v193 = qcdr(v102);
    v102 = stack[0];
    stack[-1] = v193;
    stack[0] = v102;
    goto v194;

v46:
    v102 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v102); }
/* error exit handlers */
v167:
    popv(3);
    return nil;
}



/* Code for addto!-all!-taytpelorders */

static Lisp_Object CC_addtoKallKtaytpelorders(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addto-all-taytpelorders");
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
    goto v25;

v25:
    v59 = stack[-4];
    if (v59 == nil) goto v45;
    v59 = stack[-4];
    v59 = qcar(v59);
    stack[-2] = qcar(v59);
    v59 = stack[-4];
    v59 = qcar(v59);
    v59 = qcdr(v59);
    stack[-1] = qcar(v59);
    v59 = stack[-4];
    v59 = qcar(v59);
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    v60 = qcar(v59);
    v59 = stack[-3];
    v59 = qcar(v59);
    fn = elt(env, 1); /* tayexp!-plus2 */
    stack[0] = (*qfn2(fn))(qenv(fn), v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v59 = stack[-4];
    v59 = qcar(v59);
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    v60 = qcar(v59);
    v59 = stack[-3];
    v59 = qcar(v59);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v59 = (*qfn2(fn))(qenv(fn), v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v60 = list4(stack[-2], stack[-1], stack[0], v59);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v59 = stack[-5];
    v59 = cons(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[-5] = v59;
    v59 = stack[-4];
    v59 = qcdr(v59);
    stack[-4] = v59;
    v59 = stack[-3];
    v59 = qcdr(v59);
    stack[-3] = v59;
    goto v25;

v45:
    v59 = stack[-5];
    {
        popv(7);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v59);
    }
/* error exit handlers */
v174:
    popv(7);
    return nil;
}



/* Code for ratpoly_toaf */

static Lisp_Object CC_ratpoly_toaf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_toaf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v0;
/* end of prologue */
    v106 = v105;
    v106 = qcar(v106);
    if (v106 == nil) goto v6;
    v106 = elt(env, 1); /* prepf */
    {
        fn = elt(env, 2); /* sqform */
        return (*qfn2(fn))(qenv(fn), v105, v106);
    }

v6:
    v106 = (Lisp_Object)1; /* 0 */
    return onevalue(v106);
}



/* Code for formopr */

static Lisp_Object MS_CDECL CC_formopr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v128, v166, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formopr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formopr");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v110 = v83;
    v166 = v1;
    v102 = v0;
/* end of prologue */
    v128 = v110;
    v110 = elt(env, 1); /* symbolic */
    if (v128 == v110) goto v94;
    stack[0] = elt(env, 4); /* operator */
    v110 = v102;
    v110 = qcdr(v110);
    v128 = v166;
    fn = elt(env, 5); /* mkarg */
    v110 = (*qfn2(fn))(qenv(fn), v110, v128);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v167 = stack[0];
        popv(3);
        return list2(v167, v110);
    }

v94:
    stack[-1] = elt(env, 2); /* flag */
    v110 = v102;
    v110 = qcdr(v110);
    stack[0] = Lmkquote(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v110 = elt(env, 3); /* opfn */
    v110 = Lmkquote(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v72 = stack[-1];
        Lisp_Object v86 = stack[0];
        popv(3);
        return list3(v72, v86, v110);
    }
/* error exit handlers */
v170:
    popv(3);
    return nil;
}



/* Code for spmake_identity */

static Lisp_Object CC_spmake_identity(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v57, v58, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmake_identity");
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
    v118 = qvalue(elt(env, 1)); /* !*fast_la */
    if (!(v118 == nil)) goto v93;
    v118 = stack[-1];
    v118 = integerp(v118);
    if (!(v118 == nil)) goto v93;
    v118 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v118 == nil)) goto v125;
    v118 = elt(env, 3); /* "Error in spmake_identity: non integer input." 
*/
    fn = elt(env, 7); /* lprie */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    goto v125;

v125:
    v118 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    goto v93;

v93:
    stack[-2] = elt(env, 4); /* sparsemat */
    v118 = stack[-1];
    stack[0] = Lmkvect(nil, v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    v58 = elt(env, 5); /* spm */
    v57 = stack[-1];
    v118 = stack[-1];
    v118 = list3(v58, v57, v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    v118 = list3(stack[-2], stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    stack[0] = v118;
    v118 = stack[-1];
    stack[-1] = v118;
    goto v166;

v166:
    v118 = stack[-1];
    v118 = sub1(v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    v118 = Lminusp(nil, v118);
    env = stack[-3];
    if (!(v118 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v58 = stack[0];
    v57 = stack[-1];
    v118 = stack[-1];
    v107 = list3(v58, v57, v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    v58 = (Lisp_Object)17; /* 1 */
    v57 = stack[0];
    v118 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 8); /* letmtr3 */
    v118 = (*qfnn(fn))(qenv(fn), 4, v107, v58, v57, v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    v118 = stack[-1];
    v118 = sub1(v118);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-3];
    stack[-1] = v118;
    goto v166;
/* error exit handlers */
v197:
    popv(4);
    return nil;
}



/* Code for gbfquot */

static Lisp_Object CC_gbfquot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v185, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbfquot");
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
    v185 = v1;
    v186 = v0;
/* end of prologue */
    v54 = v186;
    v54 = qcar(v54);
    stack[-5] = v54;
    v54 = v186;
    v54 = qcdr(v54);
    stack[-4] = v54;
    v54 = v185;
    v54 = qcar(v54);
    stack[-3] = v54;
    v54 = v185;
    v54 = qcdr(v54);
    stack[-2] = v54;
    v185 = stack[-3];
    v54 = stack[-3];
    fn = elt(env, 2); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v185, v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v185 = stack[-2];
    v54 = stack[-2];
    fn = elt(env, 2); /* csl_timbf */
    v54 = (*qfn2(fn))(qenv(fn), v185, v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 3); /* plubf */
    v54 = (*qfn2(fn))(qenv(fn), stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-1] = v54;
    v185 = stack[-5];
    v54 = stack[-3];
    fn = elt(env, 2); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v185, v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v185 = stack[-4];
    v54 = stack[-2];
    fn = elt(env, 2); /* csl_timbf */
    v54 = (*qfn2(fn))(qenv(fn), v185, v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 3); /* plubf */
    v186 = (*qfn2(fn))(qenv(fn), stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v185 = stack[-1];
    v54 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 4); /* divide!: */
    v54 = (*qfnn(fn))(qenv(fn), 3, v186, v185, v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 5); /* csl_normbf */
    stack[0] = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v185 = stack[-4];
    v54 = stack[-3];
    fn = elt(env, 2); /* csl_timbf */
    stack[-3] = (*qfn2(fn))(qenv(fn), v185, v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v185 = stack[-5];
    v54 = stack[-2];
    fn = elt(env, 2); /* csl_timbf */
    v54 = (*qfn2(fn))(qenv(fn), v185, v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 6); /* difbf */
    v186 = (*qfn2(fn))(qenv(fn), stack[-3], v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v185 = stack[-1];
    v54 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 4); /* divide!: */
    v54 = (*qfnn(fn))(qenv(fn), 3, v186, v185, v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 5); /* csl_normbf */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v182;
    {
        Lisp_Object v73 = stack[0];
        popv(7);
        return cons(v73, v54);
    }
/* error exit handlers */
v182:
    popv(7);
    return nil;
}



/* Code for physop!*sq */

static Lisp_Object CC_physopHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physop*sq");
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
    v119 = qvalue(elt(env, 1)); /* !*nosq */
    if (v119 == nil) goto v4;
    v119 = v129;
    v119 = qcar(v119);
    fn = elt(env, 4); /* prepsqxx */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    goto v5;

v5:
    fn = elt(env, 5); /* !*collectphysops */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    if (v119 == nil) goto v168;
    v119 = elt(env, 3); /* physop */
    { popv(1); return onevalue(v119); }

v168:
    v119 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v119); }

v4:
    v119 = v129;
    v119 = qcar(v119);
    fn = elt(env, 6); /* mk!*sq */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    goto v5;
/* error exit handlers */
v127:
    popv(1);
    return nil;
}



/* Code for mk!-coeff1 */

static Lisp_Object CC_mkKcoeff1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-coeff1");
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
    v103 = v0;
/* end of prologue */
    v178 = v103;
    if (v178 == nil) goto v46;
    stack[-5] = elt(env, 1); /* times */
    v178 = v103;
    stack[-3] = v178;
    v178 = stack[-3];
    if (v178 == nil) goto v119;
    v178 = stack[-3];
    v178 = qcar(v178);
    v103 = qcar(v178);
    v178 = stack[-4];
    fn = elt(env, 3); /* getroad */
    v178 = (*qfn2(fn))(qenv(fn), v103, v178);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-6];
    fn = elt(env, 4); /* factorial */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-6];
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-6];
    stack[-1] = v178;
    stack[-2] = v178;
    goto v92;

v92:
    v178 = stack[-3];
    v178 = qcdr(v178);
    stack[-3] = v178;
    v178 = stack[-3];
    if (v178 == nil) goto v102;
    stack[0] = stack[-1];
    v178 = stack[-3];
    v178 = qcar(v178);
    v103 = qcar(v178);
    v178 = stack[-4];
    fn = elt(env, 3); /* getroad */
    v178 = (*qfn2(fn))(qenv(fn), v103, v178);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-6];
    fn = elt(env, 4); /* factorial */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-6];
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-6];
    v178 = Lrplacd(nil, stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-6];
    v178 = stack[-1];
    v178 = qcdr(v178);
    stack[-1] = v178;
    goto v92;

v102:
    v178 = stack[-2];
    goto v94;

v94:
    v178 = cons(stack[-5], v178);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 5); /* eval */
        return (*qfn1(fn))(qenv(fn), v178);
    }

v119:
    v178 = qvalue(elt(env, 2)); /* nil */
    goto v94;

v46:
    v178 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v178); }
/* error exit handlers */
v158:
    popv(7);
    return nil;
}



/* Code for put!-kvalue */

static Lisp_Object MS_CDECL CC_putKkvalue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v199, v51, v52, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "put-kvalue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for put-kvalue");
#endif
    if (stack >= stacklimit)
    {
        push4(v40,v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v83,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v40;
    stack[-2] = v83;
    stack[-3] = v1;
    stack[0] = v0;
/* end of prologue */
    v199 = stack[-1];
    v191 = elt(env, 1); /* !*sq */
    if (!consp(v199)) goto v166;
    v199 = qcar(v199);
    if (!(v199 == v191)) goto v166;
    v199 = stack[-2];
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = qcar(v191);
    v191 = qcar(v191);
    fn = elt(env, 6); /* sf_member */
    v191 = (*qfn2(fn))(qenv(fn), v199, v191);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    if (!(v191 == nil)) goto v11;
    v199 = stack[-2];
    v191 = stack[-1];
    v191 = qcdr(v191);
    v191 = qcar(v191);
    v191 = qcdr(v191);
    fn = elt(env, 6); /* sf_member */
    v191 = (*qfn2(fn))(qenv(fn), v199, v191);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    goto v11;

v11:
    if (v191 == nil) goto v98;
    v203 = qvalue(elt(env, 2)); /* nil */
    v52 = stack[-2];
    v51 = elt(env, 3); /* "improperly defined in terms of itself" */
    v199 = qvalue(elt(env, 2)); /* nil */
    v191 = qvalue(elt(env, 4)); /* t */
    {
        popv(6);
        fn = elt(env, 7); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v203, v52, v51, v199, v191);
    }

v98:
    stack[-4] = stack[0];
    stack[0] = elt(env, 5); /* kvalue */
    v199 = stack[-2];
    v191 = stack[-1];
    v191 = list2(v199, v191);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v191 = Lnconc(nil, stack[-3], v191);
    nil = C_nil;
    if (exception_pending()) goto v156;
    {
        Lisp_Object v54 = stack[-4];
        Lisp_Object v185 = stack[0];
        popv(6);
        return Lputprop(nil, 3, v54, v185, v191);
    }

v166:
    v199 = stack[-2];
    v191 = stack[-1];
    fn = elt(env, 8); /* smember */
    v191 = (*qfn2(fn))(qenv(fn), v199, v191);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    goto v11;
/* error exit handlers */
v156:
    popv(6);
    return nil;
}



/* Code for ofsf_chsimpat1 */

static Lisp_Object CC_ofsf_chsimpat1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v107, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_chsimpat1");
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
    stack[0] = nil;
    stack[-3] = nil;
    v58 = stack[-2];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    stack[-1] = v58;
    v58 = stack[-1];
    v58 = Lconsp(nil, v58);
    env = stack[-4];
    if (v58 == nil) goto v130;
    v58 = stack[-1];
    v107 = qcar(v58);
    v58 = elt(env, 1); /* (lessp leq equal neq geq greaterp) */
    v58 = Lmemq(nil, v107, v58);
    if (v58 == nil) goto v130;
    v58 = stack[-1];
    v58 = CC_ofsf_chsimpat1(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[0] = v58;
    v58 = stack[0];
    fn = elt(env, 2); /* lastcar */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    stack[-1] = v58;
    goto v130;

v130:
    v58 = stack[-2];
    v58 = qcdr(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v107 = v58;
    v107 = Lconsp(nil, v107);
    env = stack[-4];
    if (v107 == nil) goto v98;
    v107 = v58;
    v108 = qcar(v107);
    v107 = elt(env, 1); /* (lessp leq equal neq geq greaterp) */
    v107 = Lmemq(nil, v108, v107);
    if (v107 == nil) goto v98;
    v58 = CC_ofsf_chsimpat1(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[-3] = v58;
    v58 = stack[-3];
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    goto v98;

v98:
    v107 = stack[-2];
    v108 = qcar(v107);
    v107 = stack[-1];
    v107 = list3(v108, v107, v58);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    v58 = stack[-3];
    v58 = cons(v107, v58);
    nil = C_nil;
    if (exception_pending()) goto v55;
    {
        Lisp_Object v56 = stack[0];
        popv(5);
        return Lnconc(nil, v56, v58);
    }
/* error exit handlers */
v55:
    popv(5);
    return nil;
}



/* Code for preptaycoeff */

static Lisp_Object CC_preptaycoeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v187, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaycoeff");
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
    stack[-6] = nil;
    goto v4;

v4:
    v73 = stack[-4];
    if (v73 == nil) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v73 = stack[-5];
    v73 = qcar(v73);
    stack[-3] = v73;
    v73 = stack[-4];
    v73 = qcar(v73);
    v73 = qcar(v73);
    stack[-2] = v73;
    goto v192;

v192:
    v73 = stack[-2];
    if (v73 == nil) goto v68;
    v73 = stack[-2];
    v73 = qcar(v73);
    v188 = v73;
    v73 = stack[-4];
    v73 = qcar(v73);
    v73 = qcdr(v73);
    v187 = qcar(v73);
    v73 = elt(env, 2); /* infinity */
    if (v187 == v73) goto v179;
    stack[0] = v188;
    v73 = stack[-4];
    v73 = qcar(v73);
    v73 = qcdr(v73);
    v73 = qcar(v73);
    fn = elt(env, 4); /* reval */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-7];
    fn = elt(env, 5); /* checkdifference */
    v187 = (*qfn2(fn))(qenv(fn), stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-7];
    v73 = stack[-3];
    v73 = qcar(v73);
    fn = elt(env, 6); /* checkexp */
    v73 = (*qfn2(fn))(qenv(fn), v187, v73);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-7];
    v187 = v73;
    goto v169;

v169:
    v73 = stack[-6];
    v73 = cons(v187, v73);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-7];
    stack[-6] = v73;
    v73 = stack[-3];
    v73 = qcdr(v73);
    stack[-3] = v73;
    v73 = stack[-2];
    v73 = qcdr(v73);
    stack[-2] = v73;
    goto v192;

v179:
    v73 = stack[-3];
    v187 = qcar(v73);
    v73 = (Lisp_Object)1; /* 0 */
    if (v187 == v73) goto v120;
    stack[-1] = elt(env, 3); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v187 = v188;
    v73 = stack[-3];
    v73 = qcar(v73);
    fn = elt(env, 6); /* checkexp */
    v73 = (*qfn2(fn))(qenv(fn), v187, v73);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-7];
    v73 = list3(stack[-1], stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-7];
    goto v96;

v96:
    v187 = v73;
    goto v169;

v120:
    v73 = (Lisp_Object)17; /* 1 */
    goto v96;

v68:
    v73 = stack[-5];
    v73 = qcdr(v73);
    stack[-5] = v73;
    v73 = stack[-4];
    v73 = qcdr(v73);
    stack[-4] = v73;
    goto v4;
/* error exit handlers */
v204:
    popv(8);
    return nil;
}



/* Code for preptaylor!*!* */

static Lisp_Object CC_preptaylorHH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor**");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v0;
/* end of prologue */
    v130 = qvalue(elt(env, 1)); /* convert!-taylor!* */
    if (v130 == nil) return onevalue(v70);
    v130 = v70;
    {
        fn = elt(env, 2); /* preptaylor!* */
        return (*qfn1(fn))(qenv(fn), v130);
    }
}



/* Code for change!+sq!+to!+int */

static Lisp_Object CC_changeLsqLtoLint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v102, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for change+sq+to+int");
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
    v102 = v0;
/* end of prologue */
    v166 = v102;
    v166 = qcar(v166);
    if (v166 == nil) goto v4;
    v166 = elt(env, 1); /* prepf */
    fn = elt(env, 4); /* sqform */
    v166 = (*qfn2(fn))(qenv(fn), v102, v166);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[0];
    goto v5;

v5:
    fn = elt(env, 5); /* simp!* */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[0];
    v193 = v166;
    v166 = v193;
    v102 = qcdr(v166);
    v166 = (Lisp_Object)17; /* 1 */
    if (v102 == v166) goto v93;
    v166 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v166 == nil)) goto v69;
    v166 = elt(env, 3); /* "no integer in change!+sq!+to!+int" */
    fn = elt(env, 6); /* lprie */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[0];
    goto v69;

v69:
    v166 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v166 = nil;
    { popv(1); return onevalue(v166); }

v93:
    v166 = v193;
    v166 = qcar(v166);
    { popv(1); return onevalue(v166); }

v4:
    v166 = (Lisp_Object)1; /* 0 */
    goto v5;
/* error exit handlers */
v195:
    popv(1);
    return nil;
}



/* Code for iv_cutn */

static Lisp_Object CC_iv_cutn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iv_cutn");
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
    v92 = v0;
/* end of prologue */
    v192 = v92;
    v192 = qcdr(v192);
    if (v192 == nil) goto v106;
    v192 = v92;
    stack[0] = qcar(v192);
    v192 = v92;
    v192 = qcdr(v192);
    v192 = CC_iv_cutn(env, v192);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-1];
    {
        Lisp_Object v122 = stack[0];
        popv(2);
        fn = elt(env, 1); /* iv_cut */
        return (*qfn2(fn))(qenv(fn), v122, v192);
    }

v106:
    v192 = v92;
    v192 = qcar(v192);
    { popv(2); return onevalue(v192); }
/* error exit handlers */
v123:
    popv(2);
    return nil;
}



/* Code for ratpoly_univarp */

static Lisp_Object CC_ratpoly_univarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_univarp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v0;
/* end of prologue */
    v46 = qcar(v46);
    {
        fn = elt(env, 1); /* sf_univarp */
        return (*qfn1(fn))(qenv(fn), v46);
    }
}



/* Code for subeval */

static Lisp_Object CC_subeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v178, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval");
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
    stack[-2] = qvalue(elt(env, 1)); /* sublist!* */
    qvalue(elt(env, 1)) = nil; /* sublist!* */
    v103 = elt(env, 2); /* sub */
    v178 = elt(env, 3); /* psopfn */
    v98 = elt(env, 4); /* subeval0 */
    v98 = Lputprop(nil, 3, v103, v178, v98);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    stack[0] = elt(env, 4); /* subeval0 */
    v98 = stack[-1];
    v98 = Lmkquote(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v98 = list2(stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    fn = elt(env, 7); /* errorset2 */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    stack[0] = v98;
    v103 = elt(env, 2); /* sub */
    v178 = elt(env, 3); /* psopfn */
    v98 = elt(env, 0); /* subeval */
    v98 = Lputprop(nil, 3, v103, v178, v98);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    v98 = stack[0];
    if (!consp(v98)) goto v91;
    v98 = stack[0];
    v98 = qcdr(v98);
    if (!(v98 == nil)) goto v91;

v169:
    v98 = stack[0];
    v98 = qcar(v98);
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    { popv(4); return onevalue(v98); }

v91:
    v98 = qvalue(elt(env, 5)); /* errmsg!* */
    if (v98 == nil) goto v176;
    v98 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v98 == nil)) goto v72;
    v98 = qvalue(elt(env, 5)); /* errmsg!* */
    fn = elt(env, 8); /* lprie */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    goto v72;

v72:
    v98 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    goto v169;

v176:
    v98 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v98 == nil)) goto v84;
    v98 = elt(env, 2); /* sub */
    fn = elt(env, 8); /* lprie */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    goto v84;

v84:
    v98 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-3];
    goto v169;
/* error exit handlers */
v115:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    popv(4);
    return nil;
}



/* Code for tvectorp */

static Lisp_Object CC_tvectorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tvectorp");
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
    v192 = v0;
/* end of prologue */
    v192 = qcar(v192);
    v192 = qcar(v192);
    fn = elt(env, 2); /* deg!*form */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[0];
    v92 = v192;
    v192 = v92;
    if (is_number(v192)) goto v164;
    v192 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v192); }

v164:
    v192 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v92, v192);
/* error exit handlers */
v93:
    popv(1);
    return nil;
}



/* Code for propagator */

static Lisp_Object CC_propagator(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for propagator");
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
    v169 = stack[-1];
    if (v169 == nil) goto v46;
    v169 = stack[-1];
    fn = elt(env, 2); /* repeatsp */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-3];
    if (!(v169 == nil)) goto v45;
    v169 = stack[0];
    fn = elt(env, 2); /* repeatsp */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-3];
    if (!(v169 == nil)) goto v45;
    stack[-2] = elt(env, 1); /* plus */
    v169 = stack[0];
    fn = elt(env, 3); /* permutations */
    v91 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-3];
    v169 = stack[0];
    fn = elt(env, 4); /* propag */
    v169 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v91, v169);
    nil = C_nil;
    if (exception_pending()) goto v101;
    {
        Lisp_Object v175 = stack[-2];
        popv(4);
        return cons(v175, v169);
    }

v45:
    v169 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v169); }

v46:
    v169 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v169); }
/* error exit handlers */
v101:
    popv(4);
    return nil;
}



/* Code for dp_content */

static Lisp_Object CC_dp_content(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_content");
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
    v89 = stack[0];
    if (v89 == nil) goto v6;
    v89 = stack[0];
    fn = elt(env, 2); /* dp_lc */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    stack[-1] = v89;
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v105;

v105:
    v89 = stack[0];
    if (v89 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v89 = stack[-1];
    fn = elt(env, 3); /* bc_inv */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    if (!(v89 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v89 = stack[0];
    fn = elt(env, 2); /* dp_lc */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    fn = elt(env, 4); /* bc_gcd */
    v89 = (*qfn2(fn))(qenv(fn), stack[-1], v89);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    stack[-1] = v89;
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v105;

v6:
    v89 = (Lisp_Object)1; /* 0 */
    {
        popv(3);
        fn = elt(env, 5); /* bc_fi */
        return (*qfn1(fn))(qenv(fn), v89);
    }
/* error exit handlers */
v165:
    popv(3);
    return nil;
}



/* Code for lexorder */

static Lisp_Object CC_lexorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lexorder");
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
    v176 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = v176;
    goto v45;

v45:
    v176 = stack[-3];
    if (v176 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v176 = stack[-3];
    v176 = qcar(v176);
    stack[-2] = v176;
    stack[-1] = qvalue(elt(env, 2)); /* gv */
    v176 = stack[-2];
    stack[0] = qcar(v176);
    v177 = qvalue(elt(env, 2)); /* gv */
    v176 = stack[-2];
    v176 = qcar(v176);
    v176 = *(Lisp_Object *)((char *)v177 + (CELL-TAG_VECTOR) + ((int32_t)v176/(16/CELL)));
    fn = elt(env, 3); /* !*g2lex */
    v176 = (*qfn1(fn))(qenv(fn), v176);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    fn = elt(env, 4); /* gcdout */
    v176 = (*qfn1(fn))(qenv(fn), v176);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v176;
    fn = elt(env, 5); /* ljet */
    v176 = (*qfn1(fn))(qenv(fn), v176);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    v177 = stack[-2];
    v177 = qcar(v177);
    v177 = cons(v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    v176 = stack[-4];
    fn = elt(env, 6); /* insert */
    v176 = (*qfn2(fn))(qenv(fn), v177, v176);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-5];
    stack[-4] = v176;
    v176 = stack[-3];
    v176 = qcdr(v176);
    stack[-3] = v176;
    goto v45;
/* error exit handlers */
v61:
    popv(6);
    return nil;
}



/* Code for spreadvar */

static Lisp_Object MS_CDECL CC_spreadvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v97, v98;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spreadvar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spreadvar");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v97 = v83;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v5:
    v157 = stack[-1];
    if (!consp(v157)) { popv(4); return onevalue(v97); }
    v157 = stack[-1];
    v157 = qcar(v157);
    if (!consp(v157)) { popv(4); return onevalue(v97); }
    v157 = stack[-1];
    v157 = qcar(v157);
    v157 = qcar(v157);
    v98 = qcar(v157);
    v157 = stack[0];
    if (!(equal(v98, v157))) goto v168;
    v157 = stack[-1];
    v157 = qcar(v157);
    v157 = qcar(v157);
    v98 = qcdr(v157);
    v157 = v97;
    v157 = Lmember(nil, v98, v157);
    if (!(v157 == nil)) goto v168;
    v157 = stack[-1];
    v157 = qcar(v157);
    v157 = qcar(v157);
    v157 = qcdr(v157);
    v157 = cons(v157, v97);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v97 = v157;
    goto v168;

v168:
    v157 = stack[-1];
    v157 = qcdr(v157);
    stack[-2] = v157;
    v157 = stack[-1];
    v157 = qcar(v157);
    v98 = qcdr(v157);
    v157 = stack[0];
    v157 = CC_spreadvar(env, 3, v98, v157, v97);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v97 = v157;
    v157 = stack[-2];
    stack[-1] = v157;
    goto v5;
/* error exit handlers */
v196:
    popv(4);
    return nil;
}



/* Code for crzchk */

static Lisp_Object MS_CDECL CC_crzchk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v200, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "crzchk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crzchk");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v83;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v184 = stack[-2];
    v184 = qcar(v184);
    if (!consp(v184)) goto v164;
    v184 = stack[-1];
    fn = elt(env, 5); /* bfrsq */
    v200 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v184 = qvalue(elt(env, 3)); /* cr!-tolerance!* */
    fn = elt(env, 6); /* csl_timbf */
    stack[-3] = (*qfn2(fn))(qenv(fn), v200, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v184 = stack[-2];
    fn = elt(env, 5); /* bfrsq */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    fn = elt(env, 7); /* greaterp!: */
    v184 = (*qfn2(fn))(qenv(fn), stack[-3], v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    if (v184 == nil) goto v196;
    v184 = qvalue(elt(env, 4)); /* bfz!* */
    v200 = qvalue(elt(env, 4)); /* bfz!* */
    popv(5);
    return cons(v184, v200);

v196:
    v184 = stack[-2];
    v132 = qcar(v184);
    v184 = stack[-1];
    v200 = qcar(v184);
    v184 = stack[0];
    v184 = qcar(v184);
    fn = elt(env, 8); /* rdzchk */
    stack[-3] = (*qfnn(fn))(qenv(fn), 3, v132, v200, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v184 = stack[-2];
    v132 = qcdr(v184);
    v184 = stack[-1];
    v200 = qcdr(v184);
    v184 = stack[0];
    v184 = qcdr(v184);
    fn = elt(env, 8); /* rdzchk */
    v184 = (*qfnn(fn))(qenv(fn), 3, v132, v200, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    {
        Lisp_Object v181 = stack[-3];
        popv(5);
        return cons(v181, v184);
    }

v164:
    v184 = stack[-2];
    fn = elt(env, 5); /* bfrsq */
    stack[-3] = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v184 = stack[-1];
    fn = elt(env, 5); /* bfrsq */
    v200 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v184 = qvalue(elt(env, 1)); /* !!fleps2 */
    v184 = times2(v200, v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v184 = (Lisp_Object)lessp2(stack[-3], v184);
    nil = C_nil;
    if (exception_pending()) goto v186;
    v184 = v184 ? lisp_true : nil;
    env = stack[-4];
    if (v184 == nil) goto v196;
    v184 = elt(env, 2); /* 0.0 */
    v200 = elt(env, 2); /* 0.0 */
    popv(5);
    return cons(v184, v200);
/* error exit handlers */
v186:
    popv(5);
    return nil;
}



/* Code for evaluateuconst */

static Lisp_Object CC_evaluateuconst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluateuconst");
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
    v202 = stack[0];
    if (v202 == nil) goto v95;
    v202 = stack[0];
    if (!consp(v202)) goto v95;
    v202 = stack[0];
    v202 = qcar(v202);
    if (!consp(v202)) goto v95;
    v202 = stack[0];
    v202 = qcar(v202);
    v202 = qcar(v202);
    v197 = qcar(v202);
    v202 = qvalue(elt(env, 1)); /* cmap */
    v197 = Lassoc(nil, v197, v202);
    v202 = v197;
    if (v197 == nil) goto v102;
    v197 = qvalue(elt(env, 2)); /* cval */
    v202 = qcdr(v202);
    v202 = *(Lisp_Object *)((char *)v197 + (CELL-TAG_VECTOR) + ((int32_t)v202/(16/CELL)));
    goto v60;

v60:
    stack[-1] = v202;
    v202 = stack[0];
    v202 = qcar(v202);
    v202 = qcdr(v202);
    v202 = CC_evaluateuconst(env, v202);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    fn = elt(env, 3); /* !*multsq */
    v202 = (*qfn2(fn))(qenv(fn), stack[-1], v202);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    stack[-1] = v202;
    v202 = stack[0];
    v202 = qcdr(v202);
    v202 = CC_evaluateuconst(env, v202);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    {
        Lisp_Object v111 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* !*addsq */
        return (*qfn2(fn))(qenv(fn), v111, v202);
    }

v102:
    v202 = stack[0];
    v202 = qcar(v202);
    v197 = qcar(v202);
    v202 = (Lisp_Object)17; /* 1 */
    v202 = cons(v197, v202);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v197 = ncons(v202);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    v202 = (Lisp_Object)17; /* 1 */
    v202 = cons(v197, v202);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-2];
    goto v60;

v95:
    v197 = stack[0];
    v202 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v197, v202);
/* error exit handlers */
v56:
    popv(3);
    return nil;
}



/* Code for mchcomb */

static Lisp_Object MS_CDECL CC_mchcomb(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v235, v7, v8, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchcomb");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchcomb");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v83;
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */
    v234 = stack[-8];
    stack[0] = Llength(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v234 = stack[-7];
    v234 = Llength(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v234 = difference2(stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v234 = add1(v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    stack[0] = v234;
    v235 = stack[0];
    v234 = (Lisp_Object)17; /* 1 */
    v234 = (Lisp_Object)lessp2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    v234 = v234 ? lisp_true : nil;
    env = stack[-10];
    if (v234 == nil) goto v100;
    v234 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v234); }

v100:
    v235 = stack[0];
    v234 = (Lisp_Object)17; /* 1 */
    if (v235 == v234) goto v69;
    v235 = qvalue(elt(env, 2)); /* frlis!* */
    v234 = stack[-7];
    fn = elt(env, 4); /* smemqlp */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    if (v234 == nil) goto v195;
    v235 = stack[-8];
    v234 = stack[0];
    fn = elt(env, 5); /* comb */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    stack[-9] = v234;
    goto v85;

v85:
    v234 = stack[-9];
    if (v234 == nil) goto v196;
    v234 = stack[-9];
    v234 = qcar(v234);
    stack[-2] = v234;
    v234 = qvalue(elt(env, 3)); /* ncmp!* */
    if (v234 == nil) goto v191;
    v236 = stack[-2];
    v8 = stack[-8];
    v7 = qvalue(elt(env, 1)); /* nil */
    v235 = qvalue(elt(env, 1)); /* nil */
    v234 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 6); /* mchcomb2 */
    v234 = (*qfnn(fn))(qenv(fn), 5, v236, v8, v7, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    stack[0] = v234;
    v234 = stack[0];
    if (v234 == nil) goto v134;
    v7 = stack[-6];
    v235 = stack[-2];
    v234 = stack[0];
    v234 = qcar(v234);
    stack[-1] = acons(v7, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v234 = stack[0];
    v234 = qcdr(v234);
    if (v234 == nil) goto v36;
    v234 = stack[-7];
    v234 = Lreverse(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v235 = v234;
    goto v238;

v238:
    v234 = stack[-6];
    fn = elt(env, 7); /* mchsarg */
    v234 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    goto v58;

v58:
    stack[-5] = v234;
    v234 = stack[-5];
    fn = elt(env, 8); /* lastpair */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    stack[-4] = v234;
    v234 = stack[-9];
    v234 = qcdr(v234);
    stack[-9] = v234;
    v234 = stack[-4];
    if (!consp(v234)) goto v85;
    else goto v61;

v61:
    v234 = stack[-9];
    if (v234 == nil) { Lisp_Object res = stack[-5]; popv(11); return onevalue(res); }
    stack[-3] = stack[-4];
    v234 = stack[-9];
    v234 = qcar(v234);
    stack[-2] = v234;
    v234 = qvalue(elt(env, 3)); /* ncmp!* */
    if (v234 == nil) goto v239;
    v236 = stack[-2];
    v8 = stack[-8];
    v7 = qvalue(elt(env, 1)); /* nil */
    v235 = qvalue(elt(env, 1)); /* nil */
    v234 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 6); /* mchcomb2 */
    v234 = (*qfnn(fn))(qenv(fn), 5, v236, v8, v7, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    stack[0] = v234;
    v234 = stack[0];
    if (v234 == nil) goto v240;
    v7 = stack[-6];
    v235 = stack[-2];
    v234 = stack[0];
    v234 = qcar(v234);
    stack[-1] = acons(v7, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v234 = stack[0];
    v234 = qcdr(v234);
    if (v234 == nil) goto v9;
    v234 = stack[-7];
    v234 = Lreverse(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v235 = v234;
    goto v241;

v241:
    v234 = stack[-6];
    fn = elt(env, 7); /* mchsarg */
    v234 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    goto v242;

v242:
    v234 = Lrplacd(nil, stack[-3], v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v234 = stack[-4];
    fn = elt(env, 8); /* lastpair */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    stack[-4] = v234;
    v234 = stack[-9];
    v234 = qcdr(v234);
    stack[-9] = v234;
    goto v61;

v9:
    v234 = stack[-7];
    v235 = v234;
    goto v241;

v240:
    v234 = qvalue(elt(env, 1)); /* nil */
    goto v242;

v239:
    stack[-1] = stack[-6];
    stack[0] = stack[-2];
    v235 = stack[-8];
    v234 = stack[-2];
    fn = elt(env, 9); /* setdiff */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v7 = acons(stack[-1], stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v235 = stack[-7];
    v234 = stack[-6];
    fn = elt(env, 7); /* mchsarg */
    v234 = (*qfnn(fn))(qenv(fn), 3, v7, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    goto v242;

v36:
    v234 = stack[-7];
    v235 = v234;
    goto v238;

v134:
    v234 = qvalue(elt(env, 1)); /* nil */
    goto v58;

v191:
    stack[-1] = stack[-6];
    stack[0] = stack[-2];
    v235 = stack[-8];
    v234 = stack[-2];
    fn = elt(env, 9); /* setdiff */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v7 = acons(stack[-1], stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    v235 = stack[-7];
    v234 = stack[-6];
    fn = elt(env, 7); /* mchsarg */
    v234 = (*qfnn(fn))(qenv(fn), 3, v7, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-10];
    goto v58;

v196:
    v234 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v234); }

v195:
    v234 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v234); }

v69:
    v7 = stack[-8];
    v235 = stack[-7];
    v234 = stack[-6];
    {
        popv(11);
        fn = elt(env, 7); /* mchsarg */
        return (*qfnn(fn))(qenv(fn), 3, v7, v235, v234);
    }
/* error exit handlers */
v237:
    popv(11);
    return nil;
}



/* Code for qqe_qadd!-inside */

static Lisp_Object CC_qqe_qaddKinside(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qadd-inside");
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
    stack[0] = v0;
/* end of prologue */
    v203 = stack[0];
    if (v203 == nil) goto v133;
    v203 = stack[0];
    if (!consp(v203)) goto v133;
    v203 = stack[0];
    fn = elt(env, 6); /* qqe_op */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    stack[-1] = v203;
    v183 = elt(env, 2); /* a */
    v203 = qvalue(elt(env, 3)); /* qqe_qadd!-location!* */
    v203 = cons(v183, v203);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    qvalue(elt(env, 3)) = v203; /* qqe_qadd!-location!* */
    v203 = stack[0];
    v203 = Lconsp(nil, v203);
    env = stack[-3];
    if (v203 == nil) goto v63;
    v203 = stack[-1];
    fn = elt(env, 7); /* qqe_qopaddp */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    if (!(v203 == nil)) goto v63;
    v203 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v203;
    v203 = stack[-1];
    v183 = v203;
    v203 = stack[0];
    v203 = qcdr(v203);
    stack[-1] = v203;
    v203 = qvalue(elt(env, 3)); /* qqe_qadd!-location!* */
    stack[0] = v203;
    goto v175;

v175:
    v203 = stack[-1];
    if (v203 == nil) goto v101;
    v203 = stack[-2];
    if (v203 == nil) goto v101;
    v183 = elt(env, 5); /* d */
    v203 = stack[0];
    v203 = cons(v183, v203);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    qvalue(elt(env, 3)) = v203; /* qqe_qadd!-location!* */
    v203 = qvalue(elt(env, 3)); /* qqe_qadd!-location!* */
    stack[0] = v203;
    v203 = stack[-1];
    if (!consp(v203)) goto v87;
    v203 = stack[-1];
    v203 = qcar(v203);
    v203 = Lconsp(nil, v203);
    env = stack[-3];
    if (v203 == nil) goto v87;
    v203 = stack[-1];
    v203 = qcar(v203);
    v203 = CC_qqe_qaddKinside(env, v203);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    if (v203 == nil) goto v87;
    v203 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v203;
    goto v87;

v87:
    v203 = stack[-1];
    v183 = v203;
    v203 = stack[-1];
    v203 = qcdr(v203);
    stack[-1] = v203;
    goto v175;

v101:
    v203 = stack[-2];
    if (v203 == nil) { popv(4); return onevalue(v183); }
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v203); }

v63:
    v203 = stack[0];
    v203 = Lconsp(nil, v203);
    env = stack[-3];
    if (v203 == nil) goto v199;
    v203 = stack[-1];
    fn = elt(env, 7); /* qqe_qopaddp */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    if (v203 == nil) goto v199;
    v203 = qvalue(elt(env, 4)); /* t */
    { popv(4); return onevalue(v203); }

v199:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v203); }

v133:
    v203 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v203); }
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for pasf_uprap */

static Lisp_Object CC_pasf_uprap(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_uprap");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v0;
/* end of prologue */
    v133 = v11;
    v11 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* pasf_uprap1 */
        return (*qfn2(fn))(qenv(fn), v133, v11);
    }
}



/* Code for bra_mk */

static Lisp_Object MS_CDECL CC_bra_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v94, v125;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bra_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bra_mk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v95 = v83;
    v94 = v1;
    v125 = v0;
/* end of prologue */
    return list3(v125, v94, v95);
}



/* Code for appends */

static Lisp_Object MS_CDECL CC_appends(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v105, v168;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "appends");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for appends");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v106 = v83;
    v105 = v1;
    v168 = v0;
/* end of prologue */
    stack[0] = v168;
    v106 = Lappend(nil, v105, v106);
    nil = C_nil;
    if (exception_pending()) goto v192;
    {
        Lisp_Object v92 = stack[0];
        popv(1);
        return Lappend(nil, v92, v106);
    }
/* error exit handlers */
v192:
    popv(1);
    return nil;
}



/* Code for listeq */

static Lisp_Object CC_listeq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeq");
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

v46:
    v165 = stack[-1];
    if (!consp(v165)) goto v133;
    v165 = stack[0];
    if (!consp(v165)) goto v106;
    v165 = stack[-1];
    v110 = qcar(v165);
    v165 = stack[0];
    v165 = qcar(v165);
    v165 = CC_listeq(env, v110, v165);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    if (v165 == nil) goto v89;
    v165 = stack[-1];
    v165 = qcdr(v165);
    stack[-1] = v165;
    v165 = stack[0];
    v165 = qcdr(v165);
    stack[0] = v165;
    goto v46;

v89:
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v165); }

v106:
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v165); }

v133:
    v110 = stack[-1];
    v165 = stack[0];
    v165 = (v110 == v165 ? lisp_true : nil);
    { popv(3); return onevalue(v165); }
/* error exit handlers */
v102:
    popv(3);
    return nil;
}



/* Code for evalgeq */

static Lisp_Object CC_evalgeq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalgeq");
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
    v70 = v1;
    v130 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalgreaterp */
    v130 = (*qfn2(fn))(qenv(fn), v70, v130);
    errexit();
    v130 = (v130 == nil ? lisp_true : nil);
    return onevalue(v130);
}



/* Code for xvarp */

static Lisp_Object CC_xvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v158, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xvarp");
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
    v158 = qvalue(elt(env, 1)); /* xvars!* */
    v109 = qvalue(elt(env, 2)); /* t */
    if (equal(v158, v109)) goto v46;
    v109 = stack[0];
    fn = elt(env, 7); /* xdegree */
    v158 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v109 = (Lisp_Object)1; /* 0 */
    v109 = Lneq(nil, v158, v109);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    if (!(v109 == nil)) { popv(2); return onevalue(v109); }
    v109 = stack[0];
    v158 = qvalue(elt(env, 1)); /* xvars!* */
    v109 = Lmemq(nil, v109, v158);
    { popv(2); return onevalue(v109); }

v46:
    v109 = stack[0];
    if (!consp(v109)) goto v159;
    v109 = stack[0];
    v158 = qcar(v109);
    v109 = elt(env, 4); /* indexvar */
    v109 = Lflagp(nil, v158, v109);
    env = stack[-1];
    if (v109 == nil) goto v97;
    v109 = stack[0];
    v109 = qcdr(v109);
    v118 = Llength(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v109 = stack[0];
    v158 = qcar(v109);
    v109 = elt(env, 5); /* ifdegree */
    v109 = get(v158, v109);
    v109 = Lassoc(nil, v118, v109);
    { popv(2); return onevalue(v109); }

v97:
    v109 = stack[0];
    v109 = qcar(v109);
    v158 = elt(env, 6); /* (wedge d partdf hodge innerprod liedf) */
    v109 = Lmemq(nil, v109, v158);
    { popv(2); return onevalue(v109); }

v159:
    v109 = stack[0];
    v158 = elt(env, 3); /* fdegree */
    popv(2);
    return get(v109, v158);
/* error exit handlers */
v58:
    popv(2);
    return nil;
}



/* Code for gbfmult */

static Lisp_Object CC_gbfmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v71, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbfmult");
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
    v177 = stack[-1];
    v177 = Lfloatp(nil, v177);
    env = stack[-3];
    if (v177 == nil) goto v133;
    v177 = stack[-1];
    fn = elt(env, 2); /* fl2bf */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    goto v6;

v6:
    stack[-1] = v177;
    v71 = stack[-1];
    v177 = stack[0];
    v177 = qcar(v177);
    fn = elt(env, 3); /* csl_timbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v71, v177);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    v71 = stack[-1];
    v177 = stack[0];
    v177 = qcdr(v177);
    fn = elt(env, 3); /* csl_timbf */
    v177 = (*qfn2(fn))(qenv(fn), v71, v177);
    nil = C_nil;
    if (exception_pending()) goto v61;
    {
        Lisp_Object v62 = stack[-2];
        popv(4);
        return cons(v62, v177);
    }

v133:
    v177 = stack[-1];
    if (!consp(v177)) goto v125;
    v177 = stack[-1];
    goto v95;

v95:
    fn = elt(env, 4); /* csl_normbf */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    goto v6;

v125:
    v177 = stack[-1];
    v177 = integerp(v177);
    if (v177 == nil) goto v171;
    v87 = elt(env, 1); /* !:rd!: */
    v71 = stack[-1];
    v177 = (Lisp_Object)1; /* 0 */
    v177 = list2star(v87, v71, v177);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    goto v95;

v171:
    v177 = stack[-1];
    fn = elt(env, 5); /* read!:num */
    v177 = (*qfn1(fn))(qenv(fn), v177);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    goto v95;
/* error exit handlers */
v61:
    popv(4);
    return nil;
}



/* Code for calc_map_2d */

static Lisp_Object MS_CDECL CC_calc_map_2d(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v83, Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "calc_map_2d");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_map_2d");
#endif
    if (stack >= stacklimit)
    {
        push4(v40,v83,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v83,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v40;
    stack[-2] = v83;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v102 = stack[-4];
    v102 = qcar(v102);
    v102 = qcar(v102);
    fn = elt(env, 1); /* mk_names_map_2 */
    stack[-5] = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    v102 = stack[-4];
    v102 = qcar(v102);
    stack[0] = qcdr(v102);
    v102 = stack[-4];
    v102 = qcdr(v102);
    v193 = qcar(v102);
    v102 = stack[-3];
    v102 = cons(v193, v102);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    stack[0] = list2star(stack[-5], stack[0], v102);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    v102 = stack[-4];
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v193 = qcar(v102);
    v102 = stack[-1];
    fn = elt(env, 2); /* mk_binding */
    v102 = (*qfn2(fn))(qenv(fn), v193, v102);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    {
        Lisp_Object v121 = stack[0];
        Lisp_Object v179 = stack[-2];
        popv(7);
        fn = elt(env, 3); /* coeff_calc */
        return (*qfnn(fn))(qenv(fn), 3, v121, v179, v102);
    }
/* error exit handlers */
v120:
    popv(7);
    return nil;
}



/* Code for newbasis */

static Lisp_Object CC_newbasis(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v83)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newbasis");
#endif
    if (stack >= stacklimit)
    {
        push2(v83,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v83;
    v88 = v1;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v88; /* gg */
    stack[-2] = nil;
    v88 = qvalue(elt(env, 1)); /* gg */
    v88 = Lreverse(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-6];
    stack[-3] = v88;
    goto v94;

v94:
    v88 = stack[-3];
    if (v88 == nil) goto v95;
    stack[-1] = qvalue(elt(env, 3)); /* gv */
    v88 = stack[-3];
    v88 = qcar(v88);
    stack[0] = qcar(v88);
    v84 = qvalue(elt(env, 3)); /* gv */
    v88 = stack[-3];
    v88 = qcar(v88);
    v88 = qcar(v88);
    v85 = *(Lisp_Object *)((char *)v84 + (CELL-TAG_VECTOR) + ((int32_t)v88/(16/CELL)));
    v84 = stack[-2];
    v88 = stack[-4];
    fn = elt(env, 4); /* nf */
    v88 = (*qfnn(fn))(qenv(fn), 3, v85, v84, v88);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-6];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v88;
    v88 = stack[-3];
    v84 = qcar(v88);
    v88 = stack[-2];
    v88 = cons(v84, v88);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-6];
    stack[-2] = v88;
    v88 = stack[-3];
    v88 = qcdr(v88);
    stack[-3] = v88;
    goto v94;

v95:
    v88 = nil;
    qvalue(elt(env, 1)) = stack[-5]; /* gg */
    { popv(7); return onevalue(v88); }
/* error exit handlers */
v97:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-5]; /* gg */
    popv(7);
    return nil;
}



/* Code for tensor_has_dummy_idx */

static Lisp_Object CC_tensor_has_dummy_idx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensor_has_dummy_idx");
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

v46:
    v119 = stack[-1];
    if (v119 == nil) goto v4;
    v119 = stack[-1];
    v129 = qcar(v119);
    v119 = stack[0];
    fn = elt(env, 3); /* smember */
    v119 = (*qfn2(fn))(qenv(fn), v129, v119);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (v119 == nil) goto v92;
    v119 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v119); }

v92:
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-1] = v119;
    goto v46;

v4:
    v119 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v119); }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for derivative!-mod!-p */

static Lisp_Object CC_derivativeKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v90, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derivative-mod-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v69 = v0;
/* end of prologue */
    v91 = v69;
    if (!consp(v91)) goto v6;
    v91 = v69;
    v91 = qcar(v91);
    if (!consp(v91)) goto v6;
    v91 = v69;
    v91 = qcar(v91);
    v91 = qcar(v91);
    v90 = qcdr(v91);
    v91 = (Lisp_Object)17; /* 1 */
    if (v90 == v91) goto v130;
    v91 = v69;
    v90 = v69;
    v90 = qcar(v90);
    v90 = qcar(v90);
    v90 = qcar(v90);
    {
        fn = elt(env, 2); /* derivative!-mod!-p!-1 */
        return (*qfn2(fn))(qenv(fn), v91, v90);
    }

v130:
    v91 = v69;
    v91 = qcar(v91);
    v91 = qcdr(v91);
    return onevalue(v91);

v6:
    v91 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v91);
}



/* Code for make!-image!-lc!-list1 */

static Lisp_Object MS_CDECL CC_makeKimageKlcKlist1(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v83,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190, v74, v204, v243, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-image-lc-list1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image-lc-list1");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v83,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v83,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v74 = v40;
    stack[-1] = v83;
    v190 = v1;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v74; /* varlist */
    goto v133;

v133:
    v74 = stack[-1];
    if (v74 == nil) goto v76;
    v74 = v190;
    if (!consp(v74)) goto v122;
    v74 = v190;
    v74 = qcar(v74);
    if (!consp(v74)) goto v122;
    v74 = v190;
    v74 = qcar(v74);
    v74 = qcar(v74);
    v204 = qcar(v74);
    v74 = stack[-1];
    v74 = qcar(v74);
    v74 = qcar(v74);
    if (equal(v204, v74)) goto v179;
    v74 = stack[-1];
    v74 = qcdr(v74);
    stack[-1] = v74;
    v74 = qvalue(elt(env, 1)); /* varlist */
    v74 = qcdr(v74);
    qvalue(elt(env, 1)) = v74; /* varlist */
    goto v133;

v179:
    v230 = v190;
    v74 = stack[-1];
    v74 = qcar(v74);
    v243 = qcar(v74);
    v74 = stack[-1];
    v74 = qcar(v74);
    v204 = qcdr(v74);
    v74 = qvalue(elt(env, 3)); /* polyzero */
    v190 = qcar(v190);
    v190 = qcar(v190);
    v190 = qcdr(v190);
    fn = elt(env, 4); /* horner!-rule!-for!-one!-var */
    v74 = (*qfnn(fn))(qenv(fn), 5, v230, v243, v204, v74, v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    v190 = qvalue(elt(env, 1)); /* varlist */
    v190 = qcdr(v190);
    v190 = cons(v74, v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    v74 = v190;
    v74 = qcar(v74);
    if (v74 == nil) goto v197;
    stack[0] = v190;
    v204 = qcar(v190);
    v190 = stack[-1];
    v74 = qcdr(v190);
    v190 = qvalue(elt(env, 1)); /* varlist */
    v190 = qcdr(v190);
    v190 = CC_makeKimageKlcKlist1(env, 3, v204, v74, v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    v190 = cons(stack[0], v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    goto v5;

v5:
    qvalue(elt(env, 1)) = stack[-2]; /* varlist */
    { popv(4); return onevalue(v190); }

v197:
    v74 = (Lisp_Object)1; /* 0 */
    v190 = qcdr(v190);
    v190 = cons(v74, v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    v190 = ncons(v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    goto v5;

v122:
    fn = elt(env, 5); /* !*d2n */
    v74 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    v190 = qvalue(elt(env, 1)); /* varlist */
    v190 = qcdr(v190);
    v190 = cons(v74, v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    v190 = ncons(v190);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-3];
    goto v5;

v76:
    v190 = qvalue(elt(env, 2)); /* nil */
    goto v5;
/* error exit handlers */
v153:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* varlist */
    popv(4);
    return nil;
}



/* Code for negdf */

static Lisp_Object CC_negdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negdf");
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
    v101 = stack[-1];
    if (v101 == nil) goto v4;
    v101 = stack[-1];
    v101 = qcar(v101);
    stack[0] = qcar(v101);
    v101 = stack[-1];
    v101 = qcar(v101);
    v101 = qcdr(v101);
    v101 = qcar(v101);
    fn = elt(env, 1); /* negf */
    v175 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-3];
    v101 = stack[-1];
    v101 = qcar(v101);
    v101 = qcdr(v101);
    v101 = qcdr(v101);
    v175 = cons(v175, v101);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-3];
    v101 = stack[-2];
    v101 = acons(stack[0], v175, v101);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-3];
    stack[-2] = v101;
    v101 = stack[-1];
    v101 = qcdr(v101);
    stack[-1] = v101;
    goto v46;

v4:
    v101 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v101);
    }
/* error exit handlers */
v166:
    popv(4);
    return nil;
}



/* Code for conjsq */

static Lisp_Object CC_conjsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conjsq");
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
    v89 = stack[0];
    fn = elt(env, 2); /* impartsq */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    stack[-1] = v89;
    v89 = stack[-1];
    v89 = qcar(v89);
    if (v89 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v89 = stack[0];
    fn = elt(env, 3); /* repartsq */
    stack[0] = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v89 = elt(env, 1); /* i */
    fn = elt(env, 4); /* simp */
    v101 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v89 = stack[-1];
    fn = elt(env, 5); /* multsq */
    v89 = (*qfn2(fn))(qenv(fn), v101, v89);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    stack[-1] = v89;
    v89 = stack[-1];
    v89 = qcar(v89);
    fn = elt(env, 6); /* negf */
    v101 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = cons(v101, v89);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    {
        Lisp_Object v128 = stack[0];
        popv(3);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v128, v89);
    }
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



setup_type const u51_setup[] =
{
    {"nrootnn",                 too_few_2,      CC_nrootnn,    wrong_no_2},
    {"vp2df",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp2df},
    {"multtaylor*",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_multtaylorH},
    {"mk+inner+mat",            CC_mkLinnerLmat,too_many_1,    wrong_no_1},
    {"makevar",                 too_few_2,      CC_makevar,    wrong_no_2},
    {"ofsf_simpat",             CC_ofsf_simpat, too_many_1,    wrong_no_1},
    {"repr_new",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_repr_new},
    {"bc_minus?",               CC_bc_minusW,   too_many_1,    wrong_no_1},
    {"updkorder",               CC_updkorder,   too_many_1,    wrong_no_1},
    {"groebsimpcontnormalform", CC_groebsimpcontnormalform,too_many_1,wrong_no_1},
    {"xreduce1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreduce1},
    {"partitpartdf",            CC_partitpartdf,too_many_1,    wrong_no_1},
    {"mk-strand-vertex",        too_few_2,      CC_mkKstrandKvertex,wrong_no_2},
    {"split-wrt-variables",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKwrtKvariables},
    {"pst_equitable",           CC_pst_equitable,too_many_1,   wrong_no_1},
    {"eval_uni_poly_q",         too_few_2,      CC_eval_uni_poly_q,wrong_no_2},
    {"checkcoeffts",            too_few_2,      CC_checkcoeffts,wrong_no_2},
    {"addto-all-taytpelorders", too_few_2,      CC_addtoKallKtaytpelorders,wrong_no_2},
    {"ratpoly_toaf",            CC_ratpoly_toaf,too_many_1,    wrong_no_1},
    {"formopr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formopr},
    {"spmake_identity",         CC_spmake_identity,too_many_1, wrong_no_1},
    {"gbfquot",                 too_few_2,      CC_gbfquot,    wrong_no_2},
    {"physop*sq",               CC_physopHsq,   too_many_1,    wrong_no_1},
    {"mk-coeff1",               too_few_2,      CC_mkKcoeff1,  wrong_no_2},
    {"put-kvalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKkvalue},
    {"ofsf_chsimpat1",          CC_ofsf_chsimpat1,too_many_1,  wrong_no_1},
    {"preptaycoeff",            too_few_2,      CC_preptaycoeff,wrong_no_2},
    {"preptaylor**",            CC_preptaylorHH,too_many_1,    wrong_no_1},
    {"change+sq+to+int",        CC_changeLsqLtoLint,too_many_1,wrong_no_1},
    {"iv_cutn",                 CC_iv_cutn,     too_many_1,    wrong_no_1},
    {"ratpoly_univarp",         CC_ratpoly_univarp,too_many_1, wrong_no_1},
    {"subeval",                 CC_subeval,     too_many_1,    wrong_no_1},
    {"tvectorp",                CC_tvectorp,    too_many_1,    wrong_no_1},
    {"propagator",              too_few_2,      CC_propagator, wrong_no_2},
    {"dp_content",              CC_dp_content,  too_many_1,    wrong_no_1},
    {"lexorder",                CC_lexorder,    too_many_1,    wrong_no_1},
    {"spreadvar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_spreadvar},
    {"crzchk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_crzchk},
    {"evaluateuconst",          CC_evaluateuconst,too_many_1,  wrong_no_1},
    {"mchcomb",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchcomb},
    {"qqe_qadd-inside",         CC_qqe_qaddKinside,too_many_1, wrong_no_1},
    {"pasf_uprap",              CC_pasf_uprap,  too_many_1,    wrong_no_1},
    {"bra_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_bra_mk},
    {"appends",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_appends},
    {"listeq",                  too_few_2,      CC_listeq,     wrong_no_2},
    {"evalgeq",                 too_few_2,      CC_evalgeq,    wrong_no_2},
    {"xvarp",                   CC_xvarp,       too_many_1,    wrong_no_1},
    {"gbfmult",                 too_few_2,      CC_gbfmult,    wrong_no_2},
    {"calc_map_2d",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_calc_map_2d},
    {"newbasis",                too_few_2,      CC_newbasis,   wrong_no_2},
    {"tensor_has_dummy_idx",    too_few_2,      CC_tensor_has_dummy_idx,wrong_no_2},
    {"derivative-mod-p",        CC_derivativeKmodKp,too_many_1,wrong_no_1},
    {"make-image-lc-list1",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKimageKlcKlist1},
    {"negdf",                   CC_negdf,       too_many_1,    wrong_no_1},
    {"conjsq",                  CC_conjsq,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u51", (two_args *)"19301 4239559 3489231", 0}
};

/* end of generated code */
