
/* $destdir\u52.c        Machine generated C code */

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


/* Code for quotfx1 */

static Lisp_Object CC_quotfx1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfx1");
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
/* copy arguments values to proper place */
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */
    v70 = stack[-8];
    if (v70 == nil) goto v73;
    v71 = stack[-8];
    v70 = stack[-7];
    if (equal(v71, v70)) goto v74;
    v71 = stack[-7];
    v70 = (Lisp_Object)17; /* 1 */
    if (v71 == v70) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v70 = stack[-7];
    if (!consp(v70)) goto v75;
    v70 = stack[-7];
    v70 = qcar(v70);
    if (!consp(v70)) goto v75;
    v70 = stack[-8];
    if (!consp(v70)) goto v76;
    v70 = stack[-8];
    v70 = qcar(v70);
    if (!consp(v70)) goto v76;
    v70 = stack[-8];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v71 = qcar(v70);
    v70 = stack[-7];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcar(v70);
    if (v71 == v70) goto v77;
    v70 = stack[-8];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v71 = qcar(v70);
    v70 = stack[-7];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcar(v70);
    fn = elt(env, 4); /* ordop */
    v70 = (*qfn2(fn))(qenv(fn), v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    if (v70 == nil) goto v79;
    v71 = stack[-8];
    v70 = stack[-7];
    {
        popv(11);
        fn = elt(env, 5); /* quotkx */
        return (*qfn2(fn))(qenv(fn), v71, v70);
    }

v79:
    v70 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v70 == nil)) goto v80;
    v70 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 6); /* lprie */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    goto v80;

v80:
    v70 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v70 = nil;
    { popv(11); return onevalue(v70); }

v77:
    stack[-9] = nil;
    stack[-1] = nil;
    v70 = stack[-7];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcdr(v70);
    stack[-5] = v70;
    goto v81;

v81:
    v70 = stack[-8];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v71 = qcdr(v70);
    stack[-6] = v71;
    v70 = stack[-5];
    v70 = (Lisp_Object)lessp2(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v70 = v70 ? lisp_true : nil;
    env = stack[-10];
    if (v70 == nil) goto v82;
    v70 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v70 == nil)) goto v83;
    v70 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 6); /* lprie */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    goto v83;

v83:
    v70 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v70 = nil;
    { popv(11); return onevalue(v70); }

v82:
    v70 = stack[-8];
    fn = elt(env, 7); /* lt!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    stack[0] = v70;
    v70 = stack[-7];
    fn = elt(env, 7); /* lt!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    v71 = stack[-7];
    v71 = qcar(v71);
    v71 = qcar(v71);
    v71 = qcar(v71);
    stack[-4] = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    v70 = qcdr(v70);
    v70 = CC_quotfx1(env, v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    stack[-3] = v70;
    v71 = stack[-6];
    v70 = stack[-5];
    v70 = (Lisp_Object)(int32_t)((int32_t)v71 - (int32_t)v70 + TAG_FIXNUM);
    stack[0] = v70;
    v71 = stack[0];
    v70 = (Lisp_Object)1; /* 0 */
    if (v71 == v70) goto v84;
    v71 = stack[-4];
    v70 = stack[0];
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    stack[-2] = v70;
    v70 = stack[-9];
    if (!(v70 == nil)) goto v85;
    v71 = stack[-6];
    v70 = stack[0];
    v70 = (Lisp_Object)(int32_t)((int32_t)v71 - (int32_t)v70 + TAG_FIXNUM);
    v70 = (Lisp_Object)((int32_t)(v70) - 0x10);
    v72 = v70;
    v71 = (Lisp_Object)17; /* 1 */
    if (((int32_t)(v72)) < ((int32_t)(v71))) goto v86;
    v72 = stack[-8];
    v71 = stack[-4];
    fn = elt(env, 8); /* cutf1 */
    v70 = (*qfnn(fn))(qenv(fn), 3, v72, v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    goto v87;

v87:
    stack[-8] = v70;
    goto v85;

v85:
    v70 = qvalue(elt(env, 3)); /* t */
    stack[-9] = v70;
    v71 = stack[-5];
    v70 = stack[0];
    v70 = (Lisp_Object)(int32_t)((int32_t)v71 - (int32_t)v70 + TAG_FIXNUM);
    v70 = (Lisp_Object)((int32_t)(v70) - 0x10);
    v72 = v70;
    v71 = (Lisp_Object)17; /* 1 */
    if (((int32_t)(v72)) < ((int32_t)(v71))) goto v88;
    v72 = stack[-7];
    v71 = stack[-4];
    fn = elt(env, 8); /* cutf1 */
    v70 = (*qfnn(fn))(qenv(fn), 3, v72, v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    goto v89;

v89:
    stack[-7] = v70;
    stack[-6] = stack[-8];
    v71 = stack[0];
    v70 = (Lisp_Object)1; /* 0 */
    if (v71 == v70) goto v90;
    v71 = stack[-2];
    v70 = (Lisp_Object)17; /* 1 */
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    v71 = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    v70 = stack[-7];
    fn = elt(env, 9); /* multf */
    v70 = (*qfn2(fn))(qenv(fn), v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    stack[0] = v70;
    goto v91;

v91:
    v70 = stack[-3];
    fn = elt(env, 10); /* negf */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    fn = elt(env, 9); /* multf */
    v70 = (*qfn2(fn))(qenv(fn), stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    fn = elt(env, 11); /* addf */
    v70 = (*qfn2(fn))(qenv(fn), stack[-6], v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    stack[-8] = v70;
    v70 = stack[-8];
    if (v70 == nil) goto v92;
    v70 = stack[-8];
    if (!consp(v70)) goto v93;
    v70 = stack[-8];
    v70 = qcar(v70);
    if (!consp(v70)) goto v93;
    v70 = stack[-8];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v71 = qcar(v70);
    v70 = stack[-4];
    if (!(v71 == v70)) goto v93;

v92:
    stack[0] = stack[-1];
    v71 = stack[-2];
    v70 = stack[-3];
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    v70 = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    v70 = Lnconc(nil, stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    stack[-1] = v70;
    v70 = stack[-8];
    if (v70 == nil) { Lisp_Object res = stack[-1]; popv(11); return onevalue(res); }
    else goto v81;

v93:
    v70 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v70 == nil)) goto v94;
    v70 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 6); /* lprie */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    goto v94;

v94:
    v70 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v70 = nil;
    { popv(11); return onevalue(v70); }

v90:
    v70 = stack[-7];
    stack[0] = v70;
    goto v91;

v88:
    v70 = stack[-7];
    goto v89;

v86:
    v70 = stack[-8];
    goto v87;

v84:
    v71 = stack[-1];
    v70 = stack[-3];
    {
        popv(11);
        fn = elt(env, 12); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v71, v70);
    }

v76:
    v70 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v70 == nil)) goto v95;
    v70 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 6); /* lprie */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    goto v95;

v95:
    v70 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v70 = nil;
    { popv(11); return onevalue(v70); }

v75:
    v71 = stack[-8];
    v70 = stack[-7];
    {
        popv(11);
        fn = elt(env, 13); /* quotfdx */
        return (*qfn2(fn))(qenv(fn), v71, v70);
    }

v74:
    v70 = (Lisp_Object)17; /* 1 */
    { popv(11); return onevalue(v70); }

v73:
    v70 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v70 == nil)) goto v96;
    v70 = elt(env, 2); /* "exact division failed" */
    fn = elt(env, 6); /* lprie */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-10];
    goto v96;

v96:
    v70 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    v70 = nil;
    { popv(11); return onevalue(v70); }
/* error exit handlers */
v78:
    popv(11);
    return nil;
}



/* Code for ps!:plus!-erule */

static Lisp_Object CC_psTplusKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:plus-erule");
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
    stack[-1] = v1;
    stack[0] = v0;
/* end of prologue */
    v105 = qvalue(elt(env, 1)); /* nil */
    v104 = (Lisp_Object)17; /* 1 */
    v104 = cons(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v105 = v104;
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[-2] = v104;
    goto v106;

v106:
    v104 = stack[-2];
    if (v104 == nil) { popv(4); return onevalue(v105); }
    v104 = stack[-2];
    v104 = qcar(v104);
    stack[0] = v105;
    v105 = v104;
    v104 = stack[-1];
    fn = elt(env, 2); /* ps!:evaluate */
    v104 = (*qfn2(fn))(qenv(fn), v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    fn = elt(env, 3); /* addsq */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v105 = v104;
    v104 = stack[-2];
    v104 = qcdr(v104);
    stack[-2] = v104;
    goto v106;
/* error exit handlers */
v65:
    popv(4);
    return nil;
}



/* Code for arprep!: */

static Lisp_Object CC_arprepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arprep:");
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
    v111 = v0;
/* end of prologue */
    v110 = qvalue(elt(env, 1)); /* !*reexpress */
    if (v110 == nil) goto v112;
    v110 = v111;
    v110 = qcdr(v110);
    fn = elt(env, 3); /* express!-in!-arvars */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    v111 = v110;
    goto v73;

v73:
    v110 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* prepf1 */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[0];
    v111 = v110;
    v110 = v111;
    if (v110 == nil) goto v114;
    v110 = v111;
    {
        popv(1);
        fn = elt(env, 5); /* replus */
        return (*qfn1(fn))(qenv(fn), v110);
    }

v114:
    v110 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v110); }

v112:
    v110 = v111;
    v110 = qcdr(v110);
    v111 = v110;
    goto v73;
/* error exit handlers */
v113:
    popv(1);
    return nil;
}



/* Code for fast_augment_columns */

static Lisp_Object CC_fast_augment_columns(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fast_augment_columns");
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
    stack[-9] = v1;
    stack[-3] = v0;
/* end of prologue */
    v148 = stack[-9];
    if (!consp(v148)) goto v151;
    stack[-10] = elt(env, 1); /* mat */
    v148 = stack[-3];
    v148 = qcdr(v148);
    stack[-8] = v148;
    v148 = stack[-8];
    if (v148 == nil) goto v81;
    v148 = stack[-8];
    v148 = qcar(v148);
    stack[-4] = v148;
    v148 = stack[-9];
    stack[-3] = v148;
    v148 = stack[-3];
    if (v148 == nil) goto v152;
    v148 = stack[-3];
    v148 = qcar(v148);
    v149 = stack[-4];
    fn = elt(env, 3); /* pnth */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = qcar(v148);
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    stack[-1] = v148;
    stack[-2] = v148;
    goto v83;

v83:
    v148 = stack[-3];
    v148 = qcdr(v148);
    stack[-3] = v148;
    v148 = stack[-3];
    if (v148 == nil) goto v153;
    stack[0] = stack[-1];
    v148 = stack[-3];
    v148 = qcar(v148);
    v149 = stack[-4];
    fn = elt(env, 3); /* pnth */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = qcar(v148);
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = Lrplacd(nil, stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v83;

v153:
    v148 = stack[-2];
    goto v154;

v154:
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    stack[-6] = v148;
    stack[-7] = v148;
    goto v155;

v155:
    v148 = stack[-8];
    v148 = qcdr(v148);
    stack[-8] = v148;
    v148 = stack[-8];
    if (v148 == nil) goto v156;
    stack[-5] = stack[-6];
    v148 = stack[-8];
    v148 = qcar(v148);
    stack[-4] = v148;
    v148 = stack[-9];
    stack[-3] = v148;
    v148 = stack[-3];
    if (v148 == nil) goto v157;
    v148 = stack[-3];
    v148 = qcar(v148);
    v149 = stack[-4];
    fn = elt(env, 3); /* pnth */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = qcar(v148);
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    stack[-1] = v148;
    stack[-2] = v148;
    goto v37;

v37:
    v148 = stack[-3];
    v148 = qcdr(v148);
    stack[-3] = v148;
    v148 = stack[-3];
    if (v148 == nil) goto v158;
    stack[0] = stack[-1];
    v148 = stack[-3];
    v148 = qcar(v148);
    v149 = stack[-4];
    fn = elt(env, 3); /* pnth */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = qcar(v148);
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = Lrplacd(nil, stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v37;

v158:
    v148 = stack[-2];
    goto v41;

v41:
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = Lrplacd(nil, stack[-5], v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = stack[-6];
    v148 = qcdr(v148);
    stack[-6] = v148;
    goto v155;

v157:
    v148 = qvalue(elt(env, 2)); /* nil */
    goto v41;

v156:
    v148 = stack[-7];
    goto v159;

v159:
    {
        Lisp_Object v17 = stack[-10];
        popv(12);
        return cons(v17, v148);
    }

v152:
    v148 = qvalue(elt(env, 2)); /* nil */
    goto v154;

v81:
    v148 = qvalue(elt(env, 2)); /* nil */
    goto v159;

v151:
    stack[-5] = elt(env, 1); /* mat */
    v148 = (Lisp_Object)17; /* 1 */
    stack[-4] = v148;
    v148 = stack[-3];
    v148 = Llength(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v149 = (Lisp_Object)((int32_t)(v148) - 0x10);
    v148 = stack[-4];
    v148 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = Lminusp(nil, v148);
    env = stack[-11];
    if (v148 == nil) goto v97;
    v148 = qvalue(elt(env, 2)); /* nil */
    goto v102;

v102:
    {
        Lisp_Object v160 = stack[-5];
        popv(12);
        return cons(v160, v148);
    }

v97:
    v150 = stack[-3];
    v149 = stack[-4];
    v148 = stack[-9];
    v148 = list3(v150, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    fn = elt(env, 4); /* fast_unchecked_getmatelem */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    stack[-1] = v148;
    stack[-2] = v148;
    goto v109;

v109:
    v148 = stack[-4];
    v148 = add1(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    stack[-4] = v148;
    v148 = stack[-3];
    v148 = Llength(nil, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v149 = (Lisp_Object)((int32_t)(v148) - 0x10);
    v148 = stack[-4];
    v148 = difference2(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = Lminusp(nil, v148);
    env = stack[-11];
    if (v148 == nil) goto v161;
    v148 = stack[-2];
    goto v102;

v161:
    stack[0] = stack[-1];
    v150 = stack[-3];
    v149 = stack[-4];
    v148 = stack[-9];
    v148 = list3(v150, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    fn = elt(env, 4); /* fast_unchecked_getmatelem */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = Lrplacd(nil, stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-11];
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v109;
/* error exit handlers */
v16:
    popv(12);
    return nil;
}



/* Code for mkuniquewedge1 */

static Lisp_Object CC_mkuniquewedge1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuniquewedge1");
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
    v163 = stack[0];
    v163 = qcdr(v163);
    if (v163 == nil) goto v165;
    v163 = qvalue(elt(env, 1)); /* wedgemtch!* */
    if (v163 == nil) goto v166;
    v163 = stack[0];
    fn = elt(env, 3); /* wedgemtch */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-1];
    v164 = v163;
    if (v163 == nil) goto v166;
    v163 = v164;
    {
        popv(2);
        fn = elt(env, 4); /* partitop */
        return (*qfn1(fn))(qenv(fn), v163);
    }

v166:
    v164 = elt(env, 2); /* wedge */
    v163 = stack[0];
    v163 = cons(v164, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 5); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v163);
    }

v165:
    v163 = stack[0];
    v163 = qcar(v163);
    {
        popv(2);
        fn = elt(env, 5); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v163);
    }
/* error exit handlers */
v167:
    popv(2);
    return nil;
}



/* Code for deflate1c */

static Lisp_Object CC_deflate1c(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v130, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deflate1c");
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
    v137 = v0;
/* end of prologue */
    stack[-5] = nil;
    fn = elt(env, 3); /* ncoeffs */
    v130 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-6];
    v137 = v130;
    v130 = qcar(v130);
    stack[-3] = v130;
    v137 = qcdr(v137);
    v130 = v137;
    v130 = qcar(v130);
    stack[-2] = v130;
    v137 = qcdr(v137);
    stack[-1] = v137;
    goto v74;

v74:
    v137 = stack[-1];
    if (v137 == nil) goto v177;
    v137 = stack[-1];
    v137 = qcar(v137);
    stack[0] = v137;
    v137 = stack[-3];
    v137 = sub1(v137);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-6];
    stack[-3] = v137;
    v137 = stack[-2];
    v137 = qcar(v137);
    if (!consp(v137)) goto v178;
    v137 = stack[-2];
    v137 = qcar(v137);
    v137 = qcdr(v137);
    v130 = qcar(v137);
    v137 = (Lisp_Object)1; /* 0 */
    if (v130 == v137) goto v179;
    v137 = qvalue(elt(env, 1)); /* nil */
    goto v162;

v162:
    if (!(v137 == nil)) goto v11;
    v154 = stack[-3];
    v130 = stack[-2];
    v137 = stack[-5];
    v137 = acons(v154, v130, v137);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-6];
    stack[-5] = v137;
    goto v11;

v11:
    v130 = stack[-4];
    v137 = stack[-2];
    fn = elt(env, 4); /* gftimesn */
    v137 = (*qfn2(fn))(qenv(fn), v130, v137);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-6];
    stack[-2] = v137;
    v137 = stack[0];
    if (v137 == nil) goto v180;
    v130 = stack[-2];
    v137 = stack[0];
    fn = elt(env, 5); /* gfplusn */
    v137 = (*qfn2(fn))(qenv(fn), v130, v137);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-6];
    stack[-2] = v137;
    goto v180;

v180:
    v137 = stack[-1];
    v137 = qcdr(v137);
    stack[-1] = v137;
    goto v74;

v179:
    v137 = stack[-2];
    v137 = qcdr(v137);
    v137 = qcdr(v137);
    v130 = qcar(v137);
    v137 = (Lisp_Object)1; /* 0 */
    v137 = (v130 == v137 ? lisp_true : nil);
    goto v162;

v178:
    v130 = stack[-2];
    v137 = elt(env, 2); /* (0.0 . 0.0) */
    v137 = (equal(v130, v137) ? lisp_true : nil);
    goto v162;

v177:
    v130 = stack[-2];
    v137 = stack[-5];
    popv(7);
    return cons(v130, v137);
/* error exit handlers */
v176:
    popv(7);
    return nil;
}



/* Code for sin!: */

static Lisp_Object CC_sinT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v349, v350, v351;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sin:");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-12] = v1;
    stack[-2] = v0;
/* end of prologue */
    v349 = stack[-12];
    v349 = integerp(v349);
    if (v349 == nil) goto v109;
    v350 = stack[-12];
    v349 = (Lisp_Object)1; /* 0 */
    v349 = (Lisp_Object)lesseq2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    v349 = v349 ? lisp_true : nil;
    env = stack[-15];
    if (!(v349 == nil)) goto v109;
    v349 = stack[-2];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = (Lisp_Object)1; /* 0 */
    if (v350 == v349) goto v113;
    v350 = stack[-2];
    v349 = elt(env, 3); /* !:rd!: */
    if (!consp(v350)) goto v81;
    v350 = qcar(v350);
    if (!(v350 == v349)) goto v81;
    v349 = stack[-2];
    v349 = qcdr(v349);
    if (!consp(v349)) goto v81;
    v349 = stack[-2];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = (Lisp_Object)1; /* 0 */
    v349 = (Lisp_Object)lessp2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    v349 = v349 ? lisp_true : nil;
    env = stack[-15];
    if (v349 == nil) goto v81;
    stack[0] = elt(env, 3); /* !:rd!: */
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v350 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-15];
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v350 = list2star(stack[0], v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-15];
    v349 = stack[-12];
    v349 = CC_sinT(env, v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-15];
    stack[-1] = v349;
    stack[0] = elt(env, 3); /* !:rd!: */
    v349 = stack[-1];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v350 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    v349 = stack[-1];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    {
        Lisp_Object v353 = stack[0];
        popv(16);
        return list2star(v353, v350, v349);
    }

v81:
    stack[-7] = qvalue(elt(env, 4)); /* !!scls */
    qvalue(elt(env, 4)) = nil; /* !!scls */
    v350 = stack[-12];
    v349 = (Lisp_Object)113; /* 7 */
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-13] = v349;
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v349 = Labsval(nil, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 9); /* msd */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-11] = v349;
    v350 = stack[-13];
    v349 = stack[-11];
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 10); /* !:pi */
    v350 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = qvalue(elt(env, 5)); /* !:bf!-0!.25 */
    stack[-4] = v350;
    stack[-3] = v349;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v349 = stack[-4];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    stack[0] = times2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-4];
    v349 = qcdr(v349);
    v350 = qcdr(v349);
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-3] = v349;
    v350 = stack[-3];
    v349 = stack[-2];
    fn = elt(env, 11); /* greaterp!: */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    if (v349 == nil) goto v355;
    v349 = (Lisp_Object)1; /* 0 */
    stack[-11] = v349;
    v349 = stack[-2];
    stack[-9] = v349;
    goto v356;

v356:
    v349 = qvalue(elt(env, 6)); /* bfone!* */
    stack[-10] = v349;
    v350 = stack[-11];
    v349 = (Lisp_Object)129; /* 8 */
    v349 = (Lisp_Object)geq2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    v349 = v349 ? lisp_true : nil;
    env = stack[-15];
    if (v349 == nil) goto v357;
    v350 = stack[-11];
    v349 = (Lisp_Object)129; /* 8 */
    v349 = Cremainder(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-11] = v349;
    goto v357;

v357:
    v350 = stack[-11];
    v349 = (Lisp_Object)65; /* 4 */
    v349 = (Lisp_Object)geq2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    v349 = v349 ? lisp_true : nil;
    env = stack[-15];
    if (v349 == nil) goto v358;
    stack[0] = elt(env, 3); /* !:rd!: */
    v349 = stack[-10];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v350 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-10];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = list2star(stack[0], v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-10] = v349;
    v350 = stack[-11];
    v349 = (Lisp_Object)65; /* 4 */
    v349 = difference2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-11] = v349;
    goto v358;

v358:
    v350 = stack[-11];
    v349 = (Lisp_Object)1; /* 0 */
    if (v350 == v349) goto v359;
    v349 = stack[-11];
    v349 = Lonep(nil, v349);
    env = stack[-15];
    if (v349 == nil) goto v360;
    v350 = stack[-3];
    v349 = stack[-9];
    fn = elt(env, 12); /* difference!: */
    v350 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-13];
    fn = elt(env, 13); /* cut!:mt */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-9] = v349;
    v350 = stack[-9];
    v349 = stack[-12];
    fn = elt(env, 14); /* cos!: */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-2] = v349;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v349 = stack[-10];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    stack[0] = times2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-10];
    v349 = qcdr(v349);
    v350 = qcdr(v349);
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    goto v130;

v130:
    qvalue(elt(env, 4)) = stack[-7]; /* !!scls */
    { popv(16); return onevalue(v349); }

v360:
    v350 = stack[-11];
    v349 = (Lisp_Object)33; /* 2 */
    if (v350 == v349) goto v361;
    v350 = stack[-3];
    v349 = stack[-9];
    fn = elt(env, 12); /* difference!: */
    v350 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-13];
    fn = elt(env, 13); /* cut!:mt */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-9] = v349;
    v349 = stack[-2];
    qvalue(elt(env, 4)) = v349; /* !!scls */
    goto v362;

v362:
    v349 = qvalue(elt(env, 7)); /* !!sclc */
    if (v349 == nil) goto v363;
    v349 = qvalue(elt(env, 7)); /* !!sclc */
    goto v364;

v364:
    stack[-2] = v349;
    v349 = stack[-2];
    if (v349 == nil) goto v365;
    stack[-1] = elt(env, 3); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v350 = (Lisp_Object)49; /* 3 */
    v349 = stack[-12];
    v349 = difference2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-3] = v349;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v349 = stack[-2];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    stack[0] = times2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-2];
    v349 = qcdr(v349);
    v350 = qcdr(v349);
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v350 = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-9];
    fn = elt(env, 11); /* greaterp!: */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    if (v349 == nil) goto v365;
    v349 = qvalue(elt(env, 2)); /* bfz!* */
    goto v130;

v365:
    stack[-2] = stack[-13];
    stack[-1] = (Lisp_Object)1; /* 0 */
    v349 = stack[-9];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = (Lisp_Object)1; /* 0 */
    if (v350 == v349) goto v366;
    v349 = stack[-9];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v349 = Labsval(nil, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-9];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = sub1(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = plus2(stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    goto v367;

v367:
    v349 = add1(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 15); /* min */
    v349 = (*qfn2(fn))(qenv(fn), stack[-1], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = difference2(stack[-2], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-5] = v349;
    stack[-1] = elt(env, 3); /* !:rd!: */
    stack[0] = (Lisp_Object)33; /* 2 */
    v349 = stack[-5];
    v349 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-4] = v349;
    v349 = stack[-9];
    stack[-1] = v349;
    stack[-2] = v349;
    stack[-8] = v349;
    stack[-3] = elt(env, 3); /* !:rd!: */
    v349 = stack[-9];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = stack[-9];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    stack[0] = times2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-9];
    v349 = qcdr(v349);
    v350 = qcdr(v349);
    v349 = stack[-9];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[0] = list2star(stack[-3], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-5];
    v349 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 16); /* cut!:ep */
    v349 = (*qfn2(fn))(qenv(fn), stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-3] = v349;
    stack[0] = elt(env, 3); /* !:rd!: */
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v350 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = list2star(stack[0], v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-9] = v349;
    v349 = (Lisp_Object)17; /* 1 */
    stack[-6] = v349;
    stack[-11] = v349;
    goto v368;

v368:
    v349 = stack[-1];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = (Lisp_Object)1; /* 0 */
    v349 = (Lisp_Object)greaterp2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    v349 = v349 ? lisp_true : nil;
    env = stack[-15];
    if (v349 == nil) goto v369;
    v349 = stack[-1];
    v350 = v349;
    goto v370;

v370:
    v349 = stack[-4];
    fn = elt(env, 11); /* greaterp!: */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    if (v349 == nil) goto v371;
    v350 = stack[-6];
    v349 = (Lisp_Object)33; /* 2 */
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-6] = v349;
    stack[-1] = elt(env, 3); /* !:rd!: */
    stack[-3] = stack[-11];
    stack[0] = stack[-6];
    v349 = stack[-6];
    v349 = sub1(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = times2(stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v350 = times2(stack[-3], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-11] = v350;
    v349 = (Lisp_Object)1; /* 0 */
    v349 = list2star(stack[-1], v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-3] = v349;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v349 = stack[-2];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = stack[-9];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    stack[0] = times2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-2];
    v349 = qcdr(v349);
    v350 = qcdr(v349);
    v349 = stack[-9];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[0] = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-5];
    v349 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 16); /* cut!:ep */
    v349 = (*qfn2(fn))(qenv(fn), stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-2] = v349;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[-14] = stack[-13];
    v349 = stack[-3];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = (Lisp_Object)1; /* 0 */
    if (v350 == v349) goto v372;
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v349 = Labsval(nil, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = sub1(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = plus2(stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    goto v373;

v373:
    stack[-14] = difference2(stack[-14], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-2];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = (Lisp_Object)1; /* 0 */
    if (v350 == v349) goto v374;
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v349 = Labsval(nil, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 9); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = sub1(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = plus2(stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    goto v375;

v375:
    v349 = plus2(stack[-14], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 17); /* max */
    v349 = (*qfn2(fn))(qenv(fn), stack[-1], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v351 = stack[-2];
    v350 = stack[-3];
    fn = elt(env, 18); /* divide!: */
    v349 = (*qfnn(fn))(qenv(fn), 3, v351, v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-1] = v349;
    v350 = stack[-8];
    v349 = stack[-1];
    fn = elt(env, 19); /* plus!: */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-8] = v349;
    v350 = stack[-6];
    v349 = (Lisp_Object)321; /* 20 */
    v349 = Cremainder(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = (Lisp_Object)zerop(v349);
    v349 = v349 ? lisp_true : nil;
    env = stack[-15];
    if (v349 == nil) goto v368;
    stack[0] = stack[-8];
    v349 = stack[-5];
    v349 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 16); /* cut!:ep */
    v349 = (*qfn2(fn))(qenv(fn), stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-8] = v349;
    goto v368;

v374:
    v349 = (Lisp_Object)1; /* 0 */
    goto v375;

v372:
    v349 = (Lisp_Object)1; /* 0 */
    goto v373;

v371:
    stack[-1] = elt(env, 3); /* !:rd!: */
    v349 = stack[-10];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = stack[-8];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    stack[0] = times2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-10];
    v349 = qcdr(v349);
    v350 = qcdr(v349);
    v349 = stack[-8];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v350 = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-12];
    fn = elt(env, 20); /* round!:mt */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    goto v130;

v369:
    stack[0] = elt(env, 3); /* !:rd!: */
    v349 = stack[-1];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v350 = negate(v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-1];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = list2star(stack[0], v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v350 = v349;
    goto v370;

v366:
    v349 = (Lisp_Object)1; /* 0 */
    goto v367;

v363:
    v349 = qvalue(elt(env, 4)); /* !!scls */
    goto v364;

v361:
    v350 = stack[-9];
    v349 = stack[-13];
    fn = elt(env, 13); /* cut!:mt */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-9] = v349;
    v350 = stack[-9];
    v349 = stack[-12];
    fn = elt(env, 14); /* cos!: */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-2] = v349;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v349 = stack[-10];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    stack[0] = times2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-10];
    v349 = qcdr(v349);
    v350 = qcdr(v349);
    v349 = stack[-2];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    goto v130;

v359:
    v349 = stack[-2];
    qvalue(elt(env, 4)) = v349; /* !!scls */
    goto v362;

v355:
    v350 = stack[-2];
    v349 = stack[-3];
    fn = elt(env, 21); /* quotient!: */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-5] = v349;
    v350 = v349;
    v350 = qcdr(v350);
    v350 = qcar(v350);
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = Lash1(nil, v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-11] = v349;
    stack[-4] = stack[-2];
    stack[-1] = elt(env, 3); /* !:rd!: */
    v349 = stack[-5];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    stack[0] = times2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = stack[-5];
    v349 = qcdr(v349);
    v350 = qcdr(v349);
    v349 = stack[-3];
    v349 = qcdr(v349);
    v349 = qcdr(v349);
    v349 = plus2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    v349 = list2star(stack[-1], stack[0], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    fn = elt(env, 12); /* difference!: */
    v349 = (*qfn2(fn))(qenv(fn), stack[-4], v349);
    nil = C_nil;
    if (exception_pending()) goto v354;
    env = stack[-15];
    stack[-9] = v349;
    goto v356;

v113:
    v349 = qvalue(elt(env, 2)); /* bfz!* */
    { popv(16); return onevalue(v349); }

v109:
    stack[0] = (Lisp_Object)1; /* 0 */
    v350 = elt(env, 1); /* "Invalid argument to" */
    v349 = elt(env, 0); /* sin!: */
    v349 = list2(v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v352;
    env = stack[-15];
    {
        Lisp_Object v376 = stack[0];
        popv(16);
        fn = elt(env, 22); /* error */
        return (*qfn2(fn))(qenv(fn), v376, v349);
    }
/* error exit handlers */
v354:
    env = stack[-15];
    qvalue(elt(env, 4)) = stack[-7]; /* !!scls */
    popv(16);
    return nil;
v352:
    popv(16);
    return nil;
}



/* Code for lispstmtp */

static Lisp_Object CC_lispstmtp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v380, v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispstmtp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v0;
/* end of prologue */
    v145 = v77;
    v145 = (consp(v145) ? nil : lisp_true);
    if (!(v145 == nil)) return onevalue(v145);
    v145 = v77;
    v380 = qcar(v145);
    v145 = qvalue(elt(env, 1)); /* !*lispstmtops!* */
    v145 = Lmemq(nil, v380, v145);
    if (!(v145 == nil)) return onevalue(v145);
    v145 = v77;
    v145 = qcar(v145);
    if (!consp(v145)) goto v170;
    v145 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v145);

v170:
    v145 = v77;
    v380 = qcar(v145);
    v145 = qvalue(elt(env, 3)); /* !*lisparithexpops!* */
    v145 = Lmemq(nil, v380, v145);
    if (!(v145 == nil)) goto v381;
    v145 = v77;
    v380 = qcar(v145);
    v145 = qvalue(elt(env, 4)); /* !*lisplogexpops!* */
    v145 = Lmemq(nil, v380, v145);
    if (!(v145 == nil)) goto v381;
    v145 = v77;
    v380 = qcar(v145);
    v145 = qvalue(elt(env, 5)); /* !*lispstmtgpops!* */
    v145 = Lmemq(nil, v380, v145);
    if (!(v145 == nil)) goto v381;
    v145 = v77;
    v145 = qcar(v145);
    v380 = qvalue(elt(env, 6)); /* !*lispdefops!* */
    v145 = Lmemq(nil, v145, v380);
    goto v381;

v381:
    v145 = (v145 == nil ? lisp_true : nil);
    return onevalue(v145);
}



/* Code for calc_map_tar */

static Lisp_Object CC_calc_map_tar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v387, v63, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_map_tar");
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
    v63 = v0;
/* end of prologue */
    v387 = v63;
    v387 = qcar(v387);
    stack[-4] = v387;
    v387 = v63;
    v387 = qcdr(v387);
    v387 = qcar(v387);
    stack[-2] = v387;
    v387 = v63;
    v387 = qcdr(v387);
    v387 = qcdr(v387);
    v387 = qcar(v387);
    stack[0] = v387;
    v387 = v63;
    v387 = qcdr(v387);
    v387 = qcdr(v387);
    v387 = qcdr(v387);
    v387 = qcar(v387);
    stack[-1] = v387;
    v387 = v63;
    v387 = qcdr(v387);
    v387 = qcdr(v387);
    v387 = qcdr(v387);
    v387 = qcdr(v387);
    v387 = qcar(v387);
    v63 = v387;
    v387 = stack[-3];
    fn = elt(env, 1); /* ev!-poles */
    v387 = (*qfn2(fn))(qenv(fn), v63, v387);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    if (v387 == nil) goto v75;
    v387 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v387); }

v75:
    v387 = stack[-1];
    fn = elt(env, 2); /* constimes */
    stack[-1] = (*qfn1(fn))(qenv(fn), v387);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v63 = stack[0];
    v387 = stack[-3];
    fn = elt(env, 3); /* ev!-tades */
    v387 = (*qfn2(fn))(qenv(fn), v63, v387);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    fn = elt(env, 2); /* constimes */
    stack[0] = (*qfn1(fn))(qenv(fn), v387);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    v387 = stack[-2];
    if (v387 == nil) goto v388;
    v49 = stack[-4];
    v63 = stack[-2];
    v387 = stack[-3];
    fn = elt(env, 4); /* strand!-alg!-top */
    v387 = (*qfnn(fn))(qenv(fn), 3, v49, v63, v387);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    goto v64;

v64:
    v387 = list3(stack[-1], stack[0], v387);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 2); /* constimes */
        return (*qfn1(fn))(qenv(fn), v387);
    }

v388:
    v387 = (Lisp_Object)17; /* 1 */
    goto v64;
/* error exit handlers */
v10:
    popv(6);
    return nil;
}



/* Code for fs!:onep */

static Lisp_Object CC_fsTonep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:onep");
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
    v146 = stack[0];
    v147 = (Lisp_Object)49; /* 3 */
    v147 = *(Lisp_Object *)((char *)v146 + (CELL-TAG_VECTOR) + ((int32_t)v147/(16/CELL)));
    if (v147 == nil) goto v74;
    v147 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v147); }

v74:
    v146 = stack[0];
    v147 = (Lisp_Object)1; /* 0 */
    v147 = *(Lisp_Object *)((char *)v146 + (CELL-TAG_VECTOR) + ((int32_t)v147/(16/CELL)));
    v147 = Lonep(nil, v147);
    env = stack[-1];
    if (v147 == nil) goto v143;
    v147 = stack[0];
    fn = elt(env, 3); /* fs!:null!-angle */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    if (v147 == nil) goto v381;
    v146 = stack[0];
    v147 = (Lisp_Object)17; /* 1 */
    v147 = *(Lisp_Object *)((char *)v146 + (CELL-TAG_VECTOR) + ((int32_t)v147/(16/CELL)));
    v146 = elt(env, 2); /* cos */
    v147 = (v147 == v146 ? lisp_true : nil);
    { popv(2); return onevalue(v147); }

v381:
    v147 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v147); }

v143:
    v147 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v147); }
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for partsym_zerop */

static Lisp_Object CC_partsym_zerop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v348, v379;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partsym_zerop");
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

v391:
    v98 = stack[-1];
    if (v98 == nil) goto v73;
    v98 = stack[-1];
    v98 = qcar(v98);
    fn = elt(env, 3); /* repeats */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v379 = v98;
    v98 = stack[0];
    v348 = qcar(v98);
    v98 = elt(env, 2); /* !- */
    if (!(v348 == v98)) goto v113;
    v98 = v379;
    if (!(v98 == nil)) { popv(3); return onevalue(v379); }

v113:
    v98 = stack[-1];
    v348 = qcdr(v98);
    v98 = stack[0];
    v98 = qcdr(v98);
    stack[-1] = v348;
    stack[0] = v98;
    goto v391;

v73:
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v98); }
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for bdstest */

static Lisp_Object CC_bdstest(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bdstest");
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
    v114 = stack[0];
    v114 = qcar(v114);
    fn = elt(env, 1); /* r2bf */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v381;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v381;
    env = stack[-2];
    v114 = stack[0];
    v114 = qcdr(v114);
    fn = elt(env, 1); /* r2bf */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v381;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v381;
    env = stack[-2];
    stack[0] = v114;
    fn = elt(env, 3); /* equal!: */
    v114 = (*qfn2(fn))(qenv(fn), stack[-1], v114);
    nil = C_nil;
    if (exception_pending()) goto v381;
    if (!(v114 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v114 = nil;
    { popv(3); return onevalue(v114); }
/* error exit handlers */
v381:
    popv(3);
    return nil;
}



/* Code for insertglue */

static Lisp_Object CC_insertglue(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v44, v45, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertglue");
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
    stack[-4] = v0;
/* end of prologue */
    stack[0] = nil;
    v122 = (Lisp_Object)1; /* 0 */
    stack[-1] = v122;
    stack[-2] = v122;
    v122 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v122;
    v122 = stack[-4];
    stack[-3] = v122;
    goto v74;

v74:
    v122 = stack[-4];
    if (v122 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v122 = stack[-5];
    v44 = v122;
    v122 = stack[-4];
    v122 = qcar(v122);
    stack[-5] = v122;
    v123 = v44;
    v45 = stack[-5];
    v44 = stack[-2];
    v122 = stack[-1];
    fn = elt(env, 10); /* interglue */
    v122 = (*qfnn(fn))(qenv(fn), 4, v123, v45, v44, v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-6];
    v44 = v122;
    v122 = v44;
    if (v122 == nil) goto v98;
    v122 = stack[-4];
    v122 = cons(v44, v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-6];
    v122 = Lrplacd(nil, stack[0], v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-6];
    goto v98;

v98:
    v122 = stack[-4];
    stack[0] = v122;
    v122 = stack[-4];
    v122 = qcdr(v122);
    stack[-4] = v122;
    v44 = stack[-5];
    v122 = elt(env, 2); /* class */
    v44 = get(v44, v122);
    env = stack[-6];
    v122 = elt(env, 3); /* inn */
    if (v44 == v122) goto v26;
    v44 = stack[-5];
    v122 = elt(env, 2); /* class */
    v44 = get(v44, v122);
    env = stack[-6];
    v122 = elt(env, 8); /* opn */
    if (v44 == v122) goto v401;
    v44 = stack[-5];
    v122 = elt(env, 2); /* class */
    v44 = get(v44, v122);
    env = stack[-6];
    v122 = elt(env, 9); /* clo */
    if (!(v44 == v122)) goto v74;
    v122 = stack[-1];
    v122 = sub1(v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-6];
    stack[-1] = v122;
    goto v74;

v401:
    v122 = stack[-1];
    v122 = add1(v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-6];
    stack[-1] = v122;
    goto v74;

v26:
    v44 = stack[-5];
    v122 = elt(env, 4); /* textag */
    v44 = get(v44, v122);
    env = stack[-6];
    v122 = elt(env, 5); /* (beg sup sub frc mat) */
    v122 = Lmemq(nil, v44, v122);
    if (v122 == nil) goto v402;
    v44 = stack[-5];
    v122 = elt(env, 4); /* textag */
    v44 = get(v44, v122);
    env = stack[-6];
    v122 = elt(env, 6); /* frc */
    if (!(v44 == v122)) goto v49;
    v44 = stack[-2];
    v122 = (Lisp_Object)1; /* 0 */
    if (!(v44 == v122)) goto v49;

v402:
    v44 = stack[-5];
    v122 = elt(env, 4); /* textag */
    v44 = get(v44, v122);
    env = stack[-6];
    v122 = elt(env, 7); /* end */
    if (!(v44 == v122)) goto v74;
    v44 = stack[-2];
    v122 = (Lisp_Object)1; /* 0 */
    v122 = (Lisp_Object)greaterp2(v44, v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    v122 = v122 ? lisp_true : nil;
    env = stack[-6];
    if (v122 == nil) goto v74;
    v122 = stack[-2];
    v122 = sub1(v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-6];
    stack[-2] = v122;
    goto v74;

v49:
    v122 = stack[-2];
    v122 = add1(v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-6];
    stack[-2] = v122;
    goto v74;
/* error exit handlers */
v157:
    popv(7);
    return nil;
}



/* Code for canprod */

static Lisp_Object CC_canprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v306, v421, v422, v423;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canprod");
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
    stack[0] = nil;
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v306 = stack[-3];
    if (!consp(v306)) goto v66;
    v306 = stack[-3];
    v306 = qcar(v306);
    if (!consp(v306)) goto v66;
    v306 = stack[-3];
    v306 = qcdr(v306);
    if (!(v306 == nil)) goto v66;
    v306 = stack[-4];
    if (!consp(v306)) goto v348;
    v306 = stack[-4];
    v306 = qcar(v306);
    if (!consp(v306)) goto v348;
    v306 = stack[-4];
    v306 = qcdr(v306);
    if (!(v306 == nil)) goto v66;

v348:
    v306 = stack[-4];
    if (!consp(v306)) goto v147;
    v306 = stack[-4];
    v306 = qcar(v306);
    if (!(!consp(v306))) goto v75;

v147:
    v306 = stack[-3];
    if (!consp(v306)) goto v424;
    v306 = stack[-3];
    v306 = qcar(v306);
    if (!(!consp(v306))) goto v75;

v424:
    v421 = stack[-2];
    v306 = stack[-4];
    fn = elt(env, 2); /* reprod */
    v306 = (*qfn2(fn))(qenv(fn), v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    fn = elt(env, 2); /* reprod */
    v306 = (*qfn2(fn))(qenv(fn), stack[0], v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[0] = v306;
    stack[-2] = stack[-5];
    v421 = stack[-1];
    v306 = stack[-3];
    fn = elt(env, 2); /* reprod */
    v306 = (*qfn2(fn))(qenv(fn), v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    fn = elt(env, 2); /* reprod */
    v306 = (*qfn2(fn))(qenv(fn), stack[-2], v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[-5] = v306;
    v306 = stack[-5];
    fn = elt(env, 3); /* minusf */
    v306 = (*qfn1(fn))(qenv(fn), v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    if (v306 == nil) goto v17;
    v306 = stack[0];
    fn = elt(env, 4); /* negf */
    v306 = (*qfn1(fn))(qenv(fn), v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[0] = v306;
    v306 = stack[-5];
    fn = elt(env, 4); /* negf */
    v306 = (*qfn1(fn))(qenv(fn), v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[-5] = v306;
    goto v17;

v17:
    v421 = stack[0];
    v306 = stack[-5];
    v306 = cons(v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    fn = elt(env, 5); /* cancel */
    v306 = (*qfn1(fn))(qenv(fn), v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[-5] = v306;
    v306 = stack[-5];
    v306 = qcar(v306);
    stack[0] = v306;
    v306 = stack[0];
    if (!consp(v306)) goto v426;
    v306 = stack[0];
    v306 = qcar(v306);
    if (!consp(v306)) goto v426;
    v306 = stack[0];
    v306 = qcdr(v306);
    if (!(v306 == nil)) goto v426;
    v306 = stack[0];
    v306 = qcar(v306);
    v421 = qcdr(v306);
    v306 = (Lisp_Object)17; /* 1 */
    if (!(v421 == v306)) goto v426;
    v306 = stack[0];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v421 = qcdr(v306);
    v306 = (Lisp_Object)17; /* 1 */
    if (!(v421 == v306)) goto v426;
    v306 = stack[0];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    stack[-2] = v306;
    v421 = v306;
    v306 = v421;
    if (!consp(v306)) goto v427;
    v306 = v421;
    v306 = qcar(v306);
    v306 = (consp(v306) ? nil : lisp_true);
    v306 = (v306 == nil ? lisp_true : nil);
    goto v428;

v428:
    if (v306 == nil) goto v426;
    v306 = stack[-2];
    stack[0] = v306;
    goto v426;

v426:
    v306 = stack[-5];
    v306 = qcdr(v306);
    stack[-5] = v306;
    v306 = stack[-5];
    if (!consp(v306)) goto v429;
    v306 = stack[-5];
    v306 = qcar(v306);
    if (!consp(v306)) goto v429;
    v306 = stack[-5];
    v306 = qcdr(v306);
    if (!(v306 == nil)) goto v429;
    v306 = stack[-5];
    v306 = qcar(v306);
    v421 = qcdr(v306);
    v306 = (Lisp_Object)17; /* 1 */
    if (!(v421 == v306)) goto v429;
    v306 = stack[-5];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v421 = qcdr(v306);
    v306 = (Lisp_Object)17; /* 1 */
    if (!(v421 == v306)) goto v429;
    v306 = stack[-5];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    stack[-2] = v306;
    v421 = v306;
    v306 = v421;
    if (!consp(v306)) goto v430;
    v306 = v421;
    v306 = qcar(v306);
    v306 = (consp(v306) ? nil : lisp_true);
    v306 = (v306 == nil ? lisp_true : nil);
    goto v4;

v4:
    if (v306 == nil) goto v429;
    v306 = stack[-2];
    stack[-5] = v306;
    goto v429;

v429:
    v421 = stack[0];
    v306 = stack[-5];
    v306 = cons(v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 6); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v306);
    }

v430:
    v306 = qvalue(elt(env, 1)); /* nil */
    goto v4;

v427:
    v306 = qvalue(elt(env, 1)); /* nil */
    goto v428;

v75:
    v306 = stack[-4];
    if (!consp(v306)) goto v377;
    v306 = stack[-4];
    v306 = qcar(v306);
    if (!consp(v306)) goto v377;
    v306 = stack[-4];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    if (!consp(v306)) goto v377;
    v306 = stack[-4];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    if (!consp(v306)) goto v377;
    v306 = stack[-4];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v423 = qcar(v306);
    v306 = stack[-4];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v422 = qcdr(v306);
    v421 = stack[0];
    v306 = stack[-5];
    fn = elt(env, 7); /* cprod1 */
    v306 = (*qfnn(fn))(qenv(fn), 4, v423, v422, v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    v421 = v306;
    v306 = v421;
    v306 = qcar(v306);
    stack[0] = v306;
    v306 = v421;
    v306 = qcdr(v306);
    stack[-5] = v306;
    v306 = stack[-4];
    v306 = qcar(v306);
    v306 = qcdr(v306);
    stack[-4] = v306;
    goto v348;

v377:
    v306 = stack[-3];
    if (!consp(v306)) goto v81;
    v306 = stack[-3];
    v306 = qcar(v306);
    if (!consp(v306)) goto v81;
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    if (!consp(v306)) goto v81;
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    v306 = qcar(v306);
    if (!consp(v306)) goto v81;
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v423 = qcar(v306);
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcar(v306);
    v422 = qcdr(v306);
    v421 = stack[-5];
    v306 = stack[0];
    fn = elt(env, 7); /* cprod1 */
    v306 = (*qfnn(fn))(qenv(fn), 4, v423, v422, v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    v421 = v306;
    v306 = v421;
    v306 = qcar(v306);
    stack[-5] = v306;
    v306 = v421;
    v306 = qcdr(v306);
    stack[0] = v306;
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcdr(v306);
    stack[-3] = v306;
    goto v348;

v81:
    v306 = stack[-4];
    if (!consp(v306)) goto v431;
    v306 = stack[-4];
    v306 = qcar(v306);
    if (!consp(v306)) goto v431;
    v306 = stack[-3];
    if (!consp(v306)) goto v85;
    v306 = stack[-3];
    v306 = qcar(v306);
    if (!consp(v306)) goto v85;
    v306 = stack[-4];
    v306 = qcar(v306);
    v421 = qcar(v306);
    v306 = stack[-2];
    v306 = cons(v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[-2] = v306;
    v306 = stack[-3];
    v306 = qcar(v306);
    v421 = qcar(v306);
    v306 = stack[-1];
    v306 = cons(v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[-1] = v306;
    v306 = stack[-4];
    v306 = qcar(v306);
    v306 = qcdr(v306);
    stack[-4] = v306;
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcdr(v306);
    stack[-3] = v306;
    goto v348;

v85:
    v306 = stack[-4];
    v306 = qcar(v306);
    v421 = qcar(v306);
    v306 = stack[-2];
    v306 = cons(v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[-2] = v306;
    v306 = stack[-4];
    v306 = qcar(v306);
    v306 = qcdr(v306);
    stack[-4] = v306;
    goto v348;

v431:
    v306 = stack[-3];
    v306 = qcar(v306);
    v421 = qcar(v306);
    v306 = stack[-1];
    v306 = cons(v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    stack[-1] = v306;
    v306 = stack[-3];
    v306 = qcar(v306);
    v306 = qcdr(v306);
    stack[-3] = v306;
    goto v348;

v66:
    v421 = stack[-4];
    v306 = stack[-3];
    v306 = cons(v421, v306);
    nil = C_nil;
    if (exception_pending()) goto v425;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 5); /* cancel */
        return (*qfn1(fn))(qenv(fn), v306);
    }
/* error exit handlers */
v425:
    popv(7);
    return nil;
}



/* Code for delqip */

static Lisp_Object CC_delqip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delqip");
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
    v113 = v0;
/* end of prologue */
    v110 = stack[0];
    if (!consp(v110)) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v111 = v113;
    v110 = stack[0];
    v110 = qcar(v110);
    if (v111 == v110) goto v151;
    v111 = v113;
    v110 = stack[0];
    fn = elt(env, 1); /* delqip1 */
    v110 = (*qfn2(fn))(qenv(fn), v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v67;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v151:
    v110 = stack[0];
    v110 = qcdr(v110);
    { popv(1); return onevalue(v110); }
/* error exit handlers */
v67:
    popv(1);
    return nil;
}



/* Code for spmultsm */

static Lisp_Object CC_spmultsm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v433, v140, v344, v402;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmultsm");
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
    v433 = stack[-6];
    v433 = qcdr(v433);
    v433 = qcdr(v433);
    v433 = qcar(v433);
    stack[-8] = v433;
    v433 = stack[-8];
    v433 = qcdr(v433);
    v140 = qcar(v433);
    v433 = stack[-8];
    fn = elt(env, 2); /* mkempspmat */
    v433 = (*qfn2(fn))(qenv(fn), v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    stack[-5] = v433;
    v433 = (Lisp_Object)17; /* 1 */
    stack[-1] = v433;
    goto v162;

v162:
    v433 = stack[-8];
    v433 = qcdr(v433);
    v140 = qcar(v433);
    v433 = stack[-1];
    v433 = difference2(v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    v433 = Lminusp(nil, v433);
    env = stack[-9];
    if (v433 == nil) goto v105;
    v433 = stack[-5];
    popv(10);
    return ncons(v433);

v105:
    v140 = stack[-6];
    v433 = stack[-1];
    fn = elt(env, 3); /* findrow */
    v433 = (*qfn2(fn))(qenv(fn), v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    v140 = v433;
    v433 = stack[-1];
    stack[-4] = v433;
    v433 = v140;
    if (v433 == nil) goto v346;
    v433 = v140;
    v433 = qcdr(v433);
    stack[0] = v433;
    goto v378;

v378:
    v433 = stack[0];
    if (v433 == nil) goto v346;
    v433 = stack[0];
    v433 = qcar(v433);
    v140 = v433;
    v433 = v140;
    v433 = qcar(v433);
    stack[-3] = v433;
    v433 = v140;
    v433 = qcdr(v433);
    fn = elt(env, 4); /* simp */
    v433 = (*qfn1(fn))(qenv(fn), v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    v140 = stack[-7];
    fn = elt(env, 5); /* multsq */
    v433 = (*qfn2(fn))(qenv(fn), v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    stack[-2] = v433;
    v433 = stack[-2];
    fn = elt(env, 6); /* mk!*sq */
    v433 = (*qfn1(fn))(qenv(fn), v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    stack[-2] = v433;
    v140 = stack[-2];
    v433 = (Lisp_Object)1; /* 0 */
    if (v140 == v433) goto v11;
    v344 = stack[-5];
    v140 = stack[-4];
    v433 = stack[-3];
    v402 = list3(v344, v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    v344 = stack[-2];
    v140 = stack[-5];
    v433 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* letmtr3 */
    v433 = (*qfnn(fn))(qenv(fn), 4, v402, v344, v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    goto v11;

v11:
    v433 = stack[0];
    v433 = qcdr(v433);
    stack[0] = v433;
    goto v378;

v346:
    v433 = stack[-1];
    v433 = add1(v433);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-9];
    stack[-1] = v433;
    goto v162;
/* error exit handlers */
v420:
    popv(10);
    return nil;
}



/* Code for improvelayout */

static Lisp_Object MS_CDECL CC_improvelayout(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v436, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "improvelayout");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for improvelayout");
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
    stack[-2] = nil;
    v81 = (Lisp_Object)1; /* 0 */
    stack[-1] = v81;
    goto v112;

v112:
    v436 = qvalue(elt(env, 1)); /* rowmax */
    v81 = stack[-1];
    v81 = difference2(v436, v81);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-3];
    v81 = Lminusp(nil, v81);
    env = stack[-3];
    if (v81 == nil) goto v66;
    v81 = stack[-2];
    if (v81 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    fn = elt(env, 10); /* improvekvarlst */
    v81 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v334;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v66:
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v436 = qvalue(elt(env, 4)); /* maxvar */
    v81 = stack[-1];
    v81 = plus2(v436, v81);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-3];
    v436 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v81/(16/CELL)));
    v81 = (Lisp_Object)49; /* 3 */
    v81 = *(Lisp_Object *)((char *)v436 + (CELL-TAG_VECTOR) + ((int32_t)v81/(16/CELL)));
    v220 = v81;
    if (is_number(v81)) goto v68;
    v81 = v220;
    v81 = Lconsp(nil, v81);
    env = stack[-3];
    if (!(v81 == nil)) goto v68;
    v436 = stack[-1];
    v81 = qvalue(elt(env, 5)); /* codbexl!* */
    v81 = Lmember(nil, v436, v81);
    if (v81 == nil) goto v345;
    v436 = v220;
    v81 = elt(env, 6); /* nex */
    v81 = get(v436, v81);
    env = stack[-3];
    if (!(v81 == nil)) goto v68;
    v436 = v220;
    v81 = elt(env, 7); /* newsym */
    v81 = Lflagp(nil, v436, v81);
    env = stack[-3];
    if (v81 == nil) goto v68;
    v436 = v220;
    v81 = elt(env, 8); /* alias */
    v81 = get(v436, v81);
    env = stack[-3];
    if (!(v81 == nil)) goto v68;

v345:
    v436 = v220;
    v81 = stack[-1];
    fn = elt(env, 11); /* testononeel */
    v81 = (*qfn2(fn))(qenv(fn), v436, v81);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-3];
    if (v81 == nil) goto v68;
    v81 = qvalue(elt(env, 9)); /* t */
    stack[-2] = v81;
    goto v68;

v68:
    v81 = stack[-1];
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v334;
    env = stack[-3];
    stack[-1] = v81;
    goto v112;
/* error exit handlers */
v334:
    popv(4);
    return nil;
}



/* Code for poly!-remainder */

static Lisp_Object CC_polyKremainder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v101, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-remainder");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v103 = v0;
/* end of prologue */
    v143 = v103;
    v101 = elt(env, 1); /* remainder */
    v103 = qvalue(elt(env, 2)); /* nil */
    {
        fn = elt(env, 3); /* poly!-divide!* */
        return (*qfnn(fn))(qenv(fn), 3, v143, v101, v103);
    }
}



/* Code for evalsetbool */

static Lisp_Object MS_CDECL CC_evalsetbool(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v393, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v355, v444, v445, v416;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evalsetbool");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalsetbool");
#endif
    if (stack >= stacklimit)
    {
        push3(v393,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v393);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v393;
    stack[-6] = v1;
    stack[-7] = v0;
/* end of prologue */
    stack[-8] = nil;
    stack[-4] = nil;
    v444 = stack[-6];
    v355 = stack[-5];
    v355 = list2(v444, v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    stack[-3] = v355;
    v355 = stack[-3];
    if (v355 == nil) goto v68;
    v355 = stack[-3];
    v355 = qcar(v355);
    v445 = v355;
    v444 = v445;
    v355 = elt(env, 2); /* list */
    if (!consp(v444)) goto v67;
    v444 = qcar(v444);
    if (!(v444 == v355)) goto v67;
    v355 = qvalue(elt(env, 3)); /* t */
    stack[-8] = v355;
    v355 = v445;
    v355 = qcdr(v355);
    goto v113;

v113:
    v355 = ncons(v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    stack[-1] = v355;
    stack[-2] = v355;
    goto v101;

v101:
    v355 = stack[-3];
    v355 = qcdr(v355);
    stack[-3] = v355;
    v355 = stack[-3];
    if (v355 == nil) goto v387;
    stack[0] = stack[-1];
    v355 = stack[-3];
    v355 = qcar(v355);
    v445 = v355;
    v444 = v445;
    v355 = elt(env, 2); /* list */
    if (!consp(v444)) goto v116;
    v444 = qcar(v444);
    if (!(v444 == v355)) goto v116;
    v355 = qvalue(elt(env, 3)); /* t */
    stack[-8] = v355;
    v355 = v445;
    v355 = qcdr(v355);
    goto v159;

v159:
    v355 = ncons(v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    v355 = Lrplacd(nil, stack[0], v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    v355 = stack[-1];
    v355 = qcdr(v355);
    stack[-1] = v355;
    goto v101;

v116:
    v355 = v445;
    fn = elt(env, 9); /* reval */
    v355 = (*qfn1(fn))(qenv(fn), v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    v445 = v355;
    if (symbolp(v355)) goto v436;
    v355 = v445;
    v355 = Lconsp(nil, v355);
    env = stack[-9];
    if (v355 == nil) goto v344;
    v355 = v445;
    v444 = qcar(v355);
    v355 = elt(env, 4); /* setvalued */
    v355 = Lflagp(nil, v444, v355);
    env = stack[-9];
    if (!(v355 == nil)) goto v436;

v344:
    v444 = v445;
    v355 = elt(env, 5); /* "set" */
    fn = elt(env, 10); /* typerr */
    v355 = (*qfn2(fn))(qenv(fn), v444, v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    goto v159;

v436:
    v355 = qvalue(elt(env, 3)); /* t */
    stack[-4] = v355;
    v355 = v445;
    goto v159;

v387:
    v355 = stack[-2];
    goto v103;

v103:
    v445 = v355;
    v355 = stack[-8];
    if (v355 == nil) { popv(10); return onevalue(v445); }
    v355 = stack[-4];
    if (v355 == nil) goto v122;
    stack[0] = elt(env, 6); /* "Cannot evaluate" */
    stack[-1] = stack[-7];
    v355 = stack[-6];
    fn = elt(env, 9); /* reval */
    stack[-2] = (*qfn1(fn))(qenv(fn), v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    v355 = stack[-5];
    fn = elt(env, 9); /* reval */
    v355 = (*qfn1(fn))(qenv(fn), v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    v416 = list3(stack[-1], stack[-2], v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    v445 = elt(env, 7); /* "as Boolean-valued set expression" */
    v444 = qvalue(elt(env, 1)); /* nil */
    v355 = qvalue(elt(env, 3)); /* t */
    {
        Lisp_Object v125 = stack[0];
        popv(10);
        fn = elt(env, 11); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v125, v416, v445, v444, v355);
    }

v122:
    v444 = stack[-7];
    v355 = elt(env, 8); /* setboolfn */
    v355 = get(v444, v355);
    env = stack[-9];
    v444 = v445;
    {
        popv(10);
        fn = elt(env, 12); /* apply */
        return (*qfn2(fn))(qenv(fn), v355, v444);
    }

v67:
    v355 = v445;
    fn = elt(env, 9); /* reval */
    v355 = (*qfn1(fn))(qenv(fn), v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    v445 = v355;
    if (symbolp(v355)) goto v105;
    v355 = v445;
    v355 = Lconsp(nil, v355);
    env = stack[-9];
    if (v355 == nil) goto v178;
    v355 = v445;
    v444 = qcar(v355);
    v355 = elt(env, 4); /* setvalued */
    v355 = Lflagp(nil, v444, v355);
    env = stack[-9];
    if (!(v355 == nil)) goto v105;

v178:
    v444 = v445;
    v355 = elt(env, 5); /* "set" */
    fn = elt(env, 10); /* typerr */
    v355 = (*qfn2(fn))(qenv(fn), v444, v355);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-9];
    goto v113;

v105:
    v355 = qvalue(elt(env, 3)); /* t */
    stack[-4] = v355;
    v355 = v445;
    goto v113;

v68:
    v355 = qvalue(elt(env, 1)); /* nil */
    goto v103;
/* error exit handlers */
v124:
    popv(10);
    return nil;
}



/* Code for partdff */

static Lisp_Object CC_partdff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v433, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partdff");
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
    goto v385;

v385:
    v433 = stack[-3];
    if (!consp(v433)) goto v169;
    v433 = stack[-3];
    v433 = qcar(v433);
    if (!consp(v433)) goto v169;
    v433 = qvalue(elt(env, 1)); /* !*product!-rule */
    if (v433 == nil) goto v166;
    v433 = stack[-3];
    v433 = qcar(v433);
    v140 = qcar(v433);
    v433 = (Lisp_Object)17; /* 1 */
    v433 = cons(v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v140 = ncons(v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v433 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v433 = stack[-3];
    v433 = qcar(v433);
    v140 = qcdr(v433);
    v433 = stack[-2];
    v433 = CC_partdff(env, v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    fn = elt(env, 3); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v433 = stack[-3];
    v433 = qcar(v433);
    v140 = qcar(v433);
    v433 = stack[-2];
    fn = elt(env, 4); /* partdfpow */
    stack[0] = (*qfn2(fn))(qenv(fn), v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v433 = stack[-3];
    v433 = qcar(v433);
    v140 = qcdr(v433);
    v433 = (Lisp_Object)17; /* 1 */
    v433 = cons(v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    fn = elt(env, 3); /* multsq */
    v433 = (*qfn2(fn))(qenv(fn), stack[0], v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    fn = elt(env, 5); /* addsq */
    v433 = (*qfn2(fn))(qenv(fn), stack[-1], v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v140 = v433;
    goto v435;

v435:
    v433 = stack[-4];
    v433 = cons(v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    stack[-4] = v433;
    v433 = stack[-3];
    v433 = qcdr(v433);
    stack[-3] = v433;
    goto v385;

v166:
    v433 = stack[-3];
    v140 = qcar(v433);
    v433 = stack[-2];
    fn = elt(env, 6); /* partdft */
    v433 = (*qfn2(fn))(qenv(fn), v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v140 = v433;
    goto v435;

v169:
    v140 = qvalue(elt(env, 2)); /* nil */
    v433 = (Lisp_Object)17; /* 1 */
    v433 = cons(v140, v433);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v140 = v433;
    goto v151;

v151:
    v433 = stack[-4];
    if (v433 == nil) { popv(6); return onevalue(v140); }
    v433 = stack[-4];
    v433 = qcar(v433);
    fn = elt(env, 5); /* addsq */
    v433 = (*qfn2(fn))(qenv(fn), v433, v140);
    nil = C_nil;
    if (exception_pending()) goto v441;
    env = stack[-5];
    v140 = v433;
    v433 = stack[-4];
    v433 = qcdr(v433);
    stack[-4] = v433;
    goto v151;
/* error exit handlers */
v441:
    popv(6);
    return nil;
}



/* Code for delength */

static Lisp_Object CC_delength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v345, v448, v171;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delength");
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
    v448 = v0;
/* end of prologue */
    v345 = v448;
    v345 = Lconsp(nil, v345);
    env = stack[-2];
    if (v345 == nil) goto v165;
    v345 = v448;
    v171 = qcar(v345);
    v345 = elt(env, 1); /* plus */
    if (v171 == v345) goto v106;
    v345 = v448;
    v171 = qcar(v345);
    v345 = elt(env, 2); /* times */
    if (v171 == v345) goto v106;
    v345 = v448;
    v171 = qcar(v345);
    v345 = elt(env, 3); /* quotient */
    if (v171 == v345) goto v106;
    v345 = v448;
    v171 = qcar(v345);
    v345 = elt(env, 4); /* minus */
    if (v171 == v345) goto v106;
    v345 = v448;
    v171 = qcar(v345);
    v345 = elt(env, 5); /* equal */
    if (v171 == v345) goto v106;
    v345 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v345); }

v106:
    v345 = v448;
    v345 = qcdr(v345);
    stack[-1] = v345;
    v345 = (Lisp_Object)1; /* 0 */
    stack[0] = v345;
    goto v145;

v145:
    v345 = stack[-1];
    if (v345 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v345 = stack[-1];
    v345 = qcar(v345);
    v448 = CC_delength(env, v345);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-2];
    v345 = stack[0];
    v345 = plus2(v448, v345);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-2];
    stack[0] = v345;
    v345 = stack[-1];
    v345 = qcdr(v345);
    stack[-1] = v345;
    goto v145;

v165:
    v345 = v448;
    if (v345 == nil) goto v101;
    v345 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v345); }

v101:
    v345 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v345); }
/* error exit handlers */
v180:
    popv(3);
    return nil;
}



/* Code for all_defined_map_ */

static Lisp_Object CC_all_defined_map_(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v143, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined_map_");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v101 = v1;
    v143 = v0;
/* end of prologue */
    v112 = v143;
    v143 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_map_ */
        return (*qfnn(fn))(qenv(fn), 3, v112, v143, v101);
    }
}



/* Code for simpdfp */

static Lisp_Object CC_simpdfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v463, v464, v465, v318;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdfp");
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
    stack[0] = v0;
/* end of prologue */
    v92 = stack[0];
    v463 = Llength(nil, v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v92 = (Lisp_Object)33; /* 2 */
    v92 = (Lisp_Object)lessp2(v463, v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    v92 = v92 ? lisp_true : nil;
    env = stack[-6];
    if (v92 == nil) goto v102;
    v463 = elt(env, 2); /* dfp */
    v92 = stack[0];
    v463 = cons(v463, v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v92 = elt(env, 11); /* "generic differential" */
    fn = elt(env, 12); /* typerr */
    v92 = (*qfn2(fn))(qenv(fn), v463, v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    v92 = nil;
    { popv(7); return onevalue(v92); }

v102:
    v92 = stack[0];
    v92 = qcar(v92);
    fn = elt(env, 13); /* reval */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    stack[-5] = v92;
    v92 = stack[-5];
    v92 = Lconsp(nil, v92);
    env = stack[-6];
    if (v92 == nil) goto v162;
    v92 = stack[-5];
    v92 = qcar(v92);
    stack[-1] = v92;
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    fn = elt(env, 13); /* reval */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v318 = v92;
    v463 = v318;
    v92 = qvalue(elt(env, 1)); /* frlis!* */
    v92 = Lmember(nil, v463, v92);
    if (!(v92 == nil)) goto v85;
    v463 = v318;
    v92 = elt(env, 3); /* list */
    if (!consp(v463)) goto v155;
    v463 = qcar(v463);
    if (!(v463 == v92)) goto v155;

v85:
    v463 = stack[-1];
    v92 = elt(env, 5); /* generic_function */
    v92 = get(v463, v92);
    env = stack[-6];
    v465 = v92;
    v92 = qvalue(elt(env, 6)); /* t */
    v463 = v465;
    if (v463 == nil) goto v44;
    v464 = v318;
    v463 = elt(env, 3); /* list */
    if (!consp(v464)) goto v44;
    v464 = qcar(v464);
    if (!(v464 == v463)) goto v44;
    v463 = v318;
    v463 = qcdr(v463);
    v464 = v463;
    goto v338;

v338:
    v463 = v464;
    if (v463 == nil) goto v44;
    v463 = v464;
    v463 = qcar(v463);
    if (v92 == nil) goto v467;
    v92 = v465;
    v92 = Lmember(nil, v463, v92);
    goto v158;

v158:
    v463 = v464;
    v463 = qcdr(v463);
    v464 = v463;
    goto v338;

v467:
    v92 = qvalue(elt(env, 4)); /* nil */
    goto v158;

v44:
    if (v92 == nil) goto v414;
    v463 = v318;
    v92 = elt(env, 7); /* (list) */
    if (equal(v463, v92)) goto v16;
    v92 = v465;
    if (v92 == nil) goto v93;
    v463 = stack[-1];
    v92 = elt(env, 8); /* dfp_commute */
    v92 = Lflagp(nil, v463, v92);
    env = stack[-6];
    if (v92 == nil) goto v93;
    v92 = v465;
    stack[-1] = qvalue(elt(env, 9)); /* kord!* */
    qvalue(elt(env, 9)) = v92; /* kord!* */
    stack[0] = elt(env, 3); /* list */
    v92 = v318;
    v463 = qcdr(v92);
    v92 = elt(env, 10); /* ordp */
    fn = elt(env, 14); /* sort */
    v92 = (*qfn2(fn))(qenv(fn), v463, v92);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v92 = cons(stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v318 = v92;
    qvalue(elt(env, 9)) = stack[-1]; /* kord!* */
    goto v93;

v93:
    v463 = elt(env, 2); /* dfp */
    v92 = stack[-5];
    v464 = v318;
    v92 = list3(v463, v92, v464);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    stack[0] = v92;
    v463 = stack[0];
    v92 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 15); /* mksq */
        return (*qfn2(fn))(qenv(fn), v463, v92);
    }

v16:
    v463 = stack[-5];
    v92 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 15); /* mksq */
        return (*qfn2(fn))(qenv(fn), v463, v92);
    }

v414:
    v463 = qvalue(elt(env, 4)); /* nil */
    v92 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v463, v92);

v155:
    stack[-4] = v318;
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcdr(v92);
    stack[-3] = v92;
    v92 = stack[-3];
    if (v92 == nil) goto v154;
    v92 = stack[-3];
    v92 = qcar(v92);
    fn = elt(env, 13); /* reval */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    stack[-1] = v92;
    stack[-2] = v92;
    goto v334;

v334:
    v92 = stack[-3];
    v92 = qcdr(v92);
    stack[-3] = v92;
    v92 = stack[-3];
    if (v92 == nil) goto v402;
    stack[0] = stack[-1];
    v92 = stack[-3];
    v92 = qcar(v92);
    fn = elt(env, 13); /* reval */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v92 = ncons(v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v92 = Lrplacd(nil, stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v92 = stack[-1];
    v92 = qcdr(v92);
    stack[-1] = v92;
    goto v334;

v402:
    v92 = stack[-2];
    goto v168;

v168:
    v92 = cons(stack[-4], v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v318 = v92;
    stack[0] = elt(env, 3); /* list */
    v463 = v318;
    v92 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* dfp!-normalize */
    v92 = (*qfn2(fn))(qenv(fn), v463, v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v92 = cons(stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v318 = v92;
    v463 = elt(env, 2); /* dfp */
    v92 = stack[-5];
    v464 = v318;
    v92 = list3(v463, v92, v464);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 17); /* simp */
        return (*qfn1(fn))(qenv(fn), v92);
    }

v154:
    v92 = qvalue(elt(env, 4)); /* nil */
    goto v168;

v162:
    v92 = stack[0];
    v92 = qcdr(v92);
    v463 = qcar(v92);
    v92 = qvalue(elt(env, 1)); /* frlis!* */
    v92 = Lmember(nil, v463, v92);
    if (v92 == nil) goto v388;
    v463 = elt(env, 2); /* dfp */
    v92 = stack[0];
    v463 = cons(v463, v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    v92 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 15); /* mksq */
        return (*qfn2(fn))(qenv(fn), v463, v92);
    }

v388:
    v463 = stack[-5];
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    v92 = qcdr(v92);
    v92 = cons(v463, v92);
    nil = C_nil;
    if (exception_pending()) goto v466;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 18); /* simpdf */
        return (*qfn1(fn))(qenv(fn), v92);
    }
/* error exit handlers */
v406:
    env = stack[-6];
    qvalue(elt(env, 9)) = stack[-1]; /* kord!* */
    popv(7);
    return nil;
v466:
    popv(7);
    return nil;
}



setup_type const u52_setup[] =
{
    {"quotfx1",                 too_few_2,      CC_quotfx1,    wrong_no_2},
    {"ps:plus-erule",           too_few_2,      CC_psTplusKerule,wrong_no_2},
    {"arprep:",                 CC_arprepT,     too_many_1,    wrong_no_1},
    {"fast_augment_columns",    too_few_2,      CC_fast_augment_columns,wrong_no_2},
    {"mkuniquewedge1",          CC_mkuniquewedge1,too_many_1,  wrong_no_1},
    {"deflate1c",               too_few_2,      CC_deflate1c,  wrong_no_2},
    {"sin:",                    too_few_2,      CC_sinT,       wrong_no_2},
    {"lispstmtp",               CC_lispstmtp,   too_many_1,    wrong_no_1},
    {"calc_map_tar",            too_few_2,      CC_calc_map_tar,wrong_no_2},
    {"fs:onep",                 CC_fsTonep,     too_many_1,    wrong_no_1},
    {"partsym_zerop",           too_few_2,      CC_partsym_zerop,wrong_no_2},
    {"bdstest",                 CC_bdstest,     too_many_1,    wrong_no_1},
    {"insertglue",              CC_insertglue,  too_many_1,    wrong_no_1},
    {"canprod",                 too_few_2,      CC_canprod,    wrong_no_2},
    {"delqip",                  too_few_2,      CC_delqip,     wrong_no_2},
    {"spmultsm",                too_few_2,      CC_spmultsm,   wrong_no_2},
    {"improvelayout",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_improvelayout},
    {"poly-remainder",          CC_polyKremainder,too_many_1,  wrong_no_1},
    {"evalsetbool",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_evalsetbool},
    {"partdff",                 too_few_2,      CC_partdff,    wrong_no_2},
    {"delength",                CC_delength,    too_many_1,    wrong_no_1},
    {"all_defined_map_",        too_few_2,      CC_all_defined_map_,wrong_no_2},
    {"simpdfp",                 CC_simpdfp,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u52", (two_args *)"22315 3659185 9169944", 0}
};

/* end of generated code */
