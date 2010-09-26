
/* $destdir\u22.c        Machine generated C code */

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


/* Code for drnconv */

static Lisp_Object CC_drnconv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9, v10;
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
    v10 = v0;
/* end of prologue */
    v8 = v10;
    if (v8 == nil) return onevalue(v10);
    v8 = v10;
    if (is_number(v8)) return onevalue(v10);
    v9 = v10;
    v8 = qvalue(elt(env, 1)); /* dmd!* */
    if (!consp(v9)) goto v11;
    v9 = qcar(v9);
    if (v9 == v8) return onevalue(v10);
    else goto v11;

v11:
    v8 = v10;
    v9 = qcar(v8);
    v8 = qvalue(elt(env, 1)); /* dmd!* */
    v8 = get(v9, v8);
    v9 = v8;
    v8 = v9;
    if (v8 == nil) return onevalue(v10);
    v8 = v9;
    if (!(!consp(v8))) return onevalue(v10);
    v8 = v9;
    v9 = v10;
        return Lapply1(nil, v8, v9);
}



/* Code for get!*elements */

static Lisp_Object CC_getHelements(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*elements");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v14 = v0;
/* end of prologue */
    v15 = elt(env, 1); /* elems */
    return get(v14, v15);
}



/* Code for qqe_arg!-check!-q */

static Lisp_Object CC_qqe_argKcheckKq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16;
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
    v16 = stack[0];
    fn = elt(env, 3); /* qqe_id!-nyt!-branchq */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    if (v16 == nil) goto v17;
    v16 = stack[0];
    if (!(!consp(v16))) goto v12;
    v16 = stack[0];
    if (is_number(v16)) goto v12;
    v16 = stack[0];
    fn = elt(env, 4); /* qqe_btidp */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    if (v16 == nil) goto v18;
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v16); }

v18:
    v16 = stack[0];
    fn = elt(env, 5); /* qqe_nytidp */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    if (v16 == nil) goto v19;
    v16 = stack[0];
    fn = elt(env, 6); /* qqe_qtid */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    v16 = stack[0];
    fn = elt(env, 7); /* qqe_add2rollbackids */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    v16 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v16); }

v19:
    v16 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v16); }

v12:
    v16 = stack[0];
    if (is_number(v16)) goto v20;
    v16 = stack[0];
    fn = elt(env, 8); /* qqe_arg!-check */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    v16 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v16); }

v20:
    v16 = nil;
    { popv(2); return onevalue(v16); }

v17:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v16); }
/* error exit handlers */
v1:
    popv(2);
    return nil;
}



/* Code for pasf_subfof1 */

static Lisp_Object MS_CDECL CC_pasf_subfof1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v22, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pasf_subfof1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_subfof1");
#endif
    if (stack >= stacklimit)
    {
        push3(v22,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v22;
    stack[-2] = v21;
    stack[-3] = v0;
/* end of prologue */
    v48 = stack[-3];
    v48 = Lconsp(nil, v48);
    env = stack[-5];
    if (v48 == nil) goto v50;
    v48 = stack[-3];
    v48 = qcar(v48);
    v48 = Lconsp(nil, v48);
    env = stack[-5];
    if (v48 == nil) goto v50;
    v48 = stack[-3];
    v48 = qcar(v48);
    v49 = qcar(v48);
    v48 = elt(env, 1); /* (cong ncong) */
    v48 = Lmemq(nil, v49, v48);
    if (v48 == nil) goto v50;
    v49 = stack[-3];
    v48 = elt(env, 2); /* true */
    if (v49 == v48) goto v51;
    v49 = stack[-3];
    v48 = elt(env, 3); /* false */
    if (v49 == v48) goto v51;
    v48 = stack[-3];
    v48 = qcar(v48);
    v48 = Lconsp(nil, v48);
    env = stack[-5];
    if (v48 == nil) goto v52;
    v48 = stack[-3];
    v48 = qcar(v48);
    v48 = qcar(v48);
    stack[-4] = v48;
    goto v53;

v53:
    v48 = stack[-3];
    v48 = qcar(v48);
    stack[0] = qcdr(v48);
    v49 = stack[-2];
    v48 = stack[-1];
    v48 = cons(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    fn = elt(env, 4); /* subf */
    v48 = (*qfn2(fn))(qenv(fn), stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = qcar(v48);
    v48 = cons(stack[-4], v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    stack[-4] = v48;
    goto v55;

v55:
    v48 = stack[-3];
    v48 = qcdr(v48);
    stack[0] = qcar(v48);
    v49 = stack[-2];
    v48 = stack[-1];
    v48 = cons(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    fn = elt(env, 4); /* subf */
    v48 = (*qfn2(fn))(qenv(fn), stack[0], v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    stack[0] = qcar(v48);
    v48 = stack[-3];
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    stack[-3] = qcar(v48);
    v49 = stack[-2];
    v48 = stack[-1];
    v48 = cons(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    v48 = ncons(v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-5];
    fn = elt(env, 4); /* subf */
    v48 = (*qfn2(fn))(qenv(fn), stack[-3], v48);
    nil = C_nil;
    if (exception_pending()) goto v54;
    v48 = qcar(v48);
    {
        Lisp_Object v56 = stack[-4];
        Lisp_Object v57 = stack[0];
        popv(6);
        return list3(v56, v57, v48);
    }

v52:
    v48 = stack[-3];
    v48 = qcar(v48);
    stack[-4] = v48;
    goto v53;

v51:
    v48 = stack[-3];
    stack[-4] = v48;
    goto v53;

v50:
    v49 = stack[-3];
    v48 = elt(env, 2); /* true */
    if (v49 == v48) goto v58;
    v49 = stack[-3];
    v48 = elt(env, 3); /* false */
    if (v49 == v48) goto v58;
    v48 = stack[-3];
    v48 = qcar(v48);
    v48 = Lconsp(nil, v48);
    env = stack[-5];
    if (v48 == nil) goto v59;
    v48 = stack[-3];
    v48 = qcar(v48);
    v48 = qcar(v48);
    goto v60;

v60:
    stack[-4] = v48;
    goto v55;

v59:
    v48 = stack[-3];
    v48 = qcar(v48);
    goto v60;

v58:
    v48 = stack[-3];
    goto v60;
/* error exit handlers */
v54:
    popv(6);
    return nil;
}



/* Code for ibalp_negatet */

static Lisp_Object CC_ibalp_negatet(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v64, v65;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negatet");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v0;
/* end of prologue */
    v64 = v65;
    v19 = (Lisp_Object)1; /* 0 */
    if (v64 == v19) goto v66;
    v64 = v65;
    v19 = (Lisp_Object)17; /* 1 */
    if (v64 == v19) goto v15;
    v19 = elt(env, 1); /* bnot */
    v64 = v65;
    return list2(v19, v64);

v15:
    v19 = (Lisp_Object)1; /* 0 */
    return onevalue(v19);

v66:
    v19 = (Lisp_Object)17; /* 1 */
    return onevalue(v19);
}



/* Code for bvarml */

static Lisp_Object CC_bvarml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v64;
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
    v19 = elt(env, 1); /* "<bvar>" */
    fn = elt(env, 5); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    v19 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 6); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcar(v19);
    fn = elt(env, 7); /* expression */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcdr(v19);
    v64 = qcar(v19);
    v19 = (Lisp_Object)17; /* 1 */
    if (v64 == v19) goto v12;
    v19 = stack[0];
    v19 = qcdr(v19);
    v19 = qcar(v19);
    v19 = ncons(v19);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    fn = elt(env, 8); /* degreeml */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    goto v12;

v12:
    v19 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 6); /* indent!* */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    v19 = elt(env, 4); /* "</bvar>" */
    fn = elt(env, 5); /* printout */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v19 = nil;
    { popv(2); return onevalue(v19); }
/* error exit handlers */
v67:
    popv(2);
    return nil;
}



/* Code for ps!:expansion!-point */

static Lisp_Object CC_psTexpansionKpoint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v38, v73;
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
    v38 = v0;
/* end of prologue */
    v72 = v38;
    if (!consp(v72)) goto v66;
    v72 = v38;
    v73 = qcar(v72);
    v72 = elt(env, 1); /* !:ps!: */
    if (v73 == v72) goto v19;
    v72 = v38;
    v73 = qcar(v72);
    v72 = elt(env, 2); /* dname */
    v72 = get(v73, v72);
    env = stack[0];
    if (!(v72 == nil)) goto v66;

v19:
    v72 = (Lisp_Object)49; /* 3 */
    {
        popv(1);
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v38, v72);
    }

v66:
    v72 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v72); }
}



/* Code for recaliasbacksubst */

static Lisp_Object CC_recaliasbacksubst(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for recaliasbacksubst");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v21;
    stack[0] = v0;
/* end of prologue */
    v80 = stack[0];
    if (!consp(v80)) goto v71;
    v80 = stack[0];
    fn = elt(env, 2); /* constp */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    if (!(v80 == nil)) goto v71;
    v80 = stack[0];
    stack[-4] = v80;
    v80 = stack[-4];
    if (v80 == nil) goto v1;
    v80 = stack[-4];
    v80 = qcar(v80);
    v81 = v80;
    v80 = stack[-3];
    v80 = CC_recaliasbacksubst(env, v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    stack[-1] = v80;
    stack[-2] = v80;
    goto v82;

v82:
    v80 = stack[-4];
    v80 = qcdr(v80);
    stack[-4] = v80;
    v80 = stack[-4];
    if (v80 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v80 = stack[-4];
    v80 = qcar(v80);
    v81 = v80;
    v80 = stack[-3];
    v80 = CC_recaliasbacksubst(env, v81, v80);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    v80 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    v80 = Lrplacd(nil, stack[0], v80);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-5];
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v82;

v1:
    v80 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v80); }

v71:
    v81 = stack[0];
    v80 = stack[-3];
    v80 = Lassoc(nil, v81, v80);
    if (v80 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v81 = stack[0];
    v80 = stack[-3];
    v80 = Lassoc(nil, v81, v80);
    v80 = qcdr(v80);
    { popv(6); return onevalue(v80); }
/* error exit handlers */
v50:
    popv(6);
    return nil;
}



/* Code for meq */

static Lisp_Object CC_meq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v47, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for meq");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */
    v3 = stack[-1];
    fn = elt(env, 2); /* binding */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    v47 = v3;
    v3 = v47;
    if (v3 == nil) goto v69;
    v3 = v47;
    v61 = elt(env, 1); /* unbound */
    if (v3 == v61) goto v69;
    v3 = v47;
    v47 = v3;
    goto v84;

v84:
    v3 = stack[0];
    v3 = (equal(v47, v3) ? lisp_true : nil);
    { popv(3); return onevalue(v3); }

v69:
    v3 = stack[-1];
    v47 = v3;
    goto v84;
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for groedeletip */

static Lisp_Object CC_groedeletip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groedeletip");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */

v84:
    v89 = stack[0];
    if (v89 == nil) goto v91;
    v90 = stack[-1];
    v89 = stack[0];
    v89 = qcar(v89);
    if (!(equal(v90, v89))) goto v91;
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v84;

v91:
    v89 = stack[0];
    if (v89 == nil) goto v4;
    v89 = stack[0];
    stack[-2] = v89;
    goto v65;

v65:
    v89 = stack[0];
    v89 = qcdr(v89);
    if (v89 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v90 = stack[-1];
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcar(v89);
    if (equal(v90, v89)) goto v44;
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v65;

v44:
    v90 = stack[0];
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    fn = elt(env, 2); /* setcdr */
    v89 = (*qfn2(fn))(qenv(fn), v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    goto v65;

v4:
    v89 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v89); }
/* error exit handlers */
v74:
    popv(4);
    return nil;
}



/* Code for vdpsave */

static Lisp_Object CC_vdpsave(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v88;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpsave");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v88 = v0;
/* end of prologue */
    return onevalue(v88);
}



/* Code for testchar1 */

static Lisp_Object CC_testchar1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93;
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
    v92 = stack[0];
    v92 = integerp(v92);
    if (!(v92 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v92 = stack[0];
    v92 = Lexplodec(nil, v92);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    v92 = qcdr(v92);
    if (v92 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v93 = stack[0];
    v92 = qvalue(elt(env, 1)); /* nochar!* */
    v92 = Lmember(nil, v93, v92);
    if (!(v92 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v93 = stack[0];
    v92 = qvalue(elt(env, 2)); /* nochar1!* */
    v92 = Lmember(nil, v93, v92);
    if (!(v92 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v93 = stack[0];
    v92 = qvalue(elt(env, 2)); /* nochar1!* */
    v92 = cons(v93, v92);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-1];
    qvalue(elt(env, 2)) = v92; /* nochar1!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v8:
    popv(2);
    return nil;
}



/* Code for physopordchk!* */

static Lisp_Object CC_physopordchkH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopordchk*");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */

v108:
    v106 = stack[-1];
    v106 = qcar(v106);
    stack[-4] = v106;
    v106 = stack[-1];
    v106 = qcdr(v106);
    stack[-1] = v106;
    v106 = stack[-1];
    if (v106 == nil) goto v15;
    v106 = stack[-4];
    v107 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v106 = stack[0];
    v106 = CC_physopordchkH(env, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    if (v106 == nil) goto v109;
    v107 = stack[-1];
    v106 = stack[0];
    stack[-1] = v107;
    stack[0] = v106;
    goto v108;

v109:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v106); }

v15:
    v106 = stack[0];
    v106 = qcdr(v106);
    if (v106 == nil) goto v110;
    v106 = stack[0];
    stack[-3] = v106;
    v106 = stack[-3];
    if (v106 == nil) goto v77;
    v106 = stack[-3];
    v106 = qcar(v106);
    v107 = stack[-4];
    fn = elt(env, 3); /* ncmpchk */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    stack[-1] = v106;
    stack[-2] = v106;
    goto v111;

v111:
    v106 = stack[-3];
    v106 = qcdr(v106);
    stack[-3] = v106;
    v106 = stack[-3];
    if (v106 == nil) goto v40;
    stack[0] = stack[-1];
    v106 = stack[-3];
    v106 = qcar(v106);
    v107 = stack[-4];
    fn = elt(env, 3); /* ncmpchk */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v106 = Lrplacd(nil, stack[0], v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    v106 = stack[-1];
    v106 = qcdr(v106);
    stack[-1] = v106;
    goto v111;

v40:
    v106 = stack[-2];
    goto v112;

v112:
    v107 = qvalue(elt(env, 1)); /* nil */
    v106 = Lmember(nil, v107, v106);
    if (v106 == nil) goto v113;
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v106); }

v113:
    v106 = qvalue(elt(env, 2)); /* t */
    { popv(6); return onevalue(v106); }

v77:
    v106 = qvalue(elt(env, 1)); /* nil */
    goto v112;

v110:
    v107 = stack[-4];
    v106 = stack[0];
    v106 = qcar(v106);
    fn = elt(env, 3); /* ncmpchk */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-5];
    if (v106 == nil) goto v114;
    v106 = stack[-4];
    fn = elt(env, 4); /* invp */
    v107 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v25;
    v106 = stack[0];
    v106 = qcar(v106);
    v106 = (equal(v107, v106) ? lisp_true : nil);
    v106 = (v106 == nil ? lisp_true : nil);
    { popv(6); return onevalue(v106); }

v114:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v106); }
/* error exit handlers */
v25:
    popv(6);
    return nil;
}



/* Code for rnprep!: */

static Lisp_Object CC_rnprepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v89, v90;
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
    v117 = stack[-1];
    v117 = qcdr(v117);
    v89 = qcar(v117);
    v117 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* prepf1 */
    v117 = (*qfn2(fn))(qenv(fn), v89, v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    v89 = v117;
    v117 = v89;
    if (v117 == nil) goto v118;
    v117 = v89;
    fn = elt(env, 4); /* replus */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    goto v15;

v15:
    v90 = v117;
    v117 = stack[-1];
    v117 = qcdr(v117);
    v89 = qcdr(v117);
    v117 = (Lisp_Object)17; /* 1 */
    if (v89 == v117) { popv(4); return onevalue(v90); }
    stack[-2] = elt(env, 2); /* quotient */
    stack[0] = v90;
    v117 = stack[-1];
    v117 = qcdr(v117);
    v89 = qcdr(v117);
    v117 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* prepf1 */
    v117 = (*qfn2(fn))(qenv(fn), v89, v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    v89 = v117;
    v117 = v89;
    if (v117 == nil) goto v85;
    v117 = v89;
    fn = elt(env, 4); /* replus */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    goto v2;

v2:
    {
        Lisp_Object v75 = stack[-2];
        Lisp_Object v119 = stack[0];
        popv(4);
        return list3(v75, v119, v117);
    }

v85:
    v117 = (Lisp_Object)1; /* 0 */
    goto v2;

v118:
    v117 = (Lisp_Object)1; /* 0 */
    goto v15;
/* error exit handlers */
v74:
    popv(4);
    return nil;
}



/* Code for ofsf_entry2at1 */

static Lisp_Object MS_CDECL CC_ofsf_entry2at1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v22, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v38, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at1");
#endif
    if (stack >= stacklimit)
    {
        push3(v22,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v21;
    v72 = v0;
/* end of prologue */
    v38 = stack[-1];
    v73 = qcar(v38);
    v38 = v72;
    v72 = elt(env, 1); /* and */
    v72 = (v38 == v72 ? lisp_true : nil);
    fn = elt(env, 3); /* ofsf_clnegrel */
    stack[-2] = (*qfn2(fn))(qenv(fn), v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    v38 = stack[0];
    v72 = stack[-1];
    v72 = qcdr(v72);
    fn = elt(env, 4); /* addsq */
    v72 = (*qfn2(fn))(qenv(fn), v38, v72);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    v72 = qcar(v72);
    v38 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v2 = stack[-2];
        popv(4);
        return list3(v2, v72, v38);
    }
/* error exit handlers */
v16:
    popv(4);
    return nil;
}



/* Code for wusort */

static Lisp_Object CC_wusort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wusort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v116 = v0;
/* end of prologue */
    v13 = v116;
    v116 = elt(env, 1); /* wulessp!* */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v13, v116);
    }
}



/* Code for smemberlp */

static Lisp_Object CC_smemberlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v103;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemberlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */

v108:
    v82 = stack[0];
    if (v82 == nil) goto v20;
    v82 = stack[0];
    if (!consp(v82)) goto v12;
    v103 = stack[-1];
    v82 = stack[0];
    v82 = qcar(v82);
    v82 = CC_smemberlp(env, v103, v82);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-2];
    if (!(v82 == nil)) { popv(3); return onevalue(v82); }
    v103 = stack[-1];
    v82 = stack[0];
    v82 = qcdr(v82);
    stack[-1] = v103;
    stack[0] = v82;
    goto v108;

v12:
    v103 = stack[0];
    v82 = stack[-1];
    v82 = Lmember(nil, v103, v82);
    { popv(3); return onevalue(v82); }

v20:
    v82 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v82); }
/* error exit handlers */
v1:
    popv(3);
    return nil;
}



/* Code for simpexpt11 */

static Lisp_Object MS_CDECL CC_simpexpt11(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v22, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v128, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt11");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt11");
#endif
    if (stack >= stacklimit)
    {
        push3(v22,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v22;
    stack[-2] = v21;
    stack[-3] = v0;
/* end of prologue */
    v127 = qvalue(elt(env, 1)); /* !*precise_complex */
    if (v127 == nil) goto v116;
    v129 = stack[-3];
    v128 = stack[-2];
    v127 = stack[-1];
    {
        popv(6);
        fn = elt(env, 2); /* simpexpt2 */
        return (*qfnn(fn))(qenv(fn), 3, v129, v128, v127);
    }

v116:
    v127 = stack[-2];
    v127 = qcdr(v127);
    if (!consp(v127)) goto v46;
    v127 = stack[-2];
    v127 = qcdr(v127);
    v127 = qcar(v127);
    if (!consp(v127)) goto v46;
    v127 = stack[-2];
    v128 = qcar(v127);
    v127 = stack[-2];
    v127 = qcdr(v127);
    fn = elt(env, 3); /* qremf */
    v127 = (*qfn2(fn))(qenv(fn), v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    stack[-4] = v127;
    v127 = qcar(v127);
    if (v127 == nil) goto v46;
    v127 = stack[-4];
    v127 = qcdr(v127);
    if (v127 == nil) goto v46;
    stack[0] = stack[-3];
    v127 = stack[-4];
    v128 = qcar(v127);
    v127 = (Lisp_Object)17; /* 1 */
    v128 = cons(v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v127 = stack[-1];
    fn = elt(env, 4); /* simpexpt1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, stack[0], v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v127 = stack[-4];
    v128 = qcdr(v127);
    v127 = stack[-2];
    v127 = qcdr(v127);
    v128 = cons(v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v127 = stack[-1];
    fn = elt(env, 4); /* simpexpt1 */
    v127 = (*qfnn(fn))(qenv(fn), 3, stack[-3], v128, v127);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    {
        Lisp_Object v96 = stack[0];
        popv(6);
        fn = elt(env, 5); /* multsq */
        return (*qfn2(fn))(qenv(fn), v96, v127);
    }

v46:
    v129 = stack[-3];
    v128 = stack[-2];
    v127 = stack[-1];
    {
        popv(6);
        fn = elt(env, 2); /* simpexpt2 */
        return (*qfnn(fn))(qenv(fn), 3, v129, v128, v127);
    }
/* error exit handlers */
v95:
    popv(6);
    return nil;
}



/* Code for get!-denom!-l */

static Lisp_Object CC_getKdenomKl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10, v79;
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
    v10 = v0;
/* end of prologue */
    v9 = v10;
    v9 = qcar(v9);
    if (!consp(v9)) goto v66;
    v9 = v10;
    v9 = qcar(v9);
    v9 = qcdr(v9);
    v9 = qcdr(v9);
    goto v88;

v88:
    v10 = qcdr(v10);
    stack[0] = v10;
    goto v120;

v120:
    v10 = stack[0];
    if (v10 == nil) { popv(2); return onevalue(v9); }
    v10 = stack[0];
    v10 = qcar(v10);
    v79 = v10;
    v10 = v9;
    v9 = v79;
    if (!consp(v9)) goto v38;
    v9 = v79;
    v9 = qcdr(v9);
    v9 = qcdr(v9);
    goto v64;

v64:
    fn = elt(env, 2); /* lcmn */
    v9 = (*qfn2(fn))(qenv(fn), v10, v9);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[0] = v10;
    goto v120;

v38:
    v9 = (Lisp_Object)17; /* 1 */
    goto v64;

v66:
    v9 = (Lisp_Object)17; /* 1 */
    goto v88;
/* error exit handlers */
v87:
    popv(2);
    return nil;
}



/* Code for ibalp_readform */

static Lisp_Object CC_ibalp_readform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v133;
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
    v26 = v0;
/* end of prologue */
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-3] = nil;
    v133 = (Lisp_Object)1; /* 0 */
    stack[0] = v133;
    v133 = v26;
    v26 = elt(env, 1); /* and */
    fn = elt(env, 9); /* cl_mkstrict */
    v26 = (*qfn2(fn))(qenv(fn), v133, v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    v26 = qcdr(v26);
    stack[-2] = v26;
    v26 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v26;
    goto v69;

v69:
    v26 = stack[-1];
    if (v26 == nil) goto v114;
    v26 = stack[-2];
    if (v26 == nil) goto v114;
    v26 = stack[-2];
    v26 = qcar(v26);
    v133 = v26;
    v26 = stack[-2];
    v26 = qcdr(v26);
    stack[-2] = v26;
    v26 = stack[-4];
    fn = elt(env, 10); /* ibalp_readclause */
    v26 = (*qfn2(fn))(qenv(fn), v133, v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    stack[-6] = v26;
    v26 = stack[-6];
    v26 = qcar(v26);
    stack[-3] = v26;
    v26 = stack[-6];
    v26 = qcdr(v26);
    stack[-4] = v26;
    v133 = stack[-3];
    v26 = elt(env, 4); /* true */
    if (v133 == v26) goto v69;
    v26 = stack[-3];
    fn = elt(env, 11); /* ibalp_emptyclausep */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    if (v26 == nil) goto v75;
    v26 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v26;
    goto v69;

v75:
    v133 = stack[-3];
    v26 = stack[-5];
    fn = elt(env, 12); /* ibalp_clmember */
    v26 = (*qfn2(fn))(qenv(fn), v133, v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    if (!(v26 == nil)) goto v53;
    v26 = stack[-3];
    fn = elt(env, 13); /* ibalp_redclause */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    if (!(v26 == nil)) goto v53;
    v26 = stack[-6];
    v133 = qcar(v26);
    v26 = stack[-5];
    v26 = cons(v133, v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    stack[-5] = v26;
    goto v69;

v53:
    v26 = stack[-3];
    fn = elt(env, 14); /* ibalp_undoclause */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    v26 = stack[0];
    v26 = add1(v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    stack[0] = v26;
    goto v69;

v114:
    v26 = stack[-1];
    if (v26 == nil) goto v37;
    v26 = stack[-5];
    if (v26 == nil) goto v134;
    v26 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v26 == nil) goto v107;
    v133 = elt(env, 8); /* "Deleted redundant clauses: " */
    v26 = stack[0];
    v26 = list2(v133, v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    goto v107;

v107:
    v133 = stack[-5];
    v26 = stack[-4];
    popv(8);
    return cons(v133, v26);

v134:
    v26 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v26 == nil) goto v135;
    v26 = elt(env, 7); /* "Tautology detected" */
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    goto v135;

v135:
    v26 = qvalue(elt(env, 3)); /* nil */
    popv(8);
    return ncons(v26);

v37:
    v26 = qvalue(elt(env, 5)); /* !*rlverbose */
    if (v26 == nil) goto v129;
    v26 = elt(env, 6); /* "Detected empty clause" */
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    fn = elt(env, 15); /* ioto_tprin2t */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-7];
    goto v129;

v129:
    v26 = stack[-3];
    v26 = ncons(v26);
    nil = C_nil;
    if (exception_pending()) goto v24;
    popv(8);
    return ncons(v26);
/* error exit handlers */
v24:
    popv(8);
    return nil;
}



/* Code for numpoly_lc */

static Lisp_Object CC_numpoly_lc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_lc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v6 = v7;
    if (v6 == nil) return onevalue(v7);
    v6 = v7;
    if (is_number(v6)) return onevalue(v7);
    v7 = qcar(v7);
    v7 = qcdr(v7);
    return onevalue(v7);
}



/* Code for encodeir */

static Lisp_Object CC_encodeir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v46, v8;
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
    v46 = elt(env, 2); /* !  */
    v93 = qvalue(elt(env, 3)); /* atts */
    v93 = cons(v46, v93);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v93 = Lappend(nil, stack[-1], v93);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v46 = elt(env, 4); /* !$ */
    fn = elt(env, 7); /* delall */
    v93 = (*qfn2(fn))(qenv(fn), v46, v93);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    stack[-1] = elt(env, 5); /* semantic */
    v8 = stack[0];
    v46 = v93;
    v93 = qvalue(elt(env, 6)); /* nil */
    v93 = list2star(v8, v46, v93);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v46 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v97 = stack[-1];
        popv(3);
        return list2star(v97, v93, v46);
    }
/* error exit handlers */
v79:
    popv(3);
    return nil;
}



/* Code for insoccs */

static Lisp_Object CC_insoccs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insoccs");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */
    v136 = stack[-1];
    if (symbolp(v136)) goto v11;
    v136 = stack[-1];
    fn = elt(env, 2); /* subscriptedvarp */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    if (!(v136 == nil)) goto v11;
    v136 = stack[-1];
    v136 = Lconsp(nil, v136);
    env = stack[-2];
    if (v136 == nil) goto v17;
    v136 = stack[-1];
    v136 = qcar(v136);
    fn = elt(env, 2); /* subscriptedvarp */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    if (!(v136 == nil)) goto v11;

v17:
    v136 = stack[-1];
    if (symbolp(v136)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v136 = stack[-1];
    fn = elt(env, 3); /* constp */
    v136 = (*qfn1(fn))(qenv(fn), v136);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    if (!(v136 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v136 = stack[-1];
    v136 = qcdr(v136);
    stack[-1] = v136;
    goto v51;

v51:
    v136 = stack[-1];
    if (v136 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v136 = stack[-1];
    v136 = qcar(v136);
    v86 = v136;
    v136 = stack[0];
    v136 = CC_insoccs(env, v86, v136);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    stack[0] = v136;
    v136 = stack[-1];
    v136 = qcdr(v136);
    stack[-1] = v136;
    goto v51;

v11:
    v86 = stack[0];
    v136 = stack[-1];
    fn = elt(env, 4); /* insertocc */
    v136 = (*qfn2(fn))(qenv(fn), v86, v136);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    stack[0] = v136;
    goto v17;
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for embed!-null!-fn */

static Lisp_Object CC_embedKnullKfn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v127, v128;
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
    v127 = v0;
/* end of prologue */
    v123 = v127;
    if (!consp(v123)) { popv(5); return onevalue(v127); }
    v123 = v127;
    stack[-3] = v123;
    goto v118;

v118:
    v123 = stack[-3];
    if (v123 == nil) goto v18;
    v123 = stack[-3];
    v123 = qcar(v123);
    v128 = v123;
    v123 = v128;
    if (!consp(v123)) goto v4;
    v123 = v128;
    v127 = qcar(v123);
    v123 = elt(env, 2); /* null!-fn */
    if (v127 == v123) goto v19;
    v123 = v128;
    v123 = CC_embedKnullKfn(env, v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    goto v110;

v110:
    stack[-2] = v123;
    v123 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    stack[-1] = v123;
    v123 = stack[-3];
    v123 = qcdr(v123);
    stack[-3] = v123;
    v123 = stack[-1];
    if (!consp(v123)) goto v118;
    else goto v71;

v71:
    v123 = stack[-3];
    if (v123 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v123 = stack[-3];
    v123 = qcar(v123);
    v128 = v123;
    v123 = v128;
    if (!consp(v123)) goto v119;
    v123 = v128;
    v127 = qcar(v123);
    v123 = elt(env, 2); /* null!-fn */
    if (v127 == v123) goto v125;
    v123 = v128;
    v123 = CC_embedKnullKfn(env, v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    goto v117;

v117:
    v123 = Lrplacd(nil, stack[0], v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    v123 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    stack[-1] = v123;
    v123 = stack[-3];
    v123 = qcdr(v123);
    stack[-3] = v123;
    goto v71;

v125:
    v123 = v128;
    v123 = qcdr(v123);
    v123 = CC_embedKnullKfn(env, v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    goto v117;

v119:
    v123 = v128;
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    goto v117;

v19:
    v123 = v128;
    v123 = qcdr(v123);
    v123 = CC_embedKnullKfn(env, v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    goto v110;

v4:
    v123 = v128;
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    goto v110;

v18:
    v123 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v123); }
/* error exit handlers */
v35:
    popv(5);
    return nil;
}



/* Code for mk!-numr */

static Lisp_Object MS_CDECL CC_mkKnumr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v22, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk-numr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-numr");
#endif
    if (stack >= stacklimit)
    {
        push3(v22,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v22;
    stack[-1] = v21;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v12;

v12:
    v44 = stack[-1];
    v111 = stack[0];
    if (equal(v44, v111)) goto v116;
    v44 = stack[-1];
    v111 = (Lisp_Object)1; /* 0 */
    if (v44 == v111) goto v3;
    v45 = elt(env, 1); /* difference */
    v44 = stack[-2];
    v111 = stack[-1];
    v111 = list3(v45, v44, v111);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v44 = v111;
    goto v69;

v69:
    v111 = stack[-3];
    v111 = cons(v44, v111);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    stack[-3] = v111;
    v111 = stack[-1];
    v111 = add1(v111);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    stack[-1] = v111;
    goto v12;

v3:
    v111 = stack[-2];
    v44 = v111;
    goto v69;

v116:
    v111 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v111);
    }
/* error exit handlers */
v137:
    popv(5);
    return nil;
}



/* Code for one!-entryp */

static Lisp_Object CC_oneKentryp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v2;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for one-entryp");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */

v20:
    v16 = stack[0];
    if (!consp(v16)) goto v84;
    v2 = stack[-1];
    v16 = stack[0];
    v16 = qcar(v16);
    v16 = Lsmemq(nil, v2, v16);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    if (v16 == nil) goto v73;
    v2 = stack[-1];
    v16 = stack[0];
    v16 = qcdr(v16);
    v16 = Lsmemq(nil, v2, v16);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-2];
    if (v16 == nil) goto v67;
    v16 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v16); }

v67:
    v16 = stack[0];
    v16 = qcar(v16);
    stack[0] = v16;
    goto v20;

v73:
    v16 = stack[0];
    v16 = qcdr(v16);
    stack[0] = v16;
    goto v20;

v84:
    v16 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v16); }
/* error exit handlers */
v93:
    popv(3);
    return nil;
}



/* Code for nzero */

static Lisp_Object CC_nzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v47;
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
    goto v116;

v116:
    v47 = stack[0];
    v3 = (Lisp_Object)1; /* 0 */
    if (v47 == v3) goto v84;
    v47 = (Lisp_Object)1; /* 0 */
    v3 = stack[-1];
    v3 = cons(v47, v3);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[-1] = v3;
    v3 = stack[0];
    v3 = sub1(v3);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    stack[0] = v3;
    goto v116;

v84:
    v3 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v3);
    }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for moid_member */

static Lisp_Object CC_moid_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moid_member");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */

v108:
    v47 = stack[0];
    if (v47 == nil) goto v20;
    v47 = stack[0];
    v61 = qcar(v47);
    v47 = stack[-1];
    fn = elt(env, 2); /* mo_vdivides!? */
    v47 = (*qfn2(fn))(qenv(fn), v61, v47);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    if (!(v47 == nil)) { popv(3); return onevalue(v47); }
    v61 = stack[-1];
    v47 = stack[0];
    v47 = qcdr(v47);
    stack[-1] = v61;
    stack[0] = v47;
    goto v108;

v20:
    v47 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v47); }
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for dv_ind2var */

static Lisp_Object CC_dv_ind2var(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v64;
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
    v19 = qvalue(elt(env, 1)); /* g_dvnames */
    fn = elt(env, 3); /* upbve */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v19 = (Lisp_Object)lesseq2(stack[-1], v19);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v19 = v19 ? lisp_true : nil;
    env = stack[-2];
    if (v19 == nil) goto v70;
    stack[-1] = qvalue(elt(env, 1)); /* g_dvnames */
    v19 = stack[0];
    v19 = sub1(v19);
    nil = C_nil;
    if (exception_pending()) goto v68;
    v19 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v19/(16/CELL)));
    { popv(3); return onevalue(v19); }

v70:
    v64 = qvalue(elt(env, 2)); /* g_dvbase */
    v19 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v64, v19);
    }
/* error exit handlers */
v68:
    popv(3);
    return nil;
}



/* Code for ratminus */

static Lisp_Object CC_ratminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
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
    v14 = stack[0];
    v14 = qcar(v14);
    v15 = negate(v14);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v14 = stack[0];
    v14 = qcdr(v14);
    popv(1);
    return cons(v15, v14);
/* error exit handlers */
v71:
    popv(1);
    return nil;
}



/* Code for cl_flip */

static Lisp_Object CC_cl_flip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v36, v37;
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
    v37 = v0;
/* end of prologue */
    v36 = v37;
    v99 = elt(env, 1); /* and */
    if (v36 == v99) goto v66;
    v36 = v37;
    v99 = elt(env, 2); /* or */
    if (v36 == v99) goto v15;
    v36 = v37;
    v99 = elt(env, 3); /* all */
    if (v36 == v99) goto v83;
    v36 = v37;
    v99 = elt(env, 4); /* ex */
    if (v36 == v99) goto v19;
    v36 = v37;
    v99 = elt(env, 5); /* ball */
    if (v36 == v99) goto v103;
    v36 = v37;
    v99 = elt(env, 6); /* bex */
    if (v36 == v99) goto v79;
    v36 = v37;
    v99 = elt(env, 7); /* true */
    if (v36 == v99) goto v137;
    v36 = v37;
    v99 = elt(env, 8); /* false */
    if (v36 == v99) goto v53;
    v99 = qvalue(elt(env, 9)); /* !*protfg */
    if (!(v99 == nil)) goto v42;
    v99 = elt(env, 10); /* "cl_flip(): don't know" */
    v36 = v37;
    v99 = list2(v99, v36);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[0];
    fn = elt(env, 11); /* lprie */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[0];
    goto v42;

v42:
    v99 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v123;
    v99 = nil;
    { popv(1); return onevalue(v99); }

v53:
    v99 = elt(env, 7); /* true */
    { popv(1); return onevalue(v99); }

v137:
    v99 = elt(env, 8); /* false */
    { popv(1); return onevalue(v99); }

v79:
    v99 = elt(env, 5); /* ball */
    { popv(1); return onevalue(v99); }

v103:
    v99 = elt(env, 6); /* bex */
    { popv(1); return onevalue(v99); }

v19:
    v99 = elt(env, 3); /* all */
    { popv(1); return onevalue(v99); }

v83:
    v99 = elt(env, 4); /* ex */
    { popv(1); return onevalue(v99); }

v15:
    v99 = elt(env, 1); /* and */
    { popv(1); return onevalue(v99); }

v66:
    v99 = elt(env, 2); /* or */
    { popv(1); return onevalue(v99); }
/* error exit handlers */
v123:
    popv(1);
    return nil;
}



/* Code for width */

static Lisp_Object CC_width(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v136, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for width");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    v136 = v0;
/* end of prologue */
    v86 = v136;
    v137 = elt(env, 1); /* textag */
    v137 = get(v86, v137);
    env = stack[-2];
    stack[-1] = v137;
    v137 = stack[-1];
    if (!(v137 == nil)) goto v82;
    v137 = elt(env, 2); /* "cannot find item " */
    v136 = list2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    v137 = elt(env, 3); /* fatal */
    fn = elt(env, 5); /* tri!-error */
    v137 = (*qfn2(fn))(qenv(fn), v136, v137);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    goto v82;

v82:
    v136 = stack[0];
    v137 = (Lisp_Object)1; /* 0 */
    v137 = (Lisp_Object)greaterp2(v136, v137);
    nil = C_nil;
    if (exception_pending()) goto v52;
    v137 = v137 ? lisp_true : nil;
    env = stack[-2];
    if (v137 == nil) goto v64;
    v137 = stack[-1];
    v137 = qcdr(v137);
    if (v137 == nil) goto v64;
    v137 = stack[-1];
    v137 = qcdr(v137);
    stack[-1] = v137;
    v137 = stack[0];
    v137 = sub1(v137);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    stack[0] = v137;
    goto v82;

v64:
    v137 = stack[-1];
    v137 = qcar(v137);
    if (!(v137 == nil)) { popv(3); return onevalue(v137); }
    v137 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v137); }
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for !*tayexp2q */

static Lisp_Object CC_Htayexp2q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v4;
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
    v110 = v0;
/* end of prologue */
    v4 = v110;
    if (!consp(v4)) goto v84;
    v110 = qcdr(v110);
    { popv(1); return onevalue(v110); }

v84:
    v4 = v110;
    v4 = (Lisp_Object)zerop(v4);
    v4 = v4 ? lisp_true : nil;
    env = stack[0];
    if (v4 == nil) goto v18;
    v110 = qvalue(elt(env, 1)); /* nil */
    v4 = v110;
    goto v116;

v116:
    v110 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v4, v110);

v18:
    v4 = v110;
    goto v116;
}



/* Code for mk!+trace */

static Lisp_Object CC_mkLtrace(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v101, v74;
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
    v100 = stack[-1];
    fn = elt(env, 6); /* squared!+matrix!+p */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    if (!(v100 == nil)) goto v11;
    v100 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v100 == nil)) goto v118;
    v100 = elt(env, 2); /* "no square matrix in add" */
    fn = elt(env, 7); /* lprie */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    goto v118;

v118:
    v100 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    goto v11;

v11:
    v101 = qvalue(elt(env, 3)); /* nil */
    v100 = (Lisp_Object)17; /* 1 */
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[0] = v100;
    v100 = (Lisp_Object)17; /* 1 */
    stack[-2] = v100;
    goto v73;

v73:
    v100 = stack[-1];
    fn = elt(env, 8); /* get!+row!+nr */
    v101 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    v100 = stack[-2];
    v100 = difference2(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    v100 = Lminusp(nil, v100);
    env = stack[-3];
    if (v100 == nil) goto v44;
    v100 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v100; /* !*sub2 */
    v100 = stack[0];
    fn = elt(env, 9); /* subs2 */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    stack[0] = v100;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v44:
    v74 = stack[-1];
    v101 = stack[-2];
    v100 = stack[-2];
    fn = elt(env, 10); /* get!+mat!+entry */
    v100 = (*qfnn(fn))(qenv(fn), 3, v74, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    fn = elt(env, 11); /* addsq */
    v100 = (*qfn2(fn))(qenv(fn), stack[0], v100);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[0] = v100;
    v100 = stack[-2];
    v100 = add1(v100);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[-2] = v100;
    goto v73;
/* error exit handlers */
v41:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(4);
    return nil;
v40:
    popv(4);
    return nil;
}



/* Code for ibalp_var!-unset */

static Lisp_Object CC_ibalp_varKunset(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-unset");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v21;
    stack[-4] = v0;
/* end of prologue */
    v148 = stack[-4];
    v149 = qcdr(v148);
    v148 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    v148 = stack[-4];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v149 = qcdr(v148);
    v148 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* setcar */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    v148 = stack[-4];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v149 = qcdr(v148);
    v148 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    v148 = stack[-4];
    v148 = qcar(v148);
    stack[-5] = v148;
    v149 = stack[-3];
    v148 = (Lisp_Object)17; /* 1 */
    v148 = Leqn(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    if (v148 == nil) goto v136;
    v148 = stack[-4];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    goto v93;

v93:
    stack[-2] = v148;
    goto v53;

v53:
    v148 = stack[-2];
    if (v148 == nil) goto v30;
    v148 = stack[-2];
    v148 = qcar(v148);
    stack[-1] = v148;
    v149 = stack[-3];
    v148 = (Lisp_Object)17; /* 1 */
    v148 = Leqn(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    if (v148 == nil) goto v96;
    v148 = stack[-1];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    stack[0] = qcdr(v148);
    v148 = stack[-1];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    v148 = add1(v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    goto v124;

v124:
    v148 = stack[-2];
    v148 = qcdr(v148);
    stack[-2] = v148;
    goto v53;

v96:
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[0] = qcdr(v148);
    v148 = stack[-1];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    v148 = add1(v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    goto v124;

v30:
    v149 = stack[-3];
    v148 = (Lisp_Object)1; /* 0 */
    v148 = Leqn(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    if (v148 == nil) goto v106;
    v148 = stack[-4];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    goto v25;

v25:
    v149 = v148;
    v148 = stack[-5];
    fn = elt(env, 3); /* ibalp_unvar!-unsatlist */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    v148 = stack[-4];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    stack[0] = qcdr(v148);
    v148 = stack[-4];
    fn = elt(env, 4); /* ibalp_calcmom */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v148 = (*qfn2(fn))(qenv(fn), stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v150;
    v148 = nil;
    { popv(7); return onevalue(v148); }

v106:
    v148 = stack[-4];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    goto v25;

v136:
    v148 = stack[-4];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    goto v93;
/* error exit handlers */
v150:
    popv(7);
    return nil;
}



/* Code for ev_invlexcomp */

static Lisp_Object CC_ev_invlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v43;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_invlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */

v108:
    v42 = stack[-1];
    if (v42 == nil) goto v84;
    v42 = stack[-1];
    v43 = qcar(v42);
    v42 = stack[0];
    v42 = qcar(v42);
    v42 = Leqn(nil, v43, v42);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    if (v42 == nil) goto v67;
    v42 = stack[-1];
    v43 = qcdr(v42);
    v42 = stack[0];
    v42 = qcdr(v42);
    stack[-1] = v43;
    stack[0] = v42;
    goto v108;

v67:
    v42 = stack[-1];
    v43 = qcdr(v42);
    v42 = stack[0];
    v42 = qcdr(v42);
    v42 = CC_ev_invlexcomp(env, v43, v42);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    stack[-2] = v42;
    v43 = stack[-2];
    v42 = (Lisp_Object)1; /* 0 */
    v42 = Leqn(nil, v43, v42);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    if (v42 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v42 = stack[0];
    v43 = qcar(v42);
    v42 = stack[-1];
    v42 = qcar(v42);
    v42 = Leqn(nil, v43, v42);
    nil = C_nil;
    if (exception_pending()) goto v33;
    if (v42 == nil) goto v75;
    v42 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v42); }

v75:
    v42 = stack[0];
    v43 = qcar(v42);
    v42 = stack[-1];
    v42 = qcar(v42);
    if (((int32_t)(v43)) > ((int32_t)(v42))) goto v101;
    v42 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v42); }

v101:
    v42 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v42); }

v84:
    v42 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v42); }
/* error exit handlers */
v33:
    popv(4);
    return nil;
}



/* Code for row */

static Lisp_Object CC_row(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71;
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
    v71 = stack[0];
    if (v71 == nil) goto v20;
    v71 = stack[0];
    v71 = qcar(v71);
    fn = elt(env, 2); /* expression */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-1];
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = CC_row(env, v71);
    nil = C_nil;
    if (exception_pending()) goto v6;
    goto v20;

v20:
    v71 = nil;
    { popv(2); return onevalue(v71); }
/* error exit handlers */
v6:
    popv(2);
    return nil;
}



/* Code for evalvars */

static Lisp_Object CC_evalvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v153;
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
    goto v20;

v20:
    v152 = stack[-1];
    if (v152 == nil) goto v84;
    v152 = stack[-1];
    v152 = qcar(v152);
    if (!consp(v152)) goto v5;
    v152 = stack[-1];
    v152 = qcar(v152);
    v153 = qcar(v152);
    v152 = elt(env, 1); /* intfn */
    v152 = Lflagp(nil, v153, v152);
    env = stack[-3];
    if (!(v152 == nil)) goto v5;
    v152 = stack[-1];
    v152 = qcar(v152);
    v153 = qcar(v152);
    v152 = elt(env, 2); /* rtype */
    v153 = get(v153, v152);
    env = stack[-3];
    v152 = elt(env, 3); /* setelemfn */
    v152 = get(v153, v152);
    env = stack[-3];
    if (v152 == nil) goto v154;
    v152 = stack[-1];
    v152 = qcar(v152);
    stack[0] = qcar(v152);
    v152 = stack[-1];
    v152 = qcar(v152);
    v152 = qcdr(v152);
    fn = elt(env, 4); /* revlis_without_mode */
    v153 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v152 = stack[-2];
    v152 = acons(stack[0], v153, v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[-2] = v152;
    v152 = stack[-1];
    v152 = qcdr(v152);
    stack[-1] = v152;
    goto v20;

v154:
    v152 = stack[-1];
    v152 = qcar(v152);
    stack[0] = qcar(v152);
    v152 = stack[-1];
    v152 = qcar(v152);
    v152 = qcdr(v152);
    fn = elt(env, 5); /* revlis */
    v153 = (*qfn1(fn))(qenv(fn), v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v152 = stack[-2];
    v152 = acons(stack[0], v153, v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[-2] = v152;
    v152 = stack[-1];
    v152 = qcdr(v152);
    stack[-1] = v152;
    goto v20;

v5:
    v152 = stack[-1];
    v153 = qcar(v152);
    v152 = stack[-2];
    v152 = cons(v153, v152);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[-2] = v152;
    v152 = stack[-1];
    v152 = qcdr(v152);
    stack[-1] = v152;
    goto v20;

v84:
    v152 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v152);
    }
/* error exit handlers */
v98:
    popv(4);
    return nil;
}



/* Code for bcfd */

static Lisp_Object CC_bcfd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v79, v97;
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
    v97 = v0;
/* end of prologue */
    v10 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v10 == nil) goto v84;
    v10 = v97;
    v10 = integerp(v10);
    if (v10 == nil) goto v11;
    v10 = v97;
    {
        popv(1);
        fn = elt(env, 5); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v10);
    }

v11:
    v10 = v97;
    v79 = qcar(v10);
    v10 = elt(env, 2); /* !:mod!: */
    if (v79 == v10) goto v92;
    v10 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v10 == nil)) goto v19;
    v10 = elt(env, 4); /* "Invalid modular coefficient" */
    v79 = v97;
    v10 = list2(v10, v79);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    fn = elt(env, 6); /* lprie */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    goto v19;

v19:
    v10 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v87;
    v10 = nil;
    { popv(1); return onevalue(v10); }

v92:
    v10 = v97;
    v10 = qcdr(v10);
    {
        popv(1);
        fn = elt(env, 5); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v10);
    }

v84:
    v79 = v97;
    v10 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 7); /* mkbc */
        return (*qfn2(fn))(qenv(fn), v79, v10);
    }
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



/* Code for dipprod */

static Lisp_Object CC_dipprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipprod");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */
    v64 = stack[-1];
    fn = elt(env, 1); /* diplength */
    stack[-2] = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    v64 = stack[0];
    fn = elt(env, 1); /* diplength */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    v64 = (Lisp_Object)lesseq2(stack[-2], v64);
    nil = C_nil;
    if (exception_pending()) goto v38;
    v64 = v64 ? lisp_true : nil;
    env = stack[-3];
    if (v64 == nil) goto v110;
    v65 = stack[-1];
    v64 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* dipprodin */
        return (*qfn2(fn))(qenv(fn), v65, v64);
    }

v110:
    v65 = stack[0];
    v64 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* dipprodin */
        return (*qfn2(fn))(qenv(fn), v65, v64);
    }
/* error exit handlers */
v38:
    popv(4);
    return nil;
}



/* Code for ordexp */

static Lisp_Object CC_ordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v46, v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v21;
    v8 = v0;
/* end of prologue */

v20:
    v93 = v8;
    if (v93 == nil) goto v84;
    v93 = v8;
    v9 = qcar(v93);
    v93 = v46;
    v93 = qcar(v93);
    if (v9 == v93) goto v12;
    v93 = v8;
    v93 = qcar(v93);
    if (v93 == nil) goto v70;
    v93 = v46;
    v93 = qcar(v93);
    if (v93 == nil) goto v47;
    v93 = v8;
    v93 = qcar(v93);
    v46 = qcar(v46);
    {
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v93, v46);
    }

v47:
    v93 = qvalue(elt(env, 1)); /* t */
    return onevalue(v93);

v70:
    v93 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v93);

v12:
    v93 = v8;
    v93 = qcdr(v93);
    v8 = v93;
    v93 = v46;
    v93 = qcdr(v93);
    v46 = v93;
    goto v20;

v84:
    v93 = qvalue(elt(env, 1)); /* t */
    return onevalue(v93);
}



/* Code for partitexdf */

static Lisp_Object CC_partitexdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
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
    v17 = v0;
/* end of prologue */
    v17 = qcar(v17);
    fn = elt(env, 1); /* partitop */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* exdfpf */
        return (*qfn1(fn))(qenv(fn), v17);
    }
/* error exit handlers */
v91:
    popv(1);
    return nil;
}



/* Code for difference!: */

static Lisp_Object CC_differenceT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v160, v130;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference:");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v21;
    v130 = v0;
/* end of prologue */
    v159 = v130;
    v159 = qcdr(v159);
    v160 = qcar(v159);
    stack[-1] = v160;
    v159 = (Lisp_Object)1; /* 0 */
    if (v160 == v159) goto v83;
    v159 = stack[-2];
    v159 = qcdr(v159);
    v160 = qcar(v159);
    stack[0] = v160;
    v159 = (Lisp_Object)1; /* 0 */
    if (v160 == v159) { popv(6); return onevalue(v130); }
    v159 = v130;
    v159 = qcdr(v159);
    v160 = qcdr(v159);
    stack[-4] = v160;
    v159 = stack[-2];
    v159 = qcdr(v159);
    v159 = qcdr(v159);
    stack[-2] = v159;
    v160 = difference2(v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    stack[-3] = v160;
    v159 = (Lisp_Object)1; /* 0 */
    if (v160 == v159) goto v89;
    v160 = stack[-3];
    v159 = (Lisp_Object)1; /* 0 */
    v159 = (Lisp_Object)greaterp2(v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v159 = v159 ? lisp_true : nil;
    env = stack[-5];
    if (v159 == nil) goto v161;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v160 = stack[-1];
    v159 = stack[-3];
    v160 = Lash1(nil, v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v159 = stack[0];
    v160 = difference2(v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v159 = stack[-2];
    {
        Lisp_Object v143 = stack[-4];
        popv(6);
        return list2star(v143, v160, v159);
    }

v161:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v159 = stack[-3];
    v159 = negate(v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v159 = Lash1(nil, stack[0], v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-5];
    v160 = difference2(stack[-1], v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v159 = stack[-4];
    {
        Lisp_Object v162 = stack[-2];
        popv(6);
        return list2star(v162, v160, v159);
    }

v89:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v160 = stack[-1];
    v159 = stack[0];
    v160 = difference2(v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v159 = stack[-4];
    {
        Lisp_Object v27 = stack[-2];
        popv(6);
        return list2star(v27, v160, v159);
    }

v83:
    stack[0] = elt(env, 1); /* !:rd!: */
    v159 = stack[-2];
    v159 = qcdr(v159);
    v159 = qcar(v159);
    v160 = negate(v159);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v159 = stack[-2];
    v159 = qcdr(v159);
    v159 = qcdr(v159);
    {
        Lisp_Object v28 = stack[0];
        popv(6);
        return list2star(v28, v160, v159);
    }
/* error exit handlers */
v142:
    popv(6);
    return nil;
}



/* Code for gparg1p */

static Lisp_Object CC_gparg1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18;
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

v108:
    v18 = stack[0];
    v18 = (v18 == nil ? lisp_true : nil);
    if (!(v18 == nil)) { popv(2); return onevalue(v18); }
    v18 = stack[0];
    v18 = qcar(v18);
    fn = elt(env, 2); /* gpargp */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    if (v18 == nil) goto v121;
    v18 = stack[0];
    v18 = qcdr(v18);
    stack[0] = v18;
    goto v108;

v121:
    v18 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v18); }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for permp */

static Lisp_Object CC_permp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10, v79, v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for permp");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v10 = v21;
    v79 = v0;
/* end of prologue */

v20:
    v9 = v79;
    if (v9 == nil) goto v84;
    v9 = v79;
    v97 = qcar(v9);
    v9 = v10;
    v9 = qcar(v9);
    if (equal(v97, v9)) goto v12;
    v9 = v79;
    stack[0] = qcdr(v9);
    v9 = v10;
    v9 = qcar(v9);
    v79 = qcar(v79);
    v10 = qcdr(v10);
    v9 = Lsubst(nil, 3, v9, v79, v10);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    v9 = CC_permp(env, stack[0], v9);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v9 = (v9 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v9); }

v12:
    v9 = v79;
    v9 = qcdr(v9);
    v79 = v9;
    v9 = v10;
    v9 = qcdr(v9);
    v10 = v9;
    goto v20;

v84:
    v9 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v9); }
/* error exit handlers */
v111:
    popv(2);
    return nil;
}



/* Code for ordop2 */

static Lisp_Object CC_ordop2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v2, v1, v92, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordop2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v92 = v21;
    v93 = v0;
/* end of prologue */
    v16 = qvalue(elt(env, 1)); /* kord!* */
    v1 = v16;
    goto v17;

v17:
    v16 = v1;
    if (v16 == nil) goto v15;
    v2 = v93;
    v16 = v1;
    v16 = qcar(v16);
    if (v2 == v16) goto v63;
    v2 = v92;
    v16 = v1;
    v16 = qcar(v16);
    if (v2 == v16) goto v47;
    v16 = v1;
    v16 = qcdr(v16);
    v1 = v16;
    goto v17;

v47:
    v16 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v16);

v63:
    v16 = qvalue(elt(env, 2)); /* t */
    return onevalue(v16);

v15:
    v16 = v93;
    v2 = v92;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v16, v2);
    }
}



/* Code for lastcar */

static Lisp_Object CC_lastcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lastcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v63 = v0;
/* end of prologue */

v66:
    v62 = v63;
    if (v62 == nil) goto v91;
    v62 = v63;
    v62 = qcdr(v62);
    if (v62 == nil) goto v13;
    v63 = qcdr(v63);
    goto v66;

v13:
    v63 = qcar(v63);
    return onevalue(v63);

v91:
    v63 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v63);
}



/* Code for red_topredbe */

static Lisp_Object CC_red_topredbe(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_topredbe");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v21;
    stack[-2] = v0;
/* end of prologue */
    v117 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    if (v117 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v117 = stack[-2];
    if (v117 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    fn = elt(env, 4); /* cali_trace */
    v89 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v117 = (Lisp_Object)1265; /* 79 */
    v117 = (Lisp_Object)greaterp2(v89, v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v117 = v117 ? lisp_true : nil;
    env = stack[-4];
    if (v117 == nil) goto v72;
    v117 = elt(env, 1); /* " reduce " */
    v117 = Lprinc(nil, v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v117 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    fn = elt(env, 5); /* dp_print */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    goto v72;

v72:
    v117 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v89 = v117;
    if (v117 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    stack[-3] = stack[-2];
    v117 = v89;
    fn = elt(env, 6); /* dp_lmon */
    stack[0] = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v117 = stack[-1];
    fn = elt(env, 7); /* bas_dpecart */
    v117 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    fn = elt(env, 8); /* red_divtestbe */
    v89 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    v117 = v89;
    if (v89 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v89 = stack[-1];
    fn = elt(env, 9); /* red_subst */
    v117 = (*qfn2(fn))(qenv(fn), v89, v117);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-4];
    stack[-1] = v117;
    goto v72;
/* error exit handlers */
v74:
    popv(5);
    return nil;
}



/* Code for nf */

static Lisp_Object MS_CDECL CC_nf(Lisp_Object env, int nargs,
                         Lisp_Object v21, Lisp_Object v22,
                         Lisp_Object v88, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v186, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "nf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nf");
#endif
    if (stack >= stacklimit)
    {
        push3(v88,v22,v21);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v21,v22,v88);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v88;
    v185 = v22;
    v186 = v21;
/* end of prologue */
    stack[-10] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v185; /* gg */
    v185 = qvalue(elt(env, 1)); /* gg */
    if (v185 == nil) goto v13;
    stack[-3] = nil;
    v185 = (Lisp_Object)1; /* 0 */
    stack[0] = v185;
    v185 = v186;
    stack[-8] = v185;
    v185 = qvalue(elt(env, 1)); /* gg */
    stack[-2] = v185;
    goto v5;

v5:
    v185 = stack[-8];
    if (v185 == nil) goto v188;
    v185 = stack[-8];
    v185 = qcar(v185);
    v185 = qcar(v185);
    stack[-7] = v185;
    goto v16;

v16:
    v185 = stack[-2];
    if (v185 == nil) goto v103;
    v186 = stack[-7];
    v185 = stack[-2];
    v185 = qcar(v185);
    v185 = qcdr(v185);
    fn = elt(env, 13); /* dless */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    if (v185 == nil) goto v103;
    v185 = stack[-2];
    v185 = qcdr(v185);
    stack[-2] = v185;
    goto v16;

v103:
    v185 = stack[-2];
    if (v185 == nil) goto v188;
    v185 = stack[-2];
    stack[-1] = v185;
    goto v53;

v53:
    v185 = stack[-1];
    if (v185 == nil) goto v90;
    v185 = stack[-1];
    v185 = qcar(v185);
    v186 = qcdr(v185);
    v185 = stack[-7];
    fn = elt(env, 14); /* dd */
    stack[-4] = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v186 = stack[-9];
    v185 = (Lisp_Object)33; /* 2 */
    v185 = plus2(v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    if (!(((int32_t)(stack[-4])) < ((int32_t)(v185)))) goto v90;
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    goto v53;

v90:
    v185 = stack[-1];
    if (v185 == nil) goto v112;
    v186 = qvalue(elt(env, 4)); /* gv */
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = qcar(v185);
    v185 = *(Lisp_Object *)((char *)v186 + (CELL-TAG_VECTOR) + ((int32_t)v185/(16/CELL)));
    stack[-6] = v185;
    v185 = stack[-8];
    v185 = qcar(v185);
    v186 = qcdr(v185);
    v185 = stack[-6];
    v185 = qcar(v185);
    v185 = qcdr(v185);
    fn = elt(env, 15); /* gcdf!* */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-4] = v185;
    v185 = stack[-8];
    v185 = qcar(v185);
    v186 = qcdr(v185);
    v185 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-5] = v185;
    v185 = stack[-6];
    v185 = qcar(v185);
    v186 = qcdr(v185);
    v185 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-4] = v185;
    v186 = stack[-8];
    v185 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-8] = v185;
    v186 = stack[-3];
    v185 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-3] = v185;
    v186 = stack[-6];
    v185 = stack[-5];
    fn = elt(env, 17); /* pcmult */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-6] = v185;
    v185 = stack[-6];
    stack[-4] = qcdr(v185);
    v186 = stack[-7];
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = qcdr(v185);
    fn = elt(env, 18); /* dquot */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    fn = elt(env, 19); /* pdmult */
    v185 = (*qfn2(fn))(qenv(fn), stack[-4], v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-4] = v185;
    v185 = qvalue(elt(env, 5)); /* tred */
    if (v185 == nil) goto v190;
    v185 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v185 = elt(env, 6); /* "r e d u c t i o n :  " */
    v185 = Lprinc(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v185 = stack[-7];
    v185 = Lprinc(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v185 = elt(env, 7); /* "/" */
    v185 = Lprinc(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v185 = stack[-1];
    v185 = qcar(v185);
    v185 = qcdr(v185);
    v185 = Lprinc(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    v185 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    goto v190;

v190:
    v185 = qvalue(elt(env, 8)); /* stars */
    if (v185 == nil) goto v191;
    v185 = elt(env, 9); /* "*" */
    v185 = Lprinc(nil, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    goto v191;

v191:
    v185 = stack[0];
    v185 = (Lisp_Object)((int32_t)(v185) + 0x10);
    stack[0] = v185;
    v185 = stack[-8];
    v186 = qcdr(v185);
    v185 = stack[-4];
    fn = elt(env, 20); /* pdif */
    v185 = (*qfn2(fn))(qenv(fn), v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-8] = v185;
    goto v5;

v112:
    v185 = qvalue(elt(env, 3)); /* redtails */
    if (v185 == nil) goto v188;
    v187 = stack[-7];
    v185 = stack[-8];
    v185 = qcar(v185);
    v186 = qcdr(v185);
    v185 = stack[-3];
    v185 = acons(v187, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-3] = v185;
    v185 = stack[-8];
    v185 = qcdr(v185);
    stack[-8] = v185;
    goto v5;

v188:
    v186 = qvalue(elt(env, 10)); /* reductions */
    v185 = stack[0];
    v185 = (Lisp_Object)(int32_t)((int32_t)v186 + (int32_t)v185 - TAG_FIXNUM);
    qvalue(elt(env, 10)) = v185; /* reductions */
    v185 = qvalue(elt(env, 11)); /* nforms */
    v185 = (Lisp_Object)((int32_t)(v185) + 0x10);
    qvalue(elt(env, 11)) = v185; /* nforms */
    v185 = stack[-3];
    v186 = Lnreverse(nil, v185);
    env = stack[-11];
    v185 = stack[-8];
    v185 = Lappend(nil, v186, v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    fn = elt(env, 21); /* gcdout */
    v185 = (*qfn1(fn))(qenv(fn), v185);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-11];
    stack[-4] = v185;
    v185 = stack[-4];
    if (!(v185 == nil)) goto v192;
    v185 = qvalue(elt(env, 12)); /* zeros */
    v185 = (Lisp_Object)((int32_t)(v185) + 0x10);
    qvalue(elt(env, 12)) = v185; /* zeros */
    goto v192;

v192:
    v185 = stack[-4];
    goto v91;

v91:
    qvalue(elt(env, 1)) = stack[-10]; /* gg */
    { popv(12); return onevalue(v185); }

v13:
    v185 = v186;
    goto v91;
/* error exit handlers */
v189:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-10]; /* gg */
    popv(12);
    return nil;
}



/* Code for safe!-modrecip */

static Lisp_Object CC_safeKmodrecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v111, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for safe-modrecip");
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
    v111 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* !*msg */
    qvalue(elt(env, 1)) = nil; /* !*msg */
    stack[0] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = nil; /* !*protfg */
    v87 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v87; /* !*msg */
    v87 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v87; /* !*protfg */
    v44 = v111;
    v87 = elt(env, 5); /* !:mod!: */
    if (!consp(v44)) goto v47;
    v44 = qcar(v44);
    if (!(v44 == v87)) goto v47;
    v87 = v111;
    v87 = qcdr(v87);
    v111 = v87;
    goto v47;

v47:
    v87 = elt(env, 6); /* general!-modular!-reciprocal */
    v44 = list2(v87, v111);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    v111 = qvalue(elt(env, 3)); /* nil */
    v87 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* errorset */
    v87 = (*qfnn(fn))(qenv(fn), 3, v44, v111, v87);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    v111 = v87;
    v87 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 7)) = v87; /* erfg!* */
    v87 = v111;
    if (!consp(v87)) goto v103;
    v87 = v111;
    v87 = qcdr(v87);
    if (!(v87 == nil)) goto v103;
    v87 = v111;
    v87 = qcar(v87);
    goto v17;

v17:
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    { popv(3); return onevalue(v87); }

v103:
    v87 = qvalue(elt(env, 3)); /* nil */
    goto v17;
/* error exit handlers */
v77:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    popv(3);
    return nil;
}



/* Code for use!-berlekamp */

static Lisp_Object MS_CDECL CC_useKberlekamp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v21,
                         Lisp_Object v22, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v235, v236, v237, v238, v239, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "use-berlekamp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for use-berlekamp");
#endif
    if (stack >= stacklimit)
    {
        push3(v22,v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v21,v22);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v22;
    stack[-5] = v21;
    stack[-6] = v0;
/* end of prologue */
    v234 = qvalue(elt(env, 1)); /* dpoly */
    v234 = (Lisp_Object)((int32_t)(v234) - 0x10);
    stack[-3] = v234;
    v234 = stack[-3];
    v234 = Lmkvect(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-8];
    stack[-7] = v234;
    v234 = (Lisp_Object)1; /* 0 */
    stack[0] = v234;
    goto v83;

v83:
    v235 = stack[-3];
    v234 = stack[0];
    v234 = (Lisp_Object)(int32_t)((int32_t)v235 - (int32_t)v234 + TAG_FIXNUM);
    v234 = ((intptr_t)(v234) < 0 ? lisp_true : nil);
    if (v234 == nil) goto v63;
    v237 = stack[-6];
    v236 = stack[-5];
    v235 = qvalue(elt(env, 3)); /* poly!-vector */
    v234 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v234 = (*qfnn(fn))(qenv(fn), 4, v237, v236, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-8];
    stack[-5] = v234;
    v234 = (Lisp_Object)1; /* 0 */
    stack[-2] = v234;
    v234 = stack[-3];
    v234 = Lmkvect(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-8];
    stack[-1] = v234;
    v236 = stack[-1];
    v235 = (Lisp_Object)1; /* 0 */
    v234 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v236 + (CELL-TAG_VECTOR) + ((int32_t)v235/(16/CELL))) = v234;
    v234 = (Lisp_Object)17; /* 1 */
    stack[0] = v234;
    goto v95;

v95:
    v235 = stack[-3];
    v234 = stack[0];
    v234 = (Lisp_Object)(int32_t)((int32_t)v235 - (int32_t)v234 + TAG_FIXNUM);
    v234 = ((intptr_t)(v234) < 0 ? lisp_true : nil);
    if (v234 == nil) goto v183;
    v235 = stack[-7];
    v234 = stack[-3];
    {
        popv(9);
        fn = elt(env, 6); /* find!-null!-space */
        return (*qfn2(fn))(qenv(fn), v235, v234);
    }

v183:
    v235 = qvalue(elt(env, 4)); /* current!-modulus */
    v234 = qvalue(elt(env, 1)); /* dpoly */
    if (((int32_t)(v235)) > ((int32_t)(v234))) goto v242;
    v234 = (Lisp_Object)1; /* 0 */
    v237 = v234;
    goto v28;

v28:
    v234 = qvalue(elt(env, 4)); /* current!-modulus */
    v235 = (Lisp_Object)((int32_t)(v234) - 0x10);
    v234 = v237;
    v234 = (Lisp_Object)(int32_t)((int32_t)v235 - (int32_t)v234 + TAG_FIXNUM);
    v234 = ((intptr_t)(v234) < 0 ? lisp_true : nil);
    if (v234 == nil) goto v57;
    v234 = (Lisp_Object)1; /* 0 */
    v238 = v234;
    goto v243;

v243:
    v235 = stack[-2];
    v234 = v238;
    v234 = (Lisp_Object)(int32_t)((int32_t)v235 - (int32_t)v234 + TAG_FIXNUM);
    v234 = ((intptr_t)(v234) < 0 ? lisp_true : nil);
    if (v234 == nil) goto v244;
    v235 = stack[-2];
    v234 = qvalue(elt(env, 4)); /* current!-modulus */
    v234 = (Lisp_Object)(int32_t)((int32_t)v235 + (int32_t)v234 - TAG_FIXNUM);
    stack[-2] = v234;
    goto v191;

v191:
    v237 = stack[-4];
    v236 = stack[-2];
    v235 = qvalue(elt(env, 3)); /* poly!-vector */
    v234 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v234 = (*qfnn(fn))(qenv(fn), 4, v237, v236, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-8];
    stack[-2] = v234;
    v234 = (Lisp_Object)1; /* 0 */
    v240 = v234;
    goto v245;

v245:
    v235 = stack[-2];
    v234 = v240;
    v234 = (Lisp_Object)(int32_t)((int32_t)v235 - (int32_t)v234 + TAG_FIXNUM);
    v234 = ((intptr_t)(v234) < 0 ? lisp_true : nil);
    if (v234 == nil) goto v246;
    v235 = stack[-7];
    v234 = stack[0];
    v237 = *(Lisp_Object *)((char *)v235 + (CELL-TAG_VECTOR) + ((int32_t)v234/(16/CELL)));
    v236 = stack[0];
    v235 = stack[-7];
    v234 = stack[0];
    v235 = *(Lisp_Object *)((char *)v235 + (CELL-TAG_VECTOR) + ((int32_t)v234/(16/CELL)));
    v234 = stack[0];
    v235 = *(Lisp_Object *)((char *)v235 + (CELL-TAG_VECTOR) + ((int32_t)v234/(16/CELL)));
    v234 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v235) - int_of_fixnum(v234);
        if (w < 0) w += current_modulus;
        v234 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL))) = v234;
    v234 = stack[0];
    v234 = (Lisp_Object)((int32_t)(v234) + 0x10);
    stack[0] = v234;
    goto v95;

v246:
    v235 = stack[-7];
    v234 = v240;
    v239 = *(Lisp_Object *)((char *)v235 + (CELL-TAG_VECTOR) + ((int32_t)v234/(16/CELL)));
    v238 = stack[0];
    v237 = stack[-1];
    v236 = v240;
    v235 = stack[-4];
    v234 = v240;
    v234 = *(Lisp_Object *)((char *)v235 + (CELL-TAG_VECTOR) + ((int32_t)v234/(16/CELL)));
    *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL))) = v234;
    *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v238/(16/CELL))) = v234;
    v234 = v240;
    v234 = (Lisp_Object)((int32_t)(v234) + 0x10);
    v240 = v234;
    goto v245;

v244:
    v237 = stack[-4];
    v235 = qvalue(elt(env, 4)); /* current!-modulus */
    v234 = v238;
    v236 = (Lisp_Object)(int32_t)((int32_t)v235 + (int32_t)v234 - TAG_FIXNUM);
    v235 = stack[-1];
    v234 = v238;
    v234 = *(Lisp_Object *)((char *)v235 + (CELL-TAG_VECTOR) + ((int32_t)v234/(16/CELL)));
    *(Lisp_Object *)((char *)v237 + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL))) = v234;
    v234 = v238;
    v234 = (Lisp_Object)((int32_t)(v234) + 0x10);
    v238 = v234;
    goto v243;

v57:
    v236 = stack[-4];
    v235 = v237;
    v234 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v236 + (CELL-TAG_VECTOR) + ((int32_t)v235/(16/CELL))) = v234;
    v234 = v237;
    v234 = (Lisp_Object)((int32_t)(v234) + 0x10);
    v237 = v234;
    goto v28;

v242:
    v238 = stack[-1];
    v237 = stack[-2];
    v236 = stack[-6];
    v235 = stack[-5];
    v234 = stack[-4];
    fn = elt(env, 7); /* times!-in!-vector */
    v234 = (*qfnn(fn))(qenv(fn), 5, v238, v237, v236, v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-8];
    stack[-2] = v234;
    goto v191;

v63:
    v234 = stack[-3];
    v234 = Lmkvect(nil, v234);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-8];
    v238 = v234;
    v234 = (Lisp_Object)1; /* 0 */
    v237 = v234;
    goto v16;

v16:
    v235 = stack[-3];
    v234 = v237;
    v234 = (Lisp_Object)(int32_t)((int32_t)v235 - (int32_t)v234 + TAG_FIXNUM);
    v234 = ((intptr_t)(v234) < 0 ? lisp_true : nil);
    if (v234 == nil) goto v97;
    v235 = stack[-7];
    v234 = stack[0];
    v236 = v238;
    *(Lisp_Object *)((char *)v235 + (CELL-TAG_VECTOR) + ((int32_t)v234/(16/CELL))) = v236;
    v234 = stack[0];
    v234 = (Lisp_Object)((int32_t)(v234) + 0x10);
    stack[0] = v234;
    goto v83;

v97:
    v236 = v238;
    v235 = v237;
    v234 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v236 + (CELL-TAG_VECTOR) + ((int32_t)v235/(16/CELL))) = v234;
    v234 = v237;
    v234 = (Lisp_Object)((int32_t)(v234) + 0x10);
    v237 = v234;
    goto v16;
/* error exit handlers */
v241:
    popv(9);
    return nil;
}



/* Code for mconv1 */

static Lisp_Object CC_mconv1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mconv1");
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
    goto v20;

v20:
    v103 = stack[-1];
    if (!consp(v103)) goto v71;
    v103 = stack[-1];
    v103 = qcar(v103);
    if (!consp(v103)) goto v71;
    v103 = stack[-1];
    v103 = qcar(v103);
    stack[0] = qcar(v103);
    v103 = stack[-1];
    v103 = qcar(v103);
    v103 = qcdr(v103);
    v16 = CC_mconv1(env, v103);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    v103 = stack[-2];
    v103 = acons(stack[0], v16, v103);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    stack[-2] = v103;
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    goto v20;

v71:
    stack[0] = stack[-2];
    v103 = stack[-1];
    fn = elt(env, 1); /* drnconv */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-3];
    {
        Lisp_Object v46 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v46, v103);
    }
/* error exit handlers */
v93:
    popv(4);
    return nil;
}



/* Code for prepreform1 */

static Lisp_Object CC_prepreform1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepreform1");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v21;
    stack[0] = v0;
/* end of prologue */

v108:
    v250 = stack[0];
    if (!consp(v250)) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v250 = stack[0];
    v173 = qcar(v250);
    v250 = elt(env, 1); /* dname */
    v250 = get(v173, v250);
    env = stack[-7];
    if (!(v250 == nil)) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    stack[-6] = nil;
    v250 = stack[-5];
    stack[-1] = v250;
    goto v4;

v4:
    v250 = stack[-6];
    if (!(v250 == nil)) goto v110;
    v250 = stack[-1];
    if (v250 == nil) goto v110;
    v250 = stack[-1];
    v173 = qcar(v250);
    v250 = stack[0];
    v250 = qcdr(v250);
    v250 = Lsmemq(nil, v173, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    if (v250 == nil) goto v79;
    v250 = qvalue(elt(env, 3)); /* t */
    stack[-6] = v250;
    goto v4;

v79:
    v250 = stack[-1];
    v250 = qcdr(v250);
    stack[-1] = v250;
    goto v4;

v110:
    v250 = stack[-6];
    if (v250 == nil) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v250 = stack[0];
    v173 = qcar(v250);
    v250 = elt(env, 4); /* (plus difference minus times quotient) */
    v250 = Lmemq(nil, v173, v250);
    if (!(v250 == nil)) goto v86;
    v250 = stack[0];
    v173 = qcar(v250);
    v250 = elt(env, 5); /* simpfn */
    v250 = get(v173, v250);
    env = stack[-7];
    if (!(v250 == nil)) goto v81;

v86:
    v250 = qvalue(elt(env, 2)); /* nil */
    stack[-6] = v250;
    goto v81;

v81:
    v250 = stack[0];
    v173 = qcar(v250);
    v250 = elt(env, 6); /* !*sq */
    if (v173 == v250) goto v98;
    v250 = stack[0];
    stack[-4] = qcar(v250);
    v250 = stack[0];
    v250 = qcdr(v250);
    stack[-3] = v250;
    v250 = stack[-3];
    if (v250 == nil) goto v252;
    v250 = stack[-3];
    v250 = qcar(v250);
    v173 = v250;
    v250 = stack[-6];
    if (v250 == nil) goto v26;
    v250 = v173;
    fn = elt(env, 7); /* simp!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    fn = elt(env, 8); /* sqhorner!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v173 = v250;
    goto v32;

v32:
    v250 = stack[-5];
    v250 = CC_prepreform1(env, v173, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = ncons(v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-1] = v250;
    stack[-2] = v250;
    goto v55;

v55:
    v250 = stack[-3];
    v250 = qcdr(v250);
    stack[-3] = v250;
    v250 = stack[-3];
    if (v250 == nil) goto v28;
    stack[0] = stack[-1];
    v250 = stack[-3];
    v250 = qcar(v250);
    v173 = v250;
    v250 = stack[-6];
    if (v250 == nil) goto v176;
    v250 = v173;
    fn = elt(env, 7); /* simp!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    fn = elt(env, 8); /* sqhorner!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v173 = v250;
    goto v148;

v148:
    v250 = stack[-5];
    v250 = CC_prepreform1(env, v173, v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = ncons(v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = Lrplacd(nil, stack[0], v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = stack[-1];
    v250 = qcdr(v250);
    stack[-1] = v250;
    goto v55;

v176:
    v250 = v173;
    v173 = v250;
    goto v148;

v28:
    v250 = stack[-2];
    goto v113;

v113:
    {
        Lisp_Object v169 = stack[-4];
        popv(8);
        return cons(v169, v250);
    }

v26:
    v250 = v173;
    v173 = v250;
    goto v32;

v252:
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v113;

v98:
    v250 = stack[0];
    v250 = qcdr(v250);
    v250 = qcar(v250);
    fn = elt(env, 8); /* sqhorner!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v173 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = stack[-5];
    stack[0] = v173;
    stack[-5] = v250;
    goto v108;
/* error exit handlers */
v251:
    popv(8);
    return nil;
}



/* Code for negind */

static Lisp_Object CC_negind(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v21)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v82;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negind");
#endif
    if (stack >= stacklimit)
    {
        push2(v21,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v21);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v21;
    stack[-1] = v0;
/* end of prologue */

v108:
    v51 = stack[-1];
    if (v51 == nil) goto v20;
    v51 = stack[-1];
    v82 = qcar(v51);
    v51 = stack[0];
    v51 = qcar(v51);
    v51 = qcar(v51);
    v82 = plus2(v82, v51);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-2];
    v51 = (Lisp_Object)1; /* 0 */
    v51 = (Lisp_Object)lessp2(v82, v51);
    nil = C_nil;
    if (exception_pending()) goto v2;
    v51 = v51 ? lisp_true : nil;
    env = stack[-2];
    if (!(v51 == nil)) { popv(3); return onevalue(v51); }
    v51 = stack[-1];
    v82 = qcdr(v51);
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[-1] = v82;
    stack[0] = v51;
    goto v108;

v20:
    v51 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v51); }
/* error exit handlers */
v2:
    popv(3);
    return nil;
}



/* Code for cl_fvarl1 */

static Lisp_Object CC_cl_fvarl1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_fvarl1");
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
    v20 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cl_varl1 */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    errexit();
    v20 = qcar(v20);
    return onevalue(v20);
}



/* Code for cl_pnf2 */

static Lisp_Object CC_cl_pnf2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v170, v257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pnf2");
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
    v169 = stack[0];
    if (!consp(v169)) goto v91;
    v169 = stack[0];
    v169 = qcar(v169);
    goto v17;

v17:
    v170 = v169;
    v257 = v170;
    v169 = elt(env, 1); /* ex */
    if (v257 == v169) goto v7;
    v257 = v170;
    v169 = elt(env, 2); /* all */
    if (v257 == v169) goto v7;
    v257 = v170;
    v169 = elt(env, 3); /* or */
    if (v257 == v169) goto v72;
    v257 = v170;
    v169 = elt(env, 4); /* and */
    if (v257 == v169) goto v72;
    v257 = v170;
    v169 = elt(env, 5); /* true */
    if (v257 == v169) goto v77;
    v257 = v170;
    v169 = elt(env, 6); /* false */
    if (v257 == v169) goto v77;
    v257 = v170;
    v169 = elt(env, 5); /* true */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 6); /* false */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 3); /* or */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 4); /* and */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 7); /* not */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 8); /* impl */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 9); /* repl */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 10); /* equiv */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 1); /* ex */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 2); /* all */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 11); /* bex */
    if (v257 == v169) goto v132;
    v257 = v170;
    v169 = elt(env, 12); /* ball */
    if (!(v257 == v169)) goto v41;

v132:
    v169 = qvalue(elt(env, 13)); /* !*protfg */
    if (!(v169 == nil)) goto v258;
    v257 = elt(env, 14); /* "cl_pnf2():" */
    v169 = elt(env, 15); /* "invalid as operator" */
    v169 = list3(v257, v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-1];
    fn = elt(env, 16); /* lprie */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-1];
    goto v258;

v258:
    v169 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v259;
    goto v41;

v41:
    v169 = stack[0];
    popv(2);
    return ncons(v169);

v77:
    v169 = stack[0];
    popv(2);
    return ncons(v169);

v72:
    v169 = stack[0];
    {
        popv(2);
        fn = elt(env, 17); /* cl_pnf2!-junctor */
        return (*qfn1(fn))(qenv(fn), v169);
    }

v7:
    v169 = stack[0];
    {
        popv(2);
        fn = elt(env, 18); /* cl_pnf2!-quantifier */
        return (*qfn1(fn))(qenv(fn), v169);
    }

v91:
    v169 = stack[0];
    goto v17;
/* error exit handlers */
v259:
    popv(2);
    return nil;
}



setup_type const u22_setup[] =
{
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
    {"nf",                      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nf},
    {"safe-modrecip",           CC_safeKmodrecip,too_many_1,   wrong_no_1},
    {"use-berlekamp",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_useKberlekamp},
    {"mconv1",                  CC_mconv1,      too_many_1,    wrong_no_1},
    {"prepreform1",             too_few_2,      CC_prepreform1,wrong_no_2},
    {"negind",                  too_few_2,      CC_negind,     wrong_no_2},
    {"cl_fvarl1",               CC_cl_fvarl1,   too_many_1,    wrong_no_1},
    {"cl_pnf2",                 CC_cl_pnf2,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u22", (two_args *)"15267 4292573 4580198", 0}
};

/* end of generated code */
