
/* $destdir\u06.c        Machine generated C code */

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


/* Code for physopp!* */

static Lisp_Object CC_physoppH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopp*");
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
    v8 = stack[0];
    fn = elt(env, 5); /* physopp */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    if (!(v8 == nil)) { popv(2); return onevalue(v8); }
    v8 = stack[0];
    if (!consp(v8)) goto v11;
    v8 = stack[0];
    v9 = qcar(v8);
    v8 = elt(env, 2); /* physopfn */
    v8 = Lflagp(nil, v9, v8);
    env = stack[-1];
    if (!(v8 == nil)) { popv(2); return onevalue(v8); }
    v8 = stack[0];
    v9 = qcar(v8);
    v8 = elt(env, 3); /* physoparith */
    v8 = Lflagp(nil, v9, v8);
    env = stack[-1];
    if (v8 == nil) goto v12;
    v8 = stack[0];
    v8 = qcdr(v8);
    fn = elt(env, 6); /* hasonephysop */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    goto v13;

v13:
    if (!(v8 == nil)) { popv(2); return onevalue(v8); }
    v8 = stack[0];
    v9 = qcar(v8);
    v8 = elt(env, 4); /* physopmapping */
    v8 = Lflagp(nil, v9, v8);
    env = stack[-1];
    if (v8 == nil) goto v14;
    v8 = stack[0];
    v8 = qcdr(v8);
    {
        popv(2);
        fn = elt(env, 6); /* hasonephysop */
        return (*qfn1(fn))(qenv(fn), v8);
    }

v14:
    v8 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v8); }

v12:
    v8 = qvalue(elt(env, 1)); /* nil */
    goto v13;

v11:
    v8 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v8); }
/* error exit handlers */
v10:
    popv(2);
    return nil;
}



/* Code for argnochk */

static Lisp_Object CC_argnochk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for argnochk");
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
    v30 = qvalue(elt(env, 1)); /* !*argnochk */
    if (v30 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v30 = stack[-3];
    v31 = qcar(v30);
    v30 = elt(env, 2); /* number!-of!-args */
    v30 = get(v31, v30);
    env = stack[-5];
    stack[-4] = v30;
    if (v30 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[0] = stack[-4];
    v30 = stack[-3];
    v30 = qcdr(v30);
    v30 = Llength(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    if (equal(stack[0], v30)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v30 = stack[-3];
    v31 = qcar(v30);
    v30 = elt(env, 3); /* simpfn */
    v30 = get(v31, v30);
    env = stack[-5];
    if (!(v30 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v30 = stack[-3];
    v31 = qcar(v30);
    v30 = elt(env, 4); /* psopfn */
    v30 = get(v31, v30);
    env = stack[-5];
    if (!(v30 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v30 = stack[-3];
    stack[-2] = qcar(v30);
    stack[-1] = elt(env, 5); /* "called with" */
    v30 = stack[-3];
    v30 = qcdr(v30);
    stack[0] = Llength(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v30 = stack[-3];
    v30 = qcdr(v30);
    v31 = Llength(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v30 = (Lisp_Object)17; /* 1 */
    if (v31 == v30) goto v34;
    v30 = elt(env, 7); /* "arguments" */
    v32 = v30;
    goto v35;

v35:
    v31 = elt(env, 8); /* "instead of" */
    v30 = stack[-4];
    v30 = list3(v32, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v30 = list3star(stack[-2], stack[-1], stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v31 = v30;
    v30 = v31;
    qvalue(elt(env, 9)) = v30; /* errmsg!* */
    v30 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v30 == nil)) goto v36;
    v30 = v31;
    fn = elt(env, 11); /* lprie */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    goto v36;

v36:
    v30 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v30 = nil;
    { popv(6); return onevalue(v30); }

v34:
    v30 = elt(env, 6); /* "argument" */
    v32 = v30;
    goto v35;
/* error exit handlers */
v33:
    popv(6);
    return nil;
}



/* Code for getelv */

static Lisp_Object CC_getelv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getelv");
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
    v45 = v0;
/* end of prologue */
    v44 = v45;
    stack[-4] = qcar(v44);
    v44 = v45;
    v44 = qcdr(v44);
    stack[-3] = v44;
    v44 = stack[-3];
    if (v44 == nil) goto v28;
    v44 = stack[-3];
    v44 = qcar(v44);
    fn = elt(env, 2); /* reval_without_mod */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-1] = v44;
    stack[-2] = v44;
    goto v47;

v47:
    v44 = stack[-3];
    v44 = qcdr(v44);
    stack[-3] = v44;
    v44 = stack[-3];
    if (v44 == nil) goto v48;
    stack[0] = stack[-1];
    v44 = stack[-3];
    v44 = qcar(v44);
    fn = elt(env, 2); /* reval_without_mod */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v44 = Lrplacd(nil, stack[0], v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v44 = stack[-1];
    v44 = qcdr(v44);
    stack[-1] = v44;
    goto v47;

v48:
    v44 = stack[-2];
    goto v49;

v49:
    v44 = cons(stack[-4], v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 3); /* getel */
        return (*qfn1(fn))(qenv(fn), v44);
    }

v28:
    v44 = qvalue(elt(env, 1)); /* nil */
    goto v49;
/* error exit handlers */
v46:
    popv(6);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v50;
    stack[-1] = v0;
/* end of prologue */
    v53 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v54 = stack[-1];
    v53 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v55;
    {
        Lisp_Object v6 = stack[-2];
        popv(4);
        return cons(v6, v53);
    }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for red_divtestbe */

static Lisp_Object MS_CDECL CC_red_divtestbe(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v50,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "red_divtestbe");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_divtestbe");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v50,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v50;
    stack[-2] = v0;
/* end of prologue */

v59:
    v58 = stack[-2];
    if (v58 == nil) goto v11;
    v58 = stack[-2];
    v58 = qcar(v58);
    fn = elt(env, 2); /* bas_dpecart */
    v39 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    v58 = stack[0];
    v58 = (Lisp_Object)lesseq2(v39, v58);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v58 = v58 ? lisp_true : nil;
    env = stack[-3];
    if (v58 == nil) goto v5;
    v58 = stack[-2];
    v58 = qcar(v58);
    fn = elt(env, 3); /* bas_dpoly */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    fn = elt(env, 4); /* dp_lmon */
    v39 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    v58 = stack[-1];
    fn = elt(env, 5); /* mo_vdivides!? */
    v58 = (*qfn2(fn))(qenv(fn), v39, v58);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-3];
    if (v58 == nil) goto v5;
    v58 = stack[-2];
    v58 = qcar(v58);
    { popv(4); return onevalue(v58); }

v5:
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    goto v59;

v11:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v58); }
/* error exit handlers */
v14:
    popv(4);
    return nil;
}



/* Code for gcdf!* */

static Lisp_Object CC_gcdfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v47, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf*");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v47 = v50;
    v51 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v62 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v62; /* !*gcd */
    v62 = v51;
    fn = elt(env, 3); /* gcdf */
    v62 = (*qfn2(fn))(qenv(fn), v62, v47);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v62); }
/* error exit handlers */
v53:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for maprint */

static Lisp_Object CC_maprint(Lisp_Object env,
                         Lisp_Object v50, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maprint");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v50);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v50,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v102 = v21;
    stack[-3] = v50;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* p!*!* */
    qvalue(elt(env, 1)) = nil; /* p!*!* */
    qvalue(elt(env, 1)) = v102; /* p!*!* */
    stack[0] = nil;
    v102 = qvalue(elt(env, 1)); /* p!*!* */
    stack[-2] = v102;
    v102 = stack[-3];
    if (v102 == nil) goto v47;
    v102 = stack[-3];
    if (!consp(v102)) goto v54;
    v102 = stack[-3];
    v102 = qcar(v102);
    if (!consp(v102)) goto v18;
    v102 = stack[-3];
    v103 = qcar(v102);
    v102 = stack[-2];
    v102 = CC_maprint(env, v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v62;

v62:
    v102 = elt(env, 5); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v102 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 12)) = v102; /* obrkp!* */
    v102 = qvalue(elt(env, 10)); /* orig!* */
    stack[0] = v102;
    v103 = qvalue(elt(env, 11)); /* posn!* */
    v102 = (Lisp_Object)289; /* 18 */
    v102 = (Lisp_Object)lessp2(v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v102 = v102 ? lisp_true : nil;
    env = stack[-5];
    if (v102 == nil) goto v106;
    v102 = qvalue(elt(env, 11)); /* posn!* */
    goto v107;

v107:
    qvalue(elt(env, 10)) = v102; /* orig!* */
    v102 = stack[-3];
    v102 = qcdr(v102);
    if (v102 == nil) goto v108;
    v104 = elt(env, 13); /* !*comma!* */
    v103 = (Lisp_Object)1; /* 0 */
    v102 = stack[-3];
    v102 = qcdr(v102);
    fn = elt(env, 16); /* inprint */
    v102 = (*qfnn(fn))(qenv(fn), 3, v104, v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v108;

v108:
    v102 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 12)) = v102; /* obrkp!* */
    v102 = stack[0];
    qvalue(elt(env, 10)) = v102; /* orig!* */
    v102 = elt(env, 6); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v102 = stack[-3];
    goto v59;

v59:
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    { popv(6); return onevalue(v102); }

v106:
    v103 = qvalue(elt(env, 10)); /* orig!* */
    v102 = (Lisp_Object)49; /* 3 */
    v102 = plus2(v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v107;

v18:
    v102 = stack[-3];
    v103 = qcar(v102);
    v102 = elt(env, 7); /* pprifn */
    v102 = get(v103, v102);
    env = stack[-5];
    stack[-1] = v102;
    if (v102 == nil) goto v109;
    v104 = stack[-1];
    v103 = stack[-3];
    v102 = stack[-2];
    v103 = Lapply2(nil, 3, v104, v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v102 = elt(env, 8); /* failed */
    if (!(v103 == v102)) goto v22;

v109:
    v102 = stack[-3];
    v103 = qcar(v102);
    v102 = elt(env, 9); /* prifn */
    v102 = get(v103, v102);
    env = stack[-5];
    stack[-1] = v102;
    if (v102 == nil) goto v110;
    v103 = stack[-1];
    v102 = stack[-3];
    v103 = Lapply1(nil, v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v102 = elt(env, 8); /* failed */
    if (!(v103 == v102)) goto v22;

v110:
    v102 = stack[-3];
    v103 = qcar(v102);
    v102 = elt(env, 4); /* infix */
    v102 = get(v103, v102);
    env = stack[-5];
    stack[-1] = v102;
    if (v102 == nil) goto v111;
    v103 = stack[-1];
    v102 = stack[-2];
    v102 = (Lisp_Object)greaterp2(v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v102 = v102 ? lisp_true : nil;
    env = stack[-5];
    v102 = (v102 == nil ? lisp_true : nil);
    stack[-2] = v102;
    v102 = stack[-2];
    if (v102 == nil) goto v112;
    v102 = qvalue(elt(env, 10)); /* orig!* */
    stack[0] = v102;
    v102 = elt(env, 5); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v103 = qvalue(elt(env, 11)); /* posn!* */
    v102 = (Lisp_Object)289; /* 18 */
    v102 = (Lisp_Object)lessp2(v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v102 = v102 ? lisp_true : nil;
    env = stack[-5];
    if (v102 == nil) goto v113;
    v102 = qvalue(elt(env, 11)); /* posn!* */
    goto v114;

v114:
    qvalue(elt(env, 10)) = v102; /* orig!* */
    goto v112;

v112:
    v102 = stack[-3];
    v104 = qcar(v102);
    v103 = stack[-1];
    v102 = stack[-3];
    v102 = qcdr(v102);
    fn = elt(env, 16); /* inprint */
    v102 = (*qfnn(fn))(qenv(fn), 3, v104, v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v102 = stack[-2];
    if (v102 == nil) goto v115;
    v102 = elt(env, 6); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v102 = stack[0];
    qvalue(elt(env, 10)) = v102; /* orig!* */
    goto v115;

v115:
    v102 = stack[-3];
    goto v59;

v113:
    v103 = qvalue(elt(env, 10)); /* orig!* */
    v102 = (Lisp_Object)49; /* 3 */
    v102 = plus2(v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v114;

v111:
    v102 = stack[-3];
    v102 = qcar(v102);
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v62;

v22:
    v102 = stack[-3];
    goto v59;

v54:
    v102 = stack[-3];
    v102 = Lsimple_vectorp(nil, v102);
    env = stack[-5];
    if (v102 == nil) goto v7;
    v103 = stack[-3];
    v102 = qvalue(elt(env, 1)); /* p!*!* */
    fn = elt(env, 17); /* vec!-maprin */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v55;

v55:
    v102 = stack[-3];
    goto v59;

v7:
    v102 = stack[-3];
    if (!(is_number(v102))) goto v57;
    v103 = stack[-3];
    v102 = (Lisp_Object)1; /* 0 */
    v102 = (Lisp_Object)lessp2(v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v102 = v102 ? lisp_true : nil;
    env = stack[-5];
    if (v102 == nil) goto v57;
    v104 = stack[-2];
    v103 = elt(env, 3); /* minus */
    v102 = elt(env, 4); /* infix */
    v102 = get(v103, v102);
    env = stack[-5];
    v102 = (Lisp_Object)lesseq2(v104, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v102 = v102 ? lisp_true : nil;
    env = stack[-5];
    if (!(v102 == nil)) goto v57;
    v102 = elt(env, 5); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v102 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    v102 = elt(env, 6); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v55;

v57:
    v102 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-5];
    goto v55;

v47:
    v102 = qvalue(elt(env, 2)); /* nil */
    goto v59;
/* error exit handlers */
v105:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    popv(6);
    return nil;
}



/* Code for pv_applp */

static Lisp_Object CC_pv_applp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_applp");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v50;
    v118 = v0;
/* end of prologue */
    stack[-5] = v118;
    v118 = stack[-5];
    if (v118 == nil) goto v42;
    v118 = stack[-5];
    v118 = qcar(v118);
    v119 = v118;
    v118 = v119;
    stack[0] = qcar(v118);
    v118 = v119;
    v119 = qcdr(v118);
    v118 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    v118 = cons(stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    stack[-2] = v118;
    stack[-3] = v118;
    goto v11;

v11:
    v118 = stack[-5];
    v118 = qcdr(v118);
    stack[-5] = v118;
    v118 = stack[-5];
    if (v118 == nil) goto v26;
    stack[-1] = stack[-2];
    v118 = stack[-5];
    v118 = qcar(v118);
    v119 = v118;
    v118 = v119;
    stack[0] = qcar(v118);
    v118 = v119;
    v119 = qcdr(v118);
    v118 = stack[-4];
    fn = elt(env, 2); /* pappl0 */
    v118 = (*qfn2(fn))(qenv(fn), v119, v118);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    v118 = cons(stack[0], v118);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    v118 = ncons(v118);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    v118 = Lrplacd(nil, stack[-1], v118);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-6];
    v118 = stack[-2];
    v118 = qcdr(v118);
    stack[-2] = v118;
    goto v11;

v26:
    v118 = stack[-3];
    goto v75;

v75:
    {
        popv(7);
        fn = elt(env, 3); /* pv_sort */
        return (*qfn1(fn))(qenv(fn), v118);
    }

v42:
    v118 = qvalue(elt(env, 1)); /* nil */
    goto v75;
/* error exit handlers */
v120:
    popv(7);
    return nil;
}



/* Code for raddf */

static Lisp_Object CC_raddf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raddf");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v50;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v59;

v59:
    v132 = stack[-2];
    if (v132 == nil) goto v42;
    v132 = stack[-1];
    if (v132 == nil) goto v55;
    v132 = stack[-2];
    if (!consp(v132)) goto v4;
    v132 = stack[-2];
    v132 = qcar(v132);
    if (!consp(v132)) goto v4;
    v132 = stack[-1];
    if (!consp(v132)) goto v46;
    v132 = stack[-1];
    v132 = qcar(v132);
    if (!consp(v132)) goto v46;
    v132 = stack[-2];
    v132 = qcar(v132);
    v133 = qcar(v132);
    v132 = stack[-1];
    v132 = qcar(v132);
    v132 = qcar(v132);
    if (equal(v133, v132)) goto v97;
    v132 = stack[-2];
    v132 = qcar(v132);
    v133 = qcar(v132);
    v132 = stack[-1];
    v132 = qcar(v132);
    v132 = qcar(v132);
    fn = elt(env, 1); /* ordpp */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    if (v132 == nil) goto v87;
    v132 = stack[-2];
    v133 = qcar(v132);
    v132 = stack[-3];
    v132 = cons(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[-3] = v132;
    v132 = stack[-2];
    v132 = qcdr(v132);
    stack[-2] = v132;
    goto v59;

v87:
    v132 = stack[-1];
    v133 = qcar(v132);
    v132 = stack[-3];
    v132 = cons(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[-3] = v132;
    v132 = stack[-1];
    v132 = qcdr(v132);
    stack[-1] = v132;
    goto v59;

v97:
    v132 = stack[-2];
    v132 = qcar(v132);
    stack[0] = qcar(v132);
    v132 = stack[-2];
    v132 = qcar(v132);
    v133 = qcdr(v132);
    v132 = stack[-1];
    v132 = qcar(v132);
    v132 = qcdr(v132);
    v133 = CC_raddf(env, v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v132 = stack[-3];
    v132 = acons(stack[0], v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[-3] = v132;
    v132 = stack[-2];
    v132 = qcdr(v132);
    stack[-2] = v132;
    v132 = stack[-1];
    v132 = qcdr(v132);
    stack[-1] = v132;
    goto v59;

v46:
    stack[0] = stack[-3];
    v133 = stack[-1];
    v132 = stack[-2];
    fn = elt(env, 2); /* addd */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    {
        Lisp_Object v135 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v135, v132);
    }

v4:
    stack[0] = stack[-3];
    v133 = stack[-2];
    v132 = stack[-1];
    fn = elt(env, 2); /* addd */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    {
        Lisp_Object v136 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v136, v132);
    }

v55:
    v133 = stack[-3];
    v132 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v133, v132);
    }

v42:
    v133 = stack[-3];
    v132 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v133, v132);
    }
/* error exit handlers */
v134:
    popv(5);
    return nil;
}



/* Code for msappend */

static Lisp_Object CC_msappend(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msappend");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v50;
    v142 = v0;
/* end of prologue */
    stack[-5] = v142;
    v142 = stack[-5];
    if (v142 == nil) goto v43;
    v142 = stack[-5];
    v142 = qcar(v142);
    stack[0] = stack[-4];
    v116 = stack[-4];
    v142 = Lsublis(nil, v116, v142);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = Lappend(nil, stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    stack[-2] = v142;
    stack[-3] = v142;
    goto v75;

v75:
    v142 = stack[-5];
    v142 = qcdr(v142);
    stack[-5] = v142;
    v142 = stack[-5];
    if (v142 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v142 = stack[-5];
    v142 = qcar(v142);
    stack[0] = stack[-4];
    v116 = stack[-4];
    v142 = Lsublis(nil, v116, v142);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = Lappend(nil, stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = Lrplacd(nil, stack[-1], v142);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-6];
    v142 = stack[-2];
    v142 = qcdr(v142);
    stack[-2] = v142;
    goto v75;

v43:
    v142 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v142); }
/* error exit handlers */
v143:
    popv(7);
    return nil;
}



/* Code for subs2f1 */

static Lisp_Object CC_subs2f1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v214, v215, v216, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2f1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0;
/* end of prologue */
    v213 = stack[-7];
    if (!consp(v213)) goto v60;
    v213 = stack[-7];
    v213 = qcar(v213);
    if (!consp(v213)) goto v60;
    stack[-3] = nil;
    v213 = stack[-7];
    v213 = qcar(v213);
    v213 = qcar(v213);
    v213 = qcar(v213);
    stack[-8] = v213;
    v214 = qvalue(elt(env, 1)); /* nil */
    v213 = (Lisp_Object)17; /* 1 */
    v213 = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-2] = v213;
    goto v219;

v219:
    v213 = stack[-7];
    if (v213 == nil) goto v55;
    v214 = stack[-7];
    v213 = stack[-8];
    fn = elt(env, 11); /* degr */
    v214 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = (Lisp_Object)1; /* 0 */
    if (v214 == v213) goto v55;
    v213 = stack[-7];
    v214 = qcar(v213);
    v213 = stack[-3];
    v213 = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-3] = v213;
    v213 = stack[-7];
    v213 = qcdr(v213);
    stack[-7] = v213;
    goto v219;

v55:
    v213 = qvalue(elt(env, 2)); /* powlis!* */
    stack[-4] = v213;
    goto v6;

v6:
    v213 = stack[-4];
    if (v213 == nil) goto v7;
    v213 = stack[-3];
    v213 = qcar(v213);
    v213 = qcar(v213);
    v214 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcar(v213);
    if (equal(v214, v213)) goto v127;
    v214 = stack[-8];
    v213 = elt(env, 3); /* expt */
    if (!consp(v214)) goto v143;
    v214 = qcar(v214);
    if (!(v214 == v213)) goto v143;
    v213 = stack[-8];
    v213 = qcdr(v213);
    v214 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcar(v213);
    if (!(equal(v214, v213))) goto v143;
    v213 = stack[-8];
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v214 = qcar(v213);
    v213 = elt(env, 4); /* quotient */
    if (!consp(v214)) goto v143;
    v214 = qcar(v214);
    if (!(v214 == v213)) goto v143;
    v213 = stack[-8];
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v214 = qcar(v213);
    v213 = (Lisp_Object)17; /* 1 */
    if (!(v214 == v213)) goto v143;
    v213 = stack[-8];
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    if (!(is_number(v213))) goto v143;
    v213 = stack[-3];
    v213 = qcar(v213);
    v213 = qcar(v213);
    v214 = qcdr(v213);
    v213 = stack[-8];
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    v213 = Ldivide(nil, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-6] = v213;
    v213 = stack[-6];
    v214 = qcar(v213);
    v213 = (Lisp_Object)1; /* 0 */
    if (v214 == v213) goto v220;
    v213 = stack[-8];
    v213 = qcdr(v213);
    v213 = qcar(v213);
    fn = elt(env, 12); /* simp */
    v214 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = stack[-6];
    v213 = qcar(v213);
    fn = elt(env, 13); /* exptsq */
    v213 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-5] = v213;
    goto v221;

v221:
    v213 = stack[-6];
    v214 = qcdr(v213);
    v213 = (Lisp_Object)1; /* 0 */
    if (v214 == v213) goto v222;
    stack[-1] = qvalue(elt(env, 5)); /* alglist!* */
    qvalue(elt(env, 5)) = nil; /* alglist!* */
    stack[0] = qvalue(elt(env, 6)); /* dmode!* */
    qvalue(elt(env, 6)) = nil; /* dmode!* */
    v213 = qvalue(elt(env, 1)); /* nil */
    v213 = ncons(v213);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-9];
    qvalue(elt(env, 5)) = v213; /* alglist!* */
    v213 = stack[-6];
    v214 = qcdr(v213);
    v213 = stack[-8];
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    v213 = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-9];
    fn = elt(env, 14); /* cancel */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-9];
    stack[-6] = v213;
    qvalue(elt(env, 6)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 5)) = stack[-1]; /* alglist!* */
    v213 = stack[-8];
    v213 = qcdr(v213);
    v214 = qcar(v213);
    v213 = stack[-6];
    v213 = qcar(v213);
    v215 = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v214 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    fn = elt(env, 15); /* subs2p */
    v213 = (*qfnn(fn))(qenv(fn), 3, v215, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    fn = elt(env, 16); /* mk!*sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v215 = elt(env, 4); /* quotient */
    v214 = (Lisp_Object)17; /* 1 */
    v213 = stack[-6];
    v213 = qcdr(v213);
    v213 = list3(v215, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = list2(stack[0], v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    fn = elt(env, 17); /* simpexpt */
    v214 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = stack[-5];
    fn = elt(env, 18); /* multsq */
    v213 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-5] = v213;
    goto v222;

v222:
    stack[0] = stack[-5];
    v213 = stack[-3];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = CC_subs2f1(env, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    fn = elt(env, 18); /* multsq */
    v214 = (*qfn2(fn))(qenv(fn), stack[0], v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = stack[-2];
    fn = elt(env, 19); /* addsq */
    v213 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-2] = v213;
    goto v13;

v13:
    v213 = stack[-3];
    v213 = qcdr(v213);
    stack[-3] = v213;
    v213 = stack[-3];
    if (!(v213 == nil)) goto v55;

v12:
    v213 = stack[-7];
    v213 = CC_subs2f1(env, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-3] = v213;
    v213 = qvalue(elt(env, 9)); /* !*exp */
    if (!(v213 == nil)) goto v224;
    v213 = stack[-3];
    v213 = qcar(v213);
    fn = elt(env, 20); /* mkprod */
    stack[0] = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = stack[-3];
    v213 = qcdr(v213);
    fn = elt(env, 20); /* mkprod */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = cons(stack[0], v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-3] = v213;
    goto v224;

v224:
    v214 = stack[-2];
    v213 = stack[-3];
    {
        popv(10);
        fn = elt(env, 19); /* addsq */
        return (*qfn2(fn))(qenv(fn), v214, v213);
    }

v220:
    v214 = (Lisp_Object)17; /* 1 */
    v213 = (Lisp_Object)17; /* 1 */
    v213 = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-5] = v213;
    goto v221;

v143:
    v213 = stack[-4];
    v213 = qcdr(v213);
    stack[-4] = v213;
    goto v6;

v127:
    v213 = stack[-3];
    v213 = qcar(v213);
    v215 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v214 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    fn = elt(env, 15); /* subs2p */
    v213 = (*qfnn(fn))(qenv(fn), 3, v215, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-5] = v213;
    goto v222;

v7:
    v213 = qvalue(elt(env, 7)); /* powlis1!* */
    stack[-4] = v213;
    goto v140;

v140:
    v213 = stack[-4];
    if (v213 == nil) goto v225;
    v213 = stack[-3];
    v213 = qcar(v213);
    v217 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v216 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v215 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    v214 = qcar(v213);
    v213 = stack[-4];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = qcar(v213);
    v213 = qcdr(v213);
    fn = elt(env, 21); /* mtchp */
    v213 = (*qfnn(fn))(qenv(fn), 5, v217, v216, v215, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-5] = v213;
    if (!(v213 == nil)) goto v222;
    v213 = stack[-4];
    v213 = qcdr(v213);
    stack[-4] = v213;
    goto v140;

v225:
    v214 = stack[-8];
    v213 = elt(env, 3); /* expt */
    if (!consp(v214)) goto v226;
    v214 = qcar(v214);
    if (!(v214 == v213)) goto v226;
    v213 = qvalue(elt(env, 8)); /* !*structure */
    if (!(v213 == nil)) goto v226;

v227:
    v213 = stack[-3];
    v213 = qcar(v213);
    v213 = qcar(v213);
    v214 = qcdr(v213);
    v213 = (Lisp_Object)17; /* 1 */
    if (!(v214 == v213)) goto v228;
    v213 = stack[-8];
    v213 = qcdr(v213);
    v214 = qcar(v213);
    v213 = elt(env, 3); /* expt */
    if (!consp(v214)) goto v229;
    v214 = qcar(v214);
    if (!(v214 == v213)) goto v229;

v228:
    v213 = stack[-8];
    v213 = qcdr(v213);
    stack[0] = qcar(v213);
    v215 = elt(env, 10); /* times */
    v213 = stack[-8];
    v213 = qcdr(v213);
    v213 = qcdr(v213);
    v214 = qcar(v213);
    v213 = stack[-3];
    v213 = qcar(v213);
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = list3(v215, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = list2(stack[0], v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    fn = elt(env, 17); /* simpexpt */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-5] = v213;
    goto v230;

v230:
    stack[0] = stack[-5];
    v213 = stack[-3];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = CC_subs2f1(env, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    fn = elt(env, 18); /* multsq */
    v214 = (*qfn2(fn))(qenv(fn), stack[0], v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = stack[-2];
    fn = elt(env, 19); /* addsq */
    v213 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-2] = v213;
    v213 = stack[-3];
    v213 = qcdr(v213);
    stack[-3] = v213;
    v213 = stack[-3];
    if (v213 == nil) goto v12;
    else goto v227;

v229:
    v214 = stack[-8];
    v213 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 22); /* mksq */
    v213 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-5] = v213;
    goto v230;

v226:
    v213 = stack[-3];
    v213 = qcar(v213);
    v214 = qcar(v213);
    v213 = (Lisp_Object)17; /* 1 */
    v213 = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v214 = ncons(v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = stack[-3];
    v213 = qcar(v213);
    v213 = qcdr(v213);
    v213 = CC_subs2f1(env, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    fn = elt(env, 18); /* multsq */
    v214 = (*qfn2(fn))(qenv(fn), stack[0], v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    v213 = stack[-2];
    fn = elt(env, 19); /* addsq */
    v213 = (*qfn2(fn))(qenv(fn), v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-9];
    stack[-2] = v213;
    goto v13;

v60:
    v213 = stack[-7];
    {
        popv(10);
        fn = elt(env, 23); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v213);
    }
/* error exit handlers */
v223:
    env = stack[-9];
    qvalue(elt(env, 6)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 5)) = stack[-1]; /* alglist!* */
    popv(10);
    return nil;
v218:
    popv(10);
    return nil;
}



/* Code for ibalp_commonlenisone */

static Lisp_Object CC_ibalp_commonlenisone(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_commonlenisone");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v50;
    stack[-1] = v0;
/* end of prologue */
    v7 = stack[-1];
    if (v7 == nil) goto v43;
    v7 = qvalue(elt(env, 1)); /* nil */
    goto v49;

v49:
    if (!(v7 == nil)) { popv(3); return onevalue(v7); }
    v7 = stack[0];
    if (v7 == nil) goto v29;
    v7 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v7); }

v29:
    v7 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* ibalp_lenisone */
        return (*qfn1(fn))(qenv(fn), v7);
    }

v43:
    v7 = stack[0];
    fn = elt(env, 2); /* ibalp_lenisone */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    goto v49;
/* error exit handlers */
v13:
    popv(3);
    return nil;
}



/* Code for ctx_new */

static Lisp_Object MS_CDECL CC_ctx_new(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ctx_new");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_new");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v61 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v61);
    }
}



/* Code for free!-powerp */

static Lisp_Object CC_freeKpowerp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for free-powerp");
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

v232:
    v231 = stack[0];
    if (!consp(v231)) goto v60;
    v231 = stack[0];
    v231 = qcar(v231);
    if (!consp(v231)) goto v60;
    v231 = stack[0];
    v231 = qcar(v231);
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v231 = integerp(v231);
    v231 = (v231 == nil ? lisp_true : nil);
    if (!(v231 == nil)) { popv(2); return onevalue(v231); }
    v231 = stack[0];
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v231 = CC_freeKpowerp(env, v231);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    if (!(v231 == nil)) { popv(2); return onevalue(v231); }
    v231 = stack[0];
    v231 = qcdr(v231);
    stack[0] = v231;
    goto v232;

v60:
    v231 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v231); }
/* error exit handlers */
v56:
    popv(2);
    return nil;
}



/* Code for rl_sacatlp */

static Lisp_Object CC_rl_sacatlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_sacatlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v52 = v50;
    v53 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacatlp!* */
    v52 = list2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    {
        Lisp_Object v29 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v29, v52);
    }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for mathml */

static Lisp_Object MS_CDECL CC_mathml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 2); /* lex */
    v49 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v75:
    popv(1);
    return nil;
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v208, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difff");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v50;
    stack[-2] = v0;
/* end of prologue */
    v239 = stack[-2];
    if (!consp(v239)) goto v11;
    v239 = stack[-2];
    v239 = qcar(v239);
    if (!consp(v239)) goto v28;
    v239 = stack[-2];
    v239 = qcar(v239);
    v208 = qcar(v239);
    v239 = (Lisp_Object)17; /* 1 */
    v239 = cons(v208, v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v208 = ncons(v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v239 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v208, v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v239 = stack[-2];
    v239 = qcar(v239);
    v208 = qcdr(v239);
    v239 = stack[-1];
    v239 = CC_difff(env, v208, v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v239 = stack[-2];
    v239 = qcar(v239);
    v208 = qcar(v239);
    v239 = stack[-1];
    fn = elt(env, 4); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v208, v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v239 = stack[-2];
    v239 = qcar(v239);
    v208 = qcdr(v239);
    v239 = (Lisp_Object)17; /* 1 */
    v239 = cons(v208, v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v239 = (*qfn2(fn))(qenv(fn), stack[0], v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    fn = elt(env, 5); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v239 = stack[-2];
    v208 = qcdr(v239);
    v239 = stack[-1];
    v239 = CC_difff(env, v208, v239);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    {
        Lisp_Object v241 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v241, v239);
    }

v28:
    v239 = stack[-2];
    v208 = qcar(v239);
    v239 = elt(env, 2); /* domain!-diff!-fn */
    v239 = get(v208, v239);
    env = stack[-4];
    v208 = v239;
    v239 = v208;
    if (v239 == nil) goto v14;
    v240 = v208;
    v208 = stack[-2];
    v239 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v240, v208, v239);

v14:
    v208 = qvalue(elt(env, 1)); /* nil */
    v239 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v208, v239);

v11:
    v208 = qvalue(elt(env, 1)); /* nil */
    v239 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v208, v239);
/* error exit handlers */
v86:
    popv(5);
    return nil;
}



/* Code for initbrsea */

static Lisp_Object MS_CDECL CC_initbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v33, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initbrsea");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initbrsea");
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
    v93 = (Lisp_Object)3201; /* 200 */
    stack[-2] = v93;
    v93 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v93;
    goto v47;

v47:
    v33 = qvalue(elt(env, 2)); /* rowmax */
    v93 = stack[-1];
    v93 = difference2(v33, v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    v93 = Lminusp(nil, v93);
    env = stack[-3];
    if (v93 == nil) goto v56;
    fn = elt(env, 8); /* redcodmat */
    v93 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    v93 = qvalue(elt(env, 6)); /* codhisto */
    if (v93 == nil) goto v237;
    v93 = (Lisp_Object)1; /* 0 */
    stack[0] = v93;
    goto v142;

v142:
    v33 = (Lisp_Object)3201; /* 200 */
    v93 = stack[0];
    v93 = difference2(v33, v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    v93 = Lminusp(nil, v93);
    env = stack[-3];
    if (!(v93 == nil)) goto v117;
    v245 = qvalue(elt(env, 6)); /* codhisto */
    v33 = stack[0];
    v93 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v245 + (CELL-TAG_VECTOR) + ((int32_t)v33/(16/CELL))) = v93;
    v93 = stack[0];
    v93 = add1(v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    stack[0] = v93;
    goto v142;

v117:
    v93 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v93; /* headhisto */
    v93 = (Lisp_Object)1; /* 0 */
    stack[0] = v93;
    goto v128;

v128:
    v33 = qvalue(elt(env, 2)); /* rowmax */
    v93 = stack[0];
    v93 = difference2(v33, v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    v93 = Lminusp(nil, v93);
    env = stack[-3];
    if (v93 == nil) goto v36;
    v93 = nil;
    { popv(4); return onevalue(v93); }

v36:
    v93 = stack[0];
    fn = elt(env, 9); /* inshisto */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    v93 = stack[0];
    v93 = add1(v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    stack[0] = v93;
    goto v128;

v237:
    v93 = stack[-2];
    v93 = Lmkvect(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    qvalue(elt(env, 6)) = v93; /* codhisto */
    goto v117;

v56:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v33 = qvalue(elt(env, 5)); /* maxvar */
    v93 = stack[-1];
    v93 = plus2(v33, v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    v33 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v93 = (Lisp_Object)1; /* 0 */
    v93 = *(Lisp_Object *)((char *)v33 + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    if (v93 == nil) goto v6;
    v93 = stack[-1];
    fn = elt(env, 10); /* initwght */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    goto v6;

v6:
    v93 = stack[-1];
    v93 = add1(v93);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    stack[-1] = v93;
    goto v47;
/* error exit handlers */
v246:
    popv(4);
    return nil;
}



/* Code for genp */

static Lisp_Object CC_genp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v55, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for genp");
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
    v55 = v0;
/* end of prologue */
    v219 = v55;
    if (!consp(v219)) goto v38;
    v219 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v219); }

v38:
    v6 = v55;
    v219 = elt(env, 2); /* gen */
    v219 = get(v6, v219);
    env = stack[0];
    if (!(v219 == nil)) { popv(1); return onevalue(v219); }
    v219 = v55;
    {
        popv(1);
        fn = elt(env, 3); /* mgenp */
        return (*qfn1(fn))(qenv(fn), v219);
    }
}



/* Code for rd!:onep */

static Lisp_Object CC_rdTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:onep");
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
    v131 = v137;
    v131 = qcdr(v131);
    if (!consp(v131)) goto v47;
    stack[-1] = qvalue(elt(env, 3)); /* bfone!* */
    stack[0] = v137;
    v131 = qvalue(elt(env, 4)); /* !:bprec!: */
    v137 = (Lisp_Object)49; /* 3 */
    v137 = difference2(v131, v137);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    fn = elt(env, 5); /* round!:mt */
    v137 = (*qfn2(fn))(qenv(fn), stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    fn = elt(env, 6); /* csl_normbf */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    {
        Lisp_Object v45 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* equal!: */
        return (*qfn2(fn))(qenv(fn), v45, v137);
    }

v47:
    v131 = elt(env, 1); /* 1.0 */
    v137 = qcdr(v137);
    v137 = difference2(v131, v137);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v137 = Labsval(nil, v137);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v131 = qvalue(elt(env, 2)); /* !!fleps1 */
        popv(3);
        return Llessp(nil, v137, v131);
/* error exit handlers */
v44:
    popv(3);
    return nil;
}



/* Code for xdegree */

static Lisp_Object CC_xdegree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegree");
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
    v38 = v0;
/* end of prologue */
    fn = elt(env, 1); /* deg!*form */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    errexit();
    v62 = v38;
    v38 = v62;
    if (!(v38 == nil)) return onevalue(v62);
    v38 = (Lisp_Object)1; /* 0 */
    return onevalue(v38);
}



/* Code for deg!*farg */

static Lisp_Object CC_degHfarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*farg");
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
    v27 = v0;
/* end of prologue */
    v26 = v27;
    v26 = qcdr(v26);
    if (v26 == nil) goto v60;
    stack[-1] = nil;
    v26 = v27;
    stack[0] = v26;
    goto v53;

v53:
    v26 = stack[0];
    if (v26 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v26 = stack[0];
    v26 = qcar(v26);
    fn = elt(env, 2); /* deg!*form */
    v27 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-2];
    v26 = stack[-1];
    fn = elt(env, 3); /* addf */
    v26 = (*qfn2(fn))(qenv(fn), v27, v26);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-2];
    stack[-1] = v26;
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v53;

v60:
    v26 = v27;
    v26 = qcar(v26);
    {
        popv(3);
        fn = elt(env, 2); /* deg!*form */
        return (*qfn1(fn))(qenv(fn), v26);
    }
/* error exit handlers */
v40:
    popv(3);
    return nil;
}



/* Code for cut!:ep */

static Lisp_Object CC_cutTep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cut:ep");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v50;
    stack[-2] = v0;
/* end of prologue */
    v18 = stack[-2];
    v234 = elt(env, 1); /* !:rd!: */
    if (!consp(v18)) goto v34;
    v18 = qcar(v18);
    if (!(v18 == v234)) goto v34;
    v234 = stack[-2];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v34;
    v234 = stack[-1];
    v234 = integerp(v234);
    if (v234 == nil) goto v34;
    v18 = stack[-1];
    v234 = stack[-2];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v18 = difference2(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[-1] = v18;
    v234 = (Lisp_Object)1; /* 0 */
    v234 = (Lisp_Object)lesseq2(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    v234 = v234 ? lisp_true : nil;
    env = stack[-4];
    if (!(v234 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v234 = stack[-2];
    v234 = qcdr(v234);
    stack[0] = qcar(v234);
    v234 = stack[-1];
    v234 = negate(v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    v234 = stack[-2];
    v234 = qcdr(v234);
    v18 = qcdr(v234);
    v234 = stack[-1];
    v234 = plus2(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    {
        Lisp_Object v95 = stack[-3];
        Lisp_Object v36 = stack[0];
        popv(5);
        return list2star(v95, v36, v234);
    }

v34:
    stack[0] = (Lisp_Object)1; /* 0 */
    v18 = elt(env, 2); /* "Invalid argument to" */
    v234 = elt(env, 0); /* cut!:ep */
    v234 = list2(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    {
        Lisp_Object v235 = stack[0];
        popv(5);
        fn = elt(env, 3); /* error */
        return (*qfn2(fn))(qenv(fn), v235, v234);
    }
/* error exit handlers */
v250:
    popv(5);
    return nil;
}



/* Code for getphystype!*sq */

static Lisp_Object CC_getphystypeHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype*sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v0;
/* end of prologue */
    v59 = qcar(v59);
    v59 = qcar(v59);
    {
        fn = elt(env, 1); /* getphystypesf */
        return (*qfn1(fn))(qenv(fn), v59);
    }
}



/* Code for scan */

static Lisp_Object MS_CDECL CC_scan(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v322, v323, v324;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "scan");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scan");
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
    v323 = qvalue(elt(env, 1)); /* cursym!* */
    v322 = elt(env, 2); /* !*semicol!* */
    if (!(v323 == v322)) goto v49;

v59:
    fn = elt(env, 37); /* token1 */
    v322 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 3)) = v322; /* nxtsym!* */
    goto v49;

v49:
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!consp(v322)) goto v17;
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    v324 = v322;
    v322 = v324;
    v322 = (is_number(v322) ? lisp_true : nil);
    if (!(v322 == nil)) goto v247;
    v323 = v324;
    v322 = elt(env, 4); /* !:dn!: */
    v322 = Leqcar(nil, v323, v322);
    env = stack[-3];
    if (!(v322 == nil)) goto v247;
    v323 = v324;
    v322 = elt(env, 5); /* !:int!: */
    v322 = Leqcar(nil, v323, v322);
    env = stack[-3];
    goto v247;

v247:
    if (!(v322 == nil)) goto v17;
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    v323 = qcar(v322);
    v322 = elt(env, 35); /* string */
    if (!(v323 == v322)) goto v51;
    v323 = elt(env, 36); /* " " */
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = qcdr(v322);
    v322 = qcar(v322);
    v322 = Lmkquote(nil, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 3)) = v322; /* nxtsym!* */
    v322 = qcdr(v322);
    v323 = qcar(v322);
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    goto v51;

v51:
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 1)) = v322; /* cursym!* */
    fn = elt(env, 37); /* token1 */
    v322 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 3)) = v322; /* nxtsym!* */
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = qvalue(elt(env, 23)); /* !$eof!$ */
    if (!(v323 == v322)) goto v52;
    v323 = qvalue(elt(env, 13)); /* ttype!* */
    v322 = (Lisp_Object)49; /* 3 */
    if (!(v323 == v322)) goto v52;
    {
        popv(4);
        fn = elt(env, 38); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v52:
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (is_number(v322)) goto v326;
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!(!consp(v322))) goto v327;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 29); /* switch!* */
    v322 = get(v323, v322);
    env = stack[-3];
    if (!(v322 == nil)) goto v327;

v326:
    v323 = elt(env, 36); /* " " */
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    goto v327;

v327:
    v322 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 1)) = v322; /* cursym!* */
    { popv(4); return onevalue(v322); }

v17:
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 6); /* else */
    if (v323 == v322) goto v328;
    v323 = qvalue(elt(env, 1)); /* cursym!* */
    v322 = elt(env, 2); /* !*semicol!* */
    if (!(v323 == v322)) goto v236;

v328:
    v322 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 8)) = v322; /* outl!* */
    goto v236;

v236:
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    goto v75;

v75:
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!(symbolp(v322))) goto v51;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 9); /* newnam */
    v322 = get(v323, v322);
    env = stack[-3];
    stack[-1] = v322;
    if (v322 == nil) goto v329;
    v323 = stack[-1];
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (equal(v323, v322)) goto v329;
    v322 = stack[-1];
    qvalue(elt(env, 3)) = v322; /* nxtsym!* */
    v322 = stack[-1];
    v322 = Lstringp(nil, v322);
    env = stack[-3];
    if (!(v322 == nil)) goto v51;
    v322 = stack[-1];
    if (!consp(v322)) goto v75;
    else goto v51;

v329:
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 10); /* comment */
    if (v323 == v322) goto v31;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 12); /* !% */
    if (!(v323 == v322)) goto v136;
    v323 = qvalue(elt(env, 13)); /* ttype!* */
    v322 = (Lisp_Object)49; /* 3 */
    if (!(v323 == v322)) goto v136;
    v322 = elt(env, 14); /* percent_comment */
    fn = elt(env, 39); /* read!-comment1 */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    stack[-1] = v322;
    v322 = qvalue(elt(env, 11)); /* !*comment */
    if (v322 == nil) goto v59;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v136:
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 15); /* !#if */
    if (v323 == v322) goto v330;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 16); /* !#else */
    if (v323 == v322) goto v331;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 17); /* !#elif */
    if (v323 == v322) goto v331;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 18); /* !#endif */
    if (v323 == v322) goto v59;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 19); /* !#eval */
    if (v323 == v322) goto v332;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 22); /* !#define */
    if (v323 == v322) goto v333;
    v323 = qvalue(elt(env, 13)); /* ttype!* */
    v322 = (Lisp_Object)49; /* 3 */
    if (!(v323 == v322)) goto v51;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = qvalue(elt(env, 23)); /* !$eof!$ */
    if (v323 == v322) goto v188;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 24); /* !' */
    if (v323 == v322) goto v334;
    v322 = qvalue(elt(env, 27)); /* !*eoldelimp */
    if (v322 == nil) goto v335;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = qvalue(elt(env, 28)); /* !$eol!$ */
    if (!(v323 == v322)) goto v335;

v38:
    v322 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 34)) = v322; /* semic!* */
    v322 = elt(env, 2); /* !*semicol!* */
    qvalue(elt(env, 1)) = v322; /* cursym!* */
    { popv(4); return onevalue(v322); }

v335:
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 29); /* switch!* */
    v322 = get(v323, v322);
    env = stack[-3];
    stack[-1] = v322;
    if (v322 == nil) goto v51;
    v322 = stack[-1];
    v323 = qcdr(v322);
    v322 = elt(env, 2); /* !*semicol!* */
    if (!consp(v323)) goto v22;
    v323 = qcar(v323);
    if (v323 == v322) goto v38;
    else goto v22;

v22:
    v322 = qvalue(elt(env, 30)); /* crchar!* */
    v322 = Lwhitespace_char_p(nil, v322);
    env = stack[-3];
    stack[-2] = v322;
    goto v11;

v11:
    fn = elt(env, 37); /* token1 */
    v322 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 3)) = v322; /* nxtsym!* */
    v323 = qvalue(elt(env, 13)); /* ttype!* */
    v322 = (Lisp_Object)49; /* 3 */
    if (!(v323 == v322)) goto v37;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = qvalue(elt(env, 23)); /* !$eof!$ */
    if (v323 == v322) goto v336;
    v322 = stack[-1];
    v322 = qcar(v322);
    if (v322 == nil) goto v37;
    v322 = stack[-2];
    if (!(v322 == nil)) goto v37;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = stack[-1];
    v322 = qcar(v322);
    v322 = Latsoc(nil, v323, v322);
    stack[0] = v322;
    if (v322 == nil) goto v37;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    v322 = stack[0];
    v322 = qcdr(v322);
    stack[-1] = v322;
    v322 = stack[-1];
    v322 = qcar(v322);
    if (!(v322 == nil)) goto v11;
    v322 = stack[-1];
    v322 = qcdr(v322);
    v323 = qcar(v322);
    v322 = elt(env, 32); /* !*comment!* */
    if (!(v323 == v322)) goto v11;
    fn = elt(env, 40); /* read!-comment */
    v322 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 33)) = v322; /* comment!* */
    goto v59;

v37:
    v322 = stack[-1];
    v322 = qcdr(v322);
    v322 = qcar(v322);
    qvalue(elt(env, 1)) = v322; /* cursym!* */
    v323 = qvalue(elt(env, 1)); /* cursym!* */
    v322 = elt(env, 31); /* !*rpar!* */
    if (v323 == v322) goto v52;
    v322 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 1)) = v322; /* cursym!* */
    { popv(4); return onevalue(v322); }

v336:
    {
        popv(4);
        fn = elt(env, 38); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v334:
    v322 = qvalue(elt(env, 25)); /* !*protfg */
    if (!(v322 == nil)) goto v337;
    v322 = elt(env, 26); /* "Invalid QUOTE" */
    fn = elt(env, 41); /* lprie */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    goto v337;

v337:
    v322 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    goto v22;

v188:
    {
        popv(4);
        fn = elt(env, 38); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v333:
    v323 = elt(env, 20); /* " '" */
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    fn = elt(env, 42); /* rread1 */
    v324 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    v323 = qvalue(elt(env, 21)); /* !*backtrace */
    v322 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 43); /* errorset */
    v322 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    stack[-1] = v322;
    v322 = stack[-1];
    if (!consp(v322)) goto v59;
    v322 = stack[-1];
    v322 = qcdr(v322);
    if (!(v322 == nil)) goto v59;
    v323 = elt(env, 20); /* " '" */
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    fn = elt(env, 42); /* rread1 */
    v324 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    v323 = qvalue(elt(env, 21)); /* !*backtrace */
    v322 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 43); /* errorset */
    v322 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    stack[0] = v322;
    v322 = stack[0];
    if (!consp(v322)) goto v59;
    v322 = stack[0];
    v322 = qcdr(v322);
    if (!(v322 == nil)) goto v59;
    v324 = stack[-1];
    v323 = elt(env, 9); /* newnam */
    v322 = stack[0];
    v322 = Lputprop(nil, 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    goto v59;

v332:
    v323 = elt(env, 20); /* " '" */
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    fn = elt(env, 42); /* rread1 */
    v324 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    v323 = qvalue(elt(env, 21)); /* !*backtrace */
    v322 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 43); /* errorset */
    v322 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    goto v59;

v331:
    v322 = qvalue(elt(env, 7)); /* nil */
    stack[-1] = v322;
    qvalue(elt(env, 3)) = v322; /* nxtsym!* */
    goto v338;

v338:
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 18); /* !#endif */
    if (v323 == v322) goto v339;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 15); /* !#if */
    if (v323 == v322) goto v340;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 16); /* !#else */
    if (!(v323 == v322)) goto v341;
    v322 = stack[-1];
    if (v322 == nil) goto v59;
    else goto v341;

v341:
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = elt(env, 17); /* !#elif */
    if (!(v323 == v322)) goto v342;
    v322 = stack[-1];
    if (!(v322 == nil)) goto v342;

v330:
    v323 = elt(env, 20); /* " '" */
    v322 = qvalue(elt(env, 8)); /* outl!* */
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 8)) = v322; /* outl!* */
    fn = elt(env, 42); /* rread1 */
    v324 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    v323 = qvalue(elt(env, 21)); /* !*backtrace */
    v322 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 43); /* errorset */
    v322 = (*qfnn(fn))(qenv(fn), 3, v324, v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    stack[-1] = v322;
    v322 = stack[-1];
    if (!consp(v322)) goto v343;
    v322 = stack[-1];
    v322 = qcdr(v322);
    if (!(v322 == nil)) goto v343;
    v322 = stack[-1];
    v322 = qcar(v322);
    if (!(v322 == nil)) goto v59;

v343:
    v322 = qvalue(elt(env, 7)); /* nil */
    stack[-1] = v322;
    goto v338;

v342:
    fn = elt(env, 37); /* token1 */
    v322 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    qvalue(elt(env, 3)) = v322; /* nxtsym!* */
    v323 = qvalue(elt(env, 13)); /* ttype!* */
    v322 = (Lisp_Object)49; /* 3 */
    if (!(v323 == v322)) goto v338;
    v323 = qvalue(elt(env, 3)); /* nxtsym!* */
    v322 = qvalue(elt(env, 23)); /* !$eof!$ */
    if (!(v323 == v322)) goto v338;
    {
        popv(4);
        fn = elt(env, 38); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v340:
    v323 = qvalue(elt(env, 7)); /* nil */
    v322 = stack[-1];
    v322 = cons(v323, v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    stack[-1] = v322;
    goto v342;

v339:
    v322 = stack[-1];
    if (v322 == nil) goto v59;
    v322 = stack[-1];
    v322 = qcdr(v322);
    stack[-1] = v322;
    goto v342;

v31:
    v322 = elt(env, 10); /* comment */
    fn = elt(env, 39); /* read!-comment1 */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-3];
    stack[-1] = v322;
    v322 = qvalue(elt(env, 11)); /* !*comment */
    if (v322 == nil) goto v59;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v325:
    popv(4);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdiff");
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
    v47 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v47 = stack[0];
    v47 = qcar(v47);
    fn = elt(env, 2); /* simp */
    stack[-1] = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v47 = stack[0];
    v47 = qcdr(v47);
    fn = elt(env, 3); /* simpminus */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    {
        Lisp_Object v54 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v54, v47);
    }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for dp_diff */

static Lisp_Object CC_dp_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v43 = v50;
    v42 = v0;
/* end of prologue */
    stack[0] = v42;
    fn = elt(env, 1); /* dp_neg */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    {
        Lisp_Object v47 = stack[0];
        popv(2);
        fn = elt(env, 2); /* dp_sum */
        return (*qfn2(fn))(qenv(fn), v47, v43);
    }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oprin");
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
    v249 = stack[0];
    v130 = elt(env, 1); /* prtch */
    v130 = get(v249, v130);
    env = stack[-2];
    stack[-1] = v130;
    v130 = stack[-1];
    if (v130 == nil) goto v42;
    v130 = qvalue(elt(env, 3)); /* !*fort */
    if (v130 == nil) goto v219;
    v130 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v130);
    }

v219:
    v130 = qvalue(elt(env, 4)); /* !*list */
    if (v130 == nil) goto v98;
    v130 = qvalue(elt(env, 5)); /* obrkp!* */
    if (v130 == nil) goto v98;
    v249 = stack[0];
    v130 = elt(env, 6); /* (plus minus) */
    v130 = Lmemq(nil, v249, v130);
    if (v130 == nil) goto v98;
    v130 = qvalue(elt(env, 7)); /* testing!-width!* */
    if (v130 == nil) goto v100;
    v130 = qvalue(elt(env, 8)); /* t */
    qvalue(elt(env, 9)) = v130; /* overflowed!* */
    { popv(3); return onevalue(v130); }

v100:
    v130 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 12); /* terpri!* */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v130 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v130);
    }

v98:
    v249 = stack[0];
    v130 = elt(env, 10); /* spaced */
    v130 = Lflagp(nil, v249, v130);
    env = stack[-2];
    if (v130 == nil) goto v16;
    v130 = elt(env, 2); /* " " */
    fn = elt(env, 11); /* prin2!* */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v130 = stack[-1];
    fn = elt(env, 11); /* prin2!* */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v130 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v130);
    }

v16:
    v130 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v130);
    }

v42:
    v130 = elt(env, 2); /* " " */
    fn = elt(env, 11); /* prin2!* */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v130 = stack[0];
    fn = elt(env, 11); /* prin2!* */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v130 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v130);
    }
/* error exit handlers */
v20:
    popv(3);
    return nil;
}



/* Code for insert_pv1 */

static Lisp_Object MS_CDECL CC_insert_pv1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v50,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "insert_pv1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv1");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v50,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v50;
    stack[-2] = v0;
/* end of prologue */

v49:
    v234 = stack[-1];
    if (v234 == nil) goto v37;
    v234 = stack[-2];
    if (v234 == nil) goto v231;
    v234 = stack[-1];
    v234 = qcar(v234);
    v234 = qcar(v234);
    v18 = qcdr(v234);
    v234 = stack[-2];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    v234 = (Lisp_Object)greaterp2(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    v234 = v234 ? lisp_true : nil;
    env = stack[-4];
    if (v234 == nil) goto v236;
    v234 = stack[-1];
    v234 = qcdr(v234);
    stack[-3] = v234;
    v234 = stack[-1];
    v18 = qcar(v234);
    v234 = stack[-2];
    fn = elt(env, 2); /* reduce_pv */
    v234 = (*qfn2(fn))(qenv(fn), v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    fn = elt(env, 3); /* pv_renorm */
    v18 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    v234 = stack[0];
    v234 = cons(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[0] = v234;
    v234 = stack[-3];
    stack[-1] = v234;
    goto v49;

v236:
    v234 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v234;
    v18 = stack[-2];
    v234 = stack[0];
    v234 = cons(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[0] = v234;
    v234 = stack[-3];
    stack[-2] = v234;
    goto v49;

v231:
    v234 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v234;
    v234 = stack[-1];
    v234 = qcdr(v234);
    stack[-3] = v234;
    v234 = stack[-1];
    v18 = qcar(v234);
    v234 = stack[0];
    v234 = cons(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[0] = v234;
    v234 = stack[-3];
    stack[-1] = v234;
    goto v49;

v37:
    v234 = stack[-2];
    if (v234 == nil) goto v62;
    v18 = stack[-2];
    v234 = stack[0];
    v234 = cons(v18, v234);
    nil = C_nil;
    if (exception_pending()) goto v250;
        popv(5);
        return Lnreverse(nil, v234);

v62:
    v234 = stack[0];
        popv(5);
        return Lnreverse(nil, v234);
/* error exit handlers */
v250:
    popv(5);
    return nil;
}



/* Code for !*id2num */

static Lisp_Object CC_Hid2num(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *id2num");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v53 = v0;
/* end of prologue */
    v54 = qvalue(elt(env, 1)); /* pair_id_num!* */
    v53 = Lassoc(nil, v53, v54);
    v54 = v53;
    if (v53 == nil) goto v59;
    v53 = v54;
    v53 = qcdr(v53);
    return onevalue(v53);

v59:
    v53 = nil;
    return onevalue(v53);
}



/* Code for dv_skelhead */

static Lisp_Object CC_dv_skelhead(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelhead");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v63 = v0;
/* end of prologue */
    v63 = qcar(v63);
    {
        fn = elt(env, 1); /* dv_cambhead */
        return (*qfn1(fn))(qenv(fn), v63);
    }
}



/* Code for general!-plus!-mod!-p */

static Lisp_Object CC_generalKplusKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v356, v333;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-plus-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v50;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v59;

v59:
    v356 = stack[-3];
    if (v356 == nil) goto v42;
    v356 = stack[-2];
    if (v356 == nil) goto v55;
    v356 = stack[-3];
    if (!consp(v356)) goto v231;
    v356 = stack[-3];
    v356 = qcar(v356);
    if (!consp(v356)) goto v231;
    v356 = stack[-2];
    if (!consp(v356)) goto v234;
    v356 = stack[-2];
    v356 = qcar(v356);
    if (!consp(v356)) goto v234;
    v356 = stack[-3];
    v356 = qcar(v356);
    v333 = qcar(v356);
    v356 = stack[-2];
    v356 = qcar(v356);
    v356 = qcar(v356);
    if (equal(v333, v356)) goto v92;
    v356 = stack[-3];
    v356 = qcar(v356);
    v356 = qcar(v356);
    v333 = qcar(v356);
    v356 = stack[-2];
    v356 = qcar(v356);
    v356 = qcar(v356);
    v356 = qcar(v356);
    if (!(equal(v333, v356))) goto v205;
    v356 = stack[-3];
    v356 = qcar(v356);
    v356 = qcar(v356);
    v333 = qcdr(v356);
    v356 = stack[-2];
    v356 = qcar(v356);
    v356 = qcar(v356);
    v356 = qcdr(v356);
    if (!(((int32_t)(v333)) > ((int32_t)(v356)))) goto v205;

v357:
    v356 = stack[-3];
    v333 = qcar(v356);
    v356 = stack[0];
    v356 = cons(v333, v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    stack[0] = v356;
    v356 = stack[-3];
    v356 = qcdr(v356);
    stack[-3] = v356;
    goto v59;

v205:
    v356 = stack[-3];
    v356 = qcar(v356);
    v356 = qcar(v356);
    v333 = qcar(v356);
    v356 = stack[-2];
    v356 = qcar(v356);
    v356 = qcar(v356);
    v356 = qcar(v356);
    if (equal(v333, v356)) goto v309;
    v356 = stack[-3];
    v356 = qcar(v356);
    v356 = qcar(v356);
    v333 = qcar(v356);
    v356 = stack[-2];
    v356 = qcar(v356);
    v356 = qcar(v356);
    v356 = qcar(v356);
    fn = elt(env, 2); /* ordop */
    v356 = (*qfn2(fn))(qenv(fn), v333, v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    if (!(v356 == nil)) goto v357;

v309:
    v356 = stack[-2];
    v333 = qcar(v356);
    v356 = stack[0];
    v356 = cons(v333, v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    stack[0] = v356;
    v356 = stack[-2];
    v356 = qcdr(v356);
    stack[-2] = v356;
    goto v59;

v92:
    stack[-4] = stack[0];
    v356 = stack[-3];
    v356 = qcar(v356);
    stack[-1] = qcar(v356);
    v356 = stack[-3];
    v356 = qcar(v356);
    v333 = qcdr(v356);
    v356 = stack[-2];
    v356 = qcar(v356);
    v356 = qcdr(v356);
    stack[0] = CC_generalKplusKmodKp(env, v333, v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    v356 = stack[-3];
    v333 = qcdr(v356);
    v356 = stack[-2];
    v356 = qcdr(v356);
    v356 = CC_generalKplusKmodKp(env, v333, v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    fn = elt(env, 3); /* adjoin!-term */
    v356 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    {
        Lisp_Object v305 = stack[-4];
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v305, v356);
    }

v234:
    v356 = stack[-3];
    v333 = qcar(v356);
    v356 = stack[0];
    v356 = cons(v333, v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    stack[0] = v356;
    v356 = stack[-3];
    v356 = qcdr(v356);
    stack[-3] = v356;
    goto v59;

v231:
    v356 = stack[-2];
    if (!consp(v356)) goto v45;
    v356 = stack[-2];
    v356 = qcar(v356);
    if (!consp(v356)) goto v45;
    v356 = stack[-2];
    v333 = qcar(v356);
    v356 = stack[0];
    v356 = cons(v333, v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    stack[0] = v356;
    v356 = stack[-2];
    v356 = qcdr(v356);
    stack[-2] = v356;
    goto v59;

v45:
    v333 = stack[-3];
    v356 = stack[-2];
    fn = elt(env, 5); /* general!-modular!-plus */
    v356 = (*qfn2(fn))(qenv(fn), v333, v356);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-5];
    v333 = v356;
    v356 = v333;
    v356 = (Lisp_Object)zerop(v356);
    v356 = v356 ? lisp_true : nil;
    env = stack[-5];
    if (v356 == nil) goto v16;
    v356 = qvalue(elt(env, 1)); /* nil */
    goto v131;

v131:
    {
        Lisp_Object v68 = stack[0];
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v68, v356);
    }

v16:
    v356 = v333;
    goto v131;

v55:
    v333 = stack[0];
    v356 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v333, v356);
    }

v42:
    v333 = stack[0];
    v356 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v333, v356);
    }
/* error exit handlers */
v307:
    popv(6);
    return nil;
}



/* Code for conv!:mt */

static Lisp_Object CC_convTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conv:mt");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v50;
    stack[-2] = v0;
/* end of prologue */
    v110 = stack[-2];
    v121 = elt(env, 1); /* !:rd!: */
    if (!consp(v110)) goto v360;
    v110 = qcar(v110);
    if (!(v110 == v121)) goto v360;
    v121 = stack[-2];
    v121 = qcdr(v121);
    if (!consp(v121)) goto v360;
    v121 = stack[0];
    v121 = integerp(v121);
    if (v121 == nil) goto v360;
    v110 = stack[0];
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)greaterp2(v110, v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    v121 = v121 ? lisp_true : nil;
    env = stack[-4];
    if (v121 == nil) goto v360;
    v121 = stack[-2];
    v121 = qcdr(v121);
    v121 = qcar(v121);
    v121 = Labsval(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    fn = elt(env, 3); /* msd */
    v110 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    v121 = stack[0];
    v110 = difference2(v110, v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    stack[0] = v110;
    v121 = (Lisp_Object)1; /* 0 */
    if (v110 == v121) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v110 = stack[0];
    v121 = (Lisp_Object)1; /* 0 */
    v121 = (Lisp_Object)lessp2(v110, v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    v121 = v121 ? lisp_true : nil;
    env = stack[-4];
    if (v121 == nil) goto v15;
    v121 = stack[0];
    v121 = negate(v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    stack[-3] = v121;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v121 = stack[-2];
    v121 = qcdr(v121);
    v110 = qcar(v121);
    v121 = stack[-3];
    stack[0] = Lash1(nil, v110, v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    v121 = stack[-2];
    v121 = qcdr(v121);
    v110 = qcdr(v121);
    v121 = stack[-3];
    v121 = difference2(v110, v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    {
        Lisp_Object v83 = stack[-1];
        Lisp_Object v84 = stack[0];
        popv(5);
        return list2star(v83, v84, v121);
    }

v15:
    v121 = stack[0];
    v121 = sub1(v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    stack[-3] = v121;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v121 = stack[-2];
    v121 = qcdr(v121);
    stack[0] = qcar(v121);
    v121 = stack[-3];
    v121 = negate(v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    v121 = stack[-2];
    v121 = qcdr(v121);
    v110 = qcdr(v121);
    v121 = stack[-3];
    v121 = plus2(v110, v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    v121 = list2star(stack[-1], stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v360:
    stack[0] = (Lisp_Object)1; /* 0 */
    v110 = elt(env, 2); /* "Invalid argument to" */
    v121 = elt(env, 0); /* conv!:mt */
    v121 = list2(v110, v121);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-4];
    {
        Lisp_Object v361 = stack[0];
        popv(5);
        fn = elt(env, 5); /* error */
        return (*qfn2(fn))(qenv(fn), v361, v121);
    }
/* error exit handlers */
v352:
    popv(5);
    return nil;
}



/* Code for mapcons */

static Lisp_Object CC_mapcons(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v1;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapcons");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v50;
    v98 = v0;
/* end of prologue */
    stack[-4] = v98;
    v98 = stack[-4];
    if (v98 == nil) goto v43;
    v98 = stack[-4];
    v98 = qcar(v98);
    v1 = stack[-3];
    v98 = cons(v1, v98);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    stack[-1] = v98;
    stack[-2] = v98;
    goto v75;

v75:
    v98 = stack[-4];
    v98 = qcdr(v98);
    stack[-4] = v98;
    v98 = stack[-4];
    if (v98 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v98 = stack[-4];
    v98 = qcar(v98);
    v1 = stack[-3];
    v98 = cons(v1, v98);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v98 = Lrplacd(nil, stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v75;

v43:
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v98); }
/* error exit handlers */
v99:
    popv(6);
    return nil;
}



/* Code for wulessp */

static Lisp_Object CC_wulessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v362;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v50;
    stack[-1] = v0;
/* end of prologue */
    v362 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    if (v362 == nil) goto v53;
    v362 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v362;
    goto v11;

v11:
    v362 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    if (v362 == nil) goto v363;
    v362 = qvalue(elt(env, 1)); /* nil */
    goto v37;

v37:
    fn = elt(env, 3); /* symbollessp */
    v362 = (*qfn2(fn))(qenv(fn), stack[-2], v362);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    if (!(v362 == nil)) { popv(4); return onevalue(v362); }
    v362 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    if (v362 == nil) goto v44;
    v362 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v362;
    goto v58;

v58:
    v362 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    if (v362 == nil) goto v9;
    v362 = qvalue(elt(env, 1)); /* nil */
    goto v39;

v39:
    if (equal(stack[-2], v362)) goto v119;
    v362 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v362); }

v119:
    v362 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    if (v362 == nil) goto v97;
    v362 = (Lisp_Object)1; /* 0 */
    stack[-1] = v362;
    goto v143;

v143:
    v362 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v362 = (*qfn1(fn))(qenv(fn), v362);
    nil = C_nil;
    if (exception_pending()) goto v30;
    if (v362 == nil) goto v36;
    v362 = (Lisp_Object)1; /* 0 */
    goto v34;

v34:
    {
        Lisp_Object v31 = stack[-1];
        popv(4);
        return Llessp(nil, v31, v362);
    }

v36:
    v362 = stack[0];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcdr(v362);
    goto v34;

v97:
    v362 = stack[-1];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcdr(v362);
    stack[-1] = v362;
    goto v143;

v9:
    v362 = stack[0];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcar(v362);
    goto v39;

v44:
    v362 = stack[-1];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcar(v362);
    stack[-2] = v362;
    goto v58;

v363:
    v362 = stack[0];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcar(v362);
    goto v37;

v53:
    v362 = stack[-1];
    v362 = qcar(v362);
    v362 = qcar(v362);
    v362 = qcar(v362);
    stack[-2] = v362;
    goto v11;
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for resimp1 */

static Lisp_Object CC_resimp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v363;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp1");
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
    v231 = stack[0];
    v363 = qcar(v231);
    v231 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v363, v231);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v231 = stack[0];
    v363 = qcdr(v231);
    v231 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* subf1 */
    v231 = (*qfn2(fn))(qenv(fn), v363, v231);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    fn = elt(env, 5); /* invsq */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    fn = elt(env, 6); /* multsq */
    v231 = (*qfn2(fn))(qenv(fn), stack[-1], v231);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    stack[0] = v231;
    v231 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v231; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for matrix!+p */

static Lisp_Object CC_matrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix+p");
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
    v117 = stack[0];
    v98 = Llength(nil, v117);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    v117 = (Lisp_Object)17; /* 1 */
    v117 = (Lisp_Object)lessp2(v98, v117);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v117 = v117 ? lisp_true : nil;
    env = stack[-4];
    if (v117 == nil) goto v75;
    v117 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v117); }

v75:
    v117 = stack[0];
    v117 = qcar(v117);
    v117 = Llength(nil, v117);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    stack[-3] = v117;
    v117 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v117;
    v117 = stack[0];
    v117 = qcdr(v117);
    stack[-1] = v117;
    goto v3;

v3:
    v117 = stack[-1];
    if (v117 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v117 = stack[-1];
    v117 = qcar(v117);
    stack[0] = stack[-3];
    v117 = Llength(nil, v117);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    if (equal(stack[0], v117)) goto v247;
    v117 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v117;
    goto v247;

v247:
    v117 = stack[-1];
    v117 = qcdr(v117);
    stack[-1] = v117;
    goto v3;
/* error exit handlers */
v328:
    popv(5);
    return nil;
}



/* Code for ibalp_varlat */

static Lisp_Object CC_ibalp_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlat");
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
    v38 = stack[0];
    fn = elt(env, 1); /* ibalp_arg2l */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    stack[-1] = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v38 = stack[0];
    fn = elt(env, 3); /* ibalp_arg2r */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    {
        Lisp_Object v52 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* union */
        return (*qfn2(fn))(qenv(fn), v52, v38);
    }
/* error exit handlers */
v51:
    popv(3);
    return nil;
}



/* Code for aex_reducedtag */

static Lisp_Object CC_aex_reducedtag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v75;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_reducedtag");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v75 = v0;
/* end of prologue */
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = qcar(v75);
    return onevalue(v75);
}



/* Code for retattributes */

static Lisp_Object CC_retattributes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retattributes");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v50;
    stack[-1] = v0;
/* end of prologue */

v232:
    v99 = stack[0];
    if (v99 == nil) goto v49;
    v17 = stack[-1];
    v99 = stack[0];
    v99 = qcar(v99);
    fn = elt(env, 2); /* find */
    v99 = (*qfn2(fn))(qenv(fn), v17, v99);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    v17 = v99;
    if (v17 == nil) goto v45;
    v17 = stack[0];
    v17 = qcar(v17);
    stack[-2] = list2(v17, v99);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    v17 = stack[-1];
    v99 = stack[0];
    v99 = qcdr(v99);
    v99 = CC_retattributes(env, v17, v99);
    nil = C_nil;
    if (exception_pending()) goto v10;
    {
        Lisp_Object v16 = stack[-2];
        popv(4);
        return cons(v16, v99);
    }

v45:
    v17 = stack[-1];
    v99 = stack[0];
    v99 = qcdr(v99);
    stack[-1] = v17;
    stack[0] = v99;
    goto v232;

v49:
    v99 = nil;
    { popv(4); return onevalue(v99); }
/* error exit handlers */
v10:
    popv(4);
    return nil;
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*");
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
    stack[-3] = qvalue(elt(env, 1)); /* !*asymp!* */
    qvalue(elt(env, 1)) = nil; /* !*asymp!* */
    v210 = stack[-2];
    v123 = elt(env, 2); /* !*sq */
    if (!consp(v210)) goto v12;
    v210 = qcar(v210);
    if (!(v210 == v123)) goto v12;
    v123 = stack[-2];
    v123 = qcdr(v123);
    v123 = qcdr(v123);
    v123 = qcar(v123);
    if (v123 == nil) goto v12;
    v123 = qvalue(elt(env, 3)); /* !*resimp */
    if (!(v123 == nil)) goto v12;
    v123 = stack[-2];
    v123 = qcdr(v123);
    v123 = qcar(v123);
    goto v63;

v63:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v123); }

v12:
    v210 = qvalue(elt(env, 4)); /* mul!* */
    v123 = qvalue(elt(env, 5)); /* !*sub2 */
    v123 = cons(v210, v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-1] = v123;
    v123 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 4)) = v123; /* mul!* */
    v123 = stack[-2];
    fn = elt(env, 14); /* simp */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-2] = v123;
    v123 = qvalue(elt(env, 7)); /* !*nospurp */
    if (v123 == nil) goto v247;
    v210 = qvalue(elt(env, 4)); /* mul!* */
    v123 = elt(env, 8); /* (isimpq) */
    fn = elt(env, 15); /* union */
    v123 = (*qfn2(fn))(qenv(fn), v210, v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    qvalue(elt(env, 4)) = v123; /* mul!* */
    goto v247;

v247:
    v123 = qvalue(elt(env, 4)); /* mul!* */
    stack[0] = v123;
    goto v117;

v117:
    v123 = stack[0];
    if (v123 == nil) goto v45;
    v123 = stack[0];
    v123 = qcar(v123);
    v210 = v123;
    v123 = stack[-2];
    v123 = Lapply1(nil, v210, v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-2] = v123;
    v123 = stack[0];
    v123 = qcdr(v123);
    stack[0] = v123;
    goto v117;

v45:
    v123 = stack[-1];
    v123 = qcar(v123);
    qvalue(elt(env, 4)) = v123; /* mul!* */
    v123 = stack[-2];
    fn = elt(env, 16); /* subs2 */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-2] = v123;
    v123 = qvalue(elt(env, 9)); /* !*combinelogs */
    if (v123 == nil) goto v211;
    v123 = stack[-2];
    fn = elt(env, 17); /* clogsq!* */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-2] = v123;
    goto v211;

v211:
    v210 = qvalue(elt(env, 10)); /* dmode!* */
    v123 = elt(env, 11); /* !:gi!: */
    if (!(v210 == v123)) goto v237;
    v123 = qvalue(elt(env, 12)); /* !*norationalgi */
    if (!(v123 == nil)) goto v237;
    v123 = stack[-2];
    fn = elt(env, 18); /* girationalize!: */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-2] = v123;
    goto v97;

v97:
    v123 = stack[-1];
    v123 = qcdr(v123);
    qvalue(elt(env, 5)) = v123; /* !*sub2 */
    v123 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v123 == nil) goto v354;
    v123 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v123 == nil) goto v354;
    v123 = stack[-2];
    fn = elt(env, 19); /* gcdchk */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-2] = v123;
    goto v354;

v354:
    v123 = stack[-2];
    goto v63;

v237:
    v123 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v123 == nil) goto v91;
    v123 = stack[-2];
    fn = elt(env, 20); /* rationalizesq */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-2] = v123;
    goto v97;

v91:
    v123 = stack[-2];
    fn = elt(env, 21); /* rationalizei */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v359;
    env = stack[-4];
    stack[-2] = v123;
    goto v97;
/* error exit handlers */
v359:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v117, v98, v1;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symtabget");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v50;
    v98 = v0;
/* end of prologue */
    v45 = v1;
    if (v45 == nil) goto v60;
    v45 = v98;
    if (!(v45 == nil)) goto v11;
    v45 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v45 = qcar(v45);
    goto v11;

v11:
    v98 = v45;
    goto v60;

v60:
    v45 = v98;
    if (v45 == nil) goto v47;
    v117 = v1;
    v45 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v45 = Lmemq(nil, v117, v45);
    if (v45 == nil) goto v5;
    v45 = v98;
    v117 = v1;
    return get(v45, v117);

v5:
    v117 = v1;
    v45 = elt(env, 3); /* !*decs!* */
    v45 = get(v98, v45);
    v45 = Lassoc(nil, v117, v45);
    return onevalue(v45);

v47:
    v45 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v45);
}



/* Code for ident */

static Lisp_Object CC_ident(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v61;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ident");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v61 = v0;
/* end of prologue */
    return onevalue(v61);
}



/* Code for worderp */

static Lisp_Object CC_worderp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v50)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v320, v121, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for worderp");
#endif
    if (stack >= stacklimit)
    {
        push2(v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v50);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v50;
    stack[-1] = v0;
/* end of prologue */

v63:
    v320 = stack[-1];
    if (!consp(v320)) goto v11;
    v320 = stack[-1];
    v121 = qcar(v320);
    v320 = elt(env, 1); /* indexvar */
    v320 = Lflagp(nil, v121, v320);
    env = stack[-2];
    if (v320 == nil) goto v11;
    v320 = stack[0];
    if (!consp(v320)) goto v11;
    v320 = stack[0];
    v121 = qcar(v320);
    v320 = elt(env, 1); /* indexvar */
    v320 = Lflagp(nil, v121, v320);
    env = stack[-2];
    if (v320 == nil) goto v11;
    v121 = stack[-1];
    v320 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* indexvarordp */
        return (*qfn2(fn))(qenv(fn), v121, v320);
    }

v11:
    v320 = stack[-1];
    if (!consp(v320)) goto v26;
    v121 = stack[-1];
    v320 = qvalue(elt(env, 2)); /* kord!* */
    v320 = Lmemq(nil, v121, v320);
    if (!(v320 == nil)) goto v26;
    v320 = stack[0];
    if (!consp(v320)) goto v364;
    v121 = stack[0];
    v320 = qvalue(elt(env, 2)); /* kord!* */
    v320 = Lmemq(nil, v121, v320);
    if (!(v320 == nil)) goto v364;
    v320 = stack[-1];
    fn = elt(env, 6); /* peel */
    v320 = (*qfn1(fn))(qenv(fn), v320);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-2];
    stack[-1] = v320;
    v320 = stack[0];
    fn = elt(env, 6); /* peel */
    v320 = (*qfn1(fn))(qenv(fn), v320);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-2];
    stack[0] = v320;
    goto v63;

v364:
    v320 = stack[-1];
    fn = elt(env, 6); /* peel */
    v320 = (*qfn1(fn))(qenv(fn), v320);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-2];
    v110 = v320;
    v121 = v110;
    v320 = stack[0];
    if (v121 == v320) goto v349;
    v121 = v110;
    v320 = stack[0];
    stack[-1] = v121;
    stack[0] = v320;
    goto v63;

v349:
    v320 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v320); }

v26:
    v320 = stack[0];
    if (!consp(v320)) goto v142;
    v121 = stack[0];
    v320 = qvalue(elt(env, 2)); /* kord!* */
    v320 = Lmemq(nil, v121, v320);
    if (!(v320 == nil)) goto v142;
    v320 = stack[0];
    fn = elt(env, 6); /* peel */
    v320 = (*qfn1(fn))(qenv(fn), v320);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-2];
    v110 = v320;
    v121 = stack[-1];
    v320 = v110;
    if (v121 == v320) goto v248;
    v320 = stack[-1];
    v121 = v110;
    stack[-1] = v320;
    stack[0] = v121;
    goto v63;

v248:
    v320 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v320); }

v142:
    v121 = stack[-1];
    v320 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* ordop */
        return (*qfn2(fn))(qenv(fn), v121, v320);
    }
/* error exit handlers */
v132:
    popv(3);
    return nil;
}



/* Code for vecopp */

static Lisp_Object CC_vecopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v138, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecopp");
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
    v138 = v0;
/* end of prologue */
    v2 = v138;
    if (symbolp(v2)) goto v53;
    v2 = qvalue(elt(env, 1)); /* nil */
    goto v59;

v59:
    if (!(v2 == nil)) { popv(1); return onevalue(v2); }
    v2 = v138;
    if (!consp(v2)) goto v12;
    v2 = v138;
    v46 = qcar(v2);
    v2 = elt(env, 2); /* phystype */
    v46 = get(v46, v2);
    env = stack[0];
    v2 = elt(env, 3); /* vector */
    if (v46 == v2) goto v24;
    v2 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v2); }

v24:
    v2 = v138;
    v2 = qcdr(v2);
    v2 = qcar(v2);
    fn = elt(env, 4); /* isanindex */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v328;
    v2 = (v2 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v2); }

v12:
    v2 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v2); }

v53:
    v46 = v138;
    v2 = elt(env, 2); /* phystype */
    v46 = get(v46, v2);
    env = stack[0];
    v2 = elt(env, 3); /* vector */
    v2 = (v46 == v2 ? lisp_true : nil);
    goto v59;
/* error exit handlers */
v328:
    popv(1);
    return nil;
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v50,
                         Lisp_Object v21, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v328;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp2");
#endif
    if (stack >= stacklimit)
    {
        push3(v21,v50,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v50,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v50;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v46 = stack[-2];
    v46 = Llength(nil, v46);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    if (stack[-3] == v46) goto v54;
    v46 = nil;
    { popv(5); return onevalue(v46); }

v54:
    v328 = stack[0];
    v46 = stack[-2];
    v46 = qcar(v46);
    if (equal(v328, v46)) goto v13;
    v328 = stack[0];
    v46 = stack[-2];
    v46 = qcdr(v46);
    v46 = qcar(v46);
    if (equal(v328, v46)) goto v137;
    v46 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v46); }

v137:
    v46 = stack[-2];
    v328 = qcar(v46);
    v46 = stack[-1];
    popv(5);
    return cons(v328, v46);

v13:
    v46 = stack[-2];
    v46 = qcdr(v46);
    v328 = qcar(v46);
    v46 = stack[-1];
    popv(5);
    return cons(v328, v46);
/* error exit handlers */
v9:
    popv(5);
    return nil;
}



setup_type const u06_setup[] =
{
    {"physopp*",                CC_physoppH,    too_many_1,    wrong_no_1},
    {"argnochk",                CC_argnochk,    too_many_1,    wrong_no_1},
    {"getelv",                  CC_getelv,      too_many_1,    wrong_no_1},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"red_divtestbe",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_red_divtestbe},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"pv_applp",                too_few_2,      CC_pv_applp,   wrong_no_2},
    {"raddf",                   too_few_2,      CC_raddf,      wrong_no_2},
    {"msappend",                too_few_2,      CC_msappend,   wrong_no_2},
    {"subs2f1",                 CC_subs2f1,     too_many_1,    wrong_no_1},
    {"ibalp_commonlenisone",    too_few_2,      CC_ibalp_commonlenisone,wrong_no_2},
    {"ctx_new",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_ctx_new},
    {"free-powerp",             CC_freeKpowerp, too_many_1,    wrong_no_1},
    {"rl_sacatlp",              too_few_2,      CC_rl_sacatlp, wrong_no_2},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"initbrsea",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_initbrsea},
    {"genp",                    CC_genp,        too_many_1,    wrong_no_1},
    {"rd:onep",                 CC_rdTonep,     too_many_1,    wrong_no_1},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"deg*farg",                CC_degHfarg,    too_many_1,    wrong_no_1},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"scan",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_scan},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"dp_diff",                 too_few_2,      CC_dp_diff,    wrong_no_2},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"insert_pv1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_insert_pv1},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"dv_skelhead",             CC_dv_skelhead, too_many_1,    wrong_no_1},
    {"general-plus-mod-p",      too_few_2,      CC_generalKplusKmodKp,wrong_no_2},
    {"conv:mt",                 too_few_2,      CC_convTmt,    wrong_no_2},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {"wulessp",                 too_few_2,      CC_wulessp,    wrong_no_2},
    {"resimp1",                 CC_resimp1,     too_many_1,    wrong_no_1},
    {"matrix+p",                CC_matrixLp,    too_many_1,    wrong_no_1},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"aex_reducedtag",          CC_aex_reducedtag,too_many_1,  wrong_no_1},
    {"retattributes",           too_few_2,      CC_retattributes,wrong_no_2},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"worderp",                 too_few_2,      CC_worderp,    wrong_no_2},
    {"vecopp",                  CC_vecopp,      too_many_1,    wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {NULL, (one_args *)"u06", (two_args *)"8167 1582262 4224347", 0}
};

/* end of generated code */
