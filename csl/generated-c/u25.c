
/* $destdir\u25.c        Machine generated C code */

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


/* Code for cnrd */

static Lisp_Object MS_CDECL CC_cnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cnrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    v44 = qvalue(elt(env, 2)); /* atts */
    v43 = elt(env, 3); /* type */
    fn = elt(env, 16); /* find */
    v43 = (*qfn2(fn))(qenv(fn), v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v43 = Lintern(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-1] = v43;
    v44 = qvalue(elt(env, 2)); /* atts */
    v43 = elt(env, 4); /* base */
    fn = elt(env, 16); /* find */
    v43 = (*qfn2(fn))(qenv(fn), v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[0] = v43;
    fn = elt(env, 17); /* lex */
    v43 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v43 = qvalue(elt(env, 5)); /* char */
    stack[-4] = v43;
    fn = elt(env, 17); /* lex */
    v43 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v44 = stack[-1];
    v43 = elt(env, 6); /* constant */
    if (v44 == v43) goto v47;
    v43 = stack[-1];
    if (v43 == nil) goto v48;
    v44 = stack[-1];
    v43 = elt(env, 7); /* (real integer) */
    v43 = Lmember(nil, v44, v43);
    if (v43 == nil) goto v49;
    v43 = stack[0];
    if (v43 == nil) goto v50;
    stack[-3] = elt(env, 8); /* based_integer */
    stack[-2] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = stack[0];
    stack[0] = elt(env, 9); /* string */
    v43 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v44 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v43 = qvalue(elt(env, 1)); /* nil */
    v44 = list2star(stack[0], v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v43 = qvalue(elt(env, 1)); /* nil */
    v43 = list2star(stack[-1], v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    {
        Lisp_Object v51 = stack[-3];
        Lisp_Object v52 = stack[-2];
        popv(6);
        return list2star(v51, v52, v43);
    }

v50:
    v43 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v43);
    }

v49:
    v43 = stack[-1];
    v44 = Lintern(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v43 = elt(env, 10); /* (rational complex!-cartesian complex!-polar) 
*/
    v43 = Lmember(nil, v44, v43);
    if (v43 == nil) goto v53;
    fn = elt(env, 19); /* seprd */
    v43 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-2] = v43;
    v44 = stack[-1];
    v43 = elt(env, 11); /* rational */
    if (v44 == v43) goto v54;
    v44 = stack[-1];
    v43 = elt(env, 12); /* complex!-cartesian */
    if (v44 == v43) goto v55;
    v44 = stack[-1];
    v43 = elt(env, 14); /* complex!-polar */
    if (!(v44 == v43)) goto v53;
    fn = elt(env, 17); /* lex */
    v43 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-1] = elt(env, 15); /* complex_polar */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v43 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v45 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v44 = stack[-2];
    v43 = qvalue(elt(env, 1)); /* nil */
    v43 = list2star(v45, v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    {
        Lisp_Object v56 = stack[-1];
        Lisp_Object v57 = stack[0];
        popv(6);
        return list2star(v56, v57, v43);
    }

v53:
    v43 = nil;
    { popv(6); return onevalue(v43); }

v55:
    fn = elt(env, 17); /* lex */
    v43 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-1] = elt(env, 13); /* complex_cartesian */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v43 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v45 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v44 = stack[-2];
    v43 = qvalue(elt(env, 1)); /* nil */
    v43 = list2star(v45, v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    {
        Lisp_Object v58 = stack[-1];
        Lisp_Object v59 = stack[0];
        popv(6);
        return list2star(v58, v59, v43);
    }

v54:
    fn = elt(env, 17); /* lex */
    v43 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v43 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v44 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v43 = stack[-2];
    {
        popv(6);
        fn = elt(env, 11); /* rational */
        return (*qfn2(fn))(qenv(fn), v44, v43);
    }

v48:
    v43 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v43);
    }

v47:
    v43 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v43);
    }
/* error exit handlers */
v46:
    popv(6);
    return nil;
}



/* Code for gcd2 */

static Lisp_Object CC_gcd2(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd2");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    v67 = v60;
/* end of prologue */

v68:
    v66 = stack[0];
    v66 = Cremainder(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-1];
    v37 = v66;
    v67 = v37;
    v66 = (Lisp_Object)1; /* 0 */
    if (v67 == v66) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v67 = stack[0];
    v66 = v37;
    stack[0] = v66;
    goto v68;
/* error exit handlers */
v69:
    popv(2);
    return nil;
}



/* Code for intrdsortin */

static Lisp_Object CC_intrdsortin(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intrdsortin");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v60;
/* end of prologue */
    stack[-2] = nil;
    goto v80;

v80:
    v78 = stack[0];
    if (v78 == nil) goto v63;
    v78 = stack[-1];
    v79 = qcar(v78);
    v78 = stack[0];
    v78 = qcar(v78);
    v78 = qcar(v78);
    fn = elt(env, 1); /* !:difference */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    fn = elt(env, 2); /* !:minusp */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    if (v78 == nil) goto v82;
    v78 = stack[0];
    v79 = qcar(v78);
    v78 = stack[-2];
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    stack[-2] = v78;
    v78 = stack[0];
    v78 = qcdr(v78);
    stack[0] = v78;
    goto v80;

v82:
    v79 = stack[-1];
    v78 = stack[0];
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    {
        Lisp_Object v83 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v83, v78);
    }

v63:
    stack[0] = stack[-2];
    v78 = stack[-1];
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-3];
    {
        Lisp_Object v84 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v84, v78);
    }
/* error exit handlers */
v81:
    popv(4);
    return nil;
}



/* Code for smemberl */

static Lisp_Object CC_smemberl(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemberl");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v60;
/* end of prologue */
    stack[-2] = nil;
    goto v80;

v80:
    v73 = stack[-1];
    if (v73 == nil) goto v88;
    v73 = stack[0];
    if (v73 == nil) goto v88;
    v73 = stack[-1];
    v87 = qcar(v73);
    v73 = stack[0];
    fn = elt(env, 1); /* smember */
    v73 = (*qfn2(fn))(qenv(fn), v87, v73);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    if (v73 == nil) goto v38;
    v73 = stack[-1];
    v87 = qcar(v73);
    v73 = stack[-2];
    v73 = cons(v87, v73);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    stack[-2] = v73;
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    goto v80;

v38:
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    goto v80;

v88:
    v73 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v73);
    }
/* error exit handlers */
v89:
    popv(4);
    return nil;
}



/* Code for dummyp */

static Lisp_Object CC_dummyp(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dummyp");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v60;
/* end of prologue */
    v98 = (Lisp_Object)1; /* 0 */
    stack[-2] = v98;
    v98 = stack[-3];
    if (symbolp(v98)) goto v101;
    v98 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v98); }

v101:
    v98 = (Lisp_Object)17; /* 1 */
    stack[-4] = v98;
    goto v39;

v39:
    stack[0] = stack[-4];
    v98 = qvalue(elt(env, 2)); /* g_dvnames */
    fn = elt(env, 4); /* upbve */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v98 = (Lisp_Object)lesseq2(stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    v98 = v98 ? lisp_true : nil;
    env = stack[-5];
    if (v98 == nil) goto v70;
    stack[-1] = stack[-3];
    stack[0] = qvalue(elt(env, 2)); /* g_dvnames */
    v98 = stack[-4];
    v98 = sub1(v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v98 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v98/(16/CELL)));
    if (equal(stack[-1], v98)) goto v64;
    v98 = stack[-4];
    v98 = add1(v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    stack[-4] = v98;
    goto v39;

v64:
    v98 = stack[-4];
    stack[-2] = v98;
    v98 = qvalue(elt(env, 2)); /* g_dvnames */
    fn = elt(env, 4); /* upbve */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v98 = add1(v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    stack[-4] = v98;
    goto v39;

v70:
    v99 = stack[-2];
    v98 = (Lisp_Object)1; /* 0 */
    if (!(v99 == v98)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v98 = stack[-3];
    fn = elt(env, 5); /* ad_splitname */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-5];
    v99 = v98;
    v98 = v99;
    v98 = qcar(v98);
    v100 = qvalue(elt(env, 3)); /* g_dvbase */
    if (v98 == v100) goto v103;
    v98 = nil;
    { popv(6); return onevalue(v98); }

v103:
    v98 = v99;
    v98 = qcdr(v98);
    { popv(6); return onevalue(v98); }
/* error exit handlers */
v102:
    popv(6);
    return nil;
}



/* Code for reverse!-num1 */

static Lisp_Object CC_reverseKnum1(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reverse-num1");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v10;
    stack[0] = v60;
/* end of prologue */
    v129 = stack[0];
    v128 = (Lisp_Object)1; /* 0 */
    if (v129 == v128) goto v130;
    v129 = stack[-2];
    v128 = (Lisp_Object)17; /* 1 */
    if (v129 == v128) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v129 = stack[-2];
    v128 = (Lisp_Object)33; /* 2 */
    if (v129 == v128) goto v65;
    v129 = stack[-2];
    v128 = (Lisp_Object)49; /* 3 */
    if (v129 == v128) goto v35;
    v129 = stack[-2];
    v128 = (Lisp_Object)65; /* 4 */
    if (v129 == v128) goto v131;
    stack[-1] = (Lisp_Object)33; /* 2 */
    v129 = stack[-2];
    v128 = (Lisp_Object)33; /* 2 */
    v128 = quot2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v128 = Lexpt(nil, stack[-1], v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    stack[-3] = v128;
    v129 = stack[0];
    v128 = stack[-3];
    v128 = Ldivide(nil, v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    stack[-1] = v128;
    v128 = stack[-2];
    v128 = Levenp(nil, v128);
    env = stack[-4];
    if (!(v128 == nil)) goto v133;
    v129 = stack[-3];
    v128 = (Lisp_Object)33; /* 2 */
    v128 = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    stack[-3] = v128;
    goto v133;

v133:
    v128 = stack[-1];
    stack[0] = qcdr(v128);
    v129 = stack[-2];
    v128 = (Lisp_Object)33; /* 2 */
    v128 = quot2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v129 = CC_reverseKnum1(env, stack[0], v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v128 = stack[-3];
    stack[0] = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v128 = stack[-1];
    stack[-1] = qcar(v128);
    v128 = stack[-2];
    v129 = add1(v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v128 = (Lisp_Object)33; /* 2 */
    v128 = quot2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v128 = CC_reverseKnum1(env, stack[-1], v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    {
        Lisp_Object v134 = stack[0];
        popv(5);
        return plus2(v134, v128);
    }

v131:
    v129 = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v128 = stack[0];
    v128 = *(Lisp_Object *)((char *)v129 + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    { popv(5); return onevalue(v128); }

v35:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v129 = (Lisp_Object)33; /* 2 */
    v128 = stack[0];
    v128 = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v128 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    { popv(5); return onevalue(v128); }

v65:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v129 = (Lisp_Object)65; /* 4 */
    v128 = stack[0];
    v128 = times2(v129, v128);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v128 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v128/(16/CELL)));
    { popv(5); return onevalue(v128); }

v130:
    v128 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v128); }
/* error exit handlers */
v132:
    popv(5);
    return nil;
}



/* Code for sgn1 */

static Lisp_Object CC_sgn1(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v139;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sgn1");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v139 = v10;
    stack[-4] = v60;
/* end of prologue */
    v54 = stack[-4];
    if (!consp(v54)) goto v63;
    v54 = v139;
    v54 = qcar(v54);
    stack[-2] = v54;
    v54 = v139;
    v54 = qcdr(v54);
    stack[-1] = v54;
    v54 = (Lisp_Object)1; /* 0 */
    stack[-3] = v54;
    v54 = (Lisp_Object)17; /* 1 */
    stack[-5] = v54;
    v54 = stack[-4];
    v54 = qcdr(v54);
    stack[-4] = v54;
    goto v140;

v140:
    v139 = stack[-5];
    v54 = stack[-4];
    v54 = qcar(v54);
    stack[0] = times2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    v139 = stack[-2];
    v54 = stack[-3];
    v54 = times2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    v54 = plus2(stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    stack[-3] = v54;
    v139 = stack[-5];
    v54 = stack[-1];
    v54 = times2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    stack[-5] = v54;
    v54 = stack[-4];
    v54 = qcdr(v54);
    stack[-4] = v54;
    if (!(v54 == nil)) goto v140;
    v139 = stack[-3];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)greaterp2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v54 = v54 ? lisp_true : nil;
    env = stack[-6];
    if (v54 == nil) goto v141;
    v54 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v54); }

v141:
    v139 = stack[-3];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)lessp2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v54 = v54 ? lisp_true : nil;
    if (v54 == nil) goto v142;
    v54 = (Lisp_Object)-15; /* -1 */
    { popv(7); return onevalue(v54); }

v142:
    v54 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v54); }

v63:
    v139 = stack[-4];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)greaterp2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v54 = v54 ? lisp_true : nil;
    env = stack[-6];
    if (v54 == nil) goto v39;
    v54 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v54); }

v39:
    v139 = stack[-4];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)lessp2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v54 = v54 ? lisp_true : nil;
    if (v54 == nil) goto v125;
    v54 = (Lisp_Object)-15; /* -1 */
    { popv(7); return onevalue(v54); }

v125:
    v54 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v54); }
/* error exit handlers */
v22:
    popv(7);
    return nil;
}



/* Code for horner!-rule!-for!-one!-var */

static Lisp_Object MS_CDECL CC_hornerKruleKforKoneKvar(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, Lisp_Object v7,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v151, v152, v153, v110, v111, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-for-one-var");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-for-one-var");
#endif
    if (stack >= stacklimit)
    {
        push5(v34,v7,v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v60,v10,v6,v7,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v151 = v34;
    v152 = v7;
    v153 = v6;
    v110 = v10;
    v111 = v60;
/* end of prologue */

v155:
    v150 = v111;
    if (!consp(v150)) goto v156;
    v150 = v111;
    v150 = qcar(v150);
    if (!consp(v150)) goto v156;
    v150 = v111;
    v150 = qcar(v150);
    v150 = qcar(v150);
    v154 = qcar(v150);
    v150 = v110;
    if (!(equal(v154, v150))) goto v156;
    v150 = v111;
    v150 = qcar(v150);
    v150 = qcar(v150);
    v150 = qcdr(v150);
    stack[-5] = v150;
    v150 = v111;
    stack[-4] = qcdr(v150);
    stack[-3] = v110;
    stack[-2] = v153;
    v150 = v153;
    v150 = (Lisp_Object)zerop(v150);
    v150 = v150 ? lisp_true : nil;
    env = stack[-6];
    if (v150 == nil) goto v49;
    v150 = v111;
    v150 = qcar(v150);
    v150 = qcdr(v150);
    v151 = v150;
    goto v120;

v120:
    v150 = stack[-5];
    v111 = stack[-4];
    v110 = stack[-3];
    v153 = stack[-2];
    v152 = v151;
    v151 = v150;
    goto v155;

v49:
    v150 = v111;
    v150 = qcar(v150);
    stack[-1] = qcdr(v150);
    stack[0] = v152;
    v152 = v153;
    v150 = stack[-5];
    v150 = (Lisp_Object)(int32_t)((int32_t)v151 - (int32_t)v150 + TAG_FIXNUM);
    v150 = Lexpt(nil, v152, v150);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v151 = v150;
    v150 = v151;
    v150 = (Lisp_Object)zerop(v150);
    v150 = v150 ? lisp_true : nil;
    env = stack[-6];
    if (v150 == nil) goto v17;
    v150 = qvalue(elt(env, 1)); /* nil */
    goto v54;

v54:
    fn = elt(env, 2); /* multf */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    fn = elt(env, 3); /* addf */
    v150 = (*qfn2(fn))(qenv(fn), stack[-1], v150);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v151 = v150;
    goto v120;

v17:
    v150 = v151;
    goto v54;

v156:
    v150 = v153;
    v150 = (Lisp_Object)zerop(v150);
    v150 = v150 ? lisp_true : nil;
    env = stack[-6];
    if (!(v150 == nil)) { popv(7); return onevalue(v111); }
    stack[-1] = v111;
    stack[0] = v152;
    v150 = v153;
    v150 = Lexpt(nil, v150, v151);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    v151 = v150;
    v150 = v151;
    v150 = (Lisp_Object)zerop(v150);
    v150 = v150 ? lisp_true : nil;
    env = stack[-6];
    if (v150 == nil) goto v71;
    v150 = qvalue(elt(env, 1)); /* nil */
    goto v73;

v73:
    fn = elt(env, 2); /* multf */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-6];
    {
        Lisp_Object v104 = stack[-1];
        popv(7);
        fn = elt(env, 3); /* addf */
        return (*qfn2(fn))(qenv(fn), v104, v150);
    }

v71:
    v150 = v151;
    goto v73;
/* error exit handlers */
v109:
    popv(7);
    return nil;
}



/* Code for cl_identifyonoff */

static Lisp_Object CC_cl_identifyonoff(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object v7;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyonoff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v60;
/* end of prologue */
    v7 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v7; /* cl_identify!-atl!* */
    return onevalue(v7);
}



/* Code for multdfconst */

static Lisp_Object CC_multdfconst(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdfconst");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v60;
/* end of prologue */
    stack[-3] = nil;
    goto v80;

v80:
    v158 = stack[-1];
    if (v158 == nil) goto v68;
    v158 = stack[-2];
    v158 = qcar(v158);
    if (v158 == nil) goto v68;
    v158 = stack[-1];
    v158 = qcar(v158);
    stack[0] = qcar(v158);
    v72 = stack[-2];
    v158 = stack[-1];
    v158 = qcar(v158);
    v158 = qcdr(v158);
    fn = elt(env, 1); /* multsq */
    v158 = (*qfn2(fn))(qenv(fn), v72, v158);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    fn = elt(env, 2); /* subs2q */
    v72 = (*qfn1(fn))(qenv(fn), v158);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    v158 = stack[-3];
    v158 = acons(stack[0], v72, v158);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-4];
    stack[-3] = v158;
    v158 = stack[-1];
    v158 = qcdr(v158);
    stack[-1] = v158;
    goto v80;

v68:
    v158 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v158);
    }
/* error exit handlers */
v94:
    popv(5);
    return nil;
}



/* Code for expnd */

static Lisp_Object CC_expnd(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expnd");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v60;
/* end of prologue */
    v67 = qvalue(elt(env, 1)); /* !*really_off_exp */
    if (!(v67 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v67 = stack[0];
    fn = elt(env, 3); /* expnd1 */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    stack[0] = v67;
    v67 = qvalue(elt(env, 2)); /* !*sub2 */
    if (v67 == nil) goto v65;
    v67 = stack[0];
    fn = elt(env, 4); /* subs2f */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    v38 = v67;
    v37 = qcdr(v67);
    v67 = (Lisp_Object)17; /* 1 */
    if (!(v37 == v67)) goto v65;
    v67 = v38;
    v67 = qcar(v67);
    goto v63;

v63:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    { popv(3); return onevalue(v67); }

v65:
    v67 = stack[0];
    goto v63;
/* error exit handlers */
v95:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    popv(3);
    return nil;
}



/* Code for cl_susiupdknowl2 */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl2(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v167, v168, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_susiupdknowl2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl2");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v60,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v6;
    stack[-5] = v10;
    stack[-6] = v60;
/* end of prologue */
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v166 = stack[-5];
    stack[-2] = v166;
    v166 = qvalue(elt(env, 1)); /* nil */
    v169 = v166;
    v166 = stack[-5];
    v168 = v166;
    goto v76;

v76:
    v166 = v168;
    if (v166 == nil) goto v42;
    v166 = v168;
    v166 = qcar(v166);
    v167 = stack[-6];
    if (!(equal(v167, v166))) goto v97;
    v166 = lisp_true;
    v169 = v166;
    goto v97;

v97:
    v166 = v168;
    v166 = qcdr(v166);
    v168 = v166;
    goto v76;

v42:
    v166 = v169;
    if (!(v166 == nil)) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }

v94:
    v166 = stack[-2];
    if (v166 == nil) goto v114;
    v166 = stack[-2];
    v166 = qcar(v166);
    stack[-7] = v166;
    v166 = stack[-2];
    v166 = qcdr(v166);
    stack[-2] = v166;
    v167 = stack[-7];
    v166 = stack[-6];
    fn = elt(env, 4); /* rl_susibin */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-8];
    stack[-3] = v166;
    v167 = stack[-3];
    v166 = elt(env, 2); /* false */
    if (v167 == v166) goto v81;
    v168 = stack[-3];
    v167 = stack[-5];
    v166 = stack[-7];
    fn = elt(env, 5); /* cl_susiinter */
    v166 = (*qfnn(fn))(qenv(fn), 3, v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-8];
    stack[-3] = v166;
    v167 = stack[0];
    v166 = stack[-3];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    v166 = Lnconc(nil, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-8];
    stack[0] = v166;
    v166 = stack[-3];
    v166 = qcar(v166);
    stack[-5] = v166;
    v166 = stack[-3];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    if (!(v166 == nil)) goto v170;

v170:
    v166 = stack[-3];
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcdr(v166);
    v166 = qcar(v166);
    if (v166 == nil) goto v94;
    v166 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v166;
    v166 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v166;
    goto v94;

v81:
    v166 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v166;
    goto v94;

v114:
    v167 = stack[-3];
    v166 = elt(env, 2); /* false */
    if (v167 == v166) goto v171;
    v166 = stack[-1];
    if (!(v166 == nil)) goto v154;
    v167 = stack[-6];
    v166 = stack[-5];
    v166 = cons(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-8];
    stack[-5] = v166;
    goto v154;

v154:
    v166 = stack[0];
    if (v166 == nil) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v166 = stack[0];
    v168 = qcar(v166);
    v167 = stack[-5];
    v166 = stack[-4];
    v166 = CC_cl_susiupdknowl2(env, 3, v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-8];
    stack[-5] = v166;
    v167 = stack[-5];
    v166 = elt(env, 2); /* false */
    if (v167 == v166) goto v172;
    v166 = stack[0];
    v166 = qcdr(v166);
    stack[0] = v166;
    goto v154;

v172:
    v166 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v166;
    goto v154;

v171:
    v166 = elt(env, 2); /* false */
    { popv(9); return onevalue(v166); }
/* error exit handlers */
v44:
    popv(9);
    return nil;
}



/* Code for expvec2a */

static Lisp_Object CC_expvec2a(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expvec2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v101 = v60;
/* end of prologue */
    v159 = v101;
    v101 = qvalue(elt(env, 1)); /* dipvars!* */
    {
        fn = elt(env, 2); /* expvec2a1 */
        return (*qfn2(fn))(qenv(fn), v159, v101);
    }
}



/* Code for divide!-by!-power!-of!-ten */

static Lisp_Object CC_divideKbyKpowerKofKten(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v139, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divide-by-power-of-ten");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v10;
    stack[-3] = v60;
/* end of prologue */
    v139 = stack[-2];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)lessp2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v54 = v54 ? lisp_true : nil;
    env = stack[-5];
    if (v54 == nil) goto v97;
    stack[0] = (Lisp_Object)1; /* 0 */
    v139 = elt(env, 1); /* "Invalid argument to" */
    v54 = elt(env, 0); /* divide!-by!-power!-of!-ten */
    v54 = list2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    {
        Lisp_Object v145 = stack[0];
        popv(6);
        fn = elt(env, 6); /* error */
        return (*qfn2(fn))(qenv(fn), v145, v54);
    }

v97:
    v54 = qvalue(elt(env, 2)); /* bften!* */
    stack[-4] = v54;
    goto v95;

v95:
    v139 = stack[-2];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)greaterp2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v54 = v54 ? lisp_true : nil;
    env = stack[-5];
    if (v54 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v54 = stack[-2];
    v54 = Levenp(nil, v54);
    env = stack[-5];
    if (!(v54 == nil)) goto v137;
    v144 = stack[-3];
    v139 = stack[-4];
    v54 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 7); /* divide!: */
    v54 = (*qfnn(fn))(qenv(fn), 3, v144, v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    fn = elt(env, 8); /* csl_normbf */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    stack[-3] = v54;
    goto v137;

v137:
    v139 = stack[-2];
    v54 = (Lisp_Object)-15; /* -1 */
    v54 = ash(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    stack[-2] = v54;
    stack[-1] = elt(env, 5); /* !:rd!: */
    v54 = stack[-4];
    v54 = qcdr(v54);
    v139 = qcar(v54);
    v54 = stack[-4];
    v54 = qcdr(v54);
    v54 = qcar(v54);
    stack[0] = times2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v54 = stack[-4];
    v54 = qcdr(v54);
    v139 = qcdr(v54);
    v54 = stack[-4];
    v54 = qcdr(v54);
    v54 = qcdr(v54);
    v54 = plus2(v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v139 = list2star(stack[-1], stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    v54 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 9); /* cut!:mt */
    v54 = (*qfn2(fn))(qenv(fn), v139, v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    fn = elt(env, 8); /* csl_normbf */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-5];
    stack[-4] = v54;
    goto v95;
/* error exit handlers */
v22:
    popv(6);
    return nil;
}



/* Code for prop!-simp2 */

static Lisp_Object CC_propKsimp2(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v140;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp2");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v10;
    stack[-3] = v60;
/* end of prologue */
    v82 = stack[-2];
    if (!consp(v82)) goto v62;
    v140 = stack[-2];
    v82 = stack[-3];
    v82 = Lmember(nil, v140, v82);
    goto v159;

v159:
    stack[-4] = v82;
    if (v82 == nil) goto v124;
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v82 = stack[-3];
    stack[0] = Llength(nil, v82);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v82 = stack[-4];
    v82 = Llength(nil, v82);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v82 = difference2(stack[0], v82);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = Lexpt(nil, stack[-1], v82);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v140 = stack[-2];
    v82 = stack[-3];
    v82 = Ldelete(nil, v140, v82);
    nil = C_nil;
    if (exception_pending()) goto v78;
    {
        Lisp_Object v79 = stack[0];
        popv(6);
        return cons(v79, v82);
    }

v124:
    v82 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v82); }

v62:
    v82 = qvalue(elt(env, 1)); /* nil */
    goto v159;
/* error exit handlers */
v78:
    popv(6);
    return nil;
}



/* Code for symbvarlst */

static Lisp_Object MS_CDECL CC_symbvarlst(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v117, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "symbvarlst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbvarlst");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v60,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v29 = v6;
    stack[-4] = v10;
    v53 = v60;
/* end of prologue */
    v117 = v29;
    v29 = elt(env, 1); /* symbolic */
    if (v117 == v29) goto v101;
    v29 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v29); }

v101:
    v29 = v53;
    stack[-5] = v29;
    goto v156;

v156:
    v29 = stack[-5];
    if (v29 == nil) goto v39;
    v29 = stack[-5];
    v29 = qcar(v29);
    v29 = Lconsp(nil, v29);
    env = stack[-6];
    if (v29 == nil) goto v37;
    v29 = stack[-5];
    v29 = qcar(v29);
    v29 = qcar(v29);
    goto v74;

v74:
    stack[0] = v29;
    v29 = stack[0];
    v29 = Lsymbol_specialp(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-6];
    if (!(v29 == nil)) goto v88;
    v29 = stack[0];
    v29 = Lsymbol_globalp(nil, v29);
    env = stack[-6];
    if (!(v29 == nil)) goto v88;
    v117 = stack[0];
    v29 = stack[-4];
    v29 = Lsmemq(nil, v117, v29);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-6];
    if (!(v29 == nil)) goto v88;
    v29 = qvalue(elt(env, 3)); /* !*novarmsg */
    if (!(v29 == nil)) goto v88;
    v29 = qvalue(elt(env, 4)); /* !*msg */
    if (v29 == nil) goto v88;
    stack[-3] = elt(env, 5); /* "***" */
    stack[-2] = elt(env, 6); /* "local variable" */
    stack[-1] = stack[0];
    stack[0] = elt(env, 7); /* "in procedure" */
    v117 = qvalue(elt(env, 8)); /* fname!* */
    v29 = elt(env, 9); /* "not used" */
    v29 = list2(v117, v29);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-6];
    v29 = list3star(stack[-2], stack[-1], stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-6];
    fn = elt(env, 10); /* lpriw */
    v29 = (*qfn2(fn))(qenv(fn), stack[-3], v29);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-6];
    goto v88;

v88:
    v29 = stack[-5];
    v29 = qcdr(v29);
    stack[-5] = v29;
    goto v156;

v37:
    v29 = stack[-5];
    v29 = qcar(v29);
    goto v74;

v39:
    v29 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v29); }
/* error exit handlers */
v119:
    popv(7);
    return nil;
}



/* Code for sqhorner!* */

static Lisp_Object CC_sqhornerH(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqhorner*");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v60;
/* end of prologue */
    v126 = qvalue(elt(env, 1)); /* !*horner */
    if (v126 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v65 = qvalue(elt(env, 2)); /* ordl!* */
    v126 = qvalue(elt(env, 3)); /* kord!* */
    v126 = Lappend(nil, v65, v126);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    stack[-2] = qvalue(elt(env, 3)); /* kord!* */
    qvalue(elt(env, 3)) = v126; /* kord!* */
    v126 = stack[-1];
    v126 = qcar(v126);
    fn = elt(env, 4); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    v126 = stack[-1];
    v126 = qcdr(v126);
    fn = elt(env, 4); /* reorder */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    fn = elt(env, 5); /* hornerf */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    v126 = cons(stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    fn = elt(env, 6); /* hornersq */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* kord!* */
    { popv(4); return onevalue(v126); }
/* error exit handlers */
v38:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* kord!* */
    popv(4);
    return nil;
v37:
    popv(4);
    return nil;
}



/* Code for split_cov_cont_ids */

static Lisp_Object CC_split_cov_cont_ids(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v50, v122;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_cov_cont_ids");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v60;
/* end of prologue */
    stack[-2] = nil;
    stack[0] = nil;
    goto v156;

v156:
    v179 = stack[-1];
    if (v179 == nil) goto v180;
    v179 = stack[-1];
    v179 = qcar(v179);
    v122 = v179;
    v50 = v122;
    v179 = elt(env, 2); /* minus */
    if (!consp(v50)) goto v88;
    v50 = qcar(v50);
    if (!(v50 == v179)) goto v88;
    v179 = v122;
    v179 = qcdr(v179);
    v50 = qcar(v179);
    v179 = stack[-2];
    v179 = cons(v50, v179);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    stack[-2] = v179;
    goto v77;

v77:
    v179 = stack[-1];
    v179 = qcdr(v179);
    stack[-1] = v179;
    goto v156;

v88:
    v50 = v122;
    v179 = stack[0];
    v179 = cons(v50, v179);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    stack[0] = v179;
    goto v77;

v180:
    v179 = stack[-2];
    v50 = Lnreverse(nil, v179);
    env = stack[-3];
    v179 = stack[0];
    v179 = Lnreverse(nil, v179);
    popv(4);
    return list2(v50, v179);
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for giplus!: */

static Lisp_Object CC_giplusT(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v10;
    stack[-2] = v60;
/* end of prologue */
    stack[-3] = elt(env, 1); /* !:gi!: */
    v66 = stack[-2];
    v66 = qcdr(v66);
    v67 = qcar(v66);
    v66 = stack[-1];
    v66 = qcdr(v66);
    v66 = qcar(v66);
    stack[0] = plus2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-4];
    v66 = stack[-2];
    v66 = qcdr(v66);
    v67 = qcdr(v66);
    v66 = stack[-1];
    v66 = qcdr(v66);
    v66 = qcdr(v66);
    v66 = plus2(v67, v66);
    nil = C_nil;
    if (exception_pending()) goto v95;
    {
        Lisp_Object v88 = stack[-3];
        Lisp_Object v48 = stack[0];
        popv(5);
        return list2star(v88, v48, v66);
    }
/* error exit handlers */
v95:
    popv(5);
    return nil;
}



/* Code for dfconst */

static Lisp_Object CC_dfconst(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfconst");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v60;
/* end of prologue */
    v174 = stack[0];
    v174 = qcar(v174);
    if (v174 == nil) goto v34;
    v174 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 3); /* vp2 */
    v127 = (*qfn1(fn))(qenv(fn), v174);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v174 = stack[0];
    v174 = cons(v127, v174);
    nil = C_nil;
    if (exception_pending()) goto v39;
    popv(2);
    return ncons(v174);

v34:
    v174 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v174); }
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for cl_sacat */

static Lisp_Object MS_CDECL CC_cl_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v181, v174;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sacat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v6;
    v181 = v10;
    v174 = v60;
/* end of prologue */
    v77 = v174;
    if (equal(v77, v181)) goto v80;
    v77 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v77);

v80:
    v77 = elt(env, 1); /* keep */
    return onevalue(v77);
}



/* Code for cl_susicpknowl */

static Lisp_Object CC_cl_susicpknowl(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v140;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susicpknowl");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v82 = v60;
/* end of prologue */
    stack[-3] = v82;
    v82 = stack[-3];
    if (v82 == nil) goto v159;
    v82 = stack[-3];
    v82 = qcar(v82);
    v140 = v82;
    v140 = qcar(v140);
    v82 = qcdr(v82);
    v82 = cons(v140, v82);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    stack[-1] = v82;
    stack[-2] = v82;
    goto v182;

v182:
    v82 = stack[-3];
    v82 = qcdr(v82);
    stack[-3] = v82;
    v82 = stack[-3];
    if (v82 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v82 = stack[-3];
    v82 = qcar(v82);
    v140 = v82;
    v140 = qcar(v140);
    v82 = qcdr(v82);
    v82 = cons(v140, v82);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v82 = Lrplacd(nil, stack[0], v82);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-4];
    v82 = stack[-1];
    v82 = qcdr(v82);
    stack[-1] = v82;
    goto v182;

v159:
    v82 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v82); }
/* error exit handlers */
v71:
    popv(5);
    return nil;
}



/* Code for matrixrowom */

static Lisp_Object CC_matrixrowom(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowom");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v60;
/* end of prologue */
    v85 = stack[0];
    if (v85 == nil) goto v130;
    v85 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 6); /* printout */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v85 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* indent!* */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v85 = elt(env, 3); /* "<OMS cd=""linalg1"" name=""matrixrow""/>" */
    fn = elt(env, 6); /* printout */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v85 = stack[0];
    v85 = qcar(v85);
    fn = elt(env, 8); /* multiom */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v85 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* indent!* */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v85 = elt(env, 5); /* "</OMA>" */
    fn = elt(env, 6); /* printout */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v85 = stack[0];
    v85 = qcdr(v85);
    v85 = CC_matrixrowom(env, v85);
    nil = C_nil;
    if (exception_pending()) goto v75;
    goto v130;

v130:
    v85 = nil;
    { popv(2); return onevalue(v85); }
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for crn!:prep */

static Lisp_Object CC_crnTprep(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:prep");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v40 = v60;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !:rn!: */
    v85 = v40;
    v85 = qcdr(v85);
    stack[0] = qcar(v85);
    v85 = elt(env, 1); /* !:rn!: */
    v40 = qcdr(v40);
    v40 = qcdr(v40);
    v40 = cons(v85, v40);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v40 = acons(stack[-1], stack[0], v40);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 2); /* crnprep1 */
        return (*qfn1(fn))(qenv(fn), v40);
    }
/* error exit handlers */
v74:
    popv(3);
    return nil;
}



/* Code for matrixp */

static Lisp_Object CC_matrixp(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v76 = v60;
/* end of prologue */
    v77 = v76;
    v76 = elt(env, 1); /* mat */
    if (!consp(v77)) goto v34;
    v77 = qcar(v77);
    if (!(v77 == v76)) goto v34;
    v76 = qvalue(elt(env, 3)); /* t */
    return onevalue(v76);

v34:
    v76 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v76);
}



/* Code for dm!-mkfloat */

static Lisp_Object CC_dmKmkfloat(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86, v75;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-mkfloat");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v86 = v60;
/* end of prologue */
    v85 = v86;
    v85 = Lintegerp(nil, v85);
    env = stack[0];
    if (v85 == nil) { popv(1); return onevalue(v86); }
    v75 = elt(env, 1); /* !:rd!: */
    v85 = elt(env, 2); /* i2d */
    v85 = get(v75, v85);
        popv(1);
        return Lapply1(nil, v85, v86);
}



/* Code for dip!-nc!-ev!-prod1 */

static Lisp_Object MS_CDECL CC_dipKncKevKprod1(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67, v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip-nc-ev-prod1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip-nc-ev-prod1");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v60,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v67 = v6;
    v37 = v10;
    v38 = v60;
/* end of prologue */
    v66 = v38;
    if (v66 == nil) { popv(3); return onevalue(v67); }
    v66 = v38;
    stack[-1] = qcar(v66);
    stack[0] = v37;
    v66 = v38;
    v66 = qcdr(v66);
    v37 = (Lisp_Object)((int32_t)(v37) + 0x10);
    v66 = CC_dipKncKevKprod1(env, 3, v66, v37, v67);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    {
        Lisp_Object v88 = stack[-1];
        Lisp_Object v48 = stack[0];
        popv(3);
        fn = elt(env, 1); /* dip!-nc!-ev!-prod2 */
        return (*qfnn(fn))(qenv(fn), 3, v88, v48, v66);
    }
/* error exit handlers */
v95:
    popv(3);
    return nil;
}



/* Code for inprinla */

static Lisp_Object MS_CDECL CC_inprinla(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "inprinla");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inprinla");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v60,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v10;
    stack[-2] = v60;
/* end of prologue */
    v170 = stack[-2];
    v141 = elt(env, 1); /* alt */
    v141 = get(v170, v141);
    env = stack[-4];
    if (!(v141 == nil)) goto v182;
    v141 = stack[0];
    v170 = qcar(v141);
    v141 = stack[-1];
    fn = elt(env, 4); /* maprintla */
    v141 = (*qfn2(fn))(qenv(fn), v170, v141);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    goto v80;

v80:
    v141 = stack[0];
    v141 = qcdr(v141);
    stack[0] = v141;
    goto v182;

v182:
    v141 = stack[0];
    if (v141 == nil) goto v126;
    v141 = stack[0];
    v141 = qcar(v141);
    if (!consp(v141)) goto v67;
    stack[-3] = stack[-2];
    v141 = stack[0];
    v141 = qcar(v141);
    v170 = qcar(v141);
    v141 = elt(env, 1); /* alt */
    v141 = Lget(nil, v170, v141);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    if (!(stack[-3] == v141)) goto v67;
    v141 = stack[0];
    v170 = qcar(v141);
    v141 = stack[-1];
    fn = elt(env, 4); /* maprintla */
    v141 = (*qfn2(fn))(qenv(fn), v170, v141);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    goto v80;

v67:
    v141 = stack[-2];
    fn = elt(env, 5); /* oprinla */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v141 = stack[0];
    v170 = qcar(v141);
    v141 = elt(env, 3); /* minus */
    if (!consp(v170)) goto v98;
    v170 = qcar(v170);
    if (!(v170 == v141)) goto v98;
    v141 = stack[0];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    v141 = qcar(v141);
    if (!(is_number(v141))) goto v98;
    v141 = stack[0];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    v141 = qcar(v141);
    v141 = negate(v141);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v170 = v141;
    goto v122;

v122:
    v141 = stack[-1];
    fn = elt(env, 4); /* maprintla */
    v141 = (*qfn2(fn))(qenv(fn), v170, v141);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    goto v80;

v98:
    v141 = stack[0];
    v141 = qcar(v141);
    v170 = v141;
    goto v122;

v126:
    v141 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v141); }
/* error exit handlers */
v24:
    popv(5);
    return nil;
}



/* Code for formrlis */

static Lisp_Object MS_CDECL CC_formrlis(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v105, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formrlis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formrlis");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v60,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v187 = v6;
    stack[-1] = v10;
    stack[-2] = v60;
/* end of prologue */
    v187 = stack[-2];
    v105 = qcar(v187);
    v187 = elt(env, 1); /* flagop */
    v187 = Lflagp(nil, v105, v187);
    env = stack[-4];
    if (v187 == nil) goto v76;
    v187 = stack[-2];
    v187 = qcdr(v187);
    fn = elt(env, 8); /* idlistp */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    if (v187 == nil) goto v189;
    stack[-3] = elt(env, 7); /* flag */
    stack[0] = elt(env, 2); /* list */
    v187 = stack[-2];
    v188 = qcdr(v187);
    v105 = stack[-1];
    v187 = elt(env, 4); /* algebraic */
    fn = elt(env, 9); /* formlis */
    v187 = (*qfnn(fn))(qenv(fn), 3, v188, v105, v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    stack[0] = cons(stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v187 = stack[-2];
    v187 = qcar(v187);
    v187 = Lmkquote(nil, v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    {
        Lisp_Object v133 = stack[-3];
        Lisp_Object v149 = stack[0];
        popv(5);
        return list3(v133, v149, v187);
    }

v189:
    v105 = elt(env, 5); /* !*comma!* */
    v187 = stack[-2];
    v187 = qcdr(v187);
    v105 = cons(v105, v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v187 = elt(env, 6); /* "identifier list" */
    {
        popv(5);
        fn = elt(env, 10); /* typerr */
        return (*qfn2(fn))(qenv(fn), v105, v187);
    }

v76:
    v187 = stack[-2];
    stack[-3] = qcar(v187);
    stack[0] = elt(env, 2); /* list */
    v187 = stack[-2];
    v105 = qcar(v187);
    v187 = elt(env, 3); /* share */
    if (v105 == v187) goto v65;
    v187 = stack[-2];
    v188 = qcdr(v187);
    v105 = stack[-1];
    v187 = elt(env, 4); /* algebraic */
    fn = elt(env, 9); /* formlis */
    v187 = (*qfnn(fn))(qenv(fn), 3, v188, v105, v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    goto v74;

v74:
    v187 = cons(stack[0], v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    {
        Lisp_Object v150 = stack[-3];
        popv(5);
        return list2(v150, v187);
    }

v65:
    stack[-1] = nil;
    v187 = stack[-2];
    v187 = qcdr(v187);
    stack[-2] = v187;
    goto v87;

v87:
    v187 = stack[-2];
    if (v187 == nil) goto v180;
    v187 = stack[-2];
    v187 = qcar(v187);
    v105 = Lmkquote(nil, v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    v187 = stack[-1];
    v187 = cons(v105, v187);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-4];
    stack[-1] = v187;
    v187 = stack[-2];
    v187 = qcdr(v187);
    stack[-2] = v187;
    goto v87;

v180:
    v187 = stack[-1];
    v187 = Lnreverse(nil, v187);
    env = stack[-4];
    goto v74;
/* error exit handlers */
v18:
    popv(5);
    return nil;
}



/* Code for red!=subst1 */

static Lisp_Object CC_redMsubst1(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v167, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=subst1");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v10;
    stack[-6] = v60;
/* end of prologue */
    v166 = stack[-6];
    fn = elt(env, 5); /* bas_dpoly */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[0] = v166;
    v166 = stack[0];
    fn = elt(env, 6); /* dp_lc */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-1] = v166;
    v166 = stack[-6];
    fn = elt(env, 7); /* bas_rep */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-7] = v166;
    v166 = stack[-5];
    fn = elt(env, 5); /* bas_dpoly */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-3] = v166;
    v166 = stack[-3];
    fn = elt(env, 6); /* dp_lc */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-2] = v166;
    v166 = qvalue(elt(env, 1)); /* !*bcsimp */
    if (v166 == nil) goto v84;
    v166 = stack[-2];
    fn = elt(env, 8); /* bc_inv */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-4] = v166;
    if (v166 == nil) goto v87;
    v167 = stack[-1];
    v166 = stack[-4];
    fn = elt(env, 9); /* bc_prod */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-1] = v166;
    v166 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* bc_fi */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-2] = v166;
    goto v84;

v84:
    v166 = stack[0];
    fn = elt(env, 11); /* dp_lmon */
    stack[-4] = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = stack[-3];
    fn = elt(env, 11); /* dp_lmon */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    fn = elt(env, 12); /* mo_diff */
    v166 = (*qfn2(fn))(qenv(fn), stack[-4], v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-4] = v166;
    v167 = stack[-2];
    v166 = stack[0];
    fn = elt(env, 13); /* dp_times_bc */
    stack[0] = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v168 = stack[-1];
    v167 = stack[-4];
    v166 = stack[-3];
    fn = elt(env, 14); /* dp_times_bcmo */
    v166 = (*qfnn(fn))(qenv(fn), 3, v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    fn = elt(env, 15); /* dp_diff */
    v166 = (*qfn2(fn))(qenv(fn), stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[0] = v166;
    v167 = stack[-2];
    v166 = stack[-7];
    fn = elt(env, 13); /* dp_times_bc */
    stack[-2] = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = stack[-5];
    fn = elt(env, 7); /* bas_rep */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    fn = elt(env, 14); /* dp_times_bcmo */
    v166 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-4], v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    fn = elt(env, 15); /* dp_diff */
    v166 = (*qfn2(fn))(qenv(fn), stack[-2], v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-1] = v166;
    fn = elt(env, 16); /* cali_trace */
    v167 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = (Lisp_Object)1265; /* 79 */
    v166 = (Lisp_Object)greaterp2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v166 = v166 ? lisp_true : nil;
    env = stack[-8];
    if (v166 == nil) goto v111;
    v166 = elt(env, 2); /* "---> " */
    v166 = Lprinc(nil, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = stack[0];
    fn = elt(env, 17); /* dp_print */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    goto v14;

v14:
    fn = elt(env, 16); /* cali_trace */
    v167 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = (Lisp_Object)1425; /* 89 */
    v166 = (Lisp_Object)greaterp2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v166 = v166 ? lisp_true : nil;
    env = stack[-8];
    if (v166 == nil) goto v128;
    v166 = elt(env, 4); /* " uses " */
    v166 = Lprinc(nil, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = stack[-3];
    fn = elt(env, 17); /* dp_print */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    goto v128;

v128:
    v166 = stack[-6];
    fn = elt(env, 18); /* bas_nr */
    v168 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v167 = stack[0];
    v166 = stack[-1];
    {
        popv(9);
        fn = elt(env, 19); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v168, v167, v166);
    }

v111:
    fn = elt(env, 16); /* cali_trace */
    v167 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)greaterp2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v166 = v166 ? lisp_true : nil;
    env = stack[-8];
    if (v166 == nil) goto v14;
    v166 = elt(env, 3); /* "." */
    v166 = Lprinc(nil, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    goto v14;

v87:
    v167 = stack[-2];
    v166 = stack[-1];
    fn = elt(env, 20); /* bc_gcd */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    stack[-4] = v166;
    v167 = stack[-2];
    v166 = stack[-4];
    fn = elt(env, 21); /* bc_divmod */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = qcar(v166);
    stack[-2] = v166;
    v167 = stack[-1];
    v166 = stack[-4];
    fn = elt(env, 21); /* bc_divmod */
    v166 = (*qfn2(fn))(qenv(fn), v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-8];
    v166 = qcar(v166);
    stack[-1] = v166;
    goto v84;
/* error exit handlers */
v43:
    popv(9);
    return nil;
}



/* Code for simp!-prop!-condense */

static Lisp_Object CC_simpKpropKcondense(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop-condense");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v60;
/* end of prologue */
    stack[-2] = nil;
    v138 = stack[-3];
    v84 = elt(env, 1); /* lambda_l9xqts_6 */
    fn = elt(env, 3); /* sort */
    v84 = (*qfn2(fn))(qenv(fn), v138, v84);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-3] = v84;
    goto v41;

v41:
    v84 = stack[-3];
    if (v84 == nil) goto v165;
    v84 = stack[-3];
    v84 = qcar(v84);
    stack[-4] = v84;
    v84 = stack[-3];
    v84 = qcdr(v84);
    stack[-3] = v84;
    v138 = stack[-4];
    v84 = stack[-2];
    v84 = cons(v138, v84);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-2] = v84;
    v84 = stack[-3];
    stack[-1] = v84;
    goto v37;

v37:
    v84 = stack[-1];
    if (v84 == nil) goto v41;
    v84 = stack[-1];
    v84 = qcar(v84);
    stack[0] = v84;
    v138 = stack[-4];
    v84 = stack[0];
    fn = elt(env, 4); /* subsetp */
    v84 = (*qfn2(fn))(qenv(fn), v138, v84);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    if (v84 == nil) goto v195;
    v138 = stack[0];
    v84 = stack[-3];
    v84 = Ldelete(nil, v138, v84);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-5];
    stack[-3] = v84;
    goto v195;

v195:
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-1] = v84;
    goto v37;

v165:
    v84 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* ordn */
        return (*qfn1(fn))(qenv(fn), v84);
    }
/* error exit handlers */
v121:
    popv(6);
    return nil;
}



/* Code for lambda_l9xqts_6 */

static Lisp_Object CC_lambda_l9xqts_6(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9xqts_6");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    v63 = v60;
/* end of prologue */
    stack[-1] = Llength(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-2];
    v63 = stack[0];
    v63 = Llength(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v41;
    {
        Lisp_Object v42 = stack[-1];
        popv(3);
        return Llessp(nil, v42, v63);
    }
/* error exit handlers */
v41:
    popv(3);
    return nil;
}



/* Code for !:expt */

static Lisp_Object CC_Texpt(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v207, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :expt");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v10;
    stack[-4] = v60;
/* end of prologue */
    v206 = stack[-4];
    if (v206 == nil) goto v62;
    v207 = stack[-3];
    v206 = (Lisp_Object)1; /* 0 */
    if (v207 == v206) goto v64;
    v207 = stack[-3];
    v206 = (Lisp_Object)17; /* 1 */
    if (v207 == v206) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v207 = stack[-4];
    v206 = (Lisp_Object)17; /* 1 */
    if (v207 == v206) goto v176;
    v207 = stack[-3];
    v206 = (Lisp_Object)1; /* 0 */
    v206 = (Lisp_Object)lessp2(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v206 = v206 ? lisp_true : nil;
    env = stack[-6];
    if (v206 == nil) goto v71;
    v206 = stack[-4];
    if (!consp(v206)) goto v90;
    v206 = stack[-4];
    v207 = qcar(v206);
    v206 = elt(env, 5); /* field */
    v206 = Lflagp(nil, v207, v206);
    env = stack[-6];
    if (v206 == nil) goto v90;
    v206 = stack[-4];
    stack[0] = v206;
    goto v25;

v25:
    v206 = stack[-3];
    v206 = negate(v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v206 = CC_Texpt(env, stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 9); /* !:recip */
        return (*qfn1(fn))(qenv(fn), v206);
    }

v90:
    v206 = stack[-4];
    fn = elt(env, 10); /* mkratnum */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[0] = v206;
    goto v25;

v71:
    v206 = stack[-4];
    if (!consp(v206)) goto v118;
    v206 = stack[-4];
    v207 = qcar(v206);
    v206 = elt(env, 6); /* expt */
    v206 = get(v207, v206);
    env = stack[-6];
    stack[-2] = v206;
    if (v206 == nil) goto v12;
    v208 = stack[-2];
    v207 = stack[-4];
    v206 = stack[-3];
        popv(7);
        return Lapply2(nil, 3, v208, v207, v206);

v12:
    v206 = stack[-4];
    v207 = qcar(v206);
    v206 = elt(env, 7); /* i2d */
    v207 = get(v207, v206);
    env = stack[-6];
    v206 = (Lisp_Object)17; /* 1 */
    v206 = Lapply1(nil, v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-5] = v206;
    v206 = stack[-4];
    v207 = qcar(v206);
    v206 = elt(env, 8); /* times */
    v206 = get(v207, v206);
    env = stack[-6];
    stack[-2] = v206;
    goto v186;

v186:
    v206 = stack[-3];
    stack[-1] = v206;
    stack[0] = (Lisp_Object)33; /* 2 */
    v207 = stack[-3];
    v206 = (Lisp_Object)33; /* 2 */
    v206 = quot2(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-3] = v206;
    v206 = times2(stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v207 = difference2(stack[-1], v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v206 = (Lisp_Object)1; /* 0 */
    if (v207 == v206) goto v210;
    v208 = stack[-2];
    v207 = stack[-4];
    v206 = stack[-5];
    v206 = Lapply2(nil, 3, v208, v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-5] = v206;
    goto v210;

v210:
    v207 = stack[-3];
    v206 = (Lisp_Object)1; /* 0 */
    if (v207 == v206) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v208 = stack[-2];
    v207 = stack[-4];
    v206 = stack[-4];
    v206 = Lapply2(nil, 3, v208, v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-4] = v206;
    goto v186;

v118:
    v207 = stack[-4];
    v206 = stack[-3];
        popv(7);
        return Lexpt(nil, v207, v206);

v176:
    v206 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v206); }

v64:
    v206 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v206); }

v62:
    v207 = stack[-3];
    v206 = (Lisp_Object)1; /* 0 */
    if (v207 == v206) goto v101;
    v206 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v206); }

v101:
    v206 = elt(env, 1); /* "0/0 formed" */
    v207 = v206;
    v206 = v207;
    qvalue(elt(env, 2)) = v206; /* errmsg!* */
    v206 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v206 == nil)) goto v40;
    v206 = v207;
    fn = elt(env, 11); /* lprie */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    goto v40;

v40:
    v206 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v206 = nil;
    { popv(7); return onevalue(v206); }
/* error exit handlers */
v209:
    popv(7);
    return nil;
}



/* Code for innprodp2 */

static Lisp_Object CC_innprodp2(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v72, v73, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodp2");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v73 = v10;
    stack[0] = v60;
/* end of prologue */
    v158 = qvalue(elt(env, 1)); /* nil */
    v72 = v73;
    v158 = cons(v158, v72);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-1];
    v73 = v158;
    goto v165;

v165:
    v158 = stack[0];
    if (v158 == nil) { popv(2); return onevalue(v73); }
    v158 = v73;
    if (v158 == nil) { popv(2); return onevalue(v73); }
    v87 = qvalue(elt(env, 1)); /* nil */
    v158 = stack[0];
    v72 = qcar(v158);
    v158 = v73;
    v158 = qcdr(v158);
    v73 = qcar(v73);
    fn = elt(env, 2); /* innprodkp */
    v158 = (*qfnn(fn))(qenv(fn), 4, v87, v72, v158, v73);
    nil = C_nil;
    if (exception_pending()) goto v195;
    env = stack[-1];
    v73 = v158;
    v158 = stack[0];
    v158 = qcdr(v158);
    stack[0] = v158;
    goto v165;
/* error exit handlers */
v195:
    popv(2);
    return nil;
}



/* Code for diff!-over!-k!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKoverKkKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-over-k-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-over-k-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v60,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    stack[-2] = v10;
    stack[-3] = v60;
/* end of prologue */
    v133 = stack[-3];
    if (!consp(v133)) goto v80;
    v133 = stack[-3];
    v133 = qcar(v133);
    if (!consp(v133)) goto v80;
    v133 = stack[-3];
    v133 = qcar(v133);
    v133 = qcar(v133);
    v149 = qcar(v133);
    v133 = stack[-1];
    if (equal(v149, v133)) goto v97;
    v133 = stack[-3];
    v133 = qcar(v133);
    stack[-4] = qcar(v133);
    v133 = stack[-3];
    v133 = qcar(v133);
    v150 = qcdr(v133);
    v149 = stack[-2];
    v133 = stack[-1];
    stack[0] = CC_diffKoverKkKmodKp(env, 3, v150, v149, v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v133 = stack[-3];
    v150 = qcdr(v133);
    v149 = stack[-2];
    v133 = stack[-1];
    v133 = CC_diffKoverKkKmodKp(env, 3, v150, v149, v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    {
        Lisp_Object v12 = stack[-4];
        Lisp_Object v11 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v12, v11, v133);
    }

v97:
    v133 = stack[-3];
    v133 = qcar(v133);
    v133 = qcar(v133);
    v149 = qcdr(v133);
    v133 = (Lisp_Object)17; /* 1 */
    if (v149 == v133) goto v157;
    v133 = stack[-1];
    fn = elt(env, 3); /* fkern */
    v149 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v133 = stack[-3];
    v133 = qcar(v133);
    v133 = qcar(v133);
    v133 = qcdr(v133);
    v133 = (Lisp_Object)((int32_t)(v133) - 0x10);
    fn = elt(env, 4); /* getpower */
    stack[-4] = (*qfn2(fn))(qenv(fn), v149, v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v133 = stack[-3];
    v133 = qcar(v133);
    v133 = qcar(v133);
    v133 = qcdr(v133);
    v149 = Lmodular_number(nil, v133);
    env = stack[-5];
    v133 = stack[-3];
    v133 = qcar(v133);
    v133 = qcdr(v133);
    fn = elt(env, 5); /* times!-mod!-p */
    v149 = (*qfn2(fn))(qenv(fn), v149, v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v133 = stack[-2];
    v133 = Lmodular_number(nil, v133);
    env = stack[-5];
    fn = elt(env, 6); /* quotient!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v149, v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v133 = stack[-3];
    v150 = qcdr(v133);
    v149 = stack[-2];
    v133 = stack[-1];
    v133 = CC_diffKoverKkKmodKp(env, 3, v150, v149, v133);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    {
        Lisp_Object v13 = stack[-4];
        Lisp_Object v191 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v13, v191, v133);
    }

v157:
    v133 = stack[-3];
    v133 = qcar(v133);
    v149 = qcdr(v133);
    v133 = stack[-2];
    v133 = Lmodular_number(nil, v133);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 6); /* quotient!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v149, v133);
    }

v80:
    v133 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v133); }
/* error exit handlers */
v154:
    popv(6);
    return nil;
}



/* Code for cgp_number */

static Lisp_Object CC_cgp_number(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_number");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v159 = v60;
/* end of prologue */
    v62 = v159;
    v159 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v159 = (*qfn2(fn))(qenv(fn), v62, v159);
    errexit();
    v159 = qcar(v159);
    return onevalue(v159);
}



/* Code for dvfsf_mk2 */

static Lisp_Object MS_CDECL CC_dvfsf_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v41, v42;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dvfsf_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v165 = v6;
    v41 = v10;
    v42 = v60;
/* end of prologue */
    return list3(v42, v41, v165);
}



/* Code for ombindir */

static Lisp_Object MS_CDECL CC_ombindir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ombindir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ombindir");
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
    fn = elt(env, 2); /* lex */
    v125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    fn = elt(env, 3); /* omobj */
    v125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[-1] = v125;
    fn = elt(env, 2); /* lex */
    v125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    fn = elt(env, 4); /* variablesir */
    v125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    fn = elt(env, 5); /* tobvarir */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[0] = v125;
    fn = elt(env, 2); /* lex */
    v125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    fn = elt(env, 3); /* omobj */
    v125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    stack[-2] = v125;
    fn = elt(env, 2); /* lex */
    v125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v125 = elt(env, 1); /* (!/ o m b i n d) */
    fn = elt(env, 6); /* checktag */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v125 = stack[-2];
    v125 = ncons(v125);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v125 = Lappend(nil, stack[0], v125);
    nil = C_nil;
    if (exception_pending()) goto v66;
    {
        Lisp_Object v67 = stack[-1];
        popv(4);
        return Lappend(nil, v67, v125);
    }
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for atomlis */

static Lisp_Object CC_atomlis(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v181;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atomlis");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v60;
/* end of prologue */

v155:
    v181 = v77;
    v181 = (v181 == nil ? lisp_true : nil);
    if (!(v181 == nil)) return onevalue(v181);
    v181 = v77;
    v181 = qcar(v181);
    if (!consp(v181)) goto v175;
    v77 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v77);

v175:
    v77 = qcdr(v77);
    goto v155;
}



/* Code for make!-unique!-freevars */

static Lisp_Object CC_makeKuniqueKfreevars(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v24, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-unique-freevars");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v24 = v60;
/* end of prologue */
    v135 = v24;
    if (!consp(v135)) goto v62;
    v135 = v24;
    stack[-3] = v135;
    v135 = stack[-3];
    if (v135 == nil) goto v25;
    v135 = stack[-3];
    v135 = qcar(v135);
    v135 = CC_makeKuniqueKfreevars(env, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    stack[-1] = v135;
    stack[-2] = v135;
    goto v138;

v138:
    v135 = stack[-3];
    v135 = qcdr(v135);
    stack[-3] = v135;
    v135 = stack[-3];
    if (v135 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v135 = stack[-3];
    v135 = qcar(v135);
    v135 = CC_makeKuniqueKfreevars(env, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = ncons(v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = Lrplacd(nil, stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = stack[-1];
    v135 = qcdr(v135);
    stack[-1] = v135;
    goto v138;

v25:
    v135 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v135); }

v62:
    v143 = v24;
    v135 = elt(env, 1); /* gen */
    v135 = get(v143, v135);
    env = stack[-4];
    if (v135 == nil) { popv(5); return onevalue(v24); }
    v143 = v24;
    v135 = qvalue(elt(env, 2)); /* freevarlist!* */
    v135 = Latsoc(nil, v143, v135);
    stack[0] = v135;
    v135 = stack[0];
    if (!(v135 == nil)) goto v47;
    stack[0] = v24;
    fn = elt(env, 5); /* pm!:gensym */
    v135 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v135 = cons(stack[0], v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    stack[0] = v135;
    v135 = stack[0];
    v143 = qcdr(v135);
    v24 = elt(env, 1); /* gen */
    v135 = qvalue(elt(env, 3)); /* t */
    v135 = Lputprop(nil, 3, v143, v24, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v24 = stack[0];
    v135 = qvalue(elt(env, 2)); /* freevarlist!* */
    v135 = cons(v24, v135);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    qvalue(elt(env, 2)) = v135; /* freevarlist!* */
    goto v47;

v47:
    v135 = stack[0];
    v135 = qcdr(v135);
    { popv(5); return onevalue(v135); }
/* error exit handlers */
v139:
    popv(5);
    return nil;
}



/* Code for overall_factor */

static Lisp_Object CC_overall_factor(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for overall_factor");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v60;
/* end of prologue */

v155:
    v126 = stack[0];
    v126 = (v126 == nil ? lisp_true : nil);
    if (!(v126 == nil)) { popv(4); return onevalue(v126); }
    stack[-2] = stack[-1];
    v126 = stack[0];
    fn = elt(env, 2); /* xval */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-3];
    v126 = Lmemq(nil, stack[-2], v126);
    if (v126 == nil) goto v101;
    v65 = stack[-1];
    v126 = stack[0];
    v126 = qcdr(v126);
    stack[-1] = v65;
    stack[0] = v126;
    goto v155;

v101:
    v126 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v126); }
/* error exit handlers */
v37:
    popv(4);
    return nil;
}



/* Code for gfplusn */

static Lisp_Object CC_gfplusn(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfplusn");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v60;
/* end of prologue */
    v50 = stack[-1];
    v50 = qcar(v50);
    if (!consp(v50)) goto v41;
    v50 = stack[-1];
    v122 = qcar(v50);
    v50 = stack[0];
    v50 = qcar(v50);
    fn = elt(env, 1); /* plus!: */
    stack[-2] = (*qfn2(fn))(qenv(fn), v122, v50);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v50 = stack[-1];
    v122 = qcdr(v50);
    v50 = stack[0];
    v50 = qcdr(v50);
    fn = elt(env, 1); /* plus!: */
    v50 = (*qfn2(fn))(qenv(fn), v122, v50);
    nil = C_nil;
    if (exception_pending()) goto v79;
    {
        Lisp_Object v137 = stack[-2];
        popv(4);
        return cons(v137, v50);
    }

v41:
    v50 = stack[-1];
    v122 = qcar(v50);
    v50 = stack[0];
    v50 = qcar(v50);
    stack[-2] = plus2(v122, v50);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v50 = stack[-1];
    v122 = qcdr(v50);
    v50 = stack[0];
    v50 = qcdr(v50);
    v50 = plus2(v122, v50);
    nil = C_nil;
    if (exception_pending()) goto v79;
    {
        Lisp_Object v92 = stack[-2];
        popv(4);
        return cons(v92, v50);
    }
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for sublap */

static Lisp_Object CC_sublap(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sublap");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v60;
/* end of prologue */
    v90 = stack[-1];
    if (v90 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v90 = stack[0];
    if (v90 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v90 = stack[0];
    if (!consp(v90)) goto v165;
    v90 = stack[0];
    v91 = qcar(v90);
    v90 = elt(env, 1); /* app */
    v90 = Lflagp(nil, v91, v90);
    env = stack[-3];
    if (v90 == nil) goto v78;
    v91 = stack[-1];
    v90 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* sublap1 */
        return (*qfn2(fn))(qenv(fn), v91, v90);
    }

v78:
    v91 = stack[-1];
    v90 = stack[0];
    v90 = qcar(v90);
    stack[-2] = CC_sublap(env, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-3];
    v91 = stack[-1];
    v90 = stack[0];
    v90 = qcdr(v90);
    v90 = CC_sublap(env, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v28;
    {
        Lisp_Object v178 = stack[-2];
        popv(4);
        return cons(v178, v90);
    }

v165:
    v90 = stack[0];
    if (is_number(v90)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v91 = stack[0];
    v90 = stack[-1];
    v90 = Latsoc(nil, v91, v90);
    v91 = v90;
    if (v90 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v90 = v91;
    v90 = qcdr(v90);
    { popv(4); return onevalue(v90); }
/* error exit handlers */
v28:
    popv(4);
    return nil;
}



/* Code for unresidp */

static Lisp_Object CC_unresidp(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unresidp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v159 = v60;
/* end of prologue */
    v62 = qvalue(elt(env, 1)); /* !*reservedops!* */
    v159 = Lmemq(nil, v159, v62);
    v159 = (v159 == nil ? lisp_true : nil);
    return onevalue(v159);
}



/* Code for getphystypeor */

static Lisp_Object CC_getphystypeor(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypeor");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v60;
/* end of prologue */

v155:
    v77 = stack[0];
    if (!consp(v77)) goto v34;
    v77 = stack[0];
    v77 = qcar(v77);
    fn = elt(env, 2); /* getphystype */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-1];
    if (!(v77 == nil)) { popv(2); return onevalue(v77); }
    v77 = stack[0];
    v77 = qcdr(v77);
    stack[0] = v77;
    goto v155;

v34:
    v77 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v77); }
/* error exit handlers */
v174:
    popv(2);
    return nil;
}



/* Code for subcare */

static Lisp_Object MS_CDECL CC_subcare(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v26, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subcare");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subcare");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v60,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v10;
    stack[-2] = v60;
/* end of prologue */
    stack[-3] = nil;
    goto v182;

v182:
    v177 = stack[0];
    if (v177 == nil) goto v101;
    v26 = stack[-2];
    v177 = stack[0];
    if (equal(v26, v177)) goto v40;
    v177 = stack[0];
    if (!consp(v177)) goto v73;
    v177 = stack[0];
    v26 = qcar(v177);
    v177 = elt(env, 1); /* subfunc */
    v177 = get(v26, v177);
    env = stack[-4];
    if (!(v177 == nil)) goto v73;
    v25 = stack[-2];
    v26 = stack[-1];
    v177 = stack[0];
    v177 = qcar(v177);
    v26 = CC_subcare(env, 3, v25, v26, v177);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    v177 = stack[-3];
    v177 = cons(v26, v177);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-4];
    stack[-3] = v177;
    v177 = stack[0];
    v177 = qcdr(v177);
    stack[0] = v177;
    goto v182;

v73:
    v26 = stack[-3];
    v177 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v26, v177);
    }

v40:
    v26 = stack[-3];
    v177 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v26, v177);
    }

v101:
    v177 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v177);
    }
/* error exit handlers */
v90:
    popv(5);
    return nil;
}



/* Code for red_totalred */

static Lisp_Object CC_red_totalred(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_totalred");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v76 = v10;
    v77 = v60;
/* end of prologue */
    stack[0] = v77;
    fn = elt(env, 1); /* red_topred */
    v76 = (*qfn2(fn))(qenv(fn), v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-1];
    {
        Lisp_Object v127 = stack[0];
        popv(2);
        fn = elt(env, 2); /* red_tailred */
        return (*qfn2(fn))(qenv(fn), v127, v76);
    }
/* error exit handlers */
v174:
    popv(2);
    return nil;
}



/* Code for reduce!-mod!-p!* */

static Lisp_Object CC_reduceKmodKpH(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-p*");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v182 = v10;
    v156 = v60;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* current!-modulus */
    qvalue(elt(env, 1)) = v182; /* current!-modulus */
    v182 = v156;
    fn = elt(env, 2); /* general!-reduce!-mod!-p */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* current!-modulus */
    { popv(2); return onevalue(v182); }
/* error exit handlers */
v101:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* current!-modulus */
    popv(2);
    return nil;
}



/* Code for reduce!-mod!-eigf */

static Lisp_Object CC_reduceKmodKeigf(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-eigf");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v10;
    v72 = v60;
/* end of prologue */
    v73 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[-3] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v73; /* !*sub2 */
    v73 = v72;
    v73 = qcar(v73);
    stack[-1] = qcar(v73);
    v73 = v72;
    v73 = qcdr(v73);
    v72 = qcar(v72);
    v72 = qcdr(v72);
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    fn = elt(env, 2); /* cancel */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    stack[0] = v72;
    v72 = stack[0];
    v72 = qcar(v72);
    fn = elt(env, 3); /* negf */
    v73 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v72 = stack[0];
    v72 = qcdr(v72);
    v72 = cons(v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v73 = cons(stack[-1], v72);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v72 = stack[-2];
    fn = elt(env, 4); /* reduce!-eival!-powers */
    v72 = (*qfn2(fn))(qenv(fn), v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    fn = elt(env, 5); /* subs2 */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*sub2 */
    { popv(5); return onevalue(v72); }
/* error exit handlers */
v89:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*sub2 */
    popv(5);
    return nil;
}



/* Code for ofsf_entry2at */

static Lisp_Object MS_CDECL CC_ofsf_entry2at(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v64, v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v60,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v64 = v6;
    v66 = v10;
    v67 = v60;
/* end of prologue */
    v65 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v65 == nil) goto v39;
    v65 = v67;
    fn = elt(env, 2); /* ofsf_entry2at1 */
    v65 = (*qfnn(fn))(qenv(fn), 3, v65, v66, v64);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cl_identifyat */
        return (*qfn1(fn))(qenv(fn), v65);
    }

v39:
    v65 = v67;
    {
        popv(1);
        fn = elt(env, 2); /* ofsf_entry2at1 */
        return (*qfnn(fn))(qenv(fn), 3, v65, v66, v64);
    }
/* error exit handlers */
v37:
    popv(1);
    return nil;
}



/* Code for multdf */

static Lisp_Object CC_multdf(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdf");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v60;
/* end of prologue */
    v179 = stack[-1];
    if (v179 == nil) goto v130;
    v179 = stack[0];
    if (v179 == nil) goto v130;
    v179 = stack[-1];
    v50 = qcar(v179);
    v179 = stack[0];
    v179 = qcar(v179);
    fn = elt(env, 2); /* multerm */
    v179 = (*qfn2(fn))(qenv(fn), v50, v179);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    stack[-2] = v179;
    v179 = stack[-1];
    v50 = qcdr(v179);
    v179 = stack[0];
    v179 = CC_multdf(env, v50, v179);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    fn = elt(env, 3); /* plusdf */
    v179 = (*qfn2(fn))(qenv(fn), stack[-2], v179);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    stack[-2] = v179;
    v179 = stack[-1];
    v179 = qcar(v179);
    v50 = ncons(v179);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    v179 = stack[0];
    v179 = qcdr(v179);
    v179 = CC_multdf(env, v50, v179);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    {
        Lisp_Object v79 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v79, v179);
    }

v130:
    v179 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v179); }
/* error exit handlers */
v78:
    popv(4);
    return nil;
}



/* Code for evallessp */

static Lisp_Object CC_evallessp(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evallessp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v62 = v10;
    v159 = v60;
/* end of prologue */
    {
        fn = elt(env, 1); /* evalgreaterp */
        return (*qfn2(fn))(qenv(fn), v62, v159);
    }
}



/* Code for makecoeffpairshom */

static Lisp_Object MS_CDECL CC_makecoeffpairshom(Lisp_Object env, int nargs,
                         Lisp_Object v60, Lisp_Object v10,
                         Lisp_Object v6, Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v246, v247, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairshom");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairshom");
#endif
    if (stack >= stacklimit)
    {
        push4(v7,v6,v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v60,v10,v6,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-11] = v7;
    stack[-12] = v6;
    stack[-13] = v10;
    stack[-14] = v60;
/* end of prologue */
    v245 = stack[-12];
    if (v245 == nil) goto v182;
    v245 = stack[-13];
    v245 = qcar(v245);
    stack[-15] = v245;
    goto v75;

v75:
    stack[0] = stack[-11];
    v245 = stack[-14];
    v246 = qcar(v245);
    v245 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    fn = elt(env, 4); /* tayexp!-times2 */
    v245 = (*qfn2(fn))(qenv(fn), stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    fn = elt(env, 5); /* tayexp!-minusp */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    if (v245 == nil) goto v94;
    v245 = qvalue(elt(env, 2)); /* nil */
    { popv(17); return onevalue(v245); }

v94:
    v245 = stack[-14];
    v248 = qcdr(v245);
    v245 = stack[-13];
    v247 = qcdr(v245);
    v245 = stack[-12];
    v246 = qcdr(v245);
    v245 = stack[-11];
    v245 = CC_makecoeffpairshom(env, 4, v248, v247, v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    stack[-7] = v245;
    v245 = stack[-7];
    if (v245 == nil) goto v137;
    v245 = stack[-7];
    v245 = qcar(v245);
    stack[-3] = v245;
    stack[-2] = stack[-15];
    v245 = stack[-3];
    stack[-1] = qcar(v245);
    v245 = stack[-13];
    stack[0] = qcar(v245);
    v245 = stack[-12];
    v246 = qcar(v245);
    v245 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v246 = (*qfn2(fn))(qenv(fn), stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = stack[-3];
    v245 = qcdr(v245);
    v245 = cons(v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = acons(stack[-2], stack[-1], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    stack[-5] = v245;
    stack[-6] = v245;
    goto v96;

v96:
    v245 = stack[-7];
    v245 = qcdr(v245);
    stack[-7] = v245;
    v245 = stack[-7];
    if (v245 == nil) goto v116;
    stack[-4] = stack[-5];
    v245 = stack[-7];
    v245 = qcar(v245);
    stack[-3] = v245;
    stack[-2] = stack[-15];
    v245 = stack[-3];
    stack[-1] = qcar(v245);
    v245 = stack[-13];
    stack[0] = qcar(v245);
    v245 = stack[-12];
    v246 = qcar(v245);
    v245 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v246 = (*qfn2(fn))(qenv(fn), stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = stack[-3];
    v245 = qcdr(v245);
    v245 = cons(v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = acons(stack[-2], stack[-1], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = Lrplacd(nil, stack[-4], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = stack[-5];
    v245 = qcdr(v245);
    stack[-5] = v245;
    goto v96;

v116:
    v245 = stack[-6];
    goto v87;

v87:
    stack[-10] = v245;
    v245 = stack[-10];
    fn = elt(env, 7); /* lastpair */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    stack[-9] = v245;
    v246 = stack[-15];
    v245 = stack[-11];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    stack[-15] = v245;
    v245 = stack[-9];
    if (!consp(v245)) goto v75;
    else goto v167;

v167:
    stack[0] = stack[-11];
    v245 = stack[-14];
    v246 = qcar(v245);
    v245 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    fn = elt(env, 4); /* tayexp!-times2 */
    v245 = (*qfn2(fn))(qenv(fn), stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    fn = elt(env, 5); /* tayexp!-minusp */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    if (!(v245 == nil)) { Lisp_Object res = stack[-10]; popv(17); return onevalue(res); }
    stack[-8] = stack[-9];
    v245 = stack[-14];
    v248 = qcdr(v245);
    v245 = stack[-13];
    v247 = qcdr(v245);
    v245 = stack[-12];
    v246 = qcdr(v245);
    v245 = stack[-11];
    v245 = CC_makecoeffpairshom(env, 4, v248, v247, v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    stack[-7] = v245;
    v245 = stack[-7];
    if (v245 == nil) goto v197;
    v245 = stack[-7];
    v245 = qcar(v245);
    stack[-3] = v245;
    stack[-2] = stack[-15];
    v245 = stack[-3];
    stack[-1] = qcar(v245);
    v245 = stack[-13];
    stack[0] = qcar(v245);
    v245 = stack[-12];
    v246 = qcar(v245);
    v245 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v246 = (*qfn2(fn))(qenv(fn), stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = stack[-3];
    v245 = qcdr(v245);
    v245 = cons(v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = acons(stack[-2], stack[-1], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    stack[-5] = v245;
    stack[-6] = v245;
    goto v250;

v250:
    v245 = stack[-7];
    v245 = qcdr(v245);
    stack[-7] = v245;
    v245 = stack[-7];
    if (v245 == nil) goto v251;
    stack[-4] = stack[-5];
    v245 = stack[-7];
    v245 = qcar(v245);
    stack[-3] = v245;
    stack[-2] = stack[-15];
    v245 = stack[-3];
    stack[-1] = qcar(v245);
    v245 = stack[-13];
    stack[0] = qcar(v245);
    v245 = stack[-12];
    v246 = qcar(v245);
    v245 = stack[-15];
    fn = elt(env, 3); /* tayexp!-difference */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v246 = (*qfn2(fn))(qenv(fn), stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = stack[-3];
    v245 = qcdr(v245);
    v245 = cons(v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = acons(stack[-2], stack[-1], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = Lrplacd(nil, stack[-4], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = stack[-5];
    v245 = qcdr(v245);
    stack[-5] = v245;
    goto v250;

v251:
    v245 = stack[-6];
    goto v52;

v52:
    v245 = Lrplacd(nil, stack[-8], v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    v245 = stack[-9];
    fn = elt(env, 7); /* lastpair */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    stack[-9] = v245;
    v246 = stack[-15];
    v245 = stack[-11];
    fn = elt(env, 6); /* tayexp!-plus2 */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-16];
    stack[-15] = v245;
    goto v167;

v197:
    v245 = qvalue(elt(env, 2)); /* nil */
    goto v52;

v137:
    v245 = qvalue(elt(env, 2)); /* nil */
    goto v87;

v182:
    v245 = elt(env, 1); /* ((nil)) */
    { popv(17); return onevalue(v245); }
/* error exit handlers */
v249:
    popv(17);
    return nil;
}



/* Code for pasf_pdp */

static Lisp_Object CC_pasf_pdp(Lisp_Object env,
                         Lisp_Object v60)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v163, v190;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_pdp");
#endif
    if (stack >= stacklimit)
    {
        push(v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v60);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v60;
/* end of prologue */
    v162 = stack[0];
    if (!consp(v162)) goto v156;
    v162 = stack[0];
    v162 = qcar(v162);
    if (!consp(v162)) goto v156;
    v162 = stack[0];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = qcdr(v162);
    v162 = Levenp(nil, v162);
    env = stack[-2];
    if (v162 == nil) goto v73;
    v162 = stack[0];
    v162 = qcar(v162);
    v162 = qcdr(v162);
    v162 = CC_pasf_pdp(env, v162);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    stack[-1] = v162;
    v162 = stack[0];
    v162 = qcdr(v162);
    v162 = CC_pasf_pdp(env, v162);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-2];
    v190 = v162;
    v162 = v190;
    if (!(v162 == nil)) goto v50;
    v163 = stack[-1];
    v162 = elt(env, 4); /* psdef */
    if (v163 == v162) goto v122;
    v163 = stack[-1];
    v162 = elt(env, 3); /* pdef */
    if (!(v163 == v162)) goto v50;

v122:
    v162 = elt(env, 4); /* psdef */
    { popv(3); return onevalue(v162); }

v50:
    v162 = v190;
    if (!(v162 == nil)) goto v142;
    v163 = stack[-1];
    v162 = elt(env, 5); /* nsdef */
    if (v163 == v162) goto v30;
    v163 = stack[-1];
    v162 = elt(env, 2); /* ndef */
    if (!(v163 == v162)) goto v142;

v30:
    v162 = elt(env, 5); /* nsdef */
    { popv(3); return onevalue(v162); }

v142:
    v163 = v190;
    v162 = elt(env, 3); /* pdef */
    if (!(v163 == v162)) goto v18;
    v163 = stack[-1];
    v162 = elt(env, 4); /* psdef */
    if (v163 == v162) goto v135;
    v163 = stack[-1];
    v162 = elt(env, 3); /* pdef */
    if (!(v163 == v162)) goto v18;

v135:
    v162 = elt(env, 3); /* pdef */
    { popv(3); return onevalue(v162); }

v18:
    v163 = v190;
    v162 = elt(env, 2); /* ndef */
    if (!(v163 == v162)) goto v73;
    v163 = stack[-1];
    v162 = elt(env, 5); /* nsdef */
    if (v163 == v162) goto v243;
    v163 = stack[-1];
    v162 = elt(env, 2); /* ndef */
    if (!(v163 == v162)) goto v73;

v243:
    v162 = elt(env, 2); /* ndef */
    { popv(3); return onevalue(v162); }

v73:
    v162 = elt(env, 1); /* indef */
    { popv(3); return onevalue(v162); }

v156:
    v162 = stack[0];
    if (v162 == nil) goto v42;
    v163 = stack[0];
    v162 = (Lisp_Object)1; /* 0 */
    v162 = (Lisp_Object)lessp2(v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v8;
    v162 = v162 ? lisp_true : nil;
    env = stack[-2];
    if (v162 == nil) goto v64;
    v162 = elt(env, 2); /* ndef */
    { popv(3); return onevalue(v162); }

v64:
    v163 = stack[0];
    v162 = (Lisp_Object)1; /* 0 */
    v162 = (Lisp_Object)greaterp2(v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v8;
    v162 = v162 ? lisp_true : nil;
    env = stack[-2];
    if (v162 == nil) goto v88;
    v162 = elt(env, 3); /* pdef */
    { popv(3); return onevalue(v162); }

v88:
    v162 = elt(env, 1); /* indef */
    { popv(3); return onevalue(v162); }

v42:
    v162 = elt(env, 1); /* indef */
    { popv(3); return onevalue(v162); }
/* error exit handlers */
v8:
    popv(3);
    return nil;
}



/* Code for exptplus */

static Lisp_Object CC_exptplus(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v94, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptplus");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v94 = v10;
    v89 = v60;
/* end of prologue */
    v195 = v89;
    if (!consp(v195)) goto v130;
    v195 = v94;
    if (!consp(v195)) goto v37;
    v195 = elt(env, 1); /* "Bad exponent sum" */
    {
        fn = elt(env, 2); /* interr */
        return (*qfn1(fn))(qenv(fn), v195);
    }

v37:
    v195 = v89;
    v195 = qcar(v195);
    v195 = plus2(v195, v94);
    errexit();
    return ncons(v195);

v130:
    v195 = v94;
    if (!consp(v195)) goto v175;
    v195 = v89;
    v94 = qcar(v94);
    v195 = plus2(v195, v94);
    errexit();
    return ncons(v195);

v175:
    v195 = v89;
    return plus2(v195, v94);
}



/* Code for derad */

static Lisp_Object CC_derad(Lisp_Object env,
                         Lisp_Object v60, Lisp_Object v10)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v252, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derad");
#endif
    if (stack >= stacklimit)
    {
        push2(v10,v60);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v60,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v60;
/* end of prologue */
    stack[-2] = nil;
    goto v80;

v80:
    v188 = stack[0];
    if (v188 == nil) goto v63;
    v188 = stack[0];
    v188 = qcar(v188);
    if (is_number(v188)) goto v85;
    v252 = stack[-1];
    v188 = stack[0];
    v188 = qcar(v188);
    if (equal(v252, v188)) goto v66;
    v252 = stack[-1];
    v188 = stack[0];
    v188 = qcar(v188);
    fn = elt(env, 1); /* ordp */
    v188 = (*qfn2(fn))(qenv(fn), v252, v188);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    if (v188 == nil) goto v192;
    v252 = stack[-1];
    v188 = stack[0];
    v188 = cons(v252, v188);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    {
        Lisp_Object v149 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v149, v188);
    }

v192:
    v188 = stack[0];
    v252 = qcar(v188);
    v188 = stack[-2];
    v188 = cons(v252, v188);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    stack[-2] = v188;
    v188 = stack[0];
    v188 = qcdr(v188);
    stack[0] = v188;
    goto v80;

v66:
    v188 = stack[0];
    v188 = qcdr(v188);
    if (v188 == nil) goto v178;
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    if (!(is_number(v188))) goto v178;
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcar(v188);
    v252 = add1(v188);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = qcdr(v188);
    v188 = list2star(stack[-1], v252, v188);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    {
        Lisp_Object v150 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v150, v188);
    }

v178:
    v243 = stack[-1];
    v252 = (Lisp_Object)33; /* 2 */
    v188 = stack[0];
    v188 = qcdr(v188);
    v188 = list2star(v243, v252, v188);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    {
        Lisp_Object v151 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v151, v188);
    }

v85:
    v188 = stack[0];
    v252 = qcar(v188);
    v188 = stack[-2];
    v188 = cons(v252, v188);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    stack[-2] = v188;
    v188 = stack[0];
    v188 = qcdr(v188);
    stack[0] = v188;
    goto v80;

v63:
    stack[0] = stack[-2];
    v188 = stack[-1];
    v188 = ncons(v188);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    {
        Lisp_Object v152 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v152, v188);
    }
/* error exit handlers */
v133:
    popv(4);
    return nil;
}



setup_type const u25_setup[] =
{
    {"cnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnrd},
    {"gcd2",                    too_few_2,      CC_gcd2,       wrong_no_2},
    {"intrdsortin",             too_few_2,      CC_intrdsortin,wrong_no_2},
    {"smemberl",                too_few_2,      CC_smemberl,   wrong_no_2},
    {"dummyp",                  CC_dummyp,      too_many_1,    wrong_no_1},
    {"reverse-num1",            too_few_2,      CC_reverseKnum1,wrong_no_2},
    {"sgn1",                    too_few_2,      CC_sgn1,       wrong_no_2},
    {"horner-rule-for-one-var", wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"cl_identifyonoff",        CC_cl_identifyonoff,too_many_1,wrong_no_1},
    {"multdfconst",             too_few_2,      CC_multdfconst,wrong_no_2},
    {"expnd",                   CC_expnd,       too_many_1,    wrong_no_1},
    {"cl_susiupdknowl2",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl2},
    {"expvec2a",                CC_expvec2a,    too_many_1,    wrong_no_1},
    {"divide-by-power-of-ten",  too_few_2,      CC_divideKbyKpowerKofKten,wrong_no_2},
    {"prop-simp2",              too_few_2,      CC_propKsimp2, wrong_no_2},
    {"symbvarlst",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_symbvarlst},
    {"sqhorner*",               CC_sqhornerH,   too_many_1,    wrong_no_1},
    {"split_cov_cont_ids",      CC_split_cov_cont_ids,too_many_1,wrong_no_1},
    {"giplus:",                 too_few_2,      CC_giplusT,    wrong_no_2},
    {"dfconst",                 CC_dfconst,     too_many_1,    wrong_no_1},
    {"cl_sacat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_sacat},
    {"cl_susicpknowl",          CC_cl_susicpknowl,too_many_1,  wrong_no_1},
    {"matrixrowom",             CC_matrixrowom, too_many_1,    wrong_no_1},
    {"crn:prep",                CC_crnTprep,    too_many_1,    wrong_no_1},
    {"matrixp",                 CC_matrixp,     too_many_1,    wrong_no_1},
    {"dm-mkfloat",              CC_dmKmkfloat,  too_many_1,    wrong_no_1},
    {"dip-nc-ev-prod1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod1},
    {"inprinla",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_inprinla},
    {"formrlis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formrlis},
    {"red=subst1",              too_few_2,      CC_redMsubst1, wrong_no_2},
    {"simp-prop-condense",      CC_simpKpropKcondense,too_many_1,wrong_no_1},
    {"lambda_l9xqts_6",         too_few_2,      CC_lambda_l9xqts_6,wrong_no_2},
    {":expt",                   too_few_2,      CC_Texpt,      wrong_no_2},
    {"innprodp2",               too_few_2,      CC_innprodp2,  wrong_no_2},
    {"diff-over-k-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKoverKkKmodKp},
    {"cgp_number",              CC_cgp_number,  too_many_1,    wrong_no_1},
    {"dvfsf_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_mk2},
    {"ombindir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_ombindir},
    {"atomlis",                 CC_atomlis,     too_many_1,    wrong_no_1},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,too_many_1,wrong_no_1},
    {"overall_factor",          too_few_2,      CC_overall_factor,wrong_no_2},
    {"gfplusn",                 too_few_2,      CC_gfplusn,    wrong_no_2},
    {"sublap",                  too_few_2,      CC_sublap,     wrong_no_2},
    {"unresidp",                CC_unresidp,    too_many_1,    wrong_no_1},
    {"getphystypeor",           CC_getphystypeor,too_many_1,   wrong_no_1},
    {"subcare",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subcare},
    {"red_totalred",            too_few_2,      CC_red_totalred,wrong_no_2},
    {"reduce-mod-p*",           too_few_2,      CC_reduceKmodKpH,wrong_no_2},
    {"reduce-mod-eigf",         too_few_2,      CC_reduceKmodKeigf,wrong_no_2},
    {"ofsf_entry2at",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at},
    {"multdf",                  too_few_2,      CC_multdf,     wrong_no_2},
    {"evallessp",               too_few_2,      CC_evallessp,  wrong_no_2},
    {"makecoeffpairshom",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairshom},
    {"pasf_pdp",                CC_pasf_pdp,    too_many_1,    wrong_no_1},
    {"exptplus",                too_few_2,      CC_exptplus,   wrong_no_2},
    {"derad",                   too_few_2,      CC_derad,      wrong_no_2},
    {NULL, (one_args *)"u25", (two_args *)"30 3588000 7130486", 0}
};

/* end of generated code */
