
/* $destdir\u19.c        Machine generated C code */

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


/* Code for ibalp_renewwl */

static Lisp_Object CC_ibalp_renewwl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_renewwl");
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
    v38 = v0;
/* end of prologue */
    stack[-2] = v38;
    goto v40;

v40:
    v38 = stack[-2];
    if (v38 == nil) goto v41;
    v38 = stack[-2];
    v38 = qcar(v38);
    stack[-1] = v38;
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    if (!(v38 == nil)) goto v42;
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v39 = Llength(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v38 = (Lisp_Object)17; /* 1 */
    v38 = Leqn(nil, v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    if (v38 == nil) goto v44;
    v38 = stack[-1];
    v38 = qcar(v38);
    stack[0] = Llength(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v38 = Llength(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v39 = plus2(stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v38 = (Lisp_Object)17; /* 1 */
    v38 = (Lisp_Object)greaterp2(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v38 = v38 ? lisp_true : nil;
    env = stack[-4];
    if (v38 == nil) goto v44;
    v38 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    stack[-3] = v38;
    v38 = stack[-3];
    if (v38 == nil) goto v42;
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    stack[0] = qcdr(v38);
    v39 = stack[-3];
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v38 = cons(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v38 = stack[-3];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    stack[0] = qcdr(v38);
    v39 = stack[-1];
    v38 = stack[-3];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v38 = cons(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    goto v42;

v42:
    v38 = stack[-2];
    v38 = qcdr(v38);
    stack[-2] = v38;
    goto v40;

v44:
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    if (!(v38 == nil)) goto v42;
    v38 = stack[-1];
    v38 = qcar(v38);
    stack[0] = Llength(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v38 = Llength(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v39 = plus2(stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v38 = (Lisp_Object)17; /* 1 */
    v38 = (Lisp_Object)greaterp2(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v38 = v38 ? lisp_true : nil;
    env = stack[-4];
    if (v38 == nil) goto v42;
    v38 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    stack[-3] = v38;
    v38 = stack[-3];
    if (v38 == nil) goto v45;
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    stack[0] = qcdr(v38);
    v39 = stack[-3];
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v38 = cons(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v38 = stack[-3];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    stack[0] = qcdr(v38);
    v39 = stack[-1];
    v38 = stack[-3];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v38 = cons(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    goto v45;

v45:
    v38 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    stack[-3] = v38;
    v38 = stack[-3];
    if (v38 == nil) goto v42;
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    stack[0] = qcdr(v38);
    v39 = stack[-3];
    v38 = stack[-1];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v38 = cons(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    v38 = stack[-3];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    stack[0] = qcdr(v38);
    v39 = stack[-1];
    v38 = stack[-3];
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    v38 = qcar(v38);
    v38 = cons(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v38 = (*qfn2(fn))(qenv(fn), stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-4];
    goto v42;

v41:
    v38 = nil;
    { popv(5); return onevalue(v38); }
/* error exit handlers */
v43:
    popv(5);
    return nil;
}



/* Code for ev_lexcomp */

static Lisp_Object CC_ev_lexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_lexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */

v37:
    v51 = stack[-1];
    if (v51 == nil) goto v40;
    v51 = stack[-1];
    v52 = qcar(v51);
    v51 = stack[0];
    v51 = qcar(v51);
    v51 = Leqn(nil, v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    if (v51 == nil) goto v54;
    v51 = stack[-1];
    v51 = qcdr(v51);
    stack[-1] = v51;
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[0] = v51;
    goto v37;

v54:
    v51 = stack[-1];
    v52 = qcar(v51);
    v51 = stack[0];
    v51 = qcar(v51);
    if (((int32_t)(v52)) > ((int32_t)(v51))) goto v55;
    v51 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v51); }

v55:
    v51 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v51); }

v40:
    v51 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for getsetvars */

static Lisp_Object CC_getsetvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getsetvars");
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
    goto v37;

v37:
    v61 = stack[0];
    if (!consp(v61)) goto v40;
    v61 = stack[0];
    v62 = qcar(v61);
    v61 = elt(env, 1); /* (setel setk) */
    v61 = Lmemq(nil, v62, v61);
    if (v61 == nil) goto v63;
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = qcar(v61);
    fn = elt(env, 3); /* getsetvarlis */
    v62 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v61 = stack[-1];
    v61 = cons(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[-1] = v61;
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = qcar(v61);
    stack[0] = v61;
    goto v37;

v63:
    v61 = stack[0];
    v62 = qcar(v61);
    v61 = elt(env, 2); /* setq */
    if (v62 == v61) goto v65;
    v61 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v61);
    }

v65:
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = qcar(v61);
    v62 = Lmkquote(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v61 = stack[-1];
    v61 = cons(v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[-1] = v61;
    v61 = stack[0];
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = qcar(v61);
    stack[0] = v61;
    goto v37;

v40:
    v61 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v61);
    }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for nextcomb */

static Lisp_Object CC_nextcomb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextcomb");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    v86 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v85 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v85; /* i */
    v85 = v86;
    v85 = qcar(v85);
    stack[-3] = v85;
    v85 = v86;
    v85 = qcdr(v85);
    stack[-1] = v85;
    v86 = stack[0];
    v85 = (Lisp_Object)1; /* 0 */
    if (v86 == v85) goto v87;
    v85 = stack[-3];
    v86 = Llength(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v85 = stack[0];
    v86 = difference2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    qvalue(elt(env, 1)) = v86; /* i */
    v85 = (Lisp_Object)1; /* 0 */
    v85 = (Lisp_Object)lessp2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v85 = v85 ? lisp_true : nil;
    env = stack[-4];
    if (v85 == nil) goto v36;
    v85 = qvalue(elt(env, 2)); /* nil */
    v85 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v40;

v40:
    qvalue(elt(env, 1)) = stack[-2]; /* i */
    { popv(5); return onevalue(v85); }

v36:
    v86 = qvalue(elt(env, 1)); /* i */
    v85 = (Lisp_Object)1; /* 0 */
    if (v86 == v85) goto v53;
    v85 = stack[-1];
    if (v85 == nil) goto v30;
    v85 = stack[0];
    v85 = sub1(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v85 = CC_nextcomb(env, stack[-1], v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v86 = stack[-3];
    stack[-1] = qcar(v86);
    v86 = v85;
    stack[0] = qcar(v86);
    v86 = v85;
    v86 = qcdr(v86);
    if (v86 == nil) goto v29;
    v86 = stack[-3];
    v85 = qcdr(v85);
    v85 = cons(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v89;

v89:
    v85 = acons(stack[-1], stack[0], v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v40;

v29:
    v85 = stack[-3];
    v85 = qcdr(v85);
    v85 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v89;

v30:
    v85 = stack[-3];
    v85 = qcdr(v85);
    fn = elt(env, 3); /* initcomb */
    stack[-1] = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v85 = stack[0];
    v85 = sub1(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v85 = CC_nextcomb(env, stack[-1], v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v86 = stack[-3];
    stack[-1] = qcar(v86);
    v86 = v85;
    stack[0] = qcar(v86);
    v86 = v85;
    v86 = qcdr(v86);
    if (v86 == nil) goto v90;
    v86 = stack[-3];
    v85 = qcdr(v85);
    v85 = cons(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v91;

v91:
    v85 = acons(stack[-1], stack[0], v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v40;

v90:
    v85 = stack[-3];
    v85 = qcdr(v85);
    v85 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v91;

v53:
    v85 = stack[-3];
    v85 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v40;

v87:
    v85 = qvalue(elt(env, 2)); /* nil */
    v85 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    goto v40;
/* error exit handlers */
v88:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-2]; /* i */
    popv(5);
    return nil;
}



/* Code for setdmode */

static Lisp_Object CC_setdmode(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdmode");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */
    v110 = stack[-1];
    v109 = elt(env, 1); /* dname */
    v109 = get(v110, v109);
    env = stack[-3];
    stack[-2] = v109;
    if (v109 == nil) goto v50;
    v109 = stack[-2];
    stack[-1] = v109;
    goto v50;

v50:
    v110 = stack[-1];
    v109 = elt(env, 2); /* complex!-rational */
    if (v110 == v109) goto v49;
    v110 = stack[-1];
    v109 = elt(env, 6); /* complex!-rounded */
    if (v110 == v109) goto v112;
    v110 = stack[-1];
    v109 = elt(env, 8); /* tag */
    v109 = get(v110, v109);
    env = stack[-3];
    if (!(v109 == nil)) goto v72;
    v111 = elt(env, 9); /* "Domain mode error:" */
    v110 = stack[-1];
    v109 = elt(env, 10); /* "is not a domain mode" */
    v109 = list3(v111, v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v110 = v109;
    v109 = v110;
    qvalue(elt(env, 11)) = v109; /* errmsg!* */
    v109 = qvalue(elt(env, 12)); /* !*protfg */
    if (!(v109 == nil)) goto v69;
    v109 = v110;
    fn = elt(env, 15); /* lprie */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    goto v69;

v69:
    v109 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    goto v72;

v72:
    v110 = stack[-1];
    v109 = elt(env, 13); /* package!-name */
    v109 = get(v110, v109);
    env = stack[-3];
    stack[-2] = v109;
    if (v109 == nil) goto v88;
    v109 = stack[-2];
    fn = elt(env, 16); /* load!-package */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    goto v88;

v88:
    v110 = stack[-1];
    v109 = elt(env, 4); /* complex */
    if (v110 == v109) goto v114;
    v109 = qvalue(elt(env, 14)); /* !*complex */
    if (!(v109 == nil)) goto v114;
    v110 = stack[-1];
    v109 = stack[0];
    {
        popv(4);
        fn = elt(env, 17); /* setdmode1 */
        return (*qfn2(fn))(qenv(fn), v110, v109);
    }

v114:
    v110 = stack[-1];
    v109 = stack[0];
    {
        popv(4);
        fn = elt(env, 18); /* setcmpxmode */
        return (*qfn2(fn))(qenv(fn), v110, v109);
    }

v112:
    v109 = qvalue(elt(env, 3)); /* dmode!* */
    stack[-2] = v109;
    if (v109 == nil) goto v115;
    v110 = stack[-2];
    v109 = elt(env, 1); /* dname */
    v109 = get(v110, v109);
    env = stack[-3];
    stack[-2] = v109;
    goto v115;

v115:
    v110 = elt(env, 4); /* complex */
    v109 = stack[0];
    fn = elt(env, 19); /* onoff */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v110 = elt(env, 7); /* rounded */
    v109 = stack[0];
    fn = elt(env, 19); /* onoff */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v49:
    v109 = qvalue(elt(env, 3)); /* dmode!* */
    stack[-2] = v109;
    if (v109 == nil) goto v52;
    v110 = stack[-2];
    v109 = elt(env, 1); /* dname */
    v109 = get(v110, v109);
    env = stack[-3];
    stack[-2] = v109;
    goto v52;

v52:
    v110 = elt(env, 4); /* complex */
    v109 = stack[0];
    fn = elt(env, 19); /* onoff */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v110 = elt(env, 5); /* rational */
    v109 = stack[0];
    fn = elt(env, 19); /* onoff */
    v109 = (*qfn2(fn))(qenv(fn), v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v113:
    popv(4);
    return nil;
}



/* Code for groebcplistsortin */

static Lisp_Object CC_groebcplistsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsortin");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    v60 = v0;
/* end of prologue */
    v49 = stack[0];
    if (v49 == nil) goto v37;
    v49 = stack[0];
    fn = elt(env, 1); /* groebcplistsortin1 */
    v49 = (*qfn2(fn))(qenv(fn), v60, v49);
    nil = C_nil;
    if (exception_pending()) goto v84;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v37:
    v49 = v60;
    popv(1);
    return ncons(v49);
/* error exit handlers */
v84:
    popv(1);
    return nil;
}



/* Code for rd!:times */

static Lisp_Object CC_rdTtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v134, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:times");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */
    v133 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (!(v133 == nil)) goto v51;
    v133 = stack[-1];
    v133 = qcdr(v133);
    if (!(!consp(v133))) goto v51;
    v133 = stack[0];
    v133 = qcdr(v133);
    if (!(!consp(v133))) goto v51;
    v133 = stack[-1];
    v134 = qcdr(v133);
    v133 = stack[0];
    v133 = qcdr(v133);
    fn = elt(env, 7); /* safe!-fp!-times */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = v133;
    if (v133 == nil) goto v51;
    v133 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v133, v134);

v51:
    v134 = stack[-1];
    v133 = stack[0];
    fn = elt(env, 8); /* convprc2 */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[-3] = v133;
    v133 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v133;
    v133 = stack[-3];
    if (!consp(v133)) goto v137;
    v134 = stack[-3];
    v133 = stack[-2];
    fn = elt(env, 9); /* csl_timbf */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v138;

v138:
    v134 = v133;
    v133 = v134;
    if (!(!consp(v133))) { popv(5); return onevalue(v134); }
    v133 = elt(env, 3); /* !:rd!: */
    popv(5);
    return cons(v133, v134);

v137:
    stack[-1] = elt(env, 5); /* times2 */
    v133 = stack[-3];
    stack[0] = Lmkquote(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v133 = stack[-2];
    v133 = Lmkquote(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v135 = list3(stack[-1], stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = qvalue(elt(env, 1)); /* nil */
    v133 = qvalue(elt(env, 6)); /* !*backtrace */
    fn = elt(env, 10); /* errorset */
    v133 = (*qfnn(fn))(qenv(fn), 3, v135, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v134 = v133;
    v133 = v134;
    if (!consp(v133)) goto v28;
    v133 = v134;
    v133 = qcdr(v133);
    if (!(v133 == nil)) goto v28;
    v133 = v134;
    v133 = qcar(v133);
    goto v138;

v28:
    fn = elt(env, 11); /* rndbfon */
    v133 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    v133 = stack[-3];
    v133 = Lfloatp(nil, v133);
    env = stack[-4];
    if (v133 == nil) goto v74;
    v133 = stack[-3];
    fn = elt(env, 12); /* fl2bf */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[0] = v133;
    goto v139;

v139:
    v133 = stack[-2];
    v133 = Lfloatp(nil, v133);
    env = stack[-4];
    if (v133 == nil) goto v140;
    v133 = stack[-2];
    fn = elt(env, 12); /* fl2bf */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v141;

v141:
    fn = elt(env, 9); /* csl_timbf */
    v133 = (*qfn2(fn))(qenv(fn), stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v138;

v140:
    v133 = stack[-2];
    if (!consp(v133)) goto v142;
    v133 = stack[-2];
    goto v88;

v88:
    fn = elt(env, 13); /* csl_normbf */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v141;

v142:
    v133 = stack[-2];
    v133 = integerp(v133);
    if (v133 == nil) goto v143;
    v135 = elt(env, 3); /* !:rd!: */
    v134 = stack[-2];
    v133 = (Lisp_Object)1; /* 0 */
    v133 = list2star(v135, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v88;

v143:
    v133 = stack[-2];
    fn = elt(env, 14); /* read!:num */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v88;

v74:
    v133 = stack[-3];
    if (!consp(v133)) goto v100;
    v133 = stack[-3];
    goto v144;

v144:
    fn = elt(env, 13); /* csl_normbf */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    stack[0] = v133;
    goto v139;

v100:
    v133 = stack[-3];
    v133 = integerp(v133);
    if (v133 == nil) goto v145;
    v135 = elt(env, 3); /* !:rd!: */
    v134 = stack[-3];
    v133 = (Lisp_Object)1; /* 0 */
    v133 = list2star(v135, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v144;

v145:
    v133 = stack[-3];
    fn = elt(env, 14); /* read!:num */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-4];
    goto v144;
/* error exit handlers */
v136:
    popv(5);
    return nil;
}



/* Code for fortranname */

static Lisp_Object CC_fortranname(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortranname");
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
    v62 = stack[0];
    v62 = Lstringp(nil, v62);
    env = stack[-1];
    if (v62 == nil) goto v87;
    v62 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* stringtoatom */
        return (*qfn1(fn))(qenv(fn), v62);
    }

v87:
    v32 = stack[0];
    v62 = qvalue(elt(env, 1)); /* !*notfortranfuns!* */
    v62 = Lmemq(nil, v32, v62);
    if (v62 == nil) goto v147;
    v62 = qvalue(elt(env, 2)); /* !*stdout!* */
    v62 = qcdr(v62);
    v62 = Lwrs(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v62 = elt(env, 3); /* "*** WARNING: " */
    v62 = Lprinc(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v62 = stack[0];
    v62 = Lprin(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v62 = elt(env, 4); /* " is not an intrinsic Fortran function" */
    v62 = Lprinc(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v62 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    goto v147;

v147:
    v62 = qvalue(elt(env, 6)); /* !*double */
    if (v62 == nil) goto v148;
    v32 = stack[0];
    v62 = elt(env, 7); /* !*doublename!* */
    v62 = get(v32, v62);
    if (v62 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v62); }

v148:
    v32 = stack[0];
    v62 = elt(env, 8); /* !*fortranname!* */
    v62 = get(v32, v62);
    if (v62 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v62); }
/* error exit handlers */
v64:
    popv(2);
    return nil;
}



/* Code for powers3 */

static Lisp_Object CC_powers3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v118;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers3");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v46;
    v65 = v0;
/* end of prologue */

v66:
    v118 = v65;
    if (!consp(v118)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v118 = v65;
    v118 = qcar(v118);
    if (!consp(v118)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v118 = v65;
    v118 = qcar(v118);
    v118 = qcdr(v118);
    stack[-2] = v118;
    v118 = v65;
    v118 = qcar(v118);
    v118 = qcar(v118);
    stack[0] = qcar(v118);
    v118 = v65;
    v118 = qcar(v118);
    v118 = qcar(v118);
    v118 = qcdr(v118);
    v65 = qcar(v65);
    v65 = qcar(v65);
    v65 = qcdr(v65);
    v118 = cons(v118, v65);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v65 = stack[-1];
    v65 = acons(stack[0], v118, v65);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    stack[-1] = v65;
    v65 = stack[-2];
    goto v66;
/* error exit handlers */
v56:
    popv(4);
    return nil;
}



/* Code for assert_uninstall */

static Lisp_Object CC_assert_uninstall(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall");
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
    v150 = v0;
/* end of prologue */
    v131 = qvalue(elt(env, 1)); /* !*assert */
    if (v131 == nil) goto v37;
    v131 = v150;
    stack[0] = v131;
    goto v151;

v151:
    v131 = stack[0];
    if (v131 == nil) goto v67;
    v131 = stack[0];
    v131 = qcar(v131);
    fn = elt(env, 3); /* assert_uninstall1 */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v131 = stack[0];
    v131 = qcdr(v131);
    stack[0] = v131;
    goto v151;

v67:
    v131 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v131); }

v37:
    v131 = nil;
    { popv(2); return onevalue(v131); }
/* error exit handlers */
v55:
    popv(2);
    return nil;
}



/* Code for repeats */

static Lisp_Object CC_repeats(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v63, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeats");
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
    v106 = nil;
    goto v37;

v37:
    v35 = stack[0];
    if (v35 == nil) goto v40;
    v35 = stack[0];
    v63 = qcar(v35);
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = Lmember(nil, v63, v35);
    if (v35 == nil) goto v48;
    v35 = stack[0];
    v35 = qcar(v35);
    v63 = v106;
    v35 = cons(v35, v63);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    v106 = v35;
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v37;

v48:
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v37;

v40:
    v35 = v106;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v35);
    }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for st_sorttree */

static Lisp_Object MS_CDECL CC_st_sorttree(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v108, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v5;
    v108 = v46;
    v6 = v0;
/* end of prologue */
    fn = elt(env, 1); /* st_sorttree1 */
    v87 = (*qfnn(fn))(qenv(fn), 3, v6, v108, v87);
    errexit();
    v87 = qcdr(v87);
    return onevalue(v87);
}



/* Code for ilcm */

static Lisp_Object CC_ilcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62, v32, v154;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ilcm");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v32 = v46;
    v154 = v0;
/* end of prologue */
    v62 = v154;
    v61 = (Lisp_Object)1; /* 0 */
    if (v62 == v61) goto v37;
    v62 = v32;
    v61 = (Lisp_Object)1; /* 0 */
    if (v62 == v61) goto v37;
    v62 = v154;
    v61 = (Lisp_Object)17; /* 1 */
    if (v62 == v61) { popv(3); return onevalue(v32); }
    v62 = v32;
    v61 = (Lisp_Object)17; /* 1 */
    if (v62 == v61) { popv(3); return onevalue(v154); }
    stack[-1] = v154;
    stack[0] = v32;
    v61 = v154;
    v62 = v32;
    v61 = Lgcd(nil, v61, v62);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v61 = quot2(stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v128;
    {
        Lisp_Object v137 = stack[-1];
        popv(3);
        return times2(v137, v61);
    }

v37:
    v61 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v61); }
/* error exit handlers */
v128:
    popv(3);
    return nil;
}



/* Code for sfto_ucontentf1 */

static Lisp_Object CC_sfto_ucontentf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_ucontentf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v41;

v41:
    v148 = stack[-1];
    if (!consp(v148)) goto v40;
    v148 = stack[-1];
    v148 = qcar(v148);
    if (!consp(v148)) goto v40;
    v148 = stack[-1];
    v148 = qcar(v148);
    v148 = qcar(v148);
    v130 = qcar(v148);
    v148 = stack[0];
    if (!(equal(v130, v148))) goto v40;
    v148 = stack[-1];
    v148 = qcar(v148);
    v130 = qcdr(v148);
    v148 = stack[-2];
    v148 = cons(v130, v148);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[-2] = v148;
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v41;

v40:
    v148 = stack[-1];
    v130 = v148;
    goto v155;

v155:
    v148 = stack[-2];
    if (v148 == nil) { popv(4); return onevalue(v130); }
    v148 = stack[-2];
    v148 = qcar(v148);
    fn = elt(env, 1); /* sfto_gcdf!* */
    v148 = (*qfn2(fn))(qenv(fn), v148, v130);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    v130 = v148;
    v148 = stack[-2];
    v148 = qcdr(v148);
    stack[-2] = v148;
    goto v155;
/* error exit handlers */
v34:
    popv(4);
    return nil;
}



/* Code for simpqg */

static Lisp_Object CC_simpqg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpqg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v151 = v0;
/* end of prologue */
    v156 = v151;
    v151 = elt(env, 1); /* qg */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v156, v151);
    }
}



/* Code for delet */

static Lisp_Object CC_delet(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v80, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delet");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */
    v61 = nil;
    goto v66;

v66:
    v34 = stack[-1];
    if (v34 == nil) goto v147;
    v34 = stack[0];
    if (v34 == nil) goto v42;
    v80 = stack[-1];
    v34 = stack[0];
    if (equal(v80, v34)) goto v42;
    v80 = stack[-1];
    v34 = stack[0];
    v34 = qcar(v34);
    if (equal(v80, v34)) goto v157;
    v34 = stack[0];
    v34 = qcar(v34);
    v80 = v61;
    v34 = cons(v34, v80);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    v61 = v34;
    v34 = stack[0];
    v34 = qcdr(v34);
    stack[0] = v34;
    goto v66;

v157:
    v80 = v61;
    v34 = stack[0];
    v34 = qcdr(v34);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v80, v34);
    }

v42:
    v34 = v61;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v34);
    }

v147:
    v80 = v61;
    v34 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v80, v34);
    }
/* error exit handlers */
v154:
    popv(3);
    return nil;
}



/* Code for ibalp_var!-unsatlist */

static Lisp_Object CC_ibalp_varKunsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-unsatlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v46;
    v33 = v0;
/* end of prologue */
    stack[-3] = v33;
    goto v66;

v66:
    v33 = stack[-3];
    if (v33 == nil) goto v151;
    v33 = stack[-3];
    v33 = qcar(v33);
    stack[-1] = v33;
    v159 = stack[-2];
    v33 = (Lisp_Object)17; /* 1 */
    v33 = Leqn(nil, v159, v33);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    if (v33 == nil) goto v58;
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    stack[0] = qcdr(v33);
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    v33 = qcar(v33);
    v33 = sub1(v33);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    fn = elt(env, 2); /* setcar */
    v33 = (*qfn2(fn))(qenv(fn), stack[0], v33);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    goto v6;

v6:
    v33 = stack[-3];
    v33 = qcdr(v33);
    stack[-3] = v33;
    goto v66;

v58:
    v33 = stack[-1];
    v33 = qcdr(v33);
    stack[0] = qcdr(v33);
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = qcdr(v33);
    v33 = qcar(v33);
    v33 = sub1(v33);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    fn = elt(env, 2); /* setcar */
    v33 = (*qfn2(fn))(qenv(fn), stack[0], v33);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    goto v6;

v151:
    v33 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v33); }
/* error exit handlers */
v62:
    popv(5);
    return nil;
}



/* Code for band_matrix */

static Lisp_Object CC_band_matrix(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for band_matrix");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v46;
    stack[-9] = v0;
/* end of prologue */
    stack[-10] = nil;
    v7 = stack[-8];
    v7 = integerp(v7);
    if (!(v7 == nil)) goto v184;
    v7 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v7 == nil)) goto v50;
    v7 = elt(env, 2); /* "Error in band_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 9); /* lprie */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v50;

v50:
    v7 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v184;

v184:
    v7 = stack[-9];
    if (!consp(v7)) goto v44;
    v7 = stack[-9];
    v8 = qcar(v7);
    v7 = elt(env, 3); /* list */
    if (v8 == v7) goto v186;
    v7 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v7 == nil)) goto v82;
    v7 = elt(env, 4); /* "Error in band_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 9); /* lprie */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v82;

v82:
    v7 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v153;

v153:
    v7 = stack[-9];
    v7 = Llength(nil, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    stack[-7] = v7;
    v7 = stack[-7];
    v7 = Levenp(nil, v7);
    env = stack[-11];
    if (v7 == nil) goto v75;
    v7 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v7 == nil)) goto v64;
    v7 = elt(env, 5); /* "Error in band matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 9); /* lprie */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v64;

v64:
    v7 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v75;

v75:
    stack[0] = elt(env, 6); /* quotient */
    v7 = stack[-7];
    v8 = add1(v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = (Lisp_Object)33; /* 2 */
    v7 = list3(stack[0], v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    fn = elt(env, 10); /* reval */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    stack[-6] = v7;
    v7 = stack[-6];
    v7 = integerp(v7);
    if (v7 == nil) goto v101;
    v7 = stack[-6];
    v8 = v7;
    goto v187;

v187:
    v7 = stack[-8];
    v7 = (Lisp_Object)greaterp2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    v7 = v7 ? lisp_true : nil;
    env = stack[-11];
    if (v7 == nil) goto v69;
    v7 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v7 == nil)) goto v144;
    v7 = elt(env, 7); /* "Error in band_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 9); /* lprie */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v144;

v144:
    v7 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v188;

v188:
    v7 = (Lisp_Object)17; /* 1 */
    stack[-5] = v7;
    goto v98;

v98:
    v8 = stack[-8];
    v7 = stack[-5];
    v7 = difference2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = Lminusp(nil, v7);
    env = stack[-11];
    if (!(v7 == nil)) { Lisp_Object res = stack[-10]; popv(12); return onevalue(res); }
    v7 = (Lisp_Object)17; /* 1 */
    stack[-4] = v7;
    goto v189;

v189:
    v8 = stack[-8];
    v7 = stack[-4];
    v7 = difference2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = Lminusp(nil, v7);
    env = stack[-11];
    if (v7 == nil) goto v190;
    v7 = stack[-5];
    v7 = add1(v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    stack[-5] = v7;
    goto v98;

v190:
    v8 = stack[-6];
    v7 = stack[-5];
    v8 = difference2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = stack[-4];
    v8 = plus2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = (Lisp_Object)1; /* 0 */
    v7 = (Lisp_Object)greaterp2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    v7 = v7 ? lisp_true : nil;
    env = stack[-11];
    if (v7 == nil) goto v143;
    v8 = stack[-6];
    v7 = stack[-5];
    v8 = difference2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = stack[-4];
    v8 = plus2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = stack[-7];
    v7 = (Lisp_Object)lesseq2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    v7 = v7 ? lisp_true : nil;
    env = stack[-11];
    if (v7 == nil) goto v143;
    stack[-3] = stack[-10];
    stack[-2] = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-9];
    v8 = stack[-6];
    v7 = stack[-5];
    v8 = difference2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = stack[-4];
    v7 = plus2(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    fn = elt(env, 11); /* pnth */
    v7 = (*qfn2(fn))(qenv(fn), stack[0], v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v7 = qcar(v7);
    fn = elt(env, 12); /* setmat */
    v7 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[-2], stack[-1], v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    goto v143;

v143:
    v7 = stack[-4];
    v7 = add1(v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    stack[-4] = v7;
    goto v189;

v69:
    v8 = stack[-8];
    v7 = stack[-8];
    fn = elt(env, 13); /* mkmatrix */
    v7 = (*qfn2(fn))(qenv(fn), v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    stack[-10] = v7;
    goto v188;

v101:
    v7 = stack[-6];
    fn = elt(env, 10); /* reval */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    v8 = v7;
    goto v187;

v186:
    v7 = stack[-9];
    v7 = qcdr(v7);
    stack[-9] = v7;
    goto v153;

v44:
    v7 = stack[-9];
    v7 = ncons(v7);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-11];
    stack[-9] = v7;
    goto v153;
/* error exit handlers */
v185:
    popv(12);
    return nil;
}



/* Code for evgradlexcomp */

static Lisp_Object CC_evgradlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evgradlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v46;
    stack[-2] = v0;
/* end of prologue */

v37:
    v76 = stack[-2];
    if (v76 == nil) goto v40;
    v76 = stack[-1];
    if (v76 == nil) goto v152;
    v76 = stack[-2];
    v115 = qcar(v76);
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = Leqn(nil, v115, v76);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    if (v76 == nil) goto v44;
    v76 = stack[-2];
    v76 = qcdr(v76);
    stack[-2] = v76;
    v76 = stack[-1];
    v76 = qcdr(v76);
    stack[-1] = v76;
    goto v37;

v44:
    v76 = stack[-2];
    fn = elt(env, 2); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    v76 = stack[-1];
    fn = elt(env, 2); /* evtdeg */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v76;
    v115 = stack[-3];
    v76 = stack[0];
    v76 = Leqn(nil, v115, v76);
    nil = C_nil;
    if (exception_pending()) goto v102;
    if (v76 == nil) goto v154;
    v76 = stack[-2];
    v115 = qcar(v76);
    v76 = stack[-1];
    v76 = qcar(v76);
    if (((int32_t)(v115)) > ((int32_t)(v76))) goto v82;
    v76 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v76); }

v82:
    v76 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v76); }

v154:
    v115 = stack[-3];
    v76 = stack[0];
    if (((int32_t)(v115)) > ((int32_t)(v76))) goto v62;
    v76 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v76); }

v62:
    v76 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v76); }

v152:
    v76 = elt(env, 1); /* (0) */
    stack[-1] = v76;
    goto v37;

v40:
    v76 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v76); }
/* error exit handlers */
v102:
    popv(5);
    return nil;
}



/* Code for gftimesn */

static Lisp_Object CC_gftimesn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v202, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gftimesn");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v202 = v46;
    v203 = v0;
/* end of prologue */
    v175 = v203;
    v175 = qcar(v175);
    if (!consp(v175)) goto v151;
    v175 = v203;
    v175 = qcar(v175);
    stack[-5] = v175;
    v175 = v203;
    v175 = qcdr(v175);
    stack[-4] = v175;
    v175 = v202;
    v175 = qcar(v175);
    stack[-3] = v175;
    v175 = v202;
    v175 = qcdr(v175);
    stack[-2] = v175;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v175 = stack[-5];
    v175 = qcdr(v175);
    v202 = qcar(v175);
    v175 = stack[-3];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    stack[0] = times2(v202, v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v175 = stack[-5];
    v175 = qcdr(v175);
    v202 = qcdr(v175);
    v175 = stack[-3];
    v175 = qcdr(v175);
    v175 = qcdr(v175);
    v175 = plus2(v202, v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-6] = list2star(stack[-1], stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-1] = elt(env, 1); /* !:rd!: */
    v175 = stack[-4];
    v175 = qcdr(v175);
    v202 = qcar(v175);
    v175 = stack[-2];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    stack[0] = times2(v202, v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v175 = stack[-4];
    v175 = qcdr(v175);
    v202 = qcdr(v175);
    v175 = stack[-2];
    v175 = qcdr(v175);
    v175 = qcdr(v175);
    v175 = plus2(v202, v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v175 = list2star(stack[-1], stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    fn = elt(env, 2); /* difference!: */
    stack[-6] = (*qfn2(fn))(qenv(fn), stack[-6], v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-1] = elt(env, 1); /* !:rd!: */
    v175 = stack[-5];
    v175 = qcdr(v175);
    v202 = qcar(v175);
    v175 = stack[-2];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    stack[0] = times2(v202, v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v175 = stack[-5];
    v175 = qcdr(v175);
    v202 = qcdr(v175);
    v175 = stack[-2];
    v175 = qcdr(v175);
    v175 = qcdr(v175);
    v175 = plus2(v202, v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-2] = list2star(stack[-1], stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-1] = elt(env, 1); /* !:rd!: */
    v175 = stack[-4];
    v175 = qcdr(v175);
    v202 = qcar(v175);
    v175 = stack[-3];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    stack[0] = times2(v202, v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v175 = stack[-4];
    v175 = qcdr(v175);
    v202 = qcdr(v175);
    v175 = stack[-3];
    v175 = qcdr(v175);
    v175 = qcdr(v175);
    v175 = plus2(v202, v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    v175 = list2star(stack[-1], stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    fn = elt(env, 3); /* plus!: */
    v175 = (*qfn2(fn))(qenv(fn), stack[-2], v175);
    nil = C_nil;
    if (exception_pending()) goto v117;
    {
        Lisp_Object v15 = stack[-6];
        popv(8);
        return cons(v15, v175);
    }

v151:
    v175 = v203;
    {
        popv(8);
        fn = elt(env, 4); /* gfftimes */
        return (*qfn2(fn))(qenv(fn), v175, v202);
    }
/* error exit handlers */
v117:
    popv(8);
    return nil;
}



/* Code for lesspcdr */

static Lisp_Object CC_lesspcdr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v67;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lesspcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v147 = v46;
    v67 = v0;
/* end of prologue */
    v67 = qcdr(v67);
    v147 = qcdr(v147);
        return Llessp(nil, v67, v147);
}



/* Code for subla!-q */

static Lisp_Object CC_sublaKq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subla-q");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */
    v95 = stack[-1];
    if (v95 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v95 = stack[0];
    if (v95 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v95 = stack[0];
    if (!consp(v95)) goto v60;
    v95 = stack[0];
    v96 = qcar(v95);
    v95 = elt(env, 1); /* quote */
    if (v96 == v95) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v95 = stack[0];
    v96 = qcar(v95);
    v95 = elt(env, 2); /* go */
    if (v96 == v95) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v96 = stack[0];
    v95 = elt(env, 3); /* lambda */
    if (!consp(v96)) goto v32;
    v96 = qcar(v96);
    if (!(v96 == v95)) goto v32;

v105:
    v95 = stack[0];
    v95 = qcdr(v95);
    if (!consp(v95)) goto v26;
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = qcar(v95);
    stack[-2] = v95;
    goto v197;

v197:
    v95 = stack[-2];
    if (v95 == nil) goto v209;
    v95 = stack[-2];
    v95 = qcar(v95);
    v96 = v95;
    v95 = stack[-1];
    fn = elt(env, 6); /* delasc */
    v95 = (*qfn2(fn))(qenv(fn), v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-3];
    stack[-1] = v95;
    v95 = stack[-2];
    v95 = qcdr(v95);
    stack[-2] = v95;
    goto v197;

v209:
    v96 = stack[-1];
    v95 = stack[0];
    v95 = qcar(v95);
    stack[-2] = CC_sublaKq(env, v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-3];
    v96 = stack[-1];
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = CC_sublaKq(env, v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v114;
    {
        Lisp_Object v189 = stack[-2];
        popv(4);
        return cons(v189, v95);
    }

v26:
    v96 = stack[-1];
    v95 = stack[0];
    v95 = qcar(v95);
    stack[-2] = CC_sublaKq(env, v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-3];
    v96 = stack[-1];
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = CC_sublaKq(env, v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v114;
    {
        Lisp_Object v210 = stack[-2];
        popv(4);
        return cons(v210, v95);
    }

v32:
    v96 = stack[0];
    v95 = elt(env, 4); /* prog */
    if (!consp(v96)) goto v26;
    v96 = qcar(v96);
    if (v96 == v95) goto v105;
    else goto v26;

v60:
    v96 = stack[0];
    v95 = stack[-1];
    v96 = Latsoc(nil, v96, v95);
    v95 = v96;
    if (v96 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v95 = qcdr(v95);
    { popv(4); return onevalue(v95); }
/* error exit handlers */
v114:
    popv(4);
    return nil;
}



/* Code for setk0 */

static Lisp_Object CC_setk0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v74, v209, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setk0");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v46;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* frasc!* */
    qvalue(elt(env, 1)) = nil; /* frasc!* */
    v213 = stack[-1];
    fn = elt(env, 8); /* getrtype */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    stack[-3] = v213;
    if (v213 == nil) goto v151;
    v74 = stack[-3];
    v213 = elt(env, 2); /* setelemfn */
    v213 = get(v74, v213);
    env = stack[-4];
    if (v213 == nil) goto v151;
    v213 = qvalue(elt(env, 3)); /* nil */
    v213 = ncons(v213);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    qvalue(elt(env, 4)) = v213; /* alglist!* */
    v214 = stack[-2];
    v209 = stack[-1];
    v74 = qvalue(elt(env, 3)); /* nil */
    v213 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 9); /* let2 */
    v213 = (*qfnn(fn))(qenv(fn), 4, v214, v209, v74, v213);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    goto v40;

v40:
    v213 = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* frasc!* */
    { popv(5); return onevalue(v213); }

v151:
    v213 = stack[-2];
    if (!consp(v213)) goto v200;
    v213 = stack[-2];
    v213 = qcar(v213);
    if (!(symbolp(v213))) goto v200;
    v213 = stack[-2];
    fn = elt(env, 8); /* getrtype */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    if (!(v213 == nil)) goto v65;
    v213 = stack[-2];
    v74 = qcar(v213);
    v213 = elt(env, 6); /* rtype */
    v213 = get(v74, v213);
    env = stack[-4];
    goto v65;

v65:
    stack[-3] = v213;
    if (v213 == nil) goto v128;
    v74 = stack[-3];
    v213 = elt(env, 2); /* setelemfn */
    v213 = get(v74, v213);
    env = stack[-4];
    stack[-3] = v213;
    if (!(v213 == nil)) goto v120;

v128:
    v213 = stack[-2];
    v74 = qcar(v213);
    v213 = elt(env, 7); /* setkfn */
    v213 = get(v74, v213);
    env = stack[-4];
    stack[-3] = v213;
    if (!(v213 == nil)) goto v120;

v200:
    v214 = stack[-2];
    v209 = stack[-1];
    v74 = qvalue(elt(env, 3)); /* nil */
    v213 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 9); /* let2 */
    v213 = (*qfnn(fn))(qenv(fn), 4, v214, v209, v74, v213);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    goto v40;

v120:
    v213 = qvalue(elt(env, 3)); /* nil */
    v213 = ncons(v213);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    qvalue(elt(env, 4)) = v213; /* alglist!* */
    v209 = stack[-3];
    v74 = stack[-2];
    v213 = stack[-1];
    v213 = Lapply2(nil, 3, v209, v74, v213);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    goto v40;
/* error exit handlers */
v99:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* frasc!* */
    popv(5);
    return nil;
}



/* Code for fs!:times */

static Lisp_Object CC_fsTtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:times");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */
    v58 = stack[-1];
    if (v58 == nil) goto v37;
    v58 = stack[0];
    if (v58 == nil) goto v155;
    v36 = stack[-1];
    v58 = stack[0];
    fn = elt(env, 2); /* fs!:timesterm */
    v58 = (*qfn2(fn))(qenv(fn), v36, v58);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    stack[-2] = v58;
    v36 = stack[-1];
    v58 = (Lisp_Object)49; /* 3 */
    v36 = *(Lisp_Object *)((char *)v36 + (CELL-TAG_VECTOR) + ((int32_t)v58/(16/CELL)));
    v58 = stack[0];
    v58 = CC_fsTtimes(env, v36, v58);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    {
        Lisp_Object v82 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v82, v58);
    }

v155:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v58); }

v37:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v58); }
/* error exit handlers */
v146:
    popv(4);
    return nil;
}



/* Code for evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_evaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v215, v198, v211, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v5;
    stack[-2] = v46;
    stack[-3] = v0;
/* end of prologue */

v66:
    v30 = stack[-3];
    if (!consp(v30)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v30 = stack[-3];
    v30 = qcar(v30);
    if (!consp(v30)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v215 = stack[-1];
    v30 = (Lisp_Object)1; /* 0 */
    if (v215 == v30) goto v108;
    v30 = stack[-2];
    if (v30 == nil) goto v132;
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v215 = qcar(v30);
    v30 = stack[-2];
    if (equal(v215, v30)) goto v157;
    v30 = stack[-3];
    v30 = qcar(v30);
    stack[-4] = qcar(v30);
    v30 = stack[-3];
    v30 = qcar(v30);
    v198 = qcdr(v30);
    v215 = stack[-2];
    v30 = stack[-1];
    stack[0] = CC_evaluateKmodKp(env, 3, v198, v215, v30);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    v30 = stack[-3];
    v198 = qcdr(v30);
    v215 = stack[-2];
    v30 = stack[-1];
    v30 = CC_evaluateKmodKp(env, 3, v198, v215, v30);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-5];
    {
        Lisp_Object v123 = stack[-4];
        Lisp_Object v144 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v123, v144, v30);
    }

v157:
    v30 = stack[-3];
    v30 = qcar(v30);
    v101 = qcdr(v30);
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v211 = qcdr(v30);
    v30 = stack[-3];
    v198 = qcdr(v30);
    v215 = stack[-1];
    v30 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v101, v211, v198, v215, v30);
    }

v132:
    v30 = elt(env, 2); /* "Variable=NIL in EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v30);
    }

v108:
    v30 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v30;
    goto v66;
/* error exit handlers */
v214:
    popv(6);
    return nil;
}



/* Code for delasc */

static Lisp_Object CC_delasc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v183, v53;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delasc");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */
    v53 = nil;
    goto v40;

v40:
    v157 = stack[0];
    if (v157 == nil) goto v41;
    v157 = stack[0];
    v157 = qcar(v157);
    if (!consp(v157)) goto v149;
    v183 = stack[-1];
    v157 = stack[0];
    v157 = qcar(v157);
    v157 = qcar(v157);
    if (!(equal(v183, v157))) goto v149;

v87:
    v157 = stack[0];
    v157 = qcdr(v157);
    stack[0] = v157;
    goto v40;

v149:
    v157 = stack[0];
    v157 = qcar(v157);
    v183 = v53;
    v157 = cons(v157, v183);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    v53 = v157;
    goto v87;

v41:
    v157 = v53;
        popv(3);
        return Lnreverse(nil, v157);
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for get!-denom!-ll */

static Lisp_Object CC_getKdenomKll(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-denom-ll");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v46;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v66;

v66:
    v47 = stack[-2];
    if (v47 == nil) goto v155;
    v47 = stack[-2];
    stack[0] = qcar(v47);
    v47 = stack[-1];
    v47 = qcar(v47);
    fn = elt(env, 1); /* get!-denom!-l */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    fn = elt(env, 2); /* lcmn */
    v120 = (*qfn2(fn))(qenv(fn), stack[0], v47);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    v47 = stack[-3];
    v47 = cons(v120, v47);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-4];
    stack[-3] = v47;
    v47 = stack[-2];
    v47 = qcdr(v47);
    stack[-2] = v47;
    v47 = stack[-1];
    v47 = qcdr(v47);
    stack[-1] = v47;
    goto v66;

v155:
    v47 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v47);
    }
/* error exit handlers */
v52:
    popv(5);
    return nil;
}



/* Code for sfto_sqfpartf */

static Lisp_Object CC_sfto_sqfpartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_sqfpartf");
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
    v57 = stack[-3];
    if (!consp(v57)) goto v40;
    v57 = stack[-3];
    v57 = qcar(v57);
    if (!consp(v57)) goto v40;
    v57 = stack[-3];
    fn = elt(env, 1); /* sfto_ucontentf */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-5];
    stack[0] = v57;
    v112 = stack[-3];
    v57 = stack[0];
    fn = elt(env, 2); /* quotf */
    v57 = (*qfn2(fn))(qenv(fn), v112, v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-5];
    stack[-4] = v57;
    v57 = stack[0];
    stack[-2] = CC_sfto_sqfpartf(env, v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-4];
    v112 = stack[-4];
    v57 = stack[-3];
    v57 = qcar(v57);
    v57 = qcar(v57);
    v57 = qcar(v57);
    fn = elt(env, 3); /* diff */
    v57 = (*qfn2(fn))(qenv(fn), v112, v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-5];
    fn = elt(env, 4); /* sfto_gcdf!* */
    v57 = (*qfn2(fn))(qenv(fn), stack[0], v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-5];
    fn = elt(env, 2); /* quotf */
    v57 = (*qfn2(fn))(qenv(fn), stack[-1], v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-5];
    {
        Lisp_Object v80 = stack[-2];
        popv(6);
        fn = elt(env, 5); /* multf */
        return (*qfn2(fn))(qenv(fn), v80, v57);
    }

v40:
    v57 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v57); }
/* error exit handlers */
v34:
    popv(6);
    return nil;
}



/* Code for pasf_vf */

static Lisp_Object CC_pasf_vf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v216, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_vf");
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
    v216 = v0;
/* end of prologue */
    v217 = v216;
    v187 = elt(env, 1); /* true */
    if (v217 == v187) { popv(1); return onevalue(v216); }
    v217 = v216;
    v187 = elt(env, 2); /* false */
    if (v217 == v187) { popv(1); return onevalue(v216); }
    v187 = v216;
    v187 = qcdr(v187);
    v187 = qcar(v187);
    if (!consp(v187)) goto v66;
    v187 = v216;
    v187 = qcdr(v187);
    v187 = qcar(v187);
    v187 = qcar(v187);
    if (!(!consp(v187))) { popv(1); return onevalue(v216); }

v66:
    v187 = v216;
    v187 = Lconsp(nil, v187);
    env = stack[0];
    if (v187 == nil) goto v218;
    v187 = v216;
    v187 = qcar(v187);
    v187 = Lconsp(nil, v187);
    env = stack[0];
    if (v187 == nil) goto v218;
    v187 = v216;
    v187 = qcar(v187);
    v217 = qcar(v187);
    v187 = elt(env, 3); /* (cong ncong) */
    v187 = Lmemq(nil, v217, v187);
    if (v187 == nil) goto v218;
    v187 = v216;
    v187 = qcar(v187);
    v187 = qcdr(v187);
    if (!consp(v187)) goto v218;
    v187 = v216;
    v187 = qcar(v187);
    v187 = qcdr(v187);
    v187 = qcar(v187);
    if (!consp(v187)) goto v218;
    v187 = v216;
    v187 = qcdr(v187);
    v187 = qcar(v187);
    if (!(v187 == nil)) { popv(1); return onevalue(v216); }
    v187 = elt(env, 2); /* false */
    { popv(1); return onevalue(v187); }

v218:
    v187 = v216;
    v187 = qcar(v187);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    fn = elt(env, 4); /* pasf_evalatp */
    v187 = (*qfn2(fn))(qenv(fn), v187, v216);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[0];
    if (v187 == nil) goto v199;
    v187 = elt(env, 1); /* true */
    { popv(1); return onevalue(v187); }

v199:
    v187 = elt(env, 2); /* false */
    { popv(1); return onevalue(v187); }
/* error exit handlers */
v139:
    popv(1);
    return nil;
}



/* Code for token!-number */

static Lisp_Object CC_tokenKnumber(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v232, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for token-number");
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
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v231 = (Lisp_Object)1; /* 0 */
    stack[-3] = v231;
    v231 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v231; /* ttype!* */
    goto v155;

v155:
    v231 = stack[-1];
    if (!(v231 == nil)) goto v59;
    v232 = stack[-4];
    v231 = elt(env, 2); /* !) */
    if (!(v232 == v231)) goto v59;

v42:
    v231 = stack[-5];
    if (v231 == nil) goto v138;
    v231 = stack[-3];
    v231 = sub1(v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-3] = v231;
    goto v138;

v138:
    fn = elt(env, 23); /* readch1 */
    v232 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-4] = v232;
    v231 = elt(env, 3); /* !. */
    if (v232 == v231) goto v65;
    v231 = stack[-4];
    v231 = Ldigitp(nil, v231);
    env = stack[-6];
    if (!(v231 == nil)) goto v155;
    v232 = stack[-1];
    v231 = elt(env, 8); /* (!0) */
    if (!(equal(v232, v231))) goto v74;
    v232 = stack[-4];
    v231 = elt(env, 9); /* x */
    if (v232 == v231) goto v152;
    v232 = stack[-4];
    v231 = elt(env, 10); /* !X */
    if (!(v232 == v231)) goto v74;

v152:
    v231 = (Lisp_Object)1; /* 0 */
    stack[-1] = v231;
    goto v190;

v190:
    fn = elt(env, 23); /* readch1 */
    v232 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-4] = v232;
    v231 = elt(env, 17); /* hexdigit */
    v231 = get(v232, v231);
    env = stack[-6];
    stack[0] = v231;
    if (v231 == nil) goto v87;
    v232 = (Lisp_Object)257; /* 16 */
    v231 = stack[-1];
    v232 = times2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    v231 = stack[0];
    v231 = plus2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-1] = v231;
    goto v190;

v87:
    v231 = stack[-5];
    if (v231 == nil) goto v235;
    v233 = elt(env, 18); /* !:dn!: */
    v232 = stack[-1];
    v231 = stack[-3];
    v231 = list2star(v233, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    goto v236;

v236:
    qvalue(elt(env, 21)) = v231; /* nxtsym!* */
    v231 = stack[-4];
    qvalue(elt(env, 22)) = v231; /* crchar!* */
    v231 = qvalue(elt(env, 21)); /* nxtsym!* */
    { popv(7); return onevalue(v231); }

v235:
    v231 = qvalue(elt(env, 19)); /* !*adjprec */
    if (v231 == nil) goto v237;
    v233 = elt(env, 20); /* !:int!: */
    v232 = stack[-1];
    v231 = qvalue(elt(env, 16)); /* nil */
    v231 = list2star(v233, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    goto v236;

v237:
    v231 = stack[-1];
    goto v236;

v74:
    v232 = stack[-4];
    v231 = elt(env, 11); /* !\ */
    if (v232 == v231) goto v192;
    v232 = stack[-4];
    v231 = elt(env, 12); /* e */
    if (v232 == v231) goto v36;
    v232 = stack[-4];
    v231 = elt(env, 13); /* !E */
    if (!(v232 == v231)) goto v184;

v36:
    v231 = qvalue(elt(env, 7)); /* t */
    stack[-5] = v231;
    fn = elt(env, 23); /* readch1 */
    v232 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-4] = v232;
    v231 = elt(env, 14); /* !- */
    if (v232 == v231) goto v90;
    v232 = stack[-4];
    v231 = elt(env, 15); /* !+ */
    if (v232 == v231) goto v156;
    v231 = stack[-4];
    v231 = Ldigitp(nil, v231);
    env = stack[-6];
    if (v231 == nil) goto v184;
    v231 = stack[-4];
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[0] = v231;
    goto v156;

v156:
    fn = elt(env, 23); /* readch1 */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-4] = v231;
    v231 = Ldigitp(nil, v231);
    env = stack[-6];
    if (v231 == nil) goto v67;
    v232 = stack[-4];
    v231 = stack[0];
    v231 = cons(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[0] = v231;
    goto v156;

v67:
    v231 = stack[0];
    if (!(v231 == nil)) goto v238;
    v231 = elt(env, 4); /* "Syntax error: improper number" */
    v232 = v231;
    v231 = v232;
    qvalue(elt(env, 5)) = v231; /* errmsg!* */
    v231 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v231 == nil)) goto v239;
    v231 = v232;
    fn = elt(env, 24); /* lprie */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    goto v239;

v239:
    v231 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    goto v238;

v238:
    v231 = stack[0];
    v231 = Lnreverse(nil, v231);
    env = stack[-6];
    v231 = Lcompress(nil, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[0] = v231;
    v231 = stack[-2];
    if (v231 == nil) goto v240;
    v232 = stack[-3];
    v231 = stack[0];
    v231 = difference2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-3] = v231;
    goto v184;

v184:
    v231 = stack[-1];
    v231 = Lnreverse(nil, v231);
    env = stack[-6];
    v231 = Lcompress(nil, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-1] = v231;
    goto v87;

v240:
    v232 = stack[-3];
    v231 = stack[0];
    v231 = plus2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-3] = v231;
    goto v184;

v90:
    v231 = qvalue(elt(env, 7)); /* t */
    stack[-2] = v231;
    goto v156;

v192:
    v231 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    goto v138;

v65:
    v231 = stack[-5];
    if (v231 == nil) goto v191;
    v231 = elt(env, 4); /* "Syntax error: improper number" */
    v232 = v231;
    v231 = v232;
    qvalue(elt(env, 5)) = v231; /* errmsg!* */
    v231 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v231 == nil)) goto v32;
    v231 = v232;
    fn = elt(env, 24); /* lprie */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    goto v32;

v32:
    v231 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    goto v36;

v191:
    v231 = qvalue(elt(env, 7)); /* t */
    stack[-5] = v231;
    goto v138;

v59:
    v232 = stack[-4];
    v231 = stack[-1];
    v231 = cons(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-6];
    stack[-1] = v231;
    goto v42;
/* error exit handlers */
v234:
    popv(7);
    return nil;
}



/* Code for poly!-minusp */

static Lisp_Object CC_polyKminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v131 = v0;
/* end of prologue */

v81:
    v150 = v131;
    if (v150 == nil) goto v41;
    v150 = v131;
    if (!consp(v150)) goto v156;
    v150 = v131;
    v150 = qcar(v150);
    if (!consp(v150)) goto v156;
    v131 = qcar(v131);
    v131 = qcdr(v131);
    goto v81;

v156:
        return Lminusp(nil, v131);

v41:
    v131 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v131);
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **a2s");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v78 = v46;
    stack[-3] = v0;
/* end of prologue */
    v78 = stack[-3];
    if (v78 == nil) goto v37;
    v199 = stack[-3];
    v78 = elt(env, 3); /* nochange */
    v78 = Lflagpcar(nil, v199, v78);
    env = stack[-5];
    if (v78 == nil) goto v106;
    v78 = stack[-3];
    v199 = qcar(v78);
    v78 = elt(env, 4); /* getel */
    if (!(v199 == v78)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v106:
    v199 = elt(env, 5); /* random */
    v78 = stack[-3];
    fn = elt(env, 12); /* smember */
    v78 = (*qfn2(fn))(qenv(fn), v199, v78);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    if (v78 == nil) goto v127;
    stack[-4] = elt(env, 6); /* lambda */
    stack[-2] = elt(env, 7); /* (!*uncached) */
    stack[-1] = elt(env, 8); /* progn */
    stack[0] = elt(env, 9); /* (declare (special !*uncached)) */
    v199 = qvalue(elt(env, 10)); /* !*!*a2sfn */
    v78 = stack[-3];
    v78 = list2(v199, v78);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    v78 = list3(stack[-1], stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    v78 = list3(stack[-4], stack[-2], v78);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    v199 = qvalue(elt(env, 11)); /* t */
    popv(6);
    return list2(v78, v199);

v127:
    v199 = qvalue(elt(env, 10)); /* !*!*a2sfn */
    v78 = stack[-3];
    popv(6);
    return list2(v199, v78);

v37:
    v78 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v78 == nil)) goto v156;
    v78 = elt(env, 2); /* "tell Hearn!!" */
    fn = elt(env, 13); /* lprie */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    goto v156;

v156:
    v78 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v217;
    v78 = nil;
    { popv(6); return onevalue(v78); }
/* error exit handlers */
v217:
    popv(6);
    return nil;
}



/* Code for diffsq */

static Lisp_Object CC_diffsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v46;
    stack[-2] = v0;
/* end of prologue */
    v148 = stack[-2];
    v130 = qcar(v148);
    v148 = stack[-1];
    fn = elt(env, 1); /* difff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v130, v148);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    stack[0] = stack[-2];
    v148 = stack[-2];
    v130 = qcdr(v148);
    v148 = stack[-1];
    fn = elt(env, 1); /* difff */
    v148 = (*qfn2(fn))(qenv(fn), v130, v148);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    stack[0] = v148;
    v148 = stack[0];
    v148 = qcar(v148);
    fn = elt(env, 3); /* negf */
    v130 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    v148 = stack[0];
    v148 = qcdr(v148);
    v148 = cons(v130, v148);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v148);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    v130 = (Lisp_Object)17; /* 1 */
    v148 = stack[-2];
    v148 = qcdr(v148);
    v148 = cons(v130, v148);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    {
        Lisp_Object v61 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v61, v148);
    }
/* error exit handlers */
v80:
    popv(5);
    return nil;
}



/* Code for evmtest!? */

static Lisp_Object CC_evmtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v120, v35, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmtest?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v120 = v46;
    v35 = v0;
/* end of prologue */

v37:
    v47 = v35;
    if (v47 == nil) goto v59;
    v47 = v120;
    if (v47 == nil) goto v59;
    v47 = v35;
    v63 = qcar(v47);
    v47 = v120;
    v47 = qcar(v47);
    if (((int32_t)(v63)) < ((int32_t)(v47))) goto v153;
    v47 = v35;
    v47 = qcdr(v47);
    v35 = v47;
    v47 = v120;
    v47 = qcdr(v47);
    v120 = v47;
    goto v37;

v153:
    v47 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v47);

v59:
    v47 = v120;
    {
        fn = elt(env, 2); /* evzero!? */
        return (*qfn1(fn))(qenv(fn), v47);
    }
}



/* Code for bc2a */

static Lisp_Object CC_bc2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v0;
/* end of prologue */
    v132 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (!(v132 == nil)) return onevalue(v55);
    v132 = v55;
    v132 = qcar(v132);
    if (v132 == nil) goto v152;
    v132 = elt(env, 2); /* prepf */
    {
        fn = elt(env, 3); /* sqform */
        return (*qfn2(fn))(qenv(fn), v55, v132);
    }

v152:
    v132 = (Lisp_Object)1; /* 0 */
    return onevalue(v132);
}



/* Code for freeoff */

static Lisp_Object CC_freeoff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeoff");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v46;
    stack[-1] = v0;
/* end of prologue */

v37:
    v30 = stack[-1];
    if (!consp(v30)) goto v40;
    v30 = stack[-1];
    v30 = qcar(v30);
    if (!consp(v30)) goto v40;
    v30 = stack[-1];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    if (!consp(v30)) goto v241;
    v30 = stack[-1];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    if (!consp(v30)) goto v241;
    v30 = stack[-1];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v215 = qcar(v30);
    v30 = stack[0];
    v30 = CC_freeoff(env, v215, v30);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    if (v30 == nil) goto v33;
    v30 = stack[-1];
    v30 = qcar(v30);
    v215 = qcdr(v30);
    v30 = stack[0];
    v30 = CC_freeoff(env, v215, v30);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    if (v30 == nil) goto v112;
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    goto v37;

v112:
    v30 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v30); }

v33:
    v30 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v30); }

v241:
    v30 = stack[-1];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v215 = qcar(v30);
    v30 = stack[0];
    fn = elt(env, 3); /* ndepends */
    v30 = (*qfn2(fn))(qenv(fn), v215, v30);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    if (v30 == nil) goto v102;
    v30 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v30); }

v102:
    v30 = stack[-1];
    v30 = qcar(v30);
    v215 = qcdr(v30);
    v30 = stack[0];
    v30 = CC_freeoff(env, v215, v30);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    if (v30 == nil) goto v187;
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    goto v37;

v187:
    v30 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v30); }

v40:
    v30 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v30); }
/* error exit handlers */
v101:
    popv(3);
    return nil;
}



/* Code for wedgek2 */

static Lisp_Object MS_CDECL CC_wedgek2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wedgek2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgek2");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v5;
    stack[-3] = v46;
    stack[-4] = v0;
/* end of prologue */

v152:
    v11 = stack[-4];
    v248 = stack[-3];
    v248 = qcar(v248);
    if (!(v11 == v248)) goto v32;
    v11 = stack[-4];
    v248 = elt(env, 1); /* wedge */
    if (!consp(v11)) goto v155;
    v11 = qcar(v11);
    if (!(v11 == v248)) goto v155;

v32:
    v248 = stack[-3];
    v11 = qcar(v248);
    v248 = elt(env, 1); /* wedge */
    if (!consp(v11)) goto v218;
    v11 = qcar(v11);
    if (!(v11 == v248)) goto v218;
    v248 = stack[-3];
    v248 = qcar(v248);
    v248 = qcdr(v248);
    stack[-3] = v248;
    goto v152;

v218:
    v11 = stack[-4];
    v248 = elt(env, 1); /* wedge */
    if (!consp(v11)) goto v192;
    v11 = qcar(v11);
    if (!(v11 == v248)) goto v192;
    v248 = stack[-4];
    v11 = qcdr(v248);
    v248 = stack[-3];
    fn = elt(env, 3); /* wedgewedge */
    stack[0] = (*qfn2(fn))(qenv(fn), v11, v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v248 = stack[-2];
    fn = elt(env, 4); /* mksgnsq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    {
        Lisp_Object v249 = stack[0];
        popv(7);
        fn = elt(env, 5); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v249, v248);
    }

v192:
    v11 = stack[-4];
    v248 = stack[-3];
    v248 = qcar(v248);
    fn = elt(env, 6); /* worderp */
    v248 = (*qfn2(fn))(qenv(fn), v11, v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    if (v248 == nil) goto v101;
    v11 = stack[-4];
    v248 = stack[-3];
    v248 = cons(v11, v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 7); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v248 = stack[-2];
    fn = elt(env, 4); /* mksgnsq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    {
        Lisp_Object v250 = stack[0];
        popv(7);
        fn = elt(env, 5); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v250, v248);
    }

v101:
    v248 = stack[-3];
    v248 = qcdr(v248);
    if (v248 == nil) goto v133;
    v248 = stack[-3];
    v12 = qcar(v248);
    v11 = (Lisp_Object)17; /* 1 */
    v248 = (Lisp_Object)17; /* 1 */
    v248 = list2star(v12, v11, v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    stack[-5] = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    stack[-1] = stack[-4];
    v248 = stack[-3];
    stack[0] = qcdr(v248);
    v248 = stack[-4];
    fn = elt(env, 8); /* deg!*form */
    stack[-4] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v248 = stack[-3];
    v248 = qcar(v248);
    fn = elt(env, 8); /* deg!*form */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v248 = (*qfn2(fn))(qenv(fn), stack[-4], v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v248 = (*qfn2(fn))(qenv(fn), stack[-2], v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v248 = CC_wedgek2(env, 3, stack[-1], stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    {
        Lisp_Object v251 = stack[-5];
        popv(7);
        fn = elt(env, 11); /* wedgepf2 */
        return (*qfn2(fn))(qenv(fn), v251, v248);
    }

v133:
    v248 = stack[-3];
    v11 = qcar(v248);
    v248 = stack[-4];
    v248 = list2(v11, v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 7); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    stack[-1] = stack[-2];
    v248 = stack[-4];
    fn = elt(env, 8); /* deg!*form */
    stack[-2] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v248 = stack[-3];
    v248 = qcar(v248);
    fn = elt(env, 8); /* deg!*form */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v248 = (*qfn2(fn))(qenv(fn), stack[-2], v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v248 = (*qfn2(fn))(qenv(fn), stack[-1], v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 4); /* mksgnsq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    {
        Lisp_Object v252 = stack[0];
        popv(7);
        fn = elt(env, 5); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v252, v248);
    }

v155:
    v248 = stack[-4];
    fn = elt(env, 8); /* deg!*form */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v11 = v248;
    v248 = v11;
    v248 = integerp(v248);
    if (v248 == nil) goto v47;
    v248 = v11;
    v248 = Loddp(nil, v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    goto v186;

v186:
    if (v248 == nil) goto v105;
    v248 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v248); }

v105:
    v11 = stack[-4];
    v248 = stack[-3];
    v248 = cons(v11, v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    fn = elt(env, 7); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    v248 = stack[-2];
    fn = elt(env, 4); /* mksgnsq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-6];
    {
        Lisp_Object v253 = stack[0];
        popv(7);
        fn = elt(env, 5); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v253, v248);
    }

v47:
    v248 = qvalue(elt(env, 2)); /* nil */
    goto v186;
/* error exit handlers */
v160:
    popv(7);
    return nil;
}



/* Code for plubf */

static Lisp_Object CC_plubf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v261, v262, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plubf");
#endif
    if (stack >= stacklimit)
    {
        push2(v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v46);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v46;
    stack[-7] = v0;
/* end of prologue */
    v261 = stack[-7];
    v261 = qcdr(v261);
    v262 = qcar(v261);
    stack[-8] = v262;
    v261 = (Lisp_Object)1; /* 0 */
    if (v262 == v261) goto v67;
    v261 = stack[-6];
    v261 = qcdr(v261);
    v262 = qcar(v261);
    stack[-5] = v262;
    v261 = (Lisp_Object)1; /* 0 */
    if (v262 == v261) goto v55;
    v261 = stack[-7];
    v261 = qcdr(v261);
    v262 = qcdr(v261);
    stack[-4] = v262;
    v261 = stack[-6];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    stack[-3] = v261;
    v262 = difference2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    stack[-2] = v262;
    v261 = (Lisp_Object)1; /* 0 */
    if (v262 == v261) goto v33;
    stack[-1] = stack[-2];
    v261 = stack[-8];
    v261 = Labsval(nil, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = stack[-5];
    v261 = Labsval(nil, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = difference2(stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = plus2(stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    stack[-1] = v261;
    v261 = qvalue(elt(env, 2)); /* !:bprec!: */
    v261 = add1(v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    stack[0] = v261;
    v262 = stack[-1];
    v261 = stack[0];
    v261 = (Lisp_Object)greaterp2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    v261 = v261 ? lisp_true : nil;
    env = stack[-9];
    if (v261 == nil) goto v91;
    v261 = stack[-7];
    goto v156;

v156:
    stack[-2] = v261;
    v261 = stack[-2];
    v261 = qcdr(v261);
    v261 = qcar(v261);
    v167 = v261;
    v262 = v167;
    v261 = (Lisp_Object)1; /* 0 */
    if (v262 == v261) goto v171;
    v262 = v167;
    v261 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v167 = v261;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v261 = v167;
    stack[0] = qcar(v261);
    v261 = v167;
    v262 = qcdr(v261);
    v261 = stack[-2];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = plus2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    {
        Lisp_Object v7 = stack[-1];
        Lisp_Object v8 = stack[0];
        popv(10);
        return list2star(v7, v8, v261);
    }

v171:
    v167 = elt(env, 1); /* !:rd!: */
    v262 = (Lisp_Object)1; /* 0 */
    v261 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v167, v262, v261);

v91:
    v261 = stack[0];
    v261 = negate(v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = (Lisp_Object)lessp2(stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    v261 = v261 ? lisp_true : nil;
    env = stack[-9];
    if (v261 == nil) goto v182;
    v261 = stack[-6];
    goto v156;

v182:
    v262 = stack[-2];
    v261 = (Lisp_Object)1; /* 0 */
    v261 = (Lisp_Object)greaterp2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    v261 = v261 ? lisp_true : nil;
    env = stack[-9];
    if (v261 == nil) goto v93;
    stack[0] = elt(env, 1); /* !:rd!: */
    v262 = stack[-8];
    v261 = stack[-2];
    v262 = Lash1(nil, v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = stack[-5];
    v262 = plus2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = stack[-3];
    v261 = list2star(stack[0], v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    goto v156;

v93:
    stack[0] = elt(env, 1); /* !:rd!: */
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v261 = stack[-2];
    v261 = negate(v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = Lash1(nil, stack[-3], v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v262 = plus2(stack[-1], v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = stack[-4];
    v261 = list2star(stack[0], v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    goto v156;

v33:
    stack[0] = elt(env, 1); /* !:rd!: */
    v262 = stack[-8];
    v261 = stack[-5];
    v262 = plus2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    v261 = stack[-4];
    v261 = list2star(stack[0], v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-9];
    goto v156;

v55:
    v261 = stack[-7];
    goto v156;

v67:
    v261 = stack[-6];
    goto v156;
/* error exit handlers */
v263:
    popv(10);
    return nil;
}



/* Code for lispassignp */

static Lisp_Object CC_lispassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v151 = v0;
/* end of prologue */
    v156 = elt(env, 1); /* setq */
        return Leqcar(nil, v151, v156);
}



/* Code for fctargs */

static Lisp_Object CC_fctargs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v108;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctargs");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v0;
/* end of prologue */
    v108 = qvalue(elt(env, 1)); /* depl!* */
    v108 = Lassoc(nil, v87, v108);
    v87 = v108;
    if (v108 == nil) goto v37;
    v87 = qcdr(v87);
    return onevalue(v87);

v37:
    v87 = nil;
    return onevalue(v87);
}



/* Code for physopsimp */

static Lisp_Object CC_physopsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v291, v292, v293;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsimp");
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
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = nil;
    v291 = stack[-6];
    if (symbolp(v291)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v291 = stack[-6];
    v291 = qcar(v291);
    stack[-7] = v291;
    v291 = stack[-6];
    v291 = qcdr(v291);
    stack[-5] = v291;
    v291 = stack[-5];
    if (v291 == nil) goto v132;
    v291 = stack[-5];
    v291 = qcar(v291);
    stack[0] = v291;
    v291 = stack[0];
    if (!(symbolp(v291))) goto v36;
    v291 = stack[0];
    fn = elt(env, 8); /* isanindex */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (!(v291 == nil)) goto v186;
    v291 = stack[0];
    fn = elt(env, 9); /* isavarindex */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (!(v291 == nil)) goto v186;

v36:
    v291 = stack[0];
    fn = elt(env, 10); /* physopsm!* */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    goto v48;

v48:
    v291 = ncons(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-2] = v291;
    stack[-3] = v291;
    goto v60;

v60:
    v291 = stack[-5];
    v291 = qcdr(v291);
    stack[-5] = v291;
    v291 = stack[-5];
    if (v291 == nil) goto v31;
    stack[-1] = stack[-2];
    v291 = stack[-5];
    v291 = qcar(v291);
    stack[0] = v291;
    v291 = stack[0];
    if (!(symbolp(v291))) goto v197;
    v291 = stack[0];
    fn = elt(env, 8); /* isanindex */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (!(v291 == nil)) goto v128;
    v291 = stack[0];
    fn = elt(env, 9); /* isavarindex */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (!(v291 == nil)) goto v128;

v197:
    v291 = stack[0];
    fn = elt(env, 10); /* physopsm!* */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    goto v241;

v241:
    v291 = ncons(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = Lrplacd(nil, stack[-1], v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = stack[-2];
    v291 = qcdr(v291);
    stack[-2] = v291;
    goto v60;

v128:
    v291 = stack[0];
    goto v241;

v31:
    v291 = stack[-3];
    goto v49;

v49:
    stack[0] = v291;
    stack[-5] = stack[-7];
    v291 = stack[0];
    stack[-3] = v291;
    v291 = stack[-3];
    if (v291 == nil) goto v211;
    v291 = stack[-3];
    v291 = qcar(v291);
    v293 = v291;
    v292 = v293;
    v291 = elt(env, 2); /* !*sq */
    if (!consp(v292)) goto v181;
    v292 = qcar(v292);
    if (!(v292 == v291)) goto v181;
    v291 = v293;
    v291 = qcdr(v291);
    v291 = qcar(v291);
    fn = elt(env, 11); /* prepsqxx */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    goto v144;

v144:
    v291 = ncons(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-1] = v291;
    stack[-2] = v291;
    goto v208;

v208:
    v291 = stack[-3];
    v291 = qcdr(v291);
    stack[-3] = v291;
    v291 = stack[-3];
    if (v291 == nil) goto v72;
    stack[0] = stack[-1];
    v291 = stack[-3];
    v291 = qcar(v291);
    v293 = v291;
    v292 = v293;
    v291 = elt(env, 2); /* !*sq */
    if (!consp(v292)) goto v22;
    v292 = qcar(v292);
    if (!(v292 == v291)) goto v22;
    v291 = v293;
    v291 = qcdr(v291);
    v291 = qcar(v291);
    fn = elt(env, 11); /* prepsqxx */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    goto v142;

v142:
    v291 = ncons(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = Lrplacd(nil, stack[0], v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = stack[-1];
    v291 = qcdr(v291);
    stack[-1] = v291;
    goto v208;

v22:
    v291 = v293;
    goto v142;

v72:
    v291 = stack[-2];
    goto v79;

v79:
    v291 = cons(stack[-5], v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-6] = v291;
    v291 = stack[-6];
    fn = elt(env, 12); /* opmtch!* */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[0] = v291;
    if (!(v291 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v291 = stack[-6];
    fn = elt(env, 13); /* scalopp */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (v291 == nil) goto v203;
    v291 = stack[-7];
    fn = elt(env, 14); /* tensopp */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (v291 == nil) goto v203;
    v292 = stack[-7];
    v291 = elt(env, 3); /* tensdimen */
    v291 = get(v292, v291);
    env = stack[-8];
    stack[-5] = v291;
    v291 = (Lisp_Object)17; /* 1 */
    stack[-3] = v291;
    v292 = stack[-5];
    v291 = stack[-3];
    v291 = difference2(v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = Lminusp(nil, v291);
    env = stack[-8];
    if (v291 == nil) goto v239;
    v291 = qvalue(elt(env, 1)); /* nil */
    goto v244;

v244:
    stack[0] = v291;
    v291 = stack[-6];
    v291 = qcdr(v291);
    v292 = Llength(nil, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = stack[-5];
    v291 = (Lisp_Object)greaterp2(v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    v291 = v291 ? lisp_true : nil;
    env = stack[-8];
    if (v291 == nil) goto v295;
    v291 = stack[-6];
    stack[-1] = qcdr(v291);
    v291 = stack[-5];
    v291 = add1(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    fn = elt(env, 15); /* pnth */
    v291 = (*qfn2(fn))(qenv(fn), stack[-1], v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-5] = v291;
    goto v296;

v296:
    v292 = stack[-7];
    v291 = elt(env, 4); /* symmetric */
    v291 = Lflagp(nil, v292, v291);
    env = stack[-8];
    if (v291 == nil) goto v38;
    stack[-1] = stack[-7];
    v291 = stack[0];
    fn = elt(env, 16); /* ordn */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = cons(stack[-1], v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-6] = v291;
    goto v233;

v233:
    v291 = stack[-5];
    if (v291 == nil) goto v297;
    v292 = stack[-6];
    v291 = stack[-5];
    v291 = Lappend(nil, v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-6] = v291;
    goto v297;

v297:
    v291 = stack[-4];
    if (v291 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v292 = elt(env, 7); /* minus */
    v291 = stack[-6];
    popv(9);
    return list2(v292, v291);

v38:
    v292 = stack[-7];
    v291 = elt(env, 5); /* antisymmetric */
    v291 = Lflagp(nil, v292, v291);
    env = stack[-8];
    if (v291 == nil) goto v298;
    v291 = stack[0];
    fn = elt(env, 17); /* repeats */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (v291 == nil) goto v299;
    v291 = (Lisp_Object)1; /* 0 */
    { popv(9); return onevalue(v291); }

v299:
    v291 = stack[0];
    fn = elt(env, 16); /* ordn */
    v292 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-1] = v292;
    v291 = stack[0];
    fn = elt(env, 18); /* permp */
    v291 = (*qfn2(fn))(qenv(fn), v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (!(v291 == nil)) goto v300;
    v291 = qvalue(elt(env, 6)); /* t */
    stack[-4] = v291;
    goto v300;

v300:
    v291 = stack[-1];
    stack[0] = v291;
    v292 = stack[-7];
    v291 = stack[0];
    v291 = cons(v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-6] = v291;
    goto v233;

v298:
    v292 = stack[-7];
    v291 = stack[0];
    v291 = cons(v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-6] = v291;
    goto v233;

v295:
    v291 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v291;
    goto v296;

v239:
    v291 = stack[-6];
    v292 = qcdr(v291);
    v291 = stack[-3];
    fn = elt(env, 15); /* pnth */
    v291 = (*qfn2(fn))(qenv(fn), v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = qcar(v291);
    v291 = ncons(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-1] = v291;
    stack[-2] = v291;
    goto v136;

v136:
    v291 = stack[-3];
    v291 = add1(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[-3] = v291;
    v292 = stack[-5];
    v291 = stack[-3];
    v291 = difference2(v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = Lminusp(nil, v291);
    env = stack[-8];
    if (v291 == nil) goto v240;
    v291 = stack[-2];
    goto v244;

v240:
    stack[0] = stack[-1];
    v291 = stack[-6];
    v292 = qcdr(v291);
    v291 = stack[-3];
    fn = elt(env, 15); /* pnth */
    v291 = (*qfn2(fn))(qenv(fn), v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = qcar(v291);
    v291 = ncons(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = Lrplacd(nil, stack[0], v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = stack[-1];
    v291 = qcdr(v291);
    stack[-1] = v291;
    goto v136;

v203:
    v291 = stack[-6];
    fn = elt(env, 19); /* vecopp */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (v291 == nil) goto v301;
    v291 = stack[-6];
    fn = elt(env, 20); /* listp */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (v291 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v291 = stack[-6];
    v291 = qcdr(v291);
    v291 = qcar(v291);
    fn = elt(env, 21); /* putanewindex!* */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }

v301:
    v291 = stack[-6];
    fn = elt(env, 14); /* tensopp */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (v291 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v291 = stack[-6];
    fn = elt(env, 20); /* listp */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    if (v291 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v291 = (Lisp_Object)17; /* 1 */
    stack[0] = v291;
    goto v302;

v302:
    v291 = stack[-6];
    v291 = qcdr(v291);
    v292 = Llength(nil, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = stack[0];
    v291 = difference2(v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = Lminusp(nil, v291);
    env = stack[-8];
    if (!(v291 == nil)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    v291 = stack[-6];
    v292 = qcdr(v291);
    v291 = stack[0];
    fn = elt(env, 15); /* pnth */
    v291 = (*qfn2(fn))(qenv(fn), v292, v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = qcar(v291);
    fn = elt(env, 21); /* putanewindex!* */
    v291 = (*qfn1(fn))(qenv(fn), v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    v291 = stack[0];
    v291 = add1(v291);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[-8];
    stack[0] = v291;
    goto v302;

v181:
    v291 = v293;
    goto v144;

v211:
    v291 = qvalue(elt(env, 1)); /* nil */
    goto v79;

v186:
    v291 = stack[0];
    goto v48;

v132:
    v291 = qvalue(elt(env, 1)); /* nil */
    goto v49;
/* error exit handlers */
v294:
    popv(9);
    return nil;
}



setup_type const u19_setup[] =
{
    {"ibalp_renewwl",           CC_ibalp_renewwl,too_many_1,   wrong_no_1},
    {"ev_lexcomp",              too_few_2,      CC_ev_lexcomp, wrong_no_2},
    {"getsetvars",              CC_getsetvars,  too_many_1,    wrong_no_1},
    {"nextcomb",                too_few_2,      CC_nextcomb,   wrong_no_2},
    {"setdmode",                too_few_2,      CC_setdmode,   wrong_no_2},
    {"groebcplistsortin",       too_few_2,      CC_groebcplistsortin,wrong_no_2},
    {"rd:times",                too_few_2,      CC_rdTtimes,   wrong_no_2},
    {"fortranname",             CC_fortranname, too_many_1,    wrong_no_1},
    {"powers3",                 too_few_2,      CC_powers3,    wrong_no_2},
    {"assert_uninstall",        CC_assert_uninstall,too_many_1,wrong_no_1},
    {"repeats",                 CC_repeats,     too_many_1,    wrong_no_1},
    {"st_sorttree",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree},
    {"ilcm",                    too_few_2,      CC_ilcm,       wrong_no_2},
    {"sfto_ucontentf1",         too_few_2,      CC_sfto_ucontentf1,wrong_no_2},
    {"simpqg",                  CC_simpqg,      too_many_1,    wrong_no_1},
    {"delet",                   too_few_2,      CC_delet,      wrong_no_2},
    {"ibalp_var-unsatlist",     too_few_2,      CC_ibalp_varKunsatlist,wrong_no_2},
    {"band_matrix",             too_few_2,      CC_band_matrix,wrong_no_2},
    {"evgradlexcomp",           too_few_2,      CC_evgradlexcomp,wrong_no_2},
    {"gftimesn",                too_few_2,      CC_gftimesn,   wrong_no_2},
    {"lesspcdr",                too_few_2,      CC_lesspcdr,   wrong_no_2},
    {"subla-q",                 too_few_2,      CC_sublaKq,    wrong_no_2},
    {"setk0",                   too_few_2,      CC_setk0,      wrong_no_2},
    {"fs:times",                too_few_2,      CC_fsTtimes,   wrong_no_2},
    {"evaluate-mod-p",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKmodKp},
    {"delasc",                  too_few_2,      CC_delasc,     wrong_no_2},
    {"get-denom-ll",            too_few_2,      CC_getKdenomKll,wrong_no_2},
    {"sfto_sqfpartf",           CC_sfto_sqfpartf,too_many_1,   wrong_no_1},
    {"pasf_vf",                 CC_pasf_vf,     too_many_1,    wrong_no_1},
    {"token-number",            CC_tokenKnumber,too_many_1,    wrong_no_1},
    {"poly-minusp",             CC_polyKminusp, too_many_1,    wrong_no_1},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"diffsq",                  too_few_2,      CC_diffsq,     wrong_no_2},
    {"evmtest?",                too_few_2,      CC_evmtestW,   wrong_no_2},
    {"bc2a",                    CC_bc2a,        too_many_1,    wrong_no_1},
    {"freeoff",                 too_few_2,      CC_freeoff,    wrong_no_2},
    {"wedgek2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_wedgek2},
    {"plubf",                   too_few_2,      CC_plubf,      wrong_no_2},
    {"lispassignp",             CC_lispassignp, too_many_1,    wrong_no_1},
    {"fctargs",                 CC_fctargs,     too_many_1,    wrong_no_1},
    {"physopsimp",              CC_physopsimp,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u19", (two_args *)"21617 9869526 9866983", 0}
};

/* end of generated code */
