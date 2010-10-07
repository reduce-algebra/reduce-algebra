
/* $destdir\u40.c        Machine generated C code */

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


/* Code for makecoeffpairs1 */

static Lisp_Object MS_CDECL CC_makecoeffpairs1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairs1");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v3;
    stack[-11] = v2;
    stack[-12] = v1;
    stack[-13] = v0;
/* end of prologue */
    v58 = stack[-12];
    if (v58 == nil) goto v62;
    v58 = stack[-13];
    v61 = qcdr(v58);
    v58 = stack[-12];
    v60 = qcdr(v58);
    v58 = stack[-11];
    v59 = qcdr(v58);
    v58 = stack[-10];
    v58 = qcdr(v58);
    v58 = CC_makecoeffpairs1(env, 4, v61, v60, v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-14] = v58;
    goto v64;

v64:
    v58 = stack[-14];
    if (v58 == nil) goto v65;
    v58 = stack[-14];
    v58 = qcar(v58);
    stack[-6] = v58;
    v58 = stack[-13];
    stack[-2] = qcar(v58);
    v58 = stack[-12];
    stack[-1] = qcar(v58);
    v58 = stack[-11];
    stack[0] = qcar(v58);
    v58 = stack[-10];
    v58 = qcar(v58);
    fn = elt(env, 3); /* tayexp!-minus */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v58 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v66;
    v58 = stack[-5];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[-1] = qcar(v58);
    v58 = stack[-6];
    stack[0] = qcar(v58);
    v58 = v59;
    v59 = qcdr(v58);
    v58 = stack[-6];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = acons(stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-3] = v58;
    stack[-4] = v58;
    goto v67;

v67:
    v58 = stack[-5];
    v58 = qcdr(v58);
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v68;
    stack[-2] = stack[-3];
    v58 = stack[-5];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[-1] = qcar(v58);
    v58 = stack[-6];
    stack[0] = qcar(v58);
    v58 = v59;
    v59 = qcdr(v58);
    v58 = stack[-6];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = acons(stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = Lrplacd(nil, stack[-2], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = stack[-3];
    v58 = qcdr(v58);
    stack[-3] = v58;
    goto v67;

v68:
    v58 = stack[-4];
    goto v69;

v69:
    stack[-9] = v58;
    v58 = stack[-9];
    fn = elt(env, 5); /* lastpair */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-8] = v58;
    v58 = stack[-14];
    v58 = qcdr(v58);
    stack[-14] = v58;
    v58 = stack[-8];
    if (!consp(v58)) goto v64;
    else goto v70;

v70:
    v58 = stack[-14];
    if (v58 == nil) { Lisp_Object res = stack[-9]; popv(16); return onevalue(res); }
    stack[-7] = stack[-8];
    v58 = stack[-14];
    v58 = qcar(v58);
    stack[-6] = v58;
    v58 = stack[-13];
    stack[-2] = qcar(v58);
    v58 = stack[-12];
    stack[-1] = qcar(v58);
    v58 = stack[-11];
    stack[0] = qcar(v58);
    v58 = stack[-10];
    v58 = qcar(v58);
    fn = elt(env, 3); /* tayexp!-minus */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v58 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v71;
    v58 = stack[-5];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[-1] = qcar(v58);
    v58 = stack[-6];
    stack[0] = qcar(v58);
    v58 = v59;
    v59 = qcdr(v58);
    v58 = stack[-6];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = acons(stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-3] = v58;
    stack[-4] = v58;
    goto v72;

v72:
    v58 = stack[-5];
    v58 = qcdr(v58);
    stack[-5] = v58;
    v58 = stack[-5];
    if (v58 == nil) goto v73;
    stack[-2] = stack[-3];
    v58 = stack[-5];
    v58 = qcar(v58);
    v59 = v58;
    v58 = v59;
    stack[-1] = qcar(v58);
    v58 = stack[-6];
    stack[0] = qcar(v58);
    v58 = v59;
    v59 = qcdr(v58);
    v58 = stack[-6];
    v58 = qcdr(v58);
    v58 = cons(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = acons(stack[-1], stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = Lrplacd(nil, stack[-2], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = stack[-3];
    v58 = qcdr(v58);
    stack[-3] = v58;
    goto v72;

v73:
    v58 = stack[-4];
    goto v74;

v74:
    v58 = Lrplacd(nil, stack[-7], v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    v58 = stack[-8];
    fn = elt(env, 5); /* lastpair */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-15];
    stack[-8] = v58;
    v58 = stack[-14];
    v58 = qcdr(v58);
    stack[-14] = v58;
    goto v70;

v71:
    v58 = qvalue(elt(env, 2)); /* nil */
    goto v74;

v66:
    v58 = qvalue(elt(env, 2)); /* nil */
    goto v69;

v65:
    v58 = qvalue(elt(env, 2)); /* nil */
    { popv(16); return onevalue(v58); }

v62:
    v58 = elt(env, 1); /* ((nil)) */
    { popv(16); return onevalue(v58); }
/* error exit handlers */
v63:
    popv(16);
    return nil;
}



/* Code for repr_a */

static Lisp_Object CC_repr_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repr_a");
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
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = qcar(v75);
    v75 = Lreverse(nil, v75);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    v75 = qcar(v75);
    v76 = qcar(v75);
    v75 = stack[0];
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = qcdr(v75);
    v75 = qcar(v75);
    {
        popv(2);
        fn = elt(env, 1); /* addf */
        return (*qfn2(fn))(qenv(fn), v76, v75);
    }
/* error exit handlers */
v77:
    popv(2);
    return nil;
}



/* Code for ofsf_sacrel!-and */

static Lisp_Object CC_ofsf_sacrelKand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v80, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacrel-and");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v79 = v1;
    v80 = v0;
/* end of prologue */
    v81 = elt(env, 1); /* ((lessp (lessp . keep) (leq . keep2) (equal . drop) (neq . keep2) (geq . drop) (greaterp . drop)) (leq (lessp . keep1) (leq . keep) (equal . keep1) (neq . lessp) (geq . equal
) (greaterp . drop)) (equal (lessp . drop) (leq . keep2) (equal . keep) (neq . drop) (geq . keep2) (greaterp . drop)) (neq (lessp . keep1) (leq . lessp) (equal . drop) (neq . keep) (geq . greaterp) (g
reaterp . keep1)) (geq (lessp . drop) (leq . equal) (equal . keep1) (neq . greaterp) (geq . keep) (greaterp . keep1)) (greaterp (lessp . drop) (leq . drop) (equal . drop) (neq . keep2) (geq . keep2) (
greaterp . keep))) */
    v79 = Latsoc(nil, v79, v81);
    v79 = qcdr(v79);
    v79 = Latsoc(nil, v80, v79);
    v79 = qcdr(v79);
    return onevalue(v79);
}



/* Code for prsubsetrd */

static Lisp_Object CC_prsubsetrd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prsubsetrd");
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
    v87 = qvalue(elt(env, 1)); /* t */
    stack[-1] = v87;
    goto v6;

v6:
    v87 = stack[-3];
    v88 = Llength(nil, v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v87 = (Lisp_Object)17; /* 1 */
    v87 = (Lisp_Object)greaterp2(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v87 = v87 ? lisp_true : nil;
    env = stack[-4];
    if (v87 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v87 = stack[-3];
    stack[0] = qcar(v87);
    v87 = stack[-3];
    v87 = qcar(v87);
    fn = elt(env, 4); /* reval */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    if (equal(stack[0], v87)) goto v81;
    v87 = stack[-3];
    v87 = qcdr(v87);
    stack[0] = qcar(v87);
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcar(v87);
    fn = elt(env, 4); /* reval */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    if (equal(stack[0], v87)) goto v81;
    v87 = stack[-1];
    if (v87 == nil) goto v53;
    v87 = stack[-3];
    v87 = qcar(v87);
    fn = elt(env, 4); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcar(v87);
    fn = elt(env, 4); /* reval */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    fn = elt(env, 5); /* alg_prsubset */
    v87 = (*qfn2(fn))(qenv(fn), stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    goto v89;

v89:
    stack[-1] = v87;
    v87 = stack[-3];
    v87 = qcdr(v87);
    stack[-3] = v87;
    goto v6;

v53:
    v87 = qvalue(elt(env, 2)); /* nil */
    goto v89;

v81:
    v87 = nil;
    stack[-3] = v87;
    stack[0] = elt(env, 3); /* prsubset */
    v87 = stack[-2];
    fn = elt(env, 6); /* eval_list_sets */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v87 = cons(stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-1] = v87;
    goto v6;
/* error exit handlers */
v45:
    popv(5);
    return nil;
}



/* Code for spmatsm!* */

static Lisp_Object CC_spmatsmH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmatsm*");
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
    v81 = v1;
    v90 = v0;
/* end of prologue */
    v81 = v90;
    fn = elt(env, 3); /* spmatsm */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[0];
    v91 = v81;
    v90 = v91;
    v81 = elt(env, 1); /* sparsemat */
    if (!consp(v90)) goto v76;
    v90 = qcar(v90);
    if (v90 == v81) { popv(1); return onevalue(v91); }
    else goto v76;

v76:
    v81 = v91;
    {
        popv(1);
        fn = elt(env, 4); /* matsm!*1 */
        return (*qfn1(fn))(qenv(fn), v81);
    }
/* error exit handlers */
v92:
    popv(1);
    return nil;
}



/* Code for vdpmember */

static Lisp_Object CC_vdpmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpmember");
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

v93:
    v91 = stack[0];
    if (v91 == nil) goto v94;
    v92 = stack[-1];
    v91 = stack[0];
    v91 = qcar(v91);
    fn = elt(env, 2); /* vdpequal */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    if (!(v91 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v91 = stack[0];
    v91 = qcdr(v91);
    stack[0] = v91;
    goto v93;

v94:
    v91 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v91); }
/* error exit handlers */
v95:
    popv(3);
    return nil;
}



/* Code for dipcontenti */

static Lisp_Object CC_dipcontenti(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v52, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontenti");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v89 = v0;
/* end of prologue */
    v97 = v89;
    if (v97 == nil) goto v99;
    v97 = v89;
    v97 = qcdr(v97);
    v97 = qcdr(v97);
    v52 = v97;
    v97 = v52;
    if (v97 == nil) goto v75;
    v97 = v89;
    v97 = qcdr(v97);
    v98 = qcar(v97);
    v97 = qvalue(elt(env, 1)); /* !*groebrm */
    if (v97 == nil) goto v100;
    v97 = v89;
    v97 = qcar(v97);
    goto v39;

v39:
    {
        fn = elt(env, 3); /* dipcontenti1 */
        return (*qfnn(fn))(qenv(fn), 3, v98, v97, v52);
    }

v100:
    v97 = qvalue(elt(env, 2)); /* nil */
    goto v39;

v75:
    v97 = v89;
    v97 = qcdr(v97);
    v98 = qcar(v97);
    v97 = qvalue(elt(env, 1)); /* !*groebrm */
    if (v97 == nil) goto v54;
    v97 = v89;
    v97 = qcar(v97);
    goto v77;

v77:
    return cons(v98, v97);

v54:
    v97 = qvalue(elt(env, 2)); /* nil */
    goto v77;

v99:
    v97 = (Lisp_Object)17; /* 1 */
    return onevalue(v97);
}



/* Code for gf2bf */

static Lisp_Object CC_gf2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gf2bf");
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
    goto v93;

v93:
    v109 = stack[0];
    if (v109 == nil) goto v111;
    v109 = stack[0];
    if (!consp(v109)) goto v29;
    v110 = stack[0];
    v109 = elt(env, 1); /* !:rd!: */
    if (!consp(v110)) goto v46;
    v110 = qcar(v110);
    if (!(v110 == v109)) goto v46;
    v109 = stack[0];
    v109 = qcdr(v109);
    if (!consp(v109)) goto v46;
    v110 = stack[-1];
    v109 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v110, v109);
    }

v46:
    v109 = stack[0];
    v109 = qcar(v109);
    v110 = CC_gf2bf(env, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    v109 = stack[-1];
    v109 = cons(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    stack[-1] = v109;
    v109 = stack[0];
    v109 = qcdr(v109);
    stack[0] = v109;
    goto v93;

v29:
    v109 = stack[0];
    v109 = Lfloatp(nil, v109);
    env = stack[-2];
    if (v109 == nil) goto v85;
    v109 = stack[0];
    fn = elt(env, 3); /* fl2bf */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    {
        Lisp_Object v113 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v113, v109);
    }

v85:
    v109 = stack[0];
    if (!consp(v109)) goto v114;
    v109 = stack[0];
    goto v115;

v115:
    fn = elt(env, 4); /* csl_normbf */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    {
        Lisp_Object v116 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v116, v109);
    }

v114:
    v109 = stack[0];
    v109 = integerp(v109);
    if (v109 == nil) goto v97;
    v68 = elt(env, 1); /* !:rd!: */
    v110 = stack[0];
    v109 = (Lisp_Object)1; /* 0 */
    v109 = list2star(v68, v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    goto v115;

v97:
    v109 = stack[0];
    fn = elt(env, 5); /* read!:num */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    goto v115;

v111:
    v109 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v109);
    }
/* error exit handlers */
v112:
    popv(3);
    return nil;
}



/* Code for addnew */

static Lisp_Object MS_CDECL CC_addnew(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v42, v31, v69, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addnew");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addnew");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    v69 = v1;
    v67 = v0;
/* end of prologue */
    v31 = qvalue(elt(env, 1)); /* gv */
    v42 = v69;
    v43 = v67;
    *(Lisp_Object *)((char *)v31 + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL))) = v43;
    v31 = qvalue(elt(env, 2)); /* bv */
    v42 = v69;
    v43 = qvalue(elt(env, 3)); /* t */
    *(Lisp_Object *)((char *)v31 + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL))) = v43;
    v43 = v67;
    if (v43 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = v69;
    v43 = v67;
    fn = elt(env, 4); /* ljet */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    v42 = cons(stack[-1], v43);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    v43 = stack[0];
    fn = elt(env, 5); /* insert */
    v43 = (*qfn2(fn))(qenv(fn), v42, v43);
    nil = C_nil;
    if (exception_pending()) goto v120;
    { popv(3); return onevalue(v43); }
/* error exit handlers */
v120:
    popv(3);
    return nil;
}



/* Code for rl_qefsolset */

static Lisp_Object MS_CDECL CC_rl_qefsolset(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v99, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v54, v85, v55, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rl_qefsolset");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_qefsolset");
#endif
    if (stack >= stacklimit)
    {
        push5(v99,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v99);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v121 = v99;
    v54 = v3;
    v85 = v2;
    v55 = v1;
    v117 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* rl_qefsolset!* */
    stack[-2] = v117;
    stack[-1] = v55;
    stack[0] = v85;
    v121 = list2(v54, v121);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    v121 = list3star(stack[-2], stack[-1], stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-4];
    {
        Lisp_Object v114 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v114, v121);
    }
/* error exit handlers */
v122:
    popv(5);
    return nil;
}



/* Code for sfto_yun!-updecf */

static Lisp_Object CC_sfto_yunKupdecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_yun-updecf");
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
    stack[-7] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-1] = nil;
    v141 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v141; /* !*gcd */
    v142 = (Lisp_Object)17; /* 1 */
    v141 = (Lisp_Object)17; /* 1 */
    v141 = cons(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    stack[-2] = v141;
    v141 = stack[-6];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = qcar(v141);
    stack[-5] = v141;
    stack[-3] = stack[-6];
    v142 = stack[-6];
    v141 = stack[-5];
    fn = elt(env, 3); /* diff */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    stack[0] = v141;
    fn = elt(env, 4); /* sfto_gcdf */
    v141 = (*qfn2(fn))(qenv(fn), stack[-3], v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    stack[-3] = v141;
    v142 = stack[-6];
    v141 = stack[-3];
    fn = elt(env, 5); /* quotf */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    stack[-4] = v141;
    v142 = stack[0];
    v141 = stack[-3];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    v142 = stack[-4];
    v141 = stack[-5];
    fn = elt(env, 3); /* diff */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    fn = elt(env, 6); /* negf */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    fn = elt(env, 7); /* addf */
    v141 = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    stack[-3] = v141;
    goto v143;

v143:
    v141 = stack[-1];
    v141 = (v141 == nil ? lisp_true : nil);
    stack[-1] = v141;
    v142 = stack[-4];
    v141 = stack[-3];
    fn = elt(env, 4); /* sfto_gcdf */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    stack[-6] = v141;
    v141 = stack[-1];
    if (v141 == nil) goto v68;
    stack[0] = stack[-2];
    v141 = stack[-2];
    v142 = qcar(v141);
    v141 = stack[-6];
    fn = elt(env, 8); /* multf */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    fn = elt(env, 9); /* setcar */
    v141 = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    goto v144;

v144:
    v142 = stack[-4];
    v141 = stack[-6];
    fn = elt(env, 5); /* quotf */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    stack[-4] = v141;
    v142 = stack[-3];
    v141 = stack[-6];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    v142 = stack[-4];
    v141 = stack[-5];
    fn = elt(env, 3); /* diff */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    fn = elt(env, 6); /* negf */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    fn = elt(env, 7); /* addf */
    v141 = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    stack[-3] = v141;
    v141 = stack[-4];
    if (!consp(v141)) goto v145;
    v141 = stack[-4];
    v141 = qcar(v141);
    if (!(!consp(v141))) goto v143;

v145:
    v141 = stack[-2];
    qvalue(elt(env, 1)) = stack[-7]; /* !*gcd */
    { popv(9); return onevalue(v141); }

v68:
    stack[0] = stack[-2];
    v141 = stack[-2];
    v142 = qcdr(v141);
    v141 = stack[-6];
    fn = elt(env, 8); /* multf */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    fn = elt(env, 10); /* setcdr */
    v141 = (*qfn2(fn))(qenv(fn), stack[0], v141);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-8];
    goto v144;
/* error exit handlers */
v17:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-7]; /* !*gcd */
    popv(9);
    return nil;
}



/* Code for checkexp */

static Lisp_Object CC_checkexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v65, v108, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkexp");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v108 = v1;
    v115 = v0;
/* end of prologue */
    v65 = v108;
    v107 = (Lisp_Object)1; /* 0 */
    if (v65 == v107) goto v93;
    v65 = v108;
    v107 = (Lisp_Object)17; /* 1 */
    if (v65 == v107) { popv(2); return onevalue(v115); }
    stack[-1] = elt(env, 1); /* expt */
    stack[0] = v115;
    v107 = v108;
    fn = elt(env, 2); /* preptayexp */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v118;
    {
        Lisp_Object v39 = stack[-1];
        Lisp_Object v41 = stack[0];
        popv(2);
        return list3(v39, v41, v107);
    }

v93:
    v107 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v107); }
/* error exit handlers */
v118:
    popv(2);
    return nil;
}



/* Code for rule!* */

static Lisp_Object MS_CDECL CC_ruleH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v99, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v24, v164, v165, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rule*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule*");
#endif
    if (stack >= stacklimit)
    {
        push5(v99,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v99);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v99;
    stack[-1] = v3;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v163 = stack[-2];
    qvalue(elt(env, 1)) = v163; /* frasc!* */
    v24 = stack[-1];
    v163 = qvalue(elt(env, 2)); /* t */
    v163 = (v24 == v163 ? lisp_true : nil);
    if (!(v163 == nil)) goto v119;
    v24 = stack[-2];
    v163 = stack[-1];
    v163 = Lsubla(nil, v24, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    goto v119;

v119:
    qvalue(elt(env, 3)) = v163; /* mcond!* */
    v163 = stack[0];
    if (v163 == nil) goto v168;
    v24 = stack[0];
    v163 = elt(env, 4); /* old */
    if (v24 == v163) goto v168;
    v165 = stack[-4];
    v164 = stack[-3];
    v24 = stack[-2];
    v163 = stack[-1];
    v163 = list4(v165, v164, v24, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    qvalue(elt(env, 5)) = v163; /* newrule!* */
    v163 = stack[-4];
    if (!(symbolp(v163))) goto v169;
    v24 = stack[-4];
    v163 = elt(env, 6); /* rtype */
    v163 = get(v24, v163);
    env = stack[-5];
    v24 = v163;
    if (v163 == nil) goto v170;
    stack[-1] = stack[-4];
    v163 = elt(env, 6); /* rtype */
    v24 = cons(v163, v24);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    v163 = qvalue(elt(env, 7)); /* props!* */
    v163 = acons(stack[-1], v24, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    qvalue(elt(env, 7)) = v163; /* props!* */
    v24 = stack[-4];
    v163 = elt(env, 6); /* rtype */
    v163 = Lremprop(nil, v24, v163);
    env = stack[-5];
    goto v170;

v170:
    v24 = stack[-4];
    v163 = elt(env, 8); /* avalue */
    v163 = get(v24, v163);
    env = stack[-5];
    v24 = v163;
    if (v163 == nil) goto v169;
    v163 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 12); /* updoldrules */
    v163 = (*qfn2(fn))(qenv(fn), v24, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    v24 = stack[-4];
    v163 = elt(env, 8); /* avalue */
    v163 = Lremprop(nil, v24, v163);
    env = stack[-5];
    goto v169;

v169:
    v24 = stack[-3];
    v163 = (Lisp_Object)1; /* 0 */
    if (!(v24 == v163)) goto v168;
    v24 = stack[-4];
    v163 = elt(env, 10); /* expt */
    if (!consp(v24)) goto v168;
    v24 = qcar(v24);
    if (!(v24 == v163)) goto v168;
    v163 = stack[-4];
    v163 = qcdr(v163);
    v163 = qcar(v163);
    if (!(symbolp(v163))) goto v168;
    v163 = stack[-4];
    v163 = qcdr(v163);
    v163 = qcdr(v163);
    v163 = qcar(v163);
    if (!(is_number(v163))) goto v168;
    v163 = stack[-4];
    v163 = qcdr(v163);
    v24 = qcar(v163);
    v163 = qvalue(elt(env, 11)); /* asymplis!* */
    v163 = Lassoc(nil, v24, v163);
    v24 = v163;
    if (v163 == nil) goto v168;
    v163 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 12); /* updoldrules */
    v163 = (*qfn2(fn))(qenv(fn), v24, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-5];
    goto v168;

v168:
    v166 = stack[-4];
    v165 = stack[-3];
    v164 = stack[-2];
    v24 = stack[0];
    v163 = elt(env, 4); /* old */
    if (v24 == v163) goto v171;
    v163 = stack[0];
    goto v172;

v172:
    {
        popv(6);
        fn = elt(env, 13); /* rule */
        return (*qfnn(fn))(qenv(fn), 4, v166, v165, v164, v163);
    }

v171:
    v163 = qvalue(elt(env, 2)); /* t */
    goto v172;
/* error exit handlers */
v167:
    popv(6);
    return nil;
}



/* Code for qqe_simplbtat */

static Lisp_Object CC_qqe_simplbtat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplbtat");
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
    v174 = v1;
    stack[-2] = v0;
/* end of prologue */
    v174 = stack[-2];
    fn = elt(env, 6); /* rl_prepat */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    stack[-3] = v174;
    v174 = stack[-2];
    fn = elt(env, 7); /* qqe_op */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    stack[0] = v174;
    v174 = stack[-3];
    fn = elt(env, 8); /* qqe_arg2l */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    fn = elt(env, 9); /* qqe_eta!-in!-term */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    stack[-1] = v174;
    v174 = stack[-3];
    fn = elt(env, 10); /* qqe_arg2r */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    fn = elt(env, 9); /* qqe_eta!-in!-term */
    v174 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    v44 = v174;
    v174 = stack[-1];
    if (v174 == nil) goto v86;
    v174 = v44;
    if (!(v174 == nil)) goto v86;
    v44 = stack[0];
    v174 = elt(env, 1); /* neq */
    if (v44 == v174) goto v107;
    v174 = elt(env, 2); /* false */
    { popv(5); return onevalue(v174); }

v107:
    v174 = elt(env, 3); /* true */
    { popv(5); return onevalue(v174); }

v86:
    v174 = v44;
    if (v174 == nil) goto v114;
    v174 = stack[-1];
    if (!(v174 == nil)) goto v114;
    v44 = stack[0];
    v174 = elt(env, 1); /* neq */
    if (v44 == v174) goto v96;
    v174 = elt(env, 2); /* false */
    { popv(5); return onevalue(v174); }

v96:
    v174 = elt(env, 3); /* true */
    { popv(5); return onevalue(v174); }

v114:
    v174 = stack[-1];
    if (v174 == nil) goto v87;
    v174 = v44;
    if (v174 == nil) goto v87;
    v174 = stack[-2];
    fn = elt(env, 7); /* qqe_op */
    v44 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    v174 = elt(env, 5); /* equal */
    if (v44 == v174) goto v143;
    v174 = elt(env, 2); /* false */
    { popv(5); return onevalue(v174); }

v143:
    v174 = elt(env, 3); /* true */
    { popv(5); return onevalue(v174); }

v87:
    v174 = stack[-3];
    {
        popv(5);
        fn = elt(env, 11); /* rl_simpat */
        return (*qfn1(fn))(qenv(fn), v174);
    }
/* error exit handlers */
v159:
    popv(5);
    return nil;
}



/* Code for pasf_floor */

static Lisp_Object CC_pasf_floor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v132, v177;
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
    v116 = stack[-1];
    if (!consp(v116)) goto v62;
    v116 = stack[-1];
    v116 = qcar(v116);
    if (!(!consp(v116))) goto v46;

v62:
    v116 = stack[0];
    if (!consp(v116)) goto v93;
    v116 = stack[0];
    v116 = qcar(v116);
    if (!(!consp(v116))) goto v46;

v93:
    v116 = stack[-1];
    if (v116 == nil) goto v76;
    v132 = stack[-1];
    v116 = stack[0];
    v132 = Cremainder(v132, v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v116 = (Lisp_Object)1; /* 0 */
    if (v132 == v116) goto v41;
    v132 = stack[-1];
    v116 = stack[0];
    v132 = times2(v132, v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v116 = (Lisp_Object)1; /* 0 */
    v116 = (Lisp_Object)greaterp2(v132, v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v116 = v116 ? lisp_true : nil;
    env = stack[-2];
    if (v116 == nil) goto v137;
    v132 = stack[-1];
    v116 = stack[0];
    v116 = quot2(v132, v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    goto v92;

v92:
    fn = elt(env, 4); /* simp */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v116 = qcar(v116);
    { popv(3); return onevalue(v116); }

v137:
    v132 = stack[-1];
    v116 = stack[0];
    v116 = quot2(v132, v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    v116 = sub1(v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    goto v92;

v41:
    v132 = stack[-1];
    v116 = stack[0];
    v116 = quot2(v132, v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    goto v92;

v76:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v116); }

v46:
    v116 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v116 == nil)) goto v101;
    v177 = elt(env, 3); /* "pasf_floor: not a domain valued sf in input" 
*/
    v132 = stack[-1];
    v116 = stack[0];
    v116 = list3(v177, v132, v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    fn = elt(env, 5); /* lprie */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-2];
    goto v101;

v101:
    v116 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v116 = nil;
    { popv(3); return onevalue(v116); }
/* error exit handlers */
v32:
    popv(3);
    return nil;
}



/* Code for diffrd */

static Lisp_Object MS_CDECL CC_diffrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v118, v39;
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
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    v118 = qvalue(elt(env, 1)); /* char */
    v114 = elt(env, 2); /* (b v a r) */
    if (equal(v118, v114)) goto v123;
    v114 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v114;
    v114 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v114;
    goto v138;

v138:
    fn = elt(env, 5); /* mathml2 */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    stack[0] = v114;
    fn = elt(env, 4); /* lex */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    v39 = stack[0];
    v118 = stack[-2];
    v114 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* alg_df */
        return (*qfnn(fn))(qenv(fn), 3, v39, v118, v114);
    }

v123:
    fn = elt(env, 7); /* bvarrd */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    stack[-2] = v114;
    v114 = stack[-2];
    v114 = qcdr(v114);
    v114 = qcar(v114);
    stack[-1] = v114;
    v114 = stack[-2];
    v114 = qcar(v114);
    stack[-2] = v114;
    fn = elt(env, 4); /* lex */
    v114 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-3];
    goto v138;
/* error exit handlers */
v31:
    popv(4);
    return nil;
}



/* Code for rand!-comb */

static Lisp_Object CC_randKcomb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v163, v24;
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
    v163 = stack[-3];
    v183 = stack[-1];
    if (equal(v163, v183)) goto v93;
    stack[-2] = nil;
    v163 = stack[-1];
    v183 = stack[-3];
    v163 = difference2(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = stack[-3];
    v183 = (Lisp_Object)lessp2(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    v183 = v183 ? lisp_true : nil;
    env = stack[-5];
    if (v183 == nil) goto v185;
    stack[0] = stack[-1];
    v163 = stack[-1];
    v183 = stack[-3];
    v183 = difference2(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = CC_randKcomb(env, stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[-3] = v183;
    v183 = (Lisp_Object)1; /* 0 */
    stack[0] = v183;
    goto v33;

v33:
    v183 = stack[-1];
    v163 = sub1(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = stack[0];
    v183 = difference2(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = Lminusp(nil, v183);
    env = stack[-5];
    if (!(v183 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v163 = stack[0];
    v183 = stack[-3];
    v183 = Lmember(nil, v163, v183);
    if (!(v183 == nil)) goto v130;
    v163 = stack[0];
    v183 = stack[-2];
    v183 = cons(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[-2] = v183;
    goto v130;

v130:
    v183 = stack[0];
    v183 = add1(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[0] = v183;
    goto v33;

v185:
    v183 = (Lisp_Object)1; /* 0 */
    stack[0] = v183;
    goto v186;

v186:
    v183 = stack[-3];
    v163 = sub1(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = stack[0];
    v183 = difference2(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = Lminusp(nil, v183);
    env = stack[-5];
    if (!(v183 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v187:
    v183 = stack[-1];
    fn = elt(env, 2); /* random */
    v163 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v24 = v163;
    v183 = stack[-2];
    v183 = Lmember(nil, v163, v183);
    if (!(v183 == nil)) goto v187;
    v163 = v24;
    v183 = stack[-2];
    v183 = cons(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[-2] = v183;
    v183 = stack[0];
    v183 = add1(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[0] = v183;
    goto v186;

v93:
    v183 = (Lisp_Object)1; /* 0 */
    stack[-4] = v183;
    v183 = stack[-3];
    v163 = sub1(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = stack[-4];
    v183 = difference2(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = Lminusp(nil, v183);
    env = stack[-5];
    if (v183 == nil) goto v86;
    v183 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v183); }

v86:
    v183 = stack[-4];
    v183 = ncons(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[-1] = v183;
    stack[-2] = v183;
    goto v70;

v70:
    v183 = stack[-4];
    v183 = add1(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[-4] = v183;
    v183 = stack[-3];
    v163 = sub1(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = stack[-4];
    v183 = difference2(v163, v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = Lminusp(nil, v183);
    env = stack[-5];
    if (!(v183 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v183 = stack[-4];
    v183 = ncons(v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = Lrplacd(nil, stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v183 = stack[-1];
    v183 = qcdr(v183);
    stack[-1] = v183;
    goto v70;
/* error exit handlers */
v184:
    popv(6);
    return nil;
}



/* Code for symmetrize!-inds */

static Lisp_Object CC_symmetrizeKinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v208;
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
    v207 = (Lisp_Object)1; /* 0 */
    stack[-10] = v207;
    v207 = stack[-9];
    stack[-7] = v207;
    v207 = stack[-7];
    if (v207 == nil) goto v70;
    v207 = stack[-7];
    v207 = qcar(v207);
    v208 = v207;
    if (!consp(v208)) goto v57;
    stack[-3] = v207;
    v207 = stack[-3];
    if (v207 == nil) goto v67;
    v207 = stack[-3];
    v207 = qcar(v207);
    v208 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v207 = (*qfn2(fn))(qenv(fn), v208, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = qcar(v207);
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-1] = v207;
    stack[-2] = v207;
    goto v43;

v43:
    v207 = stack[-3];
    v207 = qcdr(v207);
    stack[-3] = v207;
    v207 = stack[-3];
    if (v207 == nil) goto v143;
    stack[0] = stack[-1];
    v207 = stack[-3];
    v207 = qcar(v207);
    v208 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v207 = (*qfn2(fn))(qenv(fn), v208, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = qcar(v207);
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = Lrplacd(nil, stack[0], v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = stack[-1];
    v207 = qcdr(v207);
    stack[-1] = v207;
    goto v43;

v143:
    v207 = stack[-2];
    goto v91;

v91:
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-5] = v207;
    stack[-6] = v207;
    goto v6;

v6:
    v207 = stack[-7];
    v207 = qcdr(v207);
    stack[-7] = v207;
    v207 = stack[-7];
    if (v207 == nil) goto v48;
    stack[-4] = stack[-5];
    v207 = stack[-7];
    v207 = qcar(v207);
    v208 = v207;
    if (!consp(v208)) goto v144;
    stack[-3] = v207;
    v207 = stack[-3];
    if (v207 == nil) goto v128;
    v207 = stack[-3];
    v207 = qcar(v207);
    v208 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v207 = (*qfn2(fn))(qenv(fn), v208, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = qcar(v207);
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-1] = v207;
    stack[-2] = v207;
    goto v154;

v154:
    v207 = stack[-3];
    v207 = qcdr(v207);
    stack[-3] = v207;
    v207 = stack[-3];
    if (v207 == nil) goto v141;
    stack[0] = stack[-1];
    v207 = stack[-3];
    v207 = qcar(v207);
    v208 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v207 = (*qfn2(fn))(qenv(fn), v208, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = qcar(v207);
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = Lrplacd(nil, stack[0], v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = stack[-1];
    v207 = qcdr(v207);
    stack[-1] = v207;
    goto v154;

v141:
    v207 = stack[-2];
    goto v33;

v33:
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = Lrplacd(nil, stack[-4], v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = stack[-5];
    v207 = qcdr(v207);
    stack[-5] = v207;
    goto v6;

v128:
    v207 = qvalue(elt(env, 1)); /* nil */
    goto v33;

v144:
    v208 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v207 = (*qfn2(fn))(qenv(fn), v208, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = qcar(v207);
    goto v33;

v48:
    v207 = stack[-6];
    goto v30;

v30:
    stack[-5] = v207;
    v207 = stack[-5];
    v207 = qcar(v207);
    if (!consp(v207)) goto v26;
    v207 = stack[-5];
    fn = elt(env, 3); /* indordln */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    fn = elt(env, 4); /* flatindl */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    goto v25;

v25:
    stack[0] = v207;
    v207 = stack[-9];
    v207 = qcar(v207);
    if (!consp(v207)) goto v210;
    v207 = stack[-9];
    fn = elt(env, 4); /* flatindl */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-9] = v207;
    goto v210;

v210:
    v208 = stack[-9];
    v207 = stack[0];
    fn = elt(env, 5); /* pair */
    v207 = (*qfn2(fn))(qenv(fn), v208, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-5] = v207;
    stack[-6] = (Lisp_Object)17; /* 1 */
    v207 = stack[-8];
    stack[-7] = v207;
    v207 = stack[-7];
    if (v207 == nil) goto v211;
    v207 = stack[-7];
    v207 = qcar(v207);
    stack[-1] = v207;
    v207 = stack[-5];
    if (v207 == nil) goto v212;
    v207 = stack[-5];
    v207 = qcar(v207);
    stack[0] = qcar(v207);
    v207 = stack[-10];
    v207 = add1(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-10] = v207;
    if (!(equal(stack[0], v207))) goto v212;
    v207 = stack[-5];
    v207 = qcar(v207);
    v207 = qcdr(v207);
    v208 = v207;
    v207 = stack[-5];
    v207 = qcdr(v207);
    stack[-5] = v207;
    v207 = v208;
    goto v213;

v213:
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-3] = v207;
    stack[-4] = v207;
    goto v73;

v73:
    v207 = stack[-7];
    v207 = qcdr(v207);
    stack[-7] = v207;
    v207 = stack[-7];
    if (v207 == nil) goto v214;
    stack[-2] = stack[-3];
    v207 = stack[-7];
    v207 = qcar(v207);
    stack[-1] = v207;
    v207 = stack[-5];
    if (v207 == nil) goto v215;
    v207 = stack[-5];
    v207 = qcar(v207);
    stack[0] = qcar(v207);
    v207 = stack[-10];
    v207 = add1(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    stack[-10] = v207;
    if (!(equal(stack[0], v207))) goto v215;
    v207 = stack[-5];
    v207 = qcar(v207);
    v207 = qcdr(v207);
    v208 = v207;
    v207 = stack[-5];
    v207 = qcdr(v207);
    stack[-5] = v207;
    v207 = v208;
    goto v216;

v216:
    v207 = ncons(v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = Lrplacd(nil, stack[-2], v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = stack[-3];
    v207 = qcdr(v207);
    stack[-3] = v207;
    goto v73;

v215:
    v207 = stack[-1];
    goto v216;

v214:
    v207 = stack[-4];
    goto v217;

v217:
    {
        Lisp_Object v218 = stack[-6];
        popv(12);
        return cons(v218, v207);
    }

v212:
    v207 = stack[-1];
    goto v213;

v211:
    v207 = qvalue(elt(env, 1)); /* nil */
    goto v217;

v26:
    v207 = stack[-5];
    fn = elt(env, 6); /* indordn */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    goto v25;

v67:
    v207 = qvalue(elt(env, 1)); /* nil */
    goto v91;

v57:
    v208 = stack[-8];
    fn = elt(env, 2); /* pnth */
    v207 = (*qfn2(fn))(qenv(fn), v208, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-11];
    v207 = qcar(v207);
    goto v91;

v70:
    v207 = qvalue(elt(env, 1)); /* nil */
    goto v30;
/* error exit handlers */
v209:
    popv(12);
    return nil;
}



/* Code for ev!-edgeloop */

static Lisp_Object CC_evKedgeloop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-edgeloop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v75 = v1;
    v76 = v0;
/* end of prologue */
    v86 = qvalue(elt(env, 1)); /* ndim!* */
    v76 = qcar(v76);
    v75 = Lassoc(nil, v76, v75);
    v75 = qcdr(v75);
    {
        fn = elt(env, 2); /* binc */
        return (*qfn2(fn))(qenv(fn), v86, v75);
    }
}



/* Code for fs!:prin!: */

static Lisp_Object CC_fsTprinT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138;
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
    v138 = elt(env, 1); /* "[" */
    fn = elt(env, 3); /* prin2!* */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-1];
    v138 = stack[0];
    v138 = qcdr(v138);
    fn = elt(env, 4); /* fs!:prin */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-1];
    v138 = elt(env, 2); /* "]" */
    {
        popv(2);
        fn = elt(env, 3); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v138);
    }
/* error exit handlers */
v119:
    popv(2);
    return nil;
}



/* Code for st_extract_symcells1 */

static Lisp_Object MS_CDECL CC_st_extract_symcells1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v179, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_extract_symcells1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_extract_symcells1");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    v223 = stack[0];
    v223 = qcdr(v223);
    v223 = qcar(v223);
    fn = elt(env, 3); /* listp */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    if (v223 == nil) goto v178;
    v223 = stack[0];
    stack[-6] = qcar(v223);
    v223 = stack[0];
    v223 = qcdr(v223);
    stack[-3] = v223;
    v223 = stack[-3];
    if (v223 == nil) goto v120;
    v223 = stack[-3];
    v223 = qcar(v223);
    v14 = v223;
    v179 = stack[-5];
    v223 = stack[-4];
    v223 = CC_st_extract_symcells1(env, 3, v14, v179, v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    v179 = v223;
    v179 = qcdr(v179);
    v179 = qcar(v179);
    stack[-5] = v179;
    v179 = v223;
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcar(v179);
    stack[-4] = v179;
    v179 = v223;
    v179 = qcar(v179);
    if (is_number(v179)) goto v87;
    v223 = qcar(v223);
    goto v136;

v136:
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    stack[-1] = v223;
    stack[-2] = v223;
    goto v31;

v31:
    v223 = stack[-3];
    v223 = qcdr(v223);
    stack[-3] = v223;
    v223 = stack[-3];
    if (v223 == nil) goto v135;
    stack[0] = stack[-1];
    v223 = stack[-3];
    v223 = qcar(v223);
    v14 = v223;
    v179 = stack[-5];
    v223 = stack[-4];
    v223 = CC_st_extract_symcells1(env, 3, v14, v179, v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    v179 = v223;
    v179 = qcdr(v179);
    v179 = qcar(v179);
    stack[-5] = v179;
    v179 = v223;
    v179 = qcdr(v179);
    v179 = qcdr(v179);
    v179 = qcar(v179);
    stack[-4] = v179;
    v179 = v223;
    v179 = qcar(v179);
    if (is_number(v179)) goto v38;
    v223 = qcar(v223);
    goto v155;

v155:
    v223 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    v223 = Lrplacd(nil, stack[0], v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    v223 = stack[-1];
    v223 = qcdr(v223);
    stack[-1] = v223;
    goto v31;

v38:
    v179 = elt(env, 2); /* !* */
    v223 = qcar(v223);
    v223 = list2(v179, v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    goto v155;

v135:
    v223 = stack[-2];
    goto v108;

v108:
    v223 = cons(stack[-6], v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    v14 = v223;
    v179 = stack[-5];
    v223 = stack[-4];
    popv(8);
    return list3(v14, v179, v223);

v87:
    v179 = elt(env, 2); /* !* */
    v223 = qcar(v223);
    v223 = list2(v179, v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    goto v136;

v120:
    v223 = qvalue(elt(env, 1)); /* nil */
    goto v108;

v178:
    stack[-1] = stack[-4];
    v179 = stack[0];
    v223 = stack[-5];
    stack[0] = cons(v179, v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-7];
    v223 = stack[-4];
    v223 = add1(v223);
    nil = C_nil;
    if (exception_pending()) goto v224;
    {
        Lisp_Object v225 = stack[-1];
        Lisp_Object v226 = stack[0];
        popv(8);
        return list3(v225, v226, v223);
    }
/* error exit handlers */
v224:
    popv(8);
    return nil;
}



/* Code for eval_uni_poly */

static Lisp_Object CC_eval_uni_poly(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v48, v135;
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
    v111 = stack[-2];
    if (!consp(v111)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v111 = stack[-2];
    v111 = qcar(v111);
    v111 = qcdr(v111);
    v135 = v111;
    v111 = stack[-2];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = qcdr(v111);
    v48 = v111;
    v111 = stack[-2];
    v111 = qcdr(v111);
    stack[-2] = v111;
    goto v81;

v81:
    v111 = stack[-2];
    if (!consp(v111)) goto v66;
    stack[-3] = v135;
    stack[0] = stack[-1];
    v111 = stack[-2];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = qcdr(v111);
    v111 = difference2(v48, v111);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v111 = Lexpt(nil, stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v48 = times2(stack[-3], v111);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v111 = stack[-2];
    v111 = qcar(v111);
    v111 = qcdr(v111);
    v111 = plus2(v48, v111);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v135 = v111;
    v111 = stack[-2];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = qcdr(v111);
    v48 = v111;
    v111 = stack[-2];
    v111 = qcdr(v111);
    stack[-2] = v111;
    goto v81;

v66:
    stack[0] = v135;
    v111 = stack[-1];
    v111 = Lexpt(nil, v111, v48);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v111 = times2(stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v135 = v111;
    v111 = stack[-2];
    if (v111 == nil) { popv(5); return onevalue(v135); }
    v48 = v135;
    v111 = stack[-2];
    v111 = plus2(v48, v111);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v135 = v111;
    { popv(5); return onevalue(v135); }
/* error exit handlers */
v175:
    popv(5);
    return nil;
}



/* Code for domainp_list */

static Lisp_Object CC_domainp_list(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v80;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domainp_list");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v79 = v0;
/* end of prologue */

v228:
    v80 = v79;
    v80 = (v80 == nil ? lisp_true : nil);
    if (!(v80 == nil)) return onevalue(v80);
    v80 = v79;
    v80 = qcar(v80);
    if (!consp(v80)) goto v70;
    v80 = v79;
    v80 = qcar(v80);
    v80 = qcar(v80);
    if (!consp(v80)) goto v70;
    v79 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v79);

v70:
    v79 = qcdr(v79);
    goto v228;
}



/* Code for update_components */

static Lisp_Object MS_CDECL CC_update_components(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v120, v161, v229;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "update_components");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for update_components");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v161 = v2;
    stack[0] = v1;
    v139 = v0;
/* end of prologue */
    stack[-1] = v139;
    goto v123;

v123:
    v139 = stack[-1];
    if (v139 == nil) { popv(3); return onevalue(v161); }
    v139 = stack[-1];
    v139 = qcar(v139);
    v120 = v139;
    v229 = v120;
    v139 = stack[0];
    v139 = Lassoc(nil, v229, v139);
    v229 = v139;
    if (v139 == nil) goto v86;
    v139 = v161;
    v139 = Lassoc(nil, v120, v139);
    if (!(v139 == nil)) goto v86;
    v139 = v229;
    v120 = v161;
    v139 = cons(v139, v120);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    v161 = v139;
    goto v86;

v86:
    v139 = stack[-1];
    v139 = qcdr(v139);
    stack[-1] = v139;
    goto v123;
/* error exit handlers */
v84:
    popv(3);
    return nil;
}



/* Code for rl_fvarl */

static Lisp_Object CC_rl_fvarl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119;
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
    v119 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_fvarl!* */
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    {
        Lisp_Object v30 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v30, v119);
    }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for mktag */

static Lisp_Object MS_CDECL CC_mktag(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktag");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktag");
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
    v87 = v0;
/* end of prologue */
    v88 = v87;
    if (v88 == nil) goto v129;
    v88 = v87;
    if (!consp(v88)) goto v123;
    v88 = v87;
    v160 = qcar(v88);
    v88 = elt(env, 2); /* texprec */
    v88 = get(v160, v88);
    env = stack[-4];
    if (!(v88 == nil)) goto v86;
    v88 = (Lisp_Object)15985; /* 999 */
    goto v86;

v86:
    stack[-3] = v88;
    v88 = v87;
    v160 = qcar(v88);
    v88 = qcdr(v87);
    v87 = stack[-3];
    fn = elt(env, 5); /* makefunc */
    v87 = (*qfnn(fn))(qenv(fn), 3, v160, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[0] = v87;
    v87 = stack[-1];
    if (v87 == nil) goto v52;
    v88 = stack[-2];
    v87 = stack[-3];
    if (!(equal(v88, v87))) goto v52;

v82:
    v88 = elt(env, 3); /* !\!( */
    v87 = stack[0];
    stack[0] = cons(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v87 = elt(env, 4); /* !\!) */
    v87 = ncons(v87);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    v87 = Lnconc(nil, stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v134;
    stack[0] = v87;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v52:
    v88 = stack[-3];
    v87 = stack[-2];
    v87 = (Lisp_Object)lessp2(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v87 = v87 ? lisp_true : nil;
    env = stack[-4];
    if (v87 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v82;

v123:
    {
        popv(5);
        fn = elt(env, 6); /* texexplode */
        return (*qfn1(fn))(qenv(fn), v87);
    }

v129:
    v87 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v87); }
/* error exit handlers */
v134:
    popv(5);
    return nil;
}



/* Code for get_dimension_in */

static Lisp_Object CC_get_dimension_in(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v6;
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
    v30 = v0;
/* end of prologue */
    v6 = elt(env, 1); /* id */
    fn = elt(env, 2); /* get_rep_matrix_in */
    v30 = (*qfn2(fn))(qenv(fn), v6, v30);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[0];
    fn = elt(env, 3); /* mk!+trace */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* change!+sq!+to!+int */
        return (*qfn1(fn))(qenv(fn), v30);
    }
/* error exit handlers */
v182:
    popv(1);
    return nil;
}



/* Code for iv_cutcongs1 */

static Lisp_Object CC_iv_cutcongs1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v57;
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

v93:
    v95 = stack[0];
    if (v95 == nil) goto v92;
    v57 = stack[-1];
    v95 = stack[0];
    v95 = qcar(v95);
    fn = elt(env, 3); /* iv_cutcongs2 */
    v95 = (*qfn2(fn))(qenv(fn), v57, v95);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-2];
    if (v95 == nil) goto v81;
    v95 = stack[0];
    v95 = qcdr(v95);
    stack[0] = v95;
    goto v93;

v81:
    v95 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v95); }

v92:
    v95 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v95); }
/* error exit handlers */
v85:
    popv(3);
    return nil;
}



/* Code for integralir */

static Lisp_Object MS_CDECL CC_integralir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v136;
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
    v136 = qvalue(elt(env, 1)); /* atts */
    v49 = elt(env, 2); /* name */
    fn = elt(env, 7); /* find */
    v49 = (*qfn2(fn))(qenv(fn), v136, v49);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    v49 = Lintern(nil, v49);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-1] = v49;
    v49 = elt(env, 3); /* (bvar x 1) */
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[0] = v49;
    v136 = stack[-1];
    v49 = elt(env, 5); /* defint */
    if (!(v136 == v49)) goto v75;
    fn = elt(env, 8); /* lex */
    v49 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v49 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    goto v75;

v75:
    fn = elt(env, 8); /* lex */
    v49 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v49 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v49;
    v49 = stack[-2];
    v49 = Lconsp(nil, v49);
    env = stack[-3];
    if (v49 == nil) goto v89;
    v49 = stack[-2];
    v136 = qcar(v49);
    v49 = elt(env, 6); /* lambda */
    if (!(v136 == v49)) goto v89;
    v49 = stack[-2];
    fn = elt(env, 10); /* lambdavar */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[0] = v49;
    v49 = stack[-2];
    fn = elt(env, 11); /* lambdafun */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v49;
    goto v89;

v89:
    v136 = stack[-1];
    v49 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = list2(v136, v49);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    v49 = stack[-2];
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    v49 = Lappend(nil, stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v103;
    {
        Lisp_Object v104 = stack[-1];
        popv(4);
        return Lappend(nil, v104, v49);
    }
/* error exit handlers */
v103:
    popv(4);
    return nil;
}



/* Code for nestzerop!: */

static Lisp_Object CC_nestzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v70;
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
    v70 = v0;
/* end of prologue */
    v64 = v70;
    v64 = integerp(v64);
    if (v64 == nil) goto v123;
    v64 = v70;
    fn = elt(env, 1); /* simp */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    errexit();
    goto v3;

v3:
    v64 = qcar(v64);
    v64 = (v64 == nil ? lisp_true : nil);
    return onevalue(v64);

v123:
    v64 = v70;
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    goto v3;
}



/* Code for latexprint */

static Lisp_Object CC_latexprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129;
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
    v129 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    v129 = stack[0];
    fn = elt(env, 2); /* latexprin */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* prinlaend */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v94:
    popv(2);
    return nil;
}



/* Code for force!-to!-dm */

static Lisp_Object CC_forceKtoKdm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v169, v34;
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
    v169 = v0;
/* end of prologue */

v99:
    v36 = v169;
    if (!consp(v36)) goto v94;
    v36 = v169;
    v36 = qcar(v36);
    if (!consp(v36)) goto v94;
    v36 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* prepf1 */
    v36 = (*qfn2(fn))(qenv(fn), v169, v36);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    v169 = v36;
    v36 = v169;
    if (v36 == nil) goto v56;
    v36 = v169;
    fn = elt(env, 8); /* replus */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    v169 = v36;
    goto v178;

v178:
    v36 = elt(env, 2); /* "number" */
    {
        popv(2);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v169, v36);
    }

v56:
    v36 = (Lisp_Object)1; /* 0 */
    v169 = v36;
    goto v178;

v94:
    v36 = v169;
    if (v36 == nil) goto v65;
    v36 = v169;
    if (is_number(v36)) goto v139;
    v36 = v169;
    v36 = Lconsp(nil, v36);
    env = stack[-1];
    if (v36 == nil) goto v82;
    v36 = v169;
    v34 = qcar(v36);
    v36 = qvalue(elt(env, 3)); /* dmode!* */
    if (equal(v34, v36)) { popv(2); return onevalue(v169); }
    else goto v82;

v82:
    v36 = v169;
    v36 = Lconsp(nil, v36);
    env = stack[-1];
    if (v36 == nil) goto v136;
    v36 = v169;
    v34 = qcar(v36);
    v36 = qvalue(elt(env, 3)); /* dmode!* */
    v36 = get(v34, v36);
    env = stack[-1];
    goto v49;

v49:
    v34 = v36;
    v36 = v34;
    if (v36 == nil) goto v116;
    stack[0] = v34;
    v36 = v169;
    v36 = ncons(v36);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    {
        Lisp_Object v124 = stack[0];
        popv(2);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v124, v36);
    }

v116:
    v36 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v36 == nil)) goto v32;
    v36 = elt(env, 6); /* "conversion error with " */
    v36 = list2(v36, v169);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    fn = elt(env, 11); /* lprie */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    goto v32;

v32:
    v36 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    v36 = nil;
    { popv(2); return onevalue(v36); }

v136:
    v36 = qvalue(elt(env, 1)); /* nil */
    goto v49;

v139:
    v34 = qvalue(elt(env, 3)); /* dmode!* */
    v36 = elt(env, 4); /* i2d */
    stack[0] = get(v34, v36);
    env = stack[-1];
    v36 = v169;
    v36 = ncons(v36);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    {
        Lisp_Object v155 = stack[0];
        popv(2);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v155, v36);
    }

v65:
    v36 = (Lisp_Object)1; /* 0 */
    v169 = v36;
    goto v99;
/* error exit handlers */
v201:
    popv(2);
    return nil;
}



/* Code for markedvarp */

static Lisp_Object CC_markedvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v119;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for markedvarp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v123 = v0;
/* end of prologue */
    v119 = elt(env, 1); /* !*marked!* */
        return Lflagp(nil, v123, v119);
}



/* Code for indordlp */

static Lisp_Object CC_indordlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v105, v176, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v1;
    v176 = v0;
/* end of prologue */

v93:
    v106 = v176;
    if (v106 == nil) goto v94;
    v106 = v105;
    if (v106 == nil) goto v78;
    v106 = v176;
    v82 = qcar(v106);
    v106 = v105;
    v106 = qcar(v106);
    if (equal(v82, v106)) goto v182;
    v106 = v176;
    v106 = qcar(v106);
    if (!consp(v106)) goto v56;
    v106 = v105;
    v106 = qcar(v106);
    if (!consp(v106)) goto v139;
    v106 = v176;
    v106 = qcar(v106);
    v106 = qcdr(v106);
    v106 = qcar(v106);
    v105 = qcar(v105);
    v105 = qcdr(v105);
    v105 = qcar(v105);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v106, v105);
    }

v139:
    v106 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v106);

v56:
    v106 = v105;
    v106 = qcar(v106);
    if (!consp(v106)) goto v115;
    v106 = qvalue(elt(env, 2)); /* t */
    return onevalue(v106);

v115:
    v106 = v176;
    v106 = qcar(v106);
    v105 = qcar(v105);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v106, v105);
    }

v182:
    v106 = v176;
    v106 = qcdr(v106);
    v176 = v106;
    v106 = v105;
    v106 = qcdr(v106);
    v105 = v106;
    goto v93;

v78:
    v106 = qvalue(elt(env, 2)); /* t */
    return onevalue(v106);

v94:
    v106 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v106);
}



/* Code for find_bubles1 */

static Lisp_Object CC_find_bubles1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v232, v56, v95, v57, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v92 = v1;
    v232 = v0;
/* end of prologue */
    v121 = qvalue(elt(env, 1)); /* nil */
    v56 = v232;
    v57 = qcar(v56);
    v95 = qvalue(elt(env, 1)); /* nil */
    v56 = v232;
    v56 = qcdr(v56);
    v56 = qcar(v56);
    v232 = qcdr(v232);
    v232 = qcdr(v232);
    v232 = qcar(v232);
    {
        fn = elt(env, 2); /* select_bubles */
        return (*qfnn(fn))(qenv(fn), 6, v121, v57, v95, v56, v232, v92);
    }
}



/* Code for subsq */

static Lisp_Object CC_subsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v140;
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
    v51 = stack[-1];
    v140 = qcar(v51);
    v51 = stack[0];
    fn = elt(env, 4); /* subf */
    v51 = (*qfn2(fn))(qenv(fn), v140, v51);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[-2] = v51;
    v51 = stack[-1];
    v140 = qcdr(v51);
    v51 = stack[0];
    fn = elt(env, 4); /* subf */
    v51 = (*qfn2(fn))(qenv(fn), v140, v51);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[-1] = v51;
    v51 = stack[-1];
    fn = elt(env, 5); /* subs2!* */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v51 = qcar(v51);
    if (!(v51 == nil)) goto v96;
    v51 = stack[-2];
    fn = elt(env, 5); /* subs2!* */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v51 = qcar(v51);
    if (v51 == nil) goto v57;
    v51 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v51 == nil)) goto v162;
    v51 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 6); /* lprie */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    goto v162;

v162:
    v51 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    goto v96;

v96:
    stack[0] = stack[-2];
    v51 = stack[-1];
    fn = elt(env, 7); /* invsq */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    {
        Lisp_Object v106 = stack[0];
        popv(4);
        fn = elt(env, 8); /* multsq */
        return (*qfn2(fn))(qenv(fn), v106, v51);
    }

v57:
    v51 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v51 == nil)) goto v108;
    v51 = elt(env, 2); /* "0/0 formed" */
    fn = elt(env, 6); /* lprie */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    goto v108;

v108:
    v51 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    goto v96;
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for groeb!=testb */

static Lisp_Object CC_groebMtestb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v175;
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
    v68 = stack[-1];
    fn = elt(env, 2); /* mo_comp */
    v175 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v68 = stack[0];
    v68 = qcar(v68);
    if (equal(v175, v68)) goto v75;
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v68); }

v75:
    stack[-2] = stack[-1];
    v175 = stack[0];
    v68 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v68 = (*qfn2(fn))(qenv(fn), v175, v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v68 = qcar(v68);
    fn = elt(env, 4); /* mo_divides!? */
    v68 = (*qfn2(fn))(qenv(fn), stack[-2], v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    if (v68 == nil) goto v178;
    v175 = stack[0];
    v68 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 3); /* pnth */
    v68 = (*qfn2(fn))(qenv(fn), v175, v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v68 = qcar(v68);
    fn = elt(env, 5); /* bas_dpoly */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    fn = elt(env, 6); /* dp_lmon */
    v175 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v68 = stack[-1];
    fn = elt(env, 7); /* mo_lcm */
    stack[-2] = (*qfn2(fn))(qenv(fn), v175, v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v175 = stack[0];
    v68 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v68 = (*qfn2(fn))(qenv(fn), v175, v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v68 = qcar(v68);
    fn = elt(env, 8); /* mo_equal!? */
    v68 = (*qfn2(fn))(qenv(fn), stack[-2], v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    if (v68 == nil) goto v88;
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v68); }

v88:
    v175 = stack[0];
    v68 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 3); /* pnth */
    v68 = (*qfn2(fn))(qenv(fn), v175, v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v68 = qcar(v68);
    fn = elt(env, 5); /* bas_dpoly */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    fn = elt(env, 6); /* dp_lmon */
    v175 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v68 = stack[-1];
    fn = elt(env, 7); /* mo_lcm */
    stack[-1] = (*qfn2(fn))(qenv(fn), v175, v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v175 = stack[0];
    v68 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v68 = (*qfn2(fn))(qenv(fn), v175, v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-3];
    v68 = qcar(v68);
    fn = elt(env, 8); /* mo_equal!? */
    v68 = (*qfn2(fn))(qenv(fn), stack[-1], v68);
    nil = C_nil;
    if (exception_pending()) goto v116;
    v68 = (v68 == nil ? lisp_true : nil);
    { popv(4); return onevalue(v68); }

v178:
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v68); }
/* error exit handlers */
v116:
    popv(4);
    return nil;
}



/* Code for monic */

static Lisp_Object CC_monic(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v68;
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
    v110 = stack[-3];
    v110 = Lreverse(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    stack[-3] = v110;
    v110 = qvalue(elt(env, 1)); /* varlist */
    v110 = Llength(nil, v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    stack[-1] = v110;
    v110 = (Lisp_Object)17; /* 1 */
    stack[0] = v110;
    goto v86;

v86:
    v68 = stack[-1];
    v110 = stack[0];
    v110 = difference2(v68, v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v110 = Lminusp(nil, v110);
    env = stack[-5];
    if (v110 == nil) goto v121;
    v110 = qvalue(elt(env, 1)); /* varlist */
    v110 = qcdr(v110);
    stack[-3] = v110;
    v110 = stack[-3];
    if (v110 == nil) goto v106;
    v110 = (Lisp_Object)1; /* 0 */
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    stack[-1] = v110;
    stack[-2] = v110;
    goto v140;

v140:
    v110 = stack[-3];
    v110 = qcdr(v110);
    stack[-3] = v110;
    v110 = stack[-3];
    if (v110 == nil) goto v87;
    stack[0] = stack[-1];
    v110 = (Lisp_Object)1; /* 0 */
    v110 = ncons(v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v110 = Lrplacd(nil, stack[0], v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v110 = stack[-1];
    v110 = qcdr(v110);
    stack[-1] = v110;
    goto v140;

v87:
    v110 = stack[-2];
    goto v97;

v97:
    v110 = (equal(stack[-4], v110) ? lisp_true : nil);
    { popv(6); return onevalue(v110); }

v106:
    v110 = qvalue(elt(env, 2)); /* nil */
    goto v97;

v121:
    v68 = stack[0];
    v110 = stack[-2];
    if (equal(v68, v110)) goto v56;
    v68 = stack[-3];
    v110 = stack[0];
    fn = elt(env, 3); /* pnth */
    v110 = (*qfn2(fn))(qenv(fn), v68, v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    v68 = qcar(v110);
    v110 = stack[-4];
    v110 = cons(v68, v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    stack[-4] = v110;
    goto v56;

v56:
    v110 = stack[0];
    v110 = add1(v110);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-5];
    stack[0] = v110;
    goto v86;
/* error exit handlers */
v132:
    popv(6);
    return nil;
}



/* Code for extract_numid */

static Lisp_Object CC_extract_numid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v54;
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

v228:
    v121 = stack[0];
    if (v121 == nil) goto v99;
    v121 = stack[0];
    v121 = qcar(v121);
    fn = elt(env, 2); /* !*id2num */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-2];
    v54 = v121;
    v121 = v54;
    if (v121 == nil) goto v92;
    stack[-1] = v54;
    v121 = stack[0];
    v121 = qcdr(v121);
    v121 = CC_extract_numid(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v117;
    {
        Lisp_Object v107 = stack[-1];
        popv(3);
        return cons(v107, v121);
    }

v92:
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v228;

v99:
    v121 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v121); }
/* error exit handlers */
v117:
    popv(3);
    return nil;
}



/* Code for can_rep_cell */

static Lisp_Object CC_can_rep_cell(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v86, v77;
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
    v77 = v1;
    v76 = v0;
/* end of prologue */
    v76 = qcdr(v76);
    v86 = qcar(v76);
    v76 = (Lisp_Object)17; /* 1 */
    stack[0] = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL)));
    v76 = v77;
    v76 = sub1(v76);
    nil = C_nil;
    if (exception_pending()) goto v80;
    v76 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL)));
    { popv(1); return onevalue(v76); }
/* error exit handlers */
v80:
    popv(1);
    return nil;
}



/* Code for max!-degree */

static Lisp_Object CC_maxKdegree(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v96, v97, v98;
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
    v96 = v1;
    v97 = v0;
/* end of prologue */

v129:
    v84 = v97;
    if (!consp(v84)) { popv(2); return onevalue(v96); }
    v84 = v97;
    v84 = qcar(v84);
    if (!consp(v84)) { popv(2); return onevalue(v96); }
    v98 = v96;
    v84 = v97;
    v84 = qcar(v84);
    v84 = qcar(v84);
    v84 = qcdr(v84);
    if (((int32_t)(v98)) > ((int32_t)(v84))) goto v178;
    v84 = v97;
    v84 = qcdr(v84);
    stack[0] = v84;
    v84 = v97;
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v96 = v97;
    v96 = qcar(v96);
    v96 = qcar(v96);
    v96 = qcdr(v96);
    v84 = CC_maxKdegree(env, v84, v96);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-1];
    v96 = v84;
    v84 = stack[0];
    v97 = v84;
    goto v129;

v178:
    v84 = v97;
    v84 = qcdr(v84);
    stack[0] = v84;
    v84 = v97;
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v84 = CC_maxKdegree(env, v84, v96);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-1];
    v96 = v84;
    v84 = stack[0];
    v97 = v84;
    goto v129;
/* error exit handlers */
v89:
    popv(2);
    return nil;
}



/* Code for list_assoc */

static Lisp_Object CC_list_assoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92, v232, v56;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list_assoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v92 = v1;
    v232 = v0;
/* end of prologue */

v93:
    v91 = v92;
    if (v91 == nil) return onevalue(v92);
    v91 = v92;
    v91 = qcar(v91);
    v56 = qcar(v91);
    v91 = v232;
    if (equal(v56, v91)) return onevalue(v92);
    v91 = v92;
    v91 = qcdr(v91);
    v92 = v91;
    goto v93;
}



/* Code for lto_insert */

static Lisp_Object CC_lto_insert(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v90, v91, v92;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_insert");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v1;
    v91 = v0;
/* end of prologue */
    v92 = v91;
    v81 = v90;
    v81 = Lmember(nil, v92, v81);
    if (!(v81 == nil)) return onevalue(v90);
    v81 = v91;
    return cons(v81, v90);
}



setup_type const u40_setup[] =
{
    {"makecoeffpairs1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs1},
    {"repr_a",                  CC_repr_a,      too_many_1,    wrong_no_1},
    {"ofsf_sacrel-and",         too_few_2,      CC_ofsf_sacrelKand,wrong_no_2},
    {"prsubsetrd",              CC_prsubsetrd,  too_many_1,    wrong_no_1},
    {"spmatsm*",                too_few_2,      CC_spmatsmH,   wrong_no_2},
    {"vdpmember",               too_few_2,      CC_vdpmember,  wrong_no_2},
    {"dipcontenti",             CC_dipcontenti, too_many_1,    wrong_no_1},
    {"gf2bf",                   CC_gf2bf,       too_many_1,    wrong_no_1},
    {"addnew",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_addnew},
    {"rl_qefsolset",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_qefsolset},
    {"sfto_yun-updecf",         CC_sfto_yunKupdecf,too_many_1, wrong_no_1},
    {"checkexp",                too_few_2,      CC_checkexp,   wrong_no_2},
    {"rule*",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_ruleH},
    {"qqe_simplbtat",           too_few_2,      CC_qqe_simplbtat,wrong_no_2},
    {"pasf_floor",              too_few_2,      CC_pasf_floor, wrong_no_2},
    {"diffrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffrd},
    {"rand-comb",               too_few_2,      CC_randKcomb,  wrong_no_2},
    {"symmetrize-inds",         too_few_2,      CC_symmetrizeKinds,wrong_no_2},
    {"ev-edgeloop",             too_few_2,      CC_evKedgeloop,wrong_no_2},
    {"fs:prin:",                CC_fsTprinT,    too_many_1,    wrong_no_1},
    {"st_extract_symcells1",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_extract_symcells1},
    {"eval_uni_poly",           too_few_2,      CC_eval_uni_poly,wrong_no_2},
    {"domainp_list",            CC_domainp_list,too_many_1,    wrong_no_1},
    {"update_components",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_update_components},
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
    {"list_assoc",              too_few_2,      CC_list_assoc, wrong_no_2},
    {"lto_insert",              too_few_2,      CC_lto_insert, wrong_no_2},
    {NULL, (one_args *)"u40", (two_args *)"21428 8383409 3238869", 0}
};

/* end of generated code */
