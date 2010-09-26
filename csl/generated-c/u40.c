
/* $destdir\u40.c        Machine generated C code */

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


/* Code for pasf_floor */

static Lisp_Object CC_pasf_floor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_floor");
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
    v20 = stack[-1];
    if (!consp(v20)) goto v23;
    v20 = stack[-1];
    v20 = qcar(v20);
    if (!(!consp(v20))) goto v24;

v23:
    v20 = stack[0];
    if (!consp(v20)) goto v25;
    v20 = stack[0];
    v20 = qcar(v20);
    if (!(!consp(v20))) goto v24;

v25:
    v20 = stack[-1];
    if (v20 == nil) goto v26;
    v21 = stack[-1];
    v20 = stack[0];
    v21 = Cremainder(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v20 = (Lisp_Object)1; /* 0 */
    if (v21 == v20) goto v28;
    v21 = stack[-1];
    v20 = stack[0];
    v21 = times2(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v20 = (Lisp_Object)1; /* 0 */
    v20 = (Lisp_Object)greaterp2(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    v20 = v20 ? lisp_true : nil;
    env = stack[-2];
    if (v20 == nil) goto v29;
    v21 = stack[-1];
    v20 = stack[0];
    v20 = quot2(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    goto v30;

v30:
    fn = elt(env, 4); /* simp */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    v20 = qcar(v20);
    { popv(3); return onevalue(v20); }

v29:
    v21 = stack[-1];
    v20 = stack[0];
    v20 = quot2(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v20 = sub1(v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    goto v30;

v28:
    v21 = stack[-1];
    v20 = stack[0];
    v20 = quot2(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    goto v30;

v26:
    v20 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v20); }

v24:
    v20 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v20 == nil)) goto v31;
    v22 = elt(env, 3); /* "pasf_floor: not a domain valued sf in input" 
*/
    v21 = stack[-1];
    v20 = stack[0];
    v20 = list3(v22, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    fn = elt(env, 5); /* lprie */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    goto v31;

v31:
    v20 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    v20 = nil;
    { popv(3); return onevalue(v20); }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for diffrd */

static Lisp_Object MS_CDECL CC_diffrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v17, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "diffrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffrd");
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
    fn = elt(env, 4); /* lex */
    v19 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    v17 = qvalue(elt(env, 1)); /* char */
    v19 = elt(env, 2); /* (b v a r) */
    if (equal(v17, v19)) goto v41;
    v19 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v19;
    v19 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v19;
    goto v42;

v42:
    fn = elt(env, 5); /* mathml2 */
    v19 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[0] = v19;
    fn = elt(env, 4); /* lex */
    v19 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    v39 = stack[0];
    v17 = stack[-2];
    v19 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* alg_df */
        return (*qfnn(fn))(qenv(fn), 3, v39, v17, v19);
    }

v41:
    fn = elt(env, 7); /* bvarrd */
    v19 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[-2] = v19;
    v19 = stack[-2];
    v19 = qcdr(v19);
    v19 = qcar(v19);
    stack[-1] = v19;
    v19 = stack[-2];
    v19 = qcar(v19);
    stack[-2] = v19;
    fn = elt(env, 4); /* lex */
    v19 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    goto v42;
/* error exit handlers */
v40:
    popv(4);
    return nil;
}



/* Code for rand!-comb */

static Lisp_Object CC_randKcomb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rand-comb");
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
    stack[-3] = v1;
    stack[-1] = v0;
/* end of prologue */
    v75 = stack[-3];
    v74 = stack[-1];
    if (equal(v75, v74)) goto v25;
    stack[-2] = nil;
    v75 = stack[-1];
    v74 = stack[-3];
    v75 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = stack[-3];
    v74 = (Lisp_Object)lessp2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v74 = v74 ? lisp_true : nil;
    env = stack[-5];
    if (v74 == nil) goto v78;
    stack[0] = stack[-1];
    v75 = stack[-1];
    v74 = stack[-3];
    v74 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = CC_randKcomb(env, stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-3] = v74;
    v74 = (Lisp_Object)1; /* 0 */
    stack[0] = v74;
    goto v79;

v79:
    v74 = stack[-1];
    v75 = sub1(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = stack[0];
    v74 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = Lminusp(nil, v74);
    env = stack[-5];
    if (!(v74 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v75 = stack[0];
    v74 = stack[-3];
    v74 = Lmember(nil, v75, v74);
    if (!(v74 == nil)) goto v80;
    v75 = stack[0];
    v74 = stack[-2];
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-2] = v74;
    goto v80;

v80:
    v74 = stack[0];
    v74 = add1(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[0] = v74;
    goto v79;

v78:
    v74 = (Lisp_Object)1; /* 0 */
    stack[0] = v74;
    goto v81;

v81:
    v74 = stack[-3];
    v75 = sub1(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = stack[0];
    v74 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = Lminusp(nil, v74);
    env = stack[-5];
    if (!(v74 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v82:
    v74 = stack[-1];
    fn = elt(env, 2); /* random */
    v75 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v76 = v75;
    v74 = stack[-2];
    v74 = Lmember(nil, v75, v74);
    if (!(v74 == nil)) goto v82;
    v75 = v76;
    v74 = stack[-2];
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-2] = v74;
    v74 = stack[0];
    v74 = add1(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[0] = v74;
    goto v81;

v25:
    v74 = (Lisp_Object)1; /* 0 */
    stack[-4] = v74;
    v74 = stack[-3];
    v75 = sub1(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = stack[-4];
    v74 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = Lminusp(nil, v74);
    env = stack[-5];
    if (v74 == nil) goto v83;
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v74); }

v83:
    v74 = stack[-4];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-1] = v74;
    stack[-2] = v74;
    goto v84;

v84:
    v74 = stack[-4];
    v74 = add1(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-4] = v74;
    v74 = stack[-3];
    v75 = sub1(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = stack[-4];
    v74 = difference2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = Lminusp(nil, v74);
    env = stack[-5];
    if (!(v74 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v74 = stack[-4];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = Lrplacd(nil, stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v74 = stack[-1];
    v74 = qcdr(v74);
    stack[-1] = v74;
    goto v84;
/* error exit handlers */
v77:
    popv(6);
    return nil;
}



/* Code for symmetrize!-inds */

static Lisp_Object CC_symmetrizeKinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symmetrize-inds");
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
    v127 = (Lisp_Object)1; /* 0 */
    stack[-10] = v127;
    v127 = stack[-9];
    stack[-7] = v127;
    v127 = stack[-7];
    if (v127 == nil) goto v84;
    v127 = stack[-7];
    v127 = qcar(v127);
    v128 = v127;
    if (!consp(v128)) goto v129;
    stack[-3] = v127;
    v127 = stack[-3];
    if (v127 == nil) goto v14;
    v127 = stack[-3];
    v127 = qcar(v127);
    v128 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = qcar(v127);
    v127 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    stack[-1] = v127;
    stack[-2] = v127;
    goto v131;

v131:
    v127 = stack[-3];
    v127 = qcdr(v127);
    stack[-3] = v127;
    v127 = stack[-3];
    if (v127 == nil) goto v132;
    stack[0] = stack[-1];
    v127 = stack[-3];
    v127 = qcar(v127);
    v128 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = qcar(v127);
    v127 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = Lrplacd(nil, stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = stack[-1];
    v127 = qcdr(v127);
    stack[-1] = v127;
    goto v131;

v132:
    v127 = stack[-2];
    goto v5;

v5:
    v127 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    stack[-5] = v127;
    stack[-6] = v127;
    goto v69;

v69:
    v127 = stack[-7];
    v127 = qcdr(v127);
    stack[-7] = v127;
    v127 = stack[-7];
    if (v127 == nil) goto v133;
    stack[-4] = stack[-5];
    v127 = stack[-7];
    v127 = qcar(v127);
    v128 = v127;
    if (!consp(v128)) goto v57;
    stack[-3] = v127;
    v127 = stack[-3];
    if (v127 == nil) goto v134;
    v127 = stack[-3];
    v127 = qcar(v127);
    v128 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = qcar(v127);
    v127 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    stack[-1] = v127;
    stack[-2] = v127;
    goto v135;

v135:
    v127 = stack[-3];
    v127 = qcdr(v127);
    stack[-3] = v127;
    v127 = stack[-3];
    if (v127 == nil) goto v136;
    stack[0] = stack[-1];
    v127 = stack[-3];
    v127 = qcar(v127);
    v128 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = qcar(v127);
    v127 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = Lrplacd(nil, stack[0], v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = stack[-1];
    v127 = qcdr(v127);
    stack[-1] = v127;
    goto v135;

v136:
    v127 = stack[-2];
    goto v79;

v79:
    v127 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = Lrplacd(nil, stack[-4], v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = stack[-5];
    v127 = qcdr(v127);
    stack[-5] = v127;
    goto v69;

v134:
    v127 = qvalue(elt(env, 1)); /* nil */
    goto v79;

v57:
    v128 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = qcar(v127);
    goto v79;

v133:
    v127 = stack[-6];
    goto v66;

v66:
    stack[-5] = v127;
    v127 = stack[-5];
    v127 = qcar(v127);
    if (!consp(v127)) goto v137;
    v127 = stack[-5];
    fn = elt(env, 3); /* indordln */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    fn = elt(env, 4); /* flatindl */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    goto v138;

v138:
    stack[0] = v127;
    v127 = stack[-9];
    v127 = qcar(v127);
    if (!consp(v127)) goto v139;
    v127 = stack[-9];
    fn = elt(env, 4); /* flatindl */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    stack[-9] = v127;
    goto v139;

v139:
    v128 = stack[-9];
    v127 = stack[0];
    fn = elt(env, 5); /* pair */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    stack[-5] = v127;
    stack[-6] = (Lisp_Object)17; /* 1 */
    v127 = stack[-8];
    stack[-7] = v127;
    v127 = stack[-7];
    if (v127 == nil) goto v140;
    v127 = stack[-7];
    v127 = qcar(v127);
    stack[-1] = v127;
    v127 = stack[-5];
    if (v127 == nil) goto v141;
    v127 = stack[-5];
    v127 = qcar(v127);
    stack[0] = qcar(v127);
    v127 = stack[-10];
    v127 = add1(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    stack[-10] = v127;
    if (!(equal(stack[0], v127))) goto v141;
    v127 = stack[-5];
    v127 = qcar(v127);
    v127 = qcdr(v127);
    v128 = v127;
    v127 = stack[-5];
    v127 = qcdr(v127);
    stack[-5] = v127;
    v127 = v128;
    goto v142;

v142:
    v127 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    stack[-3] = v127;
    stack[-4] = v127;
    goto v143;

v143:
    v127 = stack[-7];
    v127 = qcdr(v127);
    stack[-7] = v127;
    v127 = stack[-7];
    if (v127 == nil) goto v144;
    stack[-2] = stack[-3];
    v127 = stack[-7];
    v127 = qcar(v127);
    stack[-1] = v127;
    v127 = stack[-5];
    if (v127 == nil) goto v145;
    v127 = stack[-5];
    v127 = qcar(v127);
    stack[0] = qcar(v127);
    v127 = stack[-10];
    v127 = add1(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    stack[-10] = v127;
    if (!(equal(stack[0], v127))) goto v145;
    v127 = stack[-5];
    v127 = qcar(v127);
    v127 = qcdr(v127);
    v128 = v127;
    v127 = stack[-5];
    v127 = qcdr(v127);
    stack[-5] = v127;
    v127 = v128;
    goto v146;

v146:
    v127 = ncons(v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = Lrplacd(nil, stack[-2], v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = stack[-3];
    v127 = qcdr(v127);
    stack[-3] = v127;
    goto v143;

v145:
    v127 = stack[-1];
    goto v146;

v144:
    v127 = stack[-4];
    goto v147;

v147:
    {
        Lisp_Object v148 = stack[-6];
        popv(12);
        return cons(v148, v127);
    }

v141:
    v127 = stack[-1];
    goto v142;

v140:
    v127 = qvalue(elt(env, 1)); /* nil */
    goto v147;

v137:
    v127 = stack[-5];
    fn = elt(env, 6); /* indordn */
    v127 = (*qfn1(fn))(qenv(fn), v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    goto v138;

v14:
    v127 = qvalue(elt(env, 1)); /* nil */
    goto v5;

v129:
    v128 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-11];
    v127 = qcar(v127);
    goto v5;

v84:
    v127 = qvalue(elt(env, 1)); /* nil */
    goto v66;
/* error exit handlers */
v130:
    popv(12);
    return nil;
}



/* Code for ev!-edgeloop */

static Lisp_Object CC_evKedgeloop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v26, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-edgeloop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v149 = v1;
    v26 = v0;
/* end of prologue */
    v83 = qvalue(elt(env, 1)); /* ndim!* */
    v26 = qcar(v26);
    v149 = Lassoc(nil, v26, v149);
    v149 = qcdr(v149);
    {
        fn = elt(env, 2); /* binc */
        return (*qfn2(fn))(qenv(fn), v83, v149);
    }
}



/* Code for fs!:prin!: */

static Lisp_Object CC_fsTprinT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin:");
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
    v42 = elt(env, 1); /* "[" */
    fn = elt(env, 3); /* prin2!* */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-1];
    v42 = stack[0];
    v42 = qcdr(v42);
    fn = elt(env, 4); /* fs!:prin */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-1];
    v42 = elt(env, 2); /* "]" */
    {
        popv(2);
        fn = elt(env, 3); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v42);
    }
/* error exit handlers */
v116:
    popv(2);
    return nil;
}



/* Code for st_extract_symcells1 */

static Lisp_Object MS_CDECL CC_st_extract_symcells1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v35, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v50, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_extract_symcells1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_extract_symcells1");
#endif
    if (stack >= stacklimit)
    {
        push3(v35,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v35);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v35;
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    v163 = stack[0];
    v163 = qcdr(v163);
    v163 = qcar(v163);
    fn = elt(env, 3); /* listp */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    if (v163 == nil) goto v37;
    v163 = stack[0];
    stack[-6] = qcar(v163);
    v163 = stack[0];
    v163 = qcdr(v163);
    stack[-3] = v163;
    v163 = stack[-3];
    if (v163 == nil) goto v166;
    v163 = stack[-3];
    v163 = qcar(v163);
    v164 = v163;
    v50 = stack[-5];
    v163 = stack[-4];
    v163 = CC_st_extract_symcells1(env, 3, v164, v50, v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    v50 = v163;
    v50 = qcdr(v50);
    v50 = qcar(v50);
    stack[-5] = v50;
    v50 = v163;
    v50 = qcdr(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    stack[-4] = v50;
    v50 = v163;
    v50 = qcar(v50);
    if (is_number(v50)) goto v6;
    v163 = qcar(v163);
    goto v167;

v167:
    v163 = ncons(v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    stack[-1] = v163;
    stack[-2] = v163;
    goto v40;

v40:
    v163 = stack[-3];
    v163 = qcdr(v163);
    stack[-3] = v163;
    v163 = stack[-3];
    if (v163 == nil) goto v168;
    stack[0] = stack[-1];
    v163 = stack[-3];
    v163 = qcar(v163);
    v164 = v163;
    v50 = stack[-5];
    v163 = stack[-4];
    v163 = CC_st_extract_symcells1(env, 3, v164, v50, v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    v50 = v163;
    v50 = qcdr(v50);
    v50 = qcar(v50);
    stack[-5] = v50;
    v50 = v163;
    v50 = qcdr(v50);
    v50 = qcdr(v50);
    v50 = qcar(v50);
    stack[-4] = v50;
    v50 = v163;
    v50 = qcar(v50);
    if (is_number(v50)) goto v169;
    v163 = qcar(v163);
    goto v55;

v55:
    v163 = ncons(v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    v163 = Lrplacd(nil, stack[0], v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    v163 = stack[-1];
    v163 = qcdr(v163);
    stack[-1] = v163;
    goto v40;

v169:
    v50 = elt(env, 2); /* !* */
    v163 = qcar(v163);
    v163 = list2(v50, v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    goto v55;

v168:
    v163 = stack[-2];
    goto v33;

v33:
    v163 = cons(stack[-6], v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v164 = v163;
    v50 = stack[-5];
    v163 = stack[-4];
    popv(8);
    return list3(v164, v50, v163);

v6:
    v50 = elt(env, 2); /* !* */
    v163 = qcar(v163);
    v163 = list2(v50, v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    goto v167;

v166:
    v163 = qvalue(elt(env, 1)); /* nil */
    goto v33;

v37:
    stack[-1] = stack[-4];
    v50 = stack[0];
    v163 = stack[-5];
    stack[0] = cons(v50, v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-7];
    v163 = stack[-4];
    v163 = add1(v163);
    nil = C_nil;
    if (exception_pending()) goto v165;
    {
        Lisp_Object v170 = stack[-1];
        Lisp_Object v171 = stack[0];
        popv(8);
        return list3(v170, v171, v163);
    }
/* error exit handlers */
v165:
    popv(8);
    return nil;
}



/* Code for eval_uni_poly */

static Lisp_Object CC_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v176, v133, v168;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eval_uni_poly");
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
    v176 = stack[-2];
    if (!consp(v176)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v176 = stack[-2];
    v176 = qcar(v176);
    v176 = qcdr(v176);
    v168 = v176;
    v176 = stack[-2];
    v176 = qcar(v176);
    v176 = qcar(v176);
    v176 = qcdr(v176);
    v133 = v176;
    v176 = stack[-2];
    v176 = qcdr(v176);
    stack[-2] = v176;
    goto v124;

v124:
    v176 = stack[-2];
    if (!consp(v176)) goto v177;
    stack[-3] = v168;
    stack[0] = stack[-1];
    v176 = stack[-2];
    v176 = qcar(v176);
    v176 = qcar(v176);
    v176 = qcdr(v176);
    v176 = difference2(v133, v176);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v176 = Lexpt(nil, stack[0], v176);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v133 = times2(stack[-3], v176);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v176 = stack[-2];
    v176 = qcar(v176);
    v176 = qcdr(v176);
    v176 = plus2(v133, v176);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v168 = v176;
    v176 = stack[-2];
    v176 = qcar(v176);
    v176 = qcar(v176);
    v176 = qcdr(v176);
    v133 = v176;
    v176 = stack[-2];
    v176 = qcdr(v176);
    stack[-2] = v176;
    goto v124;

v177:
    stack[0] = v168;
    v176 = stack[-1];
    v176 = Lexpt(nil, v176, v133);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v176 = times2(stack[0], v176);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v168 = v176;
    v176 = stack[-2];
    if (v176 == nil) { popv(5); return onevalue(v168); }
    v133 = v168;
    v176 = stack[-2];
    v176 = plus2(v133, v176);
    nil = C_nil;
    if (exception_pending()) goto v4;
    v168 = v176;
    { popv(5); return onevalue(v168); }
/* error exit handlers */
v4:
    popv(5);
    return nil;
}



/* Code for domainp_list */

static Lisp_Object CC_domainp_list(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v160;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domainp_list");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v161 = v0;
/* end of prologue */

v178:
    v160 = v161;
    v160 = (v160 == nil ? lisp_true : nil);
    if (!(v160 == nil)) return onevalue(v160);
    v160 = v161;
    v160 = qcar(v160);
    if (!consp(v160)) goto v84;
    v160 = v161;
    v160 = qcar(v160);
    v160 = qcar(v160);
    if (!consp(v160)) goto v84;
    v161 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v161);

v84:
    v161 = qcdr(v161);
    goto v178;
}



/* Code for rl_fvarl */

static Lisp_Object CC_rl_fvarl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_fvarl");
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
    v116 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_fvarl!* */
    v116 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    {
        Lisp_Object v66 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v66, v116);
    }
/* error exit handlers */
v73:
    popv(2);
    return nil;
}



/* Code for mktag */

static Lisp_Object MS_CDECL CC_mktag(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v35, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktag");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktag");
#endif
    if (stack >= stacklimit)
    {
        push3(v35,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v35);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v35;
    stack[-2] = v1;
    v6 = v0;
/* end of prologue */
    v7 = v6;
    if (v7 == nil) goto v93;
    v7 = v6;
    if (!consp(v7)) goto v41;
    v7 = v6;
    v56 = qcar(v7);
    v7 = elt(env, 2); /* texprec */
    v7 = get(v56, v7);
    env = stack[-4];
    if (!(v7 == nil)) goto v83;
    v7 = (Lisp_Object)15985; /* 999 */
    goto v83;

v83:
    stack[-3] = v7;
    v7 = v6;
    v56 = qcar(v7);
    v7 = qcdr(v6);
    v6 = stack[-3];
    fn = elt(env, 5); /* makefunc */
    v6 = (*qfnn(fn))(qenv(fn), 3, v56, v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    stack[0] = v6;
    v6 = stack[-1];
    if (v6 == nil) goto v182;
    v7 = stack[-2];
    v6 = stack[-3];
    if (!(equal(v7, v6))) goto v182;

v9:
    v7 = elt(env, 3); /* !\!( */
    v6 = stack[0];
    stack[0] = cons(v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    v6 = elt(env, 4); /* !\!) */
    v6 = ncons(v6);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-4];
    v6 = Lnconc(nil, stack[0], v6);
    nil = C_nil;
    if (exception_pending()) goto v120;
    stack[0] = v6;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v182:
    v7 = stack[-3];
    v6 = stack[-2];
    v6 = (Lisp_Object)lessp2(v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v120;
    v6 = v6 ? lisp_true : nil;
    env = stack[-4];
    if (v6 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v9;

v41:
    {
        popv(5);
        fn = elt(env, 6); /* texexplode */
        return (*qfn1(fn))(qenv(fn), v6);
    }

v93:
    v6 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v6); }
/* error exit handlers */
v120:
    popv(5);
    return nil;
}



/* Code for get_dimension_in */

static Lisp_Object CC_get_dimension_in(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_dimension_in");
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
    v66 = v0;
/* end of prologue */
    v69 = elt(env, 1); /* id */
    fn = elt(env, 2); /* get_rep_matrix_in */
    v66 = (*qfn2(fn))(qenv(fn), v69, v66);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    fn = elt(env, 3); /* mk!+trace */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* change!+sq!+to!+int */
        return (*qfn1(fn))(qenv(fn), v66);
    }
/* error exit handlers */
v67:
    popv(1);
    return nil;
}



/* Code for iv_cutcongs1 */

static Lisp_Object CC_iv_cutcongs1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iv_cutcongs1");
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
    v70 = stack[0];
    if (v70 == nil) goto v30;
    v129 = stack[-1];
    v70 = stack[0];
    v70 = qcar(v70);
    fn = elt(env, 3); /* iv_cutcongs2 */
    v70 = (*qfn2(fn))(qenv(fn), v129, v70);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    if (v70 == nil) goto v124;
    v70 = stack[0];
    v70 = qcdr(v70);
    stack[0] = v70;
    goto v25;

v124:
    v70 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v70); }

v30:
    v70 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v70); }
/* error exit handlers */
v184:
    popv(3);
    return nil;
}



/* Code for integralir */

static Lisp_Object MS_CDECL CC_integralir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "integralir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for integralir");
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
    v167 = qvalue(elt(env, 1)); /* atts */
    v63 = elt(env, 2); /* name */
    fn = elt(env, 7); /* find */
    v63 = (*qfn2(fn))(qenv(fn), v167, v63);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    v63 = Lintern(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    stack[-1] = v63;
    v63 = elt(env, 3); /* (bvar x 1) */
    v63 = ncons(v63);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    stack[0] = v63;
    v167 = stack[-1];
    v63 = elt(env, 5); /* defint */
    if (!(v167 == v63)) goto v149;
    fn = elt(env, 8); /* lex */
    v63 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v63 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    goto v149;

v149:
    fn = elt(env, 8); /* lex */
    v63 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v63 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    stack[-2] = v63;
    v63 = stack[-2];
    v63 = Lconsp(nil, v63);
    env = stack[-3];
    if (v63 == nil) goto v185;
    v63 = stack[-2];
    v167 = qcar(v63);
    v63 = elt(env, 6); /* lambda */
    if (!(v167 == v63)) goto v185;
    v63 = stack[-2];
    fn = elt(env, 10); /* lambdavar */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    stack[0] = v63;
    v63 = stack[-2];
    fn = elt(env, 11); /* lambdafun */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    stack[-2] = v63;
    goto v185;

v185:
    v167 = stack[-1];
    v63 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = list2(v167, v63);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    v63 = stack[-2];
    v63 = ncons(v63);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-3];
    v63 = Lappend(nil, stack[0], v63);
    nil = C_nil;
    if (exception_pending()) goto v174;
    {
        Lisp_Object v64 = stack[-1];
        popv(4);
        return Lappend(nil, v64, v63);
    }
/* error exit handlers */
v174:
    popv(4);
    return nil;
}



/* Code for nestzerop!: */

static Lisp_Object CC_nestzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nestzerop:");
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
    v84 = v0;
/* end of prologue */
    v38 = v84;
    v38 = integerp(v38);
    if (v38 == nil) goto v41;
    v38 = v84;
    fn = elt(env, 1); /* simp */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    errexit();
    goto v36;

v36:
    v38 = qcar(v38);
    v38 = (v38 == nil ? lisp_true : nil);
    return onevalue(v38);

v41:
    v38 = v84;
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    goto v36;
}



/* Code for latexprint */

static Lisp_Object CC_latexprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for latexprint");
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
    fn = elt(env, 1); /* prinlabegin */
    v93 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-1];
    v93 = stack[0];
    fn = elt(env, 2); /* latexprin */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* prinlaend */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v179:
    popv(2);
    return nil;
}



/* Code for force!-to!-dm */

static Lisp_Object CC_forceKtoKdm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190, v191, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for force-to-dm");
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
    v191 = v0;
/* end of prologue */

v152:
    v190 = v191;
    if (!consp(v190)) goto v179;
    v190 = v191;
    v190 = qcar(v190);
    if (!consp(v190)) goto v179;
    v190 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* prepf1 */
    v190 = (*qfn2(fn))(qenv(fn), v191, v190);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v191 = v190;
    v190 = v191;
    if (v190 == nil) goto v162;
    v190 = v191;
    fn = elt(env, 8); /* replus */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    v191 = v190;
    goto v37;

v37:
    v190 = elt(env, 2); /* "number" */
    {
        popv(2);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v191, v190);
    }

v162:
    v190 = (Lisp_Object)1; /* 0 */
    v191 = v190;
    goto v37;

v179:
    v190 = v191;
    if (v190 == nil) goto v32;
    v190 = v191;
    if (is_number(v190)) goto v192;
    v190 = v191;
    v190 = Lconsp(nil, v190);
    env = stack[-1];
    if (v190 == nil) goto v9;
    v190 = v191;
    v109 = qcar(v190);
    v190 = qvalue(elt(env, 3)); /* dmode!* */
    if (equal(v109, v190)) { popv(2); return onevalue(v191); }
    else goto v9;

v9:
    v190 = v191;
    v190 = Lconsp(nil, v190);
    env = stack[-1];
    if (v190 == nil) goto v167;
    v190 = v191;
    v109 = qcar(v190);
    v190 = qvalue(elt(env, 3)); /* dmode!* */
    v190 = get(v109, v190);
    env = stack[-1];
    goto v63;

v63:
    v109 = v190;
    v190 = v109;
    if (v190 == nil) goto v20;
    stack[0] = v109;
    v190 = v191;
    v190 = ncons(v190);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    {
        Lisp_Object v54 = stack[0];
        popv(2);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v54, v190);
    }

v20:
    v190 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v190 == nil)) goto v27;
    v190 = elt(env, 6); /* "conversion error with " */
    v190 = list2(v190, v191);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    fn = elt(env, 11); /* lprie */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    goto v27;

v27:
    v190 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v110;
    v190 = nil;
    { popv(2); return onevalue(v190); }

v167:
    v190 = qvalue(elt(env, 1)); /* nil */
    goto v63;

v192:
    v109 = qvalue(elt(env, 3)); /* dmode!* */
    v190 = elt(env, 4); /* i2d */
    stack[0] = get(v109, v190);
    env = stack[-1];
    v190 = v191;
    v190 = ncons(v190);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    {
        Lisp_Object v55 = stack[0];
        popv(2);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v55, v190);
    }

v32:
    v190 = (Lisp_Object)1; /* 0 */
    v191 = v190;
    goto v152;
/* error exit handlers */
v110:
    popv(2);
    return nil;
}



/* Code for markedvarp */

static Lisp_Object CC_markedvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for markedvarp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */
    v116 = elt(env, 1); /* !*marked!* */
        return Lflagp(nil, v41, v116);
}



/* Code for indordlp */

static Lisp_Object CC_indordlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v189, v188, v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v188 = v1;
    v8 = v0;
/* end of prologue */

v25:
    v189 = v8;
    if (v189 == nil) goto v179;
    v189 = v188;
    if (v189 == nil) goto v72;
    v189 = v8;
    v9 = qcar(v189);
    v189 = v188;
    v189 = qcar(v189);
    if (equal(v9, v189)) goto v67;
    v189 = v8;
    v189 = qcar(v189);
    if (!consp(v189)) goto v162;
    v189 = v188;
    v189 = qcar(v189);
    if (!consp(v189)) goto v192;
    v189 = v8;
    v189 = qcar(v189);
    v189 = qcdr(v189);
    v189 = qcar(v189);
    v188 = qcar(v188);
    v188 = qcdr(v188);
    v188 = qcar(v188);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v189, v188);
    }

v192:
    v189 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v189);

v162:
    v189 = v188;
    v189 = qcar(v189);
    if (!consp(v189)) goto v34;
    v189 = qvalue(elt(env, 2)); /* t */
    return onevalue(v189);

v34:
    v189 = v8;
    v189 = qcar(v189);
    v188 = qcar(v188);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v189, v188);
    }

v67:
    v189 = v8;
    v189 = qcdr(v189);
    v8 = v189;
    v189 = v188;
    v189 = qcdr(v189);
    v188 = v189;
    goto v25;

v72:
    v189 = qvalue(elt(env, 2)); /* t */
    return onevalue(v189);

v179:
    v189 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v189);
}



/* Code for find_bubles1 */

static Lisp_Object CC_find_bubles1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v193, v162, v70, v129, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v1;
    v193 = v0;
/* end of prologue */
    v71 = qvalue(elt(env, 1)); /* nil */
    v162 = v193;
    v129 = qcar(v162);
    v70 = qvalue(elt(env, 1)); /* nil */
    v162 = v193;
    v162 = qcdr(v162);
    v162 = qcar(v162);
    v193 = qcdr(v193);
    v193 = qcdr(v193);
    v193 = qcar(v193);
    {
        fn = elt(env, 2); /* select_bubles */
        return (*qfnn(fn))(qenv(fn), 6, v71, v129, v70, v162, v193, v30);
    }
}



/* Code for subsq */

static Lisp_Object CC_subsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsq");
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
    v13 = stack[-1];
    v11 = qcar(v13);
    v13 = stack[0];
    fn = elt(env, 4); /* subf */
    v13 = (*qfn2(fn))(qenv(fn), v11, v13);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    stack[-2] = v13;
    v13 = stack[-1];
    v11 = qcdr(v13);
    v13 = stack[0];
    fn = elt(env, 4); /* subf */
    v13 = (*qfn2(fn))(qenv(fn), v11, v13);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    stack[-1] = v13;
    v13 = stack[-1];
    fn = elt(env, 5); /* subs2!* */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    v13 = qcar(v13);
    if (!(v13 == nil)) goto v65;
    v13 = stack[-2];
    fn = elt(env, 5); /* subs2!* */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    v13 = qcar(v13);
    if (v13 == nil) goto v129;
    v13 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v13 == nil)) goto v15;
    v13 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 6); /* lprie */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    goto v15;

v15:
    v13 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    goto v65;

v65:
    stack[0] = stack[-2];
    v13 = stack[-1];
    fn = elt(env, 7); /* invsq */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    {
        Lisp_Object v189 = stack[0];
        popv(4);
        fn = elt(env, 8); /* multsq */
        return (*qfn2(fn))(qenv(fn), v189, v13);
    }

v129:
    v13 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v13 == nil)) goto v33;
    v13 = elt(env, 2); /* "0/0 formed" */
    fn = elt(env, 6); /* lprie */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    goto v33;

v33:
    v13 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-3];
    goto v65;
/* error exit handlers */
v177:
    popv(4);
    return nil;
}



/* Code for groeb!=testb */

static Lisp_Object CC_groebMtestb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testb");
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
    v51 = stack[-1];
    fn = elt(env, 2); /* mo_comp */
    v4 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v51 = stack[0];
    v51 = qcar(v51);
    if (equal(v4, v51)) goto v149;
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v51); }

v149:
    stack[-2] = stack[-1];
    v4 = stack[0];
    v51 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v51 = (*qfn2(fn))(qenv(fn), v4, v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v51 = qcar(v51);
    fn = elt(env, 4); /* mo_divides!? */
    v51 = (*qfn2(fn))(qenv(fn), stack[-2], v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    if (v51 == nil) goto v37;
    v4 = stack[0];
    v51 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 3); /* pnth */
    v51 = (*qfn2(fn))(qenv(fn), v4, v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v51 = qcar(v51);
    fn = elt(env, 5); /* bas_dpoly */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    fn = elt(env, 6); /* dp_lmon */
    v4 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v51 = stack[-1];
    fn = elt(env, 7); /* mo_lcm */
    stack[-2] = (*qfn2(fn))(qenv(fn), v4, v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v4 = stack[0];
    v51 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v51 = (*qfn2(fn))(qenv(fn), v4, v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v51 = qcar(v51);
    fn = elt(env, 8); /* mo_equal!? */
    v51 = (*qfn2(fn))(qenv(fn), stack[-2], v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    if (v51 == nil) goto v7;
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v51); }

v7:
    v4 = stack[0];
    v51 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 3); /* pnth */
    v51 = (*qfn2(fn))(qenv(fn), v4, v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v51 = qcar(v51);
    fn = elt(env, 5); /* bas_dpoly */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    fn = elt(env, 6); /* dp_lmon */
    v4 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v51 = stack[-1];
    fn = elt(env, 7); /* mo_lcm */
    stack[-1] = (*qfn2(fn))(qenv(fn), v4, v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v4 = stack[0];
    v51 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v51 = (*qfn2(fn))(qenv(fn), v4, v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v51 = qcar(v51);
    fn = elt(env, 8); /* mo_equal!? */
    v51 = (*qfn2(fn))(qenv(fn), stack[-1], v51);
    nil = C_nil;
    if (exception_pending()) goto v20;
    v51 = (v51 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v51); }

v37:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v51); }
/* error exit handlers */
v20:
    popv(4);
    return nil;
}



/* Code for monic */

static Lisp_Object CC_monic(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monic");
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
    v62 = stack[-3];
    v62 = Lreverse(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-3] = v62;
    v62 = qvalue(elt(env, 1)); /* varlist */
    v62 = Llength(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-1] = v62;
    v62 = (Lisp_Object)17; /* 1 */
    stack[0] = v62;
    goto v83;

v83:
    v51 = stack[-1];
    v62 = stack[0];
    v62 = difference2(v51, v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v62 = Lminusp(nil, v62);
    env = stack[-5];
    if (v62 == nil) goto v71;
    v62 = qvalue(elt(env, 1)); /* varlist */
    v62 = qcdr(v62);
    stack[-3] = v62;
    v62 = stack[-3];
    if (v62 == nil) goto v189;
    v62 = (Lisp_Object)1; /* 0 */
    v62 = ncons(v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-1] = v62;
    stack[-2] = v62;
    goto v11;

v11:
    v62 = stack[-3];
    v62 = qcdr(v62);
    stack[-3] = v62;
    v62 = stack[-3];
    if (v62 == nil) goto v6;
    stack[0] = stack[-1];
    v62 = (Lisp_Object)1; /* 0 */
    v62 = ncons(v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v62 = Lrplacd(nil, stack[0], v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v62 = stack[-1];
    v62 = qcdr(v62);
    stack[-1] = v62;
    goto v11;

v6:
    v62 = stack[-2];
    goto v10;

v10:
    v62 = (equal(stack[-4], v62) ? lisp_true : nil);
    { popv(6); return onevalue(v62); }

v189:
    v62 = qvalue(elt(env, 2)); /* nil */
    goto v10;

v71:
    v51 = stack[0];
    v62 = stack[-2];
    if (equal(v51, v62)) goto v162;
    v51 = stack[-3];
    v62 = stack[0];
    fn = elt(env, 3); /* pnth */
    v62 = (*qfn2(fn))(qenv(fn), v51, v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v51 = qcar(v62);
    v62 = stack[-4];
    v62 = cons(v51, v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-4] = v62;
    goto v162;

v162:
    v62 = stack[0];
    v62 = add1(v62);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[0] = v62;
    goto v83;
/* error exit handlers */
v21:
    popv(6);
    return nil;
}



/* Code for extract_numid */

static Lisp_Object CC_extract_numid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extract_numid");
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

v178:
    v71 = stack[0];
    if (v71 == nil) goto v152;
    v71 = stack[0];
    v71 = qcar(v71);
    fn = elt(env, 2); /* !*id2num */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-2];
    v197 = v71;
    v71 = v197;
    if (v71 == nil) goto v30;
    stack[-1] = v197;
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = CC_extract_numid(env, v71);
    nil = C_nil;
    if (exception_pending()) goto v125;
    {
        Lisp_Object v126 = stack[-1];
        popv(3);
        return cons(v126, v71);
    }

v30:
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v178;

v152:
    v71 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v71); }
/* error exit handlers */
v125:
    popv(3);
    return nil;
}



/* Code for can_rep_cell */

static Lisp_Object CC_can_rep_cell(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v83, v183;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for can_rep_cell");
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
    v183 = v1;
    v26 = v0;
/* end of prologue */
    v26 = qcdr(v26);
    v83 = qcar(v26);
    v26 = (Lisp_Object)17; /* 1 */
    stack[0] = *(Lisp_Object *)((char *)v83 + (CELL-TAG_VECTOR) + ((int32_t)v26/(16/CELL)));
    v26 = v183;
    v26 = sub1(v26);
    nil = C_nil;
    if (exception_pending()) goto v160;
    v26 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v26/(16/CELL)));
    { popv(1); return onevalue(v26); }
/* error exit handlers */
v160:
    popv(1);
    return nil;
}



/* Code for max!-degree */

static Lisp_Object CC_maxKdegree(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v65, v10, v175;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for max-degree");
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
    v65 = v1;
    v10 = v0;
/* end of prologue */

v93:
    v181 = v10;
    if (!consp(v181)) { popv(2); return onevalue(v65); }
    v181 = v10;
    v181 = qcar(v181);
    if (!consp(v181)) { popv(2); return onevalue(v65); }
    v175 = v65;
    v181 = v10;
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = qcdr(v181);
    if (((int32_t)(v175)) > ((int32_t)(v181))) goto v37;
    v181 = v10;
    v181 = qcdr(v181);
    stack[0] = v181;
    v181 = v10;
    v181 = qcar(v181);
    v181 = qcdr(v181);
    v65 = v10;
    v65 = qcar(v65);
    v65 = qcar(v65);
    v65 = qcdr(v65);
    v181 = CC_maxKdegree(env, v181, v65);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-1];
    v65 = v181;
    v181 = stack[0];
    v10 = v181;
    goto v93;

v37:
    v181 = v10;
    v181 = qcdr(v181);
    stack[0] = v181;
    v181 = v10;
    v181 = qcar(v181);
    v181 = qcdr(v181);
    v181 = CC_maxKdegree(env, v181, v65);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-1];
    v65 = v181;
    v181 = stack[0];
    v10 = v181;
    goto v93;
/* error exit handlers */
v185:
    popv(2);
    return nil;
}



/* Code for lto_insert */

static Lisp_Object CC_lto_insert(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v117, v5, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_insert");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v117 = v1;
    v5 = v0;
/* end of prologue */
    v30 = v5;
    v124 = v117;
    v124 = Lmember(nil, v30, v124);
    if (!(v124 == nil)) return onevalue(v117);
    v124 = v5;
    return cons(v124, v117);
}



/* Code for simpx1 */

static Lisp_Object MS_CDECL CC_simpx1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v35, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v316, v317;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpx1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpx1");
#endif
    if (stack >= stacklimit)
    {
        push3(v35,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v35);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v35;
    stack[-1] = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-6] = nil;
    v316 = stack[-4];
    v315 = elt(env, 1); /* !*minus!* */
    if (!consp(v316)) goto v72;
    v316 = qcar(v316);
    if (!(v316 == v315)) goto v72;
    v316 = stack[-1];
    v315 = (Lisp_Object)17; /* 1 */
    if (!(v316 == v315)) goto v196;
    v315 = stack[-3];
    v315 = integerp(v315);
    if (v315 == nil) goto v196;
    v316 = stack[-3];
    v315 = (Lisp_Object)33; /* 2 */
    v316 = Cremainder(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = (Lisp_Object)1; /* 0 */
    if (!(v316 == v315)) goto v196;

v21:
    stack[-6] = elt(env, 3); /* expt */
    stack[-5] = elt(env, 4); /* i */
    stack[-2] = elt(env, 2); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v316 = stack[-3];
    v315 = (Lisp_Object)33; /* 2 */
    v315 = quot2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = list3(stack[-2], stack[0], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = list3(stack[-6], stack[-5], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = stack[-4];
    v315 = qcdr(v315);
    stack[-2] = qcar(v315);
    v317 = elt(env, 2); /* quotient */
    v316 = stack[-1];
    v315 = stack[-3];
    v315 = list3(v317, v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = list2(stack[-2], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    {
        Lisp_Object v319 = stack[0];
        popv(8);
        fn = elt(env, 22); /* multsq */
        return (*qfn2(fn))(qenv(fn), v319, v315);
    }

v196:
    v316 = stack[-3];
    v315 = (Lisp_Object)17; /* 1 */
    if (!(v316 == v315)) goto v320;
    v316 = stack[-1];
    v315 = elt(env, 2); /* quotient */
    if (!consp(v316)) goto v320;
    v316 = qcar(v316);
    if (!(v316 == v315)) goto v320;
    v315 = stack[-1];
    v315 = qcdr(v315);
    v316 = qcar(v315);
    v315 = (Lisp_Object)17; /* 1 */
    if (!(v316 == v315)) goto v320;
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v315 = qcar(v315);
    v315 = integerp(v315);
    if (v315 == nil) goto v320;
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v316 = qcar(v315);
    v315 = (Lisp_Object)33; /* 2 */
    v316 = Cremainder(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = (Lisp_Object)1; /* 0 */
    if (v316 == v315) goto v21;
    else goto v320;

v320:
    v316 = stack[-1];
    v315 = (Lisp_Object)17; /* 1 */
    if (!(v316 == v315)) goto v72;
    v315 = stack[-3];
    v315 = integerp(v315);
    if (v315 == nil) goto v72;
    v315 = stack[-4];
    v315 = qcdr(v315);
    stack[0] = qcar(v315);
    v317 = elt(env, 2); /* quotient */
    v316 = stack[-1];
    v315 = stack[-3];
    v315 = list3(v317, v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = list2(stack[0], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[0] = v315;
    v315 = stack[0];
    v315 = qcar(v315);
    fn = elt(env, 23); /* negf */
    v316 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v315 = stack[0];
    v315 = qcdr(v315);
    popv(8);
    return cons(v316, v315);

v72:
    v315 = stack[-1];
    if (!(is_number(v315))) goto v102;
    v315 = stack[-3];
    if (!(is_number(v315))) goto v102;

v42:
    v315 = stack[-1];
    if (is_number(v315)) goto v321;
    v315 = stack[-1];
    if (!consp(v315)) goto v322;
    v315 = stack[-1];
    v316 = qcar(v315);
    v315 = elt(env, 11); /* minus */
    if (v316 == v315) goto v323;
    v315 = stack[-1];
    v316 = qcar(v315);
    v315 = elt(env, 12); /* plus */
    if (!(v316 == v315)) goto v324;
    v315 = qvalue(elt(env, 13)); /* !*expandexpt */
    if (v315 == nil) goto v324;
    v316 = (Lisp_Object)17; /* 1 */
    v315 = (Lisp_Object)17; /* 1 */
    v315 = cons(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-5] = v315;
    v315 = stack[-1];
    v315 = qcdr(v315);
    stack[-2] = v315;
    goto v325;

v325:
    v315 = stack[-2];
    if (v315 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v315 = stack[-2];
    v315 = qcar(v315);
    stack[-1] = stack[-4];
    stack[0] = elt(env, 2); /* quotient */
    v316 = stack[-6];
    if (v316 == nil) goto v326;
    v316 = elt(env, 11); /* minus */
    v315 = list2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v316 = v315;
    goto v327;

v327:
    v315 = stack[-3];
    v315 = list3(stack[0], v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = list2(stack[-1], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v316 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = stack[-5];
    fn = elt(env, 22); /* multsq */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-5] = v315;
    v315 = stack[-2];
    v315 = qcdr(v315);
    stack[-2] = v315;
    goto v325;

v326:
    v316 = v315;
    goto v327;

v324:
    v315 = stack[-1];
    v316 = qcar(v315);
    v315 = elt(env, 15); /* times */
    if (!(v316 == v315)) goto v328;
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcar(v315);
    v315 = integerp(v315);
    if (v315 == nil) goto v328;
    v315 = stack[-3];
    if (is_number(v315)) goto v329;
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcar(v315);
    stack[-5] = v315;
    goto v330;

v330:
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    if (v315 == nil) goto v331;
    v316 = elt(env, 15); /* times */
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v315 = cons(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    goto v332;

v332:
    stack[-1] = v315;
    goto v333;

v333:
    v315 = stack[-4];
    if (!(symbolp(v315))) goto v334;
    v316 = stack[-4];
    v315 = elt(env, 16); /* used!* */
    v315 = Lflagp(nil, v316, v315);
    env = stack[-7];
    if (!(v315 == nil)) goto v334;
    v315 = stack[-4];
    v316 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = elt(env, 16); /* used!* */
    v315 = Lflag(nil, v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    goto v334;

v334:
    v316 = stack[-4];
    v315 = elt(env, 17); /* (minus 1) */
    if (!(equal(v316, v315))) goto v335;
    v316 = stack[-3];
    v315 = (Lisp_Object)17; /* 1 */
    if (!(v316 == v315)) goto v335;
    v317 = elt(env, 18); /* difference */
    v316 = stack[-1];
    v315 = elt(env, 19); /* (quotient 1 2) */
    v315 = list3(v317, v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = qcar(v315);
    if (!(v315 == nil)) goto v335;
    v315 = elt(env, 4); /* i */
    fn = elt(env, 20); /* simp */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-4] = v315;
    v315 = stack[-6];
    if (v315 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v315 = stack[-4];
    v315 = qcar(v315);
    fn = elt(env, 23); /* negf */
    v316 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v315 = stack[-4];
    v315 = qcdr(v315);
    popv(8);
    return cons(v316, v315);

v335:
    stack[0] = elt(env, 3); /* expt */
    stack[-2] = stack[-4];
    v316 = stack[-3];
    v315 = (Lisp_Object)17; /* 1 */
    if (v316 == v315) goto v336;
    v317 = elt(env, 2); /* quotient */
    v316 = stack[-1];
    v315 = stack[-3];
    v315 = list3(v317, v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    goto v337;

v337:
    v315 = list3(stack[0], stack[-2], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-4] = v315;
    stack[0] = stack[-4];
    v315 = stack[-6];
    if (v315 == nil) goto v338;
    v315 = stack[-5];
    v315 = negate(v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    goto v339;

v339:
    {
        Lisp_Object v340 = stack[0];
        popv(8);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v340, v315);
    }

v338:
    v315 = stack[-5];
    goto v339;

v336:
    v315 = stack[-1];
    goto v337;

v331:
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v315 = qcar(v315);
    goto v332;

v329:
    v316 = stack[-3];
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcar(v315);
    v315 = Lgcd(nil, v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-5] = v315;
    v316 = stack[-3];
    v315 = stack[-5];
    v315 = quot2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-3] = v315;
    v315 = stack[-1];
    v315 = qcdr(v315);
    v316 = qcar(v315);
    v315 = stack[-5];
    v315 = quot2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-5] = v315;
    goto v330;

v328:
    v315 = stack[-1];
    v316 = qcar(v315);
    v315 = elt(env, 2); /* quotient */
    if (!(v316 == v315)) goto v341;
    v316 = stack[-3];
    v315 = (Lisp_Object)17; /* 1 */
    if (!(v316 == v315)) goto v341;
    v315 = qvalue(elt(env, 13)); /* !*expandexpt */
    if (v315 == nil) goto v341;
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcdr(v315);
    v315 = qcar(v315);
    stack[-3] = v315;
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcar(v315);
    stack[-1] = v315;
    goto v42;

v341:
    v315 = (Lisp_Object)17; /* 1 */
    stack[-5] = v315;
    goto v333;

v323:
    v315 = stack[-1];
    v315 = qcdr(v315);
    v315 = qcar(v315);
    stack[-1] = v315;
    goto v41;

v41:
    v315 = qvalue(elt(env, 6)); /* !*mcd */
    if (v315 == nil) goto v342;
    v317 = stack[-4];
    v316 = stack[-1];
    v315 = stack[-3];
    v315 = CC_simpx1(env, 3, v317, v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 25); /* invsq */
        return (*qfn1(fn))(qenv(fn), v315);
    }

v342:
    v315 = stack[-6];
    v315 = (v315 == nil ? lisp_true : nil);
    stack[-6] = v315;
    goto v42;

v322:
    v315 = (Lisp_Object)17; /* 1 */
    stack[-5] = v315;
    goto v333;

v321:
    v315 = stack[-1];
    v315 = Lminusp(nil, v315);
    env = stack[-7];
    if (v315 == nil) goto v88;
    v315 = stack[-1];
    v315 = negate(v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-1] = v315;
    goto v41;

v88:
    v315 = stack[-1];
    v315 = integerp(v315);
    if (v315 == nil) goto v343;
    v315 = stack[-3];
    v315 = integerp(v315);
    if (v315 == nil) goto v344;
    v315 = stack[-6];
    if (v315 == nil) goto v345;
    v315 = stack[-1];
    v315 = negate(v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-1] = v315;
    goto v345;

v345:
    v315 = stack[-1];
    stack[-5] = v315;
    v315 = qvalue(elt(env, 6)); /* !*mcd */
    if (v315 == nil) goto v346;
    v315 = stack[-4];
    v315 = integerp(v315);
    if (!(v315 == nil)) goto v347;
    v315 = qvalue(elt(env, 7)); /* !*notseparate */
    if (!(v315 == nil)) goto v346;

v347:
    stack[-2] = stack[-5];
    stack[0] = stack[-3];
    v316 = stack[-1];
    v315 = stack[-3];
    v315 = quot2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-1] = v315;
    v315 = times2(stack[0], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = difference2(stack[-2], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-5] = v315;
    v316 = stack[-5];
    v315 = (Lisp_Object)1; /* 0 */
    v315 = (Lisp_Object)lessp2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v315 = v315 ? lisp_true : nil;
    env = stack[-7];
    if (v315 == nil) goto v348;
    v315 = stack[-1];
    v315 = sub1(v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-1] = v315;
    v316 = stack[-5];
    v315 = stack[-3];
    v315 = plus2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-5] = v315;
    goto v348;

v348:
    v316 = stack[-4];
    v315 = stack[-1];
    v315 = list2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[0] = v315;
    v316 = stack[-5];
    v315 = (Lisp_Object)1; /* 0 */
    if (v316 == v315) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v316 = stack[-3];
    v315 = (Lisp_Object)33; /* 2 */
    if (!(v316 == v315)) goto v349;
    v315 = qvalue(elt(env, 8)); /* !*keepsqrts */
    if (v315 == nil) goto v349;
    stack[-1] = stack[0];
    v316 = elt(env, 9); /* sqrt */
    v315 = elt(env, 10); /* simpfn */
    stack[0] = get(v316, v315);
    env = stack[-7];
    v315 = stack[-4];
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = Lapply1(nil, stack[0], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    fn = elt(env, 22); /* multsq */
    v315 = (*qfn2(fn))(qenv(fn), stack[-1], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[0] = v315;
    v316 = stack[-5];
    v315 = (Lisp_Object)1; /* 0 */
    v315 = (Lisp_Object)lessp2(v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    v315 = v315 ? lisp_true : nil;
    env = stack[-7];
    if (v315 == nil) goto v350;
    v315 = stack[0];
    fn = elt(env, 25); /* invsq */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[0] = v315;
    v315 = stack[-5];
    v315 = negate(v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    stack[-5] = v315;
    goto v350;

v350:
    v316 = stack[0];
    v315 = stack[-5];
    {
        popv(8);
        fn = elt(env, 26); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v316, v315);
    }

v349:
    v315 = stack[-4];
    fn = elt(env, 27); /* simp!* */
    v316 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = stack[-3];
    fn = elt(env, 28); /* simprad */
    v316 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = stack[-5];
    fn = elt(env, 26); /* exptsq */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    {
        Lisp_Object v351 = stack[0];
        popv(8);
        fn = elt(env, 22); /* multsq */
        return (*qfn2(fn))(qenv(fn), v351, v315);
    }

v346:
    v315 = (Lisp_Object)1; /* 0 */
    stack[-1] = v315;
    goto v348;

v344:
    v315 = stack[-1];
    stack[-5] = v315;
    v315 = (Lisp_Object)17; /* 1 */
    stack[-1] = v315;
    goto v333;

v343:
    v315 = (Lisp_Object)17; /* 1 */
    stack[-5] = v315;
    goto v333;

v102:
    v316 = qvalue(elt(env, 5)); /* frlis!* */
    v315 = stack[-1];
    fn = elt(env, 29); /* smemqlp */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    if (!(v315 == nil)) goto v352;
    v316 = qvalue(elt(env, 5)); /* frlis!* */
    v315 = stack[-3];
    fn = elt(env, 29); /* smemqlp */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    if (v315 == nil) goto v42;
    else goto v352;

v352:
    stack[0] = elt(env, 3); /* expt */
    stack[-2] = stack[-4];
    v316 = stack[-3];
    v315 = (Lisp_Object)17; /* 1 */
    if (v316 == v315) goto v353;
    v317 = elt(env, 2); /* quotient */
    v316 = stack[-1];
    v315 = stack[-3];
    v315 = list3(v317, v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    goto v354;

v354:
    v316 = list3(stack[0], stack[-2], v315);
    nil = C_nil;
    if (exception_pending()) goto v318;
    env = stack[-7];
    v315 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v316, v315);
    }

v353:
    v315 = stack[-1];
    goto v354;
/* error exit handlers */
v318:
    popv(8);
    return nil;
}



/* Code for repartf */

static Lisp_Object CC_repartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v310, v311;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repartf");
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
    v311 = elt(env, 1); /* i */
    v310 = qvalue(elt(env, 2)); /* kord!* */
    v310 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v310; /* kord!* */
    v310 = stack[0];
    fn = elt(env, 5); /* reorder */
    v310 = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    stack[-2] = v310;
    v310 = stack[-2];
    if (!consp(v310)) goto v67;
    v310 = stack[-2];
    v310 = qcar(v310);
    if (!consp(v310)) goto v67;
    v310 = stack[-2];
    v310 = qcar(v310);
    v310 = qcar(v310);
    v311 = qcar(v310);
    v310 = elt(env, 1); /* i */
    if (v311 == v310) goto v189;
    v310 = stack[-2];
    v310 = qcar(v310);
    v311 = qcar(v310);
    v310 = (Lisp_Object)17; /* 1 */
    v310 = cons(v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    stack[0] = ncons(v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    v310 = stack[-2];
    v310 = qcar(v310);
    v310 = qcdr(v310);
    v310 = CC_repartf(env, v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    fn = elt(env, 6); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    v310 = stack[-2];
    v310 = qcdr(v310);
    v310 = CC_repartf(env, v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    fn = elt(env, 7); /* addf */
    v310 = (*qfn2(fn))(qenv(fn), stack[0], v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    goto v69;

v69:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v310); }

v189:
    v310 = stack[-2];
    v310 = qcdr(v310);
    v310 = CC_repartf(env, v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    goto v69;

v67:
    v310 = stack[-2];
    if (!consp(v310)) goto v160;
    v310 = stack[-2];
    v311 = qcar(v310);
    v310 = elt(env, 3); /* cmpxfn */
    v310 = get(v311, v310);
    env = stack[-4];
    if (v310 == nil) goto v158;
    v310 = stack[-2];
    stack[-1] = qcar(v310);
    v310 = stack[-2];
    v310 = qcdr(v310);
    stack[0] = qcar(v310);
    v310 = stack[-2];
    v311 = qcar(v310);
    v310 = elt(env, 4); /* i2d */
    v311 = get(v311, v310);
    env = stack[-4];
    v310 = (Lisp_Object)1; /* 0 */
    v310 = Lapply1(nil, v311, v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    v310 = qcdr(v310);
    v310 = qcar(v310);
    v310 = list2star(stack[-1], stack[0], v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    fn = elt(env, 8); /* int!-equiv!-chk */
    v310 = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    goto v69;

v158:
    v310 = stack[-2];
    goto v69;

v160:
    v310 = stack[-2];
    goto v69;
/* error exit handlers */
v80:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v155:
    popv(5);
    return nil;
}



/* Code for pasf_negateat */

static Lisp_Object CC_pasf_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v357, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_negateat");
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
    v357 = stack[0];
    v47 = elt(env, 1); /* true */
    if (v357 == v47) goto v124;
    v357 = stack[0];
    v47 = elt(env, 2); /* false */
    if (v357 == v47) goto v124;
    v357 = stack[0];
    v47 = elt(env, 1); /* true */
    if (v357 == v47) goto v39;
    v357 = stack[0];
    v47 = elt(env, 2); /* false */
    if (v357 == v47) goto v39;
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = Lconsp(nil, v47);
    env = stack[-1];
    if (v47 == nil) goto v132;
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = qcar(v47);
    v357 = v47;
    goto v33;

v33:
    v47 = elt(env, 3); /* (cong ncong) */
    v47 = Lmemq(nil, v357, v47);
    if (v47 == nil) goto v358;
    v357 = stack[0];
    v47 = elt(env, 1); /* true */
    if (v357 == v47) goto v31;
    v357 = stack[0];
    v47 = elt(env, 2); /* false */
    if (v357 == v47) goto v31;
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = Lconsp(nil, v47);
    env = stack[-1];
    if (v47 == nil) goto v311;
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = qcar(v47);
    goto v120;

v120:
    fn = elt(env, 4); /* pasf_lnegrel */
    v357 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = qcdr(v47);
    fn = elt(env, 5); /* pasf_mkop */
    v48 = (*qfn2(fn))(qenv(fn), v357, v47);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v47 = stack[0];
    v47 = qcdr(v47);
    v357 = qcar(v47);
    v47 = stack[0];
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = qcar(v47);
    popv(2);
    return list3(v48, v357, v47);

v311:
    v47 = stack[0];
    v47 = qcar(v47);
    goto v120;

v31:
    v47 = stack[0];
    goto v120;

v358:
    v357 = stack[0];
    v47 = elt(env, 1); /* true */
    if (v357 == v47) goto v78;
    v357 = stack[0];
    v47 = elt(env, 2); /* false */
    if (v357 == v47) goto v78;
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = Lconsp(nil, v47);
    env = stack[-1];
    if (v47 == nil) goto v359;
    v47 = stack[0];
    v47 = qcar(v47);
    v47 = qcar(v47);
    goto v153;

v153:
    fn = elt(env, 4); /* pasf_lnegrel */
    v48 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v47 = stack[0];
    v47 = qcdr(v47);
    v357 = qcar(v47);
    v47 = stack[0];
    v47 = qcdr(v47);
    v47 = qcdr(v47);
    v47 = qcar(v47);
    popv(2);
    return list3(v48, v357, v47);

v359:
    v47 = stack[0];
    v47 = qcar(v47);
    goto v153;

v78:
    v47 = stack[0];
    goto v153;

v132:
    v47 = stack[0];
    v47 = qcar(v47);
    v357 = v47;
    goto v33;

v39:
    v47 = stack[0];
    v357 = v47;
    goto v33;

v124:
    v357 = stack[0];
    v47 = elt(env, 2); /* false */
    if (v357 == v47) goto v161;
    v47 = elt(env, 2); /* false */
    { popv(2); return onevalue(v47); }

v161:
    v47 = elt(env, 1); /* true */
    { popv(2); return onevalue(v47); }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for ratpoly_sub */

static Lisp_Object MS_CDECL CC_ratpoly_sub(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v35, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v26, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ratpoly_sub");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_sub");
#endif
    if (stack >= stacklimit)
    {
        push3(v35,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v35);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v149 = v35;
    v26 = v1;
    v83 = v0;
/* end of prologue */
    stack[0] = v83;
    v149 = cons(v26, v149);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-1];
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-1];
    {
        Lisp_Object v160 = stack[0];
        popv(2);
        fn = elt(env, 1); /* subsq */
        return (*qfn2(fn))(qenv(fn), v160, v149);
    }
/* error exit handlers */
v161:
    popv(2);
    return nil;
}



/* Code for vdp_getprop */

static Lisp_Object CC_vdp_getprop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_getprop");
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
    v183 = v1;
    v161 = v0;
/* end of prologue */
    stack[0] = v183;
    v183 = v161;
    fn = elt(env, 2); /* vdp_plist */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    v183 = Latsoc(nil, stack[0], v183);
    v161 = v183;
    v183 = v161;
    if (v183 == nil) goto v149;
    v183 = v161;
    v183 = qcdr(v183);
    { popv(2); return onevalue(v183); }

v149:
    v183 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v183); }
/* error exit handlers */
v124:
    popv(2);
    return nil;
}



/* Code for impartsq */

static Lisp_Object CC_impartsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v174, v64, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartsq");
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
    v180 = stack[0];
    v180 = qcar(v180);
    fn = elt(env, 1); /* splitcomplex */
    stack[-1] = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v180 = stack[0];
    v180 = qcdr(v180);
    fn = elt(env, 1); /* splitcomplex */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v174 = stack[-1];
    v64 = v174;
    v6 = qcar(v64);
    v64 = qcdr(v174);
    v174 = v180;
    v174 = qcar(v174);
    v180 = qcdr(v180);
    stack[0] = v6;
    stack[-3] = v174;
    stack[-2] = v180;
    v174 = v64;
    v180 = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v174, v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v174 = stack[0];
    v180 = stack[-2];
    fn = elt(env, 2); /* multsq */
    v180 = (*qfn2(fn))(qenv(fn), v174, v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    stack[0] = v180;
    v180 = stack[0];
    v180 = qcar(v180);
    fn = elt(env, 3); /* negf */
    v174 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v180 = stack[0];
    v180 = qcdr(v180);
    v180 = cons(v174, v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-1], v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v174 = stack[-3];
    v180 = stack[-3];
    fn = elt(env, 2); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v174, v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    v174 = stack[-2];
    v180 = stack[-2];
    fn = elt(env, 2); /* multsq */
    v180 = (*qfn2(fn))(qenv(fn), v174, v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    v180 = (*qfn2(fn))(qenv(fn), stack[-1], v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    fn = elt(env, 5); /* invsq */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-4];
    {
        Lisp_Object v119 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v119, v180);
    }
/* error exit handlers */
v157:
    popv(5);
    return nil;
}



/* Code for transferrow1 */

static Lisp_Object CC_transferrow1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v166;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow1");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v166 = qvalue(elt(env, 2)); /* maxvar */
    v192 = stack[0];
    v192 = plus2(v166, v192);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-2];
    v166 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v192/(16/CELL)));
    v192 = (Lisp_Object)81; /* 5 */
    v192 = *(Lisp_Object *)((char *)v166 + (CELL-TAG_VECTOR) + ((int32_t)v192/(16/CELL)));
    if (v192 == nil) goto v184;
    v192 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v192); }

v184:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v166 = qvalue(elt(env, 2)); /* maxvar */
    v192 = stack[0];
    v192 = plus2(v166, v192);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v166 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v192/(16/CELL)));
    v192 = (Lisp_Object)49; /* 3 */
    v192 = *(Lisp_Object *)((char *)v166 + (CELL-TAG_VECTOR) + ((int32_t)v192/(16/CELL)));
    v192 = (is_number(v192) ? lisp_true : nil);
    { popv(3); return onevalue(v192); }
/* error exit handlers */
v195:
    popv(3);
    return nil;
}



/* Code for simpwedge */

static Lisp_Object CC_simpwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpwedge");
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
    v25 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitwedge */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v25);
    }
/* error exit handlers */
v93:
    popv(1);
    return nil;
}



/* Code for ratmean */

static Lisp_Object CC_ratmean(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v69, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratmean");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v66 = v1;
    v69 = v0;
/* end of prologue */
    v67 = v69;
    v69 = v66;
    v66 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* ratplusm */
        return (*qfnn(fn))(qenv(fn), 3, v67, v69, v66);
    }
}



/* Code for endofstmtp */

static Lisp_Object MS_CDECL CC_endofstmtp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v69;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endofstmtp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endofstmtp");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v69 = qvalue(elt(env, 1)); /* cursym!* */
    v66 = elt(env, 2); /* (!*semicol!* !*rsqbkt!* end) */
    v66 = Lmember(nil, v69, v66);
    if (v66 == nil) goto v152;
    v66 = qvalue(elt(env, 3)); /* t */
    return onevalue(v66);

v152:
    v66 = nil;
    return onevalue(v66);
}



/* Code for lndepends */

static Lisp_Object CC_lndepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lndepends");
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

v178:
    v70 = stack[-1];
    if (v70 == nil) goto v25;
    v70 = stack[-1];
    v129 = qcar(v70);
    v70 = stack[0];
    fn = elt(env, 2); /* ndepends */
    v70 = (*qfn2(fn))(qenv(fn), v129, v70);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    if (!(v70 == nil)) { popv(3); return onevalue(v70); }
    v70 = stack[-1];
    v129 = qcdr(v70);
    v70 = stack[0];
    stack[-1] = v129;
    stack[0] = v70;
    goto v178;

v25:
    v70 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v70); }
/* error exit handlers */
v184:
    popv(3);
    return nil;
}



/* Code for mk_binding */

static Lisp_Object CC_mk_binding(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_binding");
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
    v5 = stack[-1];
    v30 = qcar(v5);
    v5 = stack[0];
    fn = elt(env, 2); /* can_be_proved */
    v5 = (*qfn2(fn))(qenv(fn), v30, v5);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    if (v5 == nil) goto v25;
    v5 = stack[-1];
    v30 = qcdr(v5);
    v5 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* edge_bind */
        return (*qfn2(fn))(qenv(fn), v30, v5);
    }

v25:
    v5 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v70:
    popv(3);
    return nil;
}



/* Code for compactf1 */

static Lisp_Object MS_CDECL CC_compactf1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v35, Lisp_Object v36, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v32, v33, v34, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "compactf1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf1");
#endif
    if (stack >= stacklimit)
    {
        push4(v36,v35,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v35,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v36;
    stack[-1] = v35;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v32 = stack[-1];
    v126 = stack[0];
    fn = elt(env, 1); /* intersection */
    v126 = (*qfn2(fn))(qenv(fn), v32, v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-4];
    v32 = v126;
    if (v32 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v18 = stack[-3];
    v34 = stack[-2];
    v33 = stack[-1];
    v32 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); /* compactf11 */
        return (*qfnn(fn))(qenv(fn), 5, v18, v34, v33, v32, v126);
    }
/* error exit handlers */
v131:
    popv(5);
    return nil;
}



/* Code for baglistp */

static Lisp_Object CC_baglistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v70, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for baglistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v129 = v0;
/* end of prologue */
    v162 = v129;
    if (!consp(v162)) goto v152;
    v162 = v129;
    v70 = qcar(v162);
    v162 = elt(env, 2); /* list */
    v162 = (v70 == v162 ? lisp_true : nil);
    if (!(v162 == nil)) return onevalue(v162);
    v162 = v129;
    v162 = qcar(v162);
    v70 = elt(env, 3); /* bag */
        return Lflagp(nil, v162, v70);

v152:
    v162 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v162);
}



/* Code for proper!-simpsqrt */

static Lisp_Object CC_properKsimpsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for proper-simpsqrt");
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
    v71 = v0;
/* end of prologue */
    v129 = v71;
    v129 = qcdr(v129);
    if (v129 == nil) goto v25;
    v71 = elt(env, 1); /* "Wrong number of arguments to" */
    v129 = elt(env, 0); /* proper!-simpsqrt */
    v129 = list2(v71, v129);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[0];
    v71 = v129;
    v129 = v71;
    qvalue(elt(env, 2)) = v129; /* errmsg!* */
    v129 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v129 == nil)) goto v124;
    v129 = v71;
    fn = elt(env, 4); /* lprie */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[0];
    goto v124;

v124:
    v129 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[0];
    v129 = nil;
    goto v152;

v152:
    {
        popv(1);
        fn = elt(env, 5); /* simpsqrti */
        return (*qfn1(fn))(qenv(fn), v129);
    }

v25:
    v129 = v71;
    v129 = qcar(v129);
    goto v152;
/* error exit handlers */
v197:
    popv(1);
    return nil;
}



/* Code for ofsf_irl2atl */

static Lisp_Object MS_CDECL CC_ofsf_irl2atl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v35, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v132, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_irl2atl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_irl2atl");
#endif
    if (stack >= stacklimit)
    {
        push3(v35,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v35);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v35;
    v158 = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v158;
    goto v42;

v42:
    v158 = stack[-5];
    if (v158 == nil) goto v66;
    v158 = stack[-5];
    v158 = qcar(v158);
    v177 = stack[-4];
    v132 = v158;
    v158 = stack[-3];
    fn = elt(env, 2); /* ofsf_ir2atl */
    v158 = (*qfnn(fn))(qenv(fn), 3, v177, v132, v158);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-6];
    stack[-2] = v158;
    v158 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-6];
    stack[-1] = v158;
    v158 = stack[-5];
    v158 = qcdr(v158);
    stack[-5] = v158;
    v158 = stack[-1];
    if (!consp(v158)) goto v42;
    else goto v41;

v41:
    v158 = stack[-5];
    if (v158 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v158 = stack[-5];
    v158 = qcar(v158);
    v177 = stack[-4];
    v132 = v158;
    v158 = stack[-3];
    fn = elt(env, 2); /* ofsf_ir2atl */
    v158 = (*qfnn(fn))(qenv(fn), 3, v177, v132, v158);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-6];
    v158 = Lrplacd(nil, stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-6];
    v158 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v158 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-6];
    stack[-1] = v158;
    v158 = stack[-5];
    v158 = qcdr(v158);
    stack[-5] = v158;
    goto v41;

v66:
    v158 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v158); }
/* error exit handlers */
v63:
    popv(7);
    return nil;
}



/* Code for impartf */

static Lisp_Object CC_impartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v313, v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartf");
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
    v190 = elt(env, 1); /* i */
    v313 = qvalue(elt(env, 2)); /* kord!* */
    v313 = cons(v190, v313);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v313; /* kord!* */
    v313 = stack[0];
    fn = elt(env, 6); /* reorder */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[-2] = v313;
    v313 = stack[-2];
    if (!consp(v313)) goto v67;
    v313 = stack[-2];
    v313 = qcar(v313);
    if (!consp(v313)) goto v67;
    v313 = stack[-2];
    v313 = qcar(v313);
    v313 = qcar(v313);
    v190 = qcar(v313);
    v313 = elt(env, 1); /* i */
    if (v190 == v313) goto v6;
    v313 = stack[-2];
    v313 = qcar(v313);
    v190 = qcar(v313);
    v313 = (Lisp_Object)17; /* 1 */
    v313 = cons(v190, v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[0] = ncons(v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    v313 = stack[-2];
    v313 = qcar(v313);
    v313 = qcdr(v313);
    v313 = CC_impartf(env, v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    fn = elt(env, 7); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    v313 = stack[-2];
    v313 = qcdr(v313);
    v313 = CC_impartf(env, v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    fn = elt(env, 8); /* addf */
    v313 = (*qfn2(fn))(qenv(fn), stack[0], v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    goto v69;

v69:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v313); }

v6:
    v313 = stack[-2];
    v313 = qcar(v313);
    stack[0] = qcdr(v313);
    v313 = stack[-2];
    v313 = qcdr(v313);
    v313 = CC_impartf(env, v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    fn = elt(env, 8); /* addf */
    v313 = (*qfn2(fn))(qenv(fn), stack[0], v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    goto v69;

v67:
    v313 = stack[-2];
    if (!consp(v313)) goto v160;
    v313 = stack[-2];
    v190 = qcar(v313);
    v313 = elt(env, 4); /* cmpxfn */
    v313 = get(v190, v313);
    env = stack[-4];
    if (v313 == nil) goto v158;
    v313 = stack[-2];
    stack[-1] = qcar(v313);
    v313 = stack[-2];
    v313 = qcdr(v313);
    stack[0] = qcdr(v313);
    v313 = stack[-2];
    v190 = qcar(v313);
    v313 = elt(env, 5); /* i2d */
    v190 = get(v190, v313);
    env = stack[-4];
    v313 = (Lisp_Object)1; /* 0 */
    v313 = Lapply1(nil, v190, v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    v313 = qcdr(v313);
    v313 = qcar(v313);
    v313 = list2star(stack[-1], stack[0], v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    fn = elt(env, 9); /* int!-equiv!-chk */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    goto v69;

v158:
    v313 = qvalue(elt(env, 3)); /* nil */
    goto v69;

v160:
    v313 = qvalue(elt(env, 3)); /* nil */
    goto v69;
/* error exit handlers */
v55:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v54:
    popv(5);
    return nil;
}



/* Code for pasf_lnegrel */

static Lisp_Object CC_pasf_lnegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v168, v194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_lnegrel");
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
    v194 = v0;
/* end of prologue */
    v168 = v194;
    v133 = elt(env, 1); /* equal */
    if (v168 == v133) goto v152;
    v168 = v194;
    v133 = elt(env, 2); /* neq */
    if (v168 == v133) goto v66;
    v168 = v194;
    v133 = elt(env, 3); /* leq */
    if (v168 == v133) goto v161;
    v168 = v194;
    v133 = elt(env, 5); /* lessp */
    if (v168 == v133) goto v71;
    v168 = v194;
    v133 = elt(env, 6); /* geq */
    if (v168 == v133) goto v19;
    v168 = v194;
    v133 = elt(env, 4); /* greaterp */
    if (v168 == v133) goto v192;
    v168 = v194;
    v133 = elt(env, 7); /* cong */
    if (v168 == v133) goto v182;
    v168 = v194;
    v133 = elt(env, 8); /* ncong */
    if (v168 == v133) goto v177;
    v133 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v133 == nil)) goto v7;
    v133 = elt(env, 10); /* "pasf_lnegrel: unknown operator" */
    v168 = v194;
    v133 = list2(v133, v168);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[0];
    fn = elt(env, 11); /* lprie */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[0];
    goto v7;

v7:
    v133 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v133 = nil;
    { popv(1); return onevalue(v133); }

v177:
    v133 = elt(env, 7); /* cong */
    { popv(1); return onevalue(v133); }

v182:
    v133 = elt(env, 8); /* ncong */
    { popv(1); return onevalue(v133); }

v192:
    v133 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v133); }

v19:
    v133 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v133); }

v71:
    v133 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v133); }

v161:
    v133 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v133); }

v66:
    v133 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v133); }

v152:
    v133 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v133); }
/* error exit handlers */
v61:
    popv(1);
    return nil;
}



/* Code for transposerd */

static Lisp_Object MS_CDECL CC_transposerd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "transposerd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transposerd");
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
    v37 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    v38 = elt(env, 1); /* tp */
    v37 = list2(v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    fn = elt(env, 3); /* aeval */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    stack[0] = v37;
    fn = elt(env, 4); /* lex */
    v37 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v149;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v149:
    popv(2);
    return nil;
}



/* Code for reprod */

static Lisp_Object CC_reprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reprod");
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
    v70 = stack[-1];
    if (v70 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v70 = stack[-1];
    v129 = qcar(v70);
    v70 = (Lisp_Object)17; /* 1 */
    v70 = cons(v129, v70);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    v129 = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    v70 = stack[0];
    fn = elt(env, 2); /* multf */
    v70 = (*qfn2(fn))(qenv(fn), v129, v70);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    stack[0] = v70;
    v70 = stack[-1];
    v70 = qcdr(v70);
    stack[-1] = v70;
    goto v25;
/* error exit handlers */
v184:
    popv(3);
    return nil;
}



/* Code for ps!:term!-rthpow */

static Lisp_Object MS_CDECL CC_psTtermKrthpow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v35, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:term-rthpow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:term-rthpow");
#endif
    if (stack >= stacklimit)
    {
        push3(v35,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v35);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v35;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v10 = stack[-3];
    v65 = stack[-2];
    fn = elt(env, 2); /* ps!:get!-term */
    v65 = (*qfn2(fn))(qenv(fn), v10, v65);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-5];
    stack[-4] = v65;
    v65 = stack[-4];
    if (!(v65 == nil)) goto v15;
    v65 = stack[-3];
    fn = elt(env, 3); /* ps!:last!-term */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-5];
    v65 = add1(v65);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-5];
    stack[0] = v65;
    goto v71;

v71:
    v10 = stack[-2];
    v65 = stack[0];
    v65 = difference2(v10, v65);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-5];
    v65 = Lminusp(nil, v65);
    env = stack[-5];
    if (!(v65 == nil)) goto v15;
    v10 = stack[-3];
    v65 = stack[0];
    fn = elt(env, 4); /* ps!:set!-rthpow */
    v65 = (*qfn2(fn))(qenv(fn), v10, v65);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-5];
    stack[-4] = v65;
    v65 = stack[0];
    v65 = add1(v65);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-5];
    stack[0] = v65;
    goto v71;

v15:
    v10 = stack[-4];
    v65 = stack[-1];
    {
        popv(6);
        fn = elt(env, 5); /* ps!:evaluate */
        return (*qfn2(fn))(qenv(fn), v10, v65);
    }
/* error exit handlers */
v12:
    popv(6);
    return nil;
}



/* Code for ldf!-deg */

static Lisp_Object CC_ldfKdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-deg");
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
    stack[-3] = v1;
    v181 = v0;
/* end of prologue */
    stack[-4] = v181;
    v181 = stack[-4];
    if (v181 == nil) goto v73;
    v181 = stack[-4];
    v181 = qcar(v181);
    v65 = qcdr(v181);
    v181 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v181 = (*qfn2(fn))(qenv(fn), v65, v181);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    stack[-1] = v181;
    stack[-2] = v181;
    goto v42;

v42:
    v181 = stack[-4];
    v181 = qcdr(v181);
    stack[-4] = v181;
    v181 = stack[-4];
    if (v181 == nil) goto v71;
    stack[0] = stack[-1];
    v181 = stack[-4];
    v181 = qcar(v181);
    v65 = qcdr(v181);
    v181 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v181 = (*qfn2(fn))(qenv(fn), v65, v181);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v181 = ncons(v181);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v181 = Lrplacd(nil, stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-5];
    v181 = stack[-1];
    v181 = qcdr(v181);
    stack[-1] = v181;
    goto v42;

v71:
    v181 = stack[-2];
    goto v179;

v179:
    {
        popv(6);
        fn = elt(env, 3); /* maxl */
        return (*qfn1(fn))(qenv(fn), v181);
    }

v73:
    v181 = qvalue(elt(env, 1)); /* nil */
    goto v179;
/* error exit handlers */
v122:
    popv(6);
    return nil;
}



/* Code for subs2pf */

static Lisp_Object CC_subs2pf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v126, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2pf");
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

v178:
    v125 = stack[0];
    if (v125 == nil) goto v25;
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = qcdr(v125);
    fn = elt(env, 1); /* resimp */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    fn = elt(env, 2); /* subs2 */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v126 = v125;
    v126 = qcar(v126);
    if (v126 == nil) goto v129;
    v126 = stack[0];
    v126 = qcar(v126);
    v32 = qcar(v126);
    v126 = v125;
    v125 = stack[0];
    v125 = qcdr(v125);
    popv(2);
    return acons(v32, v126, v125);

v129:
    v125 = stack[0];
    v125 = qcdr(v125);
    stack[0] = v125;
    goto v178;

v25:
    v125 = nil;
    { popv(2); return onevalue(v125); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



setup_type const u40_setup[] =
{
    {"pasf_floor",              too_few_2,      CC_pasf_floor, wrong_no_2},
    {"diffrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffrd},
    {"rand-comb",               too_few_2,      CC_randKcomb,  wrong_no_2},
    {"symmetrize-inds",         too_few_2,      CC_symmetrizeKinds,wrong_no_2},
    {"ev-edgeloop",             too_few_2,      CC_evKedgeloop,wrong_no_2},
    {"fs:prin:",                CC_fsTprinT,    too_many_1,    wrong_no_1},
    {"st_extract_symcells1",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_extract_symcells1},
    {"eval_uni_poly",           too_few_2,      CC_eval_uni_poly,wrong_no_2},
    {"domainp_list",            CC_domainp_list,too_many_1,    wrong_no_1},
    {"rl_fvarl",                CC_rl_fvarl,    too_many_1,    wrong_no_1},
    {"mktag",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktag},
    {"get_dimension_in",        CC_get_dimension_in,too_many_1,wrong_no_1},
    {"iv_cutcongs1",            too_few_2,      CC_iv_cutcongs1,wrong_no_2},
    {"integralir",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_integralir},
    {"nestzerop:",              CC_nestzeropT,  too_many_1,    wrong_no_1},
    {"latexprint",              CC_latexprint,  too_many_1,    wrong_no_1},
    {"force-to-dm",             CC_forceKtoKdm, too_many_1,    wrong_no_1},
    {"markedvarp",              CC_markedvarp,  too_many_1,    wrong_no_1},
    {"indordlp",                too_few_2,      CC_indordlp,   wrong_no_2},
    {"find_bubles1",            too_few_2,      CC_find_bubles1,wrong_no_2},
    {"subsq",                   too_few_2,      CC_subsq,      wrong_no_2},
    {"groeb=testb",             too_few_2,      CC_groebMtestb,wrong_no_2},
    {"monic",                   too_few_2,      CC_monic,      wrong_no_2},
    {"extract_numid",           CC_extract_numid,too_many_1,   wrong_no_1},
    {"can_rep_cell",            too_few_2,      CC_can_rep_cell,wrong_no_2},
    {"max-degree",              too_few_2,      CC_maxKdegree, wrong_no_2},
    {"lto_insert",              too_few_2,      CC_lto_insert, wrong_no_2},
    {"simpx1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpx1},
    {"repartf",                 CC_repartf,     too_many_1,    wrong_no_1},
    {"pasf_negateat",           CC_pasf_negateat,too_many_1,   wrong_no_1},
    {"ratpoly_sub",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_sub},
    {"vdp_getprop",             too_few_2,      CC_vdp_getprop,wrong_no_2},
    {"impartsq",                CC_impartsq,    too_many_1,    wrong_no_1},
    {"transferrow1",            CC_transferrow1,too_many_1,    wrong_no_1},
    {"simpwedge",               CC_simpwedge,   too_many_1,    wrong_no_1},
    {"ratmean",                 too_few_2,      CC_ratmean,    wrong_no_2},
    {"endofstmtp",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_endofstmtp},
    {"lndepends",               too_few_2,      CC_lndepends,  wrong_no_2},
    {"mk_binding",              too_few_2,      CC_mk_binding, wrong_no_2},
    {"compactf1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf1},
    {"baglistp",                CC_baglistp,    too_many_1,    wrong_no_1},
    {"proper-simpsqrt",         CC_properKsimpsqrt,too_many_1, wrong_no_1},
    {"ofsf_irl2atl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_irl2atl},
    {"impartf",                 CC_impartf,     too_many_1,    wrong_no_1},
    {"pasf_lnegrel",            CC_pasf_lnegrel,too_many_1,    wrong_no_1},
    {"transposerd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_transposerd},
    {"reprod",                  too_few_2,      CC_reprod,     wrong_no_2},
    {"ps:term-rthpow",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTtermKrthpow},
    {"ldf-deg",                 too_few_2,      CC_ldfKdeg,    wrong_no_2},
    {"subs2pf",                 CC_subs2pf,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u40", (two_args *)"18643 3893845 27900", 0}
};

/* end of generated code */
