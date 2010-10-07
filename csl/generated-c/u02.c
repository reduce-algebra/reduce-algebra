
/* $destdir\u02.c        Machine generated C code */

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


/* Code for rnequiv */

static Lisp_Object CC_rnequiv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4, v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnequiv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v3 = v4;
    v3 = qcdr(v3);
    v4 = v3;
    v5 = qcdr(v3);
    v3 = (Lisp_Object)17; /* 1 */
    if (v5 == v3) goto v6;
    v3 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v3);

v6:
    v3 = v4;
    v3 = qcar(v3);
    return onevalue(v3);
}



/* Code for general!-modular!-times */

static Lisp_Object CC_generalKmodularKtimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-times");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v16 = v7;
    v17 = v0;
/* end of prologue */
    v17 = times2(v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v16 = qvalue(elt(env, 1)); /* current!-modulus */
    v16 = Cremainder(v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    stack[0] = v16;
    v17 = stack[0];
    v16 = (Lisp_Object)1; /* 0 */
    v16 = (Lisp_Object)lessp2(v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    v16 = v16 ? lisp_true : nil;
    env = stack[-1];
    if (v16 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v17 = stack[0];
    v16 = qvalue(elt(env, 1)); /* current!-modulus */
    v16 = plus2(v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v18;
    stack[0] = v16;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for getpower */

static Lisp_Object CC_getpower(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getpower");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v25 = stack[-1];
    v26 = qcar(v25);
    v25 = elt(env, 1); /* expt */
    if (!consp(v26)) goto v27;
    v26 = qcar(v26);
    if (!(v26 == v25)) goto v27;
    v26 = stack[0];
    v25 = (Lisp_Object)17; /* 1 */
    v25 = (Lisp_Object)greaterp2(v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    v25 = v25 ? lisp_true : nil;
    env = stack[-2];
    if (v25 == nil) goto v27;
    v25 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 3)) = v25; /* !*sub2 */
    goto v27;

v27:
    v25 = stack[-1];
    v26 = qcar(v25);
    v25 = stack[0];
    popv(3);
    return cons(v26, v25);
/* error exit handlers */
v9:
    popv(3);
    return nil;
}



/* Code for ofsf_smwupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smwupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v7,
                         Lisp_Object v28, Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v31, v16, v17, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v10;
    v16 = v28;
    v17 = v7;
    v32 = v0;
/* end of prologue */
    v9 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v9 == nil) goto v33;
    v9 = v32;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v9, v17, v16, v31);
    }

v33:
    v9 = v32;
    {
        fn = elt(env, 3); /* ofsf_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v9, v17, v16, v31);
    }
}



/* Code for gcdf */

static Lisp_Object CC_gcdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[0] = qvalue(elt(env, 2)); /* !*rounded */
    qvalue(elt(env, 2)) = nil; /* !*rounded */
    v39 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v39; /* !*exp */
    v39 = stack[-2];
    if (!consp(v39)) goto v19;
    v39 = stack[-2];
    v39 = qcar(v39);
    if (!consp(v39)) goto v19;
    v39 = stack[-1];
    if (!consp(v39)) goto v19;
    v39 = stack[-1];
    v39 = qcar(v39);
    if (!consp(v39)) goto v19;
    v39 = qvalue(elt(env, 4)); /* !*ezgcd */
    if (v39 == nil) goto v19;
    v39 = qvalue(elt(env, 5)); /* dmode!* */
    if (!(v39 == nil)) goto v19;
    v39 = stack[-2];
    fn = elt(env, 6); /* free!-powerp */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    if (!(v39 == nil)) goto v19;
    v39 = stack[-1];
    fn = elt(env, 6); /* free!-powerp */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    if (!(v39 == nil)) goto v19;
    v40 = stack[-2];
    v39 = stack[-1];
    fn = elt(env, 7); /* ezgcdf */
    v39 = (*qfn2(fn))(qenv(fn), v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    goto v42;

v42:
    stack[-2] = v39;
    v39 = stack[-2];
    fn = elt(env, 8); /* minusf */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    if (v39 == nil) goto v43;
    v39 = stack[-2];
    fn = elt(env, 9); /* negf */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    goto v44;

v44:
    qvalue(elt(env, 2)) = stack[0]; /* !*rounded */
    qvalue(elt(env, 1)) = stack[-3]; /* !*exp */
    { popv(5); return onevalue(v39); }

v43:
    v39 = stack[-2];
    goto v44;

v19:
    v40 = stack[-2];
    v39 = stack[-1];
    fn = elt(env, 10); /* gcdf1 */
    v39 = (*qfn2(fn))(qenv(fn), v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-4];
    goto v42;
/* error exit handlers */
v41:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[0]; /* !*rounded */
    qvalue(elt(env, 1)) = stack[-3]; /* !*exp */
    popv(5);
    return nil;
}



/* Code for finde */

static Lisp_Object CC_finde(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46, v11, v12;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for finde");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v7;
    v11 = v0;
/* end of prologue */

v34:
    v45 = v11;
    if (v45 == nil) goto v36;
    v46 = v12;
    v45 = v11;
    v45 = qcar(v45);
    v45 = qcdr(v45);
    v45 = Lmemq(nil, v46, v45);
    if (!(v45 == nil)) return onevalue(v11);
    v45 = v11;
    v45 = qcdr(v45);
    v11 = v45;
    goto v34;

v36:
    v45 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v45);
}



/* Code for qqe_qopaddp */

static Lisp_Object CC_qqe_qopaddp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qopaddp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v24 = v0;
/* end of prologue */
    v23 = v24;
    v24 = elt(env, 1); /* (ladd radd) */
    v24 = Lmemq(nil, v23, v24);
    if (v24 == nil) goto v34;
    v24 = qvalue(elt(env, 2)); /* t */
    return onevalue(v24);

v34:
    v24 = nil;
    return onevalue(v24);
}



/* Code for lto_setequalq */

static Lisp_Object CC_lto_setequalq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_setequalq");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v50 = qvalue(elt(env, 1)); /* !*rlsetequalqhash */
    if (v50 == nil) goto v11;
    v51 = stack[-1];
    v50 = stack[0];
    fn = elt(env, 4); /* lto_hashequalq */
    v50 = (*qfn2(fn))(qenv(fn), v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    goto v23;

v23:
    if (v50 == nil) goto v9;
    v50 = qvalue(elt(env, 3)); /* t */
    v52 = v50;
    goto v54;

v54:
    v50 = v52;
    if (v50 == nil) { popv(3); return onevalue(v52); }
    v50 = stack[-1];
    if (v50 == nil) { popv(3); return onevalue(v52); }
    v50 = stack[-1];
    v50 = qcar(v50);
    v51 = v50;
    v50 = stack[0];
    v50 = Lmemq(nil, v51, v50);
    if (v50 == nil) goto v55;
    v50 = stack[-1];
    v50 = qcdr(v50);
    stack[-1] = v50;
    goto v54;

v55:
    v50 = qvalue(elt(env, 2)); /* nil */
    v52 = v50;
    goto v54;

v9:
    v50 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v50); }

v11:
    v51 = stack[-1];
    v50 = stack[0];
    fn = elt(env, 5); /* lto_equallengthp */
    v50 = (*qfn2(fn))(qenv(fn), v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    goto v23;
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for !*d2n */

static Lisp_Object CC_Hd2n(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *d2n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v0;
/* end of prologue */
    v13 = v47;
    if (!(v13 == nil)) return onevalue(v47);
    v47 = (Lisp_Object)1; /* 0 */
    return onevalue(v47);
}



/* Code for compress!* */

static Lisp_Object CC_compressH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v66, v67;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compress*");
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
    v64 = v0;
/* end of prologue */
    v67 = nil;
    v65 = v64;
    v65 = qcar(v65);
    v65 = Ldigitp(nil, v65);
    env = stack[-1];
    if (v65 == nil) goto v44;
        popv(2);
        return Lcompress(nil, v64);

v44:
    stack[0] = v64;
    goto v68;

v68:
    v64 = stack[0];
    if (v64 == nil) goto v23;
    v64 = stack[0];
    v64 = qcar(v64);
    v66 = v64;
    v65 = v66;
    v64 = elt(env, 2); /* !/ */
    if (v65 == v64) goto v69;
    v65 = v66;
    v64 = elt(env, 3); /* !- */
    if (v65 == v64) goto v69;
    v65 = v66;
    v64 = elt(env, 4); /* !; */
    if (v65 == v64) goto v69;
    v65 = v66;
    v64 = elt(env, 5); /* !. */
    if (v65 == v64) goto v69;
    v64 = v66;
    v65 = v67;
    v64 = cons(v64, v65);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v67 = v64;
    goto v45;

v45:
    v64 = stack[0];
    v64 = qcdr(v64);
    stack[0] = v64;
    goto v68;

v69:
    v65 = v66;
    v64 = elt(env, 6); /* !! */
    v66 = v67;
    v64 = list2star(v65, v64, v66);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    v67 = v64;
    goto v45;

v23:
    v64 = v67;
    v64 = Lnreverse(nil, v64);
    env = stack[-1];
    v64 = Lcompress(nil, v64);
    nil = C_nil;
    if (exception_pending()) goto v70;
        popv(2);
        return Lintern(nil, v64);
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for printout */

static Lisp_Object CC_printout(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for printout");
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
    v72 = qvalue(elt(env, 1)); /* !*web */
    if (!(v72 == nil)) goto v34;
    v72 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    goto v34;

v34:
    v72 = qvalue(elt(env, 1)); /* !*web */
    if (!(v72 == nil)) goto v47;
    v72 = (Lisp_Object)17; /* 1 */
    stack[-1] = v72;
    goto v49;

v49:
    v50 = qvalue(elt(env, 2)); /* indent */
    v72 = stack[-1];
    v72 = difference2(v50, v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    v72 = Lminusp(nil, v72);
    env = stack[-2];
    if (!(v72 == nil)) goto v47;
    v72 = elt(env, 4); /* " " */
    v72 = Lprinc(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    v72 = stack[-1];
    v72 = add1(v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    stack[-1] = v72;
    goto v49;

v47:
    v72 = stack[0];
    v72 = Lconsp(nil, v72);
    env = stack[-2];
    if (v72 == nil) goto v59;
    v72 = stack[0];
    v50 = qcar(v72);
    v72 = elt(env, 5); /* !:rd!: */
    if (v50 == v72) goto v63;
    v72 = stack[0];
    v50 = qcar(v72);
    v72 = elt(env, 6); /* !:rn!: */
    if (v50 == v72) goto v63;
    v72 = stack[0];
    v72 = Lprinc(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    goto v8;

v8:
    v72 = nil;
    { popv(3); return onevalue(v72); }

v63:
    v72 = stack[0];
    fn = elt(env, 7); /* ma_print */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    goto v8;

v59:
    v72 = stack[0];
    v72 = Lprinc(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    goto v8;
/* error exit handlers */
v73:
    popv(3);
    return nil;
}



/* Code for retimes */

static Lisp_Object CC_retimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retimes");
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
    v18 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*bool */
    qvalue(elt(env, 1)) = nil; /* !*bool */
    fn = elt(env, 4); /* retimes1 */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v63 = v18;
    if (v63 == nil) goto v42;
    v63 = v18;
    v63 = qcdr(v63);
    if (v63 == nil) goto v22;
    v63 = elt(env, 2); /* times */
    v18 = cons(v63, v18);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    goto v36;

v36:
    v63 = qvalue(elt(env, 1)); /* !*bool */
    if (v63 == nil) goto v6;
    v63 = elt(env, 3); /* minus */
    v18 = list2(v63, v18);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    goto v6;

v6:
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    { popv(2); return onevalue(v18); }

v22:
    v18 = qcar(v18);
    goto v36;

v42:
    v18 = (Lisp_Object)17; /* 1 */
    goto v36;
/* error exit handlers */
v75:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*bool */
    popv(2);
    return nil;
}



/* Code for ps!:last!-term */

static Lisp_Object CC_psTlastKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:last-term");
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
    v9 = v0;
/* end of prologue */
    v8 = v9;
    if (!consp(v8)) goto v6;
    v8 = v9;
    v31 = qcar(v8);
    v8 = elt(env, 1); /* !:ps!: */
    if (v31 == v8) goto v20;
    v8 = v9;
    v31 = qcar(v8);
    v8 = elt(env, 2); /* dname */
    v8 = get(v31, v8);
    env = stack[0];
    if (!(v8 == nil)) goto v6;

v20:
    v8 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v9, v8);
    }

v6:
    v8 = qvalue(elt(env, 3)); /* ps!:max!-order */
    { popv(1); return onevalue(v8); }
}



/* Code for round!:mt */

static Lisp_Object CC_roundTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for round:mt");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v0;
/* end of prologue */
    v86 = stack[-2];
    v85 = elt(env, 1); /* !:rd!: */
    if (!consp(v86)) goto v87;
    v86 = qcar(v86);
    if (!(v86 == v85)) goto v87;
    v85 = stack[-2];
    v85 = qcdr(v85);
    if (!consp(v85)) goto v87;
    v85 = stack[-1];
    v85 = integerp(v85);
    if (v85 == nil) goto v87;
    v86 = stack[-1];
    v85 = (Lisp_Object)1; /* 0 */
    v85 = (Lisp_Object)greaterp2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v85 = v85 ? lisp_true : nil;
    env = stack[-4];
    if (v85 == nil) goto v87;
    v85 = stack[-2];
    v85 = qcdr(v85);
    v85 = qcar(v85);
    v85 = Labsval(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    fn = elt(env, 3); /* msd */
    v86 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v85 = stack[-1];
    v85 = difference2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v86 = sub1(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    stack[-1] = v86;
    v85 = (Lisp_Object)1; /* 0 */
    v85 = (Lisp_Object)lessp2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v85 = v85 ? lisp_true : nil;
    env = stack[-4];
    if (!(v85 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v86 = stack[-1];
    v85 = (Lisp_Object)1; /* 0 */
    if (v86 == v85) goto v89;
    stack[-3] = elt(env, 1); /* !:rd!: */
    v85 = stack[-2];
    v85 = qcdr(v85);
    stack[0] = qcar(v85);
    v85 = stack[-1];
    v85 = negate(v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v85 = stack[-2];
    v85 = qcdr(v85);
    v86 = qcdr(v85);
    v85 = stack[-1];
    v85 = plus2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    v85 = list2star(stack[-3], stack[0], v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 4); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v85);
    }

v89:
    v85 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v85);
    }

v87:
    stack[0] = (Lisp_Object)1; /* 0 */
    v86 = elt(env, 2); /* "Invalid argument to" */
    v85 = elt(env, 0); /* round!:mt */
    v85 = list2(v86, v85);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-4];
    {
        Lisp_Object v90 = stack[0];
        popv(5);
        fn = elt(env, 5); /* error */
        return (*qfn2(fn))(qenv(fn), v90, v85);
    }
/* error exit handlers */
v88:
    popv(5);
    return nil;
}



/* Code for c!:ordexn */

static Lisp_Object CC_cTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordexn");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    stack[-3] = nil;
    goto v74;

v74:
    v95 = stack[-1];
    if (v95 == nil) goto v5;
    v80 = stack[-2];
    v95 = stack[-1];
    v95 = qcar(v95);
    if (equal(v80, v95)) goto v45;
    v95 = stack[-2];
    v95 = Lconsp(nil, v95);
    env = stack[-4];
    if (v95 == nil) goto v35;
    v95 = stack[-1];
    v95 = qcar(v95);
    v95 = Lconsp(nil, v95);
    env = stack[-4];
    if (!(v95 == nil)) goto v45;

v35:
    v80 = stack[-2];
    v95 = stack[-1];
    v95 = qcar(v95);
    fn = elt(env, 2); /* c!:ordxp */
    v95 = (*qfn2(fn))(qenv(fn), v80, v95);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    if (v95 == nil) goto v96;
    v80 = stack[-2];
    v95 = stack[-3];
    v95 = cons(v80, v95);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    v80 = Lreverse(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    v95 = stack[-1];
    v95 = Lappend(nil, v80, v95);
    nil = C_nil;
    if (exception_pending()) goto v87;
    {
        Lisp_Object v97 = stack[0];
        popv(5);
        return cons(v97, v95);
    }

v96:
    v95 = stack[-1];
    v80 = qcar(v95);
    v95 = stack[-3];
    v95 = cons(v80, v95);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    stack[-3] = v95;
    v95 = stack[-1];
    v95 = qcdr(v95);
    stack[-1] = v95;
    v95 = stack[0];
    v95 = (v95 == nil ? lisp_true : nil);
    stack[0] = v95;
    goto v74;

v45:
    v95 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v95); }

v5:
    v80 = stack[-2];
    v95 = stack[-3];
    v95 = cons(v80, v95);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    v95 = Lreverse(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v87;
    {
        Lisp_Object v98 = stack[0];
        popv(5);
        return cons(v98, v95);
    }
/* error exit handlers */
v87:
    popv(5);
    return nil;
}



/* Code for !:zerop */

static Lisp_Object CC_Tzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :zerop");
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
    v31 = v0;
/* end of prologue */
    v8 = v31;
    if (v8 == nil) goto v6;
    v9 = v31;
    v8 = (Lisp_Object)1; /* 0 */
    if (v9 == v8) goto v6;
    v8 = v31;
    if (!consp(v8)) goto v68;
    v8 = v31;
    v9 = qcar(v8);
    v8 = elt(env, 3); /* zerop */
    v8 = get(v9, v8);
    v9 = v31;
        return Lapply1(nil, v8, v9);

v68:
    v8 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v8);

v6:
    v8 = qvalue(elt(env, 1)); /* t */
    return onevalue(v8);
}



/* Code for mval */

static Lisp_Object CC_mval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v10;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    return onevalue(v10);
}



/* Code for bcprod */

static Lisp_Object CC_bcprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcprod");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v16 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v16 == nil) goto v30;
    v17 = stack[-1];
    v16 = stack[0];
    v16 = times2(v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v16);
    }

v30:
    v32 = stack[-1];
    v17 = stack[0];
    v16 = elt(env, 2); /* times */
    fn = elt(env, 4); /* bcint2op */
    v16 = (*qfnn(fn))(qenv(fn), 3, v32, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    if (!(v16 == nil)) { popv(3); return onevalue(v16); }
    v17 = stack[-1];
    v16 = stack[0];
    fn = elt(env, 5); /* multsq */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bccheckz */
        return (*qfn1(fn))(qenv(fn), v16);
    }
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for sublistp */

static Lisp_Object CC_sublistp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v16, v17, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sublistp");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v16 = v7;
    v17 = v0;
/* end of prologue */

v99:
    v31 = v17;
    v31 = (v31 == nil ? lisp_true : nil);
    if (!(v31 == nil)) { popv(2); return onevalue(v31); }
    v31 = v17;
    v32 = qcar(v31);
    v31 = v16;
    v31 = Lmember(nil, v32, v31);
    if (v31 == nil) goto v100;
    v31 = v17;
    stack[0] = qcdr(v31);
    v31 = v17;
    v31 = qcar(v31);
    v31 = Ldelete(nil, v31, v16);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-1];
    v17 = stack[0];
    v16 = v31;
    goto v99;

v100:
    v31 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v31); }
/* error exit handlers */
v63:
    popv(2);
    return nil;
}



/* Code for chundexp */

static Lisp_Object CC_chundexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v102;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chundexp");
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
    v58 = stack[-1];
    v58 = Lexplodec(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    stack[-1] = v58;
    v58 = stack[-1];
    stack[-2] = v58;
    v102 = stack[-1];
    v58 = elt(env, 1); /* !_ */
    if (!consp(v102)) goto v34;
    v102 = qcar(v102);
    if (!(v102 == v58)) goto v34;
    v58 = stack[-1];
    v58 = qcdr(v58);
    if (v58 == nil) goto v34;
    v102 = elt(env, 2); /* !\ */
    v58 = stack[-1];
    v58 = cons(v102, v58);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    stack[-1] = v58;
    goto v34;

v34:
    v58 = stack[-2];
    v58 = qcdr(v58);
    if (v58 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v58 = stack[-2];
    v58 = qcdr(v58);
    v102 = qcar(v58);
    v58 = elt(env, 1); /* !_ */
    if (!(v102 == v58)) goto v31;
    stack[0] = stack[-2];
    v102 = elt(env, 2); /* !\ */
    v58 = stack[-2];
    v58 = qcdr(v58);
    v58 = cons(v102, v58);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v58 = Lrplacd(nil, stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    goto v31;

v31:
    v58 = stack[-2];
    v58 = qcdr(v58);
    stack[-2] = v58;
    goto v34;
/* error exit handlers */
v52:
    popv(4);
    return nil;
}



/* Code for !:times */

static Lisp_Object CC_Ttimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :times");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v7;
    v31 = v0;
/* end of prologue */
    v8 = v31;
    if (v8 == nil) goto v34;
    v8 = v9;
    if (v8 == nil) goto v34;
    v8 = v31;
    if (!(!consp(v8))) goto v101;
    v8 = v9;
    if (!(!consp(v8))) goto v101;
    v8 = v31;
    return times2(v8, v9);

v101:
    v8 = elt(env, 2); /* times */
    {
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v31, v9, v8);
    }

v34:
    v8 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v8);
}



/* Code for listsum */

static Lisp_Object CC_listsum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listsum");
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
    goto v44;

v44:
    v17 = stack[0];
    if (v17 == nil) goto v74;
    v17 = stack[0];
    v32 = qcar(v17);
    v17 = stack[-1];
    v17 = cons(v32, v17);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    stack[-1] = v17;
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v44;

v74:
    v17 = (Lisp_Object)1; /* 0 */
    v32 = v17;
    goto v36;

v36:
    v17 = stack[-1];
    if (v17 == nil) { popv(3); return onevalue(v32); }
    v17 = stack[-1];
    v17 = qcar(v17);
    v17 = plus2(v17, v32);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v32 = v17;
    v17 = stack[-1];
    v17 = qcdr(v17);
    stack[-1] = v17;
    goto v36;
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for !*physopp */

static Lisp_Object CC_Hphysopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *physopp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v17 = v32;
    if (!consp(v17)) goto v6;
    v17 = v32;
    v17 = qcar(v17);
    if (symbolp(v17)) goto v19;
    v17 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v17);

v19:
    v17 = v32;
    v17 = qcar(v17);
    v32 = elt(env, 2); /* phystype */
    return get(v17, v32);

v6:
    v17 = v32;
    if (symbolp(v17)) goto v23;
    v17 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v17);

v23:
    v17 = v32;
    v32 = elt(env, 2); /* phystype */
    return get(v17, v32);
}



/* Code for expdrmacro */

static Lisp_Object CC_expdrmacro(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expdrmacro");
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
    fn = elt(env, 6); /* getrmacro */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v17 = v31;
    if (v31 == nil) goto v74;
    v16 = stack[0];
    v31 = elt(env, 1); /* noexpand */
    v31 = Lflagp(nil, v16, v31);
    env = stack[-1];
    if (!(v31 == nil)) goto v74;
    v31 = qvalue(elt(env, 3)); /* !*cref */
    if (v31 == nil) { popv(2); return onevalue(v17); }
    v16 = stack[0];
    v31 = elt(env, 4); /* expand */
    v31 = Lflagp(nil, v16, v31);
    env = stack[-1];
    if (!(v31 == nil)) { popv(2); return onevalue(v17); }
    v31 = qvalue(elt(env, 5)); /* !*force */
    if (!(v31 == nil)) { popv(2); return onevalue(v17); }
    v31 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v31); }

v74:
    v31 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v31); }
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for aeval!* */

static Lisp_Object CC_aevalH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aeval*");
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
    stack[-1] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v24 = qvalue(elt(env, 2)); /* nil */
    v24 = ncons(v24);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    qvalue(elt(env, 1)) = v24; /* alglist!* */
    v23 = stack[0];
    v24 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* reval1 */
    v24 = (*qfn2(fn))(qenv(fn), v23, v24);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    { popv(3); return onevalue(v24); }
/* error exit handlers */
v15:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* alglist!* */
    popv(3);
    return nil;
}



/* Code for adddm */

static Lisp_Object CC_adddm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v50, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adddm");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v50 = v7;
    v51 = v0;
/* end of prologue */
    v72 = v51;
    if (!(!consp(v72))) goto v104;
    v72 = v50;
    if (!(!consp(v72))) goto v104;
    v72 = v51;
    v72 = plus2(v72, v50);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[0];
    v51 = v72;
    v72 = qvalue(elt(env, 1)); /* dmode!* */
    if (v72 == nil) goto v5;
    v50 = qvalue(elt(env, 1)); /* dmode!* */
    v72 = elt(env, 2); /* convert */
    v72 = Lflagp(nil, v50, v72);
    env = stack[0];
    if (v72 == nil) goto v5;
    v50 = qvalue(elt(env, 1)); /* dmode!* */
    v72 = elt(env, 4); /* i2d */
    v72 = get(v50, v72);
    env = stack[0];
    v50 = v51;
    v72 = Lapply1(nil, v72, v50);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v72);
    }

v5:
    v72 = v51;
    v72 = (Lisp_Object)zerop(v72);
    v72 = v72 ? lisp_true : nil;
    env = stack[0];
    if (v72 == nil) { popv(1); return onevalue(v51); }
    v72 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v72); }

v104:
    v72 = elt(env, 5); /* plus */
    {
        popv(1);
        fn = elt(env, 7); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v51, v50, v72);
    }
/* error exit handlers */
v52:
    popv(1);
    return nil;
}



/* Code for mo_vdivides!? */

static Lisp_Object CC_mo_vdividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_vdivides?");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v27 = stack[-1];
    fn = elt(env, 2); /* mo_comp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-3];
    v27 = stack[0];
    fn = elt(env, 2); /* mo_comp */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-3];
    v27 = Leqn(nil, stack[-2], v27);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-3];
    if (v27 == nil) goto v34;
    v45 = stack[-1];
    v27 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v45, v27);
    }

v34:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v27); }
/* error exit handlers */
v101:
    popv(4);
    return nil;
}



/* Code for unpkp */

static Lisp_Object CC_unpkp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v90, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unpkp");
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
    v88 = stack[-1];
    if (!(!consp(v88))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v88 = stack[-1];
    v88 = Lexplode(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    stack[-1] = v88;
    v88 = stack[-1];
    v90 = Llength(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v88 = (Lisp_Object)161; /* 10 */
    v88 = (Lisp_Object)geq2(v90, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v88 = v88 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v88;
    v88 = stack[0];
    if (v88 == nil) goto v32;
    v88 = stack[-1];
    v88 = Llength(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v88 = Levenp(nil, v88);
    env = stack[-3];
    if (!(v88 == nil)) goto v32;
    v90 = elt(env, 1); /* !0 */
    v88 = stack[-1];
    v88 = cons(v90, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    stack[-1] = v88;
    goto v32;

v32:
    v88 = stack[-1];
    if (v88 == nil) goto v17;
    v88 = stack[0];
    if (v88 == nil) goto v112;
    v88 = stack[-1];
    v90 = qcar(v88);
    v88 = qvalue(elt(env, 3)); /* diglist!* */
    v88 = Lassoc(nil, v90, v88);
    v88 = qcdr(v88);
    v90 = v88;
    v88 = stack[-1];
    v88 = qcdr(v88);
    stack[-1] = v88;
    v88 = (Lisp_Object)161; /* 10 */
    v110 = times2(v90, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v88 = stack[-1];
    v90 = qcar(v88);
    v88 = qvalue(elt(env, 3)); /* diglist!* */
    v88 = Lassoc(nil, v90, v88);
    v88 = qcdr(v88);
    v90 = plus2(v110, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    v88 = stack[-2];
    v88 = cons(v90, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    stack[-2] = v88;
    goto v35;

v35:
    v88 = stack[-1];
    v88 = qcdr(v88);
    stack[-1] = v88;
    goto v32;

v112:
    v88 = stack[-1];
    v90 = qcar(v88);
    v88 = qvalue(elt(env, 3)); /* diglist!* */
    v88 = Lassoc(nil, v90, v88);
    v90 = qcdr(v88);
    v88 = stack[-2];
    v88 = cons(v90, v88);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-3];
    stack[-2] = v88;
    goto v35;

v17:
    v88 = stack[-2];
        popv(4);
        return Lnreverse(nil, v88);
/* error exit handlers */
v111:
    popv(4);
    return nil;
}



/* Code for !*i2mod */

static Lisp_Object CC_Hi2mod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2mod");
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
    v34 = v0;
/* end of prologue */
    fn = elt(env, 1); /* general!-modular!-number */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v34);
    }
/* error exit handlers */
v44:
    popv(1);
    return nil;
}



/* Code for general!-modular!-plus */

static Lisp_Object CC_generalKmodularKplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-plus");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v19 = v7;
    v25 = v0;
/* end of prologue */
    v19 = plus2(v25, v19);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    stack[0] = v19;
    v25 = stack[0];
    v19 = qvalue(elt(env, 1)); /* current!-modulus */
    v19 = (Lisp_Object)geq2(v25, v19);
    nil = C_nil;
    if (exception_pending()) goto v29;
    v19 = v19 ? lisp_true : nil;
    env = stack[-1];
    if (v19 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v25 = stack[0];
    v19 = qvalue(elt(env, 1)); /* current!-modulus */
    v19 = difference2(v25, v19);
    nil = C_nil;
    if (exception_pending()) goto v29;
    stack[0] = v19;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for remainder!-in!-vector */

static Lisp_Object MS_CDECL CC_remainderKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v7,
                         Lisp_Object v28, Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v131, v132, v133, v134, v135, v136, v137, v138, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "remainder-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remainder-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v10,v28,v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v7,v28,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v28;
    stack[-2] = v7;
    stack[-3] = v0;
/* end of prologue */
    v131 = stack[0];
    v130 = (Lisp_Object)1; /* 0 */
    if (v131 == v130) goto v1;
    v131 = stack[0];
    v130 = (Lisp_Object)-15; /* -1 */
    if (!(v131 == v130)) goto v19;
    v130 = elt(env, 1); /* "ATTEMPT TO DIVIDE BY ZERO" */
    fn = elt(env, 3); /* errorf */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    goto v19;

v19:
    v131 = stack[-1];
    v130 = stack[0];
    v130 = *(Lisp_Object *)((char *)v131 + (CELL-TAG_VECTOR) + ((int32_t)v130/(16/CELL)));
    v130 = Lmodular_reciprocal(nil, v130);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v130);
        if (w != 0) w = current_modulus - w;
        v130 = fixnum_of_int(w);
    }
    v137 = v130;
    v130 = stack[0];
    v130 = (Lisp_Object)((int32_t)(v130) - 0x10);
    v138 = v130;
    goto v141;

v141:
    v131 = stack[-2];
    v130 = stack[0];
    v131 = (Lisp_Object)(int32_t)((int32_t)v131 - (int32_t)v130 + TAG_FIXNUM);
    v139 = v131;
    v130 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v131)) < ((int32_t)(v130))) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v132 = v137;
    v131 = stack[-3];
    v130 = stack[-2];
    v130 = *(Lisp_Object *)((char *)v131 + (CELL-TAG_VECTOR) + ((int32_t)v130/(16/CELL)));
    v130 = Lmodular_times(nil, v132, v130);
    env = stack[-4];
    v136 = v130;
    v130 = (Lisp_Object)1; /* 0 */
    v135 = v130;
    goto v65;

v65:
    v131 = v138;
    v130 = v135;
    v130 = (Lisp_Object)(int32_t)((int32_t)v131 - (int32_t)v130 + TAG_FIXNUM);
    v130 = ((intptr_t)(v130) < 0 ? lisp_true : nil);
    if (v130 == nil) goto v142;
    v130 = stack[-2];
    v130 = (Lisp_Object)((int32_t)(v130) - 0x10);
    stack[-2] = v130;
    goto v143;

v143:
    v131 = stack[-2];
    v130 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v131)) < ((int32_t)(v130))) goto v141;
    v131 = stack[-3];
    v130 = stack[-2];
    v131 = *(Lisp_Object *)((char *)v131 + (CELL-TAG_VECTOR) + ((int32_t)v130/(16/CELL)));
    v130 = (Lisp_Object)1; /* 0 */
    if (!(v131 == v130)) goto v141;
    v130 = stack[-2];
    v130 = (Lisp_Object)((int32_t)(v130) - 0x10);
    stack[-2] = v130;
    goto v143;

v142:
    v134 = stack[-3];
    v131 = v135;
    v130 = v139;
    v133 = (Lisp_Object)(int32_t)((int32_t)v131 + (int32_t)v130 - TAG_FIXNUM);
    v132 = stack[-3];
    v131 = v135;
    v130 = v139;
    v130 = (Lisp_Object)(int32_t)((int32_t)v131 + (int32_t)v130 - TAG_FIXNUM);
    v132 = *(Lisp_Object *)((char *)v132 + (CELL-TAG_VECTOR) + ((int32_t)v130/(16/CELL)));
    v131 = stack[-1];
    v130 = v135;
    v131 = *(Lisp_Object *)((char *)v131 + (CELL-TAG_VECTOR) + ((int32_t)v130/(16/CELL)));
    v130 = v136;
    v130 = Lmodular_times(nil, v131, v130);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v132) + int_of_fixnum(v130);
        if (w >= current_modulus) w -= current_modulus;
        v130 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v134 + (CELL-TAG_VECTOR) + ((int32_t)v133/(16/CELL))) = v130;
    v130 = v135;
    v130 = (Lisp_Object)((int32_t)(v130) + 0x10);
    v135 = v130;
    goto v65;

v1:
    v130 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v130); }
/* error exit handlers */
v140:
    popv(5);
    return nil;
}



/* Code for split_form */

static Lisp_Object CC_split_form(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_form");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v14 = v7;
    v15 = v0;
/* end of prologue */
    stack[-2] = v15;
    stack[-1] = v14;
    stack[0] = (Lisp_Object)17; /* 1 */
    v14 = qvalue(elt(env, 1)); /* nil */
    v14 = ncons(v14);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    {
        Lisp_Object v21 = stack[-2];
        Lisp_Object v22 = stack[-1];
        Lisp_Object v49 = stack[0];
        popv(4);
        fn = elt(env, 2); /* split_f */
        return (*qfnn(fn))(qenv(fn), 4, v21, v22, v49, v14);
    }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for ofsf_posdefp */

static Lisp_Object CC_ofsf_posdefp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_posdefp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v0;
/* end of prologue */
    v1 = qvalue(elt(env, 1)); /* !*rlpos */
    if (v1 == nil) goto v42;
    v1 = v2;
    {
        fn = elt(env, 2); /* ofsf_posdefp!-pos */
        return (*qfn1(fn))(qenv(fn), v1);
    }

v42:
    v1 = v2;
    {
        fn = elt(env, 3); /* sfto_tsqsumf */
        return (*qfn1(fn))(qenv(fn), v1);
    }
}



/* Code for mcharg */

static Lisp_Object MS_CDECL CC_mcharg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v7,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mcharg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v7,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v28;
    stack[0] = v7;
    v150 = v0;
/* end of prologue */
    v149 = elt(env, 1); /* minus */
    v148 = stack[0];
    v148 = Latsoc(nil, v149, v148);
    if (v148 == nil) goto v74;
    v149 = v150;
    v148 = stack[0];
    fn = elt(env, 4); /* reform!-minus */
    v150 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-5];
    v149 = stack[0];
    v148 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* mcharg1 */
        return (*qfnn(fn))(qenv(fn), 3, v150, v149, v148);
    }

v74:
    v148 = stack[0];
    if (v148 == nil) goto v152;
    v148 = stack[0];
    v149 = qcar(v148);
    v148 = elt(env, 2); /* slash */
    if (!consp(v149)) goto v152;
    v149 = qcar(v149);
    if (!(v149 == v148)) goto v152;
    v149 = v150;
    v148 = stack[0];
    fn = elt(env, 6); /* reform!-minus2 */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-5];
    stack[-4] = v148;
    goto v153;

v153:
    v148 = stack[-4];
    if (v148 == nil) goto v69;
    v148 = stack[-4];
    v148 = qcar(v148);
    v149 = v148;
    v150 = qcar(v149);
    v149 = qcdr(v148);
    v148 = stack[-3];
    fn = elt(env, 5); /* mcharg1 */
    v148 = (*qfnn(fn))(qenv(fn), 3, v150, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-5];
    stack[-2] = v148;
    v148 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-5];
    stack[-1] = v148;
    v148 = stack[-4];
    v148 = qcdr(v148);
    stack[-4] = v148;
    v148 = stack[-1];
    if (!consp(v148)) goto v153;
    else goto v61;

v61:
    v148 = stack[-4];
    if (v148 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v148 = stack[-4];
    v148 = qcar(v148);
    v149 = v148;
    v150 = qcar(v149);
    v149 = qcdr(v148);
    v148 = stack[-3];
    fn = elt(env, 5); /* mcharg1 */
    v148 = (*qfnn(fn))(qenv(fn), 3, v150, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-5];
    v148 = Lrplacd(nil, stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-5];
    v148 = stack[-1];
    fn = elt(env, 7); /* lastpair */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-5];
    stack[-1] = v148;
    v148 = stack[-4];
    v148 = qcdr(v148);
    stack[-4] = v148;
    goto v61;

v69:
    v148 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v148); }

v152:
    v149 = stack[0];
    v148 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* mcharg1 */
        return (*qfnn(fn))(qenv(fn), 3, v150, v149, v148);
    }
/* error exit handlers */
v151:
    popv(6);
    return nil;
}



/* Code for multsq */

static Lisp_Object CC_multsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v7;
    stack[-3] = v0;
/* end of prologue */
    v150 = stack[-3];
    v150 = qcar(v150);
    if (v150 == nil) goto v2;
    v150 = stack[-2];
    v150 = qcar(v150);
    if (v150 == nil) goto v2;
    v150 = stack[-3];
    v157 = qcdr(v150);
    v150 = (Lisp_Object)17; /* 1 */
    if (!(v157 == v150)) goto v92;
    v150 = stack[-2];
    v157 = qcdr(v150);
    v150 = (Lisp_Object)17; /* 1 */
    if (!(v157 == v150)) goto v92;
    v150 = stack[-3];
    v157 = qcar(v150);
    v150 = stack[-2];
    v150 = qcar(v150);
    fn = elt(env, 2); /* multf */
    v157 = (*qfn2(fn))(qenv(fn), v157, v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v150 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v157, v150);

v92:
    v150 = stack[-3];
    v157 = qcar(v150);
    v150 = stack[-2];
    v150 = qcdr(v150);
    fn = elt(env, 3); /* gcdf */
    v150 = (*qfn2(fn))(qenv(fn), v157, v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-4] = v150;
    v150 = stack[-2];
    v157 = qcar(v150);
    v150 = stack[-3];
    v150 = qcdr(v150);
    fn = elt(env, 3); /* gcdf */
    v150 = (*qfn2(fn))(qenv(fn), v157, v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-1] = v150;
    v150 = stack[-3];
    v157 = qcar(v150);
    v150 = stack[-4];
    fn = elt(env, 4); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v157, v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v150 = stack[-2];
    v157 = qcar(v150);
    v150 = stack[-1];
    fn = elt(env, 4); /* quotf */
    v150 = (*qfn2(fn))(qenv(fn), v157, v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    fn = elt(env, 2); /* multf */
    v150 = (*qfn2(fn))(qenv(fn), stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[0] = v150;
    v150 = stack[-3];
    v157 = qcdr(v150);
    v150 = stack[-1];
    fn = elt(env, 4); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v157, v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    v150 = stack[-2];
    v157 = qcdr(v150);
    v150 = stack[-4];
    fn = elt(env, 4); /* quotf */
    v150 = (*qfn2(fn))(qenv(fn), v157, v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    fn = elt(env, 2); /* multf */
    v150 = (*qfn2(fn))(qenv(fn), stack[-1], v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    stack[-4] = v150;
    v157 = stack[0];
    v150 = stack[-4];
    v150 = cons(v157, v150);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v150);
    }

v2:
    v157 = qvalue(elt(env, 1)); /* nil */
    v150 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v157, v150);
/* error exit handlers */
v124:
    popv(6);
    return nil;
}



/* Code for qqe_qopheadp */

static Lisp_Object CC_qqe_qopheadp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_qopheadp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v100 = v0;
/* end of prologue */
    v47 = elt(env, 1); /* (lhead rhead) */
    v100 = Lmemq(nil, v100, v47);
    return onevalue(v100);
}



/* Code for rl_simplat1 */

static Lisp_Object CC_rl_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v14 = v7;
    v15 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simplat1!* */
    v14 = list2(v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-1];
    {
        Lisp_Object v5 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v5, v14);
    }
/* error exit handlers */
v4:
    popv(2);
    return nil;
}



/* Code for setcar */

static Lisp_Object CC_setcar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v1;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setcar");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    v13 = v0;
/* end of prologue */
    v1 = v13;
    v13 = stack[0];
    v13 = Lrplaca(nil, v1, v13);
    nil = C_nil;
    if (exception_pending()) goto v24;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v24:
    popv(1);
    return nil;
}



/* Code for !:minus */

static Lisp_Object CC_Tminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v35, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :minus");
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
    v35 = v0;
/* end of prologue */
    v38 = v35;
    if (v38 == nil) goto v6;
    v38 = v35;
    if (!consp(v38)) goto v36;
    v38 = v35;
    v153 = qcar(v38);
    v38 = elt(env, 2); /* minus */
    v38 = get(v153, v38);
    env = stack[0];
    v153 = v38;
    v38 = v153;
    if (v38 == nil) goto v31;
    v38 = v153;
        popv(1);
        return Lapply1(nil, v38, v35);

v31:
    v153 = v35;
    v35 = (Lisp_Object)-15; /* -1 */
    v38 = elt(env, 3); /* times */
    {
        popv(1);
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v153, v35, v38);
    }

v36:
    v38 = v35;
    popv(1);
    return negate(v38);

v6:
    v38 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v38); }
}



/* Code for get_token */

static Lisp_Object MS_CDECL CC_get_token(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "get_token");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_token");
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
    v25 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v25;
    goto v13;

v13:
    v26 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    qvalue(elt(env, 2)) = v26; /* ch */
    v25 = elt(env, 3); /* !> */
    if (v26 == v25) goto v45;
    v26 = qvalue(elt(env, 2)); /* ch */
    v25 = stack[0];
    v25 = cons(v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    stack[0] = v25;
    goto v13;

v45:
    v26 = elt(env, 4); /* !$ */
    v25 = stack[0];
    popv(2);
    return cons(v26, v25);
/* error exit handlers */
v8:
    popv(2);
    return nil;
}



/* Code for dm!-abs */

static Lisp_Object CC_dmKabs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dm-abs");
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
    v25 = stack[0];
    if (!consp(v25)) goto v36;
    v25 = stack[0];
    v26 = qcar(v25);
    v25 = elt(env, 1); /* minusp */
    v26 = get(v26, v25);
    env = stack[-1];
    v25 = stack[0];
    v25 = Lapply1(nil, v26, v25);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    goto v74;

v74:
    if (v25 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v25 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* dm!-minus */
        return (*qfn1(fn))(qenv(fn), v25);
    }

v36:
    v25 = stack[0];
    v25 = Lminusp(nil, v25);
    env = stack[-1];
    goto v74;
/* error exit handlers */
v8:
    popv(2);
    return nil;
}



/* Code for bczero!? */

static Lisp_Object CC_bczeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bczero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v4 == nil) goto v24;
    v4 = v3;
    v3 = (Lisp_Object)1; /* 0 */
        return Leqn(nil, v4, v3);

v24:
    v3 = qcar(v3);
    v3 = (v3 == nil ? lisp_true : nil);
    return onevalue(v3);
}



/* Code for rd!:zerop */

static Lisp_Object CC_rdTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:zerop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v21 = v30;
    v21 = qcdr(v21);
    if (!consp(v21)) goto v6;
    v30 = qcdr(v30);
    v21 = qcar(v30);
    v30 = (Lisp_Object)1; /* 0 */
    v30 = (v21 == v30 ? lisp_true : nil);
    return onevalue(v30);

v6:
    v30 = qcdr(v30);
        return Lzerop(nil, v30);
}



/* Code for evzero!? */

static Lisp_Object CC_evzeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v49, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evzero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v49 = v0;
/* end of prologue */

v99:
    v22 = v49;
    v22 = (v22 == nil ? lisp_true : nil);
    if (!(v22 == nil)) return onevalue(v22);
    v22 = v49;
    v33 = qcar(v22);
    v22 = (Lisp_Object)1; /* 0 */
    if (v33 == v22) goto v3;
    v22 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v22);

v3:
    v22 = v49;
    v22 = qcdr(v22);
    v49 = v22;
    goto v99;
}



/* Code for wedgepf2 */

static Lisp_Object CC_wedgepf2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgepf2");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v0;
/* end of prologue */
    v71 = stack[-2];
    if (v71 == nil) goto v34;
    v71 = stack[-1];
    if (v71 == nil) goto v34;
    v71 = stack[-2];
    v89 = qcar(v71);
    v71 = stack[-1];
    v71 = qcar(v71);
    fn = elt(env, 2); /* wedget2 */
    stack[-3] = (*qfn2(fn))(qenv(fn), v89, v71);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v71 = stack[-2];
    v71 = qcar(v71);
    v89 = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v71 = stack[-1];
    v71 = qcdr(v71);
    stack[0] = CC_wedgepf2(env, v89, v71);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    v71 = stack[-2];
    v89 = qcdr(v71);
    v71 = stack[-1];
    v71 = CC_wedgepf2(env, v89, v71);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    fn = elt(env, 3); /* addpf */
    v71 = (*qfn2(fn))(qenv(fn), stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-4];
    {
        Lisp_Object v39 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* addpf */
        return (*qfn2(fn))(qenv(fn), v39, v71);
    }

v34:
    v71 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v71); }
/* error exit handlers */
v60:
    popv(5);
    return nil;
}



/* Code for update!-pline */

static Lisp_Object MS_CDECL CC_updateKpline(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v7,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v167, v168;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "update-pline");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for update-pline");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v7,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v168 = v28;
    stack[-4] = v7;
    stack[-5] = v0;
/* end of prologue */
    v167 = stack[-5];
    v166 = (Lisp_Object)1; /* 0 */
    if (!(v167 == v166)) goto v22;
    v167 = stack[-4];
    v166 = (Lisp_Object)1; /* 0 */
    if (v167 == v166) { popv(8); return onevalue(v168); }
    else goto v22;

v22:
    v166 = v168;
    stack[-6] = v166;
    v166 = stack[-6];
    if (v166 == nil) goto v25;
    v166 = stack[-6];
    v166 = qcar(v166);
    stack[0] = v166;
    v166 = stack[0];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = stack[-5];
    v168 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v166 = stack[0];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-5];
    v166 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v168 = cons(v168, v166);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-7];
    v166 = stack[0];
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-4];
    v167 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = acons(v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-7];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-7];
    stack[-2] = v166;
    stack[-3] = v166;
    goto v12;

v12:
    v166 = stack[-6];
    v166 = qcdr(v166);
    stack[-6] = v166;
    v166 = stack[-6];
    if (v166 == nil) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-2];
    v166 = stack[-6];
    v166 = qcar(v166);
    stack[0] = v166;
    v166 = stack[0];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcar(v166);
    v166 = stack[-5];
    v168 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v166 = stack[0];
    v166 = qcar(v166);
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-5];
    v166 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v168 = cons(v168, v166);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-7];
    v166 = stack[0];
    v166 = qcar(v166);
    v167 = qcdr(v166);
    v166 = stack[-4];
    v167 = (Lisp_Object)(int32_t)((int32_t)v167 + (int32_t)v166 - TAG_FIXNUM);
    v166 = stack[0];
    v166 = qcdr(v166);
    v166 = acons(v168, v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-7];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-7];
    v166 = Lrplacd(nil, stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-7];
    v166 = stack[-2];
    v166 = qcdr(v166);
    stack[-2] = v166;
    goto v12;

v25:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v166); }
/* error exit handlers */
v118:
    popv(8);
    return nil;
}



/* Code for !:plus */

static Lisp_Object CC_Tplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v89, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :plus");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v89 = v7;
    v141 = v0;
/* end of prologue */
    v71 = v141;
    if (v71 == nil) { popv(1); return onevalue(v89); }
    v71 = v89;
    if (v71 == nil) { popv(1); return onevalue(v141); }
    v71 = v141;
    if (!(!consp(v71))) goto v37;
    v71 = v89;
    if (!(!consp(v71))) goto v37;
    v71 = v141;
    v71 = plus2(v71, v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[0];
    v141 = v71;
    v89 = v141;
    v71 = (Lisp_Object)1; /* 0 */
    if (!(v89 == v71)) { popv(1); return onevalue(v141); }
    v71 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v71); }

v37:
    v71 = elt(env, 2); /* plus */
    {
        popv(1);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v141, v89, v71);
    }
/* error exit handlers */
v94:
    popv(1);
    return nil;
}



/* Code for fprin2 */

static Lisp_Object CC_fprin2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fprin2");
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
    v23 = v0;
/* end of prologue */
    v24 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*lower */
    qvalue(elt(env, 2)) = v24; /* !*lower */
    v24 = qvalue(elt(env, 3)); /* !*fortupper */
    if (v24 == nil) goto v47;
    v24 = v23;
    fn = elt(env, 4); /* prin2!-upcase */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    goto v34;

v34:
    qvalue(elt(env, 2)) = stack[0]; /* !*lower */
    { popv(2); return onevalue(v24); }

v47:
    v24 = v23;
    fn = elt(env, 5); /* prin2!-downcase */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    goto v34;
/* error exit handlers */
v14:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*lower */
    popv(2);
    return nil;
}



/* Code for powers0 */

static Lisp_Object CC_powers0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v156, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers0");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */

v99:
    v98 = stack[-1];
    if (v98 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v98 = stack[-1];
    if (!consp(v98)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v98 = stack[-1];
    v98 = qcar(v98);
    if (!consp(v98)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v98 = stack[-1];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v156 = qcar(v98);
    v98 = stack[0];
    v156 = Latsoc(nil, v156, v98);
    v98 = v156;
    if (v156 == nil) goto v59;
    v156 = stack[-1];
    v156 = qcar(v156);
    v156 = qcar(v156);
    v156 = qcdr(v156);
    v98 = qcdr(v98);
    v98 = (Lisp_Object)greaterp2(v156, v98);
    nil = C_nil;
    if (exception_pending()) goto v169;
    v98 = v98 ? lisp_true : nil;
    env = stack[-3];
    if (v98 == nil) goto v83;
    v98 = stack[-1];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v112 = qcar(v98);
    v98 = stack[-1];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v156 = qcdr(v98);
    v98 = stack[0];
    fn = elt(env, 1); /* repasc */
    v98 = (*qfnn(fn))(qenv(fn), 3, v112, v156, v98);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[0] = v98;
    goto v83;

v83:
    v98 = stack[-1];
    stack[-2] = qcdr(v98);
    v98 = stack[-1];
    v98 = qcar(v98);
    v156 = qcdr(v98);
    v98 = stack[0];
    v98 = CC_powers0(env, v156, v98);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v98;
    goto v99;

v59:
    v98 = stack[-1];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v112 = qcar(v98);
    v98 = stack[-1];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v156 = qcdr(v98);
    v98 = stack[0];
    v98 = acons(v112, v156, v98);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-3];
    stack[0] = v98;
    goto v83;
/* error exit handlers */
v169:
    popv(4);
    return nil;
}



/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domain*p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v0;
/* end of prologue */
    v33 = v27;
    v33 = (v33 == nil ? lisp_true : nil);
    if (!(v33 == nil)) return onevalue(v33);
    v33 = v27;
    v33 = (is_number(v33) ? lisp_true : nil);
    if (!(v33 == nil)) return onevalue(v33);
    v33 = v27;
    if (!consp(v33)) goto v13;
    v33 = v27;
    v33 = qcar(v33);
    v27 = qvalue(elt(env, 2)); /* domainlist!* */
    v33 = Lmemq(nil, v33, v27);
    return onevalue(v33);

v13:
    v33 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v33);
}



/* Code for union_edges */

static Lisp_Object CC_union_edges(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v27, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for union_edges");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v33 = v7;
    v27 = v0;
/* end of prologue */

v44:
    v45 = v27;
    if (v45 == nil) { popv(2); return onevalue(v33); }
    v45 = v27;
    v45 = qcdr(v45);
    stack[0] = v45;
    v27 = qcar(v27);
    fn = elt(env, 1); /* union_edge */
    v33 = (*qfn2(fn))(qenv(fn), v27, v33);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-1];
    v27 = stack[0];
    goto v44;
/* error exit handlers */
v11:
    popv(2);
    return nil;
}



/* Code for macrochk */

static Lisp_Object CC_macrochk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v104, v147, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for macrochk");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v41 = stack[-1];
    if (!consp(v41)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v41 = stack[-1];
    v41 = qcar(v41);
    fn = elt(env, 4); /* expdrmacro */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    v104 = v41;
    if (v41 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v147 = stack[0];
    v41 = elt(env, 1); /* symbolic */
    if (v147 == v41) goto v35;
    v41 = stack[-1];
    v41 = qcar(v41);
    if (!(symbolp(v41))) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v41 = stack[-1];
    v147 = qcar(v41);
    v41 = elt(env, 2); /* opfn */
    v41 = Lflagp(nil, v147, v41);
    env = stack[-2];
    if (v41 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else goto v35;

v35:
    v41 = v104;
    v147 = qcar(v41);
    v41 = elt(env, 3); /* macrofn */
    v59 = get(v147, v41);
    v41 = v104;
    v147 = qcdr(v41);
    v41 = stack[-1];
    v104 = qcdr(v41);
    v41 = stack[-1];
    v41 = qcar(v41);
        popv(3);
        return Lapply3(nil, 4, v59, v147, v104, v41);
/* error exit handlers */
v102:
    popv(3);
    return nil;
}



/* Code for reval_without_mod */

static Lisp_Object CC_reval_without_mod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval_without_mod");
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
    v30 = v0;
/* end of prologue */
    v5 = qvalue(elt(env, 1)); /* dmode!* */
    v4 = elt(env, 2); /* !:mod!: */
    if (v5 == v4) goto v6;
    v4 = v30;
    {
        popv(2);
        fn = elt(env, 4); /* reval */
        return (*qfn1(fn))(qenv(fn), v4);
    }

v6:
    v4 = qvalue(elt(env, 3)); /* nil */
    stack[0] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = v4; /* dmode!* */
    v4 = v30;
    fn = elt(env, 4); /* reval */
    v4 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    { popv(2); return onevalue(v4); }
/* error exit handlers */
v22:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* dmode!* */
    popv(2);
    return nil;
}



/* Code for angles!-equal */

static Lisp_Object CC_anglesKequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v37, v38;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for angles-equal");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v84 = (Lisp_Object)1; /* 0 */
    stack[-2] = v84;
    goto v68;

v68:
    v37 = stack[-1];
    v84 = stack[-2];
    v38 = *(Lisp_Object *)((char *)v37 + (CELL-TAG_VECTOR) + ((int32_t)v84/(16/CELL)));
    v37 = stack[0];
    v84 = stack[-2];
    v84 = *(Lisp_Object *)((char *)v37 + (CELL-TAG_VECTOR) + ((int32_t)v84/(16/CELL)));
    if (equal(v38, v84)) goto v42;
    v84 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v84); }

v42:
    v84 = stack[-2];
    v84 = add1(v84);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-3];
    stack[-2] = v84;
    v37 = stack[-2];
    v84 = (Lisp_Object)129; /* 8 */
    v84 = (Lisp_Object)lessp2(v37, v84);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v84 = v84 ? lisp_true : nil;
    env = stack[-3];
    if (!(v84 == nil)) goto v68;
    v84 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v84); }
/* error exit handlers */
v62:
    popv(4);
    return nil;
}



/* Code for mo!=sprod */

static Lisp_Object CC_moMsprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v141, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=sprod");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v94 = nil;
    goto v74;

v74:
    v89 = stack[-1];
    if (v89 == nil) goto v36;
    v89 = stack[0];
    if (v89 == nil) goto v36;
    v89 = stack[-1];
    v141 = qcar(v89);
    v89 = stack[0];
    v89 = qcar(v89);
    v89 = fixnum_of_int((int32_t)(int_of_fixnum(v141) * int_of_fixnum(v89)));
    v141 = v94;
    v89 = cons(v89, v141);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v94 = v89;
    v89 = stack[-1];
    v89 = qcdr(v89);
    stack[-1] = v89;
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v74;

v36:
    v89 = (Lisp_Object)1; /* 0 */
    goto v42;

v42:
    v141 = v94;
    if (v141 == nil) { popv(3); return onevalue(v89); }
    v141 = v94;
    v141 = qcar(v141);
    v89 = (Lisp_Object)(int32_t)((int32_t)v141 + (int32_t)v89 - TAG_FIXNUM);
    v141 = v94;
    v141 = qcdr(v141);
    v94 = v141;
    goto v42;
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for mtchp1 */

static Lisp_Object MS_CDECL CC_mtchp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v7,
                         Lisp_Object v28, Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v174, v175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mtchp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtchp1");
#endif
    if (stack >= stacklimit)
    {
        push4(v10,v28,v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v7,v28,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v173 = v10;
    stack[0] = v28;
    stack[-1] = v7;
    stack[-2] = v0;
/* end of prologue */
    v174 = stack[-2];
    v173 = stack[-1];
    if (equal(v174, v173)) goto v100;
    v173 = stack[-2];
    v174 = qcar(v173);
    v173 = stack[-1];
    v173 = qcar(v173);
    fn = elt(env, 4); /* mchk!* */
    v173 = (*qfn2(fn))(qenv(fn), v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    stack[-3] = v173;
    if (v173 == nil) goto v4;
    v173 = stack[-1];
    v174 = qcdr(v173);
    v173 = qvalue(elt(env, 2)); /* frlis!* */
    v173 = Lmemq(nil, v174, v173);
    if (v173 == nil) goto v19;
    v173 = stack[-2];
    v174 = qcdr(v173);
    v173 = (Lisp_Object)17; /* 1 */
    if (v174 == v173) goto v54;
    v173 = stack[-1];
    v175 = qcdr(v173);
    v174 = stack[-3];
    v173 = stack[-2];
    v173 = qcdr(v173);
    fn = elt(env, 5); /* powmtch */
    v173 = (*qfnn(fn))(qenv(fn), 3, v175, v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    stack[-3] = v173;
    if (v173 == nil) goto v54;
    stack[0] = stack[-3];
    v173 = stack[-1];
    v174 = qcdr(v173);
    v173 = stack[-2];
    v173 = qcdr(v173);
    v173 = cons(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    {
        Lisp_Object v177 = stack[0];
        popv(5);
        fn = elt(env, 6); /* mapcons */
        return (*qfn2(fn))(qenv(fn), v177, v173);
    }

v54:
    v173 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v173); }

v19:
    v173 = stack[0];
    if (v173 == nil) goto v67;
    v173 = stack[-2];
    v174 = qcdr(v173);
    v173 = stack[-1];
    v173 = qcdr(v173);
    if (!(equal(v174, v173))) goto v65;

v67:
    v173 = stack[-1];
    v173 = qcdr(v173);
    if (!(is_number(v173))) goto v65;
    v173 = stack[-2];
    v173 = qcdr(v173);
    if (!(is_number(v173))) goto v65;
    v173 = qvalue(elt(env, 3)); /* !*mcd */
    if (v173 == nil) goto v149;
    v173 = stack[-2];
    v174 = qcdr(v173);
    v173 = stack[-1];
    v173 = qcdr(v173);
    v173 = (Lisp_Object)lessp2(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v173 = v173 ? lisp_true : nil;
    env = stack[-4];
    goto v106;

v106:
    if (v173 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    else goto v65;

v65:
    v173 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v173); }

v149:
    v173 = stack[-2];
    v174 = qcdr(v173);
    v173 = stack[-1];
    v173 = qcdr(v173);
    v174 = times2(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v173 = (Lisp_Object)1; /* 0 */
    v173 = (Lisp_Object)lessp2(v174, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v173 = v173 ? lisp_true : nil;
    env = stack[-4];
    if (!(v173 == nil)) goto v106;
    v173 = stack[-2];
    v173 = qcdr(v173);
    stack[0] = Labsval(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v173 = stack[-1];
    v173 = qcdr(v173);
    v173 = Labsval(nil, v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v173 = (Lisp_Object)lessp2(stack[0], v173);
    nil = C_nil;
    if (exception_pending()) goto v176;
    v173 = v173 ? lisp_true : nil;
    env = stack[-4];
    goto v106;

v4:
    v173 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v173); }

v100:
    v173 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return ncons(v173);
/* error exit handlers */
v176:
    popv(5);
    return nil;
}



/* Code for pappl0 */

static Lisp_Object CC_pappl0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pappl0");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v1 = v7;
    v2 = v0;
/* end of prologue */
    stack[0] = v2;
    fn = elt(env, 1); /* unpkp */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    fn = elt(env, 2); /* pappl */
    v1 = (*qfn2(fn))(qenv(fn), stack[0], v1);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v1);
    }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for rnonep!: */

static Lisp_Object CC_rnonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v45, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnonep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v0;
/* end of prologue */
    v27 = v46;
    v27 = qcdr(v27);
    v45 = qcar(v27);
    v27 = (Lisp_Object)17; /* 1 */
    if (v45 == v27) goto v14;
    v27 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v27);

v14:
    v27 = v46;
    v27 = qcdr(v27);
    v45 = qcdr(v27);
    v27 = (Lisp_Object)17; /* 1 */
    v27 = (v45 == v27 ? lisp_true : nil);
    return onevalue(v27);
}



/* Code for modtimes!: */

static Lisp_Object CC_modtimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modtimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v2 = v7;
    v24 = v0;
/* end of prologue */
    v24 = qcdr(v24);
    v2 = qcdr(v2);
    fn = elt(env, 1); /* general!-modular!-times */
    v2 = (*qfn2(fn))(qenv(fn), v24, v2);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v2);
    }
/* error exit handlers */
v23:
    popv(1);
    return nil;
}



/* Code for rank */

static Lisp_Object CC_rank(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rank");
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
    v98 = qvalue(elt(env, 1)); /* !*mcd */
    if (v98 == nil) goto v47;
    v98 = stack[-2];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v98 = qcdr(v98);
    { popv(5); return onevalue(v98); }

v47:
    v98 = stack[-2];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v98 = qcdr(v98);
    stack[-1] = v98;
    v98 = stack[-2];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v98 = qcar(v98);
    stack[0] = v98;
    goto v14;

v14:
    v98 = stack[-2];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[-2];
    v98 = qcdr(v98);
    if (v98 == nil) goto v9;
    v98 = stack[-2];
    v98 = qcdr(v98);
    stack[-2] = v98;
    v156 = stack[-2];
    v98 = stack[0];
    fn = elt(env, 2); /* degr */
    v156 = (*qfn2(fn))(qenv(fn), v156, v98);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-4];
    v98 = (Lisp_Object)1; /* 0 */
    if (!(v156 == v98)) goto v14;
    v156 = stack[-3];
    v98 = (Lisp_Object)1; /* 0 */
    v98 = (Lisp_Object)lessp2(v156, v98);
    nil = C_nil;
    if (exception_pending()) goto v169;
    v98 = v98 ? lisp_true : nil;
    env = stack[-4];
    if (v98 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v156 = stack[-1];
    v98 = (Lisp_Object)1; /* 0 */
    v98 = (Lisp_Object)lessp2(v156, v98);
    nil = C_nil;
    if (exception_pending()) goto v169;
    v98 = v98 ? lisp_true : nil;
    if (v98 == nil) goto v70;
    v98 = stack[-3];
    popv(5);
    return negate(v98);

v70:
    v156 = stack[-1];
    v98 = stack[-3];
    popv(5);
    return difference2(v156, v98);

v9:
    v156 = stack[-1];
    v98 = stack[-3];
    popv(5);
    return difference2(v156, v98);
/* error exit handlers */
v169:
    popv(5);
    return nil;
}



/* Code for remove!-free!-vars */

static Lisp_Object CC_removeKfreeKvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars");
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
    v175 = stack[0];
    if (!consp(v175)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v175 = stack[0];
    v182 = qcar(v175);
    v175 = elt(env, 1); /* !~ */
    if (v182 == v175) goto v13;
    v175 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* remove!-free!-vars!-l */
        return (*qfn1(fn))(qenv(fn), v175);
    }

v13:
    v175 = qvalue(elt(env, 2)); /* !*!*noremove!*!* */
    if (v175 == nil) goto v22;
    v175 = stack[0];
    v175 = qcdr(v175);
    v182 = qcar(v175);
    v175 = qvalue(elt(env, 3)); /* frasc!* */
    v175 = Latsoc(nil, v182, v175);
    v182 = v175;
    if (!(v175 == nil)) goto v45;
    v175 = stack[0];
    v175 = qcdr(v175);
    v182 = qcar(v175);
    v175 = elt(env, 1); /* !~ */
    if (!consp(v182)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v182 = qcar(v182);
    if (!(v182 == v175)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v175 = stack[0];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    v175 = qcdr(v175);
    v175 = qcar(v175);
    v182 = qvalue(elt(env, 3)); /* frasc!* */
    v175 = Latsoc(nil, v175, v182);
    v182 = v175;
    if (v175 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else goto v45;

v45:
    v175 = v182;
    v175 = qcdr(v175);
    { popv(3); return onevalue(v175); }

v22:
    v175 = stack[0];
    v175 = qcdr(v175);
    if (!consp(v175)) goto v50;
    v175 = stack[0];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    stack[-1] = v175;
    if (is_number(v175)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v175 = stack[-1];
    if (symbolp(v175)) goto v76;
    v182 = stack[-1];
    v175 = elt(env, 1); /* !~ */
    if (!consp(v182)) goto v64;
    v182 = qcar(v182);
    if (!(v182 == v175)) goto v64;
    v175 = stack[-1];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    stack[-1] = v175;
    if (!(v175 == nil)) goto v76;

v64:
    v175 = stack[0];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    v175 = qcar(v175);
    if (symbolp(v175)) goto v126;
    v182 = stack[0];
    v175 = elt(env, 4); /* "free variable" */
    {
        popv(3);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v182, v175);
    }

v126:
    v175 = stack[0];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    v175 = qcar(v175);
    fn = elt(env, 8); /* get!-free!-form */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-2];
    v182 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-2];
    v175 = qvalue(elt(env, 5)); /* frlis!* */
    fn = elt(env, 9); /* union */
    v175 = (*qfn2(fn))(qenv(fn), v182, v175);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-2];
    qvalue(elt(env, 5)) = v175; /* frlis!* */
    v175 = stack[0];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    stack[-1] = qcar(v175);
    v175 = stack[0];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    v175 = qcdr(v175);
    fn = elt(env, 6); /* remove!-free!-vars!-l */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v183;
    {
        Lisp_Object v176 = stack[-1];
        popv(3);
        return cons(v176, v175);
    }

v76:
    v175 = stack[0];
    v175 = qcdr(v175);
    v175 = qcar(v175);
    fn = elt(env, 8); /* get!-free!-form */
    v175 = (*qfn1(fn))(qenv(fn), v175);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-2];
    v182 = ncons(v175);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-2];
    v175 = qvalue(elt(env, 5)); /* frlis!* */
    fn = elt(env, 9); /* union */
    v175 = (*qfn2(fn))(qenv(fn), v182, v175);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-2];
    qvalue(elt(env, 5)) = v175; /* frlis!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v50:
    v182 = stack[0];
    v175 = elt(env, 4); /* "free variable" */
    {
        popv(3);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v182, v175);
    }
/* error exit handlers */
v183:
    popv(3);
    return nil;
}



/* Code for tayexp!-greaterp */

static Lisp_Object CC_tayexpKgreaterp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-greaterp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v7;
    v47 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* tayexp!-lessp */
        return (*qfn2(fn))(qenv(fn), v13, v47);
    }
}



/* Code for subs2q */

static Lisp_Object CC_subs2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v91, v48, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2q");
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
    v92 = stack[-2];
    v91 = qcar(v92);
    v92 = stack[-2];
    v92 = qcdr(v92);
    stack[-3] = v91;
    stack[-1] = v92;
    v92 = stack[-3];
    fn = elt(env, 1); /* subs2f */
    stack[0] = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v92 = stack[-1];
    fn = elt(env, 1); /* subs2f */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    v41 = stack[0];
    v48 = v92;
    v92 = v41;
    v91 = qcdr(v92);
    v92 = (Lisp_Object)17; /* 1 */
    if (!(v91 == v92)) goto v141;
    v92 = v48;
    v91 = qcdr(v92);
    v92 = (Lisp_Object)17; /* 1 */
    if (!(v91 == v92)) goto v141;
    v92 = v41;
    v91 = qcar(v92);
    v92 = stack[-3];
    if (!(equal(v91, v92))) goto v141;
    v92 = v48;
    v91 = qcar(v92);
    v92 = stack[-1];
    if (equal(v91, v92)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    else goto v141;

v141:
    stack[0] = v41;
    v92 = v48;
    fn = elt(env, 2); /* invsq */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-4];
    {
        Lisp_Object v102 = stack[0];
        popv(5);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v102, v92);
    }
/* error exit handlers */
v58:
    popv(5);
    return nil;
}



/* Code for kernord!-sort */

static Lisp_Object CC_kernordKsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord-sort");
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
    stack[0] = nil;
    goto v36;

v36:
    v32 = stack[-1];
    if (v32 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v32 = stack[-1];
    v18 = qcdr(v32);
    v32 = stack[-1];
    v32 = qcar(v32);
    fn = elt(env, 2); /* maxdeg */
    v32 = (*qfn2(fn))(qenv(fn), v18, v32);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    stack[-2] = v32;
    v32 = stack[-2];
    v18 = qcar(v32);
    v32 = stack[-1];
    fn = elt(env, 3); /* delallasc */
    v32 = (*qfn2(fn))(qenv(fn), v18, v32);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    stack[-1] = v32;
    v32 = stack[-2];
    v18 = qcar(v32);
    v32 = stack[0];
    v32 = cons(v18, v32);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    stack[0] = v32;
    goto v36;
/* error exit handlers */
v84:
    popv(4);
    return nil;
}



/* Code for delq */

static Lisp_Object CC_delq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delq");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v35 = nil;
    goto v44;

v44:
    v37 = stack[0];
    if (v37 == nil) goto v63;
    v37 = stack[0];
    v38 = qcar(v37);
    v37 = stack[-1];
    if (v38 == v37) goto v22;
    v37 = stack[0];
    v37 = qcar(v37);
    v38 = v35;
    v37 = cons(v37, v38);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v35 = v37;
    v37 = stack[0];
    v37 = qcdr(v37);
    stack[0] = v37;
    goto v44;

v22:
    v38 = v35;
    v37 = stack[0];
    v37 = qcdr(v37);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v38, v37);
    }

v63:
    v37 = v35;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v37);
    }
/* error exit handlers */
v62:
    popv(3);
    return nil;
}



/* Code for rmultpf */

static Lisp_Object CC_rmultpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rmultpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v44;

v44:
    v50 = stack[-1];
    if (v50 == nil) goto v42;
    v50 = stack[-1];
    if (!consp(v50)) goto v25;
    v50 = stack[-1];
    v50 = qcar(v50);
    if (!consp(v50)) goto v25;
    v50 = stack[-2];
    v51 = qcar(v50);
    v50 = stack[-1];
    v50 = qcar(v50);
    v50 = qcar(v50);
    v50 = qcar(v50);
    fn = elt(env, 1); /* reordop */
    v50 = (*qfn2(fn))(qenv(fn), v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-4];
    if (!(v50 == nil)) goto v25;
    v50 = stack[-1];
    v50 = qcar(v50);
    stack[0] = qcar(v50);
    v51 = stack[-2];
    v50 = stack[-1];
    v50 = qcar(v50);
    v50 = qcdr(v50);
    v51 = CC_rmultpf(env, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-4];
    v50 = stack[-3];
    v50 = acons(stack[0], v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-4];
    stack[-3] = v50;
    v50 = stack[-1];
    v50 = qcdr(v50);
    stack[-1] = v50;
    goto v44;

v25:
    stack[0] = stack[-3];
    v51 = stack[-2];
    v50 = stack[-1];
    v50 = cons(v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-4];
    v50 = ncons(v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-4];
    {
        Lisp_Object v57 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v57, v50);
    }

v42:
    v50 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v50);
    }
/* error exit handlers */
v56:
    popv(5);
    return nil;
}



/* Code for attributes */

static Lisp_Object CC_attributes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for attributes");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    v103 = v0;
/* end of prologue */
    v103 = Llength(nil, v103);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    stack[-2] = v103;
    v103 = (Lisp_Object)17; /* 1 */
    stack[0] = v103;
    goto v15;

v15:
    v60 = stack[-2];
    v103 = stack[0];
    v103 = difference2(v60, v103);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    v103 = Lminusp(nil, v103);
    env = stack[-3];
    if (!(v103 == nil)) goto v29;
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    v103 = stack[0];
    v103 = add1(v103);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-3];
    stack[0] = v103;
    goto v15;

v29:
    v103 = stack[-1];
    v60 = qcar(v103);
    v103 = elt(env, 2); /* !  */
    if (v60 == v103) goto v19;
    v60 = stack[-1];
    v103 = elt(env, 3); /* (!$) */
    if (equal(v60, v103)) goto v37;
    v103 = stack[-1];
    qvalue(elt(env, 4)) = v103; /* atts */
    goto v37;

v37:
    v103 = nil;
    { popv(4); return onevalue(v103); }

v19:
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    goto v29;
/* error exit handlers */
v92:
    popv(4);
    return nil;
}



/* Code for equal!: */

static Lisp_Object CC_equalT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equal:");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v0;
/* end of prologue */
    v153 = stack[-1];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = (Lisp_Object)zerop(v153);
    v153 = v153 ? lisp_true : nil;
    env = stack[-3];
    if (v153 == nil) goto v36;
    v153 = stack[0];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = (Lisp_Object)zerop(v153);
    v153 = v153 ? lisp_true : nil;
    env = stack[-3];
    goto v74;

v74:
    if (!(v153 == nil)) { popv(4); return onevalue(v153); }
    v153 = stack[-1];
    fn = elt(env, 2); /* csl_normbf */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-1] = v153;
    v153 = qcdr(v153);
    stack[-2] = qcdr(v153);
    v153 = stack[0];
    fn = elt(env, 2); /* csl_normbf */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[0] = v153;
    v153 = qcdr(v153);
    v153 = qcdr(v153);
    if (equal(stack[-2], v153)) goto v31;
    v153 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v153); }

v31:
    v153 = stack[-1];
    v153 = qcdr(v153);
    v61 = qcar(v153);
    v153 = stack[0];
    v153 = qcdr(v153);
    v153 = qcar(v153);
    v153 = (equal(v61, v153) ? lisp_true : nil);
    { popv(4); return onevalue(v153); }

v36:
    v153 = qvalue(elt(env, 1)); /* nil */
    goto v74;
/* error exit handlers */
v141:
    popv(4);
    return nil;
}



/* Code for mgenp */

static Lisp_Object CC_mgenp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mgenp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v14 = v15;
    if (!consp(v14)) goto v47;
    v14 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v14);

v47:
    v14 = v15;
    v15 = elt(env, 2); /* mgen */
    return get(v14, v15);
}



/* Code for bcint2op */

static Lisp_Object MS_CDECL CC_bcint2op(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v7,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v156, v112, v76, v77;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bcint2op");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcint2op");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v7,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v77 = v28;
    v112 = v7;
    v76 = v0;
/* end of prologue */
    v98 = qvalue(elt(env, 1)); /* dmode!* */
    if (!(v98 == nil)) goto v74;
    v156 = (Lisp_Object)17; /* 1 */
    v98 = v76;
    v98 = qcdr(v98);
    if (!(v156 == v98)) goto v74;
    v98 = v76;
    v98 = qcar(v98);
    v76 = v98;
    if (!(is_number(v98))) goto v74;
    v156 = (Lisp_Object)17; /* 1 */
    v98 = v112;
    v98 = qcdr(v98);
    if (!(v156 == v98)) goto v74;
    v98 = v112;
    v98 = qcar(v98);
    v112 = v98;
    if (!(is_number(v98))) goto v74;
    v156 = v77;
    v98 = elt(env, 2); /* times */
    if (v156 == v98) goto v54;
    v156 = v77;
    v98 = elt(env, 3); /* plus */
    if (v156 == v98) goto v40;
    v98 = v77;
    v156 = v76;
    v98 = Lapply2(nil, 3, v98, v156, v112);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[0];
    goto v25;

v25:
    v76 = v98;
    if (v98 == nil) goto v74;
    v156 = v76;
    v98 = (Lisp_Object)1; /* 0 */
    if (v156 == v98) goto v65;
    v98 = v76;
    v156 = v98;
    goto v109;

v109:
    v98 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v156, v98);

v65:
    v98 = qvalue(elt(env, 4)); /* nil */
    v156 = v98;
    goto v109;

v74:
    v98 = nil;
    { popv(1); return onevalue(v98); }

v40:
    v98 = v76;
    v156 = v112;
    v98 = plus2(v98, v156);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[0];
    goto v25;

v54:
    v98 = v76;
    v156 = v112;
    v98 = times2(v98, v156);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[0];
    goto v25;
/* error exit handlers */
v184:
    popv(1);
    return nil;
}



/* Code for evmatrixcomp1 */

static Lisp_Object MS_CDECL CC_evmatrixcomp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v7,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v72, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evmatrixcomp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmatrixcomp1");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v7,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v28;
    stack[-2] = v7;
    stack[-3] = v0;
/* end of prologue */

v99:
    v102 = stack[-1];
    if (v102 == nil) goto v44;
    v50 = stack[-3];
    v102 = stack[-1];
    v72 = qcar(v102);
    v102 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* evmatrixcomp2 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v50, v72, v102);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    v50 = stack[-2];
    v102 = stack[-1];
    v72 = qcar(v102);
    v102 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* evmatrixcomp2 */
    v102 = (*qfnn(fn))(qenv(fn), 3, v50, v72, v102);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v102;
    v72 = stack[-4];
    v102 = stack[0];
    v102 = Leqn(nil, v72, v102);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-5];
    if (v102 == nil) goto v40;
    v50 = stack[-3];
    v72 = stack[-2];
    v102 = stack[-1];
    v102 = qcdr(v102);
    stack[-3] = v50;
    stack[-2] = v72;
    stack[-1] = v102;
    goto v99;

v40:
    v72 = stack[-4];
    v102 = stack[0];
    if (((int32_t)(v72)) > ((int32_t)(v102))) goto v60;
    v102 = (Lisp_Object)-15; /* -1 */
    { popv(6); return onevalue(v102); }

v60:
    v102 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v102); }

v44:
    v102 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v102); }
/* error exit handlers */
v56:
    popv(6);
    return nil;
}



/* Code for round!:last */

static Lisp_Object CC_roundTlast(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v59, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for round:last");
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
    v59 = v0;
/* end of prologue */
    v147 = v59;
    v147 = qcdr(v147);
    stack[0] = qcar(v147);
    v147 = v59;
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v59 = add1(v147);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v147 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = stack[0];
    stack[-1] = v59;
    stack[0] = v147;
    v59 = stack[-2];
    v147 = (Lisp_Object)1; /* 0 */
    v147 = (Lisp_Object)lessp2(v59, v147);
    nil = C_nil;
    if (exception_pending()) goto v50;
    v147 = v147 ? lisp_true : nil;
    env = stack[-3];
    if (v147 == nil) goto v2;
    v147 = stack[-2];
    v147 = negate(v147);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    stack[-2] = v147;
    v147 = qvalue(elt(env, 2)); /* t */
    stack[0] = v147;
    goto v2;

v2:
    v147 = stack[-2];
    v147 = Levenp(nil, v147);
    env = stack[-3];
    if (v147 == nil) goto v25;
    v59 = stack[-2];
    v147 = (Lisp_Object)-15; /* -1 */
    v147 = ash(v59, v147);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    goto v45;

v45:
    stack[-2] = v147;
    v147 = stack[0];
    if (v147 == nil) goto v103;
    v147 = stack[-2];
    v147 = negate(v147);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    stack[-2] = v147;
    goto v103;

v103:
    v55 = elt(env, 3); /* !:rd!: */
    v59 = stack[-2];
    v147 = stack[-1];
    popv(4);
    return list2star(v55, v59, v147);

v25:
    v59 = stack[-2];
    v147 = (Lisp_Object)-15; /* -1 */
    v147 = ash(v59, v147);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v147 = add1(v147);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    goto v45;
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for !:minusp */

static Lisp_Object CC_Tminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v27, v45;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :minusp");
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
    v45 = v0;
/* end of prologue */
    v33 = v45;
    if (!consp(v33)) goto v6;
    v33 = v45;
    v27 = qcar(v33);
    v33 = elt(env, 1); /* minusp */
    v33 = get(v27, v33);
    v27 = v45;
        return Lapply1(nil, v33, v27);

v6:
    v33 = v45;
        return Lminusp(nil, v33);
}



/* Code for mtchp */

static Lisp_Object MS_CDECL CC_mtchp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v7,
                         Lisp_Object v28, Lisp_Object v10,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v155, v88, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "mtchp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mtchp");
#endif
    if (stack >= stacklimit)
    {
        push5(v6,v10,v28,v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v7,v28,v10,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    v146 = v10;
    stack[-1] = v28;
    stack[-2] = v7;
    stack[-3] = v0;
/* end of prologue */
    v90 = stack[-3];
    v88 = stack[-2];
    v155 = v146;
    v146 = stack[0];
    fn = elt(env, 2); /* mtchp1 */
    v146 = (*qfnn(fn))(qenv(fn), 4, v90, v88, v155, v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    stack[-4] = v146;
    goto v42;

v42:
    v146 = stack[-4];
    if (v146 == nil) goto v33;
    v146 = stack[-4];
    v155 = qcar(v146);
    v146 = stack[0];
    v146 = Lsubla(nil, v155, v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    fn = elt(env, 3); /* eval */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    if (v146 == nil) goto v49;
    v146 = stack[-3];
    stack[0] = qcdr(v146);
    v146 = stack[-4];
    v155 = qcar(v146);
    v146 = stack[-2];
    v146 = qcdr(v146);
    v146 = Lsubla(nil, v155, v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v146 = Ldivide(nil, stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    stack[-2] = v146;
    v146 = stack[-4];
    v155 = qcar(v146);
    v146 = stack[-1];
    v146 = Lsubla(nil, v155, v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    fn = elt(env, 4); /* simp */
    v155 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v146 = stack[-2];
    v146 = qcar(v146);
    fn = elt(env, 5); /* exptsq */
    v146 = (*qfn2(fn))(qenv(fn), v155, v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    stack[-1] = v146;
    v146 = stack[-2];
    v155 = qcdr(v146);
    v146 = (Lisp_Object)1; /* 0 */
    if (v155 == v146) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v146 = stack[-3];
    v88 = qcar(v146);
    v146 = stack[-2];
    v155 = qcdr(v146);
    v146 = (Lisp_Object)17; /* 1 */
    v146 = acons(v88, v155, v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v155 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v146 = (Lisp_Object)17; /* 1 */
    v155 = cons(v155, v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-5];
    v146 = stack[-1];
    fn = elt(env, 6); /* multsq */
    v146 = (*qfn2(fn))(qenv(fn), v155, v146);
    nil = C_nil;
    if (exception_pending()) goto v154;
    stack[-1] = v146;
    { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }

v49:
    v146 = stack[-4];
    v146 = qcdr(v146);
    stack[-4] = v146;
    goto v42;

v33:
    v146 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v146); }
/* error exit handlers */
v154:
    popv(6);
    return nil;
}



/* Code for collectindices */

static Lisp_Object CC_collectindices(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectindices");
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
    v17 = nil;
    v16 = stack[0];
    if (!(!consp(v16))) goto v44;
    v16 = stack[0];
    fn = elt(env, 2); /* isanindex */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    if (v16 == nil) goto v3;
    v16 = stack[0];
    popv(3);
    return ncons(v16);

v3:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v16); }

v44:
    v16 = stack[0];
    v16 = qcar(v16);
    v32 = v16;
    v16 = stack[0];
    v16 = qcdr(v16);
    stack[0] = v16;
    stack[-1] = v17;
    v16 = v32;
    v16 = CC_collectindices(env, v16);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v16 = Lnconc(nil, stack[-1], v16);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v17 = v16;
    v16 = stack[0];
    if (v16 == nil) { popv(3); return onevalue(v17); }
    else goto v44;
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for mo_ecart */

static Lisp_Object CC_mo_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_ecart");
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
    v75 = qcar(v75);
    if (v75 == nil) goto v6;
    v75 = stack[0];
    fn = elt(env, 3); /* mo_comp */
    v84 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    v75 = qvalue(elt(env, 1)); /* cali!=degrees */
    v75 = Latsoc(nil, v84, v75);
    v84 = v75;
    v75 = v84;
    if (v75 == nil) goto v31;
    v75 = v84;
    v84 = qcdr(v75);
    v75 = stack[0];
    fn = elt(env, 4); /* mo_sum */
    v75 = (*qfn2(fn))(qenv(fn), v84, v75);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    goto v27;

v27:
    v75 = qcar(v75);
    stack[0] = qcdr(v75);
    v75 = qvalue(elt(env, 2)); /* cali!=basering */
    fn = elt(env, 5); /* ring_ecart */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    {
        Lisp_Object v35 = stack[0];
        popv(2);
        fn = elt(env, 6); /* mo!=sprod */
        return (*qfn2(fn))(qenv(fn), v35, v75);
    }

v31:
    v75 = stack[0];
    goto v27;

v6:
    v75 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v75); }
/* error exit handlers */
v38:
    popv(2);
    return nil;
}



/* Code for dless */

static Lisp_Object CC_dless(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v109, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dless");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v82 = v7;
    stack[0] = v0;
/* end of prologue */
    v109 = qvalue(elt(env, 1)); /* ordering */
    v96 = elt(env, 2); /* lex */
    if (v109 == v96) goto v24;
    v96 = stack[0];
    v109 = qcar(v96);
    v96 = v82;
    v96 = qcar(v96);
    if (((int32_t)(v109)) < ((int32_t)(v96))) goto v5;
    v96 = stack[0];
    v109 = qcar(v96);
    v96 = v82;
    v96 = qcar(v96);
    if (((int32_t)(v109)) > ((int32_t)(v96))) goto v20;
    v109 = qvalue(elt(env, 1)); /* ordering */
    v96 = elt(env, 5); /* glex */
    if (v109 == v96) goto v71;
    v109 = qvalue(elt(env, 1)); /* ordering */
    v96 = elt(env, 6); /* grev */
    if (v109 == v96) goto v102;
    v96 = nil;
    { popv(3); return onevalue(v96); }

v102:
    v96 = v82;
    v96 = qcdr(v96);
    stack[-1] = Lreverse(nil, v96);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v96 = stack[0];
    v96 = qcdr(v96);
    v96 = Lreverse(nil, v96);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    {
        Lisp_Object v65 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v65, v96);
    }

v71:
    v96 = stack[0];
    v96 = qcdr(v96);
    v109 = v82;
    v109 = qcdr(v109);
    {
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v96, v109);
    }

v20:
    v96 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v96); }

v5:
    v96 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v96); }

v24:
    v96 = stack[0];
    v109 = v82;
    {
        popv(3);
        fn = elt(env, 7); /* dlesslex */
        return (*qfn2(fn))(qenv(fn), v96, v109);
    }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for hasonevector */

static Lisp_Object CC_hasonevector(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hasonevector");
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

v99:
    v15 = stack[0];
    if (v15 == nil) goto v6;
    v15 = stack[0];
    v15 = qcar(v15);
    fn = elt(env, 2); /* vecp */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-1];
    if (!(v15 == nil)) { popv(2); return onevalue(v15); }
    v15 = stack[0];
    v15 = qcdr(v15);
    stack[0] = v15;
    goto v99;

v6:
    v15 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v15); }
/* error exit handlers */
v4:
    popv(2);
    return nil;
}



/* Code for sieve_pv */

static Lisp_Object CC_sieve_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v24, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sieve_pv");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v2 = v7;
    v24 = v0;
/* end of prologue */
    v23 = v24;
    v24 = v2;
    v2 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* sieve_pv0 */
        return (*qfnn(fn))(qenv(fn), 3, v23, v24, v2);
    }
}



setup_type const u02_setup[] =
{
    {"rnequiv",                 CC_rnequiv,     too_many_1,    wrong_no_1},
    {"general-modular-times",   too_few_2,      CC_generalKmodularKtimes,wrong_no_2},
    {"getpower",                too_few_2,      CC_getpower,   wrong_no_2},
    {"ofsf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwupdknowl},
    {"gcdf",                    too_few_2,      CC_gcdf,       wrong_no_2},
    {"finde",                   too_few_2,      CC_finde,      wrong_no_2},
    {"qqe_qopaddp",             CC_qqe_qopaddp, too_many_1,    wrong_no_1},
    {"lto_setequalq",           too_few_2,      CC_lto_setequalq,wrong_no_2},
    {"*d2n",                    CC_Hd2n,        too_many_1,    wrong_no_1},
    {"compress*",               CC_compressH,   too_many_1,    wrong_no_1},
    {"printout",                CC_printout,    too_many_1,    wrong_no_1},
    {"retimes",                 CC_retimes,     too_many_1,    wrong_no_1},
    {"ps:last-term",            CC_psTlastKterm,too_many_1,    wrong_no_1},
    {"round:mt",                too_few_2,      CC_roundTmt,   wrong_no_2},
    {"c:ordexn",                too_few_2,      CC_cTordexn,   wrong_no_2},
    {":zerop",                  CC_Tzerop,      too_many_1,    wrong_no_1},
    {"mval",                    CC_mval,        too_many_1,    wrong_no_1},
    {"bcprod",                  too_few_2,      CC_bcprod,     wrong_no_2},
    {"sublistp",                too_few_2,      CC_sublistp,   wrong_no_2},
    {"chundexp",                CC_chundexp,    too_many_1,    wrong_no_1},
    {":times",                  too_few_2,      CC_Ttimes,     wrong_no_2},
    {"listsum",                 CC_listsum,     too_many_1,    wrong_no_1},
    {"*physopp",                CC_Hphysopp,    too_many_1,    wrong_no_1},
    {"expdrmacro",              CC_expdrmacro,  too_many_1,    wrong_no_1},
    {"aeval*",                  CC_aevalH,      too_many_1,    wrong_no_1},
    {"adddm",                   too_few_2,      CC_adddm,      wrong_no_2},
    {"mo_vdivides?",            too_few_2,      CC_mo_vdividesW,wrong_no_2},
    {"unpkp",                   CC_unpkp,       too_many_1,    wrong_no_1},
    {"*i2mod",                  CC_Hi2mod,      too_many_1,    wrong_no_1},
    {"general-modular-plus",    too_few_2,      CC_generalKmodularKplus,wrong_no_2},
    {"remainder-in-vector",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_remainderKinKvector},
    {"split_form",              too_few_2,      CC_split_form, wrong_no_2},
    {"ofsf_posdefp",            CC_ofsf_posdefp,too_many_1,    wrong_no_1},
    {"mcharg",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg},
    {"multsq",                  too_few_2,      CC_multsq,     wrong_no_2},
    {"qqe_qopheadp",            CC_qqe_qopheadp,too_many_1,    wrong_no_1},
    {"rl_simplat1",             too_few_2,      CC_rl_simplat1,wrong_no_2},
    {"setcar",                  too_few_2,      CC_setcar,     wrong_no_2},
    {":minus",                  CC_Tminus,      too_many_1,    wrong_no_1},
    {"get_token",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_get_token},
    {"dm-abs",                  CC_dmKabs,      too_many_1,    wrong_no_1},
    {"bczero?",                 CC_bczeroW,     too_many_1,    wrong_no_1},
    {"rd:zerop",                CC_rdTzerop,    too_many_1,    wrong_no_1},
    {"evzero?",                 CC_evzeroW,     too_many_1,    wrong_no_1},
    {"wedgepf2",                too_few_2,      CC_wedgepf2,   wrong_no_2},
    {"update-pline",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_updateKpline},
    {":plus",                   too_few_2,      CC_Tplus,      wrong_no_2},
    {"fprin2",                  CC_fprin2,      too_many_1,    wrong_no_1},
    {"powers0",                 too_few_2,      CC_powers0,    wrong_no_2},
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"union_edges",             too_few_2,      CC_union_edges,wrong_no_2},
    {"macrochk",                too_few_2,      CC_macrochk,   wrong_no_2},
    {"reval_without_mod",       CC_reval_without_mod,too_many_1,wrong_no_1},
    {"angles-equal",            too_few_2,      CC_anglesKequal,wrong_no_2},
    {"mo=sprod",                too_few_2,      CC_moMsprod,   wrong_no_2},
    {"mtchp1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp1},
    {"pappl0",                  too_few_2,      CC_pappl0,     wrong_no_2},
    {"rnonep:",                 CC_rnonepT,     too_many_1,    wrong_no_1},
    {"modtimes:",               too_few_2,      CC_modtimesT,  wrong_no_2},
    {"rank",                    CC_rank,        too_many_1,    wrong_no_1},
    {"remove-free-vars",        CC_removeKfreeKvars,too_many_1,wrong_no_1},
    {"tayexp-greaterp",         too_few_2,      CC_tayexpKgreaterp,wrong_no_2},
    {"subs2q",                  CC_subs2q,      too_many_1,    wrong_no_1},
    {"kernord-sort",            CC_kernordKsort,too_many_1,    wrong_no_1},
    {"delq",                    too_few_2,      CC_delq,       wrong_no_2},
    {"rmultpf",                 too_few_2,      CC_rmultpf,    wrong_no_2},
    {"attributes",              too_few_2,      CC_attributes, wrong_no_2},
    {"equal:",                  too_few_2,      CC_equalT,     wrong_no_2},
    {"mgenp",                   CC_mgenp,       too_many_1,    wrong_no_1},
    {"bcint2op",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_bcint2op},
    {"evmatrixcomp1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp1},
    {"round:last",              CC_roundTlast,  too_many_1,    wrong_no_1},
    {":minusp",                 CC_Tminusp,     too_many_1,    wrong_no_1},
    {"mtchp",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp},
    {"collectindices",          CC_collectindices,too_many_1,  wrong_no_1},
    {"mo_ecart",                CC_mo_ecart,    too_many_1,    wrong_no_1},
    {"dless",                   too_few_2,      CC_dless,      wrong_no_2},
    {"hasonevector",            CC_hasonevector,too_many_1,    wrong_no_1},
    {"sieve_pv",                too_few_2,      CC_sieve_pv,   wrong_no_2},
    {NULL, (one_args *)"u02", (two_args *)"12739 9420600 5513158", 0}
};

/* end of generated code */
