
/* $destdir\u17.c        Machine generated C code */

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


/* Code for simpatom */

static Lisp_Object CC_simpatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpatom");
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
    v58 = stack[0];
    if (v58 == nil) goto v61;
    v58 = stack[0];
    if (is_number(v58)) goto v62;
    v58 = stack[0];
    v58 = Lstringp(nil, v58);
    env = stack[-2];
    if (v58 == nil) goto v63;
    v59 = elt(env, 8); /* "String" */
    v58 = stack[0];
    v59 = list2(v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v58 = elt(env, 9); /* "identifier" */
    {
        popv(3);
        fn = elt(env, 17); /* typerr */
        return (*qfn2(fn))(qenv(fn), v59, v58);
    }

v63:
    v59 = stack[0];
    v58 = elt(env, 10); /* share */
    v58 = Lflagp(nil, v59, v58);
    env = stack[-2];
    if (v58 == nil) goto v65;
    v58 = stack[0];
    fn = elt(env, 18); /* eval */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v60 = v58;
    v59 = v60;
    v58 = stack[0];
    if (v59 == v58) goto v66;
    v58 = v60;
    {
        popv(3);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v58);
    }

v66:
    v59 = stack[0];
    v58 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 20); /* mksq */
        return (*qfn2(fn))(qenv(fn), v59, v58);
    }

v65:
    v59 = stack[0];
    v58 = elt(env, 11); /* idvalfn */
    v58 = get(v59, v58);
    env = stack[-2];
    v60 = v58;
    if (v58 == nil) goto v67;
    v59 = v60;
    v58 = stack[0];
        popv(3);
        return Lapply1(nil, v59, v58);

v67:
    v58 = qvalue(elt(env, 12)); /* !*numval */
    if (v58 == nil) goto v68;
    v58 = qvalue(elt(env, 3)); /* dmode!* */
    if (v58 == nil) goto v68;
    v59 = stack[0];
    v58 = elt(env, 13); /* constant */
    v58 = Lflagp(nil, v59, v58);
    env = stack[-2];
    if (v58 == nil) goto v68;
    v59 = stack[0];
    v58 = qvalue(elt(env, 3)); /* dmode!* */
    v58 = get(v59, v58);
    env = stack[-2];
    v60 = v58;
    if (v58 == nil) goto v68;
    stack[-1] = elt(env, 14); /* lispapply */
    v58 = v60;
    v59 = Lmkquote(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v58 = qvalue(elt(env, 1)); /* nil */
    v60 = list3(stack[-1], v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v59 = qvalue(elt(env, 1)); /* nil */
    v58 = qvalue(elt(env, 15)); /* !*backtrace */
    fn = elt(env, 21); /* errorset */
    v58 = (*qfnn(fn))(qenv(fn), 3, v60, v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v60 = v58;
    v59 = v58;
    v58 = v59;
    v58 = (consp(v58) ? nil : lisp_true);
    if (!(v58 == nil)) goto v69;
    v58 = v59;
    v58 = qcdr(v58);
    goto v69;

v69:
    if (!(v58 == nil)) goto v68;
    v58 = v60;
    v58 = qcar(v58);
    {
        popv(3);
        fn = elt(env, 22); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v58);
    }

v68:
    v58 = stack[0];
    fn = elt(env, 23); /* getrtype */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (v58 == nil) goto v70;
    v59 = stack[0];
    v58 = elt(env, 16); /* scalar */
    fn = elt(env, 17); /* typerr */
    v58 = (*qfn2(fn))(qenv(fn), v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v58 = nil;
    { popv(3); return onevalue(v58); }

v70:
    v59 = stack[0];
    v58 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 20); /* mksq */
        return (*qfn2(fn))(qenv(fn), v59, v58);
    }

v62:
    v59 = stack[0];
    v58 = (Lisp_Object)1; /* 0 */
    if (v59 == v58) goto v71;
    v58 = stack[0];
    v58 = integerp(v58);
    if (v58 == nil) goto v72;
    v59 = qvalue(elt(env, 3)); /* dmode!* */
    v58 = elt(env, 4); /* !:mod!: */
    if (!(v59 == v58)) goto v73;
    v59 = qvalue(elt(env, 5)); /* current!-modulus */
    v58 = (Lisp_Object)17; /* 1 */
    if (!(v59 == v58)) goto v73;
    v59 = qvalue(elt(env, 1)); /* nil */
    v58 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v59, v58);

v73:
    v59 = qvalue(elt(env, 3)); /* dmode!* */
    v58 = elt(env, 6); /* convert */
    v58 = Lflagp(nil, v59, v58);
    env = stack[-2];
    if (v58 == nil) goto v74;
    v59 = stack[0];
    v58 = (Lisp_Object)17; /* 1 */
    if (v59 == v58) goto v74;
    v59 = qvalue(elt(env, 3)); /* dmode!* */
    v58 = elt(env, 7); /* i2d */
    v59 = get(v59, v58);
    env = stack[-2];
    v58 = stack[0];
    v58 = Lapply1(nil, v59, v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 22); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v58);
    }

v74:
    v59 = stack[0];
    v58 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v59, v58);

v72:
    stack[-1] = elt(env, 2); /* !:rd!: */
    v58 = stack[0];
    fn = elt(env, 24); /* fl2bf */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v59 = qcdr(v58);
    v58 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v75 = stack[-1];
        popv(3);
        return acons(v75, v59, v58);
    }

v71:
    v59 = qvalue(elt(env, 1)); /* nil */
    v58 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v59, v58);

v61:
    v59 = qvalue(elt(env, 1)); /* nil */
    v58 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v59, v58);
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for nonlnrsys */

static Lisp_Object CC_nonlnrsys(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonlnrsys");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v76;
    stack[-1] = v0;
/* end of prologue */

v81:
    v79 = stack[-1];
    if (v79 == nil) goto v82;
    v79 = stack[-1];
    v80 = qcar(v79);
    v79 = stack[0];
    fn = elt(env, 2); /* nonlnr */
    v79 = (*qfn2(fn))(qenv(fn), v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    if (!(v79 == nil)) { popv(3); return onevalue(v79); }
    v79 = stack[-1];
    v80 = qcdr(v79);
    v79 = stack[0];
    stack[-1] = v80;
    stack[0] = v79;
    goto v81;

v82:
    v79 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v79); }
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for cl_simpl */

static Lisp_Object MS_CDECL CC_cl_simpl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v76,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97, v98, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_simpl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_simpl");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v76,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v83;
    v97 = v76;
    stack[-3] = v0;
/* end of prologue */
    v96 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v96 == nil) goto v57;
    v96 = v97;
    fn = elt(env, 6); /* cl_sitheo */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-5];
    v97 = v96;
    v98 = v97;
    v96 = elt(env, 3); /* inctheo */
    if (v98 == v96) goto v71;
    stack[-4] = elt(env, 4); /* and */
    stack[-1] = v97;
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v96 = stack[-2];
    v96 = add1(v96);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-5];
    fn = elt(env, 7); /* rl_smupdknowl */
    v96 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-1], stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-5];
    v97 = v96;
    v98 = v97;
    v96 = elt(env, 5); /* false */
    if (v98 == v96) goto v99;
    v73 = stack[-3];
    v98 = v97;
    v97 = stack[-2];
    v96 = qvalue(elt(env, 2)); /* nil */
    {
        popv(6);
        fn = elt(env, 8); /* cl_simpl1 */
        return (*qfnn(fn))(qenv(fn), 4, v73, v98, v97, v96);
    }

v99:
    v96 = elt(env, 3); /* inctheo */
    { popv(6); return onevalue(v96); }

v71:
    v96 = elt(env, 3); /* inctheo */
    { popv(6); return onevalue(v96); }

v57:
    v73 = stack[-3];
    v98 = qvalue(elt(env, 2)); /* nil */
    v97 = stack[-2];
    v96 = qvalue(elt(env, 2)); /* nil */
    {
        popv(6);
        fn = elt(env, 8); /* cl_simpl1 */
        return (*qfnn(fn))(qenv(fn), 4, v73, v98, v97, v96);
    }
/* error exit handlers */
v42:
    popv(6);
    return nil;
}



/* Code for simpg3 */

static Lisp_Object CC_simpg3(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpg3");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v101 = v0;
/* end of prologue */
    v102 = v101;
    v101 = elt(env, 1); /* g3 */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v102, v101);
    }
}



/* Code for remove!-free!-vars!* */

static Lisp_Object CC_removeKfreeKvarsH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove-free-vars*");
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
    v104 = v0;
/* end of prologue */
    v103 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*!*noremove!*!* */
    qvalue(elt(env, 2)) = v103; /* !*!*noremove!*!* */
    v103 = v104;
    fn = elt(env, 3); /* remove!-free!-vars */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    { popv(2); return onevalue(v103); }
/* error exit handlers */
v100:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    popv(2);
    return nil;
}



/* Code for evaluatecoeffts */

static Lisp_Object CC_evaluatecoeffts(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v117, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluatecoeffts");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v76;
    stack[-1] = v0;
/* end of prologue */
    v116 = stack[-1];
    if (v116 == nil) goto v118;
    v116 = stack[-1];
    if (!consp(v116)) goto v118;
    v116 = stack[-1];
    v116 = qcar(v116);
    if (!consp(v116)) goto v118;
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v117 = qcar(v116);
    v116 = qvalue(elt(env, 2)); /* indexlist */
    v116 = Lmember(nil, v117, v116);
    if (v116 == nil) goto v119;
    v116 = stack[-1];
    v116 = qcar(v116);
    v116 = qcar(v116);
    v37 = qcar(v116);
    v117 = stack[0];
    v116 = qvalue(elt(env, 2)); /* indexlist */
    fn = elt(env, 3); /* valuecoefft */
    v116 = (*qfnn(fn))(qenv(fn), 3, v37, v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    goto v44;

v44:
    stack[-2] = v116;
    v116 = stack[-1];
    v116 = qcar(v116);
    v117 = qcdr(v116);
    v116 = stack[0];
    v116 = CC_evaluatecoeffts(env, v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    fn = elt(env, 4); /* !*multf */
    v116 = (*qfn2(fn))(qenv(fn), stack[-2], v116);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    stack[-2] = v116;
    v116 = stack[-1];
    v117 = qcdr(v116);
    v116 = stack[0];
    v116 = CC_evaluatecoeffts(env, v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    {
        Lisp_Object v121 = stack[-2];
        popv(4);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v121, v116);
    }

v119:
    v116 = stack[-1];
    v116 = qcar(v116);
    v117 = qcar(v116);
    v116 = (Lisp_Object)17; /* 1 */
    v116 = cons(v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v116 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    goto v44;

v118:
    v117 = stack[-1];
    v116 = (Lisp_Object)1; /* 0 */
    if (!(v117 == v116)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v116); }
/* error exit handlers */
v120:
    popv(4);
    return nil;
}



/* Code for expnd1 */

static Lisp_Object CC_expnd1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expnd1");
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
    goto v103;

v103:
    v129 = stack[-1];
    if (!consp(v129)) goto v104;
    v129 = stack[-1];
    v129 = qcar(v129);
    if (!consp(v129)) goto v104;
    v129 = stack[-1];
    v129 = qcar(v129);
    v129 = qcar(v129);
    v129 = qcar(v129);
    if (!consp(v129)) goto v131;
    v129 = stack[-1];
    v129 = qcar(v129);
    v129 = qcar(v129);
    v129 = qcar(v129);
    v129 = qcar(v129);
    if (!consp(v129)) goto v131;
    v129 = stack[-1];
    v129 = qcar(v129);
    v129 = qcar(v129);
    v130 = qcdr(v129);
    v129 = (Lisp_Object)1; /* 0 */
    v129 = (Lisp_Object)lessp2(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v129 = v129 ? lisp_true : nil;
    env = stack[-3];
    if (!(v129 == nil)) goto v131;
    v129 = stack[-1];
    v129 = qcar(v129);
    v129 = qcar(v129);
    v129 = qcar(v129);
    v130 = CC_expnd1(env, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v129 = stack[-1];
    v129 = qcar(v129);
    v129 = qcar(v129);
    v129 = qcdr(v129);
    fn = elt(env, 1); /* exptf */
    stack[0] = (*qfn2(fn))(qenv(fn), v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v129 = stack[-1];
    v129 = qcar(v129);
    v129 = qcdr(v129);
    v129 = CC_expnd1(env, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    fn = elt(env, 2); /* multf */
    v129 = (*qfn2(fn))(qenv(fn), stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v130 = v129;
    goto v77;

v77:
    v129 = stack[-2];
    v129 = cons(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    stack[-2] = v129;
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v103;

v131:
    v129 = stack[-1];
    v129 = qcar(v129);
    v130 = qcar(v129);
    v129 = (Lisp_Object)17; /* 1 */
    v129 = cons(v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    stack[0] = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v129 = stack[-1];
    v129 = qcar(v129);
    v129 = qcdr(v129);
    v129 = CC_expnd1(env, v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    fn = elt(env, 2); /* multf */
    v129 = (*qfn2(fn))(qenv(fn), stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v130 = v129;
    goto v77;

v104:
    v129 = stack[-1];
    v130 = v129;
    goto v61;

v61:
    v129 = stack[-2];
    if (v129 == nil) { popv(4); return onevalue(v130); }
    v129 = stack[-2];
    v129 = qcar(v129);
    fn = elt(env, 3); /* addf */
    v129 = (*qfn2(fn))(qenv(fn), v129, v130);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-3];
    v130 = v129;
    v129 = stack[-2];
    v129 = qcdr(v129);
    stack[-2] = v129;
    goto v61;
/* error exit handlers */
v132:
    popv(4);
    return nil;
}



/* Code for ibalp_lenisone */

static Lisp_Object CC_ibalp_lenisone(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v56;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_lenisone");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v56 = v0;
/* end of prologue */
    v57 = v56;
    if (v57 == nil) goto v86;
    v57 = v56;
    v57 = qcdr(v57);
    v57 = (v57 == nil ? lisp_true : nil);
    return onevalue(v57);

v86:
    v57 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v57);
}



/* Code for numpoly_ldeg */

static Lisp_Object CC_numpoly_ldeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_ldeg");
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
    v118 = stack[0];
    fn = elt(env, 1); /* numpoly_nullp */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v77;
    if (v118 == nil) goto v82;
    v118 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v118); }

v82:
    v118 = stack[0];
    if (is_number(v118)) goto v100;
    v118 = stack[0];
    v118 = qcar(v118);
    v118 = qcar(v118);
    v118 = qcdr(v118);
    { popv(1); return onevalue(v118); }

v100:
    v118 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v118); }
/* error exit handlers */
v77:
    popv(1);
    return nil;
}



/* Code for om2mml */

static Lisp_Object MS_CDECL CC_om2mml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2mml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for om2mml");
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
    fn = elt(env, 3); /* om2ir */
    v133 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    stack[0] = v133;
    v133 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v133 = elt(env, 2); /* "Intermediate representation:" */
    v133 = Lprinc(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v133 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v133 = stack[0];
    v133 = Lprinc(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v133 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v133 = stack[0];
    fn = elt(env, 5); /* ir2mml */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v133 = nil;
    { popv(2); return onevalue(v133); }
/* error exit handlers */
v118:
    popv(2);
    return nil;
}



/* Code for revalx */

static Lisp_Object CC_revalx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalx");
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
    v53 = v0;
/* end of prologue */
    v136 = v53;
    if (!consp(v136)) goto v78;
    v136 = v53;
    v136 = qcar(v136);
    if (!consp(v136)) goto v78;
    v136 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1 */
    v136 = (*qfn2(fn))(qenv(fn), v53, v136);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[0];
    v53 = v136;
    v136 = v53;
    if (v136 == nil) goto v93;
    v136 = v53;
    fn = elt(env, 3); /* replus */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[0];
    goto v86;

v86:
    {
        popv(1);
        fn = elt(env, 4); /* reval */
        return (*qfn1(fn))(qenv(fn), v136);
    }

v93:
    v136 = (Lisp_Object)1; /* 0 */
    goto v86;

v78:
    v136 = v53;
    goto v86;
/* error exit handlers */
v52:
    popv(1);
    return nil;
}



/* Code for dipcondense */

static Lisp_Object CC_dipcondense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcondense");
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
    v142 = qvalue(elt(env, 1)); /* dipevlist!* */
    stack[-3] = v142;
    goto v100;

v100:
    v142 = stack[-2];
    if (v142 == nil) goto v61;
    v142 = stack[-2];
    v142 = qcar(v142);
    stack[-1] = v142;
    goto v134;

v134:
    v142 = stack[-3];
    v142 = qcdr(v142);
    if (v142 == nil) goto v118;
    v142 = stack[-2];
    v109 = qcar(v142);
    v142 = stack[-3];
    v142 = qcdr(v142);
    v142 = qcar(v142);
    fn = elt(env, 3); /* evcompless!? */
    v142 = (*qfn2(fn))(qenv(fn), v109, v142);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    if (v142 == nil) goto v118;
    v142 = stack[-3];
    v142 = qcdr(v142);
    stack[-3] = v142;
    goto v134;

v118:
    v142 = stack[-3];
    v142 = qcdr(v142);
    if (v142 == nil) goto v143;
    v109 = stack[-1];
    v142 = stack[-3];
    v142 = qcdr(v142);
    v142 = qcar(v142);
    if (!(equal(v109, v142))) goto v143;
    v109 = stack[-2];
    v142 = stack[-3];
    v142 = qcdr(v142);
    v142 = qcar(v142);
    fn = elt(env, 4); /* setcar */
    v142 = (*qfn2(fn))(qenv(fn), v109, v142);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    goto v144;

v144:
    v142 = stack[-2];
    v142 = qcdr(v142);
    v142 = qcdr(v142);
    stack[-2] = v142;
    goto v100;

v143:
    stack[0] = stack[-3];
    v109 = stack[-1];
    v142 = stack[-3];
    v142 = qcdr(v142);
    v142 = cons(v109, v142);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    fn = elt(env, 5); /* setcdr */
    v142 = (*qfn2(fn))(qenv(fn), stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    goto v144;

v61:
    v142 = nil;
    { popv(5); return onevalue(v142); }
/* error exit handlers */
v40:
    popv(5);
    return nil;
}



/* Code for !*wedgepf2pf */

static Lisp_Object CC_Hwedgepf2pf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v136, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *wedgepf2pf");
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
    goto v82;

v82:
    v80 = stack[0];
    if (v80 == nil) goto v61;
    v80 = stack[0];
    v80 = qcar(v80);
    v80 = qcar(v80);
    fn = elt(env, 1); /* mkuwedge */
    v53 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    v80 = stack[0];
    v80 = qcar(v80);
    v136 = qcdr(v80);
    v80 = stack[-1];
    v80 = acons(v53, v136, v80);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    stack[-1] = v80;
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[0] = v80;
    goto v82;

v61:
    v80 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v80);
    }
/* error exit handlers */
v92:
    popv(3);
    return nil;
}



/* Code for mktails1 */

static Lisp_Object MS_CDECL CC_mktails1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v76,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktails1");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v76,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v83;
    v158 = v76;
    stack[-1] = v0;
/* end of prologue */
    v159 = stack[-1];
    fn = elt(env, 3); /* getroad */
    v158 = (*qfn2(fn))(qenv(fn), v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v159 = v158;
    v160 = (Lisp_Object)1; /* 0 */
    v158 = v159;
    if (v160 == v158) goto v145;
    v160 = (Lisp_Object)1; /* 0 */
    v158 = stack[-1];
    v158 = qcdr(v158);
    if (v160 == v158) goto v140;
    v160 = stack[-1];
    v158 = stack[0];
    v158 = Lassoc(nil, v160, v158);
    v160 = v158;
    v158 = v160;
    if (v158 == nil) goto v43;
    v158 = v160;
    v158 = qcdr(v158);
    v158 = qcdr(v158);
    if (v158 == nil) goto v142;
    v158 = v160;
    v158 = qcdr(v158);
    v159 = Lreverse(nil, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    v158 = stack[0];
    popv(4);
    return cons(v159, v158);

v142:
    v158 = v160;
    v159 = qcdr(v158);
    v158 = stack[0];
    popv(4);
    return cons(v159, v158);

v43:
    v158 = stack[-1];
    fn = elt(env, 4); /* mkinds */
    v158 = (*qfn2(fn))(qenv(fn), v158, v159);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v160 = v158;
    stack[-2] = v160;
    v158 = stack[-1];
    v159 = v160;
    v159 = cons(v158, v159);
    nil = C_nil;
    if (exception_pending()) goto v161;
    v158 = stack[0];
    {
        Lisp_Object v162 = stack[-2];
        popv(4);
        return list2star(v162, v159, v158);
    }

v140:
    v158 = stack[-1];
    v159 = qcar(v158);
    v158 = elt(env, 2); /* replace_by_vector */
    v158 = get(v159, v158);
    env = stack[-3];
    if (!(v158 == nil)) goto v139;
    v158 = stack[-1];
    v158 = qcar(v158);
    goto v139;

v139:
    v159 = ncons(v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    v158 = stack[0];
    popv(4);
    return cons(v159, v158);

v145:
    v159 = qvalue(elt(env, 1)); /* nil */
    v158 = stack[0];
    popv(4);
    return cons(v159, v158);
/* error exit handlers */
v161:
    popv(4);
    return nil;
}



/* Code for formsetq */

static Lisp_Object MS_CDECL CC_formsetq(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v76,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v164, v124, v165, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v83;
    v165 = v76;
    v41 = v0;
/* end of prologue */
    v164 = v124;
    v137 = elt(env, 1); /* symbolic */
    if (v164 == v137) goto v145;
    v137 = v41;
    v164 = v165;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v137, v164, v124);
    }

v145:
    v137 = v41;
    v137 = qcdr(v137);
    v164 = qcar(v137);
    v137 = elt(env, 2); /* list */
    if (!consp(v164)) goto v49;
    v164 = qcar(v164);
    if (!(v164 == v137)) goto v49;
    v137 = v41;
    v164 = v165;
    {
        fn = elt(env, 5); /* formsetq1 */
        return (*qfnn(fn))(qenv(fn), 3, v137, v164, v124);
    }

v49:
    v137 = v41;
    v137 = qcdr(v137);
    v164 = qcar(v137);
    v137 = elt(env, 3); /* cons */
    if (!consp(v164)) goto v111;
    v164 = qcar(v164);
    if (!(v164 == v137)) goto v111;
    v137 = v41;
    v164 = v165;
    {
        fn = elt(env, 6); /* formsetq2 */
        return (*qfnn(fn))(qenv(fn), 3, v137, v164, v124);
    }

v111:
    v137 = v41;
    v164 = v165;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v137, v164, v124);
    }
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v76,
                         Lisp_Object v83, Lisp_Object v122, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v142, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel1");
#endif
    if (stack >= stacklimit)
    {
        push4(v122,v83,v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v76,v83,v122);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v122;
    stack[-1] = v83;
    stack[-2] = v76;
    stack[-3] = v0;
/* end of prologue */

v104:
    v42 = stack[-2];
    v42 = qcar(v42);
    v42 = integerp(v42);
    if (v42 == nil) goto v157;
    v42 = stack[-2];
    v142 = qcar(v42);
    v42 = stack[0];
    v42 = qcar(v42);
    v42 = (Lisp_Object)geq2(v142, v42);
    nil = C_nil;
    if (exception_pending()) goto v40;
    v42 = v42 ? lisp_true : nil;
    env = stack[-4];
    if (!(v42 == nil)) goto v94;
    v42 = stack[-2];
    v142 = qcar(v42);
    v42 = (Lisp_Object)1; /* 0 */
    v42 = (Lisp_Object)lessp2(v142, v42);
    nil = C_nil;
    if (exception_pending()) goto v40;
    v42 = v42 ? lisp_true : nil;
    env = stack[-4];
    if (!(v42 == nil)) goto v94;
    v42 = stack[-2];
    v42 = qcdr(v42);
    if (v42 == nil) goto v87;
    v142 = stack[-3];
    v42 = stack[-2];
    v42 = qcar(v42);
    v42 = *(Lisp_Object *)((char *)v142 + (CELL-TAG_VECTOR) + ((int32_t)v42/(16/CELL)));
    stack[-3] = v42;
    v42 = stack[-2];
    v42 = qcdr(v42);
    stack[-2] = v42;
    v42 = stack[0];
    v42 = qcdr(v42);
    stack[0] = v42;
    goto v104;

v87:
    v109 = stack[-3];
    v42 = stack[-2];
    v142 = qcar(v42);
    v42 = stack[-1];
    *(Lisp_Object *)((char *)v109 + (CELL-TAG_VECTOR) + ((int32_t)v142/(16/CELL))) = v42;
    { popv(5); return onevalue(v42); }

v94:
    v42 = elt(env, 2); /* "Array out of bounds" */
    v142 = v42;
    v42 = v142;
    qvalue(elt(env, 3)) = v42; /* errmsg!* */
    v42 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v42 == nil)) goto v51;
    v42 = v142;
    fn = elt(env, 5); /* lprie */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-4];
    goto v51;

v51:
    v42 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v40;
    v42 = nil;
    { popv(5); return onevalue(v42); }

v157:
    v42 = stack[-2];
    v142 = qcar(v42);
    v42 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v142, v42);
    }
/* error exit handlers */
v40:
    popv(5);
    return nil;
}



/* Code for mo_from_a */

static Lisp_Object CC_mo_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_from_a");
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
    stack[0] = stack[-3];
    v107 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    v107 = Lmember(nil, stack[0], v107);
    if (v107 == nil) goto v157;
    v107 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    stack[-4] = v107;
    v107 = stack[-4];
    if (v107 == nil) goto v170;
    v107 = stack[-4];
    v107 = qcar(v107);
    v108 = v107;
    v107 = stack[-3];
    if (equal(v108, v107)) goto v90;
    v107 = (Lisp_Object)1; /* 0 */
    goto v50;

v50:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    stack[-1] = v107;
    stack[-2] = v107;
    goto v53;

v53:
    v107 = stack[-4];
    v107 = qcdr(v107);
    stack[-4] = v107;
    v107 = stack[-4];
    if (v107 == nil) goto v128;
    stack[0] = stack[-1];
    v107 = stack[-4];
    v107 = qcar(v107);
    v108 = v107;
    v107 = stack[-3];
    if (equal(v108, v107)) goto v73;
    v107 = (Lisp_Object)1; /* 0 */
    goto v98;

v98:
    v107 = ncons(v107);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    v107 = Lrplacd(nil, stack[0], v107);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    v107 = stack[-1];
    v107 = qcdr(v107);
    stack[-1] = v107;
    goto v53;

v73:
    v107 = (Lisp_Object)17; /* 1 */
    goto v98;

v128:
    v107 = stack[-2];
    goto v136;

v136:
    fn = elt(env, 5); /* mo!=shorten */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    stack[0] = v107;
    fn = elt(env, 6); /* mo!=deglist */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v169;
    {
        Lisp_Object v120 = stack[0];
        popv(6);
        return cons(v120, v107);
    }

v90:
    v107 = (Lisp_Object)17; /* 1 */
    goto v50;

v170:
    v107 = qvalue(elt(env, 3)); /* nil */
    goto v136;

v157:
    v108 = stack[-3];
    v107 = elt(env, 2); /* "dpoly variable" */
    {
        popv(6);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v108, v107);
    }
/* error exit handlers */
v169:
    popv(6);
    return nil;
}



/* Code for exptpri */

static Lisp_Object CC_exptpri(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v211, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptpri");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v211 = v76;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*list */
    qvalue(elt(env, 1)) = nil; /* !*list */
    stack[0] = nil;
    v210 = qvalue(elt(env, 2)); /* !*nat */
    if (v210 == nil) goto v57;
    v210 = qvalue(elt(env, 3)); /* !*fort */
    if (!(v210 == nil)) goto v57;
    v212 = elt(env, 5); /* expt */
    v210 = elt(env, 6); /* infix */
    v210 = get(v212, v210);
    env = stack[-7];
    stack[-2] = v210;
    v210 = (Lisp_Object)greaterp2(v210, v211);
    nil = C_nil;
    if (exception_pending()) goto v213;
    v210 = v210 ? lisp_true : nil;
    env = stack[-7];
    v210 = (v210 == nil ? lisp_true : nil);
    stack[-4] = v210;
    v210 = stack[-5];
    v210 = qcdr(v210);
    v210 = qcar(v210);
    stack[-1] = v210;
    v210 = stack[-5];
    v210 = qcdr(v210);
    v210 = qcdr(v210);
    v210 = qcar(v210);
    stack[-3] = v210;
    v210 = qvalue(elt(env, 7)); /* !*eraise */
    if (v210 == nil) goto v42;
    v210 = stack[-1];
    if (!consp(v210)) goto v42;
    v210 = stack[-1];
    v211 = qcar(v210);
    v210 = elt(env, 8); /* prifn */
    v210 = get(v211, v210);
    env = stack[-7];
    stack[0] = v210;
    if (v210 == nil) goto v42;
    v211 = stack[0];
    v210 = elt(env, 5); /* expt */
    v211 = get(v211, v210);
    env = stack[-7];
    v210 = elt(env, 9); /* inbrackets */
    if (!(v211 == v210)) goto v42;
    v212 = stack[-1];
    v211 = (Lisp_Object)1; /* 0 */
    v210 = elt(env, 9); /* inbrackets */
    fn = elt(env, 21); /* layout!-formula */
    v210 = (*qfnn(fn))(qenv(fn), 3, v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    stack[-1] = v210;
    goto v144;

v144:
    v210 = stack[-1];
    if (v210 == nil) goto v147;
    stack[-5] = qvalue(elt(env, 12)); /* !*ratpri */
    qvalue(elt(env, 12)) = nil; /* !*ratpri */
    v211 = stack[-3];
    v210 = elt(env, 13); /* quotient */
    if (!consp(v211)) goto v214;
    v211 = qcar(v211);
    if (!(v211 == v210)) goto v214;
    v210 = stack[-3];
    v210 = qcdr(v210);
    v211 = qcar(v210);
    v210 = elt(env, 14); /* minus */
    if (!consp(v211)) goto v214;
    v211 = qcar(v211);
    if (!(v211 == v210)) goto v214;
    stack[0] = elt(env, 14); /* minus */
    v210 = stack[-3];
    v212 = qcar(v210);
    v210 = stack[-3];
    v210 = qcdr(v210);
    v210 = qcar(v210);
    v210 = qcdr(v210);
    v211 = qcar(v210);
    v210 = stack[-3];
    v210 = qcdr(v210);
    v210 = qcdr(v210);
    v210 = qcar(v210);
    v210 = list3(v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    v210 = list2(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    stack[-3] = v210;
    goto v216;

v216:
    v212 = stack[-3];
    v210 = qvalue(elt(env, 7)); /* !*eraise */
    if (v210 == nil) goto v217;
    v210 = (Lisp_Object)1; /* 0 */
    v211 = v210;
    goto v218;

v218:
    v210 = qvalue(elt(env, 11)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v210 = (*qfnn(fn))(qenv(fn), 3, v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    stack[-3] = v210;
    qvalue(elt(env, 12)) = stack[-5]; /* !*ratpri */
    v210 = stack[-3];
    if (v210 == nil) goto v219;
    v210 = stack[-1];
    v210 = qcar(v210);
    v211 = qcdr(v210);
    v210 = stack[-3];
    v210 = qcar(v210);
    v210 = qcdr(v210);
    v210 = plus2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    stack[-5] = v210;
    v210 = stack[-4];
    if (v210 == nil) goto v220;
    v211 = stack[-5];
    v210 = (Lisp_Object)33; /* 2 */
    v210 = plus2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    stack[-5] = v210;
    goto v220;

v220:
    stack[0] = stack[-5];
    v210 = qvalue(elt(env, 11)); /* nil */
    v211 = Llinelength(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = qvalue(elt(env, 15)); /* spare!* */
    v211 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = qvalue(elt(env, 16)); /* orig!* */
    v210 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = (Lisp_Object)greaterp2(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    v210 = v210 ? lisp_true : nil;
    env = stack[-7];
    if (v210 == nil) goto v221;
    v210 = elt(env, 4); /* failed */
    goto v101;

v101:
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    { popv(8); return onevalue(v210); }

v221:
    stack[0] = stack[-5];
    v210 = qvalue(elt(env, 11)); /* nil */
    v211 = Llinelength(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = qvalue(elt(env, 15)); /* spare!* */
    v211 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = qvalue(elt(env, 17)); /* posn!* */
    v210 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = (Lisp_Object)greaterp2(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    v210 = v210 ? lisp_true : nil;
    env = stack[-7];
    if (v210 == nil) goto v64;
    v210 = qvalue(elt(env, 18)); /* t */
    fn = elt(env, 22); /* terpri!* */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    goto v64;

v64:
    v210 = stack[-4];
    if (v210 == nil) goto v222;
    v210 = elt(env, 19); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    goto v222;

v222:
    v210 = stack[-1];
    fn = elt(env, 24); /* putpline */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = qvalue(elt(env, 7)); /* !*eraise */
    if (v210 == nil) goto v223;
    v211 = (Lisp_Object)17; /* 1 */
    v210 = stack[-3];
    v210 = qcdr(v210);
    v210 = qcar(v210);
    v210 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    stack[-5] = v210;
    goto v224;

v224:
    v212 = (Lisp_Object)1; /* 0 */
    v211 = stack[-5];
    v210 = stack[-3];
    v210 = qcar(v210);
    v210 = qcar(v210);
    fn = elt(env, 25); /* update!-pline */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = stack[-3];
    v210 = qcar(v210);
    stack[-1] = qcdr(v210);
    v210 = stack[-3];
    v210 = qcdr(v210);
    v211 = qcar(v210);
    v210 = stack[-5];
    stack[0] = plus2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = stack[-3];
    v210 = qcdr(v210);
    v211 = qcdr(v210);
    v210 = stack[-5];
    v210 = plus2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = cons(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = acons(stack[-2], stack[-1], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    fn = elt(env, 24); /* putpline */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = stack[-4];
    if (v210 == nil) goto v225;
    v210 = elt(env, 20); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    goto v225;

v225:
    v210 = nil;
    goto v101;

v223:
    v210 = elt(env, 5); /* expt */
    fn = elt(env, 26); /* oprin */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = (Lisp_Object)1; /* 0 */
    stack[-5] = v210;
    goto v224;

v219:
    v210 = elt(env, 4); /* failed */
    goto v101;

v217:
    v210 = stack[-2];
    v211 = v210;
    goto v218;

v214:
    v211 = stack[-3];
    v210 = elt(env, 14); /* minus */
    if (!consp(v211)) goto v226;
    v211 = qcar(v211);
    if (!(v211 == v210)) goto v226;
    v210 = stack[-3];
    v210 = qcdr(v210);
    v210 = qcar(v210);
    if (!(is_number(v210))) goto v226;
    v210 = stack[-3];
    v210 = qcdr(v210);
    v210 = qcar(v210);
    v210 = negate(v210);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-7];
    goto v67;

v67:
    stack[-3] = v210;
    goto v216;

v226:
    v210 = stack[-3];
    goto v67;

v147:
    v210 = elt(env, 4); /* failed */
    goto v101;

v42:
    v211 = stack[0];
    v210 = elt(env, 10); /* indexprin */
    if (!(v211 == v210)) goto v120;
    v211 = stack[-1];
    v210 = stack[-3];
    fn = elt(env, 27); /* indexpower */
    v211 = (*qfn2(fn))(qenv(fn), v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    v210 = elt(env, 4); /* failed */
    if (v211 == v210) goto v120;
    v210 = qvalue(elt(env, 11)); /* nil */
    goto v101;

v120:
    v212 = stack[-1];
    v211 = stack[-2];
    v210 = qvalue(elt(env, 11)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v210 = (*qfnn(fn))(qenv(fn), 3, v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-7];
    stack[-1] = v210;
    goto v144;

v57:
    v210 = elt(env, 4); /* failed */
    goto v101;
/* error exit handlers */
v215:
    env = stack[-7];
    qvalue(elt(env, 12)) = stack[-5]; /* !*ratpri */
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
v213:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
}



/* Code for reduce_pv0 */

static Lisp_Object MS_CDECL CC_reduce_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v76,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v76,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v83;
    stack[-4] = v76;
    stack[0] = v0;
/* end of prologue */
    v232 = stack[-4];
    if (v232 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v232 = stack[0];
    if (v232 == nil) goto v101;
    v232 = stack[0];
    stack[-5] = v232;
    goto v93;

v93:
    v232 = stack[-5];
    if (v232 == nil) goto v62;
    v232 = stack[-4];
    if (v232 == nil) goto v62;
    v232 = stack[-5];
    v232 = qcar(v232);
    v233 = qcdr(v232);
    v232 = stack[-4];
    v232 = qcar(v232);
    v232 = qcdr(v232);
    v232 = (Lisp_Object)greaterp2(v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v232 = v232 ? lisp_true : nil;
    env = stack[-6];
    if (v232 == nil) goto v62;
    v232 = stack[-5];
    v232 = qcdr(v232);
    stack[-5] = v232;
    goto v93;

v62:
    v232 = stack[-5];
    if (v232 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v232 = stack[-4];
    if (v232 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v232 = stack[-4];
    v232 = qcar(v232);
    v233 = qcdr(v232);
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = qcdr(v232);
    if (!(equal(v233, v232))) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v232 = stack[-5];
    v232 = qcar(v232);
    v233 = qcar(v232);
    v232 = stack[-4];
    v232 = qcar(v232);
    v232 = qcar(v232);
    fn = elt(env, 3); /* lcm */
    v232 = (*qfn2(fn))(qenv(fn), v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    stack[-2] = v232;
    v233 = stack[-2];
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = quot2(v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    stack[0] = stack[-4];
    v233 = stack[-2];
    v232 = stack[-4];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = quot2(v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    v232 = negate(v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    v232 = (*qfn2(fn))(qenv(fn), stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    fn = elt(env, 5); /* pv_add */
    v232 = (*qfn2(fn))(qenv(fn), stack[-1], v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    stack[0] = v232;
    v232 = stack[-3];
    if (v232 == nil) goto v234;
    v232 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v232; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v234:
    stack[-1] = qvalue(elt(env, 2)); /* pv_den */
    v233 = stack[-2];
    v232 = stack[-5];
    v232 = qcar(v232);
    v232 = qcar(v232);
    v232 = quot2(v233, v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    v232 = times2(stack[-1], v232);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-6];
    qvalue(elt(env, 2)) = v232; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v101:
    v232 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v232); }
/* error exit handlers */
v22:
    popv(7);
    return nil;
}



/* Code for simpiden */

static Lisp_Object CC_simpiden(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v281, v282, v283;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpiden");
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
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    v281 = stack[0];
    v281 = qcar(v281);
    stack[-6] = v281;
    v281 = stack[0];
    v281 = qcdr(v281);
    stack[0] = v281;
    v282 = stack[-6];
    v281 = elt(env, 1); /* !:rn!: */
    v281 = get(v282, v281);
    env = stack[-7];
    if (!(v281 == nil)) goto v141;
    v282 = stack[-6];
    v281 = elt(env, 2); /* !:rd!: */
    v281 = get(v282, v281);
    env = stack[-7];
    if (!(v281 == nil)) goto v141;

v156:
    v281 = stack[0];
    if (v281 == nil) goto v115;
    v281 = stack[0];
    v282 = qcar(v281);
    v281 = elt(env, 3); /* list */
    if (!consp(v282)) goto v115;
    v282 = qcar(v282);
    if (!(v282 == v281)) goto v115;
    v281 = stack[0];
    v281 = qcdr(v281);
    if (!(v281 == nil)) goto v115;
    stack[-1] = stack[-6];
    v281 = stack[0];
    v281 = qcar(v281);
    fn = elt(env, 15); /* aeval */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v282 = list2(stack[-1], v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 16); /* mksq */
        return (*qfn2(fn))(qenv(fn), v282, v281);
    }

v115:
    v281 = stack[0];
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v109;
    v281 = stack[-3];
    v281 = qcar(v281);
    fn = elt(env, 15); /* aeval */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v281;
    stack[-2] = v281;
    goto v165;

v165:
    v281 = stack[-3];
    v281 = qcdr(v281);
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v35;
    stack[0] = stack[-1];
    v281 = stack[-3];
    v281 = qcar(v281);
    fn = elt(env, 15); /* aeval */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = Lrplacd(nil, stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v165;

v35:
    v281 = stack[-2];
    goto v124;

v124:
    stack[-5] = v281;
    v281 = stack[-5];
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v285;
    v281 = stack[-3];
    v281 = qcar(v281);
    v283 = v281;
    v282 = v283;
    v281 = elt(env, 5); /* !*sq */
    if (!consp(v282)) goto v162;
    v282 = qcar(v282);
    if (!(v282 == v281)) goto v162;
    v281 = v283;
    v281 = qcdr(v281);
    v281 = qcar(v281);
    fn = elt(env, 17); /* prepsqxx */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v30;

v30:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v281;
    stack[-2] = v281;
    goto v286;

v286:
    v281 = stack[-3];
    v281 = qcdr(v281);
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v287;
    stack[0] = stack[-1];
    v281 = stack[-3];
    v281 = qcar(v281);
    v283 = v281;
    v282 = v283;
    v281 = elt(env, 5); /* !*sq */
    if (!consp(v282)) goto v67;
    v282 = qcar(v282);
    if (!(v282 == v281)) goto v67;
    v281 = v283;
    v281 = qcdr(v281);
    v281 = qcar(v281);
    fn = elt(env, 17); /* prepsqxx */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v288;

v288:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = Lrplacd(nil, stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v286;

v67:
    v281 = v283;
    if (is_number(v281)) goto v289;
    v281 = v283;
    goto v288;

v289:
    v281 = v283;
    goto v288;

v287:
    v281 = stack[-2];
    goto v146;

v146:
    stack[0] = v281;
    v281 = stack[0];
    if (v281 == nil) goto v6;
    v281 = stack[0];
    v282 = qcar(v281);
    v281 = (Lisp_Object)1; /* 0 */
    if (!(v282 == v281)) goto v6;
    v282 = stack[-6];
    v281 = elt(env, 7); /* odd */
    v281 = Lflagp(nil, v282, v281);
    env = stack[-7];
    if (v281 == nil) goto v6;
    v282 = stack[-6];
    v281 = elt(env, 8); /* nonzero */
    v281 = Lflagp(nil, v282, v281);
    env = stack[-7];
    if (!(v281 == nil)) goto v6;
    v282 = qvalue(elt(env, 4)); /* nil */
    v281 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v282, v281);

v6:
    v282 = stack[-6];
    v281 = stack[0];
    v281 = cons(v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v281;
    v281 = stack[-6];
    if (!symbolp(v281)) v281 = nil;
    else { v281 = qfastgets(v281);
           if (v281 != nil) { v281 = elt(v281, 0); /* noncom */
#ifdef RECORD_GET
             if (v281 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v281 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v281 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v281 == SPID_NOPROP) v281 = nil; else v281 = lisp_true; }}
#endif
    if (v281 == nil) goto v290;
    v281 = qvalue(elt(env, 6)); /* t */
    qvalue(elt(env, 9)) = v281; /* ncmp!* */
    goto v290;

v290:
    v281 = qvalue(elt(env, 10)); /* subfg!* */
    if (v281 == nil) goto v291;
    v282 = stack[-6];
    v281 = elt(env, 11); /* linear */
    v281 = Lflagp(nil, v282, v281);
    env = stack[-7];
    if (v281 == nil) goto v3;
    v281 = stack[0];
    fn = elt(env, 18); /* formlnr */
    v282 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v282;
    v281 = stack[0];
    if (equal(v282, v281)) goto v3;
    v281 = stack[-1];
    {
        popv(8);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v281);
    }

v3:
    v281 = stack[0];
    fn = elt(env, 20); /* opmtch */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v281;
    if (v281 == nil) goto v291;
    v281 = stack[-1];
    {
        popv(8);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v281);
    }

v291:
    v282 = stack[-6];
    v281 = elt(env, 12); /* symmetric */
    v281 = Lflagp(nil, v282, v281);
    env = stack[-7];
    if (v281 == nil) goto v292;
    stack[-1] = stack[-6];
    v281 = stack[0];
    v281 = qcdr(v281);
    fn = elt(env, 21); /* ordn */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = cons(stack[-1], v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v281;
    goto v293;

v293:
    v282 = stack[-6];
    v281 = elt(env, 14); /* even */
    v281 = Lflagp(nil, v282, v281);
    env = stack[-7];
    if (!(v281 == nil)) goto v294;
    v282 = stack[-6];
    v281 = elt(env, 7); /* odd */
    v281 = Lflagp(nil, v282, v281);
    env = stack[-7];
    if (!(v281 == nil)) goto v294;

v295:
    v282 = stack[0];
    v281 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksq */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v281;
    v281 = stack[-4];
    if (v281 == nil) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v281 = stack[0];
    v281 = qcar(v281);
    fn = elt(env, 22); /* negf */
    v282 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v281 = stack[0];
    v281 = qcdr(v281);
    popv(8);
    return cons(v282, v281);

v294:
    v281 = stack[-5];
    if (v281 == nil) goto v295;
    v281 = stack[-5];
    v281 = qcar(v281);
    fn = elt(env, 19); /* simp */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-5] = v281;
    v281 = qcar(v281);
    fn = elt(env, 23); /* minusf */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    if (v281 == nil) goto v295;
    v282 = stack[-6];
    v281 = elt(env, 14); /* even */
    v281 = Lflagp(nil, v282, v281);
    env = stack[-7];
    if (!(v281 == nil)) goto v296;
    v281 = stack[-4];
    v281 = (v281 == nil ? lisp_true : nil);
    stack[-4] = v281;
    goto v296;

v296:
    stack[-1] = stack[-6];
    v281 = stack[-5];
    v281 = qcar(v281);
    fn = elt(env, 22); /* negf */
    v282 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[-5];
    v281 = qcdr(v281);
    v281 = cons(v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 17); /* prepsqxx */
    v282 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[0];
    v281 = qcdr(v281);
    v281 = qcdr(v281);
    v281 = list2star(stack[-1], v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v281;
    v281 = stack[0];
    fn = elt(env, 20); /* opmtch */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v281;
    if (v281 == nil) goto v295;
    v281 = stack[-4];
    if (v281 == nil) goto v297;
    v281 = stack[-1];
    fn = elt(env, 19); /* simp */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v281;
    v281 = stack[0];
    v281 = qcar(v281);
    fn = elt(env, 22); /* negf */
    v282 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v281 = stack[0];
    v281 = qcdr(v281);
    popv(8);
    return cons(v282, v281);

v297:
    v281 = stack[-1];
    {
        popv(8);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v281);
    }

v292:
    v282 = stack[-6];
    v281 = elt(env, 13); /* antisymmetric */
    v281 = Lflagp(nil, v282, v281);
    env = stack[-7];
    if (v281 == nil) goto v293;
    v281 = stack[0];
    v281 = qcdr(v281);
    fn = elt(env, 24); /* repeats */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    if (v281 == nil) goto v298;
    v282 = qvalue(elt(env, 4)); /* nil */
    v281 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v282, v281);

v298:
    v281 = stack[0];
    v281 = qcdr(v281);
    fn = elt(env, 21); /* ordn */
    v282 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v282;
    v281 = stack[0];
    v281 = qcdr(v281);
    fn = elt(env, 25); /* permp */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    if (!(v281 == nil)) goto v299;
    v281 = qvalue(elt(env, 6)); /* t */
    stack[-4] = v281;
    goto v299;

v299:
    v281 = stack[0];
    v282 = qcar(v281);
    v281 = stack[-1];
    v281 = cons(v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-6] = v281;
    v282 = stack[-1];
    v281 = stack[0];
    v281 = qcdr(v281);
    if (equal(v282, v281)) goto v171;
    v281 = stack[-6];
    fn = elt(env, 20); /* opmtch */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v281;
    if (v281 == nil) goto v171;
    v281 = stack[-4];
    if (v281 == nil) goto v210;
    v281 = stack[-1];
    fn = elt(env, 19); /* simp */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v281;
    v281 = stack[0];
    v281 = qcar(v281);
    fn = elt(env, 22); /* negf */
    v282 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v281 = stack[0];
    v281 = qcdr(v281);
    popv(8);
    return cons(v282, v281);

v210:
    v281 = stack[-1];
    {
        popv(8);
        fn = elt(env, 19); /* simp */
        return (*qfn1(fn))(qenv(fn), v281);
    }

v171:
    v281 = stack[-6];
    stack[0] = v281;
    goto v293;

v162:
    v281 = v283;
    if (is_number(v281)) goto v205;
    v281 = v283;
    goto v30;

v205:
    v281 = v283;
    goto v30;

v285:
    v281 = qvalue(elt(env, 4)); /* nil */
    goto v146;

v109:
    v281 = qvalue(elt(env, 4)); /* nil */
    goto v124;

v141:
    v282 = stack[-6];
    v281 = stack[0];
    fn = elt(env, 26); /* valuechk */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-5] = v281;
    if (v281 == nil) goto v156;
    else { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
/* error exit handlers */
v284:
    popv(8);
    return nil;
}



/* Code for rl_csimpl */

static Lisp_Object CC_rl_csimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v155, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_csimpl");
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
    v95 = qvalue(elt(env, 1)); /* !*rlsimpl */
    if (v95 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v95 = elt(env, 2); /* rl_simpl */
    fn = elt(env, 4); /* getd */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    if (v95 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v55 = stack[0];
    v155 = qvalue(elt(env, 3)); /* nil */
    v95 = (Lisp_Object)-15; /* -1 */
    {
        popv(2);
        fn = elt(env, 2); /* rl_simpl */
        return (*qfnn(fn))(qenv(fn), 3, v55, v155, v95);
    }
/* error exit handlers */
v145:
    popv(2);
    return nil;
}



/* Code for wureducedpolysp */

static Lisp_Object CC_wureducedpolysp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wureducedpolysp");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v76;
    stack[-1] = v0;
/* end of prologue */

v81:
    v80 = stack[0];
    v80 = (v80 == nil ? lisp_true : nil);
    if (!(v80 == nil)) { popv(3); return onevalue(v80); }
    v136 = stack[-1];
    v80 = stack[0];
    v80 = qcar(v80);
    fn = elt(env, 2); /* wureducedp */
    v80 = (*qfn2(fn))(qenv(fn), v136, v80);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    if (v80 == nil) goto v101;
    v136 = stack[-1];
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[-1] = v136;
    stack[0] = v80;
    goto v81;

v101:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v80); }
/* error exit handlers */
v91:
    popv(3);
    return nil;
}



/* Code for tmsf */

static Lisp_Object CC_tmsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v158, v159, v160;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tmsf");
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
    v158 = (Lisp_Object)1; /* 0 */
    v160 = v158;
    goto v100;

v100:
    v158 = stack[-1];
    if (!consp(v158)) goto v61;
    v158 = stack[-1];
    v158 = qcar(v158);
    if (!consp(v158)) goto v61;
    stack[-2] = v160;
    v158 = stack[-1];
    v158 = qcar(v158);
    v158 = qcar(v158);
    v158 = qcar(v158);
    v160 = v158;
    v159 = v158;
    v158 = v159;
    if (!consp(v158)) goto v144;
    v158 = v159;
    v158 = qcar(v158);
    v158 = (consp(v158) ? nil : lisp_true);
    v158 = (v158 == nil ? lisp_true : nil);
    goto v300;

v300:
    if (v158 == nil) goto v139;
    v158 = v160;
    v158 = CC_tmsf(env, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    stack[0] = v158;
    goto v71;

v71:
    v158 = stack[-1];
    v158 = qcar(v158);
    v158 = qcdr(v158);
    if (!(is_number(v158))) goto v85;
    v158 = stack[-1];
    v158 = qcar(v158);
    v158 = qcdr(v158);
    v158 = Ltruncate(nil, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v159 = Labsval(nil, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v158 = (Lisp_Object)17; /* 1 */
    if (!(v159 == v158)) goto v85;
    v158 = (Lisp_Object)1; /* 0 */
    goto v78;

v78:
    v158 = plus2(stack[0], v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v158 = plus2(stack[-2], v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v160 = v158;
    v158 = stack[-1];
    v158 = qcar(v158);
    v158 = qcar(v158);
    v159 = qcdr(v158);
    v158 = (Lisp_Object)17; /* 1 */
    if (v159 == v158) goto v124;
    v158 = stack[-1];
    v158 = qcar(v158);
    v158 = qcar(v158);
    v159 = qcdr(v158);
    v158 = (Lisp_Object)33; /* 2 */
    if (v159 == v158) goto v230;
    v159 = v160;
    v158 = (Lisp_Object)33; /* 2 */
    v158 = plus2(v159, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v160 = v158;
    goto v124;

v124:
    v158 = stack[-1];
    v158 = qcdr(v158);
    stack[-1] = v158;
    goto v100;

v230:
    v158 = v160;
    v158 = add1(v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    v160 = v158;
    goto v124;

v85:
    v158 = stack[-1];
    v158 = qcar(v158);
    v158 = qcdr(v158);
    v158 = CC_tmsf(env, v158);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    goto v78;

v139:
    v158 = (Lisp_Object)17; /* 1 */
    stack[0] = v158;
    goto v71;

v144:
    v158 = qvalue(elt(env, 1)); /* nil */
    goto v300;

v61:
    v158 = stack[-1];
    if (v158 == nil) { popv(4); return onevalue(v160); }
    v158 = v160;
    popv(4);
    return add1(v158);
/* error exit handlers */
v161:
    popv(4);
    return nil;
}



/* Code for ibalp_unvar!-unsatlist */

static Lisp_Object CC_ibalp_unvarKunsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v316, v256;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_unvar-unsatlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v76;
    v316 = v0;
/* end of prologue */
    stack[-5] = v316;
    goto v100;

v100:
    v316 = stack[-5];
    if (v316 == nil) goto v61;
    v316 = stack[-5];
    v316 = qcar(v316);
    stack[-3] = v316;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v256 = stack[-4];
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    fn = elt(env, 2); /* delq */
    v316 = (*qfn2(fn))(qenv(fn), v256, v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    if (!(v316 == nil)) goto v154;
    v316 = stack[-3];
    v316 = qcar(v316);
    stack[-2] = v316;
    goto v99;

v99:
    v316 = stack[-2];
    if (v316 == nil) goto v139;
    v316 = stack[-2];
    v316 = qcar(v316);
    stack[-1] = v316;
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = add1(v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v316 = stack[-1];
    fn = elt(env, 4); /* ibalp_calcmom */
    v316 = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-2];
    v316 = qcdr(v316);
    stack[-2] = v316;
    goto v99;

v139:
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcar(v316);
    stack[-2] = v316;
    goto v37;

v37:
    v316 = stack[-2];
    if (v316 == nil) goto v117;
    v316 = stack[-2];
    v316 = qcar(v316);
    stack[-1] = v316;
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = add1(v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v316 = stack[-1];
    fn = elt(env, 4); /* ibalp_calcmom */
    v316 = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-2];
    v316 = qcdr(v316);
    stack[-2] = v316;
    goto v37;

v117:
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    stack[-1] = v316;
    goto v287;

v287:
    v316 = stack[-1];
    if (v316 == nil) goto v14;
    v316 = stack[-1];
    v316 = qcar(v316);
    v256 = v316;
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    v256 = qcdr(v256);
    stack[0] = qcdr(v256);
    v256 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    fn = elt(env, 2); /* delq */
    v316 = (*qfn2(fn))(qenv(fn), v256, v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-1];
    v316 = qcdr(v316);
    stack[-1] = v316;
    goto v287;

v14:
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v256 = qcdr(v316);
    v316 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), v256, v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-3];
    fn = elt(env, 5); /* ibalp_getnewwl */
    v316 = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    stack[-1] = v316;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v256 = stack[-1];
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = cons(v256, v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v256 = stack[-3];
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = cons(v256, v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-3];
    fn = elt(env, 5); /* ibalp_getnewwl */
    v316 = (*qfn1(fn))(qenv(fn), v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    stack[-1] = v316;
    v316 = stack[-1];
    if (v316 == nil) goto v154;
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v256 = stack[-1];
    v316 = stack[-3];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = cons(v256, v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    stack[0] = qcdr(v316);
    v256 = stack[-3];
    v316 = stack[-1];
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcdr(v316);
    v316 = qcar(v316);
    v316 = cons(v256, v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v316 = (*qfn2(fn))(qenv(fn), stack[0], v316);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    goto v154;

v154:
    v316 = stack[-5];
    v316 = qcdr(v316);
    stack[-5] = v316;
    goto v100;

v61:
    v316 = nil;
    { popv(7); return onevalue(v316); }
/* error exit handlers */
v179:
    popv(7);
    return nil;
}



/* Code for ratpoly_deg */

static Lisp_Object CC_ratpoly_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v95 = v76;
    stack[0] = v0;
/* end of prologue */
    v155 = stack[0];
    fn = elt(env, 1); /* ratpoly_mvartest */
    v95 = (*qfn2(fn))(qenv(fn), v155, v95);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    if (v95 == nil) goto v103;
    v95 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_ldeg */
        return (*qfn1(fn))(qenv(fn), v95);
    }

v103:
    v95 = stack[0];
    fn = elt(env, 3); /* ratpoly_nullp */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v54;
    if (v95 == nil) goto v62;
    v95 = (Lisp_Object)-15; /* -1 */
    { popv(2); return onevalue(v95); }

v62:
    v95 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v95); }
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for ir2om */

static Lisp_Object CC_ir2om(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ir2om");
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
    v157 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v157; /* ind */
    v157 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v157; /* indent */
    v157 = elt(env, 3); /* "<OMOBJ>" */
    fn = elt(env, 7); /* printout */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    v157 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* indent!* */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    v157 = stack[0];
    fn = elt(env, 9); /* objectom */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    v157 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    v157 = elt(env, 6); /* "</OMOBJ>" */
    fn = elt(env, 7); /* printout */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v135;
    v157 = nil;
    { popv(2); return onevalue(v157); }
/* error exit handlers */
v135:
    popv(2);
    return nil;
}



/* Code for rowdel */

static Lisp_Object CC_rowdel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v84, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rowdel");
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
    fn = elt(env, 4); /* delhisto */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v84 = qvalue(elt(env, 2)); /* maxvar */
    v112 = stack[0];
    v112 = plus2(v84, v112);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v44 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v112/(16/CELL)));
    v84 = (Lisp_Object)1; /* 0 */
    v112 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v44 + (CELL-TAG_VECTOR) + ((int32_t)v84/(16/CELL))) = v112;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v84 = qvalue(elt(env, 2)); /* maxvar */
    v112 = stack[0];
    v112 = plus2(v84, v112);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v84 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v112/(16/CELL)));
    v112 = (Lisp_Object)65; /* 4 */
    v112 = *(Lisp_Object *)((char *)v84 + (CELL-TAG_VECTOR) + ((int32_t)v112/(16/CELL)));
    stack[0] = v112;
    goto v78;

v78:
    v112 = stack[0];
    if (v112 == nil) goto v139;
    v112 = stack[0];
    v112 = qcar(v112);
    v84 = v112;
    v84 = qcar(v84);
    v112 = qcdr(v112);
    v112 = qcar(v112);
    fn = elt(env, 5); /* downwght */
    v112 = (*qfn2(fn))(qenv(fn), v84, v112);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v112 = stack[0];
    v112 = qcdr(v112);
    stack[0] = v112;
    goto v78;

v139:
    v112 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v112); }
/* error exit handlers */
v96:
    popv(3);
    return nil;
}



/* Code for bcquot */

static Lisp_Object CC_bcquot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v73, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcquot");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v76;
    stack[-1] = v0;
/* end of prologue */
    v98 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v98 == nil) goto v103;
    v98 = stack[0];
    v98 = Lmodular_reciprocal(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    v98 = times2(stack[-1], v98);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v98);
    }

v103:
    v98 = qvalue(elt(env, 2)); /* !*vdpinteger */
    if (v98 == nil) goto v84;
    v137 = stack[-1];
    v73 = stack[0];
    v98 = elt(env, 3); /* quotientx */
    fn = elt(env, 7); /* bcint2op */
    v98 = (*qfnn(fn))(qenv(fn), 3, v137, v73, v98);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    if (!(v98 == nil)) { popv(3); return onevalue(v98); }
    v98 = qvalue(elt(env, 4)); /* !*exp */
    if (v98 == nil) goto v90;
    v98 = qvalue(elt(env, 5)); /* !*mcd */
    if (v98 == nil) goto v90;
    v98 = stack[-1];
    v73 = qcar(v98);
    v98 = stack[0];
    v98 = qcar(v98);
    fn = elt(env, 8); /* quotfx1 */
    v98 = (*qfn2(fn))(qenv(fn), v73, v98);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v73 = v98;
    goto v92;

v92:
    v98 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v73, v98);

v90:
    v98 = stack[-1];
    v73 = qcar(v98);
    v98 = stack[0];
    v98 = qcar(v98);
    fn = elt(env, 9); /* quotf */
    v98 = (*qfn2(fn))(qenv(fn), v73, v98);
    nil = C_nil;
    if (exception_pending()) goto v165;
    v73 = v98;
    goto v92;

v84:
    v98 = stack[0];
    fn = elt(env, 10); /* invsq */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-2];
    {
        Lisp_Object v41 = stack[-1];
        popv(3);
        fn = elt(env, 11); /* multsq */
        return (*qfn2(fn))(qenv(fn), v41, v98);
    }
/* error exit handlers */
v165:
    popv(3);
    return nil;
}



/* Code for freeoffl */

static Lisp_Object CC_freeoffl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeoffl");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v76;
    stack[-1] = v0;
/* end of prologue */

v81:
    v80 = stack[0];
    v80 = (v80 == nil ? lisp_true : nil);
    if (!(v80 == nil)) { popv(3); return onevalue(v80); }
    v136 = stack[-1];
    v80 = stack[0];
    v80 = qcar(v80);
    fn = elt(env, 2); /* freeoff */
    v80 = (*qfn2(fn))(qenv(fn), v136, v80);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-2];
    if (v80 == nil) goto v101;
    v136 = stack[-1];
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[-1] = v136;
    stack[0] = v80;
    goto v81;

v101:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v80); }
/* error exit handlers */
v91:
    popv(3);
    return nil;
}



/* Code for xord_deglex */

static Lisp_Object CC_xord_deglex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v138, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_deglex");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v76;
    stack[-1] = v0;
/* end of prologue */
    v87 = stack[-1];
    v88 = qcar(v87);
    v87 = (Lisp_Object)17; /* 1 */
    if (v88 == v87) goto v82;
    v87 = stack[0];
    v88 = qcar(v87);
    v87 = (Lisp_Object)17; /* 1 */
    if (v88 == v87) goto v157;
    v87 = stack[-1];
    fn = elt(env, 3); /* xdegreemon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    v87 = stack[0];
    fn = elt(env, 3); /* xdegreemon */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    v128 = stack[-2];
    v138 = v87;
    v88 = v128;
    v87 = v138;
    if (equal(v88, v87)) goto v114;
    v87 = v128;
    v88 = v138;
        popv(4);
        return Lgreaterp(nil, v87, v88);

v114:
    v88 = stack[-1];
    v87 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v88, v87);
    }

v157:
    v87 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v87); }

v82:
    v87 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v87); }
/* error exit handlers */
v45:
    popv(4);
    return nil;
}



/* Code for oprinla */

static Lisp_Object CC_oprinla(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v90, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oprinla");
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
    v90 = v0;
/* end of prologue */
    v89 = v90;
    v50 = elt(env, 1); /* lapr */
    v50 = get(v89, v50);
    env = stack[0];
    v89 = v50;
    if (v50 == nil) goto v62;
    v50 = v89;
    fn = elt(env, 5); /* prin2la */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v49;
    goto v103;

v103:
    v50 = nil;
    { popv(1); return onevalue(v50); }

v62:
    v89 = v90;
    v50 = elt(env, 2); /* prtch */
    v50 = get(v89, v50);
    env = stack[0];
    v89 = v50;
    if (v50 == nil) goto v136;
    v50 = v89;
    fn = elt(env, 5); /* prin2la */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v49;
    goto v103;

v136:
    v89 = v90;
    v50 = elt(env, 3); /* lapop */
    v50 = get(v89, v50);
    env = stack[0];
    v89 = v50;
    if (v50 == nil) goto v154;
    v50 = v89;
    fn = elt(env, 5); /* prin2la */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[0];
    v50 = elt(env, 4); /* !  */
    fn = elt(env, 5); /* prin2la */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v49;
    goto v103;

v154:
    v50 = v90;
    fn = elt(env, 6); /* prinlatom */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v49;
    goto v103;
/* error exit handlers */
v49:
    popv(1);
    return nil;
}



/* Code for physop2sq */

static Lisp_Object CC_physop2sq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v314, v318, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physop2sq");
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

v81:
    v314 = stack[0];
    fn = elt(env, 5); /* physopp */
    v314 = (*qfn1(fn))(qenv(fn), v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    if (v314 == nil) goto v61;
    v318 = stack[0];
    v314 = elt(env, 1); /* rvalue */
    v314 = get(v318, v314);
    env = stack[-2];
    stack[-1] = v314;
    if (v314 == nil) goto v56;
    v314 = stack[-1];
    stack[0] = v314;
    goto v81;

v56:
    v314 = stack[0];
    if (symbolp(v314)) goto v52;
    v314 = stack[0];
    v318 = qcar(v314);
    v314 = elt(env, 2); /* psimpfn */
    v314 = get(v318, v314);
    env = stack[-2];
    stack[-1] = v314;
    if (v314 == nil) goto v105;
    v318 = stack[-1];
    v314 = stack[0];
    v314 = Lapply1(nil, v318, v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    stack[-1] = v314;
    fn = elt(env, 5); /* physopp */
    v314 = (*qfn1(fn))(qenv(fn), v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    if (v314 == nil) goto v42;
    v202 = stack[-1];
    v318 = (Lisp_Object)17; /* 1 */
    v314 = (Lisp_Object)17; /* 1 */
    v314 = acons(v202, v318, v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    v318 = ncons(v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    v314 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v318, v314);

v42:
    v314 = stack[-1];
    fn = elt(env, 6); /* physopsm!* */
    v314 = (*qfn1(fn))(qenv(fn), v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    v314 = qcdr(v314);
    v314 = qcar(v314);
    { popv(3); return onevalue(v314); }

v105:
    v314 = stack[0];
    v318 = qcar(v314);
    v314 = elt(env, 3); /* opmtch */
    v314 = get(v318, v314);
    env = stack[-2];
    if (v314 == nil) goto v34;
    v314 = stack[0];
    fn = elt(env, 7); /* opmtch!* */
    v314 = (*qfn1(fn))(qenv(fn), v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    stack[-1] = v314;
    if (v314 == nil) goto v34;
    v314 = stack[-1];
    stack[0] = v314;
    goto v81;

v34:
    v202 = stack[0];
    v318 = (Lisp_Object)17; /* 1 */
    v314 = (Lisp_Object)17; /* 1 */
    v314 = acons(v202, v318, v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    v318 = ncons(v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    v314 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v318, v314);

v52:
    v202 = stack[0];
    v318 = (Lisp_Object)17; /* 1 */
    v314 = (Lisp_Object)17; /* 1 */
    v314 = acons(v202, v318, v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    v318 = ncons(v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    v314 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v318, v314);

v61:
    v314 = stack[0];
    if (!consp(v314)) goto v285;
    v314 = stack[0];
    v318 = qcar(v314);
    v314 = elt(env, 4); /* !*sq */
    if (v318 == v314) goto v159;
    v314 = stack[0];
    fn = elt(env, 8); /* getphystype */
    v314 = (*qfn1(fn))(qenv(fn), v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    if (v314 == nil) goto v27;
    v314 = stack[0];
    fn = elt(env, 6); /* physopsm!* */
    v314 = (*qfn1(fn))(qenv(fn), v314);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    stack[0] = v314;
    goto v81;

v27:
    v314 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* simp */
        return (*qfn1(fn))(qenv(fn), v314);
    }

v159:
    v314 = stack[0];
    v314 = qcdr(v314);
    v314 = qcar(v314);
    { popv(3); return onevalue(v314); }

v285:
    v314 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* simp */
        return (*qfn1(fn))(qenv(fn), v314);
    }
/* error exit handlers */
v319:
    popv(3);
    return nil;
}



/* Code for total!-degree!-in!-powers */

static Lisp_Object CC_totalKdegreeKinKpowers(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v315, v167;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for total-degree-in-powers");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v76;
    stack[-1] = v0;
/* end of prologue */

v81:
    v209 = stack[-1];
    if (v209 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v209 = stack[-1];
    if (!consp(v209)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v209 = stack[-1];
    v209 = qcar(v209);
    if (!consp(v209)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v209 = stack[-1];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v315 = qcar(v209);
    v209 = stack[0];
    v209 = Latsoc(nil, v315, v209);
    stack[-2] = v209;
    if (v209 == nil) goto v127;
    v209 = stack[-1];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v315 = qcdr(v209);
    v209 = stack[-2];
    v209 = qcdr(v209);
    v209 = (Lisp_Object)greaterp2(v315, v209);
    nil = C_nil;
    if (exception_pending()) goto v108;
    v209 = v209 ? lisp_true : nil;
    env = stack[-3];
    if (v209 == nil) goto v164;
    v315 = stack[-2];
    v209 = stack[-1];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v209 = qcdr(v209);
    v209 = Lrplacd(nil, v315, v209);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    goto v164;

v164:
    v209 = stack[-1];
    stack[-2] = qcdr(v209);
    v209 = stack[-1];
    v209 = qcar(v209);
    v315 = qcdr(v209);
    v209 = stack[0];
    v209 = CC_totalKdegreeKinKpowers(env, v315, v209);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v209;
    goto v81;

v127:
    v209 = stack[-1];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v167 = qcar(v209);
    v209 = stack[-1];
    v209 = qcar(v209);
    v209 = qcar(v209);
    v315 = qcdr(v209);
    v209 = stack[0];
    v209 = acons(v167, v315, v209);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-3];
    stack[0] = v209;
    goto v164;
/* error exit handlers */
v108:
    popv(4);
    return nil;
}



/* Code for assert_uninstall_all */

static Lisp_Object MS_CDECL CC_assert_uninstall_all(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall_all");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v61 = qvalue(elt(env, 1)); /* !*assert */
    if (v61 == nil) goto v86;
    v61 = qvalue(elt(env, 2)); /* assert_functionl!* */
    {
        fn = elt(env, 3); /* assert_uninstall */
        return (*qfn1(fn))(qenv(fn), v61);
    }

v86:
    v61 = nil;
    return onevalue(v61);
}



/* Code for dssoc */

static Lisp_Object CC_dssoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v71, v78, v79;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dssoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v78 = v76;
    v79 = v0;
/* end of prologue */

v82:
    v145 = v78;
    if (v145 == nil) goto v61;
    v71 = v79;
    v145 = v78;
    v145 = qcar(v145);
    v145 = qcdr(v145);
    if (equal(v71, v145)) goto v168;
    v145 = v78;
    v145 = qcdr(v145);
    v78 = v145;
    goto v82;

v168:
    v145 = v78;
    v145 = qcar(v145);
    return onevalue(v145);

v61:
    v145 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v145);
}



/* Code for xremainder!-mod!-p */

static Lisp_Object MS_CDECL CC_xremainderKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v76,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v320, v321;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremainder-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xremainder-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v76,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v83;
    stack[-2] = v76;
    stack[-3] = v0;
/* end of prologue */

v81:
    v233 = stack[-3];
    if (!consp(v233)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v233 = stack[-3];
    v233 = qcar(v233);
    if (!consp(v233)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v233 = stack[-3];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v320 = qcar(v233);
    v233 = stack[-1];
    if (!(equal(v320, v233))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v233 = stack[-3];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v320 = qcdr(v233);
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcdr(v233);
    if (((int32_t)(v320)) < ((int32_t)(v233))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v233 = stack[-3];
    v233 = qcar(v233);
    v233 = qcdr(v233);
    fn = elt(env, 1); /* minus!-mod!-p */
    v320 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcdr(v233);
    fn = elt(env, 2); /* quotient!-mod!-p */
    v233 = (*qfn2(fn))(qenv(fn), v320, v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    stack[-4] = v233;
    v233 = stack[-3];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v320 = qcdr(v233);
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcdr(v233);
    v233 = (Lisp_Object)(int32_t)((int32_t)v320 - (int32_t)v233 + TAG_FIXNUM);
    stack[0] = v233;
    v320 = stack[0];
    v233 = (Lisp_Object)1; /* 0 */
    if (v320 == v233) goto v137;
    v233 = stack[-3];
    stack[-3] = qcdr(v233);
    v233 = stack[-2];
    v233 = qcar(v233);
    v233 = qcar(v233);
    v233 = qcar(v233);
    fn = elt(env, 3); /* fkern */
    v320 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    v233 = stack[0];
    fn = elt(env, 4); /* getpower */
    v320 = (*qfn2(fn))(qenv(fn), v320, v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    v233 = stack[-4];
    v320 = cons(v320, v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    v233 = stack[-2];
    v233 = qcdr(v233);
    fn = elt(env, 5); /* times!-term!-mod!-p */
    v233 = (*qfn2(fn))(qenv(fn), v320, v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    fn = elt(env, 6); /* plus!-mod!-p */
    v233 = (*qfn2(fn))(qenv(fn), stack[-3], v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    stack[-3] = v233;
    goto v159;

v159:
    v321 = stack[-3];
    v320 = stack[-2];
    v233 = stack[-1];
    stack[-3] = v321;
    stack[-2] = v320;
    stack[-1] = v233;
    goto v81;

v137:
    v233 = stack[-3];
    stack[0] = qcdr(v233);
    v233 = stack[-2];
    v320 = qcdr(v233);
    v233 = stack[-4];
    fn = elt(env, 7); /* multiply!-by!-constant!-mod!-p */
    v233 = (*qfn2(fn))(qenv(fn), v320, v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    fn = elt(env, 6); /* plus!-mod!-p */
    v233 = (*qfn2(fn))(qenv(fn), stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-5];
    stack[-3] = v233;
    goto v159;
/* error exit handlers */
v206:
    popv(6);
    return nil;
}



/* Code for gitimes!: */

static Lisp_Object CC_gitimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v280, v143, v166, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gitimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v76);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v280 = v76;
    v143 = v0;
/* end of prologue */
    v166 = v143;
    v166 = qcdr(v166);
    v111 = qcar(v166);
    v143 = qcdr(v143);
    v166 = qcdr(v143);
    v143 = v280;
    v143 = qcdr(v143);
    v143 = qcar(v143);
    v280 = qcdr(v280);
    v280 = qcdr(v280);
    stack[-5] = v111;
    stack[-4] = v166;
    stack[-3] = v143;
    stack[-2] = v280;
    stack[-1] = elt(env, 1); /* !:gi!: */
    v143 = stack[-5];
    v280 = stack[-3];
    stack[0] = times2(v143, v280);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-6];
    v143 = stack[-4];
    v280 = stack[-2];
    v280 = times2(v143, v280);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-6];
    stack[0] = difference2(stack[0], v280);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-6];
    v143 = stack[-5];
    v280 = stack[-2];
    stack[-2] = times2(v143, v280);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-6];
    v143 = stack[-3];
    v280 = stack[-4];
    v280 = times2(v143, v280);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-6];
    v280 = plus2(stack[-2], v280);
    nil = C_nil;
    if (exception_pending()) goto v97;
    {
        Lisp_Object v98 = stack[-1];
        Lisp_Object v73 = stack[0];
        popv(7);
        return list2star(v98, v73, v280);
    }
/* error exit handlers */
v97:
    popv(7);
    return nil;
}



/* Code for mkpartitions1 */

static Lisp_Object MS_CDECL CC_mkpartitions1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v76,
                         Lisp_Object v83, Lisp_Object v122,
                         Lisp_Object v86, Lisp_Object v82, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v146, v286, v317;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "mkpartitions1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkpartitions1");
#endif
    if (stack >= stacklimit)
    {
        push6(v82,v86,v122,v83,v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v76,v83,v122,v86,v82);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v82;
    stack[-4] = v86;
    stack[-5] = v122;
    stack[-6] = v83;
    stack[-7] = v76;
    stack[-8] = v0;
/* end of prologue */

v135:
    v146 = stack[-7];
    v147 = (Lisp_Object)17; /* 1 */
    if (v146 == v147) goto v71;
    v146 = stack[-6];
    v147 = stack[-5];
    v147 = (Lisp_Object)greaterp2(v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v147 = v147 ? lisp_true : nil;
    env = stack[-10];
    if (!(v147 == nil)) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v146 = stack[-8];
    v147 = stack[-6];
    v147 = difference2(v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    stack[-9] = v147;
    v147 = stack[-7];
    v147 = sub1(v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    stack[-2] = v147;
    v146 = stack[-8];
    v147 = stack[-6];
    stack[0] = difference2(v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    v147 = stack[-7];
    v147 = sub1(v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    v147 = quot2(stack[0], v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    stack[-1] = v147;
    v146 = stack[-6];
    v147 = stack[-4];
    v147 = cons(v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    stack[0] = v147;
    v147 = stack[-6];
    v317 = add1(v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    v286 = stack[-5];
    v146 = stack[-4];
    v147 = stack[-3];
    v147 = CC_mkpartitions1(env, 6, stack[-8], stack[-7], v317, v286, v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    stack[-3] = v147;
    v147 = stack[0];
    stack[-4] = v147;
    v147 = stack[-1];
    stack[-5] = v147;
    v147 = stack[-2];
    stack[-7] = v147;
    v147 = stack[-9];
    stack[-8] = v147;
    goto v135;

v71:
    v146 = stack[-8];
    v147 = stack[-6];
    v147 = (Lisp_Object)geq2(v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v147 = v147 ? lisp_true : nil;
    env = stack[-10];
    if (v147 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v146 = stack[-8];
    v147 = stack[-4];
    v147 = cons(v146, v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-10];
    v146 = Lreverse(nil, v147);
    nil = C_nil;
    if (exception_pending()) goto v32;
    v147 = stack[-3];
    popv(11);
    return cons(v146, v147);
/* error exit handlers */
v32:
    popv(11);
    return nil;
}



/* Code for ofsf_clnegrel */

static Lisp_Object CC_ofsf_clnegrel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v76)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_clnegrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v76;
    v56 = v0;
/* end of prologue */
    if (!(v57 == nil)) return onevalue(v56);
    v57 = v56;
    {
        fn = elt(env, 1); /* ofsf_lnegrel */
        return (*qfn1(fn))(qenv(fn), v57);
    }
}



/* Code for texstrlen */

static Lisp_Object CC_texstrlen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v114, v115;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texstrlen");
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
    v163 = v0;
/* end of prologue */
    v114 = (Lisp_Object)1; /* 0 */
    v115 = v114;
    v114 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v163;
    goto v168;

v168:
    v163 = stack[0];
    if (v163 == nil) { popv(2); return onevalue(v115); }
    v163 = stack[0];
    v163 = qcar(v163);
    if (!(v114 == nil)) goto v92;
    v114 = v163;
    v163 = elt(env, 2); /* !! */
    if (!(v114 == v163)) goto v92;
    v163 = qvalue(elt(env, 3)); /* t */
    v114 = v163;
    goto v94;

v94:
    v163 = stack[0];
    v163 = qcdr(v163);
    stack[0] = v163;
    goto v168;

v92:
    v163 = v115;
    v163 = add1(v163);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-1];
    v115 = v163;
    v163 = qvalue(elt(env, 1)); /* nil */
    v114 = v163;
    goto v94;
/* error exit handlers */
v90:
    popv(2);
    return nil;
}



/* Code for mkprod */

static Lisp_Object CC_mkprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprod");
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
    stack[-2] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v9 = stack[-4];
    if (v9 == nil) goto v168;
    v9 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    if (!(v9 == nil)) goto v168;
    v9 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v9; /* !*sub2 */
    v7 = stack[-4];
    v9 = (Lisp_Object)17; /* 1 */
    v9 = cons(v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    fn = elt(env, 11); /* subs2 */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[0] = v9;
    v9 = stack[0];
    v7 = qcdr(v9);
    v9 = (Lisp_Object)17; /* 1 */
    if (v7 == v9) goto v154;
    v9 = stack[-4];
    goto v100;

v100:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    { popv(7); return onevalue(v9); }

v154:
    v9 = stack[0];
    v7 = qcar(v9);
    v9 = stack[-4];
    if (equal(v7, v9)) goto v78;
    v9 = stack[0];
    v9 = qcar(v9);
    stack[-4] = v9;
    v9 = stack[-4];
    if (v9 == nil) goto v99;
    v9 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    if (!(v9 == nil)) goto v99;

v78:
    v9 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v9; /* !*exp */
    v9 = stack[-4];
    fn = elt(env, 12); /* ckrn */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[-5] = v9;
    v7 = stack[-4];
    v9 = stack[-5];
    fn = elt(env, 13); /* quotf */
    v9 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[-4] = v9;
    v9 = stack[-4];
    fn = elt(env, 14); /* expnd */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[0] = v9;
    v9 = stack[0];
    if (v9 == nil) goto v165;
    v9 = stack[0];
    fn = elt(env, 10); /* kernlp */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    if (!(v9 == nil)) goto v165;
    v9 = qvalue(elt(env, 4)); /* !*mcd */
    if (v9 == nil) goto v116;
    v9 = qvalue(elt(env, 5)); /* !*sqfree */
    if (!(v9 == nil)) goto v40;
    v9 = qvalue(elt(env, 6)); /* !*factor */
    if (!(v9 == nil)) goto v40;
    v9 = qvalue(elt(env, 7)); /* !*gcd */
    if (!(v9 == nil)) goto v40;

v116:
    v9 = stack[0];
    fn = elt(env, 12); /* ckrn */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[-3] = v9;
    v7 = stack[0];
    v9 = stack[-3];
    fn = elt(env, 13); /* quotf */
    v9 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[0] = v9;
    v7 = stack[0];
    v9 = (Lisp_Object)17; /* 1 */
    v9 = cons(v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    v9 = list2(stack[-3], v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[-3] = v9;
    goto v30;

v30:
    v9 = stack[-3];
    v9 = qcdr(v9);
    v9 = qcar(v9);
    v7 = qcdr(v9);
    v9 = (Lisp_Object)17; /* 1 */
    v9 = (Lisp_Object)greaterp2(v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    v9 = v9 ? lisp_true : nil;
    env = stack[-6];
    if (!(v9 == nil)) goto v159;
    v9 = stack[-3];
    v9 = qcdr(v9);
    v9 = qcdr(v9);
    if (!(v9 == nil)) goto v159;
    v9 = qvalue(elt(env, 9)); /* !*group */
    if (!(v9 == nil)) goto v329;
    v9 = stack[-4];
    fn = elt(env, 15); /* tmsf */
    stack[0] = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    v9 = stack[-3];
    v9 = qcdr(v9);
    v9 = qcar(v9);
    v9 = qcar(v9);
    fn = elt(env, 15); /* tmsf */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    v9 = (Lisp_Object)greaterp2(stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    v9 = v9 ? lisp_true : nil;
    env = stack[-6];
    if (v9 == nil) goto v329;
    v9 = stack[-3];
    v9 = qcdr(v9);
    v9 = qcar(v9);
    v7 = qcar(v9);
    v9 = stack[-3];
    v9 = qcdr(v9);
    v9 = qcar(v9);
    v9 = qcdr(v9);
    fn = elt(env, 16); /* mksp!* */
    v7 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    v9 = stack[-3];
    v9 = qcar(v9);
    fn = elt(env, 17); /* multf */
    v9 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[0] = v9;
    goto v195;

v195:
    v7 = stack[-5];
    v9 = stack[0];
    fn = elt(env, 17); /* multf */
    v9 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    goto v100;

v329:
    v7 = stack[-4];
    v9 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksp!* */
    v9 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[0] = v9;
    goto v195;

v159:
    v9 = stack[-3];
    v9 = qcar(v9);
    stack[0] = v9;
    v9 = stack[-3];
    v9 = qcdr(v9);
    stack[-3] = v9;
    goto v313;

v313:
    v9 = stack[-3];
    if (v9 == nil) goto v195;
    v9 = stack[-3];
    v9 = qcar(v9);
    v7 = v9;
    v7 = qcar(v7);
    v9 = qcdr(v9);
    fn = elt(env, 16); /* mksp!* */
    v7 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    v9 = stack[0];
    fn = elt(env, 17); /* multf */
    v9 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[0] = v9;
    v9 = stack[-3];
    v9 = qcdr(v9);
    stack[-3] = v9;
    goto v313;

v40:
    v9 = stack[0];
    fn = elt(env, 18); /* fctrf */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    stack[-3] = v9;
    goto v30;

v165:
    v7 = stack[-5];
    v9 = stack[0];
    fn = elt(env, 17); /* multf */
    v9 = (*qfn2(fn))(qenv(fn), v7, v9);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-6];
    goto v100;

v99:
    v9 = stack[-4];
    goto v100;

v168:
    v9 = stack[-4];
    goto v100;
/* error exit handlers */
v193:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    popv(7);
    return nil;
}



/* Code for lastnondomain */

static Lisp_Object CC_lastnondomain(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lastnondomain");
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

v86:
    v87 = stack[0];
    if (!consp(v87)) goto v104;
    v87 = stack[0];
    v87 = qcar(v87);
    if (!consp(v87)) goto v104;
    v87 = stack[0];
    v87 = qcdr(v87);
    if (!consp(v87)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v87 = stack[0];
    v87 = qcdr(v87);
    v87 = qcar(v87);
    if (!consp(v87)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v87 = stack[0];
    v87 = qcdr(v87);
    stack[0] = v87;
    goto v86;

v104:
    v87 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 9); /* terpri!* */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    v87 = elt(env, 2); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 10); /* lprie */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    v88 = elt(env, 3); /* "non-domain" */
    v87 = stack[0];
    v87 = list2(v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    fn = elt(env, 11); /* printty */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    v88 = elt(env, 4); /* " " */
    v87 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 12); /* lpriw */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    v87 = elt(env, 6); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v88 = v87;
    v87 = v88;
    qvalue(elt(env, 7)) = v87; /* errmsg!* */
    v87 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v87 == nil)) goto v300;
    v87 = v88;
    fn = elt(env, 10); /* lprie */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-1];
    goto v300;

v300:
    v87 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v87 = nil;
    { popv(2); return onevalue(v87); }
/* error exit handlers */
v128:
    popv(2);
    return nil;
}



/* Code for aex_subrat1 */

static Lisp_Object MS_CDECL CC_aex_subrat1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v76,
                         Lisp_Object v83, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_subrat1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_subrat1");
#endif
    if (stack >= stacklimit)
    {
        push3(v83,v76,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v76,v83);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v83;
    stack[-1] = v76;
    stack[-2] = v0;
/* end of prologue */
    v71 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v79 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v78 = stack[-1];
    v71 = stack[0];
    fn = elt(env, 3); /* ratpoly_subrat1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v79, v78, v71);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v71 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v79 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-3];
    v78 = qvalue(elt(env, 1)); /* nil */
    v71 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v91 = stack[0];
        popv(4);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v91, v79, v78, v71);
    }
/* error exit handlers */
v52:
    popv(4);
    return nil;
}



/* Code for tobvarir */

static Lisp_Object CC_tobvarir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v78;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tobvarir");
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
    v71 = stack[-1];
    if (v71 == nil) goto v82;
    stack[-2] = elt(env, 1); /* bvar */
    v71 = stack[-1];
    v78 = qcar(v71);
    v71 = (Lisp_Object)17; /* 1 */
    stack[0] = list2(v78, v71);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-3];
    v71 = stack[-1];
    v71 = qcdr(v71);
    v71 = CC_tobvarir(env, v71);
    nil = C_nil;
    if (exception_pending()) goto v53;
    {
        Lisp_Object v52 = stack[-2];
        Lisp_Object v91 = stack[0];
        popv(4);
        return acons(v52, v91, v71);
    }

v82:
    v71 = nil;
    { popv(4); return onevalue(v71); }
/* error exit handlers */
v53:
    popv(4);
    return nil;
}



setup_type const u17_setup[] =
{
    {"simpatom",                CC_simpatom,    too_many_1,    wrong_no_1},
    {"nonlnrsys",               too_few_2,      CC_nonlnrsys,  wrong_no_2},
    {"cl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_simpl},
    {"simpg3",                  CC_simpg3,      too_many_1,    wrong_no_1},
    {"remove-free-vars*",       CC_removeKfreeKvarsH,too_many_1,wrong_no_1},
    {"evaluatecoeffts",         too_few_2,      CC_evaluatecoeffts,wrong_no_2},
    {"expnd1",                  CC_expnd1,      too_many_1,    wrong_no_1},
    {"ibalp_lenisone",          CC_ibalp_lenisone,too_many_1,  wrong_no_1},
    {"numpoly_ldeg",            CC_numpoly_ldeg,too_many_1,    wrong_no_1},
    {"om2mml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2mml},
    {"revalx",                  CC_revalx,      too_many_1,    wrong_no_1},
    {"dipcondense",             CC_dipcondense, too_many_1,    wrong_no_1},
    {"*wedgepf2pf",             CC_Hwedgepf2pf, too_many_1,    wrong_no_1},
    {"mktails1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails1},
    {"formsetq",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"mo_from_a",               CC_mo_from_a,   too_many_1,    wrong_no_1},
    {"exptpri",                 too_few_2,      CC_exptpri,    wrong_no_2},
    {"reduce_pv0",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduce_pv0},
    {"simpiden",                CC_simpiden,    too_many_1,    wrong_no_1},
    {"rl_csimpl",               CC_rl_csimpl,   too_many_1,    wrong_no_1},
    {"wureducedpolysp",         too_few_2,      CC_wureducedpolysp,wrong_no_2},
    {"tmsf",                    CC_tmsf,        too_many_1,    wrong_no_1},
    {"ibalp_unvar-unsatlist",   too_few_2,      CC_ibalp_unvarKunsatlist,wrong_no_2},
    {"ratpoly_deg",             too_few_2,      CC_ratpoly_deg,wrong_no_2},
    {"ir2om",                   CC_ir2om,       too_many_1,    wrong_no_1},
    {"rowdel",                  CC_rowdel,      too_many_1,    wrong_no_1},
    {"bcquot",                  too_few_2,      CC_bcquot,     wrong_no_2},
    {"freeoffl",                too_few_2,      CC_freeoffl,   wrong_no_2},
    {"xord_deglex",             too_few_2,      CC_xord_deglex,wrong_no_2},
    {"oprinla",                 CC_oprinla,     too_many_1,    wrong_no_1},
    {"physop2sq",               CC_physop2sq,   too_many_1,    wrong_no_1},
    {"total-degree-in-powers",  too_few_2,      CC_totalKdegreeKinKpowers,wrong_no_2},
    {"assert_uninstall_all",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_uninstall_all},
    {"dssoc",                   too_few_2,      CC_dssoc,      wrong_no_2},
    {"xremainder-mod-p",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremainderKmodKp},
    {"gitimes:",                too_few_2,      CC_gitimesT,   wrong_no_2},
    {"mkpartitions1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkpartitions1},
    {"ofsf_clnegrel",           too_few_2,      CC_ofsf_clnegrel,wrong_no_2},
    {"texstrlen",               CC_texstrlen,   too_many_1,    wrong_no_1},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"lastnondomain",           CC_lastnondomain,too_many_1,   wrong_no_1},
    {"aex_subrat1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrat1},
    {"tobvarir",                CC_tobvarir,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u17", (two_args *)"15806 5494228 6430508", 0}
};

/* end of generated code */
