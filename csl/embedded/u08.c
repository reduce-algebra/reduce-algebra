
/* $destdir/generated-c\u08.c Machine generated C code */

/* Signature: 00000000 13-Aug-2010 */

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
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? 153600 : 2048)
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
#define PAGE_MASK               ((((uint32_t)1) << (32-PAGE_BITS)) - 1)
#define OFFSET_MASK             ((((uint32_t)1) << PAGE_BITS) - 1)
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
extern Lisp_Object gchook, resources, callstack;
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
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#endif
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
extern jmp_buf *errorset_buffer;
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
extern int time_base,  space_base,  io_base,  errors_base;
extern int time_now,   space_now,   io_now,   errors_now;
extern int time_limit, space_limit, io_limit, errors_limit;
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


/* Code for stable!-sortip */

static Lisp_Object CC_stableKsortip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stable-sortip");
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
    v30 = stack[-3];
    if (v30 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v30 = stack[-3];
    stack[-4] = v30;
    v30 = stack[-3];
    v30 = qcdr(v30);
    stack[-1] = v30;
    v30 = stack[-1];
    if (v30 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-3] = v30;
    v30 = stack[-3];
    if (v30 == nil) goto v33;
    v30 = stack[-4];
    stack[-3] = v30;
    goto v34;

v34:
    v30 = stack[-1];
    if (v30 == nil) goto v35;
    v32 = stack[-2];
    v30 = stack[-1];
    v31 = qcar(v30);
    v30 = stack[-3];
    v30 = qcar(v30);
    v30 = Lapply2(nil, 3, v32, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    if (!(v30 == nil)) goto v35;
    v30 = stack[-1];
    stack[-3] = v30;
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    goto v34;

v35:
    v30 = stack[-1];
    if (v30 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v30 = stack[-4];
    stack[-1] = v30;
    v30 = stack[-1];
    v30 = qcdr(v30);
    v30 = qcdr(v30);
    stack[-3] = v30;
    goto v37;

v37:
    v30 = stack[-3];
    if (v30 == nil) goto v38;
    v30 = stack[-3];
    v30 = qcdr(v30);
    if (v30 == nil) goto v38;
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    v30 = stack[-3];
    v30 = qcdr(v30);
    v30 = qcdr(v30);
    stack[-3] = v30;
    goto v37;

v38:
    v30 = stack[-1];
    stack[-3] = v30;
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    v31 = stack[-3];
    v30 = qvalue(elt(env, 1)); /* nil */
    v30 = Lrplacd(nil, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    v31 = stack[-4];
    v30 = stack[-2];
    v30 = CC_stableKsortip(env, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    stack[-4] = v30;
    v31 = stack[-1];
    v30 = stack[-2];
    v30 = CC_stableKsortip(env, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    stack[-1] = v30;
    v30 = qvalue(elt(env, 1)); /* nil */
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    stack[0] = v30;
    stack[-3] = v30;
    goto v39;

v39:
    v30 = stack[-4];
    if (v30 == nil) goto v40;
    v30 = stack[-1];
    if (v30 == nil) goto v40;
    v32 = stack[-2];
    v30 = stack[-1];
    v31 = qcar(v30);
    v30 = stack[-4];
    v30 = qcar(v30);
    v30 = Lapply2(nil, 3, v32, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    if (v30 == nil) goto v41;
    v31 = stack[0];
    v30 = stack[-1];
    v30 = Lrplacd(nil, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    v30 = stack[-1];
    stack[0] = v30;
    v30 = stack[-1];
    v30 = qcdr(v30);
    stack[-1] = v30;
    goto v39;

v41:
    v31 = stack[0];
    v30 = stack[-4];
    v30 = Lrplacd(nil, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    v30 = stack[-4];
    stack[0] = v30;
    v30 = stack[-4];
    v30 = qcdr(v30);
    stack[-4] = v30;
    goto v39;

v40:
    v30 = stack[-4];
    if (v30 == nil) goto v42;
    v30 = stack[-4];
    stack[-1] = v30;
    goto v42;

v42:
    v31 = stack[0];
    v30 = stack[-1];
    v30 = Lrplacd(nil, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    v30 = stack[-3];
    v30 = qcdr(v30);
    { popv(6); return onevalue(v30); }

v33:
    v32 = stack[-2];
    v30 = stack[-1];
    v31 = qcar(v30);
    v30 = stack[-4];
    v30 = qcar(v30);
    v30 = Lapply2(nil, 3, v32, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    if (v30 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v30 = stack[-4];
    v30 = qcar(v30);
    stack[-3] = v30;
    v31 = stack[-4];
    v30 = stack[-1];
    v30 = qcar(v30);
    v30 = Lrplaca(nil, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-5];
    v31 = stack[-1];
    v30 = stack[-3];
    v30 = Lrplaca(nil, v31, v30);
    nil = C_nil;
    if (exception_pending()) goto v36;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v36:
    popv(6);
    return nil;
}



/* Code for symbol */

static Lisp_Object CC_symbol(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbol");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v0;
/* end of prologue */
    v46 = elt(env, 1); /* symbol!-character */
    return get(v45, v46);
}



/* Code for ident */

static Lisp_Object CC_ident(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v6;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ident");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    return onevalue(v6);
}



/* Code for wedget2 */

static Lisp_Object CC_wedget2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedget2");
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
    v62 = stack[-1];
    v63 = qcar(v62);
    v62 = (Lisp_Object)17; /* 1 */
    if (v63 == v62) goto v65;
    v62 = stack[0];
    v62 = qcar(v62);
    v63 = qcar(v62);
    v62 = (Lisp_Object)17; /* 1 */
    if (v63 == v62) goto v66;
    v62 = stack[-1];
    v64 = qcar(v62);
    v62 = stack[0];
    v63 = qcar(v62);
    v62 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* wedgek2 */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v64, v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v62 = stack[-1];
    v63 = qcdr(v62);
    v62 = stack[0];
    v62 = qcdr(v62);
    fn = elt(env, 3); /* multsq */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    {
        Lisp_Object v68 = stack[-2];
        popv(4);
        fn = elt(env, 4); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v68, v62);
    }

v66:
    v62 = stack[-1];
    v62 = qcar(v62);
    stack[-2] = ncons(v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v62 = stack[-1];
    v63 = qcdr(v62);
    v62 = stack[0];
    v62 = qcdr(v62);
    fn = elt(env, 3); /* multsq */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v62 = cons(stack[-2], v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    popv(4);
    return ncons(v62);

v65:
    v62 = stack[0];
    stack[-2] = qcar(v62);
    v62 = stack[-1];
    v63 = qcdr(v62);
    v62 = stack[0];
    v62 = qcdr(v62);
    fn = elt(env, 3); /* multsq */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v62 = cons(stack[-2], v62);
    nil = C_nil;
    if (exception_pending()) goto v67;
    popv(4);
    return ncons(v62);
/* error exit handlers */
v67:
    popv(4);
    return nil;
}



/* Code for contrsp */

static Lisp_Object CC_contrsp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp");
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
    v74 = stack[-1];
    v74 = qcdr(v74);
    v76 = qcar(v74);
    v74 = stack[-1];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v75 = qcar(v74);
    v74 = stack[0];
    fn = elt(env, 1); /* contrsp2 */
    v74 = (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    if (!(v74 == nil)) { popv(3); return onevalue(v74); }
    v74 = stack[-1];
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v76 = qcar(v74);
    v74 = stack[-1];
    v74 = qcdr(v74);
    v75 = qcar(v74);
    v74 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* contrsp2 */
        return (*qfnn(fn))(qenv(fn), 3, v76, v75, v74);
    }
/* error exit handlers */
v55:
    popv(3);
    return nil;
}



/* Code for mo_diff */

static Lisp_Object CC_mo_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_diff");
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
    v77 = v1;
    v60 = v0;
/* end of prologue */
    stack[0] = v60;
    fn = elt(env, 1); /* mo_neg */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-1];
    {
        Lisp_Object v73 = stack[0];
        popv(2);
        fn = elt(env, 2); /* mo_sum */
        return (*qfn2(fn))(qenv(fn), v73, v77);
    }
/* error exit handlers */
v78:
    popv(2);
    return nil;
}



/* Code for gcddd */

static Lisp_Object CC_gcddd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcddd");
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
    v90 = stack[-1];
    v89 = (Lisp_Object)17; /* 1 */
    if (v90 == v89) goto v5;
    v90 = stack[0];
    v89 = (Lisp_Object)17; /* 1 */
    if (v90 == v89) goto v5;
    v89 = stack[-1];
    if (!consp(v89)) goto v57;
    v89 = stack[0];
    if (!consp(v89)) goto v92;
    v89 = stack[-1];
    v90 = qcar(v89);
    v89 = elt(env, 2); /* field */
    v89 = Lflagp(nil, v90, v89);
    env = stack[-2];
    if (!(v89 == nil)) goto v20;
    v89 = stack[0];
    v90 = qcar(v89);
    v89 = elt(env, 2); /* field */
    v89 = Lflagp(nil, v90, v89);
    env = stack[-2];
    if (!(v89 == nil)) goto v20;
    v91 = stack[-1];
    v90 = stack[0];
    v89 = elt(env, 1); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v91, v90, v89);
    }

v20:
    v89 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v89); }

v92:
    v89 = stack[-1];
    v90 = qcar(v89);
    v89 = elt(env, 2); /* field */
    v89 = Lflagp(nil, v90, v89);
    env = stack[-2];
    if (v89 == nil) goto v93;
    v89 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v89); }

v93:
    v91 = stack[-1];
    v90 = stack[0];
    v89 = elt(env, 1); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v91, v90, v89);
    }

v57:
    v89 = stack[0];
    if (!consp(v89)) goto v59;
    v89 = stack[0];
    fn = elt(env, 4); /* fieldp */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    if (v89 == nil) goto v95;
    v89 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v89); }

v95:
    v91 = stack[-1];
    v90 = stack[0];
    v89 = elt(env, 1); /* gcd */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v91, v90, v89);
    }

v59:
    v90 = stack[-1];
    v89 = stack[0];
        popv(3);
        return Lgcd(nil, v90, v89);

v5:
    v89 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v89); }
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for general!-modular!-minus */

static Lisp_Object CC_generalKmodularKminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v96, v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-minus");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v97 = v0;
/* end of prologue */
    v96 = v97;
    v57 = (Lisp_Object)1; /* 0 */
    if (v96 == v57) return onevalue(v97);
    v57 = qvalue(elt(env, 1)); /* current!-modulus */
    v96 = v97;
    return difference2(v57, v96);
}



/* Code for mk!+mat!+mult!+mat */

static Lisp_Object CC_mkLmatLmultLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v179, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+mat+mult+mat");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-13] = v1;
    stack[-14] = v0;
/* end of prologue */
    v178 = stack[-14];
    fn = elt(env, 6); /* matrix!+p */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    if (!(v178 == nil)) goto v61;
    v178 = elt(env, 1); /* "no matrix in mult" */
    fn = elt(env, 7); /* rederr */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    goto v61;

v61:
    v178 = stack[-13];
    fn = elt(env, 6); /* matrix!+p */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    if (!(v178 == nil)) goto v88;
    v178 = elt(env, 1); /* "no matrix in mult" */
    fn = elt(env, 7); /* rederr */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    goto v88;

v88:
    v178 = stack[-14];
    fn = elt(env, 8); /* get!+col!+nr */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-15] = v178;
    v178 = stack[-14];
    fn = elt(env, 9); /* get!+row!+nr */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-12] = v178;
    v178 = stack[-13];
    fn = elt(env, 8); /* get!+col!+nr */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-11] = v178;
    stack[0] = stack[-15];
    v178 = stack[-13];
    fn = elt(env, 9); /* get!+row!+nr */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    if (equal(stack[0], v178)) goto v69;
    v178 = elt(env, 2); /* "matrices can not be multiplied" */
    fn = elt(env, 7); /* rederr */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    goto v69;

v69:
    v178 = (Lisp_Object)17; /* 1 */
    stack[-10] = v178;
    v179 = stack[-12];
    v178 = stack[-10];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v26;
    v178 = qvalue(elt(env, 3)); /* nil */
    { popv(17); return onevalue(v178); }

v26:
    v178 = (Lisp_Object)17; /* 1 */
    stack[-5] = v178;
    v179 = stack[-11];
    v178 = stack[-5];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v182;
    v178 = qvalue(elt(env, 3)); /* nil */
    goto v183;

v183:
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-8] = v178;
    stack[-9] = v178;
    goto v184;

v184:
    v178 = stack[-10];
    v178 = add1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-10] = v178;
    v179 = stack[-12];
    v178 = stack[-10];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (!(v178 == nil)) { Lisp_Object res = stack[-9]; popv(17); return onevalue(res); }
    stack[-7] = stack[-8];
    v178 = (Lisp_Object)17; /* 1 */
    stack[-6] = v178;
    v179 = stack[-11];
    v178 = stack[-6];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v185;
    v178 = qvalue(elt(env, 3)); /* nil */
    goto v186;

v186:
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lrplacd(nil, stack[-7], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = stack[-8];
    v178 = qcdr(v178);
    stack[-8] = v178;
    goto v184;

v185:
    v179 = qvalue(elt(env, 3)); /* nil */
    v178 = (Lisp_Object)17; /* 1 */
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[0] = v178;
    v178 = (Lisp_Object)17; /* 1 */
    stack[-1] = v178;
    goto v187;

v187:
    v179 = stack[-15];
    v178 = stack[-1];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v188;
    v178 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v178; /* !*sub2 */
    v178 = stack[0];
    fn = elt(env, 10); /* subs2 */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-16];
    stack[0] = v178;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    v178 = stack[0];
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-4] = v178;
    stack[-5] = v178;
    goto v190;

v190:
    v178 = stack[-6];
    v178 = add1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-6] = v178;
    v179 = stack[-11];
    v178 = stack[-6];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v191;
    v178 = stack[-5];
    goto v186;

v191:
    stack[-3] = stack[-4];
    v179 = qvalue(elt(env, 3)); /* nil */
    v178 = (Lisp_Object)17; /* 1 */
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[0] = v178;
    v178 = (Lisp_Object)17; /* 1 */
    stack[-2] = v178;
    goto v192;

v192:
    v179 = stack[-15];
    v178 = stack[-2];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v193;
    v178 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v178; /* !*sub2 */
    v178 = stack[0];
    fn = elt(env, 10); /* subs2 */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-16];
    stack[0] = v178;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    v178 = stack[0];
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lrplacd(nil, stack[-3], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = stack[-4];
    v178 = qcdr(v178);
    stack[-4] = v178;
    goto v190;

v193:
    stack[-1] = stack[0];
    v180 = stack[-14];
    v179 = stack[-10];
    v178 = stack[-2];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v180 = stack[-13];
    v179 = stack[-2];
    v178 = stack[-6];
    fn = elt(env, 11); /* get!+mat!+entry */
    v178 = (*qfnn(fn))(qenv(fn), 3, v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    fn = elt(env, 12); /* multsq */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    fn = elt(env, 13); /* addsq */
    v178 = (*qfn2(fn))(qenv(fn), stack[-1], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[0] = v178;
    v178 = stack[-2];
    v178 = add1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-2] = v178;
    goto v192;

v188:
    stack[-2] = stack[0];
    v180 = stack[-14];
    v179 = stack[-10];
    v178 = stack[-1];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v180 = stack[-13];
    v179 = stack[-1];
    v178 = stack[-6];
    fn = elt(env, 11); /* get!+mat!+entry */
    v178 = (*qfnn(fn))(qenv(fn), 3, v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    fn = elt(env, 12); /* multsq */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    fn = elt(env, 13); /* addsq */
    v178 = (*qfn2(fn))(qenv(fn), stack[-2], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[0] = v178;
    v178 = stack[-1];
    v178 = add1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-1] = v178;
    goto v187;

v182:
    v179 = qvalue(elt(env, 3)); /* nil */
    v178 = (Lisp_Object)17; /* 1 */
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[0] = v178;
    v178 = (Lisp_Object)17; /* 1 */
    stack[-1] = v178;
    goto v195;

v195:
    v179 = stack[-15];
    v178 = stack[-1];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v79;
    v178 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v178; /* !*sub2 */
    v178 = stack[0];
    fn = elt(env, 10); /* subs2 */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-16];
    stack[0] = v178;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    v178 = stack[0];
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-3] = v178;
    stack[-4] = v178;
    goto v197;

v197:
    v178 = stack[-5];
    v178 = add1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-5] = v178;
    v179 = stack[-11];
    v178 = stack[-5];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v198;
    v178 = stack[-4];
    goto v183;

v198:
    stack[-2] = stack[-3];
    v179 = qvalue(elt(env, 3)); /* nil */
    v178 = (Lisp_Object)17; /* 1 */
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[0] = v178;
    v178 = (Lisp_Object)17; /* 1 */
    stack[-1] = v178;
    goto v199;

v199:
    v179 = stack[-15];
    v178 = stack[-1];
    v178 = difference2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lminusp(nil, v178);
    env = stack[-16];
    if (v178 == nil) goto v200;
    v178 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v178; /* !*sub2 */
    v178 = stack[0];
    fn = elt(env, 10); /* subs2 */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-16];
    stack[0] = v178;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    v178 = stack[0];
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = Lrplacd(nil, stack[-2], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v178 = stack[-3];
    v178 = qcdr(v178);
    stack[-3] = v178;
    goto v197;

v200:
    stack[-6] = stack[0];
    v180 = stack[-14];
    v179 = stack[-10];
    v178 = stack[-1];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v180 = stack[-13];
    v179 = stack[-1];
    v178 = stack[-5];
    fn = elt(env, 11); /* get!+mat!+entry */
    v178 = (*qfnn(fn))(qenv(fn), 3, v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    fn = elt(env, 12); /* multsq */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    fn = elt(env, 13); /* addsq */
    v178 = (*qfn2(fn))(qenv(fn), stack[-6], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[0] = v178;
    v178 = stack[-1];
    v178 = add1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-1] = v178;
    goto v199;

v79:
    stack[-2] = stack[0];
    v180 = stack[-14];
    v179 = stack[-10];
    v178 = stack[-1];
    fn = elt(env, 11); /* get!+mat!+entry */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    v180 = stack[-13];
    v179 = stack[-1];
    v178 = stack[-5];
    fn = elt(env, 11); /* get!+mat!+entry */
    v178 = (*qfnn(fn))(qenv(fn), 3, v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    fn = elt(env, 12); /* multsq */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    fn = elt(env, 13); /* addsq */
    v178 = (*qfn2(fn))(qenv(fn), stack[-2], v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[0] = v178;
    v178 = stack[-1];
    v178 = add1(v178);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-16];
    stack[-1] = v178;
    goto v195;
/* error exit handlers */
v201:
    env = stack[-16];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v196:
    env = stack[-16];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v194:
    env = stack[-16];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v189:
    env = stack[-16];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(17);
    return nil;
v181:
    popv(17);
    return nil;
}



/* Code for tmsf!* */

static Lisp_Object CC_tmsfH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tmsf*");
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
    v56 = stack[0];
    if (!(is_number(v56))) goto v202;
    v56 = stack[0];
    v56 = Ltruncate(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    v57 = Labsval(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    v56 = (Lisp_Object)17; /* 1 */
    if (!(v57 == v56)) goto v202;
    v56 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v56); }

v202:
    v56 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* tmsf */
        return (*qfn1(fn))(qenv(fn), v56);
    }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for ibalp_varlat */

static Lisp_Object CC_ibalp_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlat");
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
    fn = elt(env, 1); /* ibalp_arg2l */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    stack[-1] = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    v61 = stack[0];
    fn = elt(env, 3); /* ibalp_arg2r */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    fn = elt(env, 2); /* ibalp_varlt */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    {
        Lisp_Object v203 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* union */
        return (*qfn2(fn))(qenv(fn), v203, v61);
    }
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for smtp */

static Lisp_Object CC_smtp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v222, v223, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smtp");
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
    stack[-6] = v1;
    stack[0] = v0;
/* end of prologue */
    v221 = stack[0];
    if (!consp(v221)) goto v71;
    v222 = stack[0];
    v221 = elt(env, 2); /* sparsemat */
    if (!consp(v222)) goto v141;
    v222 = qcar(v222);
    if (!(v222 == v221)) goto v141;
    v221 = stack[0];
    stack[-7] = v221;
    v221 = stack[-7];
    v221 = qcdr(v221);
    v221 = qcdr(v221);
    v221 = qcar(v221);
    v222 = v221;
    goto v78;

v78:
    v221 = v222;
    v221 = qcdr(v221);
    v221 = qcar(v221);
    stack[-4] = v221;
    v221 = v222;
    v221 = qcdr(v221);
    v221 = qcdr(v221);
    v221 = qcar(v221);
    stack[-1] = v221;
    v223 = elt(env, 3); /* spm */
    v222 = v221;
    v221 = stack[-4];
    v221 = list3(v223, v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    fn = elt(env, 8); /* mkempspmat */
    v221 = (*qfn2(fn))(qenv(fn), stack[-1], v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    stack[-5] = v221;
    v222 = stack[-7];
    v221 = elt(env, 2); /* sparsemat */
    if (!consp(v222)) goto v67;
    v222 = qcar(v222);
    if (!(v222 == v221)) goto v67;
    v221 = (Lisp_Object)17; /* 1 */
    stack[-1] = v221;
    goto v224;

v224:
    v222 = stack[-4];
    v221 = stack[-1];
    v221 = difference2(v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    v221 = Lminusp(nil, v221);
    env = stack[-8];
    if (!(v221 == nil)) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v222 = stack[-7];
    v221 = stack[-1];
    fn = elt(env, 9); /* findrow */
    v221 = (*qfn2(fn))(qenv(fn), v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    v222 = v221;
    v221 = v222;
    if (v221 == nil) goto v168;
    v221 = stack[-1];
    stack[-3] = v221;
    v221 = v222;
    v221 = qcdr(v221);
    stack[0] = v221;
    goto v225;

v225:
    v221 = stack[0];
    if (v221 == nil) goto v168;
    v221 = stack[0];
    v221 = qcar(v221);
    v222 = v221;
    v221 = v222;
    v221 = qcar(v221);
    v222 = qcdr(v222);
    stack[-2] = v222;
    v223 = stack[-5];
    v222 = v221;
    v221 = stack[-3];
    v160 = list3(v223, v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    v223 = stack[-2];
    v222 = stack[-5];
    v221 = stack[-6];
    fn = elt(env, 10); /* letmtr3 */
    v221 = (*qfnn(fn))(qenv(fn), 4, v160, v223, v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    v221 = stack[0];
    v221 = qcdr(v221);
    stack[0] = v221;
    goto v225;

v168:
    v221 = stack[-1];
    v221 = add1(v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    stack[-1] = v221;
    goto v224;

v67:
    stack[-2] = elt(env, 4); /* matrix */
    stack[-1] = (Lisp_Object)33; /* 2 */
    v223 = elt(env, 5); /* "Matrix" */
    v222 = stack[0];
    v221 = elt(env, 6); /* "not set" */
    v221 = list3(v223, v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    fn = elt(env, 11); /* rerror */
    v221 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }

v141:
    v221 = stack[0];
    v221 = qcdr(v221);
    v222 = qcar(v221);
    v221 = stack[-6];
    v221 = CC_smtp(env, v222, v221);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-8];
    stack[-7] = v221;
    v221 = stack[-7];
    v221 = qcdr(v221);
    v221 = qcdr(v221);
    v221 = qcar(v221);
    v222 = v221;
    goto v78;

v71:
    v222 = stack[0];
    v221 = elt(env, 1); /* avalue */
    v221 = get(v222, v221);
    env = stack[-8];
    v221 = qcdr(v221);
    v221 = qcar(v221);
    stack[-7] = v221;
    v221 = stack[-7];
    v221 = qcdr(v221);
    v221 = qcdr(v221);
    v221 = qcar(v221);
    v222 = v221;
    goto v78;
/* error exit handlers */
v148:
    popv(9);
    return nil;
}



/* Code for comm_kernels1 */

static Lisp_Object CC_comm_kernels1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm_kernels1");
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
    v24 = v0;
/* end of prologue */

v229:
    v92 = v24;
    if (!consp(v92)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v92 = v24;
    v92 = qcar(v92);
    if (!consp(v92)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v92 = v24;
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    stack[-3] = v92;
    v92 = v24;
    v92 = qcar(v92);
    stack[-1] = qcdr(v92);
    stack[0] = qcdr(v24);
    v92 = stack[-3];
    v24 = stack[-2];
    v24 = Lmemq(nil, v92, v24);
    if (!(v24 == nil)) goto v75;
    v24 = stack[-3];
    fn = elt(env, 1); /* noncomp */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    if (!(v24 == nil)) goto v75;
    v24 = stack[-3];
    v24 = ncons(v24);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v24 = Lappend(nil, stack[-2], v24);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    goto v59;

v59:
    v92 = CC_comm_kernels1(env, stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-4];
    v24 = stack[-1];
    stack[-2] = v92;
    goto v229;

v75:
    v24 = stack[-2];
    goto v59;
/* error exit handlers */
v156:
    popv(5);
    return nil;
}



/* Code for flatindxl */

static Lisp_Object CC_flatindxl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v85, v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatindxl");
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
    v22 = v0;
/* end of prologue */
    stack[-3] = v22;
    v22 = stack[-3];
    if (v22 == nil) goto v46;
    v22 = stack[-3];
    v22 = qcar(v22);
    v20 = v22;
    v22 = v20;
    if (!consp(v22)) goto v72;
    v85 = v20;
    v22 = elt(env, 2); /* minus */
    if (!consp(v85)) goto v74;
    v85 = qcar(v85);
    if (!(v85 == v22)) goto v74;
    v22 = v20;
    v22 = qcdr(v22);
    v22 = qcar(v22);
    goto v71;

v71:
    v22 = ncons(v22);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    stack[-1] = v22;
    stack[-2] = v22;
    goto v210;

v210:
    v22 = stack[-3];
    v22 = qcdr(v22);
    stack[-3] = v22;
    v22 = stack[-3];
    if (v22 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v22 = stack[-3];
    v22 = qcar(v22);
    v20 = v22;
    v22 = v20;
    if (!consp(v22)) goto v226;
    v85 = v20;
    v22 = elt(env, 2); /* minus */
    if (!consp(v85)) goto v234;
    v85 = qcar(v85);
    if (!(v85 == v22)) goto v234;
    v22 = v20;
    v22 = qcdr(v22);
    v22 = qcar(v22);
    goto v54;

v54:
    v22 = ncons(v22);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v22 = Lrplacd(nil, stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v22 = stack[-1];
    v22 = qcdr(v22);
    stack[-1] = v22;
    goto v210;

v234:
    v22 = v20;
    v22 = qcdr(v22);
    goto v54;

v226:
    v22 = v20;
    goto v54;

v74:
    v22 = v20;
    v22 = qcdr(v22);
    goto v71;

v72:
    v22 = v20;
    goto v71;

v46:
    v22 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v22); }
/* error exit handlers */
v48:
    popv(5);
    return nil;
}



/* Code for minus!: */

static Lisp_Object CC_minusT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v202;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minus:");
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
    stack[-1] = elt(env, 1); /* !:rd!: */
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcar(v203);
    v202 = negate(v203);
    nil = C_nil;
    if (exception_pending()) goto v88;
    v203 = stack[0];
    v203 = qcdr(v203);
    v203 = qcdr(v203);
    {
        Lisp_Object v56 = stack[-1];
        popv(2);
        return list2star(v56, v202, v203);
    }
/* error exit handlers */
v88:
    popv(2);
    return nil;
}



/* Code for greaterp!: */

static Lisp_Object CC_greaterpT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v243, v244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greaterp:");
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
    v244 = v0;
/* end of prologue */
    v242 = v244;
    v242 = qcdr(v242);
    v243 = qcdr(v242);
    v242 = stack[0];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    if (equal(v243, v242)) goto v202;
    v242 = v244;
    fn = elt(env, 2); /* csl_normbf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v242 = stack[0];
    fn = elt(env, 2); /* csl_normbf */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[0] = v242;
    v242 = stack[-1];
    v242 = qcdr(v242);
    v243 = qcdr(v242);
    v242 = stack[0];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    v244 = difference2(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v242 = stack[-1];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = stack[0];
    v242 = qcdr(v242);
    v242 = qcar(v242);
    stack[-4] = v244;
    stack[-3] = v243;
    stack[-2] = v242;
    v243 = stack[-4];
    v242 = (Lisp_Object)1; /* 0 */
    if (v243 == v242) goto v156;
    v243 = (Lisp_Object)33; /* 2 */
    v242 = qvalue(elt(env, 1)); /* !:bprec!: */
    v242 = times2(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    stack[-1] = v242;
    v243 = stack[-4];
    v242 = stack[-1];
    v242 = (Lisp_Object)greaterp2(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v242 = v242 ? lisp_true : nil;
    env = stack[-5];
    if (v242 == nil) goto v195;
    v243 = stack[-3];
    v242 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v243, v242);

v195:
    stack[0] = stack[-4];
    v242 = stack[-1];
    v242 = negate(v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v242 = (Lisp_Object)lessp2(stack[0], v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v242 = v242 ? lisp_true : nil;
    env = stack[-5];
    if (v242 == nil) goto v245;
    v243 = stack[-2];
    v242 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Llessp(nil, v243, v242);

v245:
    v243 = stack[-4];
    v242 = (Lisp_Object)1; /* 0 */
    v242 = (Lisp_Object)greaterp2(v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v242 = v242 ? lisp_true : nil;
    env = stack[-5];
    if (v242 == nil) goto v246;
    v243 = stack[-3];
    v242 = stack[-4];
    v243 = Lash1(nil, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    v242 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v243, v242);

v246:
    stack[0] = stack[-3];
    stack[-1] = stack[-2];
    v242 = stack[-4];
    v242 = negate(v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-5];
    v242 = Lash1(nil, stack[-1], v242);
    nil = C_nil;
    if (exception_pending()) goto v198;
    {
        Lisp_Object v12 = stack[0];
        popv(6);
        return Lgreaterp(nil, v12, v242);
    }

v156:
    v243 = stack[-3];
    v242 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v243, v242);

v202:
    v242 = v244;
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = stack[0];
    v242 = qcdr(v242);
    v242 = qcar(v242);
        popv(6);
        return Lgreaterp(nil, v243, v242);
/* error exit handlers */
v198:
    popv(6);
    return nil;
}



/* Code for leftzeros */

static Lisp_Object CC_leftzeros(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v248, v184;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for leftzeros");
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
    v184 = nil;
    goto v209;

v209:
    v53 = stack[0];
    if (v53 == nil) goto v210;
    v53 = stack[0];
    v248 = qcar(v53);
    v53 = (Lisp_Object)1; /* 0 */
    if (!(v248 == v53)) goto v210;
    v53 = (Lisp_Object)17; /* 1 */
    v248 = v184;
    v53 = cons(v53, v248);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    v184 = v53;
    v53 = stack[0];
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v209;

v210:
    v53 = (Lisp_Object)1; /* 0 */
    goto v44;

v44:
    v248 = v184;
    if (v248 == nil) { popv(2); return onevalue(v53); }
    v248 = v184;
    v248 = qcar(v248);
    v53 = (Lisp_Object)(int32_t)((int32_t)v248 + (int32_t)v53 - TAG_FIXNUM);
    v248 = v184;
    v248 = qcdr(v248);
    v184 = v248;
    goto v44;
/* error exit handlers */
v87:
    popv(2);
    return nil;
}



/* Code for th_match0 */

static Lisp_Object CC_th_match0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v233, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for th_match0");
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
    v33 = v0;
/* end of prologue */
    v59 = v33;
    v233 = qcar(v59);
    v59 = stack[0];
    v59 = qcar(v59);
    if (equal(v233, v59)) goto v202;
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v59); }

v202:
    v59 = v33;
    v59 = qcdr(v59);
    v59 = qcar(v59);
    stack[-1] = Llength(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcar(v59);
    v59 = Llength(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v59 = (equal(stack[-1], v59) ? lisp_true : nil);
    { popv(3); return onevalue(v59); }
/* error exit handlers */
v74:
    popv(3);
    return nil;
}



/* Code for c!:extadd */

static Lisp_Object CC_cTextadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v224, v240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:extadd");
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
    stack[0] = nil;
    goto v209;

v209:
    v250 = stack[-2];
    if (v250 == nil) goto v60;
    v250 = stack[-1];
    if (v250 == nil) goto v57;
    v250 = stack[-2];
    v250 = qcar(v250);
    v224 = qcar(v250);
    v250 = stack[-1];
    v250 = qcar(v250);
    v250 = qcar(v250);
    if (equal(v224, v250)) goto v177;
    v250 = stack[-2];
    v250 = qcar(v250);
    v224 = qcar(v250);
    v250 = stack[-1];
    v250 = qcar(v250);
    v250 = qcar(v250);
    fn = elt(env, 1); /* c!:ordexp */
    v250 = (*qfn2(fn))(qenv(fn), v224, v250);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    if (v250 == nil) goto v89;
    v250 = stack[-2];
    v224 = qcar(v250);
    v250 = stack[0];
    v250 = cons(v224, v250);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    stack[0] = v250;
    v250 = stack[-2];
    v250 = qcdr(v250);
    stack[-2] = v250;
    goto v209;

v89:
    v250 = stack[-1];
    v224 = qcar(v250);
    v250 = stack[0];
    v250 = cons(v224, v250);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    stack[0] = v250;
    v250 = stack[-1];
    v250 = qcdr(v250);
    stack[-1] = v250;
    goto v209;

v177:
    stack[-3] = stack[0];
    v250 = stack[-2];
    v250 = qcar(v250);
    v224 = qcdr(v250);
    v250 = stack[-1];
    v250 = qcar(v250);
    v250 = qcdr(v250);
    fn = elt(env, 2); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), v224, v250);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v250 = stack[-2];
    v224 = qcdr(v250);
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = CC_cTextadd(env, v224, v250);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v224 = stack[0];
    v240 = v224;
    if (v240 == nil) goto v95;
    v240 = stack[-2];
    v240 = qcar(v240);
    v240 = qcar(v240);
    v250 = acons(v240, v224, v250);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    goto v95;

v95:
    {
        Lisp_Object v169 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v169, v250);
    }

v57:
    v224 = stack[0];
    v250 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v224, v250);
    }

v60:
    v224 = stack[0];
    v250 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v224, v250);
    }
/* error exit handlers */
v17:
    popv(5);
    return nil;
}



/* Code for cl_cflip */

static Lisp_Object CC_cl_cflip(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_cflip");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v1;
    v61 = v0;
/* end of prologue */
    if (!(v60 == nil)) return onevalue(v61);
    v60 = v61;
    {
        fn = elt(env, 1); /* cl_flip */
        return (*qfn1(fn))(qenv(fn), v60);
    }
}



/* Code for totalcompare */

static Lisp_Object CC_totalcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v174, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totalcompare");
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

v210:
    v174 = stack[-1];
    v20 = stack[0];
    if (equal(v174, v20)) goto v5;
    v174 = stack[-1];
    v20 = stack[0];
    fn = elt(env, 4); /* wulessp */
    v20 = (*qfn2(fn))(qenv(fn), v174, v20);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    if (v20 == nil) goto v227;
    v20 = elt(env, 2); /* less */
    { popv(3); return onevalue(v20); }

v227:
    v174 = stack[0];
    v20 = stack[-1];
    fn = elt(env, 4); /* wulessp */
    v20 = (*qfn2(fn))(qenv(fn), v174, v20);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    if (v20 == nil) goto v251;
    v20 = elt(env, 3); /* greater */
    { popv(3); return onevalue(v20); }

v251:
    v20 = stack[-1];
    fn = elt(env, 5); /* wuconstantp */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    if (v20 == nil) goto v25;
    v174 = stack[-1];
    v20 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* totalcompareconstants */
        return (*qfn2(fn))(qenv(fn), v174, v20);
    }

v25:
    v20 = stack[-1];
    v20 = qcar(v20);
    v174 = qcdr(v20);
    v20 = stack[0];
    v20 = qcar(v20);
    v20 = qcdr(v20);
    v20 = CC_totalcompare(env, v174, v20);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-2];
    v21 = v20;
    v174 = v21;
    v20 = elt(env, 1); /* equal */
    if (!(v174 == v20)) { popv(3); return onevalue(v21); }
    v20 = stack[-1];
    v174 = qcdr(v20);
    v20 = stack[0];
    v20 = qcdr(v20);
    stack[-1] = v174;
    stack[0] = v20;
    goto v210;

v5:
    v20 = elt(env, 1); /* equal */
    { popv(3); return onevalue(v20); }
/* error exit handlers */
v48:
    popv(3);
    return nil;
}



/* Code for setdiff */

static Lisp_Object CC_setdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v247;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdiff");
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
    v227 = v0;
/* end of prologue */

v5:
    v247 = stack[0];
    if (v247 == nil) { popv(2); return onevalue(v227); }
    v247 = v227;
    if (v247 == nil) goto v77;
    v247 = stack[0];
    v247 = qcar(v247);
    v227 = Ldelete(nil, v247, v227);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-1];
    v247 = stack[0];
    v247 = qcdr(v247);
    stack[0] = v247;
    goto v5;

v77:
    v227 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v227); }
/* error exit handlers */
v252:
    popv(2);
    return nil;
}



/* Code for get_rep_matrix_in */

static Lisp_Object CC_get_rep_matrix_in(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_matrix_in");
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
    v23 = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = nil;
    v226 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v226;
    v226 = v23;
    v226 = qcdr(v226);
    stack[0] = v226;
    goto v60;

v60:
    v226 = stack[-3];
    if (!(v226 == nil)) goto v77;
    v226 = stack[0];
    v23 = Llength(nil, v226);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-4];
    v226 = (Lisp_Object)1; /* 0 */
    v226 = (Lisp_Object)greaterp2(v23, v226);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v226 = v226 ? lisp_true : nil;
    env = stack[-4];
    if (v226 == nil) goto v77;
    v226 = stack[0];
    v226 = qcar(v226);
    v23 = qcar(v226);
    v226 = stack[-2];
    if (!(equal(v23, v226))) goto v252;
    v226 = stack[0];
    v226 = qcar(v226);
    v226 = qcdr(v226);
    v226 = qcar(v226);
    stack[-1] = v226;
    v226 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v226;
    goto v252;

v252:
    v226 = stack[0];
    v226 = qcdr(v226);
    stack[0] = v226;
    goto v60;

v77:
    v226 = stack[-3];
    if (!(v226 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v226 = elt(env, 3); /* "error in get representation matrix" */
    fn = elt(env, 4); /* rederr */
    v226 = (*qfn1(fn))(qenv(fn), v226);
    nil = C_nil;
    if (exception_pending()) goto v35;
    v226 = nil;
    { popv(5); return onevalue(v226); }
/* error exit handlers */
v35:
    popv(5);
    return nil;
}



/* Code for unplus */

static Lisp_Object CC_unplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v253, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unplus");
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
    v234 = nil;
    goto v5;

v5:
    v93 = stack[-1];
    if (!consp(v93)) goto v77;
    v93 = stack[-1];
    v253 = qcar(v93);
    v93 = elt(env, 1); /* plus */
    if (v253 == v93) goto v202;
    v93 = stack[-1];
    v93 = qcar(v93);
    if (!consp(v93)) goto v66;
    v93 = stack[-1];
    v253 = qcar(v93);
    v93 = elt(env, 1); /* plus */
    if (!consp(v253)) goto v66;
    v253 = qcar(v253);
    if (!(v253 == v93)) goto v66;
    stack[-2] = v234;
    v93 = stack[-1];
    v93 = qcar(v93);
    stack[0] = qcdr(v93);
    v93 = stack[-1];
    v93 = qcdr(v93);
    v93 = CC_unplus(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v93 = Lappend(nil, stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    {
        Lisp_Object v51 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v51, v93);
    }

v66:
    v93 = stack[-1];
    v93 = qcar(v93);
    v253 = v234;
    v93 = cons(v93, v253);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v234 = v93;
    v93 = stack[-1];
    v93 = qcdr(v93);
    stack[-1] = v93;
    goto v5;

v202:
    v93 = stack[-1];
    v93 = qcdr(v93);
    stack[-1] = v93;
    goto v5;

v77:
    v253 = v234;
    v93 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v253, v93);
    }
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for formlis */

static Lisp_Object MS_CDECL CC_formlis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v232, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formlis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formlis");
#endif
    if (stack >= stacklimit)
    {
        push3(v232,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v232);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v232;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v210;

v210:
    v69 = stack[-2];
    if (v69 == nil) goto v45;
    v69 = stack[-2];
    v74 = qcar(v69);
    v70 = stack[-1];
    v69 = stack[0];
    fn = elt(env, 1); /* form1 */
    v70 = (*qfnn(fn))(qenv(fn), 3, v74, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    v69 = stack[-3];
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[-3] = v69;
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v210;

v45:
    v69 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* reversip!* */
        return (*qfn1(fn))(qenv(fn), v69);
    }
/* error exit handlers */
v55:
    popv(5);
    return nil;
}



/* Code for omair */

static Lisp_Object MS_CDECL CC_omair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v252, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omair");
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
    stack[0] = nil;
    fn = elt(env, 4); /* lex */
    v252 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    fn = elt(env, 5); /* omobj */
    v252 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    stack[-1] = v252;
    v252 = stack[-1];
    v59 = qcar(v252);
    v252 = elt(env, 1); /* matrix */
    if (v59 == v252) goto v96;
    fn = elt(env, 4); /* lex */
    v252 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    fn = elt(env, 6); /* omobjs */
    v252 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    stack[0] = v252;
    v252 = elt(env, 2); /* (!/ o m a) */
    fn = elt(env, 7); /* checktag */
    v252 = (*qfn1(fn))(qenv(fn), v252);
    nil = C_nil;
    if (exception_pending()) goto v69;
    goto v96;

v96:
    v59 = stack[-1];
    v252 = stack[0];
        popv(3);
        return Lappend(nil, v59, v252);
/* error exit handlers */
v69:
    popv(3);
    return nil;
}



/* Code for scalopp */

static Lisp_Object CC_scalopp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v223, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scalopp");
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
    v222 = stack[-3];
    if (symbolp(v222)) goto v202;
    v222 = qvalue(elt(env, 1)); /* nil */
    goto v209;

v209:
    if (!(v222 == nil)) { popv(6); return onevalue(v222); }
    v222 = stack[-3];
    if (!consp(v222)) goto v247;
    v222 = stack[-3];
    v223 = qcar(v222);
    v222 = elt(env, 2); /* phystype */
    v223 = get(v223, v222);
    env = stack[-5];
    v222 = elt(env, 3); /* scalar */
    v222 = (v223 == v222 ? lisp_true : nil);
    if (!(v222 == nil)) { popv(6); return onevalue(v222); }
    v222 = stack[-3];
    v223 = qcar(v222);
    v222 = elt(env, 2); /* phystype */
    v223 = get(v223, v222);
    env = stack[-5];
    v222 = elt(env, 4); /* vector */
    if (v223 == v222) goto v197;
    v222 = qvalue(elt(env, 1)); /* nil */
    goto v26;

v26:
    if (!(v222 == nil)) { popv(6); return onevalue(v222); }
    v222 = stack[-3];
    v223 = qcar(v222);
    v222 = elt(env, 2); /* phystype */
    v223 = get(v223, v222);
    env = stack[-5];
    v222 = elt(env, 5); /* tensor */
    if (v223 == v222) goto v260;
    v222 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v222); }

v260:
    v222 = stack[-3];
    v222 = qcdr(v222);
    v160 = Llength(nil, v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    v222 = stack[-3];
    v223 = qcar(v222);
    v222 = elt(env, 6); /* tensdimen */
    v222 = get(v223, v222);
    env = stack[-5];
    v222 = (Lisp_Object)geq2(v160, v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    v222 = v222 ? lisp_true : nil;
    env = stack[-5];
    if (v222 == nil) goto v67;
    v222 = (Lisp_Object)17; /* 1 */
    stack[-4] = v222;
    v222 = stack[-3];
    v223 = qcar(v222);
    v222 = elt(env, 6); /* tensdimen */
    v223 = get(v223, v222);
    env = stack[-5];
    v222 = stack[-4];
    v222 = difference2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    v222 = Lminusp(nil, v222);
    env = stack[-5];
    if (v222 == nil) goto v211;
    v222 = qvalue(elt(env, 1)); /* nil */
    goto v249;

v249:
    {
        popv(6);
        fn = elt(env, 7); /* areallindices */
        return (*qfn1(fn))(qenv(fn), v222);
    }

v211:
    v222 = stack[-3];
    v223 = qcdr(v222);
    v222 = stack[-4];
    fn = elt(env, 8); /* nth */
    v222 = (*qfn2(fn))(qenv(fn), v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    v222 = ncons(v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    stack[-1] = v222;
    stack[-2] = v222;
    goto v245;

v245:
    v222 = stack[-4];
    v222 = add1(v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    stack[-4] = v222;
    v222 = stack[-3];
    v223 = qcar(v222);
    v222 = elt(env, 6); /* tensdimen */
    v223 = get(v223, v222);
    env = stack[-5];
    v222 = stack[-4];
    v222 = difference2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    v222 = Lminusp(nil, v222);
    env = stack[-5];
    if (v222 == nil) goto v262;
    v222 = stack[-2];
    goto v249;

v262:
    stack[0] = stack[-1];
    v222 = stack[-3];
    v223 = qcdr(v222);
    v222 = stack[-4];
    fn = elt(env, 8); /* nth */
    v222 = (*qfn2(fn))(qenv(fn), v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    v222 = ncons(v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    v222 = Lrplacd(nil, stack[0], v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    v222 = stack[-1];
    v222 = qcdr(v222);
    stack[-1] = v222;
    goto v245;

v67:
    v222 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v222); }

v197:
    v222 = stack[-3];
    v222 = qcdr(v222);
    v222 = qcar(v222);
    fn = elt(env, 9); /* isanindex */
    v222 = (*qfn1(fn))(qenv(fn), v222);
    nil = C_nil;
    if (exception_pending()) goto v261;
    env = stack[-5];
    goto v26;

v247:
    v222 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v222); }

v202:
    v223 = stack[-3];
    v222 = elt(env, 2); /* phystype */
    v223 = get(v223, v222);
    env = stack[-5];
    v222 = elt(env, 3); /* scalar */
    v222 = (v223 == v222 ? lisp_true : nil);
    goto v209;
/* error exit handlers */
v261:
    popv(6);
    return nil;
}



/* Code for getel */

static Lisp_Object CC_getel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v54, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getel");
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
    v230 = stack[-1];
    v54 = qcar(v230);
    v230 = elt(env, 1); /* dimension */
    v230 = get(v54, v230);
    env = stack[-3];
    stack[-2] = v230;
    v230 = stack[-2];
    stack[0] = Llength(nil, v230);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v230 = stack[-1];
    v230 = qcdr(v230);
    v230 = Llength(nil, v230);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    if (equal(stack[0], v230)) goto v95;
    v226 = elt(env, 2); /* rlisp */
    v54 = (Lisp_Object)337; /* 21 */
    v230 = elt(env, 3); /* "Incorrect array reference" */
    {
        popv(4);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v226, v54, v230);
    }

v95:
    v230 = stack[-1];
    v54 = qcar(v230);
    v230 = elt(env, 4); /* avalue */
    v230 = get(v54, v230);
    env = stack[-3];
    v230 = qcdr(v230);
    v226 = qcar(v230);
    v230 = stack[-1];
    v54 = qcdr(v230);
    v230 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* getel1 */
        return (*qfnn(fn))(qenv(fn), 3, v226, v54, v230);
    }
/* error exit handlers */
v175:
    popv(4);
    return nil;
}



/* Code for b!:extmult */

static Lisp_Object CC_bTextmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:extmult");
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
    v16 = stack[-3];
    if (v16 == nil) goto v5;
    v16 = stack[-2];
    if (v16 == nil) goto v5;
    v17 = stack[-2];
    v16 = (Lisp_Object)17; /* 1 */
    if (v17 == v16) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v16 = stack[-3];
    v16 = qcar(v16);
    v16 = qcar(v16);
    v17 = qcar(v16);
    v16 = stack[-2];
    v16 = qcar(v16);
    v16 = qcar(v16);
    fn = elt(env, 2); /* b!:ordexn */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    v17 = v16;
    v16 = v17;
    if (v16 == nil) goto v79;
    v16 = v17;
    stack[-4] = qcdr(v16);
    v16 = v17;
    v16 = qcar(v16);
    if (v16 == nil) goto v183;
    v16 = stack[-3];
    v16 = qcar(v16);
    v17 = qcdr(v16);
    v16 = stack[-2];
    v16 = qcar(v16);
    v16 = qcdr(v16);
    fn = elt(env, 3); /* multf */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    fn = elt(env, 4); /* negf */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    stack[-1] = v16;
    goto v48;

v48:
    v16 = stack[-3];
    v16 = qcar(v16);
    v17 = ncons(v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    v16 = stack[-2];
    v16 = qcdr(v16);
    stack[0] = CC_bTextmult(env, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    v16 = stack[-3];
    v17 = qcdr(v16);
    v16 = stack[-2];
    v16 = CC_bTextmult(env, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    fn = elt(env, 5); /* b!:extadd */
    v16 = (*qfn2(fn))(qenv(fn), stack[0], v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    {
        Lisp_Object v14 = stack[-4];
        Lisp_Object v15 = stack[-1];
        popv(6);
        return acons(v14, v15, v16);
    }

v183:
    v16 = stack[-3];
    v16 = qcar(v16);
    v17 = qcdr(v16);
    v16 = stack[-2];
    v16 = qcar(v16);
    v16 = qcdr(v16);
    fn = elt(env, 3); /* multf */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    stack[-1] = v16;
    goto v48;

v79:
    v16 = stack[-3];
    v17 = qcdr(v16);
    v16 = stack[-2];
    stack[0] = CC_bTextmult(env, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    v16 = stack[-3];
    v16 = qcar(v16);
    v17 = ncons(v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    v16 = stack[-2];
    v16 = qcdr(v16);
    v16 = CC_bTextmult(env, v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v265;
    env = stack[-5];
    {
        Lisp_Object v212 = stack[0];
        popv(6);
        fn = elt(env, 5); /* b!:extadd */
        return (*qfn2(fn))(qenv(fn), v212, v16);
    }

v5:
    v16 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v16); }
/* error exit handlers */
v265:
    popv(6);
    return nil;
}



/* Code for horner!-rule */

static Lisp_Object MS_CDECL CC_hornerKrule(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v232, Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v270, v271, v254;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "horner-rule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule");
#endif
    if (stack >= stacklimit)
    {
        push4(v6,v232,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v232,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    stack[-2] = v232;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v229:
    v8 = stack[-2];
    if (!consp(v8)) goto v210;
    v8 = stack[-2];
    v8 = qcar(v8);
    if (!consp(v8)) goto v210;
    v8 = stack[-2];
    v8 = qcar(v8);
    v8 = qcar(v8);
    v270 = qcar(v8);
    v8 = stack[-1];
    v8 = qcar(v8);
    v8 = qcar(v8);
    if (equal(v270, v8)) goto v272;
    v8 = stack[-1];
    v8 = qcar(v8);
    v8 = qcdr(v8);
    v8 = (Lisp_Object)zerop(v8);
    v8 = v8 ? lisp_true : nil;
    env = stack[-6];
    if (v8 == nil) goto v259;
    v270 = stack[-2];
    v8 = stack[-1];
    v8 = qcdr(v8);
    {
        popv(7);
        fn = elt(env, 1); /* evaluate!-in!-order */
        return (*qfn2(fn))(qenv(fn), v270, v8);
    }

v259:
    v270 = stack[-2];
    v8 = stack[-1];
    v8 = qcdr(v8);
    fn = elt(env, 1); /* evaluate!-in!-order */
    stack[0] = (*qfn2(fn))(qenv(fn), v270, v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    stack[-2] = stack[-4];
    v8 = stack[-1];
    v8 = qcar(v8);
    v270 = qcdr(v8);
    v8 = stack[-3];
    v8 = Lexpt(nil, v270, v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v8 = times2(stack[-2], v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    {
        Lisp_Object v42 = stack[0];
        popv(7);
        return plus2(v42, v8);
    }

v272:
    v8 = stack[-2];
    v8 = qcar(v8);
    v8 = qcar(v8);
    v8 = qcdr(v8);
    stack[-5] = v8;
    v8 = stack[-1];
    v8 = qcar(v8);
    v8 = qcdr(v8);
    v8 = (Lisp_Object)zerop(v8);
    v8 = v8 ? lisp_true : nil;
    env = stack[-6];
    if (v8 == nil) goto v256;
    v8 = stack[-2];
    v8 = qcar(v8);
    v270 = qcdr(v8);
    v8 = stack[-1];
    v8 = qcdr(v8);
    fn = elt(env, 1); /* evaluate!-in!-order */
    v8 = (*qfn2(fn))(qenv(fn), v270, v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v254 = v8;
    goto v255;

v255:
    v271 = stack[-5];
    v8 = stack[-2];
    v270 = qcdr(v8);
    v8 = stack[-1];
    stack[-4] = v254;
    stack[-3] = v271;
    stack[-2] = v270;
    stack[-1] = v8;
    goto v229;

v256:
    v8 = stack[-2];
    v8 = qcar(v8);
    v270 = qcdr(v8);
    v8 = stack[-1];
    v8 = qcdr(v8);
    fn = elt(env, 1); /* evaluate!-in!-order */
    stack[0] = (*qfn2(fn))(qenv(fn), v270, v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v8 = stack[-1];
    v8 = qcar(v8);
    v271 = qcdr(v8);
    v270 = stack[-3];
    v8 = stack[-5];
    v8 = (Lisp_Object)(int32_t)((int32_t)v270 - (int32_t)v8 + TAG_FIXNUM);
    v8 = Lexpt(nil, v271, v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v8 = times2(stack[-4], v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v8 = plus2(stack[0], v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v254 = v8;
    goto v255;

v210:
    v8 = stack[-1];
    v8 = qcar(v8);
    v8 = qcdr(v8);
    v8 = (Lisp_Object)zerop(v8);
    v8 = v8 ? lisp_true : nil;
    env = stack[-6];
    if (v8 == nil) goto v251;
    v8 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* !*d2n */
        return (*qfn1(fn))(qenv(fn), v8);
    }

v251:
    v8 = stack[-2];
    fn = elt(env, 2); /* !*d2n */
    stack[0] = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    stack[-2] = stack[-4];
    v8 = stack[-1];
    v8 = qcar(v8);
    v270 = qcdr(v8);
    v8 = stack[-3];
    v8 = Lexpt(nil, v270, v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-6];
    v8 = times2(stack[-2], v8);
    nil = C_nil;
    if (exception_pending()) goto v161;
    {
        Lisp_Object v273 = stack[0];
        popv(7);
        return plus2(v273, v8);
    }
/* error exit handlers */
v161:
    popv(7);
    return nil;
}



/* Code for cl_varl1 */

static Lisp_Object CC_cl_varl1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v65, v203, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_varl1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    v202 = v73;
    v203 = qvalue(elt(env, 1)); /* nil */
    v65 = qvalue(elt(env, 1)); /* nil */
    v73 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_varl2 */
        return (*qfnn(fn))(qenv(fn), 4, v202, v203, v65, v73);
    }
}



/* Code for ibalp_csat */

static Lisp_Object CC_ibalp_csat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v96;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_csat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */

v229:
    v96 = v57;
    v96 = (v96 == nil ? lisp_true : nil);
    if (!(v96 == nil)) return onevalue(v96);
    v96 = v57;
    v96 = qcar(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v96 = qcar(v96);
    if (v96 == nil) goto v43;
    v57 = qcdr(v57);
    goto v229;

v43:
    v57 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v57);
}



/* Code for off_mod_reval */

static Lisp_Object CC_off_mod_reval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for off_mod_reval");
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
    v56 = qvalue(elt(env, 1)); /* !*modular */
    if (v56 == nil) goto v203;
    v56 = elt(env, 2); /* modular */
    v56 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    fn = elt(env, 4); /* off */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v56 = stack[0];
    fn = elt(env, 5); /* reval */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    stack[0] = v56;
    v56 = elt(env, 2); /* modular */
    v56 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    fn = elt(env, 6); /* on */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v96;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v203:
    v56 = stack[0];
    fn = elt(env, 5); /* reval */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v96;
    stack[0] = v56;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for xord_lex */

static Lisp_Object CC_xord_lex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v226, v23, v24, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_lex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v23 = v1;
    v24 = v0;
/* end of prologue */

v5:
    v226 = v24;
    if (v226 == nil) goto v44;
    v226 = v24;
    v92 = qcar(v226);
    v226 = (Lisp_Object)17; /* 1 */
    if (v92 == v226) goto v44;
    v226 = v23;
    if (v226 == nil) goto v88;
    v226 = v23;
    v92 = qcar(v226);
    v226 = (Lisp_Object)17; /* 1 */
    if (v92 == v226) goto v88;
    v226 = v24;
    v92 = qcar(v226);
    v226 = v23;
    v226 = qcar(v226);
    if (v92 == v226) goto v69;
    v226 = v24;
    v226 = qcar(v226);
    v23 = qcar(v23);
    {
        fn = elt(env, 3); /* factorordp */
        return (*qfn2(fn))(qenv(fn), v226, v23);
    }

v69:
    v226 = v24;
    v226 = qcdr(v226);
    v24 = v226;
    v226 = v23;
    v226 = qcdr(v226);
    v23 = v226;
    goto v5;

v88:
    v226 = qvalue(elt(env, 2)); /* t */
    return onevalue(v226);

v44:
    v226 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v226);
}



/* Code for plus!: */

static Lisp_Object CC_plusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v275, v263, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plus:");
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
    v263 = v1;
    v16 = v0;
/* end of prologue */
    v241 = v16;
    v241 = qcdr(v241);
    v275 = qcar(v241);
    stack[-1] = v275;
    v241 = (Lisp_Object)1; /* 0 */
    if (v275 == v241) { popv(6); return onevalue(v263); }
    v241 = v263;
    v241 = qcdr(v241);
    v275 = qcar(v241);
    stack[0] = v275;
    v241 = (Lisp_Object)1; /* 0 */
    if (v275 == v241) { popv(6); return onevalue(v16); }
    v241 = v16;
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    stack[-4] = v241;
    v275 = v263;
    v275 = qcdr(v275);
    v275 = qcdr(v275);
    stack[-2] = v275;
    v275 = difference2(v241, v275);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-5];
    stack[-3] = v275;
    v241 = (Lisp_Object)1; /* 0 */
    if (v275 == v241) goto v26;
    v275 = stack[-3];
    v241 = (Lisp_Object)1; /* 0 */
    v241 = (Lisp_Object)greaterp2(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v276;
    v241 = v241 ? lisp_true : nil;
    env = stack[-5];
    if (v241 == nil) goto v195;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v275 = stack[-1];
    v241 = stack[-3];
    v275 = Lash1(nil, v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-5];
    v241 = stack[0];
    v275 = plus2(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v276;
    v241 = stack[-2];
    {
        Lisp_Object v265 = stack[-4];
        popv(6);
        return list2star(v265, v275, v241);
    }

v195:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v241 = stack[-3];
    v241 = negate(v241);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-5];
    v241 = Lash1(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-5];
    v275 = plus2(stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v276;
    v241 = stack[-4];
    {
        Lisp_Object v14 = stack[-2];
        popv(6);
        return list2star(v14, v275, v241);
    }

v26:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v275 = stack[-1];
    v241 = stack[0];
    v275 = plus2(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v276;
    v241 = stack[-4];
    {
        Lisp_Object v15 = stack[-2];
        popv(6);
        return list2star(v15, v275, v241);
    }
/* error exit handlers */
v276:
    popv(6);
    return nil;
}



/* Code for errorset2 */

static Lisp_Object CC_errorset2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v203, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for errorset2");
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
    v203 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*protfg */
    qvalue(elt(env, 1)) = nil; /* !*protfg */
    v65 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v65; /* !*protfg */
    v202 = v203;
    v203 = qvalue(elt(env, 3)); /* nil */
    v65 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 4); /* errorset */
    v65 = (*qfnn(fn))(qenv(fn), 3, v202, v203, v65);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    { popv(2); return onevalue(v65); }
/* error exit handlers */
v72:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*protfg */
    popv(2);
    return nil;
}



/* Code for formop */

static Lisp_Object CC_formop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formop");
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
    goto v209;

v209:
    v218 = stack[-1];
    if (!consp(v218)) goto v210;
    v218 = stack[-1];
    v218 = qcar(v218);
    if (!consp(v218)) goto v210;
    v218 = stack[-1];
    v218 = qcar(v218);
    stack[0] = qcar(v218);
    v218 = stack[-1];
    v218 = qcar(v218);
    v218 = qcdr(v218);
    v218 = CC_formop(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-3];
    fn = elt(env, 1); /* multop */
    v219 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-3];
    v218 = stack[-2];
    v218 = cons(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-3];
    stack[-2] = v218;
    v218 = stack[-1];
    v218 = qcdr(v218);
    stack[-1] = v218;
    goto v209;

v210:
    v218 = stack[-1];
    v219 = v218;
    goto v44;

v44:
    v218 = stack[-2];
    if (v218 == nil) { popv(4); return onevalue(v219); }
    v218 = stack[-2];
    v218 = qcar(v218);
    fn = elt(env, 2); /* raddf */
    v218 = (*qfn2(fn))(qenv(fn), v218, v219);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-3];
    v219 = v218;
    v218 = stack[-2];
    v218 = qcdr(v218);
    stack[-2] = v218;
    goto v44;
/* error exit handlers */
v226:
    popv(4);
    return nil;
}



/* Code for conv!:mt */

static Lisp_Object CC_convTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v275;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conv:mt");
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
    stack[0] = v1;
    stack[-2] = v0;
/* end of prologue */
    v275 = stack[-2];
    v241 = elt(env, 1); /* !:rd!: */
    if (!consp(v275)) goto v19;
    v275 = qcar(v275);
    if (!(v275 == v241)) goto v19;
    v241 = stack[-2];
    v241 = qcdr(v241);
    if (!consp(v241)) goto v19;
    v241 = stack[0];
    v241 = integerp(v241);
    if (v241 == nil) goto v19;
    v275 = stack[0];
    v241 = (Lisp_Object)1; /* 0 */
    v241 = (Lisp_Object)greaterp2(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v241 = v241 ? lisp_true : nil;
    env = stack[-4];
    if (v241 == nil) goto v19;
    v241 = stack[-2];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v241 = Labsval(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    fn = elt(env, 2); /* msd */
    v275 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v241 = stack[0];
    v275 = difference2(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    stack[0] = v275;
    v241 = (Lisp_Object)1; /* 0 */
    if (v275 == v241) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v275 = stack[0];
    v241 = (Lisp_Object)1; /* 0 */
    v241 = (Lisp_Object)lessp2(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v241 = v241 ? lisp_true : nil;
    env = stack[-4];
    if (v241 == nil) goto v63;
    v241 = stack[0];
    v241 = negate(v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    stack[-3] = v241;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v241 = stack[-2];
    v241 = qcdr(v241);
    v275 = qcar(v241);
    v241 = stack[-3];
    stack[0] = Lash1(nil, v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v241 = stack[-2];
    v241 = qcdr(v241);
    v275 = qcdr(v241);
    v241 = stack[-3];
    v241 = difference2(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v167 = stack[-1];
        Lisp_Object v277 = stack[0];
        popv(5);
        return list2star(v167, v277, v241);
    }

v63:
    v241 = stack[0];
    v241 = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    stack[-3] = v241;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v241 = stack[-2];
    v241 = qcdr(v241);
    stack[0] = qcar(v241);
    v241 = stack[-3];
    v241 = negate(v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v241 = stack[-2];
    v241 = qcdr(v241);
    v275 = qcdr(v241);
    v241 = stack[-3];
    v241 = plus2(v275, v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v241 = list2star(stack[-1], stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v241);
    }

v19:
    v241 = elt(env, 0); /* conv!:mt */
    {
        popv(5);
        fn = elt(env, 4); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v241);
    }
/* error exit handlers */
v170:
    popv(5);
    return nil;
}



/* Code for convertmode */

static Lisp_Object MS_CDECL CC_convertmode(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v232, Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v247, v58, v252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convertmode");
#endif
    if (stack >= stacklimit)
    {
        push4(v6,v232,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v232,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v232;
    stack[-2] = v1;
    v227 = v0;
/* end of prologue */
    v58 = v227;
    v247 = stack[-2];
    v227 = stack[0];
    fn = elt(env, 1); /* form1 */
    v252 = (*qfnn(fn))(qenv(fn), 3, v58, v247, v227);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-3];
    v58 = stack[-2];
    v247 = stack[-1];
    v227 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v252, v58, v247, v227);
    }
/* error exit handlers */
v69:
    popv(4);
    return nil;
}



/* Code for diffp1 */

static Lisp_Object CC_diffp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v26, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp1");
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
    v87 = v1;
    v218 = v0;
/* end of prologue */
    v26 = v218;
    v26 = qcar(v26);
    if (v26 == v87) goto v203;
    v87 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v87); }

v203:
    v87 = v218;
    v26 = qcdr(v87);
    v87 = (Lisp_Object)17; /* 1 */
    if (v26 == v87) goto v73;
    v87 = v218;
    stack[-1] = qcdr(v87);
    v87 = v218;
    stack[0] = qcar(v87);
    v87 = v218;
    v87 = qcdr(v87);
    v87 = sub1(v87);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    fn = elt(env, 2); /* to */
    v26 = (*qfn2(fn))(qenv(fn), stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    v87 = (Lisp_Object)17; /* 1 */
    v87 = cons(v26, v87);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    v87 = ncons(v87);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    {
        Lisp_Object v54 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* multd */
        return (*qfn2(fn))(qenv(fn), v54, v87);
    }

v73:
    v87 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v87); }
/* error exit handlers */
v230:
    popv(3);
    return nil;
}



/* Code for canonsq */

static Lisp_Object CC_canonsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v154, v288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canonsq");
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
    v153 = stack[-1];
    v154 = qcdr(v153);
    v153 = (Lisp_Object)17; /* 1 */
    if (v154 == v153) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v153 = stack[-1];
    v153 = qcar(v153);
    if (v153 == nil) goto v71;
    v153 = qvalue(elt(env, 2)); /* asymplis!* */
    if (v153 == nil) goto v233;
    v153 = stack[-1];
    v154 = qcar(v153);
    v153 = stack[-1];
    v153 = qcdr(v153);
    fn = elt(env, 9); /* gcdf */
    v154 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    stack[-2] = v154;
    v153 = (Lisp_Object)17; /* 1 */
    if (v154 == v153) goto v233;
    v153 = stack[-1];
    v154 = qcar(v153);
    v153 = stack[-2];
    fn = elt(env, 10); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    v153 = stack[-1];
    v154 = qcdr(v153);
    v153 = stack[-2];
    fn = elt(env, 10); /* quotf */
    v153 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    v153 = cons(stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    stack[-1] = v153;
    goto v233;

v233:
    v153 = stack[-1];
    v153 = qcdr(v153);
    fn = elt(env, 11); /* lnc */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    stack[-2] = v153;
    v154 = stack[-2];
    v153 = (Lisp_Object)17; /* 1 */
    if (v154 == v153) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v153 = stack[-2];
    if (!consp(v153)) goto v49;
    v153 = stack[-2];
    v154 = qcar(v153);
    v153 = elt(env, 3); /* minusp */
    v154 = get(v154, v153);
    env = stack[-3];
    v153 = stack[-2];
    v153 = Lapply1(nil, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    if (v153 == nil) goto v50;
    v153 = stack[-1];
    v153 = qcar(v153);
    fn = elt(env, 12); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    v153 = stack[-1];
    v153 = qcdr(v153);
    fn = elt(env, 12); /* negf */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    v153 = cons(stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    stack[-1] = v153;
    v153 = stack[-2];
    v154 = qcar(v153);
    v153 = elt(env, 4); /* difference */
    stack[0] = get(v154, v153);
    env = stack[-3];
    v153 = stack[-2];
    v154 = qcar(v153);
    v153 = elt(env, 5); /* i2d */
    v154 = get(v154, v153);
    env = stack[-3];
    v153 = (Lisp_Object)1; /* 0 */
    v154 = Lapply1(nil, v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    v153 = stack[-2];
    v153 = Lapply2(nil, 3, stack[0], v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    stack[-2] = v153;
    goto v50;

v50:
    v153 = stack[-2];
    if (is_number(v153)) goto v290;
    v154 = qvalue(elt(env, 6)); /* dmode!* */
    v153 = elt(env, 7); /* unitsfn */
    v153 = get(v154, v153);
    env = stack[-3];
    v154 = v153;
    if (v153 == nil) goto v290;
    v288 = v154;
    v154 = stack[-1];
    v153 = stack[-2];
        popv(4);
        return Lapply2(nil, 3, v288, v154, v153);

v290:
    v154 = qvalue(elt(env, 6)); /* dmode!* */
    v153 = elt(env, 8); /* field */
    v153 = Lflagp(nil, v154, v153);
    env = stack[-3];
    if (!(v153 == nil)) goto v158;
    v153 = stack[-2];
    if (!consp(v153)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v153 = stack[-2];
    v154 = qcar(v153);
    v153 = elt(env, 8); /* field */
    v153 = Lflagp(nil, v154, v153);
    env = stack[-3];
    if (v153 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else goto v158;

v158:
    v154 = stack[-2];
    v153 = stack[-1];
    {
        popv(4);
        fn = elt(env, 13); /* fieldconv */
        return (*qfn2(fn))(qenv(fn), v154, v153);
    }

v49:
    v153 = stack[-2];
    v153 = Lminusp(nil, v153);
    env = stack[-3];
    if (v153 == nil) goto v50;
    v153 = stack[-1];
    v153 = qcar(v153);
    fn = elt(env, 12); /* negf */
    stack[0] = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    v153 = stack[-1];
    v153 = qcdr(v153);
    fn = elt(env, 12); /* negf */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    v153 = cons(stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    stack[-1] = v153;
    v153 = stack[-2];
    v153 = negate(v153);
    nil = C_nil;
    if (exception_pending()) goto v289;
    env = stack[-3];
    stack[-2] = v153;
    goto v50;

v71:
    v154 = qvalue(elt(env, 1)); /* nil */
    v153 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v154, v153);
/* error exit handlers */
v289:
    popv(4);
    return nil;
}



/* Code for comm_kernels */

static Lisp_Object CC_comm_kernels(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm_kernels");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v0;
/* end of prologue */
    v46 = v45;
    v45 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* comm_kernels1 */
        return (*qfn2(fn))(qenv(fn), v46, v45);
    }
}



/* Code for bcone!? */

static Lisp_Object CC_bconeW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v29, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcone?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v0;
/* end of prologue */
    v220 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v220 == nil) goto v72;
    v29 = v55;
    v220 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v29, v220);

v72:
    v220 = v55;
    v29 = qcdr(v220);
    v220 = (Lisp_Object)17; /* 1 */
    if (v29 == v220) goto v252;
    v220 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v220);

v252:
    v220 = v55;
    v29 = qcar(v220);
    v220 = (Lisp_Object)17; /* 1 */
    v220 = (v29 == v220 ? lisp_true : nil);
    return onevalue(v220);
}



/* Code for mksgnsq */

static Lisp_Object CC_mksgnsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v248, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksgnsq");
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
    v248 = v0;
/* end of prologue */
    v53 = v248;
    fn = elt(env, 1); /* evenfree */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    v248 = v53;
    if (v53 == nil) goto v43;
    v184 = v248;
    v53 = (Lisp_Object)17; /* 1 */
    if (v184 == v53) goto v97;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v53 = (Lisp_Object)17; /* 1 */
    v53 = cons(v248, v53);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    fn = elt(env, 2); /* mk!*sq */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    v53 = list2(stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v53);
    }

v97:
    v248 = (Lisp_Object)-15; /* -1 */
    v53 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v248, v53);

v43:
    v248 = (Lisp_Object)17; /* 1 */
    v53 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v248, v53);
/* error exit handlers */
v87:
    popv(2);
    return nil;
}



/* Code for ncmpchk */

static Lisp_Object CC_ncmpchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ncmpchk");
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
    v57 = stack[-1];
    v56 = stack[0];
    fn = elt(env, 1); /* noncommuting */
    v56 = (*qfn2(fn))(qenv(fn), v57, v56);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    v56 = (v56 == nil ? lisp_true : nil);
    if (!(v56 == nil)) { popv(3); return onevalue(v56); }
    v57 = stack[-1];
    v56 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* ordop */
        return (*qfn2(fn))(qenv(fn), v57, v56);
    }
/* error exit handlers */
v251:
    popv(3);
    return nil;
}



/* Code for mv!-domainlist!-!- */

static Lisp_Object CC_mvKdomainlistKK(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist--");
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
    goto v209;

v209:
    v70 = stack[-1];
    if (v70 == nil) goto v43;
    v70 = stack[-1];
    v74 = qcar(v70);
    v70 = stack[0];
    v70 = qcar(v70);
    v74 = difference2(v74, v70);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    v70 = stack[-2];
    v70 = cons(v74, v70);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-3];
    stack[-2] = v70;
    v70 = stack[-1];
    v70 = qcdr(v70);
    stack[-1] = v70;
    v70 = stack[0];
    v70 = qcdr(v70);
    stack[0] = v70;
    goto v209;

v43:
    v70 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v70);
    }
/* error exit handlers */
v29:
    popv(4);
    return nil;
}



/* Code for make!-term */

static Lisp_Object MS_CDECL CC_makeKterm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v232, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v161, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-term");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-term");
#endif
    if (stack >= stacklimit)
    {
        push3(v232,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v232);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v232;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v160 = (Lisp_Object)1; /* 0 */
    stack[-2] = v160;
    v160 = (Lisp_Object)1; /* 0 */
    stack[0] = v160;
    goto v88;

v88:
    v161 = stack[-4];
    v160 = stack[0];
    v161 = *(Lisp_Object *)((char *)v161 + (CELL-TAG_VECTOR) + ((int32_t)v160/(16/CELL)));
    v160 = (Lisp_Object)1; /* 0 */
    v160 = (Lisp_Object)lessp2(v161, v160);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v160 = v160 ? lisp_true : nil;
    env = stack[-7];
    if (v160 == nil) goto v76;
    v160 = (Lisp_Object)-15; /* -1 */
    stack[-2] = v160;
    goto v60;

v60:
    v160 = (Lisp_Object)49; /* 3 */
    v160 = Lmkvect(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    stack[-6] = v160;
    v161 = stack[-2];
    v160 = (Lisp_Object)17; /* 1 */
    if (v161 == v160) goto v63;
    v161 = stack[-5];
    v160 = elt(env, 3); /* cos */
    if (v161 == v160) goto v63;
    stack[-1] = stack[-6];
    stack[0] = (Lisp_Object)1; /* 0 */
    v161 = elt(env, 4); /* (-1 . 1) */
    v160 = stack[-3];
    fn = elt(env, 5); /* multsq */
    v160 = (*qfn2(fn))(qenv(fn), v161, v160);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v160;
    goto v91;

v91:
    v42 = stack[-6];
    v161 = (Lisp_Object)17; /* 1 */
    v160 = stack[-5];
    *(Lisp_Object *)((char *)v42 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL))) = v160;
    v161 = stack[-2];
    v160 = (Lisp_Object)-15; /* -1 */
    if (!(v161 == v160)) goto v295;
    v160 = (Lisp_Object)113; /* 7 */
    v160 = Lmkvect(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    stack[-2] = v160;
    v160 = (Lisp_Object)1; /* 0 */
    stack[-3] = v160;
    goto v225;

v225:
    v161 = (Lisp_Object)113; /* 7 */
    v160 = stack[-3];
    v160 = difference2(v161, v160);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    v160 = Lminusp(nil, v160);
    env = stack[-7];
    if (v160 == nil) goto v237;
    v160 = stack[-2];
    stack[-4] = v160;
    goto v295;

v295:
    v42 = stack[-6];
    v161 = (Lisp_Object)33; /* 2 */
    v160 = stack[-4];
    *(Lisp_Object *)((char *)v42 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL))) = v160;
    v161 = stack[-6];
    v160 = (Lisp_Object)49; /* 3 */
    v42 = qvalue(elt(env, 2)); /* nil */
    *(Lisp_Object *)((char *)v161 + (CELL-TAG_VECTOR) + ((int32_t)v160/(16/CELL))) = v42;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v237:
    stack[-1] = stack[-2];
    stack[0] = stack[-3];
    v161 = stack[-4];
    v160 = stack[-3];
    v160 = *(Lisp_Object *)((char *)v161 + (CELL-TAG_VECTOR) + ((int32_t)v160/(16/CELL)));
    v160 = negate(v160);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v160;
    v160 = stack[-3];
    v160 = add1(v160);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-7];
    stack[-3] = v160;
    goto v225;

v63:
    v42 = stack[-6];
    v161 = (Lisp_Object)1; /* 0 */
    v160 = stack[-3];
    *(Lisp_Object *)((char *)v42 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL))) = v160;
    goto v91;

v76:
    v161 = stack[-4];
    v160 = stack[0];
    v161 = *(Lisp_Object *)((char *)v161 + (CELL-TAG_VECTOR) + ((int32_t)v160/(16/CELL)));
    v160 = (Lisp_Object)1; /* 0 */
    v160 = (Lisp_Object)greaterp2(v161, v160);
    nil = C_nil;
    if (exception_pending()) goto v149;
    v160 = v160 ? lisp_true : nil;
    env = stack[-7];
    if (v160 == nil) goto v53;
    v160 = (Lisp_Object)17; /* 1 */
    stack[-2] = v160;
    goto v60;

v53:
    v161 = stack[0];
    v160 = (Lisp_Object)113; /* 7 */
    if (v161 == v160) goto v226;
    v160 = stack[0];
    v160 = (Lisp_Object)((int32_t)(v160) + 0x10);
    stack[0] = v160;
    goto v88;

v226:
    v161 = stack[-5];
    v160 = elt(env, 1); /* sin */
    if (!(v161 == v160)) goto v60;
    v160 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v160); }
/* error exit handlers */
v149:
    popv(8);
    return nil;
}



/* Code for listtest */

static Lisp_Object MS_CDECL CC_listtest(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v232, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v55, v27;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "listtest");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listtest");
#endif
    if (stack >= stacklimit)
    {
        push3(v232,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v232);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v232;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v209:
    v29 = stack[-2];
    if (v29 == nil) goto v43;
    v27 = stack[0];
    v29 = stack[-2];
    v55 = qcar(v29);
    v29 = stack[-1];
    v29 = Lapply2(nil, 3, v27, v55, v29);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-3];
    if (v29 == nil) goto v74;
    v29 = stack[-2];
    v29 = qcar(v29);
    if (v29 == nil) goto v227;
    v29 = stack[-2];
    v29 = qcar(v29);
    { popv(4); return onevalue(v29); }

v227:
    v29 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v29); }

v74:
    v29 = stack[-2];
    v29 = qcdr(v29);
    stack[-2] = v29;
    goto v209;

v43:
    v29 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v29); }
/* error exit handlers */
v95:
    popv(4);
    return nil;
}



/* Code for ord */

static Lisp_Object CC_ord(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v251, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ord");
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
    v228 = v0;
/* end of prologue */
    v251 = qvalue(elt(env, 1)); /* ordering */
    v97 = elt(env, 2); /* lex */
    if (v251 == v97) goto v78;
    v97 = v228;
    v97 = qcar(v97);
    { popv(1); return onevalue(v97); }

v78:
    v97 = elt(env, 3); /* plus */
    v251 = v228;
    v97 = cons(v97, v251);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* eval */
        return (*qfn1(fn))(qenv(fn), v97);
    }
/* error exit handlers */
v227:
    popv(1);
    return nil;
}



/* Code for pv_neg */

static Lisp_Object CC_pv_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v69, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_neg");
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
    goto v210;

v210:
    v33 = stack[0];
    if (v33 == nil) goto v209;
    v33 = stack[0];
    v33 = qcar(v33);
    v33 = qcar(v33);
    v70 = negate(v33);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v33 = stack[0];
    v33 = qcar(v33);
    v69 = qcdr(v33);
    v33 = stack[-1];
    v33 = acons(v70, v69, v33);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    stack[-1] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v210;

v209:
    v33 = stack[-1];
        popv(3);
        return Lnreverse(nil, v33);
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for exptmod!: */

static Lisp_Object CC_exptmodT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptmod:");
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
    v60 = v1;
    v61 = v0;
/* end of prologue */
    v61 = qcdr(v61);
    fn = elt(env, 1); /* general!-modular!-expt */
    v60 = (*qfn2(fn))(qenv(fn), v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v60);
    }
/* error exit handlers */
v78:
    popv(1);
    return nil;
}



/* Code for crprcd */

static Lisp_Object CC_crprcd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprcd");
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
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcar(v71);
    fn = elt(env, 1); /* convprec!* */
    stack[-1] = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    fn = elt(env, 1); /* convprec!* */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v72 = stack[-1];
    popv(3);
    return cons(v72, v71);
/* error exit handlers */
v57:
    popv(3);
    return nil;
}



/* Code for revv0 */

static Lisp_Object CC_revv0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revv0");
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

v210:
    v34 = stack[-1];
    v34 = qcdr(v34);
    v156 = qcar(v34);
    v34 = stack[0];
    if (v156 == v34) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v34 = stack[-1];
    v34 = qcdr(v34);
    v34 = qcar(v34);
    stack[-2] = v34;
    v34 = stack[-1];
    v156 = qcdr(v34);
    v34 = stack[-1];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    v34 = Lrplaca(nil, v156, v34);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v34 = stack[-1];
    v34 = qcdr(v34);
    v156 = qcdr(v34);
    v34 = stack[-1];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    v34 = Lrplaca(nil, v156, v34);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v34 = stack[-1];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v156 = qcdr(v34);
    v34 = stack[-2];
    v34 = Lrplaca(nil, v156, v34);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v156 = stack[-1];
    v34 = stack[0];
    stack[-1] = v156;
    stack[0] = v34;
    goto v210;
/* error exit handlers */
v183:
    popv(4);
    return nil;
}



/* Code for ibalp_renewwl */

static Lisp_Object CC_ibalp_renewwl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v304;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_renewwl");
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
    v303 = v0;
/* end of prologue */
    stack[-2] = v303;
    goto v44;

v44:
    v303 = stack[-2];
    if (v303 == nil) goto v210;
    v303 = stack[-2];
    v303 = qcar(v303);
    stack[-1] = v303;
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    if (!(v303 == nil)) goto v71;
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v304 = Llength(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v303 = (Lisp_Object)17; /* 1 */
    v303 = Leqn(nil, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    if (v303 == nil) goto v252;
    v303 = stack[-1];
    v303 = qcar(v303);
    stack[0] = Llength(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v303 = Llength(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v304 = plus2(stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v303 = (Lisp_Object)17; /* 1 */
    v303 = (Lisp_Object)greaterp2(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    v303 = v303 ? lisp_true : nil;
    env = stack[-4];
    if (v303 == nil) goto v252;
    v303 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    stack[-3] = v303;
    v303 = stack[-3];
    if (v303 == nil) goto v71;
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    stack[0] = qcdr(v303);
    v304 = stack[-3];
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v303 = cons(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v303 = stack[-3];
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
    v304 = stack[-1];
    v303 = stack[-3];
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
    v303 = qcar(v303);
    v303 = cons(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    goto v71;

v71:
    v303 = stack[-2];
    v303 = qcdr(v303);
    stack[-2] = v303;
    goto v44;

v252:
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    if (!(v303 == nil)) goto v71;
    v303 = stack[-1];
    v303 = qcar(v303);
    stack[0] = Llength(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v303 = Llength(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v304 = plus2(stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v303 = (Lisp_Object)17; /* 1 */
    v303 = (Lisp_Object)greaterp2(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    v303 = v303 ? lisp_true : nil;
    env = stack[-4];
    if (v303 == nil) goto v71;
    v303 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    stack[-3] = v303;
    v303 = stack[-3];
    if (v303 == nil) goto v11;
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    stack[0] = qcdr(v303);
    v304 = stack[-3];
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v303 = cons(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v303 = stack[-3];
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
    v304 = stack[-1];
    v303 = stack[-3];
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
    v303 = qcar(v303);
    v303 = cons(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    goto v11;

v11:
    v303 = stack[-1];
    fn = elt(env, 2); /* ibalp_getnewwl */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    stack[-3] = v303;
    v303 = stack[-3];
    if (v303 == nil) goto v71;
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    stack[0] = qcdr(v303);
    v304 = stack[-3];
    v303 = stack[-1];
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcdr(v303);
    v303 = qcar(v303);
    v303 = cons(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    v303 = stack[-3];
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
    v304 = stack[-1];
    v303 = stack[-3];
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
    v303 = qcar(v303);
    v303 = cons(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    fn = elt(env, 3); /* setcar */
    v303 = (*qfn2(fn))(qenv(fn), stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-4];
    goto v71;

v210:
    v303 = nil;
    { popv(5); return onevalue(v303); }
/* error exit handlers */
v305:
    popv(5);
    return nil;
}



/* Code for rl_sacat */

static Lisp_Object MS_CDECL CC_rl_sacat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v232, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_sacat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_sacat");
#endif
    if (stack >= stacklimit)
    {
        push3(v232,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v232);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v88 = v232;
    v56 = v1;
    v57 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacat!* */
    v88 = list3(v57, v56, v88);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-1];
    {
        Lisp_Object v251 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v251, v88);
    }
/* error exit handlers */
v97:
    popv(2);
    return nil;
}



/* Code for command1 */

static Lisp_Object MS_CDECL CC_command1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for command1");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 4); /* scan */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[0];
    fn = elt(env, 5); /* setcloc!* */
    v44 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[0];
    v44 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 2)) = v44; /* key!* */
    v44 = qvalue(elt(env, 3)); /* nil */
    {
        popv(1);
        fn = elt(env, 6); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v44);
    }
/* error exit handlers */
v43:
    popv(1);
    return nil;
}



/* Code for dfn_prop */

static Lisp_Object CC_dfn_prop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v115, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfn_prop");
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
    v95 = v0;
/* end of prologue */
    v95 = qcdr(v95);
    v95 = Llength(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[0];
    v144 = v95;
    v115 = v144;
    v95 = (Lisp_Object)17; /* 1 */
    if (v115 == v95) goto v44;
    v115 = v144;
    v95 = (Lisp_Object)33; /* 2 */
    if (v115 == v95) goto v203;
    v115 = v144;
    v95 = (Lisp_Object)49; /* 3 */
    if (v115 == v95) goto v228;
    v95 = elt(env, 1); /* dfn */
    v115 = v144;
    {
        popv(1);
        fn = elt(env, 4); /* mkid */
        return (*qfn2(fn))(qenv(fn), v95, v115);
    }

v228:
    v95 = elt(env, 3); /* dfn3 */
    { popv(1); return onevalue(v95); }

v203:
    v95 = elt(env, 2); /* dfn2 */
    { popv(1); return onevalue(v95); }

v44:
    v95 = elt(env, 1); /* dfn */
    { popv(1); return onevalue(v95); }
/* error exit handlers */
v141:
    popv(1);
    return nil;
}



setup_type const u08_setup[] =
{
    {"stable-sortip",           too_few_2,      CC_stableKsortip,wrong_no_2},
    {"symbol",                  CC_symbol,      too_many_1,    wrong_no_1},
    {"ident",                   CC_ident,       too_many_1,    wrong_no_1},
    {"wedget2",                 too_few_2,      CC_wedget2,    wrong_no_2},
    {"contrsp",                 too_few_2,      CC_contrsp,    wrong_no_2},
    {"mo_diff",                 too_few_2,      CC_mo_diff,    wrong_no_2},
    {"gcddd",                   too_few_2,      CC_gcddd,      wrong_no_2},
    {"general-modular-minus",   CC_generalKmodularKminus,too_many_1,wrong_no_1},
    {"mk+mat+mult+mat",         too_few_2,      CC_mkLmatLmultLmat,wrong_no_2},
    {"tmsf*",                   CC_tmsfH,       too_many_1,    wrong_no_1},
    {"ibalp_varlat",            CC_ibalp_varlat,too_many_1,    wrong_no_1},
    {"smtp",                    too_few_2,      CC_smtp,       wrong_no_2},
    {"comm_kernels1",           too_few_2,      CC_comm_kernels1,wrong_no_2},
    {"flatindxl",               CC_flatindxl,   too_many_1,    wrong_no_1},
    {"minus:",                  CC_minusT,      too_many_1,    wrong_no_1},
    {"greaterp:",               too_few_2,      CC_greaterpT,  wrong_no_2},
    {"leftzeros",               CC_leftzeros,   too_many_1,    wrong_no_1},
    {"th_match0",               too_few_2,      CC_th_match0,  wrong_no_2},
    {"c:extadd",                too_few_2,      CC_cTextadd,   wrong_no_2},
    {"cl_cflip",                too_few_2,      CC_cl_cflip,   wrong_no_2},
    {"totalcompare",            too_few_2,      CC_totalcompare,wrong_no_2},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"get_rep_matrix_in",       too_few_2,      CC_get_rep_matrix_in,wrong_no_2},
    {"unplus",                  CC_unplus,      too_many_1,    wrong_no_1},
    {"formlis",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formlis},
    {"omair",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omair},
    {"scalopp",                 CC_scalopp,     too_many_1,    wrong_no_1},
    {"getel",                   CC_getel,       too_many_1,    wrong_no_1},
    {"b:extmult",               too_few_2,      CC_bTextmult,  wrong_no_2},
    {"horner-rule",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKrule},
    {"cl_varl1",                CC_cl_varl1,    too_many_1,    wrong_no_1},
    {"ibalp_csat",              CC_ibalp_csat,  too_many_1,    wrong_no_1},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"xord_lex",                too_few_2,      CC_xord_lex,   wrong_no_2},
    {"plus:",                   too_few_2,      CC_plusT,      wrong_no_2},
    {"errorset2",               CC_errorset2,   too_many_1,    wrong_no_1},
    {"formop",                  CC_formop,      too_many_1,    wrong_no_1},
    {"conv:mt",                 too_few_2,      CC_convTmt,    wrong_no_2},
    {"convertmode",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode},
    {"diffp1",                  too_few_2,      CC_diffp1,     wrong_no_2},
    {"canonsq",                 CC_canonsq,     too_many_1,    wrong_no_1},
    {"comm_kernels",            CC_comm_kernels,too_many_1,    wrong_no_1},
    {"bcone?",                  CC_bconeW,      too_many_1,    wrong_no_1},
    {"mksgnsq",                 CC_mksgnsq,     too_many_1,    wrong_no_1},
    {"ncmpchk",                 too_few_2,      CC_ncmpchk,    wrong_no_2},
    {"mv-domainlist--",         too_few_2,      CC_mvKdomainlistKK,wrong_no_2},
    {"make-term",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKterm},
    {"listtest",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_listtest},
    {"ord",                     CC_ord,         too_many_1,    wrong_no_1},
    {"pv_neg",                  CC_pv_neg,      too_many_1,    wrong_no_1},
    {"exptmod:",                too_few_2,      CC_exptmodT,   wrong_no_2},
    {"crprcd",                  CC_crprcd,      too_many_1,    wrong_no_1},
    {"revv0",                   too_few_2,      CC_revv0,      wrong_no_2},
    {"ibalp_renewwl",           CC_ibalp_renewwl,too_many_1,   wrong_no_1},
    {"rl_sacat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_sacat},
    {"command1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_command1},
    {"dfn_prop",                CC_dfn_prop,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u08", (two_args *)"20666 5646907 1412311", 0}
};

/* end of generated code */
