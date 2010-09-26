
/* $destdir\u35.c        Machine generated C code */

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


/* Code for setmatelem */

static Lisp_Object CC_setmatelem(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmatelem");
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
    v34 = stack[-2];
    v35 = Llength(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    v34 = (Lisp_Object)49; /* 3 */
    if (v35 == v34) goto v38;
    v35 = stack[-2];
    v34 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 11); /* typerr */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    goto v38;

v38:
    v34 = stack[-2];
    v35 = qcar(v34);
    v34 = elt(env, 2); /* avalue */
    v34 = get(v35, v34);
    env = stack[-4];
    stack[-3] = v34;
    v34 = stack[-3];
    if (v34 == nil) goto v39;
    v34 = stack[-3];
    v35 = qcar(v34);
    v34 = elt(env, 3); /* matrix */
    if (!(v35 == v34)) goto v39;
    v34 = stack[-3];
    v34 = qcdr(v34);
    v35 = qcar(v34);
    stack[-3] = v35;
    v34 = elt(env, 5); /* mat */
    if (!consp(v35)) goto v40;
    v35 = qcar(v35);
    if (!(v35 == v34)) goto v40;

v41:
    v34 = stack[-2];
    v34 = qcdr(v34);
    v34 = qcar(v34);
    fn = elt(env, 12); /* reval_without_mod */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    stack[0] = v34;
    v34 = stack[0];
    v34 = integerp(v34);
    if (v34 == nil) goto v42;
    v35 = stack[0];
    v34 = (Lisp_Object)1; /* 0 */
    v34 = (Lisp_Object)lesseq2(v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v34 = v34 ? lisp_true : nil;
    env = stack[-4];
    if (!(v34 == nil)) goto v42;

v43:
    v34 = stack[-3];
    v35 = qcdr(v34);
    v34 = stack[0];
    fn = elt(env, 13); /* pnth */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    v34 = qcar(v34);
    stack[-3] = v34;
    v34 = stack[-2];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    fn = elt(env, 12); /* reval_without_mod */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    stack[0] = v34;
    v34 = stack[0];
    v34 = integerp(v34);
    if (v34 == nil) goto v44;
    v35 = stack[0];
    v34 = (Lisp_Object)1; /* 0 */
    v34 = (Lisp_Object)lesseq2(v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v34 = v34 ? lisp_true : nil;
    env = stack[-4];
    if (!(v34 == nil)) goto v44;

v45:
    v35 = stack[-3];
    v34 = stack[0];
    fn = elt(env, 13); /* pnth */
    v35 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v34 = stack[-1];
        popv(5);
        return Lrplaca(nil, v35, v34);

v44:
    v35 = stack[0];
    v34 = elt(env, 10); /* "positive integer" */
    fn = elt(env, 11); /* typerr */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    goto v45;

v42:
    v35 = stack[0];
    v34 = elt(env, 10); /* "positive integer" */
    fn = elt(env, 11); /* typerr */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    goto v43;

v40:
    v36 = elt(env, 6); /* "Matrix" */
    v34 = stack[-2];
    v35 = qcar(v34);
    v34 = elt(env, 7); /* "not set" */
    v34 = list3(v36, v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    v35 = v34;
    v34 = v35;
    qvalue(elt(env, 8)) = v34; /* errmsg!* */
    v34 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v34 == nil)) goto v46;
    v34 = v35;
    fn = elt(env, 14); /* lprie */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    goto v46;

v46:
    v34 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    goto v41;

v39:
    v34 = stack[-2];
    v35 = qcar(v34);
    v34 = elt(env, 4); /* "matrix" */
    fn = elt(env, 11); /* typerr */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-4];
    goto v41;
/* error exit handlers */
v37:
    popv(5);
    return nil;
}



/* Code for prepsq!*1 */

static Lisp_Object MS_CDECL CC_prepsqH1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v188, v189, v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prepsq*1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*1");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v47;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v187 = stack[-6];
    if (!consp(v187)) goto v191;
    v187 = stack[-6];
    v187 = qcar(v187);
    if (!consp(v187)) goto v191;
    v187 = stack[-6];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v188 = qcar(v187);
    v187 = qvalue(elt(env, 1)); /* factors!* */
    v187 = Lmember(nil, v188, v187);
    if (!(v187 == nil)) goto v192;
    v187 = stack[-6];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v187 = qcar(v187);
    if (!consp(v187)) goto v191;
    v187 = stack[-6];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v187 = qcar(v187);
    v188 = qcar(v187);
    v187 = qvalue(elt(env, 1)); /* factors!* */
    v187 = Lmember(nil, v188, v187);
    if (!(v187 == nil)) goto v192;

v191:
    v187 = stack[-5];
    if (!consp(v187)) goto v193;
    v187 = stack[-5];
    v187 = qcar(v187);
    if (!consp(v187)) goto v193;
    v187 = qvalue(elt(env, 4)); /* kord!* */
    stack[-3] = v187;
    goto v194;

v194:
    v187 = stack[-3];
    if (v187 == nil) goto v193;
    v187 = stack[-3];
    v187 = qcar(v187);
    stack[-2] = v187;
    v187 = (Lisp_Object)1; /* 0 */
    stack[-1] = v187;
    v189 = stack[-2];
    v188 = (Lisp_Object)17; /* 1 */
    v187 = (Lisp_Object)17; /* 1 */
    v187 = acons(v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = ncons(v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[0] = v187;
    goto v196;

v196:
    v188 = stack[-5];
    v187 = stack[0];
    fn = elt(env, 13); /* quotfm */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-7] = v187;
    if (v187 == nil) goto v197;
    v187 = stack[-1];
    v187 = sub1(v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-1] = v187;
    v187 = stack[-7];
    stack[-5] = v187;
    goto v196;

v197:
    v188 = stack[-1];
    v187 = (Lisp_Object)1; /* 0 */
    v187 = (Lisp_Object)lessp2(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v187 = v187 ? lisp_true : nil;
    env = stack[-8];
    if (v187 == nil) goto v198;
    v189 = elt(env, 3); /* expt */
    v188 = stack[-2];
    v187 = stack[-1];
    v187 = list3(v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    fn = elt(env, 14); /* fkern */
    v188 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* getpower */
    v188 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = stack[-4];
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-4] = v187;
    goto v198;

v198:
    v187 = stack[-3];
    v187 = qcdr(v187);
    stack[-3] = v187;
    goto v194;

v193:
    v187 = stack[-6];
    fn = elt(env, 16); /* kernlp */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    if (v187 == nil) goto v199;
    v188 = stack[-4];
    v187 = stack[-6];
    fn = elt(env, 17); /* mkkl */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-6] = v187;
    v187 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v187;
    goto v199;

v199:
    v187 = qvalue(elt(env, 5)); /* dnl!* */
    if (v187 == nil) goto v200;
    v187 = qvalue(elt(env, 6)); /* !*allfac */
    if (v187 == nil) goto v201;
    v187 = stack[-6];
    fn = elt(env, 18); /* ckrn */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    goto v202;

v202:
    stack[-1] = v187;
    v188 = stack[-1];
    v187 = qvalue(elt(env, 5)); /* dnl!* */
    fn = elt(env, 19); /* ckrn!* */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-7] = v187;
    v188 = stack[-1];
    v187 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v188 = stack[-6];
    v187 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-6] = v187;
    v188 = stack[-5];
    v187 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-5] = v187;
    goto v200;

v200:
    v187 = qvalue(elt(env, 7)); /* upl!* */
    if (v187 == nil) goto v203;
    v187 = stack[-5];
    fn = elt(env, 18); /* ckrn */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[0] = v187;
    v188 = stack[0];
    v187 = qvalue(elt(env, 7)); /* upl!* */
    fn = elt(env, 19); /* ckrn!* */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-7] = v187;
    v188 = stack[0];
    v187 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[0] = v187;
    v188 = stack[-6];
    v187 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-6] = v187;
    v188 = stack[-5];
    v187 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-5] = v187;
    goto v204;

v204:
    stack[-1] = stack[-6];
    v188 = stack[-5];
    v187 = stack[0];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = cons(stack[-1], v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    fn = elt(env, 21); /* canonsq */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-6] = v187;
    v187 = stack[-6];
    v188 = qcar(v187);
    v187 = stack[0];
    fn = elt(env, 20); /* quotof */
    v188 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = stack[-6];
    v187 = qcdr(v187);
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-6] = v187;
    v187 = qvalue(elt(env, 6)); /* !*allfac */
    if (v187 == nil) goto v205;
    v187 = stack[-6];
    v187 = qcar(v187);
    fn = elt(env, 18); /* ckrn */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-1] = v187;
    v187 = stack[-6];
    v187 = qcdr(v187);
    fn = elt(env, 18); /* ckrn */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[0] = v187;
    v188 = stack[-1];
    v187 = (Lisp_Object)17; /* 1 */
    if (!(v188 == v187)) goto v206;
    v188 = stack[0];
    v187 = (Lisp_Object)17; /* 1 */
    if (!(v188 == v187)) goto v206;

v205:
    v187 = stack[-4];
    if (v187 == nil) goto v207;
    v190 = stack[-4];
    v189 = qvalue(elt(env, 2)); /* nil */
    v188 = qvalue(elt(env, 2)); /* nil */
    v187 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 22); /* exchk1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 4, v190, v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = stack[-6];
    v187 = qcar(v187);
    if (v187 == nil) goto v208;
    v188 = stack[-6];
    v187 = elt(env, 12); /* prepf */
    fn = elt(env, 23); /* sqform */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    goto v209;

v209:
    v187 = ncons(v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = Lnconc(nil, stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    fn = elt(env, 24); /* retimes */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    popv(9);
    return ncons(v187);

v208:
    v187 = (Lisp_Object)1; /* 0 */
    goto v209;

v207:
    v187 = stack[-6];
    v187 = qcar(v187);
    if (v187 == nil) goto v210;
    v188 = stack[-6];
    v187 = elt(env, 12); /* prepf */
    fn = elt(env, 23); /* sqform */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    goto v211;

v211:
    v188 = v187;
    v187 = v188;
    v189 = elt(env, 9); /* plus */
    if (!consp(v187)) goto v212;
    v187 = qcar(v187);
    if (!(v187 == v189)) goto v212;
    v187 = v188;
    v187 = qcdr(v187);
    { popv(9); return onevalue(v187); }

v212:
    v187 = v188;
    popv(9);
    return ncons(v187);

v210:
    v187 = (Lisp_Object)1; /* 0 */
    goto v211;

v206:
    v188 = stack[-1];
    v187 = stack[-6];
    v187 = qcar(v187);
    if (!(equal(v188, v187))) goto v213;
    v188 = stack[0];
    v187 = stack[-6];
    v187 = qcdr(v187);
    if (equal(v188, v187)) goto v205;
    else goto v213;

v213:
    v187 = stack[-6];
    v188 = qcdr(v187);
    v187 = stack[0];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-5] = v187;
    v187 = stack[-6];
    v188 = qcar(v187);
    v187 = stack[-1];
    fn = elt(env, 20); /* quotof */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-6] = v187;
    v188 = stack[-4];
    v187 = stack[-1];
    fn = elt(env, 17); /* mkkl */
    v188 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 25); /* prepf1 */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v188 = v187;
    v187 = v188;
    if (v187 == nil) goto v214;
    v187 = v188;
    fn = elt(env, 26); /* replus */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    goto v215;

v215:
    stack[-4] = v187;
    v188 = stack[0];
    v187 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 25); /* prepf1 */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v188 = v187;
    v187 = v188;
    if (v187 == nil) goto v216;
    v187 = v188;
    fn = elt(env, 26); /* replus */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    goto v217;

v217:
    stack[-1] = v187;
    v188 = stack[-4];
    v187 = stack[-6];
    fn = elt(env, 27); /* addfactors */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-6] = v187;
    v188 = stack[-1];
    v187 = stack[-5];
    fn = elt(env, 27); /* addfactors */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-5] = v187;
    v188 = stack[-5];
    v187 = (Lisp_Object)17; /* 1 */
    if (v188 == v187) goto v218;
    v188 = stack[-6];
    v187 = elt(env, 10); /* minus */
    if (!consp(v188)) goto v219;
    v188 = qcar(v188);
    if (!(v188 == v187)) goto v219;
    stack[0] = elt(env, 10); /* minus */
    v189 = elt(env, 11); /* quotient */
    v187 = stack[-6];
    v187 = qcdr(v187);
    v188 = qcar(v187);
    v187 = stack[-5];
    v187 = list3(v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = list2(stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    goto v220;

v220:
    popv(9);
    return ncons(v187);

v219:
    v189 = elt(env, 11); /* quotient */
    v188 = stack[-6];
    v187 = stack[-5];
    v187 = list3(v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    goto v220;

v218:
    v187 = stack[-6];
    v188 = elt(env, 9); /* plus */
    if (!consp(v187)) goto v221;
    v187 = qcar(v187);
    if (!(v187 == v188)) goto v221;
    v187 = stack[-6];
    v187 = qcdr(v187);
    { popv(9); return onevalue(v187); }

v221:
    v187 = stack[-6];
    popv(9);
    return ncons(v187);

v216:
    v187 = (Lisp_Object)1; /* 0 */
    goto v217;

v214:
    v187 = (Lisp_Object)1; /* 0 */
    goto v215;

v203:
    v187 = qvalue(elt(env, 8)); /* !*div */
    if (v187 == nil) goto v222;
    v187 = stack[-5];
    fn = elt(env, 18); /* ckrn */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[0] = v187;
    goto v204;

v222:
    v187 = (Lisp_Object)17; /* 1 */
    stack[0] = v187;
    goto v204;

v201:
    v187 = (Lisp_Object)17; /* 1 */
    goto v202;

v192:
    v188 = stack[-5];
    v187 = (Lisp_Object)17; /* 1 */
    if (v188 == v187) goto v223;
    v187 = stack[-6];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v187 = qcdr(v187);
    stack[-2] = v187;
    v187 = stack[-5];
    stack[-1] = v187;
    v187 = stack[-6];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v189 = qcar(v187);
    v188 = (Lisp_Object)17; /* 1 */
    v187 = (Lisp_Object)17; /* 1 */
    v187 = acons(v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = ncons(v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[0] = v187;
    goto v224;

v224:
    v188 = stack[-1];
    v187 = stack[0];
    fn = elt(env, 13); /* quotfm */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-7] = v187;
    if (v187 == nil) goto v225;
    v187 = stack[-7];
    stack[-1] = v187;
    v187 = stack[-2];
    v187 = sub1(v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[-2] = v187;
    goto v224;

v225:
    v187 = stack[-6];
    v187 = qcar(v187);
    v188 = qcdr(v187);
    v187 = stack[-1];
    stack[0] = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v188 = stack[-2];
    v187 = (Lisp_Object)1; /* 0 */
    v187 = (Lisp_Object)greaterp2(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v187 = v187 ? lisp_true : nil;
    env = stack[-8];
    if (v187 == nil) goto v37;
    v187 = stack[-6];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v189 = qcar(v187);
    v188 = stack[-2];
    v187 = stack[-4];
    v187 = acons(v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    goto v226;

v226:
    fn = elt(env, 28); /* prepsq!*0 */
    v187 = (*qfn2(fn))(qenv(fn), stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[0] = v187;
    goto v227;

v227:
    v187 = stack[-6];
    v188 = qcdr(v187);
    v187 = stack[-5];
    v188 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = stack[-4];
    fn = elt(env, 28); /* prepsq!*0 */
    v187 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    {
        Lisp_Object v228 = stack[0];
        popv(9);
        return Lnconc(nil, v228, v187);
    }

v37:
    v188 = stack[-2];
    v187 = (Lisp_Object)1; /* 0 */
    v187 = (Lisp_Object)lessp2(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    v187 = v187 ? lisp_true : nil;
    env = stack[-8];
    if (v187 == nil) goto v229;
    v189 = elt(env, 3); /* expt */
    v187 = stack[-6];
    v187 = qcar(v187);
    v187 = qcar(v187);
    v188 = qcar(v187);
    v187 = stack[-2];
    v187 = list3(v189, v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    fn = elt(env, 14); /* fkern */
    v188 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* getpower */
    v188 = (*qfn2(fn))(qenv(fn), v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = stack[-4];
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    goto v226;

v229:
    v187 = stack[-4];
    goto v226;

v223:
    v187 = stack[-6];
    v187 = qcar(v187);
    v188 = qcdr(v187);
    v187 = stack[-5];
    stack[0] = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    v187 = stack[-6];
    v187 = qcar(v187);
    v188 = qcar(v187);
    v187 = stack[-4];
    v187 = cons(v188, v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    fn = elt(env, 28); /* prepsq!*0 */
    v187 = (*qfn2(fn))(qenv(fn), stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-8];
    stack[0] = v187;
    goto v227;
/* error exit handlers */
v195:
    popv(9);
    return nil;
}



/* Code for !*g2lex */

static Lisp_Object CC_Hg2lex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *g2lex");
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
    v230 = v0;
/* end of prologue */
    v231 = nil;
    stack[-1] = v230;
    goto v232;

v232:
    v230 = stack[-1];
    if (v230 == nil) { popv(3); return onevalue(v231); }
    v230 = stack[-1];
    v230 = qcar(v230);
    stack[0] = v231;
    v231 = v230;
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v230 = qcdr(v230);
    v230 = cons(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-2];
    v230 = ncons(v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-2];
    fn = elt(env, 2); /* psum */
    v230 = (*qfn2(fn))(qenv(fn), stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-2];
    v231 = v230;
    v230 = stack[-1];
    v230 = qcdr(v230);
    stack[-1] = v230;
    goto v232;
/* error exit handlers */
v233:
    popv(3);
    return nil;
}



/* Code for inormmat */

static Lisp_Object CC_inormmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inormmat");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v250 = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-5] = v250;
    goto v191;

v191:
    v250 = stack[-5];
    if (v250 == nil) goto v251;
    v250 = stack[-5];
    v250 = qcar(v250);
    stack[-1] = v250;
    v250 = (Lisp_Object)17; /* 1 */
    stack[-7] = v250;
    v250 = stack[-1];
    stack[0] = v250;
    goto v30;

v30:
    v250 = stack[0];
    if (v250 == nil) goto v184;
    v250 = stack[0];
    v250 = qcar(v250);
    v12 = stack[-7];
    v250 = qcdr(v250);
    fn = elt(env, 2); /* ilcm */
    v250 = (*qfn2(fn))(qenv(fn), v12, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    stack[-7] = v250;
    v250 = stack[0];
    v250 = qcdr(v250);
    stack[0] = v250;
    goto v30;

v184:
    v250 = stack[-1];
    stack[-4] = v250;
    v250 = stack[-4];
    if (v250 == nil) goto v253;
    v250 = stack[-4];
    v250 = qcar(v250);
    v12 = v250;
    stack[0] = qcar(v12);
    v12 = stack[-7];
    v250 = qcdr(v250);
    v250 = quot2(v12, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    v250 = times2(stack[0], v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    v250 = ncons(v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    stack[-2] = v250;
    stack[-3] = v250;
    goto v24;

v24:
    v250 = stack[-4];
    v250 = qcdr(v250);
    stack[-4] = v250;
    v250 = stack[-4];
    if (v250 == nil) goto v254;
    stack[-1] = stack[-2];
    v250 = stack[-4];
    v250 = qcar(v250);
    v12 = v250;
    stack[0] = qcar(v12);
    v12 = stack[-7];
    v250 = qcdr(v250);
    v250 = quot2(v12, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    v250 = times2(stack[0], v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    v250 = ncons(v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    v250 = Lrplacd(nil, stack[-1], v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    v250 = stack[-2];
    v250 = qcdr(v250);
    stack[-2] = v250;
    goto v24;

v254:
    v250 = stack[-3];
    v12 = v250;
    goto v27;

v27:
    v250 = stack[-6];
    v250 = cons(v12, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-8];
    stack[-6] = v250;
    v250 = stack[-5];
    v250 = qcdr(v250);
    stack[-5] = v250;
    goto v191;

v253:
    v250 = qvalue(elt(env, 1)); /* nil */
    v12 = v250;
    goto v27;

v251:
    v250 = stack[-6];
        popv(9);
        return Lreverse(nil, v250);
/* error exit handlers */
v252:
    popv(9);
    return nil;
}



/* Code for small!-primep */

static Lisp_Object CC_smallKprimep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v272, v273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for small-primep");
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
    v272 = stack[-8];
    v272 = Levenp(nil, v272);
    env = stack[-10];
    if (!(v272 == nil)) goto v274;
    v273 = stack[-8];
    v272 = (Lisp_Object)49; /* 3 */
    v273 = Cremainder(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    v272 = (Lisp_Object)1; /* 0 */
    if (v273 == v272) goto v274;
    v272 = stack[-8];
    v272 = sub1(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    stack[-6] = v272;
    v272 = stack[-8];
    v272 = Lset_small_modulus(nil, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    stack[-3] = v272;
    v272 = (Lisp_Object)1; /* 0 */
    stack[-7] = v272;
    goto v26;

v26:
    v272 = stack[-6];
    v272 = Levenp(nil, v272);
    env = stack[-10];
    if (v272 == nil) goto v184;
    v273 = stack[-6];
    v272 = (Lisp_Object)33; /* 2 */
    v272 = quot2(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    stack[-6] = v272;
    v272 = stack[-7];
    v272 = add1(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    stack[-7] = v272;
    goto v26;

v184:
    v272 = (Lisp_Object)17; /* 1 */
    stack[-9] = v272;
    v272 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v272;
    goto v22;

v22:
    v272 = stack[-2];
    if (v272 == nil) goto v23;
    v273 = stack[-9];
    v272 = qvalue(elt(env, 3)); /* !*confidence!* */
    v272 = (Lisp_Object)lesseq2(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    v272 = v272 ? lisp_true : nil;
    env = stack[-10];
    if (v272 == nil) goto v23;
    v273 = stack[-8];
    v272 = (Lisp_Object)33; /* 2 */
    v272 = difference2(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    fn = elt(env, 4); /* random */
    v272 = (*qfn1(fn))(qenv(fn), v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    v272 = add1(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    v273 = v272;
    v272 = stack[-6];
    v272 = Lmodular_expt(nil, v273, v272);
    env = stack[-10];
    stack[-5] = v272;
    v273 = stack[-5];
    v272 = (Lisp_Object)17; /* 1 */
    if (v273 == v272) goto v276;
    v272 = (Lisp_Object)17; /* 1 */
    stack[-1] = v272;
    goto v277;

v277:
    v273 = stack[-7];
    v272 = stack[-1];
    v272 = difference2(v273, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    v272 = Lminusp(nil, v272);
    env = stack[-10];
    if (v272 == nil) goto v278;
    v273 = stack[-5];
    v272 = (Lisp_Object)17; /* 1 */
    if (v273 == v272) goto v276;
    v272 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v272;
    goto v276;

v276:
    v272 = stack[-9];
    v272 = add1(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    stack[-9] = v272;
    goto v22;

v278:
    v273 = stack[-5];
    v272 = stack[-5];
    v272 = Lmodular_times(nil, v273, v272);
    env = stack[-10];
    stack[-4] = v272;
    v273 = stack[-4];
    v272 = (Lisp_Object)17; /* 1 */
    if (!(v273 == v272)) goto v279;
    stack[0] = stack[-5];
    v272 = stack[-8];
    v272 = sub1(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    if (equal(stack[0], v272)) goto v279;
    v273 = stack[-5];
    v272 = (Lisp_Object)17; /* 1 */
    if (v273 == v272) goto v279;
    v272 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v272;
    goto v280;

v280:
    v272 = stack[-1];
    v272 = add1(v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-10];
    stack[-1] = v272;
    goto v277;

v279:
    v272 = stack[-4];
    stack[-5] = v272;
    goto v280;

v23:
    v272 = stack[-3];
    v272 = Lset_small_modulus(nil, v272);
    nil = C_nil;
    if (exception_pending()) goto v275;
    { Lisp_Object res = stack[-2]; popv(11); return onevalue(res); }

v274:
    v272 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v272); }
/* error exit handlers */
v275:
    popv(11);
    return nil;
}



/* Code for general!-multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_generalKmultiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-multiply-by-constant-mod-p");
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
    v242 = stack[-2];
    if (v242 == nil) goto v85;
    v243 = stack[-1];
    v242 = (Lisp_Object)17; /* 1 */
    if (v243 == v242) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v242 = stack[-2];
    if (!consp(v242)) goto v285;
    v242 = stack[-2];
    v242 = qcar(v242);
    if (!consp(v242)) goto v285;
    v242 = stack[-2];
    v242 = qcar(v242);
    stack[-3] = qcar(v242);
    v242 = stack[-2];
    v242 = qcar(v242);
    v243 = qcdr(v242);
    v242 = stack[-1];
    stack[0] = CC_generalKmultiplyKbyKconstantKmodKp(env, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    v242 = stack[-2];
    v243 = qcdr(v242);
    v242 = stack[-1];
    v242 = CC_generalKmultiplyKbyKconstantKmodKp(env, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    {
        Lisp_Object v18 = stack[-3];
        Lisp_Object v265 = stack[0];
        popv(5);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v18, v265, v242);
    }

v285:
    v243 = stack[-2];
    v242 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-times */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-4];
    v243 = v242;
    v242 = v243;
    v242 = (Lisp_Object)zerop(v242);
    v242 = v242 ? lisp_true : nil;
    env = stack[-4];
    if (v242 == nil) { popv(5); return onevalue(v243); }
    v242 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v242); }

v85:
    v242 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v242); }
/* error exit handlers */
v20:
    popv(5);
    return nil;
}



/* Code for preptayexp */

static Lisp_Object CC_preptayexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v286, v287;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptayexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v287 = v0;
/* end of prologue */
    v286 = v287;
    if (!consp(v286)) return onevalue(v287);
    v286 = v287;
    {
        fn = elt(env, 1); /* rnprep!: */
        return (*qfn1(fn))(qenv(fn), v286);
    }
}



/* Code for ratpoly_sgn */

static Lisp_Object CC_ratpoly_sgn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v274;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_sgn");
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
    v274 = qvalue(elt(env, 1)); /* !*rlanuexdebug */
    if (v274 == nil) goto v284;
    v274 = stack[0];
    fn = elt(env, 3); /* ratpoly_ratp */
    v274 = (*qfn1(fn))(qenv(fn), v274);
    nil = C_nil;
    if (exception_pending()) goto v288;
    env = stack[-1];
    if (!(v274 == nil)) goto v284;
    v274 = elt(env, 2); /* "***** ratpoly_sgn: not a constant polynomial" 
*/
    stack[0] = v274;
    v274 = stack[0];
    v274 = Lprinc(nil, v274);
    nil = C_nil;
    if (exception_pending()) goto v288;
    env = stack[-1];
    v274 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v288;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v284:
    v274 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* rat_sgn */
        return (*qfn1(fn))(qenv(fn), v274);
    }
/* error exit handlers */
v288:
    popv(2);
    return nil;
}



/* Code for bc_mkat */

static Lisp_Object CC_bc_mkat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v291, v32, v284;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_mkat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v291 = v1;
    v32 = v0;
/* end of prologue */
    v291 = qcar(v291);
    v284 = qvalue(elt(env, 1)); /* nil */
    return list3(v32, v291, v284);
}



/* Code for omattrir */

static Lisp_Object MS_CDECL CC_omattrir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v22, v293;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omattrir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omattrir");
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
    fn = elt(env, 6); /* lex */
    v23 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    fn = elt(env, 7); /* omatpir */
    v23 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    stack[-1] = v23;
    fn = elt(env, 6); /* lex */
    v23 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    fn = elt(env, 8); /* omobj */
    v23 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    stack[0] = v23;
    fn = elt(env, 6); /* lex */
    v23 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    v23 = elt(env, 1); /* (!/ o m a t t r) */
    fn = elt(env, 9); /* checktag */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    v23 = stack[-1];
    v23 = Lconsp(nil, v23);
    env = stack[-2];
    if (v23 == nil) goto v287;
    v23 = stack[-1];
    v23 = qcar(v23);
    v23 = qcdr(v23);
    v22 = qcar(v23);
    v23 = elt(env, 2); /* csymbol */
    if (!(v22 == v23)) goto v287;
    v22 = stack[0];
    v23 = qvalue(elt(env, 3)); /* nil */
    v293 = qvalue(elt(env, 3)); /* nil */
    popv(3);
    return list2star(v22, v23, v293);

v287:
    v23 = stack[0];
    if (is_number(v23)) goto v26;
    v293 = elt(env, 5); /* ci */
    v22 = stack[-1];
    v23 = stack[0];
    popv(3);
    return list3(v293, v22, v23);

v26:
    v293 = elt(env, 4); /* cn */
    v22 = stack[-1];
    v23 = stack[0];
    popv(3);
    return list3(v293, v22, v23);
/* error exit handlers */
v223:
    popv(3);
    return nil;
}



/* Code for letmtr */

static Lisp_Object MS_CDECL CC_letmtr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v295, v264, v238, v296, v276;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "letmtr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v47;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v264 = stack[0];
    v295 = elt(env, 1); /* mat */
    if (!consp(v264)) goto v246;
    v264 = qcar(v264);
    if (!(v264 == v295)) goto v246;
    v295 = stack[-2];
    v295 = qcdr(v295);
    fn = elt(env, 10); /* revlis */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    stack[-3] = v295;
    fn = elt(env, 11); /* numlis */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    if (v295 == nil) goto v298;
    v295 = stack[-3];
    v264 = Llength(nil, v295);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    v295 = (Lisp_Object)33; /* 2 */
    if (!(v264 == v295)) goto v298;

v46:
    v295 = stack[0];
    v264 = qcdr(v295);
    v295 = stack[-3];
    v295 = qcar(v295);
    fn = elt(env, 12); /* pnth */
    v295 = (*qfn2(fn))(qenv(fn), v264, v295);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    v264 = qcar(v295);
    v295 = stack[-3];
    v295 = qcdr(v295);
    v295 = qcar(v295);
    fn = elt(env, 12); /* pnth */
    v264 = (*qfn2(fn))(qenv(fn), v264, v295);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    v295 = stack[-1];
    v295 = Lrplaca(nil, v264, v295);
    nil = C_nil;
    if (exception_pending()) goto v297;
    v295 = nil;
    { popv(5); return onevalue(v295); }

v298:
    v276 = elt(env, 6); /* "Syntax error:" */
    v296 = stack[-2];
    v238 = elt(env, 7); /* "invalid" */
    v264 = qvalue(elt(env, 8)); /* nil */
    v295 = elt(env, 9); /* hold */
    {
        popv(5);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v276, v296, v238, v264, v295);
    }

v246:
    v238 = elt(env, 2); /* "Matrix" */
    v295 = stack[-2];
    v264 = qcar(v295);
    v295 = elt(env, 3); /* "not set" */
    v295 = list3(v238, v264, v295);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    v264 = v295;
    v295 = v264;
    qvalue(elt(env, 4)) = v295; /* errmsg!* */
    v295 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v295 == nil)) goto v299;
    v295 = v264;
    fn = elt(env, 14); /* lprie */
    v295 = (*qfn1(fn))(qenv(fn), v295);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    goto v299;

v299:
    v295 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-4];
    goto v46;
/* error exit handlers */
v297:
    popv(5);
    return nil;
}



/* Code for a2bc */

static Lisp_Object CC_a2bc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for a2bc");
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
    v230 = v0;
/* end of prologue */
    v231 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v231 == nil) goto v41;
    v231 = v230;
    if (!consp(v231)) goto v283;
    v231 = v230;
    v231 = qcar(v231);
    if (!consp(v231)) goto v283;
    v231 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v231 == nil)) goto v300;
    v231 = elt(env, 3); /* " Invalid coefficient " */
    v230 = list2(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[0];
    goto v300;

v300:
    v230 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v301;
    v230 = nil;
    { popv(1); return onevalue(v230); }

v283:
    {
        popv(1);
        fn = elt(env, 5); /* bcfd */
        return (*qfn1(fn))(qenv(fn), v230);
    }

v41:
    {
        popv(1);
        fn = elt(env, 6); /* simp!* */
        return (*qfn1(fn))(qenv(fn), v230);
    }
/* error exit handlers */
v301:
    popv(1);
    return nil;
}



/* Code for rand!-mons!-sparse */

static Lisp_Object MS_CDECL CC_randKmonsKsparse(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v47, Lisp_Object v7,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rand-mons-sparse");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rand-mons-sparse");
#endif
    if (stack >= stacklimit)
    {
        push5(v6,v7,v47,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v47,v7,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v7;
    stack[-2] = v47;
    stack[-3] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    stack[-7] = nil;
    v136 = stack[0];
    if (v136 == nil) goto v283;
    v137 = (Lisp_Object)17; /* 1 */
    v136 = stack[-1];
    v136 = difference2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = plus2(stack[-2], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    goto v330;

v330:
    stack[-2] = v136;
    v137 = v136;
    v136 = stack[-3];
    fn = elt(env, 2); /* min */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    fn = elt(env, 3); /* rand!-comb */
    v136 = (*qfn2(fn))(qenv(fn), stack[-2], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v137 = v136;
    v136 = stack[0];
    if (v136 == nil) goto v279;
    v136 = v137;
    stack[-5] = v136;
    v136 = stack[-5];
    if (v136 == nil) goto v17;
    v136 = stack[-5];
    v136 = qcar(v136);
    stack[0] = stack[-8];
    v137 = v136;
    v136 = stack[-1];
    v136 = plus2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    fn = elt(env, 4); /* !*kp2f */
    v136 = (*qfn2(fn))(qenv(fn), stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    stack[-3] = v136;
    stack[-4] = v136;
    goto v331;

v331:
    v136 = stack[-5];
    v136 = qcdr(v136);
    stack[-5] = v136;
    v136 = stack[-5];
    if (v136 == nil) { Lisp_Object res = stack[-4]; popv(11); return onevalue(res); }
    stack[-2] = stack[-3];
    v136 = stack[-5];
    v136 = qcar(v136);
    stack[0] = stack[-8];
    v137 = v136;
    v136 = stack[-1];
    v136 = plus2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    fn = elt(env, 4); /* !*kp2f */
    v136 = (*qfn2(fn))(qenv(fn), stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = Lrplacd(nil, stack[-2], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-3];
    v136 = qcdr(v136);
    stack[-3] = v136;
    goto v331;

v17:
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v136); }

v279:
    v136 = v137;
    stack[-6] = v136;
    v136 = stack[-6];
    if (v136 == nil) goto v37;
    v136 = stack[-6];
    v136 = qcar(v136);
    stack[-2] = v136;
    v136 = (Lisp_Object)17; /* 1 */
    stack[-1] = v136;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v137 = stack[-2];
    v136 = stack[-7];
    v137 = plus2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-9];
    fn = elt(env, 5); /* inttovec */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = cons(stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    stack[-2] = v136;
    v136 = stack[-8];
    stack[0] = v136;
    goto v332;

v332:
    v136 = stack[0];
    if (v136 == nil) goto v229;
    v136 = stack[0];
    v136 = qcar(v136);
    v137 = v136;
    v136 = stack[-2];
    v136 = qcdr(v136);
    stack[-2] = v136;
    v136 = qcar(v136);
    fn = elt(env, 4); /* !*kp2f */
    v137 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-1];
    fn = elt(env, 6); /* multf */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    stack[-1] = v136;
    v136 = stack[0];
    v136 = qcdr(v136);
    stack[0] = v136;
    goto v332;

v229:
    v136 = stack[-1];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    stack[-4] = v136;
    stack[-5] = v136;
    goto v168;

v168:
    v136 = stack[-6];
    v136 = qcdr(v136);
    stack[-6] = v136;
    v136 = stack[-6];
    if (v136 == nil) { Lisp_Object res = stack[-5]; popv(11); return onevalue(res); }
    stack[-3] = stack[-4];
    v136 = stack[-6];
    v136 = qcar(v136);
    stack[-2] = v136;
    v136 = (Lisp_Object)17; /* 1 */
    stack[-1] = v136;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v137 = stack[-2];
    v136 = stack[-7];
    v137 = plus2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-9];
    fn = elt(env, 5); /* inttovec */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = cons(stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    stack[-2] = v136;
    v136 = stack[-8];
    stack[0] = v136;
    goto v333;

v333:
    v136 = stack[0];
    if (v136 == nil) goto v334;
    v136 = stack[0];
    v136 = qcar(v136);
    v137 = v136;
    v136 = stack[-2];
    v136 = qcdr(v136);
    stack[-2] = v136;
    v136 = qcar(v136);
    fn = elt(env, 4); /* !*kp2f */
    v137 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-1];
    fn = elt(env, 6); /* multf */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    stack[-1] = v136;
    v136 = stack[0];
    v136 = qcdr(v136);
    stack[0] = v136;
    goto v333;

v334:
    v136 = stack[-1];
    v136 = ncons(v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = Lrplacd(nil, stack[-3], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-4];
    v136 = qcdr(v136);
    stack[-4] = v136;
    goto v168;

v37:
    v136 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v136); }

v283:
    v136 = stack[-8];
    v136 = Llength(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    stack[-9] = v136;
    v136 = stack[-1];
    v136 = (Lisp_Object)zerop(v136);
    v136 = v136 ? lisp_true : nil;
    env = stack[-10];
    if (v136 == nil) goto v240;
    v136 = (Lisp_Object)1; /* 0 */
    goto v268;

v268:
    stack[-7] = v136;
    v137 = stack[-9];
    v136 = stack[-2];
    v137 = plus2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-9];
    fn = elt(env, 7); /* binomial */
    v137 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-7];
    v136 = difference2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    goto v330;

v240:
    stack[-4] = stack[-9];
    v136 = stack[-1];
    v136 = sub1(v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v137 = plus2(stack[-4], v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    v136 = stack[-9];
    fn = elt(env, 7); /* binomial */
    v136 = (*qfn2(fn))(qenv(fn), v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-10];
    goto v268;
/* error exit handlers */
v329:
    popv(11);
    return nil;
}



/* Code for simppartdf */

static Lisp_Object CC_simppartdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simppartdf");
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
    fn = elt(env, 1); /* partitpartdf */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v85);
    }
/* error exit handlers */
v114:
    popv(1);
    return nil;
}



/* Code for spp */

static Lisp_Object CC_spp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v290, v291;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spp");
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
    v290 = v0;
/* end of prologue */
    v291 = v290;
    v291 = Lconsp(nil, v291);
    env = stack[0];
    if (v291 == nil) goto v6;
    v290 = qcar(v290);
    {
        popv(1);
        fn = elt(env, 2); /* kernelp */
        return (*qfn1(fn))(qenv(fn), v290);
    }

v6:
    v290 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v290); }
}



/* Code for incident1 */

static Lisp_Object MS_CDECL CC_incident1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v336, v14, v15, v337;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident1");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v14 = v47;
    v15 = v1;
    v337 = v0;
/* end of prologue */
    v336 = v337;
    v177 = v15;
    v177 = qcar(v177);
    v177 = qcar(v177);
    if (v336 == v177) goto v33;
    v336 = v337;
    v177 = v15;
    v177 = qcdr(v177);
    v177 = qcar(v177);
    v177 = qcar(v177);
    if (v336 == v177) goto v234;
    v336 = v337;
    v177 = v15;
    v177 = qcdr(v177);
    v177 = qcdr(v177);
    v177 = qcar(v177);
    v177 = qcar(v177);
    if (v336 == v177) goto v338;
    v177 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v177); }

v338:
    v177 = v15;
    v177 = qcar(v177);
    stack[-1] = qcar(v177);
    stack[0] = v14;
    v177 = v15;
    v177 = qcdr(v177);
    v177 = qcar(v177);
    v177 = qcar(v177);
    v336 = v14;
    v177 = cons(v177, v336);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-2];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v339;
    {
        Lisp_Object v277 = stack[-1];
        Lisp_Object v224 = stack[0];
        popv(3);
        return acons(v277, v224, v177);
    }

v234:
    v177 = v15;
    v177 = qcdr(v177);
    v177 = qcdr(v177);
    v177 = qcar(v177);
    stack[-1] = qcar(v177);
    stack[0] = v14;
    v177 = v15;
    v177 = qcar(v177);
    v177 = qcar(v177);
    v336 = v14;
    v177 = cons(v177, v336);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-2];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v339;
    {
        Lisp_Object v250 = stack[-1];
        Lisp_Object v12 = stack[0];
        popv(3);
        return acons(v250, v12, v177);
    }

v33:
    v177 = v15;
    v177 = qcdr(v177);
    v177 = qcar(v177);
    stack[-1] = qcar(v177);
    stack[0] = v14;
    v177 = v15;
    v177 = qcdr(v177);
    v177 = qcdr(v177);
    v177 = qcar(v177);
    v177 = qcar(v177);
    v336 = v14;
    v177 = cons(v177, v336);
    nil = C_nil;
    if (exception_pending()) goto v339;
    env = stack[-2];
    v177 = ncons(v177);
    nil = C_nil;
    if (exception_pending()) goto v339;
    {
        Lisp_Object v13 = stack[-1];
        Lisp_Object v262 = stack[0];
        popv(3);
        return acons(v13, v262, v177);
    }
/* error exit handlers */
v339:
    popv(3);
    return nil;
}



/* Code for quotexf!* */

static Lisp_Object CC_quotexfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotexf*");
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
    goto v114;

v114:
    v268 = stack[-2];
    if (v268 == nil) goto v251;
    v268 = stack[-2];
    v268 = qcar(v268);
    stack[0] = qcar(v268);
    v268 = stack[-2];
    v268 = qcar(v268);
    v230 = qcdr(v268);
    v268 = stack[-1];
    fn = elt(env, 1); /* quotfexf!*1 */
    v230 = (*qfn2(fn))(qenv(fn), v230, v268);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-4];
    v268 = stack[-3];
    v268 = acons(stack[0], v230, v268);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-4];
    stack[-3] = v268;
    v268 = stack[-2];
    v268 = qcdr(v268);
    stack[-2] = v268;
    goto v114;

v251:
    v268 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v268);
    }
/* error exit handlers */
v340:
    popv(5);
    return nil;
}



/* Code for arglength */

static Lisp_Object CC_arglength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v285;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arglength");
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
    v285 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*intstr */
    qvalue(elt(env, 1)) = nil; /* !*intstr */
    v31 = v285;
    if (v31 == nil) goto v232;
    v31 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v31; /* !*intstr */
    v31 = v285;
    fn = elt(env, 3); /* reval */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-1];
    v285 = v31;
    v31 = v285;
    if (!consp(v31)) goto v284;
    v31 = v285;
    v31 = qcdr(v31);
    v31 = Llength(nil, v31);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-1];
    goto v85;

v85:
    qvalue(elt(env, 1)) = stack[0]; /* !*intstr */
    { popv(2); return onevalue(v31); }

v284:
    v31 = (Lisp_Object)-15; /* -1 */
    goto v85;

v232:
    v31 = (Lisp_Object)1; /* 0 */
    goto v85;
/* error exit handlers */
v185:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*intstr */
    popv(2);
    return nil;
}



/* Code for make!-image */

static Lisp_Object CC_makeKimage(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v330, v343;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image");
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
    v330 = stack[-2];
    if (!consp(v330)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v330 = stack[-2];
    v330 = qcar(v330);
    if (!consp(v330)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v330 = stack[-2];
    v330 = qcar(v330);
    v330 = qcar(v330);
    v343 = qcar(v330);
    v330 = qvalue(elt(env, 1)); /* m!-image!-variable */
    if (equal(v343, v330)) goto v31;
    v343 = stack[-2];
    v330 = stack[-1];
    fn = elt(env, 3); /* evaluate!-in!-order */
    v330 = (*qfn2(fn))(qenv(fn), v343, v330);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-4];
    v343 = v330;
    v330 = v343;
    v330 = (Lisp_Object)zerop(v330);
    v330 = v330 ? lisp_true : nil;
    env = stack[-4];
    if (v330 == nil) { popv(5); return onevalue(v343); }
    v330 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v330); }

v31:
    v330 = stack[-2];
    v330 = qcar(v330);
    stack[-3] = qcar(v330);
    v330 = stack[-2];
    v330 = qcar(v330);
    v343 = qcdr(v330);
    v330 = stack[-1];
    fn = elt(env, 3); /* evaluate!-in!-order */
    v330 = (*qfn2(fn))(qenv(fn), v343, v330);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-4];
    v343 = v330;
    v330 = v343;
    v330 = (Lisp_Object)zerop(v330);
    v330 = v330 ? lisp_true : nil;
    env = stack[-4];
    if (v330 == nil) goto v241;
    v330 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v330;
    goto v24;

v24:
    v330 = stack[-2];
    v343 = qcdr(v330);
    v330 = stack[-1];
    v330 = CC_makeKimage(env, v343, v330);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-4];
    {
        Lisp_Object v338 = stack[-3];
        Lisp_Object v294 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v338, v294, v330);
    }

v241:
    v330 = v343;
    stack[0] = v330;
    goto v24;
/* error exit handlers */
v181:
    popv(5);
    return nil;
}



/* Code for bfprin0x */

static Lisp_Object CC_bfprin0x(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v299, v41, v270;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin0x");
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
    v41 = v1;
    v299 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bfexplode0x */
    v299 = (*qfn2(fn))(qenv(fn), v299, v41);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[0];
    v41 = v299;
    v41 = qcdr(v41);
    v41 = qcar(v41);
    v270 = v299;
    v270 = qcdr(v270);
    v270 = qcdr(v270);
    v270 = qcar(v270);
    v299 = qcar(v299);
    {
        popv(1);
        fn = elt(env, 2); /* bfprin!:lst */
        return (*qfnn(fn))(qenv(fn), 3, v299, v41, v270);
    }
/* error exit handlers */
v271:
    popv(1);
    return nil;
}



/* Code for valuechk */

static Lisp_Object CC_valuechk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260, v261, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for valuechk");
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
    v261 = stack[-1];
    v260 = elt(env, 1); /* number!-of!-args */
    v260 = get(v261, v260);
    env = stack[-3];
    stack[-2] = v260;
    if (v260 == nil) goto v191;
    v260 = stack[0];
    v261 = Llength(nil, v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    v260 = stack[-2];
    if (!(equal(v261, v260))) goto v151;

v191:
    v260 = stack[-2];
    if (!(v260 == nil)) goto v243;
    v260 = stack[0];
    if (v260 == nil) goto v243;
    v260 = stack[0];
    v260 = qcdr(v260);
    if (v260 == nil) goto v243;
    v261 = stack[-1];
    v260 = elt(env, 2); /* !:rd!: */
    v260 = get(v261, v260);
    env = stack[-3];
    if (!(v260 == nil)) goto v151;
    v261 = stack[-1];
    v260 = elt(env, 3); /* !:rn!: */
    v260 = get(v261, v260);
    env = stack[-3];
    if (!(v260 == nil)) goto v151;

v243:
    v261 = stack[-1];
    v260 = stack[0];
    v260 = cons(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    fn = elt(env, 9); /* opfchk!! */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    stack[0] = v260;
    v260 = stack[0];
    if (v260 == nil) goto v244;
    v261 = stack[0];
    v260 = elt(env, 7); /* list */
    if (!consp(v261)) goto v177;
    v261 = qcar(v261);
    if (!(v261 == v260)) goto v177;
    v226 = stack[0];
    v261 = (Lisp_Object)17; /* 1 */
    v260 = (Lisp_Object)17; /* 1 */
    v260 = acons(v226, v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    v260 = ncons(v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    v261 = v260;
    goto v181;

v181:
    v260 = (Lisp_Object)17; /* 1 */
    v260 = cons(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    stack[0] = v260;
    v260 = stack[0];
    fn = elt(env, 10); /* znumr */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    if (v260 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v261 = qvalue(elt(env, 8)); /* nil */
    v260 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v261, v260);

v177:
    v260 = stack[0];
    v261 = v260;
    goto v181;

v244:
    v260 = nil;
    { popv(4); return onevalue(v260); }

v151:
    v261 = elt(env, 4); /* "Wrong number of arguments to" */
    v260 = stack[-1];
    v260 = list2(v261, v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    v261 = v260;
    v260 = v261;
    qvalue(elt(env, 5)) = v260; /* errmsg!* */
    v260 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v260 == nil)) goto v245;
    v260 = v261;
    fn = elt(env, 11); /* lprie */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    goto v245;

v245:
    v260 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v345;
    env = stack[-3];
    goto v243;
/* error exit handlers */
v345:
    popv(4);
    return nil;
}



/* Code for mk!+inner!+product */

static Lisp_Object CC_mkLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v238, v296;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+inner+product");
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
    stack[-1] = v1;
    stack[-3] = v0;
/* end of prologue */
    v238 = stack[-3];
    fn = elt(env, 7); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    v238 = stack[-1];
    fn = elt(env, 7); /* get!+vec!+dim */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    if (equal(stack[0], v238)) goto v269;
    v238 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v238 == nil)) goto v328;
    v238 = elt(env, 2); /* "Error in Gram_schmidt: each list in input must be the same length." 
*/
    fn = elt(env, 8); /* lprie */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    goto v328;

v328:
    v238 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    goto v269;

v269:
    v296 = qvalue(elt(env, 3)); /* nil */
    v238 = (Lisp_Object)17; /* 1 */
    v238 = cons(v296, v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    stack[0] = v238;
    v238 = qvalue(elt(env, 4)); /* !*complex */
    if (v238 == nil) goto v340;
    v238 = stack[-1];
    fn = elt(env, 9); /* mk!+conjugate!+vec */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    stack[-4] = v238;
    goto v268;

v268:
    v238 = (Lisp_Object)17; /* 1 */
    stack[-2] = v238;
    goto v298;

v298:
    v238 = stack[-3];
    fn = elt(env, 7); /* get!+vec!+dim */
    v296 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    v238 = stack[-2];
    v238 = difference2(v296, v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    v238 = Lminusp(nil, v238);
    env = stack[-5];
    if (v238 == nil) goto v23;
    v238 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v238; /* !*sub2 */
    v238 = stack[0];
    fn = elt(env, 10); /* subs2 */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    stack[0] = v238;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v23:
    stack[-1] = stack[0];
    v296 = stack[-3];
    v238 = stack[-2];
    fn = elt(env, 11); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v296, v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    v296 = stack[-4];
    v238 = stack[-2];
    fn = elt(env, 11); /* get!+vec!+entry */
    v238 = (*qfn2(fn))(qenv(fn), v296, v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    fn = elt(env, 12); /* multsq */
    v238 = (*qfn2(fn))(qenv(fn), stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    fn = elt(env, 13); /* addsq */
    v238 = (*qfn2(fn))(qenv(fn), stack[-1], v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    stack[0] = v238;
    v238 = stack[-2];
    v238 = add1(v238);
    nil = C_nil;
    if (exception_pending()) goto v297;
    env = stack[-5];
    stack[-2] = v238;
    goto v298;

v340:
    v238 = stack[-1];
    stack[-4] = v238;
    goto v268;
/* error exit handlers */
v237:
    env = stack[-5];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v297:
    popv(6);
    return nil;
}



/* Code for pasf_smordtable */

static Lisp_Object MS_CDECL CC_pasf_smordtable(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v47, Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smordtable");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable");
#endif
    if (stack >= stacklimit)
    {
        push4(v7,v47,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v47,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v47;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v151 = stack[-1];
    v234 = stack[0];
    v234 = (Lisp_Object)lessp2(v151, v234);
    nil = C_nil;
    if (exception_pending()) goto v253;
    v234 = v234 ? lisp_true : nil;
    env = stack[-4];
    if (v234 == nil) goto v38;
    v151 = stack[-3];
    v234 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* pasf_smordtable2 */
        return (*qfn2(fn))(qenv(fn), v151, v234);
    }

v38:
    v151 = stack[-1];
    v234 = stack[0];
    v234 = (Lisp_Object)greaterp2(v151, v234);
    nil = C_nil;
    if (exception_pending()) goto v253;
    v234 = v234 ? lisp_true : nil;
    env = stack[-4];
    if (v234 == nil) goto v301;
    v151 = stack[-3];
    v234 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* pasf_smordtable1 */
        return (*qfn2(fn))(qenv(fn), v151, v234);
    }

v301:
    v234 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v234 == nil)) goto v184;
    v234 = elt(env, 2); /* "abused smordtable" */
    v234 = ncons(v234);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    fn = elt(env, 5); /* lprie */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-4];
    goto v184;

v184:
    v234 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v253;
    v234 = nil;
    { popv(5); return onevalue(v234); }
/* error exit handlers */
v253:
    popv(5);
    return nil;
}



/* Code for cgp_lbc */

static Lisp_Object CC_cgp_lbc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_lbc");
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
    fn = elt(env, 1); /* cgp_rp */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_lbc */
        return (*qfn1(fn))(qenv(fn), v85);
    }
/* error exit handlers */
v114:
    popv(1);
    return nil;
}



/* Code for intervalom */

static Lisp_Object CC_intervalom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181, v338;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalom");
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
    v180 = stack[-2];
    v180 = qcdr(v180);
    v180 = qcar(v180);
    stack[-3] = v180;
    v180 = stack[-2];
    v180 = qcar(v180);
    stack[-1] = v180;
    v181 = stack[-1];
    v180 = elt(env, 1); /* lowupperlimit */
    if (!(v181 == v180)) goto v271;
    v180 = elt(env, 2); /* integer_interval */
    stack[-1] = v180;
    v180 = qvalue(elt(env, 3)); /* nil */
    stack[-3] = v180;
    v180 = stack[-2];
    v338 = qcar(v180);
    v181 = qvalue(elt(env, 3)); /* nil */
    v180 = stack[-2];
    v180 = qcdr(v180);
    v180 = list2star(v338, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    stack[-2] = v180;
    goto v271;

v271:
    v181 = stack[-1];
    v180 = qvalue(elt(env, 4)); /* valid_om!* */
    v180 = Lassoc(nil, v181, v180);
    v180 = qcdr(v180);
    v180 = qcar(v180);
    stack[0] = v180;
    v180 = stack[-3];
    if (v180 == nil) goto v27;
    v180 = stack[-3];
    v180 = qcar(v180);
    v180 = qcdr(v180);
    v180 = qcar(v180);
    v181 = Lintern(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = qvalue(elt(env, 5)); /* interval!* */
    v180 = Lassoc(nil, v181, v180);
    v180 = qcdr(v180);
    v180 = qcar(v180);
    stack[-1] = v180;
    goto v27;

v27:
    v180 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* indent!* */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = stack[0];
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = elt(env, 9); /* """ name=""" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = stack[-1];
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = elt(env, 10); /* """/>" */
    v180 = Lprinc(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = stack[-2];
    v180 = qcdr(v180);
    v180 = qcdr(v180);
    fn = elt(env, 14); /* multiom */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v180 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v156;
    v180 = nil;
    { popv(5); return onevalue(v180); }
/* error exit handlers */
v156:
    popv(5);
    return nil;
}



/* Code for freeof */

static Lisp_Object CC_freeof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v292, v269;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof");
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
    v292 = stack[0];
    v186 = stack[-1];
    fn = elt(env, 2); /* smember */
    v186 = (*qfn2(fn))(qenv(fn), v292, v186);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    if (!(v186 == nil)) goto v6;
    v292 = stack[0];
    v186 = stack[-1];
    v269 = qvalue(elt(env, 1)); /* depl!* */
    v186 = Lassoc(nil, v186, v269);
    v186 = Lmember(nil, v292, v186);
    goto v6;

v6:
    v186 = (v186 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v186); }
/* error exit handlers */
v29:
    popv(3);
    return nil;
}



/* Code for tchscheme2 */

static Lisp_Object MS_CDECL CC_tchscheme2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tchscheme2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tchscheme2");
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
    v38 = (Lisp_Object)1; /* 0 */
    stack[0] = v38;
    goto v290;

v290:
    v185 = qvalue(elt(env, 1)); /* rowmax */
    v38 = stack[0];
    v38 = difference2(v185, v38);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-1];
    v38 = Lminusp(nil, v38);
    env = stack[-1];
    if (v38 == nil) goto v251;
    v38 = nil;
    { popv(2); return onevalue(v38); }

v251:
    v38 = stack[0];
    fn = elt(env, 3); /* removechild */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-1];
    v38 = stack[0];
    fn = elt(env, 4); /* to!*scheme */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-1];
    v38 = stack[0];
    v38 = add1(v38);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-1];
    stack[0] = v38;
    goto v290;
/* error exit handlers */
v292:
    popv(2);
    return nil;
}



/* Code for contposp */

static Lisp_Object CC_contposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v300, v246;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v300 = v0;
/* end of prologue */

v347:
    v246 = v300;
    v246 = (v246 == nil ? lisp_true : nil);
    if (!(v246 == nil)) return onevalue(v246);
    v246 = v300;
    v246 = qcar(v246);
    if (!consp(v246)) goto v290;
    v300 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v300);

v290:
    v300 = qcdr(v300);
    goto v347;
}



/* Code for exdfprn */

static Lisp_Object CC_exdfprn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exdfprn");
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
    v232 = elt(env, 1); /* "d" */
    fn = elt(env, 2); /* prin2!* */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-1];
    v232 = stack[0];
    v232 = qcdr(v232);
    v232 = qcar(v232);
    {
        popv(2);
        fn = elt(env, 3); /* rembras */
        return (*qfn1(fn))(qenv(fn), v232);
    }
/* error exit handlers */
v191:
    popv(2);
    return nil;
}



/* Code for endmodule */

static Lisp_Object MS_CDECL CC_endmodule(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endmodule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endmodule");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v31 = qvalue(elt(env, 1)); /* mode!-list!* */
    if (!(v31 == nil)) goto v6;
    v31 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v31 == nil)) goto v289;
    v31 = elt(env, 3); /* "ENDMODULE called outside module" */
    fn = elt(env, 9); /* lprie */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[0];
    goto v289;

v289:
    v31 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[0];
    goto v6;

v6:
    v31 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 5)) = v31; /* exportslist!* */
    v31 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 6)) = v31; /* importslist!* */
    v31 = qvalue(elt(env, 4)); /* nil */
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v285;
    env = stack[0];
    qvalue(elt(env, 7)) = v31; /* alglist!* */
    v31 = qvalue(elt(env, 1)); /* mode!-list!* */
    v31 = qcar(v31);
    qvalue(elt(env, 8)) = v31; /* !*mode */
    v31 = qvalue(elt(env, 1)); /* mode!-list!* */
    v31 = qcdr(v31);
    qvalue(elt(env, 1)) = v31; /* mode!-list!* */
    v31 = nil;
    { popv(1); return onevalue(v31); }
/* error exit handlers */
v285:
    popv(1);
    return nil;
}



/* Code for gfstorval */

static Lisp_Object CC_gfstorval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v290, v291, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfstorval");
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
    v290 = v1;
    v291 = v0;
/* end of prologue */
    v32 = v291;
    v291 = v290;
    v290 = qvalue(elt(env, 1)); /* !*xnlist */
    v290 = acons(v32, v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[0];
    qvalue(elt(env, 1)) = v290; /* !*xnlist */
    { popv(1); return onevalue(v290); }
/* error exit handlers */
v284:
    popv(1);
    return nil;
}



/* Code for natnump */

static Lisp_Object CC_natnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v300, v246;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for natnump");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v246 = v0;
/* end of prologue */
    v300 = v246;
    v300 = integerp(v300);
    if (v300 == nil) goto v6;
    v300 = (Lisp_Object)1; /* 0 */
        return Lgeq(nil, v246, v300);

v6:
    v300 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v300);
}



/* Code for asymmetrize!-inds */

static Lisp_Object CC_asymmetrizeKinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v368, v369;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for asymmetrize-inds");
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
    v368 = (Lisp_Object)1; /* 0 */
    stack[-10] = v368;
    v368 = stack[-9];
    stack[-7] = v368;
    v368 = stack[-7];
    if (v368 == nil) goto v274;
    v368 = stack[-7];
    v368 = qcar(v368);
    v369 = v368;
    if (!consp(v369)) goto v29;
    stack[-3] = v368;
    v368 = stack[-3];
    if (v368 == nil) goto v241;
    v368 = stack[-3];
    v368 = qcar(v368);
    v369 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v368 = (*qfn2(fn))(qenv(fn), v369, v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = qcar(v368);
    v368 = ncons(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-1] = v368;
    stack[-2] = v368;
    goto v27;

v27:
    v368 = stack[-3];
    v368 = qcdr(v368);
    stack[-3] = v368;
    v368 = stack[-3];
    if (v368 == nil) goto v223;
    stack[0] = stack[-1];
    v368 = stack[-3];
    v368 = qcar(v368);
    v369 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v368 = (*qfn2(fn))(qenv(fn), v369, v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = qcar(v368);
    v368 = ncons(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = Lrplacd(nil, stack[0], v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = stack[-1];
    v368 = qcdr(v368);
    stack[-1] = v368;
    goto v27;

v223:
    v368 = stack[-2];
    goto v186;

v186:
    v368 = ncons(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-5] = v368;
    stack[-6] = v368;
    goto v284;

v284:
    v368 = stack[-7];
    v368 = qcdr(v368);
    stack[-7] = v368;
    v368 = stack[-7];
    if (v368 == nil) goto v238;
    stack[-4] = stack[-5];
    v368 = stack[-7];
    v368 = qcar(v368);
    v369 = v368;
    if (!consp(v369)) goto v370;
    stack[-3] = v368;
    v368 = stack[-3];
    if (v368 == nil) goto v280;
    v368 = stack[-3];
    v368 = qcar(v368);
    v369 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v368 = (*qfn2(fn))(qenv(fn), v369, v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = qcar(v368);
    v368 = ncons(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-1] = v368;
    stack[-2] = v368;
    goto v371;

v371:
    v368 = stack[-3];
    v368 = qcdr(v368);
    stack[-3] = v368;
    v368 = stack[-3];
    if (v368 == nil) goto v169;
    stack[0] = stack[-1];
    v368 = stack[-3];
    v368 = qcar(v368);
    v369 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v368 = (*qfn2(fn))(qenv(fn), v369, v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = qcar(v368);
    v368 = ncons(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = Lrplacd(nil, stack[0], v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = stack[-1];
    v368 = qcdr(v368);
    stack[-1] = v368;
    goto v371;

v169:
    v368 = stack[-2];
    goto v336;

v336:
    v368 = ncons(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = Lrplacd(nil, stack[-4], v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = stack[-5];
    v368 = qcdr(v368);
    stack[-5] = v368;
    goto v284;

v280:
    v368 = qvalue(elt(env, 1)); /* nil */
    goto v336;

v370:
    v369 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v368 = (*qfn2(fn))(qenv(fn), v369, v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = qcar(v368);
    goto v336;

v238:
    v368 = stack[-6];
    goto v32;

v32:
    stack[0] = v368;
    v368 = stack[0];
    fn = elt(env, 3); /* repeats */
    v368 = (*qfn1(fn))(qenv(fn), v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    if (v368 == nil) goto v372;
    v368 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v368); }

v372:
    v368 = stack[0];
    v368 = qcar(v368);
    if (!consp(v368)) goto v164;
    v368 = stack[0];
    fn = elt(env, 4); /* indordln */
    v368 = (*qfn1(fn))(qenv(fn), v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v369 = v368;
    goto v373;

v373:
    stack[-5] = v369;
    v368 = stack[0];
    fn = elt(env, 5); /* permp */
    v368 = (*qfn2(fn))(qenv(fn), v369, v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    if (v368 == nil) goto v374;
    v368 = (Lisp_Object)17; /* 1 */
    goto v375;

v375:
    stack[0] = v368;
    v368 = stack[-9];
    v368 = qcar(v368);
    if (!consp(v368)) goto v153;
    v368 = stack[-9];
    fn = elt(env, 6); /* flatindl */
    v368 = (*qfn1(fn))(qenv(fn), v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-9] = v368;
    v368 = stack[-5];
    fn = elt(env, 6); /* flatindl */
    v368 = (*qfn1(fn))(qenv(fn), v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-5] = v368;
    goto v153;

v153:
    v369 = stack[-9];
    v368 = stack[-5];
    fn = elt(env, 7); /* pair */
    v368 = (*qfn2(fn))(qenv(fn), v369, v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-5] = v368;
    stack[-6] = stack[0];
    v368 = stack[-8];
    stack[-7] = v368;
    v368 = stack[-7];
    if (v368 == nil) goto v140;
    v368 = stack[-7];
    v368 = qcar(v368);
    stack[-1] = v368;
    v368 = stack[-5];
    if (v368 == nil) goto v376;
    v368 = stack[-5];
    v368 = qcar(v368);
    stack[0] = qcar(v368);
    v368 = stack[-10];
    v368 = add1(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-10] = v368;
    if (!(equal(stack[0], v368))) goto v376;
    v368 = stack[-5];
    v368 = qcar(v368);
    v368 = qcdr(v368);
    v369 = v368;
    v368 = stack[-5];
    v368 = qcdr(v368);
    stack[-5] = v368;
    v368 = v369;
    goto v308;

v308:
    v368 = ncons(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-3] = v368;
    stack[-4] = v368;
    goto v377;

v377:
    v368 = stack[-7];
    v368 = qcdr(v368);
    stack[-7] = v368;
    v368 = stack[-7];
    if (v368 == nil) goto v334;
    stack[-2] = stack[-3];
    v368 = stack[-7];
    v368 = qcar(v368);
    stack[-1] = v368;
    v368 = stack[-5];
    if (v368 == nil) goto v378;
    v368 = stack[-5];
    v368 = qcar(v368);
    stack[0] = qcar(v368);
    v368 = stack[-10];
    v368 = add1(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    stack[-10] = v368;
    if (!(equal(stack[0], v368))) goto v378;
    v368 = stack[-5];
    v368 = qcar(v368);
    v368 = qcdr(v368);
    v369 = v368;
    v368 = stack[-5];
    v368 = qcdr(v368);
    stack[-5] = v368;
    v368 = v369;
    goto v379;

v379:
    v368 = ncons(v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = Lrplacd(nil, stack[-2], v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = stack[-3];
    v368 = qcdr(v368);
    stack[-3] = v368;
    goto v377;

v378:
    v368 = stack[-1];
    goto v379;

v334:
    v368 = stack[-4];
    goto v380;

v380:
    {
        Lisp_Object v381 = stack[-6];
        popv(12);
        return cons(v381, v368);
    }

v376:
    v368 = stack[-1];
    goto v308;

v140:
    v368 = qvalue(elt(env, 1)); /* nil */
    goto v380;

v374:
    v368 = (Lisp_Object)-15; /* -1 */
    goto v375;

v164:
    v368 = stack[0];
    fn = elt(env, 8); /* indordn */
    v368 = (*qfn1(fn))(qenv(fn), v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v369 = v368;
    goto v373;

v241:
    v368 = qvalue(elt(env, 1)); /* nil */
    goto v186;

v29:
    v369 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v368 = (*qfn2(fn))(qenv(fn), v369, v368);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-11];
    v368 = qcar(v368);
    goto v186;

v274:
    v368 = qvalue(elt(env, 1)); /* nil */
    goto v32;
/* error exit handlers */
v200:
    popv(12);
    return nil;
}



/* Code for s_noparents */

static Lisp_Object CC_s_noparents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s_noparents");
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
    goto v85;

v85:
    v283 = stack[0];
    if (v283 == nil) goto v232;
    v283 = stack[0];
    v283 = qcar(v283);
    fn = elt(env, 1); /* has_parents */
    v283 = (*qfn1(fn))(qenv(fn), v283);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    if (v283 == nil) goto v288;
    v283 = stack[0];
    v283 = qcdr(v283);
    stack[0] = v283;
    goto v85;

v288:
    v283 = stack[0];
    v28 = qcar(v283);
    v283 = stack[-1];
    v283 = cons(v28, v283);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    stack[-1] = v283;
    v283 = stack[0];
    v283 = qcdr(v283);
    stack[0] = v283;
    goto v85;

v232:
    v283 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v283);
    }
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for negex */

static Lisp_Object CC_negex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negex");
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
    goto v85;

v85:
    v283 = stack[-1];
    if (v283 == nil) goto v232;
    v283 = stack[-1];
    v283 = qcar(v283);
    stack[0] = qcar(v283);
    v283 = stack[-1];
    v283 = qcar(v283);
    v283 = qcdr(v283);
    fn = elt(env, 1); /* negf */
    v28 = (*qfn1(fn))(qenv(fn), v283);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-3];
    v283 = stack[-2];
    v283 = acons(stack[0], v28, v283);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-3];
    stack[-2] = v283;
    v283 = stack[-1];
    v283 = qcdr(v283);
    stack[-1] = v283;
    goto v85;

v232:
    v283 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v283);
    }
/* error exit handlers */
v270:
    popv(4);
    return nil;
}



/* Code for cali!=min */

static Lisp_Object MS_CDECL CC_caliMmin(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v24, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cali=min");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cali=min");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v47;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v114:
    v151 = stack[-1];
    if (v151 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v25 = stack[-2];
    v151 = stack[-1];
    v24 = qcar(v151);
    v151 = stack[0];
    fn = elt(env, 1); /* listtest */
    v151 = (*qfnn(fn))(qenv(fn), 3, v25, v24, v151);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-3];
    if (!(v151 == nil)) goto v287;
    v151 = stack[-1];
    v25 = qcdr(v151);
    v151 = stack[-1];
    v24 = qcar(v151);
    v151 = stack[0];
    fn = elt(env, 1); /* listtest */
    v151 = (*qfnn(fn))(qenv(fn), 3, v25, v24, v151);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-3];
    if (!(v151 == nil)) goto v287;
    v151 = stack[-1];
    v24 = qcar(v151);
    v151 = stack[-2];
    v151 = cons(v24, v151);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-3];
    stack[-2] = v151;
    v151 = stack[-1];
    v151 = qcdr(v151);
    stack[-1] = v151;
    goto v114;

v287:
    v151 = stack[-1];
    v151 = qcdr(v151);
    stack[-1] = v151;
    goto v114;
/* error exit handlers */
v266:
    popv(4);
    return nil;
}



/* Code for num_signsort */

static Lisp_Object CC_num_signsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num_signsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v191 = v0;
/* end of prologue */
    v289 = v191;
    v191 = elt(env, 1); /* lambda_l9cw2w_9 */
    {
        fn = elt(env, 2); /* ad_signsort */
        return (*qfn2(fn))(qenv(fn), v289, v191);
    }
}



/* Code for lambda_l9cw2w_9 */

static Lisp_Object CC_lambda_l9cw2w_9(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v289, v286;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9cw2w_9");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v289 = v1;
    v286 = v0;
/* end of prologue */
        return Lleq(nil, v286, v289);
}



/* Code for balance_mod */

static Lisp_Object CC_balance_mod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for balance_mod");
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
    v28 = stack[-1];
    v283 = stack[-1];
    v28 = plus2(v28, v283);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v283 = stack[0];
    v283 = (Lisp_Object)greaterp2(v28, v283);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v283 = v283 ? lisp_true : nil;
    if (v283 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v28 = stack[-1];
    v283 = stack[0];
    popv(3);
    return difference2(v28, v283);
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for simpquot */

static Lisp_Object CC_simpquot(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v383, v275;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpquot");
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
    v383 = stack[-1];
    v383 = qcar(v383);
    fn = elt(env, 10); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    v383 = stack[-1];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    fn = elt(env, 10); /* simp */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v383;
    v383 = stack[0];
    v383 = qcar(v383);
    if (v383 == nil) goto v287;
    v275 = qvalue(elt(env, 5)); /* dmode!* */
    v383 = elt(env, 6); /* (!:rd!: !:cr!:) */
    v383 = Lmemq(nil, v275, v383);
    if (v383 == nil) goto v4;
    v383 = stack[0];
    v383 = qcar(v383);
    if (!consp(v383)) goto v253;
    v383 = stack[0];
    v383 = qcar(v383);
    v383 = qcar(v383);
    if (!(!consp(v383))) goto v4;

v253:
    v383 = stack[0];
    v383 = qcdr(v383);
    if (!consp(v383)) goto v23;
    v383 = stack[0];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    if (!(!consp(v383))) goto v4;

v23:
    v383 = stack[-2];
    v383 = qcdr(v383);
    if (!consp(v383)) goto v243;
    v383 = stack[-2];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    if (!(!consp(v383))) goto v4;

v243:
    v383 = stack[0];
    v383 = qcdr(v383);
    if (!consp(v383)) goto v46;
    v383 = stack[0];
    v383 = qcdr(v383);
    v275 = qcar(v383);
    v383 = elt(env, 7); /* onep */
    v275 = get(v275, v383);
    env = stack[-3];
    v383 = stack[0];
    v383 = qcdr(v383);
    v383 = Lapply1(nil, v275, v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    goto v343;

v343:
    if (v383 == nil) goto v4;
    v383 = stack[-2];
    v383 = qcdr(v383);
    if (!consp(v383)) goto v176;
    v383 = stack[-2];
    v383 = qcdr(v383);
    v275 = qcar(v383);
    v383 = elt(env, 7); /* onep */
    v275 = get(v275, v383);
    env = stack[-3];
    v383 = stack[-2];
    v383 = qcdr(v383);
    v383 = Lapply1(nil, v275, v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    goto v178;

v178:
    if (v383 == nil) goto v4;
    v383 = stack[-2];
    v383 = qcar(v383);
    if (v383 == nil) goto v11;
    v383 = stack[-2];
    v275 = qcar(v383);
    v383 = stack[0];
    v383 = qcar(v383);
    fn = elt(env, 11); /* divd */
    v383 = (*qfn2(fn))(qenv(fn), v275, v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    v275 = v383;
    goto v384;

v384:
    v383 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v275, v383);

v11:
    v383 = qvalue(elt(env, 8)); /* nil */
    v275 = v383;
    goto v384;

v4:
    stack[0] = stack[-2];
    v383 = stack[-1];
    v383 = qcdr(v383);
    fn = elt(env, 12); /* simprecip */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    fn = elt(env, 13); /* multsq */
    v383 = (*qfn2(fn))(qenv(fn), stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    stack[-1] = v383;
    v383 = qvalue(elt(env, 9)); /* !*modular */
    if (v383 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v383 = stack[-1];
    v383 = qcdr(v383);
    if (!(v383 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v383 = elt(env, 4); /* "Zero divisor" */
    v275 = v383;
    v383 = v275;
    qvalue(elt(env, 2)) = v383; /* errmsg!* */
    v383 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v383 == nil)) goto v385;
    v383 = v275;
    fn = elt(env, 14); /* lprie */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    goto v385;

v385:
    v383 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v373;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v176:
    v383 = stack[-2];
    v383 = qcdr(v383);
    v383 = Lonep(nil, v383);
    env = stack[-3];
    goto v178;

v46:
    v383 = stack[0];
    v383 = qcdr(v383);
    v383 = Lonep(nil, v383);
    env = stack[-3];
    goto v343;

v287:
    v383 = stack[-2];
    v383 = qcar(v383);
    if (v383 == nil) goto v300;
    v383 = elt(env, 4); /* "Zero divisor" */
    v275 = v383;
    v383 = v275;
    qvalue(elt(env, 2)) = v383; /* errmsg!* */
    v383 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v383 == nil)) goto v247;
    v383 = v275;
    fn = elt(env, 14); /* lprie */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    goto v247;

v247:
    v383 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v373;
    v383 = nil;
    { popv(4); return onevalue(v383); }

v300:
    v383 = elt(env, 1); /* "0/0 formed" */
    v275 = v383;
    v383 = v275;
    qvalue(elt(env, 2)) = v383; /* errmsg!* */
    v383 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v383 == nil)) goto v185;
    v383 = v275;
    fn = elt(env, 14); /* lprie */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v373;
    env = stack[-3];
    goto v185;

v185:
    v383 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v373;
    v383 = nil;
    { popv(4); return onevalue(v383); }
/* error exit handlers */
v373:
    popv(4);
    return nil;
}



/* Code for findnthroot */

static Lisp_Object CC_findnthroot(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v7;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findnthroot");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v7 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v7);
}



/* Code for pasf_anegateat */

static Lisp_Object CC_pasf_anegateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v366, v367;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_anegateat");
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
    v367 = stack[-1];
    v366 = elt(env, 1); /* true */
    if (v367 == v366) goto v287;
    v367 = stack[-1];
    v366 = elt(env, 2); /* false */
    if (v367 == v366) goto v287;
    v366 = stack[-1];
    v366 = qcar(v366);
    v366 = Lconsp(nil, v366);
    env = stack[-3];
    if (v366 == nil) goto v268;
    v366 = stack[-1];
    v366 = qcar(v366);
    v366 = qcar(v366);
    v367 = v366;
    goto v232;

v232:
    v366 = elt(env, 3); /* (cong ncong) */
    v366 = Lmemq(nil, v367, v366);
    if (v366 == nil) goto v14;
    v367 = stack[-1];
    v366 = elt(env, 1); /* true */
    if (v367 == v366) goto v266;
    v367 = stack[-1];
    v366 = elt(env, 2); /* false */
    if (v367 == v366) goto v266;
    v366 = stack[-1];
    v366 = qcar(v366);
    v366 = Lconsp(nil, v366);
    env = stack[-3];
    if (v366 == nil) goto v346;
    v366 = stack[-1];
    v366 = qcar(v366);
    v366 = qcar(v366);
    goto v253;

v253:
    fn = elt(env, 4); /* pasf_anegrel */
    v367 = (*qfn1(fn))(qenv(fn), v366);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-3];
    v366 = stack[-1];
    v366 = qcar(v366);
    v366 = qcdr(v366);
    fn = elt(env, 5); /* pasf_mkop */
    stack[-2] = (*qfn2(fn))(qenv(fn), v367, v366);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-3];
    v366 = stack[-1];
    v366 = qcdr(v366);
    v366 = qcar(v366);
    fn = elt(env, 6); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v366);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-3];
    v366 = stack[-1];
    v366 = qcdr(v366);
    v366 = qcdr(v366);
    v366 = qcar(v366);
    fn = elt(env, 6); /* negf */
    v366 = (*qfn1(fn))(qenv(fn), v366);
    nil = C_nil;
    if (exception_pending()) goto v324;
    {
        Lisp_Object v387 = stack[-2];
        Lisp_Object v169 = stack[0];
        popv(4);
        return list3(v387, v169, v366);
    }

v346:
    v366 = stack[-1];
    v366 = qcar(v366);
    goto v253;

v266:
    v366 = stack[-1];
    goto v253;

v14:
    v367 = stack[-1];
    v366 = elt(env, 1); /* true */
    if (v367 == v366) goto v176;
    v367 = stack[-1];
    v366 = elt(env, 2); /* false */
    if (v367 == v366) goto v176;
    v366 = stack[-1];
    v366 = qcar(v366);
    v366 = Lconsp(nil, v366);
    env = stack[-3];
    if (v366 == nil) goto v157;
    v366 = stack[-1];
    v366 = qcar(v366);
    v366 = qcar(v366);
    goto v178;

v178:
    fn = elt(env, 4); /* pasf_anegrel */
    stack[-2] = (*qfn1(fn))(qenv(fn), v366);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-3];
    v366 = stack[-1];
    v366 = qcdr(v366);
    v366 = qcar(v366);
    fn = elt(env, 6); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v366);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-3];
    v366 = stack[-1];
    v366 = qcdr(v366);
    v366 = qcdr(v366);
    v366 = qcar(v366);
    fn = elt(env, 6); /* negf */
    v366 = (*qfn1(fn))(qenv(fn), v366);
    nil = C_nil;
    if (exception_pending()) goto v324;
    {
        Lisp_Object v170 = stack[-2];
        Lisp_Object v382 = stack[0];
        popv(4);
        return list3(v170, v382, v366);
    }

v157:
    v366 = stack[-1];
    v366 = qcar(v366);
    goto v178;

v176:
    v366 = stack[-1];
    goto v178;

v268:
    v366 = stack[-1];
    v366 = qcar(v366);
    v367 = v366;
    goto v232;

v287:
    v366 = stack[-1];
    v367 = v366;
    goto v232;
/* error exit handlers */
v324:
    popv(4);
    return nil;
}



/* Code for aex_subrp */

static Lisp_Object MS_CDECL CC_aex_subrp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v47, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v292, v269;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_subrp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_subrp");
#endif
    if (stack >= stacklimit)
    {
        push3(v47,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v47);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v47;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v186 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v269 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-3];
    v292 = stack[-1];
    v186 = stack[0];
    fn = elt(env, 3); /* ratpoly_sub */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v269, v292, v186);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-3];
    v186 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v269 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-3];
    v292 = qvalue(elt(env, 1)); /* nil */
    v186 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v41 = stack[0];
        popv(4);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v41, v269, v292, v186);
    }
/* error exit handlers */
v299:
    popv(4);
    return nil;
}



/* Code for minusrd */

static Lisp_Object MS_CDECL CC_minusrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v285;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minusrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusrd");
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
    fn = elt(env, 1); /* mathml */
    v31 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-1];
    stack[0] = v31;
    fn = elt(env, 1); /* mathml */
    v31 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-1];
    v285 = v31;
    if (v285 == nil) goto v251;
    v285 = stack[0];
    fn = elt(env, 2); /* alg_difference */
    v31 = (*qfn2(fn))(qenv(fn), v285, v31);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-1];
    stack[0] = v31;
    fn = elt(env, 3); /* lex */
    v31 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v251:
    v31 = stack[0];
    fn = elt(env, 4); /* alg_minus */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v185;
    stack[0] = v31;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v185:
    popv(2);
    return nil;
}



setup_type const u35_setup[] =
{
    {"setmatelem",              too_few_2,      CC_setmatelem, wrong_no_2},
    {"prepsq*1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_prepsqH1},
    {"*g2lex",                  CC_Hg2lex,      too_many_1,    wrong_no_1},
    {"inormmat",                CC_inormmat,    too_many_1,    wrong_no_1},
    {"small-primep",            CC_smallKprimep,too_many_1,    wrong_no_1},
    {"general-multiply-by-constant-mod-p",too_few_2,CC_generalKmultiplyKbyKconstantKmodKp,wrong_no_2},
    {"preptayexp",              CC_preptayexp,  too_many_1,    wrong_no_1},
    {"ratpoly_sgn",             CC_ratpoly_sgn, too_many_1,    wrong_no_1},
    {"bc_mkat",                 too_few_2,      CC_bc_mkat,    wrong_no_2},
    {"omattrir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_omattrir},
    {"letmtr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr},
    {"a2bc",                    CC_a2bc,        too_many_1,    wrong_no_1},
    {"rand-mons-sparse",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_randKmonsKsparse},
    {"simppartdf",              CC_simppartdf,  too_many_1,    wrong_no_1},
    {"spp",                     CC_spp,         too_many_1,    wrong_no_1},
    {"incident1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident1},
    {"quotexf*",                too_few_2,      CC_quotexfH,   wrong_no_2},
    {"arglength",               CC_arglength,   too_many_1,    wrong_no_1},
    {"make-image",              too_few_2,      CC_makeKimage, wrong_no_2},
    {"bfprin0x",                too_few_2,      CC_bfprin0x,   wrong_no_2},
    {"valuechk",                too_few_2,      CC_valuechk,   wrong_no_2},
    {"mk+inner+product",        too_few_2,      CC_mkLinnerLproduct,wrong_no_2},
    {"pasf_smordtable",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smordtable},
    {"cgp_lbc",                 CC_cgp_lbc,     too_many_1,    wrong_no_1},
    {"intervalom",              CC_intervalom,  too_many_1,    wrong_no_1},
    {"freeof",                  too_few_2,      CC_freeof,     wrong_no_2},
    {"tchscheme2",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_tchscheme2},
    {"contposp",                CC_contposp,    too_many_1,    wrong_no_1},
    {"exdfprn",                 CC_exdfprn,     too_many_1,    wrong_no_1},
    {"endmodule",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_endmodule},
    {"gfstorval",               too_few_2,      CC_gfstorval,  wrong_no_2},
    {"natnump",                 CC_natnump,     too_many_1,    wrong_no_1},
    {"asymmetrize-inds",        too_few_2,      CC_asymmetrizeKinds,wrong_no_2},
    {"s_noparents",             CC_s_noparents, too_many_1,    wrong_no_1},
    {"negex",                   CC_negex,       too_many_1,    wrong_no_1},
    {"cali=min",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_caliMmin},
    {"num_signsort",            CC_num_signsort,too_many_1,    wrong_no_1},
    {"lambda_l9cw2w_9",         too_few_2,      CC_lambda_l9cw2w_9,wrong_no_2},
    {"balance_mod",             too_few_2,      CC_balance_mod,wrong_no_2},
    {"simpquot",                CC_simpquot,    too_many_1,    wrong_no_1},
    {"findnthroot",             CC_findnthroot, too_many_1,    wrong_no_1},
    {"pasf_anegateat",          CC_pasf_anegateat,too_many_1,  wrong_no_1},
    {"aex_subrp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrp},
    {"minusrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minusrd},
    {NULL, (one_args *)"u35", (two_args *)"111 9592072 5241356", 0}
};

/* end of generated code */
