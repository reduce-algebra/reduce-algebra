
/* $destdir\u43.c        Machine generated C code */

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


/* Code for liendimcom */

static Lisp_Object CC_liendimcom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v270, v271, v272, v273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for liendimcom");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0;
/* end of prologue */
    v270 = (Lisp_Object)1; /* 0 */
    stack[-9] = v270;
    stack[0] = elt(env, 1); /* lie_dim */
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-3] = v270;
    goto v275;

v275:
    stack[0] = elt(env, 2); /* difference */
    v272 = elt(env, 2); /* difference */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-3];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v276;
    v270 = elt(env, 1); /* lie_dim */
    fn = elt(env, 15); /* aeval */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v277;
    v270 = (Lisp_Object)17; /* 1 */
    stack[-5] = v270;
    goto v278;

v278:
    stack[0] = elt(env, 2); /* difference */
    v272 = elt(env, 2); /* difference */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-5];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v279;
    v270 = elt(env, 1); /* lie_dim */
    fn = elt(env, 15); /* aeval */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 20); /* evalequal */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v277;
    stack[0] = elt(env, 10); /* lie_help */
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-6] = v270;
    goto v280;

v280:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-6];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v281;
    v270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v270;
    goto v282;

v282:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v283;
    v270 = elt(env, 10); /* lie_help */
    fn = elt(env, 15); /* aeval */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* evalequal */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v284;
    v272 = elt(env, 12); /* lientrans */
    v271 = (Lisp_Object)33; /* 2 */
    v270 = elt(env, 5); /* lie_p */
    stack[-1] = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v272 = elt(env, 12); /* lientrans */
    v271 = (Lisp_Object)49; /* 3 */
    v270 = elt(env, 6); /* lie_q */
    stack[0] = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[-1], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[0] = elt(env, 13); /* lie_kk!* */
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v270;
    goto v285;

v285:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (!(v270 == nil)) goto v277;
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-1];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v286;
    stack[0] = stack[-1];
    v270 = elt(env, 5); /* lie_p */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v286;
    stack[0] = stack[-1];
    v270 = elt(env, 6); /* lie_q */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v286;
    stack[0] = elt(env, 14); /* lie_tt */
    v270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v286;

v286:
    v270 = stack[-1];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v285;

v277:
    v270 = nil;
    { popv(11); return onevalue(v270); }

v284:
    v272 = elt(env, 12); /* lientrans */
    v271 = (Lisp_Object)33; /* 2 */
    v270 = elt(env, 11); /* lie_s */
    stack[-7] = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-6] = elt(env, 8); /* quotient */
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-9];
    stack[-5] = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v270;
    v270 = (Lisp_Object)1; /* 0 */
    stack[-3] = v270;
    goto v287;

v287:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-4];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v288;
    v270 = stack[-3];
    v270 = list3(stack[-6], stack[-5], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 15); /* aeval */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[-7], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v270;
    goto v289;

v289:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (!(v270 == nil)) goto v277;
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-1];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v290;
    stack[0] = stack[-1];
    v270 = elt(env, 11); /* lie_s */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v290;
    stack[0] = elt(env, 14); /* lie_tt */
    v270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v290;

v290:
    v270 = stack[-1];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v289;

v288:
    stack[-2] = elt(env, 7); /* plus */
    stack[-1] = elt(env, 9); /* times */
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-4];
    stack[0] = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-4];
    v271 = elt(env, 11); /* lie_s */
    v270 = stack[-9];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = list3(stack[-1], stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-3];
    v270 = list3(stack[-2], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    v270 = stack[-4];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-4] = v270;
    goto v287;

v283:
    v272 = elt(env, 12); /* lientrans */
    v271 = (Lisp_Object)17; /* 1 */
    v270 = stack[-1];
    stack[0] = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-1];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v282;

v281:
    v270 = (Lisp_Object)17; /* 1 */
    stack[-5] = v270;
    goto v291;

v291:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-5];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v292;
    v270 = stack[-6];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-6] = v270;
    goto v280;

v292:
    v270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v270;
    v270 = (Lisp_Object)1; /* 0 */
    stack[-3] = v270;
    goto v293;

v293:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-4];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v294;
    v270 = stack[-3];
    v271 = v270;
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v295;
    stack[0] = elt(env, 10); /* lie_help */
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[0] = elt(env, 11); /* lie_s */
    v270 = stack[-6];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-5];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-9] = v270;
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-5] = v270;
    stack[-6] = v270;
    goto v295;

v295:
    v270 = stack[-5];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-5] = v270;
    goto v291;

v294:
    stack[-2] = elt(env, 7); /* plus */
    stack[-1] = elt(env, 9); /* times */
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-4];
    stack[0] = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-4];
    v271 = stack[-6];
    v270 = stack[-5];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = list3(stack[-1], stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-3];
    v270 = list3(stack[-2], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    v270 = stack[-4];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-4] = v270;
    goto v293;

v279:
    v270 = (Lisp_Object)17; /* 1 */
    stack[-4] = v270;
    goto v296;

v296:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-4];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v297;
    v270 = stack[-5];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-5] = v270;
    goto v278;

v297:
    stack[-1] = elt(env, 8); /* quotient */
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-5];
    v271 = stack[-4];
    v270 = stack[-9];
    stack[0] = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-9];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = list3(stack[-1], stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-6] = v270;
    v270 = (Lisp_Object)17; /* 1 */
    stack[-3] = v270;
    goto v298;

v298:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-3];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v299;
    v270 = stack[-4];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-4] = v270;
    goto v296;

v299:
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-5];
    v271 = stack[-4];
    v270 = stack[-3];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    stack[-2] = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = elt(env, 9); /* times */
    stack[0] = stack[-6];
    v273 = elt(env, 4); /* lie_cc */
    v272 = elt(env, 5); /* lie_p */
    v271 = elt(env, 6); /* lie_q */
    v270 = stack[-3];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = list3(stack[-1], stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), stack[-2], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v300;
    stack[0] = elt(env, 1); /* lie_dim */
    v270 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-5] = v270;
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-4] = v270;
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    goto v300;

v300:
    v270 = stack[-3];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    goto v298;

v276:
    v270 = stack[-3];
    stack[-2] = v270;
    goto v301;

v301:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-2];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v302;
    v270 = stack[-3];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    goto v275;

v302:
    v270 = (Lisp_Object)17; /* 1 */
    stack[-1] = v270;
    goto v303;

v303:
    stack[0] = elt(env, 2); /* difference */
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    v270 = list3(stack[0], v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 18); /* aminusp!: */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v304;
    v270 = stack[-2];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-2] = v270;
    goto v301;

v304:
    v273 = elt(env, 4); /* lie_cc */
    v272 = stack[-3];
    v271 = stack[-2];
    v270 = stack[-1];
    v270 = list4(v273, v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v271 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 19); /* evalneq */
    v270 = (*qfn2(fn))(qenv(fn), v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    if (v270 == nil) goto v305;
    stack[0] = elt(env, 1); /* lie_dim */
    v270 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[0] = elt(env, 5); /* lie_p */
    v270 = stack[-3];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[0] = elt(env, 6); /* lie_q */
    v270 = stack[-2];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 16); /* setk */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    v270 = stack[-1];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-9] = v270;
    v270 = stack[-8];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-3] = v270;
    v272 = elt(env, 7); /* plus */
    v271 = stack[-8];
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    stack[-2] = v270;
    goto v305;

v305:
    v270 = stack[-1];
    v272 = elt(env, 7); /* plus */
    v271 = v270;
    v270 = (Lisp_Object)17; /* 1 */
    v270 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    fn = elt(env, 17); /* aeval!* */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v274;
    env = stack[-10];
    stack[-1] = v270;
    goto v303;
/* error exit handlers */
v274:
    popv(11);
    return nil;
}



/* Code for groeb!=crita */

static Lisp_Object CC_groebMcrita(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v308, v309;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=crita");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v308 = v0;
/* end of prologue */
    v309 = v308;
    v308 = elt(env, 1); /* groeb!=testa */
    {
        fn = elt(env, 2); /* listminimize */
        return (*qfn2(fn))(qenv(fn), v309, v308);
    }
}



/* Code for allbkern */

static Lisp_Object CC_allbkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v316;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for allbkern");
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
    goto v317;

v317:
    v315 = stack[0];
    if (v315 == nil) goto v318;
    v315 = stack[0];
    v315 = qcar(v315);
    v316 = qcar(v315);
    v315 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* kernels1 */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    fn = elt(env, 3); /* basic!-kern */
    v316 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    v315 = stack[-1];
    v315 = cons(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    stack[-1] = v315;
    v315 = stack[0];
    v315 = qcdr(v315);
    stack[0] = v315;
    goto v317;

v318:
    v315 = qvalue(elt(env, 1)); /* nil */
    v316 = v315;
    goto v306;

v306:
    v315 = stack[-1];
    if (v315 == nil) { popv(3); return onevalue(v316); }
    v315 = stack[-1];
    v315 = qcar(v315);
    fn = elt(env, 4); /* union */
    v315 = (*qfn2(fn))(qenv(fn), v315, v316);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    v316 = v315;
    v315 = stack[-1];
    v315 = qcdr(v315);
    stack[-1] = v315;
    goto v306;
/* error exit handlers */
v319:
    popv(3);
    return nil;
}



/* Code for texexplode */

static Lisp_Object CC_texexplode(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v326, v327, v328;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texexplode");
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
    v327 = v0;
/* end of prologue */
    v326 = v327;
    if (v326 == nil) goto v306;
    v326 = v327;
    if (!(!consp(v326))) goto v306;
    v328 = v327;
    v326 = elt(env, 1); /* texname */
    v326 = get(v328, v326);
    env = stack[0];
    if (!(v326 == nil)) goto v329;
    v328 = v327;
    v326 = elt(env, 2); /* class */
    v326 = get(v328, v326);
    env = stack[0];
    if (v326 == nil) goto v313;
    v326 = v327;
    goto v329;

v329:
    if (!(v326 == nil)) goto v317;
    v326 = v327;
    if (is_number(v326)) goto v265;
    v326 = v327;
    v326 = Lstringp(nil, v326);
    env = stack[0];
    if (v326 == nil) goto v330;
    v326 = v327;
    v326 = Lexplodec(nil, v326);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[0];
    fn = elt(env, 5); /* strcollect */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[0];
    goto v317;

v317:
    v327 = v326;
    v326 = v327;
    if (v326 == nil) goto v331;
    v326 = v327;
    if (!(!consp(v326))) { popv(1); return onevalue(v327); }
    v326 = v327;
    popv(1);
    return ncons(v326);

v331:
    v326 = elt(env, 4); /* !  */
    popv(1);
    return ncons(v326);

v330:
    v326 = v327;
    v326 = Lexplodec(nil, v326);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[0];
    fn = elt(env, 6); /* texcollect */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[0];
    fn = elt(env, 7); /* texexplist */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[0];
    goto v317;

v265:
    v326 = v327;
    v326 = Lexplode(nil, v326);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[0];
    fn = elt(env, 6); /* texcollect */
    v326 = (*qfn1(fn))(qenv(fn), v326);
    nil = C_nil;
    if (exception_pending()) goto v303;
    env = stack[0];
    goto v317;

v313:
    v326 = qvalue(elt(env, 3)); /* nil */
    goto v329;

v306:
    v326 = nil;
    goto v317;
/* error exit handlers */
v303:
    popv(1);
    return nil;
}



/* Code for fctrf */

static Lisp_Object CC_fctrf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v370, v371, v372;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctrf");
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
    stack[-5] = v0;
/* end of prologue */
    v371 = qvalue(elt(env, 1)); /* !*exp */
    v370 = qvalue(elt(env, 2)); /* ncmp!* */
    stack[-6] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = v371; /* !*exp */
    stack[-4] = qvalue(elt(env, 2)); /* ncmp!* */
    qvalue(elt(env, 2)) = v370; /* ncmp!* */
    stack[-3] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = nil; /* !*ezgcd */
    stack[-2] = qvalue(elt(env, 4)); /* !*gcd */
    qvalue(elt(env, 4)) = nil; /* !*gcd */
    stack[-1] = nil;
    v370 = stack[-5];
    if (!consp(v370)) goto v373;
    v370 = stack[-5];
    v370 = qcar(v370);
    if (!consp(v370)) goto v373;
    v370 = qvalue(elt(env, 2)); /* ncmp!* */
    if (v370 == nil) goto v269;
    v370 = qvalue(elt(env, 5)); /* !*ncmp */
    if (v370 == nil) goto v374;
    v370 = stack[-5];
    fn = elt(env, 21); /* noncomfp1 */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    if (!(v370 == nil)) goto v269;

v374:
    v370 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 2)) = v370; /* ncmp!* */
    goto v269;

v269:
    v370 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 4)) = v370; /* !*gcd */
    v370 = qvalue(elt(env, 8)); /* !*limitedfactors */
    if (!(v370 == nil)) goto v322;
    v370 = qvalue(elt(env, 9)); /* dmode!* */
    if (!(v370 == nil)) goto v322;
    v370 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 3)) = v370; /* !*ezgcd */
    goto v322;

v322:
    v370 = qvalue(elt(env, 10)); /* !*mcd */
    if (v370 == nil) goto v263;
    v370 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v370 == nil)) goto v376;
    v370 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 1)) = v370; /* !*exp */
    v371 = stack[-5];
    v370 = (Lisp_Object)17; /* 1 */
    v370 = cons(v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    fn = elt(env, 22); /* resimp */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v372 = v370;
    v370 = v372;
    v371 = qcdr(v370);
    v370 = (Lisp_Object)17; /* 1 */
    if (v371 == v370) goto v377;
    v370 = v372;
    v370 = qcar(v370);
    if (v370 == nil) goto v378;
    v371 = v372;
    v370 = elt(env, 14); /* prepf */
    fn = elt(env, 23); /* sqform */
    v370 = (*qfn2(fn))(qenv(fn), v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v371 = v370;
    goto v305;

v305:
    v370 = elt(env, 15); /* polynomial */
    fn = elt(env, 24); /* typerr */
    v370 = (*qfn2(fn))(qenv(fn), v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v379;

v379:
    stack[-5] = v370;
    goto v376;

v376:
    v371 = qvalue(elt(env, 9)); /* dmode!* */
    v370 = elt(env, 16); /* !:rn!: */
    if (!(v371 == v370)) goto v252;
    v370 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 9)) = v370; /* dmode!* */
    v370 = qvalue(elt(env, 6)); /* nil */
    v370 = ncons(v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    qvalue(elt(env, 17)) = v370; /* alglist!* */
    v371 = stack[-5];
    v370 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 25); /* prepf1 */
    v370 = (*qfn2(fn))(qenv(fn), v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v371 = v370;
    v370 = v371;
    if (v370 == nil) goto v380;
    v370 = v371;
    fn = elt(env, 26); /* replus */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v381;

v381:
    fn = elt(env, 27); /* simp */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    stack[0] = v370;
    v370 = stack[0];
    v370 = qcdr(v370);
    if (!consp(v370)) goto v382;
    v370 = (Lisp_Object)17; /* 1 */
    stack[-1] = v370;
    goto v252;

v252:
    v370 = qvalue(elt(env, 2)); /* ncmp!* */
    if (!(v370 == nil)) goto v239;
    v370 = stack[-5];
    fn = elt(env, 28); /* sf2ss */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    stack[0] = v370;
    v370 = stack[0];
    fn = elt(env, 29); /* homogp */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    if (v370 == nil) goto v239;
    v370 = qvalue(elt(env, 18)); /* !*trfac */
    if (v370 == nil) goto v233;
    v370 = elt(env, 19); /* "This polynomial is homogeneous - variables scaled" 
*/
    v370 = Lprinc(nil, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v370 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v233;

v233:
    v370 = stack[0];
    v370 = qcar(v370);
    v370 = qcar(v370);
    stack[-1] = qcar(v370);
    v370 = stack[0];
    v370 = qcdr(v370);
    v370 = qcar(v370);
    v370 = qcar(v370);
    v370 = qcar(v370);
    fn = elt(env, 30); /* listsum */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v370 = cons(stack[-1], v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    stack[-5] = v370;
    v370 = stack[0];
    stack[-1] = qcar(v370);
    v370 = stack[0];
    v370 = qcdr(v370);
    v370 = qcar(v370);
    fn = elt(env, 31); /* subs0 */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v371 = Lreverse(nil, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v370 = (Lisp_Object)17; /* 1 */
    v370 = list2star(stack[-1], v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    stack[0] = v370;
    v370 = stack[0];
    if (!consp(v370)) goto v383;
    v370 = stack[0];
    v370 = qcar(v370);
    if (!consp(v370)) goto v383;
    v370 = stack[0];
    fn = elt(env, 32); /* xx2lx */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v370 = qcdr(v370);
    v370 = qcar(v370);
    fn = elt(env, 33); /* sdlist */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v372 = v370;
    v370 = stack[0];
    v370 = qcar(v370);
    v371 = qcdr(v370);
    v370 = (Lisp_Object)17; /* 1 */
    if (v371 == v370) goto v384;
    v370 = stack[0];
    v370 = qcar(v370);
    v371 = v372;
    fn = elt(env, 34); /* mulvsdl2sq */
    v370 = (*qfn2(fn))(qenv(fn), v370, v371);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v385;

v385:
    fn = elt(env, 35); /* fctrf1 */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    stack[0] = v370;
    v371 = stack[-5];
    v370 = stack[0];
    fn = elt(env, 36); /* rconst */
    v370 = (*qfn2(fn))(qenv(fn), v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    stack[0] = v370;
    v370 = stack[0];
    stack[-1] = qcar(v370);
    v370 = stack[0];
    v371 = qcdr(v370);
    v370 = elt(env, 20); /* orderfactors */
    fn = elt(env, 37); /* sort */
    v370 = (*qfn2(fn))(qenv(fn), v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v370 = cons(stack[-1], v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v386;

v386:
    qvalue(elt(env, 4)) = stack[-2]; /* !*gcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-4]; /* ncmp!* */
    qvalue(elt(env, 1)) = stack[-6]; /* !*exp */
    { popv(8); return onevalue(v370); }

v384:
    v370 = stack[0];
    v370 = qcar(v370);
    v370 = qcar(v370);
    v370 = qcar(v370);
    v371 = v372;
    fn = elt(env, 38); /* univsdl2sq */
    v370 = (*qfn2(fn))(qenv(fn), v370, v371);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v385;

v383:
    v370 = stack[0];
    goto v385;

v239:
    v370 = stack[-5];
    fn = elt(env, 35); /* fctrf1 */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    stack[-5] = v370;
    v370 = stack[-1];
    if (v370 == nil) goto v387;
    v370 = qvalue(elt(env, 6)); /* nil */
    v370 = ncons(v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    qvalue(elt(env, 17)) = v370; /* alglist!* */
    v370 = elt(env, 16); /* !:rn!: */
    qvalue(elt(env, 9)) = v370; /* dmode!* */
    stack[0] = stack[-5];
    v370 = stack[-5];
    v371 = qcar(v370);
    v370 = stack[-1];
    fn = elt(env, 39); /* quotf!* */
    v370 = (*qfn2(fn))(qenv(fn), v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    fn = elt(env, 40); /* setcar */
    v370 = (*qfn2(fn))(qenv(fn), stack[0], v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v387;

v387:
    v370 = stack[-5];
    stack[0] = qcar(v370);
    v370 = stack[-5];
    v371 = qcdr(v370);
    v370 = elt(env, 20); /* orderfactors */
    fn = elt(env, 37); /* sort */
    v370 = (*qfn2(fn))(qenv(fn), v371, v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    v370 = cons(stack[0], v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v386;

v382:
    v370 = stack[0];
    v370 = qcdr(v370);
    stack[-1] = v370;
    v370 = stack[0];
    v370 = qcar(v370);
    stack[-5] = v370;
    goto v252;

v380:
    v370 = (Lisp_Object)1; /* 0 */
    goto v381;

v378:
    v370 = (Lisp_Object)1; /* 0 */
    v371 = v370;
    goto v305;

v377:
    v370 = v372;
    v370 = qcar(v370);
    goto v379;

v263:
    v370 = elt(env, 11); /* "Factorization invalid with MCD off" */
    v371 = v370;
    v370 = v371;
    qvalue(elt(env, 12)) = v370; /* errmsg!* */
    v370 = qvalue(elt(env, 13)); /* !*protfg */
    if (!(v370 == nil)) goto v319;
    v370 = v371;
    fn = elt(env, 41); /* lprie */
    v370 = (*qfn1(fn))(qenv(fn), v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v319;

v319:
    v370 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v376;

v373:
    v370 = stack[-5];
    v370 = ncons(v370);
    nil = C_nil;
    if (exception_pending()) goto v375;
    env = stack[-7];
    goto v386;
/* error exit handlers */
v375:
    env = stack[-7];
    qvalue(elt(env, 4)) = stack[-2]; /* !*gcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-4]; /* ncmp!* */
    qvalue(elt(env, 1)) = stack[-6]; /* !*exp */
    popv(8);
    return nil;
}



/* Code for cd_ordatp */

static Lisp_Object CC_cd_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v392, v393, v394, v395;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cd_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v394 = v388;
    v395 = v0;
/* end of prologue */
    v392 = v395;
    v393 = qcar(v392);
    v392 = elt(env, 1); /* neq */
    if (!(v393 == v392)) goto v313;
    v392 = v394;
    v393 = qcar(v392);
    v392 = elt(env, 2); /* equal */
    if (!(v393 == v392)) goto v313;
    v392 = qvalue(elt(env, 3)); /* t */
    return onevalue(v392);

v313:
    v392 = v395;
    v393 = qcar(v392);
    v392 = elt(env, 2); /* equal */
    if (!(v393 == v392)) goto v396;
    v392 = v394;
    v393 = qcar(v392);
    v392 = elt(env, 1); /* neq */
    if (!(v393 == v392)) goto v396;
    v392 = qvalue(elt(env, 4)); /* nil */
    return onevalue(v392);

v396:
    v392 = v395;
    v392 = qcdr(v392);
    v392 = qcar(v392);
    v393 = v394;
    v393 = qcdr(v393);
    v393 = qcar(v393);
    {
        fn = elt(env, 5); /* ordp */
        return (*qfn2(fn))(qenv(fn), v392, v393);
    }
}



/* Code for lowupperlimitml */

static Lisp_Object CC_lowupperlimitml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v313;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowupperlimitml");
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
    v313 = elt(env, 1); /* "<lowlimit>" */
    fn = elt(env, 7); /* printout */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = stack[0];
    v313 = qcdr(v313);
    v313 = qcar(v313);
    fn = elt(env, 9); /* expression */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = elt(env, 4); /* "</lowlimit>" */
    fn = elt(env, 7); /* printout */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = elt(env, 5); /* "<uplimit>" */
    fn = elt(env, 7); /* printout */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = stack[0];
    v313 = qcdr(v313);
    v313 = qcdr(v313);
    v313 = qcar(v313);
    fn = elt(env, 9); /* expression */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-1];
    v313 = elt(env, 6); /* "</uplimit>" */
    fn = elt(env, 7); /* printout */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v312;
    v313 = nil;
    { popv(2); return onevalue(v313); }
/* error exit handlers */
v312:
    popv(2);
    return nil;
}



/* Code for !*a2kwoweight */

static Lisp_Object CC_Ha2kwoweight(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v314, v312;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *a2kwoweight");
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
    v312 = qvalue(elt(env, 1)); /* t */
    v314 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = qvalue(elt(env, 3)); /* !*uncached */
    qvalue(elt(env, 3)) = v312; /* !*uncached */
    stack[-1] = qvalue(elt(env, 4)); /* wtl!* */
    qvalue(elt(env, 4)) = v314; /* wtl!* */
    v314 = stack[-2];
    fn = elt(env, 6); /* simp!* */
    v314 = (*qfn1(fn))(qenv(fn), v314);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-4];
    stack[0] = v314;
    v314 = stack[0];
    fn = elt(env, 7); /* kernp */
    v314 = (*qfn1(fn))(qenv(fn), v314);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-4];
    if (v314 == nil) goto v391;
    v314 = stack[0];
    v314 = qcar(v314);
    v314 = qcar(v314);
    v314 = qcar(v314);
    v314 = qcar(v314);
    goto v308;

v308:
    qvalue(elt(env, 4)) = stack[-1]; /* wtl!* */
    qvalue(elt(env, 3)) = stack[-3]; /* !*uncached */
    { popv(5); return onevalue(v314); }

v391:
    v312 = stack[-2];
    v314 = elt(env, 5); /* kernel */
    fn = elt(env, 8); /* typerr */
    v314 = (*qfn2(fn))(qenv(fn), v312, v314);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-4];
    goto v308;
/* error exit handlers */
v390:
    env = stack[-4];
    qvalue(elt(env, 4)) = stack[-1]; /* wtl!* */
    qvalue(elt(env, 3)) = stack[-3]; /* !*uncached */
    popv(5);
    return nil;
}



/* Code for vdpsimpcont */

static Lisp_Object CC_vdpsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v330, v399, v301;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsimpcont");
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
    v330 = stack[-1];
    v330 = qcdr(v330);
    v330 = qcdr(v330);
    v330 = qcdr(v330);
    v330 = qcar(v330);
    stack[0] = v330;
    v330 = stack[0];
    if (v330 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v330 = stack[0];
    fn = elt(env, 2); /* dipsimpcont */
    v330 = (*qfn1(fn))(qenv(fn), v330);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-3];
    stack[-2] = v330;
    v330 = stack[-2];
    v330 = qcdr(v330);
    fn = elt(env, 3); /* dip2vdp */
    v330 = (*qfn1(fn))(qenv(fn), v330);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-3];
    stack[-1] = v330;
    v330 = stack[-2];
    v330 = qcar(v330);
    stack[-2] = v330;
    v330 = stack[-2];
    fn = elt(env, 4); /* evzero!? */
    v330 = (*qfn1(fn))(qenv(fn), v330);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-3];
    if (!(v330 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v330 = stack[0];
    v330 = qcdr(v330);
    v330 = qcdr(v330);
    if (!(v330 == nil)) goto v263;
    v330 = stack[-2];
    fn = elt(env, 5); /* evtdeg */
    v399 = (*qfn1(fn))(qenv(fn), v330);
    nil = C_nil;
    if (exception_pending()) goto v395;
    env = stack[-3];
    v330 = (Lisp_Object)17; /* 1 */
    v330 = (Lisp_Object)greaterp2(v399, v330);
    nil = C_nil;
    if (exception_pending()) goto v395;
    v330 = v330 ? lisp_true : nil;
    env = stack[-3];
    if (v330 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else goto v263;

v263:
    v301 = stack[-1];
    v399 = elt(env, 1); /* monfac */
    v330 = stack[-2];
    fn = elt(env, 6); /* vdpputprop */
    v330 = (*qfnn(fn))(qenv(fn), 3, v301, v399, v330);
    nil = C_nil;
    if (exception_pending()) goto v395;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v395:
    popv(4);
    return nil;
}



/* Code for minprec */

static Lisp_Object MS_CDECL CC_minprec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v308;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minprec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minprec");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v308 = qvalue(elt(env, 1)); /* !*bftag */
    if (v308 == nil) goto v318;
    v308 = qvalue(elt(env, 2)); /* !:prec!: */
    return onevalue(v308);

v318:
    v308 = qvalue(elt(env, 3)); /* !!nfpd */
    return onevalue(v308);
}



/* Code for fctins */

static Lisp_Object MS_CDECL CC_fctins(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v388,
                         Lisp_Object v43, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v396, v369;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fctins");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctins");
#endif
    if (stack >= stacklimit)
    {
        push3(v43,v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v388,v43);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v43;
    stack[-1] = v388;
    stack[-2] = v0;
/* end of prologue */
    v396 = stack[0];
    if (v396 == nil) goto v317;
    v396 = stack[0];
    v396 = qcar(v396);
    fn = elt(env, 1); /* fctlength */
    v369 = (*qfn1(fn))(qenv(fn), v396);
    nil = C_nil;
    if (exception_pending()) goto v302;
    env = stack[-3];
    v396 = stack[-1];
    v396 = (Lisp_Object)lessp2(v369, v396);
    nil = C_nil;
    if (exception_pending()) goto v302;
    v396 = v396 ? lisp_true : nil;
    env = stack[-3];
    if (v396 == nil) goto v264;
    v369 = stack[-2];
    v396 = stack[0];
    popv(4);
    return cons(v369, v396);

v264:
    v396 = stack[0];
    stack[-1] = qcar(v396);
    v369 = stack[-2];
    v396 = stack[0];
    v396 = qcdr(v396);
    fn = elt(env, 2); /* fctinsert */
    v396 = (*qfn2(fn))(qenv(fn), v369, v396);
    nil = C_nil;
    if (exception_pending()) goto v302;
    {
        Lisp_Object v319 = stack[-1];
        popv(4);
        return cons(v319, v396);
    }

v317:
    v396 = stack[-2];
    popv(4);
    return ncons(v396);
/* error exit handlers */
v302:
    popv(4);
    return nil;
}



/* Code for adjp */

static Lisp_Object CC_adjp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v407, v378;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adjp");
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
    v378 = stack[-1];
    v407 = elt(env, 1); /* unit */
    if (v378 == v407) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v407 = stack[-1];
    if (!consp(v407)) goto v408;
    v407 = stack[-1];
    v378 = qcar(v407);
    v407 = elt(env, 3); /* comm */
    if (v378 == v407) goto v390;
    v407 = stack[-1];
    v378 = qcar(v407);
    v407 = elt(env, 4); /* anticomm */
    if (v378 == v407) goto v395;
    v407 = stack[-1];
    v378 = qcar(v407);
    v407 = elt(env, 2); /* adjoint */
    v378 = get(v378, v407);
    v407 = stack[-1];
    v407 = qcdr(v407);
    popv(4);
    return cons(v378, v407);

v395:
    stack[-2] = elt(env, 4); /* anticomm */
    v407 = stack[-1];
    v407 = qcdr(v407);
    v407 = qcar(v407);
    stack[0] = CC_adjp(env, v407);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    v407 = stack[-1];
    v407 = qcdr(v407);
    v407 = qcdr(v407);
    v407 = qcar(v407);
    v407 = CC_adjp(env, v407);
    nil = C_nil;
    if (exception_pending()) goto v250;
    {
        Lisp_Object v409 = stack[-2];
        Lisp_Object v304 = stack[0];
        popv(4);
        return list3(v409, v304, v407);
    }

v390:
    stack[-2] = elt(env, 3); /* comm */
    v407 = stack[-1];
    v407 = qcdr(v407);
    v407 = qcdr(v407);
    v407 = qcar(v407);
    stack[0] = CC_adjp(env, v407);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    v407 = stack[-1];
    v407 = qcdr(v407);
    v407 = qcar(v407);
    v407 = CC_adjp(env, v407);
    nil = C_nil;
    if (exception_pending()) goto v250;
    {
        Lisp_Object v410 = stack[-2];
        Lisp_Object v411 = stack[0];
        popv(4);
        return list3(v410, v411, v407);
    }

v408:
    v407 = stack[-1];
    v378 = elt(env, 2); /* adjoint */
    popv(4);
    return get(v407, v378);
/* error exit handlers */
v250:
    popv(4);
    return nil;
}



/* Code for new_prove */

static Lisp_Object CC_new_prove(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v412, v401;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for new_prove");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v388;
    stack[-1] = v0;
/* end of prologue */

v413:
    v412 = stack[0];
    if (v412 == nil) goto v320;
    v401 = stack[-1];
    v412 = stack[0];
    v412 = qcar(v412);
    fn = elt(env, 2); /* new_provev */
    v412 = (*qfn2(fn))(qenv(fn), v401, v412);
    nil = C_nil;
    if (exception_pending()) goto v321;
    env = stack[-2];
    v401 = v412;
    v412 = v401;
    if (v412 == nil) goto v312;
    v412 = v401;
    popv(3);
    return ncons(v412);

v312:
    v401 = stack[-1];
    v412 = stack[0];
    v412 = qcdr(v412);
    stack[-1] = v401;
    stack[0] = v412;
    goto v413;

v320:
    v412 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v412); }
/* error exit handlers */
v321:
    popv(3);
    return nil;
}



/* Code for zeros */

static Lisp_Object CC_zeros(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v313, v314, v312;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zeros");
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
    v314 = v0;
/* end of prologue */

v332:
    v313 = v314;
    if (v313 == nil) goto v318;
    v313 = v314;
    v312 = qcar(v313);
    v313 = (Lisp_Object)1; /* 0 */
    if (v312 == v313) goto v309;
    v313 = v314;
    v313 = qcdr(v313);
    v314 = v313;
    goto v332;

v309:
    v313 = v314;
    v313 = qcdr(v313);
    v313 = CC_zeros(env, v313);
    errexit();
    return add1(v313);

v318:
    v313 = (Lisp_Object)1; /* 0 */
    return onevalue(v313);
}



/* Code for combin */

static Lisp_Object CC_combin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v361, v407;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for combin");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v388;
    stack[-3] = v0;
/* end of prologue */
    v407 = stack[-3];
    v361 = stack[-2];
    v361 = (Lisp_Object)greaterp2(v407, v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    v361 = v361 ? lisp_true : nil;
    env = stack[-5];
    if (v361 == nil) goto v230;
    v361 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v361); }

v230:
    v361 = (Lisp_Object)17; /* 1 */
    stack[-1] = v361;
    stack[-4] = v361;
    v407 = stack[-2];
    v361 = stack[-3];
    v361 = difference2(v407, v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    env = stack[-5];
    v361 = add1(v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    env = stack[-5];
    stack[0] = v361;
    goto v267;

v267:
    v407 = stack[-2];
    v361 = stack[0];
    v361 = difference2(v407, v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    env = stack[-5];
    v361 = Lminusp(nil, v361);
    env = stack[-5];
    if (v361 == nil) goto v316;
    v361 = (Lisp_Object)17; /* 1 */
    stack[0] = v361;
    goto v415;

v415:
    v407 = stack[-3];
    v361 = stack[0];
    v361 = difference2(v407, v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    env = stack[-5];
    v361 = Lminusp(nil, v361);
    env = stack[-5];
    if (v361 == nil) goto v328;
    v407 = stack[-4];
    v361 = stack[-1];
    popv(6);
    return quot2(v407, v361);

v328:
    v407 = stack[-1];
    v361 = stack[0];
    v361 = times2(v407, v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    env = stack[-5];
    stack[-1] = v361;
    v361 = stack[0];
    v361 = add1(v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    env = stack[-5];
    stack[0] = v361;
    goto v415;

v316:
    v407 = stack[-4];
    v361 = stack[0];
    v361 = times2(v407, v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    env = stack[-5];
    stack[-4] = v361;
    v361 = stack[0];
    v361 = add1(v361);
    nil = C_nil;
    if (exception_pending()) goto v409;
    env = stack[-5];
    stack[0] = v361;
    goto v267;
/* error exit handlers */
v409:
    popv(6);
    return nil;
}



/* Code for cdr_signsort */

static Lisp_Object CC_cdr_signsort(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v427, v428;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdr_signsort");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v388;
    v427 = v0;
/* end of prologue */
    fn = elt(env, 3); /* copy */
    v427 = (*qfn1(fn))(qenv(fn), v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-6] = v427;
    v427 = (Lisp_Object)17; /* 1 */
    stack[-1] = v427;
    v427 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v427;
    goto v329;

v329:
    v427 = stack[-6];
    if (v427 == nil) goto v429;
    v427 = stack[-4];
    if (v427 == nil) goto v314;
    v427 = stack[-6];
    v427 = qcar(v427);
    v428 = qcdr(v427);
    v427 = stack[-4];
    v427 = qcar(v427);
    v427 = qcdr(v427);
    if (equal(v428, v427)) goto v400;
    stack[0] = stack[-5];
    v427 = stack[-4];
    v427 = qcar(v427);
    v428 = qcdr(v427);
    v427 = stack[-6];
    v427 = qcar(v427);
    v427 = qcdr(v427);
    v427 = list2(v428, v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    fn = elt(env, 4); /* apply */
    v427 = (*qfn2(fn))(qenv(fn), stack[0], v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    if (v427 == nil) goto v258;
    v427 = stack[-6];
    v428 = qcar(v427);
    v427 = stack[-4];
    v427 = cons(v428, v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-4] = v427;
    v427 = stack[-6];
    v427 = qcdr(v427);
    stack[-6] = v427;
    goto v329;

v258:
    v427 = stack[-1];
    v427 = negate(v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-1] = v427;
    v427 = stack[-4];
    stack[-3] = v427;
    v427 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v427;
    goto v414;

v414:
    v427 = stack[-2];
    if (v427 == nil) goto v404;
    v427 = stack[-3];
    v427 = qcdr(v427);
    if (v427 == nil) goto v304;
    v427 = stack[-3];
    v427 = qcdr(v427);
    v427 = qcar(v427);
    v428 = qcdr(v427);
    v427 = stack[-6];
    v427 = qcar(v427);
    v427 = qcdr(v427);
    if (equal(v428, v427)) goto v430;
    stack[0] = stack[-5];
    v427 = stack[-3];
    v427 = qcdr(v427);
    v427 = qcar(v427);
    v428 = qcdr(v427);
    v427 = stack[-6];
    v427 = qcar(v427);
    v427 = qcdr(v427);
    v427 = list2(v428, v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    fn = elt(env, 4); /* apply */
    v427 = (*qfn2(fn))(qenv(fn), stack[0], v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    if (v427 == nil) goto v431;
    v427 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v427;
    goto v414;

v431:
    v427 = stack[-3];
    v427 = qcdr(v427);
    stack[-3] = v427;
    v427 = stack[-1];
    v427 = negate(v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-1] = v427;
    goto v414;

v430:
    v427 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v427;
    v427 = (Lisp_Object)1; /* 0 */
    stack[-1] = v427;
    v427 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v427;
    stack[-4] = v427;
    goto v414;

v304:
    v427 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v427;
    goto v414;

v404:
    v427 = stack[-6];
    if (v427 == nil) goto v329;
    stack[0] = stack[-3];
    v427 = stack[-6];
    v428 = qcar(v427);
    v427 = stack[-3];
    v427 = qcdr(v427);
    v427 = cons(v428, v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    v427 = Lrplacd(nil, stack[0], v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    v427 = stack[-6];
    v427 = qcdr(v427);
    stack[-6] = v427;
    goto v329;

v400:
    v427 = (Lisp_Object)1; /* 0 */
    stack[-1] = v427;
    v427 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v427;
    stack[-4] = v427;
    goto v329;

v314:
    v427 = stack[-6];
    v428 = qcar(v427);
    v427 = stack[-4];
    v427 = cons(v428, v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-7];
    stack[-4] = v427;
    v427 = stack[-6];
    v427 = qcdr(v427);
    stack[-6] = v427;
    goto v329;

v429:
    stack[0] = stack[-1];
    v427 = stack[-4];
    v427 = Lreverse(nil, v427);
    nil = C_nil;
    if (exception_pending()) goto v228;
    {
        Lisp_Object v226 = stack[0];
        popv(8);
        return cons(v226, v427);
    }
/* error exit handlers */
v228:
    popv(8);
    return nil;
}



/* Code for random!-teeny!-prime */

static Lisp_Object CC_randomKteenyKprime(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v392, v393;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random-teeny-prime");
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
    v392 = stack[0];
    v301 = elt(env, 1); /* all */
    if (v392 == v301) goto v332;
    v301 = stack[0];
    v392 = Llength(nil, v301);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-2];
    v301 = (Lisp_Object)161; /* 10 */
    if (!(v392 == v301)) goto v432;

v332:
    v301 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v301); }

v432:
    stack[-1] = qvalue(elt(env, 3)); /* teeny!-primes */
    fn = elt(env, 4); /* next!-random!-number */
    v392 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-2];
    v301 = (Lisp_Object)161; /* 10 */
    v301 = Cremainder(v392, v301);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-2];
    v301 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v301/(16/CELL)));
    v393 = v301;
    v392 = v393;
    v301 = stack[0];
    v301 = Lmember(nil, v392, v301);
    if (v301 == nil) { popv(3); return onevalue(v393); }
    else goto v432;
/* error exit handlers */
v426:
    popv(3);
    return nil;
}



/* Code for qqe_simplqneq */

static Lisp_Object CC_qqe_simplqneq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v367, v368, v364;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplqneq");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v368 = v388;
    v367 = v0;
/* end of prologue */
    v368 = v367;
    v368 = qcdr(v368);
    v368 = qcar(v368);
    v367 = qcdr(v367);
    v367 = qcdr(v367);
    v367 = qcar(v367);
    v364 = elt(env, 1); /* qequal */
    fn = elt(env, 6); /* qqe_mk2 */
    v368 = (*qfnn(fn))(qenv(fn), 3, v364, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-3];
    v367 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 7); /* qqe_simplqequal */
    v367 = (*qfn2(fn))(qenv(fn), v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-3];
    stack[-2] = v367;
    v368 = stack[-2];
    v367 = elt(env, 3); /* true */
    if (v368 == v367) goto v323;
    v368 = stack[-2];
    v367 = elt(env, 4); /* false */
    if (v368 == v367) goto v310;
    stack[-1] = elt(env, 5); /* qneq */
    v367 = stack[-2];
    fn = elt(env, 8); /* qqe_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-3];
    v367 = stack[-2];
    fn = elt(env, 9); /* qqe_arg2r */
    v367 = (*qfn1(fn))(qenv(fn), v367);
    nil = C_nil;
    if (exception_pending()) goto v326;
    env = stack[-3];
    fn = elt(env, 6); /* qqe_mk2 */
    v367 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v367);
    nil = C_nil;
    if (exception_pending()) goto v326;
    { popv(4); return onevalue(v367); }

v310:
    v367 = elt(env, 3); /* true */
    { popv(4); return onevalue(v367); }

v323:
    v367 = elt(env, 4); /* false */
    { popv(4); return onevalue(v367); }
/* error exit handlers */
v326:
    popv(4);
    return nil;
}



/* Code for cl_applysac */

static Lisp_Object CC_cl_applysac(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v433, v260, v405;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_applysac");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v388;
    v260 = v0;
/* end of prologue */
    v433 = nil;
    stack[-1] = v260;
    goto v309;

v309:
    v260 = stack[-1];
    if (v260 == nil) { popv(3); return onevalue(v433); }
    v260 = stack[-1];
    v405 = qcar(v260);
    v260 = v433;
    v433 = stack[0];
    fn = elt(env, 3); /* cl_applysac1 */
    v433 = (*qfnn(fn))(qenv(fn), 3, v405, v260, v433);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    v405 = v433;
    v260 = v405;
    v433 = elt(env, 2); /* break */
    if (v260 == v433) goto v432;
    v433 = stack[-1];
    v433 = qcdr(v433);
    stack[-1] = v433;
    v433 = v405;
    v433 = qcar(v433);
    if (v433 == nil) goto v395;
    v433 = v405;
    v433 = qcar(v433);
    v433 = qcdr(v433);
    v260 = v405;
    v260 = qcdr(v260);
    v433 = cons(v433, v260);
    nil = C_nil;
    if (exception_pending()) goto v367;
    env = stack[-2];
    goto v309;

v395:
    v433 = v405;
    v433 = qcdr(v433);
    goto v309;

v432:
    v433 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v433;
    v433 = elt(env, 2); /* break */
    goto v309;
/* error exit handlers */
v367:
    popv(3);
    return nil;
}



/* Code for rat_sgn */

static Lisp_Object CC_rat_sgn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v366, v403;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rat_sgn");
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
    v366 = stack[0];
    v366 = qcar(v366);
    if (v366 == nil) goto v332;
    v366 = stack[0];
    v403 = qcar(v366);
    v366 = (Lisp_Object)1; /* 0 */
    if (v403 == v366) goto v332;
    v366 = stack[0];
    v403 = qcar(v366);
    v366 = (Lisp_Object)1; /* 0 */
    v366 = (Lisp_Object)greaterp2(v403, v366);
    nil = C_nil;
    if (exception_pending()) goto v434;
    v366 = v366 ? lisp_true : nil;
    env = stack[-2];
    if (v366 == nil) goto v321;
    v366 = (Lisp_Object)17; /* 1 */
    stack[-1] = v366;
    goto v301;

v301:
    v366 = stack[0];
    v403 = qcdr(v366);
    v366 = (Lisp_Object)1; /* 0 */
    v366 = (Lisp_Object)greaterp2(v403, v366);
    nil = C_nil;
    if (exception_pending()) goto v434;
    v366 = v366 ? lisp_true : nil;
    env = stack[-2];
    if (v366 == nil) goto v240;
    v366 = (Lisp_Object)17; /* 1 */
    goto v374;

v374:
    if (equal(stack[-1], v366)) goto v402;
    v366 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v366); }

v402:
    v366 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v366); }

v240:
    v366 = stack[0];
    v403 = qcdr(v366);
    v366 = (Lisp_Object)1; /* 0 */
    v366 = (Lisp_Object)lessp2(v403, v366);
    nil = C_nil;
    if (exception_pending()) goto v434;
    v366 = v366 ? lisp_true : nil;
    if (v366 == nil) goto v327;
    v366 = (Lisp_Object)-15; /* -1 */
    goto v374;

v327:
    v366 = (Lisp_Object)1; /* 0 */
    goto v374;

v321:
    v366 = stack[0];
    v403 = qcar(v366);
    v366 = (Lisp_Object)1; /* 0 */
    v366 = (Lisp_Object)lessp2(v403, v366);
    nil = C_nil;
    if (exception_pending()) goto v434;
    v366 = v366 ? lisp_true : nil;
    env = stack[-2];
    if (v366 == nil) goto v315;
    v366 = (Lisp_Object)-15; /* -1 */
    stack[-1] = v366;
    goto v301;

v315:
    v366 = (Lisp_Object)1; /* 0 */
    stack[-1] = v366;
    goto v301;

v332:
    v366 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v366); }
/* error exit handlers */
v434:
    popv(3);
    return nil;
}



/* Code for conditionml */

static Lisp_Object CC_conditionml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v373;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conditionml");
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
    v373 = elt(env, 1); /* "<condition>" */
    fn = elt(env, 5); /* printout */
    v373 = (*qfn1(fn))(qenv(fn), v373);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-1];
    v373 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 6); /* indent!* */
    v373 = (*qfn1(fn))(qenv(fn), v373);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-1];
    v373 = stack[0];
    v373 = qcar(v373);
    fn = elt(env, 7); /* expression */
    v373 = (*qfn1(fn))(qenv(fn), v373);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-1];
    v373 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 6); /* indent!* */
    v373 = (*qfn1(fn))(qenv(fn), v373);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-1];
    v373 = elt(env, 4); /* "</condition>" */
    fn = elt(env, 5); /* printout */
    v373 = (*qfn1(fn))(qenv(fn), v373);
    nil = C_nil;
    if (exception_pending()) goto v329;
    v373 = nil;
    { popv(2); return onevalue(v373); }
/* error exit handlers */
v329:
    popv(2);
    return nil;
}



/* Code for !:mod!:units */

static Lisp_Object MS_CDECL CC_TmodTunits(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v388,
                         Lisp_Object v43, Lisp_Object v196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v438, v250;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, ":mod:units");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :mod:units");
#endif
    if (stack >= stacklimit)
    {
        push4(v196,v43,v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v388,v43,v196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v196;
    stack[-3] = v43;
    stack[-4] = v388;
    stack[-5] = v0;
/* end of prologue */

v307:
    v250 = stack[-4];
    v438 = (Lisp_Object)1; /* 0 */
    if (v250 == v438) goto v318;
    v250 = stack[-4];
    v438 = (Lisp_Object)17; /* 1 */
    if (v250 == v438) goto v312;
    v250 = stack[-5];
    v438 = stack[-4];
    v438 = quot2(v250, v438);
    nil = C_nil;
    if (exception_pending()) goto v439;
    env = stack[-7];
    stack[-6] = v438;
    stack[-1] = stack[-4];
    stack[0] = stack[-5];
    v250 = stack[-4];
    v438 = stack[-6];
    v438 = times2(v250, v438);
    nil = C_nil;
    if (exception_pending()) goto v439;
    env = stack[-7];
    stack[-4] = difference2(stack[0], v438);
    nil = C_nil;
    if (exception_pending()) goto v439;
    env = stack[-7];
    stack[0] = stack[-2];
    v250 = stack[-2];
    v438 = stack[-6];
    v438 = times2(v250, v438);
    nil = C_nil;
    if (exception_pending()) goto v439;
    env = stack[-7];
    v438 = difference2(stack[-3], v438);
    nil = C_nil;
    if (exception_pending()) goto v439;
    env = stack[-7];
    stack[-5] = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v438;
    goto v307;

v312:
    v250 = stack[-2];
    v438 = (Lisp_Object)1; /* 0 */
    v438 = (Lisp_Object)lessp2(v250, v438);
    nil = C_nil;
    if (exception_pending()) goto v439;
    v438 = v438 ? lisp_true : nil;
    env = stack[-7];
    if (v438 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v438 = stack[-2];
    v250 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(8);
    return plus2(v438, v250);

v318:
    v438 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v438); }
/* error exit handlers */
v439:
    popv(8);
    return nil;
}



/* Code for vdpfmon */

static Lisp_Object CC_vdpfmon(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v263;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpfmon");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v388;
    v263 = v0;
/* end of prologue */
    stack[-5] = elt(env, 1); /* vdp */
    stack[-3] = stack[-4];
    stack[-2] = v263;
    stack[-1] = stack[-4];
    stack[0] = ncons(v263);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-6];
    v263 = qvalue(elt(env, 2)); /* nil */
    v263 = ncons(v263);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-6];
    v263 = acons(stack[-1], stack[0], v263);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-6];
    v263 = list3star(stack[-5], stack[-3], stack[-2], v263);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-6];
    stack[-1] = v263;
    v263 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v263 == nil) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v263 = stack[-4];
    fn = elt(env, 4); /* vevtdeg */
    v263 = (*qfn1(fn))(qenv(fn), v263);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-6];
    fn = elt(env, 5); /* gsetsugar */
    v263 = (*qfn2(fn))(qenv(fn), stack[0], v263);
    nil = C_nil;
    if (exception_pending()) goto v398;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
/* error exit handlers */
v398:
    popv(7);
    return nil;
}



/* Code for evweightedcomp1 */

static Lisp_Object CC_evweightedcomp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v373, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evweightedcomp1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v269 = v388;
    v373 = v0;
/* end of prologue */
    v230 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* evweightedcomp2 */
        return (*qfnn(fn))(qenv(fn), 3, v230, v373, v269);
    }
}



/* Code for logrtn */

static Lisp_Object CC_logrtn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v399, v301;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for logrtn");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v388;
    stack[-2] = v0;
/* end of prologue */
    v399 = stack[-2];
    v399 = qcdr(v399);
    v399 = qcar(v399);
    stack[0] = v399;
    v399 = stack[0];
    fn = elt(env, 3); /* msd */
    v399 = (*qfn1(fn))(qenv(fn), v399);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-4];
    v399 = sub1(v399);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-4];
    stack[-3] = v399;
    v301 = elt(env, 1); /* 2.0 */
    v399 = stack[-3];
    v399 = Lexpt(nil, v301, v399);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-4];
    v399 = quot2(stack[0], v399);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-4];
    fn = elt(env, 4); /* log */
    stack[0] = (*qfn1(fn))(qenv(fn), v399);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-4];
    v301 = stack[-3];
    v399 = stack[-2];
    v399 = qcdr(v399);
    v399 = qcdr(v399);
    v301 = plus2(v301, v399);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-4];
    v399 = qvalue(elt(env, 2)); /* log2 */
    v399 = times2(v301, v399);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-4];
    v399 = plus2(stack[0], v399);
    nil = C_nil;
    if (exception_pending()) goto v426;
    v301 = v399;
    v399 = stack[-1];
    popv(5);
    return quot2(v301, v399);
/* error exit handlers */
v426:
    popv(5);
    return nil;
}



/* Code for physopplus */

static Lisp_Object CC_physopplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v405, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopplus");
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
    v405 = stack[0];
    v405 = qcar(v405);
    fn = elt(env, 3); /* physopsim!* */
    v405 = (*qfn1(fn))(qenv(fn), v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    stack[-3] = v405;
    v405 = stack[0];
    v405 = qcdr(v405);
    stack[0] = v405;
    goto v269;

v269:
    v405 = stack[0];
    if (v405 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v405 = stack[0];
    v405 = qcar(v405);
    fn = elt(env, 3); /* physopsim!* */
    v405 = (*qfn1(fn))(qenv(fn), v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    stack[-2] = v405;
    v405 = stack[-3];
    fn = elt(env, 4); /* getphystype */
    v405 = (*qfn1(fn))(qenv(fn), v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    stack[-1] = v405;
    v405 = stack[-2];
    fn = elt(env, 4); /* getphystype */
    v405 = (*qfn1(fn))(qenv(fn), v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    v240 = v405;
    if (v240 == nil) goto v399;
    v240 = stack[-1];
    if (v240 == nil) goto v399;
    v240 = stack[-1];
    if (v240 == v405) goto v399;
    v240 = elt(env, 0); /* physopplus */
    v405 = elt(env, 2); /* "type mismatch in plus " */
    fn = elt(env, 5); /* rederr2 */
    v405 = (*qfn2(fn))(qenv(fn), v240, v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    goto v399;

v399:
    v405 = stack[-3];
    fn = elt(env, 6); /* physop2sq */
    stack[-1] = (*qfn1(fn))(qenv(fn), v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    v405 = stack[-2];
    fn = elt(env, 6); /* physop2sq */
    v405 = (*qfn1(fn))(qenv(fn), v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    fn = elt(env, 7); /* addsq */
    v405 = (*qfn2(fn))(qenv(fn), stack[-1], v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    fn = elt(env, 8); /* mk!*sq */
    v405 = (*qfn1(fn))(qenv(fn), v405);
    nil = C_nil;
    if (exception_pending()) goto v360;
    env = stack[-4];
    stack[-3] = v405;
    v405 = stack[0];
    v405 = qcdr(v405);
    stack[0] = v405;
    goto v269;
/* error exit handlers */
v360:
    popv(5);
    return nil;
}



/* Code for red_prepare */

static Lisp_Object CC_red_prepare(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v374;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_prepare");
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
    v374 = stack[-1];
    fn = elt(env, 1); /* bas_nr */
    stack[-2] = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-3];
    v374 = stack[-1];
    fn = elt(env, 2); /* bas_dpoly */
    stack[0] = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-3];
    v374 = stack[-1];
    fn = elt(env, 3); /* bas_rep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-3];
    v374 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* dp_from_ei */
    v374 = (*qfn1(fn))(qenv(fn), v374);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-3];
    fn = elt(env, 5); /* dp_sum */
    v374 = (*qfn2(fn))(qenv(fn), stack[-1], v374);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-3];
    {
        Lisp_Object v313 = stack[-2];
        Lisp_Object v314 = stack[0];
        popv(4);
        fn = elt(env, 6); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v313, v314, v374);
    }
/* error exit handlers */
v397:
    popv(4);
    return nil;
}



/* Code for sep_tens_from_other */

static Lisp_Object CC_sep_tens_from_other(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v444, v445;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sep_tens_from_other");
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
    stack[-4] = nil;
    v444 = (Lisp_Object)17; /* 1 */
    v444 = (Lisp_Object)zerop(v444);
    v444 = v444 ? lisp_true : nil;
    env = stack[-5];
    if (v444 == nil) goto v230;
    v444 = qvalue(elt(env, 1)); /* nil */
    goto v308;

v308:
    stack[-2] = v444;
    goto v306;

v306:
    v444 = stack[-3];
    if (is_number(v444)) goto v324;
    v444 = stack[-3];
    v444 = qcar(v444);
    v444 = qcar(v444);
    v444 = qcar(v444);
    if (!consp(v444)) goto v319;
    v444 = stack[-3];
    v444 = qcar(v444);
    v444 = qcar(v444);
    v444 = qcar(v444);
    v445 = qcar(v444);
    v444 = elt(env, 2); /* translate1 */
    v444 = get(v445, v444);
    env = stack[-5];
    stack[-1] = v444;
    if (v444 == nil) goto v364;
    v444 = stack[-3];
    fn = elt(env, 3); /* fullcopy */
    v444 = (*qfn1(fn))(qenv(fn), v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    stack[-3] = v444;
    v444 = stack[-3];
    v444 = qcar(v444);
    stack[0] = qcar(v444);
    v445 = stack[-1];
    v444 = stack[-3];
    v444 = qcar(v444);
    v444 = qcar(v444);
    v444 = qcar(v444);
    v444 = Lapply1(nil, v445, v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    fn = elt(env, 4); /* setcar */
    v444 = (*qfn2(fn))(qenv(fn), stack[0], v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    goto v364;

v364:
    v444 = stack[-3];
    v444 = qcar(v444);
    v444 = qcar(v444);
    v444 = qcar(v444);
    stack[0] = v444;
    fn = elt(env, 5); /* tensorp */
    v444 = (*qfn1(fn))(qenv(fn), v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    if (v444 == nil) goto v446;
    v444 = stack[0];
    fn = elt(env, 6); /* no_dum_varp */
    v444 = (*qfn1(fn))(qenv(fn), v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    if (v444 == nil) goto v447;
    v444 = stack[0];
    v444 = qcar(v444);
    if (!symbolp(v444)) v444 = nil;
    else { v444 = qfastgets(v444);
           if (v444 != nil) { v444 = elt(v444, 0); /* noncom */
#ifdef RECORD_GET
             if (v444 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v444 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v444 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v444 == SPID_NOPROP) v444 = nil; else v444 = lisp_true; }}
#endif
    if (!(v444 == nil)) goto v447;
    stack[0] = stack[-2];
    v444 = stack[-3];
    v444 = qcar(v444);
    v445 = qcar(v444);
    v444 = (Lisp_Object)17; /* 1 */
    v444 = cons(v445, v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    v444 = ncons(v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v444 = (*qfn2(fn))(qenv(fn), stack[0], v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    stack[-2] = v444;
    goto v311;

v311:
    v444 = stack[-3];
    v444 = qcar(v444);
    v444 = qcdr(v444);
    stack[-3] = v444;
    goto v306;

v447:
    v444 = stack[-3];
    v444 = qcar(v444);
    v444 = qcar(v444);
    v445 = qcar(v444);
    v444 = stack[-4];
    v444 = cons(v445, v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    stack[-4] = v444;
    goto v311;

v446:
    stack[0] = stack[-2];
    v444 = stack[-3];
    v444 = qcar(v444);
    v445 = qcar(v444);
    v444 = (Lisp_Object)17; /* 1 */
    v444 = cons(v445, v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    v444 = ncons(v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v444 = (*qfn2(fn))(qenv(fn), stack[0], v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    stack[-2] = v444;
    goto v311;

v319:
    stack[0] = stack[-2];
    v444 = stack[-3];
    v444 = qcar(v444);
    v445 = qcar(v444);
    v444 = (Lisp_Object)17; /* 1 */
    v444 = cons(v445, v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    v444 = ncons(v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v444 = (*qfn2(fn))(qenv(fn), stack[0], v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-5];
    stack[-2] = v444;
    goto v311;

v324:
    v444 = stack[-4];
    stack[0] = Lnreverse(nil, v444);
    env = stack[-5];
    v445 = stack[-2];
    v444 = stack[-3];
    v444 = (Lisp_Object)zerop(v444);
    v444 = v444 ? lisp_true : nil;
    env = stack[-5];
    if (v444 == nil) goto v266;
    v444 = qvalue(elt(env, 1)); /* nil */
    goto v390;

v390:
    fn = elt(env, 7); /* multf */
    v444 = (*qfn2(fn))(qenv(fn), v445, v444);
    nil = C_nil;
    if (exception_pending()) goto v427;
    {
        Lisp_Object v428 = stack[0];
        popv(6);
        return list2(v428, v444);
    }

v266:
    v444 = stack[-3];
    goto v390;

v230:
    v444 = (Lisp_Object)17; /* 1 */
    goto v308;
/* error exit handlers */
v427:
    popv(6);
    return nil;
}



/* Code for mk_character */

static Lisp_Object CC_mk_character(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v256;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_character");
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
    stack[-5] = v0;
/* end of prologue */
    v258 = stack[-5];
    fn = elt(env, 2); /* get_group_in */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    stack[-6] = v258;
    v258 = stack[-6];
    fn = elt(env, 3); /* get!*elements */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    stack[-4] = v258;
    v258 = stack[-4];
    if (v258 == nil) goto v402;
    v258 = stack[-4];
    v258 = qcar(v258);
    stack[0] = v258;
    v256 = v258;
    v258 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v258 = (*qfn2(fn))(qenv(fn), v256, v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+trace */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    v258 = list2(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    stack[-2] = v258;
    stack[-3] = v258;
    goto v269;

v269:
    v258 = stack[-4];
    v258 = qcdr(v258);
    stack[-4] = v258;
    v258 = stack[-4];
    if (v258 == nil) goto v263;
    stack[-1] = stack[-2];
    v258 = stack[-4];
    v258 = qcar(v258);
    stack[0] = v258;
    v256 = v258;
    v258 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v258 = (*qfn2(fn))(qenv(fn), v256, v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+trace */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    v258 = list2(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    v258 = Lrplacd(nil, stack[-1], v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-7];
    v258 = stack[-2];
    v258 = qcdr(v258);
    stack[-2] = v258;
    goto v269;

v263:
    v258 = stack[-3];
    goto v268;

v268:
    stack[0] = v258;
    v258 = stack[-6];
    v256 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v361;
    v258 = stack[0];
        popv(8);
        return Lappend(nil, v256, v258);

v402:
    v258 = qvalue(elt(env, 1)); /* nil */
    goto v268;
/* error exit handlers */
v361:
    popv(8);
    return nil;
}



/* Code for limitom */

static Lisp_Object CC_limitom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v436, v437, v438;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for limitom");
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
    v437 = v0;
/* end of prologue */
    v436 = v437;
    v436 = qcdr(v436);
    v436 = qcdr(v436);
    v436 = qcar(v436);
    stack[-2] = v436;
    v436 = v437;
    v436 = qcdr(v436);
    v436 = qcdr(v436);
    v436 = qcdr(v436);
    v436 = qcar(v436);
    stack[0] = v436;
    v436 = v437;
    v436 = Lreverse(nil, v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = qcar(v436);
    stack[-3] = v436;
    v436 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 13); /* indent!* */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = elt(env, 3); /* "<OMS cd=""limit1"" name=""limit""/>" */
    fn = elt(env, 12); /* printout */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = stack[0];
    v437 = qcar(v436);
    v436 = elt(env, 4); /* lowlimit */
    if (!(v437 == v436)) goto v310;
    v436 = stack[0];
    v436 = qcdr(v436);
    v436 = qcar(v436);
    fn = elt(env, 14); /* objectom */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = elt(env, 5); /* "<OMS cd=""limit1"" name=""null""/>" */
    fn = elt(env, 12); /* printout */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    goto v310;

v310:
    v436 = stack[0];
    v437 = qcar(v436);
    v436 = elt(env, 6); /* condition */
    if (!(v437 == v436)) goto v379;
    v436 = stack[0];
    v436 = qcdr(v436);
    v436 = qcar(v436);
    v436 = Lreverse(nil, v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = qcar(v436);
    fn = elt(env, 14); /* objectom */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = stack[0];
    v436 = qcdr(v436);
    v436 = qcar(v436);
    v436 = qcdr(v436);
    v436 = qcar(v436);
    v436 = qcar(v436);
    v436 = qcdr(v436);
    v436 = qcar(v436);
    stack[0] = v436;
    v436 = elt(env, 7); /* "<OMS cd=""limit1"" name=""" */
    fn = elt(env, 12); /* printout */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = stack[0];
    v436 = Lprinc(nil, v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = elt(env, 8); /* """/>" */
    v436 = Lprinc(nil, v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    goto v379;

v379:
    stack[-1] = elt(env, 9); /* limit */
    stack[0] = qvalue(elt(env, 10)); /* nil */
    v438 = stack[-2];
    v437 = stack[-3];
    v436 = qvalue(elt(env, 10)); /* nil */
    v436 = list2star(v438, v437, v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = list2star(stack[-1], stack[0], v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    fn = elt(env, 15); /* lambdaom */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = qvalue(elt(env, 10)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-4];
    v436 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v436 = (*qfn1(fn))(qenv(fn), v436);
    nil = C_nil;
    if (exception_pending()) goto v411;
    v436 = nil;
    { popv(5); return onevalue(v436); }
/* error exit handlers */
v411:
    popv(5);
    return nil;
}



/* Code for make!-ps */

static Lisp_Object MS_CDECL CC_makeKps(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v388,
                         Lisp_Object v43, Lisp_Object v196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v436, v437, v438;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "make-ps");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-ps");
#endif
    if (stack >= stacklimit)
    {
        push4(v196,v43,v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v388,v43,v196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v196;
    stack[-1] = v43;
    stack[-2] = v388;
    stack[-3] = v0;
/* end of prologue */
    v437 = elt(env, 1); /* tps */
    v436 = elt(env, 2); /* tag */
    stack[-4] = get(v437, v436);
    env = stack[-5];
    v436 = (Lisp_Object)113; /* 7 */
    v436 = Lmkvect(nil, v436);
    nil = C_nil;
    if (exception_pending()) goto v450;
    env = stack[-5];
    v436 = cons(stack[-4], v436);
    nil = C_nil;
    if (exception_pending()) goto v450;
    env = stack[-5];
    stack[-4] = v436;
    v438 = stack[-4];
    v437 = (Lisp_Object)1; /* 0 */
    v436 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* ps!:putv */
    v436 = (*qfnn(fn))(qenv(fn), 3, v438, v437, v436);
    nil = C_nil;
    if (exception_pending()) goto v450;
    env = stack[-5];
    v438 = stack[-4];
    v437 = (Lisp_Object)97; /* 6 */
    v436 = stack[-3];
    fn = elt(env, 4); /* ps!:putv */
    v436 = (*qfnn(fn))(qenv(fn), 3, v438, v437, v436);
    nil = C_nil;
    if (exception_pending()) goto v450;
    env = stack[-5];
    v438 = stack[-4];
    v437 = (Lisp_Object)65; /* 4 */
    v436 = stack[-2];
    fn = elt(env, 4); /* ps!:putv */
    v436 = (*qfnn(fn))(qenv(fn), 3, v438, v437, v436);
    nil = C_nil;
    if (exception_pending()) goto v450;
    env = stack[-5];
    v438 = stack[-4];
    v437 = (Lisp_Object)33; /* 2 */
    v436 = stack[-1];
    fn = elt(env, 4); /* ps!:putv */
    v436 = (*qfnn(fn))(qenv(fn), 3, v438, v437, v436);
    nil = C_nil;
    if (exception_pending()) goto v450;
    env = stack[-5];
    v438 = stack[-4];
    v437 = (Lisp_Object)49; /* 3 */
    v436 = stack[0];
    fn = elt(env, 4); /* ps!:putv */
    v436 = (*qfnn(fn))(qenv(fn), 3, v438, v437, v436);
    nil = C_nil;
    if (exception_pending()) goto v450;
    env = stack[-5];
    v438 = stack[-4];
    v437 = (Lisp_Object)17; /* 1 */
    v436 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 4); /* ps!:putv */
    v436 = (*qfnn(fn))(qenv(fn), 3, v438, v437, v436);
    nil = C_nil;
    if (exception_pending()) goto v450;
    env = stack[-5];
    v436 = stack[-4];
    v437 = qcdr(v436);
    v436 = (Lisp_Object)113; /* 7 */
    v438 = qvalue(elt(env, 3)); /* !*sqvar!* */
    *(Lisp_Object *)((char *)v437 + (CELL-TAG_VECTOR) + ((int32_t)v436/(16/CELL))) = v438;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v450:
    popv(6);
    return nil;
}



/* Code for get_num_part */

static Lisp_Object CC_get_num_part(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v454;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_num_part");
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
    goto v308;

v308:
    v454 = stack[0];
    v234 = (Lisp_Object)1; /* 0 */
    if (v454 == v234) goto v408;
    v234 = stack[0];
    if (is_number(v234)) goto v312;
    v234 = stack[0];
    if (!consp(v234)) goto v400;
    v454 = stack[0];
    v234 = elt(env, 1); /* !:rd!: */
    if (!consp(v454)) goto v365;
    v454 = qcar(v454);
    if (!(v454 == v234)) goto v365;
    v234 = stack[0];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v426;
    v234 = stack[0];
    fn = elt(env, 5); /* bf2flr */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    {
        Lisp_Object v455 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v455, v234);
    }

v426:
    v454 = stack[-1];
    v234 = stack[0];
    v234 = qcdr(v234);
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v454, v234);
    }

v365:
    v454 = stack[0];
    v234 = elt(env, 2); /* !:dn!: */
    if (!consp(v454)) goto v304;
    v454 = qcar(v454);
    if (!(v454 == v234)) goto v304;
    v234 = stack[0];
    v234 = qcdr(v234);
    fn = elt(env, 7); /* rdwrap2 */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    {
        Lisp_Object v456 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v456, v234);
    }

v304:
    v454 = stack[0];
    v234 = elt(env, 3); /* minus */
    if (!consp(v454)) goto v457;
    v454 = qcar(v454);
    if (!(v454 == v234)) goto v457;
    v234 = stack[0];
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v234 = CC_get_num_part(env, v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    v454 = v234;
    if (is_number(v454)) goto v431;
    v454 = elt(env, 3); /* minus */
    v234 = list2(v454, v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    goto v252;

v252:
    {
        Lisp_Object v429 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v429, v234);
    }

v431:
    v234 = Lfloat(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    v234 = negate(v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    goto v252;

v457:
    v454 = stack[0];
    v234 = elt(env, 4); /* expt */
    if (!consp(v454)) goto v458;
    v454 = qcar(v454);
    if (!(v454 == v234)) goto v458;
    v234 = stack[0];
    fn = elt(env, 8); /* rdwrap!-expt */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    {
        Lisp_Object v444 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v444, v234);
    }

v458:
    v234 = stack[0];
    v234 = qcar(v234);
    v454 = CC_get_num_part(env, v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    v234 = stack[-1];
    v234 = cons(v454, v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    stack[-1] = v234;
    v234 = stack[0];
    v234 = qcdr(v234);
    stack[0] = v234;
    goto v308;

v400:
    v454 = stack[-1];
    v234 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v454, v234);
    }

v312:
    v234 = stack[0];
    v234 = Lfloat(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v442;
    env = stack[-2];
    {
        Lisp_Object v445 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v445, v234);
    }

v408:
    v454 = stack[-1];
    v234 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v454, v234);
    }
/* error exit handlers */
v442:
    popv(3);
    return nil;
}



/* Code for dipdivmon */

static Lisp_Object MS_CDECL CC_dipdivmon(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v388,
                         Lisp_Object v43, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v316, v398;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipdivmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipdivmon");
#endif
    if (stack >= stacklimit)
    {
        push3(v43,v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v388,v43);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v43;
    stack[-1] = v388;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v318;

v318:
    v316 = stack[-2];
    if (v316 == nil) goto v308;
    v316 = stack[-2];
    v398 = qcar(v316);
    v316 = stack[0];
    fn = elt(env, 1); /* evdif */
    v398 = (*qfn2(fn))(qenv(fn), v398, v316);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-4];
    v316 = stack[-3];
    v316 = cons(v398, v316);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-4];
    stack[-3] = v316;
    v316 = stack[-2];
    v316 = qcdr(v316);
    v398 = qcar(v316);
    v316 = stack[-1];
    fn = elt(env, 2); /* bcquot */
    v398 = (*qfn2(fn))(qenv(fn), v398, v316);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-4];
    v316 = stack[-3];
    v316 = cons(v398, v316);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-4];
    stack[-3] = v316;
    v316 = stack[-2];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[-2] = v316;
    goto v318;

v308:
    v316 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v316);
    }
/* error exit handlers */
v399:
    popv(5);
    return nil;
}



/* Code for f2dip2 */

static Lisp_Object MS_CDECL CC_f2dip2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v388,
                         Lisp_Object v43, Lisp_Object v196,
                         Lisp_Object v332, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v459, v424, v425;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "f2dip2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2dip2");
#endif
    if (stack >= stacklimit)
    {
        push5(v332,v196,v43,v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v388,v43,v196,v332);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v332;
    stack[-1] = v196;
    stack[-2] = v43;
    stack[-3] = v388;
    stack[-4] = v0;
/* end of prologue */
    v459 = stack[-4];
    v303 = qvalue(elt(env, 1)); /* dipvars!* */
    v303 = Lmemq(nil, v459, v303);
    if (v303 == nil) goto v432;
    v425 = stack[-1];
    v424 = stack[-4];
    v459 = stack[-3];
    v303 = qvalue(elt(env, 1)); /* dipvars!* */
    fn = elt(env, 3); /* evinsert */
    v303 = (*qfnn(fn))(qenv(fn), 4, v425, v424, v459, v303);
    nil = C_nil;
    if (exception_pending()) goto v434;
    env = stack[-5];
    goto v318;

v318:
    v459 = v303;
    v303 = v459;
    if (v303 == nil) goto v301;
    v303 = v459;
    stack[-1] = v303;
    goto v415;

v415:
    v424 = stack[-2];
    v459 = stack[-1];
    v303 = stack[0];
    {
        popv(6);
        fn = elt(env, 4); /* f2dip1 */
        return (*qfnn(fn))(qenv(fn), 3, v424, v459, v303);
    }

v301:
    v424 = stack[-4];
    v459 = stack[-3];
    v303 = (Lisp_Object)17; /* 1 */
    v424 = acons(v424, v459, v303);
    nil = C_nil;
    if (exception_pending()) goto v434;
    env = stack[-5];
    v459 = qvalue(elt(env, 2)); /* nil */
    v303 = (Lisp_Object)17; /* 1 */
    v303 = acons(v424, v459, v303);
    nil = C_nil;
    if (exception_pending()) goto v434;
    env = stack[-5];
    fn = elt(env, 5); /* multsq */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v434;
    env = stack[-5];
    stack[0] = v303;
    goto v415;

v432:
    v303 = qvalue(elt(env, 2)); /* nil */
    goto v318;
/* error exit handlers */
v434:
    popv(6);
    return nil;
}



/* Code for mkunarywedge */

static Lisp_Object CC_mkunarywedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v406, v264, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkunarywedge");
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
    goto v320;

v320:
    v406 = stack[0];
    if (v406 == nil) goto v306;
    v406 = stack[0];
    v406 = qcar(v406);
    v406 = qcar(v406);
    v262 = ncons(v406);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    v406 = stack[0];
    v406 = qcar(v406);
    v264 = qcdr(v406);
    v406 = stack[-1];
    v406 = acons(v262, v264, v406);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    stack[-1] = v406;
    v406 = stack[0];
    v406 = qcdr(v406);
    stack[0] = v406;
    goto v320;

v306:
    v406 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v406);
    }
/* error exit handlers */
v323:
    popv(3);
    return nil;
}



/* Code for drop_rl_with */

static Lisp_Object CC_drop_rl_with(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v397, v313, v314;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drop_rl_with");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v397 = v388;
    v313 = v0;
/* end of prologue */
    stack[-1] = v397;
    stack[0] = elt(env, 1); /* rl_with */
    v314 = v313;
    v313 = v397;
    v397 = elt(env, 1); /* rl_with */
    v397 = get(v313, v397);
    env = stack[-2];
    v397 = Ldelete(nil, v314, v397);
    nil = C_nil;
    if (exception_pending()) goto v406;
    {
        Lisp_Object v264 = stack[-1];
        Lisp_Object v262 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v264, v262, v397);
    }
/* error exit handlers */
v406:
    popv(3);
    return nil;
}



/* Code for dfp!-rule!-found */

static Lisp_Object CC_dfpKruleKfound(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v324, v325, v275, v397;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfp-rule-found");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v275 = v388;
    v397 = v0;
/* end of prologue */
    v325 = v397;
    v324 = elt(env, 1); /* dfp */
    v324 = Leqcar(nil, v325, v324);
    v324 = (v324 == nil ? lisp_true : nil);
    if (!(v324 == nil)) return onevalue(v324);
    v324 = v397;
    v324 = qcdr(v324);
    v324 = qcar(v324);
    v325 = v275;
        return Lneq(nil, v324, v325);
}



/* Code for hdiff */

static Lisp_Object CC_hdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v401, v400;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v388;
    stack[-1] = v0;
/* end of prologue */
    v401 = stack[-1];
    if (v401 == nil) goto v320;
    v400 = stack[-1];
    v401 = (Lisp_Object)49; /* 3 */
    v400 = *(Lisp_Object *)((char *)v400 + (CELL-TAG_VECTOR) + ((int32_t)v401/(16/CELL)));
    v401 = stack[0];
    stack[-2] = CC_hdiff(env, v400, v401);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-3];
    v400 = stack[-1];
    v401 = stack[0];
    fn = elt(env, 2); /* hdiffterm */
    v401 = (*qfn2(fn))(qenv(fn), v400, v401);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-3];
    {
        Lisp_Object v266 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v266, v401);
    }

v320:
    v401 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v401); }
/* error exit handlers */
v265:
    popv(4);
    return nil;
}



/* Code for mo_deletecomp */

static Lisp_Object CC_mo_deletecomp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v265, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_deletecomp");
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
    v265 = v0;
/* end of prologue */
    v266 = v265;
    v266 = qcar(v266);
    if (v266 == nil) { popv(2); return onevalue(v265); }
    v266 = v265;
    v266 = qcar(v266);
    v266 = qcdr(v266);
    if (v266 == nil) goto v373;
    v266 = (Lisp_Object)1; /* 0 */
    v265 = qcar(v265);
    v265 = qcdr(v265);
    v265 = cons(v266, v265);
    nil = C_nil;
    if (exception_pending()) goto v310;
    env = stack[-1];
    stack[0] = v265;
    fn = elt(env, 2); /* mo!=deglist */
    v265 = (*qfn1(fn))(qenv(fn), v265);
    nil = C_nil;
    if (exception_pending()) goto v310;
    {
        Lisp_Object v235 = stack[0];
        popv(2);
        return cons(v235, v265);
    }

v373:
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v265 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* mo!=deglist */
    v265 = (*qfn1(fn))(qenv(fn), v265);
    nil = C_nil;
    if (exception_pending()) goto v310;
    {
        Lisp_Object v396 = stack[0];
        popv(2);
        return cons(v396, v265);
    }
/* error exit handlers */
v310:
    popv(2);
    return nil;
}



/* Code for rl_qe */

static Lisp_Object CC_rl_qe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v408, v402;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_qe");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v408 = v388;
    v402 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_qe!* */
    v408 = list2(v402, v408);
    nil = C_nil;
    if (exception_pending()) goto v449;
    env = stack[-1];
    {
        Lisp_Object v276 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v276, v408);
    }
/* error exit handlers */
v449:
    popv(2);
    return nil;
}



/* Code for addcoeffs */

static Lisp_Object MS_CDECL CC_addcoeffs(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v388,
                         Lisp_Object v43, Lisp_Object v196, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v359, v248, v249, v460;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "addcoeffs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addcoeffs");
#endif
    if (stack >= stacklimit)
    {
        push4(v196,v43,v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v388,v43,v196);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v196;
    stack[-2] = v43;
    stack[-3] = v388;
    stack[-4] = v0;
/* end of prologue */
    v248 = qvalue(elt(env, 1)); /* nil */
    v359 = (Lisp_Object)17; /* 1 */
    v359 = cons(v248, v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[0] = v359;
    v359 = stack[-4];
    fn = elt(env, 2); /* smallest!-increment */
    stack[-5] = (*qfn1(fn))(qenv(fn), v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    v359 = stack[-3];
    fn = elt(env, 2); /* smallest!-increment */
    v359 = (*qfn1(fn))(qenv(fn), v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    fn = elt(env, 3); /* common!-increment */
    v359 = (*qfn2(fn))(qenv(fn), stack[-5], v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    v460 = stack[-2];
    v249 = stack[-1];
    v248 = stack[-3];
    v248 = qcar(v248);
    v248 = qcar(v248);
    fn = elt(env, 4); /* makecoeffpairs */
    v359 = (*qfnn(fn))(qenv(fn), 4, v460, v249, v248, v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[-5] = v359;
    goto v314;

v314:
    v359 = stack[-5];
    if (v359 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v359 = stack[-5];
    v359 = qcar(v359);
    stack[-2] = v359;
    stack[-1] = stack[0];
    v359 = stack[-2];
    v248 = qcar(v359);
    v359 = stack[-4];
    v359 = Lassoc(nil, v248, v359);
    v248 = v359;
    v359 = v248;
    if (v359 == nil) goto v424;
    v359 = v248;
    v359 = qcdr(v359);
    stack[0] = v359;
    goto v305;

v305:
    v359 = stack[-2];
    v248 = qcdr(v359);
    v359 = stack[-3];
    v359 = Lassoc(nil, v248, v359);
    v248 = v359;
    v359 = v248;
    if (v359 == nil) goto v430;
    v359 = v248;
    v359 = qcdr(v359);
    goto v261;

v261:
    fn = elt(env, 5); /* multsq */
    v359 = (*qfn2(fn))(qenv(fn), stack[0], v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    fn = elt(env, 6); /* addsq */
    v359 = (*qfn2(fn))(qenv(fn), stack[-1], v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[0] = v359;
    v359 = stack[-5];
    v359 = qcdr(v359);
    stack[-5] = v359;
    goto v314;

v430:
    v248 = qvalue(elt(env, 1)); /* nil */
    v359 = (Lisp_Object)17; /* 1 */
    v359 = cons(v248, v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    goto v261;

v424:
    v248 = qvalue(elt(env, 1)); /* nil */
    v359 = (Lisp_Object)17; /* 1 */
    v359 = cons(v248, v359);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[0] = v359;
    goto v305;
/* error exit handlers */
v246:
    popv(7);
    return nil;
}



/* Code for pasf_pnf */

static Lisp_Object CC_pasf_pnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v320;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_pnf");
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
    v320 = v0;
/* end of prologue */
    fn = elt(env, 1); /* rl_nnf */
    v320 = (*qfn1(fn))(qenv(fn), v320);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* pasf_pnf1 */
        return (*qfn1(fn))(qenv(fn), v320);
    }
/* error exit handlers */
v317:
    popv(1);
    return nil;
}



/* Code for pdiffvars */

static Lisp_Object CC_pdiffvars(Lisp_Object env,
                         Lisp_Object v388, Lisp_Object v43)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v401, v400;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdiffvars");
#endif
    if (stack >= stacklimit)
    {
        push2(v43,v388);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v388,v43);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v43;
    v401 = v388;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* ind */
    qvalue(elt(env, 1)) = nil; /* ind */
    qvalue(elt(env, 1)) = v401; /* ind */
    v401 = qvalue(elt(env, 1)); /* ind */
    if (v401 == nil) goto v268;
    v400 = stack[-1];
    v401 = qvalue(elt(env, 1)); /* ind */
    v401 = qcar(v401);
    fn = elt(env, 2); /* pnth */
    v401 = (*qfn2(fn))(qenv(fn), v400, v401);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-3];
    stack[0] = qcar(v401);
    v401 = qvalue(elt(env, 1)); /* ind */
    v400 = qcdr(v401);
    v401 = stack[-1];
    v401 = CC_pdiffvars(env, v400, v401);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-3];
    v401 = cons(stack[0], v401);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-3];
    goto v317;

v317:
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    { popv(4); return onevalue(v401); }

v268:
    v401 = nil;
    goto v317;
/* error exit handlers */
v265:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    popv(4);
    return nil;
}



/* Code for fac!-part */

static Lisp_Object CC_facKpart(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v388)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v367, v368;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fac-part");
#endif
    if (stack >= stacklimit)
    {
        push2(v388,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v388);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v388;
    stack[-1] = v0;
/* end of prologue */
    v368 = stack[-1];
    v367 = stack[0];
    if (equal(v368, v367)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v367 = stack[0];
    v367 = sub1(v367);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-3];
    if (equal(stack[-2], v367)) goto v325;
    v368 = stack[-1];
    v367 = stack[0];
    v368 = plus2(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-3];
    v367 = (Lisp_Object)33; /* 2 */
    v367 = quot2(v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-3];
    stack[-2] = v367;
    v368 = stack[-1];
    v367 = stack[-2];
    stack[-1] = CC_facKpart(env, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-3];
    v367 = stack[-2];
    v368 = add1(v367);
    nil = C_nil;
    if (exception_pending()) goto v377;
    env = stack[-3];
    v367 = stack[0];
    v367 = CC_facKpart(env, v368, v367);
    nil = C_nil;
    if (exception_pending()) goto v377;
    {
        Lisp_Object v326 = stack[-1];
        popv(4);
        return times2(v326, v367);
    }

v325:
    v368 = stack[-1];
    v367 = stack[0];
    popv(4);
    return times2(v368, v367);
/* error exit handlers */
v377:
    popv(4);
    return nil;
}



setup_type const u43_setup[] =
{
    {"liendimcom",              CC_liendimcom,  too_many_1,    wrong_no_1},
    {"groeb=crita",             CC_groebMcrita, too_many_1,    wrong_no_1},
    {"allbkern",                CC_allbkern,    too_many_1,    wrong_no_1},
    {"texexplode",              CC_texexplode,  too_many_1,    wrong_no_1},
    {"fctrf",                   CC_fctrf,       too_many_1,    wrong_no_1},
    {"cd_ordatp",               too_few_2,      CC_cd_ordatp,  wrong_no_2},
    {"lowupperlimitml",         CC_lowupperlimitml,too_many_1, wrong_no_1},
    {"*a2kwoweight",            CC_Ha2kwoweight,too_many_1,    wrong_no_1},
    {"vdpsimpcont",             CC_vdpsimpcont, too_many_1,    wrong_no_1},
    {"minprec",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minprec},
    {"fctins",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_fctins},
    {"adjp",                    CC_adjp,        too_many_1,    wrong_no_1},
    {"new_prove",               too_few_2,      CC_new_prove,  wrong_no_2},
    {"zeros",                   CC_zeros,       too_many_1,    wrong_no_1},
    {"combin",                  too_few_2,      CC_combin,     wrong_no_2},
    {"cdr_signsort",            too_few_2,      CC_cdr_signsort,wrong_no_2},
    {"random-teeny-prime",      CC_randomKteenyKprime,too_many_1,wrong_no_1},
    {"qqe_simplqneq",           too_few_2,      CC_qqe_simplqneq,wrong_no_2},
    {"cl_applysac",             too_few_2,      CC_cl_applysac,wrong_no_2},
    {"rat_sgn",                 CC_rat_sgn,     too_many_1,    wrong_no_1},
    {"conditionml",             CC_conditionml, too_many_1,    wrong_no_1},
    {":mod:units",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_TmodTunits},
    {"vdpfmon",                 too_few_2,      CC_vdpfmon,    wrong_no_2},
    {"evweightedcomp1",         too_few_2,      CC_evweightedcomp1,wrong_no_2},
    {"logrtn",                  too_few_2,      CC_logrtn,     wrong_no_2},
    {"physopplus",              CC_physopplus,  too_many_1,    wrong_no_1},
    {"red_prepare",             CC_red_prepare, too_many_1,    wrong_no_1},
    {"sep_tens_from_other",     CC_sep_tens_from_other,too_many_1,wrong_no_1},
    {"mk_character",            CC_mk_character,too_many_1,    wrong_no_1},
    {"limitom",                 CC_limitom,     too_many_1,    wrong_no_1},
    {"make-ps",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKps},
    {"get_num_part",            CC_get_num_part,too_many_1,    wrong_no_1},
    {"dipdivmon",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipdivmon},
    {"f2dip2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_f2dip2},
    {"mkunarywedge",            CC_mkunarywedge,too_many_1,    wrong_no_1},
    {"drop_rl_with",            too_few_2,      CC_drop_rl_with,wrong_no_2},
    {"dfp-rule-found",          too_few_2,      CC_dfpKruleKfound,wrong_no_2},
    {"hdiff",                   too_few_2,      CC_hdiff,      wrong_no_2},
    {"mo_deletecomp",           CC_mo_deletecomp,too_many_1,   wrong_no_1},
    {"rl_qe",                   too_few_2,      CC_rl_qe,      wrong_no_2},
    {"addcoeffs",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_addcoeffs},
    {"pasf_pnf",                CC_pasf_pnf,    too_many_1,    wrong_no_1},
    {"pdiffvars",               too_few_2,      CC_pdiffvars,  wrong_no_2},
    {"fac-part",                too_few_2,      CC_facKpart,   wrong_no_2},
    {NULL, (one_args *)"u43", (two_args *)"15673 7222126 9272179", 0}
};

/* end of generated code */
