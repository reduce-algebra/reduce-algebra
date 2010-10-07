
/* $destdir\u04.c        Machine generated C code */

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


/* Code for mchk */

static Lisp_Object CC_mchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchk");
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

v77:
    v75 = stack[-4];
    v74 = stack[-3];
    if (equal(v75, v74)) goto v78;
    v75 = stack[-4];
    v74 = elt(env, 2); /* !*sq */
    if (!consp(v75)) goto v79;
    v75 = qcar(v75);
    if (!(v75 == v74)) goto v79;
    v74 = stack[-4];
    v74 = qcdr(v74);
    v74 = qcar(v74);
    fn = elt(env, 9); /* prepsqxx */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    stack[-4] = v74;
    goto v77;

v79:
    v75 = stack[-3];
    v74 = elt(env, 2); /* !*sq */
    if (!consp(v75)) goto v81;
    v75 = qcar(v75);
    if (!(v75 == v74)) goto v81;
    v74 = stack[-3];
    v74 = qcdr(v74);
    v74 = qcar(v74);
    fn = elt(env, 9); /* prepsqxx */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    stack[-3] = v74;
    goto v77;

v81:
    v74 = stack[-3];
    if (!consp(v74)) goto v82;
    v74 = stack[-4];
    if (!consp(v74)) goto v83;
    v74 = stack[-3];
    v75 = qcar(v74);
    v74 = elt(env, 6); /* difference */
    if (v75 == v74) goto v84;
    v74 = stack[-4];
    v75 = qcar(v74);
    v74 = elt(env, 8); /* dname */
    v74 = get(v75, v74);
    env = stack[-6];
    if (!(v74 == nil)) goto v85;
    v74 = stack[-3];
    v75 = qcar(v74);
    v74 = elt(env, 8); /* dname */
    v74 = get(v75, v74);
    env = stack[-6];
    if (!(v74 == nil)) goto v85;
    v74 = stack[-4];
    v75 = qcar(v74);
    v74 = stack[-3];
    v74 = qcar(v74);
    if (v75 == v74) goto v86;
    v74 = stack[-3];
    v75 = qcar(v74);
    v74 = qvalue(elt(env, 3)); /* frlis!* */
    v74 = Lmemq(nil, v75, v74);
    if (v74 == nil) goto v87;
    v74 = stack[-4];
    v76 = qcar(v74);
    v74 = stack[-3];
    v75 = qcar(v74);
    v74 = stack[-4];
    v74 = qcdr(v74);
    stack[0] = Lsubst(nil, 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = stack[-4];
    v76 = qcar(v74);
    v74 = stack[-3];
    v75 = qcar(v74);
    v74 = stack[-3];
    v74 = qcdr(v74);
    v75 = Lsubst(nil, 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = stack[-4];
    v74 = qcar(v74);
    fn = elt(env, 10); /* mcharg */
    v74 = (*qfnn(fn))(qenv(fn), 3, stack[0], v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    stack[-5] = v74;
    v74 = stack[-5];
    if (v74 == nil) goto v88;
    v74 = stack[-5];
    v74 = qcar(v74);
    v75 = stack[-3];
    v76 = qcar(v75);
    v75 = stack[-4];
    v75 = qcar(v75);
    v74 = acons(v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    stack[-1] = v74;
    stack[-2] = v74;
    goto v89;

v89:
    v74 = stack[-5];
    v74 = qcdr(v74);
    stack[-5] = v74;
    v74 = stack[-5];
    if (v74 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v74 = stack[-5];
    v74 = qcar(v74);
    v75 = stack[-3];
    v76 = qcar(v75);
    v75 = stack[-4];
    v75 = qcar(v75);
    v74 = acons(v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = Lrplacd(nil, stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = stack[-1];
    v74 = qcdr(v74);
    stack[-1] = v74;
    goto v89;

v88:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v74); }

v87:
    v74 = stack[-4];
    v75 = qcar(v74);
    v74 = elt(env, 4); /* minus */
    if (v75 == v74) goto v90;
    v74 = stack[-3];
    v75 = qcar(v74);
    v74 = elt(env, 5); /* optional */
    v74 = get(v75, v74);
    env = stack[-6];
    v75 = v74;
    if (v75 == nil) goto v91;
    v76 = stack[-4];
    v75 = stack[-3];
    {
        popv(7);
        fn = elt(env, 11); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    }

v91:
    v74 = nil;
    { popv(7); return onevalue(v74); }

v90:
    v74 = stack[-4];
    v74 = qcdr(v74);
    v75 = qcar(v74);
    v74 = stack[-3];
    {
        popv(7);
        fn = elt(env, 12); /* mchkminus */
        return (*qfn2(fn))(qenv(fn), v75, v74);
    }

v86:
    v74 = stack[-4];
    v76 = qcdr(v74);
    v74 = stack[-3];
    v75 = qcdr(v74);
    v74 = stack[-4];
    v74 = qcar(v74);
    {
        popv(7);
        fn = elt(env, 10); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    }

v85:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v74); }

v84:
    stack[-1] = elt(env, 7); /* plus */
    v74 = stack[-3];
    v74 = qcdr(v74);
    stack[0] = qcar(v74);
    v75 = elt(env, 4); /* minus */
    v74 = stack[-3];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v74 = qcar(v74);
    v74 = list2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = list3(stack[-1], stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    stack[-3] = v74;
    goto v77;

v83:
    v74 = stack[-4];
    if (!(is_number(v74))) goto v92;
    v75 = stack[-4];
    v74 = (Lisp_Object)1; /* 0 */
    v74 = (Lisp_Object)lessp2(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    v74 = v74 ? lisp_true : nil;
    env = stack[-6];
    if (v74 == nil) goto v92;
    v75 = stack[-3];
    v74 = elt(env, 4); /* minus */
    if (!consp(v75)) goto v92;
    v75 = qcar(v75);
    if (!(v75 == v74)) goto v92;
    stack[0] = elt(env, 4); /* minus */
    v74 = stack[-4];
    v74 = negate(v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = list2(stack[0], v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    stack[-4] = v74;
    goto v77;

v92:
    v74 = stack[-3];
    v75 = qcar(v74);
    v74 = elt(env, 5); /* optional */
    v74 = get(v75, v74);
    env = stack[-6];
    v75 = v74;
    if (v75 == nil) goto v93;
    v76 = stack[-4];
    v75 = stack[-3];
    {
        popv(7);
        fn = elt(env, 11); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    }

v93:
    v74 = nil;
    { popv(7); return onevalue(v74); }

v82:
    v75 = stack[-3];
    v74 = qvalue(elt(env, 3)); /* frlis!* */
    v74 = Lmemq(nil, v75, v74);
    if (v74 == nil) goto v94;
    v75 = stack[-3];
    v74 = stack[-4];
    v74 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-6];
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v80;
    popv(7);
    return ncons(v74);

v94:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v74); }

v78:
    v74 = qvalue(elt(env, 1)); /* nil */
    popv(7);
    return ncons(v74);
/* error exit handlers */
v80:
    popv(7);
    return nil;
}



/* Code for rev */

static Lisp_Object CC_rev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v70, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rev");
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
    v71 = v1;
    v70 = v0;
/* end of prologue */

v99:
    v98 = v70;
    if (v98 == nil) { popv(2); return onevalue(v71); }
    v98 = v70;
    v98 = qcdr(v98);
    stack[0] = v98;
    v70 = qcar(v70);
    v71 = cons(v70, v71);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v70 = stack[0];
    goto v99;
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for !*i2rn */

static Lisp_Object CC_Hi2rn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104, v72;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2rn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v103 = v0;
/* end of prologue */
    v72 = elt(env, 1); /* !:rn!: */
    v104 = v103;
    v103 = (Lisp_Object)17; /* 1 */
    return list2star(v72, v104, v103);
}



/* Code for gintequiv!: */

static Lisp_Object CC_gintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106, v107;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gintequiv:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v107 = v0;
/* end of prologue */
    v105 = v107;
    v105 = qcdr(v105);
    v106 = qcdr(v105);
    v105 = (Lisp_Object)1; /* 0 */
    if (v106 == v105) goto v108;
    v105 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v105);

v108:
    v105 = v107;
    v105 = qcdr(v105);
    v105 = qcar(v105);
    return onevalue(v105);
}



/* Code for rl_smcpknowl */

static Lisp_Object CC_rl_smcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smcpknowl");
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
    v101 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smcpknowl!* */
    v101 = ncons(v101);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-1];
    {
        Lisp_Object v104 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v104, v101);
    }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for invsq */

static Lisp_Object CC_invsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invsq");
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
    v68 = stack[0];
    v68 = qcar(v68);
    if (!(v68 == nil)) goto v95;
    v68 = elt(env, 1); /* "Zero divisor" */
    v112 = v68;
    v68 = v112;
    qvalue(elt(env, 2)) = v68; /* errmsg!* */
    v68 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v68 == nil)) goto v73;
    v68 = v112;
    fn = elt(env, 5); /* lprie */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-1];
    goto v73;

v73:
    v68 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-1];
    goto v95;

v95:
    v68 = stack[0];
    v112 = qcdr(v68);
    v68 = stack[0];
    v68 = qcar(v68);
    v68 = cons(v112, v68);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-1];
    stack[0] = v68;
    v68 = qvalue(elt(env, 4)); /* !*rationalize */
    if (v68 == nil) goto v81;
    v68 = stack[0];
    fn = elt(env, 6); /* gcdchk */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-1];
    stack[0] = v68;
    goto v81;

v81:
    v68 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v68);
    }
/* error exit handlers */
v113:
    popv(2);
    return nil;
}



/* Code for ibalp_varlt */

static Lisp_Object CC_ibalp_varlt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlt");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v77 = v0;
/* end of prologue */
    v101 = v77;
    v77 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* ibalp_varlt1 */
        return (*qfn2(fn))(qenv(fn), v101, v77);
    }
}



/* Code for lex */

static Lisp_Object MS_CDECL CC_lex(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lex");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lex");
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
    v121 = qvalue(elt(env, 2)); /* atts */
    if (v121 == nil) goto v99;
    v121 = qvalue(elt(env, 2)); /* atts */
    qvalue(elt(env, 3)) = v121; /* safe_atts */
    goto v99;

v99:
    v121 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v121; /* atts */
    v122 = qvalue(elt(env, 4)); /* ch */
    v121 = qvalue(elt(env, 5)); /* !$eof!$ */
    if (equal(v122, v121)) goto v103;
    v122 = qvalue(elt(env, 4)); /* ch */
    v121 = qvalue(elt(env, 6)); /* space */
    if (equal(v122, v121)) goto v68;
    v122 = qvalue(elt(env, 4)); /* ch */
    v121 = elt(env, 7); /* !< */
    if (v122 == v121) goto v123;
    fn = elt(env, 10); /* get_content */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    qvalue(elt(env, 8)) = v121; /* char */
    goto v95;

v95:
    v121 = qvalue(elt(env, 8)); /* char */
    if (v121 == nil) goto v125;
    v121 = qvalue(elt(env, 9)); /* count */
    v121 = add1(v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    qvalue(elt(env, 9)) = v121; /* count */
    v121 = qvalue(elt(env, 8)); /* char */
    v121 = Lreverse(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    stack[0] = v121;
    v121 = stack[0];
    fn = elt(env, 11); /* butes */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    qvalue(elt(env, 8)) = v121; /* char */
    v122 = qvalue(elt(env, 8)); /* char */
    v121 = stack[0];
    fn = elt(env, 12); /* attributes */
    v121 = (*qfn2(fn))(qenv(fn), v122, v121);
    nil = C_nil;
    if (exception_pending()) goto v124;
    goto v103;

v103:
    v121 = nil;
    { popv(2); return onevalue(v121); }

v125:
    v121 = CC_lex(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v124;
    goto v103;

v123:
    fn = elt(env, 13); /* get_token */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    qvalue(elt(env, 8)) = v121; /* char */
    goto v95;

v68:
    v122 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    qvalue(elt(env, 4)) = v122; /* ch */
    v121 = qvalue(elt(env, 6)); /* space */
    if (equal(v122, v121)) goto v68;
    else goto v95;
/* error exit handlers */
v124:
    popv(2);
    return nil;
}



/* Code for fullcopy */

static Lisp_Object CC_fullcopy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fullcopy");
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
    stack[0] = nil;
    goto v137;

v137:
    v135 = stack[-5];
    v135 = Lconsp(nil, v135);
    env = stack[-7];
    if (v135 == nil) goto v109;
    v135 = stack[-5];
    v135 = qcar(v135);
    v136 = CC_fullcopy(env, v135);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-7];
    v135 = stack[0];
    v135 = cons(v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-7];
    stack[0] = v135;
    v135 = stack[-5];
    v135 = qcdr(v135);
    stack[-5] = v135;
    goto v137;

v109:
    v135 = stack[-5];
    v135 = Lsimple_vectorp(nil, v135);
    env = stack[-7];
    if (v135 == nil) goto v122;
    stack[-6] = stack[0];
    v135 = stack[-5];
    v135 = Lupbv(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-7];
    stack[-3] = v135;
    v135 = stack[-3];
    v135 = Lmkvect(nil, v135);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-7];
    stack[-4] = v135;
    v135 = (Lisp_Object)1; /* 0 */
    stack[-2] = v135;
    goto v139;

v139:
    v136 = stack[-3];
    v135 = stack[-2];
    v135 = difference2(v136, v135);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-7];
    v135 = Lminusp(nil, v135);
    env = stack[-7];
    if (v135 == nil) goto v140;
    v135 = stack[-4];
    {
        Lisp_Object v141 = stack[-6];
        popv(8);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v141, v135);
    }

v140:
    stack[-1] = stack[-4];
    stack[0] = stack[-2];
    v136 = stack[-5];
    v135 = stack[-2];
    v135 = *(Lisp_Object *)((char *)v136 + (CELL-TAG_VECTOR) + ((int32_t)v135/(16/CELL)));
    v135 = CC_fullcopy(env, v135);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v135;
    v135 = stack[-2];
    v135 = add1(v135);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-7];
    stack[-2] = v135;
    goto v139;

v122:
    v136 = stack[0];
    v135 = stack[-5];
    {
        popv(8);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v136, v135);
    }
/* error exit handlers */
v138:
    popv(8);
    return nil;
}



/* Code for pnthxzz */

static Lisp_Object CC_pnthxzz(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v70, v98, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnthxzz");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v1;
    v98 = v0;
/* end of prologue */

v137:
    v71 = v70;
    if (v71 == nil) return onevalue(v70);
    v71 = v70;
    v71 = qcar(v71);
    v110 = qcar(v71);
    v71 = v98;
    if (equal(v110, v71)) return onevalue(v70);
    v71 = v70;
    v71 = qcdr(v71);
    v70 = v71;
    goto v137;
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retimes1");
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
    goto v137;

v137:
    v148 = stack[0];
    if (v148 == nil) goto v78;
    v148 = stack[0];
    v149 = qcar(v148);
    v148 = (Lisp_Object)17; /* 1 */
    if (v149 == v148) goto v103;
    v148 = stack[0];
    v148 = qcar(v148);
    v148 = Lminusp(nil, v148);
    env = stack[-2];
    if (v148 == nil) goto v150;
    v148 = qvalue(elt(env, 1)); /* !*bool */
    v148 = (v148 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v148; /* !*bool */
    v148 = stack[0];
    v148 = qcar(v148);
    v149 = negate(v148);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    v148 = stack[0];
    v148 = qcdr(v148);
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    stack[0] = v148;
    goto v137;

v150:
    v148 = stack[0];
    v148 = qcar(v148);
    if (!consp(v148)) goto v119;
    v148 = stack[0];
    v148 = qcar(v148);
    v149 = qcar(v148);
    v148 = elt(env, 2); /* minus */
    if (v149 == v148) goto v117;
    v148 = stack[0];
    v148 = qcar(v148);
    v149 = qcar(v148);
    v148 = elt(env, 3); /* times */
    if (v149 == v148) goto v136;
    v148 = stack[0];
    v149 = qcar(v148);
    v148 = stack[-1];
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    stack[-1] = v148;
    v148 = stack[0];
    v148 = qcdr(v148);
    stack[0] = v148;
    goto v137;

v136:
    v148 = stack[0];
    v148 = qcar(v148);
    v149 = qcdr(v148);
    v148 = stack[0];
    v148 = qcdr(v148);
    v148 = Lappend(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    stack[0] = v148;
    goto v137;

v117:
    v148 = qvalue(elt(env, 1)); /* !*bool */
    v148 = (v148 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v148; /* !*bool */
    v148 = stack[0];
    v148 = qcar(v148);
    v148 = qcdr(v148);
    v149 = qcar(v148);
    v148 = stack[0];
    v148 = qcdr(v148);
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    stack[0] = v148;
    goto v137;

v119:
    v148 = stack[0];
    v149 = qcar(v148);
    v148 = stack[-1];
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    stack[-1] = v148;
    v148 = stack[0];
    v148 = qcdr(v148);
    stack[0] = v148;
    goto v137;

v103:
    v148 = stack[0];
    v148 = qcdr(v148);
    stack[0] = v148;
    goto v137;

v78:
    v148 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v148);
    }
/* error exit handlers */
v55:
    popv(3);
    return nil;
}



/* Code for quotematrix */

static Lisp_Object CC_quotematrix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v97;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotematrix");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v97 = v0;
/* end of prologue */
    v97 = elt(env, 1); /* matrix */
    return onevalue(v97);
}



/* Code for getrtype2 */

static Lisp_Object CC_getrtype2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v154, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtype2");
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
    v154 = v0;
/* end of prologue */
    v122 = v154;
    v124 = qcar(v122);
    v122 = elt(env, 1); /* rtype */
    v122 = get(v124, v122);
    env = stack[0];
    v124 = v122;
    if (v122 == nil) goto v155;
    v122 = elt(env, 2); /* rtypefn */
    v122 = get(v124, v122);
    env = stack[0];
    v124 = v122;
    if (v122 == nil) goto v155;
    v122 = v124;
    v154 = qcdr(v154);
        popv(1);
        return Lapply1(nil, v122, v154);

v155:
    v122 = v154;
    v124 = qcar(v122);
    v122 = elt(env, 2); /* rtypefn */
    v122 = get(v124, v122);
    env = stack[0];
    v124 = v122;
    if (v122 == nil) goto v133;
    v122 = v124;
    v154 = qcdr(v154);
        popv(1);
        return Lapply1(nil, v122, v154);

v133:
    v122 = v154;
    v124 = qcar(v122);
    v122 = elt(env, 3); /* matmapfn */
    v122 = Lflagp(nil, v124, v122);
    env = stack[0];
    if (v122 == nil) goto v156;
    v122 = v154;
    v122 = qcdr(v122);
    if (v122 == nil) goto v156;
    v122 = v154;
    v122 = qcdr(v122);
    v122 = qcar(v122);
    fn = elt(env, 6); /* getrtype */
    v154 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[0];
    v122 = elt(env, 4); /* matrix */
    if (!(v154 == v122)) goto v156;
    v122 = elt(env, 4); /* matrix */
    { popv(1); return onevalue(v122); }

v156:
    v122 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v122); }
/* error exit handlers */
v157:
    popv(1);
    return nil;
}



/* Code for tensopp */

static Lisp_Object CC_tensopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensopp");
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
    v67 = v0;
/* end of prologue */
    v66 = v67;
    if (symbolp(v66)) goto v159;
    v66 = qvalue(elt(env, 1)); /* nil */
    goto v99;

v99:
    if (!(v66 == nil)) { popv(1); return onevalue(v66); }
    v66 = v67;
    if (!consp(v66)) goto v110;
    v66 = v67;
    v133 = qcar(v66);
    v66 = elt(env, 2); /* phystype */
    v133 = get(v133, v66);
    env = stack[0];
    v66 = elt(env, 3); /* tensor */
    if (v133 == v66) goto v160;
    v66 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v66); }

v160:
    v66 = v67;
    v66 = qcdr(v66);
    v66 = qcar(v66);
    fn = elt(env, 4); /* isanindex */
    v66 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v161;
    v66 = (v66 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v66); }

v110:
    v66 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v66); }

v159:
    v133 = v67;
    v66 = elt(env, 2); /* phystype */
    v133 = get(v133, v66);
    env = stack[0];
    v66 = elt(env, 3); /* tensor */
    v66 = (v133 == v66 ? lisp_true : nil);
    goto v99;
/* error exit handlers */
v161:
    popv(1);
    return nil;
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v127, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v139, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroad");
#endif
    if (stack >= stacklimit)
    {
        push3(v127,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v127);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v127;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v151 = nil;
    goto v163;

v163:
    v82 = stack[0];
    if (v82 == nil) goto v77;
    v139 = stack[-2];
    v82 = stack[0];
    v82 = qcar(v82);
    if (equal(v139, v82)) goto v150;
    v82 = stack[0];
    v82 = qcar(v82);
    v139 = v151;
    v82 = cons(v82, v139);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v151 = v82;
    v82 = stack[0];
    v82 = qcdr(v82);
    stack[0] = v82;
    goto v163;

v150:
    stack[-2] = v151;
    v139 = stack[-1];
    v82 = stack[0];
    v82 = qcdr(v82);
    v82 = Lappend(nil, v139, v82);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    {
        Lisp_Object v133 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v133, v82);
    }

v77:
    v82 = v151;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v82);
    }
/* error exit handlers */
v67:
    popv(4);
    return nil;
}



/* Code for lpri */

static Lisp_Object CC_lpri(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpri");
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
    v134 = stack[0];
    if (v134 == nil) goto v163;
    v134 = stack[0];
    v134 = qcar(v134);
    v134 = Lprinc(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    v134 = elt(env, 2); /* " " */
    v134 = Lprinc(nil, v134);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    v134 = stack[0];
    v134 = qcdr(v134);
    stack[0] = v134;
    goto v108;

v163:
    v134 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v134); }
/* error exit handlers */
v142:
    popv(2);
    return nil;
}



/* Code for getrtype */

static Lisp_Object CC_getrtype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v85, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getrtype");
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

v177:
    v49 = stack[0];
    if (v49 == nil) goto v78;
    v49 = stack[0];
    if (!consp(v49)) goto v102;
    v49 = stack[0];
    v49 = qcar(v49);
    if (symbolp(v49)) goto v178;
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v49); }

v178:
    v49 = stack[0];
    v85 = qcar(v49);
    v49 = elt(env, 3); /* avalue */
    v49 = get(v85, v49);
    env = stack[-1];
    v176 = v49;
    if (v49 == nil) goto v179;
    v49 = v176;
    v85 = qcar(v49);
    v49 = elt(env, 6); /* rtypefn */
    v49 = get(v85, v49);
    env = stack[-1];
    v176 = v49;
    if (v49 == nil) goto v179;
    v85 = v176;
    v49 = stack[0];
    v49 = qcdr(v49);
        popv(2);
        return Lapply1(nil, v85, v49);

v179:
    v49 = stack[0];
    v85 = qcar(v49);
    v49 = elt(env, 7); /* sub */
    if (v85 == v49) goto v180;
    v49 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* getrtype2 */
        return (*qfn1(fn))(qenv(fn), v49);
    }

v180:
    v49 = elt(env, 8); /* yetunknowntype */
    { popv(2); return onevalue(v49); }

v102:
    v49 = stack[0];
    if (symbolp(v49)) goto v120;
    v49 = stack[0];
    if (is_number(v49)) goto v106;
    v49 = stack[0];
    {
        popv(2);
        fn = elt(env, 10); /* getrtype1 */
        return (*qfn1(fn))(qenv(fn), v49);
    }

v106:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v49); }

v120:
    v85 = stack[0];
    v49 = elt(env, 2); /* share */
    v49 = Lflagp(nil, v85, v49);
    env = stack[-1];
    if (v49 == nil) goto v161;
    v49 = stack[0];
    fn = elt(env, 11); /* eval */
    v85 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-1];
    v176 = v85;
    v49 = stack[0];
    if (v85 == v49) goto v68;
    v49 = v176;
    stack[0] = v49;
    goto v177;

v68:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v49); }

v161:
    v85 = stack[0];
    v49 = elt(env, 3); /* avalue */
    v49 = get(v85, v49);
    env = stack[-1];
    v176 = v49;
    if (v49 == nil) goto v125;
    v49 = v176;
    v85 = qcar(v49);
    v49 = elt(env, 4); /* (scalar generic) */
    v49 = Lmemq(nil, v85, v49);
    if (!(v49 == nil)) goto v125;

v182:
    v49 = v176;
    v85 = qcar(v49);
    v49 = elt(env, 6); /* rtypefn */
    v49 = get(v85, v49);
    env = stack[-1];
    v85 = v49;
    if (v49 == nil) goto v183;
    v49 = v85;
    v85 = qvalue(elt(env, 1)); /* nil */
        popv(2);
        return Lapply1(nil, v49, v85);

v183:
    v49 = v176;
    v49 = qcar(v49);
    { popv(2); return onevalue(v49); }

v125:
    v85 = stack[0];
    v49 = elt(env, 5); /* rtype */
    v49 = get(v85, v49);
    env = stack[-1];
    v176 = v49;
    if (v49 == nil) goto v184;
    v49 = v176;
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-1];
    v176 = v49;
    if (!(v49 == nil)) goto v182;

v184:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v49); }

v78:
    v49 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v49); }
/* error exit handlers */
v181:
    popv(2);
    return nil;
}



/* Code for negf */

static Lisp_Object CC_negf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negf");
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
    goto v137;

v137:
    v115 = stack[-1];
    if (v115 == nil) goto v78;
    v115 = stack[-1];
    if (!consp(v115)) goto v105;
    v115 = stack[-1];
    v115 = qcar(v115);
    if (!consp(v115)) goto v105;
    v115 = stack[-1];
    v115 = qcar(v115);
    stack[0] = qcar(v115);
    v115 = stack[-1];
    v115 = qcar(v115);
    v115 = qcdr(v115);
    v125 = CC_negf(env, v115);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    v115 = stack[-2];
    v115 = acons(stack[0], v125, v115);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    stack[-2] = v115;
    v115 = stack[-1];
    v115 = qcdr(v115);
    stack[-1] = v115;
    goto v137;

v105:
    stack[0] = stack[-2];
    v115 = stack[-1];
    if (!(!consp(v115))) goto v117;
    v125 = qvalue(elt(env, 1)); /* dmode!* */
    v115 = elt(env, 2); /* convert */
    v115 = Lflagp(nil, v125, v115);
    env = stack[-3];
    if (v115 == nil) goto v117;
    v125 = qvalue(elt(env, 1)); /* dmode!* */
    v115 = elt(env, 3); /* i2d */
    v125 = get(v125, v115);
    env = stack[-3];
    v115 = stack[-1];
    v115 = Lapply1(nil, v125, v115);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    goto v98;

v98:
    fn = elt(env, 4); /* !:minus */
    v115 = (*qfn1(fn))(qenv(fn), v115);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    {
        Lisp_Object v122 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v122, v115);
    }

v117:
    v115 = stack[-1];
    goto v98;

v78:
    v115 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v115);
    }
/* error exit handlers */
v121:
    popv(4);
    return nil;
}



/* Code for mo!=shorten */

static Lisp_Object CC_moMshorten(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=shorten");
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
    v100 = v0;
/* end of prologue */
    v100 = Lreverse(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    stack[0] = v100;
    goto v109;

v109:
    v100 = stack[0];
    if (v100 == nil) goto v78;
    v100 = stack[0];
    v111 = qcar(v100);
    v100 = (Lisp_Object)1; /* 0 */
    v100 = Leqn(nil, v111, v100);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-1];
    if (v100 == nil) goto v78;
    v100 = stack[0];
    v100 = qcdr(v100);
    stack[0] = v100;
    goto v109;

v78:
    v100 = stack[0];
        popv(2);
        return Lnreverse(nil, v100);
/* error exit handlers */
v81:
    popv(2);
    return nil;
}



/* Code for dquot */

static Lisp_Object CC_dquot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v162, v160;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dquot");
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
    goto v77;

v77:
    v123 = stack[-1];
    v162 = qcar(v123);
    v123 = stack[0];
    v123 = qcar(v123);
    v123 = difference2(v162, v123);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    v160 = v123;
    v162 = v160;
    v123 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v162)) < ((int32_t)(v123))) goto v105;
    v162 = v160;
    v123 = stack[-2];
    v123 = cons(v162, v123);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-3];
    stack[-2] = v123;
    v123 = stack[0];
    v123 = qcdr(v123);
    stack[0] = v123;
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    v123 = stack[0];
    if (!(v123 == nil)) goto v77;
    v123 = stack[-2];
        popv(4);
        return Lnreverse(nil, v123);

v105:
    v123 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v123); }
/* error exit handlers */
v151:
    popv(4);
    return nil;
}



/* Code for pv_sort2 */

static Lisp_Object CC_pv_sort2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort2");
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
    stack[0] = v1;
    v102 = v0;
/* end of prologue */
    v103 = v102;
    v102 = stack[0];
    fn = elt(env, 1); /* pv_sort2a */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v72;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v72:
    popv(1);
    return nil;
}



/* Code for c!:ordexp */

static Lisp_Object CC_cTordexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v155, v69, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v155 = v1;
    v69 = v0;
/* end of prologue */

v137:
    v175 = v69;
    if (v175 == nil) goto v78;
    v175 = v69;
    v68 = qcar(v175);
    v175 = v155;
    v175 = qcar(v175);
    if (equal(v68, v175)) goto v102;
    v175 = v69;
    v175 = qcar(v175);
    v155 = qcar(v155);
    {
        fn = elt(env, 2); /* c!:ordxp */
        return (*qfn2(fn))(qenv(fn), v175, v155);
    }

v102:
    v175 = v69;
    v175 = qcdr(v175);
    v69 = v175;
    v175 = v155;
    v175 = qcdr(v175);
    v155 = v175;
    goto v137;

v78:
    v175 = qvalue(elt(env, 1)); /* t */
    return onevalue(v175);
}



/* Code for evaluate!-in!-order */

static Lisp_Object CC_evaluateKinKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v187, v188, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-in-order");
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

v137:
    v140 = stack[-1];
    if (!consp(v140)) goto v78;
    v140 = stack[-1];
    v140 = qcar(v140);
    if (!consp(v140)) goto v78;
    v140 = stack[-1];
    v140 = qcar(v140);
    v140 = qcar(v140);
    v187 = qcar(v140);
    v140 = stack[0];
    v140 = qcar(v140);
    v140 = qcar(v140);
    if (equal(v187, v140)) goto v68;
    v140 = stack[0];
    v140 = qcdr(v140);
    stack[0] = v140;
    goto v137;

v68:
    v140 = stack[-1];
    v140 = qcar(v140);
    v187 = qcdr(v140);
    v140 = stack[0];
    v140 = qcdr(v140);
    v189 = CC_evaluateKinKorder(env, v187, v140);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-2];
    v140 = stack[-1];
    v140 = qcar(v140);
    v140 = qcar(v140);
    v188 = qcdr(v140);
    v140 = stack[-1];
    v187 = qcdr(v140);
    v140 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* horner!-rule */
        return (*qfnn(fn))(qenv(fn), 4, v189, v188, v187, v140);
    }

v78:
    v140 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v140);
    }
/* error exit handlers */
v190:
    popv(3);
    return nil;
}



/* Code for get!+vec!+dim */

static Lisp_Object CC_getLvecLdim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+vec+dim");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v99 = v0;
/* end of prologue */
        return Llength(nil, v99);
}



/* Code for sf_idl */

static Lisp_Object CC_sf_idl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf_idl");
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
    v113 = stack[-2];
    if (!consp(v113)) goto v137;
    v113 = stack[-2];
    v113 = qcar(v113);
    if (!consp(v113)) goto v137;
    v113 = stack[-2];
    v113 = qcar(v113);
    v113 = qcar(v113);
    stack[-3] = qcar(v113);
    v113 = stack[-2];
    v113 = qcar(v113);
    v113 = qcdr(v113);
    stack[-1] = CC_sf_idl(env, v113);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v113 = stack[-2];
    v113 = qcdr(v113);
    stack[0] = CC_sf_idl(env, v113);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v113 = stack[-2];
    v113 = qcar(v113);
    v113 = qcar(v113);
    v113 = qcar(v113);
    v113 = ncons(v113);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    fn = elt(env, 1); /* lto_setminus */
    v113 = (*qfn2(fn))(qenv(fn), stack[0], v113);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    fn = elt(env, 2); /* setunion */
    v113 = (*qfn2(fn))(qenv(fn), stack[-1], v113);
    nil = C_nil;
    if (exception_pending()) goto v123;
    {
        Lisp_Object v162 = stack[-3];
        popv(5);
        return cons(v162, v113);
    }

v137:
    v113 = nil;
    { popv(5); return onevalue(v113); }
/* error exit handlers */
v123:
    popv(5);
    return nil;
}



/* Code for multi_elem */

static Lisp_Object CC_multi_elem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_elem");
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
    v70 = stack[0];
    v98 = Llength(nil, v70);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v70 = (Lisp_Object)17; /* 1 */
    if (v98 == v70) goto v99;
    v70 = stack[0];
    v70 = qcar(v70);
    fn = elt(env, 2); /* expression */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v70 = stack[0];
    v70 = qcdr(v70);
    v70 = CC_multi_elem(env, v70);
    nil = C_nil;
    if (exception_pending()) goto v100;
    goto v137;

v137:
    v70 = nil;
    { popv(2); return onevalue(v70); }

v99:
    v70 = stack[0];
    v70 = qcar(v70);
    fn = elt(env, 2); /* expression */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v100;
    goto v137;
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v127)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate");
#endif
    if (stack >= stacklimit)
    {
        push2(v127,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v127);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v127;
    v116 = v1;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v116; /* ps */
    v117 = qvalue(elt(env, 1)); /* ps */
    v116 = stack[-2];
    fn = elt(env, 3); /* ps!:get!-term */
    v116 = (*qfn2(fn))(qenv(fn), v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    stack[-1] = v116;
    v116 = stack[-1];
    if (v116 == nil) goto v142;
    v116 = stack[-1];
    goto v99;

v99:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v116); }

v142:
    v116 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:last!-term */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    v116 = add1(v116);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    stack[0] = v116;
    goto v147;

v147:
    v117 = stack[-2];
    v116 = stack[0];
    v116 = difference2(v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    v116 = Lminusp(nil, v116);
    env = stack[-4];
    if (v116 == nil) goto v118;
    v116 = stack[-1];
    goto v99;

v118:
    v117 = qvalue(elt(env, 1)); /* ps */
    v116 = stack[0];
    fn = elt(env, 5); /* ps!:evaluate!-next */
    v116 = (*qfn2(fn))(qenv(fn), v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    stack[-1] = v116;
    v116 = stack[0];
    v116 = add1(v116);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    stack[0] = v116;
    goto v147;
/* error exit handlers */
v140:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for revlis */

static Lisp_Object CC_revlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revlis");
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
    v130 = v0;
/* end of prologue */
    stack[-3] = v130;
    v130 = stack[-3];
    if (v130 == nil) goto v101;
    v130 = stack[-3];
    v130 = qcar(v130);
    fn = elt(env, 2); /* reval */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    v130 = ncons(v130);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    stack[-1] = v130;
    stack[-2] = v130;
    goto v163;

v163:
    v130 = stack[-3];
    v130 = qcdr(v130);
    stack[-3] = v130;
    v130 = stack[-3];
    if (v130 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v130 = stack[-3];
    v130 = qcar(v130);
    fn = elt(env, 2); /* reval */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    v130 = ncons(v130);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    v130 = Lrplacd(nil, stack[0], v130);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-4];
    v130 = stack[-1];
    v130 = qcdr(v130);
    stack[-1] = v130;
    goto v163;

v101:
    v130 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v130); }
/* error exit handlers */
v158:
    popv(5);
    return nil;
}



/* Code for subscriptedvarp */

static Lisp_Object CC_subscriptedvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subscriptedvarp");
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
    v110 = qvalue(elt(env, 1)); /* nil */
    v98 = stack[0];
    fn = elt(env, 3); /* symtabget */
    v98 = (*qfn2(fn))(qenv(fn), v110, v98);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    v110 = Llength(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-1];
    v98 = (Lisp_Object)33; /* 2 */
    v98 = (Lisp_Object)greaterp2(v110, v98);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v98 = v98 ? lisp_true : nil;
    env = stack[-1];
    if (!(v98 == nil)) { popv(2); return onevalue(v98); }
    v98 = stack[0];
    v110 = elt(env, 2); /* subscripted */
        popv(2);
        return Lflagp(nil, v98, v110);
/* error exit handlers */
v111:
    popv(2);
    return nil;
}



/* Code for nextarg */

static Lisp_Object CC_nextarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextarg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v0;
/* end of prologue */
    v103 = qvalue(elt(env, 1)); /* symm */
    if (v103 == nil) goto v109;
    v103 = v104;
    {
        fn = elt(env, 2); /* s!-nextarg */
        return (*qfn1(fn))(qenv(fn), v103);
    }

v109:
    v103 = v104;
    {
        fn = elt(env, 3); /* o!-nextarg */
        return (*qfn1(fn))(qenv(fn), v103);
    }
}



/* Code for evtdeg */

static Lisp_Object CC_evtdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v150, v71;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evtdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v150 = v0;
/* end of prologue */
    v96 = (Lisp_Object)1; /* 0 */
    goto v99;

v99:
    v71 = v150;
    if (v71 == nil) return onevalue(v96);
    v71 = v150;
    v71 = qcar(v71);
    v96 = (Lisp_Object)(int32_t)((int32_t)v71 + (int32_t)v96 - TAG_FIXNUM);
    v150 = qcdr(v150);
    goto v99;
}



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v160, v191, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :difference");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v191 = v1;
    v82 = v0;
/* end of prologue */
    v162 = v82;
    if (v162 == nil) goto v137;
    v162 = v191;
    if (v162 == nil) return onevalue(v82);
    v160 = v82;
    v162 = v191;
    if (equal(v160, v162)) goto v104;
    v162 = v82;
    if (!(!consp(v162))) goto v69;
    v162 = v191;
    if (!(!consp(v162))) goto v69;
    v162 = v82;
    v160 = v191;
    return difference2(v162, v160);

v69:
    v160 = v82;
    v162 = elt(env, 2); /* difference */
    {
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v160, v191, v162);
    }

v104:
    v162 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v162);

v137:
    v162 = v191;
    {
        fn = elt(env, 4); /* !:minus */
        return (*qfn1(fn))(qenv(fn), v162);
    }
}



/* Code for freeofdepl */

static Lisp_Object MS_CDECL CC_freeofdepl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v127, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "freeofdepl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofdepl");
#endif
    if (stack >= stacklimit)
    {
        push3(v127,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v127);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v127;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v99:
    v68 = stack[-2];
    if (v68 == nil) goto v109;
    v112 = stack[0];
    v68 = stack[-2];
    v68 = qcar(v68);
    v68 = qcdr(v68);
    fn = elt(env, 3); /* smember */
    v68 = (*qfn2(fn))(qenv(fn), v112, v68);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    if (v68 == nil) goto v147;
    v68 = stack[-2];
    v68 = qcar(v68);
    v112 = qcar(v68);
    v68 = stack[-1];
    fn = elt(env, 3); /* smember */
    v68 = (*qfn2(fn))(qenv(fn), v112, v68);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    if (v68 == nil) goto v147;
    v68 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v68); }

v147:
    v68 = stack[-2];
    v68 = qcdr(v68);
    stack[-2] = v68;
    goto v99;

v109:
    v68 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v68); }
/* error exit handlers */
v118:
    popv(4);
    return nil;
}



/* Code for physopsim!* */

static Lisp_Object CC_physopsimH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsim*");
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
    v103 = stack[0];
    fn = elt(env, 1); /* !*physopp!* */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-1];
    if (v103 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v103 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* physopsm!* */
        return (*qfn1(fn))(qenv(fn), v103);
    }
/* error exit handlers */
v72:
    popv(2);
    return nil;
}



/* Code for formc */

static Lisp_Object MS_CDECL CC_formc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v127, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v192, v156, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formc");
#endif
    if (stack >= stacklimit)
    {
        push3(v127,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v127);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v127;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v125 = qvalue(elt(env, 1)); /* !*rlisp88 */
    if (v125 == nil) goto v175;
    v192 = stack[-2];
    v125 = elt(env, 2); /* modefn */
    v125 = Lflagpcar(nil, v192, v125);
    env = stack[-3];
    if (v125 == nil) goto v175;
    v125 = stack[-2];
    v192 = qcar(v125);
    v125 = elt(env, 3); /* symbolic */
    if (v192 == v125) goto v175;
    v192 = elt(env, 4); /* "algebraic expression" */
    v125 = elt(env, 5); /* "Rlisp88 form" */
    {
        popv(4);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v192, v125);
    }

v175:
    v192 = stack[0];
    v125 = elt(env, 6); /* algebraic */
    if (!(v192 == v125)) goto v190;
    v192 = stack[-2];
    v125 = stack[-1];
    fn = elt(env, 8); /* intexprnp */
    v125 = (*qfn2(fn))(qenv(fn), v192, v125);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    if (!(v125 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v190:
    v156 = stack[-2];
    v192 = stack[-1];
    v125 = stack[0];
    fn = elt(env, 9); /* form1 */
    v193 = (*qfnn(fn))(qenv(fn), 3, v156, v192, v125);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-3];
    v156 = stack[-1];
    v192 = elt(env, 3); /* symbolic */
    v125 = stack[0];
    {
        popv(4);
        fn = elt(env, 10); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v193, v156, v192, v125);
    }
/* error exit handlers */
v124:
    popv(4);
    return nil;
}



/* Code for fs!:plus */

static Lisp_Object CC_fsTplus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v214, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:plus");
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

v177:
    v37 = stack[-1];
    if (v37 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v37 = stack[-2];
    if (v37 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v214 = stack[-2];
    v37 = (Lisp_Object)17; /* 1 */
    v38 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v214 = stack[-1];
    v37 = (Lisp_Object)17; /* 1 */
    v37 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    if (!(equal(v38, v37))) goto v179;
    v214 = stack[-2];
    v37 = (Lisp_Object)33; /* 2 */
    v38 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v214 = stack[-1];
    v37 = (Lisp_Object)33; /* 2 */
    v37 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    fn = elt(env, 1); /* angles!-equal */
    v37 = (*qfn2(fn))(qenv(fn), v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    if (v37 == nil) goto v179;
    v214 = stack[-2];
    v37 = (Lisp_Object)1; /* 0 */
    v38 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v214 = stack[-1];
    v37 = (Lisp_Object)1; /* 0 */
    v37 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    fn = elt(env, 2); /* addsq */
    v37 = (*qfn2(fn))(qenv(fn), v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    v214 = v37;
    v214 = qcar(v214);
    if (v214 == nil) goto v182;
    v38 = stack[-2];
    v214 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v38 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL))) = v37;
    stack[-3] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v214 = stack[-2];
    v37 = (Lisp_Object)49; /* 3 */
    v38 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v214 = stack[-1];
    v37 = (Lisp_Object)49; /* 3 */
    v37 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v37 = CC_fsTplus(env, v38, v37);
    nil = C_nil;
    if (exception_pending()) goto v215;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v37;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v182:
    v214 = stack[-2];
    v37 = (Lisp_Object)49; /* 3 */
    v38 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v214 = stack[-1];
    v37 = (Lisp_Object)49; /* 3 */
    v37 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    stack[-2] = v38;
    stack[-1] = v37;
    goto v177;

v179:
    v214 = stack[-2];
    v37 = stack[-1];
    fn = elt(env, 3); /* fs!:angle!-order */
    v37 = (*qfn2(fn))(qenv(fn), v214, v37);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-4];
    if (v37 == nil) goto v41;
    stack[-3] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v214 = stack[-2];
    v37 = (Lisp_Object)49; /* 3 */
    v214 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v37 = stack[-1];
    v37 = CC_fsTplus(env, v214, v37);
    nil = C_nil;
    if (exception_pending()) goto v215;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v37;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v41:
    stack[-3] = stack[-1];
    stack[0] = (Lisp_Object)49; /* 3 */
    v214 = stack[-1];
    v37 = (Lisp_Object)49; /* 3 */
    v214 = *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v37/(16/CELL)));
    v37 = stack[-2];
    v37 = CC_fsTplus(env, v214, v37);
    nil = C_nil;
    if (exception_pending()) goto v215;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v37;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
/* error exit handlers */
v215:
    popv(5);
    return nil;
}



/* Code for mo_sum */

static Lisp_Object CC_mo_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_sum");
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
    v95 = v1;
    v96 = v0;
/* end of prologue */
    v96 = qcar(v96);
    v95 = qcar(v95);
    fn = elt(env, 1); /* mo!=sum */
    v95 = (*qfn2(fn))(qenv(fn), v96, v95);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    stack[-1] = v95;
    v95 = stack[-1];
    fn = elt(env, 2); /* mo!=shorten */
    stack[0] = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    v95 = stack[-1];
    fn = elt(env, 3); /* mo!=deglist */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v70;
    {
        Lisp_Object v98 = stack[0];
        popv(3);
        return cons(v98, v95);
    }
/* error exit handlers */
v70:
    popv(3);
    return nil;
}



/* Code for pv_renorm */

static Lisp_Object CC_pv_renorm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_renorm");
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
    stack[0] = v0;
/* end of prologue */
    v205 = stack[0];
    if (!(v205 == nil)) goto v73;
    v205 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v205); }

v73:
    v205 = stack[0];
    if (v205 == nil) goto v72;
    v205 = stack[0];
    v205 = qcar(v205);
    v165 = qcar(v205);
    v205 = (Lisp_Object)1; /* 0 */
    if (!(v165 == v205)) goto v72;
    v205 = stack[0];
    v205 = qcdr(v205);
    stack[0] = v205;
    goto v73;

v72:
    v205 = stack[0];
    if (v205 == nil) goto v147;
    v205 = stack[0];
    v205 = qcar(v205);
    v165 = qcar(v205);
    v205 = (Lisp_Object)1; /* 0 */
    v205 = (Lisp_Object)lessp2(v165, v205);
    nil = C_nil;
    if (exception_pending()) goto v218;
    v205 = v205 ? lisp_true : nil;
    env = stack[-4];
    if (v205 == nil) goto v112;
    v205 = stack[0];
    fn = elt(env, 2); /* pv_neg */
    v205 = (*qfn1(fn))(qenv(fn), v205);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    stack[0] = v205;
    goto v112;

v112:
    v205 = stack[0];
    v205 = qcar(v205);
    v205 = qcar(v205);
    stack[-2] = v205;
    v205 = stack[0];
    v205 = qcdr(v205);
    stack[-3] = v205;
    goto v188;

v188:
    v205 = stack[-3];
    if (v205 == nil) goto v187;
    v165 = stack[-2];
    v205 = (Lisp_Object)17; /* 1 */
    if (v165 == v205) goto v187;
    v165 = stack[-2];
    v205 = stack[-3];
    v205 = qcar(v205);
    v205 = qcar(v205);
    fn = elt(env, 3); /* gcdf!* */
    v205 = (*qfn2(fn))(qenv(fn), v165, v205);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    stack[-2] = v205;
    v205 = stack[-3];
    v205 = qcdr(v205);
    stack[-3] = v205;
    goto v188;

v187:
    v205 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v205;
    v205 = stack[0];
    stack[-1] = v205;
    goto v219;

v219:
    v205 = stack[-1];
    if (v205 == nil) goto v182;
    v205 = stack[-1];
    v205 = qcar(v205);
    stack[0] = v205;
    v205 = stack[0];
    v165 = qcar(v205);
    v205 = (Lisp_Object)1; /* 0 */
    if (v165 == v205) goto v213;
    v165 = stack[-2];
    v205 = (Lisp_Object)17; /* 1 */
    if (v165 == v205) goto v178;
    v205 = stack[0];
    v165 = qcar(v205);
    v205 = stack[-2];
    v165 = quot2(v165, v205);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    v205 = stack[0];
    v205 = qcdr(v205);
    v205 = cons(v165, v205);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    v165 = v205;
    goto v220;

v220:
    v205 = stack[-3];
    v205 = cons(v165, v205);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-4];
    stack[-3] = v205;
    goto v213;

v213:
    v205 = stack[-1];
    v205 = qcdr(v205);
    stack[-1] = v205;
    goto v219;

v178:
    v205 = stack[0];
    v165 = v205;
    goto v220;

v182:
    v205 = stack[-3];
        popv(5);
        return Lnreverse(nil, v205);

v147:
    v205 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v205); }
/* error exit handlers */
v218:
    popv(5);
    return nil;
}



/* Code for general!-modular!-number */

static Lisp_Object CC_generalKmodularKnumber(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-number");
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
    v81 = stack[0];
    v120 = qvalue(elt(env, 1)); /* current!-modulus */
    v120 = Cremainder(v81, v120);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-1];
    stack[0] = v120;
    v81 = stack[0];
    v120 = (Lisp_Object)1; /* 0 */
    v120 = (Lisp_Object)lessp2(v81, v120);
    nil = C_nil;
    if (exception_pending()) goto v79;
    v120 = v120 ? lisp_true : nil;
    env = stack[-1];
    if (v120 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v81 = stack[0];
    v120 = qvalue(elt(env, 1)); /* current!-modulus */
    v120 = plus2(v81, v120);
    nil = C_nil;
    if (exception_pending()) goto v79;
    stack[0] = v120;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v79:
    popv(2);
    return nil;
}



/* Code for fkern */

static Lisp_Object CC_fkern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223, v184, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fkern");
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
    v223 = stack[-1];
    if (!consp(v223)) goto v102;
    v223 = stack[-1];
    v184 = qcar(v223);
    v223 = elt(env, 2); /* fkernfn */
    v223 = get(v184, v223);
    env = stack[-3];
    stack[-2] = v223;
    if (v223 == nil) goto v163;
    v184 = stack[-2];
    v223 = stack[-1];
        popv(4);
        return Lapply1(nil, v184, v223);

v163:
    v223 = stack[-1];
    v223 = qcar(v223);
    if (!consp(v223)) goto v113;
    v223 = qvalue(elt(env, 4)); /* exlist!* */
    goto v175;

v175:
    stack[0] = v223;
    v184 = stack[-1];
    v223 = stack[0];
    v223 = Lassoc(nil, v184, v223);
    stack[-2] = v223;
    if (!(v223 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v184 = stack[-1];
    v223 = qvalue(elt(env, 1)); /* nil */
    v223 = list2(v184, v223);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v223;
    v184 = stack[-2];
    v223 = stack[0];
    fn = elt(env, 6); /* ordad */
    v223 = (*qfn2(fn))(qenv(fn), v184, v223);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[0] = v223;
    v223 = stack[-1];
    v223 = qcar(v223);
    if (!consp(v223)) goto v62;
    v223 = stack[0];
    qvalue(elt(env, 4)) = v223; /* exlist!* */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v62:
    v223 = stack[-1];
    v223 = qcar(v223);
    v184 = ncons(v223);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v223 = qvalue(elt(env, 5)); /* kprops!* */
    fn = elt(env, 7); /* union */
    v223 = (*qfn2(fn))(qenv(fn), v184, v223);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    qvalue(elt(env, 5)) = v223; /* kprops!* */
    v223 = stack[-1];
    v148 = qcar(v223);
    v184 = elt(env, 3); /* klist */
    v223 = stack[0];
    v223 = Lputprop(nil, 3, v148, v184, v223);
    nil = C_nil;
    if (exception_pending()) goto v55;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v113:
    v223 = stack[-1];
    v184 = qcar(v223);
    v223 = elt(env, 3); /* klist */
    v223 = get(v184, v223);
    env = stack[-3];
    goto v175;

v102:
    v223 = stack[-1];
    v184 = qvalue(elt(env, 1)); /* nil */
    popv(4);
    return list2(v223, v184);
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for gizerop!: */

static Lisp_Object CC_gizeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v98, v110;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gizerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v110 = v0;
/* end of prologue */
    v70 = v110;
    v70 = qcdr(v70);
    v98 = qcar(v70);
    v70 = (Lisp_Object)1; /* 0 */
    if (v98 == v70) goto v134;
    v70 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v70);

v134:
    v70 = v110;
    v70 = qcdr(v70);
    v98 = qcdr(v70);
    v70 = (Lisp_Object)1; /* 0 */
    v70 = (v98 == v70 ? lisp_true : nil);
    return onevalue(v70);
}



/* Code for resimp */

static Lisp_Object CC_resimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp");
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
    v99 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v99; /* varstack!* */
    v99 = v163;
    fn = elt(env, 3); /* resimp1 */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v99); }
/* error exit handlers */
v109:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for tayexp!-minusp */

static Lisp_Object CC_tayexpKminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-minusp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v0;
/* end of prologue */
    v103 = v104;
    if (!consp(v103)) goto v108;
    v103 = v104;
    {
        fn = elt(env, 1); /* rnminusp!: */
        return (*qfn1(fn))(qenv(fn), v103);
    }

v108:
    v103 = v104;
        return Lminusp(nil, v103);
}



/* Code for addsq */

static Lisp_Object CC_addsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addsq");
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
    v236 = stack[-3];
    v236 = qcar(v236);
    if (v236 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v236 = stack[-2];
    v236 = qcar(v236);
    if (v236 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v236 = stack[-3];
    v237 = qcdr(v236);
    v236 = (Lisp_Object)17; /* 1 */
    if (!(v237 == v236)) goto v160;
    v236 = stack[-2];
    v237 = qcdr(v236);
    v236 = (Lisp_Object)17; /* 1 */
    if (!(v237 == v236)) goto v160;
    v236 = stack[-3];
    v237 = qcar(v236);
    v236 = stack[-2];
    v236 = qcar(v236);
    fn = elt(env, 4); /* addf */
    v237 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v236 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v237, v236);

v160:
    v236 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v236 == nil)) goto v67;
    v236 = stack[-3];
    stack[0] = qcar(v236);
    v236 = stack[-3];
    v236 = qcdr(v236);
    fn = elt(env, 5); /* mkprod */
    v236 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v236 = cons(stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    stack[-3] = v236;
    v236 = stack[-2];
    stack[0] = qcar(v236);
    v236 = stack[-2];
    v236 = qcdr(v236);
    fn = elt(env, 5); /* mkprod */
    v236 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v236 = cons(stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    stack[-2] = v236;
    goto v67;

v67:
    v236 = qvalue(elt(env, 2)); /* !*lcm */
    if (v236 == nil) goto v141;
    v236 = stack[-3];
    v237 = qcdr(v236);
    v236 = stack[-2];
    v236 = qcdr(v236);
    fn = elt(env, 6); /* gcdf!* */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    stack[-4] = v236;
    goto v57;

v57:
    v236 = stack[-3];
    v237 = qcdr(v236);
    v236 = stack[-4];
    fn = elt(env, 7); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v236 = stack[-2];
    v237 = qcdr(v236);
    v236 = stack[-4];
    fn = elt(env, 7); /* quotf */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v236 = cons(stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    fn = elt(env, 8); /* canonsq */
    v236 = (*qfn1(fn))(qenv(fn), v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    stack[-1] = v236;
    v236 = stack[-1];
    v237 = qcdr(v236);
    v236 = stack[-3];
    v236 = qcar(v236);
    fn = elt(env, 9); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v236 = stack[-1];
    v237 = qcar(v236);
    v236 = stack[-2];
    v236 = qcar(v236);
    fn = elt(env, 9); /* multf */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    fn = elt(env, 4); /* addf */
    v236 = (*qfn2(fn))(qenv(fn), stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    stack[0] = v236;
    v236 = stack[0];
    if (v236 == nil) goto v238;
    v236 = stack[-3];
    v237 = qcdr(v236);
    v236 = stack[-1];
    v236 = qcdr(v236);
    fn = elt(env, 9); /* multf */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    stack[-1] = v236;
    v237 = stack[-4];
    v236 = (Lisp_Object)17; /* 1 */
    if (v237 == v236) goto v36;
    v237 = stack[0];
    v236 = stack[-4];
    fn = elt(env, 10); /* gcdf */
    v237 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    stack[-4] = v237;
    v236 = (Lisp_Object)17; /* 1 */
    if (v237 == v236) goto v36;
    v237 = stack[0];
    v236 = stack[-4];
    fn = elt(env, 7); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v237 = stack[-1];
    v236 = stack[-4];
    fn = elt(env, 7); /* quotf */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    v236 = cons(stack[0], v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 8); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v236);
    }

v36:
    v237 = stack[0];
    v236 = stack[-1];
    popv(6);
    return cons(v237, v236);

v238:
    v237 = qvalue(elt(env, 3)); /* nil */
    v236 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v237, v236);

v141:
    v236 = stack[-3];
    v237 = qcdr(v236);
    v236 = stack[-2];
    v236 = qcdr(v236);
    fn = elt(env, 10); /* gcdf */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-5];
    stack[-4] = v236;
    goto v57;
/* error exit handlers */
v33:
    popv(6);
    return nil;
}



/* Code for qqe_mk2 */

static Lisp_Object MS_CDECL CC_qqe_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v127, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v73, v153;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "qqe_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v127;
    v73 = v1;
    v153 = v0;
/* end of prologue */
    return list3(v153, v73, v72);
}



/* Code for kernord */

static Lisp_Object CC_kernord(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord");
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
    v107 = v1;
    stack[0] = v0;
/* end of prologue */
    v95 = stack[0];
    fn = elt(env, 1); /* kernord!-split */
    v107 = (*qfn2(fn))(qenv(fn), v95, v107);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    stack[0] = v107;
    v107 = stack[0];
    v107 = qcar(v107);
    fn = elt(env, 2); /* kernord!-sort */
    stack[-1] = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v107 = stack[0];
    v107 = qcdr(v107);
    fn = elt(env, 2); /* kernord!-sort */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v71;
    {
        Lisp_Object v70 = stack[-1];
        popv(3);
        return Lappend(nil, v70, v107);
    }
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for ibalp_csat */

static Lisp_Object CC_ibalp_csat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v96;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_csat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v95 = v0;
/* end of prologue */

v177:
    v96 = v95;
    v96 = (v96 == nil ? lisp_true : nil);
    if (!(v96 == nil)) return onevalue(v96);
    v96 = v95;
    v96 = qcar(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcar(v96);
    if (v96 == nil) goto v109;
    v95 = qcdr(v95);
    goto v177;

v109:
    v95 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v95);
}



/* Code for isvalid */

static Lisp_Object CC_isvalid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isvalid");
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
    v66 = stack[0];
    v66 = Lcompress(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v67 = Lsymbolp(nil, v66);
    env = stack[-2];
    v66 = qvalue(elt(env, 1)); /* t */
    if (equal(v67, v66)) goto v107;
    v66 = stack[0];
        popv(3);
        return Lcompress(nil, v66);

v107:
    v66 = stack[0];
    fn = elt(env, 6); /* compress!* */
    v67 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v66 = qvalue(elt(env, 2)); /* functions!* */
    v66 = Lassoc(nil, v67, v66);
    if (v66 == nil) goto v129;
    v66 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v66); }

v129:
    stack[-1] = elt(env, 3); /* !/ */
    v66 = stack[0];
    v66 = Lreverse(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v66 = cons(stack[-1], v66);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v66 = Lreverse(nil, v66);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    stack[0] = v66;
    v66 = stack[0];
    fn = elt(env, 6); /* compress!* */
    v67 = (*qfn1(fn))(qenv(fn), v66);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-2];
    v66 = qvalue(elt(env, 2)); /* functions!* */
    v66 = Lassoc(nil, v67, v66);
    if (v66 == nil) goto v130;
    v66 = stack[0];
    qvalue(elt(env, 4)) = v66; /* char */
    v66 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v66); }

v130:
    v66 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v66); }
/* error exit handlers */
v140:
    popv(3);
    return nil;
}



/* Code for findrow */

static Lisp_Object CC_findrow(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v175, v155, v69;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findrow");
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
    v147 = v1;
    v175 = v0;
/* end of prologue */
    v155 = v175;
    v155 = Lconsp(nil, v155);
    env = stack[0];
    if (v155 == nil) goto v111;
    v155 = v175;
    v155 = qcar(v155);
    v69 = elt(env, 1); /* sparsemat */
    if (!(v155 == v69)) goto v111;
    v175 = qcdr(v175);
    v175 = qcar(v175);
    goto v111;

v111:
    v147 = *(Lisp_Object *)((char *)v175 + (CELL-TAG_VECTOR) + ((int32_t)v147/(16/CELL)));
    { popv(1); return onevalue(v147); }
}



/* Code for vevcompless!? */

static Lisp_Object CC_vevcomplessW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevcompless?");
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
    v159 = v1;
    v134 = v0;
/* end of prologue */
    stack[0] = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* evcomp */
    v134 = (*qfn2(fn))(qenv(fn), v159, v134);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v134 = (stack[0] == v134 ? lisp_true : nil);
    { popv(1); return onevalue(v134); }
/* error exit handlers */
v105:
    popv(1);
    return nil;
}



/* Code for fast_unchecked_getmatelem */

static Lisp_Object CC_fast_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fast_unchecked_getmatelem");
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
    v150 = stack[0];
    v150 = qcar(v150);
    v71 = qcdr(v150);
    v150 = stack[0];
    v150 = qcdr(v150);
    v150 = qcar(v150);
    fn = elt(env, 1); /* pnth */
    v150 = (*qfn2(fn))(qenv(fn), v71, v150);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-1];
    v71 = qcar(v150);
    v150 = stack[0];
    v150 = qcdr(v150);
    v150 = qcdr(v150);
    v150 = qcar(v150);
    fn = elt(env, 1); /* pnth */
    v150 = (*qfn2(fn))(qenv(fn), v71, v150);
    nil = C_nil;
    if (exception_pending()) goto v98;
    v150 = qcar(v150);
    { popv(2); return onevalue(v150); }
/* error exit handlers */
v98:
    popv(2);
    return nil;
}



/* Code for evmatrixcomp */

static Lisp_Object CC_evmatrixcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evmatrixcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v1;
    v72 = v0;
/* end of prologue */
    v73 = v72;
    v72 = v104;
    v104 = qvalue(elt(env, 1)); /* vdpmatrix!* */
    {
        fn = elt(env, 2); /* evmatrixcomp1 */
        return (*qfnn(fn))(qenv(fn), 3, v73, v72, v104);
    }
}



/* Code for atomf */

static Lisp_Object CC_atomf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v153;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atomf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v153 = v0;
/* end of prologue */
    v73 = v153;
    v73 = (consp(v73) ? nil : lisp_true);
    if (!(v73 == nil)) return onevalue(v73);
    v73 = v153;
    v73 = qcar(v73);
    v153 = elt(env, 1); /* indexvar */
        return Lflagp(nil, v73, v153);
}



/* Code for monordp */

static Lisp_Object CC_monordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106, v107, v95;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monordp");
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
/* copy arguments values to proper place */
    v107 = v1;
    v95 = v0;
/* end of prologue */
    v106 = elt(env, 1); /* wedge */
    v105 = elt(env, 2); /* xorder */
    v105 = get(v106, v105);
    v106 = v95;
        return Lapply2(nil, 3, v105, v106, v107);
}



/* Code for delallasc */

static Lisp_Object CC_delallasc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v69, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delallasc");
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
    v68 = nil;
    goto v99;

v99:
    v155 = stack[0];
    if (v155 == nil) goto v109;
    v69 = stack[-1];
    v155 = stack[0];
    v155 = qcar(v155);
    v155 = qcar(v155);
    if (v69 == v155) goto v104;
    v155 = stack[0];
    v155 = qcar(v155);
    v69 = v68;
    v155 = cons(v155, v69);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-2];
    v68 = v155;
    v155 = stack[0];
    v155 = qcdr(v155);
    stack[0] = v155;
    goto v99;

v104:
    v155 = stack[0];
    v155 = qcdr(v155);
    stack[0] = v155;
    goto v99;

v109:
    v155 = v68;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v155);
    }
/* error exit handlers */
v113:
    popv(3);
    return nil;
}



/* Code for !*physopp!* */

static Lisp_Object CC_HphysoppH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *physopp*");
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
    v109 = stack[0];
    fn = elt(env, 1); /* physopp!* */
    v109 = (*qfn1(fn))(qenv(fn), v109);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-1];
    if (!(v109 == nil)) { popv(2); return onevalue(v109); }
    v109 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* getphystype */
        return (*qfn1(fn))(qenv(fn), v109);
    }
/* error exit handlers */
v101:
    popv(2);
    return nil;
}



/* Code for token1 */

static Lisp_Object MS_CDECL CC_token1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "token1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for token1");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    v76 = qvalue(elt(env, 1)); /* crchar!* */
    stack[-3] = v76;
    goto v137;

v137:
    v76 = stack[-3];
    v76 = Lwhitespace_char_p(nil, v76);
    env = stack[-4];
    if (v76 == nil) goto v73;
    v267 = stack[-3];
    v76 = qvalue(elt(env, 2)); /* !$eol!$ */
    if (!(v267 == v76)) goto v72;
    v76 = qvalue(elt(env, 3)); /* !*eoldelimp */
    if (!(v76 == nil)) goto v73;

v72:
    fn = elt(env, 27); /* readch1 */
    v76 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[-3] = v76;
    goto v137;

v73:
    v76 = stack[-3];
    v76 = Ldigitp(nil, v76);
    env = stack[-4];
    if (v76 == nil) goto v120;
    v76 = stack[-3];
    {
        popv(5);
        fn = elt(env, 28); /* token!-number */
        return (*qfn1(fn))(qenv(fn), v76);
    }

v120:
    v76 = stack[-3];
    v76 = Lalpha_char_p(nil, v76);
    env = stack[-4];
    if (!(v76 == nil)) goto v163;
    v267 = stack[-3];
    v76 = elt(env, 4); /* tokprop */
    v76 = get(v267, v76);
    env = stack[-4];
    stack[-2] = v76;
    if (v76 == nil) goto v157;
    v76 = stack[-2];
    if (!consp(v76)) goto v114;
    v267 = elt(env, 5); /* "Apply called with non-id arg" */
    v76 = stack[-2];
    v76 = list2(v267, v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v267 = v76;
    v76 = v267;
    qvalue(elt(env, 6)) = v76; /* errmsg!* */
    v76 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v76 == nil)) goto v64;
    v76 = v267;
    fn = elt(env, 29); /* lprie */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v64;

v64:
    v76 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v268;
    v76 = nil;
    { popv(5); return onevalue(v76); }

v114:
    v267 = stack[-2];
    v76 = qvalue(elt(env, 8)); /* nil */
    {
        popv(5);
        fn = elt(env, 30); /* apply */
        return (*qfn2(fn))(qenv(fn), v267, v76);
    }

v157:
    v267 = stack[-3];
    v76 = elt(env, 9); /* !% */
    if (!(v267 == v76)) goto v144;
    v76 = qvalue(elt(env, 10)); /* !*savecomments!* */
    if (!(v76 == nil)) goto v144;
    stack[-1] = qvalue(elt(env, 23)); /* !*lower */
    qvalue(elt(env, 23)) = nil; /* !*lower */
    v76 = qvalue(elt(env, 24)); /* !*raise */
    stack[0] = v76;
    v76 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 24)) = v76; /* !*raise */
    goto v269;

v269:
    fn = elt(env, 27); /* readch1 */
    v267 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-4];
    v76 = qvalue(elt(env, 2)); /* !$eol!$ */
    if (!(v267 == v76)) goto v269;
    v76 = stack[0];
    qvalue(elt(env, 24)) = v76; /* !*raise */
    qvalue(elt(env, 23)) = stack[-1]; /* !*lower */
    fn = elt(env, 27); /* readch1 */
    v76 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[-3] = v76;
    goto v137;

v144:
    v267 = stack[-3];
    v76 = elt(env, 11); /* !! */
    if (!(v267 == v76)) goto v223;
    v76 = qvalue(elt(env, 12)); /* !*micro!-version */
    if (v76 == nil) goto v99;
    v76 = qvalue(elt(env, 13)); /* !*defn */
    if (!(v76 == nil)) goto v99;

v223:
    v267 = stack[-3];
    v76 = elt(env, 14); /* !" */
    if (v267 == v76) goto v77;
    v76 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 15)) = v76; /* ttype!* */
    v267 = stack[-3];
    v76 = qvalue(elt(env, 16)); /* !$eof!$ */
    if (!(v267 == v76)) goto v270;
    v76 = elt(env, 17); /* !  */
    qvalue(elt(env, 1)) = v76; /* crchar!* */
    fn = elt(env, 31); /* filenderr */
    v76 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    goto v270;

v270:
    v76 = stack[-3];
    qvalue(elt(env, 18)) = v76; /* nxtsym!* */
    v267 = stack[-3];
    v76 = elt(env, 19); /* delchar */
    v76 = Lflagp(nil, v267, v76);
    env = stack[-4];
    if (v76 == nil) goto v47;
    v76 = elt(env, 17); /* !  */
    qvalue(elt(env, 1)) = v76; /* crchar!* */
    goto v164;

v164:
    v267 = stack[-3];
    v76 = elt(env, 20); /* !- */
    if (!(v267 == v76)) goto v109;
    v76 = qvalue(elt(env, 1)); /* crchar!* */
    v76 = Ldigitp(nil, v76);
    env = stack[-4];
    if (v76 == nil) goto v109;
    v76 = qvalue(elt(env, 21)); /* !*minusliter */
    if (v76 == nil) goto v109;
    v76 = qvalue(elt(env, 1)); /* crchar!* */
    fn = elt(env, 28); /* token!-number */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[-3] = v76;
    v76 = stack[-3];
    if (is_number(v76)) goto v203;
    v76 = stack[-3];
    stack[0] = qcdr(v76);
    v267 = elt(env, 22); /* minus */
    v76 = stack[-3];
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = Lapply1(nil, v267, v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v76 = Lrplaca(nil, stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v203:
    v267 = elt(env, 22); /* minus */
    v76 = stack[-3];
        popv(5);
        return Lapply1(nil, v267, v76);

v109:
    v76 = qvalue(elt(env, 18)); /* nxtsym!* */
    { popv(5); return onevalue(v76); }

v47:
    fn = elt(env, 27); /* readch1 */
    v76 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    qvalue(elt(env, 1)) = v76; /* crchar!* */
    goto v164;

v77:
    stack[0] = qvalue(elt(env, 23)); /* !*lower */
    qvalue(elt(env, 23)) = nil; /* !*lower */
    v76 = qvalue(elt(env, 24)); /* !*raise */
    stack[-1] = v76;
    v76 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 24)) = v76; /* !*raise */
    goto v271;

v271:
    v267 = stack[-3];
    v76 = stack[-2];
    v76 = cons(v267, v76);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[-2] = v76;
    fn = elt(env, 27); /* readch1 */
    v267 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[-3] = v267;
    v76 = qvalue(elt(env, 16)); /* !$eof!$ */
    if (v267 == v76) goto v273;
    v267 = stack[-3];
    v76 = elt(env, 14); /* !" */
    if (!(v267 == v76)) goto v271;

v274:
    v267 = stack[-3];
    v76 = stack[-2];
    v76 = cons(v267, v76);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[-2] = v76;
    fn = elt(env, 27); /* readch1 */
    v76 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    stack[-3] = v76;
    v267 = stack[-3];
    v76 = elt(env, 14); /* !" */
    if (v267 == v76) goto v271;
    v76 = stack[-2];
    v76 = Lnreverse(nil, v76);
    env = stack[-4];
    v76 = Lcompress(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    qvalue(elt(env, 18)) = v76; /* nxtsym!* */
    v76 = stack[-1];
    qvalue(elt(env, 24)) = v76; /* !*raise */
    qvalue(elt(env, 23)) = stack[0]; /* !*lower */
    v76 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 15)) = v76; /* ttype!* */
    v76 = stack[-3];
    qvalue(elt(env, 1)) = v76; /* crchar!* */
    goto v109;

v273:
    v76 = stack[-1];
    qvalue(elt(env, 24)) = v76; /* !*raise */
    v76 = elt(env, 17); /* !  */
    qvalue(elt(env, 1)) = v76; /* crchar!* */
    v267 = elt(env, 26); /* "***** End-of-file in string" */
    v76 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 32); /* lpriw */
    v76 = (*qfn2(fn))(qenv(fn), v267, v76);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    fn = elt(env, 31); /* filenderr */
    v76 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-4];
    goto v274;

v99:
    stack[0] = qvalue(elt(env, 23)); /* !*lower */
    qvalue(elt(env, 23)) = nil; /* !*lower */
    v76 = qvalue(elt(env, 24)); /* !*raise */
    stack[-1] = v76;
    v76 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 24)) = v76; /* !*raise */
    v267 = stack[-3];
    v76 = stack[-2];
    v76 = cons(v267, v76);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-4];
    stack[-2] = v76;
    fn = elt(env, 27); /* readch1 */
    v76 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v275;
    env = stack[-4];
    stack[-3] = v76;
    v76 = stack[-1];
    qvalue(elt(env, 24)) = v76; /* !*raise */
    qvalue(elt(env, 23)) = stack[0]; /* !*lower */
    goto v163;

v163:
    v76 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 15)) = v76; /* ttype!* */
    goto v35;

v35:
    v267 = stack[-3];
    v76 = stack[-2];
    v76 = cons(v267, v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[-2] = v76;
    fn = elt(env, 27); /* readch1 */
    v76 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[-3] = v76;
    v76 = Ldigitp(nil, v76);
    env = stack[-4];
    if (!(v76 == nil)) goto v35;
    v76 = stack[-3];
    v76 = Lalpha_char_p(nil, v76);
    env = stack[-4];
    if (!(v76 == nil)) goto v35;
    v267 = stack[-3];
    v76 = elt(env, 11); /* !! */
    if (v267 == v76) goto v99;
    v267 = stack[-3];
    v76 = elt(env, 20); /* !- */
    if (!(v267 == v76)) goto v88;
    v76 = qvalue(elt(env, 21)); /* !*minusliter */
    if (v76 == nil) goto v88;
    v267 = elt(env, 11); /* !! */
    v76 = stack[-2];
    v76 = cons(v267, v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    stack[-2] = v76;
    goto v35;

v88:
    v267 = stack[-3];
    v76 = elt(env, 25); /* !_ */
    if (v267 == v76) goto v35;
    v76 = stack[-2];
    v76 = Lnreverse(nil, v76);
    env = stack[-4];
    v76 = Lcompress(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    v76 = Lintern(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-4];
    qvalue(elt(env, 18)) = v76; /* nxtsym!* */
    v76 = stack[-3];
    qvalue(elt(env, 1)) = v76; /* crchar!* */
    goto v109;
/* error exit handlers */
v275:
    env = stack[-4];
    qvalue(elt(env, 23)) = stack[0]; /* !*lower */
    popv(5);
    return nil;
v272:
    env = stack[-4];
    qvalue(elt(env, 23)) = stack[0]; /* !*lower */
    popv(5);
    return nil;
v80:
    env = stack[-4];
    qvalue(elt(env, 23)) = stack[-1]; /* !*lower */
    popv(5);
    return nil;
v268:
    popv(5);
    return nil;
}



/* Code for nonzero!-length */

static Lisp_Object CC_nonzeroKlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v110, v100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonzero-length");
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

v108:
    v98 = v110;
    if (v98 == nil) goto v163;
    v98 = v110;
    v100 = qcar(v98);
    v98 = (Lisp_Object)1; /* 0 */
    if (v100 == v98) goto v101;
    v98 = v110;
    v98 = qcdr(v98);
    v98 = CC_nonzeroKlength(env, v98);
    errexit();
    return add1(v98);

v101:
    v98 = v110;
    v98 = qcdr(v98);
    v110 = v98;
    goto v108;

v163:
    v98 = (Lisp_Object)1; /* 0 */
    return onevalue(v98);
}



/* Code for bas_rep */

static Lisp_Object CC_bas_rep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_rep");
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
    v101 = v0;
/* end of prologue */
    v102 = v101;
    v101 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v101 = (*qfn2(fn))(qenv(fn), v102, v101);
    errexit();
    v101 = qcar(v101);
    return onevalue(v101);
}



/* Code for cdiv */

static Lisp_Object CC_cdiv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdiv");
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
    v103 = v1;
    v104 = v0;
/* end of prologue */
    v103 = cons(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[0];
    fn = elt(env, 1); /* resimp */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v103 = qcar(v103);
    { popv(1); return onevalue(v103); }
/* error exit handlers */
v72:
    popv(1);
    return nil;
}



/* Code for lcm */

static Lisp_Object CC_lcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v116, v117, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lcm");
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
    v117 = v1;
    v66 = v0;
/* end of prologue */
    v151 = v66;
    if (v151 == nil) goto v137;
    v151 = v117;
    if (v151 == nil) goto v137;
    v116 = v66;
    v151 = (Lisp_Object)17; /* 1 */
    if (v116 == v151) { popv(3); return onevalue(v117); }
    v116 = v117;
    v151 = (Lisp_Object)17; /* 1 */
    if (v116 == v151) { popv(3); return onevalue(v66); }
    stack[-1] = v66;
    stack[0] = v117;
    v151 = v66;
    v116 = v117;
    fn = elt(env, 2); /* gcdf */
    v151 = (*qfn2(fn))(qenv(fn), v151, v116);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    fn = elt(env, 3); /* quotf */
    v151 = (*qfn2(fn))(qenv(fn), stack[0], v151);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    {
        Lisp_Object v140 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v140, v151);
    }

v137:
    v151 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v151); }
/* error exit handlers */
v161:
    popv(3);
    return nil;
}



/* Code for mkrn */

static Lisp_Object CC_mkrn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v66;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrn");
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

v101:
    v66 = stack[-1];
    v117 = (Lisp_Object)1; /* 0 */
    v117 = (Lisp_Object)lessp2(v66, v117);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v117 = v117 ? lisp_true : nil;
    env = stack[-4];
    if (v117 == nil) goto v96;
    v117 = stack[-2];
    v117 = negate(v117);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    stack[-2] = v117;
    v117 = stack[-1];
    v117 = negate(v117);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    stack[-1] = v117;
    goto v101;

v96:
    v66 = stack[-2];
    v117 = stack[-1];
    v117 = Lgcd(nil, v66, v117);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    stack[-3] = v117;
    stack[0] = elt(env, 1); /* !:rn!: */
    v66 = stack[-2];
    v117 = stack[-3];
    stack[-2] = quot2(v66, v117);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v66 = stack[-1];
    v117 = stack[-3];
    v117 = quot2(v66, v117);
    nil = C_nil;
    if (exception_pending()) goto v187;
    {
        Lisp_Object v188 = stack[0];
        Lisp_Object v189 = stack[-2];
        popv(5);
        return list2star(v188, v189, v117);
    }
/* error exit handlers */
v187:
    popv(5);
    return nil;
}



/* Code for !*modular2f */

static Lisp_Object CC_Hmodular2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v60;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *modular2f");
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

v109:
    v60 = stack[0];
    v61 = (Lisp_Object)1; /* 0 */
    if (v60 == v61) goto v163;
    v61 = qvalue(elt(env, 2)); /* !*balanced_mod */
    if (v61 == nil) goto v126;
    v60 = stack[0];
    v61 = stack[0];
    v60 = plus2(v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    v61 = qvalue(elt(env, 3)); /* current!-modulus */
    v61 = (Lisp_Object)greaterp2(v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v141;
    v61 = v61 ? lisp_true : nil;
    env = stack[-2];
    if (v61 == nil) goto v140;
    stack[-1] = elt(env, 4); /* !:mod!: */
    v60 = stack[0];
    v61 = qvalue(elt(env, 3)); /* current!-modulus */
    v61 = difference2(v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v141;
    {
        Lisp_Object v276 = stack[-1];
        popv(3);
        return cons(v276, v61);
    }

v140:
    v60 = stack[0];
    v61 = stack[0];
    stack[-1] = plus2(v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    v61 = qvalue(elt(env, 3)); /* current!-modulus */
    v61 = negate(v61);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    v61 = (Lisp_Object)lesseq2(stack[-1], v61);
    nil = C_nil;
    if (exception_pending()) goto v141;
    v61 = v61 ? lisp_true : nil;
    env = stack[-2];
    if (v61 == nil) goto v192;
    v60 = stack[0];
    v61 = qvalue(elt(env, 3)); /* current!-modulus */
    v61 = plus2(v60, v61);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-2];
    stack[0] = v61;
    goto v109;

v192:
    v60 = elt(env, 4); /* !:mod!: */
    v61 = stack[0];
    popv(3);
    return cons(v60, v61);

v126:
    v60 = elt(env, 4); /* !:mod!: */
    v61 = stack[0];
    popv(3);
    return cons(v60, v61);

v163:
    v61 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v61); }
/* error exit handlers */
v141:
    popv(3);
    return nil;
}



/* Code for sfto_gcdf */

static Lisp_Object CC_sfto_gcdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf");
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
    v151 = qvalue(elt(env, 1)); /* !*rldavgcd */
    if (v151 == nil) goto v109;
    v116 = stack[-1];
    v151 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v151 = (*qfn2(fn))(qenv(fn), v116, v151);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    if (!(v151 == nil)) goto v73;
    v116 = stack[0];
    v151 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v151 = (*qfn2(fn))(qenv(fn), v116, v151);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    if (!(v151 == nil)) goto v73;
    v116 = stack[-1];
    v151 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ezgcdf */
        return (*qfn2(fn))(qenv(fn), v116, v151);
    }

v73:
    v151 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = v151; /* !*ezgcd */
    v116 = stack[-1];
    v151 = stack[0];
    fn = elt(env, 6); /* gcdf */
    v151 = (*qfn2(fn))(qenv(fn), v116, v151);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    { popv(4); return onevalue(v151); }

v109:
    v116 = stack[-1];
    v151 = stack[0];
    {
        popv(4);
        fn = elt(env, 6); /* gcdf */
        return (*qfn2(fn))(qenv(fn), v116, v151);
    }
/* error exit handlers */
v161:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    popv(4);
    return nil;
v133:
    popv(4);
    return nil;
}



/* Code for frvarsof */

static Lisp_Object CC_frvarsof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v161, v140, v187;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for frvarsof");
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
    v161 = v1;
    v140 = v0;
/* end of prologue */

v101:
    v187 = v140;
    v133 = qvalue(elt(env, 1)); /* frlis!* */
    v133 = Lmemq(nil, v187, v133);
    if (v133 == nil) goto v77;
    v187 = v140;
    v133 = v161;
    v133 = Lmemq(nil, v187, v133);
    if (!(v133 == nil)) { popv(2); return onevalue(v161); }
    stack[0] = v161;
    v133 = v140;
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v189;
    {
        Lisp_Object v145 = stack[0];
        popv(2);
        return Lappend(nil, v145, v133);
    }

v77:
    v133 = v140;
    if (!consp(v133)) { popv(2); return onevalue(v161); }
    v133 = v140;
    v133 = qcdr(v133);
    stack[0] = v133;
    v133 = v140;
    v133 = qcar(v133);
    v133 = CC_frvarsof(env, v133, v161);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-1];
    v161 = v133;
    v133 = stack[0];
    v140 = v133;
    goto v101;
/* error exit handlers */
v189:
    popv(2);
    return nil;
}



/* Code for prepd */

static Lisp_Object CC_prepd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v171, v183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepd");
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
    v172 = stack[0];
    if (!consp(v172)) goto v102;
    v172 = stack[0];
    v171 = qcar(v172);
    v172 = elt(env, 2); /* minusp */
    v171 = get(v171, v172);
    env = stack[-2];
    v172 = stack[0];
    v172 = Lapply1(nil, v171, v172);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    if (v172 == nil) goto v144;
    v172 = stack[0];
    fn = elt(env, 4); /* !:minus */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    v183 = v172;
    v172 = v183;
    if (!consp(v172)) goto v82;
    v172 = v183;
    v171 = qcar(v172);
    v172 = elt(env, 3); /* prepfn */
    v172 = get(v171, v172);
    env = stack[-2];
    v171 = v183;
    v172 = Lapply1(nil, v172, v171);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-2];
    goto v191;

v191:
    v171 = v172;
    v172 = v171;
    if (v172 == nil) goto v132;
    v172 = elt(env, 1); /* minus */
    popv(3);
    return list2(v172, v171);

v132:
    v172 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v172); }

v82:
    v172 = v183;
    goto v191;

v144:
    v172 = stack[0];
    v171 = qcar(v172);
    v172 = elt(env, 3); /* prepfn */
    v171 = get(v171, v172);
    v172 = stack[0];
        popv(3);
        return Lapply1(nil, v171, v172);

v102:
    v171 = stack[0];
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)lessp2(v171, v172);
    nil = C_nil;
    if (exception_pending()) goto v223;
    v172 = v172 ? lisp_true : nil;
    env = stack[-2];
    if (v172 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); /* minus */
    v172 = stack[0];
    v172 = negate(v172);
    nil = C_nil;
    if (exception_pending()) goto v223;
    {
        Lisp_Object v184 = stack[-1];
        popv(3);
        return list2(v184, v172);
    }
/* error exit handlers */
v223:
    popv(3);
    return nil;
}



/* Code for qqe_id!-nyt!-branchb */

static Lisp_Object CC_qqe_idKnytKbranchb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchb");
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
    v150 = stack[0];
    if (!consp(v150)) goto v108;
    v150 = stack[0];
    v150 = qcar(v150);
    fn = elt(env, 1); /* qqe_qopaddp */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    if (!(v150 == nil)) goto v153;
    v150 = stack[0];
    v150 = qcar(v150);
    fn = elt(env, 2); /* qqe_qoptailp */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v70;
    goto v153;

v153:
    v150 = (v150 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v150); }

v108:
    v150 = stack[0];
    fn = elt(env, 3); /* qqe_btidp */
    v150 = (*qfn1(fn))(qenv(fn), v150);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-1];
    if (!(v150 == nil)) { popv(2); return onevalue(v150); }
    v150 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* qqe_nytidp */
        return (*qfn1(fn))(qenv(fn), v150);
    }
/* error exit handlers */
v70:
    popv(2);
    return nil;
}



/* Code for rl_susibin */

static Lisp_Object CC_rl_susibin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susibin");
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
    v134 = v1;
    v159 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susibin!* */
    v134 = list2(v159, v134);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    {
        Lisp_Object v106 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v106, v134);
    }
/* error exit handlers */
v105:
    popv(2);
    return nil;
}



/* Code for lto_insertq */

static Lisp_Object CC_lto_insertq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v71, v70, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_insertq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v71 = v1;
    v70 = v0;
/* end of prologue */
    v98 = v70;
    v150 = v71;
    v150 = Lmemq(nil, v98, v150);
    if (!(v150 == nil)) return onevalue(v71);
    v150 = v70;
    return cons(v150, v71);
}



/* Code for powers2 */

static Lisp_Object MS_CDECL CC_powers2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v127, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v161, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powers2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powers2");
#endif
    if (stack >= stacklimit)
    {
        push3(v127,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v127);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v127;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v163:
    v133 = stack[-2];
    if (!consp(v133)) goto v77;
    v133 = stack[-2];
    v133 = qcar(v133);
    if (!consp(v133)) goto v77;
    v133 = stack[-2];
    v133 = qcar(v133);
    v133 = qcdr(v133);
    stack[-3] = v133;
    v133 = stack[-2];
    v140 = qcdr(v133);
    v161 = stack[-1];
    v133 = stack[0];
    v133 = CC_powers2(env, 3, v140, v161, v133);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    stack[-1] = v133;
    v133 = stack[-2];
    v133 = qcar(v133);
    v161 = qcar(v133);
    v133 = stack[0];
    v133 = cons(v161, v133);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    stack[0] = v133;
    v133 = stack[-3];
    stack[-2] = v133;
    goto v163;

v77:
    v133 = stack[-2];
    if (v133 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v161 = stack[0];
    v133 = stack[-1];
    {
        popv(5);
        fn = elt(env, 1); /* powers4 */
        return (*qfn2(fn))(qenv(fn), v161, v133);
    }
/* error exit handlers */
v146:
    popv(5);
    return nil;
}



/* Code for indent!* */

static Lisp_Object CC_indentH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v128;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indent*");
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
    v128 = stack[0];
    v79 = qvalue(elt(env, 1)); /* t */
    if (!(equal(v128, v79))) goto v137;
    v128 = qvalue(elt(env, 2)); /* indent */
    v79 = qvalue(elt(env, 3)); /* ind */
    v79 = plus2(v128, v79);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-1];
    qvalue(elt(env, 2)) = v79; /* indent */
    goto v137;

v137:
    v79 = stack[0];
    if (!(v79 == nil)) goto v95;
    v128 = qvalue(elt(env, 2)); /* indent */
    v79 = qvalue(elt(env, 3)); /* ind */
    v79 = difference2(v128, v79);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-1];
    qvalue(elt(env, 2)) = v79; /* indent */
    goto v95;

v95:
    v79 = nil;
    { popv(2); return onevalue(v79); }
/* error exit handlers */
v175:
    popv(2);
    return nil;
}



/* Code for isarb_compl */

static Lisp_Object CC_isarb_compl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v110, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_compl");
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
    v98 = v110;
    v98 = Lconsp(nil, v98);
    env = stack[0];
    if (v98 == nil) goto v137;
    v98 = v110;
    v100 = qcar(v98);
    v98 = elt(env, 1); /* arbcomplex */
    if (v100 == v98) goto v102;
    v98 = v110;
    v98 = qcdr(v98);
    fn = elt(env, 4); /* multi_isarb_compl */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v111;
    goto v137;

v137:
    v98 = nil;
    { popv(1); return onevalue(v98); }

v102:
    v98 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v98; /* found_compl */
    goto v137;
/* error exit handlers */
v111:
    popv(1);
    return nil;
}



/* Code for downwght */

static Lisp_Object CC_downwght(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for downwght");
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
    v72 = stack[-1];
    fn = elt(env, 1); /* delhisto */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-2];
    v73 = stack[-1];
    v72 = stack[0];
    fn = elt(env, 2); /* downwght1 */
    v72 = (*qfn2(fn))(qenv(fn), v73, v72);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-2];
    v72 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* inshisto */
        return (*qfn1(fn))(qenv(fn), v72);
    }
/* error exit handlers */
v159:
    popv(3);
    return nil;
}



/* Code for bound */

static Lisp_Object CC_bound(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bound");
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
    v105 = v0;
/* end of prologue */
    fn = elt(env, 3); /* binding */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[0];
    v106 = v105;
    v105 = v106;
    if (v105 == nil) goto v163;
    v105 = v106;
    v106 = elt(env, 2); /* unbound */
        popv(1);
        return Lneq(nil, v105, v106);

v163:
    v105 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v105); }
/* error exit handlers */
v107:
    popv(1);
    return nil;
}



/* Code for vevtdeg */

static Lisp_Object CC_vevtdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v130, v113;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevtdeg");
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
    v130 = nil;
    goto v99;

v99:
    v112 = stack[0];
    if (v112 == nil) goto v163;
    v112 = stack[0];
    v112 = qcar(v112);
    v112 = cons(v112, v130);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-1];
    v130 = v112;
    v112 = stack[0];
    v112 = qcdr(v112);
    stack[0] = v112;
    goto v99;

v163:
    v112 = (Lisp_Object)1; /* 0 */
    goto v78;

v78:
    v113 = v130;
    if (v113 == nil) { popv(2); return onevalue(v112); }
    v113 = v130;
    v113 = qcar(v113);
    v112 = (Lisp_Object)(int32_t)((int32_t)v113 + (int32_t)v112 - TAG_FIXNUM);
    v130 = qcdr(v130);
    goto v78;
/* error exit handlers */
v118:
    popv(2);
    return nil;
}



/* Code for xdiv */

static Lisp_Object CC_xdiv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdiv");
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
    stack[-2] = stack[-1];
    v112 = (Lisp_Object)17; /* 1 */
    v112 = ncons(v112);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    if (equal(stack[-2], v112)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v130 = stack[-1];
    v112 = stack[0];
    fn = elt(env, 1); /* sublistp */
    v112 = (*qfn2(fn))(qenv(fn), v130, v112);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-3];
    if (v112 == nil) goto v153;
    v130 = stack[0];
    v112 = stack[-1];
    fn = elt(env, 2); /* listdiff */
    v112 = (*qfn2(fn))(qenv(fn), v130, v112);
    nil = C_nil;
    if (exception_pending()) goto v119;
    stack[0] = v112;
    if (!(v112 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v112 = (Lisp_Object)17; /* 1 */
    popv(4);
    return ncons(v112);

v153:
    v112 = nil;
    { popv(4); return onevalue(v112); }
/* error exit handlers */
v119:
    popv(4);
    return nil;
}



setup_type const u04_setup[] =
{
    {"mchk",                    too_few_2,      CC_mchk,       wrong_no_2},
    {"rev",                     too_few_2,      CC_rev,        wrong_no_2},
    {"*i2rn",                   CC_Hi2rn,       too_many_1,    wrong_no_1},
    {"gintequiv:",              CC_gintequivT,  too_many_1,    wrong_no_1},
    {"rl_smcpknowl",            CC_rl_smcpknowl,too_many_1,    wrong_no_1},
    {"invsq",                   CC_invsq,       too_many_1,    wrong_no_1},
    {"ibalp_varlt",             CC_ibalp_varlt, too_many_1,    wrong_no_1},
    {"lex",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_lex},
    {"fullcopy",                CC_fullcopy,    too_many_1,    wrong_no_1},
    {"pnthxzz",                 too_few_2,      CC_pnthxzz,    wrong_no_2},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"quotematrix",             CC_quotematrix, too_many_1,    wrong_no_1},
    {"getrtype2",               CC_getrtype2,   too_many_1,    wrong_no_1},
    {"tensopp",                 CC_tensopp,     too_many_1,    wrong_no_1},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"lpri",                    CC_lpri,        too_many_1,    wrong_no_1},
    {"getrtype",                CC_getrtype,    too_many_1,    wrong_no_1},
    {"negf",                    CC_negf,        too_many_1,    wrong_no_1},
    {"mo=shorten",              CC_moMshorten,  too_many_1,    wrong_no_1},
    {"dquot",                   too_few_2,      CC_dquot,      wrong_no_2},
    {"pv_sort2",                too_few_2,      CC_pv_sort2,   wrong_no_2},
    {"c:ordexp",                too_few_2,      CC_cTordexp,   wrong_no_2},
    {"evaluate-in-order",       too_few_2,      CC_evaluateKinKorder,wrong_no_2},
    {"get+vec+dim",             CC_getLvecLdim, too_many_1,    wrong_no_1},
    {"sf_idl",                  CC_sf_idl,      too_many_1,    wrong_no_1},
    {"multi_elem",              CC_multi_elem,  too_many_1,    wrong_no_1},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"revlis",                  CC_revlis,      too_many_1,    wrong_no_1},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"nextarg",                 CC_nextarg,     too_many_1,    wrong_no_1},
    {"evtdeg",                  CC_evtdeg,      too_many_1,    wrong_no_1},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"freeofdepl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_freeofdepl},
    {"physopsim*",              CC_physopsimH,  too_many_1,    wrong_no_1},
    {"formc",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_formc},
    {"fs:plus",                 too_few_2,      CC_fsTplus,    wrong_no_2},
    {"mo_sum",                  too_few_2,      CC_mo_sum,     wrong_no_2},
    {"pv_renorm",               CC_pv_renorm,   too_many_1,    wrong_no_1},
    {"general-modular-number",  CC_generalKmodularKnumber,too_many_1,wrong_no_1},
    {"fkern",                   CC_fkern,       too_many_1,    wrong_no_1},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"resimp",                  CC_resimp,      too_many_1,    wrong_no_1},
    {"tayexp-minusp",           CC_tayexpKminusp,too_many_1,   wrong_no_1},
    {"addsq",                   too_few_2,      CC_addsq,      wrong_no_2},
    {"qqe_mk2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_qqe_mk2},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"ibalp_csat",              CC_ibalp_csat,  too_many_1,    wrong_no_1},
    {"isvalid",                 CC_isvalid,     too_many_1,    wrong_no_1},
    {"findrow",                 too_few_2,      CC_findrow,    wrong_no_2},
    {"vevcompless?",            too_few_2,      CC_vevcomplessW,wrong_no_2},
    {"fast_unchecked_getmatelem",CC_fast_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"evmatrixcomp",            too_few_2,      CC_evmatrixcomp,wrong_no_2},
    {"atomf",                   CC_atomf,       too_many_1,    wrong_no_1},
    {"monordp",                 too_few_2,      CC_monordp,    wrong_no_2},
    {"delallasc",               too_few_2,      CC_delallasc,  wrong_no_2},
    {"*physopp*",               CC_HphysoppH,   too_many_1,    wrong_no_1},
    {"token1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_token1},
    {"nonzero-length",          CC_nonzeroKlength,too_many_1,  wrong_no_1},
    {"bas_rep",                 CC_bas_rep,     too_many_1,    wrong_no_1},
    {"cdiv",                    too_few_2,      CC_cdiv,       wrong_no_2},
    {"lcm",                     too_few_2,      CC_lcm,        wrong_no_2},
    {"mkrn",                    too_few_2,      CC_mkrn,       wrong_no_2},
    {"*modular2f",              CC_Hmodular2f,  too_many_1,    wrong_no_1},
    {"sfto_gcdf",               too_few_2,      CC_sfto_gcdf,  wrong_no_2},
    {"frvarsof",                too_few_2,      CC_frvarsof,   wrong_no_2},
    {"prepd",                   CC_prepd,       too_many_1,    wrong_no_1},
    {"qqe_id-nyt-branchb",      CC_qqe_idKnytKbranchb,too_many_1,wrong_no_1},
    {"rl_susibin",              too_few_2,      CC_rl_susibin, wrong_no_2},
    {"lto_insertq",             too_few_2,      CC_lto_insertq,wrong_no_2},
    {"powers2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powers2},
    {"indent*",                 CC_indentH,     too_many_1,    wrong_no_1},
    {"isarb_compl",             CC_isarb_compl, too_many_1,    wrong_no_1},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"bound",                   CC_bound,       too_many_1,    wrong_no_1},
    {"vevtdeg",                 CC_vevtdeg,     too_many_1,    wrong_no_1},
    {"xdiv",                    too_few_2,      CC_xdiv,       wrong_no_2},
    {NULL, (one_args *)"u04", (two_args *)"22445 2783105 3503058", 0}
};

/* end of generated code */
