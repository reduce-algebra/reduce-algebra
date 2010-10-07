
/* $destdir\u27.c        Machine generated C code */

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


/* Code for greatertype */

static Lisp_Object CC_greatertype(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v25, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greatertype");
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
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v24 = qvalue(elt(env, 1)); /* optlang!* */
    if (v24 == nil) goto v27;
    v24 = qvalue(elt(env, 1)); /* optlang!* */
    v25 = v24;
    goto v28;

v28:
    v24 = elt(env, 3); /* conversion */
    v24 = get(v25, v24);
    env = stack[-8];
    fn = elt(env, 6); /* eval */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    stack[-7] = v24;
    v24 = stack[-7];
    v25 = qcar(v24);
    v24 = stack[-5];
    if (equal(v25, v24)) goto v30;
    v24 = stack[-7];
    v25 = qcar(v24);
    v24 = stack[-6];
    if (!(equal(v25, v24))) goto v31;
    v24 = qvalue(elt(env, 5)); /* nil */
    stack[-1] = v24;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v31:
    v24 = stack[-7];
    v24 = qcdr(v24);
    stack[-7] = v24;
    if (v24 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v24 = stack[-4];
    if (!(v24 == nil)) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v24 = stack[-7];
    v24 = qcar(v24);
    v26 = v24;
    goto v32;

v32:
    v24 = v26;
    if (v24 == nil) goto v33;
    v24 = stack[-2];
    if (!(v24 == nil)) goto v33;
    v24 = v26;
    v25 = qcar(v24);
    v24 = stack[-6];
    if (!(equal(v25, v24))) goto v34;
    v24 = qvalue(elt(env, 4)); /* t */
    stack[-3] = v24;
    goto v34;

v34:
    v24 = v26;
    v25 = qcar(v24);
    v24 = stack[-5];
    if (equal(v25, v24)) goto v35;
    v24 = v26;
    v24 = qcdr(v24);
    v26 = v24;
    goto v32;

v35:
    v24 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v24;
    goto v32;

v33:
    v24 = stack[-2];
    if (v24 == nil) goto v36;
    v24 = v26;
    v24 = qcdr(v24);
    v26 = v24;
    goto v37;

v37:
    v24 = v26;
    if (v24 == nil) goto v36;
    v24 = stack[-1];
    if (!(v24 == nil)) goto v36;
    v24 = v26;
    v25 = qcar(v24);
    v24 = stack[-6];
    if (equal(v25, v24)) goto v38;
    v24 = v26;
    v24 = qcdr(v24);
    v26 = v24;
    goto v37;

v38:
    v24 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v24;
    stack[-3] = v24;
    goto v37;

v36:
    v24 = stack[-3];
    if (v24 == nil) goto v39;
    v24 = stack[-2];
    if (!(v24 == nil)) goto v39;

v40:
    stack[0] = (Lisp_Object)65; /* 4 */
    v25 = stack[-6];
    v24 = stack[-5];
    v24 = cons(v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    fn = elt(env, 7); /* typerror */
    v24 = (*qfn2(fn))(qenv(fn), stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-8];
    goto v31;

v39:
    v24 = stack[-3];
    if (!(v24 == nil)) goto v41;
    v24 = stack[-2];
    if (!(v24 == nil)) goto v40;

v41:
    v24 = stack[-3];
    if (v24 == nil) goto v31;
    v24 = stack[-2];
    if (v24 == nil) goto v31;
    v24 = qvalue(elt(env, 4)); /* t */
    stack[-4] = v24;
    goto v31;

v30:
    v24 = qvalue(elt(env, 4)); /* t */
    stack[-1] = v24;
    { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }

v27:
    v24 = elt(env, 2); /* fortran */
    v25 = v24;
    goto v28;
/* error exit handlers */
v29:
    popv(9);
    return nil;
}



/* Code for dipsum */

static Lisp_Object CC_dipsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipsum");
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
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v64 = stack[-6];
    if (v64 == nil) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v64 = stack[-5];
    if (v64 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    stack[-7] = nil;
    stack[-2] = nil;
    stack[0] = nil;
    goto v23;

v23:
    v64 = stack[-7];
    if (!(v64 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v64 = stack[-6];
    if (v64 == nil) goto v67;
    v64 = stack[-5];
    if (v64 == nil) goto v68;
    v64 = stack[-6];
    v64 = qcar(v64);
    stack[-4] = v64;
    v64 = stack[-5];
    v64 = qcar(v64);
    stack[-3] = v64;
    v65 = stack[-4];
    v64 = stack[-3];
    fn = elt(env, 3); /* evcomp */
    v64 = (*qfn2(fn))(qenv(fn), v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-1] = v64;
    v65 = stack[-1];
    v64 = (Lisp_Object)17; /* 1 */
    v64 = Leqn(nil, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    if (v64 == nil) goto v15;
    v66 = stack[-4];
    v64 = stack[-6];
    v64 = qcdr(v64);
    v65 = qcar(v64);
    v64 = qvalue(elt(env, 1)); /* nil */
    v64 = list2star(v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-1] = v64;
    v64 = stack[-6];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    stack[-6] = v64;
    goto v70;

v70:
    v64 = stack[-1];
    if (v64 == nil) goto v23;
    v64 = stack[0];
    if (v64 == nil) goto v71;
    v64 = stack[-2];
    v65 = qcdr(v64);
    v64 = stack[-1];
    fn = elt(env, 4); /* setcdr */
    v64 = (*qfn2(fn))(qenv(fn), v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    v64 = stack[-1];
    stack[-2] = v64;
    goto v23;

v71:
    v64 = stack[-1];
    stack[-2] = v64;
    stack[0] = v64;
    goto v23;

v15:
    v65 = stack[-1];
    v64 = (Lisp_Object)-15; /* -1 */
    v64 = Leqn(nil, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    if (v64 == nil) goto v72;
    v66 = stack[-3];
    v64 = stack[-5];
    v64 = qcdr(v64);
    v65 = qcar(v64);
    v64 = qvalue(elt(env, 1)); /* nil */
    v64 = list2star(v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-1] = v64;
    v64 = stack[-5];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    stack[-5] = v64;
    goto v70;

v72:
    v64 = stack[-6];
    v64 = qcdr(v64);
    v65 = qcar(v64);
    v64 = stack[-5];
    v64 = qcdr(v64);
    v64 = qcar(v64);
    fn = elt(env, 5); /* bcsum */
    v64 = (*qfn2(fn))(qenv(fn), v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    stack[-1] = v64;
    v64 = stack[-1];
    fn = elt(env, 6); /* bczero!? */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    if (v64 == nil) goto v73;
    v64 = qvalue(elt(env, 1)); /* nil */
    goto v74;

v74:
    stack[-1] = v64;
    v64 = stack[-6];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    stack[-6] = v64;
    v64 = stack[-5];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    stack[-5] = v64;
    goto v70;

v73:
    v66 = stack[-4];
    v65 = stack[-1];
    v64 = qvalue(elt(env, 1)); /* nil */
    v64 = list2star(v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-8];
    goto v74;

v68:
    v64 = stack[-6];
    stack[-1] = v64;
    v64 = qvalue(elt(env, 2)); /* t */
    stack[-7] = v64;
    goto v70;

v67:
    v64 = stack[-5];
    stack[-1] = v64;
    v64 = qvalue(elt(env, 2)); /* t */
    stack[-7] = v64;
    goto v70;
/* error exit handlers */
v69:
    popv(9);
    return nil;
}



/* Code for vevstrictlydivides!? */

static Lisp_Object CC_vevstrictlydividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79, v23, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevstrictlydivides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v23 = v1;
    v80 = v0;
/* end of prologue */
    v79 = v80;
    v78 = v23;
    if (equal(v79, v78)) goto v17;
    v78 = v23;
    v79 = v80;
    {
        fn = elt(env, 2); /* vevmtest!? */
        return (*qfn2(fn))(qenv(fn), v78, v79);
    }

v17:
    v78 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v78);
}



/* Code for evload */

static Lisp_Object CC_evload(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evload");
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

v10:
    v63 = stack[0];
    if (v63 == nil) goto v3;
    v63 = stack[0];
    v63 = qcar(v63);
    v63 = Lload_module(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v63 = stack[0];
    v63 = qcdr(v63);
    stack[0] = v63;
    goto v10;

v3:
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v63); }
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for getphystypecar */

static Lisp_Object CC_getphystypecar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypecar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v0;
/* end of prologue */
    v77 = v81;
    if (!consp(v77)) goto v10;
    v77 = v81;
    v77 = qcar(v77);
    {
        fn = elt(env, 2); /* getphystype */
        return (*qfn1(fn))(qenv(fn), v77);
    }

v10:
    v77 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v77);
}



/* Code for no!-side!-effectp */

static Lisp_Object CC_noKsideKeffectp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no-side-effectp");
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
    v31 = stack[0];
    if (!consp(v31)) goto v10;
    v31 = stack[0];
    v84 = qcar(v31);
    v31 = elt(env, 2); /* quote */
    if (v84 == v31) goto v80;
    v31 = stack[0];
    v84 = qcar(v31);
    v31 = elt(env, 4); /* nosideeffects */
    v31 = Lflagp(nil, v84, v31);
    env = stack[-1];
    if (v31 == nil) goto v85;
    v31 = stack[0];
    v31 = qcdr(v31);
    {
        popv(2);
        fn = elt(env, 5); /* no!-side!-effect!-listp */
        return (*qfn1(fn))(qenv(fn), v31);
    }

v85:
    v31 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v31); }

v80:
    v31 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v31); }

v10:
    v31 = stack[0];
    v31 = (is_number(v31) ? lisp_true : nil);
    if (!(v31 == nil)) { popv(2); return onevalue(v31); }
    v31 = stack[0];
    if (symbolp(v31)) goto v22;
    v31 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v31); }

v22:
    v31 = stack[0];
    v31 = Lsymbol_specialp(nil, v31);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    if (!(v31 == nil)) goto v57;
    v31 = stack[0];
    v31 = Lsymbol_globalp(nil, v31);
    goto v57;

v57:
    v31 = (v31 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v31); }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for mo_zero */

static Lisp_Object MS_CDECL CC_mo_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mo_zero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_zero");
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
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v86 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* mo!=deglist */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v76;
    {
        Lisp_Object v77 = stack[0];
        popv(1);
        return cons(v77, v86);
    }
/* error exit handlers */
v76:
    popv(1);
    return nil;
}



/* Code for list_is_all_free */

static Lisp_Object CC_list_is_all_free(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list_is_all_free");
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

v10:
    v57 = stack[0];
    if (v57 == nil) goto v3;
    v57 = stack[0];
    v57 = qcar(v57);
    fn = elt(env, 3); /* nodum_varp */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    if (v57 == nil) goto v22;
    v57 = stack[0];
    v57 = qcdr(v57);
    stack[0] = v57;
    goto v10;

v22:
    v57 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v57); }

v3:
    v57 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v57); }
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for reduce!-eival!-powers */

static Lisp_Object CC_reduceKeivalKpowers(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92, v85, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-eival-powers");
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
    v85 = v1;
    v93 = v0;
/* end of prologue */
    v91 = v85;
    if (!consp(v91)) goto v23;
    v91 = v85;
    v91 = qcar(v91);
    if (!consp(v91)) goto v23;
    v91 = v85;
    v91 = qcar(v91);
    v91 = qcar(v91);
    v92 = qcar(v91);
    v91 = v93;
    v91 = qcar(v91);
    v91 = qcar(v91);
    if (!(v92 == v91)) goto v23;
    stack[0] = v93;
    v92 = v85;
    v91 = (Lisp_Object)17; /* 1 */
    v91 = cons(v92, v91);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    {
        Lisp_Object v84 = stack[0];
        popv(2);
        fn = elt(env, 1); /* reduce!-eival!-powers1 */
        return (*qfn2(fn))(qenv(fn), v84, v91);
    }

v23:
    v92 = v85;
    v91 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v92, v91);
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for give!*position */

static Lisp_Object CC_giveHposition(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for give*position");
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
    v33 = (Lisp_Object)17; /* 1 */
    stack[-4] = v33;
    v33 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v33;
    goto v98;

v98:
    v33 = stack[-1];
    if (!(v33 == nil)) goto v86;
    stack[0] = stack[-4];
    v33 = stack[-2];
    v33 = Llength(nil, v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v33 = (Lisp_Object)lesseq2(stack[0], v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    v33 = v33 ? lisp_true : nil;
    env = stack[-5];
    if (v33 == nil) goto v86;
    v32 = stack[-2];
    v33 = stack[-4];
    fn = elt(env, 5); /* pnth */
    v33 = (*qfn2(fn))(qenv(fn), v32, v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    v32 = qcar(v33);
    v33 = stack[-3];
    if (equal(v32, v33)) goto v100;
    v33 = stack[-4];
    v33 = add1(v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    stack[-4] = v33;
    goto v98;

v100:
    v33 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v33;
    goto v98;

v86:
    v33 = stack[-1];
    if (!(v33 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v33 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v33 == nil)) goto v101;
    v33 = elt(env, 4); /* "error in give position" */
    fn = elt(env, 6); /* lprie */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-5];
    goto v101;

v101:
    v33 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v99;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v99:
    popv(6);
    return nil;
}



/* Code for pasf_subfof */

static Lisp_Object MS_CDECL CC_pasf_subfof(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v75, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_subfof");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v45 = v102;
    v75 = v1;
    v27 = v0;
/* end of prologue */
    stack[-1] = v45;
    stack[0] = elt(env, 1); /* pasf_subfof1 */
    v45 = v27;
    v45 = list2(v45, v75);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    {
        Lisp_Object v80 = stack[-1];
        Lisp_Object v103 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v80, v103, v45);
    }
/* error exit handlers */
v23:
    popv(3);
    return nil;
}



/* Code for lambdaom */

static Lisp_Object CC_lambdaom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdaom");
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
    v20 = v0;
/* end of prologue */
    v83 = v20;
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    v83 = qcar(v83);
    v83 = qcdr(v83);
    v83 = qcar(v83);
    stack[-1] = v83;
    v83 = v20;
    v83 = Lreverse(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = qcar(v83);
    stack[0] = v83;
    v83 = elt(env, 1); /* "<OMBIND>" */
    fn = elt(env, 8); /* printout */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 9); /* indent!* */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = elt(env, 3); /* "<OMS cd=""fns1"" name=""lambda""/>" */
    fn = elt(env, 8); /* printout */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = elt(env, 4); /* "<OMBVAR>" */
    fn = elt(env, 8); /* printout */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 9); /* indent!* */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = stack[-1];
    fn = elt(env, 10); /* objectom */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 9); /* indent!* */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = elt(env, 6); /* "</OMBVAR>" */
    fn = elt(env, 8); /* printout */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = stack[0];
    fn = elt(env, 10); /* objectom */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 9); /* indent!* */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v83 = elt(env, 7); /* "</OMBIND>" */
    fn = elt(env, 8); /* printout */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v83 = nil;
    { popv(3); return onevalue(v83); }
/* error exit handlers */
v68:
    popv(3);
    return nil;
}



/* Code for vdpilcomb1 */

static Lisp_Object MS_CDECL CC_vdpilcomb1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, Lisp_Object v16,
                         Lisp_Object v10, Lisp_Object v17, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110, v60, v111, v112, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "vdpilcomb1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpilcomb1");
#endif
    if (stack >= stacklimit)
    {
        push6(v17,v10,v16,v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v102,v16,v10,v17);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v17;
    v109 = v10;
    stack[-2] = v16;
    stack[-3] = v102;
    v110 = v1;
    stack[-4] = v0;
/* end of prologue */
    v60 = stack[-4];
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v60 = qcdr(v60);
    v58 = qcar(v60);
    v112 = v110;
    v111 = stack[-3];
    v110 = stack[-2];
    v110 = qcdr(v110);
    v110 = qcdr(v110);
    v110 = qcdr(v110);
    v60 = qcar(v110);
    v110 = v109;
    v109 = stack[-1];
    fn = elt(env, 2); /* dipilcomb1 */
    v109 = (*qfnn(fn))(qenv(fn), 6, v58, v112, v111, v60, v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    fn = elt(env, 3); /* dip2vdp */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    stack[-5] = v109;
    v109 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v109 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v109 = stack[-4];
    fn = elt(env, 4); /* gsugar */
    stack[-4] = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    v109 = stack[-3];
    fn = elt(env, 5); /* vevtdeg */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    stack[-3] = plus2(stack[-4], v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    v109 = stack[-2];
    fn = elt(env, 4); /* gsugar */
    stack[-2] = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    v109 = stack[-1];
    fn = elt(env, 5); /* vevtdeg */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    v109 = plus2(stack[-2], v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    fn = elt(env, 6); /* max */
    v109 = (*qfn2(fn))(qenv(fn), stack[-3], v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-6];
    fn = elt(env, 7); /* gsetsugar */
    v109 = (*qfn2(fn))(qenv(fn), stack[0], v109);
    nil = C_nil;
    if (exception_pending()) goto v113;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
/* error exit handlers */
v113:
    popv(7);
    return nil;
}



/* Code for module */

static Lisp_Object CC_module(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for module");
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
    v28 = v0;
/* end of prologue */
    v63 = qvalue(elt(env, 1)); /* !*mode */
    v28 = qvalue(elt(env, 2)); /* mode!-list!* */
    v28 = cons(v63, v28);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[0];
    qvalue(elt(env, 2)) = v28; /* mode!-list!* */
    v28 = qvalue(elt(env, 3)); /* nil */
    v28 = ncons(v28);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[0];
    qvalue(elt(env, 4)) = v28; /* alglist!* */
    v28 = elt(env, 5); /* symbolic */
    qvalue(elt(env, 1)) = v28; /* !*mode */
    v28 = nil;
    { popv(1); return onevalue(v28); }
/* error exit handlers */
v50:
    popv(1);
    return nil;
}



/* Code for list!-evaluate */

static Lisp_Object MS_CDECL CC_listKevaluate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v108, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "list-evaluate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-evaluate");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v102;
    stack[-4] = v1;
    v116 = v0;
/* end of prologue */
    stack[-5] = v116;
    v116 = stack[-5];
    if (v116 == nil) goto v77;
    v116 = stack[-5];
    v116 = qcar(v116);
    v117 = v116;
    v108 = stack[-4];
    v116 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v116 = (*qfnn(fn))(qenv(fn), 3, v117, v108, v116);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v116 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    stack[-1] = v116;
    stack[-2] = v116;
    goto v118;

v118:
    v116 = stack[-5];
    v116 = qcdr(v116);
    stack[-5] = v116;
    v116 = stack[-5];
    if (v116 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v116 = stack[-5];
    v116 = qcar(v116);
    v117 = v116;
    v108 = stack[-4];
    v116 = stack[-3];
    fn = elt(env, 2); /* evaluate */
    v116 = (*qfnn(fn))(qenv(fn), 3, v117, v108, v116);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v116 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v116 = Lrplacd(nil, stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v116 = stack[-1];
    v116 = qcdr(v116);
    stack[-1] = v116;
    goto v118;

v77:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v116); }
/* error exit handlers */
v105:
    popv(7);
    return nil;
}



/* Code for ezgcdf1 */

static Lisp_Object CC_ezgcdf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v63, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ezgcdf1");
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
    v63 = v1;
    v50 = v0;
/* end of prologue */
    v28 = (Lisp_Object)1; /* 0 */
    stack[0] = qvalue(elt(env, 1)); /* factor!-level */
    qvalue(elt(env, 1)) = v28; /* factor!-level */
    v28 = v50;
    v28 = list2(v28, v63);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    fn = elt(env, 2); /* gcdlist */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    fn = elt(env, 3); /* poly!-abs */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* factor!-level */
    { popv(2); return onevalue(v28); }
/* error exit handlers */
v43:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* factor!-level */
    popv(2);
    return nil;
}



/* Code for ratfunpri1 */

static Lisp_Object CC_ratfunpri1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v186, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratfunpri1");
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
    stack[0] = v0;
/* end of prologue */
    v186 = qvalue(elt(env, 1)); /* spare!* */
    v185 = (Lisp_Object)33; /* 2 */
    v185 = plus2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    qvalue(elt(env, 1)) = v185; /* spare!* */
    v185 = stack[0];
    v185 = qcdr(v185);
    v187 = qcar(v185);
    v186 = (Lisp_Object)1; /* 0 */
    v185 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 17); /* layout!-formula */
    v185 = (*qfnn(fn))(qenv(fn), 3, v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[-7] = v185;
    if (v185 == nil) goto v189;
    v185 = stack[0];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v187 = qcar(v185);
    v186 = (Lisp_Object)1; /* 0 */
    v185 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 17); /* layout!-formula */
    v185 = (*qfnn(fn))(qenv(fn), 3, v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[-6] = v185;
    if (v185 == nil) goto v189;
    v186 = qvalue(elt(env, 1)); /* spare!* */
    v185 = (Lisp_Object)33; /* 2 */
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    qvalue(elt(env, 1)) = v185; /* spare!* */
    stack[0] = (Lisp_Object)33; /* 2 */
    v185 = stack[-7];
    v185 = qcar(v185);
    v186 = qcdr(v185);
    v185 = stack[-6];
    v185 = qcar(v185);
    v185 = qcdr(v185);
    fn = elt(env, 18); /* max */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = plus2(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[-2] = v185;
    stack[0] = stack[-2];
    v185 = qvalue(elt(env, 2)); /* nil */
    v186 = Llinelength(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = qvalue(elt(env, 1)); /* spare!* */
    v186 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = qvalue(elt(env, 3)); /* posn!* */
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = (Lisp_Object)greaterp2(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v185 = v185 ? lisp_true : nil;
    env = stack[-8];
    if (v185 == nil) goto v190;
    v185 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    goto v190;

v190:
    v185 = stack[-7];
    v185 = qcar(v185);
    v186 = qcdr(v185);
    v185 = stack[-6];
    v185 = qcar(v185);
    v185 = qcdr(v185);
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[-1] = v185;
    v186 = stack[-1];
    v185 = (Lisp_Object)1; /* 0 */
    v185 = (Lisp_Object)greaterp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v185 = v185 ? lisp_true : nil;
    env = stack[-8];
    if (v185 == nil) goto v191;
    v185 = (Lisp_Object)1; /* 0 */
    stack[0] = v185;
    v186 = stack[-1];
    v185 = (Lisp_Object)33; /* 2 */
    v185 = quot2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[-3] = v185;
    goto v192;

v192:
    v185 = stack[-7];
    v185 = qcdr(v185);
    v186 = qcdr(v185);
    v185 = stack[-7];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[-5] = v185;
    v185 = stack[-6];
    v185 = qcdr(v185);
    v186 = qcdr(v185);
    v185 = stack[-6];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[-4] = v185;
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 3)); /* posn!* */
    v186 = (Lisp_Object)17; /* 1 */
    v185 = qvalue(elt(env, 5)); /* orig!* */
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = plus2(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[0] = plus2(stack[-1], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v186 = (Lisp_Object)17; /* 1 */
    v185 = stack[-7];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v186 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = qvalue(elt(env, 6)); /* ycoord!* */
    v186 = plus2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = stack[-7];
    v185 = qcar(v185);
    v185 = qcar(v185);
    fn = elt(env, 20); /* update!-pline */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[0], v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[0] = qvalue(elt(env, 3)); /* posn!* */
    v186 = (Lisp_Object)17; /* 1 */
    v185 = qvalue(elt(env, 5)); /* orig!* */
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = plus2(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[0] = plus2(stack[-3], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v186 = qvalue(elt(env, 6)); /* ycoord!* */
    v185 = stack[-6];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v186 = sub1(v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = stack[-6];
    v185 = qcar(v185);
    v185 = qcar(v185);
    fn = elt(env, 20); /* update!-pline */
    v186 = (*qfnn(fn))(qenv(fn), 3, stack[0], v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = qvalue(elt(env, 7)); /* pline!* */
    v185 = Lappend(nil, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = Lappend(nil, stack[-1], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    qvalue(elt(env, 7)) = v185; /* pline!* */
    stack[0] = qvalue(elt(env, 8)); /* ymin!* */
    v186 = qvalue(elt(env, 6)); /* ycoord!* */
    v185 = stack[-4];
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    fn = elt(env, 21); /* min */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    qvalue(elt(env, 8)) = v185; /* ymin!* */
    stack[0] = qvalue(elt(env, 9)); /* ymax!* */
    v186 = qvalue(elt(env, 6)); /* ycoord!* */
    v185 = stack[-5];
    v185 = plus2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    fn = elt(env, 18); /* max */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    qvalue(elt(env, 9)) = v185; /* ymax!* */
    v185 = elt(env, 10); /* bar */
    fn = elt(env, 22); /* symbol */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[-1] = v185;
    v185 = (Lisp_Object)17; /* 1 */
    stack[0] = v185;
    goto v193;

v193:
    v186 = stack[-2];
    v185 = stack[0];
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = Lminusp(nil, v185);
    env = stack[-8];
    if (!(v185 == nil)) goto v30;
    v185 = stack[-1];
    fn = elt(env, 23); /* prin2!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = stack[0];
    v185 = add1(v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[0] = v185;
    goto v193;

v30:
    v185 = nil;
    { popv(9); return onevalue(v185); }

v191:
    v185 = stack[-1];
    v186 = negate(v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = (Lisp_Object)33; /* 2 */
    v185 = quot2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    stack[0] = v185;
    v185 = (Lisp_Object)1; /* 0 */
    stack[-3] = v185;
    goto v192;

v189:
    v186 = qvalue(elt(env, 1)); /* spare!* */
    v185 = (Lisp_Object)33; /* 2 */
    v185 = difference2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    qvalue(elt(env, 1)) = v185; /* spare!* */
    v185 = stack[0];
    v185 = qcdr(v185);
    stack[0] = v185;
    v186 = elt(env, 11); /* quotient */
    v185 = elt(env, 12); /* infix */
    v185 = get(v186, v185);
    env = stack[-8];
    stack[-2] = v185;
    v185 = qvalue(elt(env, 13)); /* p!*!* */
    if (v185 == nil) goto v194;
    v186 = qvalue(elt(env, 13)); /* p!*!* */
    v185 = stack[-2];
    v185 = (Lisp_Object)greaterp2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v185 = v185 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v185;
    goto v195;

v195:
    v185 = stack[-1];
    if (v185 == nil) goto v196;
    v185 = elt(env, 14); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    goto v196;

v196:
    v185 = stack[0];
    v186 = qcar(v185);
    v185 = stack[-2];
    fn = elt(env, 24); /* maprint */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = elt(env, 11); /* quotient */
    fn = elt(env, 25); /* oprin */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = stack[0];
    v185 = qcdr(v185);
    v186 = qcar(v185);
    v185 = elt(env, 15); /* minus */
    if (!consp(v186)) goto v197;
    v186 = qcar(v186);
    if (!(v186 == v185)) goto v197;
    v185 = stack[0];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = qcdr(v185);
    v185 = qcar(v185);
    if (!(is_number(v185))) goto v197;
    v185 = stack[0];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v185 = negate(v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v186 = v185;
    goto v198;

v198:
    v185 = stack[-2];
    fn = elt(env, 24); /* maprint */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-8];
    v185 = stack[-1];
    if (v185 == nil) goto v30;
    v185 = elt(env, 16); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v188;
    goto v30;

v197:
    v185 = stack[0];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v186 = v185;
    goto v198;

v194:
    v185 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v185;
    goto v195;
/* error exit handlers */
v188:
    popv(9);
    return nil;
}



/* Code for general!-horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKhornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, Lisp_Object v16,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v204, v73, v205, v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "general-horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-horner-rule-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push5(v10,v16,v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v102,v16,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v10;
    stack[-3] = v16;
    stack[-4] = v102;
    v73 = v1;
    v205 = v0;
/* end of prologue */

v207:
    v203 = stack[-4];
    if (!consp(v203)) goto v11;
    v203 = stack[-4];
    v203 = qcar(v203);
    if (!consp(v203)) goto v11;
    v203 = stack[-4];
    v203 = qcar(v203);
    v203 = qcar(v203);
    v204 = qcar(v203);
    v203 = stack[-2];
    if (!(equal(v204, v203))) goto v11;
    v203 = stack[-4];
    v203 = qcar(v203);
    v203 = qcar(v203);
    v203 = qcdr(v203);
    stack[-5] = v203;
    v203 = stack[-3];
    if (v203 == nil) goto v181;
    v203 = stack[-3];
    v203 = (Lisp_Object)zerop(v203);
    v203 = v203 ? lisp_true : nil;
    env = stack[-6];
    if (!(v203 == nil)) goto v181;
    v203 = stack[-4];
    v203 = qcar(v203);
    stack[-1] = qcdr(v203);
    stack[0] = v205;
    v204 = stack[-3];
    v203 = stack[-5];
    v203 = (Lisp_Object)(int32_t)((int32_t)v73 - (int32_t)v203 + TAG_FIXNUM);
    fn = elt(env, 1); /* general!-expt!-mod!-p */
    v203 = (*qfn2(fn))(qenv(fn), v204, v203);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-6];
    fn = elt(env, 2); /* general!-times!-mod!-p */
    v203 = (*qfn2(fn))(qenv(fn), stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-6];
    fn = elt(env, 3); /* general!-plus!-mod!-p */
    v203 = (*qfn2(fn))(qenv(fn), stack[-1], v203);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-6];
    v205 = v203;
    goto v208;

v208:
    v73 = stack[-5];
    v203 = stack[-4];
    v206 = qcdr(v203);
    v204 = stack[-3];
    v203 = stack[-2];
    stack[-4] = v206;
    stack[-3] = v204;
    stack[-2] = v203;
    goto v207;

v181:
    v203 = stack[-4];
    v203 = qcar(v203);
    v203 = qcdr(v203);
    v205 = v203;
    goto v208;

v11:
    v203 = stack[-3];
    if (v203 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v203 = stack[-3];
    v203 = (Lisp_Object)zerop(v203);
    v203 = v203 ? lisp_true : nil;
    env = stack[-6];
    if (!(v203 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v205;
    v203 = stack[-3];
    v204 = v73;
    fn = elt(env, 1); /* general!-expt!-mod!-p */
    v203 = (*qfn2(fn))(qenv(fn), v203, v204);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-6];
    fn = elt(env, 2); /* general!-times!-mod!-p */
    v203 = (*qfn2(fn))(qenv(fn), stack[0], v203);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-6];
    v205 = v203;
    v203 = stack[-4];
    v204 = v205;
    {
        popv(7);
        fn = elt(env, 3); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v203, v204);
    }
/* error exit handlers */
v48:
    popv(7);
    return nil;
}



/* Code for tayexp!-minus */

static Lisp_Object CC_tayexpKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-minus");
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v80 = stack[0];
    if (!consp(v80)) goto v10;
    v80 = stack[0];
    stack[-1] = qcar(v80);
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcar(v80);
    fn = elt(env, 1); /* !:minus */
    v103 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v80 = stack[0];
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    {
        Lisp_Object v89 = stack[-1];
        popv(2);
        return list2star(v89, v103, v80);
    }

v10:
    v80 = stack[0];
    popv(2);
    return negate(v80);
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for get!*inverse */

static Lisp_Object CC_getHinverse(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v209, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*inverse");
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
    v209 = v1;
    v89 = v0;
/* end of prologue */
    v70 = v89;
    v89 = elt(env, 1); /* inverse */
    v89 = get(v70, v89);
    env = stack[-1];
    v70 = v89;
    v89 = v70;
    v89 = qcdr(v89);
    stack[0] = qcar(v89);
    v89 = v209;
    v209 = v70;
    v209 = qcar(v209);
    fn = elt(env, 2); /* give!*position */
    v89 = (*qfn2(fn))(qenv(fn), v89, v209);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-1];
    fn = elt(env, 3); /* pnth */
    v89 = (*qfn2(fn))(qenv(fn), stack[0], v89);
    nil = C_nil;
    if (exception_pending()) goto v83;
    v89 = qcar(v89);
    { popv(2); return onevalue(v89); }
/* error exit handlers */
v83:
    popv(2);
    return nil;
}



/* Code for ctx_idl */

static Lisp_Object CC_ctx_idl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_idl");
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
    v97 = v0;
/* end of prologue */
    fn = elt(env, 2); /* ctx_ial */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    stack[-3] = v97;
    v97 = stack[-3];
    if (v97 == nil) goto v76;
    v97 = stack[-3];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    stack[-1] = v97;
    stack[-2] = v97;
    goto v3;

v3:
    v97 = stack[-3];
    v97 = qcdr(v97);
    stack[-3] = v97;
    v97 = stack[-3];
    if (v97 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v97 = stack[-3];
    v97 = qcar(v97);
    v97 = qcar(v97);
    v97 = ncons(v97);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    v97 = Lrplacd(nil, stack[0], v97);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-1] = v97;
    goto v3;

v76:
    v97 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v97); }
/* error exit handlers */
v19:
    popv(5);
    return nil;
}



/* Code for ev_sum */

static Lisp_Object CC_ev_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v210;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_sum");
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
    v210 = nil;
    goto v11;

v11:
    v20 = stack[-1];
    if (v20 == nil) goto v3;
    v20 = stack[-1];
    v21 = qcar(v20);
    v20 = stack[0];
    v20 = qcar(v20);
    v20 = (Lisp_Object)(int32_t)((int32_t)v21 + (int32_t)v20 - TAG_FIXNUM);
    v21 = v210;
    v20 = cons(v20, v21);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-2];
    v210 = v20;
    v20 = stack[-1];
    v20 = qcdr(v20);
    stack[-1] = v20;
    v20 = stack[0];
    v20 = qcdr(v20);
    stack[0] = v20;
    goto v11;

v3:
    v20 = v210;
        popv(3);
        return Lnreverse(nil, v20);
/* error exit handlers */
v88:
    popv(3);
    return nil;
}



/* Code for omfir */

static Lisp_Object MS_CDECL CC_omfir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omfir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omfir");
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
    v209 = qvalue(elt(env, 1)); /* atts */
    v89 = elt(env, 2); /* dec */
    fn = elt(env, 5); /* find */
    v89 = (*qfn2(fn))(qenv(fn), v209, v89);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    stack[0] = v89;
    v209 = qvalue(elt(env, 1)); /* atts */
    v89 = elt(env, 3); /* name */
    fn = elt(env, 5); /* find */
    v89 = (*qfn2(fn))(qenv(fn), v209, v89);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    if (v89 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v209 = elt(env, 4); /* "wrong att" */
    v89 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v89 = (*qfn2(fn))(qenv(fn), v209, v89);
    nil = C_nil;
    if (exception_pending()) goto v67;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v67:
    popv(2);
    return nil;
}



/* Code for mkempspmat */

static Lisp_Object CC_mkempspmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkempspmat");
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
    stack[0] = v1;
    v43 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* sparsemat */
    v44 = Lmkvect(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v43 = stack[0];
    {
        Lisp_Object v27 = stack[-1];
        popv(2);
        return list3(v27, v44, v43);
    }
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for specrd!:times */

static Lisp_Object CC_specrdTtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for specrd:times");
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
    v215 = stack[-1];
    fn = elt(env, 4); /* add_minus */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    stack[-1] = v215;
    v215 = stack[0];
    fn = elt(env, 4); /* add_minus */
    v215 = (*qfn1(fn))(qenv(fn), v215);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    stack[0] = v215;
    v216 = stack[-1];
    v215 = elt(env, 1); /* minus */
    if (!consp(v216)) goto v100;
    v216 = qcar(v216);
    if (!(v216 == v215)) goto v100;
    v215 = stack[-1];
    v215 = qcdr(v215);
    v215 = qcar(v215);
    stack[-1] = v215;
    v215 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v215;
    goto v100;

v100:
    v216 = stack[0];
    v215 = elt(env, 1); /* minus */
    if (!consp(v216)) goto v23;
    v216 = qcar(v216);
    if (!(v216 == v215)) goto v23;
    v215 = stack[0];
    v215 = qcdr(v215);
    v215 = qcar(v215);
    stack[0] = v215;
    v215 = stack[-2];
    v215 = (v215 == nil ? lisp_true : nil);
    stack[-2] = v215;
    goto v23;

v23:
    v215 = stack[-1];
    if (!(!consp(v215))) goto v96;
    v215 = stack[-1];
    v215 = Lfloat(nil, v215);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v216 = v215;
    if (!(!consp(v216))) goto v92;
    v216 = elt(env, 3); /* !:rd!: */
    v215 = cons(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    goto v92;

v92:
    stack[-1] = v215;
    goto v96;

v96:
    v215 = stack[0];
    if (!(!consp(v215))) goto v183;
    v215 = stack[0];
    v215 = Lfloat(nil, v215);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v216 = v215;
    if (!(!consp(v216))) goto v180;
    v216 = elt(env, 3); /* !:rd!: */
    v215 = cons(v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    goto v180;

v180:
    stack[0] = v215;
    goto v183;

v183:
    v215 = stack[-2];
    if (v215 == nil) goto v179;
    stack[-2] = elt(env, 1); /* minus */
    v216 = stack[-1];
    v215 = stack[0];
    fn = elt(env, 5); /* rd!:times */
    v215 = (*qfn2(fn))(qenv(fn), v216, v215);
    nil = C_nil;
    if (exception_pending()) goto v175;
    {
        Lisp_Object v52 = stack[-2];
        popv(4);
        return list2(v52, v215);
    }

v179:
    v216 = stack[-1];
    v215 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* rd!:times */
        return (*qfn2(fn))(qenv(fn), v216, v215);
    }
/* error exit handlers */
v175:
    popv(4);
    return nil;
}



/* Code for indexsymmetrize */

static Lisp_Object CC_indexsymmetrize(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v208, v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexsymmetrize");
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
    v105 = stack[-2];
    v208 = qcar(v105);
    v105 = elt(env, 1); /* indxsymmetrize */
    v105 = get(v208, v105);
    env = stack[-4];
    stack[-3] = v105;
    v105 = (Lisp_Object)17; /* 1 */
    stack[0] = v105;
    v208 = (Lisp_Object)17; /* 1 */
    v105 = stack[-2];
    v105 = qcdr(v105);
    v105 = cons(v208, v105);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    stack[-1] = v105;
    goto v3;

v3:
    v105 = stack[-3];
    if (v105 == nil) goto v209;
    v105 = stack[-3];
    v208 = qcar(v105);
    v105 = stack[-1];
    v105 = qcdr(v105);
    v105 = Lapply1(nil, v208, v105);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    stack[-1] = v105;
    v105 = stack[-1];
    if (v105 == nil) goto v61;
    v105 = stack[-1];
    v208 = qcar(v105);
    v105 = stack[0];
    v105 = times2(v208, v105);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    stack[0] = v105;
    v105 = stack[-3];
    v105 = qcdr(v105);
    stack[-3] = v105;
    goto v3;

v61:
    v105 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v105); }

v209:
    v106 = stack[0];
    v105 = stack[-2];
    v208 = qcar(v105);
    v105 = stack[-1];
    v105 = qcdr(v105);
    popv(5);
    return list2star(v106, v208, v105);
/* error exit handlers */
v60:
    popv(5);
    return nil;
}



/* Code for !*xadd */

static Lisp_Object CC_Hxadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v93, v217, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *xadd");
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
    v31 = v1;
    stack[0] = v0;
/* end of prologue */
    v85 = v31;
    v217 = v85;
    goto v118;

v118:
    v85 = v217;
    if (v85 == nil) goto v11;
    v85 = stack[0];
    v93 = qcar(v85);
    v85 = v217;
    v85 = qcar(v85);
    v85 = qcar(v85);
    if (equal(v93, v85)) goto v11;
    v85 = v217;
    v85 = qcdr(v85);
    v217 = v85;
    goto v118;

v11:
    v85 = v217;
    if (v85 == nil) goto v97;
    v85 = v217;
    v85 = qcar(v85);
    v93 = v31;
    v85 = Ldelete(nil, v85, v93);
    nil = C_nil;
    if (exception_pending()) goto v61;
    v31 = v85;
    goto v97;

v97:
    v85 = stack[0];
    v93 = v31;
    popv(1);
    return cons(v85, v93);
/* error exit handlers */
v61:
    popv(1);
    return nil;
}



/* Code for contract!-strand */

static Lisp_Object CC_contractKstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contract-strand");
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
    v76 = v1;
    v77 = v0;
/* end of prologue */
    stack[0] = v77;
    fn = elt(env, 1); /* zero!-roads */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    {
        Lisp_Object v63 = stack[0];
        popv(2);
        fn = elt(env, 2); /* contr!-strand */
        return (*qfn2(fn))(qenv(fn), v63, v76);
    }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for open */

static Lisp_Object CC_open(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v111, v112, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for open");
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
    v112 = v1;
    v58 = v0;
/* end of prologue */
    v111 = v112;
    v60 = elt(env, 1); /* input */
    if (v111 == v60) goto v28;
    v111 = v112;
    v60 = elt(env, 2); /* output */
    if (v111 == v60) goto v90;
    v111 = v112;
    v60 = elt(env, 3); /* append */
    if (v111 == v60) goto v31;
    v60 = elt(env, 4); /* "bad direction ~A in open" */
    v111 = v112;
    {
        popv(2);
        fn = elt(env, 5); /* error */
        return (*qfn2(fn))(qenv(fn), v60, v111);
    }

v31:
    stack[0] = v58;
    v111 = (Lisp_Object)33; /* 2 */
    v60 = (Lisp_Object)641; /* 40 */
    v60 = plus2(v111, v60);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-1];
    {
        Lisp_Object v213 = stack[0];
        popv(2);
        fn = elt(env, 6); /* internal!-open */
        return (*qfn2(fn))(qenv(fn), v213, v60);
    }

v90:
    stack[0] = v58;
    v111 = (Lisp_Object)33; /* 2 */
    v60 = (Lisp_Object)833; /* 52 */
    v60 = plus2(v111, v60);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-1];
    {
        Lisp_Object v214 = stack[0];
        popv(2);
        fn = elt(env, 6); /* internal!-open */
        return (*qfn2(fn))(qenv(fn), v214, v60);
    }

v28:
    v111 = v58;
    v60 = (Lisp_Object)1041; /* 65 */
    {
        popv(2);
        fn = elt(env, 6); /* internal!-open */
        return (*qfn2(fn))(qenv(fn), v111, v60);
    }
/* error exit handlers */
v181:
    popv(2);
    return nil;
}



/* Code for innprodpex */

static Lisp_Object CC_innprodpex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodpex");
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

v207:
    v218 = stack[-1];
    if (v218 == nil) goto v17;
    v105 = stack[-2];
    v218 = stack[-1];
    v218 = qcar(v218);
    v218 = qcar(v218);
    fn = elt(env, 2); /* innprodp2 */
    v218 = (*qfn2(fn))(qenv(fn), v105, v218);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    v105 = v218;
    v218 = v105;
    if (v218 == nil) goto v116;
    v218 = v105;
    stack[-3] = qcdr(v218);
    v218 = v105;
    v218 = qcar(v218);
    if (v218 == nil) goto v94;
    v218 = stack[-1];
    v218 = qcar(v218);
    v218 = qcdr(v218);
    fn = elt(env, 3); /* negf */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-4];
    stack[0] = v218;
    goto v85;

v85:
    v105 = stack[-2];
    v218 = stack[-1];
    v218 = qcdr(v218);
    v218 = CC_innprodpex(env, v105, v218);
    nil = C_nil;
    if (exception_pending()) goto v109;
    {
        Lisp_Object v110 = stack[-3];
        Lisp_Object v60 = stack[0];
        popv(5);
        return acons(v110, v60, v218);
    }

v94:
    v218 = stack[-1];
    v218 = qcar(v218);
    v218 = qcdr(v218);
    stack[0] = v218;
    goto v85;

v116:
    v105 = stack[-2];
    v218 = stack[-1];
    v218 = qcdr(v218);
    stack[-2] = v105;
    stack[-1] = v218;
    goto v207;

v17:
    v218 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v218); }
/* error exit handlers */
v109:
    popv(5);
    return nil;
}



/* Code for pasf_simplat1 */

static Lisp_Object CC_pasf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v229, v230;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_simplat1");
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
    v228 = v1;
    v229 = v0;
/* end of prologue */
    v228 = v229;
    fn = elt(env, 6); /* pasf_zcong */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    fn = elt(env, 7); /* pasf_mkpos */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    fn = elt(env, 8); /* pasf_dt */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    fn = elt(env, 9); /* pasf_vf */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    v229 = v228;
    v230 = v229;
    v228 = elt(env, 1); /* true */
    if (v230 == v228) { popv(1); return onevalue(v229); }
    v230 = v229;
    v228 = elt(env, 2); /* false */
    if (v230 == v228) { popv(1); return onevalue(v229); }
    v228 = v229;
    v228 = Lconsp(nil, v228);
    env = stack[0];
    if (v228 == nil) goto v105;
    v228 = v229;
    v228 = qcar(v228);
    v228 = Lconsp(nil, v228);
    env = stack[0];
    if (v228 == nil) goto v105;
    v228 = v229;
    v228 = qcar(v228);
    v230 = qcar(v228);
    v228 = elt(env, 3); /* (cong ncong) */
    v228 = Lmemq(nil, v230, v228);
    if (v228 == nil) goto v105;
    v228 = v229;
    fn = elt(env, 10); /* pasf_mr */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    fn = elt(env, 9); /* pasf_vf */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    fn = elt(env, 11); /* pasf_cecong */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    v229 = v228;
    goto v179;

v179:
    v230 = v229;
    v228 = elt(env, 1); /* true */
    if (v230 == v228) { popv(1); return onevalue(v229); }
    v230 = v229;
    v228 = elt(env, 2); /* false */
    if (v230 == v228) { popv(1); return onevalue(v229); }
    v230 = v229;
    v228 = elt(env, 1); /* true */
    if (v230 == v228) goto v8;
    v230 = v229;
    v228 = elt(env, 2); /* false */
    if (v230 == v228) goto v8;
    v228 = v229;
    v228 = qcar(v228);
    v228 = Lconsp(nil, v228);
    env = stack[0];
    if (v228 == nil) goto v4;
    v228 = v229;
    v228 = qcar(v228);
    v228 = qcar(v228);
    v230 = v228;
    goto v205;

v205:
    v228 = elt(env, 3); /* (cong ncong) */
    v228 = Lmemq(nil, v230, v228);
    if (v228 == nil) goto v170;
    v228 = v229;
    fn = elt(env, 12); /* pasf_sc */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    goto v201;

v201:
    v229 = v228;
    v228 = qvalue(elt(env, 5)); /* !*rlsifac */
    if (v228 == nil) { popv(1); return onevalue(v229); }
    v228 = v229;
    {
        popv(1);
        fn = elt(env, 13); /* pasf_fact */
        return (*qfn1(fn))(qenv(fn), v228);
    }

v170:
    v230 = v229;
    v228 = elt(env, 1); /* true */
    if (v230 == v228) goto v24;
    v230 = v229;
    v228 = elt(env, 2); /* false */
    if (v230 == v228) goto v24;
    v228 = v229;
    v228 = qcar(v228);
    v228 = Lconsp(nil, v228);
    env = stack[0];
    if (v228 == nil) goto v232;
    v228 = v229;
    v228 = qcar(v228);
    v228 = qcar(v228);
    v230 = v228;
    goto v65;

v65:
    v228 = elt(env, 4); /* (equal neq) */
    v228 = Lmemq(nil, v230, v228);
    if (v228 == nil) goto v233;
    v228 = v229;
    fn = elt(env, 14); /* pasf_se */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    goto v201;

v233:
    v228 = v229;
    fn = elt(env, 15); /* pasf_or */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    goto v201;

v232:
    v228 = v229;
    v228 = qcar(v228);
    v230 = v228;
    goto v65;

v24:
    v228 = v229;
    v230 = v228;
    goto v65;

v4:
    v228 = v229;
    v228 = qcar(v228);
    v230 = v228;
    goto v205;

v8:
    v228 = v229;
    v230 = v228;
    goto v205;

v105:
    v230 = v229;
    v228 = elt(env, 1); /* true */
    if (v230 == v228) goto v33;
    v230 = v229;
    v228 = elt(env, 2); /* false */
    if (v230 == v228) goto v33;
    v228 = v229;
    v228 = qcar(v228);
    v228 = Lconsp(nil, v228);
    env = stack[0];
    if (v228 == nil) goto v56;
    v228 = v229;
    v228 = qcar(v228);
    v228 = qcar(v228);
    v230 = v228;
    goto v108;

v108:
    v228 = elt(env, 4); /* (equal neq) */
    v228 = Lmemq(nil, v230, v228);
    if (v228 == nil) goto v12;
    v228 = v229;
    fn = elt(env, 16); /* pasf_ceeq */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    v229 = v228;
    goto v179;

v12:
    v228 = v229;
    fn = elt(env, 17); /* pasf_cein */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[0];
    v229 = v228;
    goto v179;

v56:
    v228 = v229;
    v228 = qcar(v228);
    v230 = v228;
    goto v108;

v33:
    v228 = v229;
    v230 = v228;
    goto v108;
/* error exit handlers */
v231:
    popv(1);
    return nil;
}



/* Code for vdp_plist */

static Lisp_Object CC_vdp_plist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v11;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_plist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v0;
/* end of prologue */
    v11 = qcdr(v11);
    v11 = qcdr(v11);
    v11 = qcdr(v11);
    v11 = qcdr(v11);
    v11 = qcar(v11);
    return onevalue(v11);
}



/* Code for lambdafun */

static Lisp_Object CC_lambdafun(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambdafun");
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
    v3 = v0;
/* end of prologue */
    v3 = Lreverse(nil, v3);
    errexit();
    v3 = qcar(v3);
    return onevalue(v3);
}



/* Code for simpunion */

static Lisp_Object CC_simpunion(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v99, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpunion");
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
    v180 = v0;
/* end of prologue */
    v99 = elt(env, 1); /* union */
    fn = elt(env, 3); /* applysetop */
    v180 = (*qfn2(fn))(qenv(fn), v99, v180);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v109 = v180;
    v180 = v109;
    v99 = qcar(v180);
    v180 = elt(env, 1); /* union */
    if (v99 == v180) goto v82;
    v180 = v109;
    goto v90;

v90:
    fn = elt(env, 4); /* fkern */
    v99 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v180 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* getpower */
    v99 = (*qfn2(fn))(qenv(fn), v99, v180);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v180 = (Lisp_Object)17; /* 1 */
    v180 = cons(v99, v180);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v99 = ncons(v180);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v180 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v99, v180);

v82:
    v180 = qvalue(elt(env, 2)); /* empty_set */
    v99 = v109;
    v99 = qcdr(v99);
    v180 = Ldelete(nil, v180, v99);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v109 = v180;
    v180 = qcdr(v180);
    if (v180 == nil) goto v117;
    stack[0] = elt(env, 1); /* union */
    v180 = v109;
    fn = elt(env, 6); /* ordn */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v180 = cons(stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    goto v90;

v117:
    v180 = v109;
    v180 = qcar(v180);
    goto v90;
/* error exit handlers */
v60:
    popv(2);
    return nil;
}



/* Code for formc!* */

static Lisp_Object MS_CDECL CC_formcH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v57, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formc*");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v44 = v102;
    v57 = v1;
    v45 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*!*a2sfn */
    qvalue(elt(env, 1)) = nil; /* !*!*a2sfn */
    v43 = elt(env, 2); /* revalx */
    qvalue(elt(env, 1)) = v43; /* !*!*a2sfn */
    v43 = v45;
    fn = elt(env, 3); /* formc */
    v43 = (*qfnn(fn))(qenv(fn), 3, v43, v57, v44);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*!*a2sfn */
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v27:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*!*a2sfn */
    popv(2);
    return nil;
}



/* Code for !*a2k */

static Lisp_Object CC_Ha2k(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *a2k");
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
    v70 = stack[0];
    fn = elt(env, 2); /* simp!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    stack[-1] = v70;
    fn = elt(env, 3); /* kernp */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    if (v70 == nil) goto v44;
    v70 = stack[-1];
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcar(v70);
    v70 = qcar(v70);
    { popv(3); return onevalue(v70); }

v44:
    v70 = stack[0];
    if (v70 == nil) goto v23;
    v70 = stack[0];
    v67 = v70;
    goto v45;

v45:
    v70 = elt(env, 1); /* kernel */
    fn = elt(env, 4); /* typerr */
    v70 = (*qfn2(fn))(qenv(fn), v67, v70);
    nil = C_nil;
    if (exception_pending()) goto v21;
    v70 = nil;
    { popv(3); return onevalue(v70); }

v23:
    v70 = (Lisp_Object)1; /* 0 */
    v67 = v70;
    goto v45;
/* error exit handlers */
v21:
    popv(3);
    return nil;
}



/* Code for fs!:prin */

static Lisp_Object CC_fsTprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin");
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
    v83 = stack[0];
    if (!(v83 == nil)) goto v77;
    v83 = elt(env, 1); /* " 0 " */
    {
        popv(2);
        fn = elt(env, 4); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v83);
    }

v77:
    v83 = stack[0];
    if (v83 == nil) goto v63;
    v83 = stack[0];
    fn = elt(env, 5); /* fs!:prin1 */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    v20 = stack[0];
    v83 = (Lisp_Object)49; /* 3 */
    v83 = *(Lisp_Object *)((char *)v20 + (CELL-TAG_VECTOR) + ((int32_t)v83/(16/CELL)));
    stack[0] = v83;
    v83 = stack[0];
    if (v83 == nil) goto v77;
    v83 = elt(env, 3); /* " + " */
    fn = elt(env, 4); /* prin2!* */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    goto v77;

v63:
    v83 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v83); }
/* error exit handlers */
v210:
    popv(2);
    return nil;
}



/* Code for !*f2di */

static Lisp_Object CC_Hf2di(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v102)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *f2di");
#endif
    if (stack >= stacklimit)
    {
        push2(v102,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v248 = v102;
    stack[-5] = v1;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v248; /* varlist */
    v248 = stack[-5];
    if (v248 == nil) goto v86;
    v248 = stack[-5];
    if (!consp(v248)) goto v75;
    v248 = stack[-5];
    v248 = qcar(v248);
    if (!consp(v248)) goto v75;
    v248 = stack[-5];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v249 = qcar(v248);
    v248 = qvalue(elt(env, 1)); /* varlist */
    v248 = Lmember(nil, v249, v248);
    if (v248 == nil) goto v250;
    v248 = stack[-5];
    v248 = qcar(v248);
    v249 = qcdr(v248);
    v248 = qvalue(elt(env, 1)); /* varlist */
    stack[-4] = CC_Hf2di(env, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = qvalue(elt(env, 1)); /* varlist */
    stack[-3] = v248;
    v248 = stack[-3];
    if (v248 == nil) goto v190;
    v248 = stack[-3];
    v248 = qcar(v248);
    v249 = v248;
    v248 = stack[-5];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    if (equal(v249, v248)) goto v74;
    v248 = (Lisp_Object)1; /* 0 */
    goto v46;

v46:
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    stack[-1] = v248;
    stack[-2] = v248;
    goto v178;

v178:
    v248 = stack[-3];
    v248 = qcdr(v248);
    stack[-3] = v248;
    v248 = stack[-3];
    if (v248 == nil) goto v39;
    stack[0] = stack[-1];
    v248 = stack[-3];
    v248 = qcar(v248);
    v249 = v248;
    v248 = stack[-5];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    if (equal(v249, v248)) goto v5;
    v248 = (Lisp_Object)1; /* 0 */
    goto v4;

v4:
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = Lrplacd(nil, stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = stack[-1];
    v248 = qcdr(v248);
    stack[-1] = v248;
    goto v178;

v5:
    v248 = stack[-5];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcdr(v248);
    goto v4;

v39:
    v248 = stack[-2];
    goto v179;

v179:
    fn = elt(env, 3); /* addgt */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    fn = elt(env, 4); /* pdmult */
    v248 = (*qfn2(fn))(qenv(fn), stack[-4], v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    stack[0] = v248;
    goto v233;

v233:
    v248 = stack[-5];
    v249 = qcdr(v248);
    v248 = qvalue(elt(env, 1)); /* varlist */
    v248 = CC_Hf2di(env, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    fn = elt(env, 5); /* psum */
    v248 = (*qfn2(fn))(qenv(fn), stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    goto v2;

v2:
    qvalue(elt(env, 1)) = stack[-6]; /* varlist */
    { popv(8); return onevalue(v248); }

v74:
    v248 = stack[-5];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcdr(v248);
    goto v46;

v190:
    v248 = qvalue(elt(env, 2)); /* nil */
    goto v179;

v250:
    v248 = stack[-5];
    v248 = qcar(v248);
    v249 = qcdr(v248);
    v248 = qvalue(elt(env, 1)); /* varlist */
    stack[0] = CC_Hf2di(env, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = stack[-5];
    v248 = qcar(v248);
    v249 = qcar(v248);
    v248 = (Lisp_Object)17; /* 1 */
    v248 = cons(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    fn = elt(env, 6); /* pcmult */
    v248 = (*qfn2(fn))(qenv(fn), stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    stack[0] = v248;
    goto v233;

v75:
    v248 = qvalue(elt(env, 1)); /* varlist */
    stack[-3] = v248;
    v248 = stack[-3];
    if (v248 == nil) goto v20;
    v248 = (Lisp_Object)1; /* 0 */
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    stack[-1] = v248;
    stack[-2] = v248;
    goto v209;

v209:
    v248 = stack[-3];
    v248 = qcdr(v248);
    stack[-3] = v248;
    v248 = stack[-3];
    if (v248 == nil) goto v91;
    stack[0] = stack[-1];
    v248 = (Lisp_Object)1; /* 0 */
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = Lrplacd(nil, stack[0], v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = stack[-1];
    v248 = qcdr(v248);
    stack[-1] = v248;
    goto v209;

v91:
    v248 = stack[-2];
    goto v89;

v89:
    fn = elt(env, 3); /* addgt */
    v249 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = stack[-5];
    v248 = cons(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    v248 = ncons(v248);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-7];
    goto v2;

v20:
    v248 = qvalue(elt(env, 2)); /* nil */
    goto v89;

v86:
    v248 = qvalue(elt(env, 2)); /* nil */
    goto v2;
/* error exit handlers */
v162:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varlist */
    popv(8);
    return nil;
}



/* Code for comb */

static Lisp_Object CC_comb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comb");
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
    v176 = stack[-3];
    v34 = (Lisp_Object)1; /* 0 */
    if (v176 == v34) goto v86;
    v34 = stack[-4];
    v176 = Llength(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-6];
    v34 = stack[-3];
    v176 = difference2(v176, v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-6];
    stack[-5] = v176;
    v34 = (Lisp_Object)1; /* 0 */
    v34 = (Lisp_Object)lessp2(v176, v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v34 = v34 ? lisp_true : nil;
    env = stack[-6];
    if (v34 == nil) goto v210;
    v34 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v34); }

v210:
    v34 = (Lisp_Object)17; /* 1 */
    stack[-2] = v34;
    goto v85;

v85:
    v176 = stack[-5];
    v34 = stack[-2];
    v34 = difference2(v176, v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-6];
    v34 = Lminusp(nil, v34);
    env = stack[-6];
    if (v34 == nil) goto v101;
    v176 = stack[-4];
    v34 = stack[0];
    popv(7);
    return cons(v176, v34);

v101:
    stack[-1] = stack[0];
    v34 = stack[-4];
    stack[0] = qcdr(v34);
    v34 = stack[-3];
    v34 = sub1(v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-6];
    v176 = CC_comb(env, stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-6];
    v34 = stack[-4];
    v34 = qcar(v34);
    fn = elt(env, 2); /* mapcons */
    v34 = (*qfn2(fn))(qenv(fn), v176, v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-6];
    v34 = Lnconc(nil, stack[-1], v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-6];
    stack[0] = v34;
    v34 = stack[-4];
    v34 = qcdr(v34);
    stack[-4] = v34;
    v34 = stack[-2];
    v34 = add1(v34);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-6];
    stack[-2] = v34;
    goto v85;

v86:
    v34 = qvalue(elt(env, 1)); /* nil */
    popv(7);
    return ncons(v34);
/* error exit handlers */
v55:
    popv(7);
    return nil;
}



/* Code for xquotient!-mod!-p */

static Lisp_Object MS_CDECL CC_xquotientKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xquotient-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xquotient-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v64 = stack[-2];
    if (v64 == nil) goto v2;
    v64 = stack[-2];
    if (!consp(v64)) goto v86;
    v64 = stack[-2];
    v64 = qcar(v64);
    if (!consp(v64)) goto v86;
    v64 = stack[-2];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v65 = qcar(v64);
    v64 = stack[0];
    if (!(equal(v65, v64))) goto v86;
    v64 = stack[-2];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v65 = qcdr(v64);
    v64 = stack[-1];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v64 = qcdr(v64);
    if (((int32_t)(v65)) < ((int32_t)(v64))) goto v86;
    v64 = stack[-2];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v65 = qcdr(v64);
    v64 = stack[-1];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v64 = qcdr(v64);
    if (equal(v65, v64)) goto v107;
    v64 = stack[-2];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v64 = qcar(v64);
    fn = elt(env, 3); /* fkern */
    v66 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    v64 = stack[-2];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v65 = qcdr(v64);
    v64 = stack[-1];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v64 = qcdr(v64);
    v64 = (Lisp_Object)(int32_t)((int32_t)v65 - (int32_t)v64 + TAG_FIXNUM);
    fn = elt(env, 4); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v66, v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    v64 = stack[-2];
    v64 = qcar(v64);
    v65 = qcdr(v64);
    v64 = stack[-1];
    v64 = qcar(v64);
    v64 = qcdr(v64);
    fn = elt(env, 5); /* quotient!-mod!-p */
    v64 = (*qfn2(fn))(qenv(fn), v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    v64 = cons(stack[-3], v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    stack[-3] = v64;
    v64 = stack[-2];
    stack[-2] = qcdr(v64);
    v64 = stack[-3];
    fn = elt(env, 6); /* negate!-term */
    v65 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    v64 = stack[-1];
    v64 = qcdr(v64);
    fn = elt(env, 7); /* times!-term!-mod!-p */
    v64 = (*qfn2(fn))(qenv(fn), v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    fn = elt(env, 8); /* plus!-mod!-p */
    v64 = (*qfn2(fn))(qenv(fn), stack[-2], v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    stack[-2] = v64;
    v66 = stack[-2];
    v65 = stack[-1];
    v64 = stack[0];
    v64 = CC_xquotientKmodKp(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    {
        Lisp_Object v26 = stack[-3];
        popv(5);
        return cons(v26, v64);
    }

v107:
    v64 = stack[-2];
    v64 = qcar(v64);
    v65 = qcdr(v64);
    v64 = stack[-1];
    v64 = qcar(v64);
    v64 = qcdr(v64);
    fn = elt(env, 5); /* quotient!-mod!-p */
    v64 = (*qfn2(fn))(qenv(fn), v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    stack[0] = v64;
    v65 = stack[0];
    v64 = stack[-1];
    fn = elt(env, 9); /* times!-mod!-p */
    v64 = (*qfn2(fn))(qenv(fn), v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    fn = elt(env, 10); /* difference!-mod!-p */
    v64 = (*qfn2(fn))(qenv(fn), stack[-2], v64);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-4];
    if (v64 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v64 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v64; /* exact!-quotient!-flag */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v86:
    v64 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v64; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v64); }

v2:
    v64 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v64); }
/* error exit handlers */
v25:
    popv(5);
    return nil;
}



/* Code for formboollis */

static Lisp_Object MS_CDECL CC_formboollis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v101, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "formboollis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formboollis");
#endif
    if (stack >= stacklimit)
    {
        push4(v16,v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v102,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v16;
    stack[-1] = v102;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v11;

v11:
    v115 = stack[-3];
    if (v115 == nil) goto v98;
    v115 = stack[0];
    if (v115 == nil) goto v94;
    v115 = stack[-3];
    v107 = qcar(v115);
    v101 = stack[-2];
    v115 = stack[-1];
    fn = elt(env, 1); /* formbool */
    v101 = (*qfnn(fn))(qenv(fn), 3, v107, v101, v115);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v115 = stack[-4];
    v115 = cons(v101, v115);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[-4] = v115;
    goto v86;

v86:
    v115 = stack[-3];
    v115 = qcdr(v115);
    stack[-3] = v115;
    goto v11;

v94:
    v115 = stack[-3];
    v107 = qcar(v115);
    v101 = stack[-2];
    v115 = stack[-1];
    fn = elt(env, 2); /* formc!* */
    v101 = (*qfnn(fn))(qenv(fn), 3, v107, v101, v115);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    v115 = stack[-4];
    v115 = cons(v101, v115);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-5];
    stack[-4] = v115;
    goto v86;

v98:
    v115 = stack[-4];
        popv(6);
        return Lnreverse(nil, v115);
/* error exit handlers */
v184:
    popv(6);
    return nil;
}



/* Code for squashsqrt */

static Lisp_Object CC_squashsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v6, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for squashsqrt");
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

v207:
    v42 = qvalue(elt(env, 1)); /* sqrtflag */
    if (v42 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v42 = stack[-1];
    if (!consp(v42)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcar(v42);
    if (!consp(v42)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcar(v42);
    v6 = qcar(v42);
    v42 = elt(env, 2); /* sqrt */
    if (!(v6 == v42)) goto v105;
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v6 = qcdr(v42);
    v42 = (Lisp_Object)17; /* 1 */
    v42 = (Lisp_Object)greaterp2(v6, v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v42 = v42 ? lisp_true : nil;
    env = stack[-3];
    if (v42 == nil) goto v105;
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[0] = CC_squashsqrt(env, v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v7 = qcar(v42);
    v42 = stack[-1];
    v42 = qcar(v42);
    v6 = qcdr(v42);
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcdr(v42);
    fn = elt(env, 4); /* !*multfsqrt */
    v42 = (*qfnn(fn))(qenv(fn), 3, v7, v6, v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    {
        Lisp_Object v66 = stack[0];
        popv(4);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v66, v42);
    }

v105:
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcar(v42);
    v6 = qcar(v42);
    v42 = elt(env, 3); /* expt */
    if (!(v6 == v42)) goto v49;
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcdr(v42);
    v42 = qcdr(v42);
    v42 = qcar(v42);
    fn = elt(env, 6); /* prefix!-rational!-numberp */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    if (v42 == nil) goto v49;
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v6 = qcdr(v42);
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcdr(v42);
    v42 = qcdr(v42);
    v42 = qcar(v42);
    v42 = qcdr(v42);
    v42 = qcdr(v42);
    v42 = qcar(v42);
    v42 = (Lisp_Object)geq2(v6, v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v42 = v42 ? lisp_true : nil;
    env = stack[-3];
    if (v42 == nil) goto v49;
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[0] = CC_squashsqrt(env, v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v7 = qcar(v42);
    v42 = stack[-1];
    v42 = qcar(v42);
    v6 = qcdr(v42);
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcar(v42);
    v42 = qcdr(v42);
    fn = elt(env, 7); /* !*multfexpt */
    v42 = (*qfnn(fn))(qenv(fn), 3, v7, v6, v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    {
        Lisp_Object v258 = stack[0];
        popv(4);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v258, v42);
    }

v49:
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = qcdr(v42);
    v42 = CC_squashsqrt(env, v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-3];
    v6 = v42;
    v42 = v6;
    if (v42 == nil) goto v41;
    v42 = stack[-1];
    v42 = qcar(v42);
    stack[-2] = qcar(v42);
    stack[0] = v6;
    v42 = stack[-1];
    v42 = qcdr(v42);
    v42 = CC_squashsqrt(env, v42);
    nil = C_nil;
    if (exception_pending()) goto v65;
    {
        Lisp_Object v219 = stack[-2];
        Lisp_Object v259 = stack[0];
        popv(4);
        return acons(v219, v259, v42);
    }

v41:
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[-1] = v42;
    goto v207;
/* error exit handlers */
v65:
    popv(4);
    return nil;
}



/* Code for crn!:minusp */

static Lisp_Object CC_crnTminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v78, v79;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crn:minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v79 = v0;
/* end of prologue */
    v27 = v79;
    v27 = qcdr(v27);
    v27 = qcdr(v27);
    v78 = qcar(v27);
    v27 = (Lisp_Object)1; /* 0 */
    if (v78 == v27) goto v50;
    v27 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v27);

v50:
    v27 = v79;
    v27 = qcdr(v27);
    v27 = qcar(v27);
    v27 = qcar(v27);
        return Lminusp(nil, v27);
}



/* Code for assgnpri */

static Lisp_Object MS_CDECL CC_assgnpri(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v148, v270;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assgnpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assgnpri");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v269 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v269; /* overflowed!* */
    qvalue(elt(env, 3)) = v269; /* testing!-width!* */
    v269 = stack[-2];
    if (!(v269 == nil)) goto v118;
    v269 = (Lisp_Object)1; /* 0 */
    stack[-2] = v269;
    goto v118;

v118:
    v269 = qvalue(elt(env, 4)); /* !*nero */
    if (v269 == nil) goto v28;
    v148 = stack[-2];
    v269 = (Lisp_Object)1; /* 0 */
    if (!(v148 == v269)) goto v28;
    v269 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v269); }

v28:
    v269 = qvalue(elt(env, 5)); /* !*tex */
    if (v269 == nil) goto v90;
    v270 = stack[-2];
    v148 = stack[-1];
    v269 = stack[0];
    {
        popv(5);
        fn = elt(env, 20); /* texpri */
        return (*qfnn(fn))(qenv(fn), 3, v270, v148, v269);
    }

v90:
    v269 = elt(env, 6); /* vecp */
    fn = elt(env, 21); /* getd */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    if (v269 == nil) goto v30;
    v269 = stack[-2];
    fn = elt(env, 6); /* vecp */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    if (v269 == nil) goto v30;
    v148 = stack[-2];
    v269 = elt(env, 7); /* mat */
    {
        popv(5);
        fn = elt(env, 22); /* vecpri */
        return (*qfn2(fn))(qenv(fn), v148, v269);
    }

v30:
    v269 = stack[-2];
    fn = elt(env, 23); /* getrtype */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v270 = v269;
    if (v269 == nil) goto v271;
    v148 = v270;
    v269 = elt(env, 8); /* sprifn */
    v269 = Lflagp(nil, v148, v269);
    env = stack[-4];
    if (v269 == nil) goto v271;
    v269 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (!(v269 == nil)) goto v271;
    v269 = stack[-1];
    if (v269 == nil) goto v56;
    v270 = elt(env, 12); /* setq */
    v269 = stack[-1];
    v148 = qcar(v269);
    v269 = stack[-2];
    v269 = list3(v270, v148, v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v148 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (v148 == nil) goto v51;
    v270 = qvalue(elt(env, 9)); /* outputhandler!* */
    v148 = elt(env, 13); /* maprin */
    v269 = Lapply2(nil, 3, v270, v148, v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    goto v60;

v60:
    v269 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v269); }

v51:
    v148 = qvalue(elt(env, 2)); /* overflowed!* */
    if (!(v148 == nil)) goto v60;
    v148 = v269;
    v269 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 24); /* maprint */
    v269 = (*qfn2(fn))(qenv(fn), v148, v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    goto v60;

v56:
    v148 = v270;
    v269 = elt(env, 10); /* tag */
    v148 = get(v148, v269);
    env = stack[-4];
    v269 = elt(env, 11); /* prifn */
    v148 = get(v148, v269);
    env = stack[-4];
    v269 = stack[-2];
    v269 = Lapply1(nil, v148, v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    goto v60;

v271:
    v148 = stack[0];
    v269 = elt(env, 14); /* (first only) */
    v269 = Lmemq(nil, v148, v269);
    if (v269 == nil) goto v174;
    v269 = qvalue(elt(env, 15)); /* t */
    fn = elt(env, 25); /* terpri!* */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    goto v174;

v174:
    v269 = stack[-1];
    fn = elt(env, 26); /* evalvars */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    stack[-1] = v269;
    v269 = qvalue(elt(env, 16)); /* !*fort */
    if (v269 == nil) goto v244;
    v270 = stack[-2];
    v148 = stack[-1];
    v269 = stack[0];
    fn = elt(env, 27); /* fvarpri */
    v269 = (*qfnn(fn))(qenv(fn), 3, v270, v148, v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v269 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v269); }

v244:
    v269 = stack[-1];
    if (v269 == nil) goto v159;
    stack[-3] = elt(env, 12); /* setq */
    v269 = stack[-2];
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v269 = Lnconc(nil, stack[-1], v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v269 = cons(stack[-3], v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    goto v219;

v219:
    v148 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (v148 == nil) goto v165;
    v270 = qvalue(elt(env, 9)); /* outputhandler!* */
    v148 = elt(env, 13); /* maprin */
    v269 = Lapply2(nil, 3, v270, v148, v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    goto v238;

v238:
    v269 = stack[0];
    if (v269 == nil) goto v272;
    v148 = stack[0];
    v269 = elt(env, 17); /* first */
    if (v148 == v269) goto v272;
    v269 = qvalue(elt(env, 18)); /* !*nat */
    if (!(v269 == nil)) goto v231;
    v269 = elt(env, 19); /* "$" */
    fn = elt(env, 28); /* prin2!* */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    goto v231;

v231:
    v269 = qvalue(elt(env, 18)); /* !*nat */
    v269 = (v269 == nil ? lisp_true : nil);
    fn = elt(env, 25); /* terpri!* */
    v269 = (*qfn1(fn))(qenv(fn), v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    v269 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v269); }

v272:
    v269 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v269); }

v165:
    v148 = qvalue(elt(env, 2)); /* overflowed!* */
    if (!(v148 == nil)) goto v238;
    v148 = v269;
    v269 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 24); /* maprint */
    v269 = (*qfn2(fn))(qenv(fn), v148, v269);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-4];
    goto v238;

v159:
    v269 = stack[-2];
    goto v219;
/* error exit handlers */
v151:
    popv(5);
    return nil;
}



/* Code for delyzz */

static Lisp_Object CC_delyzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delyzz");
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
    v96 = nil;
    goto v98;

v98:
    v88 = stack[-1];
    v87 = stack[0];
    v87 = qcar(v87);
    v87 = qcar(v87);
    if (equal(v88, v87)) goto v57;
    v87 = stack[0];
    v87 = qcar(v87);
    v88 = v96;
    v87 = cons(v87, v88);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v96 = v87;
    v87 = stack[0];
    v87 = qcdr(v87);
    stack[0] = v87;
    goto v98;

v57:
    v88 = v96;
    v87 = stack[0];
    v87 = qcdr(v87);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v88, v87);
    }
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for tp1 */

static Lisp_Object CC_tp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tp1");
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
    v184 = qvalue(elt(env, 1)); /* nil */
    v184 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    stack[-3] = v184;
    stack[-5] = v184;
    goto v77;

v77:
    v184 = stack[-4];
    v184 = qcar(v184);
    if (v184 == nil) goto v76;
    v184 = stack[-4];
    stack[-2] = v184;
    v184 = qvalue(elt(env, 1)); /* nil */
    v184 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    stack[0] = v184;
    stack[-1] = v184;
    goto v79;

v79:
    v184 = stack[-2];
    if (v184 == nil) goto v84;
    v184 = stack[-2];
    v184 = qcar(v184);
    v184 = qcar(v184);
    v184 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v184 = Lrplacd(nil, stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v184 = qcdr(v184);
    stack[0] = v184;
    v33 = stack[-2];
    v184 = stack[-2];
    v184 = qcar(v184);
    v184 = qcdr(v184);
    v184 = Lrplaca(nil, v33, v184);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v184 = qcdr(v184);
    stack[-2] = v184;
    goto v79;

v84:
    stack[0] = stack[-3];
    v184 = stack[-1];
    v184 = qcdr(v184);
    v184 = ncons(v184);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v184 = Lrplacd(nil, stack[0], v184);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-6];
    v184 = qcdr(v184);
    stack[-3] = v184;
    goto v77;

v76:
    v184 = stack[-5];
    v184 = qcdr(v184);
    { popv(7); return onevalue(v184); }
/* error exit handlers */
v99:
    popv(7);
    return nil;
}



/* Code for wedgef */

static Lisp_Object CC_wedgef(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v272, v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgef");
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
    v231 = stack[-1];
    fn = elt(env, 7); /* dim!<deg */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    if (v231 == nil) goto v76;
    v231 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v231); }

v76:
    v231 = stack[-1];
    v272 = qcar(v231);
    v231 = elt(env, 2); /* hodge */
    if (!consp(v272)) goto v190;
    v272 = qcar(v272);
    if (!(v272 == v231)) goto v190;
    v231 = stack[-1];
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v231 = qcar(v231);
    fn = elt(env, 8); /* deg!*form */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[-2] = v231;
    stack[0] = stack[-2];
    v231 = stack[-1];
    v231 = qcdr(v231);
    fn = elt(env, 9); /* deg!*farg */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    if (equal(stack[0], v231)) goto v85;
    v231 = stack[-1];
    {
        popv(4);
        fn = elt(env, 10); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v231);
    }

v85:
    v231 = stack[-1];
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v162 = qcar(v231);
    v272 = (Lisp_Object)17; /* 1 */
    v231 = (Lisp_Object)17; /* 1 */
    v231 = list2star(v162, v272, v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[0] = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v231 = stack[-1];
    v231 = qcdr(v231);
    v231 = qcdr(v231);
    if (v231 == nil) goto v112;
    v231 = stack[-1];
    v231 = qcdr(v231);
    fn = elt(env, 11); /* mkuniquewedge1 */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    goto v184;

v184:
    fn = elt(env, 12); /* hodgepf */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 13); /* mkunarywedge */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 14); /* wedgepf2 */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[0] = stack[-2];
    v231 = qvalue(elt(env, 3)); /* dimex!* */
    fn = elt(env, 15); /* negf */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 16); /* addf */
    v231 = (*qfn2(fn))(qenv(fn), stack[-2], v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 17); /* multf */
    v231 = (*qfn2(fn))(qenv(fn), stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 18); /* mksgnsq */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    {
        Lisp_Object v278 = stack[-1];
        popv(4);
        fn = elt(env, 19); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v278, v231);
    }

v112:
    v231 = stack[-1];
    v231 = qcdr(v231);
    v162 = qcar(v231);
    v272 = (Lisp_Object)17; /* 1 */
    v231 = (Lisp_Object)17; /* 1 */
    v231 = list2star(v162, v272, v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    goto v184;

v190:
    v231 = stack[-1];
    v272 = qcar(v231);
    v231 = elt(env, 4); /* d */
    if (!consp(v272)) goto v160;
    v272 = qcar(v272);
    if (!(v272 == v231)) goto v160;
    v272 = elt(env, 4); /* d */
    v231 = elt(env, 5); /* noxpnd */
    v231 = Lflagp(nil, v272, v231);
    env = stack[-3];
    if (!(v231 == nil)) goto v225;
    v272 = qvalue(elt(env, 6)); /* lftshft!* */
    v231 = stack[-1];
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v231 = qcar(v231);
    fn = elt(env, 20); /* smemqlp */
    v231 = (*qfn2(fn))(qenv(fn), v272, v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    if (!(v231 == nil)) goto v225;

v160:
    v231 = stack[-1];
    {
        popv(4);
        fn = elt(env, 10); /* mkwedge */
        return (*qfn1(fn))(qenv(fn), v231);
    }

v225:
    v231 = stack[-1];
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v272 = qcar(v231);
    v231 = stack[-1];
    v231 = qcdr(v231);
    v231 = cons(v272, v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 21); /* dwedge */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 13); /* mkunarywedge */
    stack[-2] = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v231 = stack[-1];
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v162 = qcar(v231);
    v272 = (Lisp_Object)17; /* 1 */
    v231 = (Lisp_Object)17; /* 1 */
    v231 = list2star(v162, v272, v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[0] = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v231 = stack[-1];
    v231 = qcdr(v231);
    v231 = qcdr(v231);
    if (v231 == nil) goto v241;
    v231 = stack[-1];
    v231 = qcdr(v231);
    fn = elt(env, 21); /* dwedge */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    goto v237;

v237:
    fn = elt(env, 13); /* mkunarywedge */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 14); /* wedgepf2 */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v231 = stack[-1];
    v231 = qcar(v231);
    v231 = qcdr(v231);
    v231 = qcar(v231);
    fn = elt(env, 8); /* deg!*form */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 18); /* mksgnsq */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[-1] = v231;
    v231 = stack[-1];
    v231 = qcar(v231);
    fn = elt(env, 15); /* negf */
    v272 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v231 = stack[-1];
    v231 = qcdr(v231);
    v231 = cons(v272, v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    fn = elt(env, 19); /* multpfsq */
    v231 = (*qfn2(fn))(qenv(fn), stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    {
        Lisp_Object v279 = stack[-2];
        popv(4);
        fn = elt(env, 22); /* addpf */
        return (*qfn2(fn))(qenv(fn), v279, v231);
    }

v241:
    v231 = stack[-1];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    fn = elt(env, 23); /* exdfk */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    goto v237;
/* error exit handlers */
v161:
    popv(4);
    return nil;
}



/* Code for aceq */

static Lisp_Object CC_aceq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97, v95, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aceq");
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
    v97 = v1;
    v95 = v0;
/* end of prologue */

v2:
    v96 = v95;
    if (v96 == nil) goto v118;
    v96 = v97;
    if (v96 == nil) goto v81;
    v96 = v95;
    v94 = qcar(v96);
    v96 = v97;
    v96 = Lmember(nil, v94, v96);
    if (v96 == nil) goto v68;
    v96 = v95;
    v96 = qcdr(v96);
    stack[0] = v96;
    v96 = v95;
    v96 = qcar(v96);
    v96 = Ldelete(nil, v96, v97);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v97 = v96;
    v96 = stack[0];
    v95 = v96;
    goto v2;

v68:
    v96 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v96); }

v81:
    v96 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v96); }

v118:
    v96 = v97;
    v96 = (v96 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v96); }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for min0 */

static Lisp_Object CC_min0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for min0");
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
    v22 = v1;
    v43 = v0;
/* end of prologue */
    fn = elt(env, 1); /* min */
    v43 = (*qfn2(fn))(qenv(fn), v43, v22);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[0];
    v22 = (Lisp_Object)1; /* 0 */
    {
        popv(1);
        fn = elt(env, 2); /* max */
        return (*qfn2(fn))(qenv(fn), v43, v22);
    }
/* error exit handlers */
v44:
    popv(1);
    return nil;
}



/* Code for contr!-strand */

static Lisp_Object CC_contrKstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr-strand");
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
    v78 = v0;
/* end of prologue */

v17:
    v79 = stack[0];
    if (v79 == nil) { popv(2); return onevalue(v78); }
    v79 = v78;
    v78 = stack[0];
    v78 = qcar(v78);
    fn = elt(env, 1); /* contr1!-strand */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-1];
    v79 = stack[0];
    v79 = qcdr(v79);
    stack[0] = v79;
    goto v17;
/* error exit handlers */
v80:
    popv(2);
    return nil;
}



/* Code for mkfil!* */

static Lisp_Object CC_mkfilH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkfil*");
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
    v61 = stack[0];
    v61 = Lstringp(nil, v61);
    env = stack[-2];
    if (!(v61 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v61 = stack[0];
    if (symbolp(v61)) goto v23;
    v62 = stack[0];
    v61 = elt(env, 1); /* "file name" */
    {
        popv(3);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v62, v61);
    }

v23:
    v62 = stack[0];
    v61 = elt(env, 2); /* share */
    v61 = Lflagp(nil, v62, v61);
    env = stack[-2];
    if (v61 == nil) goto v88;
    v61 = stack[0];
    fn = elt(env, 6); /* eval */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    v62 = v61;
    v61 = Lstringp(nil, v61);
    env = stack[-2];
    if (!(v61 == nil)) { popv(3); return onevalue(v62); }

v88:
    stack[-1] = elt(env, 3); /* !" */
    v61 = stack[0];
    fn = elt(env, 7); /* explode2lc */
    v62 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    v61 = elt(env, 4); /* (!") */
    v61 = Lappend(nil, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    v61 = cons(stack[-1], v61);
    nil = C_nil;
    if (exception_pending()) goto v101;
        popv(3);
        return Lcompress(nil, v61);
/* error exit handlers */
v101:
    popv(3);
    return nil;
}



/* Code for !*!*a2i */

static Lisp_Object CC_HHa2i(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **a2i");
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
    v79 = v1;
    stack[0] = v0;
/* end of prologue */
    v23 = stack[0];
    fn = elt(env, 2); /* intexprnp */
    v79 = (*qfn2(fn))(qenv(fn), v23, v79);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    if (!(v79 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v23 = elt(env, 1); /* ieval */
    v79 = stack[0];
    popv(2);
    return list2(v23, v79);
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for red_tailred */

static Lisp_Object CC_red_tailred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v89, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_tailred");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v90 = v1;
    v209 = v0;
/* end of prologue */
    v89 = qvalue(elt(env, 1)); /* !*noetherian */
    if (v89 == nil) goto v27;
    v89 = v90;
    v90 = elt(env, 2); /* red_topred */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v209, v89, v90);
    }

v27:
    v89 = v90;
    v90 = elt(env, 3); /* red_topredbe */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v209, v89, v90);
    }
}



/* Code for evaluate!-in!-order!-mod!-p */

static Lisp_Object CC_evaluateKinKorderKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v116, v108, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-in-order-mod-p");
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

v17:
    v107 = stack[-1];
    if (!consp(v107)) goto v11;
    v107 = stack[-1];
    v107 = qcar(v107);
    if (!consp(v107)) goto v11;
    v107 = stack[-1];
    v107 = qcar(v107);
    v107 = qcar(v107);
    v116 = qcar(v107);
    v107 = stack[0];
    v107 = qcar(v107);
    v107 = qcar(v107);
    if (equal(v116, v107)) goto v87;
    v107 = stack[0];
    v107 = qcdr(v107);
    stack[0] = v107;
    goto v17;

v87:
    v107 = stack[-1];
    v107 = qcar(v107);
    v116 = qcdr(v107);
    v107 = stack[0];
    v107 = qcdr(v107);
    v117 = CC_evaluateKinKorderKmodKp(env, v116, v107);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-2];
    v107 = stack[-1];
    v107 = qcar(v107);
    v107 = qcar(v107);
    v108 = qcdr(v107);
    v107 = stack[-1];
    v116 = qcdr(v107);
    v107 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* horner!-rule!-in!-order!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 4, v117, v108, v116, v107);
    }

v11:
    v107 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v107);
    }
/* error exit handlers */
v184:
    popv(3);
    return nil;
}



/* Code for rl_nnf */

static Lisp_Object CC_rl_nnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_nnf");
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
    v98 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_nnf!* */
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    {
        Lisp_Object v81 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v81, v98);
    }
/* error exit handlers */
v77:
    popv(2);
    return nil;
}



setup_type const u27_setup[] =
{
    {"greatertype",             too_few_2,      CC_greatertype,wrong_no_2},
    {"dipsum",                  too_few_2,      CC_dipsum,     wrong_no_2},
    {"vevstrictlydivides?",     too_few_2,      CC_vevstrictlydividesW,wrong_no_2},
    {"evload",                  CC_evload,      too_many_1,    wrong_no_1},
    {"getphystypecar",          CC_getphystypecar,too_many_1,  wrong_no_1},
    {"no-side-effectp",         CC_noKsideKeffectp,too_many_1, wrong_no_1},
    {"mo_zero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mo_zero},
    {"list_is_all_free",        CC_list_is_all_free,too_many_1,wrong_no_1},
    {"reduce-eival-powers",     too_few_2,      CC_reduceKeivalKpowers,wrong_no_2},
    {"give*position",           too_few_2,      CC_giveHposition,wrong_no_2},
    {"pasf_subfof",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof},
    {"lambdaom",                CC_lambdaom,    too_many_1,    wrong_no_1},
    {"vdpilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpilcomb1},
    {"module",                  CC_module,      too_many_1,    wrong_no_1},
    {"list-evaluate",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_listKevaluate},
    {"ezgcdf1",                 too_few_2,      CC_ezgcdf1,    wrong_no_2},
    {"ratfunpri1",              CC_ratfunpri1,  too_many_1,    wrong_no_1},
    {"general-horner-rule-mod-p",wrong_no_na,   wrong_no_nb,   (n_args *)CC_generalKhornerKruleKmodKp},
    {"tayexp-minus",            CC_tayexpKminus,too_many_1,    wrong_no_1},
    {"get*inverse",             too_few_2,      CC_getHinverse,wrong_no_2},
    {"ctx_idl",                 CC_ctx_idl,     too_many_1,    wrong_no_1},
    {"ev_sum",                  too_few_2,      CC_ev_sum,     wrong_no_2},
    {"omfir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omfir},
    {"mkempspmat",              too_few_2,      CC_mkempspmat, wrong_no_2},
    {"specrd:times",            too_few_2,      CC_specrdTtimes,wrong_no_2},
    {"indexsymmetrize",         CC_indexsymmetrize,too_many_1, wrong_no_1},
    {"*xadd",                   too_few_2,      CC_Hxadd,      wrong_no_2},
    {"contract-strand",         too_few_2,      CC_contractKstrand,wrong_no_2},
    {"open",                    too_few_2,      CC_open,       wrong_no_2},
    {"innprodpex",              too_few_2,      CC_innprodpex, wrong_no_2},
    {"pasf_simplat1",           too_few_2,      CC_pasf_simplat1,wrong_no_2},
    {"vdp_plist",               CC_vdp_plist,   too_many_1,    wrong_no_1},
    {"lambdafun",               CC_lambdafun,   too_many_1,    wrong_no_1},
    {"simpunion",               CC_simpunion,   too_many_1,    wrong_no_1},
    {"formc*",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcH},
    {"*a2k",                    CC_Ha2k,        too_many_1,    wrong_no_1},
    {"fs:prin",                 CC_fsTprin,     too_many_1,    wrong_no_1},
    {"*f2di",                   too_few_2,      CC_Hf2di,      wrong_no_2},
    {"comb",                    too_few_2,      CC_comb,       wrong_no_2},
    {"xquotient-mod-p",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_xquotientKmodKp},
    {"formboollis",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_formboollis},
    {"squashsqrt",              CC_squashsqrt,  too_many_1,    wrong_no_1},
    {"crn:minusp",              CC_crnTminusp,  too_many_1,    wrong_no_1},
    {"assgnpri",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_assgnpri},
    {"delyzz",                  too_few_2,      CC_delyzz,     wrong_no_2},
    {"tp1",                     CC_tp1,         too_many_1,    wrong_no_1},
    {"wedgef",                  CC_wedgef,      too_many_1,    wrong_no_1},
    {"aceq",                    too_few_2,      CC_aceq,       wrong_no_2},
    {"min0",                    too_few_2,      CC_min0,       wrong_no_2},
    {"contr-strand",            too_few_2,      CC_contrKstrand,wrong_no_2},
    {"mkfil*",                  CC_mkfilH,      too_many_1,    wrong_no_1},
    {"**a2i",                   too_few_2,      CC_HHa2i,      wrong_no_2},
    {"red_tailred",             too_few_2,      CC_red_tailred,wrong_no_2},
    {"evaluate-in-order-mod-p", too_few_2,      CC_evaluateKinKorderKmodKp,wrong_no_2},
    {"rl_nnf",                  CC_rl_nnf,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u27", (two_args *)"18683 9037141 1874948", 0}
};

/* end of generated code */
