
/* $destdir\u31.c        Machine generated C code */

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


/* Code for simpexpt1 */

static Lisp_Object MS_CDECL CC_simpexpt1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt1");
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
    stack[-4] = v2;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = qvalue(elt(env, 1)); /* !*allfac */
    qvalue(elt(env, 1)) = nil; /* !*allfac */
    stack[-3] = qvalue(elt(env, 2)); /* !*div */
    qvalue(elt(env, 2)) = nil; /* !*div */
    v78 = stack[-6];
    v78 = Lonep(nil, v78);
    env = stack[-8];
    if (v78 == nil) goto v81;
    v79 = (Lisp_Object)17; /* 1 */
    v78 = (Lisp_Object)17; /* 1 */
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v83:
    qvalue(elt(env, 2)) = stack[-3]; /* !*div */
    qvalue(elt(env, 1)) = stack[-7]; /* !*allfac */
    { popv(9); return onevalue(v78); }

v81:
    v78 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v78; /* !*allfac */
    v78 = stack[-5];
    v78 = qcar(v78);
    stack[-2] = v78;
    v79 = stack[-2];
    v78 = (Lisp_Object)17; /* 1 */
    if (!(v79 == v78)) goto v84;
    v78 = stack[-5];
    v79 = qcdr(v78);
    v78 = (Lisp_Object)17; /* 1 */
    if (!(v79 == v78)) goto v84;
    v78 = stack[-6];
    fn = elt(env, 13); /* simp */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v84:
    v79 = stack[-6];
    v78 = elt(env, 4); /* e */
    if (!(v79 == v78)) goto v85;
    v78 = stack[-5];
    v78 = qcdr(v78);
    if (!consp(v78)) goto v86;
    v78 = stack[-5];
    v78 = qcdr(v78);
    v78 = qcar(v78);
    if (!(!consp(v78))) goto v85;

v86:
    v78 = stack[-2];
    if (!consp(v78)) goto v85;
    v78 = stack[-2];
    v78 = qcar(v78);
    if (!consp(v78)) goto v85;
    v78 = stack[-2];
    v78 = qcar(v78);
    v78 = qcar(v78);
    v79 = qcdr(v78);
    v78 = (Lisp_Object)17; /* 1 */
    if (!(v79 == v78)) goto v85;
    v78 = stack[-2];
    v78 = qcdr(v78);
    if (!(v78 == nil)) goto v85;
    v78 = stack[-2];
    v78 = qcar(v78);
    v78 = qcar(v78);
    v79 = qcar(v78);
    v78 = elt(env, 5); /* log */
    if (!consp(v79)) goto v85;
    v79 = qcar(v79);
    if (!(v79 == v78)) goto v85;
    v78 = stack[-2];
    v78 = qcar(v78);
    v78 = qcar(v78);
    v78 = qcar(v78);
    v78 = qcdr(v78);
    v78 = qcar(v78);
    fn = elt(env, 14); /* simp!* */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    fn = elt(env, 15); /* prepsq!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v78 = stack[-2];
    v78 = qcar(v78);
    v79 = qcdr(v78);
    v78 = stack[-5];
    v78 = qcdr(v78);
    v79 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v78 = qvalue(elt(env, 6)); /* nil */
    v78 = CC_simpexpt1(env, 3, stack[0], v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v85:
    v78 = stack[-2];
    if (!consp(v78)) goto v87;
    v78 = stack[-2];
    v78 = qcar(v78);
    if (!(!consp(v78))) goto v88;

v87:
    v78 = stack[-5];
    v78 = qcdr(v78);
    if (!consp(v78)) goto v89;
    v78 = stack[-5];
    v78 = qcdr(v78);
    v78 = qcar(v78);
    if (!(!consp(v78))) goto v88;

v89:
    v78 = stack[-6];
    fn = elt(env, 13); /* simp */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    stack[-1] = v78;
    v78 = stack[-2];
    if (v78 == nil) goto v90;
    v78 = stack[-1];
    v78 = qcar(v78);
    if (v78 == nil) goto v91;
    v78 = stack[-2];
    if (!(!consp(v78))) goto v92;
    v78 = stack[-5];
    v79 = qcdr(v78);
    v78 = (Lisp_Object)17; /* 1 */
    if (!(v79 == v78)) goto v92;
    v78 = stack[-1];
    v78 = qcar(v78);
    if (!consp(v78)) goto v93;
    v78 = stack[-1];
    v78 = qcar(v78);
    v78 = qcar(v78);
    if (!(!consp(v78))) goto v92;

v93:
    v78 = stack[-1];
    v79 = qcdr(v78);
    v78 = (Lisp_Object)17; /* 1 */
    if (!(v79 == v78)) goto v92;
    v78 = stack[-1];
    v78 = qcar(v78);
    if (!(!consp(v78))) goto v94;
    v79 = stack[-2];
    v78 = (Lisp_Object)1; /* 0 */
    v78 = (Lisp_Object)greaterp2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v78 = v78 ? lisp_true : nil;
    env = stack[-8];
    if (v78 == nil) goto v94;
    v78 = stack[-1];
    v79 = qcar(v78);
    v78 = stack[-2];
    v78 = Lexpt(nil, v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    fn = elt(env, 16); /* !*d2q */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v94:
    v78 = stack[-1];
    v79 = qcar(v78);
    v78 = stack[-2];
    fn = elt(env, 17); /* !:expt */
    v79 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v78 = (Lisp_Object)17; /* 1 */
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    stack[-1] = v78;
    v78 = qvalue(elt(env, 11)); /* !*mcd */
    if (v78 == nil) goto v95;
    v78 = stack[-1];
    fn = elt(env, 18); /* resimp */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v95:
    v78 = stack[-1];
    goto v83;

v92:
    stack[0] = elt(env, 12); /* expt */
    v79 = stack[-1];
    v78 = stack[-5];
    v78 = list2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    fn = elt(env, 19); /* domainvalchk */
    v78 = (*qfn2(fn))(qenv(fn), stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v79 = v78;
    if (v78 == nil) goto v96;
    v78 = v79;
    goto v83;

v96:
    v78 = stack[-2];
    if (!(!consp(v78))) goto v97;
    v78 = stack[-5];
    v79 = qcdr(v78);
    v78 = (Lisp_Object)17; /* 1 */
    if (!(v79 == v78)) goto v97;
    v79 = stack[-2];
    v78 = (Lisp_Object)1; /* 0 */
    v78 = (Lisp_Object)lessp2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v78 = v78 ? lisp_true : nil;
    env = stack[-8];
    if (v78 == nil) goto v98;
    v78 = qvalue(elt(env, 11)); /* !*mcd */
    if (v78 == nil) goto v99;
    stack[0] = stack[-1];
    v78 = stack[-2];
    v78 = negate(v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    fn = elt(env, 20); /* exptsq */
    v78 = (*qfn2(fn))(qenv(fn), stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    fn = elt(env, 21); /* invsq */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v99:
    v78 = stack[-1];
    v79 = qcar(v78);
    v78 = stack[-2];
    fn = elt(env, 22); /* expf */
    stack[0] = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v78 = stack[-1];
    stack[-1] = qcdr(v78);
    v78 = stack[-2];
    v78 = negate(v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    fn = elt(env, 23); /* mksfpf */
    v78 = (*qfn2(fn))(qenv(fn), stack[-1], v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    fn = elt(env, 24); /* multf */
    v79 = (*qfn2(fn))(qenv(fn), stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v78 = (Lisp_Object)17; /* 1 */
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v98:
    v79 = stack[-1];
    v78 = stack[-2];
    fn = elt(env, 20); /* exptsq */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v97:
    v78 = stack[-4];
    if (v78 == nil) goto v100;
    v78 = stack[-6];
    v80 = v78;
    goto v101;

v101:
    v79 = stack[-5];
    v78 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 25); /* simpexpt11 */
    v78 = (*qfnn(fn))(qenv(fn), 3, v80, v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v100:
    v78 = stack[-1];
    fn = elt(env, 26); /* subs2!* */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    fn = elt(env, 15); /* prepsq!* */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v80 = v78;
    goto v101;

v91:
    v78 = stack[-2];
    if (!consp(v78)) goto v102;
    v78 = stack[-2];
    v78 = qcar(v78);
    if (!(!consp(v78))) goto v103;

v102:
    v78 = stack[-2];
    fn = elt(env, 27); /* minusf */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    if (v78 == nil) goto v103;
    v78 = elt(env, 10); /* "Zero divisor" */
    v79 = v78;
    v78 = v79;
    qvalue(elt(env, 8)) = v78; /* errmsg!* */
    v78 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v78 == nil)) goto v104;
    v78 = v79;
    fn = elt(env, 28); /* lprie */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v104;

v104:
    v78 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v78 = nil;
    goto v83;

v103:
    v79 = qvalue(elt(env, 6)); /* nil */
    v78 = (Lisp_Object)17; /* 1 */
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v90:
    v78 = stack[-1];
    v78 = qcar(v78);
    if (v78 == nil) goto v105;
    v79 = (Lisp_Object)17; /* 1 */
    v78 = (Lisp_Object)17; /* 1 */
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;

v105:
    v78 = elt(env, 7); /* "0**0 formed" */
    v79 = v78;
    v78 = v79;
    qvalue(elt(env, 8)) = v78; /* errmsg!* */
    v78 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v78 == nil)) goto v106;
    v78 = v79;
    fn = elt(env, 28); /* lprie */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v106;

v106:
    v78 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    v78 = nil;
    goto v83;

v88:
    v80 = stack[-6];
    v79 = stack[-5];
    v78 = stack[-4];
    fn = elt(env, 25); /* simpexpt11 */
    v78 = (*qfnn(fn))(qenv(fn), 3, v80, v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-8];
    goto v83;
/* error exit handlers */
v82:
    env = stack[-8];
    qvalue(elt(env, 2)) = stack[-3]; /* !*div */
    qvalue(elt(env, 1)) = stack[-7]; /* !*allfac */
    popv(9);
    return nil;
}



/* Code for getargsrd */

static Lisp_Object MS_CDECL CC_getargsrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "getargsrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getargsrd");
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
    v110 = qvalue(elt(env, 1)); /* char */
    v109 = elt(env, 2); /* (b v a r) */
    if (equal(v110, v109)) goto v18;
    v109 = nil;
    { popv(2); return onevalue(v109); }

v18:
    fn = elt(env, 3); /* bvarrd */
    v109 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    stack[0] = v109;
    fn = elt(env, 4); /* lex */
    v109 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    v109 = CC_getargsrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v111;
    {
        Lisp_Object v112 = stack[0];
        popv(2);
        return cons(v112, v109);
    }
/* error exit handlers */
v111:
    popv(2);
    return nil;
}



/* Code for remdiff */

static Lisp_Object CC_remdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remdiff");
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
    stack[-1] = v0;
/* end of prologue */
    v121 = stack[-1];
    if (symbolp(v121)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v121 = stack[-1];
    fn = elt(env, 5); /* constp */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    if (!(v121 == nil)) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v121 = stack[-1];
    v122 = qcar(v121);
    v121 = elt(env, 1); /* difference */
    if (v122 == v121) goto v123;
    v121 = stack[-1];
    stack[-4] = qcar(v121);
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-3] = v121;
    v121 = stack[-3];
    if (v121 == nil) goto v124;
    v121 = stack[-3];
    v121 = qcar(v121);
    v121 = CC_remdiff(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v121 = ncons(v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[-1] = v121;
    stack[-2] = v121;
    goto v125;

v125:
    v121 = stack[-3];
    v121 = qcdr(v121);
    stack[-3] = v121;
    v121 = stack[-3];
    if (v121 == nil) goto v126;
    stack[0] = stack[-1];
    v121 = stack[-3];
    v121 = qcar(v121);
    v121 = CC_remdiff(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v121 = ncons(v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v121 = Lrplacd(nil, stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v125;

v126:
    v121 = stack[-2];
    goto v127;

v127:
    {
        Lisp_Object v128 = stack[-4];
        popv(6);
        return cons(v128, v121);
    }

v124:
    v121 = qvalue(elt(env, 4)); /* nil */
    goto v127;

v123:
    stack[-3] = elt(env, 2); /* plus */
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = qcar(v121);
    stack[-2] = CC_remdiff(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[0] = elt(env, 3); /* minus */
    v121 = stack[-1];
    v121 = qcdr(v121);
    v121 = qcdr(v121);
    v121 = qcar(v121);
    v121 = CC_remdiff(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v121 = list2(stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v121 = list3(stack[-3], stack[-2], v121);
    nil = C_nil;
    if (exception_pending()) goto v63;
    { popv(6); return onevalue(v121); }
/* error exit handlers */
v63:
    popv(6);
    return nil;
}



/* Code for suspend */

static Lisp_Object MS_CDECL CC_suspend(Lisp_Object env, int nargs,
                         Lisp_Object v129, Lisp_Object v3,
                         Lisp_Object v4, Lisp_Object v18,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v70, v71, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "suspend");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for suspend");
#endif
    if (stack >= stacklimit)
    {
        push5(v10,v18,v4,v3,v129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v129,v3,v4,v18,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v10;
    v70 = v18;
    v71 = v4;
    v86 = v3;
    v114 = v129;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-6] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-5] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v114; /* op */
    v114 = v86;
    qvalue(elt(env, 2)) = v114; /* r */
    v114 = v71;
    qvalue(elt(env, 3)) = v114; /* p */
    v114 = qvalue(elt(env, 2)); /* r */
    stack[-4] = qcar(v114);
    v114 = qvalue(elt(env, 3)); /* p */
    stack[-3] = qcar(v114);
    stack[-2] = v70;
    stack[-1] = qvalue(elt(env, 1)); /* op */
    v114 = qvalue(elt(env, 2)); /* r */
    stack[0] = qcdr(v114);
    v70 = qvalue(elt(env, 1)); /* op */
    v114 = qvalue(elt(env, 3)); /* p */
    v114 = qcdr(v114);
    v114 = cons(v70, v114);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-9];
    v114 = ncons(v114);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-9];
    v70 = acons(stack[-1], stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-9];
    v114 = stack[-7];
    v114 = cons(v70, v114);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-9];
    fn = elt(env, 4); /* amatch */
    v114 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-3], stack[-2], v114);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; /* p */
    qvalue(elt(env, 2)) = stack[-6]; /* r */
    qvalue(elt(env, 1)) = stack[-8]; /* op */
    { popv(10); return onevalue(v114); }
/* error exit handlers */
v137:
    env = stack[-9];
    qvalue(elt(env, 3)) = stack[-5]; /* p */
    qvalue(elt(env, 2)) = stack[-6]; /* r */
    qvalue(elt(env, 1)) = stack[-8]; /* op */
    popv(10);
    return nil;
}



/* Code for matsm */

static Lisp_Object CC_matsm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm");
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
    v127 = v0;
/* end of prologue */
    stack[-2] = nil;
    v136 = v127;
    v127 = elt(env, 1); /* matrix */
    fn = elt(env, 3); /* nssimp */
    v127 = (*qfn2(fn))(qenv(fn), v136, v127);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    stack[-1] = v127;
    goto v5;

v5:
    v127 = stack[-1];
    if (v127 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v127 = stack[-1];
    v127 = qcar(v127);
    v136 = v127;
    v127 = v136;
    stack[0] = qcar(v127);
    v127 = v136;
    v127 = qcdr(v127);
    fn = elt(env, 4); /* matsm1 */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    fn = elt(env, 5); /* multsm */
    v127 = (*qfn2(fn))(qenv(fn), stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    v136 = stack[-2];
    if (v136 == nil) goto v75;
    v136 = stack[-2];
    fn = elt(env, 6); /* addm */
    v127 = (*qfn2(fn))(qenv(fn), v136, v127);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    goto v75;

v75:
    stack[-2] = v127;
    v127 = stack[-1];
    v127 = qcdr(v127);
    stack[-1] = v127;
    goto v5;
/* error exit handlers */
v71:
    popv(4);
    return nil;
}



/* Code for bcminus!? */

static Lisp_Object CC_bcminusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcminus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v108 = v0;
/* end of prologue */
    v107 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v107 == nil) goto v29;
    v107 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v107);

v29:
    v107 = v108;
    v107 = qcar(v107);
    {
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v107);
    }
}



/* Code for numprintlen */

static Lisp_Object CC_numprintlen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numprintlen");
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
    stack[-1] = v0;
/* end of prologue */

v3:
    v172 = stack[-1];
    if (!consp(v172)) goto v10;
    v172 = stack[-1];
    v172 = Llength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = Lonep(nil, v172);
    env = stack[-6];
    if (v172 == nil) goto v175;
    v172 = stack[-1];
    v172 = qcar(v172);
    stack[-1] = v172;
    goto v3;

v175:
    v172 = stack[-1];
    v173 = qcar(v172);
    v172 = elt(env, 1); /* !:rd!: */
    if (v173 == v172) goto v176;
    v172 = stack[-1];
    v173 = qcar(v172);
    v172 = elt(env, 3); /* (!:cr!: !:crn!: !:gi!:) */
    v172 = Lmemq(nil, v173, v172);
    if (v172 == nil) goto v177;
    v173 = elt(env, 1); /* !:rd!: */
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = cons(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v173 = v172;
    v172 = v173;
    v172 = qcdr(v172);
    if (!consp(v172)) goto v178;
    v172 = v173;
    stack[0] = v172;
    goto v179;

v179:
    v173 = qvalue(elt(env, 2)); /* !:bprec!: */
    v172 = (Lisp_Object)49; /* 3 */
    v172 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v172 = (*qfn2(fn))(qenv(fn), stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    stack[0] = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v173 = elt(env, 1); /* !:rd!: */
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = cons(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v173 = v172;
    v172 = v173;
    v172 = qcdr(v172);
    if (!consp(v172)) goto v180;
    v172 = v173;
    stack[-1] = v172;
    goto v53;

v53:
    v173 = qvalue(elt(env, 2)); /* !:bprec!: */
    v172 = (Lisp_Object)49; /* 3 */
    v172 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v172 = (*qfn2(fn))(qenv(fn), stack[-1], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = cons(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[-1] = v172;
    stack[-4] = (Lisp_Object)193; /* 12 */
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    stack[-3] = Llength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = Lexplode(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[-2] = Llength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    stack[0] = Llength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = Lexplode(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = Llength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = plus2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = plus2(stack[-2], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = plus2(stack[-3], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    {
        Lisp_Object v181 = stack[-4];
        popv(7);
        return plus2(v181, v172);
    }

v180:
    v172 = v173;
    v172 = qcdr(v172);
    fn = elt(env, 9); /* fl2bf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[-1] = v172;
    goto v53;

v178:
    v172 = v173;
    v172 = qcdr(v172);
    fn = elt(env, 9); /* fl2bf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[0] = v172;
    goto v179;

v177:
    v172 = stack[-1];
    stack[-5] = Llength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[-4] = elt(env, 4); /* plus */
    v172 = stack[-1];
    v172 = qcdr(v172);
    stack[-3] = v172;
    v172 = stack[-3];
    if (v172 == nil) goto v182;
    v172 = stack[-3];
    v172 = qcar(v172);
    v172 = CC_numprintlen(env, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[-1] = v172;
    stack[-2] = v172;
    goto v183;

v183:
    v172 = stack[-3];
    v172 = qcdr(v172);
    stack[-3] = v172;
    v172 = stack[-3];
    if (v172 == nil) goto v184;
    stack[0] = stack[-1];
    v172 = stack[-3];
    v172 = qcar(v172);
    v172 = CC_numprintlen(env, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = Lrplacd(nil, stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = stack[-1];
    v172 = qcdr(v172);
    stack[-1] = v172;
    goto v183;

v184:
    v172 = stack[-2];
    goto v185;

v185:
    v172 = cons(stack[-4], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 10); /* eval */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    {
        Lisp_Object v186 = stack[-5];
        popv(7);
        return plus2(v186, v172);
    }

v182:
    v172 = qvalue(elt(env, 5)); /* nil */
    goto v185;

v176:
    v172 = stack[-1];
    v172 = qcdr(v172);
    if (!consp(v172)) goto v187;
    v172 = stack[-1];
    stack[0] = v172;
    goto v188;

v188:
    v173 = qvalue(elt(env, 2)); /* !:bprec!: */
    v172 = (Lisp_Object)49; /* 3 */
    v172 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v172 = (*qfn2(fn))(qenv(fn), stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[-1] = v172;
    stack[-2] = (Lisp_Object)33; /* 2 */
    v172 = stack[-1];
    v172 = qcar(v172);
    stack[0] = Llength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = Lexplode(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = Llength(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v172 = plus2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    {
        Lisp_Object v189 = stack[-2];
        popv(7);
        return plus2(v189, v172);
    }

v187:
    v172 = stack[-1];
    v172 = qcdr(v172);
    fn = elt(env, 9); /* fl2bf */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    stack[0] = v172;
    goto v188;

v10:
    v172 = stack[-1];
    v172 = Lexplode(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v174;
        popv(7);
        return Llength(nil, v172);
/* error exit handlers */
v174:
    popv(7);
    return nil;
}



/* Code for indxchk */

static Lisp_Object CC_indxchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indxchk");
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
    v137 = v0;
/* end of prologue */
    stack[-1] = v137;
    v170 = qvalue(elt(env, 1)); /* indxl!* */
    v137 = qvalue(elt(env, 2)); /* nosuml!* */
    fn = elt(env, 5); /* union */
    v137 = (*qfn2(fn))(qenv(fn), v170, v137);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    stack[0] = v137;
    goto v18;

v18:
    v137 = stack[-1];
    if (v137 == nil) goto v194;
    v137 = stack[-1];
    v137 = qcar(v137);
    if (!consp(v137)) goto v176;
    v137 = stack[-1];
    v137 = qcar(v137);
    v137 = qcdr(v137);
    v137 = qcar(v137);
    if (is_number(v137)) goto v188;
    v137 = stack[-1];
    v137 = qcar(v137);
    v137 = qcdr(v137);
    v137 = qcar(v137);
    v170 = v137;
    goto v111;

v111:
    v137 = stack[0];
    v137 = Lmemq(nil, v170, v137);
    if (v137 == nil) goto v77;
    v137 = stack[-1];
    v137 = qcdr(v137);
    stack[-1] = v137;
    goto v18;

v77:
    v137 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v137); }

v188:
    v137 = stack[-1];
    v137 = qcar(v137);
    v137 = qcdr(v137);
    v137 = qcar(v137);
    fn = elt(env, 6); /* !*num2id */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    v170 = v137;
    goto v111;

v176:
    v137 = stack[-1];
    v137 = qcar(v137);
    if (is_number(v137)) goto v75;
    v137 = stack[-1];
    v137 = qcar(v137);
    goto v74;

v74:
    v170 = v137;
    goto v111;

v75:
    v137 = stack[-1];
    v137 = qcar(v137);
    v137 = Labsval(nil, v137);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    fn = elt(env, 6); /* !*num2id */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    goto v74;

v194:
    v137 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v137); }
/* error exit handlers */
v193:
    popv(3);
    return nil;
}



/* Code for color!-strand */

static Lisp_Object MS_CDECL CC_colorKstrand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v195, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color-strand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color-strand");
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
    goto v10;

v10:
    v187 = stack[-1];
    if (v187 == nil) goto v83;
    v195 = stack[-2];
    v187 = stack[-1];
    v187 = qcar(v187);
    fn = elt(env, 1); /* color!-roads */
    v196 = (*qfn2(fn))(qenv(fn), v195, v187);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v195 = stack[0];
    v187 = stack[-3];
    v187 = acons(v196, v195, v187);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    stack[-3] = v187;
    v187 = stack[-1];
    v187 = qcdr(v187);
    stack[-1] = v187;
    v187 = stack[0];
    v187 = add1(v187);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    stack[0] = v187;
    goto v10;

v83:
    v187 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v187);
    }
/* error exit handlers */
v72:
    popv(5);
    return nil;
}



/* Code for reduce!-columns */

static Lisp_Object MS_CDECL CC_reduceKcolumns(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-columns");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-columns");
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
    stack[-4] = v2;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v212 = stack[-6];
    stack[-3] = v212;
    v212 = stack[-5];
    stack[-2] = v212;
    stack[0] = stack[-6];
    v213 = stack[-6];
    v212 = stack[-4];
    fn = elt(env, 2); /* red!-weight */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    v212 = cons(stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    stack[-7] = v212;
    goto v130;

v130:
    v212 = stack[-3];
    if (v212 == nil) goto v131;
    v212 = stack[-3];
    v213 = qcar(v212);
    v212 = (Lisp_Object)1; /* 0 */
    if (v213 == v212) goto v133;
    v212 = stack[-2];
    v213 = qcar(v212);
    v212 = (Lisp_Object)1; /* 0 */
    if (v213 == v212) goto v133;
    v212 = stack[-3];
    v213 = qcar(v212);
    v212 = stack[-2];
    v212 = qcar(v212);
    v212 = Ldivide(nil, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    stack[-1] = v212;
    v213 = qcdr(v212);
    v212 = (Lisp_Object)1; /* 0 */
    if (!(v213 == v212)) goto v133;
    stack[0] = stack[-6];
    v212 = stack[-1];
    v213 = qcar(v212);
    v212 = stack[-5];
    fn = elt(env, 3); /* mv!-domainlist!-!* */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    fn = elt(env, 4); /* mv!-domainlist!-!- */
    v212 = (*qfn2(fn))(qenv(fn), stack[0], v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    stack[-1] = v212;
    v213 = stack[-1];
    v212 = stack[-4];
    fn = elt(env, 2); /* red!-weight */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    stack[0] = v212;
    v213 = stack[0];
    v212 = stack[-7];
    v212 = qcdr(v212);
    fn = elt(env, 5); /* red!-weight!-less!-p */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    if (v212 == nil) goto v133;
    v213 = stack[-1];
    v212 = stack[0];
    v213 = cons(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    v212 = stack[-7];
    fn = elt(env, 6); /* more!-apartp */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    if (!(v212 == nil)) goto v133;
    v213 = stack[-1];
    v212 = stack[0];
    v212 = cons(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-8];
    stack[-7] = v212;
    goto v133;

v133:
    v212 = stack[-3];
    v212 = qcdr(v212);
    stack[-3] = v212;
    v212 = stack[-2];
    v212 = qcdr(v212);
    stack[-2] = v212;
    goto v130;

v131:
    v212 = stack[-7];
    v212 = qcar(v212);
    { popv(9); return onevalue(v212); }
/* error exit handlers */
v214:
    popv(9);
    return nil;
}



/* Code for matop_pseudomod */

static Lisp_Object CC_matop_pseudomod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matop_pseudomod");
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
    v81 = v1;
    v107 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mod!* */
    v81 = (*qfn2(fn))(qenv(fn), v107, v81);
    errexit();
    v81 = qcar(v81);
    return onevalue(v81);
}



/* Code for pa_list2vect */

static Lisp_Object CC_pa_list2vect(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_list2vect");
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
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    v220 = (Lisp_Object)1; /* 0 */
    stack[-3] = v220;
    v220 = stack[-5];
    v220 = sub1(v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    v220 = Lmkvect(nil, v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    stack[-6] = v220;
    v220 = stack[0];
    stack[-2] = v220;
    goto v192;

v192:
    v220 = stack[-2];
    if (v220 == nil) goto v108;
    v220 = stack[-2];
    v220 = qcar(v220);
    stack[0] = v220;
    v221 = elt(env, 2); /* min */
    v220 = stack[0];
    v220 = cons(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    fn = elt(env, 3); /* eval */
    v221 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    v220 = stack[-4];
    v220 = cons(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    stack[-4] = v220;
    v220 = stack[0];
    stack[-1] = v220;
    goto v119;

v119:
    v220 = stack[-1];
    if (v220 == nil) goto v222;
    v220 = stack[-1];
    v220 = qcar(v220);
    stack[0] = stack[-6];
    v221 = sub1(v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    v220 = stack[-4];
    v220 = qcar(v220);
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL))) = v220;
    v220 = stack[-1];
    v220 = qcdr(v220);
    stack[-1] = v220;
    goto v119;

v222:
    v220 = stack[-2];
    v220 = qcdr(v220);
    stack[-2] = v220;
    goto v192;

v108:
    v220 = (Lisp_Object)17; /* 1 */
    stack[-1] = v220;
    goto v223;

v223:
    v221 = stack[-5];
    v220 = stack[-1];
    v220 = difference2(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    v220 = Lminusp(nil, v220);
    env = stack[-7];
    if (v220 == nil) goto v116;
    v220 = stack[-4];
    v221 = Lreverse(nil, v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    v220 = stack[-6];
    popv(8);
    return cons(v221, v220);

v116:
    stack[0] = stack[-6];
    v220 = stack[-1];
    v220 = sub1(v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    v220 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v220/(16/CELL)));
    if (!(v220 == nil)) goto v224;
    v221 = stack[-3];
    v220 = (Lisp_Object)1; /* 0 */
    if (!(v221 == v220)) goto v225;
    v220 = stack[-1];
    stack[-3] = v220;
    v221 = stack[-3];
    v220 = stack[-4];
    v220 = cons(v221, v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    stack[-4] = v220;
    goto v225;

v225:
    stack[0] = stack[-6];
    v220 = stack[-1];
    v221 = sub1(v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    v220 = stack[-3];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v221/(16/CELL))) = v220;
    goto v224;

v224:
    v220 = stack[-1];
    v220 = add1(v220);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-7];
    stack[-1] = v220;
    goto v223;
/* error exit handlers */
v180:
    popv(8);
    return nil;
}



/* Code for build!-null!-vector */

static Lisp_Object MS_CDECL CC_buildKnullKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v124, v228, v137, v170, v207, v229, v193;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "build-null-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for build-null-vector");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v170 = v2;
    v207 = v1;
    v229 = v0;
/* end of prologue */
    v227 = (Lisp_Object)17; /* 1 */
    v193 = v227;
    goto v192;

v192:
    v227 = v229;
    v124 = (Lisp_Object)((int32_t)(v227) - 0x10);
    v227 = v193;
    v227 = (Lisp_Object)(int32_t)((int32_t)v124 - (int32_t)v227 + TAG_FIXNUM);
    v227 = ((intptr_t)(v227) < 0 ? lisp_true : nil);
    if (v227 == nil) goto v110;
    v228 = v207;
    v124 = v229;
    v227 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v228 + (CELL-TAG_VECTOR) + ((int32_t)v124/(16/CELL))) = v227;
    v227 = v207;
    v124 = v229;
    return cons(v227, v124);

v110:
    v137 = v207;
    v228 = v193;
    v124 = v170;
    v227 = v193;
    v124 = *(Lisp_Object *)((char *)v124 + (CELL-TAG_VECTOR) + ((int32_t)v227/(16/CELL)));
    v227 = v229;
    v227 = *(Lisp_Object *)((char *)v124 + (CELL-TAG_VECTOR) + ((int32_t)v227/(16/CELL)));
    *(Lisp_Object *)((char *)v137 + (CELL-TAG_VECTOR) + ((int32_t)v228/(16/CELL))) = v227;
    v227 = v193;
    v227 = (Lisp_Object)((int32_t)(v227) + 0x10);
    v193 = v227;
    goto v192;
}



/* Code for listeval0 */

static Lisp_Object CC_listeval0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v231, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeval0");
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
    v230 = qvalue(elt(env, 1)); /* simpcount!* */
    v231 = add1(v230);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    qvalue(elt(env, 1)) = v231; /* simpcount!* */
    v230 = qvalue(elt(env, 2)); /* simplimit!* */
    v230 = (Lisp_Object)greaterp2(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v223;
    v230 = v230 ? lisp_true : nil;
    env = stack[-1];
    if (v230 == nil) goto v18;
    v230 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v230; /* simpcount!* */
    v230 = elt(env, 3); /* "Simplification recursion too deep" */
    v231 = v230;
    v230 = v231;
    qvalue(elt(env, 4)) = v230; /* errmsg!* */
    v230 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v230 == nil)) goto v109;
    v230 = v231;
    fn = elt(env, 8); /* lprie */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    goto v109;

v109:
    v230 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    goto v18;

v18:
    v230 = stack[0];
    if (!(symbolp(v230))) goto v176;
    v231 = stack[0];
    v230 = elt(env, 6); /* share */
    v230 = Lflagp(nil, v231, v230);
    env = stack[-1];
    if (v230 == nil) goto v84;
    v230 = stack[0];
    fn = elt(env, 9); /* eval */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    v230 = CC_listeval0(env, v230);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    stack[0] = v230;
    goto v176;

v176:
    v230 = qvalue(elt(env, 1)); /* simpcount!* */
    v230 = sub1(v230);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    qvalue(elt(env, 1)) = v230; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v84:
    v231 = stack[0];
    v230 = elt(env, 7); /* avalue */
    v230 = get(v231, v230);
    env = stack[-1];
    v203 = v230;
    if (v230 == nil) goto v176;
    v230 = v203;
    v230 = qcdr(v230);
    v231 = qcar(v230);
    v230 = stack[0];
    if (equal(v231, v230)) goto v176;
    v230 = v203;
    v230 = qcdr(v230);
    v230 = qcar(v230);
    v230 = CC_listeval0(env, v230);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    stack[0] = v230;
    goto v176;
/* error exit handlers */
v223:
    popv(2);
    return nil;
}



/* Code for min2!-order */

static Lisp_Object MS_CDECL CC_min2Korder(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "min2-order");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for min2-order");
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
    stack[-4] = nil;
    goto v10;

v10:
    v223 = stack[-3];
    if (v223 == nil) goto v83;
    v223 = stack[-1];
    v223 = qcar(v223);
    stack[0] = v223;
    v223 = (Lisp_Object)1; /* 0 */
    v126 = v223;
    goto v123;

v123:
    v223 = stack[0];
    if (v223 == nil) goto v176;
    v223 = stack[0];
    v223 = qcar(v223);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v223 = (*qfn2(fn))(qenv(fn), v223, v126);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    v126 = v223;
    v223 = stack[0];
    v223 = qcdr(v223);
    stack[0] = v223;
    goto v123;

v176:
    v223 = v126;
    stack[0] = v223;
    v126 = stack[0];
    v223 = stack[-2];
    v223 = qcar(v223);
    fn = elt(env, 2); /* tayexp!-greaterp */
    v223 = (*qfn2(fn))(qenv(fn), v126, v223);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    if (v223 == nil) goto v137;
    v126 = stack[0];
    v223 = stack[-3];
    v223 = qcar(v223);
    fn = elt(env, 3); /* tayexp!-min2 */
    v223 = (*qfn2(fn))(qenv(fn), v126, v223);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    v126 = v223;
    goto v210;

v210:
    v223 = stack[-4];
    v223 = cons(v126, v223);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    stack[-4] = v223;
    v223 = stack[-3];
    v223 = qcdr(v223);
    stack[-3] = v223;
    v223 = stack[-2];
    v223 = qcdr(v223);
    stack[-2] = v223;
    v223 = stack[-1];
    v223 = qcdr(v223);
    stack[-1] = v223;
    goto v10;

v137:
    v223 = stack[-3];
    v223 = qcar(v223);
    v126 = v223;
    goto v210;

v83:
    v223 = stack[-4];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v223);
    }
/* error exit handlers */
v206:
    popv(6);
    return nil;
}



/* Code for evalnumberp */

static Lisp_Object CC_evalnumberp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v188, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalnumberp");
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
    v171 = v0;
/* end of prologue */
    fn = elt(env, 4); /* aeval */
    v171 = (*qfn1(fn))(qenv(fn), v171);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[0];
    v85 = v171;
    v171 = v85;
    if (!consp(v171)) goto v10;
    v171 = v85;
    v188 = qcar(v171);
    v171 = elt(env, 1); /* !*sq */
    if (!(v188 == v171)) goto v81;
    v171 = v85;
    v171 = qcdr(v171);
    v171 = qcar(v171);
    v171 = qcdr(v171);
    if (!(!consp(v171))) goto v81;
    v171 = v85;
    v171 = qcdr(v171);
    v171 = qcar(v171);
    v171 = qcar(v171);
    v188 = v171;
    v171 = v188;
    v171 = (consp(v171) ? nil : lisp_true);
    if (!(v171 == nil)) { popv(1); return onevalue(v171); }
    v171 = v188;
    v171 = qcar(v171);
    v188 = elt(env, 3); /* numbertag */
        popv(1);
        return Lflagp(nil, v171, v188);

v81:
    v171 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v171); }

v10:
    v171 = v85;
    v171 = (is_number(v171) ? lisp_true : nil);
    { popv(1); return onevalue(v171); }
/* error exit handlers */
v138:
    popv(1);
    return nil;
}



/* Code for pasf_susibinad */

static Lisp_Object CC_pasf_susibinad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v252, v253, v254, v255, v256, v257, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_susibinad");
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
    v252 = stack[-4];
    v253 = qcdr(v252);
    v252 = stack[-3];
    v252 = qcdr(v252);
    fn = elt(env, 7); /* cl_susiminlevel */
    v252 = (*qfn2(fn))(qenv(fn), v253, v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    stack[-1] = v252;
    v252 = stack[-4];
    v252 = qcar(v252);
    stack[-4] = v252;
    v252 = stack[-3];
    v252 = qcar(v252);
    stack[-3] = v252;
    v253 = stack[-3];
    v252 = elt(env, 1); /* false */
    if (v253 == v252) goto v112;
    v253 = stack[-3];
    v252 = elt(env, 2); /* true */
    if (v253 == v252) goto v195;
    v252 = stack[-4];
    v252 = qcdr(v252);
    v253 = qcar(v252);
    v252 = stack[-3];
    v252 = qcdr(v252);
    v252 = qcar(v252);
    if (equal(v253, v252)) goto v190;
    v252 = stack[-4];
    v252 = qcdr(v252);
    v252 = qcar(v252);
    fn = elt(env, 8); /* pasf_dec */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    stack[-5] = v252;
    v252 = stack[-3];
    v252 = qcdr(v252);
    v252 = qcar(v252);
    fn = elt(env, 8); /* pasf_dec */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    stack[-2] = v252;
    v252 = stack[-5];
    v253 = qcar(v252);
    v252 = stack[-2];
    v252 = qcar(v252);
    if (equal(v253, v252)) goto v155;
    v252 = stack[-5];
    v253 = qcar(v252);
    v252 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 9); /* kernels1 */
    v252 = (*qfn2(fn))(qenv(fn), v253, v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    stack[0] = v252;
    v252 = stack[-2];
    v253 = qcar(v252);
    v252 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 9); /* kernels1 */
    v252 = (*qfn2(fn))(qenv(fn), v253, v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    v254 = v252;
    v252 = stack[-4];
    v253 = qcar(v252);
    v252 = elt(env, 5); /* equal */
    if (!(v253 == v252)) goto v259;
    v252 = stack[0];
    v252 = qcdr(v252);
    if (!(v252 == nil)) goto v259;
    v252 = stack[0];
    v253 = qcar(v252);
    v252 = v254;
    v252 = Lmemq(nil, v253, v252);
    if (v252 == nil) goto v259;
    stack[-2] = stack[-3];
    v252 = stack[0];
    stack[0] = qcar(v252);
    v252 = stack[-5];
    v252 = qcdr(v252);
    fn = elt(env, 10); /* negf */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    fn = elt(env, 11); /* pasf_subfof1 */
    v254 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    v253 = stack[-1];
    v252 = qvalue(elt(env, 6)); /* t */
    {
        popv(7);
        fn = elt(env, 12); /* pasf_susibinad1 */
        return (*qfnn(fn))(qenv(fn), 3, v254, v253, v252);
    }

v259:
    v252 = stack[-3];
    v253 = qcar(v252);
    v252 = elt(env, 5); /* equal */
    if (!(v253 == v252)) goto v260;
    v252 = v254;
    v252 = qcdr(v252);
    if (!(v252 == nil)) goto v260;
    v252 = v254;
    v253 = qcar(v252);
    v252 = stack[0];
    v252 = Lmemq(nil, v253, v252);
    if (v252 == nil) goto v260;
    stack[-3] = stack[-4];
    v252 = v254;
    stack[0] = qcar(v252);
    v252 = stack[-2];
    v252 = qcdr(v252);
    fn = elt(env, 10); /* negf */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    fn = elt(env, 11); /* pasf_subfof1 */
    v254 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v252);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-6];
    v253 = stack[-1];
    v252 = qvalue(elt(env, 4)); /* nil */
    {
        popv(7);
        fn = elt(env, 12); /* pasf_susibinad1 */
        return (*qfnn(fn))(qenv(fn), 3, v254, v253, v252);
    }

v260:
    v252 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v252); }

v155:
    v252 = stack[-4];
    v172 = qcar(v252);
    v252 = stack[-5];
    v257 = qcar(v252);
    v252 = stack[-5];
    v252 = qcdr(v252);
    if (v252 == nil) goto v166;
    v252 = stack[-5];
    v252 = qcdr(v252);
    v256 = v252;
    goto v200;

v200:
    v252 = stack[-3];
    v255 = qcar(v252);
    v252 = stack[-2];
    v254 = qcar(v252);
    v252 = stack[-2];
    v252 = qcdr(v252);
    if (v252 == nil) goto v261;
    v252 = stack[-2];
    v252 = qcdr(v252);
    v253 = v252;
    goto v61;

v61:
    v252 = stack[-1];
    {
        popv(7);
        fn = elt(env, 13); /* pasf_susibinord */
        return (*qfnn(fn))(qenv(fn), 7, v172, v257, v256, v255, v254, v253, v252);
    }

v261:
    v252 = (Lisp_Object)1; /* 0 */
    v253 = v252;
    goto v61;

v166:
    v252 = (Lisp_Object)1; /* 0 */
    v256 = v252;
    goto v200;

v190:
    v252 = stack[-4];
    v252 = qcdr(v252);
    v255 = qcar(v252);
    v252 = stack[-4];
    v254 = qcar(v252);
    v252 = stack[-3];
    v253 = qcar(v252);
    v252 = stack[-1];
    {
        popv(7);
        fn = elt(env, 14); /* pasf_susibineq */
        return (*qfnn(fn))(qenv(fn), 4, v255, v254, v253, v252);
    }

v195:
    v252 = elt(env, 3); /* (delete . t) */
    popv(7);
    return ncons(v252);

v112:
    v252 = elt(env, 1); /* false */
    { popv(7); return onevalue(v252); }
/* error exit handlers */
v258:
    popv(7);
    return nil;
}



/* Code for sets */

static Lisp_Object CC_sets(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sets");
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
    v176 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v176 = (*qfn1(fn))(qenv(fn), v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v176 = elt(env, 2); /* "<" */
    v176 = Lprinc(nil, v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v176 = stack[0];
    v176 = Lprinc(nil, v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v176 = elt(env, 3); /* "/>" */
    v176 = Lprinc(nil, v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v118 = qvalue(elt(env, 4)); /* indent */
    v176 = (Lisp_Object)49; /* 3 */
    v176 = plus2(v118, v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    qvalue(elt(env, 4)) = v176; /* indent */
    v176 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v176 = (*qfn1(fn))(qenv(fn), v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v118 = qvalue(elt(env, 4)); /* indent */
    v176 = (Lisp_Object)49; /* 3 */
    v176 = difference2(v118, v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    qvalue(elt(env, 4)) = v176; /* indent */
    v176 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v176 = (*qfn1(fn))(qenv(fn), v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    v176 = nil;
    { popv(3); return onevalue(v176); }
/* error exit handlers */
v191:
    popv(3);
    return nil;
}



/* Code for insertocc */

static Lisp_Object CC_insertocc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v138, v208;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertocc");
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
    v208 = v1;
    stack[-1] = v0;
/* end of prologue */
    v138 = v208;
    v85 = stack[-1];
    v85 = Lassoc(nil, v138, v85);
    stack[-2] = v85;
    if (v85 == nil) goto v263;
    stack[0] = v208;
    v85 = stack[-2];
    v85 = qcdr(v85);
    v85 = add1(v85);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    v208 = cons(stack[0], v85);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    v138 = stack[-2];
    v85 = stack[-1];
    v85 = Lsubst(nil, 3, v208, v138, v85);
    nil = C_nil;
    if (exception_pending()) goto v136;
    stack[-1] = v85;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v263:
    v138 = (Lisp_Object)17; /* 1 */
    v85 = stack[-1];
    v85 = acons(v208, v138, v85);
    nil = C_nil;
    if (exception_pending()) goto v136;
    stack[-1] = v85;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v136:
    popv(4);
    return nil;
}



/* Code for vdpcondense */

static Lisp_Object CC_vdpcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpcondense");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v0;
/* end of prologue */
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcar(v29);
    {
        fn = elt(env, 1); /* dipcondense */
        return (*qfn1(fn))(qenv(fn), v29);
    }
}



/* Code for gpexpp */

static Lisp_Object CC_gpexpp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexpp");
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

v4:
    v50 = stack[0];
    if (!consp(v50)) goto v29;
    v50 = stack[0];
    v144 = qcar(v50);
    v50 = elt(env, 2); /* (!:rd!: !:cr!: !:crn!: !:gi!:) */
    v50 = Lmemq(nil, v144, v50);
    if (v50 == nil) goto v187;
    v50 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v50); }

v187:
    v50 = stack[0];
    v144 = qcar(v50);
    v50 = elt(env, 4); /* plus */
    if (v144 == v50) goto v138;
    v50 = stack[0];
    v144 = qcar(v50);
    v50 = elt(env, 5); /* (minus recip) */
    v50 = Lmemq(nil, v144, v50);
    if (v50 == nil) goto v268;
    v50 = stack[0];
    v144 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    v50 = (Lisp_Object)33; /* 2 */
    if (v144 == v50) goto v269;
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v269:
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcar(v50);
    stack[0] = v50;
    goto v4;

v268:
    v50 = stack[0];
    v144 = qcar(v50);
    v50 = elt(env, 6); /* (difference quotient expt) */
    v50 = Lmemq(nil, v144, v50);
    if (v50 == nil) goto v270;
    v50 = stack[0];
    v144 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    v50 = (Lisp_Object)49; /* 3 */
    if (v144 == v50) goto v199;
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v199:
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v50 = CC_gpexpp(env, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    if (v50 == nil) goto v213;
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    stack[0] = v50;
    goto v4;

v213:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v270:
    v50 = stack[0];
    v144 = qcar(v50);
    v50 = elt(env, 7); /* times */
    if (v144 == v50) goto v90;
    v50 = stack[0];
    v144 = qcar(v50);
    v50 = elt(env, 8); /* !:rd!: */
    if (v144 == v50) goto v271;
    v50 = stack[0];
    v144 = qcar(v50);
    v50 = elt(env, 9); /* (!:cr!: !:crn!: !:gi!:) */
    v50 = Lmemq(nil, v144, v50);
    if (v50 == nil) goto v239;
    v50 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v50); }

v239:
    v50 = stack[0];
    v50 = qcar(v50);
    fn = elt(env, 10); /* unresidp */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    if (v50 == nil) goto v143;
    v50 = stack[0];
    v50 = qcdr(v50);
    {
        popv(2);
        fn = elt(env, 11); /* gparg1p */
        return (*qfn1(fn))(qenv(fn), v50);
    }

v143:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v271:
    v50 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v50); }

v90:
    v50 = stack[0];
    v144 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    v50 = (Lisp_Object)49; /* 3 */
    v50 = (Lisp_Object)geq2(v144, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    v50 = v50 ? lisp_true : nil;
    env = stack[-1];
    if (v50 == nil) goto v272;
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v50 = CC_gpexpp(env, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    if (v50 == nil) goto v152;
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v50 = CC_gpexpp(env, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    if (v50 == nil) goto v54;
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcdr(v50);
    v50 = qcdr(v50);
    {
        popv(2);
        fn = elt(env, 12); /* gpexp1p */
        return (*qfn1(fn))(qenv(fn), v50);
    }

v54:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v152:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v272:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v138:
    v50 = stack[0];
    v144 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    v50 = (Lisp_Object)33; /* 2 */
    v50 = (Lisp_Object)geq2(v144, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    v50 = v50 ? lisp_true : nil;
    env = stack[-1];
    if (v50 == nil) goto v229;
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcar(v50);
    v50 = CC_gpexpp(env, v50);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-1];
    if (v50 == nil) goto v137;
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = qcdr(v50);
    {
        popv(2);
        fn = elt(env, 12); /* gpexp1p */
        return (*qfn1(fn))(qenv(fn), v50);
    }

v137:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v229:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }

v29:
    v50 = stack[0];
    v50 = Lsymbolp(nil, v50);
    env = stack[-1];
    v144 = v50;
    if (!(v50 == nil)) { popv(2); return onevalue(v144); }
    v50 = stack[0];
    v50 = (is_number(v50) ? lisp_true : nil);
    v144 = v50;
    if (!(v50 == nil)) { popv(2); return onevalue(v144); }
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v50); }
/* error exit handlers */
v183:
    popv(2);
    return nil;
}



/* Code for indxsymp */

static Lisp_Object CC_indxsymp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v118;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indxsymp");
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

v273:
    v176 = stack[0];
    v176 = (v176 == nil ? lisp_true : nil);
    if (!(v176 == nil)) { popv(3); return onevalue(v176); }
    v176 = stack[0];
    v118 = qcar(v176);
    v176 = stack[-1];
    v176 = Lapply1(nil, v118, v176);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    if (v176 == nil) goto v83;
    v118 = stack[-1];
    v176 = stack[0];
    v176 = qcdr(v176);
    stack[-1] = v118;
    stack[0] = v176;
    goto v273;

v83:
    v176 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v176); }
/* error exit handlers */
v191:
    popv(3);
    return nil;
}



/* Code for termorder1 */

static Lisp_Object CC_termorder1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v113;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termorder1");
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

v4:
    v86 = stack[-1];
    if (v86 == nil) goto v29;
    v86 = stack[-1];
    v86 = (Lisp_Object)zerop(v86);
    v86 = v86 ? lisp_true : nil;
    env = stack[-2];
    if (v86 == nil) goto v107;
    v86 = stack[0];
    v86 = (Lisp_Object)zerop(v86);
    v86 = v86 ? lisp_true : nil;
    env = stack[-2];
    if (v86 == nil) goto v107;
    v86 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v86); }

v107:
    v86 = stack[-1];
    v86 = (Lisp_Object)zerop(v86);
    v86 = v86 ? lisp_true : nil;
    env = stack[-2];
    if (v86 == nil) goto v175;
    v86 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v86); }

v175:
    v86 = stack[0];
    v86 = (Lisp_Object)zerop(v86);
    v86 = v86 ? lisp_true : nil;
    env = stack[-2];
    if (v86 == nil) goto v118;
    v86 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v86); }

v118:
    v86 = stack[-1];
    v113 = qcar(v86);
    v86 = stack[0];
    v86 = qcar(v86);
    v86 = (Lisp_Object)lessp2(v113, v86);
    nil = C_nil;
    if (exception_pending()) goto v219;
    v86 = v86 ? lisp_true : nil;
    env = stack[-2];
    if (v86 == nil) goto v72;
    v86 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v86); }

v72:
    v86 = stack[-1];
    v113 = qcar(v86);
    v86 = stack[0];
    v86 = qcar(v86);
    v86 = (Lisp_Object)greaterp2(v113, v86);
    nil = C_nil;
    if (exception_pending()) goto v219;
    v86 = v86 ? lisp_true : nil;
    env = stack[-2];
    if (v86 == nil) goto v127;
    v86 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v86); }

v127:
    v86 = stack[-1];
    v86 = qcdr(v86);
    stack[-1] = v86;
    v86 = stack[0];
    v86 = qcdr(v86);
    stack[0] = v86;
    goto v4;

v29:
    v86 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v86); }
/* error exit handlers */
v219:
    popv(3);
    return nil;
}



/* Code for formproc */

static Lisp_Object MS_CDECL CC_formproc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v339, v340, v341, v342;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formproc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formproc");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v2;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* fname!* */
    qvalue(elt(env, 1)) = nil; /* fname!* */
    stack[-2] = nil;
    v339 = stack[-1];
    v339 = qcdr(v339);
    stack[-1] = v339;
    v339 = stack[-1];
    v339 = qcar(v339);
    qvalue(elt(env, 1)) = v339; /* fname!* */
    stack[-5] = v339;
    v339 = stack[-1];
    v339 = qcdr(v339);
    v339 = qcar(v339);
    if (v339 == nil) goto v211;
    v339 = stack[-1];
    v339 = qcdr(v339);
    v339 = qcar(v339);
    stack[-7] = v339;
    goto v211;

v211:
    v339 = stack[-1];
    v339 = qcdr(v339);
    v339 = qcdr(v339);
    stack[-1] = v339;
    v339 = stack[-1];
    v339 = qcar(v339);
    qvalue(elt(env, 2)) = v339; /* ftype!* */
    stack[-4] = v339;
    v339 = stack[-5];
    if (!symbolp(v339)) v339 = nil;
    else { v339 = qfastgets(v339);
           if (v339 != nil) { v339 = elt(v339, 1); /* lose */
#ifdef RECORD_GET
             if (v339 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v339 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v339 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v339 == SPID_NOPROP) v339 = nil; else v339 = lisp_true; }}
#endif
    if (v339 == nil) goto v74;
    v339 = qvalue(elt(env, 3)); /* !*lose */
    if (!(v339 == nil)) goto v191;
    v339 = qvalue(elt(env, 4)); /* !*defn */
    if (!(v339 == nil)) goto v74;

v191:
    v339 = qvalue(elt(env, 5)); /* !*msg */
    if (v339 == nil) goto v73;
    stack[0] = elt(env, 7); /* "***" */
    v340 = stack[-5];
    v339 = elt(env, 8); /* "not defined (LOSE flag)" */
    v339 = list2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v339 = (*qfn2(fn))(qenv(fn), stack[0], v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    goto v73;

v73:
    v339 = elt(env, 9); /* (quote nil) */
    goto v107;

v107:
    qvalue(elt(env, 1)) = stack[-6]; /* fname!* */
    { popv(10); return onevalue(v339); }

v74:
    v339 = qvalue(elt(env, 10)); /* !*redeflg!* */
    if (v339 == nil) goto v251;
    v339 = stack[-5];
    fn = elt(env, 39); /* getd */
    v339 = (*qfn1(fn))(qenv(fn), v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    if (v339 == nil) goto v251;
    v339 = qvalue(elt(env, 5)); /* !*msg */
    if (v339 == nil) goto v251;
    stack[-3] = elt(env, 7); /* "***" */
    v340 = stack[-5];
    v339 = elt(env, 11); /* "redefined" */
    v339 = list2(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v339 = (*qfn2(fn))(qenv(fn), stack[-3], v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    goto v251;

v251:
    v339 = stack[-1];
    v339 = qcdr(v339);
    v339 = qcar(v339);
    stack[-3] = v339;
    goto v108;

v108:
    v339 = stack[-3];
    if (v339 == nil) goto v192;
    v339 = stack[-3];
    v339 = qcar(v339);
    v339 = Lsymbol_specialp(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    if (!(v339 == nil)) goto v344;
    v339 = stack[-3];
    v339 = qcar(v339);
    v339 = Lsymbol_globalp(nil, v339);
    env = stack[-9];
    if (!(v339 == nil)) goto v344;

v268:
    v339 = stack[-3];
    v339 = qcdr(v339);
    stack[-3] = v339;
    goto v108;

v344:
    v339 = stack[-3];
    v340 = qcar(v339);
    v339 = stack[-2];
    v339 = cons(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-2] = v339;
    goto v268;

v192:
    v339 = stack[-1];
    v339 = qcdr(v339);
    v339 = qcar(v339);
    stack[-3] = v339;
    v339 = stack[-1];
    v339 = qcdr(v339);
    v339 = qcdr(v339);
    v339 = qcar(v339);
    stack[-8] = v339;
    v340 = stack[-8];
    v339 = elt(env, 12); /* rblock */
    if (!consp(v340)) goto v157;
    v340 = qcar(v340);
    if (!(v340 == v339)) goto v157;
    v339 = stack[-8];
    v339 = qcdr(v339);
    v339 = qcar(v339);
    goto v248;

v248:
    stack[-1] = v339;
    v342 = stack[-3];
    v341 = stack[-1];
    v340 = stack[0];
    v339 = stack[-7];
    fn = elt(env, 40); /* pairxvars */
    v339 = (*qfnn(fn))(qenv(fn), 4, v342, v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[0] = v339;
    v339 = stack[-1];
    if (v339 == nil) goto v55;
    v339 = stack[-8];
    stack[-1] = qcar(v339);
    v339 = stack[-8];
    v340 = qcdr(v339);
    v339 = stack[0];
    v339 = qcdr(v339);
    v339 = Lrplaca(nil, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = cons(stack[-1], v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    goto v55;

v55:
    v341 = stack[-8];
    v339 = stack[0];
    v340 = qcar(v339);
    v339 = stack[-7];
    fn = elt(env, 41); /* form1 */
    v339 = (*qfnn(fn))(qenv(fn), 3, v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    v339 = stack[-2];
    if (v339 == nil) goto v345;
    v340 = stack[-4];
    v339 = elt(env, 13); /* (expr fexpr macro) */
    v339 = Lmemq(nil, v340, v339);
    if (v339 == nil) goto v345;
    stack[-1] = elt(env, 14); /* progn */
    stack[0] = elt(env, 15); /* declare */
    v340 = elt(env, 16); /* special */
    v339 = stack[-2];
    v339 = cons(v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v340 = list2(stack[0], v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = stack[-8];
    v339 = list3(stack[-1], v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    goto v345;

v345:
    v339 = qvalue(elt(env, 17)); /* !*nosmacros */
    if (v339 == nil) goto v44;
    v340 = stack[-4];
    v339 = elt(env, 18); /* smacro */
    if (!(v340 == v339)) goto v44;
    v339 = elt(env, 19); /* expr */
    stack[-4] = v339;
    goto v44;

v44:
    v340 = stack[-4];
    v339 = elt(env, 18); /* smacro */
    if (v340 == v339) goto v38;
    v340 = stack[-5];
    v339 = elt(env, 18); /* smacro */
    v339 = get(v340, v339);
    env = stack[-9];
    if (v339 == nil) goto v38;
    v339 = qvalue(elt(env, 5)); /* !*msg */
    if (v339 == nil) goto v38;
    stack[0] = elt(env, 7); /* "***" */
    v341 = elt(env, 20); /* "SMACRO" */
    v340 = stack[-5];
    v339 = elt(env, 11); /* "redefined" */
    v339 = list3(v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    fn = elt(env, 38); /* lpriw */
    v339 = (*qfn2(fn))(qenv(fn), stack[0], v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    goto v38;

v38:
    v341 = stack[-3];
    v340 = stack[-8];
    v339 = stack[-7];
    fn = elt(env, 42); /* symbvarlst */
    v339 = (*qfnn(fn))(qenv(fn), 3, v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v340 = stack[-4];
    v339 = elt(env, 19); /* expr */
    if (v340 == v339) goto v31;
    v340 = stack[-4];
    v339 = elt(env, 22); /* fexpr */
    if (v340 == v339) goto v346;
    v340 = stack[-4];
    v339 = elt(env, 24); /* macro */
    if (v340 == v339) goto v347;
    v340 = stack[-4];
    v339 = elt(env, 26); /* procfn */
    v339 = get(v340, v339);
    env = stack[-9];
    stack[-1] = v339;
    if (v339 == nil) goto v17;
    v342 = stack[-1];
    v341 = stack[-5];
    v340 = stack[-3];
    v339 = stack[-8];
    v339 = Lapply3(nil, 4, v342, v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    goto v107;

v17:
    stack[-2] = elt(env, 27); /* putc */
    v339 = stack[-5];
    stack[-1] = Lmkquote(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = stack[-4];
    stack[0] = Lmkquote(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v341 = elt(env, 28); /* lambda */
    v340 = stack[-3];
    v339 = stack[-8];
    v339 = list3(v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = Lmkquote(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = list4(stack[-2], stack[-1], stack[0], v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    goto v348;

v348:
    v340 = stack[-7];
    v339 = elt(env, 29); /* symbolic */
    if (v340 == v339) goto v79;
    stack[-1] = elt(env, 30); /* flag */
    v339 = stack[-5];
    v339 = ncons(v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[0] = Lmkquote(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = elt(env, 31); /* opfn */
    v339 = Lmkquote(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v340 = list3(stack[-1], stack[0], v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = stack[-8];
    fn = elt(env, 43); /* mkprogn */
    v339 = (*qfn2(fn))(qenv(fn), v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    goto v79;

v79:
    v339 = qvalue(elt(env, 32)); /* !*argnochk */
    if (v339 == nil) goto v349;
    v340 = stack[-4];
    v339 = elt(env, 33); /* (expr smacro) */
    v339 = Lmemq(nil, v340, v339);
    if (v339 == nil) goto v349;
    stack[-1] = elt(env, 34); /* put */
    v339 = stack[-5];
    stack[-2] = Lmkquote(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = elt(env, 35); /* number!-of!-args */
    stack[0] = Lmkquote(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = stack[-3];
    v339 = Llength(nil, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v340 = list4(stack[-1], stack[-2], stack[0], v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    v339 = stack[-8];
    fn = elt(env, 43); /* mkprogn */
    v339 = (*qfn2(fn))(qenv(fn), v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    goto v349;

v349:
    v339 = qvalue(elt(env, 4)); /* !*defn */
    if (v339 == nil) goto v350;
    v340 = stack[-4];
    v339 = elt(env, 36); /* (fexpr macro smacro) */
    v339 = Lmemq(nil, v340, v339);
    if (v339 == nil) goto v350;
    v339 = stack[-8];
    fn = elt(env, 44); /* eval */
    v339 = (*qfn1(fn))(qenv(fn), v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    goto v350;

v350:
    v339 = qvalue(elt(env, 37)); /* !*micro!-version */
    if (v339 == nil) goto v351;
    v340 = stack[-4];
    v339 = elt(env, 36); /* (fexpr macro smacro) */
    v339 = Lmemq(nil, v340, v339);
    if (v339 == nil) goto v351;
    v339 = qvalue(elt(env, 6)); /* nil */
    goto v107;

v351:
    v339 = stack[-8];
    goto v107;

v347:
    v342 = elt(env, 25); /* dm */
    v341 = stack[-5];
    v340 = stack[-3];
    v339 = stack[-8];
    v339 = list4(v342, v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    goto v348;

v346:
    v342 = elt(env, 23); /* df */
    v341 = stack[-5];
    v340 = stack[-3];
    v339 = stack[-8];
    v339 = list4(v342, v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    goto v348;

v31:
    v342 = elt(env, 21); /* de */
    v341 = stack[-5];
    v340 = stack[-3];
    v339 = stack[-8];
    v339 = list4(v342, v341, v340, v339);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-9];
    stack[-8] = v339;
    goto v348;

v157:
    v339 = qvalue(elt(env, 6)); /* nil */
    goto v248;
/* error exit handlers */
v343:
    env = stack[-9];
    qvalue(elt(env, 1)) = stack[-6]; /* fname!* */
    popv(10);
    return nil;
}



/* Code for fs!:minusp */

static Lisp_Object CC_fsTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v196, v263;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v196 = v0;
/* end of prologue */

v3:
    v195 = v196;
    if (v195 == nil) goto v10;
    v263 = v196;
    v195 = (Lisp_Object)49; /* 3 */
    v195 = *(Lisp_Object *)((char *)v263 + (CELL-TAG_VECTOR) + ((int32_t)v195/(16/CELL)));
    if (v195 == nil) goto v77;
    v195 = (Lisp_Object)49; /* 3 */
    v195 = *(Lisp_Object *)((char *)v196 + (CELL-TAG_VECTOR) + ((int32_t)v195/(16/CELL)));
    v196 = v195;
    goto v3;

v77:
    v195 = (Lisp_Object)1; /* 0 */
    v195 = *(Lisp_Object *)((char *)v196 + (CELL-TAG_VECTOR) + ((int32_t)v195/(16/CELL)));
    v195 = qcar(v195);
    {
        fn = elt(env, 2); /* minusf */
        return (*qfn1(fn))(qenv(fn), v195);
    }

v10:
    v195 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v195);
}



/* Code for simp!-prop!-dist */

static Lisp_Object CC_simpKpropKdist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v87, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-dist");
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
    v87 = v0;
/* end of prologue */
    v197 = v87;
    v166 = elt(env, 1); /* plus */
    if (!consp(v197)) goto v139;
    v197 = qcar(v197);
    if (!(v197 == v166)) goto v139;
    v166 = v87;
    v166 = qcdr(v166);
    v87 = v166;
    goto v129;

v129:
    v166 = v87;
    stack[-3] = v166;
    v166 = stack[-3];
    if (v166 == nil) goto v112;
    v166 = stack[-3];
    v166 = qcar(v166);
    v197 = v166;
    v87 = v197;
    v166 = elt(env, 3); /* times */
    if (!consp(v87)) goto v188;
    v87 = qcar(v87);
    if (!(v87 == v166)) goto v188;
    v166 = v197;
    v166 = qcdr(v166);
    goto v74;

v74:
    v197 = v166;
    v166 = v197;
    v166 = qcar(v166);
    if (!(is_number(v166))) goto v113;
    v166 = v197;
    v166 = qcdr(v166);
    v197 = v166;
    goto v113;

v113:
    v87 = v197;
    v166 = elt(env, 4); /* lambda_l9cw2v_7 */
    fn = elt(env, 7); /* sort */
    v166 = (*qfn2(fn))(qenv(fn), v87, v166);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[-1] = v166;
    stack[-2] = v166;
    goto v109;

v109:
    v166 = stack[-3];
    v166 = qcdr(v166);
    stack[-3] = v166;
    v166 = stack[-3];
    if (v166 == nil) goto v207;
    stack[0] = stack[-1];
    v166 = stack[-3];
    v166 = qcar(v166);
    v197 = v166;
    v87 = v197;
    v166 = elt(env, 3); /* times */
    if (!consp(v87)) goto v121;
    v87 = qcar(v87);
    if (!(v87 == v166)) goto v121;
    v166 = v197;
    v166 = qcdr(v166);
    goto v206;

v206:
    v197 = v166;
    v166 = v197;
    v166 = qcar(v166);
    if (!(is_number(v166))) goto v178;
    v166 = v197;
    v166 = qcdr(v166);
    v197 = v166;
    goto v178;

v178:
    v87 = v197;
    v166 = elt(env, 5); /* lambda_l9cw2v_8 */
    fn = elt(env, 7); /* sort */
    v166 = (*qfn2(fn))(qenv(fn), v87, v166);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v166 = Lrplacd(nil, stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v166 = stack[-1];
    v166 = qcdr(v166);
    stack[-1] = v166;
    goto v109;

v121:
    v166 = v197;
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v206;

v207:
    v166 = stack[-2];
    goto v77;

v77:
    v87 = v166;
    v166 = elt(env, 6); /* simp!-prop!-order */
    {
        popv(5);
        fn = elt(env, 7); /* sort */
        return (*qfn2(fn))(qenv(fn), v87, v166);
    }

v188:
    v166 = v197;
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    goto v74;

v112:
    v166 = qvalue(elt(env, 2)); /* nil */
    goto v77;

v139:
    v166 = v87;
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v87 = v166;
    goto v129;
/* error exit handlers */
v162:
    popv(5);
    return nil;
}



/* Code for lambda_l9cw2v_8 */

static Lisp_Object CC_lambda_l9cw2v_8(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9cw2v_8");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v192 = v1;
    v139 = v0;
/* end of prologue */
    v139 = qcdr(v139);
    v139 = qcar(v139);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v139, v192);
    }
}



/* Code for lambda_l9cw2v_7 */

static Lisp_Object CC_lambda_l9cw2v_7(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9cw2v_7");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v192 = v1;
    v139 = v0;
/* end of prologue */
    v139 = qcdr(v139);
    v139 = qcar(v139);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v139, v192);
    }
}



/* Code for fd2q */

static Lisp_Object CC_fd2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fd2q");
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

v3:
    v231 = stack[0];
    if (!consp(v231)) goto v130;
    v231 = stack[0];
    v203 = qcar(v231);
    v231 = elt(env, 1); /* !:ar!: */
    if (v203 == v231) goto v194;
    v231 = stack[0];
    v203 = qcar(v231);
    v231 = elt(env, 2); /* !:rn!: */
    if (v203 == v231) goto v133;
    v231 = stack[0];
    v231 = qcar(v231);
    v203 = qcar(v231);
    v231 = (Lisp_Object)17; /* 1 */
    v231 = cons(v203, v231);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v203 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v231 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v203, v231);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v231 = stack[0];
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v231 = CC_fd2q(env, v231);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    fn = elt(env, 3); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v231);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    v231 = stack[0];
    v231 = qcdr(v231);
    v231 = CC_fd2q(env, v231);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    {
        Lisp_Object v68 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v68, v231);
    }

v133:
    v231 = stack[0];
    v231 = qcdr(v231);
    { popv(3); return onevalue(v231); }

v194:
    v231 = stack[0];
    v231 = qcdr(v231);
    stack[0] = v231;
    goto v3;

v130:
    v203 = stack[0];
    v231 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v203, v231);
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for msolve!-psys1 */

static Lisp_Object CC_msolveKpsys1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v356, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-psys1");
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
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    v356 = qvalue(elt(env, 1)); /* nil */
    v356 = ncons(v356);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v61 = v356;
    v356 = stack[0];
    stack[-4] = v356;
    goto v108;

v108:
    v356 = stack[-4];
    if (v356 == nil) { popv(8); return onevalue(v61); }
    v356 = stack[-4];
    v356 = qcar(v356);
    stack[-3] = v356;
    v356 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v356;
    v356 = v61;
    stack[-2] = v356;
    goto v112;

v112:
    v356 = stack[-2];
    if (v356 == nil) goto v111;
    v356 = stack[-2];
    v356 = qcar(v356);
    stack[-1] = v356;
    v61 = stack[-3];
    v356 = stack[-1];
    fn = elt(env, 2); /* subf */
    v356 = (*qfn2(fn))(qenv(fn), v61, v356);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v356 = qcar(v356);
    fn = elt(env, 3); /* moduntag */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    fn = elt(env, 4); /* general!-reduce!-mod!-p */
    v356 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v61 = v356;
    v356 = v61;
    if (v356 == nil) goto v127;
    v356 = v61;
    if (!consp(v356)) goto v85;
    v356 = v61;
    v356 = qcar(v356);
    if (!consp(v356)) goto v85;
    v356 = stack[-5];
    fn = elt(env, 5); /* msolve!-poly */
    v356 = (*qfn2(fn))(qenv(fn), v61, v356);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[0] = v356;
    goto v193;

v193:
    v356 = stack[0];
    if (v356 == nil) goto v85;
    v356 = stack[0];
    v356 = qcar(v356);
    v61 = stack[-1];
    v61 = Lappend(nil, v61, v356);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v356 = stack[-6];
    v356 = cons(v61, v356);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[-6] = v356;
    v356 = stack[0];
    v356 = qcdr(v356);
    stack[0] = v356;
    goto v193;

v85:
    v356 = stack[-2];
    v356 = qcdr(v356);
    stack[-2] = v356;
    goto v112;

v127:
    v61 = stack[-1];
    v356 = stack[-6];
    v356 = cons(v61, v356);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[-6] = v356;
    goto v85;

v111:
    v356 = stack[-6];
    v61 = v356;
    v356 = stack[-4];
    v356 = qcdr(v356);
    stack[-4] = v356;
    goto v108;
/* error exit handlers */
v64:
    popv(8);
    return nil;
}



/* Code for solvealgdepends */

static Lisp_Object CC_solvealgdepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgdepends");
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

v130:
    v126 = stack[-1];
    v223 = stack[0];
    if (equal(v126, v223)) goto v5;
    v223 = stack[-1];
    if (!consp(v223)) goto v262;
    v126 = stack[-1];
    v223 = elt(env, 3); /* root_of */
    if (!consp(v126)) goto v114;
    v126 = qcar(v126);
    if (!(v126 == v223)) goto v114;
    v126 = stack[0];
    v223 = stack[-1];
    v223 = qcdr(v223);
    v223 = qcdr(v223);
    v223 = qcar(v223);
    if (equal(v126, v223)) goto v117;
    v223 = stack[-1];
    v223 = qcdr(v223);
    v223 = qcar(v223);
    stack[-1] = v223;
    goto v130;

v117:
    v223 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v223); }

v114:
    v223 = stack[-1];
    v126 = qcar(v223);
    v223 = stack[0];
    v223 = CC_solvealgdepends(env, v126, v223);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-2];
    v126 = v223;
    if (!(v223 == nil)) { popv(3); return onevalue(v126); }
    v223 = stack[-1];
    v126 = qcdr(v223);
    v223 = stack[0];
    v223 = CC_solvealgdepends(env, v126, v223);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-2];
    v126 = v223;
    if (!(v223 == nil)) { popv(3); return onevalue(v126); }
    v223 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v223); }

v262:
    v223 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v223); }

v5:
    v223 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v223); }
/* error exit handlers */
v168:
    popv(3);
    return nil;
}



/* Code for get!-height */

static Lisp_Object CC_getKheight(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-height");
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
    v111 = stack[0];
    if (v111 == nil) goto v3;
    v111 = stack[0];
    if (is_number(v111)) goto v29;
    v111 = stack[0];
    v111 = qcar(v111);
    v111 = qcdr(v111);
    stack[-1] = CC_getKheight(env, v111);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    v111 = stack[0];
    v111 = qcdr(v111);
    v111 = CC_getKheight(env, v111);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-2];
    {
        Lisp_Object v132 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* max */
        return (*qfn2(fn))(qenv(fn), v132, v111);
    }

v29:
    v111 = stack[0];
        popv(3);
        return Labsval(nil, v111);

v3:
    v111 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v111); }
/* error exit handlers */
v131:
    popv(3);
    return nil;
}



/* Code for afactor */

static Lisp_Object CC_afactor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for afactor");
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
    stack[-4] = qvalue(elt(env, 1)); /* afactorvar */
    qvalue(elt(env, 1)) = nil; /* afactorvar */
    stack[-1] = qvalue(elt(env, 2)); /* !*noextend */
    qvalue(elt(env, 2)) = nil; /* !*noextend */
    stack[0] = qvalue(elt(env, 3)); /* !*sqfree */
    qvalue(elt(env, 3)) = nil; /* !*sqfree */
    v203 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v203; /* !*noextend */
    v203 = stack[-2];
    qvalue(elt(env, 1)) = v203; /* afactorvar */
    v203 = qvalue(elt(env, 5)); /* !*trfield */
    if (v203 == nil) goto v130;
    v203 = elt(env, 6); /* "We must factorise the following over: " */
    v203 = Lprinc(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v203 = qvalue(elt(env, 7)); /* listofnewsqrts */
    stack[-2] = v203;
    goto v210;

v210:
    v203 = stack[-2];
    if (v203 == nil) goto v262;
    v203 = stack[-2];
    v203 = qcar(v203);
    v203 = Lprinc(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v203 = elt(env, 9); /* " " */
    v203 = Lprinc(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v203 = stack[-2];
    v203 = qcdr(v203);
    stack[-2] = v203;
    goto v210;

v262:
    v203 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v203 = stack[-3];
    if (v203 == nil) goto v187;
    v203 = stack[-3];
    fn = elt(env, 11); /* xprinf2 */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    goto v75;

v75:
    v203 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* terpri!* */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    goto v130;

v130:
    v203 = stack[-3];
    fn = elt(env, 13); /* algfactor */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    stack[-2] = v203;
    v203 = qvalue(elt(env, 5)); /* !*trfield */
    if (v203 == nil) goto v209;
    v203 = elt(env, 10); /* "factorizes as " */
    v203 = Lprintc(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v203 = stack[-2];
    stack[-3] = v203;
    goto v190;

v190:
    v203 = stack[-3];
    if (v203 == nil) goto v209;
    v203 = stack[-3];
    v203 = qcar(v203);
    fn = elt(env, 14); /* printsf */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    v203 = stack[-3];
    v203 = qcdr(v203);
    stack[-3] = v203;
    goto v190;

v209:
    v203 = stack[-2];
    qvalue(elt(env, 3)) = stack[0]; /* !*sqfree */
    qvalue(elt(env, 2)) = stack[-1]; /* !*noextend */
    qvalue(elt(env, 1)) = stack[-4]; /* afactorvar */
    { popv(6); return onevalue(v203); }

v187:
    v203 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* prin2!* */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-5];
    goto v75;
/* error exit handlers */
v168:
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[0]; /* !*sqfree */
    qvalue(elt(env, 2)) = stack[-1]; /* !*noextend */
    qvalue(elt(env, 1)) = stack[-4]; /* afactorvar */
    popv(6);
    return nil;
}



/* Code for cl_bnfsimpl */

static Lisp_Object CC_cl_bnfsimpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v262, v210, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_bnfsimpl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v210 = v1;
    v211 = v0;
/* end of prologue */
    v262 = qvalue(elt(env, 1)); /* !*rlbnfsac */
    if (v262 == nil) return onevalue(v211);
    v262 = v211;
    {
        fn = elt(env, 2); /* cl_sac */
        return (*qfn2(fn))(qenv(fn), v262, v210);
    }
}



/* Code for aex_neg */

static Lisp_Object CC_aex_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_neg");
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
    v211 = stack[-2];
    fn = elt(env, 1); /* aex_ex */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    fn = elt(env, 2); /* ratpoly_neg */
    stack[-3] = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    v211 = stack[-2];
    fn = elt(env, 3); /* aex_ctx */
    stack[-1] = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    v211 = stack[-2];
    fn = elt(env, 4); /* aex_lcnttag */
    stack[0] = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    v211 = stack[-2];
    fn = elt(env, 5); /* aex_reducedtag */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    {
        Lisp_Object v123 = stack[-3];
        Lisp_Object v111 = stack[-1];
        Lisp_Object v112 = stack[0];
        popv(5);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v123, v111, v112, v211);
    }
/* error exit handlers */
v110:
    popv(5);
    return nil;
}



/* Code for listrd */

static Lisp_Object MS_CDECL CC_listrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v269, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "listrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listrd");
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
    v269 = qvalue(elt(env, 1)); /* atts */
    v206 = elt(env, 2); /* (o r d e r) */
    fn = elt(env, 11); /* search_att */
    v206 = (*qfn2(fn))(qenv(fn), v269, v206);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    stack[-1] = v206;
    v206 = elt(env, 3); /* (t y p e != l i s t !$) */
    qvalue(elt(env, 1)) = v206; /* atts */
    stack[0] = elt(env, 4); /* list */
    fn = elt(env, 12); /* stats_getargs */
    v206 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    v206 = cons(stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    v269 = v206;
    stack[0] = v269;
    v224 = stack[-1];
    v269 = elt(env, 5); /* (l e x i c o g r a p h i c) */
    if (!(equal(v224, v269))) goto v188;
    v269 = elt(env, 6); /* sortlist */
    v224 = v206;
    v206 = elt(env, 7); /* lexog */
    v206 = list3(v269, v224, v206);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    goto v188;

v188:
    v224 = stack[-1];
    v269 = elt(env, 8); /* (n u m e r i c) */
    if (equal(v224, v269)) goto v114;
    v224 = elt(env, 6); /* sortlist */
    v269 = v206;
    v206 = elt(env, 10); /* pred */
    v206 = list3(v224, v269, v206);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v116;
    goto v73;

v73:
    v269 = v206;
    if (!(v269 == nil)) { popv(3); return onevalue(v206); }
    v206 = stack[0];
    { popv(3); return onevalue(v206); }

v114:
    v224 = elt(env, 6); /* sortlist */
    v269 = v206;
    v206 = elt(env, 9); /* numer */
    v206 = list3(v224, v269, v206);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    fn = elt(env, 13); /* aeval */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v116;
    goto v73;
/* error exit handlers */
v116:
    popv(3);
    return nil;
}



/* Code for plusrd */

static Lisp_Object MS_CDECL CC_plusrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "plusrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plusrd");
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
    v175 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    v76 = v175;
    v175 = v76;
    if (v175 == nil) goto v29;
    stack[0] = v76;
    v175 = CC_plusrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    {
        Lisp_Object v110 = stack[0];
        popv(2);
        fn = elt(env, 3); /* alg_plus */
        return (*qfn2(fn))(qenv(fn), v110, v175);
    }

v29:
    v175 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v175); }
/* error exit handlers */
v109:
    popv(2);
    return nil;
}



/* Code for bfminus */

static Lisp_Object CC_bfminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfminus");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v123 = stack[0];
    if (!consp(v123)) goto v3;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v123 = stack[0];
    v123 = qcdr(v123);
    v123 = qcar(v123);
    v111 = negate(v123);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v123 = stack[0];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    {
        Lisp_Object v132 = stack[-1];
        popv(2);
        return list2star(v132, v111, v123);
    }

v3:
    v123 = stack[0];
    popv(2);
    return negate(v123);
/* error exit handlers */
v131:
    popv(2);
    return nil;
}



/* Code for findoptrow */

static Lisp_Object MS_CDECL CC_findoptrow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v358, v359, v360;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findoptrow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findoptrow");
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
    stack[-5] = v2;
    stack[0] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    stack[-2] = stack[0];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v358 = qvalue(elt(env, 2)); /* maxvar */
    v150 = stack[-6];
    v150 = plus2(v358, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    v358 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v150/(16/CELL)));
    v150 = (Lisp_Object)65; /* 4 */
    v150 = *(Lisp_Object *)((char *)v358 + (CELL-TAG_VECTOR) + ((int32_t)v150/(16/CELL)));
    fn = elt(env, 8); /* pnthxzz */
    v150 = (*qfn2(fn))(qenv(fn), stack[-2], v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    v150 = qcar(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    stack[-3] = v150;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v358 = qvalue(elt(env, 2)); /* maxvar */
    v150 = stack[0];
    v150 = plus2(v358, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    v358 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v150/(16/CELL)));
    v150 = (Lisp_Object)65; /* 4 */
    v150 = *(Lisp_Object *)((char *)v358 + (CELL-TAG_VECTOR) + ((int32_t)v150/(16/CELL)));
    stack[-2] = v150;
    goto v120;

v120:
    v150 = stack[-2];
    if (v150 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    v150 = stack[-2];
    v150 = qcar(v150);
    stack[-1] = v150;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v358 = qvalue(elt(env, 2)); /* maxvar */
    v150 = stack[-1];
    v150 = qcar(v150);
    stack[-4] = v150;
    v150 = plus2(v358, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    v358 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v150/(16/CELL)));
    v150 = (Lisp_Object)1; /* 0 */
    v150 = *(Lisp_Object *)((char *)v358 + (CELL-TAG_VECTOR) + ((int32_t)v150/(16/CELL)));
    if (v150 == nil) goto v250;
    v360 = stack[-4];
    v359 = stack[-6];
    v150 = stack[-1];
    v150 = qcdr(v150);
    v358 = qcar(v150);
    v150 = stack[-3];
    fn = elt(env, 9); /* testpr */
    v150 = (*qfnn(fn))(qenv(fn), 4, v360, v359, v358, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    stack[0] = v150;
    v150 = qcdr(v150);
    if (v150 == nil) goto v64;
    v150 = stack[0];
    v358 = Llength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    stack[-1] = v358;
    v150 = stack[-5];
    v150 = (Lisp_Object)greaterp2(v358, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    v150 = v150 ? lisp_true : nil;
    env = stack[-8];
    if (v150 == nil) goto v362;
    v150 = stack[-1];
    stack[-5] = v150;
    qvalue(elt(env, 5)) = v150; /* newnjsi */
    v150 = stack[-4];
    stack[-7] = v150;
    v150 = stack[0];
    qvalue(elt(env, 6)) = v150; /* newjsi */
    goto v362;

v362:
    v358 = stack[-4];
    v150 = qvalue(elt(env, 7)); /* roccup2 */
    v150 = cons(v358, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    qvalue(elt(env, 7)) = v150; /* roccup2 */
    goto v53;

v53:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v358 = qvalue(elt(env, 2)); /* maxvar */
    v150 = stack[-4];
    v150 = plus2(v358, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    v359 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v150/(16/CELL)));
    v358 = (Lisp_Object)1; /* 0 */
    v150 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v359 + (CELL-TAG_VECTOR) + ((int32_t)v358/(16/CELL))) = v150;
    goto v250;

v250:
    v150 = stack[-2];
    v150 = qcdr(v150);
    stack[-2] = v150;
    goto v120;

v64:
    v358 = stack[-4];
    v150 = qvalue(elt(env, 4)); /* roccup1 */
    v150 = cons(v358, v150);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-8];
    qvalue(elt(env, 4)) = v150; /* roccup1 */
    goto v53;
/* error exit handlers */
v361:
    popv(9);
    return nil;
}



/* Code for critical_element */

static Lisp_Object CC_critical_element(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v107;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for critical_element");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v0;
/* end of prologue */
    v107 = v81;
    v107 = qcdr(v107);
    v107 = qcar(v107);
        return Lapply1(nil, v107, v81);
}



/* Code for gfftimes */

static Lisp_Object CC_gfftimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v190, v226;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfftimes");
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
    v190 = v1;
    v226 = v0;
/* end of prologue */
    v219 = v226;
    v219 = qcar(v219);
    stack[-4] = v219;
    v219 = v226;
    v219 = qcdr(v219);
    stack[-3] = v219;
    v219 = v190;
    v219 = qcar(v219);
    stack[-2] = v219;
    v219 = v190;
    v219 = qcdr(v219);
    stack[-1] = v219;
    v190 = stack[-4];
    v219 = stack[-2];
    stack[0] = times2(v190, v219);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    v190 = stack[-3];
    v219 = stack[-1];
    v219 = times2(v190, v219);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    stack[0] = difference2(stack[0], v219);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    v190 = stack[-4];
    v219 = stack[-1];
    stack[-1] = times2(v190, v219);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    v190 = stack[-3];
    v219 = stack[-2];
    v219 = times2(v190, v219);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-5];
    v219 = plus2(stack[-1], v219);
    nil = C_nil;
    if (exception_pending()) goto v207;
    {
        Lisp_Object v229 = stack[0];
        popv(6);
        return cons(v229, v219);
    }
/* error exit handlers */
v207:
    popv(6);
    return nil;
}



/* Code for reval3 */

static Lisp_Object CC_reval3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval3");
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
    v10 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v29:
    popv(1);
    return nil;
}



/* Code for deletez1 */

static Lisp_Object CC_deletez1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v135, v171, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deletez1");
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
    v188 = nil;
    goto v18;

v18:
    v73 = stack[-1];
    if (v73 == nil) goto v5;
    v171 = (Lisp_Object)1; /* 0 */
    v73 = stack[-1];
    v73 = qcar(v73);
    v135 = qcar(v73);
    v73 = stack[0];
    v73 = Lassoc(nil, v135, v73);
    v73 = qcdr(v73);
    if (v171 == v73) goto v108;
    v73 = stack[-1];
    v73 = qcar(v73);
    v135 = v188;
    v73 = cons(v73, v135);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-2];
    v188 = v73;
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    goto v18;

v108:
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    goto v18;

v5:
    v73 = v188;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v73);
    }
/* error exit handlers */
v208:
    popv(3);
    return nil;
}



setup_type const u31_setup[] =
{
    {"simpexpt1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt1},
    {"getargsrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_getargsrd},
    {"remdiff",                 CC_remdiff,     too_many_1,    wrong_no_1},
    {"suspend",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_suspend},
    {"matsm",                   CC_matsm,       too_many_1,    wrong_no_1},
    {"bcminus?",                CC_bcminusW,    too_many_1,    wrong_no_1},
    {"numprintlen",             CC_numprintlen, too_many_1,    wrong_no_1},
    {"indxchk",                 CC_indxchk,     too_many_1,    wrong_no_1},
    {"color-strand",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_colorKstrand},
    {"reduce-columns",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKcolumns},
    {"matop_pseudomod",         too_few_2,      CC_matop_pseudomod,wrong_no_2},
    {"pa_list2vect",            too_few_2,      CC_pa_list2vect,wrong_no_2},
    {"build-null-vector",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_buildKnullKvector},
    {"listeval0",               CC_listeval0,   too_many_1,    wrong_no_1},
    {"min2-order",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_min2Korder},
    {"evalnumberp",             CC_evalnumberp, too_many_1,    wrong_no_1},
    {"pasf_susibinad",          too_few_2,      CC_pasf_susibinad,wrong_no_2},
    {"sets",                    too_few_2,      CC_sets,       wrong_no_2},
    {"insertocc",               too_few_2,      CC_insertocc,  wrong_no_2},
    {"vdpcondense",             CC_vdpcondense, too_many_1,    wrong_no_1},
    {"gpexpp",                  CC_gpexpp,      too_many_1,    wrong_no_1},
    {"indxsymp",                too_few_2,      CC_indxsymp,   wrong_no_2},
    {"termorder1",              too_few_2,      CC_termorder1, wrong_no_2},
    {"formproc",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formproc},
    {"fs:minusp",               CC_fsTminusp,   too_many_1,    wrong_no_1},
    {"simp-prop-dist",          CC_simpKpropKdist,too_many_1,  wrong_no_1},
    {"lambda_l9cw2v_8",         too_few_2,      CC_lambda_l9cw2v_8,wrong_no_2},
    {"lambda_l9cw2v_7",         too_few_2,      CC_lambda_l9cw2v_7,wrong_no_2},
    {"fd2q",                    CC_fd2q,        too_many_1,    wrong_no_1},
    {"msolve-psys1",            too_few_2,      CC_msolveKpsys1,wrong_no_2},
    {"solvealgdepends",         too_few_2,      CC_solvealgdepends,wrong_no_2},
    {"get-height",              CC_getKheight,  too_many_1,    wrong_no_1},
    {"afactor",                 too_few_2,      CC_afactor,    wrong_no_2},
    {"cl_bnfsimpl",             too_few_2,      CC_cl_bnfsimpl,wrong_no_2},
    {"aex_neg",                 CC_aex_neg,     too_many_1,    wrong_no_1},
    {"listrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_listrd},
    {"plusrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_plusrd},
    {"bfminus",                 CC_bfminus,     too_many_1,    wrong_no_1},
    {"findoptrow",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_findoptrow},
    {"critical_element",        CC_critical_element,too_many_1,wrong_no_1},
    {"gfftimes",                too_few_2,      CC_gfftimes,   wrong_no_2},
    {"reval3",                  CC_reval3,      too_many_1,    wrong_no_1},
    {"deletez1",                too_few_2,      CC_deletez1,   wrong_no_2},
    {NULL, (one_args *)"u31", (two_args *)"6175 4073162 7391074", 0}
};

/* end of generated code */
