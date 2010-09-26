
/* $destdir\u34.c        Machine generated C code */

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


/* Code for calc_coeffmap_ */

static Lisp_Object MS_CDECL CC_calc_coeffmap_(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "calc_coeffmap_");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_coeffmap_");
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
    stack[-1] = v2;
    stack[-2] = v1;
    v13 = v0;
/* end of prologue */
    v14 = v13;
    v13 = stack[-1];
    fn = elt(env, 2); /* calc_map_ */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    v15 = v13;
    v14 = v15;
    v13 = (Lisp_Object)1; /* 0 */
    if (v14 == v13) goto v17;
    stack[-3] = elt(env, 1); /* times */
    stack[0] = v15;
    v14 = stack[-2];
    v13 = stack[-1];
    fn = elt(env, 3); /* calc_coeff */
    v13 = (*qfn2(fn))(qenv(fn), v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v16;
    {
        Lisp_Object v18 = stack[-3];
        Lisp_Object v19 = stack[0];
        popv(5);
        return list2star(v18, v19, v13);
    }

v17:
    v13 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v13); }
/* error exit handlers */
v16:
    popv(5);
    return nil;
}



/* Code for mkindxlist */

static Lisp_Object CC_mkindxlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkindxlist");
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
    v30 = v0;
/* end of prologue */
    stack[-4] = v30;
    v30 = stack[-4];
    if (v30 == nil) goto v12;
    v30 = stack[-4];
    v30 = qcar(v30);
    v31 = v30;
    v30 = v31;
    v30 = integerp(v30);
    if (v30 == nil) goto v9;
    v30 = v31;
    fn = elt(env, 3); /* !*num2id */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    goto v33;

v33:
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    stack[-2] = v30;
    stack[-3] = v30;
    goto v34;

v34:
    v30 = stack[-4];
    v30 = qcdr(v30);
    stack[-4] = v30;
    v30 = stack[-4];
    if (v30 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v30 = stack[-4];
    v30 = qcar(v30);
    v31 = v30;
    v30 = v31;
    v30 = integerp(v30);
    if (v30 == nil) goto v35;
    v30 = v31;
    fn = elt(env, 3); /* !*num2id */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    goto v36;

v36:
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v30 = Lrplacd(nil, stack[-1], v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v30 = stack[-2];
    v30 = qcdr(v30);
    stack[-2] = v30;
    goto v34;

v35:
    v30 = v31;
    v30 = Lconsp(nil, v30);
    env = stack[-5];
    if (v30 == nil) goto v37;
    v30 = v31;
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v30 = integerp(v30);
    if (v30 == nil) goto v37;
    stack[0] = elt(env, 2); /* minus */
    v30 = v31;
    v30 = qcdr(v30);
    v30 = qcar(v30);
    fn = elt(env, 3); /* !*num2id */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v30 = list2(stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    goto v36;

v37:
    v30 = v31;
    goto v36;

v9:
    v30 = v31;
    v30 = Lconsp(nil, v30);
    env = stack[-5];
    if (v30 == nil) goto v38;
    v30 = v31;
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v30 = integerp(v30);
    if (v30 == nil) goto v38;
    stack[0] = elt(env, 2); /* minus */
    v30 = v31;
    v30 = qcdr(v30);
    v30 = qcar(v30);
    fn = elt(env, 3); /* !*num2id */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    v30 = list2(stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-5];
    goto v33;

v38:
    v30 = v31;
    goto v33;

v12:
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v30); }
/* error exit handlers */
v32:
    popv(6);
    return nil;
}



/* Code for cl_rename!-vars */

static Lisp_Object CC_cl_renameKvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_rename-vars");
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
    v8 = v0;
/* end of prologue */
    stack[0] = v8;
    fn = elt(env, 1); /* cl_replace!-varl */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    fn = elt(env, 2); /* cl_rename!-vars1 */
    v8 = (*qfn2(fn))(qenv(fn), stack[0], v8);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v8 = qcar(v8);
    { popv(2); return onevalue(v8); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for rule */

static Lisp_Object MS_CDECL CC_rule(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v27, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v83, v84, v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule");
#endif
    if (stack >= stacklimit)
    {
        push4(v27,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v27);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v27;
    stack[0] = v2;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    v83 = stack[0];
    v82 = stack[-6];
    v82 = Lsubla(nil, v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    stack[-2] = v82;
    v83 = stack[-2];
    v82 = stack[-6];
    if (equal(v83, v82)) goto v88;
    v82 = stack[-2];
    if (!consp(v82)) goto v5;
    v82 = qvalue(elt(env, 4)); /* t */
    stack[-7] = v82;
    v82 = stack[-2];
    stack[-6] = v82;
    goto v88;

v88:
    v83 = stack[0];
    v82 = stack[-5];
    v82 = Lsubla(nil, v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    stack[-2] = v82;
    v83 = stack[-2];
    v82 = stack[-5];
    if (equal(v83, v82)) goto v21;
    v82 = stack[-2];
    stack[-5] = v82;
    v83 = stack[-5];
    v82 = elt(env, 5); /* !*sq!* */
    if (!consp(v83)) goto v21;
    v83 = qcar(v83);
    if (!(v83 == v82)) goto v21;
    v82 = stack[-5];
    v82 = qcdr(v82);
    v82 = qcar(v82);
    fn = elt(env, 11); /* prepsq!* */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    stack[-5] = v82;
    goto v21;

v21:
    v82 = stack[0];
    stack[-3] = v82;
    v82 = stack[-3];
    if (v82 == nil) goto v89;
    v82 = stack[-3];
    v82 = qcar(v82);
    v82 = qcdr(v82);
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    stack[-1] = v82;
    stack[-2] = v82;
    goto v90;

v90:
    v82 = stack[-3];
    v82 = qcdr(v82);
    stack[-3] = v82;
    v82 = stack[-3];
    if (v82 == nil) goto v91;
    stack[0] = stack[-1];
    v82 = stack[-3];
    v82 = qcar(v82);
    v82 = qcdr(v82);
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    v82 = Lrplacd(nil, stack[0], v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    v82 = stack[-1];
    v82 = qcdr(v82);
    stack[-1] = v82;
    goto v90;

v91:
    v82 = stack[-2];
    goto v92;

v92:
    stack[0] = v82;
    v83 = stack[0];
    v82 = qvalue(elt(env, 6)); /* mcond!* */
    fn = elt(env, 12); /* smemql */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    stack[-2] = v82;
    v83 = stack[0];
    v82 = stack[-6];
    fn = elt(env, 12); /* smemql */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    stack[-1] = v82;
    v83 = stack[-2];
    v82 = stack[-1];
    fn = elt(env, 13); /* setdiff */
    v83 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    v82 = v83;
    if (!(v83 == nil)) goto v93;
    v83 = stack[0];
    v82 = stack[-5];
    fn = elt(env, 12); /* smemql */
    v83 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    v82 = stack[-2];
    fn = elt(env, 13); /* setdiff */
    stack[0] = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    v83 = stack[-1];
    v82 = stack[-2];
    fn = elt(env, 13); /* setdiff */
    v82 = (*qfn2(fn))(qenv(fn), v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    fn = elt(env, 13); /* setdiff */
    v83 = (*qfn2(fn))(qenv(fn), stack[0], v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    v82 = v83;
    if (!(v83 == nil)) goto v93;
    v83 = stack[-6];
    v82 = elt(env, 10); /* getel */
    if (!consp(v83)) goto v94;
    v83 = qcar(v83);
    if (!(v83 == v82)) goto v94;
    v82 = stack[-6];
    v82 = qcdr(v82);
    v82 = qcar(v82);
    fn = elt(env, 14); /* eval */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    stack[-6] = v82;
    goto v94;

v94:
    v86 = stack[-6];
    v85 = stack[-5];
    v84 = qvalue(elt(env, 3)); /* nil */
    v83 = stack[-4];
    v82 = stack[-7];
    {
        popv(9);
        fn = elt(env, 15); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v86, v85, v84, v83, v82);
    }

v93:
    v83 = elt(env, 7); /* "Unmatched free variable(s)" */
    v82 = cons(v83, v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    fn = elt(env, 16); /* lprie */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-8];
    v82 = elt(env, 8); /* hold */
    qvalue(elt(env, 9)) = v82; /* erfg!* */
    v82 = qvalue(elt(env, 3)); /* nil */
    { popv(9); return onevalue(v82); }

v89:
    v82 = qvalue(elt(env, 3)); /* nil */
    goto v92;

v5:
    v86 = elt(env, 1); /* "Substitution for" */
    v85 = stack[-6];
    v84 = elt(env, 2); /* "not allowed" */
    v83 = qvalue(elt(env, 3)); /* nil */
    v82 = qvalue(elt(env, 4)); /* t */
    {
        popv(9);
        fn = elt(env, 17); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v86, v85, v84, v83, v82);
    }
/* error exit handlers */
v87:
    popv(9);
    return nil;
}



/* Code for setrd */

static Lisp_Object MS_CDECL CC_setrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setrd");
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
    v96 = elt(env, 1); /* (t y p e != s e t !$) */
    qvalue(elt(env, 2)) = v96; /* atts */
    stack[0] = elt(env, 3); /* list */
    fn = elt(env, 4); /* stats_getargs */
    v96 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    v96 = cons(stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    v97 = v96;
    v96 = v97;
    stack[0] = qcar(v96);
    v96 = v97;
    v96 = qcdr(v96);
    fn = elt(env, 5); /* norepeat */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    {
        Lisp_Object v80 = stack[0];
        popv(2);
        return cons(v80, v96);
    }
/* error exit handlers */
v98:
    popv(2);
    return nil;
}



/* Code for countof */

static Lisp_Object CC_countof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for countof");
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
    v14 = stack[-1];
    v13 = stack[0];
    if (equal(v14, v13)) goto v47;
    v13 = stack[0];
    if (!consp(v13)) goto v17;
    v14 = stack[-1];
    v13 = stack[0];
    v13 = qcar(v13);
    stack[-2] = CC_countof(env, v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    v14 = stack[-1];
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = CC_countof(env, v14, v13);
    nil = C_nil;
    if (exception_pending()) goto v78;
    {
        Lisp_Object v79 = stack[-2];
        popv(4);
        return plus2(v79, v13);
    }

v17:
    v13 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v13); }

v47:
    v13 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v13); }
/* error exit handlers */
v78:
    popv(4);
    return nil;
}



/* Code for ps!:set!-term */

static Lisp_Object MS_CDECL CC_psTsetKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v130, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:set-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:set-term");
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
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v129 = stack[-4];
    fn = elt(env, 7); /* ps!:order */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    stack[-5] = v129;
    v130 = stack[-3];
    v129 = stack[-5];
    v129 = (Lisp_Object)lessp2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    v129 = v129 ? lisp_true : nil;
    env = stack[-6];
    if (v129 == nil) goto v38;
    v131 = stack[-3];
    v130 = elt(env, 1); /* "less than the order of " */
    v129 = stack[-4];
    v129 = list3(v131, v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v130 = v129;
    v129 = v130;
    qvalue(elt(env, 2)) = v129; /* errmsg!* */
    v129 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v129 == nil)) goto v132;
    v129 = v130;
    fn = elt(env, 8); /* lprie */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v132;

v132:
    v129 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v12;

v12:
    v129 = stack[-4];
    if (!consp(v129)) goto v133;
    v129 = stack[-4];
    v130 = qcar(v129);
    v129 = elt(env, 5); /* !:ps!: */
    if (v130 == v129) goto v134;
    v129 = stack[-4];
    v130 = qcar(v129);
    v129 = elt(env, 6); /* dname */
    v129 = get(v130, v129);
    env = stack[-6];
    if (!(v129 == nil)) goto v133;

v134:
    v130 = stack[-4];
    v129 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 9); /* ps!:getv */
    v129 = (*qfn2(fn))(qenv(fn), v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v135;

v135:
    v130 = v129;
    v129 = stack[-2];
    if (!consp(v129)) goto v136;
    v129 = stack[-2];
    v129 = qcar(v129);
    if (!(v129 == nil)) goto v136;
    v130 = stack[-3];
    v129 = stack[-5];
    if (!(equal(v130, v129))) goto v48;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)1; /* 0 */
    v129 = stack[-3];
    v129 = add1(v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    fn = elt(env, 10); /* ps!:putv */
    v129 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v48;

v48:
    v131 = stack[-4];
    v130 = (Lisp_Object)17; /* 1 */
    v129 = stack[-3];
    fn = elt(env, 10); /* ps!:putv */
    v129 = (*qfnn(fn))(qenv(fn), 3, v131, v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    v129 = nil;
    { popv(7); return onevalue(v129); }

v136:
    v129 = v130;
    if (v129 == nil) goto v137;
    stack[0] = v130;
    v130 = stack[-3];
    v129 = stack[-5];
    v130 = difference2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v129 = stack[-2];
    v129 = cons(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v129 = Lnconc(nil, stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v48;

v137:
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)81; /* 5 */
    v130 = stack[-3];
    v129 = stack[-5];
    v130 = difference2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v129 = stack[-2];
    v129 = cons(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    fn = elt(env, 10); /* ps!:putv */
    v129 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v48;

v133:
    v131 = (Lisp_Object)1; /* 0 */
    v130 = stack[-4];
    v129 = (Lisp_Object)17; /* 1 */
    v129 = list2star(v131, v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v135;

v38:
    stack[0] = stack[-3];
    v129 = stack[-4];
    fn = elt(env, 11); /* ps!:last!-term */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v129 = (Lisp_Object)lesseq2(stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    v129 = v129 ? lisp_true : nil;
    env = stack[-6];
    if (v129 == nil) goto v12;
    v131 = stack[-3];
    v130 = elt(env, 4); /* "less than power of last term of " */
    v129 = stack[-4];
    v129 = list3(v131, v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    v130 = v129;
    v129 = v130;
    qvalue(elt(env, 2)) = v129; /* errmsg!* */
    v129 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v129 == nil)) goto v138;
    v129 = v130;
    fn = elt(env, 8); /* lprie */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v138;

v138:
    v129 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-6];
    goto v12;
/* error exit handlers */
v44:
    popv(7);
    return nil;
}



/* Code for crprep1 */

static Lisp_Object CC_crprep1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprep1");
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
    v165 = v0;
/* end of prologue */
    v166 = v165;
    v166 = qcar(v166);
    v165 = qcdr(v165);
    stack[-3] = v166;
    stack[-2] = v165;
    v165 = stack[-2];
    if (is_number(v165)) goto v5;
    v165 = stack[-2];
    v165 = qcdr(v165);
    if (!consp(v165)) goto v168;
    v165 = stack[-2];
    v165 = qcdr(v165);
    v166 = qcar(v165);
    v165 = (Lisp_Object)1; /* 0 */
    v165 = (v166 == v165 ? lisp_true : nil);
    goto v169;

v169:
    if (!(v165 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v5:
    v165 = stack[-2];
    if (is_number(v165)) goto v170;
    v165 = stack[-2];
    v165 = qcdr(v165);
    if (!consp(v165)) goto v38;
    v166 = stack[-2];
    v165 = elt(env, 1); /* !:rd!: */
    if (!consp(v166)) goto v171;
    v166 = qcar(v166);
    if (!(v166 == v165)) goto v171;
    v165 = stack[-2];
    v165 = qcdr(v165);
    if (!consp(v165)) goto v171;
    v165 = stack[-2];
    v165 = qcdr(v165);
    v166 = qcar(v165);
    v165 = (Lisp_Object)1; /* 0 */
    v165 = (Lisp_Object)lessp2(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v165 = v165 ? lisp_true : nil;
    env = stack[-4];
    goto v15;

v15:
    if (v165 == nil) goto v170;
    stack[-1] = elt(env, 3); /* minus */
    v165 = stack[-2];
    v165 = qcdr(v165);
    if (!consp(v165)) goto v31;
    stack[0] = elt(env, 1); /* !:rd!: */
    v165 = stack[-2];
    v165 = qcdr(v165);
    v165 = qcar(v165);
    v166 = negate(v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    v165 = stack[-2];
    v165 = qcdr(v165);
    v165 = qcdr(v165);
    v165 = list2star(stack[0], v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    goto v37;

v37:
    fn = elt(env, 5); /* crprimp */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    v165 = list2(stack[-1], v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    goto v173;

v173:
    stack[-2] = v165;
    v165 = stack[-3];
    if (is_number(v165)) goto v137;
    v165 = stack[-3];
    v165 = qcdr(v165);
    if (!consp(v165)) goto v65;
    v165 = stack[-3];
    v165 = qcdr(v165);
    v166 = qcar(v165);
    v165 = (Lisp_Object)1; /* 0 */
    v165 = (v166 == v165 ? lisp_true : nil);
    goto v174;

v174:
    if (!(v165 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v137:
    v166 = stack[-3];
    v165 = (Lisp_Object)-15; /* -1 */
    if (v166 == v165) goto v111;
    v165 = stack[-3];
    if (is_number(v165)) goto v175;
    v165 = stack[-3];
    v165 = qcdr(v165);
    if (!consp(v165)) goto v115;
    v166 = stack[-3];
    v165 = elt(env, 1); /* !:rd!: */
    if (!consp(v166)) goto v110;
    v166 = qcar(v166);
    if (!(v166 == v165)) goto v110;
    v165 = stack[-3];
    v165 = qcdr(v165);
    if (!consp(v165)) goto v110;
    v165 = stack[-3];
    v165 = qcdr(v165);
    v166 = qcar(v165);
    v165 = (Lisp_Object)1; /* 0 */
    v165 = (Lisp_Object)lessp2(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v165 = v165 ? lisp_true : nil;
    env = stack[-4];
    goto v176;

v176:
    if (v165 == nil) goto v175;
    stack[-1] = elt(env, 3); /* minus */
    v165 = stack[-3];
    v165 = qcdr(v165);
    if (!consp(v165)) goto v177;
    stack[0] = elt(env, 1); /* !:rd!: */
    v165 = stack[-3];
    v165 = qcdr(v165);
    v165 = qcar(v165);
    v166 = negate(v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    v165 = stack[-3];
    v165 = qcdr(v165);
    v165 = qcdr(v165);
    v165 = list2star(stack[0], v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    goto v42;

v42:
    v165 = list2(stack[-1], v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    stack[-3] = v165;
    goto v175;

v175:
    v167 = elt(env, 4); /* plus */
    v166 = stack[-3];
    v165 = stack[-2];
    popv(5);
    return list3(v167, v166, v165);

v177:
    stack[0] = elt(env, 1); /* !:rd!: */
    v165 = stack[-3];
    v165 = qcdr(v165);
    v165 = negate(v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    v165 = cons(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    goto v42;

v110:
    v165 = qvalue(elt(env, 2)); /* nil */
    goto v176;

v115:
    v165 = stack[-3];
    v165 = qcdr(v165);
    v165 = Lminusp(nil, v165);
    env = stack[-4];
    goto v176;

v111:
    v166 = elt(env, 3); /* minus */
    v165 = (Lisp_Object)17; /* 1 */
    v165 = list2(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    stack[-3] = v165;
    goto v175;

v65:
    v165 = stack[-3];
    v165 = qcdr(v165);
    v165 = (Lisp_Object)zerop(v165);
    v165 = v165 ? lisp_true : nil;
    env = stack[-4];
    goto v174;

v31:
    stack[0] = elt(env, 1); /* !:rd!: */
    v165 = stack[-2];
    v165 = qcdr(v165);
    v165 = negate(v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    v165 = cons(stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    goto v37;

v170:
    v165 = stack[-2];
    fn = elt(env, 5); /* crprimp */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-4];
    goto v173;

v171:
    v165 = qvalue(elt(env, 2)); /* nil */
    goto v15;

v38:
    v165 = stack[-2];
    v165 = qcdr(v165);
    v165 = Lminusp(nil, v165);
    env = stack[-4];
    goto v15;

v168:
    v165 = stack[-2];
    v165 = qcdr(v165);
    v165 = (Lisp_Object)zerop(v165);
    v165 = v165 ? lisp_true : nil;
    env = stack[-4];
    goto v169;
/* error exit handlers */
v172:
    popv(5);
    return nil;
}



/* Code for groebinvokecritm */

static Lisp_Object CC_groebinvokecritm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebinvokecritm");
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
    v7 = stack[-1];
    stack[-3] = v7;
    goto v60;

v60:
    v7 = stack[-3];
    if (v7 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v7 = stack[-3];
    v7 = qcar(v7);
    stack[0] = v7;
    v7 = stack[-2];
    v13 = qcar(v7);
    v7 = stack[0];
    v7 = qcar(v7);
    fn = elt(env, 3); /* buchvevdivides!? */
    v7 = (*qfn2(fn))(qenv(fn), v13, v7);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    if (v7 == nil) goto v29;
    v7 = qvalue(elt(env, 2)); /* mcount!* */
    v7 = add1(v7);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    qvalue(elt(env, 2)) = v7; /* mcount!* */
    v13 = stack[0];
    v7 = stack[-1];
    fn = elt(env, 4); /* groedeletip */
    v7 = (*qfn2(fn))(qenv(fn), v13, v7);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    stack[-1] = v7;
    goto v29;

v29:
    v7 = stack[-3];
    v7 = qcdr(v7);
    stack[-3] = v7;
    goto v60;
/* error exit handlers */
v78:
    popv(5);
    return nil;
}



/* Code for evzero */

static Lisp_Object MS_CDECL CC_evzero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v3;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "evzero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evzero");
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
    v4 = (Lisp_Object)17; /* 1 */
    stack[0] = v4;
    goto v17;

v17:
    v4 = qvalue(elt(env, 1)); /* dipvars!* */
    v3 = Llength(nil, v4);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-2];
    v4 = stack[0];
    v4 = difference2(v3, v4);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-2];
    v4 = Lminusp(nil, v4);
    env = stack[-2];
    if (!(v4 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v3 = (Lisp_Object)1; /* 0 */
    v4 = stack[-1];
    v4 = cons(v3, v4);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-2];
    stack[-1] = v4;
    v4 = stack[0];
    v4 = add1(v4);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-2];
    stack[0] = v4;
    goto v17;
/* error exit handlers */
v156:
    popv(3);
    return nil;
}



/* Code for exdf0 */

static Lisp_Object CC_exdf0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exdf0");
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
    v5 = stack[0];
    v5 = qcar(v5);
    fn = elt(env, 1); /* exdff0 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v5 = stack[0];
    v5 = qcdr(v5);
    fn = elt(env, 2); /* negf */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    fn = elt(env, 1); /* exdff0 */
    v132 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v5 = stack[0];
    fn = elt(env, 3); /* multpfsq */
    v5 = (*qfn2(fn))(qenv(fn), v132, v5);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    fn = elt(env, 4); /* addpf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v5);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v132 = (Lisp_Object)17; /* 1 */
    v5 = stack[0];
    v5 = qcdr(v5);
    v5 = cons(v132, v5);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    {
        Lisp_Object v100 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v100, v5);
    }
/* error exit handlers */
v170:
    popv(3);
    return nil;
}



/* Code for evalmember */

static Lisp_Object CC_evalmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalmember");
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
    v8 = v1;
    v102 = v0;
/* end of prologue */
    stack[0] = v102;
    fn = elt(env, 1); /* getrlist */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v17;
    v8 = Lmember(nil, stack[0], v8);
    { popv(1); return onevalue(v8); }
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



/* Code for !:log2 */

static Lisp_Object CC_Tlog2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :log2");
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
    v6 = elt(env, 0); /* !:log2 */
    v100 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v100 = (*qfn2(fn))(qenv(fn), v6, v100);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    stack[-1] = v100;
    v6 = stack[-1];
    v100 = elt(env, 1); /* not_found */
    if (!(v6 == v100)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v6 = qvalue(elt(env, 2)); /* bftwo!* */
    v100 = stack[0];
    fn = elt(env, 4); /* log!: */
    v100 = (*qfn2(fn))(qenv(fn), v6, v100);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-2];
    stack[-1] = v100;
    v6 = elt(env, 0); /* !:log2 */
    v100 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v100 = (*qfn2(fn))(qenv(fn), v6, v100);
    nil = C_nil;
    if (exception_pending()) goto v14;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v14:
    popv(3);
    return nil;
}



/* Code for absf */

static Lisp_Object CC_absf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for absf");
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
    v102 = stack[0];
    fn = elt(env, 1); /* minusf */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    if (v102 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v102 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for getupper */

static Lisp_Object CC_getupper(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getupper");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v0;
/* end of prologue */
    v8 = qvalue(elt(env, 1)); /* metricu!* */
    v12 = Latsoc(nil, v12, v8);
    v12 = qcdr(v12);
    return onevalue(v12);
}



/* Code for groeb!=rf1 */

static Lisp_Object CC_groebMrf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=rf1");
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
    v29 = v0;
/* end of prologue */
    v28 = stack[0];
    fn = elt(env, 1); /* red_totalred */
    v28 = (*qfn2(fn))(qenv(fn), v28, v29);
    nil = C_nil;
    if (exception_pending()) goto v95;
    v29 = stack[0];
    popv(1);
    return list2(v28, v29);
/* error exit handlers */
v95:
    popv(1);
    return nil;
}



/* Code for cl_sitheo */

static Lisp_Object CC_cl_sitheo(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v121, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sitheo");
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
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = qvalue(elt(env, 1)); /* !*rlsiexpla */
    qvalue(elt(env, 1)) = nil; /* !*rlsiexpla */
    v180 = qvalue(elt(env, 2)); /* !*rlsithok */
    if (v180 == nil) goto v169;
    v180 = stack[-2];
    goto v34;

v34:
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    { popv(5); return onevalue(v180); }

v169:
    v180 = stack[-2];
    if (v180 == nil) goto v23;
    v180 = stack[-2];
    v180 = qcar(v180);
    stack[-3] = v180;
    v180 = stack[-2];
    v180 = qcdr(v180);
    stack[-2] = v180;
    v121 = stack[-3];
    v180 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 7); /* cl_simplat */
    v180 = (*qfn2(fn))(qenv(fn), v121, v180);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    v135 = v180;
    v121 = v135;
    v180 = elt(env, 4); /* false */
    if (v121 == v180) goto v5;
    v121 = v135;
    v180 = elt(env, 6); /* true */
    if (v121 == v180) goto v169;
    v121 = v135;
    v180 = stack[-1];
    v180 = cons(v121, v180);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-4];
    stack[-1] = v180;
    goto v169;

v5:
    v180 = elt(env, 5); /* inctheo */
    stack[-3] = v180;
    v180 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v180;
    goto v169;

v23:
    v121 = stack[-3];
    v180 = elt(env, 5); /* inctheo */
    if (v121 == v180) goto v126;
    v180 = stack[-1];
    goto v34;

v126:
    v180 = elt(env, 5); /* inctheo */
    goto v34;
/* error exit handlers */
v162:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    popv(5);
    return nil;
}



/* Code for rtypepart */

static Lisp_Object CC_rtypepart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtypepart");
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
    v102 = qcar(v102);
    fn = elt(env, 3); /* getrtype */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[0];
    if (v102 == nil) goto v11;
    v102 = elt(env, 1); /* yetunknowntype */
    { popv(1); return onevalue(v102); }

v11:
    v102 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v102); }
/* error exit handlers */
v41:
    popv(1);
    return nil;
}



/* Code for mchsarg */

static Lisp_Object MS_CDECL CC_mchsarg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchsarg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchsarg");
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
    stack[-6] = v1;
    stack[-1] = v0;
/* end of prologue */
    v155 = stack[-6];
    fn = elt(env, 3); /* mtp */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    if (v155 == nil) goto v121;
    v192 = stack[-5];
    v155 = elt(env, 1); /* times */
    if (!(v192 == v155)) goto v34;
    v155 = stack[-1];
    fn = elt(env, 4); /* noncomfree */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    if (!(v155 == nil)) goto v34;

v121:
    v155 = stack[-1];
    fn = elt(env, 5); /* noncomperm */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    stack[-7] = v155;
    goto v194;

v194:
    v155 = stack[-7];
    if (v155 == nil) goto v195;
    v155 = stack[-7];
    v155 = qcar(v155);
    stack[-1] = v155;
    stack[0] = stack[-6];
    v155 = qvalue(elt(env, 2)); /* nil */
    v192 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v155 = stack[-5];
    fn = elt(env, 6); /* mcharg2 */
    v155 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v192, v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    stack[-4] = v155;
    v155 = stack[-4];
    fn = elt(env, 7); /* lastpair */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    stack[-3] = v155;
    v155 = stack[-7];
    v155 = qcdr(v155);
    stack[-7] = v155;
    v155 = stack[-3];
    if (!consp(v155)) goto v194;
    else goto v72;

v72:
    v155 = stack[-7];
    if (v155 == nil) goto v122;
    stack[-2] = stack[-3];
    v155 = stack[-7];
    v155 = qcar(v155);
    stack[-1] = v155;
    stack[0] = stack[-6];
    v155 = qvalue(elt(env, 2)); /* nil */
    v192 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v155 = stack[-5];
    fn = elt(env, 6); /* mcharg2 */
    v155 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v192, v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v155 = Lrplacd(nil, stack[-2], v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v155 = stack[-3];
    fn = elt(env, 7); /* lastpair */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    stack[-3] = v155;
    v155 = stack[-7];
    v155 = qcdr(v155);
    stack[-7] = v155;
    goto v72;

v122:
    v155 = stack[-4];
    goto v60;

v60:
        popv(9);
        return Lnreverse(nil, v155);

v195:
    v155 = qvalue(elt(env, 2)); /* nil */
    goto v60;

v34:
    v155 = stack[-6];
    fn = elt(env, 5); /* noncomperm */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    stack[-4] = v155;
    v155 = stack[-4];
    if (v155 == nil) goto v164;
    v155 = stack[-4];
    v155 = qcar(v155);
    v192 = v155;
    v155 = stack[-1];
    fn = elt(env, 8); /* pair */
    v155 = (*qfn2(fn))(qenv(fn), v192, v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    stack[-2] = v155;
    stack[-3] = v155;
    goto v80;

v80:
    v155 = stack[-4];
    v155 = qcdr(v155);
    stack[-4] = v155;
    v155 = stack[-4];
    if (v155 == nil) goto v19;
    stack[0] = stack[-2];
    v155 = stack[-4];
    v155 = qcar(v155);
    v192 = v155;
    v155 = stack[-1];
    fn = elt(env, 8); /* pair */
    v155 = (*qfn2(fn))(qenv(fn), v192, v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v155 = Lrplacd(nil, stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-8];
    v155 = stack[-2];
    v155 = qcdr(v155);
    stack[-2] = v155;
    goto v80;

v19:
    v155 = stack[-3];
    goto v60;

v164:
    v155 = qvalue(elt(env, 2)); /* nil */
    goto v60;
/* error exit handlers */
v193:
    popv(9);
    return nil;
}



/* Code for aex_tad */

static Lisp_Object CC_aex_tad(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v33, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_tad");
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
    v28 = stack[0];
    fn = elt(env, 2); /* aex_ex */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    fn = elt(env, 3); /* ratpoly_tad */
    stack[-1] = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v28 = stack[0];
    fn = elt(env, 4); /* aex_ctx */
    v95 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-2];
    v33 = qvalue(elt(env, 1)); /* nil */
    v28 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v96 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v96, v95, v33, v28);
    }
/* error exit handlers */
v191:
    popv(3);
    return nil;
}



/* Code for setfuncsnaryrd */

static Lisp_Object MS_CDECL CC_setfuncsnaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setfuncsnaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setfuncsnaryrd");
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
    fn = elt(env, 4); /* mathml */
    v18 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-1];
    stack[0] = v18;
    v18 = stack[0];
    v18 = Lconsp(nil, v18);
    env = stack[-1];
    if (v18 == nil) goto v60;
    v18 = stack[0];
    v18 = qcdr(v18);
    v18 = qcar(v18);
    if (v18 == nil) goto v60;
    v18 = stack[0];
    v18 = qcdr(v18);
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = qcdr(v18);
    v18 = qcar(v18);
    v19 = Lintern(nil, v18);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-1];
    v18 = elt(env, 1); /* multiset */
    if (!(v19 == v18)) goto v60;
    v18 = elt(env, 1); /* multiset */
    qvalue(elt(env, 2)) = v18; /* mmlatts */
    goto v60;

v60:
    v18 = stack[0];
    if (v18 == nil) goto v156;
    v18 = CC_setfuncsnaryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v179;
    {
        Lisp_Object v160 = stack[0];
        popv(2);
        return cons(v160, v18);
    }

v156:
    v18 = nil;
    { popv(2); return onevalue(v18); }
/* error exit handlers */
v179:
    popv(2);
    return nil;
}



/* Code for ciml */

static Lisp_Object MS_CDECL CC_ciml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ciml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ciml");
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
    v173 = qvalue(elt(env, 2)); /* atts */
    v156 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 5); /* search_att */
    v156 = (*qfn2(fn))(qenv(fn), v173, v156);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    fn = elt(env, 6); /* lex */
    v156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v156 = qvalue(elt(env, 4)); /* char */
    stack[0] = v156;
    fn = elt(env, 6); /* lex */
    v156 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v156 = stack[0];
    v156 = Lcompress(nil, v156);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    stack[0] = v156;
    v156 = stack[0];
    if (!(is_number(v156))) goto v191;
    v173 = stack[0];
    v156 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 7); /* errorml */
    v156 = (*qfn2(fn))(qenv(fn), v173, v156);
    nil = C_nil;
    if (exception_pending()) goto v100;
    goto v191;

v191:
    v156 = stack[0];
        popv(2);
        return Lintern(nil, v156);
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for o!-nextarg */

static Lisp_Object CC_oKnextarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for o-nextarg");
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
    v184 = qvalue(elt(env, 1)); /* !*udebug */
    if (v184 == nil) goto v168;
    v184 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* uprint */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    goto v168;

v168:
    v206 = qvalue(elt(env, 3)); /* i */
    v184 = (Lisp_Object)17; /* 1 */
    if (!(v206 == v184)) goto v5;
    v206 = qvalue(elt(env, 3)); /* i */
    v184 = qvalue(elt(env, 4)); /* upb */
    v184 = (Lisp_Object)lesseq2(v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v184 = v184 ? lisp_true : nil;
    env = stack[-3];
    if (v184 == nil) goto v5;
    v184 = stack[-1];
    goto v102;

v102:
    stack[0] = v184;
    v184 = qvalue(elt(env, 3)); /* i */
    v184 = add1(v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    qvalue(elt(env, 3)) = v184; /* i */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v5:
    v206 = qvalue(elt(env, 3)); /* i */
    v184 = (Lisp_Object)1; /* 0 */
    if (!(v206 == v184)) goto v4;
    v206 = qvalue(elt(env, 3)); /* i */
    v184 = qvalue(elt(env, 4)); /* upb */
    v184 = (Lisp_Object)lesseq2(v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v184 = v184 ? lisp_true : nil;
    env = stack[-3];
    if (v184 == nil) goto v4;
    v206 = elt(env, 5); /* (null!-fn) */
    v184 = stack[-1];
    v184 = cons(v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    goto v102;

v4:
    v184 = qvalue(elt(env, 6)); /* acontract */
    if (v184 == nil) goto v207;
    v206 = qvalue(elt(env, 3)); /* i */
    v184 = qvalue(elt(env, 4)); /* upb */
    v184 = (Lisp_Object)lesseq2(v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v184 = v184 ? lisp_true : nil;
    env = stack[-3];
    if (v184 == nil) goto v207;
    stack[-2] = qvalue(elt(env, 7)); /* op */
    v206 = stack[-1];
    v184 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 13); /* first0 */
    stack[0] = (*qfn2(fn))(qenv(fn), v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v206 = stack[-1];
    v184 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 14); /* last0 */
    v184 = (*qfn2(fn))(qenv(fn), v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v184 = acons(stack[-2], stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    fn = elt(env, 15); /* mval */
    v184 = (*qfn1(fn))(qenv(fn), v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    goto v102;

v207:
    v184 = qvalue(elt(env, 8)); /* mcontract */
    if (v184 == nil) goto v208;
    v206 = qvalue(elt(env, 3)); /* i */
    v184 = qvalue(elt(env, 4)); /* upb */
    v184 = (Lisp_Object)lesseq2(v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    v184 = v184 ? lisp_true : nil;
    env = stack[-3];
    if (v184 == nil) goto v208;
    stack[-2] = elt(env, 9); /* null!-fn */
    v206 = stack[-1];
    v184 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 13); /* first0 */
    stack[0] = (*qfn2(fn))(qenv(fn), v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v206 = stack[-1];
    v184 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 14); /* last0 */
    v184 = (*qfn2(fn))(qenv(fn), v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v184 = acons(stack[-2], stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    goto v102;

v208:
    v184 = qvalue(elt(env, 10)); /* expand */
    if (v184 == nil) goto v153;
    v184 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 10)) = v184; /* expand */
    v206 = qvalue(elt(env, 11)); /* identity */
    v184 = stack[-1];
    v184 = cons(v206, v184);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    goto v102;

v153:
    v184 = nil;
    goto v102;
/* error exit handlers */
v155:
    popv(4);
    return nil;
}



/* Code for ndepends */

static Lisp_Object CC_ndepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ndepends");
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
    v210 = stack[-1];
    if (v210 == nil) goto v47;
    v210 = stack[-1];
    if (is_number(v210)) goto v47;
    v210 = stack[0];
    if (is_number(v210)) goto v47;
    v211 = stack[-1];
    v210 = stack[0];
    if (equal(v211, v210)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v210 = stack[-1];
    if (!(!consp(v210))) goto v173;
    v211 = stack[-1];
    v210 = qvalue(elt(env, 2)); /* frlis!* */
    v210 = Lmemq(nil, v211, v210);
    if (v210 == nil) goto v173;
    v210 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v210); }

v173:
    v211 = stack[-1];
    v210 = qvalue(elt(env, 4)); /* depl!* */
    v210 = Lassoc(nil, v211, v210);
    v211 = v210;
    v210 = v211;
    if (v210 == nil) goto v79;
    v210 = v211;
    v211 = qcdr(v210);
    v210 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v210 = (*qfn2(fn))(qenv(fn), v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    goto v78;

v78:
    if (v210 == nil) goto v156;
    v210 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v210); }

v156:
    v210 = stack[-1];
    if (!consp(v210)) goto v163;
    v210 = stack[-1];
    v210 = qcar(v210);
    if (!(symbolp(v210))) goto v163;
    v210 = stack[-1];
    v211 = qcar(v210);
    v210 = elt(env, 5); /* dname */
    v210 = get(v211, v210);
    env = stack[-2];
    if (v210 == nil) goto v163;
    v210 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v210); }

v163:
    v210 = stack[-1];
    fn = elt(env, 7); /* atomf */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    if (!(v210 == nil)) goto v194;
    v210 = stack[-1];
    v211 = qcdr(v210);
    v210 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v210 = (*qfn2(fn))(qenv(fn), v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    if (!(v210 == nil)) goto v162;
    v210 = stack[-1];
    v211 = qcar(v210);
    v210 = stack[0];
    v210 = CC_ndepends(env, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    if (!(v210 == nil)) goto v162;

v194:
    v210 = stack[0];
    fn = elt(env, 7); /* atomf */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    if (!(v210 == nil)) goto v202;
    v210 = stack[0];
    v210 = qcar(v210);
    if (!(symbolp(v210))) goto v181;
    v210 = stack[0];
    v211 = qcar(v210);
    v210 = elt(env, 5); /* dname */
    v210 = get(v211, v210);
    env = stack[-2];
    if (!(v210 == nil)) goto v202;

v181:
    v211 = stack[-1];
    v210 = stack[0];
    v210 = qcdr(v210);
    {
        popv(3);
        fn = elt(env, 8); /* ndependsl */
        return (*qfn2(fn))(qenv(fn), v211, v210);
    }

v202:
    v210 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v210); }

v162:
    v210 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v210); }

v79:
    v210 = qvalue(elt(env, 1)); /* nil */
    goto v78;

v47:
    v210 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v210); }
/* error exit handlers */
v117:
    popv(3);
    return nil;
}



/* Code for basisformp */

static Lisp_Object CC_basisformp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basisformp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    v29 = v28;
    if (!consp(v29)) goto v26;
    v29 = v28;
    v28 = qvalue(elt(env, 2)); /* basisforml!* */
    v29 = Lmemq(nil, v29, v28);
    return onevalue(v29);

v26:
    v29 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v29);
}



/* Code for decimal2internal */

static Lisp_Object CC_decimal2internal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v207, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for decimal2internal");
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
    v207 = stack[0];
    v212 = (Lisp_Object)1; /* 0 */
    v212 = (Lisp_Object)geq2(v207, v212);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v212 = v212 ? lisp_true : nil;
    env = stack[-3];
    if (v212 == nil) goto v77;
    stack[-2] = elt(env, 1); /* !:rd!: */
    v207 = (Lisp_Object)161; /* 10 */
    v212 = stack[0];
    v212 = Lexpt(nil, v207, v212);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    v207 = times2(stack[-1], v212);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v212 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v163 = stack[-2];
        popv(4);
        return list2star(v163, v207, v212);
    }

v77:
    v75 = elt(env, 1); /* !:rd!: */
    v207 = stack[-1];
    v212 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v75, v207, v212);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    v212 = stack[0];
    v212 = negate(v212);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    {
        Lisp_Object v23 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* divide!-by!-power!-of!-ten */
        return (*qfn2(fn))(qenv(fn), v23, v212);
    }
/* error exit handlers */
v126:
    popv(4);
    return nil;
}



/* Code for physoppri */

static Lisp_Object CC_physoppri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v238, v239, v240, v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physoppri");
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
    stack[-6] = nil;
    v238 = stack[-8];
    if (symbolp(v238)) goto v12;
    v238 = stack[-8];
    v238 = qcar(v238);
    goto v11;

v11:
    stack[-9] = v238;
    v238 = stack[-8];
    if (symbolp(v238)) goto v95;
    v238 = stack[-8];
    v238 = qcdr(v238);
    goto v33;

v33:
    stack[-7] = v238;
    stack[-5] = elt(env, 0); /* physoppri */
    stack[-4] = elt(env, 2); /* "x= " */
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); /* " y= " */
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); /* "nat= " */
    v240 = elt(env, 5); /* !*nat */
    v239 = elt(env, 6); /* " contract= " */
    v238 = elt(env, 7); /* !*contract */
    v238 = list3(v240, v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = list3star(stack[-2], stack[-1], stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = list3star(stack[-5], stack[-4], stack[-3], v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = qvalue(elt(env, 5)); /* !*nat */
    if (v238 == nil) goto v182;
    v238 = qvalue(elt(env, 7)); /* !*contract */
    if (!(v238 == nil)) goto v182;
    v238 = stack[-9];
    v238 = Lexplode(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lreverse(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[-9] = v238;
    v238 = stack[-9];
    v239 = Llength(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = (Lisp_Object)33; /* 2 */
    v238 = (Lisp_Object)greaterp2(v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v238 = v238 ? lisp_true : nil;
    env = stack[-10];
    if (v238 == nil) goto v243;
    v238 = stack[-9];
    v238 = qcdr(v238);
    v239 = qcar(v238);
    v238 = elt(env, 14); /* !- */
    if (v239 == v238) goto v63;
    v238 = stack[-9];
    v239 = qcar(v238);
    v238 = elt(env, 16); /* !+ */
    if (v239 == v238) goto v137;
    v238 = stack[-9];
    v238 = Lreverse(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lcompress(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[-9] = v238;
    goto v244;

v244:
    stack[0] = elt(env, 8); /* !" */
    v238 = stack[-9];
    v238 = Lexplode(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[0] = cons(stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = elt(env, 8); /* !" */
    v238 = ncons(v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lappend(nil, stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lcompress(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[-9] = v238;
    v238 = stack[-7];
    if (v238 == nil) goto v245;
    v239 = stack[-9];
    v238 = stack[-7];
    v238 = cons(v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    goto v246;

v246:
    stack[-3] = v238;
    stack[-2] = elt(env, 0); /* physoppri */
    stack[-1] = elt(env, 2); /* "x= " */
    stack[0] = stack[-9];
    v241 = elt(env, 17); /* " z= " */
    v240 = stack[-6];
    v239 = elt(env, 18); /* " x1= " */
    v238 = stack[-3];
    v238 = list4(v241, v240, v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = list3star(stack[-2], stack[-1], stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = stack[-6];
    if (v238 == nil) goto v247;
    v240 = elt(env, 19); /* expt */
    v239 = stack[-3];
    v238 = stack[-6];
    v240 = list3(v240, v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v239 = elt(env, 19); /* expt */
    v238 = elt(env, 20); /* infix */
    v238 = get(v239, v238);
    env = stack[-10];
    fn = elt(env, 22); /* exptpri */
    v238 = (*qfn2(fn))(qenv(fn), v240, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v247:
    v238 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = stack[-7];
    if (v238 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v238 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v238; /* obrkp!* */
    v240 = elt(env, 11); /* !*comma!* */
    v239 = (Lisp_Object)1; /* 0 */
    v238 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v238 = (*qfnn(fn))(qenv(fn), 3, v240, v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v238; /* obrkp!* */
    v238 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v245:
    v238 = stack[-9];
    goto v246;

v137:
    v238 = elt(env, 16); /* !+ */
    stack[-6] = v238;
    v239 = stack[-9];
    v238 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 25); /* pnth */
    v238 = (*qfn2(fn))(qenv(fn), v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lreverse(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lcompress(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[-9] = v238;
    goto v244;

v63:
    v239 = elt(env, 14); /* !- */
    v238 = elt(env, 15); /* !1 */
    v238 = list2(v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lcompress(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[-6] = v238;
    v239 = stack[-9];
    v238 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 25); /* pnth */
    v238 = (*qfn2(fn))(qenv(fn), v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lreverse(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lcompress(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[-9] = v238;
    goto v244;

v243:
    v238 = stack[-9];
    v238 = Lreverse(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lcompress(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[-9] = v238;
    goto v244;

v182:
    stack[0] = elt(env, 8); /* !" */
    v238 = stack[-9];
    v238 = Lexplode(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[0] = cons(stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = elt(env, 8); /* !" */
    v238 = ncons(v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lappend(nil, stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = Lcompress(nil, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    stack[-9] = v238;
    v238 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = stack[-7];
    if (v238 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v238 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v238; /* obrkp!* */
    v240 = elt(env, 11); /* !*comma!* */
    v239 = (Lisp_Object)1; /* 0 */
    v238 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v238 = (*qfnn(fn))(qenv(fn), 3, v240, v239, v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-10];
    v238 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v238; /* obrkp!* */
    v238 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v242;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v95:
    v238 = qvalue(elt(env, 1)); /* nil */
    goto v33;

v12:
    v238 = stack[-8];
    goto v11;
/* error exit handlers */
v242:
    popv(11);
    return nil;
}



/* Code for prsum */

static Lisp_Object CC_prsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v77, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prsum");
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
    goto v60;

v60:
    v38 = stack[-1];
    if (v38 == nil) goto v40;
    v38 = stack[0];
    v38 = qcar(v38);
    if (v38 == nil) goto v41;
    v38 = stack[-1];
    v77 = qcar(v38);
    v38 = (Lisp_Object)17; /* 1 */
    v78 = cons(v77, v38);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    v38 = stack[0];
    v77 = qcar(v38);
    v38 = stack[-2];
    v38 = acons(v78, v77, v38);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    stack[-2] = v38;
    v38 = stack[-1];
    v38 = qcdr(v38);
    stack[-1] = v38;
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v60;

v41:
    v38 = stack[-1];
    v38 = qcdr(v38);
    stack[-1] = v38;
    v38 = stack[0];
    v38 = qcdr(v38);
    stack[0] = v38;
    goto v60;

v40:
    v38 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v38);
    }
/* error exit handlers */
v19:
    popv(4);
    return nil;
}



/* Code for fs!:onep!: */

static Lisp_Object CC_fsTonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:onep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v0;
/* end of prologue */
    v47 = qcdr(v47);
    {
        fn = elt(env, 1); /* fs!:onep */
        return (*qfn1(fn))(qenv(fn), v47);
    }
}



/* Code for simp!-prop */

static Lisp_Object CC_simpKprop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v256, v257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop");
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
    stack[-2] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* propvars!* */
    qvalue(elt(env, 1)) = nil; /* propvars!* */
    v255 = stack[-2];
    v255 = qcdr(v255);
    stack[-4] = v255;
    v255 = stack[-4];
    if (v255 == nil) goto v168;
    v255 = stack[-4];
    v255 = qcar(v255);
    fn = elt(env, 14); /* reval */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v255 = ncons(v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    stack[-1] = v255;
    stack[-3] = v255;
    goto v8;

v8:
    v255 = stack[-4];
    v255 = qcdr(v255);
    stack[-4] = v255;
    v255 = stack[-4];
    if (v255 == nil) goto v127;
    stack[0] = stack[-1];
    v255 = stack[-4];
    v255 = qcar(v255);
    fn = elt(env, 14); /* reval */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v255 = ncons(v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v255 = Lrplacd(nil, stack[0], v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v255 = stack[-1];
    v255 = qcdr(v255);
    stack[-1] = v255;
    goto v8;

v127:
    v255 = stack[-3];
    goto v12;

v12:
    stack[-5] = v255;
    v256 = elt(env, 3); /* and */
    v255 = stack[-5];
    v255 = Lmember(nil, v256, v255);
    if (v255 == nil) goto v126;
    v255 = elt(env, 4); /* or */
    qvalue(elt(env, 5)) = v255; /* !'and */
    v255 = elt(env, 3); /* and */
    qvalue(elt(env, 6)) = v255; /* !'or */
    v255 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v255; /* !'true */
    v255 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 8)) = v255; /* !'false */
    goto v187;

v187:
    v255 = stack[-2];
    v256 = qcar(v255);
    v255 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v256 = (*qfn2(fn))(qenv(fn), v256, v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v255 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* prepf1 */
    v255 = (*qfn2(fn))(qenv(fn), v256, v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v256 = v255;
    v255 = v256;
    if (v255 == nil) goto v24;
    v255 = v256;
    fn = elt(env, 17); /* replus */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    goto v70;

v70:
    fn = elt(env, 14); /* reval */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v257 = v255;
    v256 = v257;
    v255 = (Lisp_Object)1; /* 0 */
    if (v256 == v255) goto v30;
    v255 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-4] = v255;
    goto v258;

v258:
    v255 = stack[-4];
    if (v255 == nil) goto v259;
    v255 = stack[-4];
    v255 = qcar(v255);
    stack[-3] = elt(env, 10); /* times */
    stack[-2] = v257;
    stack[-1] = qvalue(elt(env, 6)); /* !'or */
    stack[0] = v255;
    v256 = elt(env, 11); /* not */
    v255 = list2(v256, v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v256 = list3(stack[-1], stack[0], v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v255 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v256 = (*qfn2(fn))(qenv(fn), v256, v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v255 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* prepf1 */
    v255 = (*qfn2(fn))(qenv(fn), v256, v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v256 = v255;
    v255 = v256;
    if (v255 == nil) goto v111;
    v255 = v256;
    fn = elt(env, 17); /* replus */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    goto v199;

v199:
    v255 = list3(stack[-3], stack[-2], v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    fn = elt(env, 14); /* reval */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v257 = v255;
    v255 = stack[-4];
    v255 = qcdr(v255);
    stack[-4] = v255;
    goto v258;

v111:
    v255 = (Lisp_Object)1; /* 0 */
    goto v199;

v259:
    v255 = v257;
    fn = elt(env, 18); /* simp!-prop!-dist */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v257 = v255;
    v256 = elt(env, 12); /* full */
    v255 = stack[-5];
    v255 = Lmember(nil, v256, v255);
    if (!(v255 == nil)) goto v176;
    v255 = v257;
    fn = elt(env, 19); /* simp!-prop2 */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v257 = v255;
    goto v176;

v176:
    v255 = v257;
    fn = elt(env, 20); /* simp!-prop!-form */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v257 = v255;
    v255 = v257;
    if (is_number(v255)) goto v108;
    v255 = v257;
    if (!consp(v255)) goto v86;
    v255 = elt(env, 13); /* boolean */
    v256 = v257;
    v255 = list2(v255, v256);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v257 = v255;
    goto v86;

v86:
    v256 = (Lisp_Object)17; /* 1 */
    v255 = (Lisp_Object)17; /* 1 */
    v257 = acons(v257, v256, v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    v256 = qvalue(elt(env, 2)); /* nil */
    v255 = (Lisp_Object)17; /* 1 */
    v255 = acons(v257, v256, v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    goto v60;

v60:
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    { popv(8); return onevalue(v255); }

v108:
    v256 = v257;
    v255 = (Lisp_Object)17; /* 1 */
    v255 = cons(v256, v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    goto v60;

v30:
    v255 = qvalue(elt(env, 8)); /* !'false */
    fn = elt(env, 21); /* simp */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-7];
    goto v60;

v24:
    v255 = (Lisp_Object)1; /* 0 */
    goto v70;

v126:
    v255 = elt(env, 3); /* and */
    qvalue(elt(env, 5)) = v255; /* !'and */
    v255 = elt(env, 4); /* or */
    qvalue(elt(env, 6)) = v255; /* !'or */
    v255 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v255; /* !'true */
    v255 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 8)) = v255; /* !'false */
    goto v187;

v168:
    v255 = qvalue(elt(env, 2)); /* nil */
    goto v12;
/* error exit handlers */
v144:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    popv(8);
    return nil;
}



/* Code for vecsimp!* */

static Lisp_Object CC_vecsimpH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecsimp*");
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
    v102 = stack[0];
    fn = elt(env, 1); /* vecp */
    v102 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    if (v102 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v102 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* vecsm!* */
        return (*qfn1(fn))(qenv(fn), v102);
    }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for nodum_varp */

static Lisp_Object CC_nodum_varp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nodum_varp");
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
    v78 = stack[0];
    fn = elt(env, 7); /* listp */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    if (v78 == nil) goto v102;
    v78 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v78); }

v102:
    v79 = stack[0];
    v78 = elt(env, 2); /* dummy */
    v78 = Lflagp(nil, v79, v78);
    env = stack[-1];
    if (!(v78 == nil)) goto v40;
    v78 = stack[0];
    fn = elt(env, 8); /* ad_splitname */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v79 = qcar(v78);
    v78 = qvalue(elt(env, 3)); /* g_dvbase */
    if (equal(v79, v78)) goto v40;
    v79 = elt(env, 4); /* !~dv */
    v78 = elt(env, 5); /* !~dva */
    v78 = list2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v78 = Lmember(nil, stack[0], v78);
    if (!(v78 == nil)) goto v40;
    v78 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v78); }

v40:
    v78 = qvalue(elt(env, 6)); /* nil */
    { popv(2); return onevalue(v78); }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for cl_atmlc */

static Lisp_Object CC_cl_atmlc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atmlc");
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
    v12 = v0;
/* end of prologue */
    v8 = v12;
    v12 = (Lisp_Object)17; /* 1 */
    v12 = cons(v8, v12);
    errexit();
    return ncons(v12);
}



/* Code for color0 */

static Lisp_Object CC_color0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color0");
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
    v78 = stack[-2];
    fn = elt(env, 3); /* chkcg */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    if (v78 == nil) goto v13;
    v78 = stack[-2];
    fn = elt(env, 4); /* afactor */
    stack[-3] = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)17; /* 1 */
    v78 = stack[-2];
    fn = elt(env, 5); /* mkcopy */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    stack[-1] = acons(stack[-1], stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v79 = qvalue(elt(env, 1)); /* nil */
    v78 = (Lisp_Object)17; /* 1 */
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    fn = elt(env, 6); /* color1 */
    v78 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    {
        Lisp_Object v160 = stack[-3];
        popv(5);
        fn = elt(env, 7); /* multsq */
        return (*qfn2(fn))(qenv(fn), v160, v78);
    }

v13:
    v78 = elt(env, 2); /* "This is impossible!" */
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* cerror */
        return (*qfn1(fn))(qenv(fn), v78);
    }
/* error exit handlers */
v179:
    popv(5);
    return nil;
}



/* Code for cl_strict!-gdnf */

static Lisp_Object CC_cl_strictKgdnf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v173, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_strict-gdnf");
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
    v156 = v0;
/* end of prologue */
    v173 = v156;
    v156 = stack[0];
    fn = elt(env, 2); /* cl_strict!-gdnf1 */
    v170 = (*qfn2(fn))(qenv(fn), v173, v156);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v173 = qvalue(elt(env, 1)); /* nil */
    v156 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 3); /* rl_simpl */
    v173 = (*qfnn(fn))(qenv(fn), 3, v170, v173, v156);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v156 = stack[0];
    fn = elt(env, 4); /* cl_mkstrict */
    v156 = (*qfn2(fn))(qenv(fn), v173, v156);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v173 = v156;
    v156 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* rl_bnfsimpl */
        return (*qfn2(fn))(qenv(fn), v173, v156);
    }
/* error exit handlers */
v6:
    popv(2);
    return nil;
}



/* Code for expand!-imrepart */

static Lisp_Object CC_expandKimrepart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expand-imrepart");
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
    goto v60;

v60:
    v21 = stack[-1];
    if (!consp(v21)) goto v100;
    v21 = stack[-1];
    v21 = qcar(v21);
    if (!consp(v21)) goto v100;
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcar(v21);
    fn = elt(env, 1); /* expand!-imrepartpow */
    stack[0] = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = CC_expandKimrepart(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    fn = elt(env, 2); /* multsq */
    v126 = (*qfn2(fn))(qenv(fn), stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v21 = stack[-2];
    v21 = cons(v126, v21);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    stack[-2] = v21;
    v21 = stack[-1];
    v21 = qcdr(v21);
    stack[-1] = v21;
    goto v60;

v100:
    v126 = stack[-1];
    v21 = (Lisp_Object)17; /* 1 */
    v21 = cons(v126, v21);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v126 = v21;
    goto v39;

v39:
    v21 = stack[-2];
    if (v21 == nil) { popv(4); return onevalue(v126); }
    v21 = stack[-2];
    v21 = qcar(v21);
    fn = elt(env, 3); /* addsq */
    v21 = (*qfn2(fn))(qenv(fn), v21, v126);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-3];
    v126 = v21;
    v21 = stack[-2];
    v21 = qcdr(v21);
    stack[-2] = v21;
    goto v39;
/* error exit handlers */
v36:
    popv(4);
    return nil;
}



/* Code for groebspolynom3 */

static Lisp_Object CC_groebspolynom3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebspolynom3");
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
    v168 = v1;
    v29 = v0;
/* end of prologue */
    fn = elt(env, 1); /* groebspolynom4 */
    v168 = (*qfn2(fn))(qenv(fn), v29, v168);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    stack[0] = v168;
    v168 = stack[0];
    fn = elt(env, 2); /* groebsavelterm */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v33;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for wedgewedge */

static Lisp_Object CC_wedgewedge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v237, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgewedge");
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
    goto v34;

v34:
    v71 = stack[-1];
    v71 = qcdr(v71);
    if (v71 == nil) goto v38;
    v71 = stack[-1];
    v203 = qcar(v71);
    v237 = (Lisp_Object)17; /* 1 */
    v71 = (Lisp_Object)17; /* 1 */
    v203 = list2star(v203, v237, v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    v237 = qvalue(elt(env, 1)); /* nil */
    v71 = stack[-2];
    v71 = acons(v203, v237, v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    stack[-2] = v71;
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[-1] = v71;
    goto v34;

v38:
    v71 = stack[-1];
    v203 = qcar(v71);
    v237 = (Lisp_Object)17; /* 1 */
    v71 = (Lisp_Object)17; /* 1 */
    v71 = list2star(v203, v237, v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    stack[-1] = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    v203 = stack[0];
    v237 = (Lisp_Object)17; /* 1 */
    v71 = (Lisp_Object)17; /* 1 */
    v71 = list2star(v203, v237, v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    v71 = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    fn = elt(env, 2); /* wedgepf2 */
    v71 = (*qfn2(fn))(qenv(fn), stack[-1], v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    v237 = v71;
    goto v40;

v40:
    v71 = stack[-2];
    if (v71 == nil) { popv(4); return onevalue(v237); }
    v71 = stack[-2];
    v71 = qcar(v71);
    fn = elt(env, 2); /* wedgepf2 */
    v71 = (*qfn2(fn))(qenv(fn), v71, v237);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-3];
    v237 = v71;
    v71 = stack[-2];
    v71 = qcdr(v71);
    stack[-2] = v71;
    goto v40;
/* error exit handlers */
v24:
    popv(4);
    return nil;
}



/* Code for deflate1 */

static Lisp_Object CC_deflate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v188, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deflate1");
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
    stack[-6] = v1;
    v202 = v0;
/* end of prologue */
    stack[-7] = nil;
    fn = elt(env, 3); /* ncoeffs */
    v188 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v202 = v188;
    v188 = qcar(v188);
    stack[-5] = v188;
    v202 = qcdr(v202);
    v188 = v202;
    v188 = qcar(v188);
    stack[-4] = v188;
    v202 = qcdr(v202);
    stack[-3] = v202;
    goto v29;

v29:
    v202 = stack[-3];
    if (v202 == nil) goto v31;
    v202 = stack[-3];
    v202 = qcar(v202);
    stack[-2] = v202;
    v202 = stack[-5];
    v202 = sub1(v202);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    stack[-5] = v202;
    v202 = stack[-4];
    v202 = qcdr(v202);
    v188 = qcar(v202);
    v202 = (Lisp_Object)1; /* 0 */
    if (v188 == v202) goto v160;
    v124 = stack[-5];
    v188 = stack[-4];
    v202 = stack[-7];
    v202 = acons(v124, v188, v202);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    stack[-7] = v202;
    goto v160;

v160:
    stack[-1] = elt(env, 2); /* !:rd!: */
    v202 = stack[-6];
    v202 = qcdr(v202);
    v188 = qcar(v202);
    v202 = stack[-4];
    v202 = qcdr(v202);
    v202 = qcar(v202);
    stack[0] = times2(v188, v202);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v202 = stack[-6];
    v202 = qcdr(v202);
    v188 = qcdr(v202);
    v202 = stack[-4];
    v202 = qcdr(v202);
    v202 = qcdr(v202);
    v202 = plus2(v188, v202);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    v202 = list2star(stack[-1], stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    stack[-4] = v202;
    v202 = stack[-2];
    if (v202 == nil) goto v203;
    v188 = stack[-2];
    v202 = stack[-4];
    fn = elt(env, 4); /* plus!: */
    v202 = (*qfn2(fn))(qenv(fn), v188, v202);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-8];
    stack[-4] = v202;
    goto v203;

v203:
    v202 = stack[-3];
    v202 = qcdr(v202);
    stack[-3] = v202;
    goto v29;

v31:
    v188 = stack[-4];
    v202 = stack[-7];
    popv(9);
    return cons(v188, v202);
/* error exit handlers */
v261:
    popv(9);
    return nil;
}



/* Code for mkforttab */

static Lisp_Object MS_CDECL CC_mkforttab(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v168;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkforttab");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkforttab");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    stack[0] = elt(env, 1); /* forttab */
    v168 = qvalue(elt(env, 2)); /* fortcurrind!* */
    v169 = (Lisp_Object)97; /* 6 */
    v169 = plus2(v168, v169);
    nil = C_nil;
    if (exception_pending()) goto v28;
    {
        Lisp_Object v33 = stack[0];
        popv(1);
        return list2(v33, v169);
    }
/* error exit handlers */
v28:
    popv(1);
    return nil;
}



/* Code for rsubla */

static Lisp_Object CC_rsubla(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rsubla");
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
    if (v212 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v212 = stack[0];
    if (v212 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v212 = stack[0];
    if (!consp(v212)) goto v10;
    v207 = stack[-1];
    v212 = stack[0];
    v212 = qcar(v212);
    stack[-2] = CC_rsubla(env, v207, v212);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v207 = stack[-1];
    v212 = stack[0];
    v212 = qcdr(v212);
    v212 = CC_rsubla(env, v207, v212);
    nil = C_nil;
    if (exception_pending()) goto v21;
    {
        Lisp_Object v126 = stack[-2];
        popv(4);
        return cons(v126, v212);
    }

v10:
    v207 = stack[0];
    v212 = stack[-1];
    fn = elt(env, 1); /* rassoc */
    v212 = (*qfn2(fn))(qenv(fn), v207, v212);
    nil = C_nil;
    if (exception_pending()) goto v21;
    v207 = v212;
    if (v212 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v212 = v207;
    v212 = qcar(v212);
    { popv(4); return onevalue(v212); }
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for s_world_names */

static Lisp_Object CC_s_world_names(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s_world_names");
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
    v13 = v0;
/* end of prologue */
    v13 = qcar(v13);
    stack[-3] = v13;
    v13 = stack[-3];
    if (v13 == nil) goto v8;
    v13 = stack[-3];
    v13 = qcar(v13);
    v13 = qcar(v13);
    v13 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    stack[-1] = v13;
    stack[-2] = v13;
    goto v34;

v34:
    v13 = stack[-3];
    v13 = qcdr(v13);
    stack[-3] = v13;
    v13 = stack[-3];
    if (v13 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v13 = stack[-3];
    v13 = qcar(v13);
    v13 = qcar(v13);
    v13 = ncons(v13);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v13 = Lrplacd(nil, stack[0], v13);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v13 = stack[-1];
    v13 = qcdr(v13);
    stack[-1] = v13;
    goto v34;

v8:
    v13 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v13); }
/* error exit handlers */
v78:
    popv(5);
    return nil;
}



/* Code for fs!:timescoeff */

static Lisp_Object CC_fsTtimescoeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v197, v157, v263;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:timescoeff");
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

v264:
    v136 = stack[-2];
    if (v136 == nil) goto v47;
    v157 = stack[-3];
    v197 = stack[-2];
    v136 = (Lisp_Object)1; /* 0 */
    v136 = *(Lisp_Object *)((char *)v197 + (CELL-TAG_VECTOR) + ((int32_t)v136/(16/CELL)));
    fn = elt(env, 4); /* multsq */
    v136 = (*qfn2(fn))(qenv(fn), v157, v136);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-5];
    stack[0] = v136;
    v197 = stack[0];
    v136 = elt(env, 2); /* (nil . 1) */
    if (equal(v197, v136)) goto v128;
    v136 = (Lisp_Object)49; /* 3 */
    v136 = Lmkvect(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-5];
    stack[-4] = v136;
    v157 = stack[-4];
    v197 = (Lisp_Object)1; /* 0 */
    v136 = stack[0];
    *(Lisp_Object *)((char *)v157 + (CELL-TAG_VECTOR) + ((int32_t)v197/(16/CELL))) = v136;
    v263 = stack[-4];
    v157 = (Lisp_Object)17; /* 1 */
    v197 = stack[-2];
    v136 = (Lisp_Object)17; /* 1 */
    v136 = *(Lisp_Object *)((char *)v197 + (CELL-TAG_VECTOR) + ((int32_t)v136/(16/CELL)));
    *(Lisp_Object *)((char *)v263 + (CELL-TAG_VECTOR) + ((int32_t)v157/(16/CELL))) = v136;
    v263 = stack[-4];
    v157 = (Lisp_Object)33; /* 2 */
    v197 = stack[-2];
    v136 = (Lisp_Object)33; /* 2 */
    v136 = *(Lisp_Object *)((char *)v197 + (CELL-TAG_VECTOR) + ((int32_t)v136/(16/CELL)));
    *(Lisp_Object *)((char *)v263 + (CELL-TAG_VECTOR) + ((int32_t)v157/(16/CELL))) = v136;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)49; /* 3 */
    v157 = stack[-3];
    v197 = stack[-2];
    v136 = (Lisp_Object)49; /* 3 */
    v136 = *(Lisp_Object *)((char *)v197 + (CELL-TAG_VECTOR) + ((int32_t)v136/(16/CELL)));
    v136 = CC_fsTtimescoeff(env, v157, v136);
    nil = C_nil;
    if (exception_pending()) goto v185;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v136;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v128:
    v136 = elt(env, 3); /* "zero in times" */
    v136 = Lprint(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-5];
    v157 = stack[-3];
    v197 = stack[-2];
    v136 = (Lisp_Object)49; /* 3 */
    v136 = *(Lisp_Object *)((char *)v197 + (CELL-TAG_VECTOR) + ((int32_t)v136/(16/CELL)));
    stack[-3] = v157;
    stack[-2] = v136;
    goto v264;

v47:
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v136); }
/* error exit handlers */
v185:
    popv(6);
    return nil;
}



/* Code for f2df */

static Lisp_Object CC_f2df(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v32, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2df");
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
    v159 = stack[0];
    if (!consp(v159)) goto v102;
    v159 = stack[0];
    v159 = qcar(v159);
    if (!consp(v159)) goto v102;
    v159 = stack[0];
    v159 = qcar(v159);
    v159 = qcar(v159);
    v32 = qcar(v159);
    v159 = qvalue(elt(env, 1)); /* zlist */
    v159 = Lmember(nil, v32, v159);
    if (v159 == nil) goto v195;
    v159 = stack[0];
    v159 = qcar(v159);
    v159 = qcar(v159);
    v202 = qcar(v159);
    v159 = stack[0];
    v159 = qcar(v159);
    v159 = qcar(v159);
    v32 = qcdr(v159);
    v159 = qvalue(elt(env, 1)); /* zlist */
    fn = elt(env, 3); /* vp2df */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v202, v32, v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v159 = stack[0];
    v159 = qcar(v159);
    v159 = qcdr(v159);
    v159 = CC_f2df(env, v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    fn = elt(env, 4); /* multdf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v159 = stack[0];
    v159 = qcdr(v159);
    v159 = CC_f2df(env, v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    {
        Lisp_Object v91 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v91, v159);
    }

v195:
    v159 = stack[0];
    v159 = qcar(v159);
    v32 = qcar(v159);
    v159 = (Lisp_Object)17; /* 1 */
    v202 = cons(v32, v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v32 = qvalue(elt(env, 2)); /* nil */
    v159 = (Lisp_Object)17; /* 1 */
    stack[-1] = acons(v202, v32, v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v159 = stack[0];
    v159 = qcar(v159);
    v159 = qcdr(v159);
    v159 = CC_f2df(env, v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    fn = elt(env, 6); /* multdfconst */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v159 = stack[0];
    v159 = qcdr(v159);
    v159 = CC_f2df(env, v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    {
        Lisp_Object v259 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v259, v159);
    }

v102:
    v32 = stack[0];
    v159 = (Lisp_Object)17; /* 1 */
    v159 = cons(v32, v159);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* dfconst */
        return (*qfn1(fn))(qenv(fn), v159);
    }
/* error exit handlers */
v123:
    popv(3);
    return nil;
}



/* Code for nlist */

static Lisp_Object CC_nlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nlist");
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
    goto v12;

v12:
    v101 = stack[0];
    v128 = (Lisp_Object)1; /* 0 */
    if (v101 == v128) goto v40;
    v101 = stack[-1];
    v128 = stack[-2];
    v128 = cons(v101, v128);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    stack[-2] = v128;
    v128 = stack[0];
    v128 = sub1(v128);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    stack[0] = v128;
    goto v12;

v40:
    v128 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v128);
    }
/* error exit handlers */
v5:
    popv(4);
    return nil;
}



/* Code for pasf_smordtable1 */

static Lisp_Object CC_pasf_smordtable1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v191, v96;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v1;
    v191 = v0;
/* end of prologue */
    v96 = elt(env, 1); /* ((lessp (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (leq (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false)
 (cong nil) (ncong nil)) (equal (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (neq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong n
il) (ncong nil)) (geq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)) (greaterp (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong 
nil))) */
    v191 = Latsoc(nil, v191, v96);
    v10 = Latsoc(nil, v10, v191);
    v10 = qcdr(v10);
    return onevalue(v10);
}



/* Code for dvfsf_simplat1 */

static Lisp_Object CC_dvfsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v160, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_simplat1");
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
    v179 = stack[-2];
    fn = elt(env, 3); /* dvfsf_op */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v88 = v179;
    v160 = v88;
    v179 = elt(env, 1); /* equal */
    if (v160 == v179) goto v80;
    v160 = v88;
    v179 = elt(env, 2); /* neq */
    if (v160 == v179) goto v80;
    stack[-3] = v88;
    v179 = stack[-2];
    fn = elt(env, 4); /* dvfsf_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v179 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2r */
    v160 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v179 = stack[-1];
    {
        Lisp_Object v76 = stack[-3];
        Lisp_Object v20 = stack[0];
        popv(5);
        fn = elt(env, 6); /* dvfsf_saval */
        return (*qfnn(fn))(qenv(fn), 4, v76, v20, v160, v179);
    }

v80:
    stack[0] = v88;
    v179 = stack[-2];
    fn = elt(env, 4); /* dvfsf_arg2l */
    v160 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v179 = stack[-1];
    {
        Lisp_Object v21 = stack[0];
        popv(5);
        fn = elt(env, 7); /* dvfsf_safield */
        return (*qfnn(fn))(qenv(fn), 3, v21, v160, v179);
    }
/* error exit handlers */
v75:
    popv(5);
    return nil;
}



/* Code for bvarom */

static Lisp_Object CC_bvarom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bvarom");
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
    v128 = stack[0];
    v128 = qcar(v128);
    v128 = Lconsp(nil, v128);
    env = stack[-1];
    if (v128 == nil) goto v47;
    v128 = stack[0];
    v128 = qcar(v128);
    v101 = qcar(v128);
    v128 = elt(env, 1); /* bvar */
    if (!(v101 == v128)) goto v47;
    v128 = stack[0];
    v128 = qcar(v128);
    v128 = qcdr(v128);
    v128 = qcar(v128);
    fn = elt(env, 2); /* objectom */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-1];
    v128 = stack[0];
    v128 = qcdr(v128);
    v128 = CC_bvarom(env, v128);
    nil = C_nil;
    if (exception_pending()) goto v4;
    goto v47;

v47:
    v128 = nil;
    { popv(2); return onevalue(v128); }
/* error exit handlers */
v4:
    popv(2);
    return nil;
}



/* Code for ps!:arg!-values */

static Lisp_Object CC_psTargKvalues(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v211, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:arg-values");
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
    v211 = v0;
/* end of prologue */
    v210 = v211;
    stack[-4] = qcar(v210);
    v210 = v211;
    v210 = qcdr(v210);
    stack[-3] = v210;
    v210 = stack[-3];
    if (v210 == nil) goto v33;
    v210 = stack[-3];
    v210 = qcar(v210);
    v235 = v210;
    v210 = v235;
    if (!consp(v210)) goto v81;
    v210 = v235;
    v211 = qcar(v210);
    v210 = elt(env, 2); /* !:ps!: */
    if (v211 == v210) goto v127;
    v210 = v235;
    v211 = qcar(v210);
    v210 = elt(env, 3); /* dname */
    v210 = get(v211, v210);
    env = stack[-5];
    if (!(v210 == nil)) goto v81;

v127:
    v210 = v235;
    v210 = Lconsp(nil, v210);
    env = stack[-5];
    if (v210 == nil) goto v36;
    v210 = v235;
    v211 = qcar(v210);
    v210 = elt(env, 2); /* !:ps!: */
    if (!(v211 == v210)) goto v36;
    v210 = v235;
    fn = elt(env, 4); /* ps!:value */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    goto v80;

v80:
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    stack[-1] = v210;
    stack[-2] = v210;
    goto v17;

v17:
    v210 = stack[-3];
    v210 = qcdr(v210);
    stack[-3] = v210;
    v210 = stack[-3];
    if (v210 == nil) goto v121;
    stack[0] = stack[-1];
    v210 = stack[-3];
    v210 = qcar(v210);
    v235 = v210;
    v210 = v235;
    if (!consp(v210)) goto v67;
    v210 = v235;
    v211 = qcar(v210);
    v210 = elt(env, 2); /* !:ps!: */
    if (v211 == v210) goto v92;
    v210 = v235;
    v211 = qcar(v210);
    v210 = elt(env, 3); /* dname */
    v210 = get(v211, v210);
    env = stack[-5];
    if (!(v210 == nil)) goto v67;

v92:
    v210 = v235;
    v210 = Lconsp(nil, v210);
    env = stack[-5];
    if (v210 == nil) goto v200;
    v210 = v235;
    v211 = qcar(v210);
    v210 = elt(env, 2); /* !:ps!: */
    if (!(v211 == v210)) goto v200;
    v210 = v235;
    fn = elt(env, 4); /* ps!:value */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    goto v25;

v25:
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    v210 = Lrplacd(nil, stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    v210 = stack[-1];
    v210 = qcdr(v210);
    stack[-1] = v210;
    goto v17;

v200:
    v210 = v235;
    v210 = CC_psTargKvalues(env, v210);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    goto v25;

v67:
    v210 = v235;
    goto v25;

v121:
    v210 = stack[-2];
    goto v60;

v60:
    {
        Lisp_Object v251 = stack[-4];
        popv(6);
        return cons(v251, v210);
    }

v36:
    v210 = v235;
    v210 = CC_psTargKvalues(env, v210);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-5];
    goto v80;

v81:
    v210 = v235;
    goto v80;

v33:
    v210 = qvalue(elt(env, 1)); /* nil */
    goto v60;
/* error exit handlers */
v183:
    popv(6);
    return nil;
}



/* Code for copy_vect */

static Lisp_Object CC_copy_vect(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v78, v79, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy_vect");
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
    v77 = stack[-1];
    v77 = Lupbv(nil, v77);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-4];
    stack[-3] = v77;
    v77 = (Lisp_Object)1; /* 0 */
    stack[0] = v77;
    goto v9;

v9:
    v78 = stack[-3];
    v77 = stack[0];
    v77 = difference2(v78, v77);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-4];
    v77 = Lminusp(nil, v77);
    env = stack[-4];
    if (v77 == nil) goto v81;
    v77 = nil;
    { popv(5); return onevalue(v77); }

v81:
    v16 = stack[-2];
    v79 = stack[0];
    v78 = stack[-1];
    v77 = stack[0];
    v77 = *(Lisp_Object *)((char *)v78 + (CELL-TAG_VECTOR) + ((int32_t)v77/(16/CELL)));
    *(Lisp_Object *)((char *)v16 + (CELL-TAG_VECTOR) + ((int32_t)v79/(16/CELL))) = v77;
    v77 = stack[0];
    v77 = add1(v77);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-4];
    stack[0] = v77;
    goto v9;
/* error exit handlers */
v160:
    popv(5);
    return nil;
}



/* Code for findhc */

static Lisp_Object CC_findhc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v122;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findhc");
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
    v158 = v0;
/* end of prologue */
    stack[-4] = nil;
    v122 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v122; /* njsi */
    stack[-2] = v122;
    v122 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v122; /* jsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v122 = qvalue(elt(env, 5)); /* maxvar */
    v158 = plus2(v122, v158);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v122 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v158/(16/CELL)));
    v158 = (Lisp_Object)65; /* 4 */
    v158 = *(Lisp_Object *)((char *)v122 + (CELL-TAG_VECTOR) + ((int32_t)v158/(16/CELL)));
    stack[-1] = v158;
    goto v102;

v102:
    v158 = stack[-1];
    if (v158 == nil) goto v8;
    v158 = stack[-1];
    v158 = qcar(v158);
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v122 = qvalue(elt(env, 5)); /* maxvar */
    v158 = qcar(v158);
    stack[-3] = v158;
    v158 = plus2(v122, v158);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v122 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v158/(16/CELL)));
    v158 = (Lisp_Object)1; /* 0 */
    v158 = *(Lisp_Object *)((char *)v122 + (CELL-TAG_VECTOR) + ((int32_t)v158/(16/CELL)));
    if (v158 == nil) goto v14;
    v122 = stack[-3];
    v158 = qvalue(elt(env, 3)); /* jsi */
    v158 = cons(v122, v158);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    qvalue(elt(env, 3)) = v158; /* jsi */
    v158 = qvalue(elt(env, 1)); /* njsi */
    v158 = add1(v158);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    qvalue(elt(env, 1)) = v158; /* njsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v122 = qvalue(elt(env, 5)); /* maxvar */
    v158 = stack[-3];
    v158 = plus2(v122, v158);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v122 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v158/(16/CELL)));
    v158 = (Lisp_Object)17; /* 1 */
    v158 = *(Lisp_Object *)((char *)v122 + (CELL-TAG_VECTOR) + ((int32_t)v158/(16/CELL)));
    v158 = qcar(v158);
    v122 = qcar(v158);
    stack[0] = v122;
    v158 = stack[-2];
    v158 = (Lisp_Object)greaterp2(v122, v158);
    nil = C_nil;
    if (exception_pending()) goto v157;
    v158 = v158 ? lisp_true : nil;
    env = stack[-5];
    if (v158 == nil) goto v14;
    v158 = stack[0];
    stack[-2] = v158;
    v158 = stack[-3];
    stack[-4] = v158;
    goto v14;

v14:
    v158 = stack[-1];
    v158 = qcdr(v158);
    stack[-1] = v158;
    goto v102;

v8:
    v158 = qvalue(elt(env, 3)); /* jsi */
    v158 = Lreverse(nil, v158);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    qvalue(elt(env, 3)) = v158; /* jsi */
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v157:
    popv(6);
    return nil;
}



/* Code for calc_den_tar */

static Lisp_Object CC_calc_den_tar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_den_tar");
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
    v98 = v1;
    v80 = v0;
/* end of prologue */
    fn = elt(env, 1); /* denlist */
    v98 = (*qfn2(fn))(qenv(fn), v80, v98);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[0];
    v80 = v98;
    v98 = v80;
    if (v98 == nil) goto v41;
    v98 = v80;
    v98 = qcdr(v98);
    if (v98 == nil) goto v29;
    v98 = v80;
    {
        popv(1);
        fn = elt(env, 2); /* constimes */
        return (*qfn1(fn))(qenv(fn), v98);
    }

v29:
    v98 = v80;
    v98 = qcar(v98);
    { popv(1); return onevalue(v98); }

v41:
    v98 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v98); }
/* error exit handlers */
v81:
    popv(1);
    return nil;
}



setup_type const u34_setup[] =
{
    {"calc_coeffmap_",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_calc_coeffmap_},
    {"mkindxlist",              CC_mkindxlist,  too_many_1,    wrong_no_1},
    {"cl_rename-vars",          CC_cl_renameKvars,too_many_1,  wrong_no_1},
    {"rule",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_rule},
    {"setrd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrd},
    {"countof",                 too_few_2,      CC_countof,    wrong_no_2},
    {"ps:set-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTsetKterm},
    {"crprep1",                 CC_crprep1,     too_many_1,    wrong_no_1},
    {"groebinvokecritm",        too_few_2,      CC_groebinvokecritm,wrong_no_2},
    {"evzero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_evzero},
    {"exdf0",                   CC_exdf0,       too_many_1,    wrong_no_1},
    {"evalmember",              too_few_2,      CC_evalmember, wrong_no_2},
    {":log2",                   CC_Tlog2,       too_many_1,    wrong_no_1},
    {"absf",                    CC_absf,        too_many_1,    wrong_no_1},
    {"getupper",                CC_getupper,    too_many_1,    wrong_no_1},
    {"groeb=rf1",               too_few_2,      CC_groebMrf1,  wrong_no_2},
    {"cl_sitheo",               CC_cl_sitheo,   too_many_1,    wrong_no_1},
    {"rtypepart",               CC_rtypepart,   too_many_1,    wrong_no_1},
    {"mchsarg",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchsarg},
    {"aex_tad",                 CC_aex_tad,     too_many_1,    wrong_no_1},
    {"setfuncsnaryrd",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_setfuncsnaryrd},
    {"ciml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_ciml},
    {"o-nextarg",               CC_oKnextarg,   too_many_1,    wrong_no_1},
    {"ndepends",                too_few_2,      CC_ndepends,   wrong_no_2},
    {"basisformp",              CC_basisformp,  too_many_1,    wrong_no_1},
    {"decimal2internal",        too_few_2,      CC_decimal2internal,wrong_no_2},
    {"physoppri",               CC_physoppri,   too_many_1,    wrong_no_1},
    {"prsum",                   too_few_2,      CC_prsum,      wrong_no_2},
    {"fs:onep:",                CC_fsTonepT,    too_many_1,    wrong_no_1},
    {"simp-prop",               CC_simpKprop,   too_many_1,    wrong_no_1},
    {"vecsimp*",                CC_vecsimpH,    too_many_1,    wrong_no_1},
    {"nodum_varp",              CC_nodum_varp,  too_many_1,    wrong_no_1},
    {"cl_atmlc",                CC_cl_atmlc,    too_many_1,    wrong_no_1},
    {"color0",                  CC_color0,      too_many_1,    wrong_no_1},
    {"cl_strict-gdnf",          too_few_2,      CC_cl_strictKgdnf,wrong_no_2},
    {"expand-imrepart",         CC_expandKimrepart,too_many_1, wrong_no_1},
    {"groebspolynom3",          too_few_2,      CC_groebspolynom3,wrong_no_2},
    {"wedgewedge",              too_few_2,      CC_wedgewedge, wrong_no_2},
    {"deflate1",                too_few_2,      CC_deflate1,   wrong_no_2},
    {"mkforttab",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkforttab},
    {"rsubla",                  too_few_2,      CC_rsubla,     wrong_no_2},
    {"s_world_names",           CC_s_world_names,too_many_1,   wrong_no_1},
    {"fs:timescoeff",           too_few_2,      CC_fsTtimescoeff,wrong_no_2},
    {"f2df",                    CC_f2df,        too_many_1,    wrong_no_1},
    {"nlist",                   too_few_2,      CC_nlist,      wrong_no_2},
    {"pasf_smordtable1",        too_few_2,      CC_pasf_smordtable1,wrong_no_2},
    {"dvfsf_simplat1",          too_few_2,      CC_dvfsf_simplat1,wrong_no_2},
    {"bvarom",                  CC_bvarom,      too_many_1,    wrong_no_1},
    {"ps:arg-values",           CC_psTargKvalues,too_many_1,   wrong_no_1},
    {"copy_vect",               too_few_2,      CC_copy_vect,  wrong_no_2},
    {"findhc",                  CC_findhc,      too_many_1,    wrong_no_1},
    {"calc_den_tar",            too_few_2,      CC_calc_den_tar,wrong_no_2},
    {NULL, (one_args *)"u34", (two_args *)"6420 5705079 4772961", 0}
};

/* end of generated code */
