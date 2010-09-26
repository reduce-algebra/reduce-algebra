
/* $destdir\u33.c        Machine generated C code */

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


/* Code for ofsf_qesubqat */

static Lisp_Object MS_CDECL CC_ofsf_qesubqat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_qesubqat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qesubqat");
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
    stack[-3] = stack[-1];
    v41 = stack[-2];
    fn = elt(env, 7); /* ofsf_varlat */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = Lmemq(nil, stack[-3], v41);
    if (v41 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v41 = stack[-2];
    v41 = qcdr(v41);
    stack[-3] = qcar(v41);
    v41 = stack[0];
    v41 = qcar(v41);
    if (v41 == nil) goto v45;
    v42 = stack[0];
    v41 = elt(env, 1); /* prepf */
    fn = elt(env, 8); /* sqform */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v46;

v46:
    v41 = cons(stack[-1], v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    fn = elt(env, 9); /* subf */
    v41 = (*qfn2(fn))(qenv(fn), stack[-3], v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[-1] = v41;
    v41 = stack[-2];
    v41 = qcar(v41);
    stack[0] = v41;
    v41 = qvalue(elt(env, 2)); /* !*rlqelocal */
    if (v41 == nil) goto v47;
    v42 = stack[0];
    v41 = stack[-1];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_qesubqat!-local */
        return (*qfn2(fn))(qenv(fn), v42, v41);
    }

v47:
    v42 = stack[0];
    v41 = elt(env, 3); /* equal */
    if (v42 == v41) goto v48;
    v42 = stack[0];
    v41 = elt(env, 4); /* neq */
    if (v42 == v41) goto v48;
    v43 = elt(env, 5); /* geq */
    v41 = stack[-1];
    v42 = qcdr(v41);
    v41 = qvalue(elt(env, 6)); /* nil */
    v42 = list3(v43, v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 11); /* ofsf_surep */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (!(v41 == nil)) goto v48;
    v41 = stack[-1];
    v41 = qcdr(v41);
    fn = elt(env, 12); /* sfto_pdecf */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = qcar(v41);
    stack[-2] = v41;
    v43 = elt(env, 5); /* geq */
    v42 = stack[-2];
    v41 = qvalue(elt(env, 6)); /* nil */
    v42 = list3(v43, v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v41 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 11); /* ofsf_surep */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (v41 == nil) goto v49;
    v42 = stack[0];
    v41 = stack[-1];
    v41 = qcar(v41);
    v43 = qvalue(elt(env, 6)); /* nil */
    popv(5);
    return list3(v42, v41, v43);

v49:
    v41 = stack[-1];
    v42 = qcar(v41);
    v41 = stack[-2];
    fn = elt(env, 13); /* multf */
    v41 = (*qfn2(fn))(qenv(fn), v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v42 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v50 = stack[0];
        popv(5);
        return list3(v50, v41, v42);
    }

v48:
    v42 = stack[0];
    v41 = stack[-1];
    v41 = qcar(v41);
    v43 = qvalue(elt(env, 6)); /* nil */
    popv(5);
    return list3(v42, v41, v43);

v45:
    v41 = (Lisp_Object)1; /* 0 */
    goto v46;
/* error exit handlers */
v44:
    popv(5);
    return nil;
}



/* Code for taymindegreel */

static Lisp_Object CC_taymindegreel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taymindegreel");
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
    goto v8;

v8:
    v59 = stack[-2];
    if (v59 == nil) goto v61;
    v59 = stack[-2];
    v59 = qcar(v59);
    stack[0] = v59;
    v59 = (Lisp_Object)1; /* 0 */
    v60 = v59;
    goto v34;

v34:
    v59 = stack[0];
    if (v59 == nil) goto v62;
    v59 = stack[0];
    v59 = qcar(v59);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v59 = (*qfn2(fn))(qenv(fn), v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    v60 = v59;
    v59 = stack[0];
    v59 = qcdr(v59);
    stack[0] = v59;
    goto v34;

v62:
    v59 = v60;
    v60 = v59;
    v59 = stack[-1];
    v59 = qcar(v59);
    fn = elt(env, 2); /* tayexp!-min2 */
    v60 = (*qfn2(fn))(qenv(fn), v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    v59 = stack[-3];
    v59 = cons(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-4];
    stack[-3] = v59;
    v59 = stack[-2];
    v59 = qcdr(v59);
    stack[-2] = v59;
    v59 = stack[-1];
    v59 = qcdr(v59);
    stack[-1] = v59;
    goto v8;

v61:
    v59 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v59);
    }
/* error exit handlers */
v63:
    popv(5);
    return nil;
}



/* Code for my!+nullsq!+p */

static Lisp_Object CC_myLnullsqLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my+nullsq+p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v64 = v0;
/* end of prologue */
    v64 = qcar(v64);
    if (v64 == nil) goto v8;
    v64 = nil;
    return onevalue(v64);

v8:
    v64 = qvalue(elt(env, 1)); /* t */
    return onevalue(v64);
}



/* Code for vectorml */

static Lisp_Object CC_vectorml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vectorml");
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
    v69 = elt(env, 1); /* "<vector>" */
    fn = elt(env, 4); /* printout */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    v58 = qvalue(elt(env, 2)); /* indent */
    v69 = (Lisp_Object)49; /* 3 */
    v69 = plus2(v58, v69);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    qvalue(elt(env, 2)) = v69; /* indent */
    v69 = stack[0];
    v69 = qcar(v69);
    fn = elt(env, 5); /* multi_elem */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    v58 = qvalue(elt(env, 2)); /* indent */
    v69 = (Lisp_Object)49; /* 3 */
    v69 = difference2(v58, v69);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    qvalue(elt(env, 2)) = v69; /* indent */
    v69 = elt(env, 3); /* "</vector>" */
    fn = elt(env, 4); /* printout */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v54;
    v69 = nil;
    { popv(2); return onevalue(v69); }
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:prep");
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
    stack[-1] = v0;
/* end of prologue */
    v135 = elt(env, 1); /* !:rd!: */
    v134 = stack[-1];
    v134 = qcdr(v134);
    v134 = qcar(v134);
    v134 = cons(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[-3] = v134;
    v134 = qvalue(elt(env, 2)); /* !*noconvert */
    if (v134 == nil) goto v65;
    v134 = stack[-3];
    v134 = qcdr(v134);
    if (!consp(v134)) goto v69;
    v135 = stack[-3];
    v134 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* round!:mt */
    v134 = (*qfn2(fn))(qenv(fn), v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v137;

v137:
    stack[-3] = v134;
    goto v138;

v138:
    v135 = elt(env, 1); /* !:rd!: */
    v134 = stack[-1];
    v134 = qcdr(v134);
    v134 = qcdr(v134);
    v134 = cons(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[-2] = v134;
    v134 = qvalue(elt(env, 2)); /* !*noconvert */
    if (v134 == nil) goto v139;
    v134 = stack[-2];
    v134 = qcdr(v134);
    if (!consp(v134)) goto v140;
    v135 = stack[-2];
    v134 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* round!:mt */
    v134 = (*qfn2(fn))(qenv(fn), v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v141;

v141:
    v134 = cons(stack[-3], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v134);
    }

v140:
    v134 = stack[-2];
    goto v141;

v139:
    v134 = stack[-2];
    v134 = qcdr(v134);
    if (!consp(v134)) goto v142;
    stack[-1] = qvalue(elt(env, 6)); /* bfone!* */
    stack[0] = stack[-2];
    v135 = qvalue(elt(env, 3)); /* !:bprec!: */
    v134 = (Lisp_Object)49; /* 3 */
    v134 = difference2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 7); /* round!:mt */
    v134 = (*qfn2(fn))(qenv(fn), stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 9); /* csl_normbf */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 10); /* equal!: */
    v134 = (*qfn2(fn))(qenv(fn), stack[-1], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v143;

v143:
    if (v134 == nil) goto v144;
    v134 = (Lisp_Object)17; /* 1 */
    goto v141;

v144:
    v134 = stack[-2];
    v134 = qcdr(v134);
    if (!consp(v134)) goto v145;
    stack[0] = elt(env, 1); /* !:rd!: */
    v134 = stack[-2];
    v134 = qcdr(v134);
    v134 = qcar(v134);
    v135 = negate(v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = stack[-2];
    v134 = qcdr(v134);
    v134 = qcdr(v134);
    v134 = list2star(stack[0], v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v146;

v146:
    v135 = v134;
    v135 = qcdr(v135);
    if (!consp(v135)) goto v147;
    stack[-1] = qvalue(elt(env, 6)); /* bfone!* */
    stack[0] = v134;
    v135 = qvalue(elt(env, 3)); /* !:bprec!: */
    v134 = (Lisp_Object)49; /* 3 */
    v134 = difference2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 7); /* round!:mt */
    v134 = (*qfn2(fn))(qenv(fn), stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 9); /* csl_normbf */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 10); /* equal!: */
    v134 = (*qfn2(fn))(qenv(fn), stack[-1], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v148;

v148:
    if (v134 == nil) goto v149;
    v134 = (Lisp_Object)-15; /* -1 */
    goto v141;

v149:
    v134 = stack[-2];
    v134 = qcdr(v134);
    if (!consp(v134)) goto v150;
    v135 = stack[-2];
    v134 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* round!:mt */
    v134 = (*qfn2(fn))(qenv(fn), v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v141;

v150:
    v134 = stack[-2];
    goto v141;

v147:
    v135 = elt(env, 4); /* 1.0 */
    v134 = qcdr(v134);
    v134 = difference2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v135 = Labsval(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = qvalue(elt(env, 5)); /* !!fleps1 */
    v134 = (Lisp_Object)lessp2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v134 = v134 ? lisp_true : nil;
    env = stack[-4];
    goto v148;

v145:
    stack[0] = elt(env, 1); /* !:rd!: */
    v134 = stack[-2];
    v134 = qcdr(v134);
    v134 = negate(v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = cons(stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v146;

v142:
    v135 = elt(env, 4); /* 1.0 */
    v134 = stack[-2];
    v134 = qcdr(v134);
    v134 = difference2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v135 = Labsval(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = qvalue(elt(env, 5)); /* !!fleps1 */
    v134 = (Lisp_Object)lessp2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v134 = v134 ? lisp_true : nil;
    env = stack[-4];
    goto v143;

v69:
    v134 = stack[-3];
    goto v137;

v65:
    v134 = stack[-3];
    v134 = qcdr(v134);
    if (!consp(v134)) goto v151;
    stack[-2] = qvalue(elt(env, 6)); /* bfone!* */
    stack[0] = stack[-3];
    v135 = qvalue(elt(env, 3)); /* !:bprec!: */
    v134 = (Lisp_Object)49; /* 3 */
    v134 = difference2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 7); /* round!:mt */
    v134 = (*qfn2(fn))(qenv(fn), stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 9); /* csl_normbf */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 10); /* equal!: */
    v134 = (*qfn2(fn))(qenv(fn), stack[-2], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v152;

v152:
    if (v134 == nil) goto v153;
    v134 = (Lisp_Object)17; /* 1 */
    stack[-3] = v134;
    goto v138;

v153:
    v134 = stack[-3];
    v134 = qcdr(v134);
    if (!consp(v134)) goto v154;
    stack[0] = elt(env, 1); /* !:rd!: */
    v134 = stack[-3];
    v134 = qcdr(v134);
    v134 = qcar(v134);
    v135 = negate(v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = stack[-3];
    v134 = qcdr(v134);
    v134 = qcdr(v134);
    v134 = list2star(stack[0], v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v155;

v155:
    v135 = v134;
    v135 = qcdr(v135);
    if (!consp(v135)) goto v156;
    stack[-2] = qvalue(elt(env, 6)); /* bfone!* */
    stack[0] = v134;
    v135 = qvalue(elt(env, 3)); /* !:bprec!: */
    v134 = (Lisp_Object)49; /* 3 */
    v134 = difference2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 7); /* round!:mt */
    v134 = (*qfn2(fn))(qenv(fn), stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 9); /* csl_normbf */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    fn = elt(env, 10); /* equal!: */
    v134 = (*qfn2(fn))(qenv(fn), stack[-2], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v157;

v157:
    if (v134 == nil) goto v7;
    v134 = (Lisp_Object)-15; /* -1 */
    stack[-3] = v134;
    goto v138;

v7:
    v134 = stack[-3];
    v134 = qcdr(v134);
    if (!consp(v134)) goto v43;
    v135 = stack[-3];
    v134 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* round!:mt */
    v134 = (*qfn2(fn))(qenv(fn), v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v42;

v42:
    stack[-3] = v134;
    goto v138;

v43:
    v134 = stack[-3];
    goto v42;

v156:
    v135 = elt(env, 4); /* 1.0 */
    v134 = qcdr(v134);
    v134 = difference2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v135 = Labsval(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = qvalue(elt(env, 5)); /* !!fleps1 */
    v134 = (Lisp_Object)lessp2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v134 = v134 ? lisp_true : nil;
    env = stack[-4];
    goto v157;

v154:
    stack[0] = elt(env, 1); /* !:rd!: */
    v134 = stack[-3];
    v134 = qcdr(v134);
    v134 = negate(v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = cons(stack[0], v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v155;

v151:
    v135 = elt(env, 4); /* 1.0 */
    v134 = stack[-3];
    v134 = qcdr(v134);
    v134 = difference2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v135 = Labsval(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = qvalue(elt(env, 5)); /* !!fleps1 */
    v134 = (Lisp_Object)lessp2(v135, v134);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v134 = v134 ? lisp_true : nil;
    env = stack[-4];
    goto v152;
/* error exit handlers */
v136:
    popv(5);
    return nil;
}



/* Code for compl */

static Lisp_Object CC_compl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v132, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compl");
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
    v45 = nil;
    goto v8;

v8:
    v36 = stack[-1];
    if (v36 == nil) goto v61;
    v36 = stack[-1];
    v132 = qcar(v36);
    v36 = stack[0];
    v36 = Lmember(nil, v132, v36);
    if (v36 == nil) goto v54;
    v36 = stack[-1];
    v36 = qcdr(v36);
    stack[-1] = v36;
    goto v8;

v54:
    v36 = stack[-1];
    v36 = qcar(v36);
    v132 = v45;
    v36 = cons(v36, v132);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-2];
    v45 = v36;
    v36 = stack[-1];
    v36 = qcdr(v36);
    stack[-1] = v36;
    goto v8;

v61:
    v36 = v45;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v152:
    popv(3);
    return nil;
}



/* Code for make_spoly_pair */

static Lisp_Object CC_make_spoly_pair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166, v167, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make_spoly_pair");
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

v67:
    v166 = stack[-2];
    v165 = stack[-3];
    fn = elt(env, 3); /* pfordp */
    v165 = (*qfn2(fn))(qenv(fn), v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    if (v165 == nil) goto v131;
    v165 = stack[-2];
    v166 = v165;
    v165 = stack[-3];
    stack[-2] = v165;
    v165 = v166;
    stack[-3] = v165;
    goto v67;

v131:
    v165 = stack[-3];
    fn = elt(env, 4); /* xval */
    stack[0] = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    v165 = stack[-2];
    fn = elt(env, 4); /* xval */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    fn = elt(env, 5); /* xlcm */
    v165 = (*qfn2(fn))(qenv(fn), stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    stack[-4] = v165;
    v165 = stack[-3];
    v165 = qcdr(v165);
    if (!(v165 == nil)) goto v56;
    v165 = stack[-2];
    v165 = qcdr(v165);
    if (!(v165 == nil)) goto v56;
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v165); }

v56:
    stack[-1] = stack[-4];
    v165 = stack[-3];
    fn = elt(env, 4); /* xval */
    stack[0] = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    v165 = stack[-2];
    fn = elt(env, 4); /* xval */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    fn = elt(env, 6); /* triviallcm */
    v165 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    if (v165 == nil) goto v168;
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v165); }

v168:
    v165 = stack[-4];
    fn = elt(env, 7); /* mknwedge */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    fn = elt(env, 8); /* xdegreecheck */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-5];
    if (v165 == nil) goto v169;
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v165); }

v169:
    v167 = stack[-4];
    v27 = elt(env, 2); /* spoly_pair */
    v166 = stack[-3];
    v165 = stack[-2];
    popv(6);
    return list4(v167, v27, v166, v165);
/* error exit handlers */
v155:
    popv(6);
    return nil;
}



/* Code for gbftimes */

static Lisp_Object CC_gbftimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v63, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbftimes");
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
    v63 = v1;
    v172 = v0;
/* end of prologue */
    v171 = v172;
    v171 = qcar(v171);
    stack[-4] = v171;
    v171 = v172;
    v171 = qcdr(v171);
    stack[-3] = v171;
    v171 = v63;
    v171 = qcar(v171);
    stack[-2] = v171;
    v171 = v63;
    v171 = qcdr(v171);
    stack[-1] = v171;
    v63 = stack[-4];
    v171 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v63, v171);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v63 = stack[-3];
    v171 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v171 = (*qfn2(fn))(qenv(fn), v63, v171);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    fn = elt(env, 2); /* difbf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v171);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v63 = stack[-4];
    v171 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v63, v171);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v63 = stack[-3];
    v171 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v171 = (*qfn2(fn))(qenv(fn), v63, v171);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    fn = elt(env, 3); /* plubf */
    v171 = (*qfn2(fn))(qenv(fn), stack[-1], v171);
    nil = C_nil;
    if (exception_pending()) goto v126;
    {
        Lisp_Object v127 = stack[0];
        popv(6);
        return cons(v127, v171);
    }
/* error exit handlers */
v126:
    popv(6);
    return nil;
}



/* Code for evaluate2 */

static Lisp_Object MS_CDECL CC_evaluate2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v94, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate2");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    v94 = v1;
    stack[-4] = v0;
/* end of prologue */
    v143 = stack[-4];
    v144 = elt(env, 1); /* !:dn!: */
    if (v143 == v144) goto v8;
    v144 = v94;
    stack[-5] = v144;
    v144 = stack[-5];
    if (v144 == nil) goto v33;
    v144 = stack[-5];
    v144 = qcar(v144);
    v94 = v144;
    v144 = stack[-3];
    fn = elt(env, 6); /* evaluate1 */
    v144 = (*qfn2(fn))(qenv(fn), v94, v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    stack[-1] = v144;
    stack[-2] = v144;
    goto v69;

v69:
    v144 = stack[-5];
    v144 = qcdr(v144);
    stack[-5] = v144;
    v144 = stack[-5];
    if (v144 == nil) goto v55;
    stack[0] = stack[-1];
    v144 = stack[-5];
    v144 = qcar(v144);
    v94 = v144;
    v144 = stack[-3];
    fn = elt(env, 6); /* evaluate1 */
    v144 = (*qfn2(fn))(qenv(fn), v94, v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v144 = Lrplacd(nil, stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v144 = stack[-1];
    v144 = qcdr(v144);
    stack[-1] = v144;
    goto v69;

v55:
    v144 = stack[-2];
    goto v137;

v137:
    v94 = v144;
    v143 = stack[-4];
    v144 = elt(env, 3); /* plus */
    if (v143 == v144) goto v195;
    v143 = stack[-4];
    v144 = elt(env, 4); /* times */
    if (v143 == v144) goto v167;
    v143 = stack[-4];
    v144 = qvalue(elt(env, 5)); /* dmarith!* */
    v144 = Lassoc(nil, v143, v144);
    v143 = v144;
    if (v144 == nil) goto v196;
    v144 = v143;
    v144 = qcdr(v144);
    {
        popv(7);
        fn = elt(env, 7); /* apply */
        return (*qfn2(fn))(qenv(fn), v144, v94);
    }

v196:
    v144 = v94;
    v144 = qcar(v144);
    v144 = Lconsp(nil, v144);
    env = stack[-6];
    if (v144 == nil) goto v120;
    v143 = stack[-4];
    v144 = v94;
    v144 = qcar(v144);
    v144 = qcar(v144);
    v144 = get(v143, v144);
    env = stack[-6];
    v143 = v144;
    if (v144 == nil) goto v120;
    v144 = v143;
    {
        popv(7);
        fn = elt(env, 7); /* apply */
        return (*qfn2(fn))(qenv(fn), v144, v94);
    }

v120:
    v144 = v94;
    stack[-3] = v144;
    v144 = stack[-3];
    if (v144 == nil) goto v197;
    v144 = stack[-3];
    v144 = qcar(v144);
    v94 = v144;
    v144 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 8); /* prepf1 */
    v144 = (*qfn2(fn))(qenv(fn), v94, v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v94 = v144;
    v144 = v94;
    if (v144 == nil) goto v43;
    v144 = v94;
    fn = elt(env, 9); /* replus */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    goto v42;

v42:
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    stack[-1] = v144;
    stack[-2] = v144;
    goto v11;

v11:
    v144 = stack[-3];
    v144 = qcdr(v144);
    stack[-3] = v144;
    v144 = stack[-3];
    if (v144 == nil) goto v198;
    stack[0] = stack[-1];
    v144 = stack[-3];
    v144 = qcar(v144);
    v94 = v144;
    v144 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 8); /* prepf1 */
    v144 = (*qfn2(fn))(qenv(fn), v94, v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v94 = v144;
    v144 = v94;
    if (v144 == nil) goto v199;
    v144 = v94;
    fn = elt(env, 9); /* replus */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    goto v200;

v200:
    v144 = ncons(v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v144 = Lrplacd(nil, stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v144 = stack[-1];
    v144 = qcdr(v144);
    stack[-1] = v144;
    goto v11;

v199:
    v144 = (Lisp_Object)1; /* 0 */
    goto v200;

v198:
    v144 = stack[-2];
    goto v119;

v119:
    v144 = cons(stack[-4], v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    fn = elt(env, 10); /* simp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-6];
    v144 = qcar(v144);
    {
        popv(7);
        fn = elt(env, 11); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v144);
    }

v43:
    v144 = (Lisp_Object)1; /* 0 */
    goto v42;

v197:
    v144 = qvalue(elt(env, 2)); /* nil */
    goto v119;

v167:
    v144 = v94;
    {
        popv(7);
        fn = elt(env, 12); /* !:dmtimeslst */
        return (*qfn1(fn))(qenv(fn), v144);
    }

v195:
    v144 = v94;
    {
        popv(7);
        fn = elt(env, 13); /* !:dmpluslst */
        return (*qfn1(fn))(qenv(fn), v144);
    }

v33:
    v144 = qvalue(elt(env, 2)); /* nil */
    goto v137;

v8:
    v144 = v94;
    fn = elt(env, 14); /* dn!:simp */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v194;
    v144 = qcar(v144);
    { popv(7); return onevalue(v144); }
/* error exit handlers */
v194:
    popv(7);
    return nil;
}



/* Code for lispreadp */

static Lisp_Object CC_lispreadp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispreadp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v202 = v0;
/* end of prologue */
    v64 = elt(env, 1); /* read */
        return Leqcar(nil, v202, v64);
}



/* Code for bas_make */

static Lisp_Object CC_bas_make(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_make");
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
    v137 = v0;
/* end of prologue */
    stack[-3] = v137;
    stack[-1] = stack[-2];
    v137 = stack[-2];
    stack[0] = Llength(nil, v137);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v137 = stack[-2];
    fn = elt(env, 2); /* dp_ecart */
    v69 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-4];
    v137 = qvalue(elt(env, 1)); /* nil */
    v137 = list2(v69, v137);
    nil = C_nil;
    if (exception_pending()) goto v34;
    {
        Lisp_Object v203 = stack[-3];
        Lisp_Object v161 = stack[-1];
        Lisp_Object v170 = stack[0];
        popv(5);
        return list3star(v203, v161, v170, v137);
    }
/* error exit handlers */
v34:
    popv(5);
    return nil;
}



/* Code for extract_vars */

static Lisp_Object CC_extract_vars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extract_vars");
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
    goto v10;

v10:
    v36 = stack[0];
    if (v36 == nil) goto v201;
    v36 = stack[0];
    v36 = qcar(v36);
    fn = elt(env, 2); /* raiseind!: */
    v132 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v36 = elt(env, 1); /* variable */
    v36 = Lflagp(nil, v132, v36);
    env = stack[-2];
    if (v36 == nil) goto v158;
    v36 = stack[0];
    v132 = qcar(v36);
    v36 = stack[-1];
    v36 = cons(v132, v36);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    stack[-1] = v36;
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v10;

v158:
    v36 = stack[0];
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v10;

v201:
    v36 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v125:
    popv(3);
    return nil;
}



/* Code for lessppair */

static Lisp_Object CC_lessppair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v35, v36, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lessppair");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v1;
    v36 = v0;
/* end of prologue */
    v62 = v36;
    v132 = qcar(v62);
    v62 = v35;
    v62 = qcar(v62);
    if (equal(v132, v62)) goto v164;
    v62 = v36;
    v62 = qcar(v62);
    v35 = qcar(v35);
        return Llessp(nil, v62, v35);

v164:
    v62 = v36;
    v62 = qcdr(v62);
    v35 = qcdr(v35);
        return Llessp(nil, v62, v35);
}



/* Code for sfto_updecf */

static Lisp_Object CC_sfto_updecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_updecf");
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
    v58 = v0;
/* end of prologue */
    v69 = qvalue(elt(env, 1)); /* !*sfto_yun */
    if (v69 == nil) goto v10;
    v69 = v58;
    {
        popv(1);
        fn = elt(env, 5); /* sfto_yun!-updecf */
        return (*qfn1(fn))(qenv(fn), v69);
    }

v10:
    v69 = qvalue(elt(env, 2)); /* !*sfto_musser */
    if (v69 == nil) goto v193;
    v69 = v58;
    {
        popv(1);
        fn = elt(env, 6); /* sfto_musser!-updecf */
        return (*qfn1(fn))(qenv(fn), v69);
    }

v193:
    v69 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v69 == nil)) goto v40;
    v69 = elt(env, 4); /* "sfto_updecf: select a decomposition method" 
*/
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[0];
    fn = elt(env, 7); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[0];
    goto v40;

v40:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v69 = nil;
    { popv(1); return onevalue(v69); }
/* error exit handlers */
v57:
    popv(1);
    return nil;
}



/* Code for subtractinds */

static Lisp_Object MS_CDECL CC_subtractinds(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v205;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subtractinds");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subtractinds");
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

v201:
    v60 = stack[-2];
    if (v60 == nil) goto v64;
    v60 = stack[-3];
    v205 = qcar(v60);
    v60 = stack[-2];
    v60 = qcar(v60);
    v60 = qcar(v60);
    v205 = difference2(v205, v60);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-5];
    v60 = (Lisp_Object)1; /* 0 */
    v60 = (Lisp_Object)lessp2(v205, v60);
    nil = C_nil;
    if (exception_pending()) goto v31;
    v60 = v60 ? lisp_true : nil;
    env = stack[-5];
    if (v60 == nil) goto v46;
    v60 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v60); }

v46:
    v60 = stack[-3];
    v60 = qcdr(v60);
    stack[-4] = v60;
    v60 = stack[-2];
    v60 = qcdr(v60);
    stack[0] = v60;
    v60 = stack[-3];
    v205 = qcar(v60);
    v60 = stack[-2];
    v60 = qcar(v60);
    v60 = qcar(v60);
    v205 = difference2(v205, v60);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-5];
    v60 = stack[-1];
    v60 = cons(v205, v60);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-5];
    stack[-1] = v60;
    v60 = stack[0];
    stack[-2] = v60;
    v60 = stack[-4];
    stack[-3] = v60;
    goto v201;

v64:
    v60 = stack[-1];
        popv(6);
        return Lnreverse(nil, v60);
/* error exit handlers */
v31:
    popv(6);
    return nil;
}



/* Code for pasf_cein */

static Lisp_Object CC_pasf_cein(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_cein");
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
    v143 = stack[-3];
    v94 = elt(env, 1); /* true */
    if (v143 == v94) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v143 = stack[-3];
    v94 = elt(env, 2); /* false */
    if (v143 == v94) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v143 = stack[-3];
    v94 = elt(env, 1); /* true */
    if (v143 == v94) goto v170;
    v143 = stack[-3];
    v94 = elt(env, 2); /* false */
    if (v143 == v94) goto v170;
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = Lconsp(nil, v94);
    env = stack[-5];
    if (v94 == nil) goto v59;
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = qcar(v94);
    v143 = v94;
    goto v54;

v54:
    v94 = elt(env, 3); /* (leq greaterp geq lessp) */
    v94 = Lmemq(nil, v143, v94);
    if (v94 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v94 = stack[-3];
    v94 = qcdr(v94);
    v94 = qcar(v94);
    fn = elt(env, 9); /* pasf_deci */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    stack[-2] = v94;
    v94 = stack[-2];
    v94 = qcar(v94);
    fn = elt(env, 10); /* sfto_dcontentf */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    stack[-4] = v94;
    v94 = stack[-3];
    stack[-1] = qcar(v94);
    v94 = stack[-4];
    fn = elt(env, 11); /* simp */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v94 = qcar(v94);
    v143 = qvalue(elt(env, 4)); /* !*exp */
    if (v143 == nil) goto v215;
    v143 = qvalue(elt(env, 5)); /* !*mcd */
    if (v143 == nil) goto v215;
    v143 = stack[-2];
    v143 = qcar(v143);
    fn = elt(env, 12); /* quotfx1 */
    v94 = (*qfn2(fn))(qenv(fn), v143, v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    stack[0] = v94;
    goto v14;

v14:
    v143 = stack[-3];
    v94 = elt(env, 1); /* true */
    if (v143 == v94) goto v185;
    v143 = stack[-3];
    v94 = elt(env, 2); /* false */
    if (v143 == v94) goto v185;
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = Lconsp(nil, v94);
    env = stack[-5];
    if (v94 == nil) goto v113;
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = qcar(v94);
    v143 = v94;
    goto v112;

v112:
    v94 = elt(env, 6); /* (leq greaterp) */
    v94 = Lmemq(nil, v143, v94);
    if (v94 == nil) goto v216;
    v94 = stack[-2];
    v94 = qcdr(v94);
    v143 = negate(v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v94 = stack[-4];
    fn = elt(env, 13); /* pasf_floor */
    v94 = (*qfn2(fn))(qenv(fn), v143, v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    fn = elt(env, 14); /* negf */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    goto v27;

v27:
    fn = elt(env, 15); /* addf */
    v94 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v143 = qvalue(elt(env, 8)); /* nil */
    {
        Lisp_Object v194 = stack[-1];
        popv(6);
        return list3(v194, v94, v143);
    }

v216:
    v143 = stack[-3];
    v94 = elt(env, 1); /* true */
    if (v143 == v94) goto v44;
    v143 = stack[-3];
    v94 = elt(env, 2); /* false */
    if (v143 == v94) goto v44;
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = Lconsp(nil, v94);
    env = stack[-5];
    if (v94 == nil) goto v217;
    v94 = stack[-3];
    v94 = qcar(v94);
    v94 = qcar(v94);
    v143 = v94;
    goto v43;

v43:
    v94 = elt(env, 7); /* (geq lessp) */
    v94 = Lmemq(nil, v143, v94);
    if (v94 == nil) goto v5;
    v94 = stack[-2];
    v94 = qcdr(v94);
    v143 = negate(v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v94 = stack[-4];
    fn = elt(env, 16); /* pasf_ceil */
    v94 = (*qfn2(fn))(qenv(fn), v143, v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    fn = elt(env, 14); /* negf */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    goto v27;

v5:
    v94 = nil;
    goto v27;

v217:
    v94 = stack[-3];
    v94 = qcar(v94);
    v143 = v94;
    goto v43;

v44:
    v94 = stack[-3];
    v143 = v94;
    goto v43;

v113:
    v94 = stack[-3];
    v94 = qcar(v94);
    v143 = v94;
    goto v112;

v185:
    v94 = stack[-3];
    v143 = v94;
    goto v112;

v215:
    v143 = stack[-2];
    v143 = qcar(v143);
    fn = elt(env, 17); /* quotf */
    v94 = (*qfn2(fn))(qenv(fn), v143, v94);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    stack[0] = v94;
    goto v14;

v59:
    v94 = stack[-3];
    v94 = qcar(v94);
    v143 = v94;
    goto v54;

v170:
    v94 = stack[-3];
    v143 = v94;
    goto v54;
/* error exit handlers */
v214:
    popv(6);
    return nil;
}



/* Code for fnrd */

static Lisp_Object MS_CDECL CC_fnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnrd");
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
    stack[0] = nil;
    fn = elt(env, 3); /* lex */
    v35 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    v36 = qvalue(elt(env, 1)); /* char */
    v35 = elt(env, 2); /* (c i) */
    if (equal(v36, v35)) goto v131;
    v35 = qvalue(elt(env, 1)); /* char */
    v36 = Lcompress(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    v35 = (Lisp_Object)321; /* 20 */
    fn = elt(env, 4); /* errorml */
    v35 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    goto v8;

v8:
    v35 = stack[0];
    if (!(!consp(v35))) goto v57;
    v35 = stack[0];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    fn = elt(env, 5); /* operator */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    fn = elt(env, 6); /* aeval */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    goto v57;

v57:
    fn = elt(env, 3); /* lex */
    v35 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v45;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v131:
    fn = elt(env, 7); /* mathml2 */
    v35 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    stack[0] = v35;
    goto v8;
/* error exit handlers */
v45:
    popv(2);
    return nil;
}



/* Code for prlist */

static Lisp_Object CC_prlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prlist");
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
    v161 = nil;
    goto v10;

v10:
    v203 = stack[0];
    if (v203 == nil) goto v201;
    v203 = stack[0];
    v203 = qcar(v203);
    v203 = Lconsp(nil, v203);
    env = stack[-1];
    if (v203 == nil) goto v57;
    v203 = stack[0];
    v203 = qcar(v203);
    v203 = cons(v203, v161);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-1];
    v161 = v203;
    v203 = stack[0];
    v203 = qcdr(v203);
    stack[0] = v203;
    goto v10;

v57:
    v203 = stack[0];
    v203 = qcdr(v203);
    stack[0] = v203;
    goto v10;

v201:
    v203 = v161;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v203);
    }
/* error exit handlers */
v158:
    popv(2);
    return nil;
}



/* Code for spcol_dim */

static Lisp_Object CC_spcol_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spcol_dim");
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
    v54 = qvalue(elt(env, 1)); /* !*fast_la */
    if (!(v54 == nil)) goto v8;
    v54 = stack[0];
    fn = elt(env, 4); /* matrixp */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    if (!(v54 == nil)) goto v8;
    v54 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v54 == nil)) goto v164;
    v54 = elt(env, 3); /* "Error in spcol_dim: input should be a matrix." 
*/
    fn = elt(env, 5); /* lprie */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    goto v164;

v164:
    v54 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    goto v8;

v8:
    v54 = stack[0];
    fn = elt(env, 6); /* spmatlength */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = qcar(v54);
    { popv(2); return onevalue(v54); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for subfindices */

static Lisp_Object CC_subfindices(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subfindices");
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
    stack[-3] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v233 = qvalue(elt(env, 2)); /* nil */
    v233 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    qvalue(elt(env, 1)) = v233; /* alglist!* */
    v233 = stack[-2];
    if (!consp(v233)) goto v39;
    v233 = stack[-2];
    v233 = qcar(v233);
    if (!consp(v233)) goto v39;
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    if (!consp(v233)) goto v37;
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    if (!consp(v233)) goto v154;
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    if (!consp(v233)) goto v154;
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = stack[-1];
    v234 = CC_subfindices(env, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcdr(v233);
    fn = elt(env, 5); /* exptsq */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    stack[0] = v233;
    goto v108;

v108:
    v233 = stack[-2];
    v233 = qcar(v233);
    v234 = qcdr(v233);
    v233 = stack[-1];
    v233 = CC_subfindices(env, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    fn = elt(env, 6); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v233 = stack[-2];
    v234 = qcdr(v233);
    v233 = stack[-1];
    v233 = CC_subfindices(env, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    fn = elt(env, 7); /* addsq */
    v233 = (*qfn2(fn))(qenv(fn), stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    goto v10;

v10:
    qvalue(elt(env, 1)) = stack[-3]; /* alglist!* */
    { popv(5); return onevalue(v233); }

v154:
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = elt(env, 3); /* indexvar */
    v233 = Lflagp(nil, v234, v233);
    env = stack[-4];
    if (v233 == nil) goto v15;
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    stack[0] = qcar(v233);
    v234 = stack[-1];
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcdr(v233);
    v233 = Lsubla(nil, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v233 = cons(stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    fn = elt(env, 8); /* simpindexvar */
    v234 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcdr(v233);
    fn = elt(env, 5); /* exptsq */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    stack[0] = v233;
    goto v108;

v15:
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = elt(env, 4); /* (wedge d partdf innerprod liedf hodge vardf) 
*/
    v233 = Lmemq(nil, v234, v233);
    if (v233 == nil) goto v235;
    v234 = stack[-1];
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    fn = elt(env, 9); /* subindk */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    fn = elt(env, 10); /* simp */
    v234 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcdr(v233);
    fn = elt(env, 5); /* exptsq */
    v233 = (*qfn2(fn))(qenv(fn), v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    stack[0] = v233;
    goto v108;

v235:
    v233 = stack[-2];
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v234 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    stack[0] = v233;
    goto v108;

v37:
    v233 = stack[-2];
    v233 = qcar(v233);
    v234 = qcar(v233);
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v234 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    stack[0] = v233;
    goto v108;

v39:
    v234 = stack[-2];
    v233 = (Lisp_Object)17; /* 1 */
    v233 = cons(v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-4];
    goto v10;
/* error exit handlers */
v207:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* alglist!* */
    popv(5);
    return nil;
}



/* Code for find_buble */

static Lisp_Object CC_find_buble(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_buble");
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

v236:
    v34 = stack[0];
    if (v34 == nil) goto v10;
    v203 = stack[-1];
    v34 = stack[0];
    v34 = qcar(v34);
    fn = elt(env, 2); /* is_buble */
    v34 = (*qfn2(fn))(qenv(fn), v203, v34);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-2];
    if (!(v34 == nil)) { popv(3); return onevalue(v34); }
    v203 = stack[-1];
    v34 = stack[0];
    v34 = qcdr(v34);
    stack[-1] = v203;
    stack[0] = v34;
    goto v236;

v10:
    v34 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v34); }
/* error exit handlers */
v158:
    popv(3);
    return nil;
}



/* Code for assoc2 */

static Lisp_Object CC_assoc2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v54, v33, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assoc2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v1;
    v34 = v0;
/* end of prologue */

v10:
    v57 = v33;
    if (v57 == nil) goto v201;
    v54 = v34;
    v57 = v33;
    v57 = qcar(v57);
    v57 = qcdr(v57);
    if (equal(v54, v57)) goto v67;
    v57 = v33;
    v57 = qcdr(v57);
    v33 = v57;
    goto v10;

v67:
    v57 = v33;
    v57 = qcar(v57);
    return onevalue(v57);

v201:
    v57 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v57);
}



/* Code for cquotegex */

static Lisp_Object CC_cquotegex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cquotegex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v201 = v0;
/* end of prologue */
    v201 = qvalue(elt(env, 1)); /* !*guardian */
    if (v201 == nil) goto v10;
    v201 = elt(env, 2); /* gex */
    return onevalue(v201);

v10:
    v201 = nil;
    return onevalue(v201);
}



/* Code for klistt */

static Lisp_Object CC_klistt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for klistt");
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
    goto v10;

v10:
    v38 = stack[0];
    if (!consp(v38)) goto v201;
    v38 = stack[0];
    v38 = qcar(v38);
    v52 = qcar(v38);
    v38 = stack[-1];
    v38 = cons(v52, v38);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    stack[-1] = v38;
    v38 = stack[0];
    v38 = qcdr(v38);
    if (v38 == nil) goto v69;
    v52 = elt(env, 1); /* "Wrong number of arguments to" */
    v38 = elt(env, 2); /* list */
    v38 = list2(v52, v38);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    v52 = v38;
    v38 = v52;
    qvalue(elt(env, 3)) = v38; /* errmsg!* */
    v38 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v38 == nil)) goto v237;
    v38 = v52;
    fn = elt(env, 5); /* lprie */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    goto v237;

v237:
    v38 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-2];
    v38 = nil;
    goto v137;

v137:
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v10;

v69:
    v38 = stack[0];
    v38 = qcar(v38);
    goto v137;

v201:
    v38 = stack[-1];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v38);
    }
/* error exit handlers */
v162:
    popv(3);
    return nil;
}



/* Code for simpexpt2 */

static Lisp_Object MS_CDECL CC_simpexpt2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v321, v322, v323;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt2");
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

v68:
    v322 = stack[-3];
    v321 = (Lisp_Object)17; /* 1 */
    if (v322 == v321) goto v183;
    v321 = stack[-2];
    v321 = qcar(v321);
    stack[-4] = v321;
    v321 = stack[-3];
    v321 = Lconsp(nil, v321);
    env = stack[-5];
    if (v321 == nil) goto v33;
    v321 = stack[-3];
    v322 = qcar(v321);
    v321 = elt(env, 1); /* expt */
    if (!(v322 == v321)) goto v215;
    v321 = qvalue(elt(env, 2)); /* !*precise_complex */
    if (!(v321 == nil)) goto v215;
    v321 = stack[-3];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    v321 = qcar(v321);
    fn = elt(env, 16); /* simp */
    v322 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    stack[-4] = v322;
    v321 = stack[-2];
    fn = elt(env, 17); /* multsq */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    stack[-2] = v321;
    v321 = qvalue(elt(env, 3)); /* !*precise */
    if (v321 == nil) goto v159;
    v321 = stack[-4];
    v321 = qcar(v321);
    if (!(is_number(v321))) goto v159;
    v321 = stack[-4];
    v321 = qcar(v321);
    v321 = Levenp(nil, v321);
    env = stack[-5];
    if (v321 == nil) goto v159;
    v322 = elt(env, 4); /* abs */
    v321 = stack[-3];
    v321 = qcdr(v321);
    v321 = qcar(v321);
    v321 = list2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    stack[-3] = v321;
    goto v325;

v325:
    v323 = stack[-3];
    v322 = stack[-2];
    v321 = stack[-1];
    {
        popv(6);
        fn = elt(env, 18); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v323, v322, v321);
    }

v159:
    v321 = stack[-3];
    v321 = qcdr(v321);
    v321 = qcar(v321);
    stack[-3] = v321;
    goto v325;

v215:
    v321 = stack[-3];
    v322 = qcar(v321);
    v321 = elt(env, 5); /* sqrt */
    if (!(v322 == v321)) goto v326;
    v321 = qvalue(elt(env, 6)); /* !*keepsqrts */
    if (!(v321 == nil)) goto v326;
    v321 = stack[-3];
    v321 = qcdr(v321);
    stack[0] = qcar(v321);
    v322 = (Lisp_Object)17; /* 1 */
    v321 = (Lisp_Object)33; /* 2 */
    v322 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v321 = stack[-2];
    fn = elt(env, 17); /* multsq */
    v322 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v321 = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v322;
    stack[-1] = v321;
    goto v68;

v326:
    v321 = stack[-3];
    v322 = qcar(v321);
    v321 = elt(env, 7); /* times */
    if (!(v322 == v321)) goto v221;
    v321 = qvalue(elt(env, 3)); /* !*precise */
    if (!(v321 == nil)) goto v221;
    v322 = (Lisp_Object)17; /* 1 */
    v321 = (Lisp_Object)17; /* 1 */
    v321 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    stack[-4] = v321;
    v321 = stack[-3];
    v321 = qcdr(v321);
    stack[0] = v321;
    goto v212;

v212:
    v321 = stack[0];
    if (v321 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v321 = stack[0];
    v321 = qcar(v321);
    v323 = v321;
    v322 = stack[-2];
    v321 = stack[-1];
    fn = elt(env, 18); /* simpexpt1 */
    v322 = (*qfnn(fn))(qenv(fn), 3, v323, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v321 = stack[-4];
    fn = elt(env, 17); /* multsq */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    stack[-4] = v321;
    v321 = stack[0];
    v321 = qcdr(v321);
    stack[0] = v321;
    goto v212;

v221:
    v321 = stack[-3];
    v322 = qcar(v321);
    v321 = elt(env, 7); /* times */
    if (!(v322 == v321)) goto v99;
    v321 = stack[-3];
    v321 = qcdr(v321);
    fn = elt(env, 19); /* split!-sign */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    stack[0] = v321;
    if (v321 == nil) goto v99;
    v321 = stack[0];
    v321 = qcar(v321);
    if (v321 == nil) goto v99;
    v321 = stack[0];
    v321 = qcdr(v321);
    v322 = qcar(v321);
    v321 = stack[0];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    v321 = Lappend(nil, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    fn = elt(env, 20); /* retimes */
    v323 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v322 = stack[-2];
    v321 = stack[-1];
    fn = elt(env, 18); /* simpexpt1 */
    v321 = (*qfnn(fn))(qenv(fn), 3, v323, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    stack[-4] = v321;
    v321 = stack[0];
    v321 = qcar(v321);
    stack[0] = v321;
    goto v327;

v327:
    v321 = stack[0];
    if (v321 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v321 = stack[0];
    v321 = qcar(v321);
    v323 = v321;
    v322 = stack[-2];
    v321 = stack[-1];
    fn = elt(env, 18); /* simpexpt1 */
    v322 = (*qfnn(fn))(qenv(fn), 3, v323, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v321 = stack[-4];
    fn = elt(env, 17); /* multsq */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    stack[-4] = v321;
    v321 = stack[0];
    v321 = qcdr(v321);
    stack[0] = v321;
    goto v327;

v99:
    v321 = stack[-3];
    v322 = qcar(v321);
    v321 = elt(env, 9); /* quotient */
    if (!(v322 == v321)) goto v328;
    v321 = qvalue(elt(env, 3)); /* !*precise */
    if (v321 == nil) goto v329;
    v321 = stack[-3];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    v321 = qcar(v321);
    fn = elt(env, 21); /* posnump */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    if (v321 == nil) goto v328;
    v321 = stack[-2];
    v321 = qcar(v321);
    if (v321 == nil) goto v330;
    v322 = stack[-2];
    v321 = elt(env, 10); /* prepf */
    fn = elt(env, 22); /* sqform */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    goto v331;

v331:
    fn = elt(env, 21); /* posnump */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    if (!(v321 == nil)) goto v329;

v328:
    v321 = stack[-3];
    v322 = qcar(v321);
    v321 = elt(env, 13); /* minus */
    if (!(v322 == v321)) goto v33;
    v321 = qvalue(elt(env, 3)); /* !*precise */
    if (!(v321 == nil)) goto v33;
    v321 = stack[-3];
    v321 = qcdr(v321);
    v322 = qcar(v321);
    v321 = (Lisp_Object)17; /* 1 */
    if (v322 == v321) goto v33;
    v321 = stack[-2];
    v321 = qcar(v321);
    if (v321 == nil) goto v332;
    v322 = stack[-2];
    v321 = elt(env, 10); /* prepf */
    fn = elt(env, 22); /* sqform */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    goto v333;

v333:
    stack[-1] = v321;
    v322 = (Lisp_Object)-15; /* -1 */
    v321 = stack[-1];
    v321 = list2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    fn = elt(env, 23); /* simpexpt */
    stack[0] = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v321 = stack[-3];
    v321 = qcdr(v321);
    v322 = qcar(v321);
    v321 = stack[-1];
    v321 = list2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    fn = elt(env, 23); /* simpexpt */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    {
        Lisp_Object v334 = stack[0];
        popv(6);
        fn = elt(env, 17); /* multsq */
        return (*qfn2(fn))(qenv(fn), v334, v321);
    }

v332:
    v321 = (Lisp_Object)1; /* 0 */
    goto v333;

v33:
    v321 = stack[-1];
    if (v321 == nil) goto v335;
    v321 = stack[-3];
    if (!(is_number(v321))) goto v336;
    v321 = stack[-3];
    v321 = (Lisp_Object)zerop(v321);
    v321 = v321 ? lisp_true : nil;
    env = stack[-5];
    if (v321 == nil) goto v336;
    v322 = qvalue(elt(env, 8)); /* nil */
    v321 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v322, v321);

v336:
    v321 = stack[-4];
    if (is_number(v321)) goto v337;
    v322 = stack[-4];
    v321 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 24); /* prepf1 */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v322 = v321;
    v321 = v322;
    if (v321 == nil) goto v338;
    v321 = v322;
    fn = elt(env, 25); /* replus */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    goto v339;

v339:
    stack[-4] = v321;
    goto v337;

v337:
    v321 = stack[-2];
    v322 = qcdr(v321);
    v321 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 24); /* prepf1 */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v322 = v321;
    v321 = v322;
    if (v321 == nil) goto v340;
    v321 = v322;
    fn = elt(env, 25); /* replus */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    goto v341;

v341:
    stack[-2] = v321;
    v322 = stack[-4];
    v321 = qvalue(elt(env, 15)); /* frlis!* */
    v321 = Lmemq(nil, v322, v321);
    if (v321 == nil) goto v342;
    v322 = stack[-2];
    v321 = (Lisp_Object)17; /* 1 */
    if (!(v322 == v321)) goto v342;
    v323 = stack[-3];
    v322 = stack[-4];
    v321 = (Lisp_Object)17; /* 1 */
    v321 = acons(v323, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v322 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    v321 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v322, v321);

v342:
    v321 = qvalue(elt(env, 11)); /* !*mcd */
    if (!(v321 == nil)) goto v343;
    v321 = stack[-4];
    if (!(is_number(v321))) goto v343;
    v322 = stack[-2];
    v321 = (Lisp_Object)17; /* 1 */
    if (!(v322 == v321)) goto v343;
    v321 = stack[-3];
    if (!consp(v321)) goto v343;
    v321 = stack[-3];
    fn = elt(env, 26); /* simp!* */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v322 = qcdr(v321);
    v321 = (Lisp_Object)17; /* 1 */
    if (!(v322 == v321)) goto v343;
    v322 = stack[-3];
    v321 = stack[-4];
    {
        popv(6);
        fn = elt(env, 27); /* mksq */
        return (*qfn2(fn))(qenv(fn), v322, v321);
    }

v343:
    v323 = stack[-3];
    v322 = stack[-4];
    v321 = stack[-2];
    {
        popv(6);
        fn = elt(env, 28); /* simpx1 */
        return (*qfnn(fn))(qenv(fn), 3, v323, v322, v321);
    }

v340:
    v321 = (Lisp_Object)1; /* 0 */
    goto v341;

v338:
    v321 = (Lisp_Object)1; /* 0 */
    goto v339;

v335:
    v321 = qvalue(elt(env, 14)); /* dmode!* */
    if (v321 == nil) goto v344;
    v321 = stack[-3];
    if (!(symbolp(v321))) goto v344;
    v322 = stack[-3];
    v321 = qvalue(elt(env, 14)); /* dmode!* */
    v321 = get(v322, v321);
    env = stack[-5];
    if (!(v321 == nil)) goto v345;

v344:
    v321 = stack[-3];
    fn = elt(env, 26); /* simp!* */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v322 = v321;
    v321 = v322;
    v321 = qcar(v321);
    if (v321 == nil) goto v346;
    v321 = elt(env, 10); /* prepf */
    fn = elt(env, 22); /* sqform */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    goto v347;

v347:
    stack[-3] = v321;
    goto v345;

v345:
    v323 = stack[-3];
    v322 = stack[-2];
    v321 = qvalue(elt(env, 12)); /* t */
    {
        popv(6);
        fn = elt(env, 18); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v323, v322, v321);
    }

v346:
    v321 = (Lisp_Object)1; /* 0 */
    goto v347;

v329:
    v321 = stack[-1];
    if (!(v321 == nil)) goto v90;
    v321 = qvalue(elt(env, 11)); /* !*mcd */
    if (v321 == nil) goto v90;
    v321 = stack[-3];
    fn = elt(env, 26); /* simp!* */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v322 = v321;
    v321 = v322;
    v321 = qcar(v321);
    if (v321 == nil) goto v348;
    v321 = elt(env, 10); /* prepf */
    fn = elt(env, 22); /* sqform */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v323 = v321;
    goto v349;

v349:
    v322 = stack[-2];
    v321 = qvalue(elt(env, 12)); /* t */
    {
        popv(6);
        fn = elt(env, 18); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v323, v322, v321);
    }

v348:
    v321 = (Lisp_Object)1; /* 0 */
    v323 = v321;
    goto v349;

v90:
    v321 = stack[-2];
    v321 = qcar(v321);
    if (v321 == nil) goto v350;
    v322 = stack[-2];
    v321 = elt(env, 10); /* prepf */
    fn = elt(env, 22); /* sqform */
    v321 = (*qfn2(fn))(qenv(fn), v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    goto v351;

v351:
    stack[-2] = v321;
    v321 = stack[-3];
    v321 = qcdr(v321);
    v322 = qcar(v321);
    v321 = stack[-2];
    v321 = list2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    fn = elt(env, 23); /* simpexpt */
    stack[0] = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    v321 = stack[-3];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    v322 = qcar(v321);
    v321 = stack[-2];
    v321 = list2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    fn = elt(env, 23); /* simpexpt */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    fn = elt(env, 29); /* invsq */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-5];
    {
        Lisp_Object v352 = stack[0];
        popv(6);
        fn = elt(env, 17); /* multsq */
        return (*qfn2(fn))(qenv(fn), v352, v321);
    }

v350:
    v321 = (Lisp_Object)1; /* 0 */
    goto v351;

v330:
    v321 = (Lisp_Object)1; /* 0 */
    goto v331;

v183:
    v322 = (Lisp_Object)17; /* 1 */
    v321 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v322, v321);
/* error exit handlers */
v324:
    popv(6);
    return nil;
}



/* Code for ratpoly_minus */

static Lisp_Object CC_ratpoly_minus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_minus");
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
    v183 = v0;
/* end of prologue */
    stack[-1] = v183;
    v183 = stack[0];
    v183 = qcar(v183);
    fn = elt(env, 1); /* negf */
    v51 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = cons(v51, v183);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    {
        Lisp_Object v137 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* addsq */
        return (*qfn2(fn))(qenv(fn), v137, v183);
    }
/* error exit handlers */
v131:
    popv(3);
    return nil;
}



/* Code for bc_fd */

static Lisp_Object CC_bc_fd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_fd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v202 = v0;
/* end of prologue */
    v64 = v202;
    v202 = (Lisp_Object)17; /* 1 */
    return cons(v64, v202);
}



/* Code for ithlistelem */

static Lisp_Object CC_ithlistelem(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ithlistelem");
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
    v170 = stack[-1];
    if (v170 == nil) goto v8;
    v170 = stack[-1];
    v158 = qcar(v170);
    v170 = stack[0];
    fn = elt(env, 1); /* pnth */
    v170 = (*qfn2(fn))(qenv(fn), v158, v170);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[-2] = qcar(v170);
    v170 = stack[-1];
    v158 = qcdr(v170);
    v170 = stack[0];
    v170 = CC_ithlistelem(env, v158, v170);
    nil = C_nil;
    if (exception_pending()) goto v36;
    {
        Lisp_Object v132 = stack[-2];
        popv(4);
        return cons(v132, v170);
    }

v8:
    v170 = nil;
    { popv(4); return onevalue(v170); }
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for genexp */

static Lisp_Object CC_genexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for genexp");
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

v236:
    v70 = stack[0];
    if (!consp(v70)) goto v9;
    v70 = stack[0];
    v70 = qcar(v70);
    v70 = CC_genexp(env, v70);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    if (!(v70 == nil)) { popv(2); return onevalue(v70); }
    v70 = stack[0];
    v70 = qcdr(v70);
    stack[0] = v70;
    goto v236;

v9:
    v70 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* genp */
        return (*qfn1(fn))(qenv(fn), v70);
    }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for mkexdf */

static Lisp_Object CC_mkexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkexdf");
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
    v131 = v0;
/* end of prologue */
    v137 = elt(env, 1); /* d */
    v131 = list2(v137, v131);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    stack[0] = v131;
    fn = elt(env, 2); /* opmtch */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-1];
    v137 = v131;
    if (v131 == nil) goto v183;
    v131 = v137;
    {
        popv(2);
        fn = elt(env, 3); /* partitop */
        return (*qfn1(fn))(qenv(fn), v131);
    }

v183:
    v131 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v131);
    }
/* error exit handlers */
v58:
    popv(2);
    return nil;
}



/* Code for simpsetdiff */

static Lisp_Object CC_simpsetdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v155, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsetdiff");
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
    v121 = v0;
/* end of prologue */
    v155 = elt(env, 1); /* setdiff */
    fn = elt(env, 3); /* applysetop */
    v121 = (*qfn2(fn))(qenv(fn), v155, v121);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[0];
    v188 = v121;
    v121 = v188;
    v155 = qcar(v121);
    v121 = elt(env, 1); /* setdiff */
    if (v155 == v121) goto v237;
    v121 = v188;
    goto v34;

v34:
    fn = elt(env, 4); /* fkern */
    v155 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[0];
    v121 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* getpower */
    v155 = (*qfn2(fn))(qenv(fn), v155, v121);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[0];
    v121 = (Lisp_Object)17; /* 1 */
    v121 = cons(v155, v121);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[0];
    v155 = ncons(v121);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v121 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v155, v121);

v237:
    v121 = v188;
    v121 = qcdr(v121);
    v155 = qcar(v121);
    v121 = v188;
    v121 = qcdr(v121);
    v121 = qcdr(v121);
    v121 = qcar(v121);
    if (equal(v155, v121)) goto v152;
    v121 = v188;
    v121 = qcdr(v121);
    v155 = qcar(v121);
    v121 = qvalue(elt(env, 2)); /* empty_set */
    if (equal(v155, v121)) goto v152;
    v121 = v188;
    v121 = qcdr(v121);
    v121 = qcdr(v121);
    v155 = qcar(v121);
    v121 = qvalue(elt(env, 2)); /* empty_set */
    if (equal(v155, v121)) goto v32;
    v121 = v188;
    goto v34;

v32:
    v121 = v188;
    v121 = qcdr(v121);
    v121 = qcar(v121);
    goto v34;

v152:
    v121 = qvalue(elt(env, 2)); /* empty_set */
    goto v34;
/* error exit handlers */
v229:
    popv(1);
    return nil;
}



/* Code for maprintla */

static Lisp_Object CC_maprintla(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v374, v375, v376;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maprintla");
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

v236:
    v374 = stack[-2];
    if (v374 == nil) goto v64;
    v374 = stack[-2];
    if (is_number(v374)) goto v85;
    v374 = stack[-2];
    if (!consp(v374)) goto v39;
    v374 = stack[-2];
    v374 = Lstringp(nil, v374);
    env = stack[-4];
    if (v374 == nil) goto v66;
    v374 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); /* prin2la */
        return (*qfn1(fn))(qenv(fn), v374);
    }

v66:
    v374 = stack[-2];
    v374 = qcar(v374);
    if (!consp(v374)) goto v192;
    v374 = stack[-2];
    v375 = qcar(v374);
    v374 = stack[-1];
    stack[-2] = v375;
    stack[-1] = v374;
    goto v236;

v192:
    v374 = stack[-2];
    v375 = qcar(v374);
    v374 = elt(env, 2); /* laprifn */
    v374 = get(v375, v374);
    env = stack[-4];
    stack[-3] = v374;
    if (v374 == nil) goto v318;
    v374 = stack[-2];
    v375 = qcar(v374);
    v374 = elt(env, 3); /* fulla */
    v374 = Lflagp(nil, v375, v374);
    env = stack[-4];
    if (!(v374 == nil)) goto v325;
    stack[0] = stack[-3];
    v374 = stack[-2];
    v375 = qcdr(v374);
    v374 = stack[-1];
    v374 = list2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    fn = elt(env, 20); /* apply */
    v375 = (*qfn2(fn))(qenv(fn), stack[0], v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    v374 = elt(env, 4); /* failed */
    if (!(v375 == v374)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v325:
    v374 = stack[-2];
    v375 = qcar(v374);
    v374 = elt(env, 3); /* fulla */
    v374 = Lflagp(nil, v375, v374);
    env = stack[-4];
    if (v374 == nil) goto v318;
    stack[0] = stack[-3];
    v375 = stack[-2];
    v374 = stack[-1];
    v374 = list2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    fn = elt(env, 20); /* apply */
    v375 = (*qfn2(fn))(qenv(fn), stack[0], v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    v374 = elt(env, 4); /* failed */
    if (!(v375 == v374)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v318:
    v374 = stack[-2];
    v375 = qcar(v374);
    v374 = elt(env, 5); /* indexed */
    v374 = get(v375, v374);
    env = stack[-4];
    stack[-3] = v374;
    if (v374 == nil) goto v378;
    v374 = stack[-2];
    v376 = qcar(v374);
    v374 = stack[-2];
    v375 = qcdr(v374);
    v374 = stack[-3];
    {
        popv(5);
        fn = elt(env, 21); /* prinidop */
        return (*qfnn(fn))(qenv(fn), 3, v376, v375, v374);
    }

v378:
    v374 = stack[-2];
    v375 = qcar(v374);
    v374 = elt(env, 6); /* infix */
    v374 = get(v375, v374);
    env = stack[-4];
    stack[-3] = v374;
    if (v374 == nil) goto v11;
    v375 = stack[-3];
    v374 = stack[-1];
    v374 = (Lisp_Object)greaterp2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    v374 = v374 ? lisp_true : nil;
    env = stack[-4];
    stack[-1] = v374;
    v374 = stack[-1];
    if (!(v374 == nil)) goto v145;
    v374 = stack[-2];
    v375 = qcar(v374);
    v374 = elt(env, 14); /* equal */
    if (!(v375 == v374)) goto v145;
    v374 = qvalue(elt(env, 15)); /* t */
    stack[-1] = v374;
    goto v145;

v145:
    v374 = stack[-1];
    if (!(v374 == nil)) goto v299;
    v374 = elt(env, 16); /* !( */
    fn = elt(env, 22); /* prinlatom */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    goto v299;

v299:
    v374 = stack[-2];
    v376 = qcar(v374);
    v375 = stack[-3];
    v374 = stack[-2];
    v374 = qcdr(v374);
    fn = elt(env, 23); /* inprinla */
    v374 = (*qfnn(fn))(qenv(fn), 3, v376, v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    v374 = stack[-1];
    if (!(v374 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v374 = elt(env, 17); /* !) */
    fn = elt(env, 22); /* prinlatom */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v11:
    v374 = stack[-2];
    v375 = qcar(v374);
    v374 = elt(env, 7); /* !:rd!: */
    if (v375 == v374) goto v12;
    v374 = stack[-2];
    v374 = qcar(v374);
    fn = elt(env, 24); /* oprinla */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    v374 = stack[-2];
    v376 = qcar(v374);
    v374 = stack[-2];
    v375 = qcdr(v374);
    v374 = stack[-1];
    fn = elt(env, 25); /* prinpopargs */
    v374 = (*qfnn(fn))(qenv(fn), 3, v376, v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v12:
    stack[-1] = qvalue(elt(env, 8)); /* !*nat */
    qvalue(elt(env, 8)) = nil; /* !*nat */
    v374 = stack[-2];
    v374 = qcdr(v374);
    v374 = Lfloatp(nil, v374);
    env = stack[-4];
    if (v374 == nil) goto v379;
    v374 = stack[-2];
    v374 = qcdr(v374);
    v374 = Llengthc(nil, v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    goto v381;

v381:
    stack[0] = v374;
    v375 = qvalue(elt(env, 9)); /* ncharspr!* */
    v374 = stack[0];
    v375 = plus2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    v374 = qvalue(elt(env, 10)); /* laline!* */
    v374 = (Lisp_Object)greaterp2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    v374 = v374 ? lisp_true : nil;
    env = stack[-4];
    if (v374 == nil) goto v106;
    v374 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    v374 = stack[0];
    qvalue(elt(env, 9)) = v374; /* ncharspr!* */
    goto v175;

v175:
    v374 = qvalue(elt(env, 11)); /* orig!* */
    qvalue(elt(env, 12)) = v374; /* posn!* */
    v374 = stack[-2];
    v374 = qcdr(v374);
    if (!consp(v374)) goto v142;
    v374 = stack[-2];
    stack[0] = v374;
    goto v382;

v382:
    v375 = qvalue(elt(env, 13)); /* !:bprec!: */
    v374 = (Lisp_Object)49; /* 3 */
    v374 = difference2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    fn = elt(env, 26); /* round!:mt */
    v374 = (*qfn2(fn))(qenv(fn), stack[0], v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    fn = elt(env, 27); /* csl_normbf */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    fn = elt(env, 28); /* bfprin0 */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    v374 = nil;
    qvalue(elt(env, 8)) = stack[-1]; /* !*nat */
    { popv(5); return onevalue(v374); }

v142:
    v374 = stack[-2];
    v374 = qcdr(v374);
    fn = elt(env, 29); /* fl2bf */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    stack[0] = v374;
    goto v382;

v106:
    v375 = qvalue(elt(env, 9)); /* ncharspr!* */
    v374 = stack[0];
    v374 = plus2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    qvalue(elt(env, 9)) = v374; /* ncharspr!* */
    goto v175;

v379:
    v374 = stack[-2];
    v374 = qcdr(v374);
    v374 = qcar(v374);
    stack[0] = Llengthc(nil, v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    v374 = stack[-2];
    v374 = qcdr(v374);
    v374 = qcdr(v374);
    v375 = Llengthc(nil, v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    v374 = (Lisp_Object)81; /* 5 */
    v374 = plus2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    v374 = plus2(stack[0], v374);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-4];
    goto v381;

v39:
    v374 = stack[-2];
    {
        popv(5);
        fn = elt(env, 22); /* prinlatom */
        return (*qfn1(fn))(qenv(fn), v374);
    }

v85:
    v375 = stack[-2];
    v374 = (Lisp_Object)1; /* 0 */
    v374 = (Lisp_Object)lessp2(v375, v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    v374 = v374 ? lisp_true : nil;
    env = stack[-4];
    if (v374 == nil) goto v348;
    v376 = stack[-1];
    v375 = elt(env, 18); /* minus */
    v374 = elt(env, 6); /* infix */
    v374 = get(v375, v374);
    env = stack[-4];
    v374 = (Lisp_Object)lessp2(v376, v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    v374 = v374 ? lisp_true : nil;
    env = stack[-4];
    if (!(v374 == nil)) goto v348;
    v374 = elt(env, 16); /* !( */
    fn = elt(env, 19); /* prin2la */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    v374 = stack[-2];
    fn = elt(env, 19); /* prin2la */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-4];
    v374 = elt(env, 17); /* !) */
    fn = elt(env, 19); /* prin2la */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v377;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v348:
    v374 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); /* prin2la */
        return (*qfn1(fn))(qenv(fn), v374);
    }

v64:
    v374 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v374); }
/* error exit handlers */
v380:
    env = stack[-4];
    qvalue(elt(env, 8)) = stack[-1]; /* !*nat */
    popv(5);
    return nil;
v377:
    popv(5);
    return nil;
}



/* Code for diff_vertex */

static Lisp_Object CC_diff_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v383, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff_vertex");
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
    v37 = nil;
    goto v8;

v8:
    v232 = stack[-1];
    if (v232 == nil) goto v61;
    v232 = stack[-1];
    v232 = qcar(v232);
    v383 = qcar(v232);
    v232 = stack[0];
    v232 = Lassoc(nil, v383, v232);
    if (v232 == nil) goto v153;
    v232 = stack[-1];
    v232 = qcar(v232);
    v383 = qcar(v232);
    v232 = qvalue(elt(env, 1)); /* !_0edge */
    v232 = qcar(v232);
    if (v383 == v232) goto v153;
    v232 = stack[-1];
    v232 = qcdr(v232);
    stack[-1] = v232;
    goto v8;

v153:
    v232 = stack[-1];
    v232 = qcar(v232);
    v383 = v37;
    v232 = cons(v232, v383);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v37 = v232;
    v232 = stack[-1];
    v232 = qcdr(v232);
    stack[-1] = v232;
    goto v8;

v61:
    v232 = v37;
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v232);
    }
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for applsmacro */

static Lisp_Object MS_CDECL CC_applsmacro(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v398, v399;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "applsmacro");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applsmacro");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-6] = v1;
    v399 = v0;
/* end of prologue */
    stack[-5] = nil;
    v398 = v399;
    v398 = qcdr(v398);
    v398 = qcar(v398);
    stack[-2] = v398;
    v398 = v399;
    v398 = qcdr(v398);
    v398 = qcdr(v398);
    v398 = qcar(v398);
    stack[-7] = v398;
    v398 = stack[-2];
    stack[0] = Llength(nil, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = stack[-6];
    v398 = Llength(nil, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    if (equal(stack[0], v398)) goto v39;
    v399 = elt(env, 1); /* "Argument mismatch for SMACRO" */
    v398 = stack[-1];
    v398 = list2(v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v399 = v398;
    v398 = v399;
    qvalue(elt(env, 2)) = v398; /* errmsg!* */
    v398 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v398 == nil)) goto v153;
    v398 = v399;
    fn = elt(env, 7); /* lprie */
    v398 = (*qfn1(fn))(qenv(fn), v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    goto v153;

v153:
    v398 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    goto v39;

v39:
    v398 = stack[-6];
    fn = elt(env, 8); /* no!-side!-effect!-listp */
    v398 = (*qfn1(fn))(qenv(fn), v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    if (!(v398 == nil)) goto v191;
    v399 = stack[-2];
    v398 = stack[-7];
    fn = elt(env, 9); /* one!-entry!-listp */
    v398 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    if (!(v398 == nil)) goto v191;
    v398 = stack[-2];
    v399 = Llength(nil, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = (Lisp_Object)17; /* 1 */
    v398 = (Lisp_Object)greaterp2(v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v398 = v398 ? lisp_true : nil;
    env = stack[-8];
    if (v398 == nil) goto v55;
    v398 = stack[-2];
    stack[-4] = v398;
    v398 = stack[-4];
    if (v398 == nil) goto v196;
    v398 = stack[-4];
    v398 = qcar(v398);
    stack[0] = v398;
    v398 = elt(env, 5); /* g */
    v398 = Lgensym1(nil, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = cons(stack[0], v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    stack[-2] = v398;
    stack[-3] = v398;
    goto v188;

v188:
    v398 = stack[-4];
    v398 = qcdr(v398);
    stack[-4] = v398;
    v398 = stack[-4];
    if (v398 == nil) goto v19;
    stack[-1] = stack[-2];
    v398 = stack[-4];
    v398 = qcar(v398);
    stack[0] = v398;
    v398 = elt(env, 5); /* g */
    v398 = Lgensym1(nil, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = cons(stack[0], v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = Lrplacd(nil, stack[-1], v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = stack[-2];
    v398 = qcdr(v398);
    stack[-2] = v398;
    goto v188;

v19:
    v398 = stack[-3];
    goto v155;

v155:
    stack[0] = v398;
    v399 = stack[0];
    v398 = stack[-7];
    fn = elt(env, 10); /* subla!-q */
    v398 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    stack[-7] = v398;
    v398 = stack[0];
    stack[-3] = v398;
    v398 = stack[-3];
    if (v398 == nil) goto v400;
    v398 = stack[-3];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    stack[-1] = v398;
    stack[-2] = v398;
    goto v13;

v13:
    v398 = stack[-3];
    v398 = qcdr(v398);
    stack[-3] = v398;
    v398 = stack[-3];
    if (v398 == nil) goto v7;
    stack[0] = stack[-1];
    v398 = stack[-3];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = Lrplacd(nil, stack[0], v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = stack[-1];
    v398 = qcdr(v398);
    stack[-1] = v398;
    goto v13;

v7:
    v398 = stack[-2];
    goto v11;

v11:
    stack[-2] = v398;
    goto v55;

v55:
    v398 = stack[-6];
    stack[-1] = v398;
    goto v223;

v223:
    v398 = stack[-1];
    if (v398 == nil) goto v222;
    v398 = stack[-1];
    v398 = qcar(v398);
    stack[0] = v398;
    v398 = stack[0];
    fn = elt(env, 11); /* no!-side!-effectp */
    v398 = (*qfn1(fn))(qenv(fn), v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    if (!(v398 == nil)) goto v309;
    v398 = stack[-2];
    v399 = qcar(v398);
    v398 = stack[-7];
    fn = elt(env, 12); /* one!-entryp */
    v398 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    if (!(v398 == nil)) goto v309;
    stack[-3] = stack[-5];
    v398 = stack[-2];
    v399 = qcar(v398);
    v398 = stack[0];
    v398 = cons(v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = Lnconc(nil, stack[-3], v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    stack[-5] = v398;
    goto v218;

v218:
    v398 = stack[-2];
    v398 = qcdr(v398);
    stack[-2] = v398;
    v398 = stack[-1];
    v398 = qcdr(v398);
    stack[-1] = v398;
    goto v223;

v309:
    v398 = stack[-2];
    v399 = qcar(v398);
    v398 = stack[0];
    v398 = cons(v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v399 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = stack[-7];
    fn = elt(env, 10); /* subla!-q */
    v398 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    stack[-7] = v398;
    goto v218;

v222:
    v398 = stack[-5];
    if (v398 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    stack[-4] = elt(env, 6); /* lambda */
    v398 = stack[-5];
    stack[-3] = v398;
    v398 = stack[-3];
    if (v398 == nil) goto v330;
    v398 = stack[-3];
    v398 = qcar(v398);
    v398 = qcar(v398);
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    stack[-1] = v398;
    stack[-2] = v398;
    goto v93;

v93:
    v398 = stack[-3];
    v398 = qcdr(v398);
    stack[-3] = v398;
    v398 = stack[-3];
    if (v398 == nil) goto v300;
    stack[0] = stack[-1];
    v398 = stack[-3];
    v398 = qcar(v398);
    v398 = qcar(v398);
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = Lrplacd(nil, stack[0], v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = stack[-1];
    v398 = qcdr(v398);
    stack[-1] = v398;
    goto v93;

v300:
    v398 = stack[-2];
    v399 = v398;
    goto v364;

v364:
    v398 = stack[-7];
    stack[-3] = list3(stack[-4], v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = stack[-5];
    stack[-4] = v398;
    v398 = stack[-4];
    if (v398 == nil) goto v401;
    v398 = stack[-4];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    stack[-1] = v398;
    stack[-2] = v398;
    goto v87;

v87:
    v398 = stack[-4];
    v398 = qcdr(v398);
    stack[-4] = v398;
    v398 = stack[-4];
    if (v398 == nil) goto v79;
    stack[0] = stack[-1];
    v398 = stack[-4];
    v398 = qcar(v398);
    v398 = qcdr(v398);
    v398 = ncons(v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = Lrplacd(nil, stack[0], v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = stack[-1];
    v398 = qcdr(v398);
    stack[-1] = v398;
    goto v87;

v79:
    v398 = stack[-2];
    goto v402;

v402:
    {
        Lisp_Object v403 = stack[-3];
        popv(9);
        return cons(v403, v398);
    }

v401:
    v398 = qvalue(elt(env, 4)); /* nil */
    goto v402;

v330:
    v398 = qvalue(elt(env, 4)); /* nil */
    v399 = v398;
    goto v364;

v400:
    v398 = qvalue(elt(env, 4)); /* nil */
    goto v11;

v196:
    v398 = qvalue(elt(env, 4)); /* nil */
    goto v155;

v191:
    v399 = stack[-2];
    v398 = stack[-6];
    fn = elt(env, 13); /* pair */
    v399 = (*qfn2(fn))(qenv(fn), v399, v398);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-8];
    v398 = stack[-7];
    {
        popv(9);
        fn = elt(env, 10); /* subla!-q */
        return (*qfn2(fn))(qenv(fn), v399, v398);
    }
/* error exit handlers */
v135:
    popv(9);
    return nil;
}



/* Code for mk_dummy_ids */

static Lisp_Object CC_mk_dummy_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_dummy_ids");
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
    v132 = v0;
/* end of prologue */
    v45 = v132;
    v45 = qcar(v45);
    v132 = qcdr(v132);
    v132 = qcar(v132);
    fn = elt(env, 4); /* intersection */
    v132 = (*qfn2(fn))(qenv(fn), v45, v132);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    fn = elt(env, 5); /* clean_numid */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    stack[0] = v132;
    v45 = stack[0];
    v132 = elt(env, 1); /* dummy */
    v132 = Lflag(nil, v45, v132);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    v45 = stack[0];
    v132 = elt(env, 2); /* reserved */
    v132 = Lflag(nil, v45, v132);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    v45 = stack[0];
    v132 = qvalue(elt(env, 3)); /* dummy_id!* */
    fn = elt(env, 6); /* union */
    v132 = (*qfn2(fn))(qenv(fn), v45, v132);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-1];
    qvalue(elt(env, 3)) = v132; /* dummy_id!* */
    v132 = nil;
    { popv(2); return onevalue(v132); }
/* error exit handlers */
v125:
    popv(2);
    return nil;
}



/* Code for makeqn!-maybe */

static Lisp_Object MS_CDECL CC_makeqnKmaybe(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v66, v131;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeqn-maybe");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeqn-maybe");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v2;
    v66 = v1;
    v131 = v0;
/* end of prologue */
    if (!(v65 == nil)) return onevalue(v66);
    v65 = elt(env, 1); /* equal */
    return list3(v65, v131, v66);
}



/* Code for noncomfree */

static Lisp_Object CC_noncomfree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomfree");
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

v236:
    v54 = stack[0];
    if (symbolp(v54)) goto v9;
    v54 = stack[0];
    v54 = (consp(v54) ? nil : lisp_true);
    if (!(v54 == nil)) { popv(2); return onevalue(v54); }
    v54 = stack[0];
    v54 = qcar(v54);
    v54 = CC_noncomfree(env, v54);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    if (v54 == nil) goto v40;
    v54 = stack[0];
    v54 = qcdr(v54);
    stack[0] = v54;
    goto v236;

v40:
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v54); }

v9:
    v54 = stack[0];
    if (!symbolp(v54)) v54 = nil;
    else { v54 = qfastgets(v54);
           if (v54 != nil) { v54 = elt(v54, 0); /* noncom */
#ifdef RECORD_GET
             if (v54 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v54 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v54 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v54 == SPID_NOPROP) v54 = nil; else v54 = lisp_true; }}
#endif
    v54 = (v54 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v54); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for containerom */

static Lisp_Object CC_containerom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for containerom");
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
    v21 = stack[-2];
    v21 = qcdr(v21);
    v21 = qcar(v21);
    stack[-1] = v21;
    v21 = stack[-2];
    v21 = qcar(v21);
    stack[0] = v21;
    v21 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 15); /* printout */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v206 = stack[0];
    v21 = elt(env, 3); /* vectorml */
    if (!(v206 == v21)) goto v58;
    v21 = elt(env, 4); /* vector */
    stack[0] = v21;
    goto v58;

v58:
    v206 = stack[0];
    v21 = qvalue(elt(env, 5)); /* valid_om!* */
    v21 = Lassoc(nil, v206, v21);
    v21 = qcdr(v21);
    v21 = qcar(v21);
    stack[-3] = v21;
    v21 = stack[-2];
    v206 = qcar(v21);
    v21 = elt(env, 6); /* set */
    if (!(v206 == v21)) goto v126;
    v21 = stack[-1];
    v21 = Lconsp(nil, v21);
    env = stack[-4];
    if (v21 == nil) goto v126;
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v206 = Lintern(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = elt(env, 7); /* multiset */
    if (!(v206 == v21)) goto v126;
    v21 = elt(env, 8); /* multiset1 */
    stack[-3] = v21;
    goto v126;

v126:
    v21 = stack[-2];
    v206 = qcar(v21);
    v21 = elt(env, 3); /* vectorml */
    if (!(v206 == v21)) goto v166;
    v21 = elt(env, 10); /* "vector" */
    stack[0] = v21;
    goto v166;

v166:
    v21 = stack[-2];
    v206 = qcar(v21);
    v21 = elt(env, 3); /* vectorml */
    if (!(v206 == v21)) goto v160;
    v206 = elt(env, 4); /* vector */
    v21 = stack[-2];
    v21 = qcdr(v21);
    v21 = cons(v206, v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    stack[-2] = v21;
    goto v160;

v160:
    v21 = elt(env, 11); /* "<OMS cd=""" */
    fn = elt(env, 15); /* printout */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = stack[-3];
    v21 = Lprinc(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = elt(env, 12); /* """ name=""" */
    v21 = Lprinc(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = stack[0];
    v21 = Lprinc(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = elt(env, 13); /* """/>" */
    v21 = Lprinc(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = stack[-2];
    v21 = qcdr(v21);
    v21 = qcdr(v21);
    fn = elt(env, 17); /* multiom */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-4];
    v21 = elt(env, 14); /* "</OMA>" */
    fn = elt(env, 15); /* printout */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v117;
    v21 = nil;
    { popv(5); return onevalue(v21); }
/* error exit handlers */
v117:
    popv(5);
    return nil;
}



/* Code for ldf!-dep!-var */

static Lisp_Object CC_ldfKdepKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v383;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-dep-var");
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
    v232 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v232;
    goto v201;

v201:
    v232 = stack[-1];
    if (v232 == nil) goto v141;
    v232 = stack[-1];
    v232 = qcar(v232);
    stack[0] = v232;
    v232 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v383 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v232 = qvalue(elt(env, 2)); /* depl!* */
    v232 = Lassoc(nil, v383, v232);
    if (v232 == nil) goto v70;
    v232 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v383 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v232 = qvalue(elt(env, 2)); /* depl!* */
    v232 = Lassoc(nil, v383, v232);
    v383 = qcdr(v232);
    v232 = stack[-2];
    v232 = Lappend(nil, v383, v232);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = v232;
    goto v70;

v70:
    v232 = stack[-1];
    v232 = qcdr(v232);
    stack[-1] = v232;
    goto v201;

v141:
    v232 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* makeset */
        return (*qfn1(fn))(qenv(fn), v232);
    }
/* error exit handlers */
v151:
    popv(4);
    return nil;
}



/* Code for findhr */

static Lisp_Object MS_CDECL CC_findhr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v169, v126;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "findhr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findhr");
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
    stack[-1] = nil;
    goto v68;

v68:
    v169 = qvalue(elt(env, 1)); /* headhisto */
    v191 = (Lisp_Object)1; /* 0 */
    v191 = (Lisp_Object)greaterp2(v169, v191);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v191 = v191 ? lisp_true : nil;
    env = stack[-2];
    if (v191 == nil) goto v10;
    v169 = qvalue(elt(env, 2)); /* codhisto */
    v191 = qvalue(elt(env, 1)); /* headhisto */
    v191 = *(Lisp_Object *)((char *)v169 + (CELL-TAG_VECTOR) + ((int32_t)v191/(16/CELL)));
    stack[-1] = v191;
    if (!(v191 == nil)) goto v10;
    v191 = qvalue(elt(env, 1)); /* headhisto */
    v191 = sub1(v191);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    qvalue(elt(env, 1)) = v191; /* headhisto */
    goto v68;

v10:
    v191 = stack[-1];
    if (v191 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v191 = stack[-1];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    qvalue(elt(env, 4)) = v191; /* psi */
    v191 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 5)) = v191; /* npsi */
    stack[0] = qvalue(elt(env, 6)); /* codmat */
    v169 = qvalue(elt(env, 7)); /* maxvar */
    v191 = stack[-1];
    v191 = plus2(v169, v191);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v126 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v191/(16/CELL)));
    v169 = (Lisp_Object)1; /* 0 */
    v191 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v126 + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL))) = v191;
    v169 = stack[-1];
    v191 = qvalue(elt(env, 8)); /* rcoccup */
    v191 = cons(v169, v191);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    qvalue(elt(env, 8)) = v191; /* rcoccup */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v195:
    popv(3);
    return nil;
}



/* Code for suchp */

static Lisp_Object CC_suchp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for suchp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v0;
/* end of prologue */
    v40 = v70;
    if (!consp(v40)) goto v9;
    v40 = v70;
    v40 = qcar(v40);
    v70 = elt(env, 2); /* such!-that */
    v40 = (v40 == v70 ? lisp_true : nil);
    return onevalue(v40);

v9:
    v40 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v40);
}



/* Code for evequal */

static Lisp_Object CC_evequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v232, v383, v37, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evequal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v383 = v1;
    v37 = v0;
/* end of prologue */

v10:
    v56 = v37;
    if (!(v56 == nil)) goto v61;
    v56 = v383;
    if (!(v56 == nil)) goto v61;
    v56 = qvalue(elt(env, 1)); /* t */
    return onevalue(v56);

v61:
    v56 = v37;
    if (v56 == nil) goto v133;
    v56 = v383;
    if (v56 == nil) goto v40;
    v38 = (Lisp_Object)1; /* 0 */
    v56 = v37;
    v232 = qcar(v56);
    v56 = v383;
    v56 = qcar(v56);
    v56 = (Lisp_Object)(int32_t)((int32_t)v232 - (int32_t)v56 + TAG_FIXNUM);
    if (v38 == v56) goto v69;
    v56 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v56);

v69:
    v56 = v37;
    v56 = qcdr(v56);
    v37 = v56;
    v56 = v383;
    v56 = qcdr(v56);
    v383 = v56;
    goto v10;

v40:
    v56 = elt(env, 2); /* (0) */
    v383 = v56;
    goto v10;

v133:
    v56 = elt(env, 2); /* (0) */
    v37 = v56;
    goto v10;
}



/* Code for !:log10 */

static Lisp_Object CC_Tlog10(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :log10");
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
    v153 = elt(env, 0); /* !:log10 */
    v45 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v45 = (*qfn2(fn))(qenv(fn), v153, v45);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-2];
    stack[-1] = v45;
    v153 = stack[-1];
    v45 = elt(env, 1); /* not_found */
    if (!(v153 == v45)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v153 = qvalue(elt(env, 2)); /* bften!* */
    v45 = stack[0];
    fn = elt(env, 4); /* log!: */
    v45 = (*qfn2(fn))(qenv(fn), v153, v45);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-2];
    stack[-1] = v45;
    v153 = elt(env, 0); /* !:log10 */
    v45 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v45 = (*qfn2(fn))(qenv(fn), v153, v45);
    nil = C_nil;
    if (exception_pending()) goto v192;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v192:
    popv(3);
    return nil;
}



/* Code for getphystypeexpt */

static Lisp_Object CC_getphystypeexpt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypeexpt");
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
    v58 = stack[0];
    fn = elt(env, 3); /* getphystypecar */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v57 = v58;
    v58 = v57;
    if (v58 == nil) goto v61;
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    if (!(is_number(v58))) { popv(2); return onevalue(v57); }
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = qcar(v58);
    v58 = Levenp(nil, v58);
    env = stack[-1];
    if (v58 == nil) { popv(2); return onevalue(v57); }
    v58 = elt(env, 2); /* scalar */
    { popv(2); return onevalue(v58); }

v61:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v58); }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



setup_type const u33_setup[] =
{
    {"ofsf_qesubqat",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubqat},
    {"taymindegreel",           too_few_2,      CC_taymindegreel,wrong_no_2},
    {"my+nullsq+p",             CC_myLnullsqLp, too_many_1,    wrong_no_1},
    {"vectorml",                CC_vectorml,    too_many_1,    wrong_no_1},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"compl",                   too_few_2,      CC_compl,      wrong_no_2},
    {"make_spoly_pair",         too_few_2,      CC_make_spoly_pair,wrong_no_2},
    {"gbftimes",                too_few_2,      CC_gbftimes,   wrong_no_2},
    {"evaluate2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluate2},
    {"lispreadp",               CC_lispreadp,   too_many_1,    wrong_no_1},
    {"bas_make",                too_few_2,      CC_bas_make,   wrong_no_2},
    {"extract_vars",            CC_extract_vars,too_many_1,    wrong_no_1},
    {"lessppair",               too_few_2,      CC_lessppair,  wrong_no_2},
    {"sfto_updecf",             CC_sfto_updecf, too_many_1,    wrong_no_1},
    {"subtractinds",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_subtractinds},
    {"pasf_cein",               CC_pasf_cein,   too_many_1,    wrong_no_1},
    {"fnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnrd},
    {"prlist",                  CC_prlist,      too_many_1,    wrong_no_1},
    {"spcol_dim",               CC_spcol_dim,   too_many_1,    wrong_no_1},
    {"subfindices",             too_few_2,      CC_subfindices,wrong_no_2},
    {"find_buble",              too_few_2,      CC_find_buble, wrong_no_2},
    {"assoc2",                  too_few_2,      CC_assoc2,     wrong_no_2},
    {"cquotegex",               CC_cquotegex,   too_many_1,    wrong_no_1},
    {"klistt",                  CC_klistt,      too_many_1,    wrong_no_1},
    {"simpexpt2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt2},
    {"ratpoly_minus",           too_few_2,      CC_ratpoly_minus,wrong_no_2},
    {"bc_fd",                   CC_bc_fd,       too_many_1,    wrong_no_1},
    {"ithlistelem",             too_few_2,      CC_ithlistelem,wrong_no_2},
    {"genexp",                  CC_genexp,      too_many_1,    wrong_no_1},
    {"mkexdf",                  CC_mkexdf,      too_many_1,    wrong_no_1},
    {"simpsetdiff",             CC_simpsetdiff, too_many_1,    wrong_no_1},
    {"maprintla",               too_few_2,      CC_maprintla,  wrong_no_2},
    {"diff_vertex",             too_few_2,      CC_diff_vertex,wrong_no_2},
    {"applsmacro",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_applsmacro},
    {"mk_dummy_ids",            CC_mk_dummy_ids,too_many_1,    wrong_no_1},
    {"makeqn-maybe",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeqnKmaybe},
    {"noncomfree",              CC_noncomfree,  too_many_1,    wrong_no_1},
    {"containerom",             CC_containerom, too_many_1,    wrong_no_1},
    {"ldf-dep-var",             CC_ldfKdepKvar, too_many_1,    wrong_no_1},
    {"findhr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_findhr},
    {"suchp",                   CC_suchp,       too_many_1,    wrong_no_1},
    {"evequal",                 too_few_2,      CC_evequal,    wrong_no_2},
    {":log10",                  CC_Tlog10,      too_many_1,    wrong_no_1},
    {"getphystypeexpt",         CC_getphystypeexpt,too_many_1, wrong_no_1},
    {NULL, (one_args *)"u33", (two_args *)"20228 3425425 4896602", 0}
};

/* end of generated code */
