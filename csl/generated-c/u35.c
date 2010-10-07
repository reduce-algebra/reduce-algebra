
/* $destdir\u35.c        Machine generated C code */

/* Signature: 00000000 07-Oct-2010 */

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


/* Code for rsubla */

static Lisp_Object CC_rsubla(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v11;
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
    v10 = stack[-1];
    if (v10 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v10 = stack[0];
    if (v10 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v10 = stack[0];
    if (!consp(v10)) goto v12;
    v11 = stack[-1];
    v10 = stack[0];
    v10 = qcar(v10);
    stack[-2] = CC_rsubla(env, v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v11 = stack[-1];
    v10 = stack[0];
    v10 = qcdr(v10);
    v10 = CC_rsubla(env, v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    {
        Lisp_Object v14 = stack[-2];
        popv(4);
        return cons(v14, v10);
    }

v12:
    v11 = stack[0];
    v10 = stack[-1];
    fn = elt(env, 1); /* rassoc */
    v10 = (*qfn2(fn))(qenv(fn), v11, v10);
    nil = C_nil;
    if (exception_pending()) goto v13;
    v11 = v10;
    if (v10 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v10 = v11;
    v10 = qcar(v10);
    { popv(4); return onevalue(v10); }
/* error exit handlers */
v13:
    popv(4);
    return nil;
}



/* Code for s_world_names */

static Lisp_Object CC_s_world_names(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20;
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
    v20 = v0;
/* end of prologue */
    v20 = qcar(v20);
    stack[-3] = v20;
    v20 = stack[-3];
    if (v20 == nil) goto v21;
    v20 = stack[-3];
    v20 = qcar(v20);
    v20 = qcar(v20);
    v20 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    stack[-1] = v20;
    stack[-2] = v20;
    goto v23;

v23:
    v20 = stack[-3];
    v20 = qcdr(v20);
    stack[-3] = v20;
    v20 = stack[-3];
    if (v20 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v20 = stack[-3];
    v20 = qcar(v20);
    v20 = qcar(v20);
    v20 = ncons(v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    v20 = Lrplacd(nil, stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-4];
    v20 = stack[-1];
    v20 = qcdr(v20);
    stack[-1] = v20;
    goto v23;

v21:
    v20 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v20); }
/* error exit handlers */
v22:
    popv(5);
    return nil;
}



/* Code for fs!:timescoeff */

static Lisp_Object CC_fsTtimescoeff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52, v53, v54;
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

v55:
    v51 = stack[-2];
    if (v51 == nil) goto v56;
    v53 = stack[-3];
    v52 = stack[-2];
    v51 = (Lisp_Object)1; /* 0 */
    v51 = *(Lisp_Object *)((char *)v52 + (CELL-TAG_VECTOR) + ((int32_t)v51/(16/CELL)));
    fn = elt(env, 4); /* multsq */
    v51 = (*qfn2(fn))(qenv(fn), v53, v51);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    stack[0] = v51;
    v52 = stack[0];
    v51 = elt(env, 2); /* (nil . 1) */
    if (equal(v52, v51)) goto v58;
    v51 = (Lisp_Object)49; /* 3 */
    v51 = Lmkvect(nil, v51);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    stack[-4] = v51;
    v53 = stack[-4];
    v52 = (Lisp_Object)1; /* 0 */
    v51 = stack[0];
    *(Lisp_Object *)((char *)v53 + (CELL-TAG_VECTOR) + ((int32_t)v52/(16/CELL))) = v51;
    v54 = stack[-4];
    v53 = (Lisp_Object)17; /* 1 */
    v52 = stack[-2];
    v51 = (Lisp_Object)17; /* 1 */
    v51 = *(Lisp_Object *)((char *)v52 + (CELL-TAG_VECTOR) + ((int32_t)v51/(16/CELL)));
    *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL))) = v51;
    v54 = stack[-4];
    v53 = (Lisp_Object)33; /* 2 */
    v52 = stack[-2];
    v51 = (Lisp_Object)33; /* 2 */
    v51 = *(Lisp_Object *)((char *)v52 + (CELL-TAG_VECTOR) + ((int32_t)v51/(16/CELL)));
    *(Lisp_Object *)((char *)v54 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL))) = v51;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)49; /* 3 */
    v53 = stack[-3];
    v52 = stack[-2];
    v51 = (Lisp_Object)49; /* 3 */
    v51 = *(Lisp_Object *)((char *)v52 + (CELL-TAG_VECTOR) + ((int32_t)v51/(16/CELL)));
    v51 = CC_fsTtimescoeff(env, v53, v51);
    nil = C_nil;
    if (exception_pending()) goto v57;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v51;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v58:
    v51 = elt(env, 3); /* "zero in times" */
    v51 = Lprint(nil, v51);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-5];
    v53 = stack[-3];
    v52 = stack[-2];
    v51 = (Lisp_Object)49; /* 3 */
    v51 = *(Lisp_Object *)((char *)v52 + (CELL-TAG_VECTOR) + ((int32_t)v51/(16/CELL)));
    stack[-3] = v53;
    stack[-2] = v51;
    goto v55;

v56:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v51); }
/* error exit handlers */
v57:
    popv(6);
    return nil;
}



/* Code for f2df */

static Lisp_Object CC_f2df(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v25, v26;
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
    v68 = stack[0];
    if (!consp(v68)) goto v69;
    v68 = stack[0];
    v68 = qcar(v68);
    if (!consp(v68)) goto v69;
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v25 = qcar(v68);
    v68 = qvalue(elt(env, 1)); /* zlist */
    v68 = Lmember(nil, v25, v68);
    if (v68 == nil) goto v70;
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v26 = qcar(v68);
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcar(v68);
    v25 = qcdr(v68);
    v68 = qvalue(elt(env, 1)); /* zlist */
    fn = elt(env, 3); /* vp2df */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v26, v25, v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    v68 = CC_f2df(env, v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    fn = elt(env, 4); /* multdf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v68 = stack[0];
    v68 = qcdr(v68);
    v68 = CC_f2df(env, v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    {
        Lisp_Object v72 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v72, v68);
    }

v70:
    v68 = stack[0];
    v68 = qcar(v68);
    v25 = qcar(v68);
    v68 = (Lisp_Object)17; /* 1 */
    v26 = cons(v25, v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v25 = qvalue(elt(env, 2)); /* nil */
    v68 = (Lisp_Object)17; /* 1 */
    stack[-1] = acons(v26, v25, v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    v68 = CC_f2df(env, v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    fn = elt(env, 6); /* multdfconst */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v68 = stack[0];
    v68 = qcdr(v68);
    v68 = CC_f2df(env, v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    {
        Lisp_Object v73 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v73, v68);
    }

v69:
    v25 = stack[0];
    v68 = (Lisp_Object)17; /* 1 */
    v68 = cons(v25, v68);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* dfconst */
        return (*qfn1(fn))(qenv(fn), v68);
    }
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for nlist */

static Lisp_Object CC_nlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v76;
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
    goto v24;

v24:
    v76 = stack[0];
    v58 = (Lisp_Object)1; /* 0 */
    if (v76 == v58) goto v77;
    v76 = stack[-1];
    v58 = stack[-2];
    v58 = cons(v76, v58);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    stack[-2] = v58;
    v58 = stack[0];
    v58 = sub1(v58);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    stack[0] = v58;
    goto v24;

v77:
    v58 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v58);
    }
/* error exit handlers */
v16:
    popv(4);
    return nil;
}



/* Code for pasf_smordtable1 */

static Lisp_Object CC_pasf_smordtable1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v79, v80;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v1;
    v79 = v0;
/* end of prologue */
    v80 = elt(env, 1); /* ((lessp (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (leq (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false)
 (cong nil) (ncong nil)) (equal (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (neq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong n
il) (ncong nil)) (geq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)) (greaterp (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong 
nil))) */
    v79 = Latsoc(nil, v79, v80);
    v12 = Latsoc(nil, v12, v79);
    v12 = qcdr(v12);
    return onevalue(v12);
}



/* Code for dvfsf_simplat1 */

static Lisp_Object CC_dvfsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v48, v4;
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
    v50 = stack[-2];
    fn = elt(env, 3); /* dvfsf_op */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v4 = v50;
    v48 = v4;
    v50 = elt(env, 1); /* equal */
    if (v48 == v50) goto v9;
    v48 = v4;
    v50 = elt(env, 2); /* neq */
    if (v48 == v50) goto v9;
    stack[-3] = v4;
    v50 = stack[-2];
    fn = elt(env, 4); /* dvfsf_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v50 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2r */
    v48 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v50 = stack[-1];
    {
        Lisp_Object v84 = stack[-3];
        Lisp_Object v85 = stack[0];
        popv(5);
        fn = elt(env, 6); /* dvfsf_saval */
        return (*qfnn(fn))(qenv(fn), 4, v84, v85, v48, v50);
    }

v9:
    stack[0] = v4;
    v50 = stack[-2];
    fn = elt(env, 4); /* dvfsf_arg2l */
    v48 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v50 = stack[-1];
    {
        Lisp_Object v13 = stack[0];
        popv(5);
        fn = elt(env, 7); /* dvfsf_safield */
        return (*qfnn(fn))(qenv(fn), 3, v13, v48, v50);
    }
/* error exit handlers */
v83:
    popv(5);
    return nil;
}



/* Code for bvarom */

static Lisp_Object CC_bvarom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v76;
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
    v58 = stack[0];
    v58 = qcar(v58);
    v58 = Lconsp(nil, v58);
    env = stack[-1];
    if (v58 == nil) goto v56;
    v58 = stack[0];
    v58 = qcar(v58);
    v76 = qcar(v58);
    v58 = elt(env, 1); /* bvar */
    if (!(v76 == v58)) goto v56;
    v58 = stack[0];
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = qcar(v58);
    fn = elt(env, 2); /* objectom */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    v58 = stack[0];
    v58 = qcdr(v58);
    v58 = CC_bvarom(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v87;
    goto v56;

v56:
    v58 = nil;
    { popv(2); return onevalue(v58); }
/* error exit handlers */
v87:
    popv(2);
    return nil;
}



/* Code for ps!:arg!-values */

static Lisp_Object CC_psTargKvalues(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99, v100;
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
    v99 = v0;
/* end of prologue */
    v98 = v99;
    stack[-4] = qcar(v98);
    v98 = v99;
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[-3];
    if (v98 == nil) goto v78;
    v98 = stack[-3];
    v98 = qcar(v98);
    v100 = v98;
    v98 = v100;
    if (!consp(v98)) goto v64;
    v98 = v100;
    v99 = qcar(v98);
    v98 = elt(env, 2); /* !:ps!: */
    if (v99 == v98) goto v65;
    v98 = v100;
    v99 = qcar(v98);
    v98 = elt(env, 3); /* dname */
    v98 = get(v99, v98);
    env = stack[-5];
    if (!(v98 == nil)) goto v64;

v65:
    v98 = v100;
    v98 = Lconsp(nil, v98);
    env = stack[-5];
    if (v98 == nil) goto v101;
    v98 = v100;
    v99 = qcar(v98);
    v98 = elt(env, 2); /* !:ps!: */
    if (!(v99 == v98)) goto v101;
    v98 = v100;
    fn = elt(env, 4); /* ps!:value */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    goto v9;

v9:
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    stack[-1] = v98;
    stack[-2] = v98;
    goto v103;

v103:
    v98 = stack[-3];
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[-3];
    if (v98 == nil) goto v104;
    stack[0] = stack[-1];
    v98 = stack[-3];
    v98 = qcar(v98);
    v100 = v98;
    v98 = v100;
    if (!consp(v98)) goto v105;
    v98 = v100;
    v99 = qcar(v98);
    v98 = elt(env, 2); /* !:ps!: */
    if (v99 == v98) goto v106;
    v98 = v100;
    v99 = qcar(v98);
    v98 = elt(env, 3); /* dname */
    v98 = get(v99, v98);
    env = stack[-5];
    if (!(v98 == nil)) goto v105;

v106:
    v98 = v100;
    v98 = Lconsp(nil, v98);
    env = stack[-5];
    if (v98 == nil) goto v107;
    v98 = v100;
    v99 = qcar(v98);
    v98 = elt(env, 2); /* !:ps!: */
    if (!(v99 == v98)) goto v107;
    v98 = v100;
    fn = elt(env, 4); /* ps!:value */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    goto v33;

v33:
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v98 = Lrplacd(nil, stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v103;

v107:
    v98 = v100;
    v98 = CC_psTargKvalues(env, v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    goto v33;

v105:
    v98 = v100;
    goto v33;

v104:
    v98 = stack[-2];
    goto v108;

v108:
    {
        Lisp_Object v109 = stack[-4];
        popv(6);
        return cons(v109, v98);
    }

v101:
    v98 = v100;
    v98 = CC_psTargKvalues(env, v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    goto v9;

v64:
    v98 = v100;
    goto v9;

v78:
    v98 = qvalue(elt(env, 1)); /* nil */
    goto v108;
/* error exit handlers */
v102:
    popv(6);
    return nil;
}



/* Code for copy_vect */

static Lisp_Object CC_copy_vect(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v22, v7, v2;
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
    v6 = stack[-1];
    v6 = Lupbv(nil, v6);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    stack[-3] = v6;
    v6 = (Lisp_Object)1; /* 0 */
    stack[0] = v6;
    goto v86;

v86:
    v22 = stack[-3];
    v6 = stack[0];
    v6 = difference2(v22, v6);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v6 = Lminusp(nil, v6);
    env = stack[-4];
    if (v6 == nil) goto v64;
    v6 = nil;
    { popv(5); return onevalue(v6); }

v64:
    v2 = stack[-2];
    v7 = stack[0];
    v22 = stack[-1];
    v6 = stack[0];
    v6 = *(Lisp_Object *)((char *)v22 + (CELL-TAG_VECTOR) + ((int32_t)v6/(16/CELL)));
    *(Lisp_Object *)((char *)v2 + (CELL-TAG_VECTOR) + ((int32_t)v7/(16/CELL))) = v6;
    v6 = stack[0];
    v6 = add1(v6);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    stack[0] = v6;
    goto v86;
/* error exit handlers */
v48:
    popv(5);
    return nil;
}



/* Code for findhc */

static Lisp_Object CC_findhc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v30;
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
    v116 = v0;
/* end of prologue */
    stack[-4] = nil;
    v30 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v30; /* njsi */
    stack[-2] = v30;
    v30 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v30; /* jsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v30 = qvalue(elt(env, 5)); /* maxvar */
    v116 = plus2(v30, v116);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v30 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    v116 = (Lisp_Object)65; /* 4 */
    v116 = *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    stack[-1] = v116;
    goto v69;

v69:
    v116 = stack[-1];
    if (v116 == nil) goto v21;
    v116 = stack[-1];
    v116 = qcar(v116);
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v30 = qvalue(elt(env, 5)); /* maxvar */
    v116 = qcar(v116);
    stack[-3] = v116;
    v116 = plus2(v30, v116);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v30 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    v116 = (Lisp_Object)1; /* 0 */
    v116 = *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    if (v116 == nil) goto v110;
    v30 = stack[-3];
    v116 = qvalue(elt(env, 3)); /* jsi */
    v116 = cons(v30, v116);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    qvalue(elt(env, 3)) = v116; /* jsi */
    v116 = qvalue(elt(env, 1)); /* njsi */
    v116 = add1(v116);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    qvalue(elt(env, 1)) = v116; /* njsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v30 = qvalue(elt(env, 5)); /* maxvar */
    v116 = stack[-3];
    v116 = plus2(v30, v116);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v30 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    v116 = (Lisp_Object)17; /* 1 */
    v116 = *(Lisp_Object *)((char *)v30 + (CELL-TAG_VECTOR) + ((int32_t)v116/(16/CELL)));
    v116 = qcar(v116);
    v30 = qcar(v116);
    stack[0] = v30;
    v116 = stack[-2];
    v116 = (Lisp_Object)greaterp2(v30, v116);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v116 = v116 ? lisp_true : nil;
    env = stack[-5];
    if (v116 == nil) goto v110;
    v116 = stack[0];
    stack[-2] = v116;
    v116 = stack[-3];
    stack[-4] = v116;
    goto v110;

v110:
    v116 = stack[-1];
    v116 = qcdr(v116);
    stack[-1] = v116;
    goto v69;

v21:
    v116 = qvalue(elt(env, 3)); /* jsi */
    v116 = Lreverse(nil, v116);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    qvalue(elt(env, 3)) = v116; /* jsi */
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v53:
    popv(6);
    return nil;
}



/* Code for calc_den_tar */

static Lisp_Object CC_calc_den_tar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
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
    v8 = v1;
    v9 = v0;
/* end of prologue */
    fn = elt(env, 1); /* denlist */
    v8 = (*qfn2(fn))(qenv(fn), v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[0];
    v9 = v8;
    v8 = v9;
    if (v8 == nil) goto v117;
    v8 = v9;
    v8 = qcdr(v8);
    if (v8 == nil) goto v66;
    v8 = v9;
    {
        popv(1);
        fn = elt(env, 2); /* constimes */
        return (*qfn1(fn))(qenv(fn), v8);
    }

v66:
    v8 = v9;
    v8 = qcar(v8);
    { popv(1); return onevalue(v8); }

v117:
    v8 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v8); }
/* error exit handlers */
v64:
    popv(1);
    return nil;
}



/* Code for setmatelem */

static Lisp_Object CC_setmatelem(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133;
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
    v131 = stack[-2];
    v132 = Llength(nil, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v131 = (Lisp_Object)49; /* 3 */
    if (v132 == v131) goto v8;
    v132 = stack[-2];
    v131 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 11); /* typerr */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    goto v8;

v8:
    v131 = stack[-2];
    v132 = qcar(v131);
    v131 = elt(env, 2); /* avalue */
    v131 = get(v132, v131);
    env = stack[-4];
    stack[-3] = v131;
    v131 = stack[-3];
    if (v131 == nil) goto v2;
    v131 = stack[-3];
    v132 = qcar(v131);
    v131 = elt(env, 3); /* matrix */
    if (!(v132 == v131)) goto v2;
    v131 = stack[-3];
    v131 = qcdr(v131);
    v132 = qcar(v131);
    stack[-3] = v132;
    v131 = elt(env, 5); /* mat */
    if (!consp(v132)) goto v135;
    v132 = qcar(v132);
    if (!(v132 == v131)) goto v135;

v16:
    v131 = stack[-2];
    v131 = qcdr(v131);
    v131 = qcar(v131);
    fn = elt(env, 12); /* reval_without_mod */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[0] = v131;
    v131 = stack[0];
    v131 = integerp(v131);
    if (v131 == nil) goto v73;
    v132 = stack[0];
    v131 = (Lisp_Object)1; /* 0 */
    v131 = (Lisp_Object)lesseq2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = v131 ? lisp_true : nil;
    env = stack[-4];
    if (!(v131 == nil)) goto v73;

v30:
    v131 = stack[-3];
    v132 = qcdr(v131);
    v131 = stack[0];
    fn = elt(env, 13); /* pnth */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v131 = qcar(v131);
    stack[-3] = v131;
    v131 = stack[-2];
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    v131 = qcar(v131);
    fn = elt(env, 12); /* reval_without_mod */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[0] = v131;
    v131 = stack[0];
    v131 = integerp(v131);
    if (v131 == nil) goto v136;
    v132 = stack[0];
    v131 = (Lisp_Object)1; /* 0 */
    v131 = (Lisp_Object)lesseq2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = v131 ? lisp_true : nil;
    env = stack[-4];
    if (!(v131 == nil)) goto v136;

v137:
    v132 = stack[-3];
    v131 = stack[0];
    fn = elt(env, 13); /* pnth */
    v132 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = stack[-1];
        popv(5);
        return Lrplaca(nil, v132, v131);

v136:
    v132 = stack[0];
    v131 = elt(env, 10); /* "positive integer" */
    fn = elt(env, 11); /* typerr */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    goto v137;

v73:
    v132 = stack[0];
    v131 = elt(env, 10); /* "positive integer" */
    fn = elt(env, 11); /* typerr */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    goto v30;

v135:
    v133 = elt(env, 6); /* "Matrix" */
    v131 = stack[-2];
    v132 = qcar(v131);
    v131 = elt(env, 7); /* "not set" */
    v131 = list3(v133, v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v132 = v131;
    v131 = v132;
    qvalue(elt(env, 8)) = v131; /* errmsg!* */
    v131 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v131 == nil)) goto v88;
    v131 = v132;
    fn = elt(env, 14); /* lprie */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    goto v88;

v88:
    v131 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    goto v16;

v2:
    v131 = stack[-2];
    v132 = qcar(v131);
    v131 = elt(env, 4); /* "matrix" */
    fn = elt(env, 11); /* typerr */
    v131 = (*qfn2(fn))(qenv(fn), v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    goto v16;
/* error exit handlers */
v134:
    popv(5);
    return nil;
}



/* Code for prepsq!*1 */

static Lisp_Object MS_CDECL CC_prepsqH1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v262, v263, v264, v265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prepsq*1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*1");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v17;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v262 = stack[-6];
    if (!consp(v262)) goto v96;
    v262 = stack[-6];
    v262 = qcar(v262);
    if (!consp(v262)) goto v96;
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v263 = qcar(v262);
    v262 = qvalue(elt(env, 1)); /* factors!* */
    v262 = Lmember(nil, v263, v262);
    if (!(v262 == nil)) goto v10;
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v262 = qcar(v262);
    if (!consp(v262)) goto v96;
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v262 = qcar(v262);
    v263 = qcar(v262);
    v262 = qvalue(elt(env, 1)); /* factors!* */
    v262 = Lmember(nil, v263, v262);
    if (!(v262 == nil)) goto v10;

v96:
    v262 = stack[-5];
    if (!consp(v262)) goto v266;
    v262 = stack[-5];
    v262 = qcar(v262);
    if (!consp(v262)) goto v266;
    v262 = qvalue(elt(env, 4)); /* kord!* */
    stack[-3] = v262;
    goto v267;

v267:
    v262 = stack[-3];
    if (v262 == nil) goto v266;
    v262 = stack[-3];
    v262 = qcar(v262);
    stack[-2] = v262;
    v262 = (Lisp_Object)1; /* 0 */
    stack[-1] = v262;
    v264 = stack[-2];
    v263 = (Lisp_Object)17; /* 1 */
    v262 = (Lisp_Object)17; /* 1 */
    v262 = acons(v264, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = ncons(v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v262;
    goto v269;

v269:
    v263 = stack[-5];
    v262 = stack[0];
    fn = elt(env, 13); /* quotfm */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-7] = v262;
    if (v262 == nil) goto v270;
    v262 = stack[-1];
    v262 = sub1(v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-1] = v262;
    v262 = stack[-7];
    stack[-5] = v262;
    goto v269;

v270:
    v263 = stack[-1];
    v262 = (Lisp_Object)1; /* 0 */
    v262 = (Lisp_Object)lessp2(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    v262 = v262 ? lisp_true : nil;
    env = stack[-8];
    if (v262 == nil) goto v271;
    v264 = elt(env, 3); /* expt */
    v263 = stack[-2];
    v262 = stack[-1];
    v262 = list3(v264, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    fn = elt(env, 14); /* fkern */
    v263 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* getpower */
    v263 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = stack[-4];
    v262 = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-4] = v262;
    goto v271;

v271:
    v262 = stack[-3];
    v262 = qcdr(v262);
    stack[-3] = v262;
    goto v267;

v266:
    v262 = stack[-6];
    fn = elt(env, 16); /* kernlp */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    if (v262 == nil) goto v272;
    v263 = stack[-4];
    v262 = stack[-6];
    fn = elt(env, 17); /* mkkl */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-6] = v262;
    v262 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v262;
    goto v272;

v272:
    v262 = qvalue(elt(env, 5)); /* dnl!* */
    if (v262 == nil) goto v273;
    v262 = qvalue(elt(env, 6)); /* !*allfac */
    if (v262 == nil) goto v274;
    v262 = stack[-6];
    fn = elt(env, 18); /* ckrn */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    goto v275;

v275:
    stack[-1] = v262;
    v263 = stack[-1];
    v262 = qvalue(elt(env, 5)); /* dnl!* */
    fn = elt(env, 19); /* ckrn!* */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-7] = v262;
    v263 = stack[-1];
    v262 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v263 = stack[-6];
    v262 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-6] = v262;
    v263 = stack[-5];
    v262 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-5] = v262;
    goto v273;

v273:
    v262 = qvalue(elt(env, 7)); /* upl!* */
    if (v262 == nil) goto v276;
    v262 = stack[-5];
    fn = elt(env, 18); /* ckrn */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v262;
    v263 = stack[0];
    v262 = qvalue(elt(env, 7)); /* upl!* */
    fn = elt(env, 19); /* ckrn!* */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-7] = v262;
    v263 = stack[0];
    v262 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v262;
    v263 = stack[-6];
    v262 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-6] = v262;
    v263 = stack[-5];
    v262 = stack[-7];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-5] = v262;
    goto v277;

v277:
    stack[-1] = stack[-6];
    v263 = stack[-5];
    v262 = stack[0];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = cons(stack[-1], v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    fn = elt(env, 21); /* canonsq */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-6] = v262;
    v262 = stack[-6];
    v263 = qcar(v262);
    v262 = stack[0];
    fn = elt(env, 20); /* quotof */
    v263 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = stack[-6];
    v262 = qcdr(v262);
    v262 = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-6] = v262;
    v262 = qvalue(elt(env, 6)); /* !*allfac */
    if (v262 == nil) goto v278;
    v262 = stack[-6];
    v262 = qcar(v262);
    fn = elt(env, 18); /* ckrn */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-1] = v262;
    v262 = stack[-6];
    v262 = qcdr(v262);
    fn = elt(env, 18); /* ckrn */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v262;
    v263 = stack[-1];
    v262 = (Lisp_Object)17; /* 1 */
    if (!(v263 == v262)) goto v279;
    v263 = stack[0];
    v262 = (Lisp_Object)17; /* 1 */
    if (!(v263 == v262)) goto v279;

v278:
    v262 = stack[-4];
    if (v262 == nil) goto v280;
    v265 = stack[-4];
    v264 = qvalue(elt(env, 2)); /* nil */
    v263 = qvalue(elt(env, 2)); /* nil */
    v262 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 22); /* exchk1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 4, v265, v264, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = stack[-6];
    v262 = qcar(v262);
    if (v262 == nil) goto v281;
    v263 = stack[-6];
    v262 = elt(env, 12); /* prepf */
    fn = elt(env, 23); /* sqform */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    goto v282;

v282:
    v262 = ncons(v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = Lnconc(nil, stack[0], v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    fn = elt(env, 24); /* retimes */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    popv(9);
    return ncons(v262);

v281:
    v262 = (Lisp_Object)1; /* 0 */
    goto v282;

v280:
    v262 = stack[-6];
    v262 = qcar(v262);
    if (v262 == nil) goto v283;
    v263 = stack[-6];
    v262 = elt(env, 12); /* prepf */
    fn = elt(env, 23); /* sqform */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    goto v284;

v284:
    v263 = v262;
    v262 = v263;
    v264 = elt(env, 9); /* plus */
    if (!consp(v262)) goto v285;
    v262 = qcar(v262);
    if (!(v262 == v264)) goto v285;
    v262 = v263;
    v262 = qcdr(v262);
    { popv(9); return onevalue(v262); }

v285:
    v262 = v263;
    popv(9);
    return ncons(v262);

v283:
    v262 = (Lisp_Object)1; /* 0 */
    goto v284;

v279:
    v263 = stack[-1];
    v262 = stack[-6];
    v262 = qcar(v262);
    if (!(equal(v263, v262))) goto v286;
    v263 = stack[0];
    v262 = stack[-6];
    v262 = qcdr(v262);
    if (equal(v263, v262)) goto v278;
    else goto v286;

v286:
    v262 = stack[-6];
    v263 = qcdr(v262);
    v262 = stack[0];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-5] = v262;
    v262 = stack[-6];
    v263 = qcar(v262);
    v262 = stack[-1];
    fn = elt(env, 20); /* quotof */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-6] = v262;
    v263 = stack[-4];
    v262 = stack[-1];
    fn = elt(env, 17); /* mkkl */
    v263 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 25); /* prepf1 */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v263 = v262;
    v262 = v263;
    if (v262 == nil) goto v287;
    v262 = v263;
    fn = elt(env, 26); /* replus */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    goto v288;

v288:
    stack[-4] = v262;
    v263 = stack[0];
    v262 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 25); /* prepf1 */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v263 = v262;
    v262 = v263;
    if (v262 == nil) goto v289;
    v262 = v263;
    fn = elt(env, 26); /* replus */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    goto v290;

v290:
    stack[-1] = v262;
    v263 = stack[-4];
    v262 = stack[-6];
    fn = elt(env, 27); /* addfactors */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-6] = v262;
    v263 = stack[-1];
    v262 = stack[-5];
    fn = elt(env, 27); /* addfactors */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-5] = v262;
    v263 = stack[-5];
    v262 = (Lisp_Object)17; /* 1 */
    if (v263 == v262) goto v291;
    v263 = stack[-6];
    v262 = elt(env, 10); /* minus */
    if (!consp(v263)) goto v292;
    v263 = qcar(v263);
    if (!(v263 == v262)) goto v292;
    stack[0] = elt(env, 10); /* minus */
    v264 = elt(env, 11); /* quotient */
    v262 = stack[-6];
    v262 = qcdr(v262);
    v263 = qcar(v262);
    v262 = stack[-5];
    v262 = list3(v264, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = list2(stack[0], v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    goto v293;

v293:
    popv(9);
    return ncons(v262);

v292:
    v264 = elt(env, 11); /* quotient */
    v263 = stack[-6];
    v262 = stack[-5];
    v262 = list3(v264, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    goto v293;

v291:
    v262 = stack[-6];
    v263 = elt(env, 9); /* plus */
    if (!consp(v262)) goto v294;
    v262 = qcar(v262);
    if (!(v262 == v263)) goto v294;
    v262 = stack[-6];
    v262 = qcdr(v262);
    { popv(9); return onevalue(v262); }

v294:
    v262 = stack[-6];
    popv(9);
    return ncons(v262);

v289:
    v262 = (Lisp_Object)1; /* 0 */
    goto v290;

v287:
    v262 = (Lisp_Object)1; /* 0 */
    goto v288;

v276:
    v262 = qvalue(elt(env, 8)); /* !*div */
    if (v262 == nil) goto v295;
    v262 = stack[-5];
    fn = elt(env, 18); /* ckrn */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v262;
    goto v277;

v295:
    v262 = (Lisp_Object)17; /* 1 */
    stack[0] = v262;
    goto v277;

v274:
    v262 = (Lisp_Object)17; /* 1 */
    goto v275;

v10:
    v263 = stack[-5];
    v262 = (Lisp_Object)17; /* 1 */
    if (v263 == v262) goto v296;
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v262 = qcdr(v262);
    stack[-2] = v262;
    v262 = stack[-5];
    stack[-1] = v262;
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v264 = qcar(v262);
    v263 = (Lisp_Object)17; /* 1 */
    v262 = (Lisp_Object)17; /* 1 */
    v262 = acons(v264, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = ncons(v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v262;
    goto v51;

v51:
    v263 = stack[-1];
    v262 = stack[0];
    fn = elt(env, 13); /* quotfm */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-7] = v262;
    if (v262 == nil) goto v297;
    v262 = stack[-7];
    stack[-1] = v262;
    v262 = stack[-2];
    v262 = sub1(v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[-2] = v262;
    goto v51;

v297:
    v262 = stack[-6];
    v262 = qcar(v262);
    v263 = qcdr(v262);
    v262 = stack[-1];
    stack[0] = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v263 = stack[-2];
    v262 = (Lisp_Object)1; /* 0 */
    v262 = (Lisp_Object)greaterp2(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    v262 = v262 ? lisp_true : nil;
    env = stack[-8];
    if (v262 == nil) goto v134;
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v264 = qcar(v262);
    v263 = stack[-2];
    v262 = stack[-4];
    v262 = acons(v264, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    goto v99;

v99:
    fn = elt(env, 28); /* prepsq!*0 */
    v262 = (*qfn2(fn))(qenv(fn), stack[0], v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v262;
    goto v298;

v298:
    v262 = stack[-6];
    v263 = qcdr(v262);
    v262 = stack[-5];
    v263 = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = stack[-4];
    fn = elt(env, 28); /* prepsq!*0 */
    v262 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    {
        Lisp_Object v299 = stack[0];
        popv(9);
        return Lnconc(nil, v299, v262);
    }

v134:
    v263 = stack[-2];
    v262 = (Lisp_Object)1; /* 0 */
    v262 = (Lisp_Object)lessp2(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    v262 = v262 ? lisp_true : nil;
    env = stack[-8];
    if (v262 == nil) goto v300;
    v264 = elt(env, 3); /* expt */
    v262 = stack[-6];
    v262 = qcar(v262);
    v262 = qcar(v262);
    v263 = qcar(v262);
    v262 = stack[-2];
    v262 = list3(v264, v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    fn = elt(env, 14); /* fkern */
    v263 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* getpower */
    v263 = (*qfn2(fn))(qenv(fn), v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = stack[-4];
    v262 = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    goto v99;

v300:
    v262 = stack[-4];
    goto v99;

v296:
    v262 = stack[-6];
    v262 = qcar(v262);
    v263 = qcdr(v262);
    v262 = stack[-5];
    stack[0] = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    v262 = stack[-6];
    v262 = qcar(v262);
    v263 = qcar(v262);
    v262 = stack[-4];
    v262 = cons(v263, v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    fn = elt(env, 28); /* prepsq!*0 */
    v262 = (*qfn2(fn))(qenv(fn), stack[0], v262);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-8];
    stack[0] = v262;
    goto v298;
/* error exit handlers */
v268:
    popv(9);
    return nil;
}



/* Code for !*g2lex */

static Lisp_Object CC_Hg2lex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v97;
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
    v301 = v0;
/* end of prologue */
    v97 = nil;
    stack[-1] = v301;
    goto v302;

v302:
    v301 = stack[-1];
    if (v301 == nil) { popv(3); return onevalue(v97); }
    v301 = stack[-1];
    v301 = qcar(v301);
    stack[0] = v97;
    v97 = v301;
    v97 = qcar(v97);
    v97 = qcdr(v97);
    v301 = qcdr(v301);
    v301 = cons(v97, v301);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v301 = ncons(v301);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    fn = elt(env, 2); /* psum */
    v301 = (*qfn2(fn))(qenv(fn), stack[0], v301);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v97 = v301;
    v301 = stack[-1];
    v301 = qcdr(v301);
    stack[-1] = v301;
    goto v302;
/* error exit handlers */
v20:
    popv(3);
    return nil;
}



/* Code for inormmat */

static Lisp_Object CC_inormmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53;
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
    v52 = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-5] = v52;
    goto v96;

v96:
    v52 = stack[-5];
    if (v52 == nil) goto v77;
    v52 = stack[-5];
    v52 = qcar(v52);
    stack[-1] = v52;
    v52 = (Lisp_Object)17; /* 1 */
    stack[-7] = v52;
    v52 = stack[-1];
    stack[0] = v52;
    goto v80;

v80:
    v52 = stack[0];
    if (v52 == nil) goto v261;
    v52 = stack[0];
    v52 = qcar(v52);
    v53 = stack[-7];
    v52 = qcdr(v52);
    fn = elt(env, 2); /* ilcm */
    v52 = (*qfn2(fn))(qenv(fn), v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    stack[-7] = v52;
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v80;

v261:
    v52 = stack[-1];
    stack[-4] = v52;
    v52 = stack[-4];
    if (v52 == nil) goto v11;
    v52 = stack[-4];
    v52 = qcar(v52);
    v53 = v52;
    stack[0] = qcar(v53);
    v53 = stack[-7];
    v52 = qcdr(v52);
    v52 = quot2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    v52 = times2(stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    v52 = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    stack[-2] = v52;
    stack[-3] = v52;
    goto v4;

v4:
    v52 = stack[-4];
    v52 = qcdr(v52);
    stack[-4] = v52;
    v52 = stack[-4];
    if (v52 == nil) goto v61;
    stack[-1] = stack[-2];
    v52 = stack[-4];
    v52 = qcar(v52);
    v53 = v52;
    stack[0] = qcar(v53);
    v53 = stack[-7];
    v52 = qcdr(v52);
    v52 = quot2(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    v52 = times2(stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    v52 = ncons(v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    v52 = Lrplacd(nil, stack[-1], v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    v52 = stack[-2];
    v52 = qcdr(v52);
    stack[-2] = v52;
    goto v4;

v61:
    v52 = stack[-3];
    v53 = v52;
    goto v22;

v22:
    v52 = stack[-6];
    v52 = cons(v53, v52);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-8];
    stack[-6] = v52;
    v52 = stack[-5];
    v52 = qcdr(v52);
    stack[-5] = v52;
    goto v96;

v11:
    v52 = qvalue(elt(env, 1)); /* nil */
    v53 = v52;
    goto v22;

v77:
    v52 = stack[-6];
        popv(9);
        return Lreverse(nil, v52);
/* error exit handlers */
v305:
    popv(9);
    return nil;
}



/* Code for small!-primep */

static Lisp_Object CC_smallKprimep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v313, v314;
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
    v313 = stack[-8];
    v313 = Levenp(nil, v313);
    env = stack[-10];
    if (!(v313 == nil)) goto v46;
    v314 = stack[-8];
    v313 = (Lisp_Object)49; /* 3 */
    v314 = Cremainder(v314, v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    v313 = (Lisp_Object)1; /* 0 */
    if (v314 == v313) goto v46;
    v313 = stack[-8];
    v313 = sub1(v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    stack[-6] = v313;
    v313 = stack[-8];
    v313 = Lset_small_modulus(nil, v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    stack[-3] = v313;
    v313 = (Lisp_Object)1; /* 0 */
    stack[-7] = v313;
    goto v6;

v6:
    v313 = stack[-6];
    v313 = Levenp(nil, v313);
    env = stack[-10];
    if (v313 == nil) goto v261;
    v314 = stack[-6];
    v313 = (Lisp_Object)33; /* 2 */
    v313 = quot2(v314, v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    stack[-6] = v313;
    v313 = stack[-7];
    v313 = add1(v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    stack[-7] = v313;
    goto v6;

v261:
    v313 = (Lisp_Object)17; /* 1 */
    stack[-9] = v313;
    v313 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v313;
    goto v101;

v101:
    v313 = stack[-2];
    if (v313 == nil) goto v113;
    v314 = stack[-9];
    v313 = qvalue(elt(env, 3)); /* !*confidence!* */
    v313 = (Lisp_Object)lesseq2(v314, v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    v313 = v313 ? lisp_true : nil;
    env = stack[-10];
    if (v313 == nil) goto v113;
    v314 = stack[-8];
    v313 = (Lisp_Object)33; /* 2 */
    v313 = difference2(v314, v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    fn = elt(env, 4); /* random */
    v313 = (*qfn1(fn))(qenv(fn), v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    v313 = add1(v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    v314 = v313;
    v313 = stack[-6];
    v313 = Lmodular_expt(nil, v314, v313);
    env = stack[-10];
    stack[-5] = v313;
    v314 = stack[-5];
    v313 = (Lisp_Object)17; /* 1 */
    if (v314 == v313) goto v59;
    v313 = (Lisp_Object)17; /* 1 */
    stack[-1] = v313;
    goto v316;

v316:
    v314 = stack[-7];
    v313 = stack[-1];
    v313 = difference2(v314, v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    v313 = Lminusp(nil, v313);
    env = stack[-10];
    if (v313 == nil) goto v107;
    v314 = stack[-5];
    v313 = (Lisp_Object)17; /* 1 */
    if (v314 == v313) goto v59;
    v313 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v313;
    goto v59;

v59:
    v313 = stack[-9];
    v313 = add1(v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    stack[-9] = v313;
    goto v101;

v107:
    v314 = stack[-5];
    v313 = stack[-5];
    v313 = Lmodular_times(nil, v314, v313);
    env = stack[-10];
    stack[-4] = v313;
    v314 = stack[-4];
    v313 = (Lisp_Object)17; /* 1 */
    if (!(v314 == v313)) goto v317;
    stack[0] = stack[-5];
    v313 = stack[-8];
    v313 = sub1(v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    if (equal(stack[0], v313)) goto v317;
    v314 = stack[-5];
    v313 = (Lisp_Object)17; /* 1 */
    if (v314 == v313) goto v317;
    v313 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v313;
    goto v100;

v100:
    v313 = stack[-1];
    v313 = add1(v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-10];
    stack[-1] = v313;
    goto v316;

v317:
    v313 = stack[-4];
    stack[-5] = v313;
    goto v100;

v113:
    v313 = stack[-3];
    v313 = Lset_small_modulus(nil, v313);
    nil = C_nil;
    if (exception_pending()) goto v315;
    { Lisp_Object res = stack[-2]; popv(11); return onevalue(res); }

v46:
    v313 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v313); }
/* error exit handlers */
v315:
    popv(11);
    return nil;
}



/* Code for general!-multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_generalKmultiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
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
    v37 = stack[-2];
    if (v37 == nil) goto v56;
    v38 = stack[-1];
    v37 = (Lisp_Object)17; /* 1 */
    if (v38 == v37) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v37 = stack[-2];
    if (!consp(v37)) goto v47;
    v37 = stack[-2];
    v37 = qcar(v37);
    if (!consp(v37)) goto v47;
    v37 = stack[-2];
    v37 = qcar(v37);
    stack[-3] = qcar(v37);
    v37 = stack[-2];
    v37 = qcar(v37);
    v38 = qcdr(v37);
    v37 = stack[-1];
    stack[0] = CC_generalKmultiplyKbyKconstantKmodKp(env, v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v37 = stack[-2];
    v38 = qcdr(v37);
    v37 = stack[-1];
    v37 = CC_generalKmultiplyKbyKconstantKmodKp(env, v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    {
        Lisp_Object v40 = stack[-3];
        Lisp_Object v41 = stack[0];
        popv(5);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v40, v41, v37);
    }

v47:
    v38 = stack[-2];
    v37 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-times */
    v37 = (*qfn2(fn))(qenv(fn), v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v38 = v37;
    v37 = v38;
    v37 = (Lisp_Object)zerop(v37);
    v37 = v37 ? lisp_true : nil;
    env = stack[-4];
    if (v37 == nil) { popv(5); return onevalue(v38); }
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v37); }

v56:
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v37); }
/* error exit handlers */
v60:
    popv(5);
    return nil;
}



/* Code for preptayexp */

static Lisp_Object CC_preptayexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptayexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v69 = v0;
/* end of prologue */
    v21 = v69;
    if (!consp(v21)) return onevalue(v69);
    v21 = v69;
    {
        fn = elt(env, 1); /* rnprep!: */
        return (*qfn1(fn))(qenv(fn), v21);
    }
}



/* Code for ratpoly_sgn */

static Lisp_Object CC_ratpoly_sgn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46;
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
    v46 = qvalue(elt(env, 1)); /* !*rlanuexdebug */
    if (v46 == nil) goto v75;
    v46 = stack[0];
    fn = elt(env, 3); /* ratpoly_ratp */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    if (!(v46 == nil)) goto v75;
    v46 = elt(env, 2); /* "***** ratpoly_sgn: not a constant polynomial" 
*/
    stack[0] = v46;
    v46 = stack[0];
    v46 = Lprinc(nil, v46);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    v46 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v12;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v75:
    v46 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* rat_sgn */
        return (*qfn1(fn))(qenv(fn), v46);
    }
/* error exit handlers */
v12:
    popv(2);
    return nil;
}



/* Code for bc_mkat */

static Lisp_Object CC_bc_mkat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v74, v75;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_mkat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v103 = v1;
    v74 = v0;
/* end of prologue */
    v103 = qcar(v103);
    v75 = qvalue(elt(env, 1)); /* nil */
    return list3(v74, v103, v75);
}



/* Code for omattrir */

static Lisp_Object MS_CDECL CC_omattrir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v101, v319;
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
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-2];
    fn = elt(env, 7); /* omatpir */
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-2];
    stack[-1] = v113;
    fn = elt(env, 6); /* lex */
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-2];
    fn = elt(env, 8); /* omobj */
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-2];
    stack[0] = v113;
    fn = elt(env, 6); /* lex */
    v113 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-2];
    v113 = elt(env, 1); /* (!/ o m a t t r) */
    fn = elt(env, 9); /* checktag */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v296;
    env = stack[-2];
    v113 = stack[-1];
    v113 = Lconsp(nil, v113);
    env = stack[-2];
    if (v113 == nil) goto v69;
    v113 = stack[-1];
    v113 = qcar(v113);
    v113 = qcdr(v113);
    v101 = qcar(v113);
    v113 = elt(env, 2); /* csymbol */
    if (!(v101 == v113)) goto v69;
    v101 = stack[0];
    v113 = qvalue(elt(env, 3)); /* nil */
    v319 = qvalue(elt(env, 3)); /* nil */
    popv(3);
    return list2star(v101, v113, v319);

v69:
    v113 = stack[0];
    if (is_number(v113)) goto v6;
    v319 = elt(env, 5); /* ci */
    v101 = stack[-1];
    v113 = stack[0];
    popv(3);
    return list3(v319, v101, v113);

v6:
    v319 = elt(env, 4); /* cn */
    v101 = stack[-1];
    v113 = stack[0];
    popv(3);
    return list3(v319, v101, v113);
/* error exit handlers */
v296:
    popv(3);
    return nil;
}



/* Code for letmtr */

static Lisp_Object MS_CDECL CC_letmtr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v312, v303, v320, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "letmtr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr");
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
    stack[-3] = nil;
    v312 = stack[0];
    v34 = elt(env, 1); /* mat */
    if (!consp(v312)) goto v78;
    v312 = qcar(v312);
    if (!(v312 == v34)) goto v78;
    v34 = stack[-2];
    v34 = qcdr(v34);
    fn = elt(env, 10); /* revlis */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    stack[-3] = v34;
    fn = elt(env, 11); /* numlis */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    if (v34 == nil) goto v5;
    v34 = stack[-3];
    v312 = Llength(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v34 = (Lisp_Object)33; /* 2 */
    if (!(v312 == v34)) goto v5;

v88:
    v34 = stack[0];
    v312 = qcdr(v34);
    v34 = stack[-3];
    v34 = qcar(v34);
    fn = elt(env, 12); /* pnth */
    v34 = (*qfn2(fn))(qenv(fn), v312, v34);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v312 = qcar(v34);
    v34 = stack[-3];
    v34 = qcdr(v34);
    v34 = qcar(v34);
    fn = elt(env, 12); /* pnth */
    v312 = (*qfn2(fn))(qenv(fn), v312, v34);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v34 = stack[-1];
    v34 = Lrplaca(nil, v312, v34);
    nil = C_nil;
    if (exception_pending()) goto v26;
    v34 = nil;
    { popv(5); return onevalue(v34); }

v5:
    v59 = elt(env, 6); /* "Syntax error:" */
    v320 = stack[-2];
    v303 = elt(env, 7); /* "invalid" */
    v312 = qvalue(elt(env, 8)); /* nil */
    v34 = elt(env, 9); /* hold */
    {
        popv(5);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v59, v320, v303, v312, v34);
    }

v78:
    v303 = elt(env, 2); /* "Matrix" */
    v34 = stack[-2];
    v312 = qcar(v34);
    v34 = elt(env, 3); /* "not set" */
    v34 = list3(v303, v312, v34);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    v312 = v34;
    v34 = v312;
    qvalue(elt(env, 4)) = v34; /* errmsg!* */
    v34 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v34 == nil)) goto v15;
    v34 = v312;
    fn = elt(env, 14); /* lprie */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    goto v15;

v15:
    v34 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-4];
    goto v88;
/* error exit handlers */
v26:
    popv(5);
    return nil;
}



/* Code for a2bc */

static Lisp_Object CC_a2bc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v97;
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
    v301 = v0;
/* end of prologue */
    v97 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v97 == nil) goto v16;
    v97 = v301;
    if (!consp(v97)) goto v76;
    v97 = v301;
    v97 = qcar(v97);
    if (!consp(v97)) goto v76;
    v97 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v97 == nil)) goto v67;
    v97 = elt(env, 3); /* " Invalid coefficient " */
    v301 = list2(v97, v301);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[0];
    goto v67;

v67:
    v301 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v3;
    v301 = nil;
    { popv(1); return onevalue(v301); }

v76:
    {
        popv(1);
        fn = elt(env, 5); /* bcfd */
        return (*qfn1(fn))(qenv(fn), v301);
    }

v16:
    {
        popv(1);
        fn = elt(env, 6); /* simp!* */
        return (*qfn1(fn))(qenv(fn), v301);
    }
/* error exit handlers */
v3:
    popv(1);
    return nil;
}



/* Code for rand!-mons!-sparse */

static Lisp_Object MS_CDECL CC_randKmonsKsparse(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, Lisp_Object v19,
                         Lisp_Object v18, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rand-mons-sparse");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rand-mons-sparse");
#endif
    if (stack >= stacklimit)
    {
        push5(v18,v19,v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v17,v19,v18);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v18;
    stack[-1] = v19;
    stack[-2] = v17;
    stack[-3] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    stack[-7] = nil;
    v224 = stack[0];
    if (v224 == nil) goto v76;
    v225 = (Lisp_Object)17; /* 1 */
    v224 = stack[-1];
    v224 = difference2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = plus2(stack[-2], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    goto v345;

v345:
    stack[-2] = v224;
    v225 = v224;
    v224 = stack[-3];
    fn = elt(env, 2); /* min */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    fn = elt(env, 3); /* rand!-comb */
    v224 = (*qfn2(fn))(qenv(fn), stack[-2], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v225 = v224;
    v224 = stack[0];
    if (v224 == nil) goto v317;
    v224 = v225;
    stack[-5] = v224;
    v224 = stack[-5];
    if (v224 == nil) goto v71;
    v224 = stack[-5];
    v224 = qcar(v224);
    stack[0] = stack[-8];
    v225 = v224;
    v224 = stack[-1];
    v224 = plus2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    fn = elt(env, 4); /* !*kp2f */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    stack[-3] = v224;
    stack[-4] = v224;
    goto v25;

v25:
    v224 = stack[-5];
    v224 = qcdr(v224);
    stack[-5] = v224;
    v224 = stack[-5];
    if (v224 == nil) { Lisp_Object res = stack[-4]; popv(11); return onevalue(res); }
    stack[-2] = stack[-3];
    v224 = stack[-5];
    v224 = qcar(v224);
    stack[0] = stack[-8];
    v225 = v224;
    v224 = stack[-1];
    v224 = plus2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    fn = elt(env, 4); /* !*kp2f */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = Lrplacd(nil, stack[-2], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-3];
    v224 = qcdr(v224);
    stack[-3] = v224;
    goto v25;

v71:
    v224 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v224); }

v317:
    v224 = v225;
    stack[-6] = v224;
    v224 = stack[-6];
    if (v224 == nil) goto v134;
    v224 = stack[-6];
    v224 = qcar(v224);
    stack[-2] = v224;
    v224 = (Lisp_Object)17; /* 1 */
    stack[-1] = v224;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v225 = stack[-2];
    v224 = stack[-7];
    v225 = plus2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-9];
    fn = elt(env, 5); /* inttovec */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = cons(stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    stack[-2] = v224;
    v224 = stack[-8];
    stack[0] = v224;
    goto v346;

v346:
    v224 = stack[0];
    if (v224 == nil) goto v300;
    v224 = stack[0];
    v224 = qcar(v224);
    v225 = v224;
    v224 = stack[-2];
    v224 = qcdr(v224);
    stack[-2] = v224;
    v224 = qcar(v224);
    fn = elt(env, 4); /* !*kp2f */
    v225 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-1];
    fn = elt(env, 6); /* multf */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    stack[-1] = v224;
    v224 = stack[0];
    v224 = qcdr(v224);
    stack[0] = v224;
    goto v346;

v300:
    v224 = stack[-1];
    v224 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    stack[-4] = v224;
    stack[-5] = v224;
    goto v253;

v253:
    v224 = stack[-6];
    v224 = qcdr(v224);
    stack[-6] = v224;
    v224 = stack[-6];
    if (v224 == nil) { Lisp_Object res = stack[-5]; popv(11); return onevalue(res); }
    stack[-3] = stack[-4];
    v224 = stack[-6];
    v224 = qcar(v224);
    stack[-2] = v224;
    v224 = (Lisp_Object)17; /* 1 */
    stack[-1] = v224;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v225 = stack[-2];
    v224 = stack[-7];
    v225 = plus2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-9];
    fn = elt(env, 5); /* inttovec */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = cons(stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    stack[-2] = v224;
    v224 = stack[-8];
    stack[0] = v224;
    goto v347;

v347:
    v224 = stack[0];
    if (v224 == nil) goto v348;
    v224 = stack[0];
    v224 = qcar(v224);
    v225 = v224;
    v224 = stack[-2];
    v224 = qcdr(v224);
    stack[-2] = v224;
    v224 = qcar(v224);
    fn = elt(env, 4); /* !*kp2f */
    v225 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-1];
    fn = elt(env, 6); /* multf */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    stack[-1] = v224;
    v224 = stack[0];
    v224 = qcdr(v224);
    stack[0] = v224;
    goto v347;

v348:
    v224 = stack[-1];
    v224 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = Lrplacd(nil, stack[-3], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-4];
    v224 = qcdr(v224);
    stack[-4] = v224;
    goto v253;

v134:
    v224 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v224); }

v76:
    v224 = stack[-8];
    v224 = Llength(nil, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    stack[-9] = v224;
    v224 = stack[-1];
    v224 = (Lisp_Object)zerop(v224);
    v224 = v224 ? lisp_true : nil;
    env = stack[-10];
    if (v224 == nil) goto v49;
    v224 = (Lisp_Object)1; /* 0 */
    goto v45;

v45:
    stack[-7] = v224;
    v225 = stack[-9];
    v224 = stack[-2];
    v225 = plus2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-9];
    fn = elt(env, 7); /* binomial */
    v225 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-7];
    v224 = difference2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    goto v345;

v49:
    stack[-4] = stack[-9];
    v224 = stack[-1];
    v224 = sub1(v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v225 = plus2(stack[-4], v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    v224 = stack[-9];
    fn = elt(env, 7); /* binomial */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v344;
    env = stack[-10];
    goto v45;
/* error exit handlers */
v344:
    popv(11);
    return nil;
}



/* Code for simppartdf */

static Lisp_Object CC_simppartdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56;
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
    v56 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitpartdf */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v56);
    }
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for spp */

static Lisp_Object CC_spp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v103;
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
    v117 = v0;
/* end of prologue */
    v103 = v117;
    v103 = Lconsp(nil, v103);
    env = stack[0];
    if (v103 == nil) goto v18;
    v117 = qcar(v117);
    {
        popv(1);
        fn = elt(env, 2); /* kernelp */
        return (*qfn1(fn))(qenv(fn), v117);
    }

v18:
    v117 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v117); }
}



/* Code for incident1 */

static Lisp_Object MS_CDECL CC_incident1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v259, v349, v126, v127, v116;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident1");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v126 = v17;
    v127 = v1;
    v116 = v0;
/* end of prologue */
    v349 = v116;
    v259 = v127;
    v259 = qcar(v259);
    v259 = qcar(v259);
    if (v349 == v259) goto v66;
    v349 = v116;
    v259 = v127;
    v259 = qcdr(v259);
    v259 = qcar(v259);
    v259 = qcar(v259);
    if (v349 == v259) goto v50;
    v349 = v116;
    v259 = v127;
    v259 = qcdr(v259);
    v259 = qcdr(v259);
    v259 = qcar(v259);
    v259 = qcar(v259);
    if (v349 == v259) goto v32;
    v259 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v259); }

v32:
    v259 = v127;
    v259 = qcar(v259);
    stack[-1] = qcar(v259);
    stack[0] = v126;
    v259 = v127;
    v259 = qcdr(v259);
    v259 = qcar(v259);
    v259 = qcar(v259);
    v349 = v126;
    v259 = cons(v259, v349);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    v259 = ncons(v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    {
        Lisp_Object v316 = stack[-1];
        Lisp_Object v51 = stack[0];
        popv(3);
        return acons(v316, v51, v259);
    }

v50:
    v259 = v127;
    v259 = qcdr(v259);
    v259 = qcdr(v259);
    v259 = qcar(v259);
    stack[-1] = qcar(v259);
    stack[0] = v126;
    v259 = v127;
    v259 = qcar(v259);
    v259 = qcar(v259);
    v349 = v126;
    v259 = cons(v259, v349);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    v259 = ncons(v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    {
        Lisp_Object v52 = stack[-1];
        Lisp_Object v53 = stack[0];
        popv(3);
        return acons(v52, v53, v259);
    }

v66:
    v259 = v127;
    v259 = qcdr(v259);
    v259 = qcar(v259);
    stack[-1] = qcar(v259);
    stack[0] = v126;
    v259 = v127;
    v259 = qcdr(v259);
    v259 = qcdr(v259);
    v259 = qcar(v259);
    v259 = qcar(v259);
    v349 = v126;
    v259 = cons(v259, v349);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    v259 = ncons(v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    {
        Lisp_Object v54 = stack[-1];
        Lisp_Object v91 = stack[0];
        popv(3);
        return acons(v54, v91, v259);
    }
/* error exit handlers */
v29:
    popv(3);
    return nil;
}



/* Code for quotexf!* */

static Lisp_Object CC_quotexfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v301;
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
    goto v108;

v108:
    v45 = stack[-2];
    if (v45 == nil) goto v77;
    v45 = stack[-2];
    v45 = qcar(v45);
    stack[0] = qcar(v45);
    v45 = stack[-2];
    v45 = qcar(v45);
    v301 = qcdr(v45);
    v45 = stack[-1];
    fn = elt(env, 1); /* quotfexf!*1 */
    v301 = (*qfn2(fn))(qenv(fn), v301, v45);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    v45 = stack[-3];
    v45 = acons(stack[0], v301, v45);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-4];
    stack[-3] = v45;
    v45 = stack[-2];
    v45 = qcdr(v45);
    stack[-2] = v45;
    goto v108;

v77:
    v45 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v45);
    }
/* error exit handlers */
v110:
    popv(5);
    return nil;
}



/* Code for arglength */

static Lisp_Object CC_arglength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v47;
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
    v47 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*intstr */
    qvalue(elt(env, 1)) = nil; /* !*intstr */
    v82 = v47;
    if (v82 == nil) goto v302;
    v82 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v82; /* !*intstr */
    v82 = v47;
    fn = elt(env, 3); /* reval */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    v47 = v82;
    v82 = v47;
    if (!consp(v82)) goto v75;
    v82 = v47;
    v82 = qcdr(v82);
    v82 = Llength(nil, v82);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    goto v56;

v56:
    qvalue(elt(env, 1)) = stack[0]; /* !*intstr */
    { popv(2); return onevalue(v82); }

v75:
    v82 = (Lisp_Object)-15; /* -1 */
    goto v56;

v302:
    v82 = (Lisp_Object)1; /* 0 */
    goto v56;
/* error exit handlers */
v9:
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
    Lisp_Object v345, v351;
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
    v345 = stack[-2];
    if (!consp(v345)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v345 = stack[-2];
    v345 = qcar(v345);
    if (!consp(v345)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v345 = stack[-2];
    v345 = qcar(v345);
    v345 = qcar(v345);
    v351 = qcar(v345);
    v345 = qvalue(elt(env, 1)); /* m!-image!-variable */
    if (equal(v351, v345)) goto v82;
    v351 = stack[-2];
    v345 = stack[-1];
    fn = elt(env, 3); /* evaluate!-in!-order */
    v345 = (*qfn2(fn))(qenv(fn), v351, v345);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    v351 = v345;
    v345 = v351;
    v345 = (Lisp_Object)zerop(v345);
    v345 = v345 ? lisp_true : nil;
    env = stack[-4];
    if (v345 == nil) { popv(5); return onevalue(v351); }
    v345 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v345); }

v82:
    v345 = stack[-2];
    v345 = qcar(v345);
    stack[-3] = qcar(v345);
    v345 = stack[-2];
    v345 = qcar(v345);
    v351 = qcdr(v345);
    v345 = stack[-1];
    fn = elt(env, 3); /* evaluate!-in!-order */
    v345 = (*qfn2(fn))(qenv(fn), v351, v345);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    v351 = v345;
    v345 = v351;
    v345 = (Lisp_Object)zerop(v345);
    v345 = v345 ? lisp_true : nil;
    env = stack[-4];
    if (v345 == nil) goto v304;
    v345 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v345;
    goto v4;

v4:
    v345 = stack[-2];
    v351 = qcdr(v345);
    v345 = stack[-1];
    v345 = CC_makeKimage(env, v351, v345);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    {
        Lisp_Object v32 = stack[-3];
        Lisp_Object v33 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v32, v33, v345);
    }

v304:
    v345 = v351;
    stack[0] = v345;
    goto v4;
/* error exit handlers */
v90:
    popv(5);
    return nil;
}



/* Code for bfprin0x */

static Lisp_Object CC_bfprin0x(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16, v111;
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
    v16 = v1;
    v15 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bfexplode0x */
    v15 = (*qfn2(fn))(qenv(fn), v15, v16);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[0];
    v16 = v15;
    v16 = qcdr(v16);
    v16 = qcar(v16);
    v111 = v15;
    v111 = qcdr(v111);
    v111 = qcdr(v111);
    v111 = qcar(v111);
    v15 = qcar(v15);
    {
        popv(1);
        fn = elt(env, 2); /* bfprin!:lst */
        return (*qfnn(fn))(qenv(fn), 3, v15, v16, v111);
    }
/* error exit handlers */
v44:
    popv(1);
    return nil;
}



/* Code for valuechk */

static Lisp_Object CC_valuechk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v311, v98, v99;
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
    v98 = stack[-1];
    v311 = elt(env, 1); /* number!-of!-args */
    v311 = get(v98, v311);
    env = stack[-3];
    stack[-2] = v311;
    if (v311 == nil) goto v96;
    v311 = stack[0];
    v98 = Llength(nil, v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    v311 = stack[-2];
    if (!(equal(v98, v311))) goto v48;

v96:
    v311 = stack[-2];
    if (!(v311 == nil)) goto v38;
    v311 = stack[0];
    if (v311 == nil) goto v38;
    v311 = stack[0];
    v311 = qcdr(v311);
    if (v311 == nil) goto v38;
    v98 = stack[-1];
    v311 = elt(env, 2); /* !:rd!: */
    v311 = get(v98, v311);
    env = stack[-3];
    if (!(v311 == nil)) goto v48;
    v98 = stack[-1];
    v311 = elt(env, 3); /* !:rn!: */
    v311 = get(v98, v311);
    env = stack[-3];
    if (!(v311 == nil)) goto v48;

v38:
    v98 = stack[-1];
    v311 = stack[0];
    v311 = cons(v98, v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    fn = elt(env, 9); /* opfchk!! */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    stack[0] = v311;
    v311 = stack[0];
    if (v311 == nil) goto v39;
    v98 = stack[0];
    v311 = elt(env, 7); /* list */
    if (!consp(v98)) goto v259;
    v98 = qcar(v98);
    if (!(v98 == v311)) goto v259;
    v99 = stack[0];
    v98 = (Lisp_Object)17; /* 1 */
    v311 = (Lisp_Object)17; /* 1 */
    v311 = acons(v99, v98, v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    v311 = ncons(v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    v98 = v311;
    goto v90;

v90:
    v311 = (Lisp_Object)17; /* 1 */
    v311 = cons(v98, v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    stack[0] = v311;
    v311 = stack[0];
    fn = elt(env, 10); /* znumr */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    if (v311 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v98 = qvalue(elt(env, 8)); /* nil */
    v311 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v98, v311);

v259:
    v311 = stack[0];
    v98 = v311;
    goto v90;

v39:
    v311 = nil;
    { popv(4); return onevalue(v311); }

v48:
    v98 = elt(env, 4); /* "Wrong number of arguments to" */
    v311 = stack[-1];
    v311 = list2(v98, v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    v98 = v311;
    v311 = v98;
    qvalue(elt(env, 5)) = v311; /* errmsg!* */
    v311 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v311 == nil)) goto v43;
    v311 = v98;
    fn = elt(env, 11); /* lprie */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    goto v43;

v43:
    v311 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-3];
    goto v38;
/* error exit handlers */
v352:
    popv(4);
    return nil;
}



/* Code for mk!+inner!+product */

static Lisp_Object CC_mkLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v320;
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
    v303 = stack[-3];
    fn = elt(env, 7); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    v303 = stack[-1];
    fn = elt(env, 7); /* get!+vec!+dim */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    if (equal(stack[0], v303)) goto v58;
    v303 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v303 == nil)) goto v79;
    v303 = elt(env, 2); /* "Error in Gram_schmidt: each list in input must be the same length." 
*/
    fn = elt(env, 8); /* lprie */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    goto v79;

v79:
    v303 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    goto v58;

v58:
    v320 = qvalue(elt(env, 3)); /* nil */
    v303 = (Lisp_Object)17; /* 1 */
    v303 = cons(v320, v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    stack[0] = v303;
    v303 = qvalue(elt(env, 4)); /* !*complex */
    if (v303 == nil) goto v110;
    v303 = stack[-1];
    fn = elt(env, 9); /* mk!+conjugate!+vec */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    stack[-4] = v303;
    goto v45;

v45:
    v303 = (Lisp_Object)17; /* 1 */
    stack[-2] = v303;
    goto v5;

v5:
    v303 = stack[-3];
    fn = elt(env, 7); /* get!+vec!+dim */
    v320 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    v303 = stack[-2];
    v303 = difference2(v320, v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    v303 = Lminusp(nil, v303);
    env = stack[-5];
    if (v303 == nil) goto v113;
    v303 = qvalue(elt(env, 5)); /* t */
    stack[-1] = qvalue(elt(env, 6)); /* !*sub2 */
    qvalue(elt(env, 6)) = v303; /* !*sub2 */
    v303 = stack[0];
    fn = elt(env, 10); /* subs2 */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    stack[0] = v303;
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v113:
    stack[-1] = stack[0];
    v320 = stack[-3];
    v303 = stack[-2];
    fn = elt(env, 11); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v320, v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    v320 = stack[-4];
    v303 = stack[-2];
    fn = elt(env, 11); /* get!+vec!+entry */
    v303 = (*qfn2(fn))(qenv(fn), v320, v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    fn = elt(env, 12); /* multsq */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    fn = elt(env, 13); /* addsq */
    v303 = (*qfn2(fn))(qenv(fn), stack[-1], v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    stack[0] = v303;
    v303 = stack[-2];
    v303 = add1(v303);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-5];
    stack[-2] = v303;
    goto v5;

v110:
    v303 = stack[-1];
    stack[-4] = v303;
    goto v45;
/* error exit handlers */
v27:
    env = stack[-5];
    qvalue(elt(env, 6)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v26:
    popv(6);
    return nil;
}



/* Code for pasf_smordtable */

static Lisp_Object MS_CDECL CC_pasf_smordtable(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v17, Lisp_Object v19, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smordtable");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable");
#endif
    if (stack >= stacklimit)
    {
        push4(v19,v17,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v17,v19);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v19;
    stack[-1] = v17;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v48 = stack[-1];
    v50 = stack[0];
    v50 = (Lisp_Object)lessp2(v48, v50);
    nil = C_nil;
    if (exception_pending()) goto v11;
    v50 = v50 ? lisp_true : nil;
    env = stack[-4];
    if (v50 == nil) goto v8;
    v48 = stack[-3];
    v50 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* pasf_smordtable2 */
        return (*qfn2(fn))(qenv(fn), v48, v50);
    }

v8:
    v48 = stack[-1];
    v50 = stack[0];
    v50 = (Lisp_Object)greaterp2(v48, v50);
    nil = C_nil;
    if (exception_pending()) goto v11;
    v50 = v50 ? lisp_true : nil;
    env = stack[-4];
    if (v50 == nil) goto v3;
    v48 = stack[-3];
    v50 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* pasf_smordtable1 */
        return (*qfn2(fn))(qenv(fn), v48, v50);
    }

v3:
    v50 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v50 == nil)) goto v261;
    v50 = elt(env, 2); /* "abused smordtable" */
    v50 = ncons(v50);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    fn = elt(env, 5); /* lprie */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    goto v261;

v261:
    v50 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v11;
    v50 = nil;
    { popv(5); return onevalue(v50); }
/* error exit handlers */
v11:
    popv(5);
    return nil;
}



/* Code for cgp_lbc */

static Lisp_Object CC_cgp_lbc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56;
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
    v56 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_lbc */
        return (*qfn1(fn))(qenv(fn), v56);
    }
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for intervalom */

static Lisp_Object CC_intervalom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v90, v32;
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
    v70 = stack[-2];
    v70 = qcdr(v70);
    v70 = qcar(v70);
    stack[-3] = v70;
    v70 = stack[-2];
    v70 = qcar(v70);
    stack[-1] = v70;
    v90 = stack[-1];
    v70 = elt(env, 1); /* lowupperlimit */
    if (!(v90 == v70)) goto v44;
    v70 = elt(env, 2); /* integer_interval */
    stack[-1] = v70;
    v70 = qvalue(elt(env, 3)); /* nil */
    stack[-3] = v70;
    v70 = stack[-2];
    v32 = qcar(v70);
    v90 = qvalue(elt(env, 3)); /* nil */
    v70 = stack[-2];
    v70 = qcdr(v70);
    v70 = list2star(v32, v90, v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    stack[-2] = v70;
    goto v44;

v44:
    v90 = stack[-1];
    v70 = qvalue(elt(env, 4)); /* valid_om!* */
    v70 = Lassoc(nil, v90, v70);
    v70 = qcdr(v70);
    v70 = qcar(v70);
    stack[0] = v70;
    v70 = stack[-3];
    if (v70 == nil) goto v22;
    v70 = stack[-3];
    v70 = qcar(v70);
    v70 = qcdr(v70);
    v70 = qcar(v70);
    v90 = Lintern(nil, v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = qvalue(elt(env, 5)); /* interval!* */
    v70 = Lassoc(nil, v90, v70);
    v70 = qcdr(v70);
    v70 = qcar(v70);
    stack[-1] = v70;
    goto v22;

v22:
    v70 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* indent!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = stack[0];
    v70 = Lprinc(nil, v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = elt(env, 9); /* """ name=""" */
    v70 = Lprinc(nil, v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = stack[-1];
    v70 = Lprinc(nil, v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = elt(env, 10); /* """/>" */
    v70 = Lprinc(nil, v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = stack[-2];
    v70 = qcdr(v70);
    v70 = qcdr(v70);
    fn = elt(env, 14); /* multiom */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v70 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v70 = nil;
    { popv(5); return onevalue(v70); }
/* error exit handlers */
v62:
    popv(5);
    return nil;
}



/* Code for freeof */

static Lisp_Object CC_freeof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v58;
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
    v65 = stack[0];
    v64 = stack[-1];
    fn = elt(env, 2); /* smember */
    v64 = (*qfn2(fn))(qenv(fn), v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    if (!(v64 == nil)) goto v18;
    v65 = stack[0];
    v64 = stack[-1];
    v58 = qvalue(elt(env, 1)); /* depl!* */
    v64 = Lassoc(nil, v64, v58);
    v64 = Lmember(nil, v65, v64);
    goto v18;

v18:
    v64 = (v64 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v64); }
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for tchscheme2 */

static Lisp_Object MS_CDECL CC_tchscheme2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
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
    v8 = (Lisp_Object)1; /* 0 */
    stack[0] = v8;
    goto v117;

v117:
    v9 = qvalue(elt(env, 1)); /* rowmax */
    v8 = stack[0];
    v8 = difference2(v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v8 = Lminusp(nil, v8);
    env = stack[-1];
    if (v8 == nil) goto v77;
    v8 = nil;
    { popv(2); return onevalue(v8); }

v77:
    v8 = stack[0];
    fn = elt(env, 3); /* removechild */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v8 = stack[0];
    fn = elt(env, 4); /* to!*scheme */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v8 = stack[0];
    v8 = add1(v8);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    stack[0] = v8;
    goto v117;
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for contposp */

static Lisp_Object CC_contposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v67 = v0;
/* end of prologue */

v55:
    v78 = v67;
    v78 = (v78 == nil ? lisp_true : nil);
    if (!(v78 == nil)) return onevalue(v78);
    v78 = v67;
    v78 = qcar(v78);
    if (!consp(v78)) goto v117;
    v67 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v67);

v117:
    v67 = qcdr(v67);
    goto v55;
}



/* Code for exdfprn */

static Lisp_Object CC_exdfprn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v302;
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
    v302 = elt(env, 1); /* "d" */
    fn = elt(env, 2); /* prin2!* */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v302 = stack[0];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    {
        popv(2);
        fn = elt(env, 3); /* rembras */
        return (*qfn1(fn))(qenv(fn), v302);
    }
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for endmodule */

static Lisp_Object MS_CDECL CC_endmodule(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82;
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
    v82 = qvalue(elt(env, 1)); /* mode!-list!* */
    if (!(v82 == nil)) goto v18;
    v82 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v82 == nil)) goto v24;
    v82 = elt(env, 3); /* "ENDMODULE called outside module" */
    fn = elt(env, 9); /* lprie */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[0];
    goto v24;

v24:
    v82 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[0];
    goto v18;

v18:
    v82 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 5)) = v82; /* exportslist!* */
    v82 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 6)) = v82; /* importslist!* */
    v82 = qvalue(elt(env, 4)); /* nil */
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[0];
    qvalue(elt(env, 7)) = v82; /* alglist!* */
    v82 = qvalue(elt(env, 1)); /* mode!-list!* */
    v82 = qcar(v82);
    qvalue(elt(env, 8)) = v82; /* !*mode */
    v82 = qvalue(elt(env, 1)); /* mode!-list!* */
    v82 = qcdr(v82);
    qvalue(elt(env, 1)) = v82; /* mode!-list!* */
    v82 = nil;
    { popv(1); return onevalue(v82); }
/* error exit handlers */
v47:
    popv(1);
    return nil;
}



/* Code for gfstorval */

static Lisp_Object CC_gfstorval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v103, v74;
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
    v117 = v1;
    v103 = v0;
/* end of prologue */
    v74 = v103;
    v103 = v117;
    v117 = qvalue(elt(env, 1)); /* !*xnlist */
    v117 = acons(v74, v103, v117);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[0];
    qvalue(elt(env, 1)) = v117; /* !*xnlist */
    { popv(1); return onevalue(v117); }
/* error exit handlers */
v75:
    popv(1);
    return nil;
}



/* Code for natnump */

static Lisp_Object CC_natnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for natnump");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v78 = v0;
/* end of prologue */
    v67 = v78;
    v67 = integerp(v67);
    if (v67 == nil) goto v18;
    v67 = (Lisp_Object)1; /* 0 */
        return Lgeq(nil, v78, v67);

v18:
    v67 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v67);
}



setup_type const u35_setup[] =
{
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
    {NULL, (one_args *)"u35", (two_args *)"4941 4657502 4876500", 0}
};

/* end of generated code */
