
/* $destdir\u15.c        Machine generated C code */

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


/* Code for intexprlisp */

static Lisp_Object CC_intexprlisp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intexprlisp");
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

v8:
    v6 = stack[-1];
    v6 = (v6 == nil ? lisp_true : nil);
    if (!(v6 == nil)) { popv(3); return onevalue(v6); }
    v6 = stack[-1];
    v7 = qcar(v6);
    v6 = stack[0];
    fn = elt(env, 2); /* intexprnp */
    v6 = (*qfn2(fn))(qenv(fn), v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (v6 == nil) goto v10;
    v6 = stack[-1];
    v7 = qcdr(v6);
    v6 = stack[0];
    stack[-1] = v7;
    stack[0] = v6;
    goto v8;

v10:
    v6 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v6); }
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for squared!+matrix!+p */

static Lisp_Object CC_squaredLmatrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for squared+matrix+p");
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
    v12 = stack[0];
    fn = elt(env, 2); /* matrix!+p */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    if (v12 == nil) goto v14;
    v12 = stack[0];
    fn = elt(env, 3); /* get!+row!+nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    v12 = stack[0];
    fn = elt(env, 4); /* get!+col!+nr */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    if (!(equal(stack[-1], v12))) goto v14;
    v12 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v12); }

v14:
    v12 = nil;
    { popv(3); return onevalue(v12); }
/* error exit handlers */
v13:
    popv(3);
    return nil;
}



/* Code for ibalp_simpterm */

static Lisp_Object CC_ibalp_simpterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpterm");
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

v8:
    v27 = stack[0];
    if (!consp(v27)) goto v29;
    v27 = stack[0];
    v27 = qcar(v27);
    stack[-1] = v27;
    v27 = stack[-1];
    fn = elt(env, 3); /* ibalp_boolfp */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    if (v27 == nil) goto v31;
    stack[-4] = stack[-1];
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[-3] = v27;
    v27 = stack[-3];
    if (v27 == nil) goto v9;
    v27 = stack[-3];
    v27 = qcar(v27);
    v27 = CC_ibalp_simpterm(env, v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    stack[-1] = v27;
    stack[-2] = v27;
    goto v4;

v4:
    v27 = stack[-3];
    v27 = qcdr(v27);
    stack[-3] = v27;
    v27 = stack[-3];
    if (v27 == nil) goto v32;
    stack[0] = stack[-1];
    v27 = stack[-3];
    v27 = qcar(v27);
    v27 = CC_ibalp_simpterm(env, v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    v27 = Lrplacd(nil, stack[0], v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    goto v4;

v32:
    v27 = stack[-2];
    goto v33;

v33:
    {
        Lisp_Object v34 = stack[-4];
        popv(6);
        return cons(v34, v27);
    }

v9:
    v27 = qvalue(elt(env, 1)); /* nil */
    goto v33;

v31:
    v27 = stack[0];
    fn = elt(env, 4); /* reval */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    stack[0] = v27;
    v28 = stack[0];
    v27 = stack[-1];
    if (!consp(v28)) goto v35;
    v28 = qcar(v28);
    if (!(v28 == v27)) goto v35;
    v28 = stack[-1];
    v27 = elt(env, 2); /* "Boolean function" */
    fn = elt(env, 5); /* typerr */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-5];
    goto v35;

v35:
    v27 = stack[0];
    stack[0] = v27;
    goto v8;

v29:
    v27 = stack[0];
    {
        popv(6);
        fn = elt(env, 6); /* ibalp_simpatom */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v30:
    popv(6);
    return nil;
}



/* Code for ratpoly_nullp */

static Lisp_Object CC_ratpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v0;
/* end of prologue */
    v37 = v11;
    v37 = qcar(v37);
    v37 = (v37 == nil ? lisp_true : nil);
    if (!(v37 == nil)) return onevalue(v37);
    v37 = qcar(v11);
    v11 = (Lisp_Object)1; /* 0 */
    v11 = (v37 == v11 ? lisp_true : nil);
    return onevalue(v11);
}



/* Code for vbcgcd */

static Lisp_Object CC_vbcgcd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcgcd");
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
    v52 = stack[-1];
    v51 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 2); /* vbcsize */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    if (v51 == nil) goto v54;
    v52 = stack[0];
    v51 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 2); /* vbcsize */
    v51 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    if (v51 == nil) goto v54;
    v51 = stack[-1];
    v52 = qcdr(v51);
    v51 = (Lisp_Object)17; /* 1 */
    if (!(v52 == v51)) goto v34;
    v51 = stack[0];
    v52 = qcdr(v51);
    v51 = (Lisp_Object)17; /* 1 */
    if (!(v52 == v51)) goto v34;
    v51 = stack[-1];
    v51 = qcar(v51);
    v51 = integerp(v51);
    if (v51 == nil) goto v55;
    v51 = stack[0];
    v51 = qcar(v51);
    v51 = integerp(v51);
    if (v51 == nil) goto v55;
    v51 = stack[-1];
    v52 = qcar(v51);
    v51 = stack[0];
    v51 = qcar(v51);
    v52 = Lgcd(nil, v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v51 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v52, v51);

v55:
    v51 = stack[-1];
    v52 = qcar(v51);
    v51 = stack[0];
    v51 = qcar(v51);
    fn = elt(env, 3); /* gcdf!* */
    v52 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v51 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v52, v51);

v34:
    v52 = (Lisp_Object)17; /* 1 */
    v51 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v52, v51);

v54:
    v51 = elt(env, 1); /* (1 . 1) */
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for vdpred */

static Lisp_Object CC_vdpred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpred");
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
    v41 = stack[-3];
    v41 = qcdr(v41);
    v41 = qcdr(v41);
    v41 = qcdr(v41);
    v41 = qcar(v41);
    v41 = qcdr(v41);
    v41 = qcdr(v41);
    stack[-4] = v41;
    v41 = stack[-4];
    if (v41 == nil) goto v2;
    stack[-2] = elt(env, 1); /* vdp */
    v41 = stack[-4];
    stack[-1] = qcar(v41);
    v41 = stack[-4];
    v41 = qcdr(v41);
    stack[0] = qcar(v41);
    v55 = stack[-4];
    v41 = qvalue(elt(env, 2)); /* nil */
    v41 = list2(v55, v41);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    v41 = list3star(stack[-2], stack[-1], stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    stack[-4] = v41;
    v41 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v41 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v55 = stack[-3];
    v41 = elt(env, 4); /* sugar */
    fn = elt(env, 5); /* vdpgetprop */
    v55 = (*qfn2(fn))(qenv(fn), v55, v41);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    v41 = v55;
    if (v55 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v55 = stack[-4];
    fn = elt(env, 6); /* gsetsugar */
    v41 = (*qfn2(fn))(qenv(fn), v55, v41);
    nil = C_nil;
    if (exception_pending()) goto v28;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v2:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v41 = qvalue(elt(env, 2)); /* nil */
    stack[0] = ncons(v41);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-5];
    v55 = qvalue(elt(env, 2)); /* nil */
    v41 = qvalue(elt(env, 2)); /* nil */
    v41 = list2(v55, v41);
    nil = C_nil;
    if (exception_pending()) goto v28;
    {
        Lisp_Object v66 = stack[-2];
        Lisp_Object v42 = stack[-1];
        Lisp_Object v40 = stack[0];
        popv(6);
        return list3star(v66, v42, v40, v41);
    }
/* error exit handlers */
v28:
    popv(6);
    return nil;
}



/* Code for termordp!! */

static Lisp_Object CC_termordpB(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v26, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp!");
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
    v25 = v0;
/* end of prologue */
    v26 = v25;
    v24 = stack[0];
    if (equal(v26, v24)) goto v14;
    v24 = v25;
    fn = elt(env, 2); /* guesspftype */
    stack[-1] = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    v24 = stack[0];
    fn = elt(env, 2); /* guesspftype */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-2];
    {
        Lisp_Object v6 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* termordp */
        return (*qfn2(fn))(qenv(fn), v6, v24);
    }

v14:
    v24 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v24); }
/* error exit handlers */
v4:
    popv(3);
    return nil;
}



/* Code for !*sqprint */

static Lisp_Object CC_Hsqprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sqprint");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v0;
/* end of prologue */
    v70 = qcdr(v70);
    v70 = qcar(v70);
    {
        fn = elt(env, 1); /* sqprint */
        return (*qfn1(fn))(qenv(fn), v70);
    }
}



/* Code for rd!:plus */

static Lisp_Object CC_rdTplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:plus");
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
    stack[0] = v0;
/* end of prologue */
    v92 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (!(v92 == nil)) goto v95;
    v92 = stack[0];
    v92 = qcdr(v92);
    if (!(!consp(v92))) goto v95;
    v92 = stack[-1];
    v92 = qcdr(v92);
    if (!(!consp(v92))) goto v95;
    v92 = stack[0];
    v93 = qcdr(v92);
    v92 = stack[-1];
    v92 = qcdr(v92);
    fn = elt(env, 7); /* safe!-fp!-plus */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v93 = v92;
    if (v92 == nil) goto v95;
    v92 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v92, v93);

v95:
    v93 = stack[0];
    v92 = stack[-1];
    fn = elt(env, 8); /* convprc2 */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    stack[-3] = v92;
    v92 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v92;
    v92 = stack[-3];
    if (!consp(v92)) goto v97;
    v93 = stack[-3];
    v92 = stack[-2];
    fn = elt(env, 9); /* plubf */
    v92 = (*qfn2(fn))(qenv(fn), v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v62;

v62:
    stack[0] = v92;
    v94 = stack[0];
    v93 = stack[-3];
    v92 = stack[-2];
    fn = elt(env, 10); /* rdzchk */
    v92 = (*qfnn(fn))(qenv(fn), 3, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v93 = v92;
    v92 = v93;
    if (!(!consp(v92))) { popv(5); return onevalue(v93); }
    v92 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v92, v93);

v97:
    stack[-1] = elt(env, 5); /* plus2 */
    v92 = stack[-3];
    stack[0] = Lmkquote(nil, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v92 = stack[-2];
    v92 = Lmkquote(nil, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v94 = list3(stack[-1], stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v93 = qvalue(elt(env, 1)); /* nil */
    v92 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 11); /* errorset */
    v92 = (*qfnn(fn))(qenv(fn), 3, v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v93 = v92;
    v92 = v93;
    if (!consp(v92)) goto v16;
    v92 = v93;
    v92 = qcdr(v92);
    if (!(v92 == nil)) goto v16;
    v92 = v93;
    v92 = qcar(v92);
    goto v62;

v16:
    fn = elt(env, 12); /* rndbfon */
    v92 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v92 = stack[-3];
    v92 = Lfloatp(nil, v92);
    env = stack[-4];
    if (v92 == nil) goto v98;
    v92 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    stack[0] = v92;
    goto v99;

v99:
    stack[-3] = stack[0];
    v92 = stack[-2];
    v92 = Lfloatp(nil, v92);
    env = stack[-4];
    if (v92 == nil) goto v100;
    v92 = stack[-2];
    fn = elt(env, 13); /* fl2bf */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v101;

v101:
    stack[-2] = v92;
    fn = elt(env, 9); /* plubf */
    v92 = (*qfn2(fn))(qenv(fn), stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v62;

v100:
    v92 = stack[-2];
    if (!consp(v92)) goto v102;
    v92 = stack[-2];
    goto v103;

v103:
    fn = elt(env, 14); /* csl_normbf */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v101;

v102:
    v92 = stack[-2];
    v92 = integerp(v92);
    if (v92 == nil) goto v104;
    v94 = elt(env, 3); /* !:rd!: */
    v93 = stack[-2];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = list2star(v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v103;

v104:
    v92 = stack[-2];
    fn = elt(env, 15); /* read!:num */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v103;

v98:
    v92 = stack[-3];
    if (!consp(v92)) goto v105;
    v92 = stack[-3];
    goto v106;

v106:
    fn = elt(env, 14); /* csl_normbf */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    stack[0] = v92;
    goto v99;

v105:
    v92 = stack[-3];
    v92 = integerp(v92);
    if (v92 == nil) goto v107;
    v94 = elt(env, 3); /* !:rd!: */
    v93 = stack[-3];
    v92 = (Lisp_Object)1; /* 0 */
    v92 = list2star(v94, v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v106;

v107:
    v92 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v106;
/* error exit handlers */
v96:
    popv(5);
    return nil;
}



/* Code for physopaeval */

static Lisp_Object CC_physopaeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopaeval");
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
    v111 = stack[0];
    fn = elt(env, 6); /* physopp */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-1];
    if (v111 == nil) goto v54;
    v112 = stack[0];
    v111 = elt(env, 1); /* rvalue */
    v111 = get(v112, v111);
    env = stack[-1];
    v113 = v111;
    if (v111 == nil) goto v36;
    v111 = v113;
    v112 = qcar(v111);
    v111 = elt(env, 2); /* !*sq */
    if (!(v112 == v111)) { popv(2); return onevalue(v113); }
    v111 = qvalue(elt(env, 3)); /* !*nosq */
    if (v111 == nil) goto v9;
    v111 = v113;
    v111 = qcdr(v111);
    v111 = qcar(v111);
    {
        popv(2);
        fn = elt(env, 7); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v111);
    }

v9:
    v111 = v113;
    v111 = qcdr(v111);
    v111 = qcar(v111);
    {
        popv(2);
        fn = elt(env, 8); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v111);
    }

v36:
    v111 = stack[0];
    if (!consp(v111)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = elt(env, 4); /* psimpfn */
    v111 = get(v112, v111);
    env = stack[-1];
    v113 = v111;
    if (v111 == nil) goto v115;
    v112 = v113;
    v111 = stack[0];
        popv(2);
        return Lapply1(nil, v112, v111);

v115:
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = elt(env, 5); /* opmtch */
    v111 = get(v112, v111);
    env = stack[-1];
    if (v111 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v111 = stack[0];
    fn = elt(env, 9); /* opmtch!* */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v113 = v111;
    if (v111 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v113); }

v54:
    v111 = stack[0];
    if (!consp(v111)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = elt(env, 2); /* !*sq */
    if (!(v112 == v111)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v111 = qvalue(elt(env, 3)); /* !*nosq */
    if (v111 == nil) goto v51;
    v111 = stack[0];
    v111 = qcdr(v111);
    v111 = qcar(v111);
    {
        popv(2);
        fn = elt(env, 7); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v111);
    }

v51:
    v111 = stack[0];
    v111 = qcdr(v111);
    v111 = qcar(v111);
    {
        popv(2);
        fn = elt(env, 8); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v111);
    }
/* error exit handlers */
v114:
    popv(2);
    return nil;
}



/* Code for assert_install */

static Lisp_Object CC_assert_install(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_install");
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
    v21 = v0;
/* end of prologue */
    v13 = qvalue(elt(env, 1)); /* !*assert */
    if (v13 == nil) goto v14;
    v13 = v21;
    stack[0] = v13;
    goto v10;

v10:
    v13 = stack[0];
    if (v13 == nil) goto v36;
    v13 = stack[0];
    v13 = qcar(v13);
    fn = elt(env, 3); /* assert_install1 */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    v13 = stack[0];
    v13 = qcdr(v13);
    stack[0] = v13;
    goto v10;

v36:
    v13 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v13); }

v14:
    v13 = nil;
    { popv(2); return onevalue(v13); }
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for pv_intequiv */

static Lisp_Object CC_pv_intequiv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_intequiv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v36 = v0;
/* end of prologue */
    v69 = v36;
    v69 = qcdr(v69);
    if (!consp(v69)) goto v77;
    v69 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v69);

v77:
    v69 = v36;
    v69 = qcdr(v69);
    return onevalue(v69);
}



/* Code for splitlist!: */

static Lisp_Object CC_splitlistT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50, v116;
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
    v116 = nil;
    goto v70;

v70:
    v49 = stack[-1];
    if (v49 == nil) goto v117;
    v49 = stack[-1];
    v50 = qcar(v49);
    v49 = stack[0];
    if (!consp(v50)) goto v118;
    v50 = qcar(v50);
    if (!(v50 == v49)) goto v118;
    v49 = stack[-1];
    v49 = qcar(v49);
    v50 = v116;
    v49 = cons(v49, v50);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-2];
    v116 = v49;
    v49 = stack[-1];
    v49 = qcdr(v49);
    stack[-1] = v49;
    goto v70;

v118:
    v49 = stack[-1];
    v49 = qcdr(v49);
    stack[-1] = v49;
    goto v70;

v117:
    v49 = v116;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v49);
    }
/* error exit handlers */
v119:
    popv(3);
    return nil;
}



/* Code for wtchk */

static Lisp_Object CC_wtchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wtchk");
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
    v55 = stack[-1];
    if (v55 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v55 = stack[-2];
    stack[-3] = ncons(v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    stack[0] = elt(env, 1); /* k!* */
    v15 = stack[-1];
    v55 = stack[-2];
    v55 = qcar(v55);
    v55 = qcdr(v55);
    v15 = times2(v15, v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v55 = (Lisp_Object)17; /* 1 */
    v55 = acons(stack[0], v15, v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v55 = ncons(v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    fn = elt(env, 10); /* quotf */
    v55 = (*qfn2(fn))(qenv(fn), stack[-3], v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v15 = v55;
    v55 = v15;
    if (v55 == nil) goto v95;
    v55 = v15;
    v55 = qcar(v55);
    { popv(5); return onevalue(v55); }

v95:
    v55 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 11); /* terpri!* */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v55 = elt(env, 3); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 12); /* lprie */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v16 = elt(env, 4); /* "weight confusion" */
    v15 = stack[-2];
    v55 = stack[-1];
    v55 = list3(v16, v15, v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    fn = elt(env, 13); /* printty */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v15 = elt(env, 5); /* " " */
    v55 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 14); /* lpriw */
    v55 = (*qfn2(fn))(qenv(fn), v15, v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v55 = elt(env, 7); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v15 = v55;
    v55 = v15;
    qvalue(elt(env, 8)) = v55; /* errmsg!* */
    v55 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v55 == nil)) goto v46;
    v55 = v15;
    fn = elt(env, 12); /* lprie */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    goto v46;

v46:
    v55 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v55 = nil;
    { popv(5); return onevalue(v55); }
/* error exit handlers */
v66:
    popv(5);
    return nil;
}



/* Code for exptcompare */

static Lisp_Object CC_exptcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptcompare");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v50 = v1;
    v116 = v0;
/* end of prologue */
    v49 = v116;
    if (!consp(v49)) goto v14;
    v49 = v50;
    if (!consp(v49)) goto v33;
    v49 = v116;
    v49 = qcar(v49);
    v50 = qcar(v50);
        return Lgreaterp(nil, v49, v50);

v33:
    v49 = qvalue(elt(env, 2)); /* t */
    return onevalue(v49);

v14:
    v49 = v50;
    if (!consp(v49)) goto v36;
    v49 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v49);

v36:
    v49 = v116;
        return Lgreaterp(nil, v49, v50);
}



/* Code for qqe_number!-of!-adds!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKaddsKinKqterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_number-of-adds-in-qterm");
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

v77:
    v20 = stack[0];
    if (!consp(v20)) goto v29;
    v20 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v5 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v20 = elt(env, 1); /* (ladd radd) */
    v20 = Lmemq(nil, v5, v20);
    if (v20 == nil) goto v21;
    v20 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v20 = CC_qqe_numberKofKaddsKinKqterm(env, v20);
    nil = C_nil;
    if (exception_pending()) goto v6;
    popv(2);
    return add1(v20);

v21:
    v20 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    stack[0] = v20;
    goto v77;

v29:
    v20 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v20); }
/* error exit handlers */
v6:
    popv(2);
    return nil;
}



/* Code for sq2sspl */

static Lisp_Object CC_sq2sspl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sspl");
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
    goto v29;

v29:
    v60 = stack[-1];
    if (!consp(v60)) goto v54;
    v60 = stack[-1];
    v60 = qcar(v60);
    if (!consp(v60)) goto v54;
    v60 = stack[-1];
    v61 = qcar(v60);
    v60 = stack[0];
    fn = elt(env, 1); /* sq2sstm */
    v61 = (*qfn2(fn))(qenv(fn), v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v60 = stack[-2];
    v60 = cons(v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    stack[-2] = v60;
    v60 = stack[-1];
    v60 = qcdr(v60);
    stack[-1] = v60;
    goto v29;

v54:
    v60 = stack[-1];
    v61 = v60;
    goto v117;

v117:
    v60 = stack[-2];
    if (v60 == nil) { popv(4); return onevalue(v61); }
    v60 = stack[-2];
    v60 = qcar(v60);
    v60 = Lappend(nil, v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v61 = v60;
    v60 = stack[-2];
    v60 = qcdr(v60);
    stack[-2] = v60;
    goto v117;
/* error exit handlers */
v122:
    popv(4);
    return nil;
}



/* Code for ibalp_clauselp */

static Lisp_Object CC_ibalp_clauselp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clauselp");
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

v8:
    v3 = stack[0];
    v3 = (v3 == nil ? lisp_true : nil);
    if (!(v3 == nil)) { popv(2); return onevalue(v3); }
    v3 = stack[0];
    v3 = qcar(v3);
    fn = elt(env, 2); /* ibalp_clausep */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    if (v3 == nil) goto v117;
    v3 = stack[0];
    v3 = qcdr(v3);
    stack[0] = v3;
    goto v8;

v117:
    v3 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v3); }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for aex_lc */

static Lisp_Object CC_aex_lc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v118, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_lc");
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
    v91 = v1;
    stack[0] = v0;
/* end of prologue */
    v118 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v91 = (*qfn2(fn))(qenv(fn), v118, v91);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    if (v91 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v91 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_lc */
    stack[-1] = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    v91 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v9 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-2];
    v118 = qvalue(elt(env, 1)); /* nil */
    v91 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v50 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v50, v9, v118, v91);
    }
/* error exit handlers */
v49:
    popv(3);
    return nil;
}



/* Code for nary */

static Lisp_Object CC_nary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nary");
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
    v22 = stack[-1];
    v23 = qcar(v22);
    v22 = elt(env, 1); /* e */
    if (!(v23 == v22)) goto v91;
    v23 = stack[0];
    v22 = elt(env, 2); /* power */
    if (!(v23 == v22)) goto v91;
    v22 = stack[-1];
    v23 = qcdr(v22);
    v22 = elt(env, 3); /* exp */
    fn = elt(env, 10); /* unary */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    goto v70;

v70:
    v22 = nil;
    { popv(3); return onevalue(v22); }

v91:
    v22 = elt(env, 4); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v22 = elt(env, 5); /* "<" */
    v22 = Lprinc(nil, v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v22 = stack[0];
    v22 = Lprinc(nil, v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v22 = stack[-1];
    v23 = qcar(v22);
    v22 = elt(env, 6); /* "/" */
    fn = elt(env, 12); /* attributesml */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v22 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* indent!* */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v22 = stack[-1];
    v22 = qcdr(v22);
    fn = elt(env, 14); /* multi_elem */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v22 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-2];
    v22 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v124;
    goto v70;
/* error exit handlers */
v124:
    popv(3);
    return nil;
}



/* Code for ldt!-tvar */

static Lisp_Object CC_ldtKtvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v13, v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v0;
/* end of prologue */
    v33 = qcar(v33);
    v33 = qcar(v33);
    v13 = v33;
    v33 = v13;
    v21 = elt(env, 1); /* df */
    if (!consp(v33)) return onevalue(v13);
    v33 = qcar(v33);
    if (!(v33 == v21)) return onevalue(v13);
    v33 = v13;
    v33 = qcdr(v33);
    v33 = qcar(v33);
    return onevalue(v33);
}



/* Code for spquotematrix */

static Lisp_Object CC_spquotematrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v58;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spquotematrix");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v58 = v0;
/* end of prologue */
    v58 = elt(env, 1); /* sparse */
    return onevalue(v58);
}



/* Code for dm!-minus */

static Lisp_Object CC_dmKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-minus");
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
    v14 = v0;
/* end of prologue */
    fn = elt(env, 1); /* !:minus */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v70:
    popv(1);
    return nil;
}



/* Code for chk */

static Lisp_Object CC_chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v89, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chk");
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

v8:
    v35 = stack[0];
    v35 = (v35 == nil ? lisp_true : nil);
    if (!(v35 == nil)) { popv(3); return onevalue(v35); }
    v89 = stack[0];
    v35 = qvalue(elt(env, 1)); /* t */
    v35 = (v89 == v35 ? lisp_true : nil);
    if (!(v35 == nil)) { popv(3); return onevalue(v35); }
    v35 = stack[0];
    v35 = qcar(v35);
    fn = elt(env, 3); /* bsubs */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    stack[-1] = v35;
    v35 = stack[-1];
    fn = elt(env, 4); /* freexp */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    if (v35 == nil) goto v127;
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = CC_chk(env, v35);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v89 = v35;
    v35 = v89;
    if (v35 == nil) goto v4;
    v35 = v89;
    v97 = qvalue(elt(env, 1)); /* t */
    if (v35 == v97) goto v118;
    v35 = stack[-1];
    popv(3);
    return cons(v35, v89);

v118:
    v35 = stack[-1];
    popv(3);
    return ncons(v35);

v4:
    v35 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v35); }

v127:
    v35 = stack[-1];
    fn = elt(env, 5); /* reval */
    v89 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-2];
    v35 = qvalue(elt(env, 1)); /* t */
    if (v89 == v35) goto v128;
    v35 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v35); }

v128:
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v8;
/* error exit handlers */
v46:
    popv(3);
    return nil;
}



/* Code for vdpzero */

static Lisp_Object MS_CDECL CC_vdpzero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpzero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpzero");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v58 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* a2vdp */
        return (*qfn1(fn))(qenv(fn), v58);
    }
}



/* Code for vdpputprop */

static Lisp_Object MS_CDECL CC_vdpputprop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v34, v130, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdpputprop");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpputprop");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v30 = stack[-3];
    v30 = Lconsp(nil, v30);
    env = stack[-5];
    if (v30 == nil) goto v4;
    v30 = stack[-3];
    v30 = qcdr(v30);
    stack[-4] = v30;
    v30 = Lconsp(nil, v30);
    env = stack[-5];
    if (v30 == nil) goto v4;
    v30 = stack[-4];
    v30 = qcdr(v30);
    stack[-4] = v30;
    v30 = Lconsp(nil, v30);
    env = stack[-5];
    if (v30 == nil) goto v4;
    v30 = stack[-4];
    v30 = qcdr(v30);
    stack[-4] = v30;
    v30 = Lconsp(nil, v30);
    env = stack[-5];
    if (v30 == nil) goto v4;
    v30 = stack[-4];
    v30 = qcdr(v30);
    stack[-4] = v30;
    v30 = Lconsp(nil, v30);
    env = stack[-5];
    if (!(v30 == nil)) goto v128;

v4:
    v131 = elt(env, 1); /* "vdpputprop given a non-vdp as 1st parameter" 
*/
    v130 = stack[-3];
    v34 = stack[-2];
    v30 = stack[-1];
    v30 = list4(v131, v130, v34, v30);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    v34 = v30;
    v30 = v34;
    qvalue(elt(env, 2)) = v30; /* errmsg!* */
    v30 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v30 == nil)) goto v48;
    v30 = v34;
    fn = elt(env, 4); /* lprie */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    goto v48;

v48:
    v30 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    goto v128;

v128:
    v34 = stack[-2];
    v30 = stack[-4];
    v30 = qcar(v30);
    v30 = Lassoc(nil, v34, v30);
    v34 = v30;
    v30 = v34;
    if (v30 == nil) goto v19;
    v30 = stack[-1];
    v30 = Lrplacd(nil, v34, v30);
    nil = C_nil;
    if (exception_pending()) goto v51;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v19:
    stack[0] = stack[-4];
    v130 = stack[-2];
    v34 = stack[-1];
    v30 = stack[-4];
    v30 = qcar(v30);
    v30 = acons(v130, v34, v30);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-5];
    v30 = Lrplaca(nil, stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v51;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
/* error exit handlers */
v51:
    popv(6);
    return nil;
}



/* Code for repasc */

static Lisp_Object MS_CDECL CC_repasc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v88, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "repasc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repasc");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v41 = nil;
    goto v29;

v29:
    v57 = stack[0];
    if (v57 == nil) goto v36;
    v88 = stack[-2];
    v57 = stack[0];
    v57 = qcar(v57);
    v57 = qcar(v57);
    if (equal(v88, v57)) goto v60;
    v57 = stack[0];
    v57 = qcar(v57);
    v88 = v41;
    v57 = cons(v57, v88);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v41 = v57;
    v57 = stack[0];
    v57 = qcdr(v57);
    stack[0] = v57;
    goto v29;

v60:
    stack[-3] = v41;
    v41 = stack[-2];
    v88 = stack[-1];
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = acons(v41, v88, v57);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    {
        Lisp_Object v27 = stack[-3];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v27, v57);
    }

v36:
    stack[0] = v41;
    v41 = elt(env, 1); /* "key" */
    v88 = stack[-2];
    v57 = elt(env, 2); /* "not found" */
    v57 = list3(v41, v88, v57);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v88 = v57;
    v57 = v88;
    qvalue(elt(env, 3)) = v57; /* errmsg!* */
    v57 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v57 == nil)) goto v118;
    v57 = v88;
    fn = elt(env, 6); /* lprie */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    goto v118;

v118:
    v57 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v57 = nil;
    {
        Lisp_Object v28 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v28, v57);
    }
/* error exit handlers */
v134:
    popv(5);
    return nil;
}



/* Code for putd */

static Lisp_Object MS_CDECL CC_putd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v83, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "putd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for putd");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v17;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v83 = stack[0];
    v148 = elt(env, 1); /* funarg */
    if (!consp(v83)) goto v14;
    v83 = qcar(v83);
    if (!(v83 == v148)) goto v14;
    v83 = elt(env, 2); /* lambda */
    v148 = stack[0];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = cons(v83, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    stack[0] = v148;
    goto v14;

v14:
    v148 = stack[-2];
    if (!symbolp(v148)) v148 = nil;
    else { v148 = qfastgets(v148);
           if (v148 != nil) { v148 = elt(v148, 1); /* lose */
#ifdef RECORD_GET
             if (v148 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v148 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v148 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v148 == SPID_NOPROP) v148 = nil; else v148 = lisp_true; }}
#endif
    if (v148 == nil) goto v49;
    v148 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v148 = elt(env, 3); /* "+++ " */
    v148 = Lprinc(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v148 = stack[-2];
    v148 = Lprin(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v148 = elt(env, 4); /* " not defined (LOSE flag)" */
    v148 = Lprintc(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v148 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v148); }

v49:
    v148 = qvalue(elt(env, 6)); /* !*redefmsg */
    if (v148 == nil) goto v23;
    v148 = stack[-2];
    fn = elt(env, 15); /* getd */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    if (v148 == nil) goto v23;
    v148 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v148 = elt(env, 3); /* "+++ " */
    v148 = Lprinc(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v148 = stack[-2];
    v148 = Lprin(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    v148 = elt(env, 7); /* " redefined" */
    v148 = Lprintc(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    goto v23;

v23:
    v83 = stack[-1];
    v148 = elt(env, 8); /* expr */
    if (v83 == v148) goto v120;
    v83 = stack[-1];
    v148 = elt(env, 9); /* subr */
    if (v83 == v148) goto v88;
    v83 = stack[-1];
    v148 = elt(env, 10); /* macro */
    if (!(v83 == v148)) goto v150;
    v83 = stack[0];
    v148 = elt(env, 2); /* lambda */
    if (!consp(v83)) goto v150;
    v83 = qcar(v83);
    if (!(v83 == v148)) goto v150;
    v81 = elt(env, 11); /* dm */
    v83 = stack[-2];
    v148 = stack[0];
    v148 = qcdr(v148);
    v148 = list2star(v81, v83, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v150:
    v83 = stack[-1];
    v148 = elt(env, 12); /* fexpr */
    if (!(v83 == v148)) goto v151;
    v83 = stack[0];
    v148 = elt(env, 2); /* lambda */
    if (!consp(v83)) goto v151;
    v83 = qcar(v83);
    if (!(v83 == v148)) goto v151;
    v81 = elt(env, 13); /* df */
    v83 = stack[-2];
    v148 = stack[0];
    v148 = qcdr(v148);
    v148 = list2star(v81, v83, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v151:
    v83 = elt(env, 14); /* "Bad type ~S in putd" */
    v148 = stack[-1];
    fn = elt(env, 17); /* error */
    v148 = (*qfn2(fn))(qenv(fn), v83, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v88:
    v83 = stack[-2];
    v148 = stack[0];
    v148 = Lsymbol_set_definition(nil, v83, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v120:
    v83 = stack[-2];
    v148 = stack[0];
    v148 = Lsymbol_set_definition(nil, v83, v148);
    nil = C_nil;
    if (exception_pending()) goto v149;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v149:
    popv(4);
    return nil;
}



/* Code for evalequal */

static Lisp_Object CC_evalequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalequal");
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
    v152 = stack[-2];
    fn = elt(env, 3); /* getrtype */
    stack[0] = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    stack[-3] = stack[0];
    v152 = stack[-1];
    fn = elt(env, 3); /* getrtype */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    if (equal(stack[0], v152)) goto v117;
    v152 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v152); }

v117:
    v152 = stack[-3];
    if (v152 == nil) goto v25;
    v60 = stack[-2];
    v152 = stack[-1];
    v152 = (equal(v60, v152) ? lisp_true : nil);
    { popv(5); return onevalue(v152); }

v25:
    v61 = elt(env, 2); /* difference */
    v60 = stack[-2];
    v152 = stack[-1];
    v152 = list3(v61, v60, v152);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    fn = elt(env, 4); /* reval */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    stack[-3] = v152;
    if (is_number(v152)) goto v49;
    v152 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v152); }

v49:
    v152 = stack[-3];
        popv(5);
        return Lzerop(nil, v152);
/* error exit handlers */
v22:
    popv(5);
    return nil;
}



/* Code for sf2mv1 */

static Lisp_Object MS_CDECL CC_sf2mv1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v38, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sf2mv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2mv1");
#endif
    if (stack >= stacklimit)
    {
        push3(v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v70:
    v39 = stack[-3];
    if (v39 == nil) goto v117;
    v39 = stack[-3];
    if (!consp(v39)) goto v26;
    v39 = stack[-3];
    v39 = qcar(v39);
    if (!consp(v39)) goto v26;
    v39 = stack[-3];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v38 = qcar(v39);
    v39 = stack[-1];
    v39 = qcar(v39);
    if (equal(v38, v39)) goto v155;
    stack[0] = stack[-2];
    v39 = (Lisp_Object)1; /* 0 */
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v39 = Lappend(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    stack[-2] = v39;
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[-1] = v39;
    goto v70;

v155:
    v39 = stack[-3];
    v39 = qcar(v39);
    stack[-4] = qcdr(v39);
    stack[0] = stack[-2];
    v39 = stack[-3];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v39 = qcdr(v39);
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v38 = Lappend(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[0] = CC_sf2mv1(env, 3, stack[-4], v38, v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v39 = stack[-3];
    v154 = qcdr(v39);
    v38 = stack[-2];
    v39 = stack[-1];
    v39 = CC_sf2mv1(env, 3, v154, v38, v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    {
        Lisp_Object v84 = stack[0];
        popv(6);
        return Lappend(nil, v84, v39);
    }

v26:
    stack[0] = stack[-2];
    v39 = stack[-1];
    v39 = Llength(nil, v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    fn = elt(env, 2); /* nzeros */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v38 = Lappend(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-5];
    v39 = stack[-3];
    v39 = cons(v38, v39);
    nil = C_nil;
    if (exception_pending()) goto v156;
    popv(6);
    return ncons(v39);

v117:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v39); }
/* error exit handlers */
v156:
    popv(6);
    return nil;
}



/* Code for bc_inv */

static Lisp_Object CC_bc_inv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v90, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_inv");
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
    v47 = v0;
/* end of prologue */
    v90 = v47;
    v157 = (Lisp_Object)17; /* 1 */
    if (v90 == v157) { popv(1); return onevalue(v47); }
    v90 = v47;
    v157 = (Lisp_Object)-15; /* -1 */
    if (v90 == v157) { popv(1); return onevalue(v47); }
    v157 = (Lisp_Object)17; /* 1 */
    v90 = v47;
    fn = elt(env, 2); /* qremf */
    v157 = (*qfn2(fn))(qenv(fn), v157, v90);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[0];
    v90 = v157;
    v157 = v90;
    v157 = qcdr(v157);
    if (v157 == nil) goto v95;
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v157); }

v95:
    v157 = v90;
    v157 = qcar(v157);
    { popv(1); return onevalue(v157); }
/* error exit handlers */
v48:
    popv(1);
    return nil;
}



/* Code for gperm0 */

static Lisp_Object CC_gperm0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm0");
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
    v67 = v0;
/* end of prologue */
    v12 = v67;
    if (v12 == nil) goto v77;
    v12 = v67;
    stack[0] = qcdr(v12);
    v12 = v67;
    v12 = qcar(v12);
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    {
        Lisp_Object v21 = stack[0];
        popv(2);
        fn = elt(env, 2); /* gperm3 */
        return (*qfn2(fn))(qenv(fn), v21, v12);
    }

v77:
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v12); }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_cambhead");
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

v8:
    v95 = stack[0];
    fn = elt(env, 4); /* listp */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    if (v95 == nil) goto v14;
    v95 = stack[0];
    stack[-1] = qcar(v95);
    v126 = elt(env, 1); /* expt */
    v95 = elt(env, 2); /* minus */
    v95 = list2(v126, v95);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-2];
    v95 = Lmember(nil, stack[-1], v95);
    if (v95 == nil) goto v158;
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = qcar(v95);
    stack[0] = v95;
    goto v8;

v158:
    v95 = stack[0];
    fn = elt(env, 4); /* listp */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v157;
    if (v95 == nil) goto v14;
    v95 = stack[0];
    v95 = qcar(v95);
    { popv(3); return onevalue(v95); }

v14:
    v95 = nil;
    { popv(3); return onevalue(v95); }
/* error exit handlers */
v157:
    popv(3);
    return nil;
}



/* Code for expt!-mod!-p */

static Lisp_Object CC_exptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v46, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-mod-p");
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
    v43 = v1;
    stack[0] = v0;
/* end of prologue */
    v46 = v43;
    v59 = (Lisp_Object)1; /* 0 */
    if (v46 == v59) goto v14;
    v46 = v43;
    v59 = (Lisp_Object)17; /* 1 */
    if (v46 == v59) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v46 = v43;
    v59 = (Lisp_Object)33; /* 2 */
    v59 = Ldivide(nil, v46, v59);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    stack[-1] = v59;
    v46 = stack[0];
    v59 = stack[-1];
    v59 = qcar(v59);
    v59 = CC_exptKmodKp(env, v46, v59);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v43 = v59;
    v59 = v43;
    v46 = v43;
    fn = elt(env, 1); /* times!-mod!-p */
    v59 = (*qfn2(fn))(qenv(fn), v59, v46);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v43 = v59;
    v59 = stack[-1];
    v46 = qcdr(v59);
    v59 = (Lisp_Object)1; /* 0 */
    if (v46 == v59) { popv(3); return onevalue(v43); }
    v46 = v43;
    v59 = stack[0];
    fn = elt(env, 1); /* times!-mod!-p */
    v59 = (*qfn2(fn))(qenv(fn), v46, v59);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v43 = v59;
    { popv(3); return onevalue(v43); }

v14:
    v59 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v59); }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for qqe_simplat1 */

static Lisp_Object CC_qqe_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v152, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplat1");
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
    v133 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-2];
    v60 = v133;
    v152 = v60;
    v133 = elt(env, 1); /* (qequal qneq) */
    v133 = Lmemq(nil, v152, v133);
    if (v133 == nil) goto v2;
    v152 = v60;
    v133 = elt(env, 2); /* qequal */
    if (v152 == v133) goto v118;
    v152 = stack[-1];
    v133 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_simplqneq */
        return (*qfn2(fn))(qenv(fn), v152, v133);
    }

v118:
    v152 = stack[-1];
    v133 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* qqe_simplqequal */
        return (*qfn2(fn))(qenv(fn), v152, v133);
    }

v2:
    v152 = stack[-1];
    v133 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* qqe_simplbtat */
        return (*qfn2(fn))(qenv(fn), v152, v133);
    }
/* error exit handlers */
v155:
    popv(3);
    return nil;
}



/* Code for sf2ss */

static Lisp_Object CC_sf2ss(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf2ss");
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
    v157 = stack[-1];
    if (!consp(v157)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v157 = stack[-1];
    v157 = qcar(v157);
    if (!consp(v157)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v157 = stack[-1];
    fn = elt(env, 1); /* searchpl */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    stack[-2] = v157;
    v157 = stack[-2];
    fn = elt(env, 2); /* qsort */
    stack[0] = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v157 = stack[-2];
    v157 = Llength(nil, v157);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v157 = cons(stack[0], v157);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    stack[0] = v157;
    v90 = stack[-1];
    fn = elt(env, 3); /* sq2sspl */
    v90 = (*qfn2(fn))(qenv(fn), v90, v157);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v157 = (Lisp_Object)17; /* 1 */
    v157 = list2star(stack[0], v90, v157);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* lx2xx */
        return (*qfn1(fn))(qenv(fn), v157);
    }
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for ratpoly_1 */

static Lisp_Object MS_CDECL CC_ratpoly_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_1");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v58 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v58);
    }
}



/* Code for variableom */

static Lisp_Object CC_variableom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variableom");
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
    v60 = stack[0];
    v61 = Lintern(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = qvalue(elt(env, 1)); /* constantsom!* */
    v60 = Lassoc(nil, v61, v60);
    stack[-1] = v60;
    v60 = stack[-1];
    if (v60 == nil) goto v65;
    v60 = elt(env, 2); /* "<OMS " */
    fn = elt(env, 9); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = elt(env, 3); /* "cd=""" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = stack[-1];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = elt(env, 4); /* """ " */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = elt(env, 5); /* "name=""" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = stack[-1];
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = elt(env, 6); /* """/>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    goto v31;

v31:
    v60 = nil;
    { popv(3); return onevalue(v60); }

v65:
    v60 = stack[0];
    if (v60 == nil) goto v31;
    v60 = elt(env, 8); /* "<OMV " */
    fn = elt(env, 9); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = elt(env, 5); /* "name=""" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = stack[0];
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-2];
    v60 = elt(env, 6); /* """/>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v127;
    goto v31;
/* error exit handlers */
v127:
    popv(3);
    return nil;
}



/* Code for delhisto */

static Lisp_Object CC_delhisto(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v178, v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delhisto");
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
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v178 = qvalue(elt(env, 2)); /* maxvar */
    v177 = stack[-2];
    v177 = plus2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v178 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = (Lisp_Object)1; /* 0 */
    v177 = *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    if (v177 == nil) goto v14;
    v178 = stack[-2];
    v177 = (Lisp_Object)1; /* 0 */
    v177 = (Lisp_Object)geq2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    v177 = v177 ? lisp_true : nil;
    env = stack[-4];
    if (v177 == nil) goto v14;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v178 = qvalue(elt(env, 2)); /* maxvar */
    v177 = stack[-2];
    v177 = plus2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v178 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = (Lisp_Object)113; /* 7 */
    v177 = *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = qcar(v177);
    stack[-3] = v177;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v178 = qvalue(elt(env, 2)); /* maxvar */
    v177 = stack[-2];
    v177 = plus2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v178 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = (Lisp_Object)113; /* 7 */
    v177 = *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = qcdr(v177);
    stack[-1] = v177;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v178 = qvalue(elt(env, 2)); /* maxvar */
    v177 = stack[-2];
    v177 = plus2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v178 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = (Lisp_Object)17; /* 1 */
    v177 = *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v178 = qcdr(v177);
    v177 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 4); /* min */
    v177 = (*qfn2(fn))(qenv(fn), v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v178 = stack[-3];
    if (v178 == nil) goto v102;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v178 = qvalue(elt(env, 2)); /* maxvar */
    v177 = stack[-3];
    v177 = plus2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v178 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = (Lisp_Object)113; /* 7 */
    v178 = *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = stack[-1];
    v177 = Lrplacd(nil, v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    goto v181;

v181:
    v177 = stack[-1];
    if (v177 == nil) goto v135;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v178 = qvalue(elt(env, 2)); /* maxvar */
    v177 = stack[-1];
    v177 = plus2(v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-4];
    v178 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = (Lisp_Object)113; /* 7 */
    v178 = *(Lisp_Object *)((char *)v178 + (CELL-TAG_VECTOR) + ((int32_t)v177/(16/CELL)));
    v177 = stack[-3];
    v177 = Lrplaca(nil, v178, v177);
    nil = C_nil;
    if (exception_pending()) goto v180;
    goto v135;

v135:
    v177 = nil;
    { popv(5); return onevalue(v177); }

v102:
    v179 = qvalue(elt(env, 3)); /* codhisto */
    v178 = v177;
    v177 = stack[-1];
    *(Lisp_Object *)((char *)v179 + (CELL-TAG_VECTOR) + ((int32_t)v178/(16/CELL))) = v177;
    goto v181;

v14:
    v177 = nil;
    { popv(5); return onevalue(v177); }
/* error exit handlers */
v180:
    popv(5);
    return nil;
}



/* Code for newenv */

static Lisp_Object CC_newenv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newenv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v158 = v10;
    v10 = elt(env, 1); /* unbound */
    {
        fn = elt(env, 2); /* bind */
        return (*qfn2(fn))(qenv(fn), v158, v10);
    }
}



/* Code for setmat */

static Lisp_Object MS_CDECL CC_setmat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, Lisp_Object v58, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v89, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmat");
#endif
    if (stack >= stacklimit)
    {
        push4(v58,v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v17,v58);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v58;
    stack[-1] = v17;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v35 = qvalue(elt(env, 1)); /* !*modular */
    if (v35 == nil) goto v70;
    v35 = elt(env, 2); /* modular */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    fn = elt(env, 6); /* off */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v35 = elt(env, 3); /* mod_was_on */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    fn = elt(env, 7); /* on */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    goto v70;

v70:
    v35 = stack[-2];
    v35 = integerp(v35);
    if (v35 == nil) goto v33;
    v35 = stack[-2];
    goto v37;

v37:
    stack[-2] = v35;
    v35 = stack[-1];
    v35 = integerp(v35);
    if (v35 == nil) goto v91;
    v35 = stack[-1];
    goto v25;

v25:
    stack[-1] = v35;
    v97 = stack[-3];
    v89 = stack[-2];
    v35 = stack[-1];
    v97 = list3(v97, v89, v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v89 = stack[0];
    v35 = stack[-3];
    fn = elt(env, 8); /* my_letmtr */
    v35 = (*qfnn(fn))(qenv(fn), 3, v97, v89, v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v35 = qvalue(elt(env, 5)); /* !*mod_was_on */
    if (v35 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v35 = elt(env, 2); /* modular */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    fn = elt(env, 7); /* on */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    v35 = elt(env, 3); /* mod_was_on */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    fn = elt(env, 6); /* off */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v91:
    v35 = stack[-1];
    fn = elt(env, 9); /* reval */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    goto v25;

v33:
    v35 = stack[-2];
    fn = elt(env, 9); /* reval */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-4];
    goto v37;
/* error exit handlers */
v115:
    popv(5);
    return nil;
}



/* Code for !*pf2wedgepf */

static Lisp_Object CC_Hpf2wedgepf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *pf2wedgepf");
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
    goto v14;

v14:
    v6 = stack[0];
    if (v6 == nil) goto v54;
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcar(v6);
    fn = elt(env, 1); /* wedgefax */
    v91 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v6 = stack[0];
    v6 = qcar(v6);
    v7 = qcdr(v6);
    v6 = stack[-1];
    v6 = acons(v91, v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[-1] = v6;
    v6 = stack[0];
    v6 = qcdr(v6);
    stack[0] = v6;
    goto v14;

v54:
    v6 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v6);
    }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for prinlatom */

static Lisp_Object CC_prinlatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v120;
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
    v120 = stack[-1];
    v44 = elt(env, 1); /* font */
    v44 = get(v120, v44);
    env = stack[-3];
    stack[-2] = v44;
    if (v44 == nil) goto v21;
    v44 = stack[-2];
    fn = elt(env, 5); /* prin2la */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    goto v21;

v21:
    v120 = stack[-1];
    v44 = elt(env, 2); /* accent */
    v44 = get(v120, v44);
    env = stack[-3];
    stack[0] = v44;
    if (v44 == nil) goto v49;
    v44 = stack[0];
    fn = elt(env, 5); /* prin2la */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    goto v49;

v49:
    v120 = stack[-1];
    v44 = elt(env, 3); /* name */
    v44 = get(v120, v44);
    env = stack[-3];
    v120 = v44;
    if (v44 == nil) goto v47;
    v44 = v120;
    fn = elt(env, 5); /* prin2la */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    goto v118;

v118:
    v44 = stack[0];
    if (v44 == nil) goto v60;
    v44 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    goto v60;

v60:
    v44 = stack[-2];
    if (v44 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v44 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v89;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v47:
    v44 = stack[-1];
    fn = elt(env, 6); /* testchar1 */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    fn = elt(env, 5); /* prin2la */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    goto v118;
/* error exit handlers */
v89:
    popv(4);
    return nil;
}



/* Code for inttovec */

static Lisp_Object CC_inttovec(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec");
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
    v2 = v1;
    v37 = v0;
/* end of prologue */
    stack[0] = v2;
    fn = elt(env, 1); /* inttovec!-solve */
    v37 = (*qfn2(fn))(qenv(fn), v2, v37);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    {
        Lisp_Object v12 = stack[0];
        popv(2);
        fn = elt(env, 2); /* inttovec1 */
        return (*qfn2(fn))(qenv(fn), v12, v37);
    }
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for fctlength */

static Lisp_Object CC_fctlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctlength");
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
    v14 = v0;
/* end of prologue */
    fn = elt(env, 1); /* fctargs */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    errexit();
        return Llength(nil, v14);
}



/* Code for set!-global!-mode */

static Lisp_Object CC_setKglobalKmode(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-global-mode");
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
    v21 = qvalue(elt(env, 1)); /* nil */
    v21 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    qvalue(elt(env, 2)) = v21; /* alglist!* */
    v21 = stack[-2];
    qvalue(elt(env, 3)) = v21; /* !*mode */
    stack[-3] = elt(env, 4); /* null */
    stack[-1] = elt(env, 5); /* setq */
    stack[0] = elt(env, 3); /* !*mode */
    v21 = stack[-2];
    v21 = Lmkquote(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    v21 = list3(stack[-1], stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v5;
    {
        Lisp_Object v4 = stack[-3];
        popv(5);
        return list2(v4, v21);
    }
/* error exit handlers */
v5:
    popv(5);
    return nil;
}



/* Code for setel */

static Lisp_Object CC_setel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v147, v44, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel");
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
    v109 = stack[-2];
    v147 = qcar(v109);
    v109 = elt(env, 1); /* dimension */
    v109 = get(v147, v109);
    env = stack[-4];
    stack[-3] = v109;
    v109 = stack[-3];
    stack[0] = Llength(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-4];
    v109 = stack[-2];
    v109 = qcdr(v109);
    v109 = Llength(nil, v109);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-4];
    if (equal(stack[0], v109)) goto v133;
    v109 = elt(env, 2); /* "Incorrect array reference" */
    v147 = v109;
    v109 = v147;
    qvalue(elt(env, 3)) = v109; /* errmsg!* */
    v109 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v109 == nil)) goto v6;
    v109 = v147;
    fn = elt(env, 6); /* lprie */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-4];
    goto v6;

v6:
    v109 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v97;
    v109 = nil;
    { popv(5); return onevalue(v109); }

v133:
    v109 = stack[-2];
    v147 = qcar(v109);
    v109 = elt(env, 5); /* avalue */
    v109 = get(v147, v109);
    env = stack[-4];
    v109 = qcdr(v109);
    v120 = qcar(v109);
    v109 = stack[-2];
    v44 = qcdr(v109);
    v147 = stack[-1];
    v109 = stack[-3];
    {
        popv(5);
        fn = elt(env, 7); /* setel1 */
        return (*qfnn(fn))(qenv(fn), 4, v120, v44, v147, v109);
    }
/* error exit handlers */
v97:
    popv(5);
    return nil;
}



/* Code for mkkl */

static Lisp_Object CC_mkkl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v25, v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkkl");
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
    v26 = v1;
    v25 = v0;
/* end of prologue */

v70:
    v20 = v25;
    if (v20 == nil) { popv(2); return onevalue(v26); }
    v20 = v25;
    v20 = qcdr(v20);
    stack[0] = v20;
    v25 = qcar(v25);
    v26 = cons(v25, v26);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-1];
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-1];
    v25 = stack[0];
    goto v70;
/* error exit handlers */
v4:
    popv(2);
    return nil;
}



/* Code for groeb!=better */

static Lisp_Object CC_groebMbetter(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=better");
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
    v109 = stack[-1];
    v109 = qcdr(v109);
    v147 = qcar(v109);
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    v109 = (Lisp_Object)lessp2(v147, v109);
    nil = C_nil;
    if (exception_pending()) goto v121;
    v109 = v109 ? lisp_true : nil;
    env = stack[-2];
    if (v109 == nil) goto v12;
    v109 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v109); }

v12:
    v109 = stack[-1];
    v109 = qcdr(v109);
    v147 = qcar(v109);
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    if (equal(v147, v109)) goto v159;
    v109 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v109); }

v159:
    v147 = stack[-1];
    v109 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v109 = (*qfn2(fn))(qenv(fn), v147, v109);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-2];
    stack[-1] = qcar(v109);
    v147 = stack[0];
    v109 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v109 = (*qfn2(fn))(qenv(fn), v147, v109);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-2];
    v109 = qcar(v109);
    fn = elt(env, 4); /* mo_compare */
    v147 = (*qfn2(fn))(qenv(fn), stack[-1], v109);
    nil = C_nil;
    if (exception_pending()) goto v121;
    v109 = (Lisp_Object)1; /* 0 */
        popv(3);
        return Lleq(nil, v147, v109);
/* error exit handlers */
v121:
    popv(3);
    return nil;
}



/* Code for wi_new */

static Lisp_Object CC_wi_new(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wi_new");
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
    v25 = qvalue(elt(env, 1)); /* wi_number */
    v25 = add1(v25);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    qvalue(elt(env, 1)) = v25; /* wi_number */
    v20 = elt(env, 2); /* !: */
    v25 = qvalue(elt(env, 1)); /* wi_number */
    fn = elt(env, 4); /* mkid */
    v25 = (*qfn2(fn))(qenv(fn), v20, v25);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    v25 = Lintern(nil, v25);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    stack[-3] = v25;
    stack[-1] = stack[-3];
    stack[0] = elt(env, 3); /* windex */
    v25 = stack[-2];
    v25 = ncons(v25);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-4];
    v25 = Lputprop(nil, 3, stack[-1], stack[0], v25);
    nil = C_nil;
    if (exception_pending()) goto v91;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v91:
    popv(5);
    return nil;
}



/* Code for general!-reduce!-degree!-mod!-p */

static Lisp_Object CC_generalKreduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-degree-mod-p");
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
    v183 = stack[-2];
    v183 = qcar(v183);
    v142 = qcdr(v183);
    v183 = (Lisp_Object)1; /* 0 */
    if (v142 == v183) goto v31;
    v142 = qvalue(elt(env, 1)); /* current!-modulus */
    v183 = stack[-2];
    v183 = qcar(v183);
    v183 = qcdr(v183);
    v183 = difference2(v142, v183);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    stack[0] = v183;
    goto v10;

v10:
    v183 = stack[-1];
    v183 = qcar(v183);
    v183 = qcdr(v183);
    fn = elt(env, 2); /* general!-modular!-reciprocal */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    fn = elt(env, 3); /* general!-modular!-times */
    v183 = (*qfn2(fn))(qenv(fn), stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    stack[-3] = v183;
    v183 = stack[-2];
    v183 = qcar(v183);
    v183 = qcar(v183);
    v142 = qcdr(v183);
    v183 = stack[-1];
    v183 = qcar(v183);
    v183 = qcar(v183);
    v183 = qcdr(v183);
    v183 = (Lisp_Object)(int32_t)((int32_t)v142 - (int32_t)v183 + TAG_FIXNUM);
    stack[0] = v183;
    v142 = stack[0];
    v183 = (Lisp_Object)1; /* 0 */
    if (v142 == v183) goto v121;
    v183 = stack[-2];
    stack[-2] = qcdr(v183);
    v183 = stack[-1];
    v183 = qcar(v183);
    v183 = qcar(v183);
    v183 = qcar(v183);
    fn = elt(env, 4); /* fkern */
    v142 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    v183 = stack[0];
    fn = elt(env, 5); /* getpower */
    v142 = (*qfn2(fn))(qenv(fn), v142, v183);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    v183 = stack[-3];
    v142 = cons(v142, v183);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    v183 = stack[-1];
    v183 = qcdr(v183);
    fn = elt(env, 6); /* general!-times!-term!-mod!-p */
    v183 = (*qfn2(fn))(qenv(fn), v142, v183);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    {
        Lisp_Object v184 = stack[-2];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v184, v183);
    }

v121:
    v183 = stack[-2];
    stack[0] = qcdr(v183);
    v183 = stack[-1];
    v142 = qcdr(v183);
    v183 = stack[-3];
    fn = elt(env, 8); /* general!-multiply!-by!-constant!-mod!-p */
    v183 = (*qfn2(fn))(qenv(fn), v142, v183);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-4];
    {
        Lisp_Object v185 = stack[0];
        popv(5);
        fn = elt(env, 7); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v185, v183);
    }

v31:
    v183 = stack[-2];
    v183 = qcar(v183);
    v183 = qcdr(v183);
    stack[0] = v183;
    goto v10;
/* error exit handlers */
v114:
    popv(5);
    return nil;
}



/* Code for findremainder */

static Lisp_Object CC_findremainder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v118, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findremainder");
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
    v91 = v1;
    v118 = v0;
/* end of prologue */
    stack[0] = v91;
    goto v70;

v70:
    v91 = stack[0];
    if (v91 == nil) { popv(2); return onevalue(v118); }
    v91 = stack[0];
    v91 = qcar(v91);
    v9 = v118;
    v118 = v91;
    v91 = qcar(v91);
    v91 = qcar(v91);
    v91 = qcar(v91);
    fn = elt(env, 2); /* wupseudodivide */
    v91 = (*qfnn(fn))(qenv(fn), 3, v9, v118, v91);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v91 = qcdr(v91);
    v118 = v91;
    v91 = stack[0];
    v91 = qcdr(v91);
    stack[0] = v91;
    goto v70;
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for rndifference!: */

static Lisp_Object CC_rndifferenceT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rndifference:");
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
    v32 = stack[-1];
    v32 = qcdr(v32);
    v62 = qcar(v32);
    v32 = stack[0];
    v32 = qcdr(v32);
    v32 = qcdr(v32);
    stack[-2] = times2(v62, v32);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    v32 = stack[-1];
    v32 = qcdr(v32);
    v62 = qcdr(v32);
    v32 = stack[0];
    v32 = qcdr(v32);
    v32 = qcar(v32);
    v32 = times2(v62, v32);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    stack[-2] = difference2(stack[-2], v32);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    v32 = stack[-1];
    v32 = qcdr(v32);
    v62 = qcdr(v32);
    v32 = stack[0];
    v32 = qcdr(v32);
    v32 = qcdr(v32);
    v32 = times2(v62, v32);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-3];
    {
        Lisp_Object v128 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v128, v32);
    }
/* error exit handlers */
v61:
    popv(4);
    return nil;
}



/* Code for qqe_arg!-check */

static Lisp_Object CC_qqe_argKcheck(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check");
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
    v41 = stack[0];
    v41 = qcar(v41);
    stack[-1] = v41;
    v41 = stack[-1];
    fn = elt(env, 4); /* qqe_rqopp */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    if (v41 == nil) goto v54;
    v41 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check!-lq!-rq */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    goto v70;

v70:
    v41 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v41); }

v54:
    v41 = stack[-1];
    fn = elt(env, 6); /* qqe_rbopp */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    if (v41 == nil) goto v36;
    v41 = stack[0];
    fn = elt(env, 7); /* qqe_arg!-check!-lb!-rb */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    goto v70;

v36:
    v41 = stack[-1];
    fn = elt(env, 8); /* qqe_qopheadp */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    if (!(v41 == nil)) goto v2;
    v41 = stack[-1];
    fn = elt(env, 9); /* qqe_qoptailp */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    if (!(v41 == nil)) goto v2;
    v41 = stack[-1];
    fn = elt(env, 10); /* qqe_qopaddp */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    if (v41 == nil) goto v62;
    v41 = stack[0];
    fn = elt(env, 11); /* qqe_arg!-check!-lb!-rq */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    goto v70;

v62:
    v41 = stack[0];
    v41 = qcdr(v41);
    stack[-1] = v41;
    goto v128;

v128:
    v41 = stack[-1];
    if (v41 == nil) goto v70;
    v41 = stack[-1];
    v41 = qcar(v41);
    fn = elt(env, 12); /* qqe_arg!-check!-b */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    if (!(v41 == nil)) goto v120;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    v55 = stack[0];
    v41 = elt(env, 3); /* "some arguments are not of basic type" */
    fn = elt(env, 14); /* typerr */
    v41 = (*qfn2(fn))(qenv(fn), v55, v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    goto v120;

v120:
    v41 = stack[-1];
    v41 = qcdr(v41);
    stack[-1] = v41;
    goto v128;

v2:
    v41 = stack[0];
    v41 = qcdr(v41);
    v41 = qcar(v41);
    fn = elt(env, 15); /* qqe_arg!-check!-q */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    if (!(v41 == nil)) goto v70;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v41 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    v55 = stack[0];
    v41 = elt(env, 1); /* "some arguments are not of queue type" */
    fn = elt(env, 14); /* typerr */
    v41 = (*qfn2(fn))(qenv(fn), v55, v41);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-2];
    goto v70;
/* error exit handlers */
v145:
    popv(3);
    return nil;
}



/* Code for setunion */

static Lisp_Object CC_setunion(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v49, v50;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setunion");
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
    v49 = v0;
/* end of prologue */

v14:
    v65 = stack[0];
    if (v65 == nil) { popv(3); return onevalue(v49); }
    v65 = stack[0];
    v50 = qcar(v65);
    v65 = v49;
    v65 = Lmember(nil, v50, v65);
    if (v65 == nil) goto v26;
    v65 = stack[0];
    v65 = qcdr(v65);
    stack[0] = v65;
    goto v14;

v26:
    stack[-1] = v49;
    v65 = stack[0];
    v65 = qcar(v65);
    v65 = ncons(v65);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v65 = Lappend(nil, stack[-1], v65);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v49 = v65;
    v65 = stack[0];
    v65 = qcdr(v65);
    stack[0] = v65;
    goto v14;
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for ibalp_redclause */

static Lisp_Object CC_ibalp_redclause(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v49;
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
    v65 = stack[-1];
    v65 = qcar(v65);
    stack[-2] = v65;
    goto v10;

v10:
    v65 = stack[-2];
    if (v65 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v65 = stack[0];
    if (!(v65 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v65 = stack[-2];
    v49 = qcar(v65);
    v65 = stack[-1];
    v65 = qcdr(v65);
    v65 = qcar(v65);
    fn = elt(env, 3); /* ibalp_vmember */
    v65 = (*qfn2(fn))(qenv(fn), v49, v65);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    if (v65 == nil) goto v110;
    v65 = qvalue(elt(env, 2)); /* t */
    stack[0] = v65;
    goto v110;

v110:
    v65 = stack[-2];
    v65 = qcdr(v65);
    stack[-2] = v65;
    goto v10;
/* error exit handlers */
v126:
    popv(4);
    return nil;
}



/* Code for aex_ids */

static Lisp_Object CC_aex_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_ids");
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
    v14 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_idl */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v70:
    popv(1);
    return nil;
}



/* Code for stats_getargs */

static Lisp_Object MS_CDECL CC_stats_getargs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "stats_getargs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stats_getargs");
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
    v2 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v3 = v2;
    v2 = v3;
    if (v2 == nil) goto v29;
    stack[0] = v3;
    v2 = CC_stats_getargs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v12;
    {
        Lisp_Object v67 = stack[0];
        popv(2);
        return cons(v67, v2);
    }

v29:
    v2 = nil;
    { popv(2); return onevalue(v2); }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for nfactorial */

static Lisp_Object CC_nfactorial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nfactorial");
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
    v127 = stack[-1];
    v155 = (Lisp_Object)321; /* 20 */
    v155 = (Lisp_Object)greaterp2(v127, v155);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v155 = v155 ? lisp_true : nil;
    env = stack[-3];
    if (v155 == nil) goto v12;
    v127 = (Lisp_Object)17; /* 1 */
    v155 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* fac!-part */
        return (*qfn2(fn))(qenv(fn), v127, v155);
    }

v12:
    v155 = (Lisp_Object)17; /* 1 */
    stack[-2] = v155;
    v155 = (Lisp_Object)17; /* 1 */
    stack[0] = v155;
    goto v65;

v65:
    v127 = stack[-1];
    v155 = stack[0];
    v155 = difference2(v127, v155);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    v155 = Lminusp(nil, v155);
    env = stack[-3];
    if (!(v155 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v127 = stack[-2];
    v155 = stack[0];
    v155 = times2(v127, v155);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    stack[-2] = v155;
    v155 = stack[0];
    v155 = add1(v155);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    stack[0] = v155;
    goto v65;
/* error exit handlers */
v63:
    popv(4);
    return nil;
}



/* Code for mksetq */

static Lisp_Object CC_mksetq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v127, v122, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksetq");
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
    v127 = v1;
    v122 = v0;
/* end of prologue */
    v155 = v122;
    if (!consp(v155)) goto v117;
    v155 = v122;
    v22 = qcar(v155);
    v155 = elt(env, 2); /* setfn */
    v155 = get(v22, v155);
    env = stack[0];
    v22 = v155;
    if (v155 == nil) goto v32;
    v155 = v22;
        popv(1);
        return Lapply2(nil, 3, v155, v122, v127);

v32:
    v127 = v122;
    v155 = elt(env, 3); /* "assignment argument" */
    fn = elt(env, 4); /* typerr */
    v155 = (*qfn2(fn))(qenv(fn), v127, v155);
    nil = C_nil;
    if (exception_pending()) goto v23;
    v155 = nil;
    { popv(1); return onevalue(v155); }

v117:
    v155 = elt(env, 1); /* setq */
    popv(1);
    return list3(v155, v122, v127);
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for mo_neworder */

static Lisp_Object CC_mo_neworder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neworder");
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
    v31 = v0;
/* end of prologue */
    v31 = qcar(v31);
    fn = elt(env, 1); /* mo!=shorten */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    stack[0] = v31;
    fn = elt(env, 2); /* mo!=deglist */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v11;
    {
        Lisp_Object v37 = stack[0];
        popv(2);
        return cons(v37, v31);
    }
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for class */

static Lisp_Object CC_class(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for class");
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
    v118 = stack[0];
    fn = elt(env, 3); /* ord */
    v9 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v118 = (Lisp_Object)1; /* 0 */
    if (v9 == v118) goto v77;
    v9 = qvalue(elt(env, 1)); /* ordering */
    v118 = elt(env, 2); /* lex */
    if (v9 == v118) goto v110;
    v118 = stack[0];
    v118 = qcdr(v118);
    goto v3;

v3:
    v118 = Lreverse(nil, v118);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    fn = elt(env, 4); /* leftzeros */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v118 = (Lisp_Object)((int32_t)(v118) + 0x10);
    { popv(2); return onevalue(v118); }

v110:
    v118 = stack[0];
    goto v3;

v77:
    v118 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v118); }
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for dl_get2 */

static Lisp_Object CC_dl_get2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v126, v119, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get2");
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
    v126 = v1;
    v119 = v0;
/* end of prologue */

v70:
    v95 = v119;
    if (v95 == nil) { popv(2); return onevalue(v126); }
    v95 = v119;
    v159 = qcar(v95);
    v95 = elt(env, 1); /* dummy */
    v95 = get(v159, v95);
    env = stack[-1];
    if (v95 == nil) goto v65;
    v95 = v119;
    v95 = qcdr(v95);
    stack[0] = v95;
    v95 = v119;
    v119 = qcar(v95);
    v95 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* di_insert */
    v95 = (*qfnn(fn))(qenv(fn), 3, v119, v126, v95);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    v126 = v95;
    v95 = stack[0];
    v119 = v95;
    goto v70;

v65:
    v95 = v119;
    v95 = qcdr(v95);
    v119 = v95;
    goto v70;
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for moduntag */

static Lisp_Object CC_moduntag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moduntag");
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
    goto v158;

v158:
    v133 = stack[0];
    v62 = elt(env, 1); /* !:mod!: */
    if (!consp(v133)) goto v117;
    v133 = qcar(v133);
    if (!(v133 == v62)) goto v117;
    v133 = stack[-1];
    v62 = stack[0];
    v62 = qcdr(v62);
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v133, v62);
    }

v117:
    v62 = stack[0];
    if (!consp(v62)) goto v5;
    v62 = stack[0];
    v62 = qcar(v62);
    v133 = CC_moduntag(env, v62);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    v62 = stack[-1];
    v62 = cons(v133, v62);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    stack[-1] = v62;
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[0] = v62;
    goto v158;

v5:
    v133 = stack[-1];
    v62 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v133, v62);
    }
/* error exit handlers */
v61:
    popv(3);
    return nil;
}



/* Code for numeric!-content */

static Lisp_Object CC_numericKcontent(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v125, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numeric-content");
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

v77:
    v63 = stack[0];
    if (!consp(v63)) goto v29;
    v63 = stack[0];
    v63 = qcar(v63);
    if (!consp(v63)) goto v29;
    v63 = stack[0];
    v63 = qcdr(v63);
    if (v63 == nil) goto v13;
    v63 = stack[0];
    v63 = qcar(v63);
    v63 = qcdr(v63);
    v63 = CC_numericKcontent(env, v63);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    v124 = v63;
    v125 = v124;
    v63 = (Lisp_Object)17; /* 1 */
    if (v125 == v63) { popv(3); return onevalue(v124); }
    stack[-1] = v124;
    v63 = stack[0];
    v63 = qcdr(v63);
    v63 = CC_numericKcontent(env, v63);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    fn = elt(env, 1); /* gcddd */
    v63 = (*qfn2(fn))(qenv(fn), stack[-1], v63);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v124 = v63;
    { popv(3); return onevalue(v124); }

v13:
    v63 = stack[0];
    v63 = qcar(v63);
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v77;

v29:
    v63 = stack[0];
    fn = elt(env, 2); /* minusf */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    if (v63 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v63 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* negf */
        return (*qfn1(fn))(qenv(fn), v63);
    }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



/* Code for ibalp_clausep */

static Lisp_Object CC_ibalp_clausep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7;
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
    v6 = stack[0];
    fn = elt(env, 3); /* ibalp_litp */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    if (!(v6 == nil)) { popv(2); return onevalue(v6); }
    v6 = stack[0];
    if (!consp(v6)) goto v37;
    v6 = stack[0];
    v6 = qcar(v6);
    v7 = v6;
    goto v69;

v69:
    v6 = elt(env, 1); /* or */
    if (v7 == v6) goto v26;
    v6 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v6); }

v26:
    v6 = stack[0];
    v6 = qcdr(v6);
    {
        popv(2);
        fn = elt(env, 4); /* ibalp_litlp */
        return (*qfn1(fn))(qenv(fn), v6);
    }

v37:
    v6 = stack[0];
    v7 = v6;
    goto v69;
/* error exit handlers */
v118:
    popv(2);
    return nil;
}



/* Code for aex_fromrp */

static Lisp_Object CC_aex_fromrp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_fromrp");
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
    v67 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v67;
    fn = elt(env, 3); /* ctx_new */
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    v33 = qvalue(elt(env, 2)); /* t */
    v67 = qvalue(elt(env, 2)); /* t */
    v67 = list2(v33, v67);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v25 = stack[-2];
        Lisp_Object v20 = stack[-1];
        Lisp_Object v5 = stack[0];
        popv(4);
        return list3star(v25, v20, v5, v67);
    }
/* error exit handlers */
v26:
    popv(4);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variablesir");
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
    v126 = qvalue(elt(env, 1)); /* char */
    v95 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v126, v95)) goto v70;
    fn = elt(env, 4); /* omvir */
    v95 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-1];
    stack[0] = v95;
    fn = elt(env, 5); /* lex */
    v95 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-1];
    v95 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v159;
    v126 = stack[0];
    if (v126 == nil) goto v13;
    v126 = stack[0];
    popv(2);
    return cons(v126, v95);

v13:
    v126 = stack[0];
        popv(2);
        return Lappend(nil, v126, v95);

v70:
    v95 = nil;
    { popv(2); return onevalue(v95); }
/* error exit handlers */
v159:
    popv(2);
    return nil;
}



/* Code for cr!:minusp */

static Lisp_Object CC_crTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v152, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:minusp");
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
    v133 = v0;
/* end of prologue */
    v152 = v133;
    v152 = qcdr(v152);
    v152 = qcar(v152);
    v133 = qcdr(v133);
    v133 = qcdr(v133);
    v60 = v152;
    v152 = v133;
    v133 = v60;
    if (!consp(v133)) goto v68;
    v133 = v152;
    v133 = qcar(v133);
    v133 = (Lisp_Object)zerop(v133);
    v133 = v133 ? lisp_true : nil;
    env = stack[0];
    if (v133 == nil) goto v118;
    v133 = v60;
    v152 = qcar(v133);
    v133 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v152, v133);

v118:
    v133 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v133); }

v68:
    v133 = v152;
    v133 = (Lisp_Object)zerop(v133);
    v133 = v133 ? lisp_true : nil;
    env = stack[0];
    if (v133 == nil) goto v11;
    v152 = v60;
    v133 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v152, v133);

v11:
    v133 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v133); }
}



/* Code for groebnormalform */

static Lisp_Object MS_CDECL CC_groebnormalform(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v2, v3, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groebnormalform");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebnormalform");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v17;
    v2 = v1;
    v3 = v0;
/* end of prologue */
    v110 = v3;
    v3 = v2;
    v2 = v37;
    v37 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* groebnormalform0 */
        return (*qfnn(fn))(qenv(fn), 4, v110, v3, v2, v37);
    }
}



/* Code for inttovec1 */

static Lisp_Object CC_inttovec1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec1");
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
    v61 = stack[-1];
    v60 = (Lisp_Object)17; /* 1 */
    if (v61 == v60) goto v14;
    v60 = stack[-1];
    v61 = sub1(v60);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v60 = stack[0];
    v60 = qcdr(v60);
    fn = elt(env, 1); /* inttovec!-solve */
    v60 = (*qfn2(fn))(qenv(fn), v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    stack[-2] = v60;
    v60 = stack[0];
    v61 = qcar(v60);
    v60 = stack[-2];
    v60 = qcar(v60);
    stack[0] = difference2(v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v60 = stack[-1];
    v61 = sub1(v60);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v60 = stack[-2];
    v60 = CC_inttovec1(env, v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v122;
    {
        Lisp_Object v22 = stack[0];
        popv(4);
        return cons(v22, v60);
    }

v14:
    v60 = stack[0];
    v60 = qcar(v60);
    popv(4);
    return ncons(v60);
/* error exit handlers */
v122:
    popv(4);
    return nil;
}



/* Code for pterpri */

static Lisp_Object MS_CDECL CC_pterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v108, v109;
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
    v124 = qvalue(elt(env, 1)); /* nil */
    v124 = Lwrs(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    stack[-3] = v124;
    v124 = qvalue(elt(env, 2)); /* !*pprinbuf!* */
    v124 = Lnreverse(nil, v124);
    env = stack[-4];
    stack[-2] = v124;
    v124 = qvalue(elt(env, 3)); /* !*outchanl!* */
    stack[-1] = v124;
    goto v68;

v68:
    v124 = stack[-1];
    if (v124 == nil) goto v158;
    v124 = stack[-1];
    v124 = qcar(v124);
    v124 = Lwrs(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v124 = stack[-2];
    stack[0] = v124;
    goto v26;

v26:
    v124 = stack[0];
    if (v124 == nil) goto v24;
    v124 = stack[0];
    v124 = qcar(v124);
    v109 = v124;
    v108 = qvalue(elt(env, 4)); /* gentranlang!* */
    v124 = elt(env, 5); /* fortran */
    if (v108 == v124) goto v50;
    v124 = v109;
    v124 = Lprinc(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    goto v49;

v49:
    v124 = stack[0];
    v124 = qcdr(v124);
    stack[0] = v124;
    goto v26;

v50:
    v124 = v109;
    fn = elt(env, 7); /* fprin2 */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    goto v49;

v24:
    v124 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-1] = v124;
    goto v68;

v158:
    v124 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 6)) = v124; /* !*posn!* */
    v124 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v124; /* !*pprinbuf!* */
    v124 = stack[-3];
    v124 = Lwrs(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v124 = nil;
    { popv(5); return onevalue(v124); }
/* error exit handlers */
v132:
    popv(5);
    return nil;
}



/* Code for opmtchrevop */

static Lisp_Object CC_opmtchrevop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7;
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
    v6 = qvalue(elt(env, 1)); /* !*val */
    if (v6 == nil) goto v77;
    v7 = elt(env, 2); /* cons */
    v6 = stack[0];
    v6 = Lsmemq(nil, v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    if (!(v6 == nil)) goto v77;
    v6 = stack[0];
    stack[-1] = qcar(v6);
    v6 = stack[0];
    v6 = qcdr(v6);
    fn = elt(env, 3); /* revlis */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    v6 = cons(stack[-1], v6);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v6);
    }

v77:
    v6 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* opmtch */
        return (*qfn1(fn))(qenv(fn), v6);
    }
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for invp */

static Lisp_Object CC_invp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v109, v147;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invp");
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
    v147 = v0;
/* end of prologue */
    v109 = v147;
    v108 = elt(env, 1); /* unit */
    if (v109 == v108) return onevalue(v147);
    v108 = v147;
    if (!consp(v108)) goto v37;
    v108 = v147;
    v109 = qcar(v108);
    v108 = elt(env, 3); /* (comm anticomm) */
    v108 = Lmember(nil, v109, v108);
    if (v108 == nil) goto v61;
    v109 = elt(env, 4); /* quotient */
    v108 = (Lisp_Object)17; /* 1 */
    return list3(v109, v108, v147);

v61:
    v108 = v147;
    v109 = qcar(v108);
    v108 = elt(env, 2); /* inverse */
    v108 = get(v109, v108);
    v109 = v147;
    v109 = qcdr(v109);
    return cons(v108, v109);

v37:
    v108 = v147;
    v109 = elt(env, 2); /* inverse */
    return get(v108, v109);
}



/* Code for assert_uninstall1 */

static Lisp_Object CC_assert_uninstall1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall1");
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
    v108 = stack[0];
    v124 = elt(env, 1); /* assert_installed */
    v124 = get(v108, v124);
    env = stack[-2];
    if (v124 == nil) goto v77;
    v109 = stack[0];
    v108 = stack[0];
    v124 = elt(env, 6); /* assert_noassertfn */
    v124 = get(v108, v124);
    env = stack[-2];
    fn = elt(env, 7); /* copyd */
    v124 = (*qfn2(fn))(qenv(fn), v109, v124);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    v108 = stack[0];
    v124 = elt(env, 1); /* assert_installed */
    v109 = qvalue(elt(env, 3)); /* nil */
        popv(3);
        return Lputprop(nil, 3, v108, v124, v109);

v77:
    v124 = qvalue(elt(env, 2)); /* !*msg */
    if (v124 == nil) goto v123;
    stack[-1] = elt(env, 4); /* "***" */
    v108 = elt(env, 5); /* "assert not installed for" */
    v124 = stack[0];
    v124 = list2(v108, v124);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    {
        Lisp_Object v121 = stack[-1];
        popv(3);
        fn = elt(env, 8); /* lpriw */
        return (*qfn2(fn))(qenv(fn), v121, v124);
    }

v123:
    v124 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v124); }
/* error exit handlers */
v120:
    popv(3);
    return nil;
}



/* Code for bc_zero!? */

static Lisp_Object CC_bc_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v32, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_zero?");
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
    v32 = v0;
/* end of prologue */
    v48 = v32;
    if (v48 == nil) goto v77;
    v62 = v32;
    v48 = (Lisp_Object)1; /* 0 */
    if (v62 == v48) goto v77;
    v48 = qvalue(elt(env, 2)); /* !*hardzerotest */
    if (v48 == nil) goto v157;
    v48 = v32;
    v48 = Lconsp(nil, v48);
    env = stack[0];
    if (v48 == nil) goto v157;
    v48 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* prepf1 */
    v48 = (*qfn2(fn))(qenv(fn), v32, v48);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[0];
    v32 = v48;
    v48 = v32;
    if (v48 == nil) goto v9;
    v48 = v32;
    fn = elt(env, 5); /* replus */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[0];
    goto v118;

v118:
    fn = elt(env, 6); /* simp */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[0];
    v48 = qcar(v48);
    fn = elt(env, 7); /* bc!=simp */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v48 = (v48 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v48); }

v9:
    v48 = (Lisp_Object)1; /* 0 */
    goto v118;

v157:
    v48 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v48); }

v77:
    v48 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v48); }
/* error exit handlers */
v133:
    popv(1);
    return nil;
}



/* Code for general!-expt!-mod!-p */

static Lisp_Object CC_generalKexptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v46, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-expt-mod-p");
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
    v43 = v1;
    stack[0] = v0;
/* end of prologue */
    v46 = v43;
    v59 = (Lisp_Object)1; /* 0 */
    if (v46 == v59) goto v14;
    v46 = v43;
    v59 = (Lisp_Object)17; /* 1 */
    if (v46 == v59) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v46 = v43;
    v59 = (Lisp_Object)33; /* 2 */
    v59 = Ldivide(nil, v46, v59);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    stack[-1] = v59;
    v46 = stack[0];
    v59 = stack[-1];
    v59 = qcar(v59);
    v59 = CC_generalKexptKmodKp(env, v46, v59);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v43 = v59;
    v59 = v43;
    v46 = v43;
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v59 = (*qfn2(fn))(qenv(fn), v59, v46);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v43 = v59;
    v59 = stack[-1];
    v46 = qcdr(v59);
    v59 = (Lisp_Object)1; /* 0 */
    if (v46 == v59) { popv(3); return onevalue(v43); }
    v46 = v43;
    v59 = stack[0];
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v59 = (*qfn2(fn))(qenv(fn), v46, v59);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v43 = v59;
    { popv(3); return onevalue(v43); }

v14:
    v59 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v59); }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for multfnc */

static Lisp_Object CC_multfnc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v192, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multfnc");
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
    v191 = stack[-2];
    v191 = qcar(v191);
    stack[0] = qcdr(v191);
    v191 = stack[-1];
    v191 = qcar(v191);
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    fn = elt(env, 5); /* multf */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    stack[-3] = v191;
    v191 = stack[-3];
    if (v191 == nil) goto v193;
    v191 = stack[-3];
    if (!consp(v191)) goto v21;
    v191 = stack[-3];
    v191 = qcar(v191);
    if (!consp(v191)) goto v21;
    v191 = stack[-3];
    v191 = qcar(v191);
    v191 = qcar(v191);
    v192 = qcar(v191);
    v191 = stack[-2];
    v191 = qcar(v191);
    v191 = qcar(v191);
    v191 = qcar(v191);
    if (!(v192 == v191)) goto v21;
    v191 = stack[-2];
    v191 = qcar(v191);
    v191 = qcar(v191);
    stack[0] = qcar(v191);
    v191 = stack[-2];
    v191 = qcar(v191);
    v191 = qcar(v191);
    v192 = qcdr(v191);
    v191 = stack[-3];
    v191 = qcar(v191);
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = plus2(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    fn = elt(env, 6); /* mkspm */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v72 = v191;
    if (v191 == nil) goto v60;
    v192 = v72;
    v191 = (Lisp_Object)17; /* 1 */
    if (v192 == v191) goto v19;
    v192 = v72;
    v191 = stack[-3];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    v191 = cons(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    stack[0] = v191;
    goto v156;

v156:
    v191 = stack[-2];
    v191 = qcar(v191);
    v192 = qcar(v191);
    v191 = (Lisp_Object)17; /* 1 */
    v191 = cons(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v192 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v191 = stack[-3];
    v191 = qcdr(v191);
    fn = elt(env, 5); /* multf */
    v191 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    fn = elt(env, 7); /* addf */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    stack[-3] = v191;
    goto v193;

v193:
    v191 = stack[-2];
    v192 = qcdr(v191);
    v191 = stack[-1];
    fn = elt(env, 5); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v191 = stack[-2];
    v191 = qcar(v191);
    v192 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v191 = stack[-1];
    v191 = qcdr(v191);
    fn = elt(env, 5); /* multf */
    v191 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    fn = elt(env, 7); /* addf */
    v191 = (*qfn2(fn))(qenv(fn), stack[0], v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    {
        Lisp_Object v93 = stack[-3];
        popv(5);
        fn = elt(env, 7); /* addf */
        return (*qfn2(fn))(qenv(fn), v93, v191);
    }

v19:
    v191 = stack[-3];
    v191 = qcar(v191);
    v191 = qcdr(v191);
    stack[0] = v191;
    goto v156;

v60:
    v191 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v191;
    goto v156;

v21:
    v191 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v191 == nil) goto v174;
    v191 = stack[-2];
    v191 = qcar(v191);
    v191 = qcar(v191);
    v191 = qcar(v191);
    fn = elt(env, 8); /* noncomp1 */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    if (v191 == nil) goto v174;
    v191 = stack[-2];
    v191 = qcar(v191);
    v192 = qcar(v191);
    v191 = stack[-3];
    v191 = cons(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    stack[-3] = v191;
    goto v193;

v174:
    v191 = qvalue(elt(env, 3)); /* t */
    stack[0] = qvalue(elt(env, 4)); /* !*!*processed */
    qvalue(elt(env, 4)) = v191; /* !*!*processed */
    v191 = stack[-2];
    v191 = qcar(v191);
    v192 = qcar(v191);
    v191 = (Lisp_Object)17; /* 1 */
    v191 = cons(v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v192 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v191 = stack[-3];
    fn = elt(env, 5); /* multf */
    v191 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[-3] = v191;
    qvalue(elt(env, 4)) = stack[0]; /* !*!*processed */
    goto v193;
/* error exit handlers */
v94:
    env = stack[-4];
    qvalue(elt(env, 4)) = stack[0]; /* !*!*processed */
    popv(5);
    return nil;
v92:
    popv(5);
    return nil;
}



/* Code for qqe_ofsf_varlterm */

static Lisp_Object CC_qqe_ofsf_varlterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v127, v122, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_varlterm");
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
    v122 = v1;
    v22 = v0;
/* end of prologue */
    v155 = v22;
    if (!(!consp(v155))) goto v54;
    v155 = v22;
    if (!(symbolp(v155))) goto v54;
    v127 = v22;
    v155 = elt(env, 1); /* qepsilon */
    if (v127 == v155) goto v54;
    v155 = v22;
    v127 = v122;
    fn = elt(env, 3); /* lto_insertq */
    v155 = (*qfn2(fn))(qenv(fn), v155, v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v122 = v155;
    { popv(2); return onevalue(v122); }

v54:
    v155 = v22;
    if (!consp(v155)) { popv(2); return onevalue(v122); }
    v155 = v22;
    v155 = qcdr(v155);
    stack[0] = v155;
    goto v91;

v91:
    v155 = stack[0];
    if (v155 == nil) { popv(2); return onevalue(v122); }
    v155 = stack[0];
    v155 = qcar(v155);
    v127 = v122;
    v155 = CC_qqe_ofsf_varlterm(env, v155, v127);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-1];
    v122 = v155;
    v155 = stack[0];
    v155 = qcdr(v155);
    stack[0] = v155;
    goto v91;
/* error exit handlers */
v63:
    popv(2);
    return nil;
}



setup_type const u15_setup[] =
{
    {"intexprlisp",             too_few_2,      CC_intexprlisp,wrong_no_2},
    {"squared+matrix+p",        CC_squaredLmatrixLp,too_many_1,wrong_no_1},
    {"ibalp_simpterm",          CC_ibalp_simpterm,too_many_1,  wrong_no_1},
    {"ratpoly_nullp",           CC_ratpoly_nullp,too_many_1,   wrong_no_1},
    {"vbcgcd",                  too_few_2,      CC_vbcgcd,     wrong_no_2},
    {"vdpred",                  CC_vdpred,      too_many_1,    wrong_no_1},
    {"termordp!",               too_few_2,      CC_termordpB,  wrong_no_2},
    {"*sqprint",                CC_Hsqprint,    too_many_1,    wrong_no_1},
    {"rd:plus",                 too_few_2,      CC_rdTplus,    wrong_no_2},
    {"physopaeval",             CC_physopaeval, too_many_1,    wrong_no_1},
    {"assert_install",          CC_assert_install,too_many_1,  wrong_no_1},
    {"pv_intequiv",             CC_pv_intequiv, too_many_1,    wrong_no_1},
    {"splitlist:",              too_few_2,      CC_splitlistT, wrong_no_2},
    {"wtchk",                   too_few_2,      CC_wtchk,      wrong_no_2},
    {"exptcompare",             too_few_2,      CC_exptcompare,wrong_no_2},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,too_many_1,wrong_no_1},
    {"sq2sspl",                 too_few_2,      CC_sq2sspl,    wrong_no_2},
    {"ibalp_clauselp",          CC_ibalp_clauselp,too_many_1,  wrong_no_1},
    {"aex_lc",                  too_few_2,      CC_aex_lc,     wrong_no_2},
    {"nary",                    too_few_2,      CC_nary,       wrong_no_2},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"spquotematrix",           CC_spquotematrix,too_many_1,   wrong_no_1},
    {"dm-minus",                CC_dmKminus,    too_many_1,    wrong_no_1},
    {"chk",                     CC_chk,         too_many_1,    wrong_no_1},
    {"vdpzero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpzero},
    {"vdpputprop",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpputprop},
    {"repasc",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_repasc},
    {"putd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_putd},
    {"evalequal",               too_few_2,      CC_evalequal,  wrong_no_2},
    {"sf2mv1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_sf2mv1},
    {"bc_inv",                  CC_bc_inv,      too_many_1,    wrong_no_1},
    {"gperm0",                  CC_gperm0,      too_many_1,    wrong_no_1},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"expt-mod-p",              too_few_2,      CC_exptKmodKp, wrong_no_2},
    {"qqe_simplat1",            too_few_2,      CC_qqe_simplat1,wrong_no_2},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ratpoly_1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_1},
    {"variableom",              CC_variableom,  too_many_1,    wrong_no_1},
    {"delhisto",                CC_delhisto,    too_many_1,    wrong_no_1},
    {"newenv",                  CC_newenv,      too_many_1,    wrong_no_1},
    {"setmat",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setmat},
    {"*pf2wedgepf",             CC_Hpf2wedgepf, too_many_1,    wrong_no_1},
    {"prinlatom",               CC_prinlatom,   too_many_1,    wrong_no_1},
    {"inttovec",                too_few_2,      CC_inttovec,   wrong_no_2},
    {"fctlength",               CC_fctlength,   too_many_1,    wrong_no_1},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"setel",                   too_few_2,      CC_setel,      wrong_no_2},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {"groeb=better",            too_few_2,      CC_groebMbetter,wrong_no_2},
    {"wi_new",                  CC_wi_new,      too_many_1,    wrong_no_1},
    {"general-reduce-degree-mod-p",too_few_2,   CC_generalKreduceKdegreeKmodKp,wrong_no_2},
    {"findremainder",           too_few_2,      CC_findremainder,wrong_no_2},
    {"rndifference:",           too_few_2,      CC_rndifferenceT,wrong_no_2},
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"setunion",                too_few_2,      CC_setunion,   wrong_no_2},
    {"ibalp_redclause",         CC_ibalp_redclause,too_many_1, wrong_no_1},
    {"aex_ids",                 CC_aex_ids,     too_many_1,    wrong_no_1},
    {"stats_getargs",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_stats_getargs},
    {"nfactorial",              CC_nfactorial,  too_many_1,    wrong_no_1},
    {"mksetq",                  too_few_2,      CC_mksetq,     wrong_no_2},
    {"mo_neworder",             CC_mo_neworder, too_many_1,    wrong_no_1},
    {"class",                   CC_class,       too_many_1,    wrong_no_1},
    {"dl_get2",                 too_few_2,      CC_dl_get2,    wrong_no_2},
    {"moduntag",                CC_moduntag,    too_many_1,    wrong_no_1},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"ibalp_clausep",           CC_ibalp_clausep,too_many_1,   wrong_no_1},
    {"aex_fromrp",              CC_aex_fromrp,  too_many_1,    wrong_no_1},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"cr:minusp",               CC_crTminusp,   too_many_1,    wrong_no_1},
    {"groebnormalform",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebnormalform},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"pterpri",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_pterpri},
    {"opmtchrevop",             CC_opmtchrevop, too_many_1,    wrong_no_1},
    {"invp",                    CC_invp,        too_many_1,    wrong_no_1},
    {"assert_uninstall1",       CC_assert_uninstall1,too_many_1,wrong_no_1},
    {"bc_zero?",                CC_bc_zeroW,    too_many_1,    wrong_no_1},
    {"general-expt-mod-p",      too_few_2,      CC_generalKexptKmodKp,wrong_no_2},
    {"multfnc",                 too_few_2,      CC_multfnc,    wrong_no_2},
    {"qqe_ofsf_varlterm",       too_few_2,      CC_qqe_ofsf_varlterm,wrong_no_2},
    {NULL, (one_args *)"u15", (two_args *)"18123 1442180 4470703", 0}
};

/* end of generated code */
