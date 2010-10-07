
/* $destdir\u22.c        Machine generated C code */

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


/* Code for quotof */

static Lisp_Object CC_quotof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotof");
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
    v71 = stack[-3];
    if (v71 == nil) goto v74;
    v72 = stack[-3];
    v71 = stack[-2];
    if (equal(v72, v71)) goto v75;
    v72 = stack[-2];
    v71 = (Lisp_Object)17; /* 1 */
    if (v72 == v71) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v71 = stack[-2];
    if (!consp(v71)) goto v76;
    v71 = stack[-2];
    v71 = qcar(v71);
    if (!consp(v71)) goto v76;
    v71 = stack[-3];
    if (!consp(v71)) goto v77;
    v71 = stack[-3];
    v71 = qcar(v71);
    if (!consp(v71)) goto v77;
    v71 = stack[-3];
    v71 = qcar(v71);
    v72 = qcar(v71);
    v71 = stack[-2];
    v71 = qcar(v71);
    v71 = qcar(v71);
    stack[0] = v72;
    stack[-4] = v71;
    v71 = stack[0];
    v72 = qcar(v71);
    v71 = stack[-4];
    v71 = qcar(v71);
    if (v72 == v71) goto v78;
    v71 = stack[0];
    v72 = qcar(v71);
    v71 = stack[-4];
    v71 = qcar(v71);
    fn = elt(env, 7); /* ordop */
    v71 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    if (v71 == nil) goto v80;
    stack[-1] = stack[0];
    v71 = stack[-3];
    v71 = qcar(v71);
    v72 = qcdr(v71);
    v71 = stack[-2];
    stack[0] = CC_quotof(env, v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = stack[-3];
    v72 = qcdr(v71);
    v71 = stack[-2];
    v71 = CC_quotof(env, v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    {
        Lisp_Object v81 = stack[-1];
        Lisp_Object v82 = stack[0];
        popv(6);
        return acons(v81, v82, v71);
    }

v80:
    v71 = stack[-4];
    v71 = qcar(v71);
    fn = elt(env, 8); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = stack[-4];
    v71 = qcdr(v71);
    v71 = negate(v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    fn = elt(env, 9); /* getpower */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    stack[-1] = stack[-3];
    v71 = stack[-2];
    v71 = qcdr(v71);
    if (v71 == nil) goto v83;
    v72 = elt(env, 3); /* "Wrong number of arguments to" */
    v71 = elt(env, 4); /* lcx */
    v71 = list2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v72 = v71;
    v71 = v72;
    qvalue(elt(env, 5)) = v71; /* errmsg!* */
    v71 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v71 == nil)) goto v84;
    v71 = v72;
    fn = elt(env, 10); /* lprie */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    goto v84;

v84:
    v71 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = nil;
    goto v85;

v85:
    v71 = qcdr(v71);
    v71 = CC_quotof(env, stack[-1], v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = cons(stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    popv(6);
    return ncons(v71);

v83:
    v71 = stack[-2];
    v71 = qcar(v71);
    goto v85;

v78:
    v71 = stack[0];
    v72 = qcdr(v71);
    v71 = stack[-4];
    v71 = qcdr(v71);
    stack[-1] = difference2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = stack[-3];
    v71 = qcar(v71);
    stack[0] = qcdr(v71);
    v71 = stack[-2];
    v71 = qcdr(v71);
    if (v71 == nil) goto v86;
    v72 = elt(env, 3); /* "Wrong number of arguments to" */
    v71 = elt(env, 4); /* lcx */
    v71 = list2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v72 = v71;
    v71 = v72;
    qvalue(elt(env, 5)) = v71; /* errmsg!* */
    v71 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v71 == nil)) goto v87;
    v71 = v72;
    fn = elt(env, 10); /* lprie */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    goto v87;

v87:
    v71 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = nil;
    goto v88;

v88:
    v71 = qcdr(v71);
    stack[0] = CC_quotof(env, stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = stack[-3];
    v72 = qcdr(v71);
    v71 = stack[-2];
    v71 = CC_quotof(env, v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v73 = stack[-1];
    stack[-1] = stack[0];
    stack[0] = v71;
    v72 = v73;
    v71 = (Lisp_Object)1; /* 0 */
    if (v72 == v71) goto v89;
    v71 = stack[-4];
    v71 = qcar(v71);
    v72 = v73;
    v73 = cons(v71, v72);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v72 = stack[-1];
    v71 = stack[0];
    popv(6);
    return acons(v73, v72, v71);

v89:
    v72 = stack[-1];
    v71 = stack[0];
    {
        popv(6);
        fn = elt(env, 11); /* raddf */
        return (*qfn2(fn))(qenv(fn), v72, v71);
    }

v86:
    v71 = stack[-2];
    v71 = qcar(v71);
    goto v88;

v77:
    v71 = stack[-2];
    v71 = qcar(v71);
    v71 = qcar(v71);
    v71 = qcdr(v71);
    stack[-1] = v71;
    v71 = stack[-2];
    v71 = qcar(v71);
    v71 = qcar(v71);
    v71 = qcar(v71);
    fn = elt(env, 8); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = stack[-1];
    if (is_number(v71)) goto v90;
    v72 = elt(env, 2); /* minus */
    v71 = stack[-1];
    v71 = list2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    goto v91;

v91:
    fn = elt(env, 9); /* getpower */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    stack[-1] = stack[-3];
    v71 = stack[-2];
    v71 = qcdr(v71);
    if (v71 == nil) goto v92;
    v72 = elt(env, 3); /* "Wrong number of arguments to" */
    v71 = elt(env, 4); /* lcx */
    v71 = list2(v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v72 = v71;
    v71 = v72;
    qvalue(elt(env, 5)) = v71; /* errmsg!* */
    v71 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v71 == nil)) goto v93;
    v71 = v72;
    fn = elt(env, 10); /* lprie */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    goto v93;

v93:
    v71 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = nil;
    goto v94;

v94:
    v71 = qcdr(v71);
    v71 = CC_quotof(env, stack[-1], v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    v71 = cons(stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    popv(6);
    return ncons(v71);

v92:
    v71 = stack[-2];
    v71 = qcar(v71);
    goto v94;

v90:
    v71 = stack[-1];
    v71 = negate(v71);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-5];
    goto v91;

v76:
    v72 = stack[-3];
    v71 = stack[-2];
    {
        popv(6);
        fn = elt(env, 12); /* quotofd */
        return (*qfn2(fn))(qenv(fn), v72, v71);
    }

v75:
    v71 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v71); }

v74:
    v71 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v71); }
/* error exit handlers */
v79:
    popv(6);
    return nil;
}



/* Code for ilog2 */

static Lisp_Object CC_ilog2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v13, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ilog2");
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
    v13 = stack[-2];
    v21 = (Lisp_Object)1; /* 0 */
    v21 = (Lisp_Object)lesseq2(v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v21 = v21 ? lisp_true : nil;
    env = stack[-4];
    if (v21 == nil) goto v119;
    stack[0] = (Lisp_Object)1; /* 0 */
    v117 = stack[-2];
    v13 = elt(env, 1); /* " invalid for " */
    v21 = elt(env, 0); /* ilog2 */
    v21 = list3(v117, v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    fn = elt(env, 3); /* error */
    v21 = (*qfn2(fn))(qenv(fn), stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    goto v119;

v119:
    v21 = (Lisp_Object)33; /* 2 */
    stack[0] = v21;
    v21 = stack[0];
    v21 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    stack[-1] = v21;
    goto v120;

v120:
    v13 = stack[-2];
    v21 = stack[0];
    v21 = (Lisp_Object)greaterp2(v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v21 = v21 ? lisp_true : nil;
    env = stack[-4];
    if (v21 == nil) goto v121;
    v13 = stack[0];
    v21 = stack[-1];
    v21 = cons(v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    stack[-1] = v21;
    v13 = stack[0];
    v21 = stack[0];
    v21 = times2(v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    stack[0] = v21;
    goto v120;

v121:
    v21 = (Lisp_Object)1; /* 0 */
    stack[-3] = v21;
    goto v122;

v122:
    v21 = stack[-1];
    v13 = qcar(v21);
    stack[0] = v13;
    v21 = (Lisp_Object)33; /* 2 */
    if (v13 == v21) goto v123;
    v21 = stack[-1];
    v21 = qcdr(v21);
    stack[-1] = v21;
    v13 = stack[-2];
    v21 = stack[0];
    v21 = (Lisp_Object)geq2(v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v21 = v21 ? lisp_true : nil;
    env = stack[-4];
    if (v21 == nil) goto v59;
    v13 = stack[-2];
    v21 = stack[0];
    v21 = quot2(v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    stack[-2] = v21;
    v21 = stack[-3];
    v21 = add1(v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    stack[-3] = v21;
    goto v59;

v59:
    v13 = stack[-3];
    v21 = (Lisp_Object)33; /* 2 */
    v21 = times2(v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    stack[-3] = v21;
    goto v122;

v123:
    v13 = stack[-2];
    v21 = (Lisp_Object)33; /* 2 */
    v21 = (Lisp_Object)geq2(v13, v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v21 = v21 ? lisp_true : nil;
    env = stack[-4];
    if (v21 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v21 = stack[-3];
    v21 = add1(v21);
    nil = C_nil;
    if (exception_pending()) goto v118;
    stack[-3] = v21;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v118:
    popv(5);
    return nil;
}



/* Code for difbf */

static Lisp_Object CC_difbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difbf");
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
    v167 = stack[-7];
    v167 = qcdr(v167);
    v19 = qcar(v167);
    stack[-8] = v19;
    v167 = (Lisp_Object)1; /* 0 */
    if (v19 == v167) goto v67;
    v167 = stack[-6];
    v167 = qcdr(v167);
    v19 = qcar(v167);
    stack[-5] = v19;
    v167 = (Lisp_Object)1; /* 0 */
    if (v19 == v167) goto v66;
    v167 = stack[-7];
    v167 = qcdr(v167);
    v19 = qcdr(v167);
    stack[-4] = v19;
    v167 = stack[-6];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    stack[-3] = v167;
    v19 = difference2(v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    stack[-2] = v19;
    v167 = (Lisp_Object)1; /* 0 */
    if (v19 == v167) goto v169;
    stack[-1] = stack[-2];
    v167 = stack[-8];
    v167 = Labsval(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = stack[-5];
    v167 = Labsval(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    fn = elt(env, 3); /* msd */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = difference2(stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = plus2(stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    stack[-1] = v167;
    v167 = qvalue(elt(env, 2)); /* !:bprec!: */
    v167 = add1(v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    stack[0] = v167;
    v19 = stack[-1];
    v167 = stack[0];
    v167 = (Lisp_Object)greaterp2(v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    v167 = v167 ? lisp_true : nil;
    env = stack[-9];
    if (v167 == nil) goto v170;
    v167 = stack[-7];
    goto v171;

v171:
    stack[-2] = v167;
    v167 = stack[-2];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v20 = v167;
    v19 = v20;
    v167 = (Lisp_Object)1; /* 0 */
    if (v19 == v167) goto v172;
    v19 = v20;
    v167 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v167 = (*qfn2(fn))(qenv(fn), v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v20 = v167;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v167 = v20;
    stack[0] = qcar(v167);
    v167 = v20;
    v19 = qcdr(v167);
    v167 = stack[-2];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = plus2(v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    {
        Lisp_Object v173 = stack[-1];
        Lisp_Object v174 = stack[0];
        popv(10);
        return list2star(v173, v174, v167);
    }

v172:
    v20 = elt(env, 1); /* !:rd!: */
    v19 = (Lisp_Object)1; /* 0 */
    v167 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v20, v19, v167);

v170:
    v167 = stack[0];
    v167 = negate(v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = (Lisp_Object)lessp2(stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    v167 = v167 ? lisp_true : nil;
    env = stack[-9];
    if (v167 == nil) goto v175;
    stack[0] = elt(env, 1); /* !:rd!: */
    v167 = stack[-6];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v19 = negate(v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = stack[-6];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = list2star(stack[0], v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    goto v171;

v175:
    v19 = stack[-2];
    v167 = (Lisp_Object)1; /* 0 */
    v167 = (Lisp_Object)greaterp2(v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    v167 = v167 ? lisp_true : nil;
    env = stack[-9];
    if (v167 == nil) goto v176;
    stack[0] = elt(env, 1); /* !:rd!: */
    v19 = stack[-8];
    v167 = stack[-2];
    v19 = Lash1(nil, v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = stack[-5];
    v19 = difference2(v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = stack[-3];
    v167 = list2star(stack[0], v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    goto v171;

v176:
    stack[0] = elt(env, 1); /* !:rd!: */
    stack[-1] = stack[-8];
    stack[-3] = stack[-5];
    v167 = stack[-2];
    v167 = negate(v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = Lash1(nil, stack[-3], v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v19 = difference2(stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = stack[-4];
    v167 = list2star(stack[0], v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    goto v171;

v169:
    stack[0] = elt(env, 1); /* !:rd!: */
    v19 = stack[-8];
    v167 = stack[-5];
    v19 = difference2(v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = stack[-4];
    v167 = list2star(stack[0], v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    goto v171;

v66:
    v167 = stack[-7];
    goto v171;

v67:
    stack[0] = elt(env, 1); /* !:rd!: */
    v167 = stack[-6];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v19 = negate(v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    v167 = stack[-6];
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    v167 = list2star(stack[0], v19, v167);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-9];
    goto v171;
/* error exit handlers */
v168:
    popv(10);
    return nil;
}



/* Code for drnconv */

static Lisp_Object CC_drnconv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v162, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drnconv");
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
    v110 = v0;
/* end of prologue */
    v182 = v110;
    if (v182 == nil) return onevalue(v110);
    v182 = v110;
    if (is_number(v182)) return onevalue(v110);
    v162 = v110;
    v182 = qvalue(elt(env, 1)); /* dmd!* */
    if (!consp(v162)) goto v165;
    v162 = qcar(v162);
    if (v162 == v182) return onevalue(v110);
    else goto v165;

v165:
    v182 = v110;
    v162 = qcar(v182);
    v182 = qvalue(elt(env, 1)); /* dmd!* */
    v182 = get(v162, v182);
    v162 = v182;
    v182 = v162;
    if (v182 == nil) return onevalue(v110);
    v182 = v162;
    if (!(!consp(v182))) return onevalue(v110);
    v182 = v162;
    v162 = v110;
        return Lapply1(nil, v182, v162);
}



/* Code for get!*elements */

static Lisp_Object CC_getHelements(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v185;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*elements");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v184 = v0;
/* end of prologue */
    v185 = elt(env, 1); /* elems */
    return get(v184, v185);
}



/* Code for qqe_arg!-check!-q */

static Lisp_Object CC_qqe_argKcheckKq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_arg-check-q");
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
    v186 = stack[0];
    fn = elt(env, 3); /* qqe_id!-nyt!-branchq */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    if (v186 == nil) goto v143;
    v186 = stack[0];
    if (!(!consp(v186))) goto v183;
    v186 = stack[0];
    if (is_number(v186)) goto v183;
    v186 = stack[0];
    fn = elt(env, 4); /* qqe_btidp */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    if (v186 == nil) goto v187;
    v186 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v186); }

v187:
    v186 = stack[0];
    fn = elt(env, 5); /* qqe_nytidp */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    if (v186 == nil) goto v115;
    v186 = stack[0];
    fn = elt(env, 6); /* qqe_qtid */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    v186 = stack[0];
    fn = elt(env, 7); /* qqe_add2rollbackids */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    v186 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v186); }

v115:
    v186 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v186); }

v183:
    v186 = stack[0];
    if (is_number(v186)) goto v74;
    v186 = stack[0];
    fn = elt(env, 8); /* qqe_arg!-check */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-1];
    v186 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v186); }

v74:
    v186 = nil;
    { popv(2); return onevalue(v186); }

v143:
    v186 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v186); }
/* error exit handlers */
v177:
    popv(2);
    return nil;
}



/* Code for pasf_subfof1 */

static Lisp_Object MS_CDECL CC_pasf_subfof1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_subfof1");
#endif
    if (stack >= stacklimit)
    {
        push3(v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v95;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v205 = stack[-3];
    v205 = Lconsp(nil, v205);
    env = stack[-5];
    if (v205 == nil) goto v94;
    v205 = stack[-3];
    v205 = qcar(v205);
    v205 = Lconsp(nil, v205);
    env = stack[-5];
    if (v205 == nil) goto v94;
    v205 = stack[-3];
    v205 = qcar(v205);
    v206 = qcar(v205);
    v205 = elt(env, 1); /* (cong ncong) */
    v205 = Lmemq(nil, v206, v205);
    if (v205 == nil) goto v94;
    v206 = stack[-3];
    v205 = elt(env, 2); /* true */
    if (v206 == v205) goto v65;
    v206 = stack[-3];
    v205 = elt(env, 3); /* false */
    if (v206 == v205) goto v65;
    v205 = stack[-3];
    v205 = qcar(v205);
    v205 = Lconsp(nil, v205);
    env = stack[-5];
    if (v205 == nil) goto v60;
    v205 = stack[-3];
    v205 = qcar(v205);
    v205 = qcar(v205);
    stack[-4] = v205;
    goto v61;

v61:
    v205 = stack[-3];
    v205 = qcar(v205);
    stack[0] = qcdr(v205);
    v206 = stack[-2];
    v205 = stack[-1];
    v205 = cons(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v205 = ncons(v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    fn = elt(env, 4); /* subf */
    v205 = (*qfn2(fn))(qenv(fn), stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v205 = qcar(v205);
    v205 = cons(stack[-4], v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    stack[-4] = v205;
    goto v54;

v54:
    v205 = stack[-3];
    v205 = qcdr(v205);
    stack[0] = qcar(v205);
    v206 = stack[-2];
    v205 = stack[-1];
    v205 = cons(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v205 = ncons(v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    fn = elt(env, 4); /* subf */
    v205 = (*qfn2(fn))(qenv(fn), stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    stack[0] = qcar(v205);
    v205 = stack[-3];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    stack[-3] = qcar(v205);
    v206 = stack[-2];
    v205 = stack[-1];
    v205 = cons(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v205 = ncons(v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    fn = elt(env, 4); /* subf */
    v205 = (*qfn2(fn))(qenv(fn), stack[-3], v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v205 = qcar(v205);
    {
        Lisp_Object v207 = stack[-4];
        Lisp_Object v208 = stack[0];
        popv(6);
        return list3(v207, v208, v205);
    }

v60:
    v205 = stack[-3];
    v205 = qcar(v205);
    stack[-4] = v205;
    goto v61;

v65:
    v205 = stack[-3];
    stack[-4] = v205;
    goto v61;

v94:
    v206 = stack[-3];
    v205 = elt(env, 2); /* true */
    if (v206 == v205) goto v209;
    v206 = stack[-3];
    v205 = elt(env, 3); /* false */
    if (v206 == v205) goto v209;
    v205 = stack[-3];
    v205 = qcar(v205);
    v205 = Lconsp(nil, v205);
    env = stack[-5];
    if (v205 == nil) goto v210;
    v205 = stack[-3];
    v205 = qcar(v205);
    v205 = qcar(v205);
    goto v211;

v211:
    stack[-4] = v205;
    goto v54;

v210:
    v205 = stack[-3];
    v205 = qcar(v205);
    goto v211;

v209:
    v205 = stack[-3];
    goto v211;
/* error exit handlers */
v86:
    popv(6);
    return nil;
}



/* Code for ibalp_negatet */

static Lisp_Object CC_ibalp_negatet(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v113, v114;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negatet");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v114 = v0;
/* end of prologue */
    v113 = v114;
    v115 = (Lisp_Object)1; /* 0 */
    if (v113 == v115) goto v101;
    v113 = v114;
    v115 = (Lisp_Object)17; /* 1 */
    if (v113 == v115) goto v185;
    v115 = elt(env, 1); /* bnot */
    v113 = v114;
    return list2(v115, v113);

v185:
    v115 = (Lisp_Object)1; /* 0 */
    return onevalue(v115);

v101:
    v115 = (Lisp_Object)17; /* 1 */
    return onevalue(v115);
}



/* Code for bvarml */

static Lisp_Object CC_bvarml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bvarml");
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
    v115 = elt(env, 1); /* "<bvar>" */
    fn = elt(env, 5); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v115 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 6); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v115 = stack[0];
    v115 = qcar(v115);
    fn = elt(env, 7); /* expression */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v115 = stack[0];
    v115 = qcdr(v115);
    v113 = qcar(v115);
    v115 = (Lisp_Object)17; /* 1 */
    if (v113 == v115) goto v183;
    v115 = stack[0];
    v115 = qcdr(v115);
    v115 = qcar(v115);
    v115 = ncons(v115);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    fn = elt(env, 8); /* degreeml */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    goto v183;

v183:
    v115 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 6); /* indent!* */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v115 = elt(env, 4); /* "</bvar>" */
    fn = elt(env, 5); /* printout */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v76;
    v115 = nil;
    { popv(2); return onevalue(v115); }
/* error exit handlers */
v76:
    popv(2);
    return nil;
}



/* Code for ps!:expansion!-point */

static Lisp_Object CC_psTexpansionKpoint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v163, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expansion-point");
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
    v163 = v0;
/* end of prologue */
    v215 = v163;
    if (!consp(v215)) goto v101;
    v215 = v163;
    v121 = qcar(v215);
    v215 = elt(env, 1); /* !:ps!: */
    if (v121 == v215) goto v115;
    v215 = v163;
    v121 = qcar(v215);
    v215 = elt(env, 2); /* dname */
    v215 = get(v121, v215);
    env = stack[0];
    if (!(v215 == nil)) goto v101;

v115:
    v215 = (Lisp_Object)49; /* 3 */
    {
        popv(1);
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v163, v215);
    }

v101:
    v215 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v215); }
}



/* Code for recaliasbacksubst */

static Lisp_Object CC_recaliasbacksubst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for recaliasbacksubst");
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
    stack[0] = v0;
/* end of prologue */
    v157 = stack[0];
    if (!consp(v157)) goto v69;
    v157 = stack[0];
    fn = elt(env, 2); /* constp */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    if (!(v157 == nil)) goto v69;
    v157 = stack[0];
    stack[-4] = v157;
    v157 = stack[-4];
    if (v157 == nil) goto v177;
    v157 = stack[-4];
    v157 = qcar(v157);
    v158 = v157;
    v157 = stack[-3];
    v157 = CC_recaliasbacksubst(env, v158, v157);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    v157 = ncons(v157);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    stack[-1] = v157;
    stack[-2] = v157;
    goto v66;

v66:
    v157 = stack[-4];
    v157 = qcdr(v157);
    stack[-4] = v157;
    v157 = stack[-4];
    if (v157 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v157 = stack[-4];
    v157 = qcar(v157);
    v158 = v157;
    v157 = stack[-3];
    v157 = CC_recaliasbacksubst(env, v158, v157);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    v157 = ncons(v157);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    v157 = Lrplacd(nil, stack[0], v157);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-5];
    v157 = stack[-1];
    v157 = qcdr(v157);
    stack[-1] = v157;
    goto v66;

v177:
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v157); }

v69:
    v158 = stack[0];
    v157 = stack[-3];
    v157 = Lassoc(nil, v158, v157);
    if (v157 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v158 = stack[0];
    v157 = stack[-3];
    v157 = Lassoc(nil, v158, v157);
    v157 = qcdr(v157);
    { popv(6); return onevalue(v157); }
/* error exit handlers */
v94:
    popv(6);
    return nil;
}



/* Code for meq */

static Lisp_Object CC_meq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v204, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for meq");
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
    v179 = stack[-1];
    fn = elt(env, 2); /* binding */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    v204 = v179;
    v179 = v204;
    if (v179 == nil) goto v67;
    v179 = v204;
    v164 = elt(env, 1); /* unbound */
    if (v179 == v164) goto v67;
    v179 = v204;
    v204 = v179;
    goto v119;

v119:
    v179 = stack[0];
    v179 = (equal(v204, v179) ? lisp_true : nil);
    { popv(3); return onevalue(v179); }

v67:
    v179 = stack[-1];
    v204 = v179;
    goto v119;
/* error exit handlers */
v114:
    popv(3);
    return nil;
}



/* Code for groedeletip */

static Lisp_Object CC_groedeletip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groedeletip");
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

v119:
    v160 = stack[0];
    if (v160 == nil) goto v140;
    v221 = stack[-1];
    v160 = stack[0];
    v160 = qcar(v160);
    if (!(equal(v221, v160))) goto v140;
    v160 = stack[0];
    v160 = qcdr(v160);
    stack[0] = v160;
    goto v119;

v140:
    v160 = stack[0];
    if (v160 == nil) goto v180;
    v160 = stack[0];
    stack[-2] = v160;
    goto v114;

v114:
    v160 = stack[0];
    v160 = qcdr(v160);
    if (v160 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v221 = stack[-1];
    v160 = stack[0];
    v160 = qcdr(v160);
    v160 = qcar(v160);
    if (equal(v221, v160)) goto v201;
    v160 = stack[0];
    v160 = qcdr(v160);
    stack[0] = v160;
    goto v114;

v201:
    v221 = stack[0];
    v160 = stack[0];
    v160 = qcdr(v160);
    v160 = qcdr(v160);
    fn = elt(env, 2); /* setcdr */
    v160 = (*qfn2(fn))(qenv(fn), v221, v160);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    goto v114;

v180:
    v160 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v160); }
/* error exit handlers */
v216:
    popv(4);
    return nil;
}



/* Code for vdpsave */

static Lisp_Object CC_vdpsave(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v106;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsave");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v106 = v0;
/* end of prologue */
    return onevalue(v106);
}



/* Code for testchar1 */

static Lisp_Object CC_testchar1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v222;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testchar1");
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
    v120 = stack[0];
    v120 = integerp(v120);
    if (!(v120 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v120 = stack[0];
    v120 = Lexplodec(nil, v120);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-1];
    v120 = qcdr(v120);
    if (v120 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v222 = stack[0];
    v120 = qvalue(elt(env, 1)); /* nochar!* */
    v120 = Lmember(nil, v222, v120);
    if (!(v120 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v222 = stack[0];
    v120 = qvalue(elt(env, 2)); /* nochar1!* */
    v120 = Lmember(nil, v222, v120);
    if (!(v120 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v222 = stack[0];
    v120 = qvalue(elt(env, 2)); /* nochar1!* */
    v120 = cons(v222, v120);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-1];
    qvalue(elt(env, 2)) = v120; /* nochar1!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v182:
    popv(2);
    return nil;
}



/* Code for physopordchk!* */

static Lisp_Object CC_physopordchkH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopordchk*");
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
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v229:
    v228 = stack[-1];
    v228 = qcar(v228);
    stack[-4] = v228;
    v228 = stack[-1];
    v228 = qcdr(v228);
    stack[-1] = v228;
    v228 = stack[-1];
    if (v228 == nil) goto v185;
    v228 = stack[-4];
    v50 = ncons(v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v228 = stack[0];
    v228 = CC_physopordchkH(env, v50, v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    if (v228 == nil) goto v152;
    v50 = stack[-1];
    v228 = stack[0];
    stack[-1] = v50;
    stack[0] = v228;
    goto v229;

v152:
    v228 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v228); }

v185:
    v228 = stack[0];
    v228 = qcdr(v228);
    if (v228 == nil) goto v230;
    v228 = stack[0];
    stack[-3] = v228;
    v228 = stack[-3];
    if (v228 == nil) goto v218;
    v228 = stack[-3];
    v228 = qcar(v228);
    v50 = stack[-4];
    fn = elt(env, 3); /* ncmpchk */
    v228 = (*qfn2(fn))(qenv(fn), v50, v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v228 = ncons(v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[-1] = v228;
    stack[-2] = v228;
    goto v231;

v231:
    v228 = stack[-3];
    v228 = qcdr(v228);
    stack[-3] = v228;
    v228 = stack[-3];
    if (v228 == nil) goto v199;
    stack[0] = stack[-1];
    v228 = stack[-3];
    v228 = qcar(v228);
    v50 = stack[-4];
    fn = elt(env, 3); /* ncmpchk */
    v228 = (*qfn2(fn))(qenv(fn), v50, v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v228 = ncons(v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v228 = Lrplacd(nil, stack[0], v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v228 = stack[-1];
    v228 = qcdr(v228);
    stack[-1] = v228;
    goto v231;

v199:
    v228 = stack[-2];
    goto v100;

v100:
    v50 = qvalue(elt(env, 1)); /* nil */
    v228 = Lmember(nil, v50, v228);
    if (v228 == nil) goto v232;
    v228 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v228); }

v232:
    v228 = qvalue(elt(env, 2)); /* t */
    { popv(6); return onevalue(v228); }

v218:
    v228 = qvalue(elt(env, 1)); /* nil */
    goto v100;

v230:
    v50 = stack[-4];
    v228 = stack[0];
    v228 = qcar(v228);
    fn = elt(env, 3); /* ncmpchk */
    v228 = (*qfn2(fn))(qenv(fn), v50, v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    if (v228 == nil) goto v112;
    v228 = stack[-4];
    fn = elt(env, 4); /* invp */
    v50 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v190;
    v228 = stack[0];
    v228 = qcar(v228);
    v228 = (equal(v50, v228) ? lisp_true : nil);
    v228 = (v228 == nil ? lisp_true : nil);
    { popv(6); return onevalue(v228); }

v112:
    v228 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v228); }
/* error exit handlers */
v190:
    popv(6);
    return nil;
}



/* Code for rnprep!: */

static Lisp_Object CC_rnprepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v160, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnprep:");
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
    v108 = stack[-1];
    v108 = qcdr(v108);
    v160 = qcar(v108);
    v108 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* prepf1 */
    v108 = (*qfn2(fn))(qenv(fn), v160, v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    v160 = v108;
    v108 = v160;
    if (v108 == nil) goto v234;
    v108 = v160;
    fn = elt(env, 4); /* replus */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    goto v185;

v185:
    v221 = v108;
    v108 = stack[-1];
    v108 = qcdr(v108);
    v160 = qcdr(v108);
    v108 = (Lisp_Object)17; /* 1 */
    if (v160 == v108) { popv(4); return onevalue(v221); }
    stack[-2] = elt(env, 2); /* quotient */
    stack[0] = v221;
    v108 = stack[-1];
    v108 = qcdr(v108);
    v160 = qcdr(v108);
    v108 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* prepf1 */
    v108 = (*qfn2(fn))(qenv(fn), v160, v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    v160 = v108;
    v108 = v160;
    if (v108 == nil) goto v51;
    v108 = v160;
    fn = elt(env, 4); /* replus */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    goto v178;

v178:
    {
        Lisp_Object v169 = stack[-2];
        Lisp_Object v235 = stack[0];
        popv(4);
        return list3(v169, v235, v108);
    }

v51:
    v108 = (Lisp_Object)1; /* 0 */
    goto v178;

v234:
    v108 = (Lisp_Object)1; /* 0 */
    goto v185;
/* error exit handlers */
v216:
    popv(4);
    return nil;
}



/* Code for super_der_simp */

static Lisp_Object CC_super_der_simp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v286, v287, v288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for super_der_simp");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0;
/* end of prologue */
    v286 = stack[-9];
    v287 = Llength(nil, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = (Lisp_Object)33; /* 2 */
    if (v287 == v286) goto v101;
    v286 = stack[-9];
    {
        popv(12);
        fn = elt(env, 7); /* simpiden */
        return (*qfn1(fn))(qenv(fn), v286);
    }

v101:
    v286 = stack[-9];
    v286 = qcar(v286);
    fn = elt(env, 8); /* reval */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-10] = v286;
    v287 = stack[-10];
    v286 = elt(env, 1); /* variables */
    v286 = get(v287, v286);
    env = stack[-11];
    stack[-8] = v286;
    v286 = stack[-9];
    v286 = qcdr(v286);
    v286 = qcar(v286);
    fn = elt(env, 9); /* simp!* */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-9] = v286;
    v286 = stack[-9];
    v287 = qcar(v286);
    v286 = elt(env, 2); /* (ext) */
    fn = elt(env, 10); /* split_form */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-7] = v286;
    v286 = elt(env, 3); /* ext */
    v288 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-7];
    v287 = qcar(v286);
    v286 = stack[-7];
    v286 = qcdr(v286);
    v286 = acons(v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-7] = v286;
    v286 = stack[-9];
    v287 = qcdr(v286);
    v286 = elt(env, 2); /* (ext) */
    fn = elt(env, 10); /* split_form */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-6] = v286;
    v286 = elt(env, 3); /* ext */
    v288 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-6];
    v287 = qcar(v286);
    v286 = stack[-6];
    v286 = qcdr(v286);
    v286 = acons(v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-6] = v286;
    v286 = (Lisp_Object)17; /* 1 */
    stack[-5] = v286;
    v287 = stack[-10];
    v286 = elt(env, 4); /* even_dimension */
    v287 = get(v287, v286);
    env = stack[-11];
    v286 = stack[-5];
    v286 = difference2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = Lminusp(nil, v286);
    env = stack[-11];
    if (v286 == nil) goto v58;
    v286 = qvalue(elt(env, 5)); /* nil */
    goto v105;

v105:
    stack[-5] = v286;
    v286 = (Lisp_Object)17; /* 1 */
    stack[-4] = v286;
    v287 = stack[-10];
    v286 = elt(env, 6); /* odd_dimension */
    v287 = get(v287, v286);
    env = stack[-11];
    v286 = stack[-4];
    v286 = difference2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = Lminusp(nil, v286);
    env = stack[-11];
    if (v286 == nil) goto v290;
    v286 = qvalue(elt(env, 5)); /* nil */
    goto v291;

v291:
    stack[0] = v286;
    v287 = stack[-5];
    v286 = stack[-6];
    fn = elt(env, 11); /* even_action */
    stack[-1] = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-9];
    v287 = qcar(v286);
    v286 = (Lisp_Object)17; /* 1 */
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 12); /* super_product_sq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-9];
    v287 = qcdr(v286);
    v286 = stack[-9];
    v286 = qcdr(v286);
    fn = elt(env, 13); /* multf */
    v287 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = (Lisp_Object)17; /* 1 */
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 14); /* invsq */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 15); /* multsq */
    v286 = (*qfn2(fn))(qenv(fn), stack[-1], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-1] = v286;
    v287 = stack[-5];
    v286 = stack[-7];
    fn = elt(env, 11); /* even_action */
    stack[-2] = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v287 = stack[0];
    v286 = stack[-7];
    fn = elt(env, 16); /* odd_action */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 17); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-2], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-9];
    v287 = qcdr(v286);
    v286 = (Lisp_Object)17; /* 1 */
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 14); /* invsq */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 15); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-1];
    v286 = qcar(v286);
    fn = elt(env, 18); /* negf */
    v287 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-1];
    v286 = qcdr(v286);
    v286 = cons(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    {
        Lisp_Object v292 = stack[0];
        popv(12);
        fn = elt(env, 17); /* addsq */
        return (*qfn2(fn))(qenv(fn), v292, v286);
    }

v290:
    v288 = stack[-10];
    v287 = (Lisp_Object)17; /* 1 */
    v286 = stack[-4];
    v286 = list3(v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[0] = stack[-4];
    v287 = v286;
    v286 = elt(env, 2); /* (ext) */
    fn = elt(env, 19); /* split_ext */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = cons(stack[0], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-2] = v286;
    stack[-3] = v286;
    goto v136;

v136:
    v286 = stack[-4];
    v286 = add1(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-4] = v286;
    v287 = stack[-10];
    v286 = elt(env, 6); /* odd_dimension */
    v287 = get(v287, v286);
    env = stack[-11];
    v286 = stack[-4];
    v286 = difference2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = Lminusp(nil, v286);
    env = stack[-11];
    if (v286 == nil) goto v293;
    v286 = stack[-3];
    goto v291;

v293:
    stack[-1] = stack[-2];
    v288 = stack[-10];
    v287 = (Lisp_Object)17; /* 1 */
    v286 = stack[-4];
    v286 = list3(v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[0] = stack[-4];
    v287 = v286;
    v286 = elt(env, 2); /* (ext) */
    fn = elt(env, 19); /* split_ext */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = cons(stack[0], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = Lrplacd(nil, stack[-1], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-2];
    v286 = qcdr(v286);
    stack[-2] = v286;
    goto v136;

v58:
    v288 = stack[-10];
    v287 = (Lisp_Object)1; /* 0 */
    v286 = stack[-5];
    v286 = list3(v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-1] = v286;
    v287 = stack[-8];
    v286 = stack[-5];
    fn = elt(env, 20); /* pnth */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[0] = qcar(v286);
    v287 = stack[-1];
    v286 = elt(env, 2); /* (ext) */
    fn = elt(env, 19); /* split_ext */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = cons(stack[0], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-3] = v286;
    stack[-4] = v286;
    goto v217;

v217:
    v286 = stack[-5];
    v286 = add1(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-5] = v286;
    v287 = stack[-10];
    v286 = elt(env, 4); /* even_dimension */
    v287 = get(v287, v286);
    env = stack[-11];
    v286 = stack[-5];
    v286 = difference2(v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = Lminusp(nil, v286);
    env = stack[-11];
    if (v286 == nil) goto v88;
    v286 = stack[-4];
    goto v105;

v88:
    stack[-2] = stack[-3];
    v288 = stack[-10];
    v287 = (Lisp_Object)1; /* 0 */
    v286 = stack[-5];
    v286 = list3(v288, v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v286 = (*qfn1(fn))(qenv(fn), v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[-1] = v286;
    v287 = stack[-8];
    v286 = stack[-5];
    fn = elt(env, 20); /* pnth */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    stack[0] = qcar(v286);
    v287 = stack[-1];
    v286 = elt(env, 2); /* (ext) */
    fn = elt(env, 19); /* split_ext */
    v286 = (*qfn2(fn))(qenv(fn), v287, v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = cons(stack[0], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = ncons(v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = Lrplacd(nil, stack[-2], v286);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-11];
    v286 = stack[-3];
    v286 = qcdr(v286);
    stack[-3] = v286;
    goto v217;
/* error exit handlers */
v289:
    popv(12);
    return nil;
}



/* Code for ofsf_entry2at1 */

static Lisp_Object MS_CDECL CC_ofsf_entry2at1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v163, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at1");
#endif
    if (stack >= stacklimit)
    {
        push3(v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v95;
    stack[-1] = v1;
    v215 = v0;
/* end of prologue */
    v163 = stack[-1];
    v121 = qcar(v163);
    v163 = v215;
    v215 = elt(env, 1); /* and */
    v215 = (v163 == v215 ? lisp_true : nil);
    fn = elt(env, 3); /* ofsf_clnegrel */
    stack[-2] = (*qfn2(fn))(qenv(fn), v121, v215);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-3];
    v163 = stack[0];
    v215 = stack[-1];
    v215 = qcdr(v215);
    fn = elt(env, 4); /* addsq */
    v215 = (*qfn2(fn))(qenv(fn), v163, v215);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-3];
    v215 = qcar(v215);
    v163 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v178 = stack[-2];
        popv(4);
        return list3(v178, v215, v163);
    }
/* error exit handlers */
v186:
    popv(4);
    return nil;
}



/* Code for wusort */

static Lisp_Object CC_wusort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wusort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v134 = v0;
/* end of prologue */
    v171 = v134;
    v134 = elt(env, 1); /* wulessp!* */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v171, v134);
    }
}



/* Code for smemberlp */

static Lisp_Object CC_smemberlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemberlp");
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

v229:
    v66 = stack[0];
    if (v66 == nil) goto v74;
    v66 = stack[0];
    if (!consp(v66)) goto v183;
    v77 = stack[-1];
    v66 = stack[0];
    v66 = qcar(v66);
    v66 = CC_smemberlp(env, v77, v66);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[-2];
    if (!(v66 == nil)) { popv(3); return onevalue(v66); }
    v77 = stack[-1];
    v66 = stack[0];
    v66 = qcdr(v66);
    stack[-1] = v77;
    stack[0] = v66;
    goto v229;

v183:
    v77 = stack[0];
    v66 = stack[-1];
    v66 = Lmember(nil, v77, v66);
    { popv(3); return onevalue(v66); }

v74:
    v66 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v66); }
/* error exit handlers */
v177:
    popv(3);
    return nil;
}



/* Code for simpexpt11 */

static Lisp_Object MS_CDECL CC_simpexpt11(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v285, v153, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt11");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt11");
#endif
    if (stack >= stacklimit)
    {
        push3(v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v95;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v285 = qvalue(elt(env, 1)); /* !*precise_complex */
    if (v285 == nil) goto v134;
    v99 = stack[-3];
    v153 = stack[-2];
    v285 = stack[-1];
    {
        popv(6);
        fn = elt(env, 2); /* simpexpt2 */
        return (*qfnn(fn))(qenv(fn), 3, v99, v153, v285);
    }

v134:
    v285 = stack[-2];
    v285 = qcdr(v285);
    if (!consp(v285)) goto v203;
    v285 = stack[-2];
    v285 = qcdr(v285);
    v285 = qcar(v285);
    if (!consp(v285)) goto v203;
    v285 = stack[-2];
    v153 = qcar(v285);
    v285 = stack[-2];
    v285 = qcdr(v285);
    fn = elt(env, 3); /* qremf */
    v285 = (*qfn2(fn))(qenv(fn), v153, v285);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    stack[-4] = v285;
    v285 = qcar(v285);
    if (v285 == nil) goto v203;
    v285 = stack[-4];
    v285 = qcdr(v285);
    if (v285 == nil) goto v203;
    stack[0] = stack[-3];
    v285 = stack[-4];
    v153 = qcar(v285);
    v285 = (Lisp_Object)17; /* 1 */
    v153 = cons(v153, v285);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    v285 = stack[-1];
    fn = elt(env, 4); /* simpexpt1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, stack[0], v153, v285);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    v285 = stack[-4];
    v153 = qcdr(v285);
    v285 = stack[-2];
    v285 = qcdr(v285);
    v153 = cons(v153, v285);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    v285 = stack[-1];
    fn = elt(env, 4); /* simpexpt1 */
    v285 = (*qfnn(fn))(qenv(fn), 3, stack[-3], v153, v285);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-5];
    {
        Lisp_Object v57 = stack[0];
        popv(6);
        fn = elt(env, 5); /* multsq */
        return (*qfn2(fn))(qenv(fn), v57, v285);
    }

v203:
    v99 = stack[-3];
    v153 = stack[-2];
    v285 = stack[-1];
    {
        popv(6);
        fn = elt(env, 2); /* simpexpt2 */
        return (*qfnn(fn))(qenv(fn), 3, v99, v153, v285);
    }
/* error exit handlers */
v59:
    popv(6);
    return nil;
}



/* Code for get!-denom!-l */

static Lisp_Object CC_getKdenomKl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v110, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-denom-l");
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
    v110 = v0;
/* end of prologue */
    v162 = v110;
    v162 = qcar(v162);
    if (!consp(v162)) goto v101;
    v162 = v110;
    v162 = qcar(v162);
    v162 = qcdr(v162);
    v162 = qcdr(v162);
    goto v106;

v106:
    v110 = qcdr(v110);
    stack[0] = v110;
    goto v258;

v258:
    v110 = stack[0];
    if (v110 == nil) { popv(2); return onevalue(v162); }
    v110 = stack[0];
    v110 = qcar(v110);
    v111 = v110;
    v110 = v162;
    v162 = v111;
    if (!consp(v162)) goto v163;
    v162 = v111;
    v162 = qcdr(v162);
    v162 = qcdr(v162);
    goto v113;

v113:
    fn = elt(env, 2); /* lcmn */
    v162 = (*qfn2(fn))(qenv(fn), v110, v162);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-1];
    v110 = stack[0];
    v110 = qcdr(v110);
    stack[0] = v110;
    goto v258;

v163:
    v162 = (Lisp_Object)17; /* 1 */
    goto v113;

v101:
    v162 = (Lisp_Object)17; /* 1 */
    goto v106;
/* error exit handlers */
v220:
    popv(2);
    return nil;
}



/* Code for ibalp_readform */

static Lisp_Object CC_ibalp_readform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_readform");
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
    v191 = v0;
/* end of prologue */
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-3] = nil;
    v149 = (Lisp_Object)1; /* 0 */
    stack[0] = v149;
    v149 = v191;
    v191 = elt(env, 1); /* and */
    fn = elt(env, 9); /* cl_mkstrict */
    v191 = (*qfn2(fn))(qenv(fn), v149, v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    v191 = qcdr(v191);
    stack[-2] = v191;
    v191 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v191;
    goto v67;

v67:
    v191 = stack[-1];
    if (v191 == nil) goto v112;
    v191 = stack[-2];
    if (v191 == nil) goto v112;
    v191 = stack[-2];
    v191 = qcar(v191);
    v149 = v191;
    v191 = stack[-2];
    v191 = qcdr(v191);
    stack[-2] = v191;
    v191 = stack[-4];
    fn = elt(env, 10); /* ibalp_readclause */
    v191 = (*qfn2(fn))(qenv(fn), v149, v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    stack[-6] = v191;
    v191 = stack[-6];
    v191 = qcar(v191);
    stack[-3] = v191;
    v191 = stack[-6];
    v191 = qcdr(v191);
    stack[-4] = v191;
    v149 = stack[-3];
    v191 = elt(env, 4); /* true */
    if (v149 == v191) goto v67;
    v191 = stack[-3];
    fn = elt(env, 11); /* ibalp_emptyclausep */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    if (v191 == nil) goto v169;
    v191 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v191;
    goto v67;

v169:
    v149 = stack[-3];
    v191 = stack[-5];
    fn = elt(env, 12); /* ibalp_clmember */
    v191 = (*qfn2(fn))(qenv(fn), v149, v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    if (!(v191 == nil)) goto v61;
    v191 = stack[-3];
    fn = elt(env, 13); /* ibalp_redclause */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    if (!(v191 == nil)) goto v61;
    v191 = stack[-6];
    v149 = qcar(v191);
    v191 = stack[-5];
    v191 = cons(v149, v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    stack[-5] = v191;
    goto v67;

v61:
    v191 = stack[-3];
    fn = elt(env, 14); /* ibalp_undoclause */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    v191 = stack[0];
    v191 = add1(v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    stack[0] = v191;
    goto v67;

v112:
    v191 = stack[-1];
    if (v191 == nil) goto v198;
    v191 = stack[-5];
    if (v191 == nil) goto v93;
    v191 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v191 == nil) goto v50;
    v149 = elt(env, 8); /* "Deleted redundant clauses: " */
    v191 = stack[0];
    v191 = list2(v149, v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    goto v50;

v50:
    v149 = stack[-5];
    v191 = stack[-4];
    popv(8);
    return cons(v149, v191);

v93:
    v191 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v191 == nil) goto v296;
    v191 = elt(env, 7); /* "Tautology detected" */
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    goto v296;

v296:
    v191 = qvalue(elt(env, 3)); /* nil */
    popv(8);
    return ncons(v191);

v198:
    v191 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v191 == nil) goto v99;
    v191 = elt(env, 6); /* "Detected empty clause" */
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-7];
    goto v99;

v99:
    v191 = stack[-3];
    v191 = ncons(v191);
    nil = C_nil;
    if (exception_pending()) goto v189;
    popv(8);
    return ncons(v191);
/* error exit handlers */
v189:
    popv(8);
    return nil;
}



/* Code for numpoly_lc */

static Lisp_Object CC_numpoly_lc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v116;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_lc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v0;
/* end of prologue */
    v116 = v70;
    if (v116 == nil) return onevalue(v70);
    v116 = v70;
    if (is_number(v116)) return onevalue(v70);
    v70 = qcar(v70);
    v70 = qcdr(v70);
    return onevalue(v70);
}



/* Code for encodeir */

static Lisp_Object CC_encodeir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v203, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for encodeir");
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
    stack[-1] = qvalue(elt(env, 1)); /* char */
    v203 = elt(env, 2); /* !  */
    v222 = qvalue(elt(env, 3)); /* atts */
    v222 = cons(v203, v222);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-2];
    v222 = Lappend(nil, stack[-1], v222);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-2];
    v203 = elt(env, 4); /* !$ */
    fn = elt(env, 7); /* delall */
    v222 = (*qfn2(fn))(qenv(fn), v203, v222);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-2];
    stack[-1] = elt(env, 5); /* semantic */
    v182 = stack[0];
    v203 = v222;
    v222 = qvalue(elt(env, 6)); /* nil */
    v222 = list2star(v182, v203, v222);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-2];
    v203 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v64 = stack[-1];
        popv(3);
        return list2star(v64, v222, v203);
    }
/* error exit handlers */
v111:
    popv(3);
    return nil;
}



/* Code for insoccs */

static Lisp_Object CC_insoccs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v297, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insoccs");
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
    v297 = stack[-1];
    if (symbolp(v297)) goto v165;
    v297 = stack[-1];
    fn = elt(env, 2); /* subscriptedvarp */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    if (!(v297 == nil)) goto v165;
    v297 = stack[-1];
    v297 = Lconsp(nil, v297);
    env = stack[-2];
    if (v297 == nil) goto v143;
    v297 = stack[-1];
    v297 = qcar(v297);
    fn = elt(env, 2); /* subscriptedvarp */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    if (!(v297 == nil)) goto v165;

v143:
    v297 = stack[-1];
    if (symbolp(v297)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v297 = stack[-1];
    fn = elt(env, 3); /* constp */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    if (!(v297 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v297 = stack[-1];
    v297 = qcdr(v297);
    stack[-1] = v297;
    goto v65;

v65:
    v297 = stack[-1];
    if (v297 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v297 = stack[-1];
    v297 = qcar(v297);
    v219 = v297;
    v297 = stack[0];
    v297 = CC_insoccs(env, v219, v297);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    stack[0] = v297;
    v297 = stack[-1];
    v297 = qcdr(v297);
    stack[-1] = v297;
    goto v65;

v165:
    v219 = stack[0];
    v297 = stack[-1];
    fn = elt(env, 4); /* insertocc */
    v297 = (*qfn2(fn))(qenv(fn), v219, v297);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    stack[0] = v297;
    goto v143;
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for embed!-null!-fn */

static Lisp_Object CC_embedKnullKfn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v294, v285, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for embed-null-fn");
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
    v285 = v0;
/* end of prologue */
    v294 = v285;
    if (!consp(v294)) { popv(5); return onevalue(v285); }
    v294 = v285;
    stack[-3] = v294;
    goto v234;

v234:
    v294 = stack[-3];
    if (v294 == nil) goto v187;
    v294 = stack[-3];
    v294 = qcar(v294);
    v153 = v294;
    v294 = v153;
    if (!consp(v294)) goto v180;
    v294 = v153;
    v285 = qcar(v294);
    v294 = elt(env, 2); /* null!-fn */
    if (v285 == v294) goto v115;
    v294 = v153;
    v294 = CC_embedKnullKfn(env, v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    v294 = ncons(v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    goto v230;

v230:
    stack[-2] = v294;
    v294 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v294 = (*qfn1(fn))(qenv(fn), v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    stack[-1] = v294;
    v294 = stack[-3];
    v294 = qcdr(v294);
    stack[-3] = v294;
    v294 = stack[-1];
    if (!consp(v294)) goto v234;
    else goto v69;

v69:
    v294 = stack[-3];
    if (v294 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v294 = stack[-3];
    v294 = qcar(v294);
    v153 = v294;
    v294 = v153;
    if (!consp(v294)) goto v235;
    v294 = v153;
    v285 = qcar(v294);
    v294 = elt(env, 2); /* null!-fn */
    if (v285 == v294) goto v282;
    v294 = v153;
    v294 = CC_embedKnullKfn(env, v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    v294 = ncons(v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    goto v108;

v108:
    v294 = Lrplacd(nil, stack[0], v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    v294 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v294 = (*qfn1(fn))(qenv(fn), v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    stack[-1] = v294;
    v294 = stack[-3];
    v294 = qcdr(v294);
    stack[-3] = v294;
    goto v69;

v282:
    v294 = v153;
    v294 = qcdr(v294);
    v294 = CC_embedKnullKfn(env, v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    goto v108;

v235:
    v294 = v153;
    v294 = ncons(v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    goto v108;

v115:
    v294 = v153;
    v294 = qcdr(v294);
    v294 = CC_embedKnullKfn(env, v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    goto v230;

v180:
    v294 = v153;
    v294 = ncons(v294);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-4];
    goto v230;

v187:
    v294 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v294); }
/* error exit handlers */
v196:
    popv(5);
    return nil;
}



/* Code for mk!-numr */

static Lisp_Object MS_CDECL CC_mkKnumr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v201, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk-numr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-numr");
#endif
    if (stack >= stacklimit)
    {
        push3(v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v95;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v183;

v183:
    v201 = stack[-1];
    v231 = stack[0];
    if (equal(v201, v231)) goto v134;
    v201 = stack[-1];
    v231 = (Lisp_Object)1; /* 0 */
    if (v201 == v231) goto v179;
    v202 = elt(env, 1); /* difference */
    v201 = stack[-2];
    v231 = stack[-1];
    v231 = list3(v202, v201, v231);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    v201 = v231;
    goto v67;

v67:
    v231 = stack[-3];
    v231 = cons(v201, v231);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    stack[-3] = v231;
    v231 = stack[-1];
    v231 = add1(v231);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-4];
    stack[-1] = v231;
    goto v183;

v179:
    v231 = stack[-2];
    v201 = v231;
    goto v67;

v134:
    v231 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v231);
    }
/* error exit handlers */
v159:
    popv(5);
    return nil;
}



/* Code for one!-entryp */

static Lisp_Object CC_oneKentryp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v178;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for one-entryp");
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

v74:
    v186 = stack[0];
    if (!consp(v186)) goto v119;
    v178 = stack[-1];
    v186 = stack[0];
    v186 = qcar(v186);
    v186 = Lsmemq(nil, v178, v186);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-2];
    if (v186 == nil) goto v121;
    v178 = stack[-1];
    v186 = stack[0];
    v186 = qcdr(v186);
    v186 = Lsmemq(nil, v178, v186);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-2];
    if (v186 == nil) goto v76;
    v186 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v186); }

v76:
    v186 = stack[0];
    v186 = qcar(v186);
    stack[0] = v186;
    goto v74;

v121:
    v186 = stack[0];
    v186 = qcdr(v186);
    stack[0] = v186;
    goto v74;

v119:
    v186 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v186); }
/* error exit handlers */
v222:
    popv(3);
    return nil;
}



/* Code for nzero */

static Lisp_Object CC_nzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzero");
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
    goto v134;

v134:
    v204 = stack[0];
    v179 = (Lisp_Object)1; /* 0 */
    if (v204 == v179) goto v119;
    v204 = (Lisp_Object)1; /* 0 */
    v179 = stack[-1];
    v179 = cons(v204, v179);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    stack[-1] = v179;
    v179 = stack[0];
    v179 = sub1(v179);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    stack[0] = v179;
    goto v134;

v119:
    v179 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v179);
    }
/* error exit handlers */
v113:
    popv(3);
    return nil;
}



/* Code for moid_member */

static Lisp_Object CC_moid_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moid_member");
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

v229:
    v204 = stack[0];
    if (v204 == nil) goto v74;
    v204 = stack[0];
    v164 = qcar(v204);
    v204 = stack[-1];
    fn = elt(env, 2); /* mo_vdivides!? */
    v204 = (*qfn2(fn))(qenv(fn), v164, v204);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    if (!(v204 == nil)) { popv(3); return onevalue(v204); }
    v164 = stack[-1];
    v204 = stack[0];
    v204 = qcdr(v204);
    stack[-1] = v164;
    stack[0] = v204;
    goto v229;

v74:
    v204 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v204); }
/* error exit handlers */
v114:
    popv(3);
    return nil;
}



/* Code for dv_ind2var */

static Lisp_Object CC_dv_ind2var(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_ind2var");
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
    stack[-1] = stack[0];
    v115 = qvalue(elt(env, 1)); /* g_dvnames */
    fn = elt(env, 3); /* upbve */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    v115 = (Lisp_Object)lesseq2(stack[-1], v115);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v115 = v115 ? lisp_true : nil;
    env = stack[-2];
    if (v115 == nil) goto v68;
    stack[-1] = qvalue(elt(env, 1)); /* g_dvnames */
    v115 = stack[0];
    v115 = sub1(v115);
    nil = C_nil;
    if (exception_pending()) goto v214;
    v115 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v115/(16/CELL)));
    { popv(3); return onevalue(v115); }

v68:
    v113 = qvalue(elt(env, 2)); /* g_dvbase */
    v115 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v113, v115);
    }
/* error exit handlers */
v214:
    popv(3);
    return nil;
}



/* Code for ratminus */

static Lisp_Object CC_ratminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v184, v185;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratminus");
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
    stack[0] = v0;
/* end of prologue */
    v184 = stack[0];
    v184 = qcar(v184);
    v185 = negate(v184);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v184 = stack[0];
    v184 = qcdr(v184);
    popv(1);
    return cons(v185, v184);
/* error exit handlers */
v69:
    popv(1);
    return nil;
}



/* Code for cl_flip */

static Lisp_Object CC_cl_flip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v197, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_flip");
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
    v198 = v0;
/* end of prologue */
    v197 = v198;
    v224 = elt(env, 1); /* and */
    if (v197 == v224) goto v101;
    v197 = v198;
    v224 = elt(env, 2); /* or */
    if (v197 == v224) goto v185;
    v197 = v198;
    v224 = elt(env, 3); /* all */
    if (v197 == v224) goto v166;
    v197 = v198;
    v224 = elt(env, 4); /* ex */
    if (v197 == v224) goto v115;
    v197 = v198;
    v224 = elt(env, 5); /* ball */
    if (v197 == v224) goto v77;
    v197 = v198;
    v224 = elt(env, 6); /* bex */
    if (v197 == v224) goto v111;
    v197 = v198;
    v224 = elt(env, 7); /* true */
    if (v197 == v224) goto v159;
    v197 = v198;
    v224 = elt(env, 8); /* false */
    if (v197 == v224) goto v61;
    v224 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v224 == nil)) goto v62;
    v224 = elt(env, 10); /* "cl_flip(): don't know" */
    v197 = v198;
    v224 = list2(v224, v197);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[0];
    fn = elt(env, 11); /* lprie */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v294;
    env = stack[0];
    goto v62;

v62:
    v224 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v294;
    v224 = nil;
    { popv(1); return onevalue(v224); }

v61:
    v224 = elt(env, 7); /* true */
    { popv(1); return onevalue(v224); }

v159:
    v224 = elt(env, 8); /* false */
    { popv(1); return onevalue(v224); }

v111:
    v224 = elt(env, 5); /* ball */
    { popv(1); return onevalue(v224); }

v77:
    v224 = elt(env, 6); /* bex */
    { popv(1); return onevalue(v224); }

v115:
    v224 = elt(env, 3); /* all */
    { popv(1); return onevalue(v224); }

v166:
    v224 = elt(env, 4); /* ex */
    { popv(1); return onevalue(v224); }

v185:
    v224 = elt(env, 1); /* and */
    { popv(1); return onevalue(v224); }

v101:
    v224 = elt(env, 2); /* or */
    { popv(1); return onevalue(v224); }
/* error exit handlers */
v294:
    popv(1);
    return nil;
}



/* Code for width */

static Lisp_Object CC_width(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v297, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for width");
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
    v297 = v0;
/* end of prologue */
    v219 = v297;
    v159 = elt(env, 1); /* textag */
    v159 = get(v219, v159);
    env = stack[-2];
    stack[-1] = v159;
    v159 = stack[-1];
    if (!(v159 == nil)) goto v66;
    v159 = elt(env, 2); /* "cannot find item " */
    v297 = list2(v159, v297);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v159 = elt(env, 3); /* fatal */
    fn = elt(env, 5); /* tri!-error */
    v159 = (*qfn2(fn))(qenv(fn), v297, v159);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    goto v66;

v66:
    v297 = stack[0];
    v159 = (Lisp_Object)1; /* 0 */
    v159 = (Lisp_Object)greaterp2(v297, v159);
    nil = C_nil;
    if (exception_pending()) goto v60;
    v159 = v159 ? lisp_true : nil;
    env = stack[-2];
    if (v159 == nil) goto v113;
    v159 = stack[-1];
    v159 = qcdr(v159);
    if (v159 == nil) goto v113;
    v159 = stack[-1];
    v159 = qcdr(v159);
    stack[-1] = v159;
    v159 = stack[0];
    v159 = sub1(v159);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    stack[0] = v159;
    goto v66;

v113:
    v159 = stack[-1];
    v159 = qcar(v159);
    if (!(v159 == nil)) { popv(3); return onevalue(v159); }
    v159 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v159); }
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for !*tayexp2q */

static Lisp_Object CC_Htayexp2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v180;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *tayexp2q");
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
    v180 = v230;
    if (!consp(v180)) goto v119;
    v230 = qcdr(v230);
    { popv(1); return onevalue(v230); }

v119:
    v180 = v230;
    v180 = (Lisp_Object)zerop(v180);
    v180 = v180 ? lisp_true : nil;
    env = stack[0];
    if (v180 == nil) goto v187;
    v230 = qvalue(elt(env, 1)); /* nil */
    v180 = v230;
    goto v134;

v134:
    v230 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v180, v230);

v187:
    v180 = v230;
    goto v134;
}



/* Code for mk!+trace */

static Lisp_Object CC_mkLtrace(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v90, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+trace");
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
    v161 = stack[-1];
    fn = elt(env, 6); /* squared!+matrix!+p */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    if (!(v161 == nil)) goto v165;
    v161 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v161 == nil)) goto v234;
    v161 = elt(env, 2); /* "no square matrix in add" */
    fn = elt(env, 7); /* lprie */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    goto v234;

v234:
    v161 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    goto v165;

v165:
    v90 = qvalue(elt(env, 3)); /* nil */
    v161 = (Lisp_Object)17; /* 1 */
    v161 = cons(v90, v161);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    stack[0] = v161;
    v161 = (Lisp_Object)17; /* 1 */
    stack[-2] = v161;
    goto v121;

v121:
    v161 = stack[-1];
    fn = elt(env, 8); /* get!+row!+nr */
    v90 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    v161 = stack[-2];
    v161 = difference2(v90, v161);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    v161 = Lminusp(nil, v161);
    env = stack[-3];
    if (v161 == nil) goto v201;
    v161 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v161; /* !*sub2 */
    v161 = stack[0];
    fn = elt(env, 9); /* subs2 */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    stack[0] = v161;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v201:
    v216 = stack[-1];
    v90 = stack[-2];
    v161 = stack[-2];
    fn = elt(env, 10); /* get!+mat!+entry */
    v161 = (*qfnn(fn))(qenv(fn), 3, v216, v90, v161);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    fn = elt(env, 11); /* addsq */
    v161 = (*qfn2(fn))(qenv(fn), stack[0], v161);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    stack[0] = v161;
    v161 = stack[-2];
    v161 = add1(v161);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-3];
    stack[-2] = v161;
    goto v121;
/* error exit handlers */
v200:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(4);
    return nil;
v199:
    popv(4);
    return nil;
}



/* Code for ibalp_var!-unset */

static Lisp_Object CC_ibalp_varKunset(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v304;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-unset");
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
    v303 = stack[-4];
    v304 = qcdr(v303);
    v303 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    v303 = stack[-4];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v304 = qcdr(v303);
    v303 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    v303 = stack[-4];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v304 = qcdr(v303);
    v303 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    v303 = stack[-4];
    v303 = qcar(v303);
    stack[-5] = v303;
    v304 = stack[-3];
    v303 = (Lisp_Object)17; /* 1 */
    v303 = Leqn(nil, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    if (v303 == nil) goto v297;
    v303 = stack[-4];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    goto v222;

v222:
    stack[-2] = v303;
    goto v61;

v61:
    v303 = stack[-2];
    if (v303 == nil) goto v170;
    v303 = stack[-2];
    v303 = qcar(v303);
    stack[-1] = v303;
    v304 = stack[-3];
    v303 = (Lisp_Object)17; /* 1 */
    v303 = Leqn(nil, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    if (v303 == nil) goto v57;
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    stack[0] = qcdr(v303);
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v303 = add1(v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    goto v104;

v104:
    v303 = stack[-2];
    v303 = qcdr(v303);
    stack[-2] = v303;
    goto v61;

v57:
    v303 = stack[-1];
    v303 = qcdr(v303);
    stack[0] = qcdr(v303);
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v303 = add1(v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    goto v104;

v170:
    v304 = stack[-3];
    v303 = (Lisp_Object)1; /* 0 */
    v303 = Leqn(nil, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    if (v303 == nil) goto v228;
    v303 = stack[-4];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    goto v190;

v190:
    v304 = v303;
    v303 = stack[-5];
    fn = elt(env, 3); /* ibalp_unvar!-unsatlist */
    v303 = (*qfn2(fn))(qenv(fn), v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    v303 = stack[-4];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    stack[0] = qcdr(v303);
    v303 = stack[-4];
    fn = elt(env, 4); /* ibalp_calcmom */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v281;
    v303 = nil;
    { popv(7); return onevalue(v303); }

v228:
    v303 = stack[-4];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    goto v190;

v297:
    v303 = stack[-4];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    goto v222;
/* error exit handlers */
v281:
    popv(7);
    return nil;
}



/* Code for ev_invlexcomp */

static Lisp_Object CC_ev_invlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_invlexcomp");
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

v229:
    v62 = stack[-1];
    if (v62 == nil) goto v119;
    v62 = stack[-1];
    v63 = qcar(v62);
    v62 = stack[0];
    v62 = qcar(v62);
    v62 = Leqn(nil, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    if (v62 == nil) goto v76;
    v62 = stack[-1];
    v63 = qcdr(v62);
    v62 = stack[0];
    v62 = qcdr(v62);
    stack[-1] = v63;
    stack[0] = v62;
    goto v229;

v76:
    v62 = stack[-1];
    v63 = qcdr(v62);
    v62 = stack[0];
    v62 = qcdr(v62);
    v62 = CC_ev_invlexcomp(env, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    stack[-2] = v62;
    v63 = stack[-2];
    v62 = (Lisp_Object)1; /* 0 */
    v62 = Leqn(nil, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    if (v62 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v62 = stack[0];
    v63 = qcar(v62);
    v62 = stack[-1];
    v62 = qcar(v62);
    v62 = Leqn(nil, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v155;
    if (v62 == nil) goto v169;
    v62 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v62); }

v169:
    v62 = stack[0];
    v63 = qcar(v62);
    v62 = stack[-1];
    v62 = qcar(v62);
    if (((int32_t)(v63)) > ((int32_t)(v62))) goto v90;
    v62 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v62); }

v90:
    v62 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v62); }

v119:
    v62 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v62); }
/* error exit handlers */
v155:
    popv(4);
    return nil;
}



/* Code for row */

static Lisp_Object CC_row(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for row");
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
    v69 = stack[0];
    if (v69 == nil) goto v74;
    v69 = stack[0];
    v69 = qcar(v69);
    fn = elt(env, 2); /* expression */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-1];
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = CC_row(env, v69);
    nil = C_nil;
    if (exception_pending()) goto v116;
    goto v74;

v74:
    v69 = nil;
    { popv(2); return onevalue(v69); }
/* error exit handlers */
v116:
    popv(2);
    return nil;
}



/* Code for evalvars */

static Lisp_Object CC_evalvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalvars");
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
    goto v74;

v74:
    v53 = stack[-1];
    if (v53 == nil) goto v119;
    v53 = stack[-1];
    v53 = qcar(v53);
    if (!consp(v53)) goto v181;
    v53 = stack[-1];
    v53 = qcar(v53);
    v55 = qcar(v53);
    v53 = elt(env, 1); /* intfn */
    v53 = Lflagp(nil, v55, v53);
    env = stack[-3];
    if (!(v53 == nil)) goto v181;
    v53 = stack[-1];
    v53 = qcar(v53);
    v55 = qcar(v53);
    v53 = elt(env, 2); /* rtype */
    v55 = get(v55, v53);
    env = stack[-3];
    v53 = elt(env, 3); /* setelemfn */
    v53 = get(v55, v53);
    env = stack[-3];
    if (v53 == nil) goto v122;
    v53 = stack[-1];
    v53 = qcar(v53);
    stack[0] = qcar(v53);
    v53 = stack[-1];
    v53 = qcar(v53);
    v53 = qcdr(v53);
    fn = elt(env, 4); /* revlis_without_mode */
    v55 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    v53 = stack[-2];
    v53 = acons(stack[0], v55, v53);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v53;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    goto v74;

v122:
    v53 = stack[-1];
    v53 = qcar(v53);
    stack[0] = qcar(v53);
    v53 = stack[-1];
    v53 = qcar(v53);
    v53 = qcdr(v53);
    fn = elt(env, 5); /* revlis */
    v55 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    v53 = stack[-2];
    v53 = acons(stack[0], v55, v53);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v53;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    goto v74;

v181:
    v53 = stack[-1];
    v55 = qcar(v53);
    v53 = stack[-2];
    v53 = cons(v55, v53);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v53;
    v53 = stack[-1];
    v53 = qcdr(v53);
    stack[-1] = v53;
    goto v74;

v119:
    v53 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v53);
    }
/* error exit handlers */
v103:
    popv(4);
    return nil;
}



/* Code for bcfd */

static Lisp_Object CC_bcfd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v111, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcfd");
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
    v64 = v0;
/* end of prologue */
    v110 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v110 == nil) goto v119;
    v110 = v64;
    v110 = integerp(v110);
    if (v110 == nil) goto v165;
    v110 = v64;
    {
        popv(1);
        fn = elt(env, 5); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v110);
    }

v165:
    v110 = v64;
    v111 = qcar(v110);
    v110 = elt(env, 2); /* !:mod!: */
    if (v111 == v110) goto v120;
    v110 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v110 == nil)) goto v115;
    v110 = elt(env, 4); /* "Invalid modular coefficient" */
    v111 = v64;
    v110 = list2(v110, v111);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[0];
    fn = elt(env, 6); /* lprie */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[0];
    goto v115;

v115:
    v110 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v220;
    v110 = nil;
    { popv(1); return onevalue(v110); }

v120:
    v110 = v64;
    v110 = qcdr(v110);
    {
        popv(1);
        fn = elt(env, 5); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v110);
    }

v119:
    v111 = v64;
    v110 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 7); /* mkbc */
        return (*qfn2(fn))(qenv(fn), v111, v110);
    }
/* error exit handlers */
v220:
    popv(1);
    return nil;
}



/* Code for dipprod */

static Lisp_Object CC_dipprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipprod");
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
    v113 = stack[-1];
    fn = elt(env, 1); /* diplength */
    stack[-2] = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v113 = stack[0];
    fn = elt(env, 1); /* diplength */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v113 = (Lisp_Object)lesseq2(stack[-2], v113);
    nil = C_nil;
    if (exception_pending()) goto v163;
    v113 = v113 ? lisp_true : nil;
    env = stack[-3];
    if (v113 == nil) goto v230;
    v114 = stack[-1];
    v113 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* dipprodin */
        return (*qfn2(fn))(qenv(fn), v114, v113);
    }

v230:
    v114 = stack[0];
    v113 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* dipprodin */
        return (*qfn2(fn))(qenv(fn), v114, v113);
    }
/* error exit handlers */
v163:
    popv(4);
    return nil;
}



/* Code for ordexp */

static Lisp_Object CC_ordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v203, v182, v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v203 = v1;
    v182 = v0;
/* end of prologue */

v74:
    v222 = v182;
    if (v222 == nil) goto v119;
    v222 = v182;
    v162 = qcar(v222);
    v222 = v203;
    v222 = qcar(v222);
    if (v162 == v222) goto v183;
    v222 = v182;
    v222 = qcar(v222);
    if (v222 == nil) goto v68;
    v222 = v203;
    v222 = qcar(v222);
    if (v222 == nil) goto v204;
    v222 = v182;
    v222 = qcar(v222);
    v203 = qcar(v203);
    {
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v222, v203);
    }

v204:
    v222 = qvalue(elt(env, 1)); /* t */
    return onevalue(v222);

v68:
    v222 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v222);

v183:
    v222 = v182;
    v222 = qcdr(v222);
    v182 = v222;
    v222 = v203;
    v222 = qcdr(v222);
    v203 = v222;
    goto v74;

v119:
    v222 = qvalue(elt(env, 1)); /* t */
    return onevalue(v222);
}



/* Code for partitexdf */

static Lisp_Object CC_partitexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitexdf");
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
    v143 = v0;
/* end of prologue */
    v143 = qcar(v143);
    fn = elt(env, 1); /* partitop */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* exdfpf */
        return (*qfn1(fn))(qenv(fn), v143);
    }
/* error exit handlers */
v140:
    popv(1);
    return nil;
}



/* Code for difference!: */

static Lisp_Object CC_differenceT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v78, v295;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference:");
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
    v295 = v0;
/* end of prologue */
    v39 = v295;
    v39 = qcdr(v39);
    v78 = qcar(v39);
    stack[-1] = v78;
    v39 = (Lisp_Object)1; /* 0 */
    if (v78 == v39) goto v166;
    v39 = stack[-2];
    v39 = qcdr(v39);
    v78 = qcar(v39);
    stack[0] = v78;
    v39 = (Lisp_Object)1; /* 0 */
    if (v78 == v39) { popv(6); return onevalue(v295); }
    v39 = v295;
    v39 = qcdr(v39);
    v78 = qcdr(v39);
    stack[-4] = v78;
    v39 = stack[-2];
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    stack[-2] = v39;
    v78 = difference2(v78, v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-5];
    stack[-3] = v78;
    v39 = (Lisp_Object)1; /* 0 */
    if (v78 == v39) goto v160;
    v78 = stack[-3];
    v39 = (Lisp_Object)1; /* 0 */
    v39 = (Lisp_Object)greaterp2(v78, v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    v39 = v39 ? lisp_true : nil;
    env = stack[-5];
    if (v39 == nil) goto v123;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v78 = stack[-1];
    v39 = stack[-3];
    v78 = Lash1(nil, v78, v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-5];
    v39 = stack[0];
    v78 = difference2(v78, v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    v39 = stack[-2];
    {
        Lisp_Object v48 = stack[-4];
        popv(6);
        return list2star(v48, v78, v39);
    }

v123:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v39 = stack[-3];
    v39 = negate(v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-5];
    v39 = Lash1(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    env = stack[-5];
    v78 = difference2(stack[-1], v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    v39 = stack[-4];
    {
        Lisp_Object v38 = stack[-2];
        popv(6);
        return list2star(v38, v78, v39);
    }

v160:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v78 = stack[-1];
    v39 = stack[0];
    v78 = difference2(v78, v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    v39 = stack[-4];
    {
        Lisp_Object v175 = stack[-2];
        popv(6);
        return list2star(v175, v78, v39);
    }

v166:
    stack[0] = elt(env, 1); /* !:rd!: */
    v39 = stack[-2];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v78 = negate(v39);
    nil = C_nil;
    if (exception_pending()) goto v299;
    v39 = stack[-2];
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    {
        Lisp_Object v192 = stack[0];
        popv(6);
        return list2star(v192, v78, v39);
    }
/* error exit handlers */
v299:
    popv(6);
    return nil;
}



/* Code for gparg1p */

static Lisp_Object CC_gparg1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gparg1p");
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

v229:
    v187 = stack[0];
    v187 = (v187 == nil ? lisp_true : nil);
    if (!(v187 == nil)) { popv(2); return onevalue(v187); }
    v187 = stack[0];
    v187 = qcar(v187);
    fn = elt(env, 2); /* gpargp */
    v187 = (*qfn1(fn))(qenv(fn), v187);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-1];
    if (v187 == nil) goto v75;
    v187 = stack[0];
    v187 = qcdr(v187);
    stack[0] = v187;
    goto v229;

v75:
    v187 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v187); }
/* error exit handlers */
v212:
    popv(2);
    return nil;
}



/* Code for permp */

static Lisp_Object CC_permp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v110, v111, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for permp");
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
    v110 = v1;
    v111 = v0;
/* end of prologue */

v74:
    v162 = v111;
    if (v162 == nil) goto v119;
    v162 = v111;
    v64 = qcar(v162);
    v162 = v110;
    v162 = qcar(v162);
    if (equal(v64, v162)) goto v183;
    v162 = v111;
    stack[0] = qcdr(v162);
    v162 = v110;
    v162 = qcar(v162);
    v111 = qcar(v111);
    v110 = qcdr(v110);
    v162 = Lsubst(nil, 3, v162, v111, v110);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-1];
    v162 = CC_permp(env, stack[0], v162);
    nil = C_nil;
    if (exception_pending()) goto v231;
    v162 = (v162 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v162); }

v183:
    v162 = v111;
    v162 = qcdr(v162);
    v111 = v162;
    v162 = v110;
    v162 = qcdr(v162);
    v110 = v162;
    goto v74;

v119:
    v162 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v162); }
/* error exit handlers */
v231:
    popv(2);
    return nil;
}



/* Code for ordop2 */

static Lisp_Object CC_ordop2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v178, v177, v120, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v120 = v1;
    v222 = v0;
/* end of prologue */
    v186 = qvalue(elt(env, 1)); /* kord!* */
    v177 = v186;
    goto v143;

v143:
    v186 = v177;
    if (v186 == nil) goto v185;
    v178 = v222;
    v186 = v177;
    v186 = qcar(v186);
    if (v178 == v186) goto v213;
    v178 = v120;
    v186 = v177;
    v186 = qcar(v186);
    if (v178 == v186) goto v204;
    v186 = v177;
    v186 = qcdr(v186);
    v177 = v186;
    goto v143;

v204:
    v186 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v186);

v213:
    v186 = qvalue(elt(env, 2)); /* t */
    return onevalue(v186);

v185:
    v186 = v222;
    v178 = v120;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v186, v178);
    }
}



/* Code for lastcar */

static Lisp_Object CC_lastcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v212;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lastcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v213 = v0;
/* end of prologue */

v101:
    v212 = v213;
    if (v212 == nil) goto v140;
    v212 = v213;
    v212 = qcdr(v212);
    if (v212 == nil) goto v171;
    v213 = qcdr(v213);
    goto v101;

v171:
    v213 = qcar(v213);
    return onevalue(v213);

v140:
    v213 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v213);
}



/* Code for red_topredbe */

static Lisp_Object CC_red_topredbe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_topredbe");
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
    v108 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    if (v108 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v108 = stack[-2];
    if (v108 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    fn = elt(env, 4); /* cali_trace */
    v160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v108 = (Lisp_Object)1265; /* 79 */
    v108 = (Lisp_Object)greaterp2(v160, v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v108 = v108 ? lisp_true : nil;
    env = stack[-4];
    if (v108 == nil) goto v215;
    v108 = elt(env, 1); /* " reduce " */
    v108 = Lprinc(nil, v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v108 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    fn = elt(env, 5); /* dp_print */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    goto v215;

v215:
    v108 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v160 = v108;
    if (v108 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    stack[-3] = stack[-2];
    v108 = v160;
    fn = elt(env, 6); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v108 = stack[-1];
    fn = elt(env, 7); /* bas_dpecart */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    fn = elt(env, 8); /* red_divtestbe */
    v160 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    v108 = v160;
    if (v160 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v160 = stack[-1];
    fn = elt(env, 9); /* red_subst */
    v108 = (*qfn2(fn))(qenv(fn), v160, v108);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-4];
    stack[-1] = v108;
    goto v215;
/* error exit handlers */
v216:
    popv(5);
    return nil;
}



setup_type const u22_setup[] =
{
    {"quotof",                  too_few_2,      CC_quotof,     wrong_no_2},
    {"ilog2",                   CC_ilog2,       too_many_1,    wrong_no_1},
    {"difbf",                   too_few_2,      CC_difbf,      wrong_no_2},
    {"drnconv",                 CC_drnconv,     too_many_1,    wrong_no_1},
    {"get*elements",            CC_getHelements,too_many_1,    wrong_no_1},
    {"qqe_arg-check-q",         CC_qqe_argKcheckKq,too_many_1, wrong_no_1},
    {"pasf_subfof1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_subfof1},
    {"ibalp_negatet",           CC_ibalp_negatet,too_many_1,   wrong_no_1},
    {"bvarml",                  CC_bvarml,      too_many_1,    wrong_no_1},
    {"ps:expansion-point",      CC_psTexpansionKpoint,too_many_1,wrong_no_1},
    {"recaliasbacksubst",       too_few_2,      CC_recaliasbacksubst,wrong_no_2},
    {"meq",                     too_few_2,      CC_meq,        wrong_no_2},
    {"groedeletip",             too_few_2,      CC_groedeletip,wrong_no_2},
    {"vdpsave",                 CC_vdpsave,     too_many_1,    wrong_no_1},
    {"testchar1",               CC_testchar1,   too_many_1,    wrong_no_1},
    {"physopordchk*",           too_few_2,      CC_physopordchkH,wrong_no_2},
    {"rnprep:",                 CC_rnprepT,     too_many_1,    wrong_no_1},
    {"super_der_simp",          CC_super_der_simp,too_many_1,  wrong_no_1},
    {"ofsf_entry2at1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at1},
    {"wusort",                  CC_wusort,      too_many_1,    wrong_no_1},
    {"smemberlp",               too_few_2,      CC_smemberlp,  wrong_no_2},
    {"simpexpt11",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt11},
    {"get-denom-l",             CC_getKdenomKl, too_many_1,    wrong_no_1},
    {"ibalp_readform",          CC_ibalp_readform,too_many_1,  wrong_no_1},
    {"numpoly_lc",              CC_numpoly_lc,  too_many_1,    wrong_no_1},
    {"encodeir",                CC_encodeir,    too_many_1,    wrong_no_1},
    {"insoccs",                 too_few_2,      CC_insoccs,    wrong_no_2},
    {"embed-null-fn",           CC_embedKnullKfn,too_many_1,   wrong_no_1},
    {"mk-numr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKnumr},
    {"one-entryp",              too_few_2,      CC_oneKentryp, wrong_no_2},
    {"nzero",                   CC_nzero,       too_many_1,    wrong_no_1},
    {"moid_member",             too_few_2,      CC_moid_member,wrong_no_2},
    {"dv_ind2var",              CC_dv_ind2var,  too_many_1,    wrong_no_1},
    {"ratminus",                CC_ratminus,    too_many_1,    wrong_no_1},
    {"cl_flip",                 CC_cl_flip,     too_many_1,    wrong_no_1},
    {"width",                   too_few_2,      CC_width,      wrong_no_2},
    {"*tayexp2q",               CC_Htayexp2q,   too_many_1,    wrong_no_1},
    {"mk+trace",                CC_mkLtrace,    too_many_1,    wrong_no_1},
    {"ibalp_var-unset",         too_few_2,      CC_ibalp_varKunset,wrong_no_2},
    {"ev_invlexcomp",           too_few_2,      CC_ev_invlexcomp,wrong_no_2},
    {"row",                     CC_row,         too_many_1,    wrong_no_1},
    {"evalvars",                CC_evalvars,    too_many_1,    wrong_no_1},
    {"bcfd",                    CC_bcfd,        too_many_1,    wrong_no_1},
    {"dipprod",                 too_few_2,      CC_dipprod,    wrong_no_2},
    {"ordexp",                  too_few_2,      CC_ordexp,     wrong_no_2},
    {"partitexdf",              CC_partitexdf,  too_many_1,    wrong_no_1},
    {"difference:",             too_few_2,      CC_differenceT,wrong_no_2},
    {"gparg1p",                 CC_gparg1p,     too_many_1,    wrong_no_1},
    {"permp",                   too_few_2,      CC_permp,      wrong_no_2},
    {"ordop2",                  too_few_2,      CC_ordop2,     wrong_no_2},
    {"lastcar",                 CC_lastcar,     too_many_1,    wrong_no_1},
    {"red_topredbe",            too_few_2,      CC_red_topredbe,wrong_no_2},
    {NULL, (one_args *)"u22", (two_args *)"5005 4938750 7156399", 0}
};

/* end of generated code */
