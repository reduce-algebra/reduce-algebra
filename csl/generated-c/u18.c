
/* $destdir\u18.c        Machine generated C code */

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


/* Code for ps!:evaluate!-next */

static Lisp_Object CC_psTevaluateKnext(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate-next");
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
    stack[-2] = v1;
    v17 = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v17; /* ps */
    v18 = qvalue(elt(env, 1)); /* ps */
    v17 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 3); /* ps!:getv */
    v17 = (*qfn2(fn))(qenv(fn), v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    v18 = qcar(v17);
    v17 = elt(env, 2); /* ps!:erule */
    stack[0] = get(v18, v17);
    env = stack[-4];
    v17 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:expression */
    v18 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    v17 = stack[-2];
    v17 = list2(v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    fn = elt(env, 5); /* apply */
    v17 = (*qfn2(fn))(qenv(fn), stack[0], v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    stack[-1] = v17;
    stack[0] = qvalue(elt(env, 1)); /* ps */
    v17 = stack[-1];
    fn = elt(env, 6); /* prepsqxx */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    fn = elt(env, 7); /* simp!* */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    stack[-1] = v17;
    fn = elt(env, 8); /* ps!:set!-term */
    v17 = (*qfnn(fn))(qenv(fn), 3, stack[0], stack[-2], v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-4];
    v17 = stack[-1];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v17); }
/* error exit handlers */
v19:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for lid */

static Lisp_Object CC_lid(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lid");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v20;
/* end of prologue */
    v22 = v21;
    if (!consp(v22)) return onevalue(v21);
    v21 = qcar(v21);
    return onevalue(v21);
}



/* Code for indord2 */

static Lisp_Object CC_indord2(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indord2");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v20;
/* end of prologue */
    v26 = stack[-1];
    v10 = stack[0];
    fn = elt(env, 1); /* indordp */
    v10 = (*qfn2(fn))(qenv(fn), v26, v10);
    nil = C_nil;
    if (exception_pending()) goto v27;
    if (v10 == nil) goto v28;
    v26 = stack[-1];
    v10 = stack[0];
    popv(2);
    return list2(v26, v10);

v28:
    v26 = stack[0];
    v10 = stack[-1];
    popv(2);
    return list2(v26, v10);
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for quotfail1 */

static Lisp_Object MS_CDECL CC_quotfail1(Lisp_Object env, int nargs,
                         Lisp_Object v20, Lisp_Object v0,
                         Lisp_Object v1, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v26, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "quotfail1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail1");
#endif
    if (stack >= stacklimit)
    {
        push3(v1,v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v20,v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v26 = v0;
    v29 = v20;
/* end of prologue */
    v10 = v29;
    if (v10 == nil) goto v30;
    v10 = v29;
    fn = elt(env, 2); /* quotf */
    v10 = (*qfn2(fn))(qenv(fn), v10, v26);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    v26 = v10;
    v10 = v26;
    if (!(v10 == nil)) { popv(2); return onevalue(v26); }
    v10 = stack[0];
    fn = elt(env, 3); /* errorf */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v27;
    v10 = nil;
    { popv(2); return onevalue(v10); }

v30:
    v10 = qvalue(elt(env, 1)); /* polyzero */
    { popv(2); return onevalue(v10); }
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for my_freeof */

static Lisp_Object CC_my_freeof(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my_freeof");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v20;
/* end of prologue */
    v16 = stack[0];
    v15 = stack[-1];
    fn = elt(env, 3); /* smember */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    if (v15 == nil) goto v33;
    v15 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v15); }

v33:
    v13 = qvalue(elt(env, 2)); /* depl!* */
    v16 = stack[-1];
    v15 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeofdepl */
        return (*qfnn(fn))(qenv(fn), 3, v13, v16, v15);
    }
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for physopsm!* */

static Lisp_Object CC_physopsmH(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v74, v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsm*");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v20;
/* end of prologue */
    stack[0] = nil;
    v73 = stack[-3];
    if (v73 == nil) goto v77;
    v73 = stack[-3];
    if (is_number(v73)) goto v77;
    v73 = stack[-3];
    fn = elt(env, 13); /* physopp */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    if (v73 == nil) goto v33;
    v74 = stack[-3];
    v73 = elt(env, 1); /* rvalue */
    v73 = get(v74, v73);
    env = stack[-5];
    stack[-1] = v73;
    if (v73 == nil) goto v79;
    v73 = stack[-1];
    fn = elt(env, 14); /* physopaeval */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    goto v80;

v80:
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v79:
    v73 = stack[-3];
    if (symbolp(v73)) goto v81;
    v73 = stack[-3];
    v74 = qcar(v73);
    v73 = elt(env, 2); /* psimpfn */
    v73 = get(v74, v73);
    env = stack[-5];
    stack[-1] = v73;
    if (v73 == nil) goto v82;
    v74 = stack[-1];
    v73 = stack[-3];
    v73 = Lapply1(nil, v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    goto v80;

v82:
    v73 = stack[-3];
    v74 = qcar(v73);
    v73 = elt(env, 3); /* opmtch */
    v73 = get(v74, v73);
    env = stack[-5];
    if (v73 == nil) goto v83;
    v73 = stack[-3];
    fn = elt(env, 15); /* opmtch!* */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    stack[-1] = v73;
    if (v73 == nil) goto v83;
    v73 = stack[-1];
    goto v80;

v83:
    v73 = stack[-3];
    goto v80;

v81:
    v73 = stack[-3];
    goto v80;

v33:
    v73 = stack[-3];
    if (!consp(v73)) goto v84;
    v73 = stack[-3];
    v73 = qcar(v73);
    stack[-4] = v73;
    v73 = stack[-3];
    v73 = qcdr(v73);
    stack[-2] = v73;
    v74 = stack[-4];
    v73 = elt(env, 4); /* physopfunction */
    v73 = get(v74, v73);
    env = stack[-5];
    stack[-1] = v73;
    if (v73 == nil) goto v85;
    v74 = stack[-4];
    v73 = elt(env, 5); /* physoparith */
    v73 = Lflagp(nil, v74, v73);
    env = stack[-5];
    if (v73 == nil) goto v86;
    v73 = stack[-2];
    fn = elt(env, 16); /* hasonephysop */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    if (v73 == nil) goto v87;
    stack[0] = stack[-1];
    v73 = stack[-2];
    v73 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v73 = (*qfn2(fn))(qenv(fn), stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v87:
    v74 = stack[-4];
    v73 = stack[-2];
    v73 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    fn = elt(env, 18); /* reval3 */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v86:
    v74 = stack[-4];
    v73 = elt(env, 6); /* physopfn */
    v73 = Lflagp(nil, v74, v73);
    env = stack[-5];
    if (v73 == nil) goto v88;
    v73 = stack[-2];
    fn = elt(env, 19); /* areallphysops */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    if (v73 == nil) goto v89;
    stack[0] = stack[-1];
    v73 = stack[-2];
    v73 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v73 = (*qfn2(fn))(qenv(fn), stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v89:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v76 = elt(env, 7); /* "invalid call of " */
    v75 = stack[-4];
    v74 = elt(env, 8); /* " with args: " */
    v73 = stack[-2];
    v73 = list4(v76, v75, v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v73 = (*qfn2(fn))(qenv(fn), stack[-1], v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v88:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v75 = stack[-4];
    v74 = elt(env, 9); /* " has been flagged Physopfunction" */
    v73 = elt(env, 10); /* " but is not defined" */
    v73 = list3(v75, v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v73 = (*qfn2(fn))(qenv(fn), stack[-1], v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v85:
    v74 = stack[-4];
    v73 = elt(env, 11); /* physopmapping */
    v73 = Lflagp(nil, v74, v73);
    env = stack[-5];
    if (v73 == nil) goto v90;
    v73 = stack[-2];
    fn = elt(env, 21); /* !*physopp!* */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    if (v73 == nil) goto v90;
    v74 = stack[-4];
    v73 = stack[-2];
    v75 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v74 = (Lisp_Object)17; /* 1 */
    v73 = (Lisp_Object)17; /* 1 */
    v73 = acons(v75, v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v74 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v73 = (Lisp_Object)17; /* 1 */
    v73 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    fn = elt(env, 22); /* mk!*sq */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v90:
    v74 = stack[-4];
    v73 = elt(env, 12); /* prog */
    if (v74 == v73) goto v91;
    v73 = stack[-3];
    fn = elt(env, 23); /* aeval */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v91:
    v73 = stack[-2];
    fn = elt(env, 24); /* physopprog */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v84:
    v73 = stack[-3];
    fn = elt(env, 23); /* aeval */
    v73 = (*qfn1(fn))(qenv(fn), v73);
    nil = C_nil;
    if (exception_pending()) goto v78;
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v77:
    v73 = stack[-3];
    stack[0] = v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
/* error exit handlers */
v78:
    popv(6);
    return nil;
}



/* Code for setk */

static Lisp_Object CC_setk(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setk");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    v106 = v20;
/* end of prologue */
    v105 = v106;
    if (!consp(v105)) goto v108;
    v105 = v106;
    v107 = qcar(v105);
    v105 = elt(env, 1); /* evalargfn */
    v105 = get(v107, v105);
    env = stack[-2];
    v107 = v105;
    v105 = v107;
    if (v105 == nil) goto v109;
    v105 = v106;
    stack[-1] = qcar(v105);
    v105 = v107;
    v106 = qcdr(v106);
    v105 = Lapply1(nil, v105, v106);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v106 = cons(stack[-1], v105);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v105 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v106, v105);
    }

v109:
    v105 = v106;
    v107 = qcar(v105);
    v105 = elt(env, 2); /* rtype */
    v107 = get(v107, v105);
    env = stack[-2];
    v105 = elt(env, 3); /* matrix */
    if (v107 == v105) goto v111;
    v105 = v106;
    stack[-1] = qcar(v105);
    v105 = v106;
    v105 = qcdr(v105);
    fn = elt(env, 5); /* revlis */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v106 = cons(stack[-1], v105);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v105 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v106, v105);
    }

v111:
    v105 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v106, v105);
    }

v108:
    v105 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v106, v105);
    }
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



/* Code for mv!-domainlist */

static Lisp_Object CC_mvKdomainlist(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v32 = nil;
    goto v2;

v2:
    v31 = stack[0];
    if (v31 == nil) goto v8;
    v31 = stack[0];
    v31 = qcar(v31);
    v31 = qcdr(v31);
    v31 = cons(v31, v32);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v32 = v31;
    v31 = stack[0];
    v31 = qcdr(v31);
    stack[0] = v31;
    goto v2;

v8:
    v31 = v32;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v31);
    }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for addgt */

static Lisp_Object CC_addgt(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addgt");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v10 = qvalue(elt(env, 1)); /* ordering */
    v14 = elt(env, 2); /* lex */
    if (v10 == v14) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v10 = elt(env, 3); /* plus */
    v14 = stack[0];
    v14 = cons(v10, v14);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    fn = elt(env, 4); /* eval */
    v10 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v14 = stack[0];
    popv(2);
    return cons(v10, v14);
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for st_consolidate */

static Lisp_Object CC_st_consolidate(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_consolidate");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v20;
/* end of prologue */
    stack[-1] = nil;
    v121 = stack[-3];
    if (v121 == nil) goto v4;
    v121 = stack[-3];
    v121 = qcdr(v121);
    v121 = qcar(v121);
    if (is_number(v121)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v121 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v121;
    v121 = stack[-3];
    v121 = qcdr(v121);
    v121 = Lreverse(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-5];
    stack[0] = v121;
    goto v79;

v79:
    v121 = stack[0];
    if (v121 == nil) goto v112;
    v121 = stack[0];
    v121 = qcar(v121);
    v121 = CC_st_consolidate(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-5];
    v122 = v121;
    if (v122 == nil) goto v12;
    v122 = v121;
    v122 = qcdr(v122);
    v122 = qcdr(v122);
    if (v122 == nil) goto v17;
    v122 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v122;
    goto v124;

v124:
    v122 = v121;
    v121 = stack[-1];
    v121 = cons(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-5];
    stack[-1] = v121;
    goto v12;

v12:
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v79;

v17:
    v122 = elt(env, 3); /* !* */
    v121 = qcdr(v121);
    v121 = qcar(v121);
    v121 = list2(v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-5];
    goto v124;

v112:
    v121 = stack[-1];
    if (v121 == nil) goto v60;
    v121 = stack[-1];
    v121 = qcdr(v121);
    if (v121 == nil) goto v125;
    v121 = stack[-2];
    if (v121 == nil) goto v126;
    v121 = stack[-1];
    stack[-4] = v121;
    v121 = stack[-4];
    if (v121 == nil) goto v107;
    v121 = stack[-4];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v121 = qcar(v121);
    v121 = ncons(v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-5];
    stack[-1] = v121;
    stack[-2] = v121;
    goto v68;

v68:
    v121 = stack[-4];
    v121 = qcdr(v121);
    stack[-4] = v121;
    v121 = stack[-4];
    if (v121 == nil) goto v127;
    stack[0] = stack[-1];
    v121 = stack[-4];
    v121 = qcar(v121);
    v121 = qcdr(v121);
    v121 = qcar(v121);
    v121 = ncons(v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-5];
    v121 = Lrplacd(nil, stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-5];
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v68;

v127:
    v121 = stack[-2];
    goto v67;

v67:
    stack[-1] = v121;
    goto v126;

v126:
    v121 = stack[-3];
    v122 = qcar(v121);
    v121 = stack[-1];
    popv(6);
    return cons(v122, v121);

v107:
    v121 = qvalue(elt(env, 1)); /* nil */
    goto v67;

v125:
    v121 = stack[-1];
    v121 = qcar(v121);
    { popv(6); return onevalue(v121); }

v60:
    v121 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v121); }

v4:
    v121 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v121); }
/* error exit handlers */
v123:
    popv(6);
    return nil;
}



/* Code for arplus!: */

static Lisp_Object CC_arplusT(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v28, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v28 = v0;
    v31 = v20;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v79 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v79; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v79 = v31;
    v79 = qcdr(v79);
    v28 = qcdr(v28);
    fn = elt(env, 5); /* addf */
    v79 = (*qfn2(fn))(qenv(fn), v79, v28);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    v79 = cons(stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v79); }
/* error exit handlers */
v13:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for reverse!-num */

static Lisp_Object CC_reverseKnum(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reverse-num");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v7 = stack[0];
    v72 = (Lisp_Object)1; /* 0 */
    if (v7 == v72) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v7 = stack[0];
    v72 = (Lisp_Object)1; /* 0 */
    v72 = (Lisp_Object)lessp2(v7, v72);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v72 = v72 ? lisp_true : nil;
    env = stack[-2];
    if (v72 == nil) goto v129;
    v72 = stack[0];
    stack[-1] = negate(v72);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v72 = stack[0];
    v72 = negate(v72);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    fn = elt(env, 1); /* ilog2 */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    fn = elt(env, 2); /* reverse!-num1 */
    v72 = (*qfn2(fn))(qenv(fn), stack[-1], v72);
    nil = C_nil;
    if (exception_pending()) goto v128;
    popv(3);
    return negate(v72);

v129:
    stack[-1] = stack[0];
    v72 = stack[0];
    fn = elt(env, 1); /* ilog2 */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    {
        Lisp_Object v98 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* reverse!-num1 */
        return (*qfn2(fn))(qenv(fn), v98, v72);
    }
/* error exit handlers */
v128:
    popv(3);
    return nil;
}



/* Code for sq2sstm */

static Lisp_Object CC_sq2sstm(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sstm");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0;
    v136 = v20;
/* end of prologue */
    v106 = v136;
    v106 = qcar(v106);
    v107 = qcar(v106);
    v106 = stack[-2];
    v106 = qcar(v106);
    v106 = qcar(v106);
    if (equal(v107, v106)) goto v137;
    v106 = v136;
    stack[-1] = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v106 = stack[-2];
    v106 = qcar(v106);
    stack[0] = qcdr(v106);
    v106 = stack[-2];
    v106 = qcdr(v106);
    v106 = sub1(v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v106 = cons(stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    fn = elt(env, 1); /* sq2sscfpl */
    v106 = (*qfn2(fn))(qenv(fn), stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v107 = (Lisp_Object)1; /* 0 */
    stack[-3] = v107;
    goto v118;

v118:
    v107 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* mapins */
        return (*qfn2(fn))(qenv(fn), v107, v106);
    }

v137:
    v106 = v136;
    v106 = qcdr(v106);
    stack[0] = v106;
    v106 = v136;
    v106 = qcar(v106);
    v106 = qcdr(v106);
    stack[-3] = v106;
    v106 = stack[0];
    if (!consp(v106)) goto v11;
    v106 = stack[0];
    v106 = qcar(v106);
    if (!consp(v106)) goto v11;
    stack[-1] = stack[0];
    v106 = stack[-2];
    v106 = qcar(v106);
    stack[0] = qcdr(v106);
    v106 = stack[-2];
    v106 = qcdr(v106);
    v106 = sub1(v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v106 = cons(stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    fn = elt(env, 1); /* sq2sscfpl */
    v106 = (*qfn2(fn))(qenv(fn), stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    goto v118;

v11:
    stack[-1] = stack[-3];
    v106 = stack[-2];
    v106 = qcdr(v106);
    fn = elt(env, 3); /* mkzl */
    v107 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-4];
    v106 = stack[0];
    v106 = acons(stack[-1], v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v138;
    popv(5);
    return ncons(v106);
/* error exit handlers */
v138:
    popv(5);
    return nil;
}



/* Code for ibalp_readclause */

static Lisp_Object CC_ibalp_readclause(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v164, v165, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_readclause");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0;
    v163 = v20;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v163 = qcdr(v163);
    stack[-4] = v163;
    stack[-5] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 1)); /* nil */
    stack[0] = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)1; /* 0 */
    v165 = qvalue(elt(env, 1)); /* nil */
    v164 = qvalue(elt(env, 1)); /* nil */
    v163 = qvalue(elt(env, 1)); /* nil */
    v163 = list4(v166, v165, v164, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    v163 = list3star(stack[-5], stack[-1], stack[0], v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    stack[-5] = v163;
    v163 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v163;
    goto v102;

v102:
    v163 = stack[-1];
    if (v163 == nil) goto v168;
    v163 = stack[-4];
    if (v163 == nil) goto v168;
    v163 = stack[-4];
    v163 = qcar(v163);
    stack[-8] = v163;
    v164 = stack[-8];
    v163 = elt(env, 3); /* true */
    if (v164 == v163) goto v132;
    v163 = stack[-4];
    v163 = qcdr(v163);
    stack[-4] = v163;
    v164 = stack[-8];
    v163 = elt(env, 4); /* false */
    if (v164 == v163) goto v102;
    v163 = stack[-8];
    if (!consp(v163)) goto v117;
    v163 = stack[-8];
    v163 = qcar(v163);
    v164 = v163;
    goto v131;

v131:
    v163 = elt(env, 5); /* not */
    if (v164 == v163) goto v169;
    v163 = stack[-8];
    fn = elt(env, 6); /* ibalp_arg2l */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    stack[-6] = v163;
    v163 = stack[-8];
    fn = elt(env, 7); /* ibalp_arg2r */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    goto v116;

v116:
    v164 = v163;
    v163 = (Lisp_Object)17; /* 1 */
    v163 = Leqn(nil, v164, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    if (v163 == nil) goto v170;
    v164 = stack[-6];
    v163 = stack[-3];
    v163 = Lmemq(nil, v164, v163);
    if (!(v163 == nil)) goto v102;
    v163 = stack[-5];
    v163 = qcdr(v163);
    stack[0] = qcdr(v163);
    v163 = stack[-5];
    v163 = qcdr(v163);
    v163 = qcdr(v163);
    v163 = qcar(v163);
    v163 = add1(v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    fn = elt(env, 8); /* setcar */
    v163 = (*qfn2(fn))(qenv(fn), stack[0], v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    v164 = stack[-6];
    v163 = stack[-3];
    v163 = cons(v164, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    stack[-3] = v163;
    v166 = stack[-5];
    v165 = stack[-7];
    v164 = stack[-6];
    v163 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 9); /* ibalp_process!-var */
    v163 = (*qfnn(fn))(qenv(fn), 4, v166, v165, v164, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    stack[-7] = v163;
    goto v102;

v170:
    v164 = stack[-6];
    v163 = stack[-2];
    v163 = Lmemq(nil, v164, v163);
    if (!(v163 == nil)) goto v102;
    v163 = stack[-5];
    v163 = qcdr(v163);
    v163 = qcdr(v163);
    stack[0] = qcdr(v163);
    v163 = stack[-5];
    v163 = qcdr(v163);
    v163 = qcdr(v163);
    v163 = qcdr(v163);
    v163 = qcar(v163);
    v163 = add1(v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    fn = elt(env, 8); /* setcar */
    v163 = (*qfn2(fn))(qenv(fn), stack[0], v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    v164 = stack[-6];
    v163 = stack[-2];
    v163 = cons(v164, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    stack[-2] = v163;
    v166 = stack[-5];
    v165 = stack[-7];
    v164 = stack[-6];
    v163 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 9); /* ibalp_process!-var */
    v163 = (*qfnn(fn))(qenv(fn), 4, v166, v165, v164, v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    stack[-7] = v163;
    goto v102;

v169:
    v163 = stack[-8];
    v163 = qcdr(v163);
    v163 = qcar(v163);
    fn = elt(env, 6); /* ibalp_arg2l */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    stack[-6] = v163;
    stack[0] = (Lisp_Object)17; /* 1 */
    v163 = stack[-8];
    v163 = qcdr(v163);
    v163 = qcar(v163);
    fn = elt(env, 7); /* ibalp_arg2r */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[-9];
    v163 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v163 + TAG_FIXNUM);
    goto v116;

v117:
    v163 = stack[-8];
    v164 = v163;
    goto v131;

v132:
    v163 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v163;
    goto v102;

v168:
    v163 = stack[-1];
    if (v163 == nil) goto v42;
    v164 = stack[-5];
    v163 = stack[-7];
    popv(10);
    return cons(v164, v163);

v42:
    v164 = elt(env, 3); /* true */
    v163 = stack[-7];
    popv(10);
    return cons(v164, v163);
/* error exit handlers */
v167:
    popv(10);
    return nil;
}



/* Code for rd!:prep */

static Lisp_Object CC_rdTprep(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:prep");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v20;
/* end of prologue */
    v185 = qvalue(elt(env, 1)); /* !*noconvert */
    if (v185 == nil) goto v2;
    v185 = stack[-1];
    v185 = qcdr(v185);
    if (!consp(v185)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v151 = stack[-1];
    v185 = qvalue(elt(env, 2)); /* !:bprec!: */
    {
        popv(4);
        fn = elt(env, 7); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v151, v185);
    }

v2:
    v185 = stack[-1];
    v185 = qcdr(v185);
    if (!consp(v185)) goto v129;
    stack[-2] = qvalue(elt(env, 5)); /* bfone!* */
    stack[0] = stack[-1];
    v151 = qvalue(elt(env, 2)); /* !:bprec!: */
    v185 = (Lisp_Object)49; /* 3 */
    v185 = difference2(v151, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 7); /* round!:mt */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 8); /* csl_normbf */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 9); /* equal!: */
    v185 = (*qfn2(fn))(qenv(fn), stack[-2], v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    goto v31;

v31:
    if (v185 == nil) goto v79;
    v185 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v185); }

v79:
    v185 = stack[-1];
    v185 = qcdr(v185);
    if (!consp(v185)) goto v125;
    stack[0] = elt(env, 6); /* !:rd!: */
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = qcar(v185);
    v151 = negate(v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = qcdr(v185);
    v185 = list2star(stack[0], v151, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    goto v84;

v84:
    v151 = v185;
    v151 = qcdr(v151);
    if (!consp(v151)) goto v64;
    stack[-2] = qvalue(elt(env, 5)); /* bfone!* */
    stack[0] = v185;
    v151 = qvalue(elt(env, 2)); /* !:bprec!: */
    v185 = (Lisp_Object)49; /* 3 */
    v185 = difference2(v151, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 7); /* round!:mt */
    v185 = (*qfn2(fn))(qenv(fn), stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 8); /* csl_normbf */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    fn = elt(env, 9); /* equal!: */
    v185 = (*qfn2(fn))(qenv(fn), stack[-2], v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    goto v157;

v157:
    if (v185 == nil) goto v57;
    v185 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v185); }

v57:
    v185 = stack[-1];
    v185 = qcdr(v185);
    if (!consp(v185)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v151 = stack[-1];
    v185 = qvalue(elt(env, 2)); /* !:bprec!: */
    {
        popv(4);
        fn = elt(env, 7); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v151, v185);
    }

v64:
    v151 = elt(env, 3); /* 1.0 */
    v185 = qcdr(v185);
    v185 = difference2(v151, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v151 = Labsval(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v185 = qvalue(elt(env, 4)); /* !!fleps1 */
    v185 = (Lisp_Object)lessp2(v151, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v185 = v185 ? lisp_true : nil;
    env = stack[-3];
    goto v157;

v125:
    stack[0] = elt(env, 6); /* !:rd!: */
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = negate(v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v185 = cons(stack[0], v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    goto v84;

v129:
    v151 = elt(env, 3); /* 1.0 */
    v185 = stack[-1];
    v185 = qcdr(v185);
    v185 = difference2(v151, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v151 = Labsval(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v185 = qvalue(elt(env, 4)); /* !!fleps1 */
    v185 = (Lisp_Object)lessp2(v151, v185);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v185 = v185 ? lisp_true : nil;
    env = stack[-3];
    goto v31;
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



/* Code for mkmatrix */

static Lisp_Object CC_mkmatrix(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v175;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkmatrix");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v0;
    stack[-9] = v20;
/* end of prologue */
    stack[-10] = elt(env, 1); /* mat */
    v123 = (Lisp_Object)17; /* 1 */
    stack[-7] = v123;
    v175 = stack[-9];
    v123 = stack[-7];
    v123 = difference2(v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lminusp(nil, v123);
    env = stack[-11];
    if (v123 == nil) goto v190;
    v123 = qvalue(elt(env, 2)); /* nil */
    goto v161;

v161:
    {
        Lisp_Object v51 = stack[-10];
        popv(12);
        return cons(v51, v123);
    }

v190:
    v123 = (Lisp_Object)17; /* 1 */
    stack[-3] = v123;
    v175 = stack[-8];
    v123 = stack[-3];
    v123 = difference2(v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lminusp(nil, v123);
    env = stack[-11];
    if (v123 == nil) goto v129;
    v123 = qvalue(elt(env, 2)); /* nil */
    goto v81;

v81:
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-5] = v123;
    stack[-6] = v123;
    goto v103;

v103:
    v123 = stack[-7];
    v123 = add1(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-7] = v123;
    v175 = stack[-9];
    v123 = stack[-7];
    v123 = difference2(v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lminusp(nil, v123);
    env = stack[-11];
    if (v123 == nil) goto v67;
    v123 = stack[-6];
    goto v161;

v67:
    stack[-4] = stack[-5];
    v123 = (Lisp_Object)17; /* 1 */
    stack[-3] = v123;
    v175 = stack[-8];
    v123 = stack[-3];
    v123 = difference2(v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lminusp(nil, v123);
    env = stack[-11];
    if (v123 == nil) goto v158;
    v123 = qvalue(elt(env, 2)); /* nil */
    goto v138;

v138:
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lrplacd(nil, stack[-4], v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = stack[-5];
    v123 = qcdr(v123);
    stack[-5] = v123;
    goto v103;

v158:
    v123 = (Lisp_Object)1; /* 0 */
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-1] = v123;
    stack[-2] = v123;
    goto v65;

v65:
    v123 = stack[-3];
    v123 = add1(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-3] = v123;
    v175 = stack[-8];
    v123 = stack[-3];
    v123 = difference2(v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lminusp(nil, v123);
    env = stack[-11];
    if (v123 == nil) goto v113;
    v123 = stack[-2];
    goto v138;

v113:
    stack[0] = stack[-1];
    v123 = (Lisp_Object)1; /* 0 */
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lrplacd(nil, stack[0], v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    goto v65;

v129:
    v123 = (Lisp_Object)1; /* 0 */
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-1] = v123;
    stack[-2] = v123;
    goto v27;

v27:
    v123 = stack[-3];
    v123 = add1(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-3] = v123;
    v175 = stack[-8];
    v123 = stack[-3];
    v123 = difference2(v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lminusp(nil, v123);
    env = stack[-11];
    if (v123 == nil) goto v119;
    v123 = stack[-2];
    goto v81;

v119:
    stack[0] = stack[-1];
    v123 = (Lisp_Object)1; /* 0 */
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = Lrplacd(nil, stack[0], v123);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    goto v27;
/* error exit handlers */
v189:
    popv(12);
    return nil;
}



/* Code for indexvarordp */

static Lisp_Object CC_indexvarordp(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvarordp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v20;
/* end of prologue */
    v65 = stack[-1];
    v66 = qcar(v65);
    v65 = stack[0];
    v65 = qcar(v65);
    if (!(v66 == v65)) goto v81;
    v66 = stack[-1];
    v65 = qvalue(elt(env, 1)); /* kord!* */
    v65 = Lmemq(nil, v66, v65);
    if (!(v65 == nil)) goto v81;
    v66 = stack[0];
    v65 = qvalue(elt(env, 1)); /* kord!* */
    v65 = Lmemq(nil, v66, v65);
    if (!(v65 == nil)) goto v81;
    v65 = stack[-1];
    v65 = qcdr(v65);
    fn = elt(env, 5); /* flatindxl */
    stack[-2] = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    v65 = stack[0];
    v65 = qcdr(v65);
    fn = elt(env, 5); /* flatindxl */
    v66 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    v65 = stack[-2];
    stack[-2] = v66;
    v66 = v65;
    v65 = qvalue(elt(env, 2)); /* indxl!* */
    fn = elt(env, 6); /* boundindp */
    v65 = (*qfn2(fn))(qenv(fn), v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    if (v65 == nil) goto v159;
    v66 = stack[-2];
    v65 = qvalue(elt(env, 2)); /* indxl!* */
    fn = elt(env, 6); /* boundindp */
    v65 = (*qfn2(fn))(qenv(fn), v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    if (v65 == nil) goto v95;
    v65 = stack[-1];
    v66 = qcdr(v65);
    v65 = stack[0];
    v65 = qcdr(v65);
    {
        popv(4);
        fn = elt(env, 7); /* indordlp */
        return (*qfn2(fn))(qenv(fn), v66, v65);
    }

v95:
    v65 = qvalue(elt(env, 3)); /* t */
    { popv(4); return onevalue(v65); }

v159:
    v66 = stack[-2];
    v65 = qvalue(elt(env, 2)); /* indxl!* */
    fn = elt(env, 6); /* boundindp */
    v65 = (*qfn2(fn))(qenv(fn), v66, v65);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-3];
    if (v65 == nil) goto v107;
    v65 = qvalue(elt(env, 4)); /* nil */
    { popv(4); return onevalue(v65); }

v107:
    v66 = stack[-1];
    v65 = stack[0];
    {
        popv(4);
        fn = elt(env, 8); /* ordop */
        return (*qfn2(fn))(qenv(fn), v66, v65);
    }

v81:
    v66 = stack[-1];
    v65 = stack[0];
    {
        popv(4);
        fn = elt(env, 8); /* ordop */
        return (*qfn2(fn))(qenv(fn), v66, v65);
    }
/* error exit handlers */
v193:
    popv(4);
    return nil;
}



/* Code for endstat */

static Lisp_Object MS_CDECL CC_endstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endstat");
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
    v4 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v4;
    v4 = elt(env, 2); /* end */
    fn = elt(env, 3); /* comm1 */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v4 = stack[0];
    popv(1);
    return ncons(v4);
/* error exit handlers */
v77:
    popv(1);
    return nil;
}



/* Code for mv!-pow!-mv!-!+ */

static Lisp_Object CC_mvKpowKmvKL(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v20;
/* end of prologue */
    stack[-2] = nil;
    goto v30;

v30:
    v26 = stack[0];
    if (v26 == nil) goto v4;
    v29 = stack[-1];
    v26 = stack[0];
    v26 = qcar(v26);
    fn = elt(env, 1); /* mv!-pow!-mv!-term!-!+ */
    v29 = (*qfn2(fn))(qenv(fn), v29, v26);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    v26 = stack[-2];
    v26 = cons(v29, v26);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-3];
    stack[-2] = v26;
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v30;

v4:
    v26 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v26);
    }
/* error exit handlers */
v11:
    popv(4);
    return nil;
}



/* Code for set!-general!-modulus */

static Lisp_Object CC_setKgeneralKmodulus(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v184;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-general-modulus");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v135 = stack[0];
    if (!(is_number(v135))) goto v3;
    v184 = stack[0];
    v135 = (Lisp_Object)1; /* 0 */
    if (v184 == v135) goto v3;
    v135 = qvalue(elt(env, 1)); /* current!-modulus */
    stack[-1] = v135;
    v135 = stack[0];
    qvalue(elt(env, 1)) = v135; /* current!-modulus */
    v184 = stack[0];
    v135 = (Lisp_Object)33; /* 2 */
    v135 = quot2(v184, v135);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    qvalue(elt(env, 2)) = v135; /* modulus!/2 */
    v184 = stack[0];
    v135 = qvalue(elt(env, 3)); /* largest!-small!-modulus */
    v135 = (Lisp_Object)lesseq2(v184, v135);
    nil = C_nil;
    if (exception_pending()) goto v5;
    v135 = v135 ? lisp_true : nil;
    env = stack[-2];
    if (v135 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v135 = stack[0];
    v135 = Lset_small_modulus(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v5;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v3:
    v135 = qvalue(elt(env, 1)); /* current!-modulus */
    { popv(3); return onevalue(v135); }
/* error exit handlers */
v5:
    popv(3);
    return nil;
}



/* Code for rl_prepfof */

static Lisp_Object CC_rl_prepfof(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_prepfof");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v2 = v20;
/* end of prologue */
    fn = elt(env, 1); /* rl_csimpl */
    v2 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* rl_prepfof1 */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v30:
    popv(1);
    return nil;
}



/* Code for get_group_in */

static Lisp_Object CC_get_group_in(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object v30;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_group_in");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v20;
/* end of prologue */
    v30 = qcar(v30);
    return onevalue(v30);
}



/* Code for pasf_varlat */

static Lisp_Object CC_pasf_varlat(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_varlat");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v128 = stack[0];
    v128 = qcdr(v128);
    v98 = qcar(v128);
    v128 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v98, v128);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v128 = stack[0];
    v128 = Lconsp(nil, v128);
    env = stack[-2];
    if (v128 == nil) goto v7;
    v128 = stack[0];
    v128 = qcar(v128);
    v128 = Lconsp(nil, v128);
    env = stack[-2];
    if (v128 == nil) goto v7;
    v128 = stack[0];
    v128 = qcar(v128);
    v98 = qcar(v128);
    v128 = elt(env, 2); /* (cong ncong) */
    v128 = Lmemq(nil, v98, v128);
    if (v128 == nil) goto v7;
    v128 = stack[0];
    v128 = qcar(v128);
    v98 = qcdr(v128);
    v128 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* kernels1 */
    v128 = (*qfn2(fn))(qenv(fn), v98, v128);
    nil = C_nil;
    if (exception_pending()) goto v18;
    goto v30;

v30:
    {
        Lisp_Object v71 = stack[-1];
        popv(3);
        return Lappend(nil, v71, v128);
    }

v7:
    v128 = qvalue(elt(env, 1)); /* nil */
    goto v30;
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for ibalp_recalcv */

static Lisp_Object CC_ibalp_recalcv(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_recalcv");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v96 = v20;
/* end of prologue */
    stack[-2] = v96;
    goto v2;

v2:
    v96 = stack[-2];
    if (v96 == nil) goto v4;
    v96 = stack[-2];
    v96 = qcar(v96);
    stack[-1] = v96;
    v96 = stack[-1];
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    stack[0] = qcdr(v96);
    v96 = stack[-1];
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v181 = qcar(v96);
    v96 = elt(env, 2); /* 0.05 */
    v96 = difference2(v181, v96);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v96 = (*qfn2(fn))(qenv(fn), stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    v96 = stack[-1];
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    stack[0] = qcdr(v96);
    v96 = stack[-1];
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v181 = qcar(v96);
    v96 = elt(env, 2); /* 0.05 */
    v96 = difference2(v181, v96);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v96 = (*qfn2(fn))(qenv(fn), stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    v96 = stack[-2];
    v96 = qcdr(v96);
    stack[-2] = v96;
    goto v2;

v4:
    v96 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v96); }
/* error exit handlers */
v159:
    popv(4);
    return nil;
}



/* Code for horner!-rule!-mod!-p */

static Lisp_Object MS_CDECL CC_hornerKruleKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v20, Lisp_Object v0,
                         Lisp_Object v1, Lisp_Object v34,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v177, v155, v156, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push5(v3,v34,v1,v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v20,v0,v1,v34,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v3;
    stack[-3] = v34;
    stack[-4] = v1;
    v155 = v0;
    v156 = v20;
/* end of prologue */

v197:
    v179 = stack[-4];
    if (!consp(v179)) goto v8;
    v179 = stack[-4];
    v179 = qcar(v179);
    if (!consp(v179)) goto v8;
    v179 = stack[-4];
    v179 = qcar(v179);
    v179 = qcar(v179);
    v177 = qcar(v179);
    v179 = stack[-2];
    if (!(equal(v177, v179))) goto v8;
    v179 = stack[-4];
    v179 = qcar(v179);
    v179 = qcar(v179);
    v179 = qcdr(v179);
    stack[-5] = v179;
    v179 = stack[-3];
    if (v179 == nil) goto v194;
    v179 = stack[-3];
    v179 = (Lisp_Object)zerop(v179);
    v179 = v179 ? lisp_true : nil;
    env = stack[-6];
    if (!(v179 == nil)) goto v194;
    v179 = stack[-4];
    v179 = qcar(v179);
    stack[-1] = qcdr(v179);
    stack[0] = v156;
    v177 = stack[-3];
    v179 = stack[-5];
    v179 = (Lisp_Object)(int32_t)((int32_t)v155 - (int32_t)v179 + TAG_FIXNUM);
    fn = elt(env, 1); /* expt!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), v177, v179);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 2); /* times!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), stack[0], v179);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 3); /* plus!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), stack[-1], v179);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v156 = v179;
    goto v198;

v198:
    v155 = stack[-5];
    v179 = stack[-4];
    v61 = qcdr(v179);
    v177 = stack[-3];
    v179 = stack[-2];
    stack[-4] = v61;
    stack[-3] = v177;
    stack[-2] = v179;
    goto v197;

v194:
    v179 = stack[-4];
    v179 = qcar(v179);
    v179 = qcdr(v179);
    v156 = v179;
    goto v198;

v8:
    v179 = stack[-3];
    if (v179 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v179 = stack[-3];
    v179 = (Lisp_Object)zerop(v179);
    v179 = v179 ? lisp_true : nil;
    env = stack[-6];
    if (!(v179 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[0] = v156;
    v179 = stack[-3];
    v177 = v155;
    fn = elt(env, 1); /* expt!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), v179, v177);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    fn = elt(env, 2); /* times!-mod!-p */
    v179 = (*qfn2(fn))(qenv(fn), stack[0], v179);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-6];
    v156 = v179;
    v179 = stack[-4];
    v177 = v156;
    {
        popv(7);
        fn = elt(env, 3); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v179, v177);
    }
/* error exit handlers */
v174:
    popv(7);
    return nil;
}



/* Code for rl_updcache */

static Lisp_Object MS_CDECL CC_rl_updcache(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v202;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rl_updcache");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_updcache");
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
    v201 = qvalue(elt(env, 1)); /* rl_bbl!* */
    stack[0] = v201;
    goto v3;

v3:
    v201 = stack[0];
    if (v201 == nil) goto v16;
    v201 = stack[0];
    v201 = qcar(v201);
    v202 = v201;
    v201 = qvalue(elt(env, 2)); /* nil */
    v201 = Lset(nil, v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    v201 = stack[0];
    v201 = qcdr(v201);
    stack[0] = v201;
    goto v3;

v16:
    v201 = qvalue(elt(env, 3)); /* rl_cid!* */
    v202 = qcar(v201);
    v201 = elt(env, 4); /* rl_params */
    v201 = get(v202, v201);
    env = stack[-1];
    stack[0] = v201;
    goto v32;

v32:
    v201 = stack[0];
    if (v201 == nil) goto v31;
    v201 = stack[0];
    v201 = qcar(v201);
    v202 = v201;
    v202 = qcar(v202);
    v201 = qcdr(v201);
    v201 = Lset(nil, v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    v201 = stack[0];
    v201 = qcdr(v201);
    stack[0] = v201;
    goto v32;

v31:
    v201 = qvalue(elt(env, 5)); /* rl_servl!* */
    stack[0] = v201;
    goto v19;

v19:
    v201 = stack[0];
    if (v201 == nil) goto v96;
    v201 = stack[0];
    v201 = qcar(v201);
    v202 = v201;
    v201 = qvalue(elt(env, 2)); /* nil */
    v201 = Lset(nil, v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    v201 = stack[0];
    v201 = qcdr(v201);
    stack[0] = v201;
    goto v19;

v96:
    v201 = qvalue(elt(env, 3)); /* rl_cid!* */
    v202 = qcar(v201);
    v201 = elt(env, 6); /* rl_services */
    v201 = get(v202, v201);
    env = stack[-1];
    stack[0] = v201;
    goto v169;

v169:
    v201 = stack[0];
    if (v201 == nil) goto v114;
    v201 = stack[0];
    v201 = qcar(v201);
    v202 = v201;
    v202 = qcar(v202);
    v201 = qcdr(v201);
    v201 = Lset(nil, v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-1];
    v201 = stack[0];
    v201 = qcdr(v201);
    stack[0] = v201;
    goto v169;

v114:
    v201 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v201); }
/* error exit handlers */
v203:
    popv(2);
    return nil;
}



/* Code for ir2mml */

static Lisp_Object CC_ir2mml(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ir2mml");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v190 = elt(env, 1); /* (indent) */
    fn = elt(env, 8); /* fluid */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-1];
    v190 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 2)) = v190; /* ind */
    v190 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v190; /* indent */
    v190 = elt(env, 4); /* "<math>" */
    fn = elt(env, 9); /* printout */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-1];
    v190 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 10); /* indent!* */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-1];
    v190 = stack[0];
    fn = elt(env, 11); /* expression */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-1];
    v190 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* indent!* */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-1];
    v190 = elt(env, 7); /* "</math>" */
    fn = elt(env, 9); /* printout */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v204;
    v190 = nil;
    { popv(2); return onevalue(v190); }
/* error exit handlers */
v204:
    popv(2);
    return nil;
}



/* Code for n_nary */

static Lisp_Object CC_n_nary(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for n_nary");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v20;
/* end of prologue */
    v182 = stack[-1];
    v124 = qcar(v182);
    v182 = elt(env, 1); /* e */
    if (!(v124 == v182)) goto v29;
    v124 = stack[0];
    v182 = elt(env, 2); /* power */
    if (!(v124 == v182)) goto v29;
    v182 = stack[-1];
    v124 = qcdr(v182);
    v182 = elt(env, 3); /* exp */
    fn = elt(env, 9); /* unary */
    v182 = (*qfn2(fn))(qenv(fn), v124, v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    goto v30;

v30:
    v182 = nil;
    { popv(3); return onevalue(v182); }

v29:
    v182 = elt(env, 4); /* "<apply>" */
    fn = elt(env, 10); /* printout */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v182 = elt(env, 5); /* "<" */
    v182 = Lprinc(nil, v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v182 = stack[0];
    v182 = Lprinc(nil, v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v182 = elt(env, 6); /* "/>" */
    v182 = Lprinc(nil, v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v124 = qvalue(elt(env, 7)); /* indent */
    v182 = (Lisp_Object)49; /* 3 */
    v182 = plus2(v124, v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    qvalue(elt(env, 7)) = v182; /* indent */
    v182 = stack[-1];
    fn = elt(env, 11); /* multi_elem */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v124 = qvalue(elt(env, 7)); /* indent */
    v182 = (Lisp_Object)49; /* 3 */
    v182 = difference2(v124, v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    qvalue(elt(env, 7)) = v182; /* indent */
    v182 = elt(env, 8); /* "</apply>" */
    fn = elt(env, 10); /* printout */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v69;
    goto v30;
/* error exit handlers */
v69:
    popv(3);
    return nil;
}



/* Code for cr!:zerop */

static Lisp_Object CC_crTzerop(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v199;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:zerop");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v159 = stack[0];
    v159 = qcdr(v159);
    v159 = qcar(v159);
    if (!consp(v159)) goto v8;
    v199 = elt(env, 1); /* !:rd!: */
    v159 = stack[0];
    v159 = qcdr(v159);
    v159 = qcar(v159);
    v159 = cons(v199, v159);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    goto v161;

v161:
    v199 = v159;
    v159 = v199;
    if (!consp(v159)) goto v13;
    v159 = v199;
    v159 = qcdr(v159);
    v199 = qcar(v159);
    v159 = (Lisp_Object)1; /* 0 */
    v159 = (v199 == v159 ? lisp_true : nil);
    goto v16;

v16:
    if (v159 == nil) goto v3;
    v159 = stack[0];
    v159 = qcdr(v159);
    v159 = qcdr(v159);
    if (!consp(v159)) goto v128;
    v199 = elt(env, 1); /* !:rd!: */
    v159 = stack[0];
    v159 = qcdr(v159);
    v159 = qcdr(v159);
    v159 = cons(v199, v159);
    nil = C_nil;
    if (exception_pending()) goto v118;
    goto v6;

v6:
    v199 = v159;
    v159 = v199;
    if (!consp(v159)) goto v191;
    v159 = v199;
    v159 = qcdr(v159);
    v199 = qcar(v159);
    v159 = (Lisp_Object)1; /* 0 */
    v159 = (v199 == v159 ? lisp_true : nil);
    { popv(2); return onevalue(v159); }

v191:
    v159 = v199;
        popv(2);
        return Lzerop(nil, v159);

v128:
    v159 = stack[0];
    v159 = qcdr(v159);
    v159 = qcdr(v159);
    goto v6;

v3:
    v159 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v159); }

v13:
    v159 = v199;
    v159 = (Lisp_Object)zerop(v159);
    v159 = v159 ? lisp_true : nil;
    env = stack[-1];
    goto v16;

v8:
    v159 = stack[0];
    v159 = qcdr(v159);
    v159 = qcar(v159);
    goto v161;
/* error exit handlers */
v118:
    popv(2);
    return nil;
}



/* Code for groebcplistsortin1 */

static Lisp_Object CC_groebcplistsortin1(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistsortin1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v20;
/* end of prologue */

v77:
    v99 = stack[0];
    v19 = qcar(v99);
    v99 = stack[-1];
    fn = elt(env, 1); /* groebcpcompless!? */
    v99 = (*qfn2(fn))(qenv(fn), v19, v99);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    if (v99 == nil) goto v204;
    v99 = stack[0];
    v99 = qcdr(v99);
    if (v99 == nil) goto v5;
    v99 = stack[0];
    v99 = qcdr(v99);
    stack[0] = v99;
    goto v77;

v5:
    v99 = stack[-1];
    v99 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v124;
    {
        Lisp_Object v111 = stack[0];
        popv(4);
        return Lrplacd(nil, v111, v99);
    }

v204:
    stack[-2] = stack[0];
    v99 = stack[0];
    v19 = qcar(v99);
    v99 = stack[0];
    v99 = qcdr(v99);
    v99 = cons(v19, v99);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v99 = Lrplacd(nil, stack[-2], v99);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v19 = stack[0];
    v99 = stack[-1];
        popv(4);
        return Lrplaca(nil, v19, v99);
/* error exit handlers */
v124:
    popv(4);
    return nil;
}



/* Code for my_letmtr */

static Lisp_Object MS_CDECL CC_my_letmtr(Lisp_Object env, int nargs,
                         Lisp_Object v20, Lisp_Object v0,
                         Lisp_Object v1, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v58, v209, v210, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "my_letmtr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my_letmtr");
#endif
    if (stack >= stacklimit)
    {
        push3(v1,v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v20,v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-4] = v0;
    stack[-5] = v20;
/* end of prologue */
    stack[0] = nil;
    v58 = stack[-3];
    v57 = elt(env, 1); /* mat */
    if (!consp(v58)) goto v204;
    v58 = qcar(v58);
    if (!(v58 == v57)) goto v204;
    v57 = stack[-5];
    v57 = qcdr(v57);
    stack[-6] = v57;
    v57 = stack[-6];
    if (v57 == nil) goto v18;
    v57 = stack[-6];
    v57 = qcar(v57);
    v58 = v57;
    v57 = v58;
    v57 = integerp(v57);
    if (v57 == nil) goto v119;
    v57 = v58;
    goto v124;

v124:
    v57 = ncons(v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    stack[-1] = v57;
    stack[-2] = v57;
    goto v6;

v6:
    v57 = stack[-6];
    v57 = qcdr(v57);
    stack[-6] = v57;
    v57 = stack[-6];
    if (v57 == nil) goto v93;
    stack[0] = stack[-1];
    v57 = stack[-6];
    v57 = qcar(v57);
    v58 = v57;
    v57 = v58;
    v57 = integerp(v57);
    if (v57 == nil) goto v105;
    v57 = v58;
    goto v118;

v118:
    v57 = ncons(v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    v57 = Lrplacd(nil, stack[0], v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    v57 = stack[-1];
    v57 = qcdr(v57);
    stack[-1] = v57;
    goto v6;

v105:
    v57 = v58;
    fn = elt(env, 10); /* reval */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    goto v118;

v93:
    v57 = stack[-2];
    goto v5;

v5:
    stack[0] = v57;
    fn = elt(env, 11); /* numlis */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    if (v57 == nil) goto v202;
    v57 = stack[0];
    v58 = Llength(nil, v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    v57 = (Lisp_Object)33; /* 2 */
    if (!(v58 == v57)) goto v202;

v59:
    v57 = stack[-3];
    v58 = qcdr(v57);
    v57 = stack[0];
    v57 = qcar(v57);
    fn = elt(env, 12); /* pnth */
    v57 = (*qfn2(fn))(qenv(fn), v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    v58 = qcar(v57);
    v57 = stack[0];
    v57 = qcdr(v57);
    v57 = qcar(v57);
    fn = elt(env, 12); /* pnth */
    v58 = (*qfn2(fn))(qenv(fn), v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    v57 = stack[-4];
    v57 = Lrplaca(nil, v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v57 = nil;
    { popv(8); return onevalue(v57); }

v202:
    v211 = elt(env, 7); /* "Syntax error:" */
    v210 = stack[-5];
    v209 = elt(env, 8); /* "invalid" */
    v58 = qvalue(elt(env, 6)); /* nil */
    v57 = elt(env, 9); /* hold */
    {
        popv(8);
        fn = elt(env, 13); /* msgpri */
        return (*qfnn(fn))(qenv(fn), 5, v211, v210, v209, v58, v57);
    }

v119:
    v57 = v58;
    fn = elt(env, 10); /* reval */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    goto v124;

v18:
    v57 = qvalue(elt(env, 6)); /* nil */
    goto v5;

v204:
    v209 = elt(env, 2); /* "Matrix" */
    v57 = stack[-5];
    v58 = qcar(v57);
    v57 = elt(env, 3); /* "not set" */
    v57 = list3(v209, v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    v58 = v57;
    v57 = v58;
    qvalue(elt(env, 4)) = v57; /* errmsg!* */
    v57 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v57 == nil)) goto v81;
    v57 = v58;
    fn = elt(env, 14); /* lprie */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    goto v81;

v81:
    v57 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-7];
    goto v59;
/* error exit handlers */
v52:
    popv(8);
    return nil;
}



/* Code for triviallcm */

static Lisp_Object MS_CDECL CC_triviallcm(Lisp_Object env, int nargs,
                         Lisp_Object v20, Lisp_Object v0,
                         Lisp_Object v1, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "triviallcm");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for triviallcm");
#endif
    if (stack >= stacklimit)
    {
        push3(v1,v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v20,v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v204 = v0;
    v33 = v20;
/* end of prologue */
    fn = elt(env, 1); /* xdiv */
    v204 = (*qfn2(fn))(qenv(fn), v204, v33);
    nil = C_nil;
    if (exception_pending()) goto v23;
    v33 = stack[0];
    v33 = (equal(v204, v33) ? lisp_true : nil);
    { popv(1); return onevalue(v33); }
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for rd!:minus */

static Lisp_Object CC_rdTminus(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:minus");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v81 = stack[0];
    v81 = qcdr(v81);
    if (!consp(v81)) goto v4;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = qcar(v81);
    v27 = negate(v81);
    nil = C_nil;
    if (exception_pending()) goto v129;
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    {
        Lisp_Object v12 = stack[-1];
        popv(2);
        return list2star(v12, v27, v81);
    }

v4:
    stack[-1] = elt(env, 1); /* !:rd!: */
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = negate(v81);
    nil = C_nil;
    if (exception_pending()) goto v129;
    {
        Lisp_Object v192 = stack[-1];
        popv(2);
        return cons(v192, v81);
    }
/* error exit handlers */
v129:
    popv(2);
    return nil;
}



/* Code for collectphystype */

static Lisp_Object CC_collectphystype(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectphystype");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */
    v133 = stack[0];
    fn = elt(env, 2); /* physopp */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    if (v133 == nil) goto v2;
    v133 = stack[0];
    fn = elt(env, 3); /* getphystype */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v182;
    popv(5);
    return ncons(v133);

v2:
    v133 = stack[0];
    if (!consp(v133)) goto v77;
    v133 = stack[0];
    stack[-3] = v133;
    v133 = stack[-3];
    if (v133 == nil) goto v31;
    v133 = stack[-3];
    v133 = qcar(v133);
    fn = elt(env, 3); /* getphystype */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    stack[-1] = v133;
    stack[-2] = v133;
    goto v80;

v80:
    v133 = stack[-3];
    v133 = qcdr(v133);
    stack[-3] = v133;
    v133 = stack[-3];
    if (v133 == nil) goto v12;
    stack[0] = stack[-1];
    v133 = stack[-3];
    v133 = qcar(v133);
    fn = elt(env, 3); /* getphystype */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    v133 = Lrplacd(nil, stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-4];
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-1] = v133;
    goto v80;

v12:
    v133 = stack[-2];
    goto v23;

v23:
    {
        popv(5);
        fn = elt(env, 4); /* deletemult!* */
        return (*qfn1(fn))(qenv(fn), v133);
    }

v31:
    v133 = qvalue(elt(env, 1)); /* nil */
    goto v23;

v77:
    v133 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v133); }
/* error exit handlers */
v182:
    popv(5);
    return nil;
}



/* Code for mktails */

static Lisp_Object MS_CDECL CC_mktails(Lisp_Object env, int nargs,
                         Lisp_Object v20, Lisp_Object v0,
                         Lisp_Object v1, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v134, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktails");
#endif
    if (stack >= stacklimit)
    {
        push3(v1,v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v20,v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v134 = v1;
    stack[-2] = v0;
    v69 = v20;
/* end of prologue */
    stack[0] = nil;
    v111 = v69;
    if (v111 == nil) goto v104;
    v111 = v69;
    stack[-3] = v111;
    v111 = v134;
    stack[-1] = v111;
    goto v31;

v31:
    v111 = stack[-3];
    if (v111 == nil) goto v133;
    v111 = stack[-3];
    v69 = qcar(v111);
    v134 = stack[-2];
    v111 = stack[-1];
    fn = elt(env, 2); /* mktails1 */
    v111 = (*qfnn(fn))(qenv(fn), 3, v69, v134, v111);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    v134 = v111;
    v111 = v134;
    v111 = qcdr(v111);
    stack[-1] = v111;
    v111 = v134;
    v134 = qcar(v111);
    v111 = stack[0];
    v111 = Lappend(nil, v134, v111);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-4];
    stack[0] = v111;
    v111 = stack[-3];
    v111 = qcdr(v111);
    stack[-3] = v111;
    goto v31;

v133:
    v134 = stack[0];
    v111 = stack[-1];
    popv(5);
    return cons(v134, v111);

v104:
    v111 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return cons(v111, v134);
/* error exit handlers */
v198:
    popv(5);
    return nil;
}



/* Code for mv!-domainlist!-!+ */

static Lisp_Object CC_mvKdomainlistKL(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
    stack[-1] = v20;
/* end of prologue */
    stack[-2] = nil;
    goto v30;

v30:
    v27 = stack[-1];
    if (v27 == nil) goto v4;
    v27 = stack[-1];
    v162 = qcar(v27);
    v27 = stack[0];
    v27 = qcar(v27);
    v162 = plus2(v162, v27);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-3];
    v27 = stack[-2];
    v27 = cons(v162, v27);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-3];
    stack[-2] = v27;
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v30;

v4:
    v27 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v192:
    popv(4);
    return nil;
}



/* Code for rnminusp!: */

static Lisp_Object CC_rnminuspT(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v81, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnminusp:");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v20;
/* end of prologue */
    v29 = v81;
    v29 = qcdr(v29);
    v29 = qcar(v29);
    v81 = v29;
    if (!consp(v29)) goto v21;
    v29 = v81;
    v27 = qcar(v29);
    v29 = elt(env, 1); /* minusp */
    v29 = get(v27, v29);
        return Lapply1(nil, v29, v81);

v21:
    v29 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v81, v29);
}



/* Code for mo_times_ei */

static Lisp_Object CC_mo_times_ei(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v101, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_times_ei");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v168 = v0;
    v101 = v20;
/* end of prologue */
    v192 = v168;
    v192 = qcar(v192);
    if (v192 == nil) goto v2;
    v192 = v168;
    v192 = qcar(v192);
    v192 = qcar(v192);
    v192 = (Lisp_Object)(int32_t)((int32_t)v101 + (int32_t)v192 - TAG_FIXNUM);
    v101 = v168;
    v101 = qcar(v101);
    v101 = qcdr(v101);
    v192 = cons(v192, v101);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    goto v26;

v26:
    stack[0] = v192;
    fn = elt(env, 1); /* mo!=deglist */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v100;
    {
        Lisp_Object v135 = stack[0];
        popv(2);
        return cons(v135, v192);
    }

v2:
    v192 = v101;
    v192 = ncons(v192);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    goto v26;
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for reducepowers */

static Lisp_Object CC_reducepowers(Lisp_Object env,
                         Lisp_Object v20)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reducepowers");
#endif
    if (stack >= stacklimit)
    {
        push(v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v20);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v20;
/* end of prologue */

v3:
    v201 = stack[0];
    if (!consp(v201)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v201 = stack[0];
    v201 = qcar(v201);
    if (!consp(v201)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v201 = stack[0];
    v201 = qcar(v201);
    v201 = qcar(v201);
    v202 = qcdr(v201);
    v201 = qvalue(elt(env, 1)); /* repowl!* */
    v201 = qcar(v201);
    v201 = qcdr(v201);
    v201 = (Lisp_Object)lessp2(v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v212;
    v201 = v201 ? lisp_true : nil;
    env = stack[-2];
    if (!(v201 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v201 = stack[0];
    v201 = qcar(v201);
    v201 = qcar(v201);
    v202 = qcdr(v201);
    v201 = qvalue(elt(env, 1)); /* repowl!* */
    v201 = qcar(v201);
    v201 = qcdr(v201);
    if (equal(v202, v201)) goto v5;
    v201 = stack[0];
    v201 = qcar(v201);
    v201 = qcar(v201);
    stack[-1] = qcar(v201);
    v201 = stack[0];
    v201 = qcar(v201);
    v201 = qcar(v201);
    v202 = qcdr(v201);
    v201 = qvalue(elt(env, 1)); /* repowl!* */
    v201 = qcar(v201);
    v201 = qcdr(v201);
    v202 = difference2(v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v201 = (Lisp_Object)17; /* 1 */
    v201 = acons(stack[-1], v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v202 = ncons(v201);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v201 = stack[0];
    v201 = qcar(v201);
    v201 = qcdr(v201);
    fn = elt(env, 2); /* multf */
    v202 = (*qfn2(fn))(qenv(fn), v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v201 = qvalue(elt(env, 1)); /* repowl!* */
    v201 = qcdr(v201);
    fn = elt(env, 2); /* multf */
    v202 = (*qfn2(fn))(qenv(fn), v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v201 = stack[0];
    v201 = qcdr(v201);
    fn = elt(env, 3); /* addf */
    v201 = (*qfn2(fn))(qenv(fn), v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    stack[0] = v201;
    goto v3;

v5:
    v201 = qvalue(elt(env, 1)); /* repowl!* */
    v202 = qcdr(v201);
    v201 = stack[0];
    v201 = qcar(v201);
    v201 = qcdr(v201);
    fn = elt(env, 2); /* multf */
    v202 = (*qfn2(fn))(qenv(fn), v202, v201);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-2];
    v201 = stack[0];
    v201 = qcdr(v201);
    {
        popv(3);
        fn = elt(env, 3); /* addf */
        return (*qfn2(fn))(qenv(fn), v202, v201);
    }
/* error exit handlers */
v212:
    popv(3);
    return nil;
}



/* Code for subf1 */

static Lisp_Object CC_subf1(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v297, v298, v299;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v0;
    stack[-11] = v20;
/* end of prologue */
    v297 = stack[-11];
    if (v297 == nil) goto v4;
    v297 = stack[-11];
    if (!consp(v297)) goto v104;
    v297 = stack[-11];
    v297 = qcar(v297);
    if (!consp(v297)) goto v104;
    stack[-7] = qvalue(elt(env, 4)); /* varstack!* */
    qvalue(elt(env, 4)) = nil; /* varstack!* */
    stack[-3] = nil;
    stack[-2] = nil;
    v298 = qvalue(elt(env, 1)); /* nil */
    v297 = (Lisp_Object)17; /* 1 */
    v297 = cons(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-1] = v297;
    goto v136;

v136:
    v297 = stack[-11];
    v297 = qcar(v297);
    v297 = qcar(v297);
    v297 = qcar(v297);
    stack[-9] = v297;
    v297 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v297;
    v298 = stack[-9];
    v297 = stack[-10];
    v297 = Lassoc(nil, v298, v297);
    if (v297 == nil) goto v206;
    v298 = stack[-9];
    v297 = qvalue(elt(env, 5)); /* wtl!* */
    v297 = Lassoc(nil, v298, v297);
    stack[0] = v297;
    if (v297 == nil) goto v206;
    v297 = stack[0];
    v297 = qcdr(v297);
    stack[0] = v297;
    goto v206;

v206:
    v298 = stack[-9];
    v297 = qvalue(elt(env, 6)); /* asymplis!* */
    v297 = Lassoc(nil, v298, v297);
    stack[-8] = v297;
    if (v297 == nil) goto v188;
    v297 = stack[-8];
    v297 = qcdr(v297);
    stack[-8] = v297;
    goto v188;

v188:
    v297 = stack[-11];
    if (v297 == nil) goto v110;
    v298 = stack[-11];
    v297 = stack[-9];
    fn = elt(env, 11); /* degr */
    v298 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-12] = v298;
    v297 = (Lisp_Object)1; /* 0 */
    if (v298 == v297) goto v110;
    v297 = stack[-8];
    if (v297 == nil) goto v301;
    v298 = stack[-12];
    v297 = stack[-8];
    v297 = (Lisp_Object)lessp2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    v297 = v297 ? lisp_true : nil;
    env = stack[-13];
    if (!(v297 == nil)) goto v301;

v89:
    v297 = stack[-11];
    v297 = qcdr(v297);
    stack[-11] = v297;
    goto v188;

v301:
    v297 = stack[-11];
    v298 = qcar(v297);
    v297 = stack[0];
    fn = elt(env, 12); /* wtchk */
    v298 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-3];
    v297 = cons(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-3] = v297;
    goto v89;

v110:
    v297 = qvalue(elt(env, 1)); /* nil */
    v299 = v297;
    goto v145;

v145:
    v297 = stack[-10];
    if (v297 == nil) goto v302;
    v297 = stack[-10];
    v297 = qcar(v297);
    v298 = qcar(v297);
    v297 = stack[-10];
    v297 = qcar(v297);
    v297 = qcdr(v297);
    if (equal(v298, v297)) goto v303;
    v297 = stack[-10];
    v297 = qcar(v297);
    v298 = v299;
    v297 = cons(v297, v298);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v299 = v297;
    goto v303;

v303:
    v297 = stack[-10];
    v297 = qcdr(v297);
    stack[-10] = v297;
    goto v145;

v302:
    v297 = v299;
    v297 = Lnreverse(nil, v297);
    env = stack[-13];
    stack[-10] = v297;
    v297 = stack[-9];
    if (!consp(v297)) goto v139;
    v297 = stack[-9];
    v297 = qcar(v297);
    if (!consp(v297)) goto v139;
    v298 = stack[-9];
    v297 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 13); /* prepf1 */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v298 = v297;
    v297 = v298;
    if (v297 == nil) goto v304;
    v297 = v298;
    fn = elt(env, 14); /* replus */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    goto v305;

v305:
    stack[-9] = v297;
    goto v139;

v139:
    v297 = stack[-10];
    if (v297 == nil) goto v306;
    v298 = stack[-10];
    v297 = stack[-9];
    fn = elt(env, 15); /* subsublis */
    v298 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-4] = v298;
    v297 = stack[-9];
    if (!(equal(v298, v297))) goto v307;
    v298 = stack[-9];
    v297 = qvalue(elt(env, 6)); /* asymplis!* */
    v297 = Lassoc(nil, v298, v297);
    if (!(v297 == nil)) goto v307;

v138:
    v297 = stack[-9];
    fn = elt(env, 16); /* sub2chk */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-3];
    stack[-4] = v297;
    goto v308;

v308:
    v297 = stack[-4];
    if (v297 == nil) goto v186;
    v297 = stack[-4];
    v297 = qcar(v297);
    stack[-3] = v297;
    v297 = stack[-3];
    v298 = qcar(v297);
    v297 = (Lisp_Object)17; /* 1 */
    v297 = cons(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v298 = ncons(v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-3];
    v298 = qcdr(v297);
    v297 = stack[-10];
    v297 = CC_subf1(env, v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 17); /* multsq */
    v298 = (*qfn2(fn))(qenv(fn), stack[0], v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-1];
    fn = elt(env, 18); /* addsq */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-1] = v297;
    v297 = stack[-4];
    v297 = qcdr(v297);
    stack[-4] = v297;
    goto v308;

v186:
    v297 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v297;
    v297 = stack[-11];
    if (v297 == nil) goto v309;
    v297 = stack[-11];
    if (!consp(v297)) goto v310;
    v297 = stack[-11];
    v297 = qcar(v297);
    if (!(!consp(v297))) goto v136;

v310:
    v298 = stack[-11];
    v297 = stack[-10];
    v298 = CC_subf1(env, v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-1];
    fn = elt(env, 18); /* addsq */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    goto v107;

v107:
    qvalue(elt(env, 4)) = stack[-7]; /* varstack!* */
    { popv(14); return onevalue(v297); }

v309:
    v297 = stack[-1];
    goto v107;

v307:
    v298 = (Lisp_Object)17; /* 1 */
    v297 = (Lisp_Object)17; /* 1 */
    v297 = cons(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-6] = v297;
    v297 = (Lisp_Object)1; /* 0 */
    stack[-12] = v297;
    v297 = stack[-3];
    if (v297 == nil) goto v311;
    v297 = stack[-3];
    v297 = qcar(v297);
    v297 = qcar(v297);
    v297 = qcdr(v297);
    v297 = Lminusp(nil, v297);
    env = stack[-13];
    if (v297 == nil) goto v311;
    v297 = stack[-4];
    v297 = ncons(v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 19); /* simprecip */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-5] = v297;
    goto v312;

v312:
    v297 = stack[-3];
    v298 = qcar(v297);
    v297 = stack[-2];
    v297 = cons(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-2] = v297;
    v297 = stack[-3];
    v297 = qcdr(v297);
    stack[-3] = v297;
    v297 = stack[-3];
    if (v297 == nil) goto v157;
    v297 = stack[-3];
    v297 = qcar(v297);
    v297 = qcar(v297);
    v298 = qcdr(v297);
    v297 = (Lisp_Object)1; /* 0 */
    v297 = (Lisp_Object)lessp2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    v297 = v297 ? lisp_true : nil;
    env = stack[-13];
    if (!(v297 == nil)) goto v312;

v157:
    v297 = stack[-2];
    v297 = qcar(v297);
    v297 = qcar(v297);
    v297 = qcdr(v297);
    v297 = negate(v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-8] = v297;
    stack[0] = stack[-5];
    v298 = stack[-8];
    v297 = stack[-12];
    v297 = difference2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 20); /* exptsq */
    v297 = (*qfn2(fn))(qenv(fn), stack[0], v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 21); /* subs2 */
    v298 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-6];
    fn = elt(env, 17); /* multsq */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-6] = v297;
    v297 = stack[-8];
    stack[-12] = v297;
    stack[0] = stack[-6];
    v297 = stack[-2];
    v297 = qcar(v297);
    v298 = qcdr(v297);
    v297 = stack[-10];
    v297 = CC_subf1(env, v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 17); /* multsq */
    v298 = (*qfn2(fn))(qenv(fn), stack[0], v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-1];
    fn = elt(env, 18); /* addsq */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-1] = v297;
    v297 = stack[-2];
    v297 = qcdr(v297);
    stack[-2] = v297;
    v297 = stack[-2];
    if (!(v297 == nil)) goto v157;
    v297 = stack[-3];
    if (v297 == nil) goto v186;
    else goto v307;

v311:
    v297 = stack[-4];
    fn = elt(env, 22); /* getrtype */
    v298 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-5] = v298;
    v297 = elt(env, 8); /* yetunknowntype */
    if (!(v298 == v297)) goto v313;
    v298 = stack[-4];
    v297 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 23); /* eval!-yetunknowntypeexpr */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-4] = v297;
    fn = elt(env, 22); /* getrtype */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-5] = v297;
    goto v313;

v313:
    v297 = stack[-5];
    if (v297 == nil) goto v314;
    v298 = stack[-5];
    v297 = elt(env, 9); /* list */
    if (v298 == v297) goto v314;
    v298 = stack[-5];
    v297 = stack[-4];
    v298 = list2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = elt(env, 10); /* "substituted expression" */
    fn = elt(env, 24); /* typerr */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    goto v314;

v314:
    v297 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 25); /* setkorder */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[0] = v297;
    v297 = stack[-4];
    fn = elt(env, 26); /* simp */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-5] = v297;
    v297 = stack[0];
    fn = elt(env, 25); /* setkorder */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-5];
    v297 = qcar(v297);
    fn = elt(env, 27); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-5];
    v297 = qcdr(v297);
    fn = elt(env, 27); /* reorder */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = cons(stack[0], v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-5] = v297;
    v297 = stack[-10];
    if (!(v297 == nil)) goto v315;
    v297 = stack[-5];
    fn = elt(env, 28); /* kernp */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    if (v297 == nil) goto v315;
    v297 = stack[-5];
    v297 = qcar(v297);
    v297 = qcar(v297);
    v297 = qcar(v297);
    v298 = qcar(v297);
    v297 = stack[-9];
    if (v298 == v297) goto v138;
    else goto v315;

v315:
    v297 = stack[-5];
    v297 = qcar(v297);
    if (v297 == nil) goto v186;
    v297 = stack[-3];
    stack[-4] = v297;
    goto v316;

v316:
    v297 = stack[-4];
    if (v297 == nil) goto v186;
    v297 = stack[-4];
    v297 = qcar(v297);
    stack[-3] = v297;
    v297 = stack[-3];
    v297 = qcar(v297);
    v297 = qcdr(v297);
    stack[-8] = v297;
    stack[0] = stack[-5];
    v298 = stack[-8];
    v297 = stack[-12];
    v297 = difference2(v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 20); /* exptsq */
    v297 = (*qfn2(fn))(qenv(fn), stack[0], v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 21); /* subs2 */
    v298 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-6];
    fn = elt(env, 17); /* multsq */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-6] = v297;
    v297 = stack[-8];
    stack[-12] = v297;
    stack[0] = stack[-6];
    v297 = stack[-3];
    v298 = qcdr(v297);
    v297 = stack[-10];
    v297 = CC_subf1(env, v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    fn = elt(env, 17); /* multsq */
    v298 = (*qfn2(fn))(qenv(fn), stack[0], v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    v297 = stack[-1];
    fn = elt(env, 18); /* addsq */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-13];
    stack[-1] = v297;
    v297 = stack[-4];
    v297 = qcdr(v297);
    stack[-4] = v297;
    goto v316;

v306:
    v298 = stack[-9];
    v297 = elt(env, 7); /* k!* */
    if (v298 == v297) goto v317;
    v297 = stack[-9];
    goto v318;

v318:
    stack[-4] = v297;
    goto v307;

v317:
    v297 = (Lisp_Object)17; /* 1 */
    goto v318;

v304:
    v297 = (Lisp_Object)1; /* 0 */
    goto v305;

v104:
    v297 = stack[-11];
    if (!consp(v297)) goto v79;
    v298 = qvalue(elt(env, 2)); /* dmode!* */
    v297 = stack[-11];
    v297 = qcar(v297);
    if (!(v298 == v297)) goto v97;
    v298 = qvalue(elt(env, 2)); /* dmode!* */
    v297 = elt(env, 3); /* resimplify */
    v297 = Lflagp(nil, v298, v297);
    env = stack[-13];
    if (!(v297 == nil)) goto v97;
    v297 = stack[-11];
    {
        popv(14);
        fn = elt(env, 29); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v297);
    }

v97:
    v298 = stack[-11];
    v297 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 13); /* prepf1 */
    v297 = (*qfn2(fn))(qenv(fn), v298, v297);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-13];
    v298 = v297;
    v297 = v298;
    if (v297 == nil) goto v320;
    v297 = v298;
    fn = elt(env, 14); /* replus */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-13];
    goto v93;

v93:
    {
        popv(14);
        fn = elt(env, 26); /* simp */
        return (*qfn1(fn))(qenv(fn), v297);
    }

v320:
    v297 = (Lisp_Object)1; /* 0 */
    goto v93;

v79:
    v297 = qvalue(elt(env, 2)); /* dmode!* */
    if (v297 == nil) goto v26;
    v297 = stack[-11];
    {
        popv(14);
        fn = elt(env, 30); /* simpatom */
        return (*qfn1(fn))(qenv(fn), v297);
    }

v26:
    v298 = stack[-11];
    v297 = (Lisp_Object)17; /* 1 */
    popv(14);
    return cons(v298, v297);

v4:
    v298 = qvalue(elt(env, 1)); /* nil */
    v297 = (Lisp_Object)17; /* 1 */
    popv(14);
    return cons(v298, v297);
/* error exit handlers */
v319:
    popv(14);
    return nil;
v300:
    env = stack[-13];
    qvalue(elt(env, 4)) = stack[-7]; /* varstack!* */
    popv(14);
    return nil;
}



/* Code for innprodkp */

static Lisp_Object MS_CDECL CC_innprodkp(Lisp_Object env, int nargs,
                         Lisp_Object v20, Lisp_Object v0,
                         Lisp_Object v1, Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v71;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "innprodkp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for innprodkp");
#endif
    if (stack >= stacklimit)
    {
        push4(v34,v1,v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v20,v0,v1,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v34;
    stack[-1] = v1;
    stack[-2] = v0;
    v18 = v20;
/* end of prologue */

v161:
    v17 = stack[-1];
    if (v17 == nil) goto v137;
    v71 = stack[-2];
    v17 = stack[-1];
    v17 = qcar(v17);
    if (equal(v71, v17)) goto v14;
    v17 = stack[-1];
    v17 = qcar(v17);
    v17 = cons(v17, v18);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-3];
    v18 = v17;
    v17 = stack[-1];
    v17 = qcdr(v17);
    stack[-1] = v17;
    v17 = stack[0];
    v17 = (v17 == nil ? lisp_true : nil);
    stack[0] = v17;
    goto v161;

v14:
    v17 = v18;
    v18 = Lnreverse(nil, v17);
    env = stack[-3];
    v17 = stack[-1];
    v17 = qcdr(v17);
    v17 = Lnconc(nil, v18, v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    {
        Lisp_Object v82 = stack[0];
        popv(4);
        return cons(v82, v17);
    }

v137:
    v17 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v17); }
/* error exit handlers */
v19:
    popv(4);
    return nil;
}



/* Code for ofsf_surep */

static Lisp_Object CC_ofsf_surep(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v23, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_surep");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v24 = v0;
    v23 = v20;
/* end of prologue */
    v80 = v23;
    v23 = v24;
    v24 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* cl_simpl */
    v24 = (*qfnn(fn))(qenv(fn), 3, v80, v23, v24);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[0];
    v23 = elt(env, 1); /* true */
    v24 = (v24 == v23 ? lisp_true : nil);
    { popv(1); return onevalue(v24); }
/* error exit handlers */
v112:
    popv(1);
    return nil;
}



/* Code for qremd */

static Lisp_Object CC_qremd(Lisp_Object env,
                         Lisp_Object v20, Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qremd");
#endif
    if (stack >= stacklimit)
    {
        push2(v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v20,v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
    stack[-2] = v20;
/* end of prologue */
    v123 = stack[-2];
    if (v123 == nil) goto v4;
    v175 = stack[-1];
    v123 = (Lisp_Object)17; /* 1 */
    if (v175 == v123) goto v104;
    v175 = qvalue(elt(env, 1)); /* dmode!* */
    v123 = elt(env, 2); /* field */
    v123 = Lflagp(nil, v175, v123);
    env = stack[-4];
    if (v123 == nil) goto v32;
    v123 = stack[-1];
    fn = elt(env, 3); /* !:recip */
    v175 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v123 = stack[-2];
    fn = elt(env, 4); /* multd */
    v123 = (*qfn2(fn))(qenv(fn), v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    popv(5);
    return ncons(v123);

v32:
    v123 = stack[-2];
    if (!consp(v123)) goto v109;
    v123 = stack[-2];
    v123 = qcar(v123);
    if (!consp(v123)) goto v109;
    v123 = stack[-2];
    v123 = qcar(v123);
    v175 = qcdr(v123);
    v123 = stack[-1];
    fn = elt(env, 5); /* qremf */
    v123 = (*qfn2(fn))(qenv(fn), v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    stack[-3] = v123;
    v123 = stack[-2];
    v123 = qcar(v123);
    v175 = qcar(v123);
    v123 = (Lisp_Object)17; /* 1 */
    v123 = cons(v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v175 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v123 = stack[-3];
    v123 = qcar(v123);
    fn = elt(env, 6); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v123 = stack[-2];
    v123 = qcar(v123);
    v175 = qcar(v123);
    v123 = (Lisp_Object)17; /* 1 */
    v123 = cons(v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v175 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v123 = stack[-3];
    v123 = qcdr(v123);
    fn = elt(env, 6); /* multf */
    v123 = (*qfn2(fn))(qenv(fn), v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    stack[0] = cons(stack[0], v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v123 = stack[-2];
    v175 = qcdr(v123);
    v123 = stack[-1];
    v123 = CC_qremd(env, v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    stack[-2] = stack[0];
    stack[-1] = v123;
    v123 = stack[-2];
    v175 = qcar(v123);
    v123 = stack[-1];
    v123 = qcar(v123);
    fn = elt(env, 7); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v123 = stack[-2];
    v175 = qcdr(v123);
    v123 = stack[-1];
    v123 = qcdr(v123);
    fn = elt(env, 7); /* addf */
    v123 = (*qfn2(fn))(qenv(fn), v175, v123);
    nil = C_nil;
    if (exception_pending()) goto v210;
    {
        Lisp_Object v211 = stack[0];
        popv(5);
        return cons(v211, v123);
    }

v109:
    v175 = stack[-2];
    v123 = stack[-1];
    {
        popv(5);
        fn = elt(env, 8); /* !:divide */
        return (*qfn2(fn))(qenv(fn), v175, v123);
    }

v104:
    v123 = stack[-2];
    popv(5);
    return ncons(v123);

v4:
    v175 = stack[-2];
    v123 = stack[-2];
    popv(5);
    return cons(v175, v123);
/* error exit handlers */
v210:
    popv(5);
    return nil;
}



/* Code for cl_smsimpl!-junct */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct(Lisp_Object env, int nargs,
                         Lisp_Object v20, Lisp_Object v0,
                         Lisp_Object v1, Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v154, v123, v175, v205, v57, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_smsimpl-junct");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct");
#endif
    if (stack >= stacklimit)
    {
        push4(v34,v1,v0,v20);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v20,v0,v1,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v34;
    stack[-6] = v1;
    stack[0] = v0;
    stack[-7] = v20;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v206 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v206 == nil) goto v190;
    v206 = stack[-6];
    fn = elt(env, 5); /* rl_smcpknowl */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-9];
    stack[-2] = v206;
    v123 = elt(env, 3); /* false */
    v154 = stack[-7];
    v206 = elt(env, 4); /* and */
    v206 = (v154 == v206 ? lisp_true : nil);
    fn = elt(env, 6); /* cl_cflip */
    v206 = (*qfn2(fn))(qenv(fn), v123, v206);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-9];
    stack[-8] = v206;
    v206 = stack[0];
    stack[-1] = v206;
    goto v5;

v5:
    v206 = stack[-1];
    if (v206 == nil) goto v188;
    v206 = stack[-1];
    v206 = qcar(v206);
    stack[0] = v206;
    v206 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-9];
    if (v206 == nil) goto v191;
    v154 = stack[0];
    v206 = stack[-7];
    fn = elt(env, 8); /* cl_simplat */
    v206 = (*qfn2(fn))(qenv(fn), v154, v206);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-9];
    goto v82;

v82:
    stack[0] = v206;
    v206 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-9];
    if (v206 == nil) goto v118;
    v154 = stack[0];
    v206 = stack[-4];
    v206 = cons(v154, v206);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-9];
    stack[-4] = v206;
    goto v93;

v93:
    v206 = stack[-1];
    v206 = qcdr(v206);
    stack[-1] = v206;
    goto v5;

v118:
    v154 = stack[0];
    v206 = stack[-3];
    v206 = cons(v154, v206);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-9];
    stack[-3] = v206;
    goto v93;

v191:
    v206 = stack[0];
    goto v82;

v188:
    v175 = stack[-7];
    v123 = stack[-4];
    v154 = stack[-2];
    v206 = stack[-5];
    fn = elt(env, 9); /* rl_smupdknowl */
    v206 = (*qfnn(fn))(qenv(fn), 4, v175, v123, v154, v206);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-9];
    stack[-2] = v206;
    v154 = stack[-2];
    v206 = elt(env, 3); /* false */
    if (v154 == v206) goto v212;
    v58 = stack[-7];
    v57 = stack[-4];
    v206 = stack[-3];
    v205 = Lnreverse(nil, v206);
    env = stack[-9];
    v175 = stack[-6];
    v123 = stack[-2];
    v154 = stack[-5];
    v206 = stack[-8];
    {
        popv(10);
        fn = elt(env, 10); /* cl_smsimpl!-junct1 */
        return (*qfnn(fn))(qenv(fn), 7, v58, v57, v205, v175, v123, v154, v206);
    }

v212:
    v206 = stack[-8];
    popv(10);
    return ncons(v206);

v190:
    v175 = stack[0];
    v123 = stack[-5];
    v154 = stack[-7];
    v206 = qvalue(elt(env, 2)); /* nil */
    {
        popv(10);
        fn = elt(env, 11); /* cl_gand!-col */
        return (*qfnn(fn))(qenv(fn), 4, v175, v123, v154, v206);
    }
/* error exit handlers */
v51:
    popv(10);
    return nil;
}



setup_type const u18_setup[] =
{
    {"ps:evaluate-next",        too_few_2,      CC_psTevaluateKnext,wrong_no_2},
    {"lid",                     CC_lid,         too_many_1,    wrong_no_1},
    {"indord2",                 too_few_2,      CC_indord2,    wrong_no_2},
    {"quotfail1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfail1},
    {"my_freeof",               too_few_2,      CC_my_freeof,  wrong_no_2},
    {"physopsm*",               CC_physopsmH,   too_many_1,    wrong_no_1},
    {"setk",                    too_few_2,      CC_setk,       wrong_no_2},
    {"mv-domainlist",           CC_mvKdomainlist,too_many_1,   wrong_no_1},
    {"addgt",                   CC_addgt,       too_many_1,    wrong_no_1},
    {"st_consolidate",          CC_st_consolidate,too_many_1,  wrong_no_1},
    {"arplus:",                 too_few_2,      CC_arplusT,    wrong_no_2},
    {"reverse-num",             CC_reverseKnum, too_many_1,    wrong_no_1},
    {"sq2sstm",                 too_few_2,      CC_sq2sstm,    wrong_no_2},
    {"ibalp_readclause",        too_few_2,      CC_ibalp_readclause,wrong_no_2},
    {"rd:prep",                 CC_rdTprep,     too_many_1,    wrong_no_1},
    {"mkmatrix",                too_few_2,      CC_mkmatrix,   wrong_no_2},
    {"indexvarordp",            too_few_2,      CC_indexvarordp,wrong_no_2},
    {"endstat",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_endstat},
    {"mv-pow-mv-+",             too_few_2,      CC_mvKpowKmvKL,wrong_no_2},
    {"set-general-modulus",     CC_setKgeneralKmodulus,too_many_1,wrong_no_1},
    {"rl_prepfof",              CC_rl_prepfof,  too_many_1,    wrong_no_1},
    {"get_group_in",            CC_get_group_in,too_many_1,    wrong_no_1},
    {"pasf_varlat",             CC_pasf_varlat, too_many_1,    wrong_no_1},
    {"ibalp_recalcv",           CC_ibalp_recalcv,too_many_1,   wrong_no_1},
    {"horner-rule-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKmodKp},
    {"rl_updcache",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_updcache},
    {"ir2mml",                  CC_ir2mml,      too_many_1,    wrong_no_1},
    {"n_nary",                  too_few_2,      CC_n_nary,     wrong_no_2},
    {"cr:zerop",                CC_crTzerop,    too_many_1,    wrong_no_1},
    {"groebcplistsortin1",      too_few_2,      CC_groebcplistsortin1,wrong_no_2},
    {"my_letmtr",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_my_letmtr},
    {"triviallcm",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_triviallcm},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"collectphystype",         CC_collectphystype,too_many_1, wrong_no_1},
    {"mktails",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails},
    {"mv-domainlist-+",         too_few_2,      CC_mvKdomainlistKL,wrong_no_2},
    {"rnminusp:",               CC_rnminuspT,   too_many_1,    wrong_no_1},
    {"mo_times_ei",             too_few_2,      CC_mo_times_ei,wrong_no_2},
    {"reducepowers",            CC_reducepowers,too_many_1,    wrong_no_1},
    {"subf1",                   too_few_2,      CC_subf1,      wrong_no_2},
    {"innprodkp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_innprodkp},
    {"ofsf_surep",              too_few_2,      CC_ofsf_surep, wrong_no_2},
    {"qremd",                   too_few_2,      CC_qremd,      wrong_no_2},
    {"cl_smsimpl-junct",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct},
    {NULL, (one_args *)"u18", (two_args *)"13003 7168992 8639580", 0}
};

/* end of generated code */
