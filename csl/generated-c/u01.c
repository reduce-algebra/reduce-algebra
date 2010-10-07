
/* $destdir\u01.c        Machine generated C code */

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


/* Code for reval */

static Lisp_Object CC_reval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = v3;
    v3 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v4, v3);
    }
}



/* Code for num!-exponents */

static Lisp_Object CC_numKexponents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num-exponents");
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

v7:
    v6 = stack[0];
    v6 = (consp(v6) ? nil : lisp_true);
    if (!(v6 == nil)) goto v8;
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = (consp(v6) ? nil : lisp_true);
    goto v8;

v8:
    if (!(v6 == nil)) { popv(2); return onevalue(v6); }
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v6 = integerp(v6);
    if (v6 == nil) goto v9;
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v6 = CC_numKexponents(env, v6);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-1];
    if (v6 == nil) goto v11;
    v6 = stack[0];
    v6 = qcdr(v6);
    stack[0] = v6;
    goto v7;

v11:
    v6 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v6); }

v9:
    v6 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v6); }
/* error exit handlers */
v10:
    popv(2);
    return nil;
}



/* Code for !*ssave */

static Lisp_Object CC_Hssave(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *ssave");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v20 = v12;
    stack[-1] = v0;
/* end of prologue */
    v19 = qvalue(elt(env, 1)); /* !*uncached */
    if (!(v19 == nil)) goto v8;
    stack[-2] = qvalue(elt(env, 2)); /* alglist!* */
    stack[0] = v20;
    v20 = qvalue(elt(env, 3)); /* !*sub2 */
    v19 = stack[-1];
    v20 = cons(v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v19 = qvalue(elt(env, 2)); /* alglist!* */
    v19 = qcar(v19);
    v19 = acons(stack[0], v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v19 = Lrplaca(nil, stack[-2], v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    goto v8;

v8:
    v19 = qvalue(elt(env, 4)); /* simpcount!* */
    v19 = sub1(v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    qvalue(elt(env, 4)) = v19; /* simpcount!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for !*d2q */

static Lisp_Object CC_Hd2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *d2q");
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
    v30 = stack[0];
    if (is_number(v30)) goto v32;
    v30 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    if (v30 == nil) goto v34;
    v31 = qvalue(elt(env, 1)); /* nil */
    v30 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v31, v30);

v34:
    v31 = stack[0];
    v30 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v31, v30);

v32:
    v30 = stack[0];
    v30 = (Lisp_Object)zerop(v30);
    v30 = v30 ? lisp_true : nil;
    env = stack[-1];
    if (v30 == nil) goto v35;
    v31 = qvalue(elt(env, 1)); /* nil */
    v30 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v31, v30);

v35:
    v31 = stack[0];
    v30 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v31, v30);
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for getrtypeor */

static Lisp_Object CC_getrtypeor(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtypeor");
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

v7:
    v29 = stack[0];
    if (v29 == nil) goto v32;
    v29 = stack[0];
    v29 = qcar(v29);
    fn = elt(env, 2); /* getrtype */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    if (!(v29 == nil)) { popv(2); return onevalue(v29); }
    v29 = stack[0];
    v29 = qcdr(v29);
    stack[0] = v29;
    goto v7;

v32:
    v29 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v29); }
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for smember */

static Lisp_Object CC_smember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v39;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smember");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */

v40:
    v39 = stack[-1];
    v24 = stack[0];
    if (equal(v39, v24)) goto v5;
    v24 = stack[0];
    if (!consp(v24)) goto v9;
    v39 = stack[-1];
    v24 = stack[0];
    v24 = qcar(v24);
    v24 = CC_smember(env, v39, v24);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    if (!(v24 == nil)) { popv(3); return onevalue(v24); }
    v39 = stack[-1];
    v24 = stack[0];
    v24 = qcdr(v24);
    stack[-1] = v39;
    stack[0] = v24;
    goto v40;

v9:
    v24 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v24); }

v5:
    v24 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v24); }
/* error exit handlers */
v34:
    popv(3);
    return nil;
}



/* Code for quotf */

static Lisp_Object CC_quotf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v41, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v41 = v12;
    v9 = v0;
/* end of prologue */
    v38 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = v38; /* !*exp */
    v38 = v9;
    fn = elt(env, 3); /* quotf1 */
    v38 = (*qfn2(fn))(qenv(fn), v38, v41);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    { popv(2); return onevalue(v38); }
/* error exit handlers */
v14:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*exp */
    popv(2);
    return nil;
}



/* Code for quotelist */

static Lisp_Object CC_quotelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v42;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v42 = v0;
/* end of prologue */
    v42 = elt(env, 1); /* list */
    return onevalue(v42);
}



/* Code for wuconstantp */

static Lisp_Object CC_wuconstantp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wuconstantp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v16 = v15;
    v16 = (consp(v16) ? nil : lisp_true);
    if (!(v16 == nil)) goto v8;
    v16 = v15;
    v16 = qcar(v16);
    v16 = (consp(v16) ? nil : lisp_true);
    goto v8;

v8:
    if (!(v16 == nil)) return onevalue(v16);
    v16 = v15;
    v16 = qcar(v16);
    v16 = qcar(v16);
    v16 = qcar(v16);
    v15 = qvalue(elt(env, 1)); /* wuvarlist!* */
    v16 = Lmemq(nil, v16, v15);
    v16 = (v16 == nil ? lisp_true : nil);
    return onevalue(v16);
}



/* Code for mkcopy */

static Lisp_Object CC_mkcopy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkcopy");
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
    goto v5;

v5:
    v18 = stack[0];
    if (!consp(v18)) goto v37;
    v18 = stack[0];
    v18 = qcar(v18);
    v47 = CC_mkcopy(env, v18);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    v18 = stack[-1];
    v18 = cons(v47, v18);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    stack[-1] = v18;
    v18 = stack[0];
    v18 = qcdr(v18);
    stack[0] = v18;
    goto v5;

v37:
    v47 = stack[-1];
    v18 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v47, v18);
    }
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



/* Code for remove!-free!-vars!-l */

static Lisp_Object CC_removeKfreeKvarsKl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v33, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars-l");
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

v32:
    v51 = stack[0];
    if (!consp(v51)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v51 = stack[0];
    v33 = qcar(v51);
    v51 = elt(env, 1); /* !*sq */
    if (v33 == v51) goto v4;
    v51 = stack[0];
    v51 = qcar(v51);
    fn = elt(env, 2); /* remove!-free!-vars */
    stack[-1] = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v51 = stack[0];
    v51 = qcdr(v51);
    v51 = CC_removeKfreeKvarsKl(env, v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v51 = cons(stack[-1], v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v52 = v51;
    v33 = v52;
    v51 = stack[0];
    if (equal(v33, v51)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else { popv(3); return onevalue(v52); }

v4:
    v51 = stack[0];
    v51 = qcdr(v51);
    v51 = qcar(v51);
    fn = elt(env, 3); /* prepsq!* */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    stack[0] = v51;
    goto v32;
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for noncomp1 */

static Lisp_Object CC_noncomp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v54, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp1");
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
    v54 = v0;
/* end of prologue */
    v34 = v54;
    v34 = Lconsp(nil, v34);
    env = stack[0];
    if (v34 == nil) goto v32;
    v34 = v54;
    v34 = qcar(v34);
    v34 = Lconsp(nil, v34);
    env = stack[0];
    if (v34 == nil) goto v15;
    v34 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v34 == nil) goto v13;
    v34 = v54;
    {
        popv(1);
        fn = elt(env, 4); /* noncomfp1 */
        return (*qfn1(fn))(qenv(fn), v34);
    }

v13:
    v34 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v34); }

v15:
    v34 = v54;
    v55 = qcar(v34);
    v34 = elt(env, 3); /* taylor!* */
    if (v55 == v34) goto v35;
    v34 = v54;
    v34 = qcar(v34);
    if (!symbolp(v34)) v34 = nil;
    else { v34 = qfastgets(v34);
           if (v34 != nil) { v34 = elt(v34, 0); /* noncom */
#ifdef RECORD_GET
             if (v34 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v34 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v34 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v34 == SPID_NOPROP) v34 = nil; else v34 = lisp_true; }}
#endif
    if (!(v34 == nil)) { popv(1); return onevalue(v34); }
    v34 = v54;
    v34 = qcdr(v34);
    {
        popv(1);
        fn = elt(env, 5); /* noncomlistp */
        return (*qfn1(fn))(qenv(fn), v34);
    }

v35:
    v34 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v34); }

v32:
    v34 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v34); }
}



/* Code for pnth */

static Lisp_Object CC_pnth(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v25, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnth");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v25 = v12;
    stack[0] = v0;
/* end of prologue */

v5:
    v20 = stack[0];
    if (v20 == nil) goto v1;
    v24 = v25;
    v20 = (Lisp_Object)17; /* 1 */
    if (v24 == v20) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v20 = stack[0];
    v20 = qcdr(v20);
    stack[0] = v20;
    v20 = v25;
    v20 = sub1(v20);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    v25 = v20;
    goto v5;

v1:
    v20 = elt(env, 1); /* "Index out of range" */
    v25 = v20;
    v20 = v25;
    qvalue(elt(env, 2)) = v20; /* errmsg!* */
    v20 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v20 == nil)) goto v14;
    v20 = v25;
    fn = elt(env, 4); /* lprie */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    goto v14;

v14:
    v20 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v21;
    v20 = nil;
    { popv(2); return onevalue(v20); }
/* error exit handlers */
v21:
    popv(2);
    return nil;
}



/* Code for degr */

static Lisp_Object CC_degr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v17, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for degr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v56 = v12;
    v17 = v0;
/* end of prologue */
    v18 = v17;
    if (!consp(v18)) goto v5;
    v18 = v17;
    v18 = qcar(v18);
    if (!consp(v18)) goto v5;
    v18 = v17;
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = qcar(v18);
    if (!(v18 == v56)) goto v5;
    v56 = v17;
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = qcdr(v56);
    return onevalue(v56);

v5:
    v56 = (Lisp_Object)1; /* 0 */
    return onevalue(v56);
}



/* Code for qqe_rqopp */

static Lisp_Object CC_qqe_rqopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_rqopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = elt(env, 1); /* (qequal qneq) */
    v3 = Lmemq(nil, v3, v4);
    return onevalue(v3);
}



/* Code for ibalp_cec */

static Lisp_Object CC_ibalp_cec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_cec");
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

v32:
    v43 = stack[0];
    if (v43 == nil) goto v40;
    v43 = stack[0];
    v43 = qcar(v43);
    fn = elt(env, 2); /* ibalp_emptyclausep */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    if (v43 == nil) goto v46;
    v43 = stack[0];
    v43 = qcar(v43);
    { popv(2); return onevalue(v43); }

v46:
    v43 = stack[0];
    v43 = qcdr(v43);
    stack[0] = v43;
    goto v32;

v40:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for ctx_fromial */

static Lisp_Object CC_ctx_fromial(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_fromial");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = elt(env, 1); /* ctx */
    return list2(v4, v3);
}



/* Code for delall */

static Lisp_Object CC_delall(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v57;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delall");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */

v5:
    v21 = stack[0];
    if (v21 == nil) goto v1;
    v57 = stack[-1];
    v21 = stack[0];
    v21 = qcar(v21);
    if (equal(v57, v21)) goto v37;
    v21 = stack[0];
    v21 = qcar(v21);
    stack[-2] = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v57 = stack[-1];
    v21 = stack[0];
    v21 = qcdr(v21);
    v21 = CC_delall(env, v57, v21);
    nil = C_nil;
    if (exception_pending()) goto v49;
    {
        Lisp_Object v48 = stack[-2];
        popv(4);
        return Lappend(nil, v48, v21);
    }

v37:
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v5;

v1:
    v21 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v21); }
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for noncomfp1 */

static Lisp_Object CC_noncomfp1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomfp1");
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

v7:
    v58 = stack[0];
    if (!consp(v58)) goto v32;
    v58 = stack[0];
    v58 = qcar(v58);
    if (!consp(v58)) goto v32;
    v58 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v58 == nil) goto v29;
    v58 = stack[0];
    v58 = qcar(v58);
    v58 = qcar(v58);
    v58 = qcar(v58);
    fn = elt(env, 3); /* noncomp1 */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    goto v46;

v46:
    if (!(v58 == nil)) { popv(2); return onevalue(v58); }
    v58 = stack[0];
    v58 = qcar(v58);
    v58 = qcdr(v58);
    v58 = CC_noncomfp1(env, v58);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    if (!(v58 == nil)) { popv(2); return onevalue(v58); }
    v58 = stack[0];
    v58 = qcdr(v58);
    stack[0] = v58;
    goto v7;

v29:
    v58 = qvalue(elt(env, 1)); /* nil */
    goto v46;

v32:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v58); }
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for prepf */

static Lisp_Object CC_prepf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepf");
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
    v36 = v0;
/* end of prologue */
    v43 = v36;
    v36 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1 */
    v36 = (*qfn2(fn))(qenv(fn), v43, v36);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[0];
    v43 = v36;
    v36 = v43;
    if (v36 == nil) goto v38;
    v36 = v43;
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v36);
    }

v38:
    v36 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v36); }
/* error exit handlers */
v11:
    popv(1);
    return nil;
}



/* Code for ps!:getv */

static Lisp_Object CC_psTgetv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:getv");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    v61 = v0;
/* end of prologue */
    v60 = v61;
    v59 = elt(env, 1); /* !:ps!: */
    if (!consp(v60)) goto v57;
    v60 = qcar(v60);
    if (!(v60 == v59)) goto v57;
    v59 = v61;
    v59 = qcdr(v59);
    if (symbolp(v59)) goto v36;
    v59 = v61;
    v60 = qcdr(v59);
    v59 = stack[0];
    v59 = *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v59/(16/CELL)));
    { popv(2); return onevalue(v59); }

v36:
    v59 = v61;
    v59 = qcdr(v59);
    fn = elt(env, 5); /* eval */
    v60 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v59 = stack[0];
    v59 = *(Lisp_Object *)((char *)v60 + (CELL-TAG_VECTOR) + ((int32_t)v59/(16/CELL)));
    { popv(2); return onevalue(v59); }

v57:
    v59 = elt(env, 2); /* "PS:GETV: not a ps" */
    v60 = v61;
    v59 = list2(v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    v60 = v59;
    v59 = v60;
    qvalue(elt(env, 3)) = v59; /* errmsg!* */
    v59 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v59 == nil)) goto v52;
    v59 = v60;
    fn = elt(env, 6); /* lprie */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    goto v52;

v52:
    v59 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v59 = nil;
    { popv(2); return onevalue(v59); }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for csl_normbf */

static Lisp_Object CC_csl_normbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csl_normbf");
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
    v67 = stack[-2];
    v67 = qcdr(v67);
    v68 = qcar(v67);
    stack[0] = v68;
    v67 = (Lisp_Object)1; /* 0 */
    if (v68 == v67) goto v3;
    v68 = stack[0];
    v67 = (Lisp_Object)1; /* 0 */
    v67 = (Lisp_Object)lessp2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    v67 = v67 ? lisp_true : nil;
    env = stack[-4];
    if (v67 == nil) goto v11;
    v67 = stack[0];
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    stack[0] = v67;
    v67 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v67;
    goto v11;

v11:
    v67 = stack[0];
    fn = elt(env, 4); /* lsd */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    stack[-1] = v67;
    v67 = stack[-1];
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    v67 = ash(stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    stack[0] = v67;
    v67 = stack[-3];
    if (v67 == nil) goto v33;
    v67 = stack[0];
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    stack[0] = v67;
    goto v33;

v33:
    v68 = stack[-1];
    v67 = stack[-2];
    v67 = qcdr(v67);
    v67 = qcdr(v67);
    v67 = plus2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    stack[-1] = v67;
    v69 = elt(env, 3); /* !:rd!: */
    v68 = stack[0];
    v67 = stack[-1];
    popv(5);
    return list2star(v69, v68, v67);

v3:
    v67 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(5); return onevalue(v67); }
/* error exit handlers */
v70:
    popv(5);
    return nil;
}



/* Code for ldepends */

static Lisp_Object CC_ldepends(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */

v7:
    v39 = stack[-1];
    if (v39 == nil) goto v5;
    v39 = stack[-1];
    if (!consp(v39)) goto v38;
    v39 = stack[-1];
    v21 = qcar(v39);
    v39 = stack[0];
    fn = elt(env, 2); /* depends */
    v39 = (*qfn2(fn))(qenv(fn), v21, v39);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    if (!(v39 == nil)) { popv(3); return onevalue(v39); }
    v39 = stack[-1];
    v21 = qcdr(v39);
    v39 = stack[0];
    stack[-1] = v21;
    stack[0] = v39;
    goto v7;

v38:
    v21 = stack[-1];
    v39 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* depends */
        return (*qfn2(fn))(qenv(fn), v21, v39);
    }

v5:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v39); }
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for c!:ordxp */

static Lisp_Object CC_cTordxp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v21, v57;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordxp");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v39 = v12;
    v21 = v0;
/* end of prologue */
    v57 = v21;
    v57 = Lconsp(nil, v57);
    env = stack[0];
    if (v57 == nil) goto v8;
    v57 = v39;
    v57 = Lconsp(nil, v57);
    env = stack[0];
    if (v57 == nil) goto v16;
    v21 = qcdr(v21);
    v39 = qcdr(v39);
        popv(1);
        return Llessp(nil, v21, v39);

v16:
    v39 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v39); }

v8:
    v57 = v39;
    v57 = Lconsp(nil, v57);
    env = stack[0];
    if (v57 == nil) goto v19;
    v39 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v39); }

v19:
        popv(1);
        return Llessp(nil, v21, v39);
}



/* Code for zero2nil */

static Lisp_Object CC_zero2nil(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero2nil");
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
    v37 = stack[0];
    fn = elt(env, 2); /* !:zerop */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    if (v37 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v41:
    popv(2);
    return nil;
}



/* Code for ordop */

static Lisp_Object CC_ordop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v34, v54, v55, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v12;
    v49 = v0;
/* end of prologue */
    v57 = qvalue(elt(env, 1)); /* kord!* */
    v54 = v57;
    goto v8;

v8:
    v57 = v54;
    if (v57 == nil) goto v41;
    v34 = v49;
    v57 = v54;
    v57 = qcar(v57);
    if (v34 == v57) goto v36;
    v34 = v55;
    v57 = v54;
    v57 = qcar(v57);
    if (v34 == v57) goto v17;
    v57 = v54;
    v57 = qcdr(v57);
    v54 = v57;
    goto v8;

v17:
    v57 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v57);

v36:
    v57 = qvalue(elt(env, 2)); /* t */
    return onevalue(v57);

v41:
    v57 = v49;
    v34 = v55;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v57, v34);
    }
}



/* Code for binding */

static Lisp_Object CC_binding(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binding");
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
    v46 = v0;
/* end of prologue */
    v29 = v46;
    v46 = elt(env, 0); /* binding */
    v46 = get(v29, v46);
    v29 = v46;
    v46 = v29;
    if (v46 == nil) goto v41;
    v46 = v29;
    v46 = qcar(v46);
    return onevalue(v46);

v41:
    v46 = nil;
    return onevalue(v46);
}



/* Code for prepf1 */

static Lisp_Object CC_prepf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79, v80, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */
    v78 = stack[-1];
    if (v78 == nil) goto v5;
    v78 = stack[-1];
    if (!consp(v78)) goto v29;
    v78 = stack[-1];
    v78 = qcar(v78);
    if (!consp(v78)) goto v29;
    v78 = stack[-1];
    v78 = qcar(v78);
    stack[-2] = qcdr(v78);
    v78 = stack[-1];
    v78 = qcar(v78);
    v78 = qcar(v78);
    v79 = qcar(v78);
    v78 = elt(env, 2); /* k!* */
    if (v79 == v78) goto v82;
    v78 = stack[-1];
    v78 = qcar(v78);
    v79 = qcar(v78);
    v78 = stack[0];
    v78 = cons(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    goto v22;

v22:
    stack[-2] = CC_prepf1(env, stack[-2], v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    v78 = stack[-1];
    v79 = qcdr(v78);
    v78 = stack[0];
    v78 = CC_prepf1(env, v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    {
        Lisp_Object v84 = stack[-2];
        popv(4);
        return Lnconc(nil, v84, v78);
    }

v82:
    v78 = stack[0];
    goto v22;

v29:
    v78 = stack[-1];
    fn = elt(env, 3); /* prepd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    v81 = stack[0];
    v80 = qvalue(elt(env, 1)); /* nil */
    v79 = qvalue(elt(env, 1)); /* nil */
    v78 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* exchk1 */
    v78 = (*qfnn(fn))(qenv(fn), 4, v81, v80, v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    v78 = cons(stack[-1], v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    fn = elt(env, 5); /* retimes */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v83;
    popv(4);
    return ncons(v78);

v5:
    v78 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v78); }
/* error exit handlers */
v83:
    popv(4);
    return nil;
}



/* Code for evcomp */

static Lisp_Object CC_evcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v46 = v12;
    v29 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dipsortevcomp!* */
    v46 = list2(v29, v46);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    {
        Lisp_Object v43 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v43, v46);
    }
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for evmatrixcomp2 */

static Lisp_Object MS_CDECL CC_evmatrixcomp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v12,
                         Lisp_Object v45, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v73, v74, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmatrixcomp2");
#endif
    if (stack >= stacklimit)
    {
        push3(v45,v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v12,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v12;
    stack[-2] = v0;
/* end of prologue */

v7:
    v91 = stack[-2];
    if (v91 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v91 = stack[-1];
    if (v91 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v91 = stack[-1];
    v91 = qcar(v91);
    stack[-3] = v91;
    v73 = stack[-3];
    v91 = (Lisp_Object)1; /* 0 */
    v91 = Leqn(nil, v73, v91);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    if (v91 == nil) goto v34;
    v91 = stack[-2];
    v74 = qcdr(v91);
    v91 = stack[-1];
    v73 = qcdr(v91);
    v91 = stack[0];
    stack[-2] = v74;
    stack[-1] = v73;
    stack[0] = v91;
    goto v7;

v34:
    v73 = stack[-3];
    v91 = (Lisp_Object)17; /* 1 */
    v91 = Leqn(nil, v73, v91);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    if (v91 == nil) goto v68;
    v91 = stack[-2];
    v78 = qcdr(v91);
    v91 = stack[-1];
    v74 = qcdr(v91);
    v73 = stack[0];
    v91 = stack[-2];
    v91 = qcar(v91);
    v91 = (Lisp_Object)(int32_t)((int32_t)v73 + (int32_t)v91 - TAG_FIXNUM);
    stack[-2] = v78;
    stack[-1] = v74;
    stack[0] = v91;
    goto v7;

v68:
    v78 = stack[-2];
    v74 = stack[-3];
    v73 = stack[-1];
    v91 = stack[0];
    {
        popv(5);
        fn = elt(env, 1); /* evmatrixcomp3 */
        return (*qfnn(fn))(qenv(fn), 4, v78, v74, v73, v91);
    }
/* error exit handlers */
v92:
    popv(5);
    return nil;
}



/* Code for xval */

static Lisp_Object CC_xval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v8 = qcar(v8);
    v8 = qcar(v8);
    {
        fn = elt(env, 1); /* wedgefax */
        return (*qfn1(fn))(qenv(fn), v8);
    }
}



/* Code for add_prin_char */

static Lisp_Object CC_add_prin_char(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v76, v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_prin_char");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */
    v62 = qvalue(elt(env, 1)); /* !*nat */
    if (v62 == nil) goto v5;
    v77 = qvalue(elt(env, 3)); /* posn!* */
    v76 = stack[0];
    v62 = qvalue(elt(env, 4)); /* ycoord!* */
    v77 = acons(v77, v76, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v76 = stack[-1];
    v62 = qvalue(elt(env, 5)); /* pline!* */
    v62 = acons(v77, v76, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    qvalue(elt(env, 5)) = v62; /* pline!* */
    v62 = stack[0];
    qvalue(elt(env, 3)) = v62; /* posn!* */
    { popv(3); return onevalue(v62); }

v5:
    v62 = stack[-1];
    v62 = Lstringp(nil, v62);
    env = stack[-2];
    if (!(v62 == nil)) goto v3;
    v76 = stack[-1];
    v62 = elt(env, 2); /* switch!* */
    v62 = get(v76, v62);
    env = stack[-2];
    if (!(v62 == nil)) goto v3;
    v62 = stack[-1];
    v62 = Ldigitp(nil, v62);
    env = stack[-2];
    if (!(v62 == nil)) goto v3;
    v62 = stack[-1];
    v62 = Lexplodec(nil, v62);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v76 = qcar(v62);
    v62 = elt(env, 2); /* switch!* */
    v62 = get(v76, v62);
    if (!(v62 == nil)) goto v3;
    v62 = stack[-1];
        popv(3);
        return Lprin(nil, v62);

v3:
    v62 = stack[-1];
        popv(3);
        return Lprinc(nil, v62);
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for physopp */

static Lisp_Object CC_physopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopp");
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
    v94 = v0;
/* end of prologue */
    v52 = v94;
    if (!consp(v52)) goto v32;
    v52 = v94;
    v52 = qcar(v52);
    if (symbolp(v52)) goto v54;
    v52 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v52); }

v54:
    v52 = v94;
    v94 = qcar(v52);
    v52 = elt(env, 2); /* rtype */
    v52 = get(v94, v52);
    env = stack[0];
    v94 = elt(env, 3); /* physop */
    v52 = (v52 == v94 ? lisp_true : nil);
    { popv(1); return onevalue(v52); }

v32:
    v52 = v94;
    if (symbolp(v52)) goto v11;
    v52 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v52); }

v11:
    v52 = elt(env, 2); /* rtype */
    v52 = get(v94, v52);
    env = stack[0];
    v94 = elt(env, 3); /* physop */
    v52 = (v52 == v94 ? lisp_true : nil);
    { popv(1); return onevalue(v52); }
}



/* Code for memq_edgelist */

static Lisp_Object CC_memq_edgelist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for memq_edgelist");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v12;
    v38 = v0;
/* end of prologue */
    v38 = qcar(v38);
    v37 = Lassoc(nil, v38, v37);
    return onevalue(v37);
}



/* Code for readch1 */

static Lisp_Object MS_CDECL CC_readch1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v22;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "readch1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for readch1");
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
    v23 = qvalue(elt(env, 1)); /* !*int */
    if (v23 == nil) goto v8;
    v23 = qvalue(elt(env, 2)); /* ifl!* */
    if (!(v23 == nil)) goto v8;
    v23 = qvalue(elt(env, 6)); /* crbuf1!* */
    if (v23 == nil) goto v19;
    v23 = qvalue(elt(env, 6)); /* crbuf1!* */
    v23 = qcar(v23);
    stack[0] = v23;
    v23 = qvalue(elt(env, 6)); /* crbuf1!* */
    v23 = qcdr(v23);
    qvalue(elt(env, 6)) = v23; /* crbuf1!* */
    goto v39;

v39:
    v22 = stack[0];
    v23 = qvalue(elt(env, 7)); /* crbuf!* */
    v23 = cons(v22, v23);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    qvalue(elt(env, 7)) = v23; /* crbuf!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v19:
    v23 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    stack[0] = v23;
    goto v39;

v8:
    v23 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    stack[0] = v23;
    v22 = stack[0];
    v23 = qvalue(elt(env, 3)); /* !$eol!$ */
    if (!(v22 == v23)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v23 = qvalue(elt(env, 5)); /* curline!* */
    v23 = add1(v23);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    qvalue(elt(env, 5)) = v23; /* curline!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for termsf */

static Lisp_Object CC_termsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v39;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termsf");
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
    v24 = (Lisp_Object)1; /* 0 */
    v39 = v24;
    goto v1;

v1:
    v24 = stack[0];
    if (!consp(v24)) goto v40;
    v24 = stack[0];
    v24 = qcar(v24);
    if (!consp(v24)) goto v40;
    stack[-1] = v39;
    v24 = stack[0];
    v24 = qcar(v24);
    v24 = qcdr(v24);
    v24 = CC_termsf(env, v24);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    v24 = plus2(stack[-1], v24);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-2];
    v39 = v24;
    v24 = stack[0];
    v24 = qcdr(v24);
    stack[0] = v24;
    goto v1;

v40:
    v24 = stack[0];
    if (v24 == nil) { popv(3); return onevalue(v39); }
    v24 = v39;
    popv(3);
    return add1(v24);
/* error exit handlers */
v34:
    popv(3);
    return nil;
}



/* Code for mkspm */

static Lisp_Object CC_mkspm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkspm");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */
    v52 = stack[0];
    v33 = (Lisp_Object)1; /* 0 */
    if (v52 == v33) goto v5;
    v33 = qvalue(elt(env, 1)); /* subfg!* */
    if (v33 == nil) goto v36;
    v52 = stack[-1];
    v33 = qvalue(elt(env, 2)); /* asymplis!* */
    v33 = Latsoc(nil, v52, v33);
    v52 = v33;
    if (v33 == nil) goto v36;
    v33 = v52;
    v52 = qcdr(v33);
    v33 = stack[0];
    v33 = (Lisp_Object)lesseq2(v52, v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v33 = v33 ? lisp_true : nil;
    env = stack[-2];
    if (v33 == nil) goto v36;
    v33 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v33); }

v36:
    v33 = stack[-1];
    fn = elt(env, 4); /* sub2chk */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v52 = stack[-1];
    v33 = stack[0];
    popv(3);
    return cons(v52, v33);

v5:
    v33 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v33); }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for mo_divides!? */

static Lisp_Object CC_mo_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v12;
    v41 = v0;
/* end of prologue */
    v41 = qcar(v41);
    v38 = qcar(v38);
    {
        fn = elt(env, 1); /* mo!=modiv1 */
        return (*qfn2(fn))(qenv(fn), v41, v38);
    }
}



/* Code for mtp */

static Lisp_Object CC_mtp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */

v7:
    v19 = v20;
    v19 = (v19 == nil ? lisp_true : nil);
    if (!(v19 == nil)) return onevalue(v19);
    v19 = v20;
    v25 = qcar(v19);
    v19 = qvalue(elt(env, 1)); /* frlis!* */
    v19 = Lmemq(nil, v25, v19);
    if (v19 == nil) goto v2;
    v19 = v20;
    v25 = qcar(v19);
    v19 = v20;
    v19 = qcdr(v19);
    v19 = Lmember(nil, v25, v19);
    if (v19 == nil) goto v47;
    v19 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v19);

v47:
    v19 = v20;
    v19 = qcdr(v19);
    v20 = v19;
    goto v7;

v2:
    v19 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v19);
}



/* Code for c_zero */

static Lisp_Object MS_CDECL CC_c_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v45;
    argcheck(nargs, 0, "c_zero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c_zero");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v45 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v45);
}



/* Code for sieve_pv0 */

static Lisp_Object MS_CDECL CC_sieve_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v12,
                         Lisp_Object v45, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v95, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sieve_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sieve_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v45,v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v12,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v12;
    stack[-2] = v0;
/* end of prologue */
    v61 = stack[-2];
    if (!(v61 == nil)) goto v41;
    v61 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v61); }

v41:
    v61 = stack[-1];
    if (v61 == nil) goto v20;
    v61 = stack[-1];
    v61 = qcar(v61);
    v61 = qcar(v61);
    v95 = qcdr(v61);
    v61 = stack[-2];
    v61 = qcar(v61);
    v61 = qcdr(v61);
    v61 = (Lisp_Object)greaterp2(v95, v61);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v61 = v61 ? lisp_true : nil;
    env = stack[-3];
    if (v61 == nil) goto v20;
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    goto v41;

v20:
    v61 = stack[-2];
    if (v61 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v61 = stack[-1];
    if (v61 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v62 = stack[-2];
    v61 = stack[-1];
    v95 = qcar(v61);
    v61 = stack[0];
    fn = elt(env, 2); /* reduce_pv0 */
    v61 = (*qfnn(fn))(qenv(fn), 3, v62, v95, v61);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    stack[-2] = v61;
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    goto v20;
/* error exit handlers */
v90:
    popv(4);
    return nil;
}



/* Code for listp */

static Lisp_Object CC_listp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v0;
/* end of prologue */

v7:
    v29 = v46;
    v29 = (v29 == nil ? lisp_true : nil);
    if (!(v29 == nil)) return onevalue(v29);
    v29 = v46;
    if (!consp(v29)) goto v2;
    v46 = qcdr(v46);
    goto v7;

v2:
    v46 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v46);
}



/* Code for adjoin!-term */

static Lisp_Object MS_CDECL CC_adjoinKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v12,
                         Lisp_Object v45, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v35, v16, v15;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adjoin-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adjoin-term");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v45;
    v35 = v12;
    v16 = v0;
/* end of prologue */
    v15 = v35;
    if (v15 == nil) return onevalue(v11);
    return acons(v16, v35, v11);
}



/* Code for modzerop!: */

static Lisp_Object CC_modzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v37 = qcdr(v4);
    v4 = (Lisp_Object)1; /* 0 */
    v4 = (v37 == v4 ? lisp_true : nil);
    return onevalue(v4);
}



/* Code for ordpp */

static Lisp_Object CC_ordpp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v64, v63, v65, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordpp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v63 = v12;
    v65 = v0;
/* end of prologue */
    v90 = v65;
    v64 = qcar(v90);
    v90 = v63;
    v90 = qcar(v90);
    if (v64 == v90) goto v36;
    v90 = qvalue(elt(env, 1)); /* kord!* */
    v67 = v90;
    v90 = v65;
    v90 = qcar(v90);
    v65 = v90;
    v90 = v63;
    v90 = qcar(v90);
    v63 = v90;
    goto v8;

v8:
    v90 = v67;
    if (v90 == nil) goto v25;
    v64 = v65;
    v90 = v67;
    v90 = qcar(v90);
    if (v64 == v90) goto v55;
    v64 = v63;
    v90 = v67;
    v90 = qcar(v90);
    if (v64 == v90) goto v82;
    v90 = v67;
    v90 = qcdr(v90);
    v67 = v90;
    goto v8;

v82:
    v90 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v90);

v55:
    v90 = qvalue(elt(env, 2)); /* t */
    return onevalue(v90);

v25:
    v90 = v65;
    v64 = v63;
    {
        fn = elt(env, 4); /* ordpa */
        return (*qfn2(fn))(qenv(fn), v90, v64);
    }

v36:
    v90 = v65;
    v90 = qcdr(v90);
    v64 = v63;
    v64 = qcdr(v64);
        return Lgreaterp(nil, v90, v64);
}



/* Code for minusf */

static Lisp_Object CC_minusf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v51, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusf");
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
    v51 = v0;
/* end of prologue */

v32:
    v31 = v51;
    if (v31 == nil) goto v40;
    v31 = v51;
    if (!consp(v31)) goto v4;
    v31 = v51;
    v31 = qcar(v31);
    if (!consp(v31)) goto v4;
    v31 = v51;
    v31 = qcar(v31);
    v31 = qcdr(v31);
    v51 = v31;
    goto v32;

v4:
    v31 = v51;
    if (!consp(v31)) goto v15;
    v31 = v51;
    v33 = qcar(v31);
    v31 = elt(env, 2); /* minusp */
    v31 = get(v33, v31);
        return Lapply1(nil, v31, v51);

v15:
    v31 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v51, v31);

v40:
    v31 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v31);
}



/* Code for reorder */

static Lisp_Object CC_reorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reorder");
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
    goto v8;

v8:
    v94 = stack[-1];
    if (!consp(v94)) goto v40;
    v94 = stack[-1];
    v94 = qcar(v94);
    if (!consp(v94)) goto v40;
    v94 = stack[-1];
    v94 = qcar(v94);
    stack[0] = qcar(v94);
    v94 = stack[-1];
    v94 = qcar(v94);
    v94 = qcdr(v94);
    v94 = CC_reorder(env, v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    fn = elt(env, 1); /* rmultpf */
    v82 = (*qfn2(fn))(qenv(fn), stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    v94 = stack[-2];
    v94 = cons(v82, v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    stack[-2] = v94;
    v94 = stack[-1];
    v94 = qcdr(v94);
    stack[-1] = v94;
    goto v8;

v40:
    v94 = stack[-1];
    v82 = v94;
    goto v1;

v1:
    v94 = stack[-2];
    if (v94 == nil) { popv(4); return onevalue(v82); }
    v94 = stack[-2];
    v94 = qcar(v94);
    fn = elt(env, 2); /* raddf */
    v94 = (*qfn2(fn))(qenv(fn), v94, v82);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    v82 = v94;
    v94 = stack[-2];
    v94 = qcdr(v94);
    stack[-2] = v94;
    goto v1;
/* error exit handlers */
v93:
    popv(4);
    return nil;
}



/* Code for nocp */

static Lisp_Object CC_nocp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nocp");
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

v7:
    v35 = stack[0];
    v35 = (v35 == nil ? lisp_true : nil);
    if (!(v35 == nil)) { popv(2); return onevalue(v35); }
    v35 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v35 == nil) goto v2;
    v35 = stack[0];
    v35 = qcar(v35);
    v35 = qcar(v35);
    fn = elt(env, 3); /* noncomp1 */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    if (v35 == nil) goto v2;
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v7;

v2:
    v35 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v35); }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for get!+mat!+entry */

static Lisp_Object MS_CDECL CC_getLmatLentry(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v12,
                         Lisp_Object v45, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "get+mat+entry");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+mat+entry");
#endif
    if (stack >= stacklimit)
    {
        push3(v45,v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v12,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    v11 = v12;
    v35 = v0;
/* end of prologue */
    fn = elt(env, 1); /* pnth */
    v11 = (*qfn2(fn))(qenv(fn), v35, v11);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    v35 = qcar(v11);
    v11 = stack[0];
    fn = elt(env, 1); /* pnth */
    v11 = (*qfn2(fn))(qenv(fn), v35, v11);
    nil = C_nil;
    if (exception_pending()) goto v15;
    v11 = qcar(v11);
    { popv(2); return onevalue(v11); }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for kernlp */

static Lisp_Object CC_kernlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v0;
/* end of prologue */

v32:
    v15 = v16;
    if (!consp(v15)) return onevalue(v16);
    v15 = v16;
    v15 = qcar(v15);
    if (!consp(v15)) return onevalue(v16);
    v15 = v16;
    v15 = qcdr(v15);
    if (v15 == nil) goto v9;
    v16 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v16);

v9:
    v16 = qcar(v16);
    v16 = qcdr(v16);
    goto v32;
}



/* Code for multd */

static Lisp_Object CC_multd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multd");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v12;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v8;

v8:
    v96 = stack[-1];
    if (v96 == nil) goto v2;
    v97 = stack[-1];
    v96 = (Lisp_Object)17; /* 1 */
    if (v97 == v96) goto v35;
    v96 = stack[-1];
    if (!consp(v96)) goto v19;
    v96 = stack[-1];
    v96 = qcar(v96);
    if (!consp(v96)) goto v19;
    v96 = stack[-1];
    v96 = qcar(v96);
    stack[0] = qcar(v96);
    v97 = stack[-2];
    v96 = stack[-1];
    v96 = qcar(v96);
    v96 = qcdr(v96);
    v97 = CC_multd(env, v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v96 = stack[-3];
    v96 = acons(stack[0], v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    stack[-3] = v96;
    v96 = stack[-1];
    v96 = qcdr(v96);
    stack[-1] = v96;
    goto v8;

v19:
    stack[0] = stack[-3];
    v97 = stack[-2];
    v96 = stack[-1];
    fn = elt(env, 1); /* multdm */
    v96 = (*qfn2(fn))(qenv(fn), v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    {
        Lisp_Object v85 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v85, v96);
    }

v35:
    v97 = stack[-3];
    v96 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v97, v96);
    }

v2:
    v96 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v96);
    }
/* error exit handlers */
v98:
    popv(5);
    return nil;
}



/* Code for qqe_qoptailp */

static Lisp_Object CC_qqe_qoptailp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qoptailp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v0;
/* end of prologue */
    v13 = v9;
    v9 = elt(env, 1); /* (rtail ltail) */
    v9 = Lmemq(nil, v13, v9);
    if (v9 == nil) goto v5;
    v9 = qvalue(elt(env, 2)); /* t */
    return onevalue(v9);

v5:
    v9 = nil;
    return onevalue(v9);
}



/* Code for sort */

static Lisp_Object CC_sort(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sort");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    v46 = v0;
/* end of prologue */
    v29 = v46;
    v46 = qvalue(elt(env, 1)); /* nil */
    v29 = Lappend(nil, v29, v46);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    v46 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* stable!-sortip */
        return (*qfn2(fn))(qenv(fn), v29, v46);
    }
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for ibalp_clmember */

static Lisp_Object CC_ibalp_clmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_clmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */

v7:
    v17 = stack[0];
    if (v17 == nil) goto v5;
    v18 = stack[-1];
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 2); /* ibalp_cequal */
    v17 = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    if (!(v17 == nil)) { popv(3); return onevalue(v17); }
    v18 = stack[-1];
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[-1] = v18;
    stack[0] = v17;
    goto v7;

v5:
    v17 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v17); }
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for aex_mk */

static Lisp_Object MS_CDECL CC_aex_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v12,
                         Lisp_Object v45, Lisp_Object v42, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v44, v71, v27;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "aex_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mk");
#endif
    if (stack >= stacklimit)
    {
        push4(v42,v45,v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v12,v45,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v15 = v42;
    v44 = v45;
    v71 = v12;
    v27 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v27;
    stack[0] = v71;
    v15 = list2(v44, v15);
    nil = C_nil;
    if (exception_pending()) goto v18;
    {
        Lisp_Object v47 = stack[-2];
        Lisp_Object v6 = stack[-1];
        Lisp_Object v50 = stack[0];
        popv(3);
        return list3star(v47, v6, v50, v15);
    }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for find2 */

static Lisp_Object CC_find2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v34, v54, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v12;
    v54 = v0;
/* end of prologue */

v2:
    v55 = v34;
    v57 = nil;
    if (v55 == v57) goto v40;
    v57 = v34;
    v57 = qcar(v57);
    v54 = Lmember(nil, v57, v54);
    v57 = v34;
    v57 = qcdr(v57);
    v34 = v57;
    goto v2;

v40:
    v57 = v54;
    if (v57 == nil) goto v11;
    v57 = v54;
    v57 = qcdr(v57);
    return onevalue(v57);

v11:
    v57 = elt(env, 1); /* (stop) */
    return onevalue(v57);
}



/* Code for butes */

static Lisp_Object CC_butes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v39, v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for butes");
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
    push(nil);
/* copy arguments values to proper place */
    v21 = v0;
/* end of prologue */
    v24 = v21;
    v24 = qcar(v24);
    qvalue(elt(env, 1)) = v24; /* cha */
    v39 = qvalue(elt(env, 1)); /* cha */
    v24 = elt(env, 2); /* !  */
    if (v39 == v24) goto v2;
    v39 = qvalue(elt(env, 1)); /* cha */
    v24 = elt(env, 3); /* !$ */
    if (v39 == v24) goto v2;
    v24 = v21;
    stack[0] = qcar(v24);
    v24 = v21;
    v24 = qcdr(v24);
    v24 = CC_butes(env, v24);
    nil = C_nil;
    if (exception_pending()) goto v34;
    {
        Lisp_Object v54 = stack[0];
        popv(1);
        return cons(v54, v24);
    }

v2:
    v24 = qvalue(elt(env, 4)); /* nil */
    { popv(1); return onevalue(v24); }
/* error exit handlers */
v34:
    popv(1);
    return nil;
}



/* Code for nil2zero */

static Lisp_Object CC_nil2zero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nil2zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v37 = v4;
    if (!(v37 == nil)) return onevalue(v4);
    v4 = (Lisp_Object)1; /* 0 */
    return onevalue(v4);
}



/* Code for pm!:free */

static Lisp_Object CC_pmTfree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:free");
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
    v4 = v0;
/* end of prologue */
    fn = elt(env, 2); /* binding */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    v37 = elt(env, 1); /* unbound */
    v4 = (v4 == v37 ? lisp_true : nil);
    { popv(1); return onevalue(v4); }
/* error exit handlers */
v38:
    popv(1);
    return nil;
}



/* Code for vevmtest!? */

static Lisp_Object CC_vevmtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v89, v93, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevmtest?");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v89 = v12;
    v93 = v0;
/* end of prologue */

v5:
    v66 = v89;
    if (v66 == nil) goto v1;
    v66 = v93;
    if (v66 == nil) goto v37;
    v66 = v93;
    v59 = qcar(v66);
    v66 = v89;
    v66 = qcar(v66);
    if (((int32_t)(v59)) < ((int32_t)(v66))) goto v94;
    v66 = v93;
    v66 = qcdr(v66);
    v93 = v66;
    v66 = v89;
    v66 = qcdr(v66);
    v89 = v66;
    goto v5;

v94:
    v66 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v66); }

v37:
    v66 = v89;
    if (v66 == nil) goto v14;
    v66 = v89;
    v93 = qcar(v66);
    v66 = (Lisp_Object)1; /* 0 */
    if (!(v93 == v66)) goto v50;
    v66 = v89;
    v66 = qcdr(v66);
    fn = elt(env, 3); /* vevzero!?1 */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[0];
    if (!(v66 == nil)) goto v14;

v50:
    v66 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v66); }

v14:
    v66 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v66); }

v1:
    v66 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v66); }
/* error exit handlers */
v60:
    popv(1);
    return nil;
}



/* Code for vbcsize */

static Lisp_Object CC_vbcsize(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v49, v48;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcsize");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v49 = v12;
    stack[0] = v0;
/* end of prologue */

v40:
    v48 = v49;
    v55 = (Lisp_Object)-15; /* -1 */
    if (((int32_t)(v48)) > ((int32_t)(v55))) goto v5;
    v55 = stack[0];
    if (!consp(v55)) { popv(2); return onevalue(v49); }
    v55 = stack[0];
    v55 = qcar(v55);
    v49 = (Lisp_Object)((int32_t)(v49) + 0x10);
    v55 = CC_vbcsize(env, v55, v49);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v49 = v55;
    v55 = v49;
    if (v55 == nil) goto v6;
    v55 = stack[0];
    v55 = qcdr(v55);
    stack[0] = v55;
    goto v40;

v6:
    v55 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v55); }

v5:
    v55 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v55); }
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for wedgefax */

static Lisp_Object CC_wedgefax(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v36, v43;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgefax");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v36 = v0;
/* end of prologue */
    v28 = v36;
    v43 = elt(env, 1); /* wedge */
    if (!consp(v28)) goto v13;
    v28 = qcar(v28);
    if (!(v28 == v43)) goto v13;
    v28 = v36;
    v28 = qcdr(v28);
    return onevalue(v28);

v13:
    v28 = v36;
    return ncons(v28);
}



/* Code for prin2la */

static Lisp_Object CC_prin2la(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2la");
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
    v33 = stack[0];
    fn = elt(env, 4); /* chundexp */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    stack[0] = v33;
    v33 = stack[0];
    v33 = Llength(nil, v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    stack[-1] = v33;
    v52 = qvalue(elt(env, 1)); /* ncharspr!* */
    v33 = stack[-1];
    v52 = plus2(v52, v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v33 = qvalue(elt(env, 2)); /* laline!* */
    v33 = (Lisp_Object)greaterp2(v52, v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v33 = v33 ? lisp_true : nil;
    env = stack[-2];
    if (v33 == nil) goto v3;
    v33 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v33 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v33; /* ncharspr!* */
    goto v3;

v3:
    v33 = stack[0];
    stack[0] = v33;
    goto v18;

v18:
    v33 = stack[0];
    if (v33 == nil) goto v49;
    v33 = stack[0];
    v33 = qcar(v33);
    v33 = Lprinc(nil, v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v18;

v49:
    v52 = qvalue(elt(env, 1)); /* ncharspr!* */
    v33 = stack[-1];
    v33 = plus2(v52, v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    qvalue(elt(env, 1)) = v33; /* ncharspr!* */
    v33 = nil;
    { popv(3); return onevalue(v33); }
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for scprint */

static Lisp_Object CC_scprint(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scprint");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v12;
    v62 = v0;
/* end of prologue */
    v95 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v95; /* posn!* */
    v95 = v62;
    stack[-1] = v95;
    goto v3;

v3:
    v95 = stack[-1];
    if (v95 == nil) goto v2;
    v95 = stack[-1];
    v95 = qcar(v95);
    stack[0] = v95;
    v95 = stack[0];
    v95 = qcar(v95);
    v62 = qcdr(v95);
    v95 = stack[-2];
    if (!(equal(v62, v95))) goto v43;
    v95 = stack[0];
    v95 = qcar(v95);
    v95 = qcar(v95);
    v62 = qcar(v95);
    v95 = qvalue(elt(env, 1)); /* posn!* */
    v62 = difference2(v62, v95);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    stack[-3] = v62;
    v95 = (Lisp_Object)1; /* 0 */
    v95 = (Lisp_Object)lessp2(v62, v95);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v95 = v95 ? lisp_true : nil;
    env = stack[-4];
    if (!(v95 == nil)) goto v6;
    v95 = stack[-3];
    v95 = Lxtab(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v6;

v6:
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = Lprinc(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v95 = stack[0];
    v95 = qcar(v95);
    v95 = qcar(v95);
    v95 = qcdr(v95);
    qvalue(elt(env, 1)) = v95; /* posn!* */
    goto v43;

v43:
    v95 = stack[-1];
    v95 = qcdr(v95);
    stack[-1] = v95;
    goto v3;

v2:
    v95 = nil;
    { popv(5); return onevalue(v95); }
/* error exit handlers */
v64:
    popv(5);
    return nil;
}



/* Code for int!-equiv!-chk */

static Lisp_Object CC_intKequivKchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for int-equiv-chk");
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
    v101 = qvalue(elt(env, 1)); /* !*noequiv */
    if (!(v101 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = stack[0];
    if (!consp(v101)) goto v43;
    v101 = stack[0];
    v102 = qcar(v101);
    v101 = elt(env, 3); /* zerop */
    v102 = get(v102, v101);
    env = stack[-1];
    v101 = stack[0];
    v101 = Lapply1(nil, v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    if (v101 == nil) goto v66;
    v101 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v101); }

v66:
    v101 = stack[0];
    v102 = qcar(v101);
    v101 = elt(env, 4); /* onep */
    v102 = get(v102, v101);
    env = stack[-1];
    v101 = stack[0];
    v101 = Lapply1(nil, v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    if (v101 == nil) goto v65;
    v101 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v101); }

v65:
    v101 = stack[0];
    v102 = qcar(v101);
    v101 = elt(env, 5); /* intequivfn */
    v101 = get(v102, v101);
    env = stack[-1];
    v103 = v101;
    if (v101 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v102 = v103;
    v101 = stack[0];
    v101 = Lapply1(nil, v102, v101);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-1];
    v103 = v101;
    if (v101 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v102 = v103;
    v101 = (Lisp_Object)1; /* 0 */
    if (!(v102 == v101)) { popv(2); return onevalue(v103); }
    v101 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v101); }

v43:
    v102 = stack[0];
    v101 = (Lisp_Object)1; /* 0 */
    if (!(v102 == v101)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v101 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v101); }
/* error exit handlers */
v104:
    popv(2);
    return nil;
}



/* Code for gcdfd1 */

static Lisp_Object CC_gcdfd1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdfd1");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    v25 = v0;
/* end of prologue */

v5:
    v24 = stack[0];
    if (v24 == nil) { popv(2); return onevalue(v25); }
    v24 = stack[0];
    if (!consp(v24)) goto v28;
    v24 = stack[0];
    v24 = qcar(v24);
    if (!consp(v24)) goto v28;
    v24 = v25;
    v25 = stack[0];
    v25 = qcar(v25);
    v25 = qcdr(v25);
    v25 = CC_gcdfd1(env, v24, v25);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-1];
    v24 = stack[0];
    v24 = qcdr(v24);
    stack[0] = v24;
    goto v5;

v28:
    v24 = v25;
    v25 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* gcddd */
        return (*qfn2(fn))(qenv(fn), v24, v25);
    }
/* error exit handlers */
v21:
    popv(2);
    return nil;
}



/* Code for noncomp2 */

static Lisp_Object CC_noncomp2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v0;
/* end of prologue */
    v29 = v28;
    if (!consp(v29)) goto v32;
    v29 = v28;
    v28 = elt(env, 1); /* noncom */
        return Lflagpcar(nil, v29, v28);

v32:
    v29 = v28;
    if (!symbolp(v29)) v29 = nil;
    else { v29 = qfastgets(v29);
           if (v29 != nil) { v29 = elt(v29, 0); /* noncom */
#ifdef RECORD_GET
             if (v29 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v29 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v29 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v29 == SPID_NOPROP) v29 = nil; else v29 = lisp_true; }}
#endif
    return onevalue(v29);
}



/* Code for union_edge */

static Lisp_Object CC_union_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for union_edge");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */
    v44 = stack[-1];
    v15 = stack[0];
    fn = elt(env, 1); /* memq_edgelist */
    v15 = (*qfn2(fn))(qenv(fn), v44, v15);
    nil = C_nil;
    if (exception_pending()) goto v26;
    if (!(v15 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v44 = stack[-1];
    v15 = stack[0];
    popv(2);
    return cons(v44, v15);
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for addf */

static Lisp_Object CC_addf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addf");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v12;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v8;

v8:
    v120 = stack[-2];
    if (v120 == nil) goto v38;
    v120 = stack[-1];
    if (v120 == nil) goto v35;
    v120 = stack[-2];
    if (!consp(v120)) goto v34;
    v120 = stack[-2];
    v120 = qcar(v120);
    if (!consp(v120)) goto v34;
    v120 = stack[-1];
    if (!consp(v120)) goto v62;
    v120 = stack[-1];
    v120 = qcar(v120);
    if (!consp(v120)) goto v62;
    v120 = stack[-2];
    v120 = qcar(v120);
    v121 = qcar(v120);
    v120 = stack[-1];
    v120 = qcar(v120);
    v120 = qcar(v120);
    if (equal(v121, v120)) goto v88;
    v120 = stack[-2];
    v120 = qcar(v120);
    v121 = qcar(v120);
    v120 = stack[-1];
    v120 = qcar(v120);
    v120 = qcar(v120);
    fn = elt(env, 1); /* ordpp */
    v120 = (*qfn2(fn))(qenv(fn), v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    if (v120 == nil) goto v124;
    v120 = stack[-2];
    v121 = qcar(v120);
    v120 = stack[0];
    v120 = cons(v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[0] = v120;
    v120 = stack[-2];
    v120 = qcdr(v120);
    stack[-2] = v120;
    goto v8;

v124:
    v120 = stack[-1];
    v121 = qcar(v120);
    v120 = stack[0];
    v120 = cons(v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[0] = v120;
    v120 = stack[-1];
    v120 = qcdr(v120);
    stack[-1] = v120;
    goto v8;

v88:
    stack[-3] = stack[0];
    v120 = stack[-2];
    v120 = qcar(v120);
    v121 = qcdr(v120);
    v120 = stack[-1];
    v120 = qcar(v120);
    v120 = qcdr(v120);
    stack[0] = CC_addf(env, v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v120 = stack[-2];
    v121 = qcdr(v120);
    v120 = stack[-1];
    v120 = qcdr(v120);
    v120 = CC_addf(env, v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v121 = stack[0];
    v122 = v121;
    if (v122 == nil) goto v74;
    v122 = stack[-2];
    v122 = qcar(v122);
    v122 = qcar(v122);
    v120 = acons(v122, v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    goto v74;

v74:
    {
        Lisp_Object v125 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v125, v120);
    }

v62:
    v121 = stack[-1];
    v120 = stack[-2];
    fn = elt(env, 3); /* addd */
    v120 = (*qfn2(fn))(qenv(fn), v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    {
        Lisp_Object v126 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v126, v120);
    }

v34:
    v121 = stack[-2];
    v120 = stack[-1];
    fn = elt(env, 3); /* addd */
    v120 = (*qfn2(fn))(qenv(fn), v121, v120);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    {
        Lisp_Object v127 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v127, v120);
    }

v35:
    v121 = stack[0];
    v120 = stack[-2];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v121, v120);
    }

v38:
    v121 = stack[0];
    v120 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v121, v120);
    }
/* error exit handlers */
v123:
    popv(5);
    return nil;
}



/* Code for formlis */

static Lisp_Object MS_CDECL CC_formlis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v12,
                         Lisp_Object v45, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v10, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formlis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formlis");
#endif
    if (stack >= stacklimit)
    {
        push3(v45,v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v12,v45);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v45;
    stack[-1] = v12;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v40;

v40:
    v50 = stack[-2];
    if (v50 == nil) goto v3;
    v50 = stack[-2];
    v58 = qcar(v50);
    v10 = stack[-1];
    v50 = stack[0];
    fn = elt(env, 1); /* form1 */
    v10 = (*qfnn(fn))(qenv(fn), 3, v58, v10, v50);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v50 = stack[-3];
    v50 = cons(v10, v50);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    stack[-3] = v50;
    v50 = stack[-2];
    v50 = qcdr(v50);
    stack[-2] = v50;
    goto v40;

v3:
    v50 = stack[-3];
        popv(5);
        return Lnreverse(nil, v50);
/* error exit handlers */
v39:
    popv(5);
    return nil;
}



/* Code for getrtypecar */

static Lisp_Object CC_getrtypecar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtypecar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v5 = qcar(v5);
    {
        fn = elt(env, 1); /* getrtype */
        return (*qfn1(fn))(qenv(fn), v5);
    }
}



/* Code for multf */

static Lisp_Object CC_multf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multf");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v12;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v40;

v40:
    v172 = stack[-2];
    if (v172 == nil) goto v3;
    v172 = stack[-1];
    if (v172 == nil) goto v3;
    v173 = stack[-2];
    v172 = (Lisp_Object)17; /* 1 */
    if (v173 == v172) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v173 = stack[-1];
    v172 = (Lisp_Object)17; /* 1 */
    if (v173 == v172) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v172 = stack[-2];
    if (!consp(v172)) goto v57;
    v172 = stack[-2];
    v172 = qcar(v172);
    if (!consp(v172)) goto v57;
    v172 = stack[-1];
    if (!consp(v172)) goto v53;
    v172 = stack[-1];
    v172 = qcar(v172);
    if (!consp(v172)) goto v53;
    v172 = qvalue(elt(env, 2)); /* !*exp */
    if (!(v172 == nil)) goto v2;
    v172 = qvalue(elt(env, 3)); /* ncmp!* */
    if (!(v172 == nil)) goto v2;
    v172 = qvalue(elt(env, 4)); /* wtl!* */
    if (!(v172 == nil)) goto v2;
    v172 = stack[-3];
    if (!(v172 == nil)) goto v2;
    v172 = stack[-2];
    fn = elt(env, 11); /* mkprod */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-2] = v172;
    v172 = stack[-1];
    fn = elt(env, 11); /* mkprod */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-1] = v172;
    v172 = qvalue(elt(env, 5)); /* t */
    stack[-3] = v172;
    goto v40;

v2:
    v172 = stack[-2];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = qcar(v172);
    stack[-3] = v172;
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = qcar(v172);
    stack[0] = v172;
    v172 = qvalue(elt(env, 6)); /* !*ncmp */
    if (v172 == nil) goto v111;
    v172 = stack[-1];
    fn = elt(env, 12); /* noncomfp1 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    if (v172 == nil) goto v111;
    v172 = qvalue(elt(env, 6)); /* !*ncmp */
    if (v172 == nil) goto v84;
    v172 = stack[-3];
    fn = elt(env, 13); /* noncomp1 */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    if (!(v172 == nil)) goto v101;

v84:
    v172 = qvalue(elt(env, 7)); /* !*!*processed */
    if (!(v172 == nil)) goto v111;

v101:
    v173 = stack[-2];
    v172 = stack[-1];
    {
        popv(5);
        fn = elt(env, 14); /* multfnc */
        return (*qfn2(fn))(qenv(fn), v173, v172);
    }

v111:
    v173 = stack[-3];
    v172 = stack[0];
    if (v173 == v172) goto v116;
    v173 = stack[-3];
    v172 = stack[0];
    fn = elt(env, 15); /* ordop */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    if (v172 == nil) goto v176;
    v172 = stack[-2];
    v172 = qcar(v172);
    v173 = qcdr(v172);
    v172 = stack[-1];
    v172 = CC_multf(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v172;
    v172 = stack[-2];
    v173 = qcdr(v172);
    v172 = stack[-1];
    v172 = CC_multf(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    stack[0] = v172;
    v172 = stack[-3];
    if (v172 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v172 = stack[-2];
    v172 = qcar(v172);
    v174 = qcar(v172);
    v173 = stack[-3];
    v172 = stack[0];
    popv(5);
    return acons(v174, v173, v172);

v176:
    v173 = stack[-2];
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = CC_multf(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v172;
    v173 = stack[-2];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = CC_multf(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    stack[0] = v172;
    v172 = stack[-3];
    if (v172 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v172 = stack[-1];
    v172 = qcar(v172);
    v174 = qcar(v172);
    v173 = stack[-3];
    v172 = stack[0];
    popv(5);
    return acons(v174, v173, v172);

v116:
    v172 = stack[-2];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = integerp(v172);
    if (v172 == nil) goto v177;
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = integerp(v172);
    if (v172 == nil) goto v177;
    stack[0] = stack[-3];
    v172 = stack[-2];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v173 = qcdr(v172);
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    fn = elt(env, 16); /* mkspm */
    v172 = (*qfn2(fn))(qenv(fn), stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v172;
    goto v178;

v178:
    v172 = stack[-2];
    v173 = qcdr(v172);
    v172 = stack[-1];
    stack[0] = CC_multf(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v172 = stack[-2];
    v172 = qcar(v172);
    v173 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = CC_multf(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    fn = elt(env, 17); /* addf */
    v172 = (*qfn2(fn))(qenv(fn), stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[0] = v172;
    v172 = stack[-3];
    if (v172 == nil) goto v179;
    v172 = stack[-2];
    v172 = qcar(v172);
    v173 = qcdr(v172);
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = CC_multf(env, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-2] = v172;
    if (v172 == nil) goto v179;
    v173 = stack[-3];
    v172 = (Lisp_Object)17; /* 1 */
    if (v173 == v172) goto v180;
    v172 = qvalue(elt(env, 10)); /* !*mcd */
    if (v172 == nil) goto v181;
    v174 = stack[-3];
    v173 = stack[-2];
    v172 = stack[0];
    popv(5);
    return acons(v174, v173, v172);

v181:
    v173 = stack[-3];
    v172 = stack[-2];
    v172 = cons(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v173 = ncons(v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v172 = stack[0];
    {
        popv(5);
        fn = elt(env, 17); /* addf */
        return (*qfn2(fn))(qenv(fn), v173, v172);
    }

v180:
    v173 = stack[-2];
    v172 = stack[0];
    {
        popv(5);
        fn = elt(env, 17); /* addf */
        return (*qfn2(fn))(qenv(fn), v173, v172);
    }

v179:
    v172 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 9)) = v172; /* !*asymp!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v177:
    stack[0] = stack[-3];
    v174 = elt(env, 8); /* plus */
    v172 = stack[-2];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v173 = qcdr(v172);
    v172 = stack[-1];
    v172 = qcar(v172);
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = list3(v174, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    fn = elt(env, 18); /* reval */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    v172 = cons(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-4];
    stack[-3] = v172;
    goto v178;

v53:
    v173 = stack[-1];
    v172 = stack[-2];
    {
        popv(5);
        fn = elt(env, 19); /* multd */
        return (*qfn2(fn))(qenv(fn), v173, v172);
    }

v57:
    v173 = stack[-2];
    v172 = stack[-1];
    {
        popv(5);
        fn = elt(env, 19); /* multd */
        return (*qfn2(fn))(qenv(fn), v173, v172);
    }

v3:
    v172 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v172); }
/* error exit handlers */
v175:
    popv(5);
    return nil;
}



/* Code for bc_prod */

static Lisp_Object CC_bc_prod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_prod");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v37 = v12;
    v38 = v0;
/* end of prologue */
    fn = elt(env, 1); /* multf */
    v37 = (*qfn2(fn))(qenv(fn), v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bc!=simp */
        return (*qfn1(fn))(qenv(fn), v37);
    }
/* error exit handlers */
v41:
    popv(1);
    return nil;
}



/* Code for dlesslex */

static Lisp_Object CC_dlesslex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v39, v21, v57;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dlesslex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v12;
    v21 = v0;
/* end of prologue */

v5:
    v24 = v21;
    if (v24 == nil) goto v1;
    v24 = v21;
    v57 = qcar(v24);
    v24 = v39;
    v24 = qcar(v24);
    if (((int32_t)(v57)) > ((int32_t)(v24))) goto v37;
    v24 = v21;
    v57 = qcar(v24);
    v24 = v39;
    v24 = qcar(v24);
    if (((int32_t)(v57)) < ((int32_t)(v24))) goto v35;
    v24 = v21;
    v24 = qcdr(v24);
    v21 = v24;
    v24 = v39;
    v24 = qcdr(v24);
    v39 = v24;
    goto v5;

v35:
    v24 = qvalue(elt(env, 2)); /* t */
    return onevalue(v24);

v37:
    v24 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v24);

v1:
    v24 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v24);
}



/* Code for pappl */

static Lisp_Object CC_pappl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v12;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v53 = stack[-3];
    fn = elt(env, 2); /* unpkp */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    stack[-3] = v53;
    goto v38;

v38:
    v53 = stack[-3];
    if (v53 == nil) goto v37;
    v53 = stack[-2];
    stack[-1] = v53;
    v53 = (Lisp_Object)17; /* 1 */
    stack[0] = v53;
    goto v17;

v17:
    v53 = stack[-3];
    v53 = qcar(v53);
    v66 = sub1(v53);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v53 = stack[0];
    v53 = difference2(v66, v53);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v53 = Lminusp(nil, v53);
    env = stack[-5];
    if (v53 == nil) goto v44;
    v53 = stack[-1];
    v66 = qcar(v53);
    v53 = stack[-4];
    v53 = cons(v66, v53);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    stack[-4] = v53;
    v53 = stack[-3];
    v53 = qcdr(v53);
    stack[-3] = v53;
    goto v38;

v44:
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    v53 = stack[0];
    v53 = add1(v53);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    stack[0] = v53;
    goto v17;

v37:
    v53 = stack[-4];
        popv(6);
        return Lnreverse(nil, v53);
/* error exit handlers */
v95:
    popv(6);
    return nil;
}



/* Code for noncomlistp */

static Lisp_Object CC_noncomlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomlistp");
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

v7:
    v28 = stack[0];
    v28 = Lconsp(nil, v28);
    env = stack[-1];
    if (v28 == nil) goto v32;
    v28 = stack[0];
    v28 = qcar(v28);
    fn = elt(env, 2); /* noncomp1 */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-1];
    if (!(v28 == nil)) { popv(2); return onevalue(v28); }
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v7;

v32:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v28); }
/* error exit handlers */
v43:
    popv(2);
    return nil;
}



/* Code for rnzerop!: */

static Lisp_Object CC_rnzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v37 = qcdr(v37);
    v38 = qcar(v37);
    v37 = (Lisp_Object)1; /* 0 */
    v37 = (v38 == v37 ? lisp_true : nil);
    return onevalue(v37);
}



/* Code for modonep!: */

static Lisp_Object CC_modonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modonep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v37 = qcdr(v4);
    v4 = (Lisp_Object)17; /* 1 */
    v4 = (v37 == v4 ? lisp_true : nil);
    return onevalue(v4);
}



/* Code for mchk!* */

static Lisp_Object CC_mchkH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchk*");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */
    v72 = stack[-1];
    v70 = stack[0];
    fn = elt(env, 3); /* mchk */
    v70 = (*qfn2(fn))(qenv(fn), v72, v70);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v72 = v70;
    if (!(v70 == nil)) { popv(3); return onevalue(v72); }
    v70 = qvalue(elt(env, 1)); /* !*mcd */
    if (!(v70 == nil)) goto v29;
    v70 = stack[-1];
    if (!consp(v70)) goto v29;
    v70 = stack[-1];
    v70 = qcar(v70);
    if (!consp(v70)) goto v29;
    v70 = stack[0];
    if (!consp(v70)) goto v29;
    v70 = stack[0];
    v70 = qcar(v70);
    if (!consp(v70)) goto v29;
    v72 = stack[-1];
    v70 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* prepf1 */
    v70 = (*qfn2(fn))(qenv(fn), v72, v70);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v72 = v70;
    v70 = v72;
    if (v70 == nil) goto v33;
    v70 = v72;
    fn = elt(env, 5); /* replus */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    stack[-1] = v70;
    goto v60;

v60:
    v72 = stack[0];
    v70 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* prepf1 */
    v70 = (*qfn2(fn))(qenv(fn), v72, v70);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v72 = v70;
    v70 = v72;
    if (v70 == nil) goto v65;
    v70 = v72;
    fn = elt(env, 5); /* replus */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    goto v39;

v39:
    {
        Lisp_Object v87 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* mchk */
        return (*qfn2(fn))(qenv(fn), v87, v70);
    }

v65:
    v70 = (Lisp_Object)1; /* 0 */
    goto v39;

v33:
    v70 = (Lisp_Object)1; /* 0 */
    stack[-1] = v70;
    goto v60;

v29:
    v70 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v70); }
/* error exit handlers */
v86:
    popv(3);
    return nil;
}



/* Code for multiply!-by!-constant!-mod!-p */

static Lisp_Object CC_multiplyKbyKconstantKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiply-by-constant-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v12;
    stack[-2] = v0;
/* end of prologue */
    v68 = stack[-2];
    if (v68 == nil) goto v5;
    v69 = stack[-1];
    v68 = (Lisp_Object)17; /* 1 */
    if (v69 == v68) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v68 = stack[-2];
    if (!consp(v68)) goto v44;
    v68 = stack[-2];
    v68 = qcar(v68);
    if (!consp(v68)) goto v44;
    v68 = stack[-2];
    v68 = qcar(v68);
    stack[-3] = qcar(v68);
    v68 = stack[-2];
    v68 = qcar(v68);
    v69 = qcdr(v68);
    v68 = stack[-1];
    stack[0] = CC_multiplyKbyKconstantKmodKp(env, v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    v68 = stack[-2];
    v69 = qcdr(v68);
    v68 = stack[-1];
    v68 = CC_multiplyKbyKconstantKmodKp(env, v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-4];
    {
        Lisp_Object v72 = stack[-3];
        Lisp_Object v98 = stack[0];
        popv(5);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v72, v98, v68);
    }

v44:
    v69 = stack[-2];
    v68 = stack[-1];
    v68 = Lmodular_times(nil, v69, v68);
    env = stack[-4];
    v69 = v68;
    v68 = v69;
    v68 = (Lisp_Object)zerop(v68);
    v68 = v68 ? lisp_true : nil;
    env = stack[-4];
    if (v68 == nil) { popv(5); return onevalue(v69); }
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v68); }

v5:
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v68); }
/* error exit handlers */
v70:
    popv(5);
    return nil;
}



/* Code for aeval */

static Lisp_Object CC_aeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aeval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = v3;
    v3 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* reval1 */
        return (*qfn2(fn))(qenv(fn), v4, v3);
    }
}



/* Code for rl_smupdknowl */

static Lisp_Object MS_CDECL CC_rl_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v12,
                         Lisp_Object v45, Lisp_Object v42, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v44, v71, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rl_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v42,v45,v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v12,v45,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v15 = v42;
    v44 = v45;
    v71 = v12;
    v27 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smupdknowl!* */
    v15 = list4(v27, v71, v44, v15);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    {
        Lisp_Object v17 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v17, v15);
    }
/* error exit handlers */
v56:
    popv(2);
    return nil;
}



/* Code for kernels1 */

static Lisp_Object CC_kernels1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v89, v93, v59;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernels1");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v93 = v12;
    v66 = v0;
/* end of prologue */

v7:
    v89 = v66;
    if (!consp(v89)) { popv(4); return onevalue(v93); }
    v89 = v66;
    v89 = qcar(v89);
    if (!consp(v89)) { popv(4); return onevalue(v93); }
    v89 = v66;
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = qcar(v89);
    v59 = v89;
    v89 = v66;
    v89 = qcar(v89);
    stack[-2] = qcdr(v89);
    stack[-1] = qcdr(v66);
    v89 = v59;
    v66 = v93;
    v66 = Lmemq(nil, v89, v66);
    if (v66 == nil) goto v30;
    v66 = v93;
    goto v18;

v18:
    v89 = CC_kernels1(env, stack[-1], v66);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v66 = stack[-2];
    v93 = v89;
    goto v7;

v30:
    stack[0] = v93;
    v66 = v59;
    v66 = ncons(v66);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    v66 = Lappend(nil, stack[0], v66);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    goto v18;
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for qqe_rbopp */

static Lisp_Object CC_qqe_rbopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_rbopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = elt(env, 1); /* (equal neq lessp leq geq greaterp) */
    v3 = Lmemq(nil, v3, v4);
    return onevalue(v3);
}



/* Code for pasf_dec */

static Lisp_Object CC_pasf_dec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dec");
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
    v58 = v0;
/* end of prologue */
    v10 = v58;
    stack[-1] = v10;
    goto v1;

v1:
    v10 = stack[-1];
    if (!consp(v10)) goto v71;
    v10 = stack[-1];
    v10 = qcar(v10);
    if (!consp(v10)) goto v71;
    v10 = stack[-1];
    v10 = qcdr(v10);
    stack[-1] = v10;
    goto v1;

v71:
    stack[0] = v58;
    v10 = stack[-1];
    fn = elt(env, 2); /* negf */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-2];
    fn = elt(env, 3); /* addf */
    v58 = (*qfn2(fn))(qenv(fn), stack[0], v10);
    nil = C_nil;
    if (exception_pending()) goto v25;
    v10 = stack[-1];
    popv(3);
    return cons(v58, v10);
/* error exit handlers */
v25:
    popv(3);
    return nil;
}



/* Code for lto_hashequalq */

static Lisp_Object CC_lto_hashequalq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_hashequalq");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v12;
    stack[-3] = v0;
/* end of prologue */
    v76 = (Lisp_Object)1; /* 0 */
    stack[-1] = v76;
    v76 = (Lisp_Object)1; /* 0 */
    stack[0] = v76;
    goto v38;

v38:
    v76 = stack[-3];
    if (v76 == nil) goto v37;
    v76 = stack[-2];
    if (v76 == nil) goto v37;
    v76 = stack[-3];
    v76 = qcar(v76);
    v77 = v76;
    v76 = stack[-2];
    v76 = qcar(v76);
    stack[-4] = v76;
    v76 = stack[-3];
    v76 = qcdr(v76);
    stack[-3] = v76;
    v76 = stack[-2];
    v76 = qcdr(v76);
    stack[-2] = v76;
    v76 = v77;
    fn = elt(env, 2); /* lto_hashid */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    v76 = (Lisp_Object)(int32_t)((int32_t)stack[-1] + (int32_t)v76 - TAG_FIXNUM);
    stack[-1] = v76;
    v76 = stack[-4];
    fn = elt(env, 2); /* lto_hashid */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-5];
    v76 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v76 - TAG_FIXNUM);
    stack[0] = v76;
    goto v38;

v37:
    v76 = stack[-3];
    if (v76 == nil) goto v22;
    v76 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v76); }

v22:
    v76 = stack[-2];
    if (v76 == nil) goto v89;
    v76 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v76); }

v89:
    v77 = stack[-1];
    v76 = stack[0];
        popv(6);
        return Leqn(nil, v77, v76);
/* error exit handlers */
v67:
    popv(6);
    return nil;
}



/* Code for setkorder */

static Lisp_Object CC_setkorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v11, v35;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setkorder");
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
    v35 = v0;
/* end of prologue */
    v43 = qvalue(elt(env, 1)); /* kord!* */
    stack[0] = v43;
    v11 = v35;
    v43 = stack[0];
    if (equal(v11, v43)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v43 = v35;
    qvalue(elt(env, 1)) = v43; /* kord!* */
    v43 = qvalue(elt(env, 2)); /* nil */
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    qvalue(elt(env, 3)) = v43; /* alglist!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v15:
    popv(2);
    return nil;
}



/* Code for replus */

static Lisp_Object CC_replus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replus");
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
    push(nil);
/* copy arguments values to proper place */
    v26 = v0;
/* end of prologue */
    v27 = v26;
    if (v27 == nil) goto v32;
    v27 = v26;
    if (!consp(v27)) { popv(1); return onevalue(v26); }
    v27 = v26;
    v27 = qcdr(v27);
    if (v27 == nil) goto v37;
    stack[0] = elt(env, 1); /* plus */
    v27 = v26;
    fn = elt(env, 2); /* unplus */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v17;
    {
        Lisp_Object v18 = stack[0];
        popv(1);
        return cons(v18, v27);
    }

v37:
    v27 = v26;
    v27 = qcar(v27);
    { popv(1); return onevalue(v27); }

v32:
    v27 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v27); }
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



/* Code for ps!:order */

static Lisp_Object CC_psTorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:order");
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
    v20 = v0;
/* end of prologue */
    v19 = v20;
    if (!consp(v19)) goto v32;
    v19 = v20;
    v25 = qcar(v19);
    v19 = elt(env, 1); /* !:ps!: */
    if (v25 == v19) goto v47;
    v19 = v20;
    v25 = qcar(v19);
    v19 = elt(env, 2); /* dname */
    v19 = get(v25, v19);
    env = stack[0];
    if (!(v19 == nil)) goto v32;

v47:
    v19 = (Lisp_Object)1; /* 0 */
    {
        popv(1);
        fn = elt(env, 3); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v20, v19);
    }

v32:
    v19 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v19); }
}



/* Code for numlis */

static Lisp_Object CC_numlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v28;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlis");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v0;
/* end of prologue */

v7:
    v28 = v29;
    v28 = (v28 == nil ? lisp_true : nil);
    if (!(v28 == nil)) return onevalue(v28);
    v28 = v29;
    v28 = qcar(v28);
    if (is_number(v28)) goto v41;
    v29 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v29);

v41:
    v29 = qcdr(v29);
    goto v7;
}



/* Code for constp */

static Lisp_Object CC_constp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constp");
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
    v16 = v0;
/* end of prologue */
    v15 = v16;
    v15 = (is_number(v15) ? lisp_true : nil);
    if (!(v15 == nil)) { popv(1); return onevalue(v15); }
    v15 = v16;
    v15 = Lconsp(nil, v15);
    env = stack[0];
    if (v15 == nil) goto v2;
    v16 = qcar(v16);
    v15 = qvalue(elt(env, 2)); /* domainlist!* */
    v16 = Lmemq(nil, v16, v15);
    { popv(1); return onevalue(v16); }

v2:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v16); }
}



/* Code for buchvevdivides!? */

static Lisp_Object CC_buchvevdividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v6, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for buchvevdivides?");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */
    v6 = stack[0];
    v47 = stack[-1];
    fn = elt(env, 3); /* vevmtest!? */
    v47 = (*qfn2(fn))(qenv(fn), v6, v47);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    if (v47 == nil) goto v5;
    v47 = qvalue(elt(env, 2)); /* gmodule!* */
    v47 = (v47 == nil ? lisp_true : nil);
    if (!(v47 == nil)) { popv(3); return onevalue(v47); }
    v50 = stack[-1];
    v6 = stack[0];
    v47 = qvalue(elt(env, 2)); /* gmodule!* */
    {
        popv(3);
        fn = elt(env, 4); /* gevcompatible1 */
        return (*qfnn(fn))(qenv(fn), 3, v50, v6, v47);
    }

v5:
    v47 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v47); }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for subs2f */

static Lisp_Object CC_subs2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2f");
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
    v69 = qvalue(elt(env, 1)); /* simpcount!* */
    v68 = qvalue(elt(env, 2)); /* simplimit!* */
    v68 = (Lisp_Object)greaterp2(v69, v68);
    nil = C_nil;
    if (exception_pending()) goto v100;
    v68 = v68 ? lisp_true : nil;
    env = stack[-2];
    if (v68 == nil) goto v8;
    v68 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v68; /* simpcount!* */
    v68 = elt(env, 3); /* "Simplification recursion too deep" */
    v69 = v68;
    v68 = v69;
    qvalue(elt(env, 4)) = v68; /* errmsg!* */
    v68 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v68 == nil)) goto v35;
    v68 = v69;
    fn = elt(env, 10); /* lprie */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    goto v35;

v35:
    v68 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    goto v8;

v8:
    v68 = qvalue(elt(env, 1)); /* simpcount!* */
    v68 = add1(v68);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    qvalue(elt(env, 1)) = v68; /* simpcount!* */
    v68 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 7)) = v68; /* !*sub2 */
    v68 = stack[0];
    fn = elt(env, 11); /* subs2f1 */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    stack[-1] = v68;
    v68 = qvalue(elt(env, 7)); /* !*sub2 */
    if (!(v68 == nil)) goto v20;
    v68 = qvalue(elt(env, 8)); /* powlis1!* */
    if (!(v68 == nil)) goto v20;

v10:
    v68 = qvalue(elt(env, 1)); /* simpcount!* */
    v68 = sub1(v68);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    qvalue(elt(env, 1)) = v68; /* simpcount!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v20:
    v68 = qvalue(elt(env, 9)); /* !*resubs */
    if (v68 == nil) goto v10;
    v68 = stack[-1];
    v69 = qcar(v68);
    v68 = stack[0];
    if (!(equal(v69, v68))) goto v77;
    v68 = stack[-1];
    v69 = qcdr(v68);
    v68 = (Lisp_Object)17; /* 1 */
    if (!(v69 == v68)) goto v77;
    v68 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 7)) = v68; /* !*sub2 */
    goto v10;

v77:
    v68 = stack[-1];
    fn = elt(env, 12); /* subs2q */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    stack[-1] = v68;
    goto v10;
/* error exit handlers */
v100:
    popv(3);
    return nil;
}



/* Code for ordad */

static Lisp_Object CC_ordad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordad");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v1;

v1:
    v95 = stack[0];
    if (v95 == nil) goto v58;
    v62 = stack[-1];
    v95 = stack[0];
    v95 = qcar(v95);
    fn = elt(env, 2); /* ordp */
    v95 = (*qfn2(fn))(qenv(fn), v62, v95);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    if (!(v95 == nil)) goto v58;
    v95 = stack[0];
    v62 = qcar(v95);
    v95 = stack[-2];
    v95 = cons(v62, v95);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    stack[-2] = v95;
    v95 = stack[0];
    v95 = qcdr(v95);
    stack[0] = v95;
    goto v1;

v58:
    v62 = stack[-1];
    v95 = stack[0];
    v95 = cons(v62, v95);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    stack[0] = v95;
    goto v54;

v54:
    v95 = stack[-2];
    if (v95 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v95 = stack[-2];
    v95 = qcdr(v95);
    stack[-1] = v95;
    v62 = stack[-2];
    v95 = stack[0];
    v95 = Lrplacd(nil, v62, v95);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    v95 = stack[-2];
    stack[0] = v95;
    v95 = stack[-1];
    stack[-2] = v95;
    goto v54;
/* error exit handlers */
v90:
    popv(4);
    return nil;
}



/* Code for pprin2 */

static Lisp_Object CC_pprin2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v11;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pprin2");
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
    v11 = stack[0];
    v43 = qvalue(elt(env, 1)); /* !*pprinbuf!* */
    v43 = cons(v11, v43);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    qvalue(elt(env, 1)) = v43; /* !*pprinbuf!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*posn!* */
    v43 = stack[0];
    v43 = Lexplodec(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    v43 = Llength(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    v43 = plus2(stack[-1], v43);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    qvalue(elt(env, 2)) = v43; /* !*posn!* */
    v43 = nil;
    { popv(3); return onevalue(v43); }
/* error exit handlers */
v15:
    popv(3);
    return nil;
}



/* Code for isanindex */

static Lisp_Object CC_isanindex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v66, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isanindex");
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
    v89 = v0;
/* end of prologue */
    v53 = v89;
    if (symbolp(v53)) goto v38;
    v53 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v53); }

v38:
    v66 = v89;
    v53 = qvalue(elt(env, 2)); /* physopindices!* */
    v53 = Lmemq(nil, v66, v53);
    if (!(v53 == nil)) { popv(1); return onevalue(v53); }
    v66 = v89;
    v53 = qvalue(elt(env, 3)); /* physopvarind!* */
    v53 = Lmember(nil, v66, v53);
    if (!(v53 == nil)) { popv(1); return onevalue(v53); }
    v66 = v89;
    v53 = qvalue(elt(env, 4)); /* frlis!* */
    v53 = Lmemq(nil, v66, v53);
    if (v53 == nil) goto v17;
    v66 = v89;
    v53 = qvalue(elt(env, 5)); /* frasc!* */
    fn = elt(env, 6); /* revassoc */
    v53 = (*qfn2(fn))(qenv(fn), v66, v53);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[0];
    v66 = qvalue(elt(env, 2)); /* physopindices!* */
    v53 = Lmember(nil, v53, v66);
    { popv(1); return onevalue(v53); }

v17:
    v53 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v53); }
/* error exit handlers */
v93:
    popv(1);
    return nil;
}



/* Code for getrmacro */

static Lisp_Object CC_getrmacro(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrmacro");
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
    v54 = stack[0];
    if (symbolp(v54)) goto v1;
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v54); }

v1:
    v54 = stack[0];
    fn = elt(env, 4); /* getd */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v49 = v54;
    if (v54 == nil) goto v27;
    v54 = v49;
    v55 = qcar(v54);
    v54 = elt(env, 2); /* macro */
    if (v55 == v54) { popv(2); return onevalue(v49); }
    else goto v27;

v27:
    v55 = stack[0];
    v54 = elt(env, 3); /* smacro */
    v54 = get(v55, v54);
    env = stack[-1];
    v49 = v54;
    if (v54 == nil) goto v21;
    v54 = elt(env, 3); /* smacro */
    v55 = v49;
    popv(2);
    return cons(v54, v55);

v21:
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v54); }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for addd */

static Lisp_Object CC_addd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addd");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v12;
    stack[-1] = v0;
/* end of prologue */
    v33 = nil;
    goto v8;

v8:
    v51 = stack[0];
    if (v51 == nil) goto v9;
    v51 = stack[0];
    if (!consp(v51)) goto v71;
    v51 = stack[0];
    v51 = qcar(v51);
    if (!consp(v51)) goto v71;
    v51 = stack[0];
    v51 = qcar(v51);
    v51 = cons(v51, v33);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v33 = v51;
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[0] = v51;
    goto v8;

v71:
    stack[-2] = v33;
    v33 = stack[-1];
    v51 = stack[0];
    fn = elt(env, 1); /* adddm */
    v51 = (*qfn2(fn))(qenv(fn), v33, v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    {
        Lisp_Object v66 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v66, v51);
    }

v9:
    v51 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v33, v51);
    }
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for sub2chk */

static Lisp_Object CC_sub2chk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub2chk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v0;
/* end of prologue */
    v17 = qvalue(elt(env, 1)); /* subfg!* */
    if (v17 == nil) goto v5;
    v18 = v47;
    v17 = qvalue(elt(env, 2)); /* powlis!* */
    v17 = Latsoc(nil, v18, v17);
    if (!(v17 == nil)) goto v32;
    v17 = v47;
    if (!consp(v17)) goto v5;
    v17 = v47;
    v18 = qcar(v17);
    v17 = elt(env, 3); /* (expt sqrt) */
    v17 = Lmemq(nil, v18, v17);
    if (!(v17 == nil)) goto v32;

v5:
    v17 = nil;
    return onevalue(v17);

v32:
    v17 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 5)) = v17; /* !*sub2 */
    return onevalue(v17);
}



/* Code for ring_ecart */

static Lisp_Object CC_ring_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ring_ecart");
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
    v4 = v0;
/* end of prologue */
    v37 = v4;
    v4 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v4 = (*qfn2(fn))(qenv(fn), v37, v4);
    errexit();
    v4 = qcar(v4);
    return onevalue(v4);
}



/* Code for multdm */

static Lisp_Object CC_multdm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v95, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multdm");
#endif
    if (stack >= stacklimit)
    {
        push2(v12,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v95 = v12;
    v62 = v0;
/* end of prologue */
    v61 = v62;
    if (!(!consp(v61))) goto v53;
    v61 = v95;
    if (!(!consp(v61))) goto v53;
    v61 = v62;
    v61 = times2(v61, v95);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[0];
    v62 = v61;
    v61 = qvalue(elt(env, 1)); /* dmode!* */
    if (v61 == nil) { popv(1); return onevalue(v62); }
    v95 = qvalue(elt(env, 1)); /* dmode!* */
    v61 = elt(env, 2); /* convert */
    v61 = Lflagp(nil, v95, v61);
    env = stack[0];
    if (v61 == nil) { popv(1); return onevalue(v62); }
    v95 = qvalue(elt(env, 1)); /* dmode!* */
    v61 = elt(env, 3); /* i2d */
    v61 = get(v95, v61);
    v95 = v62;
        popv(1);
        return Lapply1(nil, v61, v95);

v53:
    v61 = elt(env, 4); /* times */
    {
        popv(1);
        fn = elt(env, 5); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v62, v95, v61);
    }
/* error exit handlers */
v76:
    popv(1);
    return nil;
}



/* Code for reduce_pv */

static Lisp_Object CC_reduce_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v12)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v9, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce_pv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v12;
    v9 = v0;
/* end of prologue */
    v13 = v9;
    v9 = v41;
    v41 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* reduce_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v13, v9, v41);
    }
}



/* Code for upbve */

static Lisp_Object CC_upbve(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for upbve");
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
    v41 = stack[0];
    v41 = Lupbv(nil, v41);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-1];
    if (v41 == nil) goto v32;
    v41 = stack[0];
    v41 = Lupbv(nil, v41);
    nil = C_nil;
    if (exception_pending()) goto v13;
    popv(2);
    return add1(v41);

v32:
    v41 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v41); }
/* error exit handlers */
v13:
    popv(2);
    return nil;
}



setup_type const u01_setup[] =
{
    {"reval",                   CC_reval,       too_many_1,    wrong_no_1},
    {"num-exponents",           CC_numKexponents,too_many_1,   wrong_no_1},
    {"*ssave",                  too_few_2,      CC_Hssave,     wrong_no_2},
    {"*d2q",                    CC_Hd2q,        too_many_1,    wrong_no_1},
    {"getrtypeor",              CC_getrtypeor,  too_many_1,    wrong_no_1},
    {"smember",                 too_few_2,      CC_smember,    wrong_no_2},
    {"quotf",                   too_few_2,      CC_quotf,      wrong_no_2},
    {"quotelist",               CC_quotelist,   too_many_1,    wrong_no_1},
    {"wuconstantp",             CC_wuconstantp, too_many_1,    wrong_no_1},
    {"mkcopy",                  CC_mkcopy,      too_many_1,    wrong_no_1},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,too_many_1,wrong_no_1},
    {"noncomp1",                CC_noncomp1,    too_many_1,    wrong_no_1},
    {"pnth",                    too_few_2,      CC_pnth,       wrong_no_2},
    {"degr",                    too_few_2,      CC_degr,       wrong_no_2},
    {"qqe_rqopp",               CC_qqe_rqopp,   too_many_1,    wrong_no_1},
    {"ibalp_cec",               CC_ibalp_cec,   too_many_1,    wrong_no_1},
    {"ctx_fromial",             CC_ctx_fromial, too_many_1,    wrong_no_1},
    {"delall",                  too_few_2,      CC_delall,     wrong_no_2},
    {"noncomfp1",               CC_noncomfp1,   too_many_1,    wrong_no_1},
    {"prepf",                   CC_prepf,       too_many_1,    wrong_no_1},
    {"ps:getv",                 too_few_2,      CC_psTgetv,    wrong_no_2},
    {"csl_normbf",              CC_csl_normbf,  too_many_1,    wrong_no_1},
    {"ldepends",                too_few_2,      CC_ldepends,   wrong_no_2},
    {"c:ordxp",                 too_few_2,      CC_cTordxp,    wrong_no_2},
    {"zero2nil",                CC_zero2nil,    too_many_1,    wrong_no_1},
    {"ordop",                   too_few_2,      CC_ordop,      wrong_no_2},
    {"binding",                 CC_binding,     too_many_1,    wrong_no_1},
    {"prepf1",                  too_few_2,      CC_prepf1,     wrong_no_2},
    {"evcomp",                  too_few_2,      CC_evcomp,     wrong_no_2},
    {"evmatrixcomp2",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp2},
    {"xval",                    CC_xval,        too_many_1,    wrong_no_1},
    {"add_prin_char",           too_few_2,      CC_add_prin_char,wrong_no_2},
    {"physopp",                 CC_physopp,     too_many_1,    wrong_no_1},
    {"memq_edgelist",           too_few_2,      CC_memq_edgelist,wrong_no_2},
    {"readch1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_readch1},
    {"termsf",                  CC_termsf,      too_many_1,    wrong_no_1},
    {"mkspm",                   too_few_2,      CC_mkspm,      wrong_no_2},
    {"mo_divides?",             too_few_2,      CC_mo_dividesW,wrong_no_2},
    {"mtp",                     CC_mtp,         too_many_1,    wrong_no_1},
    {"c_zero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_c_zero},
    {"sieve_pv0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sieve_pv0},
    {"listp",                   CC_listp,       too_many_1,    wrong_no_1},
    {"adjoin-term",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_adjoinKterm},
    {"modzerop:",               CC_modzeropT,   too_many_1,    wrong_no_1},
    {"ordpp",                   too_few_2,      CC_ordpp,      wrong_no_2},
    {"minusf",                  CC_minusf,      too_many_1,    wrong_no_1},
    {"reorder",                 CC_reorder,     too_many_1,    wrong_no_1},
    {"nocp",                    CC_nocp,        too_many_1,    wrong_no_1},
    {"get+mat+entry",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_getLmatLentry},
    {"kernlp",                  CC_kernlp,      too_many_1,    wrong_no_1},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {"qqe_qoptailp",            CC_qqe_qoptailp,too_many_1,    wrong_no_1},
    {"sort",                    too_few_2,      CC_sort,       wrong_no_2},
    {"ibalp_clmember",          too_few_2,      CC_ibalp_clmember,wrong_no_2},
    {"aex_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_mk},
    {"find2",                   too_few_2,      CC_find2,      wrong_no_2},
    {"butes",                   CC_butes,       too_many_1,    wrong_no_1},
    {"nil2zero",                CC_nil2zero,    too_many_1,    wrong_no_1},
    {"pm:free",                 CC_pmTfree,     too_many_1,    wrong_no_1},
    {"vevmtest?",               too_few_2,      CC_vevmtestW,  wrong_no_2},
    {"vbcsize",                 too_few_2,      CC_vbcsize,    wrong_no_2},
    {"wedgefax",                CC_wedgefax,    too_many_1,    wrong_no_1},
    {"prin2la",                 CC_prin2la,     too_many_1,    wrong_no_1},
    {"scprint",                 too_few_2,      CC_scprint,    wrong_no_2},
    {"int-equiv-chk",           CC_intKequivKchk,too_many_1,   wrong_no_1},
    {"gcdfd1",                  too_few_2,      CC_gcdfd1,     wrong_no_2},
    {"noncomp2",                CC_noncomp2,    too_many_1,    wrong_no_1},
    {"union_edge",              too_few_2,      CC_union_edge, wrong_no_2},
    {"addf",                    too_few_2,      CC_addf,       wrong_no_2},
    {"formlis",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formlis},
    {"getrtypecar",             CC_getrtypecar, too_many_1,    wrong_no_1},
    {"multf",                   too_few_2,      CC_multf,      wrong_no_2},
    {"bc_prod",                 too_few_2,      CC_bc_prod,    wrong_no_2},
    {"dlesslex",                too_few_2,      CC_dlesslex,   wrong_no_2},
    {"pappl",                   too_few_2,      CC_pappl,      wrong_no_2},
    {"noncomlistp",             CC_noncomlistp, too_many_1,    wrong_no_1},
    {"rnzerop:",                CC_rnzeropT,    too_many_1,    wrong_no_1},
    {"modonep:",                CC_modonepT,    too_many_1,    wrong_no_1},
    {"mchk*",                   too_few_2,      CC_mchkH,      wrong_no_2},
    {"multiply-by-constant-mod-p",too_few_2,    CC_multiplyKbyKconstantKmodKp,wrong_no_2},
    {"aeval",                   CC_aeval,       too_many_1,    wrong_no_1},
    {"rl_smupdknowl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smupdknowl},
    {"kernels1",                too_few_2,      CC_kernels1,   wrong_no_2},
    {"qqe_rbopp",               CC_qqe_rbopp,   too_many_1,    wrong_no_1},
    {"pasf_dec",                CC_pasf_dec,    too_many_1,    wrong_no_1},
    {"lto_hashequalq",          too_few_2,      CC_lto_hashequalq,wrong_no_2},
    {"setkorder",               CC_setkorder,   too_many_1,    wrong_no_1},
    {"replus",                  CC_replus,      too_many_1,    wrong_no_1},
    {"ps:order",                CC_psTorder,    too_many_1,    wrong_no_1},
    {"numlis",                  CC_numlis,      too_many_1,    wrong_no_1},
    {"constp",                  CC_constp,      too_many_1,    wrong_no_1},
    {"buchvevdivides?",         too_few_2,      CC_buchvevdividesW,wrong_no_2},
    {"subs2f",                  CC_subs2f,      too_many_1,    wrong_no_1},
    {"ordad",                   too_few_2,      CC_ordad,      wrong_no_2},
    {"pprin2",                  CC_pprin2,      too_many_1,    wrong_no_1},
    {"isanindex",               CC_isanindex,   too_many_1,    wrong_no_1},
    {"getrmacro",               CC_getrmacro,   too_many_1,    wrong_no_1},
    {"addd",                    too_few_2,      CC_addd,       wrong_no_2},
    {"sub2chk",                 CC_sub2chk,     too_many_1,    wrong_no_1},
    {"ring_ecart",              CC_ring_ecart,  too_many_1,    wrong_no_1},
    {"multdm",                  too_few_2,      CC_multdm,     wrong_no_2},
    {"reduce_pv",               too_few_2,      CC_reduce_pv,  wrong_no_2},
    {"upbve",                   CC_upbve,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u01", (two_args *)"4563 2310284 7685734", 0}
};

/* end of generated code */
