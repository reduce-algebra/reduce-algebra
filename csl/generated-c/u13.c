
/* $destdir\u13.c        Machine generated C code */

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


/* Code for pa_coinc_split */

static Lisp_Object CC_pa_coinc_split(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v73, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_coinc_split");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    stack[-6] = nil;
    v72 = stack[-9];
    v72 = qcdr(v72);
    fn = elt(env, 3); /* upbve */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-4] = v72;
    v72 = stack[-4];
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = Lmkvect(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-10] = v72;
    v72 = stack[-4];
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = Lmkvect(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-7] = v72;
    v72 = stack[-4];
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = Lmkvect(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-5] = v72;
    v72 = (Lisp_Object)1; /* 0 */
    stack[-3] = v72;
    v72 = stack[-9];
    v72 = qcar(v72);
    stack[-2] = v72;
    goto v76;

v76:
    v72 = stack[-2];
    if (v72 == nil) goto v77;
    v72 = stack[-2];
    v72 = qcar(v72);
    stack[-1] = v72;
    v72 = stack[-3];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-3] = v72;
    stack[0] = stack[-10];
    v72 = stack[-1];
    v73 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL))) = v72;
    v72 = stack[-2];
    v72 = qcdr(v72);
    stack[-2] = v72;
    goto v76;

v77:
    v72 = (Lisp_Object)1; /* 0 */
    stack[-3] = v72;
    v72 = stack[-8];
    v72 = qcar(v72);
    stack[-2] = v72;
    goto v78;

v78:
    v72 = stack[-2];
    if (v72 == nil) goto v79;
    v72 = stack[-2];
    v72 = qcar(v72);
    stack[-1] = v72;
    v72 = stack[-3];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-3] = v72;
    stack[0] = stack[-7];
    v72 = stack[-1];
    v73 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL))) = v72;
    v72 = stack[-2];
    v72 = qcdr(v72);
    stack[-2] = v72;
    goto v78;

v79:
    v72 = (Lisp_Object)17; /* 1 */
    stack[-3] = v72;
    goto v80;

v80:
    v73 = stack[-4];
    v72 = stack[-3];
    v72 = difference2(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = Lminusp(nil, v72);
    env = stack[-11];
    if (v72 == nil) goto v81;
    v73 = stack[-6];
    v72 = elt(env, 2); /* lambda_l9cw2t_2 */
    fn = elt(env, 4); /* sort */
    v72 = (*qfn2(fn))(qenv(fn), v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-6] = v72;
    v72 = stack[-6];
    stack[-3] = v72;
    v72 = stack[-3];
    if (v72 == nil) goto v82;
    v72 = stack[-3];
    v72 = qcar(v72);
    v72 = qcdr(v72);
    v72 = qcar(v72);
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-1] = v72;
    stack[-2] = v72;
    goto v83;

v83:
    v72 = stack[-3];
    v72 = qcdr(v72);
    stack[-3] = v72;
    v72 = stack[-3];
    if (v72 == nil) goto v84;
    stack[0] = stack[-1];
    v72 = stack[-3];
    v72 = qcar(v72);
    v72 = qcdr(v72);
    v72 = qcar(v72);
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = Lrplacd(nil, stack[0], v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v83;

v84:
    v72 = stack[-2];
    v73 = v72;
    goto v85;

v85:
    v72 = stack[-5];
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-5] = v72;
    v72 = stack[-6];
    stack[-3] = v72;
    v72 = stack[-3];
    if (v72 == nil) goto v86;
    v72 = stack[-3];
    v72 = qcar(v72);
    v73 = v72;
    v73 = qcar(v73);
    v72 = qcdr(v72);
    v72 = qcdr(v72);
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-1] = v72;
    stack[-2] = v72;
    goto v87;

v87:
    v72 = stack[-3];
    v72 = qcdr(v72);
    stack[-3] = v72;
    v72 = stack[-3];
    if (v72 == nil) goto v88;
    stack[0] = stack[-1];
    v72 = stack[-3];
    v72 = qcar(v72);
    v73 = v72;
    v73 = qcar(v73);
    v72 = qcdr(v72);
    v72 = qcdr(v72);
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = Lrplacd(nil, stack[0], v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = stack[-1];
    v72 = qcdr(v72);
    stack[-1] = v72;
    goto v87;

v88:
    v72 = stack[-2];
    goto v89;

v89:
    v73 = v72;
    v72 = stack[-5];
    popv(12);
    return cons(v73, v72);

v86:
    v72 = qvalue(elt(env, 1)); /* nil */
    goto v89;

v82:
    v72 = qvalue(elt(env, 1)); /* nil */
    v73 = v72;
    goto v85;

v81:
    stack[-1] = stack[-10];
    v72 = stack[-9];
    stack[0] = qcdr(v72);
    v72 = stack[-3];
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v72/(16/CELL)));
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-2] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v72/(16/CELL)));
    stack[-1] = stack[-7];
    v72 = stack[-8];
    stack[0] = qcdr(v72);
    v72 = stack[-3];
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v72/(16/CELL)));
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v72/(16/CELL)));
    v72 = cons(stack[-2], v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v74 = v72;
    v73 = v74;
    v72 = stack[-6];
    v72 = Lassoc(nil, v73, v72);
    stack[-1] = v72;
    if (v72 == nil) goto v90;
    v72 = stack[-1];
    stack[0] = qcdr(v72);
    v72 = stack[-1];
    v72 = qcdr(v72);
    v72 = qcdr(v72);
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = Lrplacd(nil, stack[0], v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[0] = stack[-5];
    v72 = stack[-3];
    v73 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = stack[-1];
    v72 = qcdr(v72);
    v72 = qcar(v72);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL))) = v72;
    goto v91;

v91:
    v72 = stack[-3];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-3] = v72;
    goto v80;

v90:
    v73 = stack[-3];
    v72 = (Lisp_Object)17; /* 1 */
    v72 = list2star(v74, v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-1] = v72;
    v73 = stack[-1];
    v72 = stack[-6];
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    stack[-6] = v72;
    stack[0] = stack[-5];
    v72 = stack[-3];
    v73 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-11];
    v72 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL))) = v72;
    goto v91;
/* error exit handlers */
v75:
    popv(12);
    return nil;
}



/* Code for lambda_l9cw2t_2 */

static Lisp_Object CC_lambda_l9cw2t_2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9cw2t_2");
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
    v98 = stack[-1];
    v98 = qcar(v98);
    v99 = qcar(v98);
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v98 = (Lisp_Object)lessp2(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v98 = v98 ? lisp_true : nil;
    env = stack[-2];
    if (v98 == nil) goto v100;
    v98 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v98); }

v100:
    v98 = stack[0];
    v98 = qcar(v98);
    v99 = qcar(v98);
    v98 = stack[-1];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v98 = (Lisp_Object)lessp2(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v98 = v98 ? lisp_true : nil;
    env = stack[-2];
    if (v98 == nil) goto v101;
    v98 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v98); }

v101:
    v98 = stack[-1];
    v98 = qcar(v98);
    v99 = qcdr(v98);
    v98 = stack[0];
    v98 = qcar(v98);
    v98 = qcdr(v98);
        popv(3);
        return Lleq(nil, v99, v98);
/* error exit handlers */
v68:
    popv(3);
    return nil;
}



/* Code for modquotient!: */

static Lisp_Object CC_modquotientT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modquotient:");
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
    v103 = v1;
    v96 = v0;
/* end of prologue */
    stack[0] = qcdr(v96);
    v96 = v103;
    v96 = qcdr(v96);
    fn = elt(env, 1); /* general!-modular!-reciprocal */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    fn = elt(env, 2); /* general!-modular!-times */
    v96 = (*qfn2(fn))(qenv(fn), stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v96);
    }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for general!-times!-mod!-p */

static Lisp_Object CC_generalKtimesKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-times-mod-p");
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
    v132 = stack[-2];
    if (v132 == nil) goto v38;
    v132 = stack[-1];
    if (v132 == nil) goto v38;
    v132 = stack[-2];
    if (!consp(v132)) goto v134;
    v132 = stack[-2];
    v132 = qcar(v132);
    if (!consp(v132)) goto v134;
    v132 = stack[-1];
    if (!consp(v132)) goto v135;
    v132 = stack[-1];
    v132 = qcar(v132);
    if (!consp(v132)) goto v135;
    v132 = stack[-2];
    v132 = qcar(v132);
    v132 = qcar(v132);
    v133 = qcar(v132);
    v132 = stack[-1];
    v132 = qcar(v132);
    v132 = qcar(v132);
    v132 = qcar(v132);
    if (equal(v133, v132)) goto v136;
    v132 = stack[-2];
    v132 = qcar(v132);
    v132 = qcar(v132);
    v133 = qcar(v132);
    v132 = stack[-1];
    v132 = qcar(v132);
    v132 = qcar(v132);
    v132 = qcar(v132);
    fn = elt(env, 2); /* ordop */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    if (v132 == nil) goto v51;
    v132 = stack[-2];
    v132 = qcar(v132);
    stack[-3] = qcar(v132);
    v132 = stack[-2];
    v132 = qcar(v132);
    v133 = qcdr(v132);
    v132 = stack[-1];
    stack[0] = CC_generalKtimesKmodKp(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v132 = stack[-2];
    v133 = qcdr(v132);
    v132 = stack[-1];
    v132 = CC_generalKtimesKmodKp(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    {
        Lisp_Object v41 = stack[-3];
        Lisp_Object v137 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v41, v137, v132);
    }

v51:
    v132 = stack[-1];
    v132 = qcar(v132);
    stack[-3] = qcar(v132);
    v133 = stack[-2];
    v132 = stack[-1];
    v132 = qcar(v132);
    v132 = qcdr(v132);
    stack[0] = CC_generalKtimesKmodKp(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v133 = stack[-2];
    v132 = stack[-1];
    v132 = qcdr(v132);
    v132 = CC_generalKtimesKmodKp(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    {
        Lisp_Object v138 = stack[-3];
        Lisp_Object v139 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v138, v139, v132);
    }

v136:
    v132 = stack[-2];
    v133 = qcar(v132);
    v132 = stack[-1];
    fn = elt(env, 4); /* general!-times!-term!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v132 = stack[-1];
    v133 = qcar(v132);
    v132 = stack[-2];
    v132 = qcdr(v132);
    fn = elt(env, 4); /* general!-times!-term!-mod!-p */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    fn = elt(env, 5); /* general!-plus!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v132 = stack[-2];
    v133 = qcdr(v132);
    v132 = stack[-1];
    v132 = qcdr(v132);
    v132 = CC_generalKtimesKmodKp(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    {
        Lisp_Object v40 = stack[0];
        popv(5);
        fn = elt(env, 5); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v40, v132);
    }

v135:
    v133 = stack[-2];
    v132 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* gen!-mult!-by!-const!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v133, v132);
    }

v134:
    v133 = stack[-1];
    v132 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* gen!-mult!-by!-const!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v133, v132);
    }

v38:
    v132 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v132); }
/* error exit handlers */
v39:
    popv(5);
    return nil;
}



/* Code for qqe_simplterm */

static Lisp_Object CC_qqe_simplterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v145, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplterm");
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
    v69 = stack[0];
    if (!consp(v69)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v69 = stack[0];
    fn = elt(env, 4); /* qqe_op */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    v67 = v69;
    v145 = v67;
    v69 = elt(env, 1); /* (ltail rtail) */
    v69 = Lmemq(nil, v145, v69);
    if (v69 == nil) goto v71;
    v69 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* qqe_simplterm!-tail */
        return (*qfn1(fn))(qenv(fn), v69);
    }

v71:
    v145 = v67;
    v69 = elt(env, 2); /* (lhead rhead) */
    v69 = Lmemq(nil, v145, v69);
    if (v69 == nil) goto v129;
    v69 = stack[0];
    {
        popv(2);
        fn = elt(env, 6); /* qqe_simplterm!-head */
        return (*qfn1(fn))(qenv(fn), v69);
    }

v129:
    v145 = v67;
    v69 = elt(env, 3); /* (ladd radd) */
    v69 = Lmemq(nil, v145, v69);
    if (v69 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v69 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* qqe_simplterm!-add */
        return (*qfn1(fn))(qenv(fn), v69);
    }
/* error exit handlers */
v146:
    popv(2);
    return nil;
}



/* Code for mkzl */

static Lisp_Object CC_mkzl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkzl");
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
    goto v64;

v64:
    v76 = stack[0];
    v77 = (Lisp_Object)17; /* 1 */
    if (v76 == v77) goto v5;
    v76 = (Lisp_Object)1; /* 0 */
    v77 = stack[-1];
    v77 = cons(v76, v77);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    stack[-1] = v77;
    v77 = stack[0];
    v77 = sub1(v77);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-2];
    stack[0] = v77;
    goto v64;

v5:
    v77 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v77);
    }
/* error exit handlers */
v135:
    popv(3);
    return nil;
}



/* Code for numpoly_nullp */

static Lisp_Object CC_numpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v96 = v0;
/* end of prologue */
    v103 = v96;
    v103 = (v103 == nil ? lisp_true : nil);
    if (!(v103 == nil)) return onevalue(v103);
    v103 = v96;
    v96 = (Lisp_Object)1; /* 0 */
    v96 = (v103 == v96 ? lisp_true : nil);
    return onevalue(v96);
}



/* Code for matrixrowrd */

static Lisp_Object MS_CDECL CC_matrixrowrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrowrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowrd");
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
    fn = elt(env, 2); /* mathml */
    v144 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    v100 = v144;
    v144 = v100;
    if (v144 == nil) goto v5;
    stack[0] = v100;
    v144 = CC_matrixrowrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v130;
    {
        Lisp_Object v131 = stack[0];
        popv(2);
        return cons(v131, v144);
    }

v5:
    v144 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v144); }
/* error exit handlers */
v130:
    popv(2);
    return nil;
}



/* Code for dipilcomb1 */

static Lisp_Object MS_CDECL CC_dipilcomb1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, Lisp_Object v57,
                         Lisp_Object v52, Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v196, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "dipilcomb1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipilcomb1");
#endif
    if (stack >= stacklimit)
    {
        push6(v38,v52,v57,v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v142,v57,v52,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v38;
    stack[-11] = v52;
    stack[-12] = v57;
    stack[-13] = v142;
    stack[-14] = v1;
    stack[-15] = v0;
/* end of prologue */
    v195 = qvalue(elt(env, 1)); /* !*gcd */
    stack[-1] = v195;
    stack[-16] = nil;
    stack[-9] = nil;
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v196 = stack[-14];
    v195 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (v195 == nil) goto v94;
    v196 = stack[-11];
    v195 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (v195 == nil) goto v94;
    v195 = stack[-1];
    goto v148;

v148:
    qvalue(elt(env, 1)) = v195; /* !*gcd */
    v195 = stack[-13];
    fn = elt(env, 5); /* evzero!? */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v195 = (v195 == nil ? lisp_true : nil);
    stack[-7] = v195;
    v195 = stack[-10];
    fn = elt(env, 5); /* evzero!? */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v195 = (v195 == nil ? lisp_true : nil);
    stack[-6] = v195;
    v195 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v195;
    stack[-5] = v195;
    v195 = qvalue(elt(env, 3)); /* nil */
    stack[-8] = v195;
    stack[-2] = v195;
    stack[-3] = v195;
    goto v131;

v131:
    v195 = stack[-5];
    if (v195 == nil) goto v199;
    v195 = stack[-15];
    if (v195 == nil) goto v200;
    v195 = stack[-15];
    v195 = qcar(v195);
    stack[-16] = v195;
    v195 = stack[-7];
    if (v195 == nil) goto v201;
    v196 = stack[-16];
    v195 = stack[-13];
    fn = elt(env, 6); /* evsum */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    stack[-16] = v195;
    goto v201;

v201:
    v195 = qvalue(elt(env, 3)); /* nil */
    stack[-5] = v195;
    goto v199;

v199:
    v195 = stack[-4];
    if (v195 == nil) goto v202;
    v195 = stack[-12];
    if (v195 == nil) goto v55;
    v195 = stack[-12];
    v195 = qcar(v195);
    stack[-9] = v195;
    v195 = stack[-6];
    if (v195 == nil) goto v203;
    v196 = stack[-9];
    v195 = stack[-10];
    fn = elt(env, 6); /* evsum */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    stack[-9] = v195;
    goto v203;

v203:
    v195 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v195;
    goto v202;

v202:
    v196 = stack[-16];
    v195 = stack[-9];
    fn = elt(env, 7); /* evcomp */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v197 = v195;
    v196 = v197;
    v195 = (Lisp_Object)17; /* 1 */
    if (v196 == v195) goto v204;
    v196 = v197;
    v195 = (Lisp_Object)-15; /* -1 */
    if (v196 == v195) goto v205;
    v195 = qvalue(elt(env, 1)); /* !*gcd */
    if (v195 == nil) goto v206;
    v195 = stack[-15];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (v195 == nil) goto v207;
    v195 = stack[-12];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (!(v195 == nil)) goto v206;

v207:
    v195 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v195; /* !*gcd */
    goto v206;

v206:
    v195 = stack[-15];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = stack[-14];
    fn = elt(env, 8); /* bcprod */
    stack[-1] = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v195 = stack[-12];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = stack[-11];
    fn = elt(env, 8); /* bcprod */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    fn = elt(env, 9); /* bcsum */
    v195 = (*qfn2(fn))(qenv(fn), stack[-1], v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    stack[-1] = v195;
    v195 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (!(v195 == nil)) goto v208;
    v197 = stack[-16];
    v196 = stack[-1];
    v195 = qvalue(elt(env, 3)); /* nil */
    v195 = list2star(v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v195 = Lnconc(nil, stack[-2], v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    stack[-3] = v195;
    v195 = stack[-3];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    stack[-2] = v195;
    goto v208;

v208:
    v195 = stack[-15];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    stack[-15] = v195;
    v195 = stack[-12];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    stack[-12] = v195;
    v195 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v195;
    stack[-5] = v195;
    goto v133;

v133:
    v195 = stack[-8];
    if (!(v195 == nil)) goto v131;
    v195 = stack[-3];
    stack[-2] = v195;
    stack[-8] = v195;
    goto v131;

v205:
    v195 = qvalue(elt(env, 1)); /* !*gcd */
    if (v195 == nil) goto v209;
    v195 = stack[-12];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (!(v195 == nil)) goto v209;
    v195 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v195; /* !*gcd */
    goto v209;

v209:
    v195 = stack[-12];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = stack[-11];
    fn = elt(env, 8); /* bcprod */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    stack[-1] = v195;
    v195 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (!(v195 == nil)) goto v210;
    v197 = stack[-9];
    v196 = stack[-1];
    v195 = qvalue(elt(env, 3)); /* nil */
    v195 = list2star(v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v195 = Lnconc(nil, stack[-2], v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    stack[-3] = v195;
    v195 = stack[-3];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    stack[-2] = v195;
    goto v210;

v210:
    v195 = stack[-12];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    stack[-12] = v195;
    v195 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v195;
    goto v133;

v204:
    v195 = qvalue(elt(env, 1)); /* !*gcd */
    if (v195 == nil) goto v211;
    v195 = stack[-15];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (!(v195 == nil)) goto v211;
    v195 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v195; /* !*gcd */
    goto v211;

v211:
    v195 = stack[-15];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = stack[-14];
    fn = elt(env, 8); /* bcprod */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    stack[-1] = v195;
    v195 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    if (!(v195 == nil)) goto v29;
    v197 = stack[-16];
    v196 = stack[-1];
    v195 = qvalue(elt(env, 3)); /* nil */
    v195 = list2star(v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v195 = Lnconc(nil, stack[-2], v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    stack[-3] = v195;
    v195 = stack[-3];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    stack[-2] = v195;
    goto v29;

v29:
    v195 = stack[-15];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    stack[-15] = v195;
    v195 = qvalue(elt(env, 2)); /* t */
    stack[-5] = v195;
    goto v133;

v55:
    stack[-1] = stack[-8];
    stack[-2] = stack[-15];
    v197 = stack[-13];
    v196 = stack[-14];
    v195 = qvalue(elt(env, 3)); /* nil */
    v195 = list2star(v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    fn = elt(env, 11); /* dipprod */
    v195 = (*qfn2(fn))(qenv(fn), stack[-2], v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v195 = Lnconc(nil, stack[-1], v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    goto v130;

v130:
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(18); return onevalue(v195); }

v200:
    v195 = stack[-12];
    if (v195 == nil) goto v136;
    stack[-1] = stack[-8];
    stack[-2] = stack[-12];
    v197 = stack[-10];
    v196 = stack[-11];
    v195 = qvalue(elt(env, 3)); /* nil */
    v195 = list2star(v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    fn = elt(env, 11); /* dipprod */
    v195 = (*qfn2(fn))(qenv(fn), stack[-2], v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    v195 = Lnconc(nil, stack[-1], v195);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-17];
    goto v130;

v136:
    v195 = stack[-8];
    goto v130;

v94:
    v195 = nil;
    goto v148;
/* error exit handlers */
v198:
    env = stack[-17];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(18);
    return nil;
}



/* Code for scalprod */

static Lisp_Object CC_scalprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scalprod");
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
    v212 = stack[-1];
    if (!(v212 == nil)) goto v20;
    v212 = stack[0];
    if (!(v212 == nil)) goto v20;
    v213 = qvalue(elt(env, 1)); /* nil */
    v212 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v213, v212);

v20:
    v212 = stack[-1];
    if (v212 == nil) goto v185;
    v212 = stack[0];
    if (v212 == nil) goto v185;
    v212 = stack[-1];
    v213 = qcar(v212);
    v212 = stack[0];
    v212 = qcar(v212);
    fn = elt(env, 5); /* multsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-3];
    v212 = stack[-1];
    v213 = qcdr(v212);
    v212 = stack[0];
    v212 = qcdr(v212);
    v212 = CC_scalprod(env, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-3];
    {
        Lisp_Object v215 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* addsq */
        return (*qfn2(fn))(qenv(fn), v215, v212);
    }

v185:
    v212 = elt(env, 2); /* "Matrix mismatch" */
    v213 = v212;
    v212 = v213;
    qvalue(elt(env, 3)) = v212; /* errmsg!* */
    v212 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v212 == nil)) goto v77;
    v212 = v213;
    fn = elt(env, 7); /* lprie */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-3];
    goto v77;

v77:
    v212 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v212 = nil;
    { popv(4); return onevalue(v212); }
/* error exit handlers */
v214:
    popv(4);
    return nil;
}



/* Code for gsugar */

static Lisp_Object CC_gsugar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsugar");
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
    v67 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v67 == nil) goto v38;
    v67 = stack[0];
    if (v67 == nil) goto v4;
    v67 = stack[0];
    v67 = qcdr(v67);
    v67 = qcdr(v67);
    v67 = qcdr(v67);
    v67 = qcar(v67);
    if (v67 == nil) goto v4;
    v217 = stack[0];
    v67 = elt(env, 2); /* sugar */
    fn = elt(env, 4); /* vdpgetprop */
    v67 = (*qfn2(fn))(qenv(fn), v217, v67);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    goto v5;

v5:
    stack[-1] = v67;
    v67 = stack[-1];
    if (!(v67 == nil)) { popv(3); return onevalue(v67); }
    v217 = elt(env, 3); /* "*** missing sugar" */
    v67 = stack[0];
    v67 = list2(v217, v67);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v67 = Lprint(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    fn = elt(env, 5); /* backtrace */
    v67 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v67 = stack[0];
    fn = elt(env, 6); /* vdptdeg */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    stack[-1] = v67;
    v217 = stack[0];
    v67 = stack[-1];
    fn = elt(env, 7); /* gsetsugar */
    v67 = (*qfn2(fn))(qenv(fn), v217, v67);
    nil = C_nil;
    if (exception_pending()) goto v66;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v4:
    v67 = (Lisp_Object)1; /* 0 */
    goto v5;

v38:
    v67 = nil;
    { popv(3); return onevalue(v67); }
/* error exit handlers */
v66:
    popv(3);
    return nil;
}



/* Code for wedgepf */

static Lisp_Object CC_wedgepf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgepf");
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
    v149 = v1;
    v154 = v0;
/* end of prologue */
    stack[0] = v154;
    fn = elt(env, 1); /* !*pf2wedgepf */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    fn = elt(env, 2); /* wedgepf2 */
    v149 = (*qfn2(fn))(qenv(fn), stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*wedgepf2pf */
        return (*qfn1(fn))(qenv(fn), v149);
    }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for ncoeffs */

static Lisp_Object CC_ncoeffs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v215;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ncoeffs");
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
    v215 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v214 = (Lisp_Object)1; /* 0 */
    stack[-2] = v214;
    v214 = v215;
    stack[-1] = v214;
    goto v60;

v60:
    v214 = stack[-1];
    if (v214 == nil) goto v219;
    v214 = stack[-1];
    v214 = qcar(v214);
    stack[0] = v214;
    v214 = stack[0];
    v214 = qcar(v214);
    stack[-4] = v214;
    goto v76;

v76:
    v215 = stack[-2];
    v214 = stack[-4];
    v214 = (Lisp_Object)lessp2(v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v214 = v214 ? lisp_true : nil;
    env = stack[-5];
    if (v214 == nil) goto v130;
    v215 = qvalue(elt(env, 1)); /* nil */
    v214 = stack[-3];
    v214 = cons(v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-3] = v214;
    v214 = stack[-2];
    v214 = add1(v214);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-2] = v214;
    goto v76;

v130:
    v214 = stack[-2];
    v214 = add1(v214);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-2] = v214;
    v214 = stack[0];
    v215 = qcdr(v214);
    v214 = stack[-3];
    v214 = cons(v215, v214);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-3] = v214;
    v214 = stack[-1];
    v214 = qcdr(v214);
    stack[-1] = v214;
    goto v60;

v219:
    v215 = stack[-4];
    v214 = stack[-3];
    popv(6);
    return cons(v215, v214);
/* error exit handlers */
v124:
    popv(6);
    return nil;
}



/* Code for prinfit */

static Lisp_Object MS_CDECL CC_prinfit(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v219, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prinfit");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinfit");
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
    v78 = qvalue(elt(env, 1)); /* !*nat */
    if (v78 == nil) goto v4;
    v78 = qvalue(elt(env, 2)); /* testing!-width!* */
    if (!(v78 == nil)) goto v4;
    v200 = stack[-2];
    v219 = stack[-1];
    v78 = stack[0];
    fn = elt(env, 3); /* layout!-formula */
    v78 = (*qfnn(fn))(qenv(fn), 3, v200, v219, v78);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v219 = v78;
    v78 = v219;
    if (v78 == nil) goto v70;
    v78 = v219;
    fn = elt(env, 4); /* putpline */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v123;
    v78 = nil;
    { popv(4); return onevalue(v78); }

v70:
    v78 = stack[0];
    if (v78 == nil) goto v69;
    v78 = stack[0];
    fn = elt(env, 5); /* oprin */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    goto v69;

v69:
    v219 = stack[-2];
    v78 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* maprint */
        return (*qfn2(fn))(qenv(fn), v219, v78);
    }

v4:
    v78 = stack[0];
    if (v78 == nil) goto v100;
    v78 = stack[0];
    fn = elt(env, 5); /* oprin */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    goto v100;

v100:
    v219 = stack[-2];
    v78 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* maprint */
        return (*qfn2(fn))(qenv(fn), v219, v78);
    }
/* error exit handlers */
v123:
    popv(4);
    return nil;
}



/* Code for defined_edge */

static Lisp_Object CC_defined_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v135, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defined_edge");
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
    v220 = v0;
/* end of prologue */
    v143 = v220;
    v135 = qcar(v143);
    v143 = qvalue(elt(env, 1)); /* old_edge_list */
    v143 = Lassoc(nil, v135, v143);
    if (!(v143 == nil)) { popv(2); return onevalue(v143); }
    v143 = v220;
    v135 = qcar(v143);
    v143 = qvalue(elt(env, 2)); /* new_edge_list */
    fn = elt(env, 4); /* all_edge */
    v220 = (*qfn2(fn))(qenv(fn), v135, v143);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    v135 = qvalue(elt(env, 3)); /* nil */
    v143 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* defined_all_edge */
        return (*qfnn(fn))(qenv(fn), 3, v220, v135, v143);
    }
/* error exit handlers */
v101:
    popv(2);
    return nil;
}



/* Code for formcond1 */

static Lisp_Object MS_CDECL CC_formcond1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v66, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond1");
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
/* copy arguments values to proper place */
    stack[-1] = v142;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v34;

v34:
    v199 = stack[-3];
    if (v199 == nil) goto v64;
    v199 = stack[-3];
    v199 = qcar(v199);
    v221 = qcar(v199);
    v66 = stack[-2];
    v199 = stack[-1];
    fn = elt(env, 1); /* formbool */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v221, v66, v199);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v199 = stack[-3];
    v199 = qcar(v199);
    v199 = qcdr(v199);
    v221 = qcar(v199);
    v66 = stack[-2];
    v199 = stack[-1];
    fn = elt(env, 2); /* formc */
    v199 = (*qfnn(fn))(qenv(fn), 3, v221, v66, v199);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v66 = list2(stack[0], v199);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v199 = stack[-4];
    v199 = cons(v66, v199);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    stack[-4] = v199;
    v199 = stack[-3];
    v199 = qcdr(v199);
    stack[-3] = v199;
    goto v34;

v64:
    v199 = stack[-4];
    {
        popv(6);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v199);
    }
/* error exit handlers */
v213:
    popv(6);
    return nil;
}



/* Code for mv!-domainlist!-!* */

static Lisp_Object CC_mvKdomainlistKH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist-*");
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
    goto v20;

v20:
    v143 = stack[0];
    if (v143 == nil) goto v4;
    v135 = stack[-1];
    v143 = stack[0];
    v143 = qcar(v143);
    v135 = times2(v135, v143);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    v143 = stack[-2];
    v143 = cons(v135, v143);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-3];
    stack[-2] = v143;
    v143 = stack[0];
    v143 = qcdr(v143);
    stack[0] = v143;
    goto v20;

v4:
    v143 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v143);
    }
/* error exit handlers */
v194:
    popv(4);
    return nil;
}



/* Code for mo!=revlexcomp */

static Lisp_Object CC_moMrevlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=revlexcomp");
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
    v216 = stack[-1];
    stack[-2] = Llength(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v216 = stack[0];
    v216 = Llength(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v216))) goto v38;
    v216 = stack[0];
    stack[-2] = Llength(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v216 = stack[-1];
    v216 = Llength(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v216))) goto v180;
    v216 = stack[-1];
    stack[-1] = Lreverse(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v216 = stack[0];
    v216 = Lreverse(nil, v216);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 1); /* mo!=degcomp */
    v216 = (*qfn2(fn))(qenv(fn), stack[-1], v216);
    nil = C_nil;
    if (exception_pending()) goto v140;
    popv(4);
    return negate(v216);

v180:
    v216 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v216); }

v38:
    v216 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v216); }
/* error exit handlers */
v140:
    popv(4);
    return nil;
}



/* Code for subsetp */

static Lisp_Object CC_subsetp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v143, v135, v220;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsetp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v143 = v1;
    v135 = v0;
/* end of prologue */

v222:
    v95 = v135;
    v95 = (v95 == nil ? lisp_true : nil);
    if (!(v95 == nil)) return onevalue(v95);
    v95 = v135;
    v220 = qcar(v95);
    v95 = v143;
    v95 = Lmember(nil, v220, v95);
    if (v95 == nil) goto v64;
    v95 = v135;
    v135 = qcdr(v95);
    v95 = v143;
    v143 = v95;
    goto v222;

v64:
    v95 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v95);
}



/* Code for dl_get */

static Lisp_Object CC_dl_get(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v64 = v0;
/* end of prologue */
    v60 = v64;
    v64 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* dl_get2 */
        return (*qfn2(fn))(qenv(fn), v60, v64);
    }
}



/* Code for removeg2 */

static Lisp_Object MS_CDECL CC_removeg2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v30, v236, v237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg2");
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
    stack[-3] = v142;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v235 = stack[-4];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v30 = v235;
    v235 = stack[-3];
    v236 = qcar(v235);
    v235 = elt(env, 1); /* g3 */
    if (!(v236 == v235)) goto v129;
    v236 = v30;
    v235 = stack[-3];
    v235 = qcdr(v235);
    v235 = Lmemq(nil, v236, v235);
    if (v235 == nil) goto v129;
    v235 = stack[-3];
    fn = elt(env, 5); /* revv0 */
    v235 = (*qfn2(fn))(qenv(fn), v235, v30);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    goto v180;

v180:
    stack[-3] = v235;
    v30 = stack[-3];
    v235 = elt(env, 4); /* qg */
    v235 = Lrplaca(nil, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = stack[-5];
    stack[0] = qcar(v235);
    v235 = stack[-5];
    v235 = qcdr(v235);
    fn = elt(env, 6); /* mkcopy */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = cons(stack[0], v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    stack[-6] = v235;
    v30 = stack[-4];
    v235 = stack[-6];
    v235 = Lmember(nil, v30, v235);
    v235 = qcar(v235);
    stack[-1] = v235;
    v30 = stack[-3];
    v235 = stack[-6];
    v235 = Lmember(nil, v30, v235);
    v235 = qcar(v235);
    stack[0] = v235;
    v235 = stack[-4];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    stack[-2] = v235;
    v235 = stack[-4];
    v235 = qcdr(v235);
    v30 = qcdr(v235);
    v235 = stack[-4];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = stack[-4];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v30 = qcdr(v235);
    v235 = stack[-3];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = stack[-3];
    v235 = qcdr(v235);
    v30 = qcdr(v235);
    v235 = stack[-2];
    v235 = Lrplaca(nil, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = stack[-1];
    v235 = qcdr(v235);
    v235 = qcar(v235);
    stack[-2] = v235;
    v235 = stack[-1];
    v30 = qcdr(v235);
    v235 = stack[-1];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = stack[-1];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v30 = qcdr(v235);
    v235 = stack[0];
    v235 = qcdr(v235);
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = stack[0];
    v235 = qcdr(v235);
    v30 = qcdr(v235);
    v235 = stack[0];
    v235 = qcdr(v235);
    v235 = qcar(v235);
    v235 = Lrplaca(nil, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = stack[0];
    v30 = qcdr(v235);
    v235 = stack[-2];
    v235 = Lrplaca(nil, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    stack[0] = stack[-5];
    v235 = stack[-6];
    v235 = qcar(v235);
    v235 = qcar(v235);
    fn = elt(env, 7); /* negf */
    v30 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    v235 = stack[-6];
    v235 = qcar(v235);
    v235 = qcdr(v235);
    v30 = cons(v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    v235 = stack[-6];
    v235 = qcdr(v235);
    {
        Lisp_Object v238 = stack[0];
        popv(8);
        return list2star(v238, v30, v235);
    }

v129:
    v237 = elt(env, 2); /* "Edge" */
    v236 = v30;
    v30 = elt(env, 3); /* "is absent in vertex" */
    v235 = stack[-3];
    v235 = list4(v237, v236, v30, v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    fn = elt(env, 8); /* cerror */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-7];
    goto v180;
/* error exit handlers */
v27:
    popv(8);
    return nil;
}



/* Code for freevarinexptchk */

static Lisp_Object CC_freevarinexptchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freevarinexptchk");
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

v222:
    v77 = stack[0];
    if (!consp(v77)) goto v52;
    v77 = stack[0];
    v77 = qcar(v77);
    if (!consp(v77)) goto v52;
    v77 = stack[0];
    v77 = qcar(v77);
    v77 = qcar(v77);
    v77 = qcdr(v77);
    v77 = (is_number(v77) ? lisp_true : nil);
    v77 = (v77 == nil ? lisp_true : nil);
    if (!(v77 == nil)) { popv(2); return onevalue(v77); }
    v77 = stack[0];
    v77 = qcar(v77);
    v77 = qcdr(v77);
    v77 = CC_freevarinexptchk(env, v77);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-1];
    if (!(v77 == nil)) { popv(2); return onevalue(v77); }
    v77 = stack[0];
    v77 = qcdr(v77);
    stack[0] = v77;
    goto v222;

v52:
    v77 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v77); }
/* error exit handlers */
v95:
    popv(2);
    return nil;
}



/* Code for pasf_smwmkatl */

static Lisp_Object MS_CDECL CC_pasf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, Lisp_Object v57, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129, v216, v70, v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwmkatl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v129 = v57;
    v216 = v142;
    v70 = v1;
    v239 = v0;
/* end of prologue */
    v128 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v128 == nil) goto v147;
    v128 = v239;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v128, v70, v216, v129);
    }

v147:
    v128 = v239;
    {
        fn = elt(env, 3); /* cl_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v128, v70, v216, v129);
    }
}



/* Code for ibalp_hassimple */

static Lisp_Object CC_ibalp_hassimple(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v216;
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
    v129 = v0;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v129;
    goto v4;

v4:
    v129 = stack[0];
    if (v129 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v129 = stack[-1];
    if (!(v129 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v129 = stack[0];
    v129 = qcar(v129);
    v216 = qcar(v129);
    v129 = stack[0];
    v129 = qcar(v129);
    v129 = qcdr(v129);
    v129 = qcar(v129);
    fn = elt(env, 2); /* ibalp_commonlenisone */
    v129 = (*qfn2(fn))(qenv(fn), v216, v129);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    if (v129 == nil) goto v134;
    v129 = stack[0];
    v129 = qcar(v129);
    stack[-1] = v129;
    goto v134;

v134:
    v129 = stack[0];
    v129 = qcdr(v129);
    stack[0] = v129;
    goto v4;
/* error exit handlers */
v93:
    popv(3);
    return nil;
}



/* Code for maxtype */

static Lisp_Object CC_maxtype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxtype");
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
    v150 = v0;
/* end of prologue */
    v134 = v150;
    if (!consp(v134)) return onevalue(v150);
    v134 = v150;
    v134 = qcdr(v134);
    v134 = Lconsp(nil, v134);
    if (v134 == nil) goto v103;
    v134 = v150;
    v134 = qcdr(v134);
    v134 = qcar(v134);
    return onevalue(v134);

v103:
    v134 = v150;
    v134 = qcar(v134);
    return onevalue(v134);
}



/* Code for actual_alst */

static Lisp_Object CC_actual_alst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v216, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for actual_alst");
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
    v70 = nil;
    goto v20;

v20:
    v129 = stack[-1];
    if (v129 == nil) goto v4;
    v129 = stack[-1];
    v129 = qcar(v129);
    v216 = qcar(v129);
    v129 = stack[0];
    v129 = Lmemq(nil, v216, v129);
    if (v129 == nil) goto v218;
    v129 = stack[-1];
    v129 = qcar(v129);
    v216 = v70;
    v129 = cons(v129, v216);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v70 = v129;
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v20;

v218:
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v20;

v4:
    v129 = v70;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v129);
    }
/* error exit handlers */
v140:
    popv(3);
    return nil;
}



/* Code for assert_check1 */

static Lisp_Object MS_CDECL CC_assert_check1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, Lisp_Object v57,
                         Lisp_Object v52, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v235, v30, v236, v237, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "assert_check1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_check1");
#endif
    if (stack >= stacklimit)
    {
        push5(v52,v57,v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v142,v57,v52);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-5] = v52;
    stack[-6] = v57;
    stack[-7] = v142;
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    stack[-4] = nil;
    v31 = (Lisp_Object)1; /* 0 */
    stack[-3] = v31;
    v31 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v31 == nil) goto v103;
    v235 = stack[-9];
    v31 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v31 = Latsoc(nil, v235, v31);
    v235 = v31;
    v31 = v235;
    if (v31 == nil) goto v92;
    v31 = v235;
    stack[0] = qcdr(v31);
    v31 = v235;
    v31 = qcdr(v31);
    v31 = qcar(v31);
    v31 = add1(v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    fn = elt(env, 6); /* setcar */
    v31 = (*qfn2(fn))(qenv(fn), stack[0], v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    goto v103;

v103:
    v31 = stack[-6];
    stack[-10] = v31;
    v31 = stack[-7];
    stack[-2] = v31;
    goto v215;

v215:
    v31 = stack[-2];
    if (v31 == nil) goto v250;
    v31 = stack[-2];
    v31 = qcar(v31);
    stack[-1] = v31;
    v31 = stack[-3];
    v31 = add1(v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    stack[-3] = v31;
    v31 = stack[-10];
    v235 = qcar(v31);
    v31 = elt(env, 4); /* assert_checkfn */
    v31 = get(v235, v31);
    env = stack[-11];
    v235 = v31;
    if (v31 == nil) goto v251;
    stack[0] = v235;
    v31 = stack[-1];
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    fn = elt(env, 7); /* apply */
    v31 = (*qfn2(fn))(qenv(fn), stack[0], v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    if (!(v31 == nil)) goto v251;
    v31 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v31;
    v248 = stack[-9];
    v237 = stack[-6];
    v236 = stack[-5];
    v30 = stack[-3];
    v31 = stack[-10];
    v235 = qcar(v31);
    v31 = stack[-1];
    fn = elt(env, 8); /* assert_error */
    v31 = (*qfnn(fn))(qenv(fn), 6, v248, v237, v236, v30, v235, v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    goto v251;

v251:
    v31 = stack[-10];
    v31 = qcdr(v31);
    stack[-10] = v31;
    v31 = stack[-2];
    v31 = qcdr(v31);
    stack[-2] = v31;
    goto v215;

v250:
    v235 = stack[-8];
    v31 = stack[-7];
    fn = elt(env, 7); /* apply */
    v31 = (*qfn2(fn))(qenv(fn), v235, v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    stack[-1] = v31;
    v235 = stack[-5];
    v31 = elt(env, 4); /* assert_checkfn */
    v31 = get(v235, v31);
    env = stack[-11];
    v235 = v31;
    if (v31 == nil) goto v252;
    stack[0] = v235;
    v31 = stack[-1];
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    fn = elt(env, 7); /* apply */
    v31 = (*qfn2(fn))(qenv(fn), stack[0], v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    if (!(v31 == nil)) goto v252;
    v31 = qvalue(elt(env, 5)); /* t */
    stack[-4] = v31;
    v248 = stack[-9];
    v237 = stack[-6];
    v236 = stack[-5];
    v30 = (Lisp_Object)1; /* 0 */
    v235 = stack[-5];
    v31 = stack[-1];
    fn = elt(env, 8); /* assert_error */
    v31 = (*qfnn(fn))(qenv(fn), 6, v248, v237, v236, v30, v235, v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    goto v252;

v252:
    v31 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v31 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v31 = stack[-4];
    if (v31 == nil) { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }
    v235 = stack[-9];
    v31 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v31 = Latsoc(nil, v235, v31);
    v31 = qcdr(v31);
    v235 = v31;
    v31 = v235;
    stack[0] = qcdr(v31);
    v31 = v235;
    v31 = qcdr(v31);
    v31 = qcar(v31);
    v31 = add1(v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    fn = elt(env, 6); /* setcar */
    v31 = (*qfn2(fn))(qenv(fn), stack[0], v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    { Lisp_Object res = stack[-1]; popv(12); return onevalue(res); }

v92:
    stack[0] = stack[-9];
    v30 = (Lisp_Object)17; /* 1 */
    v235 = (Lisp_Object)1; /* 0 */
    v31 = (Lisp_Object)1; /* 0 */
    v235 = list3(v30, v235, v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    v31 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v31 = acons(stack[0], v235, v31);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-11];
    qvalue(elt(env, 2)) = v31; /* assertstatistics!* */
    goto v103;
/* error exit handlers */
v249:
    popv(12);
    return nil;
}



/* Code for aminusp!:1 */

static Lisp_Object CC_aminuspT1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v118, v257, v258;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aminusp:1");
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
    v256 = stack[-1];
    fn = elt(env, 6); /* aeval!* */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[-1] = v256;
    v256 = stack[-1];
    stack[-2] = v256;
    v256 = stack[-2];
    v256 = integerp(v256);
    if (v256 == nil) goto v185;
    v256 = stack[-2];
        popv(4);
        return Lminusp(nil, v256);

v185:
    v118 = stack[-2];
    v256 = elt(env, 1); /* !*sq */
    if (!consp(v118)) goto v147;
    v118 = qcar(v118);
    if (!(v118 == v256)) goto v147;

v4:
    v256 = stack[-2];
    v256 = qcdr(v256);
    v256 = qcar(v256);
    stack[-2] = v256;
    v256 = stack[-2];
    v256 = qcar(v256);
    v256 = integerp(v256);
    if (v256 == nil) goto v200;
    v256 = stack[-2];
    v256 = qcdr(v256);
    v256 = integerp(v256);
    if (v256 == nil) goto v200;
    v256 = stack[-2];
    v256 = qcar(v256);
        popv(4);
        return Lminusp(nil, v256);

v200:
    v256 = stack[-2];
    v118 = qcdr(v256);
    v256 = (Lisp_Object)17; /* 1 */
    if (!(v118 == v256)) goto v259;
    v256 = stack[-2];
    v256 = qcar(v256);
    stack[-2] = v256;
    if (!consp(v256)) goto v80;
    v256 = stack[-2];
    v256 = qcar(v256);
    if (!(!consp(v256))) goto v259;

v80:
    v118 = elt(env, 5); /* !:minusp */
    v256 = stack[-2];
        popv(4);
        return Lapply1(nil, v118, v256);

v259:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v256 = stack[-1];
    fn = elt(env, 7); /* reval */
    v258 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    v257 = elt(env, 3); /* "invalid in FOR statement" */
    v118 = qvalue(elt(env, 2)); /* nil */
    v256 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v256 = (*qfnn(fn))(qenv(fn), 5, stack[0], v258, v257, v118, v256);
    nil = C_nil;
    if (exception_pending()) goto v81;
    v256 = nil;
    { popv(4); return onevalue(v256); }

v147:
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v256 = stack[-1];
    fn = elt(env, 7); /* reval */
    v258 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    v257 = elt(env, 3); /* "invalid in FOR statement" */
    v118 = qvalue(elt(env, 2)); /* nil */
    v256 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* msgpri */
    v256 = (*qfnn(fn))(qenv(fn), 5, stack[0], v258, v257, v118, v256);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    goto v4;
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for gperm3 */

static Lisp_Object CC_gperm3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v77, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm3");
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
    v77 = v1;
    v94 = v0;
/* end of prologue */

v20:
    v76 = v94;
    if (v76 == nil) { popv(2); return onevalue(v77); }
    v76 = v94;
    v76 = qcdr(v76);
    stack[0] = v76;
    v76 = v77;
    v77 = qcar(v94);
    v94 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* gperm2 */
    v94 = (*qfnn(fn))(qenv(fn), 3, v76, v77, v94);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    v77 = v94;
    v94 = stack[0];
    goto v20;
/* error exit handlers */
v143:
    popv(2);
    return nil;
}



/* Code for dv_skel2factor1 */

static Lisp_Object CC_dv_skel2factor1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v251, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor1");
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
    v251 = stack[-1];
    if (v251 == nil) goto v4;
    v251 = stack[-1];
    fn = elt(env, 3); /* listp */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    if (v251 == nil) goto v140;
    v251 = stack[-1];
    v61 = qcar(v251);
    v251 = stack[0];
    v251 = CC_dv_skel2factor1(env, v61, v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    stack[-2] = v251;
    v251 = stack[-1];
    v61 = qcdr(v251);
    v251 = stack[0];
    v251 = CC_dv_skel2factor1(env, v61, v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    v251 = cons(stack[-2], v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    { popv(4); return onevalue(v251); }

v140:
    v61 = stack[-1];
    v251 = elt(env, 2); /* !~dv */
    if (!(v61 == v251)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v251 = stack[0];
    v251 = qcar(v251);
    stack[-1] = v251;
    v251 = stack[0];
    v251 = qcdr(v251);
    if (v251 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v61 = stack[0];
    v251 = stack[0];
    v251 = qcdr(v251);
    v251 = qcar(v251);
    v251 = Lrplaca(nil, v61, v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    env = stack[-3];
    v61 = stack[0];
    v251 = stack[0];
    v251 = qcdr(v251);
    v251 = qcdr(v251);
    v251 = Lrplacd(nil, v61, v251);
    nil = C_nil;
    if (exception_pending()) goto v260;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v4:
    v251 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v251); }
/* error exit handlers */
v260:
    popv(4);
    return nil;
}



/* Code for cl_susiupdknowl */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, Lisp_Object v57, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v219, v200, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v57,v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v142,v57);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v57;
    v78 = v142;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v64;

v64:
    v219 = stack[-1];
    if (v219 == nil) goto v127;
    v219 = stack[-1];
    v219 = qcar(v219);
    stack[-3] = v219;
    v219 = stack[-1];
    v219 = qcdr(v219);
    stack[-1] = v219;
    v212 = stack[-2];
    v200 = stack[-3];
    v219 = v78;
    v78 = stack[0];
    fn = elt(env, 4); /* cl_susiupdknowl1 */
    v78 = (*qfnn(fn))(qenv(fn), 4, v212, v200, v219, v78);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-4];
    v200 = v78;
    v219 = elt(env, 2); /* false */
    if (!(v200 == v219)) goto v64;
    v219 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v219;
    v219 = elt(env, 3); /* break */
    stack[-3] = v219;
    goto v64;

v127:
    v200 = stack[-3];
    v219 = elt(env, 3); /* break */
    if (!(v200 == v219)) { popv(5); return onevalue(v78); }
    v78 = elt(env, 2); /* false */
    { popv(5); return onevalue(v78); }
/* error exit handlers */
v214:
    popv(5);
    return nil;
}



/* Code for rl_simpbop */

static Lisp_Object CC_rl_simpbop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpbop");
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
    v69 = v0;
/* end of prologue */
    v68 = v69;
    stack[-4] = qcar(v68);
    v68 = v69;
    v68 = qcdr(v68);
    stack[-3] = v68;
    v68 = stack[-3];
    if (v68 == nil) goto v134;
    v68 = stack[-3];
    v68 = qcar(v68);
    fn = elt(env, 2); /* rl_simp1 */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-5];
    v68 = ncons(v68);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-5];
    stack[-1] = v68;
    stack[-2] = v68;
    goto v96;

v96:
    v68 = stack[-3];
    v68 = qcdr(v68);
    stack[-3] = v68;
    v68 = stack[-3];
    if (v68 == nil) goto v143;
    stack[0] = stack[-1];
    v68 = stack[-3];
    v68 = qcar(v68);
    fn = elt(env, 2); /* rl_simp1 */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-5];
    v68 = ncons(v68);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-5];
    v68 = Lrplacd(nil, stack[0], v68);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-5];
    v68 = stack[-1];
    v68 = qcdr(v68);
    stack[-1] = v68;
    goto v96;

v143:
    v68 = stack[-2];
    goto v20;

v20:
    {
        Lisp_Object v221 = stack[-4];
        popv(6);
        return cons(v221, v68);
    }

v134:
    v68 = qvalue(elt(env, 1)); /* nil */
    goto v20;
/* error exit handlers */
v66:
    popv(6);
    return nil;
}



/* Code for rl_ordatp */

static Lisp_Object CC_rl_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_ordatp");
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
    v97 = v1;
    v185 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_ordatp!* */
    v97 = list2(v185, v97);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    {
        Lisp_Object v144 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v144, v97);
    }
/* error exit handlers */
v150:
    popv(2);
    return nil;
}



/* Code for spband_matrix */

static Lisp_Object CC_spband_matrix(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v277, v278, v279;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spband_matrix");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[0] = stack[-7];
    v279 = elt(env, 1); /* spm */
    v278 = stack[-7];
    v277 = stack[-7];
    v277 = list3(v279, v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    fn = elt(env, 10); /* mkempspmat */
    v277 = (*qfn2(fn))(qenv(fn), stack[0], v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    stack[-9] = v277;
    v277 = stack[-7];
    v277 = integerp(v277);
    if (!(v277 == nil)) goto v135;
    v277 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v277 == nil)) goto v70;
    v277 = elt(env, 3); /* "Error in spband_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 11); /* lprie */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    goto v70;

v70:
    v277 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    goto v135;

v135:
    v277 = stack[-8];
    if (!consp(v277)) goto v127;
    v277 = stack[-8];
    v278 = qcar(v277);
    v277 = elt(env, 4); /* list */
    if (v278 == v277) goto v217;
    v277 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v277 == nil)) goto v65;
    v277 = elt(env, 5); /* "Error in spband_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 11); /* lprie */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    goto v65;

v65:
    v277 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    goto v234;

v234:
    v277 = stack[-8];
    v277 = Llength(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    stack[-4] = v277;
    v277 = stack[-4];
    v277 = Levenp(nil, v277);
    env = stack[-10];
    if (v277 == nil) goto v80;
    v277 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v277 == nil)) goto v254;
    v277 = elt(env, 6); /* "Error in spband matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 11); /* lprie */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    goto v254;

v254:
    v277 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    goto v80;

v80:
    stack[0] = elt(env, 7); /* quotient */
    v277 = stack[-4];
    v278 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v277 = (Lisp_Object)33; /* 2 */
    v277 = list3(stack[0], v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    fn = elt(env, 12); /* reval */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    stack[-3] = v277;
    v277 = stack[-3];
    v277 = integerp(v277);
    if (v277 == nil) goto v56;
    v277 = stack[-3];
    v278 = v277;
    goto v280;

v280:
    v277 = stack[-7];
    v277 = (Lisp_Object)greaterp2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v119;
    v277 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v277 == nil)) goto v281;
    v277 = elt(env, 8); /* "Error in spband_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 11); /* lprie */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    goto v281;

v281:
    v277 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    goto v119;

v119:
    v277 = (Lisp_Object)33; /* 2 */
    stack[-5] = v277;
    v277 = (Lisp_Object)17; /* 1 */
    stack[-2] = v277;
    goto v104;

v104:
    v278 = stack[-7];
    v277 = stack[-2];
    v277 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v277 = Lminusp(nil, v277);
    env = stack[-10];
    if (!(v277 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v278 = stack[-2];
    v277 = stack[-3];
    v277 = (Lisp_Object)lesseq2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v133;
    v277 = (Lisp_Object)17; /* 1 */
    stack[-6] = v277;
    goto v242;

v242:
    v278 = stack[-3];
    v277 = stack[-2];
    v278 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v277 = stack[-6];
    v278 = plus2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v277 = (Lisp_Object)1; /* 0 */
    v277 = (Lisp_Object)greaterp2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v17;
    v278 = stack[-6];
    v277 = stack[-7];
    v277 = (Lisp_Object)lesseq2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v17;
    v278 = stack[-3];
    v277 = stack[-2];
    v278 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v277 = stack[-6];
    v278 = plus2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v277 = stack[-4];
    v277 = (Lisp_Object)lesseq2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v17;
    v279 = stack[-9];
    v278 = stack[-2];
    v277 = stack[-6];
    stack[-1] = list3(v279, v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    stack[0] = stack[-8];
    v278 = stack[-3];
    v277 = stack[-2];
    v278 = difference2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v277 = stack[-6];
    v277 = plus2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    fn = elt(env, 13); /* pnth */
    v277 = (*qfn2(fn))(qenv(fn), stack[0], v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v279 = qcar(v277);
    v278 = stack[-9];
    v277 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* letmtr3 */
    v277 = (*qfnn(fn))(qenv(fn), 4, stack[-1], v279, v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v277 = stack[-6];
    v277 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    stack[-6] = v277;
    goto v242;

v17:
    v278 = stack[-2];
    v277 = stack[-3];
    v277 = (Lisp_Object)greaterp2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v277 = v277 ? lisp_true : nil;
    env = stack[-10];
    if (v277 == nil) goto v282;
    v277 = stack[-5];
    v277 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    stack[-5] = v277;
    goto v282;

v282:
    v277 = stack[-2];
    v277 = add1(v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    stack[-2] = v277;
    goto v104;

v133:
    v277 = stack[-5];
    stack[-6] = v277;
    goto v242;

v56:
    v277 = stack[-3];
    fn = elt(env, 12); /* reval */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    v278 = v277;
    goto v280;

v217:
    v277 = stack[-8];
    v277 = qcdr(v277);
    stack[-8] = v277;
    goto v234;

v127:
    v277 = stack[-8];
    v277 = ncons(v277);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-10];
    stack[-8] = v277;
    goto v234;
/* error exit handlers */
v7:
    popv(11);
    return nil;
}



/* Code for redcodmat */

static Lisp_Object MS_CDECL CC_redcodmat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "redcodmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redcodmat");
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
    v151 = qvalue(elt(env, 1)); /* rowmin */
    stack[0] = v151;
    goto v102;

v102:
    v130 = qvalue(elt(env, 2)); /* rowmax */
    v151 = stack[0];
    v151 = difference2(v130, v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-1];
    v151 = Lminusp(nil, v151);
    env = stack[-1];
    if (v151 == nil) goto v34;
    v151 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v151); }

v34:
    v151 = stack[0];
    fn = elt(env, 4); /* testred */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-1];
    v151 = stack[0];
    v151 = add1(v151);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-1];
    stack[0] = v151;
    goto v102;
/* error exit handlers */
v147:
    popv(2);
    return nil;
}



/* Code for xord_gradlex */

static Lisp_Object CC_xord_gradlex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_gradlex");
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
    v146 = stack[-1];
    v199 = qcar(v146);
    v146 = (Lisp_Object)17; /* 1 */
    if (v199 == v146) goto v38;
    v146 = stack[0];
    v199 = qcar(v146);
    v146 = (Lisp_Object)17; /* 1 */
    if (v199 == v146) goto v103;
    v146 = stack[-1];
    stack[-2] = Llength(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    v146 = stack[0];
    v146 = Llength(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    if (equal(stack[-2], v146)) goto v194;
    v146 = stack[-1];
    stack[-1] = Llength(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    v146 = stack[0];
    v146 = Llength(nil, v146);
    nil = C_nil;
    if (exception_pending()) goto v78;
    {
        Lisp_Object v219 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v219, v146);
    }

v194:
    v199 = stack[-1];
    v146 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v199, v146);
    }

v103:
    v146 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v146); }

v38:
    v146 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v146); }
/* error exit handlers */
v78:
    popv(4);
    return nil;
}



/* Code for delete!-dups */

static Lisp_Object CC_deleteKdups(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v93, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delete-dups");
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
    v140 = nil;
    goto v38;

v38:
    v239 = stack[0];
    if (v239 == nil) goto v128;
    v239 = stack[0];
    v93 = qcar(v239);
    v239 = stack[0];
    v239 = qcdr(v239);
    v239 = Lmember(nil, v93, v239);
    if (v239 == nil) goto v94;
    v239 = stack[0];
    v239 = qcdr(v239);
    stack[0] = v239;
    goto v38;

v94:
    v239 = stack[0];
    v239 = qcar(v239);
    v93 = v140;
    v239 = cons(v239, v93);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    v140 = v239;
    v239 = stack[0];
    v239 = qcdr(v239);
    stack[0] = v239;
    goto v38;

v128:
    v239 = v140;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v239);
    }
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for inttovec!-solve */

static Lisp_Object CC_inttovecKsolve(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v122;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec-solve");
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
    v122 = stack[-2];
    v253 = (Lisp_Object)1; /* 0 */
    if (v122 == v253) goto v151;
    v122 = stack[-3];
    v253 = (Lisp_Object)17; /* 1 */
    if (v122 == v253) goto v151;
    v253 = (Lisp_Object)1; /* 0 */
    stack[-4] = v253;
    v253 = (Lisp_Object)17; /* 1 */
    stack[0] = v253;
    goto v216;

v216:
    v253 = stack[0];
    stack[-1] = v253;
    v253 = stack[-4];
    v253 = add1(v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-5];
    stack[-4] = v253;
    v122 = stack[-3];
    v253 = stack[-4];
    v122 = plus2(v122, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-5];
    v253 = stack[-1];
    v122 = times2(v122, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-5];
    v253 = stack[-4];
    v253 = quot2(v122, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-5];
    stack[0] = v253;
    v122 = stack[0];
    v253 = stack[-2];
    v253 = (Lisp_Object)greaterp2(v122, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v253 = v253 ? lisp_true : nil;
    env = stack[-5];
    if (v253 == nil) goto v216;
    stack[0] = stack[-4];
    v122 = stack[-2];
    v253 = stack[-1];
    v253 = difference2(v122, v253);
    nil = C_nil;
    if (exception_pending()) goto v284;
    {
        Lisp_Object v201 = stack[0];
        popv(6);
        return cons(v201, v253);
    }

v151:
    v122 = stack[-2];
    v253 = (Lisp_Object)1; /* 0 */
    popv(6);
    return cons(v122, v253);
/* error exit handlers */
v284:
    popv(6);
    return nil;
}



/* Code for gpexp1p */

static Lisp_Object CC_gpexp1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexp1p");
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

v222:
    v134 = stack[0];
    v134 = (v134 == nil ? lisp_true : nil);
    if (!(v134 == nil)) { popv(2); return onevalue(v134); }
    v134 = stack[0];
    v134 = qcar(v134);
    fn = elt(env, 2); /* gpexpp */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-1];
    if (v134 == nil) goto v4;
    v134 = stack[0];
    v134 = qcdr(v134);
    stack[0] = v134;
    goto v222;

v4:
    v134 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v134); }
/* error exit handlers */
v144:
    popv(2);
    return nil;
}



/* Code for cstimes */

static Lisp_Object CC_cstimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v221, v79, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cstimes");
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
    v221 = v1;
    v79 = v0;
/* end of prologue */

v20:
    v66 = v79;
    if (v66 == nil) goto v4;
    v66 = v79;
    v78 = qcar(v66);
    v66 = (Lisp_Object)17; /* 1 */
    if (v78 == v66) goto v143;
    v66 = v79;
    v66 = qcdr(v66);
    stack[0] = v66;
    v66 = v79;
    v66 = qcar(v66);
    v66 = cons(v66, v221);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-1];
    v221 = v66;
    v66 = stack[0];
    v79 = v66;
    goto v20;

v143:
    v66 = v79;
    v66 = qcdr(v66);
    v79 = v66;
    goto v20;

v4:
    v66 = v221;
    if (v66 == nil) goto v154;
    v66 = v221;
    v66 = qcdr(v66);
    if (v66 == nil) goto v97;
    v66 = elt(env, 1); /* times */
    popv(2);
    return cons(v66, v221);

v97:
    v66 = v221;
    v66 = qcar(v66);
    { popv(2); return onevalue(v66); }

v154:
    v66 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v66); }
/* error exit handlers */
v200:
    popv(2);
    return nil;
}



/* Code for evalneq */

static Lisp_Object CC_evalneq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalneq");
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
    v102 = v1;
    v149 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalequal */
    v102 = (*qfn2(fn))(qenv(fn), v149, v102);
    errexit();
    v102 = (v102 == nil ? lisp_true : nil);
    return onevalue(v102);
}



/* Code for mo_neg */

static Lisp_Object CC_mo_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neg");
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
    v283 = stack[-2];
    v283 = qcar(v283);
    stack[-4] = v283;
    v283 = stack[-4];
    if (v283 == nil) goto v97;
    v283 = stack[-4];
    v283 = qcar(v283);
    v283 = negate(v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v283 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    stack[-1] = v283;
    stack[-3] = v283;
    goto v149;

v149:
    v283 = stack[-4];
    v283 = qcdr(v283);
    stack[-4] = v283;
    v283 = stack[-4];
    if (v283 == nil) goto v76;
    stack[0] = stack[-1];
    v283 = stack[-4];
    v283 = qcar(v283);
    v283 = negate(v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v283 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v283 = Lrplacd(nil, stack[0], v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v283 = stack[-1];
    v283 = qcdr(v283);
    stack[-1] = v283;
    goto v149;

v76:
    v283 = stack[-3];
    stack[-4] = v283;
    goto v38;

v38:
    v283 = stack[-2];
    v283 = qcdr(v283);
    stack[-3] = v283;
    v283 = stack[-3];
    if (v283 == nil) goto v221;
    v283 = stack[-3];
    v283 = qcar(v283);
    v283 = negate(v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v283 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    stack[-1] = v283;
    stack[-2] = v283;
    goto v67;

v67:
    v283 = stack[-3];
    v283 = qcdr(v283);
    stack[-3] = v283;
    v283 = stack[-3];
    if (v283 == nil) goto v285;
    stack[0] = stack[-1];
    v283 = stack[-3];
    v283 = qcar(v283);
    v283 = negate(v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v283 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v283 = Lrplacd(nil, stack[0], v283);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-5];
    v283 = stack[-1];
    v283 = qcdr(v283);
    stack[-1] = v283;
    goto v67;

v285:
    v283 = stack[-2];
    goto v20;

v20:
    {
        Lisp_Object v80 = stack[-4];
        popv(6);
        return cons(v80, v283);
    }

v221:
    v283 = qvalue(elt(env, 1)); /* nil */
    goto v20;

v97:
    v283 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v283;
    goto v38;
/* error exit handlers */
v192:
    popv(6);
    return nil;
}



/* Code for pst_termnodep */

static Lisp_Object CC_pst_termnodep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v154;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v149 = v0;
/* end of prologue */
    v154 = qcdr(v149);
    v149 = (Lisp_Object)1; /* 0 */
    v149 = *(Lisp_Object *)((char *)v154 + (CELL-TAG_VECTOR) + ((int32_t)v149/(16/CELL)));
    v149 = qcdr(v149);
    v149 = (v149 == nil ? lisp_true : nil);
    return onevalue(v149);
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_negateat");
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
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v60 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    {
        Lisp_Object v154 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v154, v60);
    }
/* error exit handlers */
v149:
    popv(2);
    return nil;
}



/* Code for ibalp_simpatom */

static Lisp_Object CC_ibalp_simpatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v287;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpatom");
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
    v287 = stack[0];
    v201 = (Lisp_Object)1; /* 0 */
    if (v287 == v201) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v287 = stack[0];
    v201 = (Lisp_Object)17; /* 1 */
    if (v287 == v201) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v201 = stack[0];
    if (symbolp(v201)) goto v148;
    v201 = stack[0];
    if (!(v201 == nil)) goto v234;
    v287 = elt(env, 2); /* "nil" */
    v201 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v201 = (*qfn2(fn))(qenv(fn), v287, v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    goto v234;

v234:
    v201 = stack[0];
    if (!(is_number(v201))) goto v219;
    v287 = elt(env, 4); /* "number" */
    v201 = stack[0];
    v287 = list2(v287, v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    v201 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v201 = (*qfn2(fn))(qenv(fn), v287, v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    goto v219;

v219:
    v201 = stack[0];
    v201 = Lstringp(nil, v201);
    env = stack[-1];
    if (v201 == nil) goto v62;
    v287 = elt(env, 5); /* "string" */
    v201 = stack[0];
    v287 = list2(v287, v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    v201 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v201 = (*qfn2(fn))(qenv(fn), v287, v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    goto v62;

v62:
    v201 = nil;
    { popv(2); return onevalue(v201); }

v148:
    v201 = stack[0];
    fn = elt(env, 7); /* rl_gettype */
    v201 = (*qfn1(fn))(qenv(fn), v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    if (v201 == nil) goto v129;
    v201 = stack[0];
    fn = elt(env, 8); /* reval */
    v201 = (*qfn1(fn))(qenv(fn), v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 9); /* ibalp_simpterm */
        return (*qfn1(fn))(qenv(fn), v201);
    }

v129:
    v201 = stack[0];
    v287 = ncons(v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-1];
    v201 = elt(env, 1); /* used!* */
    v201 = Lflag(nil, v287, v201);
    nil = C_nil;
    if (exception_pending()) goto v59;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v59:
    popv(2);
    return nil;
}



/* Code for ratpoly_lc */

static Lisp_Object CC_ratpoly_lc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_lc");
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
    v149 = stack[0];
    v149 = qcar(v149);
    fn = elt(env, 1); /* numpoly_lc */
    v154 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v149 = stack[0];
    v149 = qcdr(v149);
    popv(1);
    return cons(v154, v149);
/* error exit handlers */
v103:
    popv(1);
    return nil;
}



/* Code for poly!-abs */

static Lisp_Object CC_polyKabs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-abs");
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
    v149 = stack[0];
    fn = elt(env, 1); /* poly!-minusp */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    if (v149 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v149 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v149);
    }
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for mathml2 */

static Lisp_Object MS_CDECL CC_mathml2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml2");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    {
        fn = elt(env, 2); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
}



/* Code for getrtype1 */

static Lisp_Object CC_getrtype1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v57;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtype1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */
    v57 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v57);
}



/* Code for add_minus */

static Lisp_Object CC_add_minus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v243;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_minus");
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
    v109 = stack[-1];
    if (!consp(v109)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v109 = stack[-1];
    v243 = qcar(v109);
    v109 = elt(env, 1); /* !:rd!: */
    if (!(v243 == v109)) goto v135;
    v109 = stack[-1];
    v243 = qcdr(v109);
    v109 = (Lisp_Object)1; /* 0 */
    v109 = (Lisp_Object)geq2(v243, v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v109 = v109 ? lisp_true : nil;
    env = stack[-3];
    if (!(v109 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v135:
    v109 = stack[-1];
    v243 = qcar(v109);
    v109 = elt(env, 1); /* !:rd!: */
    if (!(v243 == v109)) goto v289;
    v109 = stack[-1];
    v243 = qcdr(v109);
    v109 = (Lisp_Object)1; /* 0 */
    v109 = (Lisp_Object)lessp2(v243, v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v109 = v109 ? lisp_true : nil;
    env = stack[-3];
    if (v109 == nil) goto v289;
    stack[-2] = elt(env, 2); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v109 = stack[-1];
    v109 = qcdr(v109);
    v109 = Labsval(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-3];
    v109 = cons(stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    {
        Lisp_Object v202 = stack[-2];
        popv(4);
        return list2(v202, v109);
    }

v289:
    v109 = stack[-1];
    v243 = qcar(v109);
    v109 = elt(env, 2); /* minus */
    if (!(v243 == v109)) goto v190;
    v109 = stack[-1];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    if (is_number(v109)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else goto v190;

v190:
    v109 = stack[-1];
    v243 = qcar(v109);
    v109 = elt(env, 2); /* minus */
    if (!(v243 == v109)) goto v290;
    v109 = stack[-1];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    v243 = qcdr(v109);
    v109 = (Lisp_Object)1; /* 0 */
    v109 = (Lisp_Object)lessp2(v243, v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v109 = v109 ? lisp_true : nil;
    env = stack[-3];
    if (v109 == nil) goto v290;
    stack[0] = elt(env, 1); /* !:rd!: */
    v109 = stack[-1];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    v109 = qcdr(v109);
    v109 = Labsval(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    {
        Lisp_Object v42 = stack[0];
        popv(4);
        return cons(v42, v109);
    }

v290:
    v109 = stack[-1];
    v243 = qcar(v109);
    v109 = elt(env, 2); /* minus */
    if (v243 == v109) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v109 = stack[-1];
    v243 = qcdr(v109);
    v109 = (Lisp_Object)1; /* 0 */
    v109 = (Lisp_Object)lessp2(v243, v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v109 = v109 ? lisp_true : nil;
    env = stack[-3];
    if (v109 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = elt(env, 2); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v109 = stack[-1];
    v109 = qcdr(v109);
    v109 = Labsval(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-3];
    v109 = cons(stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v227;
    {
        Lisp_Object v43 = stack[-2];
        popv(4);
        return list2(v43, v109);
    }
/* error exit handlers */
v227:
    popv(4);
    return nil;
}



/* Code for guesspftype */

static Lisp_Object CC_guesspftype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v234, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for guesspftype");
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
    v99 = stack[0];
    if (!consp(v99)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v99 = stack[0];
    v234 = qcar(v99);
    v99 = elt(env, 1); /* (wedge d partdf hodge innerprod liedf) */
    v99 = Lmemq(nil, v234, v99);
    if (!(v99 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v99 = stack[0];
    v99 = qcdr(v99);
    v127 = Llength(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    v99 = stack[0];
    v234 = qcar(v99);
    v99 = elt(env, 2); /* ifdegree */
    v99 = get(v234, v99);
    env = stack[-1];
    v99 = Lassoc(nil, v127, v99);
    if (v99 == nil) goto v140;
    v99 = stack[0];
    v99 = qcdr(v99);
    fn = elt(env, 3); /* xvarlistp */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    if (v99 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else goto v140;

v140:
    v99 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mknwedge */
        return (*qfn1(fn))(qenv(fn), v99);
    }
/* error exit handlers */
v69:
    popv(2);
    return nil;
}



/* Code for !:dmpluslst */

static Lisp_Object CC_Tdmpluslst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmpluslst");
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
    v148 = v0;
/* end of prologue */
    v147 = v148;
    if (v147 == nil) goto v52;
    v147 = v148;
    v147 = qcdr(v147);
    if (v147 == nil) goto v5;
    v147 = v148;
    stack[0] = qcar(v147);
    v147 = v148;
    v147 = qcdr(v147);
    v147 = CC_Tdmpluslst(env, v147);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    {
        Lisp_Object v77 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:plus */
        return (*qfn2(fn))(qenv(fn), v77, v147);
    }

v5:
    v147 = v148;
    v147 = qcar(v147);
    { popv(2); return onevalue(v147); }

v52:
    v147 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v147); }
/* error exit handlers */
v94:
    popv(2);
    return nil;
}



/* Code for mapins */

static Lisp_Object CC_mapins(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapins");
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
    goto v20;

v20:
    v128 = stack[0];
    if (v128 == nil) goto v4;
    v129 = stack[-1];
    v128 = stack[0];
    v128 = qcar(v128);
    v128 = qcar(v128);
    v216 = cons(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    v128 = stack[0];
    v128 = qcar(v128);
    v129 = qcdr(v128);
    v128 = stack[-2];
    v128 = acons(v216, v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    stack[-2] = v128;
    v128 = stack[0];
    v128 = qcdr(v128);
    stack[0] = v128;
    goto v20;

v4:
    v128 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v128);
    }
/* error exit handlers */
v140:
    popv(4);
    return nil;
}



/* Code for deleteall */

static Lisp_Object CC_deleteall(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v194, v128, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteall");
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
    v128 = nil;
    goto v34;

v34:
    v101 = stack[0];
    if (v101 == nil) { popv(4); return onevalue(v128); }
    v101 = stack[0];
    v101 = qcar(v101);
    v129 = v101;
    v101 = stack[0];
    v101 = qcdr(v101);
    stack[0] = v101;
    v194 = v129;
    v101 = stack[-1];
    if (equal(v194, v101)) goto v34;
    stack[-2] = v128;
    v101 = v129;
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    v101 = Lnconc(nil, stack[-2], v101);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    v128 = v101;
    goto v34;
/* error exit handlers */
v93:
    popv(4);
    return nil;
}



/* Code for quotdd */

static Lisp_Object CC_quotdd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v283, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotdd");
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
    v255 = stack[-1];
    if (!(!consp(v255))) goto v189;
    v255 = stack[0];
    if (!consp(v255)) goto v180;
    v255 = stack[0];
    v283 = qcar(v255);
    v255 = elt(env, 2); /* i2d */
    v255 = get(v283, v255);
    env = stack[-2];
    v121 = v255;
    if (v255 == nil) goto v216;
    v283 = v121;
    v255 = stack[-1];
    v255 = Lapply1(nil, v283, v255);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    stack[-1] = v255;
    goto v189;

v189:
    v121 = stack[-1];
    v283 = stack[0];
    v255 = elt(env, 3); /* quotient */
    {
        popv(3);
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v121, v283, v255);
    }

v216:
    v255 = stack[0];
    if (!(!consp(v255))) goto v189;
    v255 = stack[-1];
    v283 = qcar(v255);
    v255 = elt(env, 2); /* i2d */
    v255 = get(v283, v255);
    env = stack[-2];
    v121 = v255;
    if (v255 == nil) goto v189;
    v283 = v121;
    v255 = stack[0];
    v255 = Lapply1(nil, v283, v255);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    stack[0] = v255;
    goto v189;

v180:
    v283 = stack[-1];
    v255 = stack[0];
    v255 = Ldivide(nil, v283, v255);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    v121 = v255;
    v255 = v121;
    v283 = qcdr(v255);
    v255 = (Lisp_Object)1; /* 0 */
    if (v283 == v255) goto v131;
    v255 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v255); }

v131:
    v255 = v121;
    v255 = qcar(v255);
    { popv(3); return onevalue(v255); }
/* error exit handlers */
v193:
    popv(3);
    return nil;
}



/* Code for assert_error */

static Lisp_Object MS_CDECL CC_assert_error(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v142, Lisp_Object v57,
                         Lisp_Object v52, Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v292, v184, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "assert_error");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_error");
#endif
    if (stack >= stacklimit)
    {
        push6(v38,v52,v57,v142,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v142,v57,v52,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v38;
    v292 = v52;
    stack[-1] = v57;
    stack[-2] = v142;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v292 = qvalue(elt(env, 1)); /* !*assertstatistics */
    if (v292 == nil) goto v239;
    v184 = stack[-4];
    v292 = qvalue(elt(env, 2)); /* assertstatistics!* */
    v292 = Latsoc(nil, v184, v292);
    v292 = qcdr(v292);
    v184 = v292;
    v292 = v184;
    v292 = qcdr(v292);
    stack[-5] = qcdr(v292);
    v292 = v184;
    v292 = qcdr(v292);
    v292 = qcdr(v292);
    v292 = qcar(v292);
    v292 = add1(v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 12); /* setcar */
    v292 = (*qfn2(fn))(qenv(fn), stack[-5], v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    goto v239;

v239:
    v184 = stack[-1];
    v292 = (Lisp_Object)1; /* 0 */
    v292 = Leqn(nil, v184, v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    if (v292 == nil) goto v124;
    stack[-1] = elt(env, 3); /* "assertion" */
    v47 = stack[-4];
    v184 = stack[-3];
    v292 = stack[-2];
    fn = elt(env, 13); /* assert_format */
    v47 = (*qfnn(fn))(qenv(fn), 3, v47, v184, v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v184 = elt(env, 4); /* "violated by result" */
    v292 = stack[0];
    v292 = list4(stack[-1], v47, v184, v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    goto v128;

v128:
    v184 = qvalue(elt(env, 7)); /* !*assertbreak */
    if (v184 == nil) goto v245;
    v184 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v184 == nil)) goto v290;
    fn = elt(env, 14); /* lprie */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    goto v290;

v290:
    v292 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v105;
    goto v288;

v288:
    v292 = nil;
    { popv(7); return onevalue(v292); }

v245:
    v184 = qvalue(elt(env, 9)); /* !*msg */
    if (v184 == nil) goto v288;
    v184 = elt(env, 11); /* "***" */
    fn = elt(env, 15); /* lpriw */
    v292 = (*qfn2(fn))(qenv(fn), v184, v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    goto v288;

v124:
    stack[-5] = elt(env, 3); /* "assertion" */
    v47 = stack[-4];
    v184 = stack[-3];
    v292 = stack[-2];
    fn = elt(env, 13); /* assert_format */
    stack[-3] = (*qfnn(fn))(qenv(fn), 3, v47, v184, v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    stack[-2] = elt(env, 5); /* "violated by" */
    v184 = elt(env, 6); /* arg */
    v292 = stack[-1];
    fn = elt(env, 16); /* mkid */
    v184 = (*qfn2(fn))(qenv(fn), v184, v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v292 = stack[0];
    v292 = list2(v184, v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v292 = list3star(stack[-5], stack[-3], stack[-2], v292);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    goto v128;
/* error exit handlers */
v105:
    popv(7);
    return nil;
}



setup_type const u13_setup[] =
{
    {"pa_coinc_split",          too_few_2,      CC_pa_coinc_split,wrong_no_2},
    {"lambda_l9cw2t_2",         too_few_2,      CC_lambda_l9cw2t_2,wrong_no_2},
    {"modquotient:",            too_few_2,      CC_modquotientT,wrong_no_2},
    {"general-times-mod-p",     too_few_2,      CC_generalKtimesKmodKp,wrong_no_2},
    {"qqe_simplterm",           CC_qqe_simplterm,too_many_1,   wrong_no_1},
    {"mkzl",                    CC_mkzl,        too_many_1,    wrong_no_1},
    {"numpoly_nullp",           CC_numpoly_nullp,too_many_1,   wrong_no_1},
    {"matrixrowrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrowrd},
    {"dipilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipilcomb1},
    {"scalprod",                too_few_2,      CC_scalprod,   wrong_no_2},
    {"gsugar",                  CC_gsugar,      too_many_1,    wrong_no_1},
    {"wedgepf",                 too_few_2,      CC_wedgepf,    wrong_no_2},
    {"ncoeffs",                 CC_ncoeffs,     too_many_1,    wrong_no_1},
    {"prinfit",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_prinfit},
    {"defined_edge",            too_few_2,      CC_defined_edge,wrong_no_2},
    {"formcond1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond1},
    {"mv-domainlist-*",         too_few_2,      CC_mvKdomainlistKH,wrong_no_2},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"subsetp",                 too_few_2,      CC_subsetp,    wrong_no_2},
    {"dl_get",                  CC_dl_get,      too_many_1,    wrong_no_1},
    {"removeg2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg2},
    {"freevarinexptchk",        CC_freevarinexptchk,too_many_1,wrong_no_1},
    {"pasf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwmkatl},
    {"ibalp_hassimple",         CC_ibalp_hassimple,too_many_1, wrong_no_1},
    {"maxtype",                 CC_maxtype,     too_many_1,    wrong_no_1},
    {"actual_alst",             too_few_2,      CC_actual_alst,wrong_no_2},
    {"assert_check1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_check1},
    {"aminusp:1",               CC_aminuspT1,   too_many_1,    wrong_no_1},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"dv_skel2factor1",         too_few_2,      CC_dv_skel2factor1,wrong_no_2},
    {"cl_susiupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"rl_ordatp",               too_few_2,      CC_rl_ordatp,  wrong_no_2},
    {"spband_matrix",           too_few_2,      CC_spband_matrix,wrong_no_2},
    {"redcodmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_redcodmat},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"delete-dups",             CC_deleteKdups, too_many_1,    wrong_no_1},
    {"inttovec-solve",          too_few_2,      CC_inttovecKsolve,wrong_no_2},
    {"gpexp1p",                 CC_gpexp1p,     too_many_1,    wrong_no_1},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"evalneq",                 too_few_2,      CC_evalneq,    wrong_no_2},
    {"mo_neg",                  CC_mo_neg,      too_many_1,    wrong_no_1},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"ibalp_simpatom",          CC_ibalp_simpatom,too_many_1,  wrong_no_1},
    {"ratpoly_lc",              CC_ratpoly_lc,  too_many_1,    wrong_no_1},
    {"poly-abs",                CC_polyKabs,    too_many_1,    wrong_no_1},
    {"mathml2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml2},
    {"getrtype1",               CC_getrtype1,   too_many_1,    wrong_no_1},
    {"add_minus",               CC_add_minus,   too_many_1,    wrong_no_1},
    {"guesspftype",             CC_guesspftype, too_many_1,    wrong_no_1},
    {":dmpluslst",              CC_Tdmpluslst,  too_many_1,    wrong_no_1},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"deleteall",               too_few_2,      CC_deleteall,  wrong_no_2},
    {"quotdd",                  too_few_2,      CC_quotdd,     wrong_no_2},
    {"assert_error",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_error},
    {NULL, (one_args *)"u13", (two_args *)"12093 1749442 718204", 0}
};

/* end of generated code */
