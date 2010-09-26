
/* $destdir\u20.c        Machine generated C code */

/* Signature: 00000000 26-Sep-2010 */

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


/* Code for mod_eval_uni_poly */

static Lisp_Object CC_mod_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v24;
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
    v22 = stack[-2];
    if (!consp(v22)) goto v25;
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    fn = elt(env, 3); /* mod!# */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = v22;
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v23 = v22;
    v22 = stack[-2];
    v22 = qcdr(v22);
    stack[-2] = v22;
    goto v27;

v27:
    v22 = stack[-2];
    if (!consp(v22)) goto v28;
    stack[-3] = v24;
    stack[0] = stack[-1];
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v22 = difference2(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    fn = elt(env, 4); /* general!-modular!-expt */
    v22 = (*qfn2(fn))(qenv(fn), stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v23 = times2(stack[-3], v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v22 = qvalue(elt(env, 2)); /* current!-modulus */
    stack[0] = Cremainder(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    fn = elt(env, 3); /* mod!# */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v22 = (*qfn2(fn))(qenv(fn), stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = v22;
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcar(v22);
    v22 = qcdr(v22);
    v23 = v22;
    v22 = stack[-2];
    v22 = qcdr(v22);
    stack[-2] = v22;
    goto v27;

v28:
    stack[0] = v24;
    v22 = stack[-1];
    fn = elt(env, 4); /* general!-modular!-expt */
    v22 = (*qfn2(fn))(qenv(fn), v22, v23);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v23 = times2(stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v22 = qvalue(elt(env, 2)); /* current!-modulus */
    v22 = Cremainder(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v24 = v22;
    v22 = stack[-2];
    if (v22 == nil) { popv(5); return onevalue(v24); }
    stack[0] = v24;
    v22 = stack[-2];
    fn = elt(env, 3); /* mod!# */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    fn = elt(env, 5); /* general!-modular!-plus */
    v22 = (*qfn2(fn))(qenv(fn), stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v26;
    v24 = v22;
    { popv(5); return onevalue(v24); }

v25:
    v22 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* mod!# */
        return (*qfn1(fn))(qenv(fn), v22);
    }
/* error exit handlers */
v26:
    popv(5);
    return nil;
}



/* Code for general!-modular!-expt */

static Lisp_Object CC_generalKmodularKexpt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54;
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

v55:
    v54 = stack[-1];
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v56;
    v54 = stack[0];
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v57;
    v54 = stack[0];
    v53 = (Lisp_Object)17; /* 1 */
    if (v54 == v53) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[0];
    v53 = qvalue(elt(env, 4)); /* current!-modulus */
    v53 = sub1(v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v53 = (Lisp_Object)geq2(stack[-2], v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v53 = v53 ? lisp_true : nil;
    env = stack[-3];
    if (v53 == nil) goto v8;
    v53 = qvalue(elt(env, 4)); /* current!-modulus */
    fn = elt(env, 6); /* primep */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    if (v53 == nil) goto v8;
    v53 = qvalue(elt(env, 4)); /* current!-modulus */
    v53 = sub1(v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v53 = Cremainder(stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v53;
    goto v55;

v8:
    v53 = stack[0];
    v53 = Levenp(nil, v53);
    env = stack[-3];
    if (v53 == nil) goto v7;
    v54 = stack[0];
    v53 = (Lisp_Object)33; /* 2 */
    v53 = quot2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v53;
    v54 = stack[-1];
    v53 = stack[-1];
    fn = elt(env, 7); /* general!-modular!-times */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[-1] = v53;
    goto v8;

v7:
    v53 = stack[0];
    fn = elt(env, 8); /* reverse!-num */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v53;
    v53 = (Lisp_Object)17; /* 1 */
    stack[-2] = v53;
    goto v59;

v59:
    v54 = stack[0];
    v53 = (Lisp_Object)1; /* 0 */
    v53 = (Lisp_Object)greaterp2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v53 = v53 ? lisp_true : nil;
    env = stack[-3];
    if (v53 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v54 = stack[-2];
    v53 = stack[-2];
    fn = elt(env, 7); /* general!-modular!-times */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[-2] = v53;
    v53 = stack[0];
    v53 = Levenp(nil, v53);
    env = stack[-3];
    if (!(v53 == nil)) goto v60;
    v54 = stack[-2];
    v53 = stack[-1];
    fn = elt(env, 7); /* general!-modular!-times */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[-2] = v53;
    goto v60;

v60:
    v54 = stack[0];
    v53 = (Lisp_Object)33; /* 2 */
    v53 = quot2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v53;
    goto v59;

v57:
    v53 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v53); }

v56:
    v54 = stack[0];
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v61;
    v53 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v53); }

v61:
    v53 = elt(env, 1); /* "0^0 formed" */
    v54 = v53;
    v53 = v54;
    qvalue(elt(env, 2)) = v53; /* errmsg!* */
    v53 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v53 == nil)) goto v62;
    v53 = v54;
    fn = elt(env, 9); /* lprie */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v62;

v62:
    v53 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v53 = nil;
    { popv(4); return onevalue(v53); }
/* error exit handlers */
v58:
    popv(4);
    return nil;
}



/* Code for rootrnd */

static Lisp_Object CC_rootrnd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootrnd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v0;
/* end of prologue */
    v65 = v55;
    v55 = qvalue(elt(env, 1)); /* acc!# */
    {
        fn = elt(env, 2); /* rtrnda */
        return (*qfn2(fn))(qenv(fn), v65, v55);
    }
}



/* Code for reduce!-degree!-mod!-p */

static Lisp_Object CC_reduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v74;
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v73 = stack[-2];
    v73 = qcar(v73);
    v73 = qcdr(v73);
    {   int32_t w = int_of_fixnum(v73);
        if (w != 0) w = current_modulus - w;
        v74 = fixnum_of_int(w);
    }
    v73 = stack[-1];
    v73 = qcar(v73);
    v73 = qcdr(v73);
    v73 = Lmodular_quotient(nil, v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    stack[-3] = v73;
    v73 = stack[-2];
    v73 = qcar(v73);
    v73 = qcar(v73);
    v74 = qcdr(v73);
    v73 = stack[-1];
    v73 = qcar(v73);
    v73 = qcar(v73);
    v73 = qcdr(v73);
    v73 = (Lisp_Object)(int32_t)((int32_t)v74 - (int32_t)v73 + TAG_FIXNUM);
    stack[0] = v73;
    v74 = stack[0];
    v73 = (Lisp_Object)1; /* 0 */
    if (v74 == v73) goto v76;
    v73 = stack[-2];
    stack[-2] = qcdr(v73);
    v73 = stack[-1];
    v73 = qcar(v73);
    v73 = qcar(v73);
    v73 = qcar(v73);
    fn = elt(env, 1); /* fkern */
    v74 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v73 = stack[0];
    fn = elt(env, 2); /* getpower */
    v74 = (*qfn2(fn))(qenv(fn), v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v73 = stack[-3];
    v74 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v73 = stack[-1];
    v73 = qcdr(v73);
    fn = elt(env, 3); /* times!-term!-mod!-p */
    v73 = (*qfn2(fn))(qenv(fn), v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    {
        Lisp_Object v77 = stack[-2];
        popv(5);
        fn = elt(env, 4); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v77, v73);
    }

v76:
    v73 = stack[-2];
    stack[0] = qcdr(v73);
    v73 = stack[-1];
    v74 = qcdr(v73);
    v73 = stack[-3];
    fn = elt(env, 5); /* multiply!-by!-constant!-mod!-p */
    v73 = (*qfn2(fn))(qenv(fn), v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    {
        Lisp_Object v78 = stack[0];
        popv(5);
        fn = elt(env, 4); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v78, v73);
    }
/* error exit handlers */
v75:
    popv(5);
    return nil;
}



/* Code for pasf_mkpos */

static Lisp_Object CC_pasf_mkpos(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_mkpos");
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
    v23 = stack[0];
    v22 = elt(env, 1); /* true */
    if (v23 == v22) goto v88;
    v23 = stack[0];
    v22 = elt(env, 2); /* false */
    if (v23 == v22) goto v88;
    v22 = stack[0];
    v22 = qcdr(v22);
    v22 = qcar(v22);
    fn = elt(env, 5); /* minusf */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    if (v22 == nil) goto v88;
    v22 = stack[0];
    fn = elt(env, 6); /* pasf_anegateat */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    goto v90;

v90:
    stack[-2] = v22;
    v22 = stack[-2];
    v22 = Lconsp(nil, v22);
    env = stack[-3];
    if (v22 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = Lconsp(nil, v22);
    env = stack[-3];
    if (v22 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v22 = stack[-2];
    v22 = qcar(v22);
    v23 = qcar(v22);
    v22 = elt(env, 3); /* (cong ncong) */
    v22 = Lmemq(nil, v23, v22);
    if (v22 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    fn = elt(env, 5); /* minusf */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    if (v22 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v23 = stack[-2];
    v22 = elt(env, 1); /* true */
    if (v23 == v22) goto v44;
    v23 = stack[-2];
    v22 = elt(env, 2); /* false */
    if (v23 == v22) goto v44;
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = Lconsp(nil, v22);
    env = stack[-3];
    if (v22 == nil) goto v91;
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcar(v22);
    stack[-1] = v22;
    goto v20;

v20:
    v22 = stack[-2];
    v22 = qcar(v22);
    v22 = qcdr(v22);
    fn = elt(env, 7); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    v22 = stack[-2];
    v22 = qcdr(v22);
    v23 = qcar(v22);
    v22 = qvalue(elt(env, 4)); /* nil */
    v22 = list2(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    v22 = acons(stack[-1], stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v89;
    stack[-2] = v22;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v91:
    v22 = stack[-2];
    v22 = qcar(v22);
    stack[-1] = v22;
    goto v20;

v44:
    v22 = stack[-2];
    stack[-1] = v22;
    goto v20;

v88:
    v22 = stack[0];
    goto v90;
/* error exit handlers */
v89:
    popv(4);
    return nil;
}



/* Code for reln */

static Lisp_Object CC_reln(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v62;
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
    v88 = elt(env, 1); /* "<reln>" */
    fn = elt(env, 6); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v88 = elt(env, 2); /* "<" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v88 = stack[0];
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v88 = elt(env, 3); /* "/>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v62 = qvalue(elt(env, 4)); /* indent */
    v88 = (Lisp_Object)49; /* 3 */
    v88 = plus2(v62, v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    qvalue(elt(env, 4)) = v88; /* indent */
    v88 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v62 = qvalue(elt(env, 4)); /* indent */
    v88 = (Lisp_Object)49; /* 3 */
    v88 = difference2(v62, v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    qvalue(elt(env, 4)) = v88; /* indent */
    v88 = elt(env, 5); /* "</reln>" */
    fn = elt(env, 6); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v88 = nil;
    { popv(3); return onevalue(v88); }
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for evdif */

static Lisp_Object CC_evdif(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evdif");
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
    v16 = nil;
    goto v63;

v63:
    v46 = stack[0];
    if (v46 == nil) goto v71;
    v46 = stack[-1];
    if (!(v46 == nil)) goto v50;
    v46 = elt(env, 2); /* (0) */
    stack[-1] = v46;
    goto v50;

v50:
    v46 = stack[-1];
    v47 = qcar(v46);
    v46 = stack[0];
    v46 = qcar(v46);
    v46 = (Lisp_Object)(int32_t)((int32_t)v47 - (int32_t)v46 + TAG_FIXNUM);
    v47 = v16;
    v46 = cons(v46, v47);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-2];
    v16 = v46;
    v46 = stack[-1];
    v46 = qcdr(v46);
    stack[-1] = v46;
    v46 = stack[0];
    v46 = qcdr(v46);
    stack[0] = v46;
    goto v63;

v71:
    v46 = v16;
    v47 = Lnreverse(nil, v46);
    v46 = stack[-1];
        popv(3);
        return Lnconc(nil, v47, v46);
/* error exit handlers */
v83:
    popv(3);
    return nil;
}



/* Code for !:dmtimeslst */

static Lisp_Object CC_Tdmtimeslst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmtimeslst");
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
    v27 = v0;
/* end of prologue */
    v50 = v27;
    if (v50 == nil) goto v70;
    v50 = v27;
    v50 = qcdr(v50);
    if (v50 == nil) goto v63;
    v50 = v27;
    stack[0] = qcar(v50);
    v50 = v27;
    v50 = qcdr(v50);
    v50 = CC_Tdmtimeslst(env, v50);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    {
        Lisp_Object v100 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:times */
        return (*qfn2(fn))(qenv(fn), v100, v50);
    }

v63:
    v50 = v27;
    v50 = qcar(v50);
    { popv(2); return onevalue(v50); }

v70:
    v50 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v50); }
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for formatfort */

static Lisp_Object CC_formatfort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122, v123;
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
    v121 = (Lisp_Object)4801; /* 300 */
    v121 = Llinelength(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-4] = v121;
    v121 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v121; /* !*posn!* */
    v121 = stack[0];
    stack[-1] = v121;
    goto v11;

v11:
    v121 = stack[-1];
    if (v121 == nil) goto v4;
    v121 = stack[-1];
    v121 = qcar(v121);
    stack[0] = v121;
    v121 = stack[0];
    v121 = Lconsp(nil, v121);
    env = stack[-5];
    if (v121 == nil) goto v72;
    v121 = stack[0];
    fn = elt(env, 12); /* eval */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    goto v85;

v85:
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v11;

v72:
    v121 = stack[0];
    v121 = integerp(v121);
    if (v121 == nil) goto v98;
    v122 = stack[0];
    v121 = qvalue(elt(env, 4)); /* maxint */
    v121 = (Lisp_Object)greaterp2(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v121 = v121 ? lisp_true : nil;
    env = stack[-5];
    if (!(v121 == nil)) goto v97;
    stack[-3] = stack[0];
    v121 = qvalue(elt(env, 4)); /* maxint */
    v121 = negate(v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v121 = (Lisp_Object)lessp2(stack[-3], v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v121 = v121 ? lisp_true : nil;
    env = stack[-5];
    if (!(v121 == nil)) goto v97;

v98:
    v121 = stack[0];
    v121 = Lexplodec(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-3] = v121;
    v121 = stack[0];
    v121 = Lfloatp(nil, v121);
    env = stack[-5];
    if (v121 == nil) goto v125;
    v121 = qvalue(elt(env, 6)); /* !*double */
    if (v121 == nil) goto v126;
    v122 = elt(env, 7); /* e */
    v121 = stack[-3];
    v121 = Lmemq(nil, v122, v121);
    if (v121 == nil) goto v39;
    v123 = elt(env, 8); /* !D */
    v122 = elt(env, 7); /* e */
    v121 = stack[-3];
    v121 = Lsubst(nil, 3, v123, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-3] = v121;
    goto v125;

v125:
    stack[0] = qvalue(elt(env, 2)); /* !*posn!* */
    v121 = stack[-3];
    v121 = Llength(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v122 = plus2(stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v121 = qvalue(elt(env, 11)); /* fortlinelen!* */
    v121 = (Lisp_Object)greaterp2(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v121 = v121 ? lisp_true : nil;
    env = stack[-5];
    if (v121 == nil) goto v53;
    fn = elt(env, 13); /* fortcontline */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    goto v53;

v53:
    v121 = stack[-3];
    stack[0] = v121;
    goto v127;

v127:
    v121 = stack[0];
    if (v121 == nil) goto v85;
    v121 = stack[0];
    v121 = qcar(v121);
    fn = elt(env, 14); /* pprin2 */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v127;

v39:
    v122 = elt(env, 9); /* !E */
    v121 = stack[-3];
    v121 = Lmemq(nil, v122, v121);
    if (v121 == nil) goto v128;
    v123 = elt(env, 8); /* !D */
    v122 = elt(env, 9); /* !E */
    v121 = stack[-3];
    v121 = Lsubst(nil, 3, v123, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-3] = v121;
    goto v125;

v128:
    v122 = stack[-3];
    v121 = elt(env, 10); /* (d !0) */
    v121 = Lappend(nil, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-3] = v121;
    goto v125;

v126:
    v122 = elt(env, 7); /* e */
    v121 = stack[-3];
    v121 = Lmemq(nil, v122, v121);
    if (v121 == nil) goto v125;
    v123 = elt(env, 9); /* !E */
    v122 = elt(env, 7); /* e */
    v121 = stack[-3];
    v121 = Lsubst(nil, 3, v123, v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-3] = v121;
    goto v125;

v97:
    v121 = stack[0];
    fn = elt(env, 15); /* chkint!* */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v122 = v121;
    if (!(!consp(v122))) goto v129;
    v122 = elt(env, 5); /* !:rd!: */
    v121 = cons(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    goto v129;

v129:
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v98;

v4:
    v121 = stack[-4];
    v121 = Llinelength(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v121 = nil;
    qvalue(elt(env, 1)) = stack[-2]; /* !*lower */
    { popv(6); return onevalue(v121); }
/* error exit handlers */
v124:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-2]; /* !*lower */
    popv(6);
    return nil;
}



/* Code for all_defined_vertex */

static Lisp_Object CC_all_defined_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v131, v61, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v1;
    v131 = v0;
/* end of prologue */
    v93 = v131;
    v61 = qvalue(elt(env, 1)); /* nil */
    v131 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_vertex */
        return (*qfnn(fn))(qenv(fn), 4, v93, v61, v131, v87);
    }
}



/* Code for assert_install1 */

static Lisp_Object CC_assert_install1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v112, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_install1");
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
    v112 = stack[0];
    v113 = elt(env, 1); /* assert_installed */
    v113 = get(v112, v113);
    env = stack[-2];
    if (v113 == nil) goto v140;
    v113 = qvalue(elt(env, 2)); /* !*msg */
    if (v113 == nil) goto v52;
    stack[-1] = elt(env, 4); /* "***" */
    v112 = elt(env, 5); /* "assert already installed for" */
    v113 = stack[0];
    v113 = list2(v112, v113);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    {
        Lisp_Object v22 = stack[-1];
        popv(3);
        fn = elt(env, 11); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v22, v113);
    }

v52:
    v113 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v113); }

v140:
    v113 = stack[0];
    fn = elt(env, 12); /* getd */
    v112 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v113 = elt(env, 6); /* expr */
    if (!consp(v112)) goto v94;
    v112 = qcar(v112);
    if (!(v112 == v113)) goto v94;
    v112 = stack[0];
    v113 = elt(env, 8); /* assert_noassertfn */
    v112 = get(v112, v113);
    env = stack[-2];
    v113 = stack[0];
    fn = elt(env, 13); /* copyd */
    v113 = (*qfn2(fn))(qenv(fn), v112, v113);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v2 = stack[0];
    v112 = stack[0];
    v113 = elt(env, 9); /* assert_assertfn */
    v113 = get(v112, v113);
    env = stack[-2];
    fn = elt(env, 13); /* copyd */
    v113 = (*qfn2(fn))(qenv(fn), v2, v113);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    v112 = stack[0];
    v113 = elt(env, 1); /* assert_installed */
    v2 = qvalue(elt(env, 10)); /* t */
        popv(3);
        return Lputprop(nil, 3, v112, v113, v2);

v94:
    v113 = qvalue(elt(env, 2)); /* !*msg */
    if (v113 == nil) goto v95;
    stack[-1] = elt(env, 4); /* "***" */
    v112 = stack[0];
    v113 = elt(env, 7); /* "is not an expr procedure - ignoring assert" 
*/
    v113 = list2(v112, v113);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-2];
    {
        Lisp_Object v23 = stack[-1];
        popv(3);
        fn = elt(env, 11); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v23, v113);
    }

v95:
    v113 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v113); }
/* error exit handlers */
v39:
    popv(3);
    return nil;
}



/* Code for sc_rep */

static Lisp_Object CC_sc_rep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_rep");
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
    v11 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v11 = sub1(v11);
    nil = C_nil;
    if (exception_pending()) goto v51;
    v11 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v11/(16/CELL)));
    v11 = qcdr(v11);
    v11 = qcar(v11);
    { popv(1); return onevalue(v11); }
/* error exit handlers */
v51:
    popv(1);
    return nil;
}



/* Code for b!:ordexp */

static Lisp_Object CC_bTordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v57;
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

v25:
    v71 = stack[-1];
    if (v71 == nil) goto v63;
    v71 = stack[-1];
    v57 = qcar(v71);
    v71 = stack[0];
    v71 = qcar(v71);
    v71 = (Lisp_Object)greaterp2(v57, v71);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v50;
    v71 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v71); }

v50:
    v71 = stack[-1];
    v57 = qcar(v71);
    v71 = stack[0];
    v71 = qcar(v71);
    if (equal(v57, v71)) goto v85;
    v71 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v71); }

v85:
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[-1] = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v25;

v63:
    v71 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v71); }
/* error exit handlers */
v14:
    popv(3);
    return nil;
}



/* Code for ibalp_tvb */

static Lisp_Object CC_ibalp_tvb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_tvb");
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
    v46 = v0;
/* end of prologue */
    stack[-2] = v46;
    goto v90;

v90:
    v46 = stack[-2];
    if (v46 == nil) goto v55;
    v46 = stack[-2];
    v46 = qcar(v46);
    stack[0] = v46;
    v46 = stack[0];
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v47 = qcar(v46);
    v46 = stack[-1];
    v46 = (Lisp_Object)geq2(v47, v46);
    nil = C_nil;
    if (exception_pending()) goto v83;
    v46 = v46 ? lisp_true : nil;
    env = stack[-3];
    if (v46 == nil) goto v131;
    v46 = stack[0];
    v47 = qcdr(v46);
    v46 = stack[0];
    v46 = qcdr(v46);
    v46 = qcdr(v46);
    v46 = qcar(v46);
    fn = elt(env, 2); /* ibalp_var!-unset */
    v46 = (*qfn2(fn))(qenv(fn), v47, v46);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    goto v131;

v131:
    v46 = stack[-2];
    v46 = qcdr(v46);
    stack[-2] = v46;
    goto v90;

v55:
    v46 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v46); }
/* error exit handlers */
v83:
    popv(4);
    return nil;
}



/* Code for ctx_union */

static Lisp_Object CC_ctx_union(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_union");
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
    v24 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setkorder */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-5];
    stack[0] = v24;
    v24 = stack[0];
    fn = elt(env, 3); /* setkorder */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-5];
    v24 = stack[-3];
    fn = elt(env, 4); /* ctx_ial */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-5];
    stack[-3] = v24;
    v24 = stack[-2];
    fn = elt(env, 4); /* ctx_ial */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-5];
    stack[-2] = v24;
    v24 = stack[0];
    stack[-1] = v24;
    goto v131;

v131:
    v24 = stack[-1];
    if (v24 == nil) goto v87;
    v24 = stack[-1];
    v24 = qcar(v24);
    stack[0] = v24;
    v24 = stack[-3];
    if (v24 == nil) goto v72;
    v24 = stack[-3];
    v24 = qcar(v24);
    v142 = qcar(v24);
    v24 = stack[0];
    if (!(v142 == v24)) goto v72;
    v24 = stack[-3];
    v142 = qcar(v24);
    v24 = stack[-4];
    v24 = cons(v142, v24);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-5];
    stack[-4] = v24;
    v24 = stack[-3];
    v24 = qcdr(v24);
    stack[-3] = v24;
    v24 = stack[-2];
    if (v24 == nil) goto v92;
    v24 = stack[-2];
    v24 = qcar(v24);
    v142 = qcar(v24);
    v24 = stack[0];
    if (!(v142 == v24)) goto v92;
    v24 = stack[-2];
    v24 = qcdr(v24);
    stack[-2] = v24;
    goto v92;

v92:
    v24 = stack[-1];
    v24 = qcdr(v24);
    stack[-1] = v24;
    goto v131;

v72:
    v24 = stack[-2];
    if (v24 == nil) goto v92;
    v24 = stack[-2];
    v24 = qcar(v24);
    v142 = qcar(v24);
    v24 = stack[0];
    if (!(v142 == v24)) goto v92;
    v24 = stack[-2];
    v142 = qcar(v24);
    v24 = stack[-4];
    v24 = cons(v142, v24);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-5];
    stack[-4] = v24;
    v24 = stack[-2];
    v24 = qcdr(v24);
    stack[-2] = v24;
    goto v92;

v87:
    v24 = stack[-3];
    if (!(v24 == nil)) goto v78;
    v24 = stack[-2];
    if (!(v24 == nil)) goto v78;

v77:
    v24 = stack[-4];
    v24 = Lnreverse(nil, v24);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v24);
    }

v78:
    v24 = elt(env, 2); /* "***** ctx_union: idorder not complete" */
    v24 = Lprinc(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-5];
    v24 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-5];
    goto v77;
/* error exit handlers */
v143:
    popv(6);
    return nil;
}



/* Code for makeset */

static Lisp_Object CC_makeset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v12, v144;
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
    v144 = nil;
    goto v25;

v25:
    v140 = stack[0];
    if (v140 == nil) goto v63;
    v140 = stack[0];
    v12 = qcar(v140);
    v140 = stack[0];
    v140 = qcdr(v140);
    v140 = Lmember(nil, v12, v140);
    if (v140 == nil) goto v92;
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[0] = v140;
    goto v25;

v92:
    v140 = stack[0];
    v140 = qcar(v140);
    v12 = v144;
    v140 = cons(v140, v12);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    v144 = v140;
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[0] = v140;
    goto v25;

v63:
    v140 = v144;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v140);
    }
/* error exit handlers */
v57:
    popv(2);
    return nil;
}



/* Code for testpr */

static Lisp_Object MS_CDECL CC_testpr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v80, Lisp_Object v69, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "testpr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testpr");
#endif
    if (stack >= stacklimit)
    {
        push4(v69,v80,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v80,v69);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v69;
    stack[-6] = v80;
    stack[0] = v1;
    v107 = v0;
/* end of prologue */
    stack[-3] = nil;
    v108 = qvalue(elt(env, 1)); /* jsi */
    stack[-2] = v108;
    stack[-1] = qvalue(elt(env, 2)); /* codmat */
    v108 = qvalue(elt(env, 3)); /* maxvar */
    v107 = plus2(v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-8];
    v108 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v107/(16/CELL)));
    v107 = (Lisp_Object)65; /* 4 */
    v107 = *(Lisp_Object *)((char *)v108 + (CELL-TAG_VECTOR) + ((int32_t)v107/(16/CELL)));
    stack[-7] = v107;
    stack[-1] = qvalue(elt(env, 2)); /* codmat */
    v108 = qvalue(elt(env, 3)); /* maxvar */
    v107 = stack[0];
    v107 = plus2(v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-8];
    v108 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v107/(16/CELL)));
    v107 = (Lisp_Object)65; /* 4 */
    v107 = *(Lisp_Object *)((char *)v108 + (CELL-TAG_VECTOR) + ((int32_t)v107/(16/CELL)));
    stack[-4] = v107;
    goto v19;

v19:
    v107 = stack[-2];
    if (v107 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v107 = stack[-7];
    if (v107 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v107 = stack[-2];
    v108 = qcar(v107);
    stack[-1] = v108;
    v107 = stack[-7];
    v107 = qcar(v107);
    v107 = qcar(v107);
    v150 = v107;
    if (equal(v108, v107)) goto v43;
    v107 = stack[-1];
    v108 = v150;
    v107 = (Lisp_Object)greaterp2(v107, v108);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v107 = v107 ? lisp_true : nil;
    env = stack[-8];
    if (v107 == nil) goto v126;
    v107 = stack[-7];
    v107 = qcdr(v107);
    stack[-7] = v107;
    goto v19;

v126:
    v107 = stack[-2];
    v107 = qcdr(v107);
    stack[-2] = v107;
    goto v19;

v43:
    v108 = stack[-1];
    v107 = stack[-4];
    fn = elt(env, 5); /* pnthxzz */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-8];
    stack[-4] = v107;
    v107 = stack[-7];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v108 = qcar(v107);
    v107 = stack[-5];
    fn = elt(env, 6); /* dm!-times */
    stack[0] = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-8];
    v107 = stack[-4];
    v107 = qcar(v107);
    v107 = qcdr(v107);
    v108 = qcar(v107);
    v107 = stack[-6];
    fn = elt(env, 6); /* dm!-times */
    v107 = (*qfn2(fn))(qenv(fn), v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-8];
    fn = elt(env, 7); /* dm!-difference */
    v107 = (*qfn2(fn))(qenv(fn), stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-8];
    fn = elt(env, 8); /* zeropp */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-8];
    if (v107 == nil) goto v134;
    v108 = stack[-1];
    v107 = stack[-3];
    v107 = cons(v108, v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-8];
    stack[-3] = v107;
    goto v134;

v134:
    v107 = stack[-2];
    v107 = qcdr(v107);
    stack[-2] = v107;
    v107 = stack[-7];
    v107 = qcdr(v107);
    stack[-7] = v107;
    goto v19;
/* error exit handlers */
v106:
    popv(9);
    return nil;
}



/* Code for random */

static Lisp_Object CC_random(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random");
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
    v156 = stack[-3];
    if (!(is_number(v156))) goto v158;
    v157 = stack[-3];
    v156 = (Lisp_Object)1; /* 0 */
    v156 = (Lisp_Object)lesseq2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    v156 = v156 ? lisp_true : nil;
    env = stack[-5];
    if (!(v156 == nil)) goto v158;

v141:
    v156 = stack[-3];
    v156 = Lfloatp(nil, v156);
    env = stack[-5];
    if (v156 == nil) goto v21;
    fn = elt(env, 5); /* next!-random!-number */
    v156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v157 = Lfloat(nil, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v156 = qvalue(elt(env, 2)); /* unidev_fac!* */
    v156 = times2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[-2] = v156;
    fn = elt(env, 5); /* next!-random!-number */
    v156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v157 = Lfloat(nil, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v156 = stack[-2];
    stack[0] = plus2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v157 = qvalue(elt(env, 2)); /* unidev_fac!* */
    v156 = stack[-3];
    v156 = times2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    {
        Lisp_Object v108 = stack[0];
        popv(6);
        return times2(v108, v156);
    }

v21:
    fn = elt(env, 5); /* next!-random!-number */
    v156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[-2] = v156;
    v156 = qvalue(elt(env, 3)); /* randommodulus!* */
    stack[-4] = v156;
    goto v82;

v82:
    v157 = stack[-4];
    v156 = stack[-3];
    v156 = (Lisp_Object)lessp2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    v156 = v156 ? lisp_true : nil;
    env = stack[-5];
    if (v156 == nil) goto v39;
    v157 = stack[-4];
    v156 = qvalue(elt(env, 3)); /* randommodulus!* */
    v156 = times2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[-4] = v156;
    v157 = qvalue(elt(env, 3)); /* randommodulus!* */
    v156 = stack[-2];
    stack[0] = times2(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    fn = elt(env, 5); /* next!-random!-number */
    v156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v156 = plus2(stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    stack[-2] = v156;
    goto v82;

v39:
    stack[-1] = stack[-2];
    stack[0] = stack[-4];
    v157 = stack[-4];
    v156 = stack[-3];
    v156 = Cremainder(v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v156 = difference2(stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v156 = (Lisp_Object)lessp2(stack[-1], v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    v156 = v156 ? lisp_true : nil;
    env = stack[-5];
    if (v156 == nil) goto v21;
    v157 = stack[-2];
    v156 = stack[-3];
    popv(6);
    return Cremainder(v157, v156);

v158:
    v157 = stack[-3];
    v156 = elt(env, 1); /* "positive number" */
    fn = elt(env, 6); /* typerr */
    v156 = (*qfn2(fn))(qenv(fn), v157, v156);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    goto v141;
/* error exit handlers */
v107:
    popv(6);
    return nil;
}



/* Code for convprc2 */

static Lisp_Object CC_convprc2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v40, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convprc2");
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
    v79 = stack[-1];
    v79 = qcdr(v79);
    if (!consp(v79)) goto v90;
    v79 = stack[-1];
    goto v25;

v25:
    fn = elt(env, 4); /* convchk */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    stack[-1] = v79;
    v79 = stack[0];
    v79 = qcdr(v79);
    if (!consp(v79)) goto v131;
    v79 = stack[0];
    goto v87;

v87:
    fn = elt(env, 4); /* convchk */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    qvalue(elt(env, 1)) = v79; /* yy!! */
    v79 = qvalue(elt(env, 2)); /* !*roundbf */
    if (v79 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v79 = qvalue(elt(env, 1)); /* yy!! */
    v40 = v79;
    v40 = Lfloatp(nil, v40);
    env = stack[-2];
    if (v40 == nil) goto v144;
    fn = elt(env, 5); /* fl2bf */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    goto v98;

v98:
    qvalue(elt(env, 1)) = v79; /* yy!! */
    v79 = stack[-1];
    v79 = Lfloatp(nil, v79);
    env = stack[-2];
    if (v79 == nil) goto v66;
    v79 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v79);
    }

v66:
    v79 = stack[-1];
    if (!consp(v79)) goto v68;
    v79 = stack[-1];
    goto v82;

v82:
    {
        popv(3);
        fn = elt(env, 6); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v79);
    }

v68:
    v79 = stack[-1];
    v79 = integerp(v79);
    if (v79 == nil) goto v9;
    v41 = elt(env, 3); /* !:rd!: */
    v40 = stack[-1];
    v79 = (Lisp_Object)1; /* 0 */
    v79 = list2star(v41, v40, v79);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    goto v82;

v9:
    v79 = stack[-1];
    fn = elt(env, 7); /* read!:num */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    goto v82;

v144:
    v40 = v79;
    if (!(!consp(v40))) goto v76;
    v40 = v79;
    v40 = integerp(v40);
    if (v40 == nil) goto v155;
    v41 = elt(env, 3); /* !:rd!: */
    v40 = v79;
    v79 = (Lisp_Object)1; /* 0 */
    v79 = list2star(v41, v40, v79);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    goto v76;

v76:
    fn = elt(env, 6); /* csl_normbf */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    goto v98;

v155:
    fn = elt(env, 7); /* read!:num */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    goto v76;

v131:
    v79 = stack[0];
    v79 = qcdr(v79);
    goto v87;

v90:
    v79 = stack[-1];
    v79 = qcdr(v79);
    goto v25;
/* error exit handlers */
v113:
    popv(3);
    return nil;
}



/* Code for physopordchk */

static Lisp_Object CC_physopordchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v118, v119;
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
    v84 = v0;
/* end of prologue */
    fn = elt(env, 4); /* !*collectphysops */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    stack[-1] = v84;
    v84 = stack[0];
    fn = elt(env, 4); /* !*collectphysops */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v119 = v84;
    v84 = stack[-1];
    if (v84 == nil) goto v131;
    v84 = v119;
    if (v84 == nil) goto v158;
    v118 = elt(env, 3); /* unit */
    v84 = stack[-1];
    v84 = Lmember(nil, v118, v84);
    if (!(v84 == nil)) goto v49;
    v118 = elt(env, 3); /* unit */
    v84 = v119;
    v84 = Lmember(nil, v118, v84);
    if (!(v84 == nil)) goto v49;
    v84 = stack[-1];
    v118 = v119;
    {
        popv(3);
        fn = elt(env, 6); /* physopordchk!* */
        return (*qfn2(fn))(qenv(fn), v84, v118);
    }

v49:
    v84 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v84); }

v158:
    v84 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v84); }

v131:
    v84 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v84); }
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for prop!-simp1 */

static Lisp_Object MS_CDECL CC_propKsimp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v80, Lisp_Object v69,
                         Lisp_Object v70, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "prop-simp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp1");
#endif
    if (stack >= stacklimit)
    {
        push5(v70,v69,v80,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v80,v69,v70);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v70;
    stack[0] = v69;
    stack[-5] = v80;
    stack[-2] = v1;
    stack[-6] = v0;
/* end of prologue */

v161:
    v38 = stack[-2];
    if (v38 == nil) goto v93;
    v39 = stack[-6];
    v38 = stack[-2];
    v38 = qcar(v38);
    fn = elt(env, 1); /* prop!-simp2 */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-8];
    stack[-3] = v38;
    v38 = stack[-3];
    if (v38 == nil) goto v96;
    v38 = stack[-3];
    stack[-6] = qcdr(v38);
    v38 = stack[-2];
    stack[-2] = qcdr(v38);
    stack[-1] = stack[-5];
    v38 = stack[0];
    stack[0] = add1(v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-8];
    v38 = stack[-3];
    stack[-7] = qcar(v38);
    stack[-3] = (Lisp_Object)-15; /* -1 */
    v38 = stack[-5];
    v38 = Llength(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-8];
    v38 = Lexpt(nil, stack[-3], v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-8];
    v38 = times2(stack[-4], v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-8];
    v38 = times2(stack[-7], v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-8];
    stack[-5] = stack[-1];
    stack[-4] = v38;
    goto v161;

v96:
    stack[-3] = stack[-6];
    v38 = stack[-2];
    stack[-1] = qcdr(v38);
    v38 = stack[-2];
    v39 = qcar(v38);
    v38 = stack[-5];
    v22 = cons(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-8];
    v39 = stack[0];
    v38 = stack[-4];
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v22;
    stack[0] = v39;
    stack[-4] = v38;
    goto v161;

v93:
    v39 = stack[0];
    v38 = stack[-4];
    stack[0] = list2(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-8];
    stack[-1] = stack[-6];
    v38 = stack[-5];
    v38 = Lreverse(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v162 = stack[0];
        Lisp_Object v59 = stack[-1];
        popv(9);
        return list2star(v162, v59, v38);
    }
/* error exit handlers */
v143:
    popv(9);
    return nil;
}



/* Code for assert_stat!-parse */

static Lisp_Object MS_CDECL CC_assert_statKparse(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v112, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_stat-parse");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_stat-parse");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    fn = elt(env, 10); /* scan */
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[-2] = v113;
    fn = elt(env, 10); /* scan */
    v112 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v113 = elt(env, 1); /* !*colon!* */
    if (v112 == v113) goto v63;
    v113 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v113 == nil)) goto v56;
    v112 = elt(env, 3); /* "expecting ':' in assert but found" */
    v113 = qvalue(elt(env, 4)); /* cursym!* */
    v113 = list2(v112, v113);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    fn = elt(env, 11); /* lprie */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    goto v56;

v56:
    v113 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    goto v63;

v63:
    fn = elt(env, 12); /* assert_stat1 */
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[-1] = v113;
    fn = elt(env, 10); /* scan */
    v112 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v113 = elt(env, 5); /* difference */
    if (!(v112 == v113)) goto v160;
    fn = elt(env, 10); /* scan */
    v112 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v113 = elt(env, 6); /* greaterp */
    if (!(v112 == v113)) goto v160;

v94:
    fn = elt(env, 10); /* scan */
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[0] = v113;
    fn = elt(env, 10); /* scan */
    v112 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v113 = elt(env, 8); /* delim */
    v113 = Lflagp(nil, v112, v113);
    env = stack[-3];
    if (!(v113 == nil)) goto v6;
    v113 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v113 == nil)) goto v5;
    v112 = elt(env, 9); /* "expecting end of assert but found" */
    v113 = qvalue(elt(env, 4)); /* cursym!* */
    v113 = list2(v112, v113);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    fn = elt(env, 11); /* lprie */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    goto v5;

v5:
    v113 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    goto v6;

v6:
    v2 = stack[-2];
    v112 = stack[-1];
    v113 = stack[0];
    popv(4);
    return list3(v2, v112, v113);

v160:
    v113 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v113 == nil)) goto v119;
    v112 = elt(env, 7); /* "expecting '->' in assert but found" */
    v113 = qvalue(elt(env, 4)); /* cursym!* */
    v113 = list2(v112, v113);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    fn = elt(env, 11); /* lprie */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    goto v119;

v119:
    v113 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    goto v94;
/* error exit handlers */
v22:
    popv(4);
    return nil;
}



/* Code for sf_member */

static Lisp_Object CC_sf_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf_member");
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

v161:
    v116 = stack[0];
    if (!consp(v116)) goto v25;
    v116 = stack[0];
    v116 = qcar(v116);
    if (!consp(v116)) goto v25;
    v117 = stack[-1];
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = (equal(v117, v116) ? lisp_true : nil);
    if (!(v116 == nil)) goto v61;
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcar(v116);
    if (!consp(v116)) goto v62;
    v117 = stack[-1];
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcar(v116);
    v116 = qcdr(v116);
    fn = elt(env, 2); /* arglist_member */
    v116 = (*qfn2(fn))(qenv(fn), v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    goto v61;

v61:
    if (!(v116 == nil)) { popv(3); return onevalue(v116); }
    v117 = stack[-1];
    v116 = stack[0];
    v116 = qcar(v116);
    v116 = qcdr(v116);
    v116 = CC_sf_member(env, v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    if (!(v116 == nil)) { popv(3); return onevalue(v116); }
    v117 = stack[-1];
    v116 = stack[0];
    v116 = qcdr(v116);
    stack[-1] = v117;
    stack[0] = v116;
    goto v161;

v62:
    v116 = qvalue(elt(env, 1)); /* nil */
    goto v61;

v25:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v116); }
/* error exit handlers */
v135:
    popv(3);
    return nil;
}



/* Code for extract_dummy_ids */

static Lisp_Object CC_extract_dummy_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v140, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extract_dummy_ids");
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
    v12 = nil;
    goto v25;

v25:
    v163 = stack[0];
    if (v163 == nil) goto v63;
    v163 = stack[0];
    v140 = qcar(v163);
    v163 = qvalue(elt(env, 1)); /* dummy_id!* */
    v163 = Lmemq(nil, v140, v163);
    if (v163 == nil) goto v98;
    v163 = stack[0];
    v163 = qcar(v163);
    v140 = v12;
    v163 = cons(v163, v140);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    v12 = v163;
    v163 = stack[0];
    v163 = qcdr(v163);
    stack[0] = v163;
    goto v25;

v98:
    v163 = stack[0];
    v163 = qcdr(v163);
    stack[0] = v163;
    goto v25;

v63:
    v163 = v12;
    {
        popv(2);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v163);
    }
/* error exit handlers */
v71:
    popv(2);
    return nil;
}



/* Code for resimpf */

static Lisp_Object CC_resimpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimpf");
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
    v130 = v0;
/* end of prologue */
    v11 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v11; /* varstack!* */
    v11 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subf1 */
    v11 = (*qfn2(fn))(qenv(fn), v130, v11);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v11 = qcar(v11);
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v11); }
/* error exit handlers */
v52:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for ofsf_smupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v80, Lisp_Object v69, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v6, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v69,v80,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v80,v69);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v69;
    stack[-2] = v80;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v4:
    v10 = stack[-3];
    if (v10 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v6 = stack[-4];
    v10 = elt(env, 2); /* and */
    if (v6 == v10) goto v56;
    v10 = stack[-3];
    v10 = qcar(v10);
    fn = elt(env, 4); /* ofsf_negateat */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    goto v93;

v93:
    v6 = v10;
    v10 = stack[-3];
    v10 = qcdr(v10);
    stack[-3] = v10;
    v10 = stack[-1];
    fn = elt(env, 5); /* ofsf_at2ir */
    v10 = (*qfn2(fn))(qenv(fn), v6, v10);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    v75 = v10;
    v10 = v75;
    v6 = qcar(v10);
    v10 = stack[-2];
    v10 = Lassoc(nil, v6, v10);
    stack[-5] = v10;
    if (v10 == nil) goto v7;
    stack[0] = stack[-5];
    v10 = v75;
    v10 = qcdr(v10);
    v6 = qcar(v10);
    v10 = stack[-5];
    v10 = qcdr(v10);
    fn = elt(env, 6); /* ofsf_sminsert */
    v10 = (*qfn2(fn))(qenv(fn), v6, v10);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    fn = elt(env, 7); /* setcdr */
    v10 = (*qfn2(fn))(qenv(fn), stack[0], v10);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    v10 = stack[-5];
    v6 = qcdr(v10);
    v10 = elt(env, 3); /* false */
    if (!(v6 == v10)) goto v4;
    v10 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v10;
    v10 = elt(env, 3); /* false */
    stack[-2] = v10;
    goto v4;

v7:
    v6 = v75;
    v10 = stack[-2];
    v10 = cons(v6, v10);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    stack[-2] = v10;
    goto v4;

v56:
    v10 = stack[-3];
    v10 = qcar(v10);
    goto v93;
/* error exit handlers */
v132:
    popv(7);
    return nil;
}



/* Code for mo_comp */

static Lisp_Object CC_mo_comp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v51;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_comp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v0;
/* end of prologue */
    v51 = v130;
    v51 = qcar(v51);
    if (v51 == nil) goto v70;
    v130 = qcar(v130);
    v130 = qcar(v130);
    return onevalue(v130);

v70:
    v130 = (Lisp_Object)1; /* 0 */
    return onevalue(v130);
}



/* Code for ofsf_prepat */

static Lisp_Object CC_ofsf_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_prepat");
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
    v149 = stack[-1];
    stack[-2] = qcar(v149);
    v149 = stack[-1];
    v149 = qcdr(v149);
    v83 = qcar(v149);
    v149 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1 */
    v149 = (*qfn2(fn))(qenv(fn), v83, v149);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-3];
    v83 = v149;
    v149 = v83;
    if (v149 == nil) goto v85;
    v149 = v83;
    fn = elt(env, 3); /* replus */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-3];
    stack[0] = v149;
    goto v62;

v62:
    v149 = stack[-1];
    v149 = qcdr(v149);
    v149 = qcdr(v149);
    v83 = qcar(v149);
    v149 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1 */
    v149 = (*qfn2(fn))(qenv(fn), v83, v149);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-3];
    v83 = v149;
    v149 = v83;
    if (v149 == nil) goto v14;
    v149 = v83;
    fn = elt(env, 3); /* replus */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v18;
    goto v63;

v63:
    {
        Lisp_Object v19 = stack[-2];
        Lisp_Object v45 = stack[0];
        popv(4);
        return list3(v19, v45, v149);
    }

v14:
    v149 = (Lisp_Object)1; /* 0 */
    goto v63;

v85:
    v149 = (Lisp_Object)1; /* 0 */
    stack[0] = v149;
    goto v62;
/* error exit handlers */
v18:
    popv(4);
    return nil;
}



/* Code for subf */

static Lisp_Object CC_subf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v175;
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
    v174 = qvalue(elt(env, 2)); /* nil */
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    qvalue(elt(env, 1)) = v174; /* alglist!* */
    v174 = stack[-6];
    if (!consp(v174)) goto v11;
    v174 = stack[-6];
    v174 = qcar(v174);
    if (!consp(v174)) goto v11;
    v174 = qvalue(elt(env, 3)); /* ncmp!* */
    if (v174 == nil) goto v163;
    v174 = stack[-6];
    fn = elt(env, 7); /* noncomexpf */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    if (v174 == nil) goto v163;
    v175 = stack[-6];
    v174 = stack[-5];
    fn = elt(env, 8); /* subf1 */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    goto v63;

v63:
    qvalue(elt(env, 1)) = stack[-7]; /* alglist!* */
    { popv(9); return onevalue(v174); }

v163:
    v174 = stack[-5];
    stack[-3] = v174;
    v174 = stack[-3];
    if (v174 == nil) goto v16;
    v174 = stack[-3];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    stack[-1] = v174;
    stack[-2] = v174;
    goto v120;

v120:
    v174 = stack[-3];
    v174 = qcdr(v174);
    stack[-3] = v174;
    v174 = stack[-3];
    if (v174 == nil) goto v20;
    stack[0] = stack[-1];
    v174 = stack[-3];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v174 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = Lrplacd(nil, stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = stack[-1];
    v174 = qcdr(v174);
    stack[-1] = v174;
    goto v120;

v20:
    v174 = stack[-2];
    stack[0] = v174;
    goto v136;

v136:
    v175 = stack[-6];
    v174 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 9); /* kernord */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    fn = elt(env, 10); /* intersection */
    v174 = (*qfn2(fn))(qenv(fn), stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = Lreverse(nil, v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    stack[0] = v174;
    v174 = stack[0];
    fn = elt(env, 11); /* setkorder */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    stack[0] = v174;
    v174 = stack[-6];
    fn = elt(env, 12); /* reorder */
    v175 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = stack[-5];
    fn = elt(env, 8); /* subf1 */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    stack[-6] = v174;
    goto v133;

v133:
    v175 = stack[-6];
    v174 = stack[-4];
    v174 = Lmember(nil, v175, v174);
    if (!(v174 == nil)) goto v77;
    stack[-1] = elt(env, 4); /* expt */
    v174 = stack[-6];
    v175 = qcar(v174);
    v174 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 13); /* kernels1 */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = Latsoc(nil, stack[-1], v174);
    if (!(v174 == nil)) goto v150;
    stack[-1] = elt(env, 4); /* expt */
    v174 = stack[-6];
    v175 = qcdr(v174);
    v174 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 13); /* kernels1 */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = Latsoc(nil, stack[-1], v174);
    if (!(v174 == nil)) goto v150;

v77:
    v174 = stack[0];
    fn = elt(env, 11); /* setkorder */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = stack[-6];
    v174 = qcar(v174);
    fn = elt(env, 12); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = stack[-6];
    v174 = qcdr(v174);
    fn = elt(env, 12); /* reorder */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v174 = cons(stack[0], v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    goto v63;

v150:
    v174 = stack[-6];
    v174 = qcar(v174);
    if (v174 == nil) goto v177;
    v175 = stack[-6];
    v174 = elt(env, 5); /* prepf */
    fn = elt(env, 14); /* sqform */
    v174 = (*qfn2(fn))(qenv(fn), v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    v175 = v174;
    goto v178;

v178:
    stack[-1] = v175;
    v174 = qvalue(elt(env, 6)); /* varstack!* */
    v174 = Lmember(nil, v175, v174);
    if (!(v174 == nil)) goto v77;
    v175 = stack[-6];
    v174 = stack[-4];
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    stack[-4] = v174;
    v174 = stack[-1];
    fn = elt(env, 15); /* simp */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    stack[-6] = v174;
    goto v133;

v177:
    v174 = (Lisp_Object)1; /* 0 */
    v175 = v174;
    goto v178;

v16:
    v174 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v174;
    goto v136;

v11:
    v174 = stack[-6];
    fn = elt(env, 16); /* !*d2q */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-8];
    goto v63;
/* error exit handlers */
v176:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-7]; /* alglist!* */
    popv(9);
    return nil;
}



/* Code for ibalp_var!-wclist */

static Lisp_Object CC_ibalp_varKwclist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-wclist");
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
    stack[-3] = nil;
    v167 = stack[-4];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    stack[-2] = v167;
    goto v64;

v64:
    v167 = stack[-2];
    if (v167 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v167 = stack[-2];
    v167 = qcar(v167);
    stack[-1] = v167;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    if (!(v167 == nil)) goto v72;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    stack[0] = qcdr(v167);
    v101 = stack[-4];
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    fn = elt(env, 2); /* delq */
    v167 = (*qfn2(fn))(qenv(fn), v101, v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v167 = (*qfn2(fn))(qenv(fn), stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v167 = stack[-4];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    stack[0] = qcdr(v167);
    v101 = stack[-1];
    v167 = stack[-4];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    fn = elt(env, 2); /* delq */
    v167 = (*qfn2(fn))(qenv(fn), v101, v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v167 = (*qfn2(fn))(qenv(fn), stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v167 = stack[-1];
    fn = elt(env, 4); /* ibalp_getnewwl */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-5] = v167;
    v167 = stack[-5];
    if (v167 == nil) goto v133;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    stack[0] = qcdr(v167);
    v101 = stack[-5];
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v167 = cons(v101, v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v167 = (*qfn2(fn))(qenv(fn), stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v167 = stack[-5];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    stack[0] = qcdr(v167);
    v101 = stack[-1];
    v167 = stack[-5];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v167 = cons(v101, v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v167 = (*qfn2(fn))(qenv(fn), stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    goto v72;

v72:
    v167 = stack[-2];
    v167 = qcdr(v167);
    stack[-2] = v167;
    goto v64;

v133:
    v101 = stack[-1];
    v167 = stack[-3];
    v167 = cons(v101, v167);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-3] = v167;
    goto v72;
/* error exit handlers */
v182:
    popv(7);
    return nil;
}



/* Code for vintersection */

static Lisp_Object CC_vintersection(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v89;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vintersection");
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

v161:
    v111 = stack[-1];
    if (v111 == nil) goto v63;
    v111 = stack[-1];
    v111 = qcar(v111);
    v89 = qcar(v111);
    v111 = stack[0];
    v111 = Lassoc(nil, v89, v111);
    stack[-2] = v111;
    if (v111 == nil) goto v85;
    v111 = stack[-1];
    v111 = qcar(v111);
    v89 = qcdr(v111);
    v111 = stack[-2];
    v111 = qcdr(v111);
    v111 = (Lisp_Object)greaterp2(v89, v111);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v111 = v111 ? lisp_true : nil;
    env = stack[-3];
    if (v111 == nil) goto v136;
    v111 = stack[-2];
    v89 = qcdr(v111);
    v111 = (Lisp_Object)1; /* 0 */
    if (v89 == v111) goto v119;
    v111 = stack[-1];
    v89 = qcdr(v111);
    v111 = stack[0];
    v111 = CC_vintersection(env, v89, v111);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v162 = stack[-2];
        popv(4);
        return cons(v162, v111);
    }

v119:
    v111 = stack[-1];
    v89 = qcdr(v111);
    v111 = stack[0];
    stack[-1] = v89;
    stack[0] = v111;
    goto v161;

v136:
    v111 = stack[-1];
    v111 = qcar(v111);
    v89 = qcdr(v111);
    v111 = (Lisp_Object)1; /* 0 */
    if (v89 == v111) goto v153;
    v111 = stack[-1];
    stack[-2] = qcar(v111);
    v111 = stack[-1];
    v89 = qcdr(v111);
    v111 = stack[0];
    v111 = CC_vintersection(env, v89, v111);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v59 = stack[-2];
        popv(4);
        return cons(v59, v111);
    }

v153:
    v111 = stack[-1];
    v89 = qcdr(v111);
    v111 = stack[0];
    stack[-1] = v89;
    stack[0] = v111;
    goto v161;

v85:
    v111 = stack[-1];
    v89 = qcdr(v111);
    v111 = stack[0];
    stack[-1] = v89;
    stack[0] = v111;
    goto v161;

v63:
    v111 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v111); }
/* error exit handlers */
v143:
    popv(4);
    return nil;
}



/* Code for resume */

static Lisp_Object CC_resume(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v12, v144, v71;
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
    v140 = v1;
    v12 = v0;
/* end of prologue */
    v144 = v140;
    if (v144 == nil) goto v92;
    v144 = v140;
    v144 = qcar(v144);
    v71 = qcar(v144);
    v144 = v140;
    v144 = qcar(v144);
    v144 = qcdr(v144);
    v144 = qcar(v144);
    v140 = qcdr(v140);
    {
        popv(1);
        fn = elt(env, 3); /* amatch */
        return (*qfnn(fn))(qenv(fn), 4, v71, v144, v12, v140);
    }

v92:
    v140 = v12;
    fn = elt(env, 4); /* chk */
    v12 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[0];
    v140 = qvalue(elt(env, 1)); /* t */
    if (v12 == v140) goto v27;
    v140 = nil;
    { popv(1); return onevalue(v140); }

v27:
    v140 = qvalue(elt(env, 2)); /* substitution */
    {
        popv(1);
        fn = elt(env, 5); /* bsubs */
        return (*qfn1(fn))(qenv(fn), v140);
    }
/* error exit handlers */
v57:
    popv(1);
    return nil;
}



/* Code for xlcm */

static Lisp_Object CC_xlcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v132;
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
    goto v90;

v90:
    v41 = stack[-1];
    if (v41 == nil) goto v99;
    v41 = stack[-1];
    v132 = qcar(v41);
    v41 = (Lisp_Object)17; /* 1 */
    if (v132 == v41) goto v99;
    v41 = stack[0];
    if (v41 == nil) goto v57;
    v41 = stack[0];
    v132 = qcar(v41);
    v41 = (Lisp_Object)17; /* 1 */
    if (v132 == v41) goto v57;
    v41 = stack[-1];
    v132 = qcar(v41);
    v41 = stack[0];
    v41 = qcar(v41);
    if (v132 == v41) goto v115;
    v41 = stack[-1];
    v132 = qcar(v41);
    v41 = stack[0];
    v41 = qcar(v41);
    fn = elt(env, 1); /* factorordp */
    v41 = (*qfn2(fn))(qenv(fn), v132, v41);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    if (v41 == nil) goto v91;
    v41 = stack[-1];
    v132 = qcar(v41);
    v41 = stack[-2];
    v41 = cons(v132, v41);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    stack[-2] = v41;
    v41 = stack[-1];
    v41 = qcdr(v41);
    stack[-1] = v41;
    goto v90;

v91:
    v41 = stack[0];
    v132 = qcar(v41);
    v41 = stack[-2];
    v41 = cons(v132, v41);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    stack[-2] = v41;
    v41 = stack[0];
    v41 = qcdr(v41);
    stack[0] = v41;
    goto v90;

v115:
    v41 = stack[-1];
    v132 = qcar(v41);
    v41 = stack[-2];
    v41 = cons(v132, v41);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    stack[-2] = v41;
    v41 = stack[-1];
    v41 = qcdr(v41);
    stack[-1] = v41;
    v41 = stack[0];
    v41 = qcdr(v41);
    stack[0] = v41;
    goto v90;

v57:
    v132 = stack[-2];
    v41 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v132, v41);
    }

v99:
    v132 = stack[-2];
    v41 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v132, v41);
    }
/* error exit handlers */
v2:
    popv(4);
    return nil;
}



/* Code for def_edge */

static Lisp_Object CC_def_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v88, v62, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for def_edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v98 = v1;
    v72 = v0;
/* end of prologue */
    v72 = qcdr(v72);
    v72 = qcar(v72);
    v62 = v72;
    v72 = v62;
    v88 = qcar(v72);
    v72 = v98;
    v72 = Lassoc(nil, v88, v72);
    if (v72 == nil) goto v64;
    v72 = v62;
    v72 = qcdr(v72);
    v88 = v98;
    v72 = Lassoc(nil, v72, v88);
    return onevalue(v72);

v64:
    v72 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v72);
}



/* Code for gcdout */

static Lisp_Object CC_gcdout(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v136, v154;
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
    v43 = qvalue(elt(env, 1)); /* !*modular */
    if (!(v43 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v43 = stack[0];
    if (v43 == nil) goto v63;
    v43 = stack[0];
    fn = elt(env, 3); /* ljet */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    fn = elt(env, 4); /* ord */
    v136 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v43 = (Lisp_Object)1; /* 0 */
    if (v136 == v43) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v43 = stack[0];
    stack[-1] = v43;
    v43 = stack[-1];
    v43 = qcar(v43);
    v43 = qcdr(v43);
    v154 = v43;
    goto v97;

v97:
    v43 = stack[-1];
    if (v43 == nil) goto v181;
    v136 = v154;
    v43 = (Lisp_Object)17; /* 1 */
    if (v136 == v43) goto v181;
    v136 = v154;
    v43 = stack[-1];
    v43 = qcar(v43);
    v43 = qcdr(v43);
    fn = elt(env, 5); /* gcdf!* */
    v43 = (*qfn2(fn))(qenv(fn), v136, v43);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v154 = v43;
    v43 = stack[-1];
    v43 = qcdr(v43);
    stack[-1] = v43;
    goto v97;

v181:
    v136 = v154;
    v43 = (Lisp_Object)17; /* 1 */
    if (v136 == v43) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v43 = stack[0];
    v136 = v154;
    {
        popv(3);
        fn = elt(env, 6); /* pcdiv */
        return (*qfn2(fn))(qenv(fn), v43, v136);
    }

v63:
    v43 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v43); }
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for cons_ordp */

static Lisp_Object MS_CDECL CC_cons_ordp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v80, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v15, v13, v44, v116;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cons_ordp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cons_ordp");
#endif
    if (stack >= stacklimit)
    {
        push3(v80,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v15 = v80;
    v13 = v1;
    v44 = v0;
/* end of prologue */

v90:
    v21 = v44;
    if (v21 == nil) goto v64;
    v21 = v13;
    if (v21 == nil) goto v11;
    v21 = v44;
    v21 = Lconsp(nil, v21);
    env = stack[0];
    if (v21 == nil) goto v131;
    v21 = v13;
    v21 = Lconsp(nil, v21);
    env = stack[0];
    if (v21 == nil) goto v95;
    v21 = v44;
    v116 = qcar(v21);
    v21 = v13;
    v21 = qcar(v21);
    if (equal(v116, v21)) goto v48;
    v21 = v44;
    v21 = qcar(v21);
    v44 = v21;
    v21 = v13;
    v21 = qcar(v21);
    v13 = v21;
    goto v90;

v48:
    v21 = v44;
    v21 = qcdr(v21);
    v44 = v21;
    v21 = v13;
    v21 = qcdr(v21);
    v13 = v21;
    goto v90;

v95:
    v21 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v21); }

v131:
    v21 = v13;
    v21 = Lconsp(nil, v21);
    env = stack[0];
    if (v21 == nil) goto v19;
    v21 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v21); }

v19:
    v21 = v15;
    v15 = v44;
        popv(1);
        return Lapply2(nil, 3, v21, v15, v13);

v11:
    v21 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v21); }

v64:
    v21 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v21); }
}



/* Code for general!-evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKevaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v80, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v77, v78, v159, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "general-evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-evaluate-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v80,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v80);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v80;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v90:
    v75 = stack[-3];
    if (!consp(v75)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v75 = stack[-3];
    v75 = qcar(v75);
    if (!consp(v75)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v77 = stack[-1];
    v75 = (Lisp_Object)1; /* 0 */
    if (v77 == v75) goto v87;
    v75 = stack[-2];
    if (v75 == nil) goto v50;
    v75 = stack[-3];
    v75 = qcar(v75);
    v75 = qcar(v75);
    v77 = qcar(v75);
    v75 = stack[-2];
    if (equal(v77, v75)) goto v139;
    v75 = stack[-3];
    v75 = qcar(v75);
    stack[-4] = qcar(v75);
    v75 = stack[-3];
    v75 = qcar(v75);
    v78 = qcdr(v75);
    v77 = stack[-2];
    v75 = stack[-1];
    stack[0] = CC_generalKevaluateKmodKp(env, 3, v78, v77, v75);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    v75 = stack[-3];
    v78 = qcdr(v75);
    v77 = stack[-2];
    v75 = stack[-1];
    v75 = CC_generalKevaluateKmodKp(env, 3, v78, v77, v75);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-5];
    {
        Lisp_Object v2 = stack[-4];
        Lisp_Object v3 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v2, v3, v75);
    }

v139:
    v75 = stack[-3];
    v75 = qcar(v75);
    v79 = qcdr(v75);
    v75 = stack[-3];
    v75 = qcar(v75);
    v75 = qcar(v75);
    v159 = qcdr(v75);
    v75 = stack[-3];
    v78 = qcdr(v75);
    v77 = stack[-1];
    v75 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* general!-horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v79, v159, v78, v77, v75);
    }

v50:
    v75 = elt(env, 2); /* "Variable=NIL in GENERAL-EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v75);
    }

v87:
    v75 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v75;
    goto v90;
/* error exit handlers */
v112:
    popv(6);
    return nil;
}



/* Code for cl_qb */

static Lisp_Object CC_cl_qb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v155, v20, v181, v137;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_qb");
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
    v137 = nil;
    v129 = (Lisp_Object)1; /* 0 */
    v181 = v129;
    goto v55;

v55:
    v129 = stack[0];
    if (!consp(v129)) goto v87;
    v129 = stack[0];
    v129 = qcar(v129);
    goto v52;

v52:
    stack[-1] = v129;
    v20 = v129;
    v155 = v20;
    v129 = elt(env, 1); /* ex */
    v129 = (v155 == v129 ? lisp_true : nil);
    if (!(v129 == nil)) goto v50;
    v155 = v20;
    v129 = elt(env, 2); /* all */
    v129 = (v155 == v129 ? lisp_true : nil);
    goto v50;

v50:
    if (v129 == nil) { popv(3); return onevalue(v181); }
    v155 = stack[-1];
    v129 = v137;
    if (equal(v155, v129)) goto v14;
    v129 = v181;
    v129 = add1(v129);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    v181 = v129;
    v129 = stack[-1];
    v137 = v129;
    goto v14;

v14:
    v129 = stack[0];
    v129 = qcdr(v129);
    v129 = qcdr(v129);
    v129 = qcar(v129);
    stack[0] = v129;
    goto v55;

v87:
    v129 = stack[0];
    goto v52;
/* error exit handlers */
v15:
    popv(3);
    return nil;
}



/* Code for ofsf_ordatp */

static Lisp_Object CC_ofsf_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v71, v57, v139, v76, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v76 = v1;
    v14 = v0;
/* end of prologue */
    v144 = v14;
    v144 = qcdr(v144);
    v144 = qcar(v144);
    v139 = v144;
    v144 = v76;
    v144 = qcdr(v144);
    v144 = qcar(v144);
    v57 = v144;
    v71 = v139;
    v144 = v57;
    if (equal(v71, v144)) goto v88;
    v144 = v139;
    v71 = v57;
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v144, v71);
    }

v88:
    v144 = v14;
    v144 = qcar(v144);
    v71 = v76;
    v71 = qcar(v71);
    {
        fn = elt(env, 2); /* ofsf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v144, v71);
    }
}



/* Code for naryom */

static Lisp_Object CC_naryom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v7;
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
    v134 = stack[-1];
    v134 = qcar(v134);
    stack[0] = v134;
    v7 = stack[0];
    v134 = elt(env, 1); /* var */
    if (!(v7 == v134)) goto v93;
    v134 = elt(env, 2); /* variance */
    stack[0] = v134;
    goto v93;

v93:
    v7 = stack[0];
    v134 = qvalue(elt(env, 3)); /* valid_om!* */
    v134 = Lassoc(nil, v7, v134);
    stack[-2] = v134;
    v134 = stack[-2];
    if (v134 == nil) goto v48;
    v134 = stack[-2];
    v134 = qcdr(v134);
    v134 = qcar(v134);
    stack[-2] = v134;
    goto v48;

v48:
    v134 = stack[-1];
    v134 = qcdr(v134);
    v134 = qcar(v134);
    if (v134 == nil) goto v94;
    v134 = stack[-1];
    v134 = qcdr(v134);
    v7 = qcar(v134);
    v134 = elt(env, 4); /* multiset */
    if (!(v7 == v134)) goto v94;
    v134 = stack[-1];
    v134 = qcdr(v134);
    v134 = qcar(v134);
    stack[-2] = v134;
    goto v94;

v94:
    v134 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v7 = qvalue(elt(env, 7)); /* indent */
    v134 = (Lisp_Object)33; /* 2 */
    v134 = plus2(v7, v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    qvalue(elt(env, 7)) = v134; /* indent */
    v134 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v134 = stack[-2];
    v134 = Lprinc(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v134 = elt(env, 9); /* """ name=""" */
    v134 = Lprinc(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v134 = stack[0];
    v134 = Lprinc(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v134 = elt(env, 10); /* """>" */
    v134 = Lprinc(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v134 = stack[-1];
    v134 = qcdr(v134);
    v134 = qcdr(v134);
    fn = elt(env, 13); /* multiom */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    v7 = qvalue(elt(env, 7)); /* indent */
    v134 = (Lisp_Object)33; /* 2 */
    v134 = difference2(v7, v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    qvalue(elt(env, 7)) = v134; /* indent */
    v134 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v73;
    v134 = nil;
    { popv(4); return onevalue(v134); }
/* error exit handlers */
v73:
    popv(4);
    return nil;
}



/* Code for ft!:zerop */

static Lisp_Object CC_ftTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v57;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ft:zerop");
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
    v71 = v0;
/* end of prologue */
    stack[0] = v71;
    v57 = (Lisp_Object)161; /* 10 */
    v71 = qvalue(elt(env, 1)); /* !:prec!: */
    v71 = Lexpt(nil, v57, v71);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v71 = times2(stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    stack[0] = v71;
    v57 = stack[0];
    v71 = (Lisp_Object)-799; /* -50 */
    v71 = (Lisp_Object)greaterp2(v57, v71);
    nil = C_nil;
    if (exception_pending()) goto v76;
    v71 = v71 ? lisp_true : nil;
    env = stack[-1];
    if (v71 == nil) goto v158;
    v57 = stack[0];
    v71 = (Lisp_Object)801; /* 50 */
        popv(2);
        return Llessp(nil, v57, v71);

v158:
    v71 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v71); }
/* error exit handlers */
v76:
    popv(2);
    return nil;
}



/* Code for gvarlis1 */

static Lisp_Object CC_gvarlis1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47;
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
    goto v141;

v141:
    v46 = stack[-1];
    if (v46 == nil) goto v63;
    v46 = stack[-1];
    v47 = qcar(v46);
    v46 = stack[0];
    fn = elt(env, 1); /* gvar1 */
    v47 = (*qfn2(fn))(qenv(fn), v47, v46);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    v46 = stack[-2];
    v46 = cons(v47, v46);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    stack[-2] = v46;
    v46 = stack[-1];
    v46 = qcdr(v46);
    stack[-1] = v46;
    goto v141;

v63:
    v46 = stack[0];
    v47 = v46;
    goto v64;

v64:
    v46 = stack[-2];
    if (v46 == nil) { popv(4); return onevalue(v47); }
    v46 = stack[-2];
    v46 = qcar(v46);
    fn = elt(env, 2); /* union */
    v46 = (*qfn2(fn))(qenv(fn), v46, v47);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    v47 = v46;
    v46 = stack[-2];
    v46 = qcdr(v46);
    stack[-2] = v46;
    goto v64;
/* error exit handlers */
v83:
    popv(4);
    return nil;
}



/* Code for assert_typedefstat */

static Lisp_Object MS_CDECL CC_assert_typedefstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v106, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_typedefstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_typedefstat");
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
    fn = elt(env, 17); /* scan */
    v185 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    stack[0] = v185;
    fn = elt(env, 17); /* scan */
    v185 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v106 = qvalue(elt(env, 1)); /* cursym!* */
    v185 = elt(env, 2); /* delim */
    v185 = Lflagp(nil, v106, v185);
    env = stack[-4];
    if (v185 == nil) goto v19;
    v185 = qvalue(elt(env, 3)); /* !*assert */
    if (v185 == nil) goto v56;
    v185 = qvalue(elt(env, 5)); /* !*msg */
    if (v185 == nil) goto v49;
    v185 = qvalue(elt(env, 5)); /* !*msg */
    if (v185 == nil) goto v49;
    stack[-1] = elt(env, 6); /* "***" */
    v29 = elt(env, 7); /* "type" */
    v106 = stack[0];
    v185 = elt(env, 8); /* "is not checked" */
    v185 = list3(v29, v106, v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    fn = elt(env, 18); /* lpriw */
    v185 = (*qfn2(fn))(qenv(fn), stack[-1], v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    goto v49;

v49:
    v185 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v185); }

v56:
    v185 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v185); }

v19:
    v106 = qvalue(elt(env, 1)); /* cursym!* */
    v185 = elt(env, 9); /* checked */
    if (v106 == v185) goto v5;
    v185 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v185 == nil)) goto v21;
    v106 = elt(env, 11); /* "expecting 'checked by' in typedef but found" 
*/
    v185 = qvalue(elt(env, 1)); /* cursym!* */
    v185 = list2(v106, v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    goto v21;

v21:
    v185 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    goto v5;

v5:
    fn = elt(env, 17); /* scan */
    v106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v185 = elt(env, 12); /* by */
    if (v106 == v185) goto v43;
    v185 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v185 == nil)) goto v73;
    v106 = elt(env, 13); /* "expecting 'by' in typedef but found" */
    v185 = qvalue(elt(env, 1)); /* cursym!* */
    v185 = list2(v106, v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    goto v73;

v73:
    v185 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    goto v43;

v43:
    fn = elt(env, 17); /* scan */
    v185 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    stack[-3] = v185;
    fn = elt(env, 17); /* scan */
    v106 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    v185 = elt(env, 2); /* delim */
    v185 = Lflagp(nil, v106, v185);
    env = stack[-4];
    if (!(v185 == nil)) goto v112;
    v185 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v185 == nil)) goto v143;
    v106 = elt(env, 14); /* "expecting end of typedef but found" */
    v185 = qvalue(elt(env, 1)); /* cursym!* */
    v185 = list2(v106, v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    goto v143;

v143:
    v185 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    goto v112;

v112:
    v185 = qvalue(elt(env, 3)); /* !*assert */
    if (v185 == nil) goto v34;
    stack[-2] = elt(env, 15); /* put */
    v185 = stack[0];
    stack[-1] = Lmkquote(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-4];
    stack[0] = elt(env, 16); /* (quote assert_checkfn) */
    v185 = stack[-3];
    v185 = Lmkquote(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v186;
    {
        Lisp_Object v179 = stack[-2];
        Lisp_Object v187 = stack[-1];
        Lisp_Object v58 = stack[0];
        popv(5);
        return list4(v179, v187, v58, v185);
    }

v34:
    v185 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v185); }
/* error exit handlers */
v186:
    popv(5);
    return nil;
}



/* Code for fs!:prin1 */

static Lisp_Object CC_fsTprin1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54;
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
    v53 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v53;
    v54 = stack[0];
    v53 = (Lisp_Object)1; /* 0 */
    v54 = *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL)));
    v53 = elt(env, 2); /* (1 . 1) */
    if (equal(v54, v53)) goto v64;
    v53 = elt(env, 3); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v54 = stack[0];
    v53 = (Lisp_Object)1; /* 0 */
    v53 = *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL)));
    fn = elt(env, 13); /* sqprint */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v53 = elt(env, 4); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    goto v64;

v64:
    v53 = stack[0];
    fn = elt(env, 14); /* fs!:null!-angle */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    if (v53 == nil) goto v76;
    v54 = stack[0];
    v53 = (Lisp_Object)1; /* 0 */
    v54 = *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL)));
    v53 = elt(env, 2); /* (1 . 1) */
    if (!(equal(v54, v53))) goto v140;
    v53 = elt(env, 11); /* "1" */
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    goto v140;

v140:
    v53 = nil;
    { popv(5); return onevalue(v53); }

v76:
    v54 = stack[0];
    v53 = (Lisp_Object)17; /* 1 */
    v53 = *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v53 = elt(env, 5); /* "[" */
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v54 = stack[0];
    v53 = (Lisp_Object)33; /* 2 */
    v53 = *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL)));
    stack[-2] = v53;
    v53 = (Lisp_Object)1; /* 0 */
    stack[0] = v53;
    goto v116;

v116:
    v54 = (Lisp_Object)113; /* 7 */
    v53 = stack[0];
    v53 = difference2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v53 = Lminusp(nil, v53);
    env = stack[-4];
    if (v53 == nil) goto v147;
    v53 = elt(env, 10); /* "]" */
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    goto v140;

v147:
    v54 = stack[-2];
    v53 = stack[0];
    v54 = *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL)));
    stack[-1] = v54;
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v68;
    v54 = stack[-1];
    v53 = (Lisp_Object)1; /* 0 */
    v53 = (Lisp_Object)lessp2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v53 = v53 ? lisp_true : nil;
    env = stack[-4];
    if (v53 == nil) goto v9;
    v53 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v53;
    v53 = elt(env, 7); /* "-" */
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v53 = stack[-1];
    v53 = negate(v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[-1] = v53;
    goto v9;

v9:
    v53 = stack[-3];
    if (!(v53 == nil)) goto v143;
    v53 = elt(env, 8); /* "+" */
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    goto v143;

v143:
    v54 = stack[-1];
    v53 = (Lisp_Object)17; /* 1 */
    if (v54 == v53) goto v189;
    v53 = stack[-1];
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    goto v189;

v189:
    v53 = qvalue(elt(env, 6)); /* nil */
    stack[-3] = v53;
    v54 = qvalue(elt(env, 9)); /* fourier!-name!* */
    v53 = stack[0];
    v53 = *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    goto v68;

v68:
    v53 = stack[0];
    v53 = add1(v53);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    stack[0] = v53;
    goto v116;
/* error exit handlers */
v188:
    popv(5);
    return nil;
}



/* Code for dpmat_coldegs */

static Lisp_Object CC_dpmat_coldegs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dpmat_coldegs");
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
    v4 = v65;
    v65 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v65 = (*qfn2(fn))(qenv(fn), v4, v65);
    errexit();
    v65 = qcar(v65);
    return onevalue(v65);
}



setup_type const u20_setup[] =
{
    {"mod_eval_uni_poly",       too_few_2,      CC_mod_eval_uni_poly,wrong_no_2},
    {"general-modular-expt",    too_few_2,      CC_generalKmodularKexpt,wrong_no_2},
    {"rootrnd",                 CC_rootrnd,     too_many_1,    wrong_no_1},
    {"reduce-degree-mod-p",     too_few_2,      CC_reduceKdegreeKmodKp,wrong_no_2},
    {"pasf_mkpos",              CC_pasf_mkpos,  too_many_1,    wrong_no_1},
    {"reln",                    too_few_2,      CC_reln,       wrong_no_2},
    {"evdif",                   too_few_2,      CC_evdif,      wrong_no_2},
    {":dmtimeslst",             CC_Tdmtimeslst, too_many_1,    wrong_no_1},
    {"formatfort",              CC_formatfort,  too_many_1,    wrong_no_1},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"assert_install1",         CC_assert_install1,too_many_1, wrong_no_1},
    {"sc_rep",                  CC_sc_rep,      too_many_1,    wrong_no_1},
    {"b:ordexp",                too_few_2,      CC_bTordexp,   wrong_no_2},
    {"ibalp_tvb",               too_few_2,      CC_ibalp_tvb,  wrong_no_2},
    {"ctx_union",               too_few_2,      CC_ctx_union,  wrong_no_2},
    {"makeset",                 CC_makeset,     too_many_1,    wrong_no_1},
    {"testpr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_testpr},
    {"random",                  CC_random,      too_many_1,    wrong_no_1},
    {"convprc2",                too_few_2,      CC_convprc2,   wrong_no_2},
    {"physopordchk",            too_few_2,      CC_physopordchk,wrong_no_2},
    {"prop-simp1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_propKsimp1},
    {"assert_stat-parse",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_statKparse},
    {"sf_member",               too_few_2,      CC_sf_member,  wrong_no_2},
    {"extract_dummy_ids",       CC_extract_dummy_ids,too_many_1,wrong_no_1},
    {"resimpf",                 CC_resimpf,     too_many_1,    wrong_no_1},
    {"ofsf_smupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smupdknowl},
    {"mo_comp",                 CC_mo_comp,     too_many_1,    wrong_no_1},
    {"ofsf_prepat",             CC_ofsf_prepat, too_many_1,    wrong_no_1},
    {"subf",                    too_few_2,      CC_subf,       wrong_no_2},
    {"ibalp_var-wclist",        CC_ibalp_varKwclist,too_many_1,wrong_no_1},
    {"vintersection",           too_few_2,      CC_vintersection,wrong_no_2},
    {"resume",                  too_few_2,      CC_resume,     wrong_no_2},
    {"xlcm",                    too_few_2,      CC_xlcm,       wrong_no_2},
    {"def_edge",                too_few_2,      CC_def_edge,   wrong_no_2},
    {"gcdout",                  CC_gcdout,      too_many_1,    wrong_no_1},
    {"cons_ordp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cons_ordp},
    {"general-evaluate-mod-p",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKevaluateKmodKp},
    {"cl_qb",                   CC_cl_qb,       too_many_1,    wrong_no_1},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"naryom",                  CC_naryom,      too_many_1,    wrong_no_1},
    {"ft:zerop",                CC_ftTzerop,    too_many_1,    wrong_no_1},
    {"gvarlis1",                too_few_2,      CC_gvarlis1,   wrong_no_2},
    {"assert_typedefstat",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_typedefstat},
    {"fs:prin1",                CC_fsTprin1,    too_many_1,    wrong_no_1},
    {"dpmat_coldegs",           CC_dpmat_coldegs,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u20", (two_args *)"5659 1498583 7199532", 0}
};

/* end of generated code */
