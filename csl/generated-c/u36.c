
/* $destdir\u36.c        Machine generated C code */

/* Signature: 00000000 26-Sep-2010 */

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


/* Code for multup */

static Lisp_Object CC_multup(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multup");
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
    v6 = v0;
/* end of prologue */
    v7 = (Lisp_Object)17; /* 1 */
    stack[0] = v6;
    goto v8;

v8:
    v6 = stack[0];
    if (v6 == nil) { popv(2); return onevalue(v7); }
    v6 = stack[0];
    v6 = qcar(v6);
    fn = elt(env, 2); /* multf */
    v6 = (*qfn2(fn))(qenv(fn), v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    v7 = v6;
    v6 = stack[0];
    v6 = qcdr(v6);
    stack[0] = v6;
    goto v8;
/* error exit handlers */
v9:
    popv(2);
    return nil;
}



/* Code for i2cr!* */

static Lisp_Object CC_i2crH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16, v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2cr*");
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
    v15 = v0;
/* end of prologue */
    fn = elt(env, 4); /* chkint!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[0];
    v16 = v15;
    if (!consp(v16)) goto v5;
    v16 = qvalue(elt(env, 2)); /* bfz!* */
    goto v20;

v20:
    v17 = elt(env, 3); /* !:cr!: */
    v18 = v15;
    if (!consp(v18)) goto v21;
    v15 = qcdr(v15);
    v18 = v15;
    goto v3;

v3:
    v15 = v16;
    if (!consp(v15)) goto v22;
    v15 = v16;
    v15 = qcdr(v15);
    goto v23;

v23:
    popv(1);
    return list2star(v17, v18, v15);

v22:
    v15 = v16;
    goto v23;

v21:
    v18 = v15;
    goto v3;

v5:
    v16 = elt(env, 1); /* 0.0 */
    goto v20;
/* error exit handlers */
v19:
    popv(1);
    return nil;
}



/* Code for ldf!-simp */

static Lisp_Object CC_ldfKsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-simp");
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
    v33 = v0;
/* end of prologue */
    v32 = v33;
    if (v32 == nil) goto v14;
    v32 = v33;
    v32 = qcdr(v32);
    if (v32 == nil) goto v35;
    v32 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1 */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v33 = v32;
    v32 = v33;
    if (v32 == nil) goto v37;
    v32 = v33;
    fn = elt(env, 3); /* replus */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    goto v38;

v38:
    fn = elt(env, 4); /* simp */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v32 = qcar(v32);
    stack[-1] = v32;
    v32 = stack[-1];
    if (!consp(v32)) goto v39;
    v32 = stack[-1];
    v32 = qcar(v32);
    if (!consp(v32)) goto v39;
    stack[0] = stack[-1];
    v32 = stack[-1];
    fn = elt(env, 5); /* comfac */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v32 = qcdr(v32);
    fn = elt(env, 6); /* quotf */
    v32 = (*qfn2(fn))(qenv(fn), stack[0], v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    stack[-1] = v32;
    goto v39;

v39:
    v32 = stack[-1];
    fn = elt(env, 7); /* minusf */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    if (v32 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v32 = stack[-1];
    {
        popv(3);
        fn = elt(env, 8); /* negf */
        return (*qfn1(fn))(qenv(fn), v32);
    }

v37:
    v32 = (Lisp_Object)1; /* 0 */
    goto v38;

v35:
    v32 = v33;
    v32 = qcar(v32);
    v32 = qcar(v32);
    v34 = qcar(v32);
    v33 = (Lisp_Object)17; /* 1 */
    v32 = (Lisp_Object)17; /* 1 */
    v32 = acons(v34, v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v33 = ncons(v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v32 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1 */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    v33 = v32;
    v32 = v33;
    if (v32 == nil) goto v40;
    v32 = v33;
    fn = elt(env, 3); /* replus */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-2];
    goto v41;

v41:
    fn = elt(env, 4); /* simp */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v36;
    v32 = qcar(v32);
    { popv(3); return onevalue(v32); }

v40:
    v32 = (Lisp_Object)1; /* 0 */
    goto v41;

v14:
    v32 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v32); }
/* error exit handlers */
v36:
    popv(3);
    return nil;
}



/* Code for noncomexpf */

static Lisp_Object CC_noncomexpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomexpf");
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

v43:
    v40 = stack[0];
    if (!consp(v40)) goto v14;
    v40 = stack[0];
    v40 = qcar(v40);
    if (!consp(v40)) goto v14;
    v40 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v40 == nil) goto v3;
    v40 = stack[0];
    v40 = qcar(v40);
    v40 = qcar(v40);
    v40 = qcar(v40);
    fn = elt(env, 3); /* noncomp1 */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    goto v45;

v45:
    if (!(v40 == nil)) { popv(2); return onevalue(v40); }
    v40 = stack[0];
    v40 = qcar(v40);
    v40 = qcdr(v40);
    v40 = CC_noncomexpf(env, v40);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    if (!(v40 == nil)) { popv(2); return onevalue(v40); }
    v40 = stack[0];
    v40 = qcdr(v40);
    stack[0] = v40;
    goto v43;

v3:
    v40 = qvalue(elt(env, 1)); /* nil */
    goto v45;

v14:
    v40 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v40); }
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for find_triangl_coeff */

static Lisp_Object MS_CDECL CC_find_triangl_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v3, v23, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "find_triangl_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_triangl_coeff");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v4;
    v3 = v46;
    v23 = v0;
/* end of prologue */
    v35 = v23;
    v23 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* find_triangle_coeff */
        return (*qfnn(fn))(qenv(fn), 4, v35, v23, v3, v45);
    }
}



/* Code for greaterpcdr */

static Lisp_Object CC_greaterpcdr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v47;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greaterpcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v13 = v46;
    v47 = v0;
/* end of prologue */
    v47 = qcdr(v47);
    v13 = qcdr(v13);
        return Lgreaterp(nil, v47, v13);
}



/* Code for mv!-compact */

static Lisp_Object MS_CDECL CC_mvKcompact(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv-compact");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-compact");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v46;
    stack[-3] = v0;
/* end of prologue */

v43:
    v74 = stack[-3];
    if (v74 == nil) goto v50;
    v75 = stack[-3];
    v74 = stack[-2];
    fn = elt(env, 1); /* mv!-pow!-chk */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-4] = v74;
    if (v74 == nil) goto v29;
    stack[0] = stack[-3];
    v75 = stack[-4];
    v74 = stack[-2];
    fn = elt(env, 2); /* mv!-pow!-mv!-!+ */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    fn = elt(env, 3); /* mv!-compact2 */
    v74 = (*qfn2(fn))(qenv(fn), stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[0] = v74;
    if (v74 == nil) goto v29;
    v76 = stack[0];
    v75 = stack[-2];
    v74 = stack[-1];
    stack[-3] = v76;
    stack[-2] = v75;
    stack[-1] = v74;
    goto v43;

v29:
    v75 = stack[-3];
    v74 = stack[-2];
    v74 = qcdr(v74);
    fn = elt(env, 1); /* mv!-pow!-chk */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-4] = v74;
    if (v74 == nil) goto v78;
    v75 = stack[-4];
    v74 = stack[-2];
    v74 = qcar(v74);
    v74 = qcar(v74);
    fn = elt(env, 4); /* mv!-pow!-!+ */
    v75 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[0] = v75;
    v74 = stack[-1];
    fn = elt(env, 5); /* mv!-pow!-assoc */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    if (!(v74 == nil)) goto v78;
    v76 = stack[0];
    v75 = (Lisp_Object)1; /* 0 */
    v74 = stack[-3];
    stack[0] = acons(v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    v75 = stack[-4];
    v74 = stack[-2];
    fn = elt(env, 2); /* mv!-pow!-mv!-!+ */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    fn = elt(env, 3); /* mv!-compact2 */
    v74 = (*qfn2(fn))(qenv(fn), stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[0] = v74;
    if (v74 == nil) goto v78;
    v76 = stack[0];
    v75 = stack[-2];
    v74 = stack[-1];
    stack[-3] = v76;
    stack[-2] = v75;
    stack[-1] = v74;
    goto v43;

v78:
    v74 = stack[-3];
    stack[0] = qcdr(v74);
    v74 = stack[-3];
    v75 = qcar(v74);
    v74 = stack[-1];
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-5];
    stack[-3] = stack[0];
    stack[-1] = v74;
    goto v43;

v50:
    v74 = stack[-1];
    {
        popv(6);
        fn = elt(env, 6); /* mv!-reverse */
        return (*qfn1(fn))(qenv(fn), v74);
    }
/* error exit handlers */
v77:
    popv(6);
    return nil;
}



/* Code for fs!:prepfn!: */

static Lisp_Object CC_fsTprepfnT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v79;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prepfn:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v79 = v0;
/* end of prologue */
    return onevalue(v79);
}



/* Code for checkdifference */

static Lisp_Object CC_checkdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v81, v82, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkdifference");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v46;
    v6 = v0;
/* end of prologue */
    v81 = v82;
    v80 = (Lisp_Object)1; /* 0 */
    if (v81 == v80) return onevalue(v6);
    v80 = elt(env, 1); /* difference */
    v81 = v6;
    return list3(v80, v81, v82);
}



/* Code for ratpoly_tad */

static Lisp_Object CC_ratpoly_tad(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v49;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_tad");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v83 = v0;
/* end of prologue */
    v49 = qcar(v83);
    v83 = (Lisp_Object)17; /* 1 */
    return cons(v49, v83);
}



/* Code for fnom */

static Lisp_Object CC_fnom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnom");
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
    v15 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 13); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 14); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 3); /* "<OMATTR>" */
    fn = elt(env, 13); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 14); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 4); /* "<OMATP>" */
    fn = elt(env, 13); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 14); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 5); /* "<OMS cd=""typmml"" name=""type""/>" */
    fn = elt(env, 13); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 6); /* "<OMS cd=""typmml"" name=""" */
    fn = elt(env, 13); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 7); /* "fn_type" */
    v15 = Lprinc(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 8); /* """/>" */
    v15 = Lprinc(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 10); /* "</OMATP>" */
    fn = elt(env, 13); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = stack[0];
    v15 = qcar(v15);
    fn = elt(env, 15); /* objectom */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 11); /* "</OMATTR>" */
    fn = elt(env, 13); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = stack[0];
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    fn = elt(env, 16); /* multiom */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* indent!* */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    v15 = elt(env, 12); /* "</OMA>" */
    fn = elt(env, 13); /* printout */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v17;
    v15 = nil;
    { popv(2); return onevalue(v15); }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for d2int */

static Lisp_Object CC_d2int(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v87, v88;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for d2int");
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
    v87 = v0;
/* end of prologue */
    v86 = v87;
    v88 = qcdr(v86);
    v86 = (Lisp_Object)17; /* 1 */
    if (v88 == v86) goto v59;
    v86 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v86); }

v59:
    v86 = v87;
    v86 = qcar(v86);
    v87 = v86;
    if (is_number(v86)) { popv(3); return onevalue(v87); }
    v86 = v87;
    if (!consp(v86)) goto v81;
    v86 = v87;
    v86 = qcar(v86);
    if (!(!consp(v86))) goto v23;

v81:
    v86 = v87;
    v88 = qcar(v86);
    v86 = elt(env, 2); /* !:rd!: */
    if (!(v88 == v86)) goto v23;
    v86 = v87;
    v86 = qcdr(v86);
    stack[-1] = v86;
    v86 = stack[-1];
    v86 = Ltruncate(nil, v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    stack[0] = v86;
    v86 = stack[0];
    v87 = Lfloat(nil, v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v86 = stack[-1];
    v86 = difference2(v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v87 = Labsval(nil, v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-2];
    v86 = qvalue(elt(env, 3)); /* !!fleps1 */
    v86 = (Lisp_Object)lessp2(v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v86 = v86 ? lisp_true : nil;
    env = stack[-2];
    if (!(v86 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v86 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v86); }

v23:
    v86 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v86); }
/* error exit handlers */
v89:
    popv(3);
    return nil;
}



/* Code for bfsqrt */

static Lisp_Object CC_bfsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfsqrt");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0;
/* end of prologue */
    v173 = stack[-7];
    v172 = elt(env, 1); /* !:rd!: */
    if (!consp(v173)) goto v27;
    v173 = qcar(v173);
    if (!(v173 == v172)) goto v27;
    v172 = stack[-7];
    v172 = qcdr(v172);
    if (!consp(v172)) goto v27;
    v172 = stack[-7];
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)lessp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v172 = v172 ? lisp_true : nil;
    env = stack[-9];
    if (v172 == nil) goto v27;
    stack[0] = (Lisp_Object)1; /* 0 */
    v174 = stack[-7];
    v173 = elt(env, 2); /* " invalid for " */
    v172 = elt(env, 0); /* bfsqrt */
    v172 = list3(v174, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    {
        Lisp_Object v176 = stack[0];
        popv(10);
        fn = elt(env, 6); /* error */
        return (*qfn2(fn))(qenv(fn), v176, v172);
    }

v27:
    v172 = stack[-7];
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = (Lisp_Object)1; /* 0 */
    if (v173 == v172) goto v30;
    v173 = qvalue(elt(env, 4)); /* !:bprec!: */
    v172 = (Lisp_Object)113; /* 7 */
    v172 = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    stack[-5] = v172;
    stack[-3] = elt(env, 1); /* !:rd!: */
    stack[-2] = (Lisp_Object)17; /* 1 */
    v172 = stack[-5];
    stack[-1] = negate(v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = stack[-7];
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = (Lisp_Object)1; /* 0 */
    if (v173 == v172) goto v177;
    v172 = stack[-7];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = Labsval(nil, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    fn = elt(env, 7); /* msd */
    stack[0] = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = stack[-7];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = sub1(v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = plus2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v173 = v172;
    goto v178;

v178:
    v172 = (Lisp_Object)161; /* 10 */
    v173 = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = (Lisp_Object)33; /* 2 */
    v172 = quot2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = plus2(stack[-1], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = list2star(stack[-3], stack[-2], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    stack[-6] = v172;
    v173 = stack[-7];
    v172 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 8); /* conv!:mt */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    stack[-8] = v172;
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = Levenp(nil, v172);
    env = stack[-9];
    if (v172 == nil) goto v179;
    stack[-1] = elt(env, 1); /* !:rd!: */
    stack[0] = (Lisp_Object)33; /* 2 */
    v173 = (Lisp_Object)49; /* 3 */
    v172 = stack[-8];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = times2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v173 = plus2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = (Lisp_Object)81; /* 5 */
    stack[0] = quot2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = stack[-8];
    v172 = qcdr(v172);
    v173 = qcdr(v172);
    v172 = (Lisp_Object)33; /* 2 */
    v172 = quot2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = list2star(stack[-1], stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    goto v74;

v74:
    stack[-8] = v172;
    v172 = (Lisp_Object)17; /* 1 */
    stack[-4] = v172;
    goto v180;

v180:
    v173 = (Lisp_Object)33; /* 2 */
    v172 = stack[-4];
    v173 = times2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    stack[-4] = v173;
    v172 = stack[-5];
    v172 = (Lisp_Object)greaterp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v172 = v172 ? lisp_true : nil;
    env = stack[-9];
    if (v172 == nil) goto v181;
    v172 = stack[-5];
    stack[-4] = v172;
    goto v181;

v181:
    stack[0] = qvalue(elt(env, 5)); /* bfhalf!* */
    v174 = stack[-7];
    v173 = stack[-8];
    v172 = stack[-4];
    fn = elt(env, 9); /* divide!: */
    v173 = (*qfnn(fn))(qenv(fn), 3, v174, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = stack[-8];
    fn = elt(env, 10); /* plus!: */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    stack[-3] = stack[0];
    stack[-2] = v172;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v172 = stack[-3];
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = stack[-2];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    stack[0] = times2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = stack[-3];
    v172 = qcdr(v172);
    v173 = qcdr(v172);
    v172 = stack[-2];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = list2star(stack[-1], stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    stack[-2] = v172;
    v173 = stack[-4];
    v172 = stack[-5];
    v172 = (Lisp_Object)geq2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v172 = v172 ? lisp_true : nil;
    env = stack[-9];
    if (v172 == nil) goto v182;
    v173 = stack[-2];
    v172 = stack[-8];
    fn = elt(env, 11); /* difference!: */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    stack[-1] = v172;
    v172 = stack[-1];
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)greaterp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    v172 = v172 ? lisp_true : nil;
    env = stack[-9];
    if (v172 == nil) goto v183;
    v172 = stack[-1];
    v173 = v172;
    goto v184;

v184:
    v172 = stack[-6];
    fn = elt(env, 12); /* greaterp!: */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    if (!(v172 == nil)) goto v182;
    v172 = stack[-8];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v174 = v172;
    v173 = v174;
    v172 = (Lisp_Object)1; /* 0 */
    if (v173 == v172) goto v185;
    v173 = v174;
    v172 = qvalue(elt(env, 4)); /* !:bprec!: */
    fn = elt(env, 13); /* inorm */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v174 = v172;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v172 = v174;
    stack[0] = qcar(v172);
    v172 = v174;
    v173 = qcdr(v172);
    v172 = stack[-8];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = plus2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    {
        Lisp_Object v186 = stack[-1];
        Lisp_Object v187 = stack[0];
        popv(10);
        return list2star(v186, v187, v172);
    }

v185:
    v174 = elt(env, 1); /* !:rd!: */
    v173 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)1; /* 0 */
    popv(10);
    return list2star(v174, v173, v172);

v182:
    v172 = stack[-2];
    stack[-8] = v172;
    goto v180;

v183:
    stack[0] = elt(env, 1); /* !:rd!: */
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v173 = negate(v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = stack[-1];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = list2star(stack[0], v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v173 = v172;
    goto v184;

v179:
    stack[-1] = elt(env, 1); /* !:rd!: */
    stack[0] = (Lisp_Object)145; /* 9 */
    v173 = (Lisp_Object)81; /* 5 */
    v172 = stack[-8];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = times2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v173 = plus2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = (Lisp_Object)161; /* 10 */
    stack[0] = quot2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = stack[-8];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v173 = sub1(v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = (Lisp_Object)33; /* 2 */
    v172 = quot2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    v172 = list2star(stack[-1], stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-9];
    goto v74;

v177:
    v172 = (Lisp_Object)1; /* 0 */
    v173 = v172;
    goto v178;

v30:
    v172 = qvalue(elt(env, 3)); /* bfz!* */
    { popv(10); return onevalue(v172); }
/* error exit handlers */
v175:
    popv(10);
    return nil;
}



/* Code for exptbf */

static Lisp_Object MS_CDECL CC_exptbf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "exptbf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptbf");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v46;
    stack[-2] = v0;
/* end of prologue */

v5:
    v24 = stack[-1];
    v24 = Levenp(nil, v24);
    env = stack[-3];
    if (!(v24 == nil)) goto v11;
    v95 = stack[0];
    v24 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v24 = (*qfn2(fn))(qenv(fn), v95, v24);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    stack[0] = v24;
    goto v11;

v11:
    v95 = stack[-1];
    v24 = (Lisp_Object)-15; /* -1 */
    v24 = ash(v95, v24);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    stack[-1] = v24;
    v95 = stack[-1];
    v24 = (Lisp_Object)1; /* 0 */
    if (v95 == v24) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v95 = stack[-2];
    v24 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v24 = (*qfn2(fn))(qenv(fn), v95, v24);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-3];
    stack[-2] = v24;
    goto v5;
/* error exit handlers */
v73:
    popv(4);
    return nil;
}



/* Code for mod!-dump1 */

static Lisp_Object MS_CDECL CC_modKdump1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mod-dump1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod-dump1");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v46;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v191;

v191:
    v16 = stack[-1];
    if (v16 == nil) goto v50;
    v16 = stack[-1];
    v16 = qcar(v16);
    stack[0] = qcar(v16);
    v18 = stack[-3];
    v17 = stack[-2];
    v16 = stack[-1];
    v16 = qcar(v16);
    v16 = qcdr(v16);
    fn = elt(env, 1); /* l!-subst */
    v17 = (*qfnn(fn))(qenv(fn), 3, v18, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v16 = stack[-4];
    v16 = acons(stack[0], v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    stack[-4] = v16;
    v16 = stack[-1];
    v16 = qcdr(v16);
    stack[-1] = v16;
    goto v191;

v50:
    v16 = stack[-4];
    {
        popv(6);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v16);
    }
/* error exit handlers */
v72:
    popv(6);
    return nil;
}



/* Code for reduce!-ratios */

static Lisp_Object CC_reduceKratios(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-ratios");
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

v83:
    v171 = stack[-2];
    v194 = stack[-1];
    fn = elt(env, 1); /* red!-ratios1 */
    v194 = (*qfn2(fn))(qenv(fn), v171, v194);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    stack[-3] = v194;
    if (v194 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v194 = stack[-3];
    v171 = qcar(v194);
    v194 = stack[-2];
    fn = elt(env, 2); /* mv!-domainlist!-!* */
    stack[0] = (*qfn2(fn))(qenv(fn), v171, v194);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v194 = stack[-3];
    v171 = qcdr(v194);
    v194 = stack[-1];
    fn = elt(env, 2); /* mv!-domainlist!-!* */
    v194 = (*qfn2(fn))(qenv(fn), v171, v194);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    fn = elt(env, 3); /* mv!-domainlist!-!- */
    v194 = (*qfn2(fn))(qenv(fn), stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    stack[-3] = v194;
    v194 = stack[-2];
    fn = elt(env, 4); /* zeros */
    stack[0] = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v194 = stack[-3];
    fn = elt(env, 4); /* zeros */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v194 = (Lisp_Object)geq2(stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v194 = v194 ? lisp_true : nil;
    env = stack[-4];
    if (!(v194 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v171 = stack[-3];
    v194 = stack[-1];
    stack[-2] = v171;
    stack[-1] = v194;
    goto v83;
/* error exit handlers */
v39:
    popv(5);
    return nil;
}



/* Code for rationalizef */

static Lisp_Object CC_rationalizef(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizef");
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
    v210 = stack[-2];
    v148 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 9); /* kernels1 */
    v148 = (*qfn2(fn))(qenv(fn), v210, v148);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-4];
    stack[0] = v148;
    stack[-3] = v148;
    goto v191;

v191:
    v148 = stack[-3];
    if (v148 == nil) goto v45;
    v148 = stack[-3];
    v148 = qcar(v148);
    stack[-1] = v148;
    v210 = stack[-1];
    v148 = elt(env, 2); /* expt */
    if (!consp(v210)) goto v38;
    v210 = qcar(v210);
    if (!(v210 == v148)) goto v38;
    v148 = stack[-1];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v210 = qcar(v148);
    v148 = elt(env, 3); /* quotient */
    if (!consp(v210)) goto v38;
    v210 = qcar(v210);
    if (!(v210 == v148)) goto v38;
    v210 = stack[0];
    v148 = stack[-1];
    v148 = qcdr(v148);
    fn = elt(env, 10); /* lowertowerp */
    v148 = (*qfn2(fn))(qenv(fn), v210, v148);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-4];
    if (!(v148 == nil)) goto v21;

v38:
    v210 = stack[-1];
    v148 = elt(env, 4); /* i */
    if (v210 == v148) goto v178;
    v210 = stack[-1];
    v148 = elt(env, 2); /* expt */
    if (!consp(v210)) goto v212;
    v210 = qcar(v210);
    if (!(v210 == v148)) goto v212;
    v148 = stack[-1];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v210 = qcar(v148);
    v148 = elt(env, 5); /* (quotient 1 2) */
    if (!(equal(v210, v148))) goto v212;

v178:
    v210 = stack[-2];
    v148 = stack[-1];
    fn = elt(env, 11); /* mkmain */
    v210 = (*qfn2(fn))(qenv(fn), v210, v148);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-4];
    v148 = stack[-1];
    {
        popv(5);
        fn = elt(env, 12); /* conjquadratic */
        return (*qfn2(fn))(qenv(fn), v210, v148);
    }

v212:
    v210 = stack[-1];
    v148 = elt(env, 6); /* sqrt */
    if (!consp(v210)) goto v69;
    v210 = qcar(v210);
    if (v210 == v148) goto v178;
    else goto v69;

v69:
    v210 = stack[-1];
    v148 = elt(env, 2); /* expt */
    if (!consp(v210)) goto v213;
    v210 = qcar(v210);
    if (!(v210 == v148)) goto v213;
    v148 = stack[-1];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v210 = qcar(v148);
    v148 = elt(env, 7); /* (quotient 1 3) */
    if (!(equal(v210, v148))) goto v213;
    v210 = stack[-2];
    v148 = stack[-1];
    fn = elt(env, 11); /* mkmain */
    v210 = (*qfn2(fn))(qenv(fn), v210, v148);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-4];
    v148 = stack[-1];
    {
        popv(5);
        fn = elt(env, 13); /* conjcubic */
        return (*qfn2(fn))(qenv(fn), v210, v148);
    }

v213:
    v210 = stack[-1];
    v148 = elt(env, 2); /* expt */
    if (!consp(v210)) goto v21;
    v210 = qcar(v210);
    if (!(v210 == v148)) goto v21;
    v148 = stack[-1];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v210 = qcar(v148);
    v148 = elt(env, 8); /* (quotient 1 4) */
    if (!(equal(v210, v148))) goto v21;
    v210 = stack[-2];
    v148 = stack[-1];
    fn = elt(env, 11); /* mkmain */
    v210 = (*qfn2(fn))(qenv(fn), v210, v148);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-4];
    v148 = stack[-1];
    {
        popv(5);
        fn = elt(env, 14); /* conjquartic */
        return (*qfn2(fn))(qenv(fn), v210, v148);
    }

v21:
    v148 = stack[-3];
    v148 = qcdr(v148);
    stack[-3] = v148;
    goto v191;

v45:
    v148 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v148); }
/* error exit handlers */
v211:
    popv(5);
    return nil;
}



/* Code for bc_2a */

static Lisp_Object CC_bc_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_2a");
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
    v11 = v35;
    v35 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepf1 */
    v35 = (*qfn2(fn))(qenv(fn), v11, v35);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[0];
    v11 = v35;
    v35 = v11;
    if (v35 == nil) goto v13;
    v35 = v11;
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v35);
    }

v13:
    v35 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v35); }
/* error exit handlers */
v10:
    popv(1);
    return nil;
}



/* Code for split!-further */

static Lisp_Object MS_CDECL CC_splitKfurther(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v234, v235, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-further");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-further");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v46;
    stack[-3] = v0;
/* end of prologue */
    v233 = stack[-3];
    if (v233 == nil) goto v5;
    v233 = stack[-3];
    v235 = qcdr(v233);
    v234 = stack[-2];
    v233 = stack[-1];
    v233 = CC_splitKfurther(env, 3, v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    stack[-4] = v233;
    v233 = stack[-4];
    v233 = qcdr(v233);
    stack[0] = v233;
    v233 = stack[-4];
    v233 = qcar(v233);
    stack[-4] = v233;
    v234 = qvalue(elt(env, 2)); /* number!-needed */
    v233 = (Lisp_Object)1; /* 0 */
    if (v234 == v233) goto v238;
    v235 = stack[-2];
    v234 = stack[-1];
    v233 = qvalue(elt(env, 3)); /* work!-vector1 */
    fn = elt(env, 7); /* copy!-vector */
    v233 = (*qfnn(fn))(qenv(fn), 3, v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    qvalue(elt(env, 4)) = v233; /* dwork1 */
    v233 = stack[-3];
    v233 = qcar(v233);
    v235 = qcar(v233);
    v233 = stack[-3];
    v233 = qcar(v233);
    v234 = qcdr(v233);
    v233 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 7); /* copy!-vector */
    v233 = (*qfnn(fn))(qenv(fn), 3, v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    qvalue(elt(env, 6)) = v233; /* dwork2 */
    v236 = qvalue(elt(env, 3)); /* work!-vector1 */
    v235 = qvalue(elt(env, 4)); /* dwork1 */
    v234 = qvalue(elt(env, 5)); /* work!-vector2 */
    v233 = qvalue(elt(env, 6)); /* dwork2 */
    fn = elt(env, 8); /* gcd!-in!-vector */
    v233 = (*qfnn(fn))(qenv(fn), 4, v236, v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    qvalue(elt(env, 4)) = v233; /* dwork1 */
    v234 = qvalue(elt(env, 4)); /* dwork1 */
    v233 = (Lisp_Object)1; /* 0 */
    if (v234 == v233) goto v238;
    v234 = qvalue(elt(env, 4)); /* dwork1 */
    v233 = stack[-3];
    v233 = qcar(v233);
    v233 = qcdr(v233);
    if (equal(v234, v233)) goto v238;
    v233 = stack[-3];
    v233 = qcar(v233);
    v235 = qcar(v233);
    v233 = stack[-3];
    v233 = qcar(v233);
    v234 = qcdr(v233);
    v233 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 7); /* copy!-vector */
    v233 = (*qfnn(fn))(qenv(fn), 3, v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    qvalue(elt(env, 6)) = v233; /* dwork2 */
    v236 = qvalue(elt(env, 5)); /* work!-vector2 */
    v235 = qvalue(elt(env, 6)); /* dwork2 */
    v234 = qvalue(elt(env, 3)); /* work!-vector1 */
    v233 = qvalue(elt(env, 4)); /* dwork1 */
    fn = elt(env, 9); /* quotfail!-in!-vector */
    v233 = (*qfnn(fn))(qenv(fn), 4, v236, v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    qvalue(elt(env, 6)) = v233; /* dwork2 */
    v233 = qvalue(elt(env, 4)); /* dwork1 */
    v233 = Lmkvect(nil, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    stack[-1] = v233;
    v235 = qvalue(elt(env, 3)); /* work!-vector1 */
    v234 = qvalue(elt(env, 4)); /* dwork1 */
    v233 = stack[-1];
    fn = elt(env, 7); /* copy!-vector */
    v233 = (*qfnn(fn))(qenv(fn), 3, v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    v235 = stack[-1];
    v234 = qvalue(elt(env, 4)); /* dwork1 */
    v233 = stack[-4];
    v233 = acons(v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    stack[-4] = v233;
    stack[-2] = qvalue(elt(env, 5)); /* work!-vector2 */
    stack[-1] = qvalue(elt(env, 6)); /* dwork2 */
    v233 = qvalue(elt(env, 6)); /* dwork2 */
    v233 = Lmkvect(nil, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    stack[-3] = v233;
    fn = elt(env, 7); /* copy!-vector */
    v233 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    v235 = stack[-3];
    v234 = qvalue(elt(env, 6)); /* dwork2 */
    v233 = stack[0];
    v233 = acons(v235, v234, v233);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-5];
    stack[0] = v233;
    v233 = qvalue(elt(env, 2)); /* number!-needed */
    v233 = (Lisp_Object)((int32_t)(v233) - 0x10);
    qvalue(elt(env, 2)) = v233; /* number!-needed */
    v234 = stack[-4];
    v233 = stack[0];
    popv(6);
    return cons(v234, v233);

v238:
    v235 = stack[-4];
    v233 = stack[-3];
    v234 = qcar(v233);
    v233 = stack[0];
    popv(6);
    return list2star(v235, v234, v233);

v5:
    v233 = qvalue(elt(env, 1)); /* nil */
    popv(6);
    return ncons(v233);
/* error exit handlers */
v237:
    popv(6);
    return nil;
}



/* Code for mksqrt */

static Lisp_Object CC_mksqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v209, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksqrt");
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
    v232 = qvalue(elt(env, 1)); /* !*keepsqrts */
    if (v232 == nil) goto v214;
    v232 = qvalue(elt(env, 4)); /* !*!*sqrt */
    if (!(v232 == nil)) goto v95;
    v232 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v232; /* !*!*sqrt */
    v29 = elt(env, 6); /* (x) */
    v209 = lisp_true;
    v232 = elt(env, 7); /* (let00 (quote ((equal (expt (sqrt x) 2) x)))) 
*/
    v232 = list3(v29, v209, v232);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    fn = elt(env, 9); /* forall */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    fn = elt(env, 10); /* aeval */
    v232 = (*qfn1(fn))(qenv(fn), v232);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    goto v95;

v95:
    v209 = elt(env, 8); /* sqrt */
    v232 = stack[0];
    popv(3);
    return list2(v209, v232);

v214:
    stack[-1] = elt(env, 2); /* expt */
    v29 = elt(env, 3); /* quotient */
    v209 = (Lisp_Object)17; /* 1 */
    v232 = (Lisp_Object)33; /* 2 */
    v232 = list3(v29, v209, v232);
    nil = C_nil;
    if (exception_pending()) goto v27;
    {
        Lisp_Object v38 = stack[-1];
        Lisp_Object v37 = stack[0];
        popv(3);
        return list3(v38, v37, v232);
    }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for totalcompareconstants */

static Lisp_Object CC_totalcompareconstants(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76, v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totalcompareconstants");
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
    v76 = stack[-2];
    v75 = stack[-1];
    if (equal(v76, v75)) goto v59;
    v75 = stack[-2];
    if (!consp(v75)) goto v20;
    v75 = stack[-2];
    v75 = qcar(v75);
    if (!consp(v75)) goto v20;
    v75 = stack[-1];
    if (!consp(v75)) goto v209;
    v75 = stack[-1];
    v75 = qcar(v75);
    if (!consp(v75)) goto v209;
    stack[-3] = qvalue(elt(env, 4)); /* wukord!* */
    qvalue(elt(env, 4)) = nil; /* wukord!* */
    stack[0] = qvalue(elt(env, 5)); /* wuvarlist!* */
    qvalue(elt(env, 5)) = nil; /* wuvarlist!* */
    v75 = stack[-2];
    v75 = qcar(v75);
    v75 = qcar(v75);
    v76 = qcar(v75);
    v75 = stack[-1];
    v75 = qcar(v75);
    v75 = qcar(v75);
    v75 = qcar(v75);
    fn = elt(env, 6); /* symbollessp */
    v75 = (*qfn2(fn))(qenv(fn), v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    if (v75 == nil) goto v240;
    v75 = elt(env, 2); /* less */
    goto v87;

v87:
    qvalue(elt(env, 5)) = stack[0]; /* wuvarlist!* */
    qvalue(elt(env, 4)) = stack[-3]; /* wukord!* */
    { popv(5); return onevalue(v75); }

v240:
    v75 = stack[-1];
    v75 = qcar(v75);
    v75 = qcar(v75);
    v76 = qcar(v75);
    v75 = stack[-2];
    v75 = qcar(v75);
    v75 = qcar(v75);
    v75 = qcar(v75);
    fn = elt(env, 6); /* symbollessp */
    v75 = (*qfn2(fn))(qenv(fn), v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    if (v75 == nil) goto v177;
    v75 = elt(env, 3); /* greater */
    goto v87;

v177:
    v75 = stack[-2];
    v75 = qcar(v75);
    v76 = qcdr(v75);
    v75 = stack[-1];
    v75 = qcar(v75);
    v75 = qcdr(v75);
    v75 = CC_totalcompareconstants(env, v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    v239 = v75;
    v76 = v239;
    v75 = elt(env, 1); /* equal */
    if (v76 == v75) goto v203;
    v75 = v239;
    goto v87;

v203:
    v75 = stack[-2];
    v76 = qcdr(v75);
    v75 = stack[-1];
    v75 = qcdr(v75);
    v75 = CC_totalcompareconstants(env, v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-4];
    goto v87;

v209:
    v75 = elt(env, 3); /* greater */
    { popv(5); return onevalue(v75); }

v20:
    v75 = stack[-1];
    if (!consp(v75)) goto v31;
    v75 = stack[-1];
    v75 = qcar(v75);
    if (!consp(v75)) goto v31;
    v75 = elt(env, 2); /* less */
    { popv(5); return onevalue(v75); }

v31:
    v75 = stack[-2];
    v76 = v75;
    if (!(v76 == nil)) goto v40;
    v75 = (Lisp_Object)1; /* 0 */
    v76 = v75;
    goto v40;

v40:
    v75 = stack[-1];
    if (!(v75 == nil)) goto v189;
    v75 = (Lisp_Object)1; /* 0 */
    goto v189;

v189:
    v75 = (Lisp_Object)lessp2(v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v75 = v75 ? lisp_true : nil;
    env = stack[-4];
    if (v75 == nil) goto v72;
    v75 = elt(env, 2); /* less */
    { popv(5); return onevalue(v75); }

v72:
    v75 = elt(env, 3); /* greater */
    { popv(5); return onevalue(v75); }

v59:
    v75 = elt(env, 1); /* equal */
    { popv(5); return onevalue(v75); }
/* error exit handlers */
v241:
    popv(5);
    return nil;
v77:
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* wuvarlist!* */
    qvalue(elt(env, 4)) = stack[-3]; /* wukord!* */
    popv(5);
    return nil;
}



/* Code for simp0 */

static Lisp_Object CC_simp0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp0");
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
    stack[-5] = qvalue(elt(env, 1)); /* !*factor */
    qvalue(elt(env, 1)) = nil; /* !*factor */
    v205 = stack[-4];
    v34 = elt(env, 2); /* !*sq */
    if (!consp(v205)) goto v2;
    v205 = qcar(v205);
    if (!(v205 == v34)) goto v2;
    v34 = stack[-4];
    v34 = qcdr(v34);
    v34 = qcar(v34);
    fn = elt(env, 9); /* prepsq!* */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v34 = CC_simp0(env, v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    goto v191;

v191:
    qvalue(elt(env, 1)) = stack[-5]; /* !*factor */
    { popv(7); return onevalue(v34); }

v2:
    v205 = stack[-4];
    v34 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 10); /* frvarsof */
    v34 = (*qfn2(fn))(qenv(fn), v205, v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    fn = elt(env, 11); /* setkorder */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[-2] = v34;
    v205 = qvalue(elt(env, 4)); /* subfg!* */
    v34 = qvalue(elt(env, 5)); /* !*sub2 */
    v34 = cons(v205, v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[-3] = v34;
    v34 = qvalue(elt(env, 3)); /* nil */
    v34 = ncons(v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    qvalue(elt(env, 6)) = v34; /* alglist!* */
    v34 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v34; /* subfg!* */
    v34 = stack[-4];
    if (!consp(v34)) goto v19;
    v34 = stack[-4];
    v34 = qcar(v34);
    if (!(symbolp(v34))) goto v168;
    v34 = stack[-4];
    v205 = qcar(v34);
    v34 = elt(env, 7); /* simp0fn */
    v34 = Lflagp(nil, v205, v34);
    env = stack[-6];
    if (!(v34 == nil)) goto v19;
    v34 = stack[-4];
    v205 = qcar(v34);
    v34 = elt(env, 8); /* rtype */
    v34 = get(v205, v34);
    env = stack[-6];
    if (!(v34 == nil)) goto v19;

v168:
    v34 = stack[-4];
    fn = elt(env, 12); /* simpiden */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[-1] = v34;
    goto v62;

v62:
    stack[0] = qvalue(elt(env, 6)); /* alglist!* */
    v205 = stack[-4];
    v34 = qvalue(elt(env, 6)); /* alglist!* */
    v34 = qcar(v34);
    fn = elt(env, 13); /* delasc */
    v34 = (*qfn2(fn))(qenv(fn), v205, v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v34 = Lrplaca(nil, stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v34 = stack[-3];
    v34 = qcar(v34);
    qvalue(elt(env, 4)) = v34; /* subfg!* */
    v34 = stack[-3];
    v34 = qcdr(v34);
    qvalue(elt(env, 5)) = v34; /* !*sub2 */
    v34 = stack[-2];
    fn = elt(env, 11); /* setkorder */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    v34 = stack[-1];
    goto v191;

v19:
    v34 = stack[-4];
    fn = elt(env, 14); /* simp */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-6];
    stack[-1] = v34;
    goto v62;
/* error exit handlers */
v207:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-5]; /* !*factor */
    popv(7);
    return nil;
}



/* Code for makecoeffpairs */

static Lisp_Object MS_CDECL CC_makecoeffpairs(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, Lisp_Object v79, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v11, v10, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairs");
#endif
    if (stack >= stacklimit)
    {
        push4(v79,v4,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v46,v4,v79);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v79;
    v11 = v4;
    v10 = v46;
    v243 = v0;
/* end of prologue */
    fn = elt(env, 1); /* makecoeffpairs1 */
    v35 = (*qfnn(fn))(qenv(fn), 4, v243, v10, v11, v35);
    errexit();
    v35 = qcdr(v35);
        return Lnreverse(nil, v35);
}



/* Code for pasf_ceil */

static Lisp_Object CC_pasf_ceil(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v206, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_ceil");
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
    v207 = stack[-1];
    if (!consp(v207)) goto v191;
    v207 = stack[-1];
    v207 = qcar(v207);
    if (!(!consp(v207))) goto v26;

v191:
    v207 = stack[0];
    if (!consp(v207)) goto v59;
    v207 = stack[0];
    v207 = qcar(v207);
    if (!(!consp(v207))) goto v26;

v59:
    v207 = stack[-1];
    if (v207 == nil) goto v35;
    v206 = stack[-1];
    v207 = stack[0];
    v206 = Cremainder(v206, v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    v207 = (Lisp_Object)1; /* 0 */
    if (v206 == v207) goto v19;
    v206 = stack[-1];
    v207 = stack[0];
    v206 = times2(v206, v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    v207 = (Lisp_Object)1; /* 0 */
    v207 = (Lisp_Object)greaterp2(v206, v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    v207 = v207 ? lisp_true : nil;
    env = stack[-2];
    if (v207 == nil) goto v62;
    v206 = stack[-1];
    v207 = stack[0];
    v207 = quot2(v206, v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    v207 = add1(v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    goto v81;

v81:
    fn = elt(env, 4); /* simp */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    v207 = qcar(v207);
    { popv(3); return onevalue(v207); }

v62:
    v206 = stack[-1];
    v207 = stack[0];
    v207 = quot2(v206, v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    goto v81;

v19:
    v206 = stack[-1];
    v207 = stack[0];
    v207 = quot2(v206, v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    goto v81;

v35:
    v207 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v207); }

v26:
    v207 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v207 == nil)) goto v162;
    v245 = elt(env, 3); /* "pasf_ceil: not a domain valued sf in input" 
*/
    v206 = stack[-1];
    v207 = stack[0];
    v207 = list3(v245, v206, v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    fn = elt(env, 5); /* lprie */
    v207 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-2];
    goto v162;

v162:
    v207 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v246;
    v207 = nil;
    { popv(3); return onevalue(v207); }
/* error exit handlers */
v246:
    popv(3);
    return nil;
}



/* Code for ev_2a */

static Lisp_Object CC_ev_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v50 = v0;
/* end of prologue */
    v83 = v50;
    v50 = qvalue(elt(env, 1)); /* dip_vars!* */
    {
        fn = elt(env, 2); /* ev_2a1 */
        return (*qfn2(fn))(qenv(fn), v83, v50);
    }
}



/* Code for vdp_setsugar */

static Lisp_Object CC_vdp_setsugar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v10, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_setsugar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v46;
    v243 = v0;
/* end of prologue */
    v10 = qvalue(elt(env, 1)); /* !*cgbsugar */
    if (v10 == nil) return onevalue(v243);
    v10 = elt(env, 2); /* sugar */
    {
        fn = elt(env, 3); /* vdp_putprop */
        return (*qfnn(fn))(qenv(fn), 3, v243, v10, v11);
    }
}



/* Code for matrixrd */

static Lisp_Object MS_CDECL CC_matrixrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v247;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    v231 = (Lisp_Object)1; /* 0 */
    stack[-1] = v231;
    v231 = nil;
    stack[0] = v231;
    goto v48;

v48:
    v247 = stack[-1];
    v231 = (Lisp_Object)1; /* 0 */
    if (v247 == v231) goto v13;
    v247 = elt(env, 6); /* mat */
    v231 = stack[0];
    v231 = cons(v247, v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* aeval */
        return (*qfn1(fn))(qenv(fn), v231);
    }

v13:
    fn = elt(env, 8); /* lex */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    v247 = qvalue(elt(env, 2)); /* char */
    v231 = elt(env, 3); /* (m a t r i x r o w) */
    if (equal(v247, v231)) goto v2;
    v231 = (Lisp_Object)17; /* 1 */
    stack[-1] = v231;
    goto v48;

v2:
    fn = elt(env, 9); /* matrixrowrd */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    v247 = v231;
    v231 = stack[0];
    if (v231 == nil) goto v114;
    v231 = v247;
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    v231 = Lappend(nil, stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    stack[0] = v231;
    goto v29;

v29:
    v247 = qvalue(elt(env, 2)); /* char */
    v231 = elt(env, 4); /* (!/ m a t r i x r o w) */
    if (equal(v247, v231)) goto v48;
    v247 = elt(env, 5); /* "</matrixrow>" */
    v231 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 10); /* errorml */
    v231 = (*qfn2(fn))(qenv(fn), v247, v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    goto v48;

v114:
    v231 = v247;
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    stack[0] = v231;
    goto v29;
/* error exit handlers */
v161:
    popv(3);
    return nil;
}



/* Code for ps!:mkpow */

static Lisp_Object MS_CDECL CC_psTmkpow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v193, v194, v171;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:mkpow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:mkpow");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v194 = v46;
    v171 = v0;
/* end of prologue */
    v193 = v194;
    v63 = (Lisp_Object)1; /* 0 */
    if (v193 == v63) goto v5;
    v193 = v194;
    v63 = (Lisp_Object)17; /* 1 */
    if (v193 == v63) goto v35;
    v63 = elt(env, 1); /* expt */
    v193 = v171;
    v63 = list3(v63, v193, v194);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-1];
    goto v23;

v23:
    v193 = stack[0];
    if (v193 == nil) goto v27;
    v194 = elt(env, 2); /* quotient */
    v193 = (Lisp_Object)17; /* 1 */
    v63 = list3(v194, v193, v63);
    nil = C_nil;
    if (exception_pending()) goto v86;
    popv(2);
    return ncons(v63);

v27:
    popv(2);
    return ncons(v63);

v35:
    v63 = v171;
    goto v23;

v5:
    v63 = (Lisp_Object)17; /* 1 */
    popv(2);
    return ncons(v63);
/* error exit handlers */
v86:
    popv(2);
    return nil;
}



/* Code for boolvalue!* */

static Lisp_Object CC_boolvalueH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boolvalue*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v23 = v0;
/* end of prologue */
    v3 = v23;
    if (v3 == nil) goto v14;
    v3 = (Lisp_Object)1; /* 0 */
    v3 = (v23 == v3 ? lisp_true : nil);
    v3 = (v3 == nil ? lisp_true : nil);
    return onevalue(v3);

v14:
    v3 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v3);
}



/* Code for simpdf */

static Lisp_Object CC_simpdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v267, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdf");
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
    stack[-5] = v0;
/* end of prologue */
    stack[-3] = nil;
    v267 = qvalue(elt(env, 1)); /* subfg!* */
    if (v267 == nil) goto v35;
    v267 = stack[-5];
    v267 = qcdr(v267);
    stack[-6] = v267;
    v267 = stack[-5];
    v267 = qcar(v267);
    fn = elt(env, 10); /* simp!* */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[-5] = v267;
    goto v214;

v214:
    v267 = stack[-6];
    if (v267 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v267 = stack[-5];
    v267 = qcar(v267);
    if (v267 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v267 = stack[-3];
    if (v267 == nil) goto v18;
    v268 = stack[-3];
    v267 = (Lisp_Object)1; /* 0 */
    if (v268 == v267) goto v18;
    v267 = stack[-3];
    goto v17;

v17:
    stack[-4] = v267;
    v267 = stack[-4];
    v268 = qcdr(v267);
    v267 = (Lisp_Object)17; /* 1 */
    if (!(v268 == v267)) goto v270;
    v267 = stack[-4];
    v267 = qcar(v267);
    if (!consp(v267)) goto v270;
    v267 = stack[-4];
    v267 = qcar(v267);
    stack[-2] = v267;
    v267 = stack[-2];
    if (!consp(v267)) goto v228;
    v267 = stack[-2];
    v267 = qcar(v267);
    if (!consp(v267)) goto v228;
    v267 = stack[-2];
    v267 = qcdr(v267);
    if (!(v267 == nil)) goto v271;
    v267 = stack[-2];
    v267 = qcar(v267);
    v268 = qcdr(v267);
    v267 = (Lisp_Object)17; /* 1 */
    if (!(v268 == v267)) goto v271;
    v267 = stack[-2];
    v267 = qcar(v267);
    v267 = qcar(v267);
    v268 = qcdr(v267);
    v267 = (Lisp_Object)17; /* 1 */
    if (!(v268 == v267)) goto v271;
    v267 = stack[-2];
    v267 = qcar(v267);
    v267 = qcar(v267);
    v267 = qcar(v267);
    stack[-4] = v267;
    goto v85;

v85:
    v267 = stack[-6];
    v267 = qcdr(v267);
    stack[-6] = v267;
    v267 = stack[-6];
    if (v267 == nil) goto v134;
    v267 = stack[-6];
    v267 = qcar(v267);
    fn = elt(env, 10); /* simp!* */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[-3] = v267;
    v267 = stack[-3];
    v267 = qcar(v267);
    if (v267 == nil) goto v272;
    v267 = stack[-3];
    fn = elt(env, 11); /* d2int */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[0] = v267;
    if (v267 == nil) goto v122;
    v267 = stack[-6];
    v267 = qcdr(v267);
    stack[-6] = v267;
    v267 = (Lisp_Object)17; /* 1 */
    stack[-1] = v267;
    goto v273;

v273:
    v268 = stack[0];
    v267 = stack[-1];
    v267 = difference2(v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    v267 = Lminusp(nil, v267);
    env = stack[-7];
    if (v267 == nil) goto v274;
    v267 = qvalue(elt(env, 8)); /* nil */
    stack[-3] = v267;
    goto v214;

v274:
    v268 = stack[-5];
    v267 = stack[-4];
    fn = elt(env, 12); /* diffsq */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[-5] = v267;
    v267 = stack[-1];
    v267 = add1(v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[-1] = v267;
    goto v273;

v122:
    v268 = stack[-5];
    v267 = stack[-4];
    fn = elt(env, 12); /* diffsq */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[-5] = v267;
    goto v214;

v272:
    v267 = stack[-6];
    v267 = qcdr(v267);
    stack[-6] = v267;
    v267 = qvalue(elt(env, 8)); /* nil */
    stack[-3] = v267;
    goto v214;

v134:
    v268 = stack[-5];
    v267 = stack[-4];
    fn = elt(env, 12); /* diffsq */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[-5] = v267;
    goto v214;

v271:
    v268 = stack[-2];
    v267 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 13); /* prepf1 */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    v268 = v267;
    v267 = v268;
    if (v267 == nil) goto v275;
    v267 = v268;
    fn = elt(env, 14); /* replus */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    v268 = v267;
    goto v276;

v276:
    v267 = elt(env, 9); /* "kernel" */
    fn = elt(env, 15); /* typerr */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    goto v85;

v275:
    v267 = (Lisp_Object)1; /* 0 */
    v268 = v267;
    goto v276;

v228:
    v267 = stack[-2];
    v268 = qcar(v267);
    v267 = elt(env, 5); /* domain!-diff!-fn */
    v267 = get(v268, v267);
    env = stack[-7];
    if (v267 == nil) goto v154;
    stack[-1] = qvalue(elt(env, 6)); /* dmode!* */
    qvalue(elt(env, 6)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 7)); /* alglist!* */
    qvalue(elt(env, 7)) = nil; /* alglist!* */
    v267 = qvalue(elt(env, 8)); /* nil */
    v267 = ncons(v267);
    nil = C_nil;
    if (exception_pending()) goto v277;
    env = stack[-7];
    qvalue(elt(env, 7)) = v267; /* alglist!* */
    v268 = stack[-2];
    v267 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 13); /* prepf1 */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v277;
    env = stack[-7];
    v268 = v267;
    v267 = v268;
    if (v267 == nil) goto v227;
    v267 = v268;
    fn = elt(env, 14); /* replus */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v277;
    env = stack[-7];
    goto v239;

v239:
    stack[-4] = v267;
    v267 = stack[-4];
    fn = elt(env, 16); /* prekernp */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v277;
    env = stack[-7];
    if (!(v267 == nil)) goto v65;
    v268 = stack[-4];
    v267 = elt(env, 9); /* "kernel" */
    fn = elt(env, 15); /* typerr */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v277;
    env = stack[-7];
    goto v65;

v65:
    qvalue(elt(env, 7)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 6)) = stack[-1]; /* dmode!* */
    goto v85;

v227:
    v267 = (Lisp_Object)1; /* 0 */
    goto v239;

v154:
    v268 = stack[-2];
    v267 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 13); /* prepf1 */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    v268 = v267;
    v267 = v268;
    if (v267 == nil) goto v157;
    v267 = v268;
    fn = elt(env, 14); /* replus */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    v268 = v267;
    goto v278;

v278:
    v267 = elt(env, 9); /* "kernel" */
    fn = elt(env, 15); /* typerr */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    goto v85;

v157:
    v267 = (Lisp_Object)1; /* 0 */
    v268 = v267;
    goto v278;

v270:
    v267 = stack[-4];
    v267 = qcar(v267);
    if (v267 == nil) goto v25;
    v268 = stack[-4];
    v267 = elt(env, 3); /* prepf */
    fn = elt(env, 17); /* sqform */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    v268 = v267;
    goto v62;

v62:
    v267 = elt(env, 4); /* "kernel or integer" */
    fn = elt(env, 15); /* typerr */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    goto v85;

v25:
    v267 = (Lisp_Object)1; /* 0 */
    v268 = v267;
    goto v62;

v18:
    v267 = stack[-6];
    v267 = qcar(v267);
    fn = elt(env, 10); /* simp!* */
    v267 = (*qfn1(fn))(qenv(fn), v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    goto v17;

v35:
    v268 = elt(env, 2); /* df */
    v267 = stack[-5];
    v268 = cons(v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    v267 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 18); /* mksq */
        return (*qfn2(fn))(qenv(fn), v268, v267);
    }
/* error exit handlers */
v277:
    env = stack[-7];
    qvalue(elt(env, 7)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 6)) = stack[-1]; /* dmode!* */
    popv(8);
    return nil;
v269:
    popv(8);
    return nil;
}



/* Code for simp_without_resimp */

static Lisp_Object CC_simp_without_resimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp_without_resimp");
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
    v191 = v0;
/* end of prologue */
    v5 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*resimp */
    qvalue(elt(env, 2)) = v5; /* !*resimp */
    v5 = v191;
    fn = elt(env, 3); /* simp */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*resimp */
    { popv(2); return onevalue(v5); }
/* error exit handlers */
v8:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*resimp */
    popv(2);
    return nil;
}



/* Code for toolongassignp */

static Lisp_Object CC_toolongassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toolongassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v191 = v0;
/* end of prologue */
    v191 = qcdr(v191);
    v191 = qcdr(v191);
    v191 = qcar(v191);
    {
        fn = elt(env, 1); /* toolongexpp */
        return (*qfn1(fn))(qenv(fn), v191);
    }
}



/* Code for indordln */

static Lisp_Object CC_indordln(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordln");
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
    v15 = v0;
/* end of prologue */
    v64 = v15;
    if (v64 == nil) goto v14;
    v64 = v15;
    v64 = qcdr(v64);
    if (v64 == nil) { popv(2); return onevalue(v15); }
    v64 = v15;
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    if (v64 == nil) goto v3;
    v64 = v15;
    stack[0] = qcar(v64);
    v64 = v15;
    v64 = qcdr(v64);
    v64 = CC_indordln(env, v64);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    {
        Lisp_Object v18 = stack[0];
        popv(2);
        fn = elt(env, 2); /* indordlad */
        return (*qfn2(fn))(qenv(fn), v18, v64);
    }

v3:
    v64 = v15;
    v64 = qcar(v64);
    v15 = qcdr(v15);
    v15 = qcar(v15);
    {
        popv(2);
        fn = elt(env, 3); /* indordl2 */
        return (*qfn2(fn))(qenv(fn), v64, v15);
    }

v14:
    v64 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v64); }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for consrecip */

static Lisp_Object CC_consrecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v41, v40;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for consrecip");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v40 = v0;
/* end of prologue */
    v31 = v40;
    v41 = qcar(v31);
    v31 = (Lisp_Object)17; /* 1 */
    if (v41 == v31) goto v14;
    v31 = v40;
    v41 = qcar(v31);
    v31 = (Lisp_Object)-15; /* -1 */
    if (v41 == v31) goto v14;
    v31 = elt(env, 1); /* recip */
    v41 = v40;
    return cons(v31, v41);

v14:
    v31 = v40;
    v31 = qcar(v31);
    return onevalue(v31);
}



/* Code for generic_arguments */

static Lisp_Object CC_generic_arguments(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v3, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for generic_arguments");
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
    v23 = elt(env, 1); /* list */
    v3 = qcar(v45);
    v45 = elt(env, 2); /* generic_function */
    v45 = get(v3, v45);
    return cons(v23, v45);
}



/* Code for arminusp!: */

static Lisp_Object CC_arminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arminusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v0;
/* end of prologue */
    v59 = qcdr(v59);
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v59);
    }
}



/* Code for mkrootsql */

static Lisp_Object CC_mkrootsql(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrootsql");
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
    v62 = stack[-1];
    if (v62 == nil) goto v59;
    v62 = stack[-1];
    v62 = qcar(v62);
    v60 = qcdr(v62);
    v62 = (Lisp_Object)17; /* 1 */
    v62 = (Lisp_Object)greaterp2(v60, v62);
    nil = C_nil;
    if (exception_pending()) goto v25;
    v62 = v62 ? lisp_true : nil;
    env = stack[-3];
    if (v62 == nil) goto v85;
    v62 = stack[-1];
    v62 = qcar(v62);
    v60 = qcar(v62);
    v62 = stack[0];
    fn = elt(env, 1); /* mkrootsq */
    v60 = (*qfn2(fn))(qenv(fn), v60, v62);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v62 = stack[-1];
    v62 = qcar(v62);
    v62 = qcdr(v62);
    fn = elt(env, 2); /* exptsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v60, v62);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v62 = stack[-1];
    v60 = qcdr(v62);
    v62 = stack[0];
    v62 = CC_mkrootsql(env, v60, v62);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    {
        Lisp_Object v160 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v160, v62);
    }

v85:
    v62 = stack[-1];
    v62 = qcar(v62);
    v60 = qcar(v62);
    v62 = stack[0];
    fn = elt(env, 1); /* mkrootsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v60, v62);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    v62 = stack[-1];
    v60 = qcdr(v62);
    v62 = stack[0];
    v62 = CC_mkrootsql(env, v60, v62);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-3];
    {
        Lisp_Object v161 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v161, v62);
    }

v59:
    v62 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 4); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v62);
    }
/* error exit handlers */
v25:
    popv(4);
    return nil;
}



/* Code for make!-modular!-symmetric */

static Lisp_Object CC_makeKmodularKsymmetric(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-modular-symmetric");
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
    v171 = stack[-1];
    if (v171 == nil) goto v14;
    v171 = stack[-1];
    if (!consp(v171)) goto v23;
    v171 = stack[-1];
    v171 = qcar(v171);
    if (!consp(v171)) goto v23;
    v171 = stack[-1];
    v171 = qcar(v171);
    stack[-2] = qcar(v171);
    v171 = stack[-1];
    v171 = qcar(v171);
    v171 = qcdr(v171);
    stack[0] = CC_makeKmodularKsymmetric(env, v171);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v171 = stack[-1];
    v171 = qcdr(v171);
    v171 = CC_makeKmodularKsymmetric(env, v171);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    {
        Lisp_Object v242 = stack[-2];
        Lisp_Object v89 = stack[0];
        popv(4);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v242, v89, v171);
    }

v23:
    v170 = stack[-1];
    v171 = qvalue(elt(env, 2)); /* modulus!/2 */
    v171 = (Lisp_Object)greaterp2(v170, v171);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v171 = v171 ? lisp_true : nil;
    env = stack[-3];
    if (v171 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v170 = stack[-1];
    v171 = qvalue(elt(env, 3)); /* current!-modulus */
    v171 = difference2(v170, v171);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v170 = v171;
    v171 = v170;
    v171 = (Lisp_Object)zerop(v171);
    v171 = v171 ? lisp_true : nil;
    env = stack[-3];
    if (v171 == nil) { popv(4); return onevalue(v170); }
    v171 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v171); }

v14:
    v171 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v171); }
/* error exit handlers */
v39:
    popv(4);
    return nil;
}



/* Code for simprd */

static Lisp_Object CC_simprd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprd");
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
    v20 = v0;
/* end of prologue */
    v47 = v20;
    if (!consp(v47)) goto v14;
    v47 = elt(env, 2); /* !:rd!: */
    stack[0] = qvalue(elt(env, 3)); /* dmode!* */
    qvalue(elt(env, 3)) = v47; /* dmode!* */
    v47 = v20;
    fn = elt(env, 4); /* simplist */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    qvalue(elt(env, 3)) = stack[0]; /* dmode!* */
    { popv(2); return onevalue(v47); }

v14:
    v47 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v47); }
/* error exit handlers */
v42:
    env = stack[-1];
    qvalue(elt(env, 3)) = stack[0]; /* dmode!* */
    popv(2);
    return nil;
}



/* Code for rl_smrmknowl */

static Lisp_Object CC_rl_smrmknowl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smrmknowl");
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
    push(nil);
/* copy arguments values to proper place */
    v45 = v46;
    v3 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smrmknowl!* */
    v45 = list2(v3, v45);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    {
        Lisp_Object v11 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v11, v45);
    }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for get_char_group */

static Lisp_Object CC_get_char_group(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v5;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_char_group");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v5 = qcar(v5);
    return onevalue(v5);
}



/* Code for factor!-prim!-f */

static Lisp_Object CC_factorKprimKf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v288, v276;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factor-prim-f");
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
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    v145 = qvalue(elt(env, 1)); /* ncmp!* */
    if (v145 == nil) goto v8;
    stack[0] = (Lisp_Object)17; /* 1 */
    v288 = stack[-1];
    v145 = (Lisp_Object)17; /* 1 */
    v145 = cons(v288, v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    {
        Lisp_Object v290 = stack[0];
        popv(5);
        return list2(v290, v145);
    }

v8:
    v145 = qvalue(elt(env, 2)); /* dmode!* */
    if (v145 == nil) goto v291;
    v288 = qvalue(elt(env, 2)); /* dmode!* */
    v145 = elt(env, 3); /* sqfrfactorfn */
    v145 = get(v288, v145);
    env = stack[-4];
    stack[-2] = v145;
    if (v145 == nil) goto v291;
    v145 = qvalue(elt(env, 4)); /* !*factor */
    if (v145 == nil) goto v29;
    v288 = stack[-2];
    v145 = stack[-1];
    v145 = Lapply1(nil, v288, v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[0] = v145;
    goto v81;

v81:
    v145 = stack[-2];
    if (v145 == nil) goto v225;
    v276 = stack[-2];
    v288 = qvalue(elt(env, 2)); /* dmode!* */
    v145 = elt(env, 7); /* factorfn */
    v145 = get(v288, v145);
    env = stack[-4];
    if (v276 == v145) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v225;

v225:
    v145 = stack[0];
    v145 = qcar(v145);
    v145 = ncons(v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[-3] = v145;
    v145 = stack[0];
    v145 = qcdr(v145);
    stack[-2] = v145;
    goto v196;

v196:
    v145 = stack[-2];
    if (v145 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v145 = stack[-2];
    v145 = qcar(v145);
    fn = elt(env, 9); /* factor!-prim!-sqfree!-f */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[-1] = v145;
    v145 = stack[-1];
    v288 = qcar(v145);
    v145 = stack[-3];
    v145 = qcar(v145);
    fn = elt(env, 10); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v288, v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    v145 = stack[-1];
    v288 = qcdr(v145);
    v145 = stack[-3];
    v145 = qcdr(v145);
    v145 = Lappend(nil, v288, v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    v145 = cons(stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[-3] = v145;
    v145 = stack[-2];
    v145 = qcdr(v145);
    stack[-2] = v145;
    goto v196;

v29:
    stack[0] = (Lisp_Object)17; /* 1 */
    v288 = stack[-1];
    v145 = (Lisp_Object)17; /* 1 */
    v145 = cons(v288, v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    v145 = list2(stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[0] = v145;
    goto v81;

v291:
    v288 = qvalue(elt(env, 2)); /* dmode!* */
    v145 = elt(env, 5); /* field */
    v145 = Lflagp(nil, v288, v145);
    env = stack[-4];
    if (v145 == nil) goto v206;
    v145 = stack[-1];
    fn = elt(env, 11); /* lnc */
    v288 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[-3] = v288;
    v145 = (Lisp_Object)17; /* 1 */
    if (v288 == v145) goto v206;
    stack[0] = stack[-3];
    v145 = stack[-3];
    fn = elt(env, 12); /* !:recip */
    v288 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    v145 = stack[-1];
    fn = elt(env, 13); /* multd */
    v145 = (*qfn2(fn))(qenv(fn), v288, v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    fn = elt(env, 14); /* sqfrf */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    v145 = cons(stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[0] = v145;
    goto v81;

v206:
    v288 = qvalue(elt(env, 2)); /* dmode!* */
    v145 = elt(env, 6); /* units */
    v145 = get(v288, v145);
    env = stack[-4];
    stack[-3] = v145;
    if (v145 == nil) goto v200;
    v145 = stack[-1];
    fn = elt(env, 11); /* lnc */
    v288 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    v276 = v288;
    v145 = stack[-3];
    v145 = Lassoc(nil, v288, v145);
    stack[-3] = v145;
    if (v145 == nil) goto v200;
    stack[0] = v276;
    v145 = stack[-3];
    v288 = qcdr(v145);
    v145 = stack[-1];
    fn = elt(env, 13); /* multd */
    v145 = (*qfn2(fn))(qenv(fn), v288, v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    fn = elt(env, 14); /* sqfrf */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    v145 = cons(stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[0] = v145;
    goto v81;

v200:
    stack[0] = (Lisp_Object)17; /* 1 */
    v145 = stack[-1];
    fn = elt(env, 14); /* sqfrf */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    v145 = cons(stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-4];
    stack[0] = v145;
    goto v81;
/* error exit handlers */
v289:
    popv(5);
    return nil;
}



/* Code for matrixelems */

static Lisp_Object CC_matrixelems(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixelems");
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
    v81 = nil;
    goto v59;

v59:
    v80 = stack[0];
    if (v80 == nil) goto v243;
    v80 = stack[0];
    v80 = qcar(v80);
    v80 = qcdr(v80);
    v80 = qcdr(v80);
    v80 = cons(v80, v81);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v81 = v80;
    v80 = stack[0];
    v80 = qcdr(v80);
    stack[0] = v80;
    goto v59;

v243:
    v80 = v81;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v80);
    }
/* error exit handlers */
v6:
    popv(2);
    return nil;
}



/* Code for scar */

static Lisp_Object CC_scar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scar");
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

v43:
    v15 = stack[0];
    if (!consp(v15)) goto v59;
    v16 = stack[-1];
    v15 = stack[0];
    v15 = qcar(v15);
    if (equal(v16, v15)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v16 = stack[-1];
    v15 = stack[0];
    v15 = qcar(v15);
    v15 = CC_scar(env, v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    if (!(v15 == nil)) { popv(3); return onevalue(v15); }
    v16 = stack[-1];
    v15 = stack[0];
    v15 = qcdr(v15);
    stack[-1] = v16;
    stack[0] = v15;
    goto v43;

v59:
    v15 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v15); }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for spmatlength */

static Lisp_Object CC_spmatlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v270, v279, v62, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmatlength");
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
    v62 = v0;
/* end of prologue */
    v270 = v62;
    v270 = Lconsp(nil, v270);
    env = stack[0];
    if (v270 == nil) goto v48;
    v270 = v62;
    goto v191;

v191:
    v279 = v270;
    v279 = qcdr(v279);
    v279 = qcdr(v279);
    v279 = qcar(v279);
    v279 = qcdr(v279);
    v60 = v279;
    v279 = v270;
    v270 = elt(env, 2); /* sparsemat */
    if (!consp(v279)) goto v15;
    v279 = qcar(v279);
    if (!(v279 == v270)) goto v15;
    v279 = elt(env, 7); /* list */
    v270 = v60;
    v270 = qcar(v270);
    v62 = v60;
    v62 = qcdr(v62);
    v62 = qcar(v62);
    popv(1);
    return list3(v279, v270, v62);

v15:
    v279 = elt(env, 3); /* "Matrix" */
    v270 = elt(env, 4); /* "not set" */
    v270 = list3(v279, v62, v270);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[0];
    v279 = v270;
    v270 = v279;
    qvalue(elt(env, 5)) = v270; /* errmsg!* */
    v270 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v270 == nil)) goto v209;
    v270 = v279;
    fn = elt(env, 8); /* lprie */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[0];
    goto v209;

v209:
    v270 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v230;
    v270 = nil;
    { popv(1); return onevalue(v270); }

v48:
    v279 = v62;
    v270 = elt(env, 1); /* avalue */
    v270 = get(v279, v270);
    env = stack[0];
    v270 = qcdr(v270);
    v270 = qcar(v270);
    goto v191;
/* error exit handlers */
v230:
    popv(1);
    return nil;
}



/* Code for sroot1 */

static Lisp_Object CC_sroot1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v294, v278, v295;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroot1");
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
    stack[0] = v46;
    stack[-3] = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* freevars */
    qvalue(elt(env, 1)) = nil; /* freevars */
    stack[-1] = qvalue(elt(env, 2)); /* substitution */
    qvalue(elt(env, 2)) = nil; /* substitution */
    v294 = qvalue(elt(env, 3)); /* rpt */
    v152 = elt(env, 4); /* inf */
    if (v294 == v152) goto v49;
    v294 = qvalue(elt(env, 3)); /* rpt */
    v152 = (Lisp_Object)1; /* 0 */
    v152 = (Lisp_Object)lesseq2(v294, v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v152 = v152 ? lisp_true : nil;
    env = stack[-5];
    if (!(v152 == nil)) goto v50;

v49:
    v152 = stack[-3];
    if (!consp(v152)) goto v50;
    v152 = stack[-3];
    v294 = qcar(v152);
    v152 = stack[0];
    v152 = qcdr(v152);
    v152 = qcar(v152);
    v152 = qcar(v152);
    if (!(equal(v294, v152))) goto v50;
    v152 = stack[0];
    v152 = qcdr(v152);
    v152 = qcar(v152);
    fn = elt(env, 12); /* findnewvars */
    v294 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v152 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 13); /* union */
    v152 = (*qfn2(fn))(qenv(fn), v294, v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    qvalue(elt(env, 1)) = v152; /* freevars */
    v152 = stack[0];
    v152 = qcdr(v152);
    v152 = qcdr(v152);
    v152 = qcar(v152);
    qvalue(elt(env, 2)) = v152; /* substitution */
    v152 = qvalue(elt(env, 1)); /* freevars */
    stack[-4] = v152;
    goto v38;

v38:
    v152 = stack[-4];
    if (v152 == nil) goto v27;
    v152 = stack[-4];
    v152 = qcar(v152);
    fn = elt(env, 14); /* newenv */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v152 = stack[-4];
    v152 = qcdr(v152);
    stack[-4] = v152;
    goto v38;

v27:
    v152 = qvalue(elt(env, 6)); /* !*trpm */
    if (v152 == nil) goto v296;
    v152 = elt(env, 7); /* "Trying rule  " */
    v152 = Lprinc(nil, v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v152 = stack[0];
    fn = elt(env, 15); /* rprint */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v152 = elt(env, 8); /* "against      " */
    v152 = Lprinc(nil, v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v152 = stack[-3];
    fn = elt(env, 15); /* rprint */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v296;

v296:
    v152 = stack[0];
    v152 = qcdr(v152);
    v295 = qcar(v152);
    v278 = stack[-3];
    v294 = qvalue(elt(env, 9)); /* t */
    v152 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 16); /* amatch */
    v152 = (*qfnn(fn))(qenv(fn), 4, v295, v278, v294, v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-4] = v152;
    v152 = qvalue(elt(env, 6)); /* !*trpm */
    if (v152 == nil) goto v55;
    v152 = stack[-4];
    if (v152 == nil) goto v78;
    v152 = elt(env, 10); /* "producing    " */
    v152 = Lprinc(nil, v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v152 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    stack[-4] = v152;
    fn = elt(env, 15); /* rprint */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v245;

v245:
    v152 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v55;

v55:
    v152 = qvalue(elt(env, 1)); /* freevars */
    stack[0] = v152;
    goto v67;

v67:
    v152 = stack[0];
    if (v152 == nil) goto v65;
    v152 = stack[0];
    v152 = qcar(v152);
    fn = elt(env, 18); /* restorenv */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v152 = stack[0];
    v152 = qcdr(v152);
    stack[0] = v152;
    goto v67;

v65:
    v152 = stack[-4];
    if (v152 == nil) goto v224;
    v294 = qvalue(elt(env, 3)); /* rpt */
    v152 = elt(env, 4); /* inf */
    if (v294 == v152) goto v213;
    v152 = qvalue(elt(env, 3)); /* rpt */
    v152 = sub1(v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    qvalue(elt(env, 3)) = v152; /* rpt */
    goto v213;

v213:
    v152 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v152 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v191;

v191:
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    { popv(6); return onevalue(v152); }

v224:
    v152 = stack[-3];
    goto v191;

v78:
    v152 = elt(env, 11); /* "failed" */
    v152 = Lprinc(nil, v152);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    v152 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-5];
    goto v245;

v50:
    v152 = stack[-3];
    goto v191;
/* error exit handlers */
v222:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    popv(6);
    return nil;
}



/* Code for precision1 */

static Lisp_Object CC_precision1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v278, v295, v299;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for precision1");
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
    v299 = v46;
    stack[0] = v0;
/* end of prologue */
    v295 = stack[0];
    v278 = (Lisp_Object)1; /* 0 */
    if (v295 == v278) goto v214;
    v278 = v299;
    if (v278 == nil) goto v3;
    v295 = qvalue(elt(env, 2)); /* !*sqvar!* */
    v278 = qvalue(elt(env, 3)); /* nil */
    v278 = Lrplaca(nil, v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v278 = qvalue(elt(env, 4)); /* t */
    v278 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    qvalue(elt(env, 2)) = v278; /* !*sqvar!* */
    v278 = qvalue(elt(env, 3)); /* nil */
    v278 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    qvalue(elt(env, 5)) = v278; /* alglist!* */
    goto v3;

v3:
    v278 = qvalue(elt(env, 1)); /* !!rdprec */
    stack[-3] = v278;
    v278 = qvalue(elt(env, 6)); /* !*roundbf */
    if (v278 == nil) goto v71;
    v278 = stack[0];
    v295 = v278;
    goto v17;

v17:
    qvalue(elt(env, 1)) = v295; /* !!rdprec */
    v278 = (Lisp_Object)33; /* 2 */
    v278 = plus2(v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    qvalue(elt(env, 8)) = v278; /* !:prec!: */
    v278 = qvalue(elt(env, 9)); /* !:print!-prec!: */
    if (v278 == nil) goto v53;
    v295 = qvalue(elt(env, 9)); /* !:print!-prec!: */
    v278 = (Lisp_Object)33; /* 2 */
    v278 = plus2(v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v278 = (Lisp_Object)lessp2(stack[0], v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v278 = v278 ? lisp_true : nil;
    env = stack[-4];
    if (v278 == nil) goto v53;
    v278 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 9)) = v278; /* !:print!-prec!: */
    goto v53;

v53:
    v295 = qvalue(elt(env, 8)); /* !:prec!: */
    v278 = qvalue(elt(env, 10)); /* log2of10 */
    v278 = times2(v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    fn = elt(env, 18); /* ceiling */
    v295 = (*qfn1(fn))(qenv(fn), v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v278 = (Lisp_Object)49; /* 3 */
    v278 = plus2(v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    qvalue(elt(env, 11)) = v278; /* !:bprec!: */
    stack[-1] = elt(env, 12); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v295 = qvalue(elt(env, 11)); /* !:bprec!: */
    v278 = (Lisp_Object)33; /* 2 */
    v278 = quot2(v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v278 = negate(v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v278 = list2star(stack[-1], stack[0], v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    qvalue(elt(env, 13)) = v278; /* epsqrt!* */
    stack[-1] = elt(env, 12); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v295 = (Lisp_Object)97; /* 6 */
    v278 = qvalue(elt(env, 11)); /* !:bprec!: */
    v278 = difference2(v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v278 = list2star(stack[-1], stack[0], v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    qvalue(elt(env, 14)) = v278; /* rd!-tolerance!* */
    stack[-2] = elt(env, 12); /* !:rd!: */
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)33; /* 2 */
    v295 = (Lisp_Object)97; /* 6 */
    v278 = qvalue(elt(env, 11)); /* !:bprec!: */
    v278 = difference2(v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v278 = times2(stack[0], v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v278 = list2star(stack[-2], stack[-1], v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    qvalue(elt(env, 15)) = v278; /* cr!-tolerance!* */
    v295 = qvalue(elt(env, 1)); /* !!rdprec */
    v278 = qvalue(elt(env, 16)); /* !!flprec */
    v278 = (Lisp_Object)greaterp2(v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v278 = v278 ? lisp_true : nil;
    env = stack[-4];
    if (!(v278 == nil)) goto v300;
    v278 = qvalue(elt(env, 6)); /* !*roundbf */
    goto v300;

v300:
    qvalue(elt(env, 17)) = v278; /* !*!*roundbf */
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v71:
    v295 = stack[0];
    v278 = qvalue(elt(env, 7)); /* minprec!# */
    fn = elt(env, 19); /* max */
    v278 = (*qfn2(fn))(qenv(fn), v295, v278);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-4];
    v295 = v278;
    goto v17;

v214:
    v278 = qvalue(elt(env, 1)); /* !!rdprec */
    { popv(5); return onevalue(v278); }
/* error exit handlers */
v222:
    popv(5);
    return nil;
}



/* Code for r2oreaction */

static Lisp_Object MS_CDECL CC_r2oreaction(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, Lisp_Object v79, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v300, v292, v293;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "r2oreaction");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2oreaction");
#endif
    if (stack >= stacklimit)
    {
        push4(v79,v4,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v46,v4,v79);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v79;
    v300 = v4;
    stack[-5] = v46;
    stack[-1] = v0;
/* end of prologue */
    stack[-6] = v300;
    v300 = stack[-1];
    stack[-2] = v300;
    goto v13;

v13:
    v300 = stack[-2];
    if (v300 == nil) goto v49;
    v300 = stack[-2];
    v300 = qcar(v300);
    stack[0] = elt(env, 2); /* times */
    stack[-3] = stack[-6];
    v293 = elt(env, 3); /* expt */
    v292 = v300;
    v292 = qcdr(v292);
    v300 = qcar(v300);
    v300 = list3(v293, v292, v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    v300 = list3(stack[0], stack[-3], v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    fn = elt(env, 6); /* aeval */
    v300 = (*qfn1(fn))(qenv(fn), v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    stack[-6] = v300;
    v300 = stack[-2];
    v300 = qcdr(v300);
    stack[-2] = v300;
    goto v13;

v49:
    v300 = stack[-1];
    stack[-3] = v300;
    goto v71;

v71:
    v300 = stack[-3];
    if (v300 == nil) goto v72;
    v300 = stack[-3];
    v300 = qcar(v300);
    v292 = v300;
    v293 = qcdr(v292);
    v292 = stack[-4];
    v292 = Lassoc(nil, v293, v292);
    stack[-2] = v292;
    stack[-1] = elt(env, 4); /* difference */
    stack[0] = qcdr(v292);
    v293 = elt(env, 2); /* times */
    v292 = stack[-6];
    v300 = qcar(v300);
    v300 = list3(v293, v292, v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    v300 = list3(stack[-1], stack[0], v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v300 = (*qfn1(fn))(qenv(fn), v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    v300 = Lrplacd(nil, stack[-2], v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    v300 = stack[-3];
    v300 = qcdr(v300);
    stack[-3] = v300;
    goto v71;

v72:
    v300 = stack[-5];
    stack[-3] = v300;
    goto v54;

v54:
    v300 = stack[-3];
    if (v300 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v300 = stack[-3];
    v300 = qcar(v300);
    v292 = v300;
    v293 = qcdr(v292);
    v292 = stack[-4];
    v292 = Lassoc(nil, v293, v292);
    stack[-2] = v292;
    stack[-1] = elt(env, 5); /* plus */
    stack[0] = qcdr(v292);
    v293 = elt(env, 2); /* times */
    v292 = stack[-6];
    v300 = qcar(v300);
    v300 = list3(v293, v292, v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    v300 = list3(stack[-1], stack[0], v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v300 = (*qfn1(fn))(qenv(fn), v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    v300 = Lrplacd(nil, stack[-2], v300);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-7];
    v300 = stack[-3];
    v300 = qcdr(v300);
    stack[-3] = v300;
    goto v54;
/* error exit handlers */
v152:
    popv(8);
    return nil;
}



/* Code for cvitimes2 */

static Lisp_Object CC_cvitimes2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v209, v29, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cvitimes2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v29 = v46;
    v30 = v0;
/* end of prologue */
    v209 = v30;
    v232 = (Lisp_Object)1; /* 0 */
    if (v209 == v232) goto v59;
    v209 = v29;
    v232 = (Lisp_Object)1; /* 0 */
    if (v209 == v232) goto v59;
    v209 = v30;
    v232 = (Lisp_Object)17; /* 1 */
    if (v209 == v232) return onevalue(v29);
    v209 = v29;
    v232 = (Lisp_Object)17; /* 1 */
    if (v209 == v232) return onevalue(v30);
    v232 = elt(env, 1); /* times */
    v209 = v30;
    return list3(v232, v209, v29);

v59:
    v232 = (Lisp_Object)1; /* 0 */
    return onevalue(v232);
}



/* Code for mapcarcar */

static Lisp_Object CC_mapcarcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapcarcar");
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
    v16 = v0;
/* end of prologue */
    stack[-3] = v16;
    v16 = stack[-3];
    if (v16 == nil) goto v83;
    v16 = stack[-3];
    v16 = qcar(v16);
    v16 = qcar(v16);
    v16 = ncons(v16);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    stack[-1] = v16;
    stack[-2] = v16;
    goto v191;

v191:
    v16 = stack[-3];
    v16 = qcdr(v16);
    stack[-3] = v16;
    v16 = stack[-3];
    if (v16 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v16 = stack[-3];
    v16 = qcar(v16);
    v16 = qcar(v16);
    v16 = ncons(v16);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v16 = Lrplacd(nil, stack[0], v16);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v16 = stack[-1];
    v16 = qcdr(v16);
    stack[-1] = v16;
    goto v191;

v83:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v16); }
/* error exit handlers */
v24:
    popv(5);
    return nil;
}



/* Code for reduce!-weights */

static Lisp_Object MS_CDECL CC_reduceKweights(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v46,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-weights");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-weights");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v46,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v46,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v4;
    stack[-4] = v46;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    v160 = stack[-5];
    v25 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v25 = (*qfn2(fn))(qenv(fn), v160, v25);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-2] = v25;
    goto v35;

v35:
    v160 = stack[-5];
    v25 = stack[-4];
    fn = elt(env, 3); /* mv!-domainlist!-!+ */
    v25 = (*qfn2(fn))(qenv(fn), v160, v25);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-1] = v25;
    v160 = stack[-1];
    v25 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v25 = (*qfn2(fn))(qenv(fn), v160, v25);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[0] = v25;
    v160 = stack[0];
    v25 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v25 = (*qfn2(fn))(qenv(fn), v160, v25);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    if (v25 == nil) goto v41;
    v25 = qvalue(elt(env, 1)); /* t */
    stack[-6] = v25;
    v25 = stack[-1];
    stack[-5] = v25;
    v25 = stack[0];
    stack[-2] = v25;
    goto v35;

v41:
    v25 = stack[-6];
    if (!(v25 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v209:
    v160 = stack[-5];
    v25 = stack[-4];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v25 = (*qfn2(fn))(qenv(fn), v160, v25);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[-1] = v25;
    v160 = stack[-1];
    v25 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v25 = (*qfn2(fn))(qenv(fn), v160, v25);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    stack[0] = v25;
    v160 = stack[0];
    v25 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v25 = (*qfn2(fn))(qenv(fn), v160, v25);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-7];
    if (v25 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v25 = stack[-1];
    stack[-5] = v25;
    v25 = stack[0];
    stack[-2] = v25;
    goto v209;
/* error exit handlers */
v229:
    popv(8);
    return nil;
}



/* Code for dv_skel2factor */

static Lisp_Object CC_dv_skel2factor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v46)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v247, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor");
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
    push(nil);
/* copy arguments values to proper place */
    v25 = v46;
    stack[-4] = v0;
/* end of prologue */
    v247 = stack[-4];
    v247 = qcdr(v247);
    if (v247 == nil) goto v8;
    v247 = stack[-4];
    v247 = qcdr(v247);
    v247 = Lsublis(nil, v25, v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-6];
    stack[-5] = v247;
    v247 = stack[-5];
    fn = elt(env, 2); /* st_ad_numsorttree */
    v247 = (*qfn1(fn))(qenv(fn), v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-6];
    stack[-5] = v247;
    v247 = stack[-5];
    v247 = qcdr(v247);
    fn = elt(env, 3); /* st_flatten */
    v247 = (*qfn1(fn))(qenv(fn), v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-6];
    stack[-3] = v247;
    v247 = stack[-3];
    if (v247 == nil) goto v41;
    v247 = stack[-3];
    v247 = qcar(v247);
    fn = elt(env, 4); /* dv_ind2var */
    v247 = (*qfn1(fn))(qenv(fn), v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-6];
    v247 = ncons(v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-6];
    stack[-1] = v247;
    stack[-2] = v247;
    goto v6;

v6:
    v247 = stack[-3];
    v247 = qcdr(v247);
    stack[-3] = v247;
    v247 = stack[-3];
    if (v247 == nil) goto v114;
    stack[0] = stack[-1];
    v247 = stack[-3];
    v247 = qcar(v247);
    fn = elt(env, 4); /* dv_ind2var */
    v247 = (*qfn1(fn))(qenv(fn), v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-6];
    v247 = ncons(v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-6];
    v247 = Lrplacd(nil, stack[0], v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    env = stack[-6];
    v247 = stack[-1];
    v247 = qcdr(v247);
    stack[-1] = v247;
    goto v6;

v114:
    v247 = stack[-2];
    goto v86;

v86:
    v25 = stack[-5];
    stack[0] = qcar(v25);
    v25 = stack[-4];
    v25 = qcar(v25);
    fn = elt(env, 5); /* dv_skel2factor1 */
    v247 = (*qfn2(fn))(qenv(fn), v25, v247);
    nil = C_nil;
    if (exception_pending()) goto v240;
    {
        Lisp_Object v162 = stack[0];
        popv(7);
        return cons(v162, v247);
    }

v41:
    v247 = qvalue(elt(env, 1)); /* nil */
    goto v86;

v8:
    v247 = stack[-4];
    v247 = qcar(v247);
    { popv(7); return onevalue(v247); }
/* error exit handlers */
v240:
    popv(7);
    return nil;
}



setup_type const u36_setup[] =
{
    {"multup",                  CC_multup,      too_many_1,    wrong_no_1},
    {"i2cr*",                   CC_i2crH,       too_many_1,    wrong_no_1},
    {"ldf-simp",                CC_ldfKsimp,    too_many_1,    wrong_no_1},
    {"noncomexpf",              CC_noncomexpf,  too_many_1,    wrong_no_1},
    {"find_triangl_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_triangl_coeff},
    {"greaterpcdr",             too_few_2,      CC_greaterpcdr,wrong_no_2},
    {"mv-compact",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_mvKcompact},
    {"fs:prepfn:",              CC_fsTprepfnT,  too_many_1,    wrong_no_1},
    {"checkdifference",         too_few_2,      CC_checkdifference,wrong_no_2},
    {"ratpoly_tad",             CC_ratpoly_tad, too_many_1,    wrong_no_1},
    {"fnom",                    CC_fnom,        too_many_1,    wrong_no_1},
    {"d2int",                   CC_d2int,       too_many_1,    wrong_no_1},
    {"bfsqrt",                  CC_bfsqrt,      too_many_1,    wrong_no_1},
    {"exptbf",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exptbf},
    {"mod-dump1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modKdump1},
    {"reduce-ratios",           too_few_2,      CC_reduceKratios,wrong_no_2},
    {"rationalizef",            CC_rationalizef,too_many_1,    wrong_no_1},
    {"bc_2a",                   CC_bc_2a,       too_many_1,    wrong_no_1},
    {"split-further",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKfurther},
    {"mksqrt",                  CC_mksqrt,      too_many_1,    wrong_no_1},
    {"totalcompareconstants",   too_few_2,      CC_totalcompareconstants,wrong_no_2},
    {"simp0",                   CC_simp0,       too_many_1,    wrong_no_1},
    {"makecoeffpairs",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs},
    {"pasf_ceil",               too_few_2,      CC_pasf_ceil,  wrong_no_2},
    {"ev_2a",                   CC_ev_2a,       too_many_1,    wrong_no_1},
    {"vdp_setsugar",            too_few_2,      CC_vdp_setsugar,wrong_no_2},
    {"matrixrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrd},
    {"ps:mkpow",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTmkpow},
    {"boolvalue*",              CC_boolvalueH,  too_many_1,    wrong_no_1},
    {"simpdf",                  CC_simpdf,      too_many_1,    wrong_no_1},
    {"simp_without_resimp",     CC_simp_without_resimp,too_many_1,wrong_no_1},
    {"toolongassignp",          CC_toolongassignp,too_many_1,  wrong_no_1},
    {"indordln",                CC_indordln,    too_many_1,    wrong_no_1},
    {"consrecip",               CC_consrecip,   too_many_1,    wrong_no_1},
    {"generic_arguments",       CC_generic_arguments,too_many_1,wrong_no_1},
    {"arminusp:",               CC_arminuspT,   too_many_1,    wrong_no_1},
    {"mkrootsql",               too_few_2,      CC_mkrootsql,  wrong_no_2},
    {"make-modular-symmetric",  CC_makeKmodularKsymmetric,too_many_1,wrong_no_1},
    {"simprd",                  CC_simprd,      too_many_1,    wrong_no_1},
    {"rl_smrmknowl",            too_few_2,      CC_rl_smrmknowl,wrong_no_2},
    {"get_char_group",          CC_get_char_group,too_many_1,  wrong_no_1},
    {"factor-prim-f",           CC_factorKprimKf,too_many_1,   wrong_no_1},
    {"matrixelems",             CC_matrixelems, too_many_1,    wrong_no_1},
    {"scar",                    too_few_2,      CC_scar,       wrong_no_2},
    {"spmatlength",             CC_spmatlength, too_many_1,    wrong_no_1},
    {"sroot1",                  too_few_2,      CC_sroot1,     wrong_no_2},
    {"precision1",              too_few_2,      CC_precision1, wrong_no_2},
    {"r2oreaction",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2oreaction},
    {"cvitimes2",               too_few_2,      CC_cvitimes2,  wrong_no_2},
    {"mapcarcar",               CC_mapcarcar,   too_many_1,    wrong_no_1},
    {"reduce-weights",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKweights},
    {"dv_skel2factor",          too_few_2,      CC_dv_skel2factor,wrong_no_2},
    {NULL, (one_args *)"u36", (two_args *)"22958 1576545 7612191", 0}
};

/* end of generated code */
