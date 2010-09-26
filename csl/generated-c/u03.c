
/* $destdir\u03.c        Machine generated C code */

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


/* Code for plus!-mod!-p */

static Lisp_Object CC_plusKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plus-mod-p");
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
    stack[0] = nil;
    goto v42;

v42:
    v39 = stack[-3];
    if (v39 == nil) goto v43;
    v39 = stack[-2];
    if (v39 == nil) goto v44;
    v39 = stack[-3];
    if (!consp(v39)) goto v45;
    v39 = stack[-3];
    v39 = qcar(v39);
    if (!consp(v39)) goto v45;
    v39 = stack[-2];
    if (!consp(v39)) goto v46;
    v39 = stack[-2];
    v39 = qcar(v39);
    if (!consp(v39)) goto v46;
    v39 = stack[-3];
    v39 = qcar(v39);
    v40 = qcar(v39);
    v39 = stack[-2];
    v39 = qcar(v39);
    v39 = qcar(v39);
    if (equal(v40, v39)) goto v47;
    v39 = stack[-3];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v40 = qcar(v39);
    v39 = stack[-2];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v39 = qcar(v39);
    if (!(equal(v40, v39))) goto v48;
    v39 = stack[-3];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v40 = qcdr(v39);
    v39 = stack[-2];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v39 = qcdr(v39);
    if (!(((int32_t)(v40)) > ((int32_t)(v39)))) goto v48;

v49:
    v39 = stack[-3];
    v40 = qcar(v39);
    v39 = stack[0];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[0] = v39;
    v39 = stack[-3];
    v39 = qcdr(v39);
    stack[-3] = v39;
    goto v42;

v48:
    v39 = stack[-3];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v40 = qcar(v39);
    v39 = stack[-2];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v39 = qcar(v39);
    if (equal(v40, v39)) goto v51;
    v39 = stack[-3];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v40 = qcar(v39);
    v39 = stack[-2];
    v39 = qcar(v39);
    v39 = qcar(v39);
    v39 = qcar(v39);
    fn = elt(env, 2); /* ordop */
    v39 = (*qfn2(fn))(qenv(fn), v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    if (!(v39 == nil)) goto v49;

v51:
    v39 = stack[-2];
    v40 = qcar(v39);
    v39 = stack[0];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[0] = v39;
    v39 = stack[-2];
    v39 = qcdr(v39);
    stack[-2] = v39;
    goto v42;

v47:
    stack[-4] = stack[0];
    v39 = stack[-3];
    v39 = qcar(v39);
    stack[-1] = qcar(v39);
    v39 = stack[-3];
    v39 = qcar(v39);
    v40 = qcdr(v39);
    v39 = stack[-2];
    v39 = qcar(v39);
    v39 = qcdr(v39);
    stack[0] = CC_plusKmodKp(env, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    v39 = stack[-3];
    v40 = qcdr(v39);
    v39 = stack[-2];
    v39 = qcdr(v39);
    v39 = CC_plusKmodKp(env, v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    fn = elt(env, 3); /* adjoin!-term */
    v39 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    {
        Lisp_Object v52 = stack[-4];
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v52, v39);
    }

v46:
    v39 = stack[-3];
    v40 = qcar(v39);
    v39 = stack[0];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[0] = v39;
    v39 = stack[-3];
    v39 = qcdr(v39);
    stack[-3] = v39;
    goto v42;

v45:
    v39 = stack[-2];
    if (!consp(v39)) goto v53;
    v39 = stack[-2];
    v39 = qcar(v39);
    if (!consp(v39)) goto v53;
    v39 = stack[-2];
    v40 = qcar(v39);
    v39 = stack[0];
    v39 = cons(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[0] = v39;
    v39 = stack[-2];
    v39 = qcdr(v39);
    stack[-2] = v39;
    goto v42;

v53:
    v41 = stack[0];
    v40 = stack[-3];
    v39 = stack[-2];
    {   int32_t w = int_of_fixnum(v40) + int_of_fixnum(v39);
        if (w >= current_modulus) w -= current_modulus;
        v39 = fixnum_of_int(w);
    }
    v40 = v39;
    v39 = v40;
    v39 = (Lisp_Object)zerop(v39);
    v39 = v39 ? lisp_true : nil;
    env = stack[-5];
    if (v39 == nil) goto v54;
    v39 = qvalue(elt(env, 1)); /* nil */
    goto v55;

v55:
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v41, v39);
    }

v54:
    v39 = v40;
    goto v55;

v44:
    v40 = stack[0];
    v39 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v40, v39);
    }

v43:
    v40 = stack[0];
    v39 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v40, v39);
    }
/* error exit handlers */
v50:
    popv(6);
    return nil;
}



/* Code for sfto_dcontentf */

static Lisp_Object CC_sfto_dcontentf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dcontentf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v58 = v0;
/* end of prologue */
    v59 = v58;
    v58 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sfto_dcontentf1 */
        return (*qfn2(fn))(qenv(fn), v59, v58);
    }
}



/* Code for lt!* */

static Lisp_Object CC_ltH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v68, v69;
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
    v54 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v54 == nil)) goto v70;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v68 = qcdr(v54);
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)greaterp2(v68, v54);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v54 = v54 ? lisp_true : nil;
    env = stack[-3];
    if (!(v54 == nil)) goto v70;
    v54 = stack[-1];
    v54 = qcar(v54);
    stack[-2] = v54;
    v54 = stack[-1];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v54 = qcar(v54);
    stack[0] = v54;
    goto v72;

v72:
    v54 = stack[-1];
    v54 = qcdr(v54);
    stack[-1] = v54;
    v54 = stack[-1];
    if (v54 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v68 = stack[-1];
    v54 = stack[0];
    fn = elt(env, 2); /* degr */
    v68 = (*qfn2(fn))(qenv(fn), v68, v54);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    v54 = (Lisp_Object)1; /* 0 */
    if (!(v68 == v54)) goto v72;
    v69 = stack[0];
    v68 = (Lisp_Object)1; /* 0 */
    v54 = stack[-1];
    popv(4);
    return acons(v69, v68, v54);

v70:
    v54 = stack[-1];
    v54 = qcar(v54);
    { popv(4); return onevalue(v54); }
/* error exit handlers */
v71:
    popv(4);
    return nil;
}



/* Code for tayexp!-plus2 */

static Lisp_Object CC_tayexpKplus2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v87, v88;
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
    v86 = v0;
/* end of prologue */
    v87 = v86;
    if (!(!consp(v87))) goto v38;
    v87 = stack[0];
    if (!(!consp(v87))) goto v38;
    v87 = v86;
    v86 = stack[0];
    popv(3);
    return plus2(v87, v86);

v38:
    v87 = v86;
    if (!consp(v87)) goto v89;
    v87 = stack[0];
    if (!consp(v87)) goto v53;
    v87 = v86;
    v86 = stack[0];
    fn = elt(env, 2); /* rnplus!: */
    v86 = (*qfn2(fn))(qenv(fn), v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v26;
    goto v90;

v90:
    v88 = v86;
    v86 = v88;
    v86 = qcdr(v86);
    v87 = qcdr(v86);
    v86 = (Lisp_Object)17; /* 1 */
    if (!(v87 == v86)) { popv(3); return onevalue(v88); }
    v86 = v88;
    v86 = qcdr(v86);
    v86 = qcar(v86);
    { popv(3); return onevalue(v86); }

v53:
    stack[-1] = v86;
    v88 = elt(env, 1); /* !:rn!: */
    v87 = stack[0];
    v86 = (Lisp_Object)17; /* 1 */
    v86 = list2star(v88, v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    fn = elt(env, 2); /* rnplus!: */
    v86 = (*qfn2(fn))(qenv(fn), stack[-1], v86);
    nil = C_nil;
    if (exception_pending()) goto v26;
    goto v90;

v89:
    v88 = elt(env, 1); /* !:rn!: */
    v87 = v86;
    v86 = (Lisp_Object)17; /* 1 */
    v87 = list2star(v88, v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v86 = stack[0];
    fn = elt(env, 2); /* rnplus!: */
    v86 = (*qfn2(fn))(qenv(fn), v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v26;
    goto v90;
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for pasf_susitf */

static Lisp_Object CC_pasf_susitf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object v70, v91;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susitf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v1;
    v91 = v0;
/* end of prologue */
    return onevalue(v91);
}



/* Code for notstring */

static Lisp_Object CC_notstring(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v82, v83;
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
    v84 = v0;
/* end of prologue */
    v82 = elt(env, 1); /* !  */
    fn = elt(env, 5); /* delall */
    v84 = (*qfn2(fn))(qenv(fn), v82, v84);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    v83 = v84;
    v84 = v83;
    v82 = qcar(v84);
    v84 = elt(env, 2); /* !" */
    if (v82 == v84) goto v96;
    v84 = v83;
    v84 = Lreverse(nil, v84);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    v82 = qcar(v84);
    v84 = elt(env, 2); /* !" */
    if (v82 == v84) goto v96;
    v84 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v84); }

v96:
    v84 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v84); }
/* error exit handlers */
v81:
    popv(1);
    return nil;
}



/* Code for multi_isarb_compl */

static Lisp_Object CC_multi_isarb_compl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
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
    v63 = stack[0];
    v63 = Lconsp(nil, v63);
    env = stack[-1];
    if (v63 == nil) goto v91;
    v63 = stack[0];
    if (v63 == nil) goto v91;
    v63 = stack[0];
    v63 = qcar(v63);
    fn = elt(env, 2); /* isarb_compl */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    v63 = stack[0];
    v63 = qcdr(v63);
    v63 = CC_multi_isarb_compl(env, v63);
    nil = C_nil;
    if (exception_pending()) goto v97;
    goto v91;

v91:
    v63 = nil;
    { popv(2); return onevalue(v63); }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for sqform */

static Lisp_Object CC_sqform(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v103, v64, v55;
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
    v103 = stack[0];
    v53 = stack[-1];
    v53 = qcar(v53);
    stack[-2] = Lapply1(nil, v103, v53);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v103 = stack[0];
    v53 = stack[-1];
    v53 = qcdr(v53);
    v53 = Lapply1(nil, v103, v53);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-3];
    v55 = stack[-2];
    v64 = v53;
    v103 = v64;
    v53 = (Lisp_Object)17; /* 1 */
    if (v103 == v53) { popv(4); return onevalue(v55); }
    v53 = elt(env, 1); /* quotient */
    v103 = v55;
    popv(4);
    return list3(v53, v103, v64);
/* error exit handlers */
v104:
    popv(4);
    return nil;
}



/* Code for dm!-times */

static Lisp_Object CC_dmKtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-times");
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
    fn = elt(env, 1); /* zero2nil */
    stack[-1] = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    v105 = stack[0];
    fn = elt(env, 1); /* zero2nil */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    fn = elt(env, 2); /* !:times */
    v105 = (*qfn2(fn))(qenv(fn), stack[-1], v105);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v105);
    }
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for initcomb */

static Lisp_Object CC_initcomb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initcomb");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v0;
/* end of prologue */
    return ncons(v70);
}



/* Code for evsum */

static Lisp_Object CC_evsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v62, v54;
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
    v54 = nil;
    goto v56;

v56:
    v60 = stack[-1];
    if (v60 == nil) goto v107;
    v60 = stack[0];
    if (v60 == nil) goto v107;
    v60 = stack[-1];
    v62 = qcar(v60);
    v60 = stack[0];
    v60 = qcar(v60);
    v60 = (Lisp_Object)(int32_t)((int32_t)v62 + (int32_t)v60 - TAG_FIXNUM);
    v62 = v54;
    v60 = cons(v60, v62);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v54 = v60;
    v60 = stack[-1];
    v60 = qcdr(v60);
    stack[-1] = v60;
    v60 = stack[0];
    v60 = qcdr(v60);
    stack[0] = v60;
    goto v56;

v107:
    v60 = v54;
    v60 = Lnreverse(nil, v60);
    v54 = v60;
    v60 = stack[-1];
    if (v60 == nil) goto v108;
    v62 = v54;
    v60 = stack[-1];
        popv(3);
        return Lnconc(nil, v62, v60);

v108:
    v60 = stack[0];
    if (v60 == nil) { popv(3); return onevalue(v54); }
    v62 = v54;
    v60 = stack[0];
        popv(3);
        return Lnconc(nil, v62, v60);
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for multpfsq */

static Lisp_Object CC_multpfsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v99;
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
    goto v42;

v42:
    v108 = stack[-2];
    if (v108 == nil) goto v57;
    v108 = stack[-1];
    v108 = qcar(v108);
    if (v108 == nil) goto v57;
    v108 = stack[-2];
    v108 = qcar(v108);
    stack[0] = qcar(v108);
    v108 = stack[-2];
    v108 = qcar(v108);
    v99 = qcdr(v108);
    v108 = stack[-1];
    fn = elt(env, 1); /* multsq */
    v99 = (*qfn2(fn))(qenv(fn), v99, v108);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v108 = stack[-3];
    v108 = acons(stack[0], v99, v108);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    stack[-3] = v108;
    v108 = stack[-2];
    v108 = qcdr(v108);
    stack[-2] = v108;
    goto v42;

v57:
    v108 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v108);
    }
/* error exit handlers */
v64:
    popv(5);
    return nil;
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v94, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "divide:");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divide:");
#endif
    if (stack >= stacklimit)
    {
        push3(v94,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v94);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v94;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = stack[-1];
    v61 = stack[-2];
    v61 = qcdr(v61);
    v61 = qcar(v61);
    v61 = Labsval(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v61 = add1(v61);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v61 = plus2(stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v61 = (*qfn2(fn))(qenv(fn), stack[-3], v61);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-3] = v61;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v61 = stack[-3];
    v61 = qcdr(v61);
    v60 = qcar(v61);
    v61 = stack[-2];
    v61 = qcdr(v61);
    v61 = qcar(v61);
    stack[0] = quot2(v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v61 = stack[-3];
    v61 = qcdr(v61);
    v60 = qcdr(v61);
    v61 = stack[-2];
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = difference2(v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v61 = list2star(stack[-4], stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-3] = v61;
    v60 = stack[-3];
    v61 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v60, v61);
    }
/* error exit handlers */
v77:
    popv(6);
    return nil;
}



/* Code for reordop */

static Lisp_Object CC_reordop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reordop");
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
    v35 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v35 == nil) goto v56;
    v35 = stack[-1];
    fn = elt(env, 3); /* noncomp1 */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    if (v35 == nil) goto v95;
    v35 = stack[0];
    fn = elt(env, 3); /* noncomp1 */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    goto v107;

v107:
    if (!(v35 == nil)) { popv(3); return onevalue(v35); }
    v36 = stack[-1];
    v35 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* ordop */
        return (*qfn2(fn))(qenv(fn), v36, v35);
    }

v95:
    v35 = qvalue(elt(env, 2)); /* nil */
    goto v107;

v56:
    v35 = qvalue(elt(env, 2)); /* nil */
    goto v107;
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for opmtch!* */

static Lisp_Object CC_opmtchH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v43;
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
    v43 = v0;
/* end of prologue */
    v95 = qvalue(elt(env, 1)); /* subfg!* */
    stack[0] = v95;
    v95 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v95; /* subfg!* */
    v95 = v43;
    fn = elt(env, 3); /* opmtch */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-1];
    v43 = v95;
    v95 = stack[0];
    qvalue(elt(env, 1)) = v95; /* subfg!* */
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v112:
    popv(2);
    return nil;
}



/* Code for qassoc */

static Lisp_Object CC_qassoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36, v45, v80;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qassoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v1;
    v80 = v0;
/* end of prologue */

v91:
    v35 = v45;
    if (v35 == nil) goto v56;
    v36 = v80;
    v35 = v45;
    v35 = qcar(v35);
    v35 = qcar(v35);
    if (v36 == v35) goto v95;
    v35 = v45;
    v35 = qcdr(v35);
    v45 = v35;
    goto v91;

v95:
    v35 = v45;
    v35 = qcar(v35);
    return onevalue(v35);

v56:
    v35 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v35);
}



/* Code for fs!:timestermterm */

static Lisp_Object CC_fsTtimestermterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v174, v175;
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
    v173 = (Lisp_Object)113; /* 7 */
    v173 = Lmkvect(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    stack[-8] = v173;
    v174 = stack[-7];
    v173 = (Lisp_Object)33; /* 2 */
    v173 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    stack[-4] = v173;
    v174 = stack[-6];
    v173 = (Lisp_Object)33; /* 2 */
    v173 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    stack[-3] = v173;
    v173 = (Lisp_Object)1; /* 0 */
    stack[-2] = v173;
    goto v84;

v84:
    v174 = (Lisp_Object)113; /* 7 */
    v173 = stack[-2];
    v173 = difference2(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    v173 = Lminusp(nil, v173);
    env = stack[-9];
    if (v173 == nil) goto v53;
    v173 = (Lisp_Object)113; /* 7 */
    v173 = Lmkvect(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    stack[-5] = v173;
    v173 = (Lisp_Object)1; /* 0 */
    stack[-2] = v173;
    goto v46;

v46:
    v174 = (Lisp_Object)113; /* 7 */
    v173 = stack[-2];
    v173 = difference2(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    v173 = Lminusp(nil, v173);
    env = stack[-9];
    if (v173 == nil) goto v177;
    v174 = stack[-7];
    v173 = (Lisp_Object)1; /* 0 */
    v175 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    v174 = stack[-6];
    v173 = (Lisp_Object)1; /* 0 */
    v173 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    fn = elt(env, 5); /* multsq */
    v173 = (*qfn2(fn))(qenv(fn), v175, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    stack[0] = v173;
    v174 = stack[0];
    v173 = elt(env, 2); /* (1 . 2) */
    fn = elt(env, 5); /* multsq */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    stack[0] = v173;
    v173 = stack[0];
    v173 = qcar(v173);
    if (v173 == nil) goto v178;
    v174 = stack[-7];
    v173 = (Lisp_Object)17; /* 1 */
    v174 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    v173 = elt(env, 3); /* sin */
    if (v174 == v173) goto v179;
    v174 = stack[-6];
    v173 = (Lisp_Object)17; /* 1 */
    v174 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    v173 = elt(env, 3); /* sin */
    if (v174 == v173) goto v180;
    v175 = elt(env, 4); /* cos */
    v174 = stack[-8];
    v173 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v175, v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    v175 = elt(env, 4); /* cos */
    v174 = stack[-5];
    v173 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v173 = (*qfnn(fn))(qenv(fn), 3, v175, v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    {
        Lisp_Object v181 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v181, v173);
    }

v180:
    v175 = elt(env, 3); /* sin */
    v174 = stack[-8];
    v173 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v175, v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    stack[-1] = elt(env, 3); /* sin */
    stack[-3] = stack[-5];
    v173 = stack[0];
    v173 = qcar(v173);
    fn = elt(env, 8); /* negf */
    v174 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = cons(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    fn = elt(env, 6); /* make!-term */
    v173 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-3], v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    {
        Lisp_Object v182 = stack[-2];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v182, v173);
    }

v179:
    v174 = stack[-6];
    v173 = (Lisp_Object)17; /* 1 */
    v174 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    v173 = elt(env, 3); /* sin */
    if (v174 == v173) goto v183;
    v175 = elt(env, 3); /* sin */
    v174 = stack[-8];
    v173 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v175, v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    v175 = elt(env, 3); /* sin */
    v174 = stack[-5];
    v173 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v173 = (*qfnn(fn))(qenv(fn), 3, v175, v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    {
        Lisp_Object v184 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v184, v173);
    }

v183:
    stack[-1] = elt(env, 4); /* cos */
    stack[-2] = stack[-8];
    v173 = stack[0];
    v173 = qcar(v173);
    fn = elt(env, 8); /* negf */
    v174 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    v173 = stack[0];
    v173 = qcdr(v173);
    v173 = cons(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-2], v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    v175 = elt(env, 4); /* cos */
    v174 = stack[-5];
    v173 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v173 = (*qfnn(fn))(qenv(fn), 3, v175, v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    {
        Lisp_Object v185 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v185, v173);
    }

v178:
    v173 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v173); }

v177:
    stack[-1] = stack[-5];
    stack[0] = stack[-2];
    v174 = stack[-4];
    v173 = stack[-2];
    v175 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    v174 = stack[-3];
    v173 = stack[-2];
    v173 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    v173 = difference2(v175, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v173;
    v173 = stack[-2];
    v173 = add1(v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    stack[-2] = v173;
    goto v46;

v53:
    stack[-1] = stack[-8];
    stack[0] = stack[-2];
    v174 = stack[-4];
    v173 = stack[-2];
    v175 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    v174 = stack[-3];
    v173 = stack[-2];
    v173 = *(Lisp_Object *)((char *)v174 + (CELL-TAG_VECTOR) + ((int32_t)v173/(16/CELL)));
    v173 = plus2(v175, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v173;
    v173 = stack[-2];
    v173 = add1(v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-9];
    stack[-2] = v173;
    goto v84;
/* error exit handlers */
v176:
    popv(10);
    return nil;
}



/* Code for mo!=sum */

static Lisp_Object CC_moMsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67, v65;
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
    v65 = nil;
    goto v56;

v56:
    v66 = stack[-1];
    if (v66 == nil) goto v84;
    v66 = stack[0];
    if (v66 == nil) goto v84;
    v66 = stack[-1];
    v67 = qcar(v66);
    v66 = stack[0];
    v66 = qcar(v66);
    v66 = (Lisp_Object)(int32_t)((int32_t)v67 + (int32_t)v66 - TAG_FIXNUM);
    v67 = v65;
    v66 = cons(v66, v67);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    v65 = v66;
    v66 = stack[-1];
    v66 = qcdr(v66);
    stack[-1] = v66;
    v66 = stack[0];
    v66 = qcdr(v66);
    stack[0] = v66;
    goto v56;

v84:
    v66 = v65;
    v67 = Lnreverse(nil, v66);
    v66 = stack[-1];
    if (v66 == nil) goto v30;
    v66 = stack[-1];
    goto v81;

v81:
        popv(3);
        return Lappend(nil, v67, v66);

v30:
    v66 = stack[0];
    goto v81;
/* error exit handlers */
v186:
    popv(3);
    return nil;
}



/* Code for pcmult */

static Lisp_Object CC_pcmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v71;
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
    v74 = v0;
/* end of prologue */
    stack[-5] = v74;
    v74 = stack[-5];
    if (v74 == nil) goto v95;
    v74 = stack[-5];
    v74 = qcar(v74);
    v71 = v74;
    stack[0] = qcar(v71);
    v71 = stack[-4];
    v74 = qcdr(v74);
    fn = elt(env, 2); /* cprod */
    v74 = (*qfn2(fn))(qenv(fn), v71, v74);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v74 = cons(stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    stack[-2] = v74;
    stack[-3] = v74;
    goto v56;

v56:
    v74 = stack[-5];
    v74 = qcdr(v74);
    stack[-5] = v74;
    v74 = stack[-5];
    if (v74 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v74 = stack[-5];
    v74 = qcar(v74);
    v71 = v74;
    stack[0] = qcar(v71);
    v71 = stack[-4];
    v74 = qcdr(v74);
    fn = elt(env, 2); /* cprod */
    v74 = (*qfn2(fn))(qenv(fn), v71, v74);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v74 = cons(stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v74 = Lrplacd(nil, stack[-1], v74);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-6];
    v74 = stack[-2];
    v74 = qcdr(v74);
    stack[-2] = v74;
    goto v56;

v95:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v74); }
/* error exit handlers */
v29:
    popv(7);
    return nil;
}



/* Code for pv_multc */

static Lisp_Object CC_pv_multc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29, v188;
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
    v29 = stack[0];
    v28 = (Lisp_Object)1; /* 0 */
    if (v29 == v28) goto v91;
    v28 = stack[-1];
    if (v28 == nil) goto v91;
    v29 = stack[0];
    v28 = (Lisp_Object)17; /* 1 */
    if (v29 == v28) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v93;

v93:
    v28 = stack[-1];
    if (v28 == nil) goto v92;
    v28 = stack[-1];
    v28 = qcar(v28);
    v29 = qcar(v28);
    v28 = (Lisp_Object)1; /* 0 */
    if (v29 == v28) goto v81;
    v29 = stack[0];
    v28 = stack[-1];
    v28 = qcar(v28);
    v28 = qcar(v28);
    v188 = times2(v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    v28 = stack[-1];
    v28 = qcar(v28);
    v29 = qcdr(v28);
    v28 = stack[-2];
    v28 = acons(v188, v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-2] = v28;
    goto v81;

v81:
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v93;

v92:
    v28 = stack[-2];
        popv(4);
        return Lnreverse(nil, v28);

v91:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v28); }
/* error exit handlers */
v75:
    popv(4);
    return nil;
}



/* Code for lnc */

static Lisp_Object CC_lnc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lnc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v44 = v0;
/* end of prologue */

v70:
    v63 = v44;
    if (v63 == nil) goto v107;
    v63 = v44;
    if (!consp(v63)) return onevalue(v44);
    v63 = v44;
    v63 = qcar(v63);
    if (!consp(v63)) return onevalue(v44);
    v44 = qcar(v44);
    v44 = qcdr(v44);
    goto v70;

v107:
    v44 = (Lisp_Object)1; /* 0 */
    return onevalue(v44);
}



/* Code for tayexp!-lessp */

static Lisp_Object CC_tayexpKlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-lessp");
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
    v66 = v1;
    v67 = v0;
/* end of prologue */
    v104 = v67;
    if (!(!consp(v104))) goto v90;
    v104 = v66;
    if (!(!consp(v104))) goto v90;
    v104 = v67;
        popv(1);
        return Llessp(nil, v104, v66);

v90:
    v104 = v67;
    fn = elt(env, 2); /* tayexp!-difference */
    v104 = (*qfn2(fn))(qenv(fn), v104, v66);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[0];
    v67 = v104;
    v104 = v67;
    if (!consp(v104)) goto v80;
    v104 = v67;
    v66 = qcar(v104);
    v104 = elt(env, 1); /* minusp */
    v104 = get(v66, v104);
    v66 = v67;
        popv(1);
        return Lapply1(nil, v104, v66);

v80:
    v104 = v67;
        popv(1);
        return Lminusp(nil, v104);
/* error exit handlers */
v65:
    popv(1);
    return nil;
}



/* Code for get!+row!+nr */

static Lisp_Object CC_getLrowLnr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+row+nr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v42 = v0;
/* end of prologue */
        return Llength(nil, v42);
}



/* Code for qqe_nytidp */

static Lisp_Object CC_qqe_nytidp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v95;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_nytidp");
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
    v59 = v0;
/* end of prologue */
    v95 = v59;
    v59 = elt(env, 1); /* idtype */
    v59 = get(v95, v59);
    v59 = (v59 == nil ? lisp_true : nil);
    return onevalue(v59);
}



/* Code for pasf_smwupdknowl */

static Lisp_Object MS_CDECL CC_pasf_smwupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v94, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v82, v83, v81, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v4;
    v83 = v94;
    v81 = v1;
    v108 = v0;
/* end of prologue */
    v84 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v84 == nil) goto v97;
    v84 = v108;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v84, v81, v83, v82);
    }

v97:
    v84 = v108;
    {
        fn = elt(env, 3); /* cl_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v84, v81, v83, v82);
    }
}



/* Code for ibalp_getupl */

static Lisp_Object CC_ibalp_getupl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getupl");
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
    v79 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v79;
    goto v56;

v56:
    v79 = stack[-1];
    if (v79 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v79 = stack[-1];
    v79 = qcar(v79);
    stack[0] = v79;
    v79 = stack[0];
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcar(v79);
    if (!(v79 == nil)) goto v102;
    v79 = stack[0];
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v110 = qcar(v79);
    v79 = stack[0];
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcar(v79);
    v110 = plus2(v110, v79);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v79 = (Lisp_Object)17; /* 1 */
    v79 = Leqn(nil, v110, v79);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    if (v79 == nil) goto v102;
    v110 = stack[0];
    v79 = stack[-2];
    v79 = cons(v110, v79);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    stack[-2] = v79;
    goto v102;

v102:
    v79 = stack[-1];
    v79 = qcdr(v79);
    stack[-1] = v79;
    goto v56;
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for minus!-mod!-p */

static Lisp_Object CC_minusKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minus-mod-p");
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
    goto v91;

v91:
    v103 = stack[-1];
    if (v103 == nil) goto v56;
    v103 = stack[-1];
    if (!consp(v103)) goto v101;
    v103 = stack[-1];
    v103 = qcar(v103);
    if (!consp(v103)) goto v101;
    v103 = stack[-1];
    v103 = qcar(v103);
    stack[0] = qcar(v103);
    v103 = stack[-1];
    v103 = qcar(v103);
    v103 = qcdr(v103);
    v64 = CC_minusKmodKp(env, v103);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    v103 = stack[-2];
    v103 = acons(stack[0], v64, v103);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    stack[-2] = v103;
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    goto v91;

v101:
    v64 = stack[-2];
    v103 = stack[-1];
    {   int32_t w = int_of_fixnum(v103);
        if (w != 0) w = current_modulus - w;
        v103 = fixnum_of_int(w);
    }
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v64, v103);
    }

v56:
    v103 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v103);
    }
/* error exit handlers */
v78:
    popv(4);
    return nil;
}



/* Code for multi_isarb_int */

static Lisp_Object CC_multi_isarb_int(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
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
    v63 = stack[0];
    v63 = Lconsp(nil, v63);
    env = stack[-1];
    if (v63 == nil) goto v91;
    v63 = stack[0];
    if (v63 == nil) goto v91;
    v63 = stack[0];
    v63 = qcar(v63);
    fn = elt(env, 2); /* isarb_int */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    v63 = stack[0];
    v63 = qcdr(v63);
    v63 = CC_multi_isarb_int(env, v63);
    nil = C_nil;
    if (exception_pending()) goto v97;
    goto v91;

v91:
    v63 = nil;
    { popv(2); return onevalue(v63); }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for depends */

static Lisp_Object CC_depends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v201, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depends");
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
    v200 = stack[-1];
    if (v200 == nil) goto v91;
    v200 = stack[-1];
    if (is_number(v200)) goto v91;
    v200 = stack[0];
    if (is_number(v200)) goto v91;
    v201 = stack[-1];
    v200 = stack[0];
    if (equal(v201, v200)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v200 = stack[-1];
    if (!(!consp(v200))) goto v84;
    v201 = stack[-1];
    v200 = qvalue(elt(env, 2)); /* frlis!* */
    v200 = Lmemq(nil, v201, v200);
    if (v200 == nil) goto v84;
    v200 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v200); }

v84:
    v201 = stack[-1];
    v200 = qvalue(elt(env, 4)); /* depl!* */
    v200 = Lassoc(nil, v201, v200);
    v201 = v200;
    v200 = v201;
    if (v200 == nil) goto v55;
    v200 = v201;
    v201 = qcdr(v200);
    v200 = stack[0];
    fn = elt(env, 7); /* ldepends */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    goto v64;

v64:
    if (v200 == nil) goto v109;
    v200 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v200); }

v109:
    v200 = stack[-1];
    if (!consp(v200)) goto v60;
    v200 = stack[-1];
    v200 = qcar(v200);
    if (!(symbolp(v200))) goto v60;
    v200 = stack[-1];
    v201 = qcar(v200);
    v200 = elt(env, 5); /* dname */
    v200 = get(v201, v200);
    env = stack[-2];
    if (v200 == nil) goto v60;
    v200 = stack[-1];
    v201 = qcar(v200);
    v200 = elt(env, 6); /* domain!-depends!-fn */
    v200 = get(v201, v200);
    env = stack[-2];
    v201 = v200;
    v200 = v201;
    if (v200 == nil) goto v164;
    v158 = v201;
    v201 = stack[-1];
    v200 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v158, v201, v200);

v164:
    v200 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v200); }

v60:
    v200 = stack[-1];
    if (!consp(v200)) goto v203;
    v200 = stack[-1];
    v201 = qcdr(v200);
    v200 = stack[0];
    fn = elt(env, 7); /* ldepends */
    v200 = (*qfn2(fn))(qenv(fn), v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    if (!(v200 == nil)) goto v24;
    v200 = stack[-1];
    v201 = qcar(v200);
    v200 = stack[0];
    v200 = CC_depends(env, v201, v200);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-2];
    if (!(v200 == nil)) goto v24;

v203:
    v200 = stack[0];
    if (!consp(v200)) goto v204;
    v200 = stack[0];
    v200 = qcar(v200);
    if (!(symbolp(v200))) goto v205;
    v200 = stack[0];
    v201 = qcar(v200);
    v200 = elt(env, 5); /* dname */
    v200 = get(v201, v200);
    env = stack[-2];
    if (!(v200 == nil)) goto v204;

v205:
    v200 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v200); }

v204:
    v200 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v200); }

v24:
    v200 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v200); }

v55:
    v200 = qvalue(elt(env, 1)); /* nil */
    goto v64;

v91:
    v200 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v200); }
/* error exit handlers */
v202:
    popv(3);
    return nil;
}



/* Code for dm!-difference */

static Lisp_Object CC_dmKdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-difference");
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
    v43 = v0;
/* end of prologue */
    fn = elt(env, 1); /* zero2nil */
    v105 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-1];
    v43 = stack[0];
    fn = elt(env, 2); /* !:difference */
    v43 = (*qfn2(fn))(qenv(fn), v105, v43);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* nil2zero */
        return (*qfn1(fn))(qenv(fn), v43);
    }
/* error exit handlers */
v206:
    popv(2);
    return nil;
}



/* Code for freexp */

static Lisp_Object CC_freexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freexp");
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

v207:
    v102 = stack[0];
    if (!consp(v102)) goto v70;
    v102 = stack[0];
    v102 = qcar(v102);
    v102 = CC_freexp(env, v102);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    if (!(v102 == nil)) { popv(2); return onevalue(v102); }
    v102 = stack[0];
    v102 = qcdr(v102);
    stack[0] = v102;
    goto v207;

v70:
    v102 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* pm!:free */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for exptchk */

static Lisp_Object CC_exptchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v110, v111;
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
    v79 = stack[0];
    if (!consp(v79)) goto v95;
    v79 = stack[0];
    v79 = qcar(v79);
    if (!consp(v79)) goto v95;
    v110 = stack[0];
    v79 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* comm_kernels1 */
    v79 = (*qfn2(fn))(qenv(fn), v110, v79);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    stack[-1] = v79;
    v79 = stack[-1];
    v110 = Llength(nil, v79);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v79 = (Lisp_Object)33; /* 2 */
    v79 = (Lisp_Object)lessp2(v110, v79);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v79 = v79 ? lisp_true : nil;
    env = stack[-2];
    if (v79 == nil) goto v78;
    v110 = stack[0];
    v79 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v110, v79);

v78:
    v111 = stack[0];
    v110 = qvalue(elt(env, 1)); /* nil */
    v79 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* exptchk0 */
        return (*qfnn(fn))(qenv(fn), 3, v111, v110, v79);
    }

v95:
    v110 = stack[0];
    v79 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v110, v79);
/* error exit handlers */
v62:
    popv(3);
    return nil;
}



/* Code for evcompless!? */

static Lisp_Object CC_evcomplessW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
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
    v38 = v1;
    v37 = v0;
/* end of prologue */
    stack[0] = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* evcomp */
    v37 = (*qfn2(fn))(qenv(fn), v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v101;
    v37 = (stack[0] == v37 ? lisp_true : nil);
    { popv(1); return onevalue(v37); }
/* error exit handlers */
v101:
    popv(1);
    return nil;
}



/* Code for copy_mat */

static Lisp_Object CC_copy_mat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93;
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
    goto v91;

v91:
    v92 = stack[0];
    v92 = Lconsp(nil, v92);
    env = stack[-2];
    if (v92 == nil) goto v97;
    v92 = stack[0];
    v92 = qcar(v92);
    v93 = CC_copy_mat(env, v92);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-2];
    v92 = stack[-1];
    v92 = cons(v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-2];
    stack[-1] = v92;
    v92 = stack[0];
    v92 = qcdr(v92);
    stack[0] = v92;
    goto v91;

v97:
    v93 = stack[-1];
    v92 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v93, v92);
    }
/* error exit handlers */
v189:
    popv(3);
    return nil;
}



/* Code for factorordp */

static Lisp_Object CC_factorordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v172, v97, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factorordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v97 = v1;
    v72 = v0;
/* end of prologue */
    v172 = v72;
    v63 = v97;
    if (v172 == v63) goto v91;
    v63 = v72;
    v172 = v97;
    {
        fn = elt(env, 2); /* worderp */
        return (*qfn2(fn))(qenv(fn), v63, v172);
    }

v91:
    v63 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v63);
}



/* Code for csl_timbf */

static Lisp_Object CC_csl_timbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v54, v68;
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
    v62 = stack[-3];
    v62 = qcdr(v62);
    v54 = qcar(v62);
    v62 = stack[-2];
    v62 = qcdr(v62);
    v62 = qcar(v62);
    v62 = times2(v54, v62);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    v68 = v62;
    v54 = v68;
    v62 = (Lisp_Object)1; /* 0 */
    if (v54 == v62) goto v102;
    v54 = v68;
    v62 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v62 = (*qfn2(fn))(qenv(fn), v54, v62);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    v68 = v62;
    stack[-4] = elt(env, 3); /* !:rd!: */
    v62 = v68;
    stack[-1] = qcar(v62);
    v62 = v68;
    stack[0] = qcdr(v62);
    v62 = stack[-3];
    v62 = qcdr(v62);
    v54 = qcdr(v62);
    v62 = stack[-2];
    v62 = qcdr(v62);
    v62 = qcdr(v62);
    v62 = plus2(v54, v62);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-5];
    v62 = plus2(stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v171;
    {
        Lisp_Object v170 = stack[-4];
        Lisp_Object v208 = stack[-1];
        popv(6);
        return list2star(v170, v208, v62);
    }

v102:
    v62 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(6); return onevalue(v62); }
/* error exit handlers */
v171:
    popv(6);
    return nil;
}



/* Code for i2rd!* */

static Lisp_Object CC_i2rdH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v90;
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
    v101 = v0;
/* end of prologue */
    fn = elt(env, 2); /* chkint!* */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[0];
    v90 = v101;
    v101 = v90;
    if (!(!consp(v101))) { popv(1); return onevalue(v90); }
    v101 = elt(env, 1); /* !:rd!: */
    popv(1);
    return cons(v101, v90);
/* error exit handlers */
v190:
    popv(1);
    return nil;
}



/* Code for hasonephysop */

static Lisp_Object CC_hasonephysop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hasonephysop");
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

v207:
    v38 = stack[0];
    if (v38 == nil) goto v70;
    v38 = stack[0];
    v38 = qcar(v38);
    fn = elt(env, 2); /* physopp!* */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    if (!(v38 == nil)) { popv(2); return onevalue(v38); }
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v207;

v70:
    v38 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v38); }
/* error exit handlers */
v101:
    popv(2);
    return nil;
}



/* Code for getroad */

static Lisp_Object CC_getroad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v82, v83, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getroad");
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
    v83 = v1;
    v81 = v0;
/* end of prologue */

v91:
    v84 = v83;
    if (v84 == nil) goto v56;
    v84 = v81;
    v82 = qcdr(v84);
    v84 = v83;
    v84 = qcar(v84);
    v84 = qcdr(v84);
    if (equal(v82, v84)) goto v63;
    v84 = v83;
    v84 = qcdr(v84);
    v83 = v84;
    goto v91;

v63:
    v84 = v81;
    v84 = qcar(v84);
    v82 = v83;
    v82 = qcar(v82);
    v82 = qcar(v82);
    fn = elt(env, 1); /* qassoc */
    v84 = (*qfn2(fn))(qenv(fn), v84, v82);
    errexit();
    v84 = qcdr(v84);
    return onevalue(v84);

v56:
    v84 = (Lisp_Object)17; /* 1 */
    return onevalue(v84);
}



/* Code for xcomment */

static Lisp_Object CC_xcomment(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v97, v72;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xcomment");
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
    v72 = v1;
    v97 = v0;
/* end of prologue */
    v172 = v72;
    if (v172 == nil) { popv(3); return onevalue(v97); }
    stack[-1] = elt(env, 1); /* comment */
    v172 = v72;
    stack[0] = Lnreverse(nil, v172);
    env = stack[-2];
    v172 = v97;
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v172 = Lnconc(nil, stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-2];
    v172 = cons(stack[-1], v172);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v97 = v172;
    { popv(3); return onevalue(v97); }
/* error exit handlers */
v45:
    popv(3);
    return nil;
}



/* Code for arraychk */

static Lisp_Object CC_arraychk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arraychk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v0;
/* end of prologue */
    if (v59 == nil) goto v70;
    v59 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v59);

v70:
    v59 = elt(env, 1); /* array */
    return onevalue(v59);
}



/* Code for fs!:angle!-order */

static Lisp_Object CC_fsTangleKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v218, v166;
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
    v217 = (Lisp_Object)1; /* 0 */
    stack[-4] = v217;
    v218 = stack[-3];
    v217 = (Lisp_Object)33; /* 2 */
    v217 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    stack[-1] = v217;
    v218 = stack[-2];
    v217 = (Lisp_Object)33; /* 2 */
    v217 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    stack[0] = v217;
    goto v89;

v89:
    v218 = stack[-1];
    v217 = stack[-4];
    v166 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v218 = stack[0];
    v217 = stack[-4];
    v217 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = difference2(v166, v217);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    v166 = v217;
    v218 = v166;
    v217 = (Lisp_Object)1; /* 0 */
    if (v218 == v217) goto v64;
    v218 = v166;
    v217 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v218, v217);

v64:
    v217 = stack[-4];
    v217 = add1(v217);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-5];
    stack[-4] = v217;
    v218 = stack[-4];
    v217 = (Lisp_Object)129; /* 8 */
    v217 = (Lisp_Object)lessp2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v191;
    v217 = v217 ? lisp_true : nil;
    env = stack[-5];
    if (!(v217 == nil)) goto v89;
    v218 = stack[-3];
    v217 = (Lisp_Object)17; /* 1 */
    v166 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v218 = stack[-2];
    v217 = (Lisp_Object)17; /* 1 */
    v217 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    if (equal(v166, v217)) goto v188;
    v218 = stack[-3];
    v217 = (Lisp_Object)17; /* 1 */
    v218 = *(Lisp_Object *)((char *)v218 + (CELL-TAG_VECTOR) + ((int32_t)v217/(16/CELL)));
    v217 = elt(env, 2); /* sin */
    if (v218 == v217) goto v195;
    v217 = qvalue(elt(env, 3)); /* t */
    { popv(6); return onevalue(v217); }

v195:
    v217 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v217); }

v188:
    v217 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v217); }
/* error exit handlers */
v191:
    popv(6);
    return nil;
}



/* Code for mo!=degcomp */

static Lisp_Object CC_moMdegcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v81, v108, v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=degcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v1;
    v108 = v0;
/* end of prologue */

v91:
    v83 = v108;
    if (v83 == nil) goto v56;
    v83 = v108;
    v99 = qcar(v83);
    v83 = v81;
    v83 = qcar(v83);
    if (equal(v99, v83)) goto v95;
    v83 = v108;
    v83 = qcar(v83);
    v81 = qcar(v81);
    if (((int32_t)(v83)) < ((int32_t)(v81))) goto v97;
    v83 = (Lisp_Object)17; /* 1 */
    return onevalue(v83);

v97:
    v83 = (Lisp_Object)-15; /* -1 */
    return onevalue(v83);

v95:
    v83 = v108;
    v83 = qcdr(v83);
    v108 = v83;
    v83 = v81;
    v83 = qcdr(v83);
    v81 = v83;
    goto v91;

v56:
    v83 = (Lisp_Object)1; /* 0 */
    return onevalue(v83);
}



/* Code for prin2!* */

static Lisp_Object CC_prin2H(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v229, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2*");
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
    v228 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v228 == nil) goto v92;
    v229 = qvalue(elt(env, 1)); /* outputhandler!* */
    v2 = elt(env, 0); /* prin2!* */
    v228 = stack[-2];
        popv(5);
        return Lapply2(nil, 3, v229, v2, v228);

v92:
    v229 = stack[-2];
    v228 = elt(env, 2); /* oldnam */
    v228 = get(v229, v228);
    env = stack[-4];
    v229 = v228;
    if (v228 == nil) goto v36;
    v228 = v229;
    stack[-2] = v228;
    goto v36;

v36:
    v228 = qvalue(elt(env, 3)); /* overflowed!* */
    if (v228 == nil) goto v99;
    v228 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v228); }

v99:
    v228 = qvalue(elt(env, 5)); /* !*fort */
    if (v228 == nil) goto v103;
    v228 = stack[-2];
    {
        popv(5);
        fn = elt(env, 18); /* fprin2!* */
        return (*qfn1(fn))(qenv(fn), v228);
    }

v103:
    v228 = qvalue(elt(env, 6)); /* !*nat */
    if (v228 == nil) goto v81;
    v229 = stack[-2];
    v228 = elt(env, 7); /* pi */
    if (v229 == v228) goto v65;
    v229 = stack[-2];
    v228 = elt(env, 9); /* infinity */
    if (!(v229 == v228)) goto v81;
    v228 = elt(env, 9); /* infinity */
    fn = elt(env, 19); /* symbol */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    stack[-2] = v228;
    goto v81;

v81:
    v228 = stack[-2];
    v228 = Llengthc(nil, v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    stack[-1] = v228;
    v228 = stack[-2];
    v228 = integerp(v228);
    if (v228 == nil) goto v160;
    v229 = stack[-1];
    v228 = (Lisp_Object)801; /* 50 */
    v228 = (Lisp_Object)greaterp2(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    v228 = v228 ? lisp_true : nil;
    env = stack[-4];
    if (v228 == nil) goto v160;
    v228 = qvalue(elt(env, 10)); /* !*rounded */
    if (v228 == nil) goto v160;
    v228 = stack[-2];
    fn = elt(env, 20); /* chkint!* */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v229 = v228;
    if (!(!consp(v229))) goto v213;
    v229 = elt(env, 11); /* !:rd!: */
    v228 = cons(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    goto v213;

v213:
    v229 = v228;
    v228 = v229;
    v228 = qcdr(v228);
    if (!consp(v228)) goto v166;
    v228 = v229;
    stack[0] = v228;
    goto v230;

v230:
    v229 = qvalue(elt(env, 12)); /* !:bprec!: */
    v228 = (Lisp_Object)49; /* 3 */
    v228 = difference2(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    fn = elt(env, 21); /* round!:mt */
    v228 = (*qfn2(fn))(qenv(fn), stack[0], v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    fn = elt(env, 22); /* csl_normbf */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 23); /* bfprin0 */
        return (*qfn1(fn))(qenv(fn), v228);
    }

v166:
    v228 = v229;
    v228 = qcdr(v228);
    fn = elt(env, 24); /* fl2bf */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    stack[0] = v228;
    goto v230;

v160:
    v229 = qvalue(elt(env, 13)); /* posn!* */
    v228 = stack[-1];
    v228 = (Lisp_Object)(int32_t)((int32_t)v229 + (int32_t)v228 - TAG_FIXNUM);
    stack[-3] = v228;
    v228 = qvalue(elt(env, 14)); /* nil */
    v229 = Llinelength(nil, v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    v228 = qvalue(elt(env, 15)); /* spare!* */
    v228 = difference2(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    stack[0] = v228;
    v229 = stack[-3];
    v228 = stack[0];
    v228 = (Lisp_Object)lesseq2(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    v228 = v228 ? lisp_true : nil;
    env = stack[-4];
    if (!(v228 == nil)) goto v231;
    v228 = qvalue(elt(env, 16)); /* testing!-width!* */
    if (!(v228 == nil)) goto v232;
    v228 = stack[-2];
    v228 = integerp(v228);
    if (!(v228 == nil)) goto v179;
    v228 = qvalue(elt(env, 17)); /* t */
    fn = elt(env, 25); /* terpri!* */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    goto v179;

v179:
    v229 = qvalue(elt(env, 13)); /* posn!* */
    v228 = stack[-1];
    v229 = (Lisp_Object)(int32_t)((int32_t)v229 + (int32_t)v228 - TAG_FIXNUM);
    stack[-3] = v229;
    v228 = stack[0];
    v228 = (Lisp_Object)lesseq2(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    v228 = v228 ? lisp_true : nil;
    env = stack[-4];
    if (!(v228 == nil)) goto v231;

v232:
    v228 = qvalue(elt(env, 16)); /* testing!-width!* */
    if (v228 == nil) goto v147;
    v228 = qvalue(elt(env, 17)); /* t */
    qvalue(elt(env, 3)) = v228; /* overflowed!* */
    v228 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v228); }

v147:
    v2 = stack[-2];
    v228 = qvalue(elt(env, 13)); /* posn!* */
    v229 = (Lisp_Object)((int32_t)(v228) + 0x10);
    v228 = stack[0];
    v228 = (Lisp_Object)((int32_t)(v228) - 0x10);
    {
        popv(5);
        fn = elt(env, 26); /* prin2lint */
        return (*qfnn(fn))(qenv(fn), 3, v2, v229, v228);
    }

v231:
    v229 = stack[-2];
    v228 = stack[-3];
    {
        popv(5);
        fn = elt(env, 27); /* add_prin_char */
        return (*qfn2(fn))(qenv(fn), v229, v228);
    }

v65:
    v228 = elt(env, 8); /* !.pi */
    fn = elt(env, 19); /* symbol */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    stack[-2] = v228;
    goto v81;
/* error exit handlers */
v40:
    popv(5);
    return nil;
}



/* Code for pkp */

static Lisp_Object CC_pkp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v236, v23;
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
    v235 = stack[0];
    if (!consp(v235)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v235 = qvalue(elt(env, 1)); /* !*ppacked */
    if (v235 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v235 = stack[0];
    v236 = Llength(nil, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    v235 = (Lisp_Object)161; /* 10 */
    v235 = (Lisp_Object)geq2(v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    v235 = v235 ? lisp_true : nil;
    env = stack[-4];
    stack[-2] = v235;
    v235 = stack[0];
    stack[-1] = v235;
    goto v72;

v72:
    v235 = stack[-1];
    if (v235 == nil) goto v97;
    v235 = stack[-1];
    v235 = qcar(v235);
    stack[0] = v235;
    v235 = stack[-2];
    if (v235 == nil) goto v166;
    v236 = stack[0];
    v235 = (Lisp_Object)161; /* 10 */
    v235 = (Lisp_Object)lessp2(v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    v235 = v235 ? lisp_true : nil;
    env = stack[-4];
    if (v235 == nil) goto v170;
    v236 = stack[0];
    v235 = qvalue(elt(env, 3)); /* diglist!* */
    fn = elt(env, 5); /* dssoc */
    v235 = (*qfn2(fn))(qenv(fn), v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    v23 = qcar(v235);
    v236 = elt(env, 4); /* !0 */
    v235 = stack[-3];
    v235 = list2star(v23, v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    stack[-3] = v235;
    goto v84;

v84:
    v235 = stack[-1];
    v235 = qcdr(v235);
    stack[-1] = v235;
    goto v72;

v170:
    v236 = stack[0];
    v235 = (Lisp_Object)161; /* 10 */
    v235 = Ldivide(nil, v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    stack[0] = v235;
    v235 = stack[0];
    v236 = qcar(v235);
    v235 = qvalue(elt(env, 3)); /* diglist!* */
    fn = elt(env, 5); /* dssoc */
    v235 = (*qfn2(fn))(qenv(fn), v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    v236 = qcar(v235);
    v235 = stack[-3];
    v235 = cons(v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    stack[-3] = v235;
    v235 = stack[0];
    v236 = qcdr(v235);
    v235 = qvalue(elt(env, 3)); /* diglist!* */
    fn = elt(env, 5); /* dssoc */
    v235 = (*qfn2(fn))(qenv(fn), v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    v236 = qcar(v235);
    v235 = stack[-3];
    v235 = cons(v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    stack[-3] = v235;
    goto v84;

v166:
    v236 = stack[0];
    v235 = qvalue(elt(env, 3)); /* diglist!* */
    fn = elt(env, 5); /* dssoc */
    v235 = (*qfn2(fn))(qenv(fn), v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    v236 = qcar(v235);
    v235 = stack[-3];
    v235 = cons(v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    stack[-3] = v235;
    goto v84;

v97:
    v235 = stack[-3];
    v235 = Lnreverse(nil, v235);
        popv(5);
        return Lcompress(nil, v235);
/* error exit handlers */
v237:
    popv(5);
    return nil;
}



/* Code for copy */

static Lisp_Object CC_copy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v92;
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
    goto v91;

v91:
    v89 = stack[0];
    if (!consp(v89)) goto v95;
    v89 = stack[0];
    v89 = qcar(v89);
    v92 = CC_copy(env, v89);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v89 = stack[-1];
    v89 = cons(v92, v89);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    stack[-1] = v89;
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v91;

v95:
    v92 = stack[-1];
    v89 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v92, v89);
    }
/* error exit handlers */
v96:
    popv(3);
    return nil;
}



/* Code for times!-term!-mod!-p */

static Lisp_Object CC_timesKtermKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v13, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-term-mod-p");
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
    v232 = stack[-1];
    if (v232 == nil) goto v91;
    v232 = stack[-1];
    if (!consp(v232)) goto v85;
    v232 = stack[-1];
    v232 = qcar(v232);
    if (!consp(v232)) goto v85;
    v232 = stack[-2];
    v232 = qcar(v232);
    v13 = qcar(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcar(v232);
    if (equal(v13, v232)) goto v33;
    v232 = stack[-2];
    v232 = qcar(v232);
    v13 = qcar(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcar(v232);
    fn = elt(env, 2); /* ordop */
    v232 = (*qfn2(fn))(qenv(fn), v13, v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    if (v232 == nil) goto v204;
    v232 = stack[-2];
    stack[0] = qcar(v232);
    v232 = stack[-2];
    v13 = qcdr(v232);
    v232 = stack[-1];
    fn = elt(env, 3); /* times!-mod!-p */
    v13 = (*qfn2(fn))(qenv(fn), v13, v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    v232 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v221 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v221, v13, v232);
    }

v204:
    v232 = stack[-1];
    v232 = qcar(v232);
    stack[-3] = qcar(v232);
    v13 = stack[-2];
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcdr(v232);
    stack[0] = CC_timesKtermKmodKp(env, v13, v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    v13 = stack[-2];
    v232 = stack[-1];
    v232 = qcdr(v232);
    v232 = CC_timesKtermKmodKp(env, v13, v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    {
        Lisp_Object v222 = stack[-3];
        Lisp_Object v245 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v222, v245, v232);
    }

v33:
    v232 = stack[-2];
    v232 = qcar(v232);
    v232 = qcar(v232);
    fn = elt(env, 5); /* fkern */
    v243 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    v232 = stack[-2];
    v232 = qcar(v232);
    v13 = qcdr(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = qcdr(v232);
    v232 = (Lisp_Object)(int32_t)((int32_t)v13 + (int32_t)v232 - TAG_FIXNUM);
    fn = elt(env, 6); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v243, v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    v232 = stack[-2];
    v13 = qcdr(v232);
    v232 = stack[-1];
    v232 = qcar(v232);
    v232 = qcdr(v232);
    fn = elt(env, 3); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v13, v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    v13 = stack[-2];
    v232 = stack[-1];
    v232 = qcdr(v232);
    v232 = CC_timesKtermKmodKp(env, v13, v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    {
        Lisp_Object v246 = stack[-3];
        Lisp_Object v247 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v246, v247, v232);
    }

v85:
    v232 = stack[-2];
    stack[0] = qcar(v232);
    v232 = stack[-2];
    v13 = qcdr(v232);
    v232 = stack[-1];
    fn = elt(env, 7); /* multiply!-by!-constant!-mod!-p */
    v13 = (*qfn2(fn))(qenv(fn), v13, v232);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-4];
    v232 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v248 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v248, v13, v232);
    }

v91:
    v232 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v232); }
/* error exit handlers */
v244:
    popv(5);
    return nil;
}



/* Code for setcdr */

static Lisp_Object CC_setcdr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v43;
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
    v95 = v0;
/* end of prologue */
    v43 = v95;
    v95 = stack[0];
    v95 = Lrplacd(nil, v43, v95);
    nil = C_nil;
    if (exception_pending()) goto v112;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v112:
    popv(1);
    return nil;
}



/* Code for symbollessp */

static Lisp_Object CC_symbollessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v187, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbollessp");
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
    v187 = v1;
    v96 = v0;
/* end of prologue */
    v93 = v187;
    if (v93 == nil) goto v91;
    v93 = v96;
    if (v93 == nil) goto v57;
    v93 = qvalue(elt(env, 3)); /* wukord!* */
    if (v93 == nil) goto v97;
    v93 = v96;
    {
        fn = elt(env, 4); /* wuorderp */
        return (*qfn2(fn))(qenv(fn), v93, v187);
    }

v97:
    v93 = v96;
    v93 = Lorderp(nil, v93, v187);
    errexit();
    v93 = (v93 == nil ? lisp_true : nil);
    return onevalue(v93);

v57:
    v93 = qvalue(elt(env, 2)); /* t */
    return onevalue(v93);

v91:
    v93 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v93);
}



/* Code for quotf1 */

static Lisp_Object CC_quotf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v262, v263;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf1");
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
    v262 = stack[-7];
    if (v262 == nil) goto v91;
    v263 = stack[-7];
    v262 = stack[-6];
    if (equal(v263, v262)) goto v57;
    v263 = stack[-6];
    v262 = (Lisp_Object)17; /* 1 */
    if (v263 == v262) { Lisp_Object res = stack[-7]; popv(10); return onevalue(res); }
    v262 = stack[-6];
    if (!consp(v262)) goto v96;
    v262 = stack[-6];
    v262 = qcar(v262);
    if (!consp(v262)) goto v96;
    v262 = stack[-7];
    if (!consp(v262)) goto v108;
    v262 = stack[-7];
    v262 = qcar(v262);
    if (!consp(v262)) goto v108;
    v262 = stack[-7];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v263 = qcar(v262);
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v262 = qcar(v262);
    if (v263 == v262) goto v106;
    v262 = stack[-7];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v263 = qcar(v262);
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v262 = qcar(v262);
    fn = elt(env, 3); /* ordop */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    if (v262 == nil) goto v124;
    v263 = stack[-7];
    v262 = stack[-6];
    {
        popv(10);
        fn = elt(env, 4); /* quotk */
        return (*qfn2(fn))(qenv(fn), v263, v262);
    }

v124:
    v262 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v262); }

v106:
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v170;

v170:
    v262 = stack[-7];
    fn = elt(env, 5); /* rank */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[-4] = v262;
    if (symbolp(v262)) goto v29;
    v262 = stack[-6];
    fn = elt(env, 5); /* rank */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[0] = v262;
    if (symbolp(v262)) goto v29;
    v263 = stack[-4];
    v262 = stack[0];
    v262 = (Lisp_Object)lessp2(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    v262 = v262 ? lisp_true : nil;
    env = stack[-9];
    if (!(v262 == nil)) goto v29;
    v262 = stack[-7];
    fn = elt(env, 6); /* lt!* */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[-4] = v262;
    v262 = stack[-6];
    fn = elt(env, 6); /* lt!* */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[0] = v262;
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v262 = qcar(v262);
    stack[-8] = v262;
    v262 = stack[-4];
    v263 = qcdr(v262);
    v262 = stack[0];
    v262 = qcdr(v262);
    v262 = CC_quotf1(env, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[-5] = v262;
    v262 = stack[-5];
    if (v262 == nil) goto v210;
    v262 = stack[-4];
    v262 = qcar(v262);
    v263 = qcdr(v262);
    v262 = stack[0];
    v262 = qcar(v262);
    v262 = qcdr(v262);
    v262 = difference2(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[0] = v262;
    v263 = stack[0];
    v262 = (Lisp_Object)1; /* 0 */
    if (v263 == v262) goto v265;
    v263 = stack[-8];
    v262 = stack[0];
    v262 = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[-3] = v262;
    goto v265;

v265:
    v262 = stack[-5];
    fn = elt(env, 7); /* negf */
    v263 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    v262 = stack[-6];
    v262 = qcdr(v262);
    fn = elt(env, 8); /* multf */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[-4] = v262;
    v262 = stack[-7];
    stack[-7] = qcdr(v262);
    v263 = stack[0];
    v262 = (Lisp_Object)1; /* 0 */
    if (v263 == v262) goto v221;
    v263 = stack[-3];
    v262 = (Lisp_Object)17; /* 1 */
    v262 = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    v263 = ncons(v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    v262 = stack[-4];
    fn = elt(env, 8); /* multf */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    goto v243;

v243:
    fn = elt(env, 9); /* addf */
    v262 = (*qfn2(fn))(qenv(fn), stack[-7], v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[-7] = v262;
    v262 = stack[-7];
    if (v262 == nil) goto v219;
    v262 = stack[-7];
    if (!consp(v262)) goto v151;
    v262 = stack[-7];
    v262 = qcar(v262);
    if (!consp(v262)) goto v151;
    v262 = stack[-7];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v263 = qcar(v262);
    v262 = stack[-8];
    if (!(v263 == v262)) goto v151;

v219:
    v263 = stack[0];
    v262 = (Lisp_Object)1; /* 0 */
    if (v263 == v262) goto v208;
    stack[0] = stack[-2];
    v263 = stack[-3];
    v262 = stack[-5];
    v262 = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    v262 = ncons(v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    v262 = Lnconc(nil, stack[0], v262);
    nil = C_nil;
    if (exception_pending()) goto v264;
    env = stack[-9];
    stack[-2] = v262;
    v262 = stack[-7];
    if (!(v262 == nil)) goto v170;
    v262 = stack[-1];
    if (v262 == nil) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    v263 = stack[-2];
    v262 = stack[-1];
    {
        popv(10);
        fn = elt(env, 10); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v263, v262);
    }

v208:
    v262 = stack[-7];
    if (v262 == nil) goto v266;
    v262 = qvalue(elt(env, 2)); /* !*mcd */
    if (v262 == nil) goto v267;
    v262 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v262); }

v267:
    v262 = stack[-5];
    stack[-1] = v262;
    goto v170;

v266:
    v263 = stack[-2];
    v262 = stack[-5];
    {
        popv(10);
        fn = elt(env, 10); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v263, v262);
    }

v151:
    v262 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v262); }

v221:
    v262 = stack[-4];
    goto v243;

v210:
    v262 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v262); }

v29:
    v262 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v262); }

v108:
    v262 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v262); }

v96:
    v263 = stack[-7];
    v262 = stack[-6];
    {
        popv(10);
        fn = elt(env, 11); /* quotfd */
        return (*qfn2(fn))(qenv(fn), v263, v262);
    }

v57:
    v262 = (Lisp_Object)17; /* 1 */
    { popv(10); return onevalue(v262); }

v91:
    v262 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v262); }
/* error exit handlers */
v264:
    popv(10);
    return nil;
}



/* Code for mcharg2 */

static Lisp_Object MS_CDECL CC_mcharg2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v94, Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v192, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mcharg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg2");
#endif
    if (stack >= stacklimit)
    {
        push4(v4,v94,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v94,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-6] = v4;
    stack[-7] = v94;
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    v191 = stack[-9];
    if (v191 == nil) { Lisp_Object res = stack[-7]; popv(12); return onevalue(res); }
    v191 = stack[-9];
    v192 = qcar(v191);
    v191 = stack[-8];
    v191 = qcar(v191);
    fn = elt(env, 2); /* mchk */
    v191 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    v192 = v191;
    v191 = stack[-9];
    v191 = qcdr(v191);
    stack[-9] = v191;
    v191 = stack[-8];
    v191 = qcdr(v191);
    stack[-8] = v191;
    v191 = v192;
    stack[-10] = v191;
    goto v89;

v89:
    v191 = stack[-10];
    if (v191 == nil) goto v189;
    v191 = stack[-10];
    v191 = qcar(v191);
    stack[-2] = v191;
    stack[-1] = stack[-9];
    v233 = stack[-2];
    v192 = stack[-8];
    v191 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v233, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    v192 = stack[-7];
    v191 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v192 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    v191 = stack[-6];
    v191 = CC_mcharg2(env, 4, stack[-1], stack[0], v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    stack[-5] = v191;
    v191 = stack[-5];
    fn = elt(env, 5); /* lastpair */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    stack[-4] = v191;
    v191 = stack[-10];
    v191 = qcdr(v191);
    stack[-10] = v191;
    v191 = stack[-4];
    if (!consp(v191)) goto v89;
    else goto v92;

v92:
    v191 = stack[-10];
    if (v191 == nil) { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v191 = stack[-10];
    v191 = qcar(v191);
    stack[-2] = v191;
    stack[-1] = stack[-9];
    v233 = stack[-2];
    v192 = stack[-8];
    v191 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v233, v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    v192 = stack[-7];
    v191 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v192 = (*qfn2(fn))(qenv(fn), v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    v191 = stack[-6];
    v191 = CC_mcharg2(env, 4, stack[-1], stack[0], v192, v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    v191 = Lrplacd(nil, stack[-3], v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    v191 = stack[-4];
    fn = elt(env, 5); /* lastpair */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-11];
    stack[-4] = v191;
    v191 = stack[-10];
    v191 = qcdr(v191);
    stack[-10] = v191;
    goto v92;

v189:
    v191 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v191); }
/* error exit handlers */
v269:
    popv(12);
    return nil;
}



/* Code for get!+vec!+entry */

static Lisp_Object CC_getLvecLentry(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+vec+entry");
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
    v105 = v1;
    v112 = v0;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v105 = (*qfn2(fn))(qenv(fn), v112, v105);
    errexit();
    v105 = qcar(v105);
    return onevalue(v105);
}



/* Code for qqe_btidp */

static Lisp_Object CC_qqe_btidp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_btidp");
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
    v85 = v0;
/* end of prologue */
    v37 = v85;
    v85 = elt(env, 1); /* idtype */
    v85 = get(v37, v85);
    env = stack[0];
    v37 = elt(env, 2); /* bt */
    v85 = (v85 == v37 ? lisp_true : nil);
    { popv(1); return onevalue(v85); }
}



/* Code for ibalp_minclnr */

static Lisp_Object CC_ibalp_minclnr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v74;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_minclnr");
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
    v74 = v0;
/* end of prologue */
    v77 = (Lisp_Object)1600001; /* 100000 */
    stack[-2] = v77;
    v77 = v74;
    stack[-1] = v77;
    goto v57;

v57:
    v77 = stack[-1];
    if (v77 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v77 = stack[-1];
    v77 = qcar(v77);
    stack[0] = v77;
    v77 = stack[0];
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcar(v77);
    if (!(v77 == nil)) goto v101;
    v77 = stack[0];
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v74 = qcar(v77);
    v77 = stack[0];
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcar(v77);
    v74 = plus2(v74, v77);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-3];
    v77 = stack[-2];
    v77 = (Lisp_Object)lessp2(v74, v77);
    nil = C_nil;
    if (exception_pending()) goto v208;
    v77 = v77 ? lisp_true : nil;
    env = stack[-3];
    if (v77 == nil) goto v101;
    v77 = stack[0];
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v74 = qcar(v77);
    v77 = stack[0];
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcdr(v77);
    v77 = qcar(v77);
    v77 = plus2(v74, v77);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-3];
    stack[-2] = v77;
    goto v101;

v101:
    v77 = stack[-1];
    v77 = qcdr(v77);
    stack[-1] = v77;
    goto v57;
/* error exit handlers */
v208:
    popv(4);
    return nil;
}



/* Code for get_content */

static Lisp_Object MS_CDECL CC_get_content(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "get_content");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_content");
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
    v77 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v77;
    goto v43;

v43:
    v74 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-1];
    qvalue(elt(env, 2)) = v74; /* ch */
    v77 = elt(env, 3); /* !< */
    if (v74 == v77) goto v42;
    v74 = qvalue(elt(env, 2)); /* ch */
    v77 = qvalue(elt(env, 4)); /* !$eof!$ */
    if (equal(v74, v77)) goto v42;
    v74 = qvalue(elt(env, 2)); /* ch */
    v77 = qvalue(elt(env, 5)); /* space */
    if (equal(v74, v77)) goto v43;
    v77 = qvalue(elt(env, 2)); /* ch */
    fn = elt(env, 7); /* explode2n */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-1];
    v74 = qcar(v77);
    v77 = (Lisp_Object)161; /* 10 */
    v77 = (Lisp_Object)greaterp2(v74, v77);
    nil = C_nil;
    if (exception_pending()) goto v171;
    v77 = v77 ? lisp_true : nil;
    env = stack[-1];
    if (v77 == nil) goto v43;
    v74 = qvalue(elt(env, 2)); /* ch */
    v77 = stack[0];
    v77 = cons(v74, v77);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-1];
    stack[0] = v77;
    goto v43;

v42:
    v77 = stack[0];
    if (v77 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v74 = elt(env, 6); /* !$ */
    v77 = stack[0];
    v77 = cons(v74, v77);
    nil = C_nil;
    if (exception_pending()) goto v171;
    stack[0] = v77;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v171:
    popv(2);
    return nil;
}



/* Code for mcharg1 */

static Lisp_Object MS_CDECL CC_mcharg1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v94, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v178, v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mcharg1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg1");
#endif
    if (stack >= stacklimit)
    {
        push3(v94,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v94);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v94;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v202 = stack[-3];
    if (!(v202 == nil)) goto v105;
    v202 = stack[-2];
    if (!(v202 == nil)) goto v105;
    v202 = qvalue(elt(env, 1)); /* nil */
    popv(6);
    return ncons(v202);

v105:
    v202 = stack[-3];
    v202 = Llength(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[-4] = v202;
    v202 = stack[-2];
    v202 = Llength(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[0] = v202;
    v178 = stack[-1];
    v202 = elt(env, 2); /* nary */
    v202 = Lflagp(nil, v178, v202);
    env = stack[-5];
    if (v202 == nil) goto v196;
    v178 = stack[-4];
    v202 = (Lisp_Object)33; /* 2 */
    v202 = (Lisp_Object)greaterp2(v178, v202);
    nil = C_nil;
    if (exception_pending()) goto v257;
    v202 = v202 ? lisp_true : nil;
    env = stack[-5];
    if (v202 == nil) goto v196;
    v178 = stack[-4];
    v202 = qvalue(elt(env, 3)); /* matchlength!* */
    v202 = (Lisp_Object)lesseq2(v178, v202);
    nil = C_nil;
    if (exception_pending()) goto v257;
    v202 = v202 ? lisp_true : nil;
    env = stack[-5];
    if (v202 == nil) goto v29;
    v178 = stack[-1];
    v202 = elt(env, 4); /* symmetric */
    v202 = Lflagp(nil, v178, v202);
    env = stack[-5];
    if (v202 == nil) goto v29;
    v232 = stack[-3];
    v178 = stack[-2];
    v202 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); /* mchcomb */
        return (*qfnn(fn))(qenv(fn), 3, v232, v178, v202);
    }

v29:
    v178 = stack[0];
    v202 = (Lisp_Object)33; /* 2 */
    if (v178 == v202) goto v198;
    v202 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v202); }

v198:
    v178 = stack[-1];
    v202 = stack[-3];
    fn = elt(env, 6); /* mkbin */
    v202 = (*qfn2(fn))(qenv(fn), v178, v202);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    v202 = qcdr(v202);
    stack[-3] = v202;
    v202 = (Lisp_Object)33; /* 2 */
    stack[-4] = v202;
    goto v196;

v196:
    v178 = stack[-4];
    v202 = stack[0];
    if (equal(v178, v202)) goto v47;
    v202 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v202); }

v47:
    v178 = stack[-1];
    v202 = elt(env, 4); /* symmetric */
    v202 = Lflagp(nil, v178, v202);
    env = stack[-5];
    if (v202 == nil) goto v25;
    v232 = stack[-3];
    v178 = stack[-2];
    v202 = stack[-1];
    {
        popv(6);
        fn = elt(env, 7); /* mchsarg */
        return (*qfnn(fn))(qenv(fn), 3, v232, v178, v202);
    }

v25:
    v202 = stack[-2];
    fn = elt(env, 8); /* mtp */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    if (v202 == nil) goto v271;
    v178 = stack[-2];
    v202 = stack[-3];
    fn = elt(env, 9); /* pair */
    v202 = (*qfn2(fn))(qenv(fn), v178, v202);
    nil = C_nil;
    if (exception_pending()) goto v257;
    popv(6);
    return ncons(v202);

v271:
    stack[0] = stack[-3];
    v202 = qvalue(elt(env, 1)); /* nil */
    v178 = ncons(v202);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    v202 = stack[-1];
    {
        Lisp_Object v244 = stack[0];
        Lisp_Object v221 = stack[-2];
        popv(6);
        fn = elt(env, 10); /* mcharg2 */
        return (*qfnn(fn))(qenv(fn), 4, v244, v221, v178, v202);
    }
/* error exit handlers */
v257:
    popv(6);
    return nil;
}



/* Code for subs2!* */

static Lisp_Object CC_subs2H(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2*");
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
    v107 = v0;
/* end of prologue */
    v42 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[0] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v42; /* !*sub2 */
    v42 = v107;
    fn = elt(env, 2); /* subs2 */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*sub2 */
    { popv(2); return onevalue(v42); }
/* error exit handlers */
v57:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*sub2 */
    popv(2);
    return nil;
}



/* Code for peel */

static Lisp_Object CC_peel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v186;
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
    v34 = stack[0];
    v186 = qcar(v34);
    v34 = elt(env, 1); /* (liedf innerprod) */
    v34 = Lmemq(nil, v186, v34);
    if (v34 == nil) goto v101;
    v34 = stack[0];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    { popv(1); return onevalue(v34); }

v101:
    v34 = stack[0];
    v186 = qcar(v34);
    v34 = elt(env, 2); /* quotient */
    if (v186 == v34) goto v92;
    v34 = stack[0];
    v34 = qcdr(v34);
    v34 = qcar(v34);
    { popv(1); return onevalue(v34); }

v92:
    v34 = stack[0];
    v34 = qcdr(v34);
    v186 = qcar(v34);
    v34 = stack[0];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    fn = elt(env, 3); /* worderp */
    v34 = (*qfn2(fn))(qenv(fn), v186, v34);
    nil = C_nil;
    if (exception_pending()) goto v31;
    if (v34 == nil) goto v103;
    v34 = stack[0];
    v34 = qcdr(v34);
    v34 = qcar(v34);
    { popv(1); return onevalue(v34); }

v103:
    v34 = stack[0];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    { popv(1); return onevalue(v34); }
/* error exit handlers */
v31:
    popv(1);
    return nil;
}



/* Code for smemql */

static Lisp_Object CC_smemql(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemql");
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
    goto v42;

v42:
    v84 = stack[-1];
    if (v84 == nil) goto v57;
    v84 = stack[-1];
    v82 = qcar(v84);
    v84 = stack[0];
    v84 = Lsmemq(nil, v82, v84);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    if (v84 == nil) goto v187;
    v84 = stack[-1];
    v82 = qcar(v84);
    v84 = stack[-2];
    v84 = cons(v82, v84);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[-2] = v84;
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v42;

v187:
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v42;

v57:
    v84 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v84);
    }
/* error exit handlers */
v99:
    popv(4);
    return nil;
}



/* Code for putpline */

static Lisp_Object CC_putpline(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211, v196, v195;
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
    v196 = qvalue(elt(env, 1)); /* posn!* */
    v211 = stack[0];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    stack[-1] = (Lisp_Object)(int32_t)((int32_t)v196 + (int32_t)v211 - TAG_FIXNUM);
    v211 = qvalue(elt(env, 2)); /* nil */
    v196 = Llinelength(nil, v211);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v211 = qvalue(elt(env, 3)); /* spare!* */
    v211 = (Lisp_Object)(int32_t)((int32_t)v196 - (int32_t)v211 + TAG_FIXNUM);
    v211 = (Lisp_Object)greaterp2(stack[-1], v211);
    nil = C_nil;
    if (exception_pending()) goto v163;
    v211 = v211 ? lisp_true : nil;
    env = stack[-2];
    if (v211 == nil) goto v103;
    v211 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 10); /* terpri!* */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    goto v103;

v103:
    v196 = qvalue(elt(env, 1)); /* posn!* */
    v211 = qvalue(elt(env, 5)); /* orig!* */
    v195 = (Lisp_Object)(int32_t)((int32_t)v196 - (int32_t)v211 + TAG_FIXNUM);
    v196 = qvalue(elt(env, 6)); /* ycoord!* */
    v211 = stack[0];
    v211 = qcar(v211);
    v211 = qcar(v211);
    fn = elt(env, 11); /* update!-pline */
    v196 = (*qfnn(fn))(qenv(fn), 3, v195, v196, v211);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v211 = qvalue(elt(env, 7)); /* pline!* */
    v211 = Lappend(nil, v196, v211);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    qvalue(elt(env, 7)) = v211; /* pline!* */
    v196 = qvalue(elt(env, 1)); /* posn!* */
    v211 = stack[0];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = (Lisp_Object)(int32_t)((int32_t)v196 + (int32_t)v211 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v211; /* posn!* */
    v195 = qvalue(elt(env, 8)); /* ymin!* */
    v211 = stack[0];
    v211 = qcdr(v211);
    v196 = qcar(v211);
    v211 = qvalue(elt(env, 6)); /* ycoord!* */
    v211 = (Lisp_Object)(int32_t)((int32_t)v196 + (int32_t)v211 - TAG_FIXNUM);
    fn = elt(env, 12); /* min */
    v211 = (*qfn2(fn))(qenv(fn), v195, v211);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    qvalue(elt(env, 8)) = v211; /* ymin!* */
    v195 = qvalue(elt(env, 9)); /* ymax!* */
    v211 = stack[0];
    v211 = qcdr(v211);
    v196 = qcdr(v211);
    v211 = qvalue(elt(env, 6)); /* ycoord!* */
    v211 = (Lisp_Object)(int32_t)((int32_t)v196 + (int32_t)v211 - TAG_FIXNUM);
    fn = elt(env, 13); /* max */
    v211 = (*qfn2(fn))(qenv(fn), v195, v211);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    qvalue(elt(env, 9)) = v211; /* ymax!* */
    v211 = nil;
    { popv(3); return onevalue(v211); }
/* error exit handlers */
v163:
    popv(3);
    return nil;
}



/* Code for prin2!-downcase */

static Lisp_Object CC_prin2Kdowncase(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v64, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2-downcase");
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
    v103 = v0;
/* end of prologue */
    v103 = Lexplodec(nil, v103);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    stack[0] = v103;
    goto v91;

v91:
    v103 = stack[0];
    if (v103 == nil) goto v58;
    v103 = stack[0];
    v103 = qcar(v103);
    v55 = v103;
    v103 = v55;
    v103 = Lalpha_char_p(nil, v103);
    env = stack[-1];
    if (v103 == nil) goto v81;
    v64 = v55;
    v103 = qvalue(elt(env, 2)); /* charassoc!* */
    v103 = Latsoc(nil, v64, v103);
    v64 = v103;
    v103 = v64;
    if (v103 == nil) goto v84;
    v103 = v64;
    v103 = qcdr(v103);
    goto v92;

v92:
    v103 = Lprinc(nil, v103);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    goto v37;

v37:
    v103 = stack[0];
    v103 = qcdr(v103);
    stack[0] = v103;
    goto v91;

v84:
    v103 = v55;
    goto v92;

v81:
    v103 = v55;
    v103 = Lprinc(nil, v103);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    goto v37;

v58:
    v103 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v103); }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for quotfm */

static Lisp_Object CC_quotfm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v206, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfm");
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
    v206 = v1;
    v85 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*mcd */
    qvalue(elt(env, 1)) = nil; /* !*mcd */
    v112 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v112; /* !*mcd */
    v112 = v85;
    fn = elt(env, 3); /* quotf */
    v112 = (*qfn2(fn))(qenv(fn), v112, v206);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*mcd */
    { popv(2); return onevalue(v112); }
/* error exit handlers */
v38:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*mcd */
    popv(2);
    return nil;
}



/* Code for !*collectphysops */

static Lisp_Object CC_Hcollectphysops(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *collectphysops");
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
    v84 = stack[0];
    fn = elt(env, 2); /* physopp */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    if (v84 == nil) goto v56;
    v84 = stack[0];
    popv(3);
    return ncons(v84);

v56:
    v84 = stack[0];
    if (!(!consp(v84))) goto v42;
    v84 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v84); }

v42:
    v84 = stack[0];
    v84 = qcar(v84);
    v82 = v84;
    v84 = stack[0];
    v84 = qcdr(v84);
    stack[0] = v84;
    v84 = v82;
    v84 = CC_Hcollectphysops(env, v84);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    v84 = Lnconc(nil, stack[-1], v84);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-2];
    stack[-1] = v84;
    v84 = stack[0];
    if (v84 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else goto v42;
/* error exit handlers */
v108:
    popv(3);
    return nil;
}



/* Code for constimes */

static Lisp_Object CC_constimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v58 = v0;
/* end of prologue */
    v59 = v58;
    v58 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cstimes */
        return (*qfn2(fn))(qenv(fn), v59, v58);
    }
}



/* Code for sfpx */

static Lisp_Object CC_sfpx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v85, v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfpx");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v206 = v0;
/* end of prologue */
    v38 = v206;
    v37 = qvalue(elt(env, 1)); /* nil */
    v85 = qvalue(elt(env, 1)); /* nil */
    v206 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 2); /* sfpx1 */
        return (*qfnn(fn))(qenv(fn), 4, v38, v37, v85, v206);
    }
}



/* Code for fs!:timesterm */

static Lisp_Object CC_fsTtimesterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v103, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:timesterm");
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
    v53 = stack[0];
    if (v53 == nil) goto v91;
    v53 = stack[-1];
    if (v53 == nil) goto v57;
    v103 = stack[-1];
    v53 = stack[0];
    fn = elt(env, 2); /* fs!:timestermterm */
    v53 = (*qfn2(fn))(qenv(fn), v103, v53);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    stack[-2] = v53;
    v64 = stack[-1];
    v103 = stack[0];
    v53 = (Lisp_Object)49; /* 3 */
    v53 = *(Lisp_Object *)((char *)v103 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL)));
    v53 = CC_fsTtimesterm(env, v64, v53);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    {
        Lisp_Object v104 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v104, v53);
    }

v57:
    v53 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v53); }

v91:
    v53 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v53); }
/* error exit handlers */
v78:
    popv(4);
    return nil;
}



/* Code for cali_trace */

static Lisp_Object MS_CDECL CC_cali_trace(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v58;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cali_trace");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cali_trace");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v57 = elt(env, 1); /* cali */
    v58 = elt(env, 2); /* trace */
    return get(v57, v58);
}



setup_type const u03_setup[] =
{
    {"plus-mod-p",              too_few_2,      CC_plusKmodKp, wrong_no_2},
    {"sfto_dcontentf",          CC_sfto_dcontentf,too_many_1,  wrong_no_1},
    {"lt*",                     CC_ltH,         too_many_1,    wrong_no_1},
    {"tayexp-plus2",            too_few_2,      CC_tayexpKplus2,wrong_no_2},
    {"pasf_susitf",             too_few_2,      CC_pasf_susitf,wrong_no_2},
    {"notstring",               CC_notstring,   too_many_1,    wrong_no_1},
    {"multi_isarb_compl",       CC_multi_isarb_compl,too_many_1,wrong_no_1},
    {"sqform",                  too_few_2,      CC_sqform,     wrong_no_2},
    {"dm-times",                too_few_2,      CC_dmKtimes,   wrong_no_2},
    {"initcomb",                CC_initcomb,    too_many_1,    wrong_no_1},
    {"evsum",                   too_few_2,      CC_evsum,      wrong_no_2},
    {"multpfsq",                too_few_2,      CC_multpfsq,   wrong_no_2},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"reordop",                 too_few_2,      CC_reordop,    wrong_no_2},
    {"opmtch*",                 CC_opmtchH,     too_many_1,    wrong_no_1},
    {"qassoc",                  too_few_2,      CC_qassoc,     wrong_no_2},
    {"fs:timestermterm",        too_few_2,      CC_fsTtimestermterm,wrong_no_2},
    {"mo=sum",                  too_few_2,      CC_moMsum,     wrong_no_2},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"pv_multc",                too_few_2,      CC_pv_multc,   wrong_no_2},
    {"lnc",                     CC_lnc,         too_many_1,    wrong_no_1},
    {"tayexp-lessp",            too_few_2,      CC_tayexpKlessp,wrong_no_2},
    {"get+row+nr",              CC_getLrowLnr,  too_many_1,    wrong_no_1},
    {"qqe_nytidp",              CC_qqe_nytidp,  too_many_1,    wrong_no_1},
    {"pasf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwupdknowl},
    {"ibalp_getupl",            CC_ibalp_getupl,too_many_1,    wrong_no_1},
    {"minus-mod-p",             CC_minusKmodKp, too_many_1,    wrong_no_1},
    {"multi_isarb_int",         CC_multi_isarb_int,too_many_1, wrong_no_1},
    {"depends",                 too_few_2,      CC_depends,    wrong_no_2},
    {"dm-difference",           too_few_2,      CC_dmKdifference,wrong_no_2},
    {"freexp",                  CC_freexp,      too_many_1,    wrong_no_1},
    {"exptchk",                 CC_exptchk,     too_many_1,    wrong_no_1},
    {"evcompless?",             too_few_2,      CC_evcomplessW,wrong_no_2},
    {"copy_mat",                CC_copy_mat,    too_many_1,    wrong_no_1},
    {"factorordp",              too_few_2,      CC_factorordp, wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {"i2rd*",                   CC_i2rdH,       too_many_1,    wrong_no_1},
    {"hasonephysop",            CC_hasonephysop,too_many_1,    wrong_no_1},
    {"getroad",                 too_few_2,      CC_getroad,    wrong_no_2},
    {"xcomment",                too_few_2,      CC_xcomment,   wrong_no_2},
    {"arraychk",                CC_arraychk,    too_many_1,    wrong_no_1},
    {"fs:angle-order",          too_few_2,      CC_fsTangleKorder,wrong_no_2},
    {"mo=degcomp",              too_few_2,      CC_moMdegcomp, wrong_no_2},
    {"prin2*",                  CC_prin2H,      too_many_1,    wrong_no_1},
    {"pkp",                     CC_pkp,         too_many_1,    wrong_no_1},
    {"copy",                    CC_copy,        too_many_1,    wrong_no_1},
    {"times-term-mod-p",        too_few_2,      CC_timesKtermKmodKp,wrong_no_2},
    {"setcdr",                  too_few_2,      CC_setcdr,     wrong_no_2},
    {"symbollessp",             too_few_2,      CC_symbollessp,wrong_no_2},
    {"quotf1",                  too_few_2,      CC_quotf1,     wrong_no_2},
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"get+vec+entry",           too_few_2,      CC_getLvecLentry,wrong_no_2},
    {"qqe_btidp",               CC_qqe_btidp,   too_many_1,    wrong_no_1},
    {"ibalp_minclnr",           CC_ibalp_minclnr,too_many_1,   wrong_no_1},
    {"get_content",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_content},
    {"mcharg1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg1},
    {"subs2*",                  CC_subs2H,      too_many_1,    wrong_no_1},
    {"peel",                    CC_peel,        too_many_1,    wrong_no_1},
    {"smemql",                  too_few_2,      CC_smemql,     wrong_no_2},
    {"putpline",                CC_putpline,    too_many_1,    wrong_no_1},
    {"prin2-downcase",          CC_prin2Kdowncase,too_many_1,  wrong_no_1},
    {"quotfm",                  too_few_2,      CC_quotfm,     wrong_no_2},
    {"*collectphysops",         CC_Hcollectphysops,too_many_1, wrong_no_1},
    {"constimes",               CC_constimes,   too_many_1,    wrong_no_1},
    {"sfpx",                    CC_sfpx,        too_many_1,    wrong_no_1},
    {"fs:timesterm",            too_few_2,      CC_fsTtimesterm,wrong_no_2},
    {"cali_trace",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_cali_trace},
    {NULL, (one_args *)"u03", (two_args *)"1491 4088234 7771010", 0}
};

/* end of generated code */
