
/* $destdir\u17.c        Machine generated C code */

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


/* Code for !*wedgepf2pf */

static Lisp_Object CC_Hwedgepf2pf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v7;
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
    goto v8;

v8:
    v5 = stack[0];
    if (v5 == nil) goto v9;
    v5 = stack[0];
    v5 = qcar(v5);
    v5 = qcar(v5);
    fn = elt(env, 1); /* mkuwedge */
    v7 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    v5 = stack[0];
    v5 = qcar(v5);
    v6 = qcdr(v5);
    v5 = stack[-1];
    v5 = acons(v7, v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    stack[-1] = v5;
    v5 = stack[0];
    v5 = qcdr(v5);
    stack[0] = v5;
    goto v8;

v9:
    v5 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v5);
    }
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



/* Code for mktails1 */

static Lisp_Object MS_CDECL CC_mktails1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktails1");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v38 = v11;
    stack[-1] = v0;
/* end of prologue */
    v39 = stack[-1];
    fn = elt(env, 3); /* getroad */
    v38 = (*qfn2(fn))(qenv(fn), v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v39 = v38;
    v40 = (Lisp_Object)1; /* 0 */
    v38 = v39;
    if (v40 == v38) goto v1;
    v40 = (Lisp_Object)1; /* 0 */
    v38 = stack[-1];
    v38 = qcdr(v38);
    if (v40 == v38) goto v42;
    v40 = stack[-1];
    v38 = stack[0];
    v38 = Lassoc(nil, v40, v38);
    v40 = v38;
    v38 = v40;
    if (v38 == nil) goto v43;
    v38 = v40;
    v38 = qcdr(v38);
    v38 = qcdr(v38);
    if (v38 == nil) goto v44;
    v38 = v40;
    v38 = qcdr(v38);
    v39 = Lreverse(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v38 = stack[0];
    popv(4);
    return cons(v39, v38);

v44:
    v38 = v40;
    v39 = qcdr(v38);
    v38 = stack[0];
    popv(4);
    return cons(v39, v38);

v43:
    v38 = stack[-1];
    fn = elt(env, 4); /* mkinds */
    v38 = (*qfn2(fn))(qenv(fn), v38, v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v40 = v38;
    stack[-2] = v40;
    v38 = stack[-1];
    v39 = v40;
    v39 = cons(v38, v39);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v38 = stack[0];
    {
        Lisp_Object v45 = stack[-2];
        popv(4);
        return list2star(v45, v39, v38);
    }

v42:
    v38 = stack[-1];
    v39 = qcar(v38);
    v38 = elt(env, 2); /* replace_by_vector */
    v38 = get(v39, v38);
    env = stack[-3];
    if (!(v38 == nil)) goto v46;
    v38 = stack[-1];
    v38 = qcar(v38);
    goto v46;

v46:
    v39 = ncons(v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    v38 = stack[0];
    popv(4);
    return cons(v39, v38);

v1:
    v39 = qvalue(elt(env, 1)); /* nil */
    v38 = stack[0];
    popv(4);
    return cons(v39, v38);
/* error exit handlers */
v41:
    popv(4);
    return nil;
}



/* Code for formsetq */

static Lisp_Object MS_CDECL CC_formsetq(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62, v63, v64, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v63 = v4;
    v64 = v11;
    v65 = v0;
/* end of prologue */
    v62 = v63;
    v61 = elt(env, 1); /* symbolic */
    if (v62 == v61) goto v1;
    v61 = v65;
    v62 = v64;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v61, v62, v63);
    }

v1:
    v61 = v65;
    v61 = qcdr(v61);
    v62 = qcar(v61);
    v61 = elt(env, 2); /* list */
    if (!consp(v62)) goto v66;
    v62 = qcar(v62);
    if (!(v62 == v61)) goto v66;
    v61 = v65;
    v62 = v64;
    {
        fn = elt(env, 5); /* formsetq1 */
        return (*qfnn(fn))(qenv(fn), 3, v61, v62, v63);
    }

v66:
    v61 = v65;
    v61 = qcdr(v61);
    v62 = qcar(v61);
    v61 = elt(env, 3); /* cons */
    if (!consp(v62)) goto v25;
    v62 = qcar(v62);
    if (!(v62 == v61)) goto v25;
    v61 = v65;
    v62 = v64;
    {
        fn = elt(env, 6); /* formsetq2 */
        return (*qfnn(fn))(qenv(fn), 3, v61, v62, v63);
    }

v25:
    v61 = v65;
    v62 = v64;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v61, v62, v63);
    }
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v4, Lisp_Object v67, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v44, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel1");
#endif
    if (stack >= stacklimit)
    {
        push4(v67,v4,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v11,v4,v67);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v67;
    stack[-1] = v4;
    stack[-2] = v11;
    stack[-3] = v0;
/* end of prologue */

v73:
    v71 = stack[-2];
    v71 = qcar(v71);
    v71 = integerp(v71);
    if (v71 == nil) goto v37;
    v71 = stack[-2];
    v44 = qcar(v71);
    v71 = stack[0];
    v71 = qcar(v71);
    v71 = (Lisp_Object)geq2(v44, v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v71 = v71 ? lisp_true : nil;
    env = stack[-4];
    if (!(v71 == nil)) goto v57;
    v71 = stack[-2];
    v44 = qcar(v71);
    v71 = (Lisp_Object)1; /* 0 */
    v71 = (Lisp_Object)lessp2(v44, v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v71 = v71 ? lisp_true : nil;
    env = stack[-4];
    if (!(v71 == nil)) goto v57;
    v71 = stack[-2];
    v71 = qcdr(v71);
    if (v71 == nil) goto v74;
    v44 = stack[-3];
    v71 = stack[-2];
    v71 = qcar(v71);
    v71 = *(Lisp_Object *)((char *)v44 + (CELL-TAG_VECTOR) + ((int32_t)v71/(16/CELL)));
    stack[-3] = v71;
    v71 = stack[-2];
    v71 = qcdr(v71);
    stack[-2] = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v73;

v74:
    v72 = stack[-3];
    v71 = stack[-2];
    v44 = qcar(v71);
    v71 = stack[-1];
    *(Lisp_Object *)((char *)v72 + (CELL-TAG_VECTOR) + ((int32_t)v44/(16/CELL))) = v71;
    { popv(5); return onevalue(v71); }

v57:
    v71 = elt(env, 2); /* "Array out of bounds" */
    v44 = v71;
    v71 = v44;
    qvalue(elt(env, 3)) = v71; /* errmsg!* */
    v71 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v71 == nil)) goto v75;
    v71 = v44;
    fn = elt(env, 5); /* lprie */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    goto v75;

v75:
    v71 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v71 = nil;
    { popv(5); return onevalue(v71); }

v37:
    v71 = stack[-2];
    v44 = qcar(v71);
    v71 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v44, v71);
    }
/* error exit handlers */
v24:
    popv(5);
    return nil;
}



/* Code for mo_from_a */

static Lisp_Object CC_mo_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89;
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
    v88 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    v88 = Lmember(nil, stack[0], v88);
    if (v88 == nil) goto v37;
    v88 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    stack[-4] = v88;
    v88 = stack[-4];
    if (v88 == nil) goto v91;
    v88 = stack[-4];
    v88 = qcar(v88);
    v89 = v88;
    v88 = stack[-3];
    if (equal(v89, v88)) goto v92;
    v88 = (Lisp_Object)1; /* 0 */
    goto v93;

v93:
    v88 = ncons(v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    stack[-1] = v88;
    stack[-2] = v88;
    goto v7;

v7:
    v88 = stack[-4];
    v88 = qcdr(v88);
    stack[-4] = v88;
    v88 = stack[-4];
    if (v88 == nil) goto v94;
    stack[0] = stack[-1];
    v88 = stack[-4];
    v88 = qcar(v88);
    v89 = v88;
    v88 = stack[-3];
    if (equal(v89, v88)) goto v49;
    v88 = (Lisp_Object)1; /* 0 */
    goto v48;

v48:
    v88 = ncons(v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    v88 = Lrplacd(nil, stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    v88 = stack[-1];
    v88 = qcdr(v88);
    stack[-1] = v88;
    goto v7;

v49:
    v88 = (Lisp_Object)17; /* 1 */
    goto v48;

v94:
    v88 = stack[-2];
    goto v6;

v6:
    fn = elt(env, 5); /* mo!=shorten */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    stack[0] = v88;
    fn = elt(env, 6); /* mo!=deglist */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v95 = stack[0];
        popv(6);
        return cons(v95, v88);
    }

v92:
    v88 = (Lisp_Object)17; /* 1 */
    goto v93;

v91:
    v88 = qvalue(elt(env, 3)); /* nil */
    goto v6;

v37:
    v89 = stack[-3];
    v88 = elt(env, 2); /* "dpoly variable" */
    {
        popv(6);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v89, v88);
    }
/* error exit handlers */
v90:
    popv(6);
    return nil;
}



/* Code for exptpri */

static Lisp_Object CC_exptpri(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v151, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptpri");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v151 = v11;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*list */
    qvalue(elt(env, 1)) = nil; /* !*list */
    stack[0] = nil;
    v150 = qvalue(elt(env, 2)); /* !*nat */
    if (v150 == nil) goto v59;
    v150 = qvalue(elt(env, 3)); /* !*fort */
    if (!(v150 == nil)) goto v59;
    v152 = elt(env, 5); /* expt */
    v150 = elt(env, 6); /* infix */
    v150 = get(v152, v150);
    env = stack[-7];
    stack[-2] = v150;
    v150 = (Lisp_Object)greaterp2(v150, v151);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v150 = v150 ? lisp_true : nil;
    env = stack[-7];
    v150 = (v150 == nil ? lisp_true : nil);
    stack[-4] = v150;
    v150 = stack[-5];
    v150 = qcdr(v150);
    v150 = qcar(v150);
    stack[-1] = v150;
    v150 = stack[-5];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    stack[-3] = v150;
    v150 = qvalue(elt(env, 7)); /* !*eraise */
    if (v150 == nil) goto v71;
    v150 = stack[-1];
    if (!consp(v150)) goto v71;
    v150 = stack[-1];
    v151 = qcar(v150);
    v150 = elt(env, 8); /* prifn */
    v150 = get(v151, v150);
    env = stack[-7];
    stack[0] = v150;
    if (v150 == nil) goto v71;
    v151 = stack[0];
    v150 = elt(env, 5); /* expt */
    v151 = get(v151, v150);
    env = stack[-7];
    v150 = elt(env, 9); /* inbrackets */
    if (!(v151 == v150)) goto v71;
    v152 = stack[-1];
    v151 = (Lisp_Object)1; /* 0 */
    v150 = elt(env, 9); /* inbrackets */
    fn = elt(env, 21); /* layout!-formula */
    v150 = (*qfnn(fn))(qenv(fn), 3, v152, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    stack[-1] = v150;
    goto v154;

v154:
    v150 = stack[-1];
    if (v150 == nil) goto v13;
    stack[-5] = qvalue(elt(env, 12)); /* !*ratpri */
    qvalue(elt(env, 12)) = nil; /* !*ratpri */
    v151 = stack[-3];
    v150 = elt(env, 13); /* quotient */
    if (!consp(v151)) goto v155;
    v151 = qcar(v151);
    if (!(v151 == v150)) goto v155;
    v150 = stack[-3];
    v150 = qcdr(v150);
    v151 = qcar(v150);
    v150 = elt(env, 14); /* minus */
    if (!consp(v151)) goto v155;
    v151 = qcar(v151);
    if (!(v151 == v150)) goto v155;
    stack[0] = elt(env, 14); /* minus */
    v150 = stack[-3];
    v152 = qcar(v150);
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = qcdr(v150);
    v151 = qcar(v150);
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = list3(v152, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    v150 = list2(stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    stack[-3] = v150;
    goto v157;

v157:
    v152 = stack[-3];
    v150 = qvalue(elt(env, 7)); /* !*eraise */
    if (v150 == nil) goto v158;
    v150 = (Lisp_Object)1; /* 0 */
    v151 = v150;
    goto v159;

v159:
    v150 = qvalue(elt(env, 11)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v150 = (*qfnn(fn))(qenv(fn), 3, v152, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    stack[-3] = v150;
    qvalue(elt(env, 12)) = stack[-5]; /* !*ratpri */
    v150 = stack[-3];
    if (v150 == nil) goto v160;
    v150 = stack[-1];
    v150 = qcar(v150);
    v151 = qcdr(v150);
    v150 = stack[-3];
    v150 = qcar(v150);
    v150 = qcdr(v150);
    v150 = plus2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    stack[-5] = v150;
    v150 = stack[-4];
    if (v150 == nil) goto v161;
    v151 = stack[-5];
    v150 = (Lisp_Object)33; /* 2 */
    v150 = plus2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    stack[-5] = v150;
    goto v161;

v161:
    stack[0] = stack[-5];
    v150 = qvalue(elt(env, 11)); /* nil */
    v151 = Llinelength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = qvalue(elt(env, 15)); /* spare!* */
    v151 = difference2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = qvalue(elt(env, 16)); /* orig!* */
    v150 = difference2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = (Lisp_Object)greaterp2(stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v150 = v150 ? lisp_true : nil;
    env = stack[-7];
    if (v150 == nil) goto v162;
    v150 = elt(env, 4); /* failed */
    goto v163;

v163:
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    { popv(8); return onevalue(v150); }

v162:
    stack[0] = stack[-5];
    v150 = qvalue(elt(env, 11)); /* nil */
    v151 = Llinelength(nil, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = qvalue(elt(env, 15)); /* spare!* */
    v151 = difference2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = qvalue(elt(env, 17)); /* posn!* */
    v150 = difference2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = (Lisp_Object)greaterp2(stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    v150 = v150 ? lisp_true : nil;
    env = stack[-7];
    if (v150 == nil) goto v164;
    v150 = qvalue(elt(env, 18)); /* t */
    fn = elt(env, 22); /* terpri!* */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    goto v164;

v164:
    v150 = stack[-4];
    if (v150 == nil) goto v165;
    v150 = elt(env, 19); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    goto v165;

v165:
    v150 = stack[-1];
    fn = elt(env, 24); /* putpline */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = qvalue(elt(env, 7)); /* !*eraise */
    if (v150 == nil) goto v166;
    v151 = (Lisp_Object)17; /* 1 */
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = difference2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    stack[-5] = v150;
    goto v167;

v167:
    v152 = (Lisp_Object)1; /* 0 */
    v151 = stack[-5];
    v150 = stack[-3];
    v150 = qcar(v150);
    v150 = qcar(v150);
    fn = elt(env, 25); /* update!-pline */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v152, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = stack[-3];
    v150 = qcar(v150);
    stack[-1] = qcdr(v150);
    v150 = stack[-3];
    v150 = qcdr(v150);
    v151 = qcar(v150);
    v150 = stack[-5];
    stack[0] = plus2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = stack[-3];
    v150 = qcdr(v150);
    v151 = qcdr(v150);
    v150 = stack[-5];
    v150 = plus2(v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = cons(stack[0], v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = acons(stack[-2], stack[-1], v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    fn = elt(env, 24); /* putpline */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = stack[-4];
    if (v150 == nil) goto v168;
    v150 = elt(env, 20); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    goto v168;

v168:
    v150 = nil;
    goto v163;

v166:
    v150 = elt(env, 5); /* expt */
    fn = elt(env, 26); /* oprin */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = (Lisp_Object)1; /* 0 */
    stack[-5] = v150;
    goto v167;

v160:
    v150 = elt(env, 4); /* failed */
    goto v163;

v158:
    v150 = stack[-2];
    v151 = v150;
    goto v159;

v155:
    v151 = stack[-3];
    v150 = elt(env, 14); /* minus */
    if (!consp(v151)) goto v169;
    v151 = qcar(v151);
    if (!(v151 == v150)) goto v169;
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcar(v150);
    if (!(is_number(v150))) goto v169;
    v150 = stack[-3];
    v150 = qcdr(v150);
    v150 = qcar(v150);
    v150 = negate(v150);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    goto v170;

v170:
    stack[-3] = v150;
    goto v157;

v169:
    v150 = stack[-3];
    goto v170;

v13:
    v150 = elt(env, 4); /* failed */
    goto v163;

v71:
    v151 = stack[0];
    v150 = elt(env, 10); /* indexprin */
    if (!(v151 == v150)) goto v95;
    v151 = stack[-1];
    v150 = stack[-3];
    fn = elt(env, 27); /* indexpower */
    v151 = (*qfn2(fn))(qenv(fn), v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    v150 = elt(env, 4); /* failed */
    if (v151 == v150) goto v95;
    v150 = qvalue(elt(env, 11)); /* nil */
    goto v163;

v95:
    v152 = stack[-1];
    v151 = stack[-2];
    v150 = qvalue(elt(env, 11)); /* nil */
    fn = elt(env, 21); /* layout!-formula */
    v150 = (*qfnn(fn))(qenv(fn), 3, v152, v151, v150);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-7];
    stack[-1] = v150;
    goto v154;

v59:
    v150 = elt(env, 4); /* failed */
    goto v163;
/* error exit handlers */
v156:
    env = stack[-7];
    qvalue(elt(env, 12)) = stack[-5]; /* !*ratpri */
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
v153:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
}



/* Code for reduce_pv0 */

static Lisp_Object MS_CDECL CC_reduce_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v4;
    stack[-4] = v11;
    stack[0] = v0;
/* end of prologue */
    v180 = stack[-4];
    if (v180 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v180 = stack[0];
    if (v180 == nil) goto v163;
    v180 = stack[0];
    stack[-5] = v180;
    goto v3;

v3:
    v180 = stack[-5];
    if (v180 == nil) goto v70;
    v180 = stack[-4];
    if (v180 == nil) goto v70;
    v180 = stack[-5];
    v180 = qcar(v180);
    v181 = qcdr(v180);
    v180 = stack[-4];
    v180 = qcar(v180);
    v180 = qcdr(v180);
    v180 = (Lisp_Object)greaterp2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    v180 = v180 ? lisp_true : nil;
    env = stack[-6];
    if (v180 == nil) goto v70;
    v180 = stack[-5];
    v180 = qcdr(v180);
    stack[-5] = v180;
    goto v3;

v70:
    v180 = stack[-5];
    if (v180 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v180 = stack[-4];
    if (v180 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v180 = stack[-4];
    v180 = qcar(v180);
    v181 = qcdr(v180);
    v180 = stack[-5];
    v180 = qcar(v180);
    v180 = qcdr(v180);
    if (!(equal(v181, v180))) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v180 = stack[-5];
    v180 = qcar(v180);
    v181 = qcar(v180);
    v180 = stack[-4];
    v180 = qcar(v180);
    v180 = qcar(v180);
    fn = elt(env, 3); /* lcm */
    v180 = (*qfn2(fn))(qenv(fn), v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[-2] = v180;
    v181 = stack[-2];
    v180 = stack[-5];
    v180 = qcar(v180);
    v180 = qcar(v180);
    v180 = quot2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[0] = stack[-4];
    v181 = stack[-2];
    v180 = stack[-4];
    v180 = qcar(v180);
    v180 = qcar(v180);
    v180 = quot2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v180 = negate(v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    v180 = (*qfn2(fn))(qenv(fn), stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    fn = elt(env, 5); /* pv_add */
    v180 = (*qfn2(fn))(qenv(fn), stack[-1], v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    stack[0] = v180;
    v180 = stack[-3];
    if (v180 == nil) goto v183;
    v180 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v180; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v183:
    stack[-1] = qvalue(elt(env, 2)); /* pv_den */
    v181 = stack[-2];
    v180 = stack[-5];
    v180 = qcar(v180);
    v180 = qcar(v180);
    v180 = quot2(v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    v180 = times2(stack[-1], v180);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-6];
    qvalue(elt(env, 2)) = v180; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v163:
    v180 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v180); }
/* error exit handlers */
v182:
    popv(7);
    return nil;
}



/* Code for rl_csimpl */

static Lisp_Object CC_rl_csimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v34, v35;
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
    v58 = qvalue(elt(env, 1)); /* !*rlsimpl */
    if (v58 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v58 = elt(env, 2); /* rl_simpl */
    fn = elt(env, 4); /* getd */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    if (v58 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v35 = stack[0];
    v34 = qvalue(elt(env, 3)); /* nil */
    v58 = (Lisp_Object)-15; /* -1 */
    {
        popv(2);
        fn = elt(env, 2); /* rl_simpl */
        return (*qfnn(fn))(qenv(fn), 3, v35, v34, v58);
    }
/* error exit handlers */
v1:
    popv(2);
    return nil;
}



/* Code for wureducedpolysp */

static Lisp_Object CC_wureducedpolysp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wureducedpolysp");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */

v187:
    v5 = stack[0];
    v5 = (v5 == nil ? lisp_true : nil);
    if (!(v5 == nil)) { popv(3); return onevalue(v5); }
    v6 = stack[-1];
    v5 = stack[0];
    v5 = qcar(v5);
    fn = elt(env, 2); /* wureducedp */
    v5 = (*qfn2(fn))(qenv(fn), v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    if (v5 == nil) goto v163;
    v6 = stack[-1];
    v5 = stack[0];
    v5 = qcdr(v5);
    stack[-1] = v6;
    stack[0] = v5;
    goto v187;

v163:
    v5 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v55:
    popv(3);
    return nil;
}



/* Code for tmsf */

static Lisp_Object CC_tmsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39, v40;
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
    v38 = (Lisp_Object)1; /* 0 */
    v40 = v38;
    goto v96;

v96:
    v38 = stack[-1];
    if (!consp(v38)) goto v9;
    v38 = stack[-1];
    v38 = qcar(v38);
    if (!consp(v38)) goto v9;
    stack[-2] = v40;
    v38 = stack[-1];
    v38 = qcar(v38);
    v38 = qcar(v38);
    v38 = qcar(v38);
    v40 = v38;
    v39 = v38;
    v38 = v39;
    if (!consp(v38)) goto v154;
    v38 = v39;
    v38 = qcar(v38);
    v38 = (consp(v38) ? nil : lisp_true);
    v38 = (v38 == nil ? lisp_true : nil);
    goto v191;

v191:
    if (v38 == nil) goto v46;
    v38 = v40;
    v38 = CC_tmsf(env, v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    stack[0] = v38;
    goto v2;

v2:
    v38 = stack[-1];
    v38 = qcar(v38);
    v38 = qcdr(v38);
    if (!(is_number(v38))) goto v192;
    v38 = stack[-1];
    v38 = qcar(v38);
    v38 = qcdr(v38);
    v38 = Ltruncate(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v39 = Labsval(nil, v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v38 = (Lisp_Object)17; /* 1 */
    if (!(v39 == v38)) goto v192;
    v38 = (Lisp_Object)1; /* 0 */
    goto v82;

v82:
    v38 = plus2(stack[0], v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v38 = plus2(stack[-2], v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v40 = v38;
    v38 = stack[-1];
    v38 = qcar(v38);
    v38 = qcar(v38);
    v39 = qcdr(v38);
    v38 = (Lisp_Object)17; /* 1 */
    if (v39 == v38) goto v63;
    v38 = stack[-1];
    v38 = qcar(v38);
    v38 = qcar(v38);
    v39 = qcdr(v38);
    v38 = (Lisp_Object)33; /* 2 */
    if (v39 == v38) goto v178;
    v39 = v40;
    v38 = (Lisp_Object)33; /* 2 */
    v38 = plus2(v39, v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v40 = v38;
    goto v63;

v63:
    v38 = stack[-1];
    v38 = qcdr(v38);
    stack[-1] = v38;
    goto v96;

v178:
    v38 = v40;
    v38 = add1(v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    v40 = v38;
    goto v63;

v192:
    v38 = stack[-1];
    v38 = qcar(v38);
    v38 = qcdr(v38);
    v38 = CC_tmsf(env, v38);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-3];
    goto v82;

v46:
    v38 = (Lisp_Object)17; /* 1 */
    stack[0] = v38;
    goto v2;

v154:
    v38 = qvalue(elt(env, 1)); /* nil */
    goto v191;

v9:
    v38 = stack[-1];
    if (v38 == nil) { popv(4); return onevalue(v40); }
    v38 = v40;
    popv(4);
    return add1(v38);
/* error exit handlers */
v41:
    popv(4);
    return nil;
}



/* Code for ibalp_unvar!-unsatlist */

static Lisp_Object CC_ibalp_unvarKunsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_unvar-unsatlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v11;
    v216 = v0;
/* end of prologue */
    stack[-5] = v216;
    goto v96;

v96:
    v216 = stack[-5];
    if (v216 == nil) goto v9;
    v216 = stack[-5];
    v216 = qcar(v216);
    stack[-3] = v216;
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v217 = stack[-4];
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    fn = elt(env, 2); /* delq */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    if (!(v216 == nil)) goto v32;
    v216 = stack[-3];
    v216 = qcar(v216);
    stack[-2] = v216;
    goto v83;

v83:
    v216 = stack[-2];
    if (v216 == nil) goto v46;
    v216 = stack[-2];
    v216 = qcar(v216);
    stack[-1] = v216;
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    v216 = add1(v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v216 = stack[-1];
    fn = elt(env, 4); /* ibalp_calcmom */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-2];
    v216 = qcdr(v216);
    stack[-2] = v216;
    goto v83;

v46:
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcar(v216);
    stack[-2] = v216;
    goto v189;

v189:
    v216 = stack[-2];
    if (v216 == nil) goto v147;
    v216 = stack[-2];
    v216 = qcar(v216);
    stack[-1] = v216;
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    v216 = add1(v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v216 = stack[-1];
    fn = elt(env, 4); /* ibalp_calcmom */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-2];
    v216 = qcdr(v216);
    stack[-2] = v216;
    goto v189;

v147:
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    stack[-1] = v216;
    goto v218;

v218:
    v216 = stack[-1];
    if (v216 == nil) goto v219;
    v216 = stack[-1];
    v216 = qcar(v216);
    v217 = v216;
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    stack[0] = qcdr(v217);
    v217 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    fn = elt(env, 2); /* delq */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-1];
    v216 = qcdr(v216);
    stack[-1] = v216;
    goto v218;

v219:
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v217 = qcdr(v216);
    v216 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-3];
    fn = elt(env, 5); /* ibalp_getnewwl */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    stack[-1] = v216;
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v217 = stack[-1];
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    v216 = cons(v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v217 = stack[-3];
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    v216 = cons(v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-3];
    fn = elt(env, 5); /* ibalp_getnewwl */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    stack[-1] = v216;
    v216 = stack[-1];
    if (v216 == nil) goto v32;
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v217 = stack[-1];
    v216 = stack[-3];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    v216 = cons(v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    stack[0] = qcdr(v216);
    v217 = stack[-3];
    v216 = stack[-1];
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcdr(v216);
    v216 = qcar(v216);
    v216 = cons(v217, v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v216 = (*qfn2(fn))(qenv(fn), stack[0], v216);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-6];
    goto v32;

v32:
    v216 = stack[-5];
    v216 = qcdr(v216);
    stack[-5] = v216;
    goto v96;

v9:
    v216 = nil;
    { popv(7); return onevalue(v216); }
/* error exit handlers */
v105:
    popv(7);
    return nil;
}



/* Code for ratpoly_deg */

static Lisp_Object CC_ratpoly_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v58 = v11;
    stack[0] = v0;
/* end of prologue */
    v34 = stack[0];
    fn = elt(env, 1); /* ratpoly_mvartest */
    v58 = (*qfn2(fn))(qenv(fn), v34, v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-1];
    if (v58 == nil) goto v17;
    v58 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_ldeg */
        return (*qfn1(fn))(qenv(fn), v58);
    }

v17:
    v58 = stack[0];
    fn = elt(env, 3); /* ratpoly_nullp */
    v58 = (*qfn1(fn))(qenv(fn), v58);
    nil = C_nil;
    if (exception_pending()) goto v220;
    if (v58 == nil) goto v70;
    v58 = (Lisp_Object)-15; /* -1 */
    { popv(2); return onevalue(v58); }

v70:
    v58 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v58); }
/* error exit handlers */
v220:
    popv(2);
    return nil;
}



/* Code for ir2om */

static Lisp_Object CC_ir2om(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37;
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
    v37 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v37; /* ind */
    v37 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v37; /* indent */
    v37 = elt(env, 3); /* "<OMOBJ>" */
    fn = elt(env, 7); /* printout */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    v37 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 8); /* indent!* */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    v37 = stack[0];
    fn = elt(env, 9); /* objectom */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    v37 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-1];
    v37 = elt(env, 6); /* "</OMOBJ>" */
    fn = elt(env, 7); /* printout */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v186;
    v37 = nil;
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v186:
    popv(2);
    return nil;
}



/* Code for rowdel */

static Lisp_Object CC_rowdel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v78, v79;
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
    v26 = stack[0];
    fn = elt(env, 4); /* delhisto */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v78 = qvalue(elt(env, 2)); /* maxvar */
    v26 = stack[0];
    v26 = plus2(v78, v26);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v79 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v26/(16/CELL)));
    v78 = (Lisp_Object)1; /* 0 */
    v26 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v79 + (CELL-TAG_VECTOR) + ((int32_t)v78/(16/CELL))) = v26;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v78 = qvalue(elt(env, 2)); /* maxvar */
    v26 = stack[0];
    v26 = plus2(v78, v26);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v78 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v26/(16/CELL)));
    v26 = (Lisp_Object)65; /* 4 */
    v26 = *(Lisp_Object *)((char *)v78 + (CELL-TAG_VECTOR) + ((int32_t)v26/(16/CELL)));
    stack[0] = v26;
    goto v82;

v82:
    v26 = stack[0];
    if (v26 == nil) goto v46;
    v26 = stack[0];
    v26 = qcar(v26);
    v78 = v26;
    v78 = qcar(v78);
    v26 = qcdr(v26);
    v26 = qcar(v26);
    fn = elt(env, 5); /* downwght */
    v26 = (*qfn2(fn))(qenv(fn), v78, v26);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-2];
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v82;

v46:
    v26 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v26); }
/* error exit handlers */
v80:
    popv(3);
    return nil;
}



/* Code for bcquot */

static Lisp_Object CC_bcquot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcquot");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v48 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v48 == nil) goto v17;
    v48 = stack[0];
    v48 = Lmodular_reciprocal(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v48 = times2(stack[-1], v48);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v48);
    }

v17:
    v48 = qvalue(elt(env, 2)); /* !*vdpinteger */
    if (v48 == nil) goto v78;
    v61 = stack[-1];
    v49 = stack[0];
    v48 = elt(env, 3); /* quotientx */
    fn = elt(env, 7); /* bcint2op */
    v48 = (*qfnn(fn))(qenv(fn), 3, v61, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (!(v48 == nil)) { popv(3); return onevalue(v48); }
    v48 = qvalue(elt(env, 4)); /* !*exp */
    if (v48 == nil) goto v92;
    v48 = qvalue(elt(env, 5)); /* !*mcd */
    if (v48 == nil) goto v92;
    v48 = stack[-1];
    v49 = qcar(v48);
    v48 = stack[0];
    v48 = qcar(v48);
    fn = elt(env, 8); /* quotfx1 */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v49 = v48;
    goto v10;

v10:
    v48 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v49, v48);

v92:
    v48 = stack[-1];
    v49 = qcar(v48);
    v48 = stack[0];
    v48 = qcar(v48);
    fn = elt(env, 9); /* quotf */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v49 = v48;
    goto v10;

v78:
    v48 = stack[0];
    fn = elt(env, 10); /* invsq */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    {
        Lisp_Object v65 = stack[-1];
        popv(3);
        fn = elt(env, 11); /* multsq */
        return (*qfn2(fn))(qenv(fn), v65, v48);
    }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for freeoffl */

static Lisp_Object CC_freeoffl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeoffl");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */

v187:
    v5 = stack[0];
    v5 = (v5 == nil ? lisp_true : nil);
    if (!(v5 == nil)) { popv(3); return onevalue(v5); }
    v6 = stack[-1];
    v5 = stack[0];
    v5 = qcar(v5);
    fn = elt(env, 2); /* freeoff */
    v5 = (*qfn2(fn))(qenv(fn), v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    if (v5 == nil) goto v163;
    v6 = stack[-1];
    v5 = stack[0];
    v5 = qcdr(v5);
    stack[-1] = v6;
    stack[0] = v5;
    goto v187;

v163:
    v5 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v55:
    popv(3);
    return nil;
}



/* Code for xord_deglex */

static Lisp_Object CC_xord_deglex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v30, v31, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_deglex");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v74 = stack[-1];
    v30 = qcar(v74);
    v74 = (Lisp_Object)17; /* 1 */
    if (v30 == v74) goto v8;
    v74 = stack[0];
    v30 = qcar(v74);
    v74 = (Lisp_Object)17; /* 1 */
    if (v30 == v74) goto v37;
    v74 = stack[-1];
    fn = elt(env, 3); /* xdegreemon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v74 = stack[0];
    fn = elt(env, 3); /* xdegreemon */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v94 = stack[-2];
    v31 = v74;
    v30 = v94;
    v74 = v31;
    if (equal(v30, v74)) goto v33;
    v74 = v94;
    v30 = v31;
        popv(4);
        return Lgreaterp(nil, v74, v30);

v33:
    v30 = stack[-1];
    v74 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v30, v74);
    }

v37:
    v74 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v74); }

v8:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v74); }
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for oprinla */

static Lisp_Object CC_oprinla(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v92, v222;
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
    v92 = v0;
/* end of prologue */
    v222 = v92;
    v93 = elt(env, 1); /* lapr */
    v93 = get(v222, v93);
    env = stack[0];
    v222 = v93;
    if (v93 == nil) goto v70;
    v93 = v222;
    fn = elt(env, 5); /* prin2la */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v66;
    goto v17;

v17:
    v93 = nil;
    { popv(1); return onevalue(v93); }

v70:
    v222 = v92;
    v93 = elt(env, 2); /* prtch */
    v93 = get(v222, v93);
    env = stack[0];
    v222 = v93;
    if (v93 == nil) goto v6;
    v93 = v222;
    fn = elt(env, 5); /* prin2la */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v66;
    goto v17;

v6:
    v222 = v92;
    v93 = elt(env, 3); /* lapop */
    v93 = get(v222, v93);
    env = stack[0];
    v222 = v93;
    if (v93 == nil) goto v32;
    v93 = v222;
    fn = elt(env, 5); /* prin2la */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[0];
    v93 = elt(env, 4); /* !  */
    fn = elt(env, 5); /* prin2la */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v66;
    goto v17;

v32:
    v93 = v92;
    fn = elt(env, 6); /* prinlatom */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v66;
    goto v17;
/* error exit handlers */
v66:
    popv(1);
    return nil;
}



/* Code for physop2sq */

static Lisp_Object CC_physop2sq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v228, v134;
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

v187:
    v213 = stack[0];
    fn = elt(env, 5); /* physopp */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    if (v213 == nil) goto v9;
    v228 = stack[0];
    v213 = elt(env, 1); /* rvalue */
    v213 = get(v228, v213);
    env = stack[-2];
    stack[-1] = v213;
    if (v213 == nil) goto v60;
    v213 = stack[-1];
    stack[0] = v213;
    goto v187;

v60:
    v213 = stack[0];
    if (symbolp(v213)) goto v56;
    v213 = stack[0];
    v228 = qcar(v213);
    v213 = elt(env, 2); /* psimpfn */
    v213 = get(v228, v213);
    env = stack[-2];
    stack[-1] = v213;
    if (v213 == nil) goto v230;
    v228 = stack[-1];
    v213 = stack[0];
    v213 = Lapply1(nil, v228, v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    stack[-1] = v213;
    fn = elt(env, 5); /* physopp */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    if (v213 == nil) goto v71;
    v134 = stack[-1];
    v228 = (Lisp_Object)17; /* 1 */
    v213 = (Lisp_Object)17; /* 1 */
    v213 = acons(v134, v228, v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    v228 = ncons(v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v213 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v228, v213);

v71:
    v213 = stack[-1];
    fn = elt(env, 6); /* physopsm!* */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v213 = qcdr(v213);
    v213 = qcar(v213);
    { popv(3); return onevalue(v213); }

v230:
    v213 = stack[0];
    v228 = qcar(v213);
    v213 = elt(env, 3); /* opmtch */
    v213 = get(v228, v213);
    env = stack[-2];
    if (v213 == nil) goto v145;
    v213 = stack[0];
    fn = elt(env, 7); /* opmtch!* */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    stack[-1] = v213;
    if (v213 == nil) goto v145;
    v213 = stack[-1];
    stack[0] = v213;
    goto v187;

v145:
    v134 = stack[0];
    v228 = (Lisp_Object)17; /* 1 */
    v213 = (Lisp_Object)17; /* 1 */
    v213 = acons(v134, v228, v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    v228 = ncons(v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v213 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v228, v213);

v56:
    v134 = stack[0];
    v228 = (Lisp_Object)17; /* 1 */
    v213 = (Lisp_Object)17; /* 1 */
    v213 = acons(v134, v228, v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    v228 = ncons(v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    v213 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v228, v213);

v9:
    v213 = stack[0];
    if (!consp(v213)) goto v231;
    v213 = stack[0];
    v228 = qcar(v213);
    v213 = elt(env, 4); /* !*sq */
    if (v228 == v213) goto v39;
    v213 = stack[0];
    fn = elt(env, 8); /* getphystype */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    if (v213 == nil) goto v232;
    v213 = stack[0];
    fn = elt(env, 6); /* physopsm!* */
    v213 = (*qfn1(fn))(qenv(fn), v213);
    nil = C_nil;
    if (exception_pending()) goto v229;
    env = stack[-2];
    stack[0] = v213;
    goto v187;

v232:
    v213 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* simp */
        return (*qfn1(fn))(qenv(fn), v213);
    }

v39:
    v213 = stack[0];
    v213 = qcdr(v213);
    v213 = qcar(v213);
    { popv(3); return onevalue(v213); }

v231:
    v213 = stack[0];
    {
        popv(3);
        fn = elt(env, 9); /* simp */
        return (*qfn1(fn))(qenv(fn), v213);
    }
/* error exit handlers */
v229:
    popv(3);
    return nil;
}



/* Code for total!-degree!-in!-powers */

static Lisp_Object CC_totalKdegreeKinKpowers(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v214, v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for total-degree-in-powers");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */

v187:
    v146 = stack[-1];
    if (v146 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v146 = stack[-1];
    if (!consp(v146)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v146 = stack[-1];
    v146 = qcar(v146);
    if (!consp(v146)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v146 = stack[-1];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v214 = qcar(v146);
    v146 = stack[0];
    v146 = Latsoc(nil, v214, v146);
    stack[-2] = v146;
    if (v146 == nil) goto v27;
    v146 = stack[-1];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v214 = qcdr(v146);
    v146 = stack[-2];
    v146 = qcdr(v146);
    v146 = (Lisp_Object)greaterp2(v214, v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v146 = v146 ? lisp_true : nil;
    env = stack[-3];
    if (v146 == nil) goto v62;
    v214 = stack[-2];
    v146 = stack[-1];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = Lrplacd(nil, v214, v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    goto v62;

v62:
    v146 = stack[-1];
    stack[-2] = qcdr(v146);
    v146 = stack[-1];
    v146 = qcar(v146);
    v214 = qcdr(v146);
    v146 = stack[0];
    v146 = CC_totalKdegreeKinKpowers(env, v214, v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v146;
    goto v187;

v27:
    v146 = stack[-1];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v77 = qcar(v146);
    v146 = stack[-1];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v214 = qcdr(v146);
    v146 = stack[0];
    v146 = acons(v77, v214, v146);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-3];
    stack[0] = v146;
    goto v62;
/* error exit handlers */
v89:
    popv(4);
    return nil;
}



/* Code for assert_uninstall_all */

static Lisp_Object MS_CDECL CC_assert_uninstall_all(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall_all");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v9 = qvalue(elt(env, 1)); /* !*assert */
    if (v9 == nil) goto v20;
    v9 = qvalue(elt(env, 2)); /* assert_functionl!* */
    {
        fn = elt(env, 3); /* assert_uninstall */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v20:
    v9 = nil;
    return onevalue(v9);
}



/* Code for dssoc */

static Lisp_Object CC_dssoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2, v82, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dssoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v82 = v11;
    v81 = v0;
/* end of prologue */

v8:
    v1 = v82;
    if (v1 == nil) goto v9;
    v2 = v81;
    v1 = v82;
    v1 = qcar(v1);
    v1 = qcdr(v1);
    if (equal(v2, v1)) goto v87;
    v1 = v82;
    v1 = qcdr(v1);
    v82 = v1;
    goto v8;

v87:
    v1 = v82;
    v1 = qcar(v1);
    return onevalue(v1);

v9:
    v1 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v1);
}



/* Code for xremainder!-mod!-p */

static Lisp_Object MS_CDECL CC_xremainderKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v181, v235, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremainder-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xremainder-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-2] = v11;
    stack[-3] = v0;
/* end of prologue */

v187:
    v181 = stack[-3];
    if (!consp(v181)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v181 = stack[-3];
    v181 = qcar(v181);
    if (!consp(v181)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v181 = stack[-3];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v235 = qcar(v181);
    v181 = stack[-1];
    if (!(equal(v235, v181))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v181 = stack[-3];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v235 = qcdr(v181);
    v181 = stack[-2];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = qcdr(v181);
    if (((int32_t)(v235)) < ((int32_t)(v181))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v181 = stack[-3];
    v181 = qcar(v181);
    v181 = qcdr(v181);
    fn = elt(env, 1); /* minus!-mod!-p */
    v235 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    v181 = stack[-2];
    v181 = qcar(v181);
    v181 = qcdr(v181);
    fn = elt(env, 2); /* quotient!-mod!-p */
    v181 = (*qfn2(fn))(qenv(fn), v235, v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    stack[-4] = v181;
    v181 = stack[-3];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v235 = qcdr(v181);
    v181 = stack[-2];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = qcdr(v181);
    v181 = (Lisp_Object)(int32_t)((int32_t)v235 - (int32_t)v181 + TAG_FIXNUM);
    stack[0] = v181;
    v235 = stack[0];
    v181 = (Lisp_Object)1; /* 0 */
    if (v235 == v181) goto v61;
    v181 = stack[-3];
    stack[-3] = qcdr(v181);
    v181 = stack[-2];
    v181 = qcar(v181);
    v181 = qcar(v181);
    v181 = qcar(v181);
    fn = elt(env, 3); /* fkern */
    v235 = (*qfn1(fn))(qenv(fn), v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    v181 = stack[0];
    fn = elt(env, 4); /* getpower */
    v235 = (*qfn2(fn))(qenv(fn), v235, v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    v181 = stack[-4];
    v235 = cons(v235, v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    v181 = stack[-2];
    v181 = qcdr(v181);
    fn = elt(env, 5); /* times!-term!-mod!-p */
    v181 = (*qfn2(fn))(qenv(fn), v235, v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    fn = elt(env, 6); /* plus!-mod!-p */
    v181 = (*qfn2(fn))(qenv(fn), stack[-3], v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    stack[-3] = v181;
    goto v39;

v39:
    v236 = stack[-3];
    v235 = stack[-2];
    v181 = stack[-1];
    stack[-3] = v236;
    stack[-2] = v235;
    stack[-1] = v181;
    goto v187;

v61:
    v181 = stack[-3];
    stack[0] = qcdr(v181);
    v181 = stack[-2];
    v235 = qcdr(v181);
    v181 = stack[-4];
    fn = elt(env, 7); /* multiply!-by!-constant!-mod!-p */
    v181 = (*qfn2(fn))(qenv(fn), v235, v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    fn = elt(env, 6); /* plus!-mod!-p */
    v181 = (*qfn2(fn))(qenv(fn), stack[0], v181);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-5];
    stack[-3] = v181;
    goto v39;
/* error exit handlers */
v140:
    popv(6);
    return nil;
}



/* Code for gitimes!: */

static Lisp_Object CC_gitimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v237, v69, v68, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gitimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v237 = v11;
    v69 = v0;
/* end of prologue */
    v68 = v69;
    v68 = qcdr(v68);
    v25 = qcar(v68);
    v69 = qcdr(v69);
    v68 = qcdr(v69);
    v69 = v237;
    v69 = qcdr(v69);
    v69 = qcar(v69);
    v237 = qcdr(v237);
    v237 = qcdr(v237);
    stack[-5] = v25;
    stack[-4] = v68;
    stack[-3] = v69;
    stack[-2] = v237;
    stack[-1] = elt(env, 1); /* !:gi!: */
    v69 = stack[-5];
    v237 = stack[-3];
    stack[0] = times2(v69, v237);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-6];
    v69 = stack[-4];
    v237 = stack[-2];
    v237 = times2(v69, v237);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-6];
    stack[0] = difference2(stack[0], v237);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-6];
    v69 = stack[-5];
    v237 = stack[-2];
    stack[-2] = times2(v69, v237);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-6];
    v69 = stack[-3];
    v237 = stack[-4];
    v237 = times2(v69, v237);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-6];
    v237 = plus2(stack[-2], v237);
    nil = C_nil;
    if (exception_pending()) goto v47;
    {
        Lisp_Object v48 = stack[-1];
        Lisp_Object v49 = stack[0];
        popv(7);
        return list2star(v48, v49, v237);
    }
/* error exit handlers */
v47:
    popv(7);
    return nil;
}



/* Code for ofsf_clnegrel */

static Lisp_Object CC_ofsf_clnegrel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_clnegrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v59 = v11;
    v60 = v0;
/* end of prologue */
    if (!(v59 == nil)) return onevalue(v60);
    v59 = v60;
    {
        fn = elt(env, 1); /* ofsf_lnegrel */
        return (*qfn1(fn))(qenv(fn), v59);
    }
}



/* Code for texstrlen */

static Lisp_Object CC_texstrlen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v33, v54;
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
    v53 = v0;
/* end of prologue */
    v33 = (Lisp_Object)1; /* 0 */
    v54 = v33;
    v33 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v53;
    goto v87;

v87:
    v53 = stack[0];
    if (v53 == nil) { popv(2); return onevalue(v54); }
    v53 = stack[0];
    v53 = qcar(v53);
    if (!(v33 == nil)) goto v10;
    v33 = v53;
    v53 = elt(env, 2); /* !! */
    if (!(v33 == v53)) goto v10;
    v53 = qvalue(elt(env, 3)); /* t */
    v33 = v53;
    goto v57;

v57:
    v53 = stack[0];
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v87;

v10:
    v53 = v54;
    v53 = add1(v53);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    v54 = v53;
    v53 = qvalue(elt(env, 1)); /* nil */
    v33 = v53;
    goto v57;
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for mkprod */

static Lisp_Object CC_mkprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v251;
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
    v250 = stack[-4];
    if (v250 == nil) goto v87;
    v250 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    if (!(v250 == nil)) goto v87;
    v250 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v250; /* !*sub2 */
    v251 = stack[-4];
    v250 = (Lisp_Object)17; /* 1 */
    v250 = cons(v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    fn = elt(env, 11); /* subs2 */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[0] = v250;
    v250 = stack[0];
    v251 = qcdr(v250);
    v250 = (Lisp_Object)17; /* 1 */
    if (v251 == v250) goto v32;
    v250 = stack[-4];
    goto v96;

v96:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    { popv(7); return onevalue(v250); }

v32:
    v250 = stack[0];
    v251 = qcar(v250);
    v250 = stack[-4];
    if (equal(v251, v250)) goto v82;
    v250 = stack[0];
    v250 = qcar(v250);
    stack[-4] = v250;
    v250 = stack[-4];
    if (v250 == nil) goto v83;
    v250 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    if (!(v250 == nil)) goto v83;

v82:
    v250 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v250; /* !*exp */
    v250 = stack[-4];
    fn = elt(env, 12); /* ckrn */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[-5] = v250;
    v251 = stack[-4];
    v250 = stack[-5];
    fn = elt(env, 13); /* quotf */
    v250 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[-4] = v250;
    v250 = stack[-4];
    fn = elt(env, 14); /* expnd */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[0] = v250;
    v250 = stack[0];
    if (v250 == nil) goto v64;
    v250 = stack[0];
    fn = elt(env, 10); /* kernlp */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    if (!(v250 == nil)) goto v64;
    v250 = qvalue(elt(env, 4)); /* !*mcd */
    if (v250 == nil) goto v21;
    v250 = qvalue(elt(env, 5)); /* !*sqfree */
    if (!(v250 == nil)) goto v24;
    v250 = qvalue(elt(env, 6)); /* !*factor */
    if (!(v250 == nil)) goto v24;
    v250 = qvalue(elt(env, 7)); /* !*gcd */
    if (!(v250 == nil)) goto v24;

v21:
    v250 = stack[0];
    fn = elt(env, 12); /* ckrn */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[-3] = v250;
    v251 = stack[0];
    v250 = stack[-3];
    fn = elt(env, 13); /* quotf */
    v250 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[0] = v250;
    v251 = stack[0];
    v250 = (Lisp_Object)17; /* 1 */
    v250 = cons(v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    v250 = list2(stack[-3], v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[-3] = v250;
    goto v252;

v252:
    v250 = stack[-3];
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v251 = qcdr(v250);
    v250 = (Lisp_Object)17; /* 1 */
    v250 = (Lisp_Object)greaterp2(v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    v250 = v250 ? lisp_true : nil;
    env = stack[-6];
    if (!(v250 == nil)) goto v39;
    v250 = stack[-3];
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    if (!(v250 == nil)) goto v39;
    v250 = qvalue(elt(env, 9)); /* !*group */
    if (!(v250 == nil)) goto v253;
    v250 = stack[-4];
    fn = elt(env, 15); /* tmsf */
    stack[0] = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    v250 = stack[-3];
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = qcar(v250);
    fn = elt(env, 15); /* tmsf */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    v250 = (Lisp_Object)greaterp2(stack[0], v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    v250 = v250 ? lisp_true : nil;
    env = stack[-6];
    if (v250 == nil) goto v253;
    v250 = stack[-3];
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v251 = qcar(v250);
    v250 = stack[-3];
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = qcdr(v250);
    fn = elt(env, 16); /* mksp!* */
    v251 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    v250 = stack[-3];
    v250 = qcar(v250);
    fn = elt(env, 17); /* multf */
    v250 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[0] = v250;
    goto v125;

v125:
    v251 = stack[-5];
    v250 = stack[0];
    fn = elt(env, 17); /* multf */
    v250 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    goto v96;

v253:
    v251 = stack[-4];
    v250 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksp!* */
    v250 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[0] = v250;
    goto v125;

v39:
    v250 = stack[-3];
    v250 = qcar(v250);
    stack[0] = v250;
    v250 = stack[-3];
    v250 = qcdr(v250);
    stack[-3] = v250;
    goto v212;

v212:
    v250 = stack[-3];
    if (v250 == nil) goto v125;
    v250 = stack[-3];
    v250 = qcar(v250);
    v251 = v250;
    v251 = qcar(v251);
    v250 = qcdr(v250);
    fn = elt(env, 16); /* mksp!* */
    v251 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    v250 = stack[0];
    fn = elt(env, 17); /* multf */
    v250 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[0] = v250;
    v250 = stack[-3];
    v250 = qcdr(v250);
    stack[-3] = v250;
    goto v212;

v24:
    v250 = stack[0];
    fn = elt(env, 18); /* fctrf */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    stack[-3] = v250;
    goto v252;

v64:
    v251 = stack[-5];
    v250 = stack[0];
    fn = elt(env, 17); /* multf */
    v250 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-6];
    goto v96;

v83:
    v250 = stack[-4];
    goto v96;

v87:
    v250 = stack[-4];
    goto v96;
/* error exit handlers */
v123:
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
    Lisp_Object v74, v30;
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

v20:
    v74 = stack[0];
    if (!consp(v74)) goto v73;
    v74 = stack[0];
    v74 = qcar(v74);
    if (!consp(v74)) goto v73;
    v74 = stack[0];
    v74 = qcdr(v74);
    if (!consp(v74)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v74 = stack[0];
    v74 = qcdr(v74);
    v74 = qcar(v74);
    if (!consp(v74)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v74 = stack[0];
    v74 = qcdr(v74);
    stack[0] = v74;
    goto v20;

v73:
    v74 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 9); /* terpri!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    v74 = elt(env, 2); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 10); /* lprie */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    v30 = elt(env, 3); /* "non-domain" */
    v74 = stack[0];
    v74 = list2(v30, v74);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    fn = elt(env, 11); /* printty */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    v30 = elt(env, 4); /* " " */
    v74 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 12); /* lpriw */
    v74 = (*qfn2(fn))(qenv(fn), v30, v74);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    v74 = elt(env, 6); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v30 = v74;
    v74 = v30;
    qvalue(elt(env, 7)) = v74; /* errmsg!* */
    v74 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v74 == nil)) goto v191;
    v74 = v30;
    fn = elt(env, 10); /* lprie */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-1];
    goto v191;

v191:
    v74 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v94;
    v74 = nil;
    { popv(2); return onevalue(v74); }
/* error exit handlers */
v94:
    popv(2);
    return nil;
}



/* Code for aex_subrat1 */

static Lisp_Object MS_CDECL CC_aex_subrat1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v82, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_subrat1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_subrat1");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v11;
    stack[-2] = v0;
/* end of prologue */
    v2 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v81 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v82 = stack[-1];
    v2 = stack[0];
    fn = elt(env, 3); /* ratpoly_subrat1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v81, v82, v2);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v2 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v81 = (*qfn1(fn))(qenv(fn), v2);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-3];
    v82 = qvalue(elt(env, 1)); /* nil */
    v2 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v55 = stack[0];
        popv(4);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v55, v81, v82, v2);
    }
/* error exit handlers */
v56:
    popv(4);
    return nil;
}



/* Code for tobvarir */

static Lisp_Object CC_tobvarir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v82;
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
    v2 = stack[-1];
    if (v2 == nil) goto v8;
    stack[-2] = elt(env, 1); /* bvar */
    v2 = stack[-1];
    v82 = qcar(v2);
    v2 = (Lisp_Object)17; /* 1 */
    stack[0] = list2(v82, v2);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-3];
    v2 = stack[-1];
    v2 = qcdr(v2);
    v2 = CC_tobvarir(env, v2);
    nil = C_nil;
    if (exception_pending()) goto v7;
    {
        Lisp_Object v56 = stack[-2];
        Lisp_Object v55 = stack[0];
        popv(4);
        return acons(v56, v55, v2);
    }

v8:
    v2 = nil;
    { popv(4); return onevalue(v2); }
/* error exit handlers */
v7:
    popv(4);
    return nil;
}



/* Code for ps!:evaluate!-next */

static Lisp_Object CC_psTevaluateKnext(Lisp_Object env,
                         Lisp_Object v11, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate-next");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v11);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v11,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v4;
    v46 = v11;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v46; /* ps */
    v83 = qvalue(elt(env, 1)); /* ps */
    v46 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 3); /* ps!:getv */
    v46 = (*qfn2(fn))(qenv(fn), v83, v46);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    v83 = qcar(v46);
    v46 = elt(env, 2); /* ps!:erule */
    stack[0] = get(v83, v46);
    env = stack[-4];
    v46 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:expression */
    v83 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    v46 = stack[-2];
    v46 = list2(v83, v46);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    fn = elt(env, 5); /* apply */
    v46 = (*qfn2(fn))(qenv(fn), stack[0], v46);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    stack[-1] = v46;
    stack[0] = qvalue(elt(env, 1)); /* ps */
    v46 = stack[-1];
    fn = elt(env, 6); /* prepsqxx */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    fn = elt(env, 7); /* simp!* */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    stack[-1] = v46;
    fn = elt(env, 8); /* ps!:set!-term */
    v46 = (*qfnn(fn))(qenv(fn), 3, stack[0], stack[-2], v46);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-4];
    v46 = stack[-1];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v46); }
/* error exit handlers */
v221:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for lid */

static Lisp_Object CC_lid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v59;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lid");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v0;
/* end of prologue */
    v59 = v87;
    if (!consp(v59)) return onevalue(v87);
    v87 = qcar(v87);
    return onevalue(v87);
}



/* Code for indord2 */

static Lisp_Object CC_indord2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indord2");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v6 = stack[-1];
    v5 = stack[0];
    fn = elt(env, 1); /* indordp */
    v5 = (*qfn2(fn))(qenv(fn), v6, v5);
    nil = C_nil;
    if (exception_pending()) goto v55;
    if (v5 == nil) goto v34;
    v6 = stack[-1];
    v5 = stack[0];
    popv(2);
    return list2(v6, v5);

v34:
    v6 = stack[0];
    v5 = stack[-1];
    popv(2);
    return list2(v6, v5);
/* error exit handlers */
v55:
    popv(2);
    return nil;
}



/* Code for quotfail1 */

static Lisp_Object MS_CDECL CC_quotfail1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "quotfail1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail1");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    v6 = v11;
    v7 = v0;
/* end of prologue */
    v5 = v7;
    if (v5 == nil) goto v17;
    v5 = v7;
    fn = elt(env, 2); /* quotf */
    v5 = (*qfn2(fn))(qenv(fn), v5, v6);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v6 = v5;
    v5 = v6;
    if (!(v5 == nil)) { popv(2); return onevalue(v6); }
    v5 = stack[0];
    fn = elt(env, 3); /* errorf */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v5 = nil;
    { popv(2); return onevalue(v5); }

v17:
    v5 = qvalue(elt(env, 1)); /* polyzero */
    { popv(2); return onevalue(v5); }
/* error exit handlers */
v55:
    popv(2);
    return nil;
}



/* Code for my_freeof */

static Lisp_Object CC_my_freeof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my_freeof");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v2 = stack[0];
    v1 = stack[-1];
    fn = elt(env, 3); /* smember */
    v1 = (*qfn2(fn))(qenv(fn), v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    if (v1 == nil) goto v184;
    v1 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v1); }

v184:
    v82 = qvalue(elt(env, 2)); /* depl!* */
    v2 = stack[-1];
    v1 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeofdepl */
        return (*qfnn(fn))(qenv(fn), 3, v82, v2, v1);
    }
/* error exit handlers */
v6:
    popv(3);
    return nil;
}



/* Code for physopsm!* */

static Lisp_Object CC_physopsmH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v269, v161, v270;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsm*");
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
    stack[0] = nil;
    v268 = stack[-3];
    if (v268 == nil) goto v86;
    v268 = stack[-3];
    if (is_number(v268)) goto v86;
    v268 = stack[-3];
    fn = elt(env, 13); /* physopp */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    if (v268 == nil) goto v184;
    v269 = stack[-3];
    v268 = elt(env, 1); /* rvalue */
    v268 = get(v269, v268);
    env = stack[-5];
    stack[-1] = v268;
    if (v268 == nil) goto v58;
    v268 = stack[-1];
    fn = elt(env, 14); /* physopaeval */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    goto v3;

v3:
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v58:
    v268 = stack[-3];
    if (symbolp(v268)) goto v56;
    v268 = stack[-3];
    v269 = qcar(v268);
    v268 = elt(env, 2); /* psimpfn */
    v268 = get(v269, v268);
    env = stack[-5];
    stack[-1] = v268;
    if (v268 == nil) goto v223;
    v269 = stack[-1];
    v268 = stack[-3];
    v268 = Lapply1(nil, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    goto v3;

v223:
    v268 = stack[-3];
    v269 = qcar(v268);
    v268 = elt(env, 3); /* opmtch */
    v268 = get(v269, v268);
    env = stack[-5];
    if (v268 == nil) goto v25;
    v268 = stack[-3];
    fn = elt(env, 15); /* opmtch!* */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    stack[-1] = v268;
    if (v268 == nil) goto v25;
    v268 = stack[-1];
    goto v3;

v25:
    v268 = stack[-3];
    goto v3;

v56:
    v268 = stack[-3];
    goto v3;

v184:
    v268 = stack[-3];
    if (!consp(v268)) goto v79;
    v268 = stack[-3];
    v268 = qcar(v268);
    stack[-4] = v268;
    v268 = stack[-3];
    v268 = qcdr(v268);
    stack[-2] = v268;
    v269 = stack[-4];
    v268 = elt(env, 4); /* physopfunction */
    v268 = get(v269, v268);
    env = stack[-5];
    stack[-1] = v268;
    if (v268 == nil) goto v209;
    v269 = stack[-4];
    v268 = elt(env, 5); /* physoparith */
    v268 = Lflagp(nil, v269, v268);
    env = stack[-5];
    if (v268 == nil) goto v172;
    v268 = stack[-2];
    fn = elt(env, 16); /* hasonephysop */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    if (v268 == nil) goto v127;
    stack[0] = stack[-1];
    v268 = stack[-2];
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v268 = (*qfn2(fn))(qenv(fn), stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v127:
    v269 = stack[-4];
    v268 = stack[-2];
    v268 = cons(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    fn = elt(env, 18); /* reval3 */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v172:
    v269 = stack[-4];
    v268 = elt(env, 6); /* physopfn */
    v268 = Lflagp(nil, v269, v268);
    env = stack[-5];
    if (v268 == nil) goto v245;
    v268 = stack[-2];
    fn = elt(env, 19); /* areallphysops */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    if (v268 == nil) goto v211;
    stack[0] = stack[-1];
    v268 = stack[-2];
    v268 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v268 = (*qfn2(fn))(qenv(fn), stack[0], v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v211:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v270 = elt(env, 7); /* "invalid call of " */
    v161 = stack[-4];
    v269 = elt(env, 8); /* " with args: " */
    v268 = stack[-2];
    v268 = list4(v270, v161, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v268 = (*qfn2(fn))(qenv(fn), stack[-1], v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v245:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v161 = stack[-4];
    v269 = elt(env, 9); /* " has been flagged Physopfunction" */
    v268 = elt(env, 10); /* " but is not defined" */
    v268 = list3(v161, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v268 = (*qfn2(fn))(qenv(fn), stack[-1], v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v209:
    v269 = stack[-4];
    v268 = elt(env, 11); /* physopmapping */
    v268 = Lflagp(nil, v269, v268);
    env = stack[-5];
    if (v268 == nil) goto v239;
    v268 = stack[-2];
    fn = elt(env, 21); /* !*physopp!* */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    if (v268 == nil) goto v239;
    v269 = stack[-4];
    v268 = stack[-2];
    v161 = cons(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v269 = (Lisp_Object)17; /* 1 */
    v268 = (Lisp_Object)17; /* 1 */
    v268 = acons(v161, v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v269 = ncons(v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    v268 = (Lisp_Object)17; /* 1 */
    v268 = cons(v269, v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-5];
    fn = elt(env, 22); /* mk!*sq */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v239:
    v269 = stack[-4];
    v268 = elt(env, 12); /* prog */
    if (v269 == v268) goto v272;
    v268 = stack[-3];
    fn = elt(env, 23); /* aeval */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v272:
    v268 = stack[-2];
    fn = elt(env, 24); /* physopprog */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v79:
    v268 = stack[-3];
    fn = elt(env, 23); /* aeval */
    v268 = (*qfn1(fn))(qenv(fn), v268);
    nil = C_nil;
    if (exception_pending()) goto v271;
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v86:
    v268 = stack[-3];
    stack[0] = v268;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
/* error exit handlers */
v271:
    popv(6);
    return nil;
}



/* Code for setk */

static Lisp_Object CC_setk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v146, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setk");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    v146 = v0;
/* end of prologue */
    v178 = v146;
    if (!consp(v178)) goto v24;
    v178 = v146;
    v214 = qcar(v178);
    v178 = elt(env, 1); /* evalargfn */
    v178 = get(v214, v178);
    env = stack[-2];
    v214 = v178;
    v178 = v214;
    if (v178 == nil) goto v29;
    v178 = v146;
    stack[-1] = qcar(v178);
    v178 = v214;
    v146 = qcdr(v146);
    v178 = Lapply1(nil, v178, v146);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v146 = cons(stack[-1], v178);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v178 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v146, v178);
    }

v29:
    v178 = v146;
    v214 = qcar(v178);
    v178 = elt(env, 2); /* rtype */
    v214 = get(v214, v178);
    env = stack[-2];
    v178 = elt(env, 3); /* matrix */
    if (v214 == v178) goto v94;
    v178 = v146;
    stack[-1] = qcar(v178);
    v178 = v146;
    v178 = qcdr(v178);
    fn = elt(env, 5); /* revlis */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v146 = cons(stack[-1], v178);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v178 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v146, v178);
    }

v94:
    v178 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v146, v178);
    }

v24:
    v178 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v146, v178);
    }
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for mv!-domainlist */

static Lisp_Object CC_mvKdomainlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist");
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
    v220 = nil;
    goto v8;

v8:
    v35 = stack[0];
    if (v35 == nil) goto v9;
    v35 = stack[0];
    v35 = qcar(v35);
    v35 = qcdr(v35);
    v35 = cons(v35, v220);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-1];
    v220 = v35;
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[0] = v35;
    goto v8;

v9:
    v35 = v220;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v35);
    }
/* error exit handlers */
v2:
    popv(2);
    return nil;
}



/* Code for addgt */

static Lisp_Object CC_addgt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addgt");
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
    v5 = qvalue(elt(env, 1)); /* ordering */
    v81 = elt(env, 2); /* lex */
    if (v5 == v81) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v5 = elt(env, 3); /* plus */
    v81 = stack[0];
    v81 = cons(v5, v81);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    fn = elt(env, 4); /* eval */
    v5 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v7;
    v81 = stack[0];
    popv(2);
    return cons(v5, v81);
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for st_consolidate */

static Lisp_Object CC_st_consolidate(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v232;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_consolidate");
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
    stack[-1] = nil;
    v236 = stack[-3];
    if (v236 == nil) goto v96;
    v236 = stack[-3];
    v236 = qcdr(v236);
    v236 = qcar(v236);
    if (is_number(v236)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v236 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v236;
    v236 = stack[-3];
    v236 = qcdr(v236);
    v236 = Lreverse(nil, v236);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    stack[0] = v236;
    goto v58;

v58:
    v236 = stack[0];
    if (v236 == nil) goto v57;
    v236 = stack[0];
    v236 = qcar(v236);
    v236 = CC_st_consolidate(env, v236);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    v232 = v236;
    if (v232 == nil) goto v179;
    v232 = v236;
    v232 = qcdr(v232);
    v232 = qcdr(v232);
    if (v232 == nil) goto v46;
    v232 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v232;
    goto v31;

v31:
    v232 = v236;
    v236 = stack[-1];
    v236 = cons(v232, v236);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    stack[-1] = v236;
    goto v179;

v179:
    v236 = stack[0];
    v236 = qcdr(v236);
    stack[0] = v236;
    goto v58;

v46:
    v232 = elt(env, 3); /* !* */
    v236 = qcdr(v236);
    v236 = qcar(v236);
    v236 = list2(v232, v236);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    goto v31;

v57:
    v236 = stack[-1];
    if (v236 == nil) goto v180;
    v236 = stack[-1];
    v236 = qcdr(v236);
    if (v236 == nil) goto v49;
    v236 = stack[-2];
    if (v236 == nil) goto v40;
    v236 = stack[-1];
    stack[-4] = v236;
    v236 = stack[-4];
    if (v236 == nil) goto v214;
    v236 = stack[-4];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    v236 = qcar(v236);
    v236 = ncons(v236);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    stack[-1] = v236;
    stack[-2] = v236;
    goto v230;

v230:
    v236 = stack[-4];
    v236 = qcdr(v236);
    stack[-4] = v236;
    v236 = stack[-4];
    if (v236 == nil) goto v19;
    stack[0] = stack[-1];
    v236 = stack[-4];
    v236 = qcar(v236);
    v236 = qcdr(v236);
    v236 = qcar(v236);
    v236 = ncons(v236);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    v236 = Lrplacd(nil, stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-5];
    v236 = stack[-1];
    v236 = qcdr(v236);
    stack[-1] = v236;
    goto v230;

v19:
    v236 = stack[-2];
    goto v177;

v177:
    stack[-1] = v236;
    goto v40;

v40:
    v236 = stack[-3];
    v232 = qcar(v236);
    v236 = stack[-1];
    popv(6);
    return cons(v232, v236);

v214:
    v236 = qvalue(elt(env, 1)); /* nil */
    goto v177;

v49:
    v236 = stack[-1];
    v236 = qcar(v236);
    { popv(6); return onevalue(v236); }

v180:
    v236 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v236); }

v96:
    v236 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v236); }
/* error exit handlers */
v139:
    popv(6);
    return nil;
}



/* Code for arplus!: */

static Lisp_Object CC_arplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v34 = v11;
    v35 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v58 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v58; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v58 = v35;
    v58 = qcdr(v58);
    v34 = qcdr(v34);
    fn = elt(env, 5); /* addf */
    v58 = (*qfn2(fn))(qenv(fn), v58, v34);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    v58 = cons(stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v58); }
/* error exit handlers */
v82:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for reverse!-num */

static Lisp_Object CC_reverseKnum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reverse-num");
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
    v92 = stack[0];
    v93 = (Lisp_Object)1; /* 0 */
    if (v92 == v93) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v92 = stack[0];
    v93 = (Lisp_Object)1; /* 0 */
    v93 = (Lisp_Object)lessp2(v92, v93);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v93 = v93 ? lisp_true : nil;
    env = stack[-2];
    if (v93 == nil) goto v91;
    v93 = stack[0];
    stack[-1] = negate(v93);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v93 = stack[0];
    v93 = negate(v93);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    fn = elt(env, 1); /* ilog2 */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v93 = add1(v93);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    fn = elt(env, 2); /* reverse!-num1 */
    v93 = (*qfn2(fn))(qenv(fn), stack[-1], v93);
    nil = C_nil;
    if (exception_pending()) goto v75;
    popv(3);
    return negate(v93);

v91:
    stack[-1] = stack[0];
    v93 = stack[0];
    fn = elt(env, 1); /* ilog2 */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v93 = add1(v93);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    {
        Lisp_Object v28 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* reverse!-num1 */
        return (*qfn2(fn))(qenv(fn), v28, v93);
    }
/* error exit handlers */
v75:
    popv(3);
    return nil;
}



/* Code for mksq */

static Lisp_Object CC_mksq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v287, v288, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksq");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v11;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = nil;
    v287 = qvalue(elt(env, 1)); /* subfg!* */
    if (v287 == nil) goto v96;
    v288 = stack[-3];
    v287 = qvalue(elt(env, 2)); /* wtl!* */
    v287 = Lassoc(nil, v288, v287);
    stack[-1] = v287;
    if (v287 == nil) goto v186;
    stack[0] = elt(env, 3); /* k!* */
    v288 = stack[-2];
    v287 = stack[-1];
    v287 = qcdr(v287);
    v287 = times2(v288, v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    v287 = CC_mksq(env, stack[0], v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    stack[-1] = v287;
    v287 = qcar(v287);
    if (v287 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    else goto v186;

v186:
    v287 = stack[-3];
    if (!consp(v287)) goto v54;
    v287 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v287 == nil)) goto v290;
    v287 = stack[-3];
    v287 = qcar(v287);
    if (!(!consp(v287))) goto v290;
    v287 = stack[-3];
    v288 = qcar(v287);
    v287 = elt(env, 13); /* mksqsubfn */
    v287 = get(v288, v287);
    env = stack[-5];
    v288 = v287;
    if (v287 == nil) goto v251;
    v287 = stack[-3];
    v287 = Lapply1(nil, v288, v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    v288 = v287;
    if (!(v287 == nil)) goto v86;

v251:
    v115 = stack[-3];
    v287 = stack[-3];
    v288 = qcar(v287);
    v287 = elt(env, 14); /* kvalue */
    v287 = get(v288, v287);
    env = stack[-5];
    v287 = Lassoc(nil, v115, v287);
    v288 = v287;
    if (!(v287 == nil)) goto v86;

v290:
    stack[0] = elt(env, 6); /* used!* */
    v287 = stack[-3];
    fn = elt(env, 16); /* fkern */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    stack[-4] = v287;
    v287 = qcdr(v287);
    v287 = qcdr(v287);
    v287 = Lmemq(nil, stack[0], v287);
    if (!(v287 == nil)) goto v9;
    stack[0] = stack[-4];
    v287 = elt(env, 6); /* used!* */
    v287 = ncons(v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    v287 = Lnconc(nil, stack[0], v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    goto v9;

v9:
    v287 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v287 == nil)) goto v96;
    v288 = stack[-2];
    v287 = (Lisp_Object)17; /* 1 */
    if (v288 == v287) goto v96;
    v288 = stack[-3];
    v287 = qvalue(elt(env, 7)); /* asymplis!* */
    v287 = Lassoc(nil, v288, v287);
    v288 = v287;
    if (v287 == nil) goto v143;
    v287 = v288;
    v288 = qcdr(v287);
    v287 = stack[-2];
    v287 = (Lisp_Object)lesseq2(v288, v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    v287 = v287 ? lisp_true : nil;
    env = stack[-5];
    if (v287 == nil) goto v143;
    v288 = qvalue(elt(env, 8)); /* nil */
    v287 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v288, v287);

v143:
    v288 = stack[-3];
    v287 = qvalue(elt(env, 9)); /* powlis!* */
    v287 = Lassoc(nil, v288, v287);
    v288 = v287;
    if (!(v287 == nil)) goto v228;
    v287 = stack[-3];
    if (!consp(v287)) goto v96;
    v287 = stack[-3];
    v288 = qcar(v287);
    v287 = elt(env, 10); /* (expt sqrt) */
    v287 = Lmemq(nil, v288, v287);
    if (v287 == nil) goto v96;
    v287 = stack[-3];
    v287 = qcdr(v287);
    v288 = qcar(v287);
    v287 = qvalue(elt(env, 9)); /* powlis!* */
    v287 = Lassoc(nil, v288, v287);
    v288 = v287;
    if (!(v287 == nil)) goto v228;

v96:
    v287 = stack[-4];
    if (!(v287 == nil)) goto v261;
    v287 = stack[-3];
    fn = elt(env, 16); /* fkern */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    stack[-4] = v287;
    goto v261;

v261:
    v288 = stack[-4];
    v287 = stack[-2];
    fn = elt(env, 17); /* getpower */
    v288 = (*qfn2(fn))(qenv(fn), v288, v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    v287 = (Lisp_Object)17; /* 1 */
    v287 = cons(v288, v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    v288 = ncons(v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    v287 = (Lisp_Object)17; /* 1 */
    v287 = cons(v288, v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    stack[-4] = v287;
    v287 = stack[-1];
    if (v287 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v288 = stack[-1];
    v287 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* multsq */
        return (*qfn2(fn))(qenv(fn), v288, v287);
    }

v228:
    v287 = stack[-2];
    v288 = qcdr(v288);
    v288 = qcar(v288);
    v288 = times2(v287, v288);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    v287 = (Lisp_Object)1; /* 0 */
    v287 = (Lisp_Object)lessp2(v288, v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    v287 = v287 ? lisp_true : nil;
    env = stack[-5];
    if (!(v287 == nil)) goto v96;
    v287 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 12)) = v287; /* !*sub2 */
    goto v96;

v86:
    v287 = v288;
    v287 = qcdr(v287);
    v288 = v287;
    v287 = qvalue(elt(env, 15)); /* !*resubs */
    if (!(v287 == nil)) goto v199;
    v287 = qvalue(elt(env, 11)); /* t */
    qvalue(elt(env, 4)) = v287; /* !*nosubs */
    goto v199;

v199:
    v287 = v288;
    v287 = qcar(v287);
    fn = elt(env, 19); /* simp */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    stack[-4] = v287;
    v287 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 4)) = v287; /* !*nosubs */
    v288 = stack[-4];
    v287 = stack[-2];
    {
        popv(6);
        fn = elt(env, 20); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v288, v287);
    }

v54:
    v287 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v287 == nil)) goto v59;
    v288 = stack[-3];
    v287 = elt(env, 5); /* avalue */
    v287 = get(v288, v287);
    env = stack[-5];
    v288 = v287;
    if (!(v287 == nil)) goto v86;

v59:
    v287 = stack[-3];
    if (!(symbolp(v287))) goto v9;
    v287 = stack[-3];
    v288 = ncons(v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    v287 = elt(env, 6); /* used!* */
    v287 = Lflag(nil, v288, v287);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-5];
    goto v9;
/* error exit handlers */
v289:
    popv(6);
    return nil;
}



/* Code for sq2sstm */

static Lisp_Object CC_sq2sstm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v214, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sstm");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v11;
    v77 = v0;
/* end of prologue */
    v146 = v77;
    v146 = qcar(v146);
    v214 = qcar(v146);
    v146 = stack[-2];
    v146 = qcar(v146);
    v146 = qcar(v146);
    if (equal(v214, v146)) goto v163;
    v146 = v77;
    stack[-1] = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v146 = stack[-2];
    v146 = qcar(v146);
    stack[0] = qcdr(v146);
    v146 = stack[-2];
    v146 = qcdr(v146);
    v146 = sub1(v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v146 = cons(stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    fn = elt(env, 1); /* sq2sscfpl */
    v146 = (*qfn2(fn))(qenv(fn), stack[-1], v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v214 = (Lisp_Object)1; /* 0 */
    stack[-3] = v214;
    goto v148;

v148:
    v214 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* mapins */
        return (*qfn2(fn))(qenv(fn), v214, v146);
    }

v163:
    v146 = v77;
    v146 = qcdr(v146);
    stack[0] = v146;
    v146 = v77;
    v146 = qcar(v146);
    v146 = qcdr(v146);
    stack[-3] = v146;
    v146 = stack[0];
    if (!consp(v146)) goto v224;
    v146 = stack[0];
    v146 = qcar(v146);
    if (!consp(v146)) goto v224;
    stack[-1] = stack[0];
    v146 = stack[-2];
    v146 = qcar(v146);
    stack[0] = qcdr(v146);
    v146 = stack[-2];
    v146 = qcdr(v146);
    v146 = sub1(v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v146 = cons(stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    fn = elt(env, 1); /* sq2sscfpl */
    v146 = (*qfn2(fn))(qenv(fn), stack[-1], v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    goto v148;

v224:
    stack[-1] = stack[-3];
    v146 = stack[-2];
    v146 = qcdr(v146);
    fn = elt(env, 3); /* mkzl */
    v214 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-4];
    v146 = stack[0];
    v146 = acons(stack[-1], v214, v146);
    nil = C_nil;
    if (exception_pending()) goto v21;
    popv(5);
    return ncons(v146);
/* error exit handlers */
v21:
    popv(5);
    return nil;
}



setup_type const u17_setup[] =
{
    {"*wedgepf2pf",             CC_Hwedgepf2pf, too_many_1,    wrong_no_1},
    {"mktails1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails1},
    {"formsetq",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"mo_from_a",               CC_mo_from_a,   too_many_1,    wrong_no_1},
    {"exptpri",                 too_few_2,      CC_exptpri,    wrong_no_2},
    {"reduce_pv0",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduce_pv0},
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
    {"ofsf_clnegrel",           too_few_2,      CC_ofsf_clnegrel,wrong_no_2},
    {"texstrlen",               CC_texstrlen,   too_many_1,    wrong_no_1},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"lastnondomain",           CC_lastnondomain,too_many_1,   wrong_no_1},
    {"aex_subrat1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrat1},
    {"tobvarir",                CC_tobvarir,    too_many_1,    wrong_no_1},
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
    {"mksq",                    too_few_2,      CC_mksq,       wrong_no_2},
    {"sq2sstm",                 too_few_2,      CC_sq2sstm,    wrong_no_2},
    {NULL, (one_args *)"u17", (two_args *)"3823 8074283 5896406", 0}
};

/* end of generated code */
