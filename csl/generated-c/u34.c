
/* $destdir\u34.c        Machine generated C code */

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


/* Code for applsmacro */

static Lisp_Object MS_CDECL CC_applsmacro(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68;
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
    v68 = v0;
/* end of prologue */
    stack[-5] = nil;
    v67 = v68;
    v67 = qcdr(v67);
    v67 = qcar(v67);
    stack[-2] = v67;
    v67 = v68;
    v67 = qcdr(v67);
    v67 = qcdr(v67);
    v67 = qcar(v67);
    stack[-7] = v67;
    v67 = stack[-2];
    stack[0] = Llength(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = stack[-6];
    v67 = Llength(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    if (equal(stack[0], v67)) goto v70;
    v68 = elt(env, 1); /* "Argument mismatch for SMACRO" */
    v67 = stack[-1];
    v67 = list2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v68 = v67;
    v67 = v68;
    qvalue(elt(env, 2)) = v67; /* errmsg!* */
    v67 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v67 == nil)) goto v71;
    v67 = v68;
    fn = elt(env, 7); /* lprie */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    goto v71;

v71:
    v67 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    goto v70;

v70:
    v67 = stack[-6];
    fn = elt(env, 8); /* no!-side!-effect!-listp */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    if (!(v67 == nil)) goto v72;
    v68 = stack[-2];
    v67 = stack[-7];
    fn = elt(env, 9); /* one!-entry!-listp */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    if (!(v67 == nil)) goto v72;
    v67 = stack[-2];
    v68 = Llength(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = (Lisp_Object)17; /* 1 */
    v67 = (Lisp_Object)greaterp2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v67 = v67 ? lisp_true : nil;
    env = stack[-8];
    if (v67 == nil) goto v73;
    v67 = stack[-2];
    stack[-4] = v67;
    v67 = stack[-4];
    if (v67 == nil) goto v74;
    v67 = stack[-4];
    v67 = qcar(v67);
    stack[0] = v67;
    v67 = elt(env, 5); /* g */
    v67 = Lgensym1(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = cons(stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-2] = v67;
    stack[-3] = v67;
    goto v75;

v75:
    v67 = stack[-4];
    v67 = qcdr(v67);
    stack[-4] = v67;
    v67 = stack[-4];
    if (v67 == nil) goto v76;
    stack[-1] = stack[-2];
    v67 = stack[-4];
    v67 = qcar(v67);
    stack[0] = v67;
    v67 = elt(env, 5); /* g */
    v67 = Lgensym1(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = cons(stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = Lrplacd(nil, stack[-1], v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = stack[-2];
    v67 = qcdr(v67);
    stack[-2] = v67;
    goto v75;

v76:
    v67 = stack[-3];
    goto v77;

v77:
    stack[0] = v67;
    v68 = stack[0];
    v67 = stack[-7];
    fn = elt(env, 10); /* subla!-q */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-7] = v67;
    v67 = stack[0];
    stack[-3] = v67;
    v67 = stack[-3];
    if (v67 == nil) goto v78;
    v67 = stack[-3];
    v67 = qcar(v67);
    v67 = qcdr(v67);
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-1] = v67;
    stack[-2] = v67;
    goto v79;

v79:
    v67 = stack[-3];
    v67 = qcdr(v67);
    stack[-3] = v67;
    v67 = stack[-3];
    if (v67 == nil) goto v80;
    stack[0] = stack[-1];
    v67 = stack[-3];
    v67 = qcar(v67);
    v67 = qcdr(v67);
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = Lrplacd(nil, stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v79;

v80:
    v67 = stack[-2];
    goto v81;

v81:
    stack[-2] = v67;
    goto v73;

v73:
    v67 = stack[-6];
    stack[-1] = v67;
    goto v82;

v82:
    v67 = stack[-1];
    if (v67 == nil) goto v83;
    v67 = stack[-1];
    v67 = qcar(v67);
    stack[0] = v67;
    v67 = stack[0];
    fn = elt(env, 11); /* no!-side!-effectp */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    if (!(v67 == nil)) goto v84;
    v67 = stack[-2];
    v68 = qcar(v67);
    v67 = stack[-7];
    fn = elt(env, 12); /* one!-entryp */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    if (!(v67 == nil)) goto v84;
    stack[-3] = stack[-5];
    v67 = stack[-2];
    v68 = qcar(v67);
    v67 = stack[0];
    v67 = cons(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = Lnconc(nil, stack[-3], v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-5] = v67;
    goto v85;

v85:
    v67 = stack[-2];
    v67 = qcdr(v67);
    stack[-2] = v67;
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v82;

v84:
    v67 = stack[-2];
    v68 = qcar(v67);
    v67 = stack[0];
    v67 = cons(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v68 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = stack[-7];
    fn = elt(env, 10); /* subla!-q */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-7] = v67;
    goto v85;

v83:
    v67 = stack[-5];
    if (v67 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    stack[-4] = elt(env, 6); /* lambda */
    v67 = stack[-5];
    stack[-3] = v67;
    v67 = stack[-3];
    if (v67 == nil) goto v86;
    v67 = stack[-3];
    v67 = qcar(v67);
    v67 = qcar(v67);
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-1] = v67;
    stack[-2] = v67;
    goto v87;

v87:
    v67 = stack[-3];
    v67 = qcdr(v67);
    stack[-3] = v67;
    v67 = stack[-3];
    if (v67 == nil) goto v88;
    stack[0] = stack[-1];
    v67 = stack[-3];
    v67 = qcar(v67);
    v67 = qcar(v67);
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = Lrplacd(nil, stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v87;

v88:
    v67 = stack[-2];
    v68 = v67;
    goto v89;

v89:
    v67 = stack[-7];
    stack[-3] = list3(stack[-4], v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = stack[-5];
    stack[-4] = v67;
    v67 = stack[-4];
    if (v67 == nil) goto v90;
    v67 = stack[-4];
    v67 = qcar(v67);
    v67 = qcdr(v67);
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-1] = v67;
    stack[-2] = v67;
    goto v91;

v91:
    v67 = stack[-4];
    v67 = qcdr(v67);
    stack[-4] = v67;
    v67 = stack[-4];
    if (v67 == nil) goto v92;
    stack[0] = stack[-1];
    v67 = stack[-4];
    v67 = qcar(v67);
    v67 = qcdr(v67);
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = Lrplacd(nil, stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v91;

v92:
    v67 = stack[-2];
    goto v93;

v93:
    {
        Lisp_Object v94 = stack[-3];
        popv(9);
        return cons(v94, v67);
    }

v90:
    v67 = qvalue(elt(env, 4)); /* nil */
    goto v93;

v86:
    v67 = qvalue(elt(env, 4)); /* nil */
    v68 = v67;
    goto v89;

v78:
    v67 = qvalue(elt(env, 4)); /* nil */
    goto v81;

v74:
    v67 = qvalue(elt(env, 4)); /* nil */
    goto v77;

v72:
    v68 = stack[-2];
    v67 = stack[-6];
    fn = elt(env, 13); /* pair */
    v68 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v67 = stack[-7];
    {
        popv(9);
        fn = elt(env, 10); /* subla!-q */
        return (*qfn2(fn))(qenv(fn), v68, v67);
    }
/* error exit handlers */
v69:
    popv(9);
    return nil;
}



/* Code for mk_dummy_ids */

static Lisp_Object CC_mk_dummy_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
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
    v103 = v0;
/* end of prologue */
    v104 = v103;
    v104 = qcar(v104);
    v103 = qcdr(v103);
    v103 = qcar(v103);
    fn = elt(env, 4); /* intersection */
    v103 = (*qfn2(fn))(qenv(fn), v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    fn = elt(env, 5); /* clean_numid */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    stack[0] = v103;
    v104 = stack[0];
    v103 = elt(env, 1); /* dummy */
    v103 = Lflag(nil, v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v104 = stack[0];
    v103 = elt(env, 2); /* reserved */
    v103 = Lflag(nil, v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v104 = stack[0];
    v103 = qvalue(elt(env, 3)); /* dummy_id!* */
    fn = elt(env, 6); /* union */
    v103 = (*qfn2(fn))(qenv(fn), v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    qvalue(elt(env, 3)) = v103; /* dummy_id!* */
    v103 = nil;
    { popv(2); return onevalue(v103); }
/* error exit handlers */
v105:
    popv(2);
    return nil;
}



/* Code for makeqn!-maybe */

static Lisp_Object MS_CDECL CC_makeqnKmaybe(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v100, v109;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeqn-maybe");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeqn-maybe");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v99 = v2;
    v100 = v1;
    v109 = v0;
/* end of prologue */
    if (!(v99 == nil)) return onevalue(v100);
    v99 = elt(env, 1); /* equal */
    return list3(v99, v109, v100);
}



/* Code for noncomfree */

static Lisp_Object CC_noncomfree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110;
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

v111:
    v110 = stack[0];
    if (symbolp(v110)) goto v14;
    v110 = stack[0];
    v110 = (consp(v110) ? nil : lisp_true);
    if (!(v110 == nil)) { popv(2); return onevalue(v110); }
    v110 = stack[0];
    v110 = qcar(v110);
    v110 = CC_noncomfree(env, v110);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    if (v110 == nil) goto v112;
    v110 = stack[0];
    v110 = qcdr(v110);
    stack[0] = v110;
    goto v111;

v112:
    v110 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v110); }

v14:
    v110 = stack[0];
    if (!symbolp(v110)) v110 = nil;
    else { v110 = qfastgets(v110);
           if (v110 != nil) { v110 = elt(v110, 0); /* noncom */
#ifdef RECORD_GET
             if (v110 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v110 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v110 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v110 == SPID_NOPROP) v110 = nil; else v110 = lisp_true; }}
#endif
    v110 = (v110 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v110); }
/* error exit handlers */
v98:
    popv(2);
    return nil;
}



/* Code for containerom */

static Lisp_Object CC_containerom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v125;
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
    v124 = stack[-2];
    v124 = qcdr(v124);
    v124 = qcar(v124);
    stack[-1] = v124;
    v124 = stack[-2];
    v124 = qcar(v124);
    stack[0] = v124;
    v124 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 15); /* printout */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 16); /* indent!* */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v125 = stack[0];
    v124 = elt(env, 3); /* vectorml */
    if (!(v125 == v124)) goto v65;
    v124 = elt(env, 4); /* vector */
    stack[0] = v124;
    goto v65;

v65:
    v125 = stack[0];
    v124 = qvalue(elt(env, 5)); /* valid_om!* */
    v124 = Lassoc(nil, v125, v124);
    v124 = qcdr(v124);
    v124 = qcar(v124);
    stack[-3] = v124;
    v124 = stack[-2];
    v125 = qcar(v124);
    v124 = elt(env, 6); /* set */
    if (!(v125 == v124)) goto v127;
    v124 = stack[-1];
    v124 = Lconsp(nil, v124);
    env = stack[-4];
    if (v124 == nil) goto v127;
    v124 = stack[-1];
    v124 = qcar(v124);
    v124 = qcdr(v124);
    v124 = qcar(v124);
    v125 = Lintern(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = elt(env, 7); /* multiset */
    if (!(v125 == v124)) goto v127;
    v124 = elt(env, 8); /* multiset1 */
    stack[-3] = v124;
    goto v127;

v127:
    v124 = stack[-2];
    v125 = qcar(v124);
    v124 = elt(env, 3); /* vectorml */
    if (!(v125 == v124)) goto v128;
    v124 = elt(env, 10); /* "vector" */
    stack[0] = v124;
    goto v128;

v128:
    v124 = stack[-2];
    v125 = qcar(v124);
    v124 = elt(env, 3); /* vectorml */
    if (!(v125 == v124)) goto v129;
    v125 = elt(env, 4); /* vector */
    v124 = stack[-2];
    v124 = qcdr(v124);
    v124 = cons(v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    stack[-2] = v124;
    goto v129;

v129:
    v124 = elt(env, 11); /* "<OMS cd=""" */
    fn = elt(env, 15); /* printout */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = stack[-3];
    v124 = Lprinc(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = elt(env, 12); /* """ name=""" */
    v124 = Lprinc(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = stack[0];
    v124 = Lprinc(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = elt(env, 13); /* """/>" */
    v124 = Lprinc(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = stack[-2];
    v124 = qcdr(v124);
    v124 = qcdr(v124);
    fn = elt(env, 17); /* multiom */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 16); /* indent!* */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    v124 = elt(env, 14); /* "</OMA>" */
    fn = elt(env, 15); /* printout */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v124 = nil;
    { popv(5); return onevalue(v124); }
/* error exit handlers */
v126:
    popv(5);
    return nil;
}



/* Code for ldf!-dep!-var */

static Lisp_Object CC_ldfKdepKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v134;
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
    v133 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v133;
    goto v135;

v135:
    v133 = stack[-1];
    if (v133 == nil) goto v41;
    v133 = stack[-1];
    v133 = qcar(v133);
    stack[0] = v133;
    v133 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v134 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    v133 = qvalue(elt(env, 2)); /* depl!* */
    v133 = Lassoc(nil, v134, v133);
    if (v133 == nil) goto v107;
    v133 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v134 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    v133 = qvalue(elt(env, 2)); /* depl!* */
    v133 = Lassoc(nil, v134, v133);
    v134 = qcdr(v133);
    v133 = stack[-2];
    v133 = Lappend(nil, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    stack[-2] = v133;
    goto v107;

v107:
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-1] = v133;
    goto v135;

v41:
    v133 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* makeset */
        return (*qfn1(fn))(qenv(fn), v133);
    }
/* error exit handlers */
v136:
    popv(4);
    return nil;
}



/* Code for findhr */

static Lisp_Object MS_CDECL CC_findhr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v145, v127;
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
    goto v101;

v101:
    v145 = qvalue(elt(env, 1)); /* headhisto */
    v72 = (Lisp_Object)1; /* 0 */
    v72 = (Lisp_Object)greaterp2(v145, v72);
    nil = C_nil;
    if (exception_pending()) goto v58;
    v72 = v72 ? lisp_true : nil;
    env = stack[-2];
    if (v72 == nil) goto v10;
    v145 = qvalue(elt(env, 2)); /* codhisto */
    v72 = qvalue(elt(env, 1)); /* headhisto */
    v72 = *(Lisp_Object *)((char *)v145 + (CELL-TAG_VECTOR) + ((int32_t)v72/(16/CELL)));
    stack[-1] = v72;
    if (!(v72 == nil)) goto v10;
    v72 = qvalue(elt(env, 1)); /* headhisto */
    v72 = sub1(v72);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    qvalue(elt(env, 1)) = v72; /* headhisto */
    goto v101;

v10:
    v72 = stack[-1];
    if (v72 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v72 = stack[-1];
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    qvalue(elt(env, 4)) = v72; /* psi */
    v72 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 5)) = v72; /* npsi */
    stack[0] = qvalue(elt(env, 6)); /* codmat */
    v145 = qvalue(elt(env, 7)); /* maxvar */
    v72 = stack[-1];
    v72 = plus2(v145, v72);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v127 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v72/(16/CELL)));
    v145 = (Lisp_Object)1; /* 0 */
    v72 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v127 + (CELL-TAG_VECTOR) + ((int32_t)v145/(16/CELL))) = v72;
    v145 = stack[-1];
    v72 = qvalue(elt(env, 8)); /* rcoccup */
    v72 = cons(v145, v72);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    qvalue(elt(env, 8)) = v72; /* rcoccup */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for suchp */

static Lisp_Object CC_suchp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v107;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for suchp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v107 = v0;
/* end of prologue */
    v112 = v107;
    if (!consp(v112)) goto v14;
    v112 = v107;
    v112 = qcar(v112);
    v107 = elt(env, 2); /* such!-that */
    v112 = (v112 == v107 ? lisp_true : nil);
    return onevalue(v112);

v14:
    v112 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v112);
}



/* Code for evequal */

static Lisp_Object CC_evequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v133, v134, v147, v148;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evequal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v1;
    v147 = v0;
/* end of prologue */

v10:
    v141 = v147;
    if (!(v141 == nil)) goto v149;
    v141 = v134;
    if (!(v141 == nil)) goto v149;
    v141 = qvalue(elt(env, 1)); /* t */
    return onevalue(v141);

v149:
    v141 = v147;
    if (v141 == nil) goto v150;
    v141 = v134;
    if (v141 == nil) goto v112;
    v148 = (Lisp_Object)1; /* 0 */
    v141 = v147;
    v133 = qcar(v141);
    v141 = v134;
    v141 = qcar(v141);
    v141 = (Lisp_Object)(int32_t)((int32_t)v133 - (int32_t)v141 + TAG_FIXNUM);
    if (v148 == v141) goto v144;
    v141 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v141);

v144:
    v141 = v147;
    v141 = qcdr(v141);
    v147 = v141;
    v141 = v134;
    v141 = qcdr(v141);
    v134 = v141;
    goto v10;

v112:
    v141 = elt(env, 2); /* (0) */
    v134 = v141;
    goto v10;

v150:
    v141 = elt(env, 2); /* (0) */
    v147 = v141;
    goto v10;
}



/* Code for !:log10 */

static Lisp_Object CC_Tlog10(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v71;
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
    v71 = elt(env, 0); /* !:log10 */
    v104 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v104 = (*qfn2(fn))(qenv(fn), v71, v104);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v104;
    v71 = stack[-1];
    v104 = elt(env, 1); /* not_found */
    if (!(v71 == v104)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v71 = qvalue(elt(env, 2)); /* bften!* */
    v104 = stack[0];
    fn = elt(env, 4); /* log!: */
    v104 = (*qfn2(fn))(qenv(fn), v71, v104);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v104;
    v71 = elt(env, 0); /* !:log10 */
    v104 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v104 = (*qfn2(fn))(qenv(fn), v71, v104);
    nil = C_nil;
    if (exception_pending()) goto v153;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for getphystypeexpt */

static Lisp_Object CC_getphystypeexpt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v154;
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
    v65 = stack[0];
    fn = elt(env, 3); /* getphystypecar */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    v154 = v65;
    v65 = v154;
    if (v65 == nil) goto v149;
    v65 = stack[0];
    v65 = qcdr(v65);
    v65 = qcar(v65);
    if (!(is_number(v65))) { popv(2); return onevalue(v154); }
    v65 = stack[0];
    v65 = qcdr(v65);
    v65 = qcar(v65);
    v65 = Levenp(nil, v65);
    env = stack[-1];
    if (v65 == nil) { popv(2); return onevalue(v154); }
    v65 = elt(env, 2); /* scalar */
    { popv(2); return onevalue(v65); }

v149:
    v65 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v65); }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for calc_coeffmap_ */

static Lisp_Object MS_CDECL CC_calc_coeffmap_(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v153, v130;
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
    v132 = v0;
/* end of prologue */
    v153 = v132;
    v132 = stack[-1];
    fn = elt(env, 2); /* calc_map_ */
    v132 = (*qfn2(fn))(qenv(fn), v153, v132);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-4];
    v130 = v132;
    v153 = v130;
    v132 = (Lisp_Object)1; /* 0 */
    if (v153 == v132) goto v150;
    stack[-3] = elt(env, 1); /* times */
    stack[0] = v130;
    v153 = stack[-2];
    v132 = stack[-1];
    fn = elt(env, 3); /* calc_coeff */
    v132 = (*qfn2(fn))(qenv(fn), v153, v132);
    nil = C_nil;
    if (exception_pending()) goto v141;
    {
        Lisp_Object v133 = stack[-3];
        Lisp_Object v134 = stack[0];
        popv(5);
        return list2star(v133, v134, v132);
    }

v150:
    v132 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v132); }
/* error exit handlers */
v141:
    popv(5);
    return nil;
}



/* Code for mkindxlist */

static Lisp_Object CC_mkindxlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v159;
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
    v114 = v0;
/* end of prologue */
    stack[-4] = v114;
    v114 = stack[-4];
    if (v114 == nil) goto v151;
    v114 = stack[-4];
    v114 = qcar(v114);
    v159 = v114;
    v114 = v159;
    v114 = integerp(v114);
    if (v114 == nil) goto v108;
    v114 = v159;
    fn = elt(env, 3); /* !*num2id */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    goto v107;

v107:
    v114 = ncons(v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    stack[-2] = v114;
    stack[-3] = v114;
    goto v41;

v41:
    v114 = stack[-4];
    v114 = qcdr(v114);
    stack[-4] = v114;
    v114 = stack[-4];
    if (v114 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v114 = stack[-4];
    v114 = qcar(v114);
    v159 = v114;
    v114 = v159;
    v114 = integerp(v114);
    if (v114 == nil) goto v72;
    v114 = v159;
    fn = elt(env, 3); /* !*num2id */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    goto v138;

v138:
    v114 = ncons(v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    v114 = Lrplacd(nil, stack[-1], v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    v114 = stack[-2];
    v114 = qcdr(v114);
    stack[-2] = v114;
    goto v41;

v72:
    v114 = v159;
    v114 = Lconsp(nil, v114);
    env = stack[-5];
    if (v114 == nil) goto v161;
    v114 = v159;
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = integerp(v114);
    if (v114 == nil) goto v161;
    stack[0] = elt(env, 2); /* minus */
    v114 = v159;
    v114 = qcdr(v114);
    v114 = qcar(v114);
    fn = elt(env, 3); /* !*num2id */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    v114 = list2(stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    goto v138;

v161:
    v114 = v159;
    goto v138;

v108:
    v114 = v159;
    v114 = Lconsp(nil, v114);
    env = stack[-5];
    if (v114 == nil) goto v131;
    v114 = v159;
    v114 = qcdr(v114);
    v114 = qcar(v114);
    v114 = integerp(v114);
    if (v114 == nil) goto v131;
    stack[0] = elt(env, 2); /* minus */
    v114 = v159;
    v114 = qcdr(v114);
    v114 = qcar(v114);
    fn = elt(env, 3); /* !*num2id */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    v114 = list2(stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-5];
    goto v107;

v131:
    v114 = v159;
    goto v107;

v151:
    v114 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v114); }
/* error exit handlers */
v160:
    popv(6);
    return nil;
}



/* Code for cl_rename!-vars */

static Lisp_Object CC_cl_renameKvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152;
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
    v152 = v0;
/* end of prologue */
    stack[0] = v152;
    fn = elt(env, 1); /* cl_replace!-varl */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    fn = elt(env, 2); /* cl_rename!-vars1 */
    v152 = (*qfn2(fn))(qenv(fn), stack[0], v152);
    nil = C_nil;
    if (exception_pending()) goto v162;
    v152 = qcar(v152);
    { popv(2); return onevalue(v152); }
/* error exit handlers */
v162:
    popv(2);
    return nil;
}



/* Code for rule */

static Lisp_Object MS_CDECL CC_rule(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v119, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v84, v187, v188, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule");
#endif
    if (stack >= stacklimit)
    {
        push4(v119,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v119);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v119;
    stack[0] = v2;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    v84 = stack[0];
    v186 = stack[-6];
    v186 = Lsubla(nil, v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-2] = v186;
    v84 = stack[-2];
    v186 = stack[-6];
    if (equal(v84, v186)) goto v136;
    v186 = stack[-2];
    if (!consp(v186)) goto v64;
    v186 = qvalue(elt(env, 4)); /* t */
    stack[-7] = v186;
    v186 = stack[-2];
    stack[-6] = v186;
    goto v136;

v136:
    v84 = stack[0];
    v186 = stack[-5];
    v186 = Lsubla(nil, v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-2] = v186;
    v84 = stack[-2];
    v186 = stack[-5];
    if (equal(v84, v186)) goto v157;
    v186 = stack[-2];
    stack[-5] = v186;
    v84 = stack[-5];
    v186 = elt(env, 5); /* !*sq!* */
    if (!consp(v84)) goto v157;
    v84 = qcar(v84);
    if (!(v84 == v186)) goto v157;
    v186 = stack[-5];
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 11); /* prepsq!* */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-5] = v186;
    goto v157;

v157:
    v186 = stack[0];
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v113;
    v186 = stack[-3];
    v186 = qcar(v186);
    v186 = qcdr(v186);
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-1] = v186;
    stack[-2] = v186;
    goto v191;

v191:
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v52;
    stack[0] = stack[-1];
    v186 = stack[-3];
    v186 = qcar(v186);
    v186 = qcdr(v186);
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = Lrplacd(nil, stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = stack[-1];
    v186 = qcdr(v186);
    stack[-1] = v186;
    goto v191;

v52:
    v186 = stack[-2];
    goto v75;

v75:
    stack[0] = v186;
    v84 = stack[0];
    v186 = qvalue(elt(env, 6)); /* mcond!* */
    fn = elt(env, 12); /* smemql */
    v186 = (*qfn2(fn))(qenv(fn), v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-2] = v186;
    v84 = stack[0];
    v186 = stack[-6];
    fn = elt(env, 12); /* smemql */
    v186 = (*qfn2(fn))(qenv(fn), v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-1] = v186;
    v84 = stack[-2];
    v186 = stack[-1];
    fn = elt(env, 13); /* setdiff */
    v84 = (*qfn2(fn))(qenv(fn), v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = v84;
    if (!(v84 == nil)) goto v192;
    v84 = stack[0];
    v186 = stack[-5];
    fn = elt(env, 12); /* smemql */
    v84 = (*qfn2(fn))(qenv(fn), v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = stack[-2];
    fn = elt(env, 13); /* setdiff */
    stack[0] = (*qfn2(fn))(qenv(fn), v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v84 = stack[-1];
    v186 = stack[-2];
    fn = elt(env, 13); /* setdiff */
    v186 = (*qfn2(fn))(qenv(fn), v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    fn = elt(env, 13); /* setdiff */
    v84 = (*qfn2(fn))(qenv(fn), stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = v84;
    if (!(v84 == nil)) goto v192;
    v84 = stack[-6];
    v186 = elt(env, 10); /* getel */
    if (!consp(v84)) goto v193;
    v84 = qcar(v84);
    if (!(v84 == v186)) goto v193;
    v186 = stack[-6];
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 14); /* eval */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    stack[-6] = v186;
    goto v193;

v193:
    v189 = stack[-6];
    v188 = stack[-5];
    v187 = qvalue(elt(env, 3)); /* nil */
    v84 = stack[-4];
    v186 = stack[-7];
    {
        popv(9);
        fn = elt(env, 15); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v189, v188, v187, v84, v186);
    }

v192:
    v84 = elt(env, 7); /* "Unmatched free variable(s)" */
    v186 = cons(v84, v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    fn = elt(env, 16); /* lprie */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-8];
    v186 = elt(env, 8); /* hold */
    qvalue(elt(env, 9)) = v186; /* erfg!* */
    v186 = qvalue(elt(env, 3)); /* nil */
    { popv(9); return onevalue(v186); }

v113:
    v186 = qvalue(elt(env, 3)); /* nil */
    goto v75;

v64:
    v189 = elt(env, 1); /* "Substitution for" */
    v188 = stack[-6];
    v187 = elt(env, 2); /* "not allowed" */
    v84 = qvalue(elt(env, 3)); /* nil */
    v186 = qvalue(elt(env, 4)); /* t */
    {
        popv(9);
        fn = elt(env, 17); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v189, v188, v187, v84, v186);
    }
/* error exit handlers */
v190:
    popv(9);
    return nil;
}



/* Code for setrd */

static Lisp_Object MS_CDECL CC_setrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v66;
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
    v109 = elt(env, 1); /* (t y p e != s e t !$) */
    qvalue(elt(env, 2)) = v109; /* atts */
    stack[0] = elt(env, 3); /* list */
    fn = elt(env, 4); /* stats_getargs */
    v109 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v109 = cons(stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v66 = v109;
    v109 = v66;
    stack[0] = qcar(v109);
    v109 = v66;
    v109 = qcdr(v109);
    fn = elt(env, 5); /* norepeat */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v65;
    {
        Lisp_Object v154 = stack[0];
        popv(2);
        return cons(v154, v109);
    }
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for countof */

static Lisp_Object CC_countof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v153;
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
    v153 = stack[-1];
    v132 = stack[0];
    if (equal(v153, v132)) goto v10;
    v132 = stack[0];
    if (!consp(v132)) goto v150;
    v153 = stack[-1];
    v132 = stack[0];
    v132 = qcar(v132);
    stack[-2] = CC_countof(env, v153, v132);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    v153 = stack[-1];
    v132 = stack[0];
    v132 = qcdr(v132);
    v132 = CC_countof(env, v153, v132);
    nil = C_nil;
    if (exception_pending()) goto v121;
    {
        Lisp_Object v73 = stack[-2];
        popv(4);
        return plus2(v73, v132);
    }

v150:
    v132 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v132); }

v10:
    v132 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v132); }
/* error exit handlers */
v121:
    popv(4);
    return nil;
}



/* Code for ps!:set!-term */

static Lisp_Object MS_CDECL CC_psTsetKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v211, v212;
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
    v210 = stack[-4];
    fn = elt(env, 7); /* ps!:order */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    stack[-5] = v210;
    v211 = stack[-3];
    v210 = stack[-5];
    v210 = (Lisp_Object)lessp2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v210 = v210 ? lisp_true : nil;
    env = stack[-6];
    if (v210 == nil) goto v131;
    v212 = stack[-3];
    v211 = elt(env, 1); /* "less than the order of " */
    v210 = stack[-4];
    v210 = list3(v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v211 = v210;
    v210 = v211;
    qvalue(elt(env, 2)) = v210; /* errmsg!* */
    v210 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v210 == nil)) goto v62;
    v210 = v211;
    fn = elt(env, 8); /* lprie */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v62;

v62:
    v210 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v151;

v151:
    v210 = stack[-4];
    if (!consp(v210)) goto v213;
    v210 = stack[-4];
    v211 = qcar(v210);
    v210 = elt(env, 5); /* !:ps!: */
    if (v211 == v210) goto v214;
    v210 = stack[-4];
    v211 = qcar(v210);
    v210 = elt(env, 6); /* dname */
    v210 = get(v211, v210);
    env = stack[-6];
    if (!(v210 == nil)) goto v213;

v214:
    v211 = stack[-4];
    v210 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 9); /* ps!:getv */
    v210 = (*qfn2(fn))(qenv(fn), v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v57;

v57:
    v211 = v210;
    v210 = stack[-2];
    if (!consp(v210)) goto v126;
    v210 = stack[-2];
    v210 = qcar(v210);
    if (!(v210 == nil)) goto v126;
    v211 = stack[-3];
    v210 = stack[-5];
    if (!(equal(v211, v210))) goto v167;
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)1; /* 0 */
    v210 = stack[-3];
    v210 = add1(v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    fn = elt(env, 10); /* ps!:putv */
    v210 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v167;

v167:
    v212 = stack[-4];
    v211 = (Lisp_Object)17; /* 1 */
    v210 = stack[-3];
    fn = elt(env, 10); /* ps!:putv */
    v210 = (*qfnn(fn))(qenv(fn), 3, v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v210 = nil;
    { popv(7); return onevalue(v210); }

v126:
    v210 = v211;
    if (v210 == nil) goto v215;
    stack[0] = v211;
    v211 = stack[-3];
    v210 = stack[-5];
    v211 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v210 = stack[-2];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v210 = Lnconc(nil, stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v167;

v215:
    stack[-1] = stack[-4];
    stack[0] = (Lisp_Object)81; /* 5 */
    v211 = stack[-3];
    v210 = stack[-5];
    v211 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v210 = stack[-2];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    fn = elt(env, 10); /* ps!:putv */
    v210 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v167;

v213:
    v212 = (Lisp_Object)1; /* 0 */
    v211 = stack[-4];
    v210 = (Lisp_Object)17; /* 1 */
    v210 = list2star(v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v210 = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v57;

v131:
    stack[0] = stack[-3];
    v210 = stack[-4];
    fn = elt(env, 11); /* ps!:last!-term */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v210 = (Lisp_Object)lesseq2(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v210 = v210 ? lisp_true : nil;
    env = stack[-6];
    if (v210 == nil) goto v151;
    v212 = stack[-3];
    v211 = elt(env, 4); /* "less than power of last term of " */
    v210 = stack[-4];
    v210 = list3(v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    v211 = v210;
    v210 = v211;
    qvalue(elt(env, 2)) = v210; /* errmsg!* */
    v210 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v210 == nil)) goto v56;
    v210 = v211;
    fn = elt(env, 8); /* lprie */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v56;

v56:
    v210 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-6];
    goto v151;
/* error exit handlers */
v165:
    popv(7);
    return nil;
}



/* Code for crprep1 */

static Lisp_Object CC_crprep1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v235, v93;
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
    v234 = v0;
/* end of prologue */
    v235 = v234;
    v235 = qcar(v235);
    v234 = qcdr(v234);
    stack[-3] = v235;
    stack[-2] = v234;
    v234 = stack[-2];
    if (is_number(v234)) goto v64;
    v234 = stack[-2];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v146;
    v234 = stack[-2];
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = (Lisp_Object)1; /* 0 */
    v234 = (v235 == v234 ? lisp_true : nil);
    goto v102;

v102:
    if (!(v234 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v64:
    v234 = stack[-2];
    if (is_number(v234)) goto v103;
    v234 = stack[-2];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v131;
    v235 = stack[-2];
    v234 = elt(env, 1); /* !:rd!: */
    if (!consp(v235)) goto v142;
    v235 = qcar(v235);
    if (!(v235 == v234)) goto v142;
    v234 = stack[-2];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v142;
    v234 = stack[-2];
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = (Lisp_Object)1; /* 0 */
    v234 = (Lisp_Object)lessp2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v234 = v234 ? lisp_true : nil;
    env = stack[-4];
    goto v130;

v130:
    if (v234 == nil) goto v103;
    stack[-1] = elt(env, 3); /* minus */
    v234 = stack[-2];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v159;
    stack[0] = elt(env, 1); /* !:rd!: */
    v234 = stack[-2];
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v235 = negate(v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    v234 = stack[-2];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = list2star(stack[0], v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    goto v161;

v161:
    fn = elt(env, 5); /* crprimp */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    v234 = list2(stack[-1], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    goto v96;

v96:
    stack[-2] = v234;
    v234 = stack[-3];
    if (is_number(v234)) goto v215;
    v234 = stack[-3];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v181;
    v234 = stack[-3];
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = (Lisp_Object)1; /* 0 */
    v234 = (v235 == v234 ? lisp_true : nil);
    goto v237;

v237:
    if (!(v234 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v215:
    v235 = stack[-3];
    v234 = (Lisp_Object)-15; /* -1 */
    if (v235 == v234) goto v200;
    v234 = stack[-3];
    if (is_number(v234)) goto v238;
    v234 = stack[-3];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v34;
    v235 = stack[-3];
    v234 = elt(env, 1); /* !:rd!: */
    if (!consp(v235)) goto v83;
    v235 = qcar(v235);
    if (!(v235 == v234)) goto v83;
    v234 = stack[-3];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v83;
    v234 = stack[-3];
    v234 = qcdr(v234);
    v235 = qcar(v234);
    v234 = (Lisp_Object)1; /* 0 */
    v234 = (Lisp_Object)lessp2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v234 = v234 ? lisp_true : nil;
    env = stack[-4];
    goto v239;

v239:
    if (v234 == nil) goto v238;
    stack[-1] = elt(env, 3); /* minus */
    v234 = stack[-3];
    v234 = qcdr(v234);
    if (!consp(v234)) goto v240;
    stack[0] = elt(env, 1); /* !:rd!: */
    v234 = stack[-3];
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v235 = negate(v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    v234 = stack[-3];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = list2star(stack[0], v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    goto v163;

v163:
    v234 = list2(stack[-1], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    stack[-3] = v234;
    goto v238;

v238:
    v93 = elt(env, 4); /* plus */
    v235 = stack[-3];
    v234 = stack[-2];
    popv(5);
    return list3(v93, v235, v234);

v240:
    stack[0] = elt(env, 1); /* !:rd!: */
    v234 = stack[-3];
    v234 = qcdr(v234);
    v234 = negate(v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    v234 = cons(stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    goto v163;

v83:
    v234 = qvalue(elt(env, 2)); /* nil */
    goto v239;

v34:
    v234 = stack[-3];
    v234 = qcdr(v234);
    v234 = Lminusp(nil, v234);
    env = stack[-4];
    goto v239;

v200:
    v235 = elt(env, 3); /* minus */
    v234 = (Lisp_Object)17; /* 1 */
    v234 = list2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    stack[-3] = v234;
    goto v238;

v181:
    v234 = stack[-3];
    v234 = qcdr(v234);
    v234 = (Lisp_Object)zerop(v234);
    v234 = v234 ? lisp_true : nil;
    env = stack[-4];
    goto v237;

v159:
    stack[0] = elt(env, 1); /* !:rd!: */
    v234 = stack[-2];
    v234 = qcdr(v234);
    v234 = negate(v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    v234 = cons(stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    goto v161;

v103:
    v234 = stack[-2];
    fn = elt(env, 5); /* crprimp */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-4];
    goto v96;

v142:
    v234 = qvalue(elt(env, 2)); /* nil */
    goto v130;

v131:
    v234 = stack[-2];
    v234 = qcdr(v234);
    v234 = Lminusp(nil, v234);
    env = stack[-4];
    goto v130;

v146:
    v234 = stack[-2];
    v234 = qcdr(v234);
    v234 = (Lisp_Object)zerop(v234);
    v234 = v234 ? lisp_true : nil;
    env = stack[-4];
    goto v102;
/* error exit handlers */
v236:
    popv(5);
    return nil;
}



/* Code for groebinvokecritm */

static Lisp_Object CC_groebinvokecritm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v132;
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
    v105 = stack[-1];
    stack[-3] = v105;
    goto v25;

v25:
    v105 = stack[-3];
    if (v105 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v105 = stack[-3];
    v105 = qcar(v105);
    stack[0] = v105;
    v105 = stack[-2];
    v132 = qcar(v105);
    v105 = stack[0];
    v105 = qcar(v105);
    fn = elt(env, 3); /* buchvevdivides!? */
    v105 = (*qfn2(fn))(qenv(fn), v132, v105);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    if (v105 == nil) goto v70;
    v105 = qvalue(elt(env, 2)); /* mcount!* */
    v105 = add1(v105);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    qvalue(elt(env, 2)) = v105; /* mcount!* */
    v132 = stack[0];
    v105 = stack[-1];
    fn = elt(env, 4); /* groedeletip */
    v105 = (*qfn2(fn))(qenv(fn), v132, v105);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-1] = v105;
    goto v70;

v70:
    v105 = stack[-3];
    v105 = qcdr(v105);
    stack[-3] = v105;
    goto v25;
/* error exit handlers */
v121:
    popv(5);
    return nil;
}



/* Code for evzero */

static Lisp_Object MS_CDECL CC_evzero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v63;
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
    v155 = (Lisp_Object)17; /* 1 */
    stack[0] = v155;
    goto v150;

v150:
    v155 = qvalue(elt(env, 1)); /* dipvars!* */
    v63 = Llength(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    v155 = stack[0];
    v155 = difference2(v63, v155);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    v155 = Lminusp(nil, v155);
    env = stack[-2];
    if (!(v155 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v63 = (Lisp_Object)1; /* 0 */
    v155 = stack[-1];
    v155 = cons(v63, v155);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    stack[-1] = v155;
    v155 = stack[0];
    v155 = add1(v155);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    stack[0] = v155;
    goto v150;
/* error exit handlers */
v95:
    popv(3);
    return nil;
}



/* Code for exdf0 */

static Lisp_Object CC_exdf0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v62;
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
    v64 = stack[0];
    v64 = qcar(v64);
    fn = elt(env, 1); /* exdff0 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v64 = stack[0];
    v64 = qcdr(v64);
    fn = elt(env, 2); /* negf */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    fn = elt(env, 1); /* exdff0 */
    v62 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v64 = stack[0];
    fn = elt(env, 3); /* multpfsq */
    v64 = (*qfn2(fn))(qenv(fn), v62, v64);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    fn = elt(env, 4); /* addpf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v64);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    v62 = (Lisp_Object)17; /* 1 */
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = cons(v62, v64);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-2];
    {
        Lisp_Object v104 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v104, v64);
    }
/* error exit handlers */
v103:
    popv(3);
    return nil;
}



/* Code for evalmember */

static Lisp_Object CC_evalmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v101;
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
    v152 = v1;
    v101 = v0;
/* end of prologue */
    stack[0] = v101;
    fn = elt(env, 1); /* getrlist */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v150;
    v152 = Lmember(nil, stack[0], v152);
    { popv(1); return onevalue(v152); }
/* error exit handlers */
v150:
    popv(1);
    return nil;
}



/* Code for !:log2 */

static Lisp_Object CC_Tlog2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v71;
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
    v71 = elt(env, 0); /* !:log2 */
    v104 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v104 = (*qfn2(fn))(qenv(fn), v71, v104);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v104;
    v71 = stack[-1];
    v104 = elt(env, 1); /* not_found */
    if (!(v71 == v104)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v71 = qvalue(elt(env, 2)); /* bftwo!* */
    v104 = stack[0];
    fn = elt(env, 4); /* log!: */
    v104 = (*qfn2(fn))(qenv(fn), v71, v104);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    stack[-1] = v104;
    v71 = elt(env, 0); /* !:log2 */
    v104 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v104 = (*qfn2(fn))(qenv(fn), v71, v104);
    nil = C_nil;
    if (exception_pending()) goto v153;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for absf */

static Lisp_Object CC_absf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101;
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
    v101 = stack[0];
    fn = elt(env, 1); /* minusf */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    if (v101 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* negf */
        return (*qfn1(fn))(qenv(fn), v101);
    }
/* error exit handlers */
v150:
    popv(2);
    return nil;
}



/* Code for getupper */

static Lisp_Object CC_getupper(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v152;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getupper");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v151 = v0;
/* end of prologue */
    v152 = qvalue(elt(env, 1)); /* metricu!* */
    v151 = Latsoc(nil, v151, v152);
    v151 = qcdr(v151);
    return onevalue(v151);
}



/* Code for groeb!=rf1 */

static Lisp_Object CC_groebMrf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v112;
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
    v70 = v0;
/* end of prologue */
    v112 = stack[0];
    fn = elt(env, 1); /* red_totalred */
    v112 = (*qfn2(fn))(qenv(fn), v112, v70);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v70 = stack[0];
    popv(1);
    return list2(v112, v70);
/* error exit handlers */
v106:
    popv(1);
    return nil;
}



/* Code for cl_sitheo */

static Lisp_Object CC_cl_sitheo(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v57;
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
    v58 = qvalue(elt(env, 2)); /* !*rlsithok */
    if (v58 == nil) goto v102;
    v58 = stack[-2];
    goto v41;

v41:
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    { popv(5); return onevalue(v58); }

v102:
    v58 = stack[-2];
    if (v58 == nil) goto v158;
    v58 = stack[-2];
    v58 = qcar(v58);
    stack[-3] = v58;
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    v59 = stack[-3];
    v58 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 7); /* cl_simplat */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-4];
    v57 = v58;
    v59 = v57;
    v58 = elt(env, 4); /* false */
    if (v59 == v58) goto v64;
    v59 = v57;
    v58 = elt(env, 6); /* true */
    if (v59 == v58) goto v102;
    v59 = v57;
    v58 = stack[-1];
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-4];
    stack[-1] = v58;
    goto v102;

v64:
    v58 = elt(env, 5); /* inctheo */
    stack[-3] = v58;
    v58 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v58;
    goto v102;

v158:
    v59 = stack[-3];
    v58 = elt(env, 5); /* inctheo */
    if (v59 == v58) goto v209;
    v58 = stack[-1];
    goto v41;

v209:
    v58 = elt(env, 5); /* inctheo */
    goto v41;
/* error exit handlers */
v129:
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
    Lisp_Object v101;
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
    v101 = v0;
/* end of prologue */
    v101 = qcar(v101);
    fn = elt(env, 3); /* getrtype */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[0];
    if (v101 == nil) goto v156;
    v101 = elt(env, 1); /* yetunknowntype */
    { popv(1); return onevalue(v101); }

v156:
    v101 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v101); }
/* error exit handlers */
v162:
    popv(1);
    return nil;
}



/* Code for mchsarg */

static Lisp_Object MS_CDECL CC_mchsarg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v33;
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
    v37 = stack[-6];
    fn = elt(env, 3); /* mtp */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    if (v37 == nil) goto v59;
    v33 = stack[-5];
    v37 = elt(env, 1); /* times */
    if (!(v33 == v37)) goto v41;
    v37 = stack[-1];
    fn = elt(env, 4); /* noncomfree */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    if (!(v37 == nil)) goto v41;

v59:
    v37 = stack[-1];
    fn = elt(env, 5); /* noncomperm */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-7] = v37;
    goto v250;

v250:
    v37 = stack[-7];
    if (v37 == nil) goto v48;
    v37 = stack[-7];
    v37 = qcar(v37);
    stack[-1] = v37;
    stack[0] = stack[-6];
    v37 = qvalue(elt(env, 2)); /* nil */
    v33 = ncons(v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v37 = stack[-5];
    fn = elt(env, 6); /* mcharg2 */
    v37 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v33, v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-4] = v37;
    v37 = stack[-4];
    fn = elt(env, 7); /* lastpair */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-3] = v37;
    v37 = stack[-7];
    v37 = qcdr(v37);
    stack[-7] = v37;
    v37 = stack[-3];
    if (!consp(v37)) goto v250;
    else goto v185;

v185:
    v37 = stack[-7];
    if (v37 == nil) goto v206;
    stack[-2] = stack[-3];
    v37 = stack[-7];
    v37 = qcar(v37);
    stack[-1] = v37;
    stack[0] = stack[-6];
    v37 = qvalue(elt(env, 2)); /* nil */
    v33 = ncons(v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v37 = stack[-5];
    fn = elt(env, 6); /* mcharg2 */
    v37 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v33, v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v37 = Lrplacd(nil, stack[-2], v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v37 = stack[-3];
    fn = elt(env, 7); /* lastpair */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-3] = v37;
    v37 = stack[-7];
    v37 = qcdr(v37);
    stack[-7] = v37;
    goto v185;

v206:
    v37 = stack[-4];
    goto v25;

v25:
        popv(9);
        return Lnreverse(nil, v37);

v48:
    v37 = qvalue(elt(env, 2)); /* nil */
    goto v25;

v41:
    v37 = stack[-6];
    fn = elt(env, 5); /* noncomperm */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-4] = v37;
    v37 = stack[-4];
    if (v37 == nil) goto v123;
    v37 = stack[-4];
    v37 = qcar(v37);
    v33 = v37;
    v37 = stack[-1];
    fn = elt(env, 8); /* pair */
    v37 = (*qfn2(fn))(qenv(fn), v33, v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v37 = ncons(v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    stack[-2] = v37;
    stack[-3] = v37;
    goto v154;

v154:
    v37 = stack[-4];
    v37 = qcdr(v37);
    stack[-4] = v37;
    v37 = stack[-4];
    if (v37 == nil) goto v134;
    stack[0] = stack[-2];
    v37 = stack[-4];
    v37 = qcar(v37);
    v33 = v37;
    v37 = stack[-1];
    fn = elt(env, 8); /* pair */
    v37 = (*qfn2(fn))(qenv(fn), v33, v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v37 = ncons(v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v37 = Lrplacd(nil, stack[0], v37);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-8];
    v37 = stack[-2];
    v37 = qcdr(v37);
    stack[-2] = v37;
    goto v154;

v134:
    v37 = stack[-3];
    goto v25;

v123:
    v37 = qvalue(elt(env, 2)); /* nil */
    goto v25;
/* error exit handlers */
v249:
    popv(9);
    return nil;
}



/* Code for aex_tad */

static Lisp_Object CC_aex_tad(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v107, v106;
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
    v112 = stack[0];
    fn = elt(env, 2); /* aex_ex */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    fn = elt(env, 3); /* ratpoly_tad */
    stack[-1] = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v112 = stack[0];
    fn = elt(env, 4); /* aex_ctx */
    v106 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v107 = qvalue(elt(env, 1)); /* nil */
    v112 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v109 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v109, v106, v107, v112);
    }
/* error exit handlers */
v100:
    popv(3);
    return nil;
}



/* Code for setfuncsnaryrd */

static Lisp_Object MS_CDECL CC_setfuncsnaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v134;
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
    v133 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    stack[0] = v133;
    v133 = stack[0];
    v133 = Lconsp(nil, v133);
    env = stack[-1];
    if (v133 == nil) goto v25;
    v133 = stack[0];
    v133 = qcdr(v133);
    v133 = qcar(v133);
    if (v133 == nil) goto v25;
    v133 = stack[0];
    v133 = qcdr(v133);
    v133 = qcar(v133);
    v133 = qcar(v133);
    v133 = qcdr(v133);
    v133 = qcar(v133);
    v134 = Lintern(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-1];
    v133 = elt(env, 1); /* multiset */
    if (!(v134 == v133)) goto v25;
    v133 = elt(env, 1); /* multiset */
    qvalue(elt(env, 2)) = v133; /* mmlatts */
    goto v25;

v25:
    v133 = stack[0];
    if (v133 == nil) goto v95;
    v133 = CC_setfuncsnaryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v148;
    {
        Lisp_Object v232 = stack[0];
        popv(2);
        return cons(v232, v133);
    }

v95:
    v133 = nil;
    { popv(2); return onevalue(v133); }
/* error exit handlers */
v148:
    popv(2);
    return nil;
}



/* Code for ciml */

static Lisp_Object MS_CDECL CC_ciml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96;
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
    v96 = qvalue(elt(env, 2)); /* atts */
    v95 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 5); /* search_att */
    v95 = (*qfn2(fn))(qenv(fn), v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    fn = elt(env, 6); /* lex */
    v95 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    v95 = qvalue(elt(env, 4)); /* char */
    stack[0] = v95;
    fn = elt(env, 6); /* lex */
    v95 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    v95 = stack[0];
    v95 = Lcompress(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    stack[0] = v95;
    v95 = stack[0];
    if (!(is_number(v95))) goto v100;
    v96 = stack[0];
    v95 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 7); /* errorml */
    v95 = (*qfn2(fn))(qenv(fn), v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v104;
    goto v100;

v100:
    v95 = stack[0];
        popv(2);
        return Lintern(nil, v95);
/* error exit handlers */
v104:
    popv(2);
    return nil;
}



/* Code for o!-nextarg */

static Lisp_Object CC_oKnextarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v39;
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
    v244 = qvalue(elt(env, 1)); /* !*udebug */
    if (v244 == nil) goto v146;
    v244 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* uprint */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v146;

v146:
    v39 = qvalue(elt(env, 3)); /* i */
    v244 = (Lisp_Object)17; /* 1 */
    if (!(v39 == v244)) goto v64;
    v39 = qvalue(elt(env, 3)); /* i */
    v244 = qvalue(elt(env, 4)); /* upb */
    v244 = (Lisp_Object)lesseq2(v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v244 = v244 ? lisp_true : nil;
    env = stack[-3];
    if (v244 == nil) goto v64;
    v244 = stack[-1];
    goto v101;

v101:
    stack[0] = v244;
    v244 = qvalue(elt(env, 3)); /* i */
    v244 = add1(v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    qvalue(elt(env, 3)) = v244; /* i */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v64:
    v39 = qvalue(elt(env, 3)); /* i */
    v244 = (Lisp_Object)1; /* 0 */
    if (!(v39 == v244)) goto v155;
    v39 = qvalue(elt(env, 3)); /* i */
    v244 = qvalue(elt(env, 4)); /* upb */
    v244 = (Lisp_Object)lesseq2(v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v244 = v244 ? lisp_true : nil;
    env = stack[-3];
    if (v244 == nil) goto v155;
    v39 = elt(env, 5); /* (null!-fn) */
    v244 = stack[-1];
    v244 = cons(v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v101;

v155:
    v244 = qvalue(elt(env, 6)); /* acontract */
    if (v244 == nil) goto v140;
    v39 = qvalue(elt(env, 3)); /* i */
    v244 = qvalue(elt(env, 4)); /* upb */
    v244 = (Lisp_Object)lesseq2(v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v244 = v244 ? lisp_true : nil;
    env = stack[-3];
    if (v244 == nil) goto v140;
    stack[-2] = qvalue(elt(env, 7)); /* op */
    v39 = stack[-1];
    v244 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 13); /* first0 */
    stack[0] = (*qfn2(fn))(qenv(fn), v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v39 = stack[-1];
    v244 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 14); /* last0 */
    v244 = (*qfn2(fn))(qenv(fn), v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v244 = acons(stack[-2], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    fn = elt(env, 15); /* mval */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v101;

v140:
    v244 = qvalue(elt(env, 8)); /* mcontract */
    if (v244 == nil) goto v74;
    v39 = qvalue(elt(env, 3)); /* i */
    v244 = qvalue(elt(env, 4)); /* upb */
    v244 = (Lisp_Object)lesseq2(v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v244 = v244 ? lisp_true : nil;
    env = stack[-3];
    if (v244 == nil) goto v74;
    stack[-2] = elt(env, 9); /* null!-fn */
    v39 = stack[-1];
    v244 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 13); /* first0 */
    stack[0] = (*qfn2(fn))(qenv(fn), v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v39 = stack[-1];
    v244 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 14); /* last0 */
    v244 = (*qfn2(fn))(qenv(fn), v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v244 = acons(stack[-2], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v101;

v74:
    v244 = qvalue(elt(env, 10)); /* expand */
    if (v244 == nil) goto v229;
    v244 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 10)) = v244; /* expand */
    v39 = qvalue(elt(env, 11)); /* identity */
    v244 = stack[-1];
    v244 = cons(v39, v244);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    goto v101;

v229:
    v244 = nil;
    goto v101;
/* error exit handlers */
v37:
    popv(4);
    return nil;
}



/* Code for ndepends */

static Lisp_Object CC_ndepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46;
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
    v45 = stack[-1];
    if (v45 == nil) goto v10;
    v45 = stack[-1];
    if (is_number(v45)) goto v10;
    v45 = stack[0];
    if (is_number(v45)) goto v10;
    v46 = stack[-1];
    v45 = stack[0];
    if (equal(v46, v45)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v45 = stack[-1];
    if (!(!consp(v45))) goto v96;
    v46 = stack[-1];
    v45 = qvalue(elt(env, 2)); /* frlis!* */
    v45 = Lmemq(nil, v46, v45);
    if (v45 == nil) goto v96;
    v45 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v45); }

v96:
    v46 = stack[-1];
    v45 = qvalue(elt(env, 4)); /* depl!* */
    v45 = Lassoc(nil, v46, v45);
    v46 = v45;
    v45 = v46;
    if (v45 == nil) goto v73;
    v45 = v46;
    v46 = qcdr(v45);
    v45 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v45 = (*qfn2(fn))(qenv(fn), v46, v45);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-2];
    goto v121;

v121:
    if (v45 == nil) goto v95;
    v45 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v45); }

v95:
    v45 = stack[-1];
    if (!consp(v45)) goto v118;
    v45 = stack[-1];
    v45 = qcar(v45);
    if (!(symbolp(v45))) goto v118;
    v45 = stack[-1];
    v46 = qcar(v45);
    v45 = elt(env, 5); /* dname */
    v45 = get(v46, v45);
    env = stack[-2];
    if (v45 == nil) goto v118;
    v45 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v45); }

v118:
    v45 = stack[-1];
    fn = elt(env, 7); /* atomf */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-2];
    if (!(v45 == nil)) goto v250;
    v45 = stack[-1];
    v46 = qcdr(v45);
    v45 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v45 = (*qfn2(fn))(qenv(fn), v46, v45);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-2];
    if (!(v45 == nil)) goto v129;
    v45 = stack[-1];
    v46 = qcar(v45);
    v45 = stack[0];
    v45 = CC_ndepends(env, v46, v45);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-2];
    if (!(v45 == nil)) goto v129;

v250:
    v45 = stack[0];
    fn = elt(env, 7); /* atomf */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-2];
    if (!(v45 == nil)) goto v255;
    v45 = stack[0];
    v45 = qcar(v45);
    if (!(symbolp(v45))) goto v241;
    v45 = stack[0];
    v46 = qcar(v45);
    v45 = elt(env, 5); /* dname */
    v45 = get(v46, v45);
    env = stack[-2];
    if (!(v45 == nil)) goto v255;

v241:
    v46 = stack[-1];
    v45 = stack[0];
    v45 = qcdr(v45);
    {
        popv(3);
        fn = elt(env, 8); /* ndependsl */
        return (*qfn2(fn))(qenv(fn), v46, v45);
    }

v255:
    v45 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v45); }

v129:
    v45 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v45); }

v73:
    v45 = qvalue(elt(env, 1)); /* nil */
    goto v121;

v10:
    v45 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v45); }
/* error exit handlers */
v204:
    popv(3);
    return nil;
}



/* Code for basisformp */

static Lisp_Object CC_basisformp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basisformp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v0;
/* end of prologue */
    v70 = v112;
    if (!consp(v70)) goto v14;
    v70 = v112;
    v112 = qvalue(elt(env, 2)); /* basisforml!* */
    v70 = Lmemq(nil, v70, v112);
    return onevalue(v70);

v14:
    v70 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v70);
}



/* Code for decimal2internal */

static Lisp_Object CC_decimal2internal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v140, v117;
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
    v140 = stack[0];
    v139 = (Lisp_Object)1; /* 0 */
    v139 = (Lisp_Object)geq2(v140, v139);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v139 = v139 ? lisp_true : nil;
    env = stack[-3];
    if (v139 == nil) goto v120;
    stack[-2] = elt(env, 1); /* !:rd!: */
    v140 = (Lisp_Object)161; /* 10 */
    v139 = stack[0];
    v139 = Lexpt(nil, v140, v139);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-3];
    v140 = times2(stack[-1], v139);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v139 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v118 = stack[-2];
        popv(4);
        return list2star(v118, v140, v139);
    }

v120:
    v117 = elt(env, 1); /* !:rd!: */
    v140 = stack[-1];
    v139 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v117, v140, v139);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-3];
    v139 = stack[0];
    v139 = negate(v139);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-3];
    {
        Lisp_Object v158 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* divide!-by!-power!-of!-ten */
        return (*qfn2(fn))(qenv(fn), v158, v139);
    }
/* error exit handlers */
v209:
    popv(4);
    return nil;
}



/* Code for physoppri */

static Lisp_Object CC_physoppri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v276, v277, v278, v279;
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
    v276 = stack[-8];
    if (symbolp(v276)) goto v151;
    v276 = stack[-8];
    v276 = qcar(v276);
    goto v156;

v156:
    stack[-9] = v276;
    v276 = stack[-8];
    if (symbolp(v276)) goto v106;
    v276 = stack[-8];
    v276 = qcdr(v276);
    goto v107;

v107:
    stack[-7] = v276;
    stack[-5] = elt(env, 0); /* physoppri */
    stack[-4] = elt(env, 2); /* "x= " */
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); /* " y= " */
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); /* "nat= " */
    v278 = elt(env, 5); /* !*nat */
    v277 = elt(env, 6); /* " contract= " */
    v276 = elt(env, 7); /* !*contract */
    v276 = list3(v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = list3star(stack[-2], stack[-1], stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = list3star(stack[-5], stack[-4], stack[-3], v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = qvalue(elt(env, 5)); /* !*nat */
    if (v276 == nil) goto v242;
    v276 = qvalue(elt(env, 7)); /* !*contract */
    if (!(v276 == nil)) goto v242;
    v276 = stack[-9];
    v276 = Lexplode(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lreverse(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[-9] = v276;
    v276 = stack[-9];
    v277 = Llength(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = (Lisp_Object)33; /* 2 */
    v276 = (Lisp_Object)greaterp2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    v276 = v276 ? lisp_true : nil;
    env = stack[-10];
    if (v276 == nil) goto v281;
    v276 = stack[-9];
    v276 = qcdr(v276);
    v277 = qcar(v276);
    v276 = elt(env, 14); /* !- */
    if (v277 == v276) goto v179;
    v276 = stack[-9];
    v277 = qcar(v276);
    v276 = elt(env, 16); /* !+ */
    if (v277 == v276) goto v215;
    v276 = stack[-9];
    v276 = Lreverse(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lcompress(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[-9] = v276;
    goto v282;

v282:
    stack[0] = elt(env, 8); /* !" */
    v276 = stack[-9];
    v276 = Lexplode(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[0] = cons(stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = elt(env, 8); /* !" */
    v276 = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lappend(nil, stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lcompress(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[-9] = v276;
    v276 = stack[-7];
    if (v276 == nil) goto v283;
    v277 = stack[-9];
    v276 = stack[-7];
    v276 = cons(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    goto v284;

v284:
    stack[-3] = v276;
    stack[-2] = elt(env, 0); /* physoppri */
    stack[-1] = elt(env, 2); /* "x= " */
    stack[0] = stack[-9];
    v279 = elt(env, 17); /* " z= " */
    v278 = stack[-6];
    v277 = elt(env, 18); /* " x1= " */
    v276 = stack[-3];
    v276 = list4(v279, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = list3star(stack[-2], stack[-1], stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = stack[-6];
    if (v276 == nil) goto v13;
    v278 = elt(env, 19); /* expt */
    v277 = stack[-3];
    v276 = stack[-6];
    v278 = list3(v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v277 = elt(env, 19); /* expt */
    v276 = elt(env, 20); /* infix */
    v276 = get(v277, v276);
    env = stack[-10];
    fn = elt(env, 22); /* exptpri */
    v276 = (*qfn2(fn))(qenv(fn), v278, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v13:
    v276 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = stack[-7];
    if (v276 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v276 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v276; /* obrkp!* */
    v278 = elt(env, 11); /* !*comma!* */
    v277 = (Lisp_Object)1; /* 0 */
    v276 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v276 = (*qfnn(fn))(qenv(fn), 3, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v276; /* obrkp!* */
    v276 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v283:
    v276 = stack[-9];
    goto v284;

v215:
    v276 = elt(env, 16); /* !+ */
    stack[-6] = v276;
    v277 = stack[-9];
    v276 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 25); /* pnth */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lreverse(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lcompress(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[-9] = v276;
    goto v282;

v179:
    v277 = elt(env, 14); /* !- */
    v276 = elt(env, 15); /* !1 */
    v276 = list2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lcompress(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[-6] = v276;
    v277 = stack[-9];
    v276 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 25); /* pnth */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lreverse(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lcompress(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[-9] = v276;
    goto v282;

v281:
    v276 = stack[-9];
    v276 = Lreverse(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lcompress(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[-9] = v276;
    goto v282;

v242:
    stack[0] = elt(env, 8); /* !" */
    v276 = stack[-9];
    v276 = Lexplode(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[0] = cons(stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = elt(env, 8); /* !" */
    v276 = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lappend(nil, stack[0], v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = Lcompress(nil, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    stack[-9] = v276;
    v276 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = stack[-7];
    if (v276 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v276 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v276; /* obrkp!* */
    v278 = elt(env, 11); /* !*comma!* */
    v277 = (Lisp_Object)1; /* 0 */
    v276 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v276 = (*qfnn(fn))(qenv(fn), 3, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-10];
    v276 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v276; /* obrkp!* */
    v276 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v106:
    v276 = qvalue(elt(env, 1)); /* nil */
    goto v107;

v151:
    v276 = stack[-8];
    goto v156;
/* error exit handlers */
v280:
    popv(11);
    return nil;
}



/* Code for prsum */

static Lisp_Object CC_prsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v120, v121;
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
    goto v25;

v25:
    v131 = stack[-1];
    if (v131 == nil) goto v149;
    v131 = stack[0];
    v131 = qcar(v131);
    if (v131 == nil) goto v162;
    v131 = stack[-1];
    v120 = qcar(v131);
    v131 = (Lisp_Object)17; /* 1 */
    v121 = cons(v120, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    v131 = stack[0];
    v120 = qcar(v131);
    v131 = stack[-2];
    v131 = acons(v121, v120, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-3];
    stack[-2] = v131;
    v131 = stack[-1];
    v131 = qcdr(v131);
    stack[-1] = v131;
    v131 = stack[0];
    v131 = qcdr(v131);
    stack[0] = v131;
    goto v25;

v162:
    v131 = stack[-1];
    v131 = qcdr(v131);
    stack[-1] = v131;
    v131 = stack[0];
    v131 = qcdr(v131);
    stack[0] = v131;
    goto v25;

v149:
    v131 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v131);
    }
/* error exit handlers */
v134:
    popv(4);
    return nil;
}



/* Code for fs!:onep!: */

static Lisp_Object CC_fsTonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:onep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v10 = qcdr(v10);
    {
        fn = elt(env, 1); /* fs!:onep */
        return (*qfn1(fn))(qenv(fn), v10);
    }
}



/* Code for simp!-prop */

static Lisp_Object CC_simpKprop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v290, v291, v292;
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
    v290 = stack[-2];
    v290 = qcdr(v290);
    stack[-4] = v290;
    v290 = stack[-4];
    if (v290 == nil) goto v146;
    v290 = stack[-4];
    v290 = qcar(v290);
    fn = elt(env, 14); /* reval */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v290 = ncons(v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    stack[-1] = v290;
    stack[-3] = v290;
    goto v152;

v152:
    v290 = stack[-4];
    v290 = qcdr(v290);
    stack[-4] = v290;
    v290 = stack[-4];
    if (v290 == nil) goto v97;
    stack[0] = stack[-1];
    v290 = stack[-4];
    v290 = qcar(v290);
    fn = elt(env, 14); /* reval */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v290 = ncons(v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v290 = Lrplacd(nil, stack[0], v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v290 = stack[-1];
    v290 = qcdr(v290);
    stack[-1] = v290;
    goto v152;

v97:
    v290 = stack[-3];
    goto v151;

v151:
    stack[-5] = v290;
    v291 = elt(env, 3); /* and */
    v290 = stack[-5];
    v290 = Lmember(nil, v291, v290);
    if (v290 == nil) goto v209;
    v290 = elt(env, 4); /* or */
    qvalue(elt(env, 5)) = v290; /* !'and */
    v290 = elt(env, 3); /* and */
    qvalue(elt(env, 6)) = v290; /* !'or */
    v290 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v290; /* !'true */
    v290 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 8)) = v290; /* !'false */
    goto v116;

v116:
    v290 = stack[-2];
    v291 = qcar(v290);
    v290 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v291 = (*qfn2(fn))(qenv(fn), v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v290 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* prepf1 */
    v290 = (*qfn2(fn))(qenv(fn), v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v291 = v290;
    v290 = v291;
    if (v290 == nil) goto v49;
    v290 = v291;
    fn = elt(env, 17); /* replus */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    goto v50;

v50:
    fn = elt(env, 14); /* reval */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v292 = v290;
    v291 = v292;
    v290 = (Lisp_Object)1; /* 0 */
    if (v291 == v290) goto v114;
    v290 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-4] = v290;
    goto v293;

v293:
    v290 = stack[-4];
    if (v290 == nil) goto v294;
    v290 = stack[-4];
    v290 = qcar(v290);
    stack[-3] = elt(env, 10); /* times */
    stack[-2] = v292;
    stack[-1] = qvalue(elt(env, 6)); /* !'or */
    stack[0] = v290;
    v291 = elt(env, 11); /* not */
    v290 = list2(v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v291 = list3(stack[-1], stack[0], v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v290 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v291 = (*qfn2(fn))(qenv(fn), v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v290 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 16); /* prepf1 */
    v290 = (*qfn2(fn))(qenv(fn), v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v291 = v290;
    v290 = v291;
    if (v290 == nil) goto v200;
    v290 = v291;
    fn = elt(env, 17); /* replus */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    goto v47;

v47:
    v290 = list3(stack[-3], stack[-2], v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    fn = elt(env, 14); /* reval */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v292 = v290;
    v290 = stack[-4];
    v290 = qcdr(v290);
    stack[-4] = v290;
    goto v293;

v200:
    v290 = (Lisp_Object)1; /* 0 */
    goto v47;

v294:
    v290 = v292;
    fn = elt(env, 18); /* simp!-prop!-dist */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v292 = v290;
    v291 = elt(env, 12); /* full */
    v290 = stack[-5];
    v290 = Lmember(nil, v291, v290);
    if (!(v290 == nil)) goto v239;
    v290 = v292;
    fn = elt(env, 19); /* simp!-prop2 */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v292 = v290;
    goto v239;

v239:
    v290 = v292;
    fn = elt(env, 20); /* simp!-prop!-form */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v292 = v290;
    v290 = v292;
    if (is_number(v290)) goto v198;
    v290 = v292;
    if (!consp(v290)) goto v189;
    v290 = elt(env, 13); /* boolean */
    v291 = v292;
    v290 = list2(v290, v291);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v292 = v290;
    goto v189;

v189:
    v291 = (Lisp_Object)17; /* 1 */
    v290 = (Lisp_Object)17; /* 1 */
    v292 = acons(v292, v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    v291 = qvalue(elt(env, 2)); /* nil */
    v290 = (Lisp_Object)17; /* 1 */
    v290 = acons(v292, v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    goto v25;

v25:
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    { popv(8); return onevalue(v290); }

v198:
    v291 = v292;
    v290 = (Lisp_Object)17; /* 1 */
    v290 = cons(v291, v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    goto v25;

v114:
    v290 = qvalue(elt(env, 8)); /* !'false */
    fn = elt(env, 21); /* simp */
    v290 = (*qfn1(fn))(qenv(fn), v290);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-7];
    goto v25;

v49:
    v290 = (Lisp_Object)1; /* 0 */
    goto v50;

v209:
    v290 = elt(env, 3); /* and */
    qvalue(elt(env, 5)) = v290; /* !'and */
    v290 = elt(env, 4); /* or */
    qvalue(elt(env, 6)) = v290; /* !'or */
    v290 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v290; /* !'true */
    v290 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 8)) = v290; /* !'false */
    goto v116;

v146:
    v290 = qvalue(elt(env, 2)); /* nil */
    goto v151;
/* error exit handlers */
v221:
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
    Lisp_Object v101;
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
    v101 = stack[0];
    fn = elt(env, 1); /* vecp */
    v101 = (*qfn1(fn))(qenv(fn), v101);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-1];
    if (v101 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* vecsm!* */
        return (*qfn1(fn))(qenv(fn), v101);
    }
/* error exit handlers */
v150:
    popv(2);
    return nil;
}



/* Code for nodum_varp */

static Lisp_Object CC_nodum_varp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v73;
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
    v121 = stack[0];
    fn = elt(env, 7); /* listp */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-1];
    if (v121 == nil) goto v101;
    v121 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v121); }

v101:
    v73 = stack[0];
    v121 = elt(env, 2); /* dummy */
    v121 = Lflagp(nil, v73, v121);
    env = stack[-1];
    if (!(v121 == nil)) goto v149;
    v121 = stack[0];
    fn = elt(env, 8); /* ad_splitname */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-1];
    v73 = qcar(v121);
    v121 = qvalue(elt(env, 3)); /* g_dvbase */
    if (equal(v73, v121)) goto v149;
    v73 = elt(env, 4); /* !~dv */
    v121 = elt(env, 5); /* !~dva */
    v121 = list2(v73, v121);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-1];
    v121 = Lmember(nil, stack[0], v121);
    if (!(v121 == nil)) goto v149;
    v121 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v121); }

v149:
    v121 = qvalue(elt(env, 6)); /* nil */
    { popv(2); return onevalue(v121); }
/* error exit handlers */
v133:
    popv(2);
    return nil;
}



/* Code for cl_atmlc */

static Lisp_Object CC_cl_atmlc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v152;
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
    v151 = v0;
/* end of prologue */
    v152 = v151;
    v151 = (Lisp_Object)17; /* 1 */
    v151 = cons(v152, v151);
    errexit();
    return ncons(v151);
}



/* Code for color0 */

static Lisp_Object CC_color0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v73;
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
    v121 = stack[-2];
    fn = elt(env, 3); /* chkcg */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    if (v121 == nil) goto v132;
    v121 = stack[-2];
    fn = elt(env, 4); /* afactor */
    stack[-3] = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)17; /* 1 */
    v121 = stack[-2];
    fn = elt(env, 5); /* mkcopy */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[-1] = acons(stack[-1], stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v73 = qvalue(elt(env, 1)); /* nil */
    v121 = (Lisp_Object)17; /* 1 */
    v121 = cons(v73, v121);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    fn = elt(env, 6); /* color1 */
    v121 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    {
        Lisp_Object v232 = stack[-3];
        popv(5);
        fn = elt(env, 7); /* multsq */
        return (*qfn2(fn))(qenv(fn), v232, v121);
    }

v132:
    v121 = elt(env, 2); /* "This is impossible!" */
    v121 = ncons(v121);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* cerror */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v148:
    popv(5);
    return nil;
}



/* Code for cl_strict!-gdnf */

static Lisp_Object CC_cl_strictKgdnf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96, v103;
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
    v95 = v0;
/* end of prologue */
    v96 = v95;
    v95 = stack[0];
    fn = elt(env, 2); /* cl_strict!-gdnf1 */
    v103 = (*qfn2(fn))(qenv(fn), v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    v96 = qvalue(elt(env, 1)); /* nil */
    v95 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 3); /* rl_simpl */
    v96 = (*qfnn(fn))(qenv(fn), 3, v103, v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    v95 = stack[0];
    fn = elt(env, 4); /* cl_mkstrict */
    v95 = (*qfn2(fn))(qenv(fn), v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-1];
    v96 = v95;
    v95 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* rl_bnfsimpl */
        return (*qfn2(fn))(qenv(fn), v96, v95);
    }
/* error exit handlers */
v71:
    popv(2);
    return nil;
}



/* Code for expand!-imrepart */

static Lisp_Object CC_expandKimrepart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v209;
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
    goto v25;

v25:
    v157 = stack[-1];
    if (!consp(v157)) goto v104;
    v157 = stack[-1];
    v157 = qcar(v157);
    if (!consp(v157)) goto v104;
    v157 = stack[-1];
    v157 = qcar(v157);
    v157 = qcar(v157);
    fn = elt(env, 1); /* expand!-imrepartpow */
    stack[0] = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    v157 = stack[-1];
    v157 = qcar(v157);
    v157 = qcdr(v157);
    v157 = CC_expandKimrepart(env, v157);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    fn = elt(env, 2); /* multsq */
    v209 = (*qfn2(fn))(qenv(fn), stack[0], v157);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    v157 = stack[-2];
    v157 = cons(v209, v157);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    stack[-2] = v157;
    v157 = stack[-1];
    v157 = qcdr(v157);
    stack[-1] = v157;
    goto v25;

v104:
    v209 = stack[-1];
    v157 = (Lisp_Object)17; /* 1 */
    v157 = cons(v209, v157);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    v209 = v157;
    goto v135;

v135:
    v157 = stack[-2];
    if (v157 == nil) { popv(4); return onevalue(v209); }
    v157 = stack[-2];
    v157 = qcar(v157);
    fn = elt(env, 3); /* addsq */
    v157 = (*qfn2(fn))(qenv(fn), v157, v209);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    v209 = v157;
    v157 = stack[-2];
    v157 = qcdr(v157);
    stack[-2] = v157;
    goto v135;
/* error exit handlers */
v138:
    popv(4);
    return nil;
}



/* Code for groebspolynom3 */

static Lisp_Object CC_groebspolynom3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v70;
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
    v146 = v1;
    v70 = v0;
/* end of prologue */
    fn = elt(env, 1); /* groebspolynom4 */
    v146 = (*qfn2(fn))(qenv(fn), v70, v146);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-1];
    stack[0] = v146;
    v146 = stack[0];
    fn = elt(env, 2); /* groebsavelterm */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v107;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v107:
    popv(2);
    return nil;
}



/* Code for wedgewedge */

static Lisp_Object CC_wedgewedge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v54, v256;
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
    goto v41;

v41:
    v128 = stack[-1];
    v128 = qcdr(v128);
    if (v128 == nil) goto v131;
    v128 = stack[-1];
    v256 = qcar(v128);
    v54 = (Lisp_Object)17; /* 1 */
    v128 = (Lisp_Object)17; /* 1 */
    v256 = list2star(v256, v54, v128);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v54 = qvalue(elt(env, 1)); /* nil */
    v128 = stack[-2];
    v128 = acons(v256, v54, v128);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    stack[-2] = v128;
    v128 = stack[-1];
    v128 = qcdr(v128);
    stack[-1] = v128;
    goto v41;

v131:
    v128 = stack[-1];
    v256 = qcar(v128);
    v54 = (Lisp_Object)17; /* 1 */
    v128 = (Lisp_Object)17; /* 1 */
    v128 = list2star(v256, v54, v128);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    stack[-1] = ncons(v128);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v256 = stack[0];
    v54 = (Lisp_Object)17; /* 1 */
    v128 = (Lisp_Object)17; /* 1 */
    v128 = list2star(v256, v54, v128);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v128 = ncons(v128);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    fn = elt(env, 2); /* wedgepf2 */
    v128 = (*qfn2(fn))(qenv(fn), stack[-1], v128);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v54 = v128;
    goto v149;

v149:
    v128 = stack[-2];
    if (v128 == nil) { popv(4); return onevalue(v54); }
    v128 = stack[-2];
    v128 = qcar(v128);
    fn = elt(env, 2); /* wedgepf2 */
    v128 = (*qfn2(fn))(qenv(fn), v128, v54);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v54 = v128;
    v128 = stack[-2];
    v128 = qcdr(v128);
    stack[-2] = v128;
    goto v149;
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for deflate1 */

static Lisp_Object CC_deflate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v246, v207;
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
    v255 = v0;
/* end of prologue */
    stack[-7] = nil;
    fn = elt(env, 3); /* ncoeffs */
    v246 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-8];
    v255 = v246;
    v246 = qcar(v246);
    stack[-5] = v246;
    v255 = qcdr(v255);
    v246 = v255;
    v246 = qcar(v246);
    stack[-4] = v246;
    v255 = qcdr(v255);
    stack[-3] = v255;
    goto v70;

v70:
    v255 = stack[-3];
    if (v255 == nil) goto v159;
    v255 = stack[-3];
    v255 = qcar(v255);
    stack[-2] = v255;
    v255 = stack[-5];
    v255 = sub1(v255);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-8];
    stack[-5] = v255;
    v255 = stack[-4];
    v255 = qcdr(v255);
    v246 = qcar(v255);
    v255 = (Lisp_Object)1; /* 0 */
    if (v246 == v255) goto v232;
    v207 = stack[-5];
    v246 = stack[-4];
    v255 = stack[-7];
    v255 = acons(v207, v246, v255);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-8];
    stack[-7] = v255;
    goto v232;

v232:
    stack[-1] = elt(env, 2); /* !:rd!: */
    v255 = stack[-6];
    v255 = qcdr(v255);
    v246 = qcar(v255);
    v255 = stack[-4];
    v255 = qcdr(v255);
    v255 = qcar(v255);
    stack[0] = times2(v246, v255);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-8];
    v255 = stack[-6];
    v255 = qcdr(v255);
    v246 = qcdr(v255);
    v255 = stack[-4];
    v255 = qcdr(v255);
    v255 = qcdr(v255);
    v255 = plus2(v246, v255);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-8];
    v255 = list2star(stack[-1], stack[0], v255);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-8];
    stack[-4] = v255;
    v255 = stack[-2];
    if (v255 == nil) goto v256;
    v246 = stack[-2];
    v255 = stack[-4];
    fn = elt(env, 4); /* plus!: */
    v255 = (*qfn2(fn))(qenv(fn), v246, v255);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-8];
    stack[-4] = v255;
    goto v256;

v256:
    v255 = stack[-3];
    v255 = qcdr(v255);
    stack[-3] = v255;
    goto v70;

v159:
    v246 = stack[-4];
    v255 = stack[-7];
    popv(9);
    return cons(v246, v255);
/* error exit handlers */
v124:
    popv(9);
    return nil;
}



/* Code for mkforttab */

static Lisp_Object MS_CDECL CC_mkforttab(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v146;
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
    v146 = qvalue(elt(env, 2)); /* fortcurrind!* */
    v102 = (Lisp_Object)97; /* 6 */
    v102 = plus2(v146, v102);
    nil = C_nil;
    if (exception_pending()) goto v112;
    {
        Lisp_Object v107 = stack[0];
        popv(1);
        return list2(v107, v102);
    }
/* error exit handlers */
v112:
    popv(1);
    return nil;
}



setup_type const u34_setup[] =
{
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
    {NULL, (one_args *)"u34", (two_args *)"16222 4708733 4560351", 0}
};

/* end of generated code */
