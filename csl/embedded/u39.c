
/* $destdir/generated-c\u39.c Machine generated C code */

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


/* Code for algmodep */

static Lisp_Object CC_algmodep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for algmodep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v3 = v4;
    if (!consp(v3)) goto v5;
    v3 = v4;
    v3 = qcar(v3);
    v4 = elt(env, 2); /* (aeval aeval!*) */
    v3 = Lmemq(nil, v3, v4);
    return onevalue(v3);

v5:
    v3 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v3);
}



/* Code for ofsf_irl2atl */

static Lisp_Object MS_CDECL CC_ofsf_irl2atl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v6,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_irl2atl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_irl2atl");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v6,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v7;
    v19 = v6;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v19;
    goto v22;

v22:
    v19 = stack[-5];
    if (v19 == nil) goto v23;
    v19 = stack[-5];
    v19 = qcar(v19);
    v21 = stack[-4];
    v20 = v19;
    v19 = stack[-3];
    fn = elt(env, 2); /* ofsf_ir2atl */
    v19 = (*qfnn(fn))(qenv(fn), 3, v21, v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-6];
    stack[-2] = v19;
    v19 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-6];
    stack[-1] = v19;
    v19 = stack[-5];
    v19 = qcdr(v19);
    stack[-5] = v19;
    v19 = stack[-1];
    if (!consp(v19)) goto v22;
    else goto v25;

v25:
    v19 = stack[-5];
    if (v19 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v19 = stack[-5];
    v19 = qcar(v19);
    v21 = stack[-4];
    v20 = v19;
    v19 = stack[-3];
    fn = elt(env, 2); /* ofsf_ir2atl */
    v19 = (*qfnn(fn))(qenv(fn), 3, v21, v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-6];
    v19 = Lrplacd(nil, stack[0], v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-6];
    v19 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-6];
    stack[-1] = v19;
    v19 = stack[-5];
    v19 = qcdr(v19);
    stack[-5] = v19;
    goto v25;

v23:
    v19 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v19); }
/* error exit handlers */
v24:
    popv(7);
    return nil;
}



/* Code for homogp */

static Lisp_Object CC_homogp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for homogp");
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
    v30 = stack[0];
    if (!consp(v30)) goto v5;
    v30 = stack[0];
    v30 = qcar(v30);
    if (!consp(v30)) goto v5;
    v30 = stack[0];
    v30 = qcar(v30);
    if (!consp(v30)) goto v5;
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    if (!consp(v30)) goto v5;
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v30 = qcdr(v30);
    if (v30 == nil) goto v32;
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    fn = elt(env, 3); /* lastnondomain */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v30 = qcdr(v30);
    v31 = v30;
    v30 = v31;
    v30 = (consp(v30) ? nil : lisp_true);
    if (!(v30 == nil)) goto v33;
    v30 = v31;
    v30 = qcar(v30);
    v30 = (consp(v30) ? nil : lisp_true);
    goto v33;

v33:
    if (v30 == nil) goto v34;
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v30); }

v34:
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    fn = elt(env, 4); /* listsum */
    stack[-1] = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    fn = elt(env, 3); /* lastnondomain */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v30 = qcar(v30);
    v30 = qcar(v30);
    fn = elt(env, 4); /* listsum */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    if (equal(stack[-1], v30)) goto v35;
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v30); }

v35:
    v30 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v30); }

v32:
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v30); }

v5:
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v30); }
/* error exit handlers */
v20:
    popv(3);
    return nil;
}



/* Code for cd_ordatp */

static Lisp_Object CC_cd_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v43, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cd_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v6;
    v44 = v0;
/* end of prologue */
    v41 = v44;
    v42 = qcar(v41);
    v41 = elt(env, 1); /* neq */
    if (!(v42 == v41)) goto v18;
    v41 = v43;
    v42 = qcar(v41);
    v41 = elt(env, 2); /* equal */
    if (!(v42 == v41)) goto v18;
    v41 = qvalue(elt(env, 3)); /* t */
    return onevalue(v41);

v18:
    v41 = v44;
    v42 = qcar(v41);
    v41 = elt(env, 2); /* equal */
    if (!(v42 == v41)) goto v45;
    v41 = v43;
    v42 = qcar(v41);
    v41 = elt(env, 1); /* neq */
    if (!(v42 == v41)) goto v45;
    v41 = qvalue(elt(env, 4)); /* nil */
    return onevalue(v41);

v45:
    v41 = v44;
    v41 = qcdr(v41);
    v41 = qcar(v41);
    v42 = v43;
    v42 = qcdr(v42);
    v42 = qcar(v42);
    {
        fn = elt(env, 5); /* ordp */
        return (*qfn2(fn))(qenv(fn), v41, v42);
    }
}



/* Code for sfpf */

static Lisp_Object CC_sfpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfpf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v3 = v4;
    if (!consp(v3)) goto v5;
    v3 = v4;
    v3 = qcar(v3);
    if (!consp(v3)) goto v5;
    v3 = v4;
    v3 = qcar(v3);
    v3 = qcar(v3);
    v3 = qcar(v3);
    {
        fn = elt(env, 2); /* sfp */
        return (*qfn1(fn))(qenv(fn), v3);
    }

v5:
    v3 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v3);
}



/* Code for rfirst */

static Lisp_Object CC_rfirst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rfirst");
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
    v50 = stack[0];
    v50 = qcar(v50);
    stack[0] = v50;
    v50 = stack[0];
    fn = elt(env, 3); /* listeval0 */
    v36 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    stack[-1] = v36;
    v50 = elt(env, 1); /* list */
    if (!consp(v36)) goto v38;
    v36 = qcar(v36);
    if (!(v36 == v50)) goto v38;

v51:
    v50 = stack[-1];
    v50 = qcdr(v50);
    if (v50 == nil) goto v52;
    v50 = stack[-1];
    v50 = qcdr(v50);
    v50 = qcar(v50);
    {
        popv(3);
        fn = elt(env, 4); /* reval */
        return (*qfn1(fn))(qenv(fn), v50);
    }

v52:
    v36 = stack[0];
    v50 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* parterr */
    v50 = (*qfn2(fn))(qenv(fn), v36, v50);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v50 = nil;
    { popv(3); return onevalue(v50); }

v38:
    v50 = stack[0];
    fn = elt(env, 6); /* aeval */
    v36 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    stack[-1] = v36;
    v50 = elt(env, 1); /* list */
    if (!consp(v36)) goto v53;
    v36 = qcar(v36);
    if (v36 == v50) goto v51;
    else goto v53;

v53:
    v36 = stack[0];
    v50 = elt(env, 2); /* "list" */
    fn = elt(env, 7); /* typerr */
    v50 = (*qfn2(fn))(qenv(fn), v36, v50);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-2];
    goto v51;
/* error exit handlers */
v43:
    popv(3);
    return nil;
}



/* Code for dp!=a2dpatom */

static Lisp_Object CC_dpMa2dpatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=a2dpatom");
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
    v46 = (Lisp_Object)1; /* 0 */
    if (v26 == v46) goto v5;
    v46 = stack[0];
    if (is_number(v46)) goto v16;
    stack[-1] = stack[0];
    v46 = qvalue(elt(env, 2)); /* cali!=basering */
    fn = elt(env, 3); /* ring_all_names */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v46 = Lmember(nil, stack[-1], v46);
    if (v46 == nil) goto v16;
    v46 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* bc_fi */
    stack[-1] = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v46 = stack[0];
    fn = elt(env, 5); /* mo_from_a */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 6); /* dp_term */
    v46 = (*qfn2(fn))(qenv(fn), stack[-1], v46);
    nil = C_nil;
    if (exception_pending()) goto v58;
    popv(3);
    return ncons(v46);

v16:
    v46 = stack[0];
    fn = elt(env, 7); /* bc_from_a */
    stack[0] = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 8); /* mo_zero */
    v46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 6); /* dp_term */
    v46 = (*qfn2(fn))(qenv(fn), stack[0], v46);
    nil = C_nil;
    if (exception_pending()) goto v58;
    popv(3);
    return ncons(v46);

v5:
    v46 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v46); }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for gd_gcasesimpl */

static Lisp_Object CC_gd_gcasesimpl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_gcasesimpl");
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
    v4 = stack[0];
    stack[-1] = qcar(v4);
    v4 = stack[0];
    v4 = qcdr(v4);
    v4 = qcar(v4);
    fn = elt(env, 1); /* gd_simpl */
    v32 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v4 = stack[0];
    v4 = qcdr(v4);
    v4 = qcdr(v4);
    v4 = qcar(v4);
    {
        Lisp_Object v55 = stack[-1];
        popv(2);
        return list3(v55, v32, v4);
    }
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for mk_character */

static Lisp_Object CC_mk_character(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_character");
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
    v69 = stack[-5];
    fn = elt(env, 2); /* get_group_in */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    stack[-6] = v69;
    v69 = stack[-6];
    fn = elt(env, 3); /* get!*elements */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    stack[-4] = v69;
    v69 = stack[-4];
    if (v69 == nil) goto v3;
    v69 = stack[-4];
    v69 = qcar(v69);
    stack[0] = v69;
    v70 = v69;
    v69 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+trace */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    v69 = list2(stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    stack[-2] = v69;
    stack[-3] = v69;
    goto v23;

v23:
    v69 = stack[-4];
    v69 = qcdr(v69);
    stack[-4] = v69;
    v69 = stack[-4];
    if (v69 == nil) goto v34;
    stack[-1] = stack[-2];
    v69 = stack[-4];
    v69 = qcar(v69);
    stack[0] = v69;
    v70 = v69;
    v69 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+trace */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    v69 = list2(stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    v69 = Lrplacd(nil, stack[-1], v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-7];
    v69 = stack[-2];
    v69 = qcdr(v69);
    stack[-2] = v69;
    goto v23;

v34:
    v69 = stack[-3];
    goto v72;

v72:
    stack[0] = v69;
    v69 = stack[-6];
    v70 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v69 = stack[0];
        popv(8);
        return Lappend(nil, v70, v69);

v3:
    v69 = qvalue(elt(env, 1)); /* nil */
    goto v72;
/* error exit handlers */
v71:
    popv(8);
    return nil;
}



/* Code for rnfloor!* */

static Lisp_Object CC_rnfloorH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnfloor*");
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
    v64 = stack[0];
    v64 = qcdr(v64);
    v65 = qcar(v64);
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v64 = Ldivide(nil, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    stack[0] = v64;
    v65 = qcdr(v64);
    v64 = (Lisp_Object)1; /* 0 */
    v64 = (Lisp_Object)lessp2(v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v64 = v64 ? lisp_true : nil;
    if (v64 == nil) goto v18;
    v64 = stack[0];
    v64 = qcar(v64);
    popv(2);
    return sub1(v64);

v18:
    v64 = stack[0];
    v64 = qcar(v64);
    { popv(2); return onevalue(v64); }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for multsqpf */

static Lisp_Object CC_multsqpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multsqpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v10;

v10:
    v37 = stack[-1];
    if (v37 == nil) goto v22;
    v37 = stack[-2];
    v37 = qcar(v37);
    if (v37 == nil) goto v22;
    v37 = stack[-1];
    v37 = qcar(v37);
    stack[0] = qcar(v37);
    v35 = stack[-2];
    v37 = stack[-1];
    v37 = qcar(v37);
    v37 = qcdr(v37);
    fn = elt(env, 1); /* multsq */
    v35 = (*qfn2(fn))(qenv(fn), v35, v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    v37 = stack[-3];
    v37 = acons(stack[0], v35, v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    stack[-3] = v37;
    v37 = stack[-1];
    v37 = qcdr(v37);
    stack[-1] = v37;
    goto v10;

v22:
    v37 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v37);
    }
/* error exit handlers */
v45:
    popv(5);
    return nil;
}



/* Code for let2 */

static Lisp_Object MS_CDECL CC_let2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v6,
                         Lisp_Object v7, Lisp_Object v73, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124, v125, v126, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "let2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let2");
#endif
    if (stack >= stacklimit)
    {
        push4(v73,v7,v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v6,v7,v73);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v73;
    stack[-4] = v7;
    stack[-5] = v6;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    v123 = stack[-6];
    fn = elt(env, 14); /* getrtype */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-1] = v123;
    if (v123 == nil) goto v23;
    v124 = stack[-1];
    v123 = elt(env, 1); /* typeletfn */
    v123 = get(v124, v123);
    env = stack[-8];
    v125 = v123;
    if (v123 == nil) goto v23;
    v124 = v125;
    v123 = elt(env, 2); /* direct */
    v123 = Lflagp(nil, v124, v123);
    env = stack[-8];
    if (v123 == nil) goto v23;
    stack[-2] = v125;
    stack[-4] = stack[-6];
    stack[0] = stack[-5];
    v123 = stack[-5];
    fn = elt(env, 14); /* getrtype */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    v123 = list2(stack[-3], v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    v123 = list3star(stack[-4], stack[0], stack[-1], v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    {
        Lisp_Object v129 = stack[-2];
        popv(9);
        fn = elt(env, 15); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v129, v123);
    }

v23:
    v123 = stack[-5];
    fn = elt(env, 14); /* getrtype */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-1] = v123;
    if (v123 == nil) goto v130;
    v124 = stack[-1];
    v123 = elt(env, 1); /* typeletfn */
    v123 = get(v124, v123);
    env = stack[-8];
    v125 = v123;
    if (v123 == nil) goto v130;
    v124 = v125;
    v123 = elt(env, 2); /* direct */
    v123 = Lflagp(nil, v124, v123);
    env = stack[-8];
    if (v123 == nil) goto v130;
    stack[-2] = v125;
    stack[-4] = stack[-6];
    stack[0] = qvalue(elt(env, 3)); /* nil */
    v124 = stack[-3];
    v123 = stack[-1];
    v123 = list2(v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    v123 = list3star(stack[-4], stack[-5], stack[0], v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    {
        Lisp_Object v131 = stack[-2];
        popv(9);
        fn = elt(env, 15); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v131, v123);
    }

v130:
    v124 = qvalue(elt(env, 4)); /* frasc!* */
    v123 = stack[-6];
    v123 = Lsubla(nil, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-2] = v123;
    v124 = stack[-2];
    v123 = stack[-6];
    if (equal(v124, v123)) goto v132;
    v123 = stack[-2];
    if (!consp(v123)) goto v133;
    v123 = qvalue(elt(env, 5)); /* t */
    stack[-7] = v123;
    v123 = stack[-2];
    stack[-6] = v123;
    goto v132;

v132:
    v124 = qvalue(elt(env, 4)); /* frasc!* */
    v123 = stack[-5];
    v123 = Lsubla(nil, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-2] = v123;
    v124 = stack[-2];
    v123 = stack[-5];
    if (equal(v124, v123)) goto v134;
    v123 = stack[-2];
    stack[-5] = v123;
    v124 = stack[-5];
    v123 = elt(env, 6); /* !*sq!* */
    if (!consp(v124)) goto v134;
    v124 = qcar(v124);
    if (!(v124 == v123)) goto v134;
    v123 = stack[-5];
    v123 = qcdr(v123);
    v123 = qcar(v123);
    fn = elt(env, 16); /* prepsq!* */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-5] = v123;
    goto v134;

v134:
    v124 = qvalue(elt(env, 7)); /* frlis!* */
    v123 = qvalue(elt(env, 8)); /* mcond!* */
    fn = elt(env, 17); /* smemql */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-2] = v123;
    v124 = qvalue(elt(env, 7)); /* frlis!* */
    v123 = stack[-6];
    fn = elt(env, 17); /* smemql */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-1] = v123;
    v124 = stack[-2];
    v123 = stack[-1];
    fn = elt(env, 18); /* setdiff */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    v125 = v123;
    if (!(v123 == nil)) goto v135;
    v124 = qvalue(elt(env, 7)); /* frlis!* */
    v123 = stack[-5];
    fn = elt(env, 17); /* smemql */
    v124 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    v123 = stack[-2];
    fn = elt(env, 18); /* setdiff */
    stack[0] = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    v124 = stack[-1];
    v123 = stack[-2];
    fn = elt(env, 18); /* setdiff */
    v123 = (*qfn2(fn))(qenv(fn), v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    fn = elt(env, 18); /* setdiff */
    v123 = (*qfn2(fn))(qenv(fn), stack[0], v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    v125 = v123;
    if (!(v123 == nil)) goto v135;
    v123 = stack[-6];
    if (!consp(v123)) goto v136;
    v123 = stack[-6];
    v124 = qcar(v123);
    v123 = elt(env, 12); /* getel */
    if (v124 == v123) goto v137;
    v123 = stack[-6];
    v124 = qcar(v123);
    v123 = elt(env, 13); /* immediate */
    v123 = Lflagp(nil, v124, v123);
    env = stack[-8];
    if (v123 == nil) goto v136;
    v123 = stack[-6];
    fn = elt(env, 19); /* reval */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-6] = v123;
    goto v136;

v136:
    v127 = stack[-6];
    v126 = stack[-5];
    v125 = stack[-4];
    v124 = stack[-3];
    v123 = stack[-7];
    {
        popv(9);
        fn = elt(env, 20); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v127, v126, v125, v124, v123);
    }

v137:
    v123 = stack[-6];
    v123 = qcdr(v123);
    v123 = qcar(v123);
    fn = elt(env, 21); /* lispeval */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    stack[-6] = v123;
    goto v136;

v135:
    v123 = elt(env, 9); /* "Unmatched free variable(s)" */
    v124 = v125;
    v123 = cons(v123, v124);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    fn = elt(env, 22); /* lprie */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-8];
    v123 = elt(env, 10); /* hold */
    qvalue(elt(env, 11)) = v123; /* erfg!* */
    v123 = qvalue(elt(env, 3)); /* nil */
    { popv(9); return onevalue(v123); }

v133:
    v123 = stack[-6];
    {
        popv(9);
        fn = elt(env, 23); /* errpri1 */
        return (*qfn1(fn))(qenv(fn), v123);
    }
/* error exit handlers */
v128:
    popv(9);
    return nil;
}



/* Code for simplog */

static Lisp_Object CC_simplog(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simplog");
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
    v30 = qcdr(v61);
    v61 = elt(env, 0); /* simplog */
    fn = elt(env, 6); /* carx */
    v61 = (*qfn2(fn))(qenv(fn), v30, v61);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    stack[-1] = v61;
    v61 = qvalue(elt(env, 1)); /* !*expandlogs */
    if (v61 == nil) goto v68;
    v61 = qvalue(elt(env, 2)); /* nil */
    stack[0] = qvalue(elt(env, 1)); /* !*expandlogs */
    qvalue(elt(env, 1)) = v61; /* !*expandlogs */
    v61 = stack[-1];
    fn = elt(env, 7); /* simplogi */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    fn = elt(env, 8); /* resimp */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[0]; /* !*expandlogs */
    { popv(3); return onevalue(v61); }

v68:
    v30 = stack[-1];
    v61 = elt(env, 3); /* quotient */
    if (!consp(v30)) goto v44;
    v30 = qcar(v30);
    if (!(v30 == v61)) goto v44;
    v61 = stack[-1];
    v61 = qcdr(v61);
    v30 = qcar(v61);
    v61 = (Lisp_Object)17; /* 1 */
    if (!(v30 == v61)) goto v44;
    v61 = qvalue(elt(env, 4)); /* !*precise */
    if (v61 == nil) goto v58;
    v61 = stack[-1];
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = qcar(v61);
    fn = elt(env, 9); /* realvaluedp */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    if (!(v61 == nil)) goto v58;

v44:
    v61 = stack[0];
    {
        popv(3);
        fn = elt(env, 10); /* simpiden */
        return (*qfn1(fn))(qenv(fn), v61);
    }

v58:
    v30 = elt(env, 5); /* log */
    v61 = stack[-1];
    v61 = qcdr(v61);
    v61 = qcdr(v61);
    v61 = cons(v30, v61);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    fn = elt(env, 10); /* simpiden */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 11); /* negsq */
        return (*qfn1(fn))(qenv(fn), v61);
    }
/* error exit handlers */
v20:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[0]; /* !*expandlogs */
    popv(3);
    return nil;
v19:
    popv(3);
    return nil;
}



/* Code for !*s2arg */

static Lisp_Object CC_Hs2arg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v71, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *s2arg");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v6;
    v71 = v0;
/* end of prologue */
    v142 = v71;
    if (!consp(v142)) { popv(6); return onevalue(v71); }
    v142 = v71;
    v143 = qcar(v142);
    v142 = elt(env, 1); /* quote */
    if (v143 == v142) { popv(6); return onevalue(v71); }
    v142 = v71;
    v142 = qcar(v142);
    if (!(symbolp(v142))) goto v3;
    v142 = v71;
    v143 = qcar(v142);
    v142 = elt(env, 2); /* nochange */
    v142 = Lflagp(nil, v143, v142);
    env = stack[-5];
    if (v142 == nil) goto v3;
    v142 = stack[-3];
    {
        popv(6);
        fn = elt(env, 4); /* mkarg */
        return (*qfn2(fn))(qenv(fn), v71, v142);
    }

v3:
    v142 = v71;
    stack[-4] = v142;
    v142 = stack[-4];
    if (v142 == nil) goto v121;
    v142 = stack[-4];
    v142 = qcar(v142);
    v71 = v142;
    v142 = stack[-3];
    v142 = CC_Hs2arg(env, v71, v142);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    stack[-1] = v142;
    stack[-2] = v142;
    goto v144;

v144:
    v142 = stack[-4];
    v142 = qcdr(v142);
    stack[-4] = v142;
    v142 = stack[-4];
    if (v142 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v142 = stack[-4];
    v142 = qcar(v142);
    v71 = v142;
    v142 = stack[-3];
    v142 = CC_Hs2arg(env, v71, v142);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    v142 = Lrplacd(nil, stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-5];
    v142 = stack[-1];
    v142 = qcdr(v142);
    stack[-1] = v142;
    goto v144;

v121:
    v142 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v142); }
/* error exit handlers */
v115:
    popv(6);
    return nil;
}



/* Code for calc_world */

static Lisp_Object CC_calc_world(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_world");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = stack[-1];
    v44 = stack[-2];
    fn = elt(env, 1); /* s_world_names */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    fn = elt(env, 2); /* actual_alst */
    v44 = (*qfn2(fn))(qenv(fn), stack[0], v44);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    stack[-1] = v44;
    v44 = stack[-2];
    v44 = qcdr(v44);
    v44 = qcar(v44);
    stack[0] = v44;
    v13 = stack[-1];
    v44 = stack[0];
    v44 = qcdr(v44);
    v44 = Lassoc(nil, v13, v44);
    stack[-3] = v44;
    v44 = stack[-3];
    if (v44 == nil) goto v33;
    v44 = stack[-3];
    v44 = qcdr(v44);
    { popv(5); return onevalue(v44); }

v33:
    v44 = stack[-2];
    v44 = qcdr(v44);
    v44 = qcdr(v44);
    v13 = qcar(v44);
    v44 = stack[-1];
    fn = elt(env, 3); /* calc_atlas */
    v44 = (*qfn2(fn))(qenv(fn), v13, v44);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    fn = elt(env, 4); /* reval */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    stack[-3] = v44;
    v13 = stack[-1];
    v44 = stack[-3];
    v44 = cons(v13, v44);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-4];
    v44 = Lnconc(nil, stack[0], v44);
    nil = C_nil;
    if (exception_pending()) goto v31;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v31:
    popv(5);
    return nil;
}



/* Code for hdiff */

static Lisp_Object CC_hdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v0;
/* end of prologue */
    v74 = stack[-1];
    if (v74 == nil) goto v15;
    v66 = stack[-1];
    v74 = (Lisp_Object)49; /* 3 */
    v66 = *(Lisp_Object *)((char *)v66 + (CELL-TAG_VECTOR) + ((int32_t)v74/(16/CELL)));
    v74 = stack[0];
    stack[-2] = CC_hdiff(env, v66, v74);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    v66 = stack[-1];
    v74 = stack[0];
    fn = elt(env, 2); /* hdiffterm */
    v74 = (*qfn2(fn))(qenv(fn), v66, v74);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-3];
    {
        Lisp_Object v52 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v52, v74);
    }

v15:
    v74 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v74); }
/* error exit handlers */
v35:
    popv(4);
    return nil;
}



/* Code for sep_tens_from_other */

static Lisp_Object CC_sep_tens_from_other(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sep_tens_from_other");
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
    stack[-4] = nil;
    v155 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 2); /* !*n2f */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-2] = v155;
    goto v51;

v51:
    v155 = stack[-3];
    if (is_number(v155)) goto v1;
    v155 = stack[-3];
    v155 = qcar(v155);
    v155 = qcar(v155);
    v155 = qcar(v155);
    if (!consp(v155)) goto v74;
    v155 = stack[-3];
    v155 = qcar(v155);
    v155 = qcar(v155);
    v155 = qcar(v155);
    v156 = qcar(v155);
    v155 = elt(env, 1); /* translate1 */
    v155 = get(v156, v155);
    env = stack[-5];
    stack[-1] = v155;
    if (v155 == nil) goto v36;
    v155 = stack[-3];
    fn = elt(env, 3); /* fullcopy */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-3] = v155;
    v155 = stack[-3];
    v155 = qcar(v155);
    stack[0] = qcar(v155);
    v156 = stack[-1];
    v155 = stack[-3];
    v155 = qcar(v155);
    v155 = qcar(v155);
    v155 = qcar(v155);
    v155 = Lapply1(nil, v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    fn = elt(env, 4); /* setcar */
    v155 = (*qfn2(fn))(qenv(fn), stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    goto v36;

v36:
    v155 = stack[-3];
    v155 = qcar(v155);
    v155 = qcar(v155);
    v155 = qcar(v155);
    stack[0] = v155;
    fn = elt(env, 5); /* tensorp */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    if (v155 == nil) goto v158;
    v155 = stack[0];
    fn = elt(env, 6); /* no_dum_varp */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    if (v155 == nil) goto v159;
    v155 = stack[0];
    v155 = qcar(v155);
    if (!symbolp(v155)) v155 = nil;
    else { v155 = qfastgets(v155);
           if (v155 != nil) { v155 = elt(v155, 0); /* noncom */
#ifdef RECORD_GET
             if (v155 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v155 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v155 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v155 == SPID_NOPROP) v155 = nil; else v155 = lisp_true; }}
#endif
    if (!(v155 == nil)) goto v159;
    stack[0] = stack[-2];
    v155 = stack[-3];
    v155 = qcar(v155);
    v156 = qcar(v155);
    v155 = (Lisp_Object)17; /* 1 */
    v155 = cons(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v155 = (*qfn2(fn))(qenv(fn), stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-2] = v155;
    goto v56;

v56:
    v155 = stack[-3];
    v155 = qcar(v155);
    v155 = qcdr(v155);
    stack[-3] = v155;
    goto v51;

v159:
    v155 = stack[-3];
    v155 = qcar(v155);
    v155 = qcar(v155);
    v156 = qcar(v155);
    v155 = stack[-4];
    v155 = cons(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-4] = v155;
    goto v56;

v158:
    stack[0] = stack[-2];
    v155 = stack[-3];
    v155 = qcar(v155);
    v156 = qcar(v155);
    v155 = (Lisp_Object)17; /* 1 */
    v155 = cons(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v155 = (*qfn2(fn))(qenv(fn), stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-2] = v155;
    goto v56;

v74:
    stack[0] = stack[-2];
    v155 = stack[-3];
    v155 = qcar(v155);
    v156 = qcar(v155);
    v155 = (Lisp_Object)17; /* 1 */
    v155 = cons(v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v155 = (*qfn2(fn))(qenv(fn), stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    stack[-2] = v155;
    goto v56;

v1:
    v155 = stack[-4];
    stack[0] = Lnreverse(nil, v155);
    env = stack[-5];
    stack[-1] = stack[-2];
    v155 = stack[-3];
    fn = elt(env, 2); /* !*n2f */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-5];
    fn = elt(env, 7); /* multf */
    v155 = (*qfn2(fn))(qenv(fn), stack[-1], v155);
    nil = C_nil;
    if (exception_pending()) goto v157;
    {
        Lisp_Object v160 = stack[0];
        popv(6);
        return list2(v160, v155);
    }
/* error exit handlers */
v157:
    popv(6);
    return nil;
}



/* Code for sc_repkern */

static Lisp_Object CC_sc_repkern(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v127, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_repkern");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v6;
    v127 = v0;
/* end of prologue */
    v126 = v127;
    v189 = qcar(v126);
    v126 = elt(env, 1); /* !* */
    if (v189 == v126) goto v15;
    stack[-1] = nil;
    stack[-6] = nil;
    stack[-4] = nil;
    v126 = v127;
    v126 = qcdr(v126);
    v127 = v126;
    v126 = v127;
    stack[-2] = v126;
    goto v132;

v132:
    v126 = stack[-2];
    if (v126 == nil) goto v97;
    v126 = stack[-2];
    v126 = qcar(v126);
    v127 = v126;
    v189 = v127;
    v126 = stack[-1];
    v126 = Lassoc(nil, v189, v126);
    v189 = v126;
    if (v126 == nil) goto v134;
    stack[0] = v189;
    v126 = v189;
    v126 = qcdr(v126);
    v126 = add1(v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v126 = Lrplacd(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    goto v190;

v190:
    v126 = stack[-2];
    v126 = qcdr(v126);
    stack[-2] = v126;
    goto v132;

v134:
    v189 = v127;
    v127 = (Lisp_Object)17; /* 1 */
    v126 = stack[-1];
    v126 = acons(v189, v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-1] = v126;
    goto v190;

v97:
    v127 = stack[-1];
    v126 = elt(env, 3); /* lambda_l73kgz_9 */
    fn = elt(env, 4); /* sort */
    v126 = (*qfn2(fn))(qenv(fn), v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-1] = v126;
    v126 = (Lisp_Object)1; /* 0 */
    stack[-3] = v126;
    v126 = stack[-1];
    stack[-2] = v126;
    goto v191;

v191:
    v126 = stack[-2];
    if (v126 == nil) goto v192;
    v126 = stack[-2];
    v126 = qcar(v126);
    stack[-1] = v126;
    v126 = stack[-1];
    v127 = qcdr(v126);
    v126 = stack[-3];
    if (equal(v127, v126)) goto v193;
    v126 = stack[-1];
    v189 = qcdr(v126);
    v127 = (Lisp_Object)17; /* 1 */
    v126 = stack[-6];
    v126 = acons(v189, v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-6] = v126;
    v126 = stack[-1];
    v126 = qcar(v126);
    v127 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v126 = stack[-4];
    v126 = cons(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-4] = v126;
    v126 = stack[-1];
    v126 = qcdr(v126);
    stack[-3] = v126;
    goto v194;

v194:
    v126 = stack[-2];
    v126 = qcdr(v126);
    stack[-2] = v126;
    goto v191;

v193:
    v126 = stack[-6];
    stack[0] = qcar(v126);
    v126 = stack[-6];
    v126 = qcar(v126);
    v126 = qcdr(v126);
    v126 = add1(v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v126 = Lrplacd(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[0] = stack[-4];
    v126 = stack[-1];
    v127 = qcar(v126);
    v126 = stack[-4];
    v126 = qcar(v126);
    v126 = cons(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v126 = Lrplaca(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    goto v194;

v192:
    stack[0] = stack[-6];
    v127 = stack[-4];
    v126 = stack[-5];
    fn = elt(env, 5); /* pa_list2vect */
    v126 = (*qfn2(fn))(qenv(fn), v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    {
        Lisp_Object v129 = stack[0];
        popv(8);
        return list2(v129, v126);
    }

v15:
    stack[-6] = nil;
    v126 = v127;
    v126 = qcdr(v126);
    stack[0] = v126;
    v126 = (Lisp_Object)1; /* 0 */
    stack[-2] = v126;
    goto v18;

v18:
    v126 = stack[0];
    if (v126 == nil) goto v130;
    v126 = stack[0];
    v126 = qcar(v126);
    stack[-3] = v126;
    v126 = stack[-3];
    v127 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v126 = stack[-6];
    v126 = cons(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-6] = v126;
    v126 = stack[0];
    v126 = qcdr(v126);
    stack[0] = v126;
    v126 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v126;
    v127 = stack[-2];
    v126 = (Lisp_Object)33; /* 2 */
    v126 = times2(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v126 = add1(v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-2] = v126;
    v126 = stack[0];
    stack[-1] = v126;
    goto v42;

v42:
    v126 = stack[-1];
    if (v126 == nil) goto v41;
    v126 = stack[-1];
    v126 = qcar(v126);
    stack[0] = v126;
    v127 = stack[0];
    v126 = stack[-3];
    if (v127 == v126) goto v60;
    v127 = stack[-2];
    v126 = (Lisp_Object)33; /* 2 */
    v126 = times2(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-2] = v126;
    v127 = stack[0];
    v126 = stack[-4];
    v126 = cons(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-4] = v126;
    goto v21;

v21:
    v126 = stack[-1];
    v126 = qcdr(v126);
    stack[-1] = v126;
    goto v42;

v60:
    v127 = stack[-2];
    v126 = (Lisp_Object)33; /* 2 */
    v126 = times2(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v126 = add1(v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[-2] = v126;
    goto v21;

v41:
    v126 = stack[-4];
    v126 = Lreverse(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    stack[0] = v126;
    goto v18;

v130:
    stack[0] = stack[-2];
    v126 = stack[-6];
    v127 = Lreverse(nil, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-7];
    v126 = stack[-5];
    fn = elt(env, 5); /* pa_list2vect */
    v126 = (*qfn2(fn))(qenv(fn), v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v128;
    {
        Lisp_Object v131 = stack[0];
        popv(8);
        return list2(v131, v126);
    }
/* error exit handlers */
v128:
    popv(8);
    return nil;
}



/* Code for lambda_l73kgz_9 */

static Lisp_Object CC_lambda_l73kgz_9(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l73kgz_9");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v6;
    v23 = v0;
/* end of prologue */
    v23 = qcdr(v23);
    v72 = qcdr(v72);
        return Lleq(nil, v23, v72);
}



/* Code for general!-difference!-mod!-p */

static Lisp_Object CC_generalKdifferenceKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-difference-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v56 = v6;
    v72 = v0;
/* end of prologue */
    stack[0] = v72;
    fn = elt(env, 1); /* general!-minus!-mod!-p */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-1];
    {
        Lisp_Object v2 = stack[0];
        popv(2);
        fn = elt(env, 2); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v2, v56);
    }
/* error exit handlers */
v40:
    popv(2);
    return nil;
}



/* Code for cl_simpl1 */

static Lisp_Object MS_CDECL CC_cl_simpl1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v6,
                         Lisp_Object v7, Lisp_Object v73, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v276, v277, v278, v279;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_simpl1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_simpl1");
#endif
    if (stack >= stacklimit)
    {
        push4(v73,v7,v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v6,v7,v73);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v73;
    stack[-1] = v7;
    stack[-2] = v6;
    stack[-3] = v0;
/* end of prologue */
    v277 = stack[-1];
    v276 = (Lisp_Object)1; /* 0 */
    v276 = Leqn(nil, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    if (!(v276 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v276 = stack[-3];
    if (!consp(v276)) goto v68;
    v276 = stack[-3];
    v276 = qcar(v276);
    goto v55;

v55:
    stack[-4] = v276;
    v277 = stack[-4];
    v276 = elt(env, 1); /* true */
    if (v277 == v276) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v277 = stack[-4];
    v276 = elt(env, 2); /* false */
    if (v277 == v276) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v277 = stack[-4];
    v276 = elt(env, 3); /* or */
    if (v277 == v276) goto v62;
    v277 = stack[-4];
    v276 = elt(env, 4); /* and */
    if (v277 == v276) goto v62;
    v277 = stack[-4];
    v276 = elt(env, 5); /* not */
    if (v277 == v276) goto v281;
    v277 = stack[-4];
    v276 = elt(env, 6); /* ex */
    if (v277 == v276) goto v177;
    v277 = stack[-4];
    v276 = elt(env, 7); /* all */
    if (v277 == v276) goto v177;
    v277 = stack[-4];
    v276 = elt(env, 9); /* bex */
    if (v277 == v276) goto v75;
    v277 = stack[-4];
    v276 = elt(env, 10); /* ball */
    if (v277 == v276) goto v75;
    v277 = stack[-4];
    v276 = elt(env, 11); /* impl */
    if (v277 == v276) goto v282;
    v277 = stack[-4];
    v276 = elt(env, 12); /* repl */
    if (v277 == v276) goto v283;
    v277 = stack[-4];
    v276 = elt(env, 13); /* equiv */
    if (v277 == v276) goto v284;
    v277 = stack[-3];
    v276 = stack[0];
    fn = elt(env, 15); /* cl_simplat */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v277 = v276;
    v276 = qvalue(elt(env, 8)); /* !*rlsism */
    if (v276 == nil) goto v285;
    v276 = v277;
    if (!consp(v276)) goto v286;
    v276 = v277;
    v276 = qcar(v276);
    goto v287;

v287:
    stack[-4] = v276;
    v278 = stack[-4];
    v276 = elt(env, 3); /* or */
    if (v278 == v276) goto v288;
    v278 = stack[-4];
    v276 = elt(env, 4); /* and */
    if (v278 == v276) goto v288;
    v278 = stack[-4];
    v276 = elt(env, 1); /* true */
    if (v278 == v276) { popv(6); return onevalue(v277); }
    v278 = stack[-4];
    v276 = elt(env, 2); /* false */
    if (v278 == v276) { popv(6); return onevalue(v277); }
    stack[-3] = elt(env, 4); /* and */
    v276 = v277;
    stack[0] = ncons(v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v276 = stack[-2];
    fn = elt(env, 16); /* rl_smcpknowl */
    v277 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v276 = stack[-1];
    fn = elt(env, 17); /* rl_smupdknowl */
    v276 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[0], v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v278 = v276;
    v277 = elt(env, 2); /* false */
    if (v278 == v277) goto v289;
    v279 = elt(env, 4); /* and */
    v278 = stack[-2];
    v277 = v276;
    v276 = stack[-1];
    fn = elt(env, 18); /* rl_smmkatl */
    v276 = (*qfnn(fn))(qenv(fn), 4, v279, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v277 = v276;
    v276 = v277;
    if (v276 == nil) goto v290;
    v276 = v277;
    v276 = qcdr(v276);
    if (v276 == nil) goto v290;
    v276 = elt(env, 4); /* and */
    popv(6);
    return cons(v276, v277);

v290:
    v276 = v277;
    if (v276 == nil) goto v291;
    v276 = v277;
    v276 = qcar(v276);
    { popv(6); return onevalue(v276); }

v291:
    v277 = elt(env, 4); /* and */
    v276 = elt(env, 4); /* and */
    if (v277 == v276) goto v292;
    v276 = elt(env, 2); /* false */
    { popv(6); return onevalue(v276); }

v292:
    v276 = elt(env, 1); /* true */
    { popv(6); return onevalue(v276); }

v289:
    v276 = elt(env, 2); /* false */
    { popv(6); return onevalue(v276); }

v288:
    v279 = stack[-4];
    v276 = v277;
    v278 = qcdr(v276);
    v277 = stack[-2];
    v276 = stack[-1];
    fn = elt(env, 19); /* cl_smsimpl!-junct */
    v276 = (*qfnn(fn))(qenv(fn), 4, v279, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v277 = v276;
    v276 = v277;
    if (v276 == nil) goto v293;
    v276 = v277;
    v276 = qcdr(v276);
    if (v276 == nil) goto v293;
    v276 = stack[-4];
    popv(6);
    return cons(v276, v277);

v293:
    v276 = v277;
    if (v276 == nil) goto v294;
    v276 = v277;
    v276 = qcar(v276);
    { popv(6); return onevalue(v276); }

v294:
    v277 = stack[-4];
    v276 = elt(env, 4); /* and */
    if (v277 == v276) goto v295;
    v276 = elt(env, 2); /* false */
    { popv(6); return onevalue(v276); }

v295:
    v276 = elt(env, 1); /* true */
    { popv(6); return onevalue(v276); }

v286:
    v276 = v277;
    goto v287;

v285:
    v276 = v277;
    if (!(v276 == nil)) { popv(6); return onevalue(v277); }
    v277 = elt(env, 14); /* "cl_simpl1(): unknown operator" */
    v276 = stack[-4];
    v276 = list2(v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    fn = elt(env, 20); /* rederr */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    v276 = nil;
    { popv(6); return onevalue(v276); }

v284:
    v276 = stack[-3];
    v276 = qcdr(v276);
    v279 = qcar(v276);
    v276 = stack[-3];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v278 = qcar(v276);
    v277 = stack[-2];
    v276 = stack[-1];
    {
        popv(6);
        fn = elt(env, 21); /* cl_smsimpl!-equiv */
        return (*qfnn(fn))(qenv(fn), 4, v279, v278, v277, v276);
    }

v283:
    v276 = stack[-3];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v279 = qcar(v276);
    v276 = stack[-3];
    v276 = qcdr(v276);
    v278 = qcar(v276);
    v277 = stack[-2];
    v276 = stack[-1];
    {
        popv(6);
        fn = elt(env, 22); /* cl_smsimpl!-imprep */
        return (*qfnn(fn))(qenv(fn), 4, v279, v278, v277, v276);
    }

v282:
    v276 = stack[-3];
    v276 = qcdr(v276);
    v279 = qcar(v276);
    v276 = stack[-3];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    v278 = qcar(v276);
    v277 = stack[-2];
    v276 = stack[-1];
    {
        popv(6);
        fn = elt(env, 22); /* cl_smsimpl!-imprep */
        return (*qfnn(fn))(qenv(fn), 4, v279, v278, v277, v276);
    }

v75:
    v276 = qvalue(elt(env, 8)); /* !*rlsism */
    if (v276 == nil) goto v296;
    v277 = stack[-2];
    v276 = stack[-3];
    v276 = qcdr(v276);
    v276 = qcar(v276);
    fn = elt(env, 23); /* rl_smrmknowl */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    stack[-2] = v276;
    goto v296;

v296:
    v278 = stack[-3];
    v277 = stack[-2];
    v276 = stack[-1];
    {
        popv(6);
        fn = elt(env, 24); /* cl_simplbq */
        return (*qfnn(fn))(qenv(fn), 3, v278, v277, v276);
    }

v177:
    v276 = qvalue(elt(env, 8)); /* !*rlsism */
    if (v276 == nil) goto v297;
    v277 = stack[-2];
    v276 = stack[-3];
    v276 = qcdr(v276);
    v276 = qcar(v276);
    fn = elt(env, 23); /* rl_smrmknowl */
    v276 = (*qfn2(fn))(qenv(fn), v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    stack[-2] = v276;
    goto v297;

v297:
    v276 = stack[-3];
    v276 = qcdr(v276);
    v276 = qcdr(v276);
    stack[0] = qcar(v276);
    v276 = stack[-1];
    v277 = sub1(v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v276 = stack[-4];
    v276 = CC_cl_simpl1(env, 4, stack[0], stack[-2], v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    stack[-1] = v276;
    v277 = stack[-1];
    v276 = elt(env, 1); /* true */
    if (v277 == v276) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v277 = stack[-1];
    v276 = elt(env, 2); /* false */
    if (v277 == v276) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v276 = stack[-3];
    v276 = qcdr(v276);
    stack[0] = qcar(v276);
    v276 = stack[-1];
    fn = elt(env, 25); /* cl_fvarl */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    v276 = Lmemq(nil, stack[0], v276);
    if (v276 == nil) { Lisp_Object res = stack[-1]; popv(6); return onevalue(res); }
    v278 = stack[-4];
    v276 = stack[-3];
    v276 = qcdr(v276);
    v277 = qcar(v276);
    v276 = stack[-1];
    popv(6);
    return list3(v278, v277, v276);

v281:
    v276 = stack[-3];
    v276 = qcdr(v276);
    stack[0] = qcar(v276);
    v276 = stack[-1];
    v277 = sub1(v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v276 = elt(env, 5); /* not */
    v276 = CC_cl_simpl1(env, 4, stack[0], stack[-2], v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    stack[-1] = v276;
    v277 = stack[-1];
    v276 = elt(env, 1); /* true */
    if (v277 == v276) goto v298;
    v277 = stack[-1];
    v276 = elt(env, 2); /* false */
    if (v277 == v276) goto v298;
    v276 = stack[-1];
    fn = elt(env, 26); /* cl_atfp */
    v276 = (*qfn1(fn))(qenv(fn), v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    if (v276 == nil) goto v299;
    v276 = stack[-1];
    {
        popv(6);
        fn = elt(env, 27); /* rl_negateat */
        return (*qfn1(fn))(qenv(fn), v276);
    }

v299:
    v276 = stack[-1];
    {
        popv(6);
        fn = elt(env, 28); /* cl_negate!-invol */
        return (*qfn1(fn))(qenv(fn), v276);
    }

v298:
    v276 = stack[-1];
    {
        popv(6);
        fn = elt(env, 29); /* cl_flip */
        return (*qfn1(fn))(qenv(fn), v276);
    }

v62:
    v279 = stack[-4];
    v276 = stack[-3];
    v278 = qcdr(v276);
    v277 = stack[-2];
    v276 = stack[-1];
    fn = elt(env, 19); /* cl_smsimpl!-junct */
    v276 = (*qfnn(fn))(qenv(fn), 4, v279, v278, v277, v276);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-5];
    v277 = v276;
    v276 = v277;
    if (v276 == nil) goto v111;
    v276 = v277;
    v276 = qcdr(v276);
    if (v276 == nil) goto v111;
    v276 = stack[-4];
    popv(6);
    return cons(v276, v277);

v111:
    v276 = v277;
    if (v276 == nil) goto v118;
    v276 = v277;
    v276 = qcar(v276);
    { popv(6); return onevalue(v276); }

v118:
    v277 = stack[-4];
    v276 = elt(env, 4); /* and */
    if (v277 == v276) goto v300;
    v276 = elt(env, 2); /* false */
    { popv(6); return onevalue(v276); }

v300:
    v276 = elt(env, 1); /* true */
    { popv(6); return onevalue(v276); }

v68:
    v276 = stack[-3];
    goto v55;
/* error exit handlers */
v280:
    popv(6);
    return nil;
}



/* Code for girationalize!: */

static Lisp_Object CC_girationalizeT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v143, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for girationalize:");
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
    stack[-5] = nil;
    stack[-3] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v71 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v71; /* !*gcd */
    stack[-1] = stack[-5];
    v71 = stack[-4];
    v71 = qcdr(v71);
    stack[-5] = v71;
    fn = elt(env, 4); /* conjgd */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[0] = v71;
    if (equal(stack[-1], v71)) goto v25;
    stack[-2] = stack[0];
    v143 = stack[-5];
    v71 = stack[0];
    fn = elt(env, 5); /* addf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v143, v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v71 = stack[-5];
    fn = elt(env, 6); /* negf */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    fn = elt(env, 5); /* addf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v185 = elt(env, 3); /* !:gi!: */
    v143 = (Lisp_Object)1; /* 0 */
    v71 = (Lisp_Object)17; /* 1 */
    v71 = list2star(v185, v143, v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    fn = elt(env, 7); /* multf */
    v71 = (*qfn2(fn))(qenv(fn), stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    fn = elt(env, 8); /* gcdf */
    v143 = (*qfn2(fn))(qenv(fn), stack[-1], v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v71 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* quotf */
    v71 = (*qfn2(fn))(qenv(fn), v143, v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    fn = elt(env, 9); /* quotf */
    v71 = (*qfn2(fn))(qenv(fn), stack[-2], v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[0] = v71;
    v71 = stack[-4];
    v143 = qcar(v71);
    v71 = stack[0];
    fn = elt(env, 7); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v143, v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v143 = stack[-5];
    v71 = stack[0];
    fn = elt(env, 7); /* multf */
    v71 = (*qfn2(fn))(qenv(fn), v143, v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    fn = elt(env, 10); /* gigcdsq */
    v71 = (*qfn2(fn))(qenv(fn), stack[-1], v71);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v10;

v10:
    qvalue(elt(env, 1)) = stack[-3]; /* !*gcd */
    { popv(7); return onevalue(v71); }

v25:
    v71 = stack[-4];
    goto v10;
/* error exit handlers */
v114:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-3]; /* !*gcd */
    popv(7);
    return nil;
}



/* Code for uterm */

static Lisp_Object CC_uterm(Lisp_Object env,
                         Lisp_Object v6, Lisp_Object v7)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for uterm");
#endif
    if (stack >= stacklimit)
    {
        push2(v7,v6);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v6,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v69 = v7;
    stack[-1] = v6;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* rhs!* */
    qvalue(elt(env, 1)) = nil; /* rhs!* */
    qvalue(elt(env, 1)) = v69; /* rhs!* */
    v69 = qvalue(elt(env, 1)); /* rhs!* */
    if (v69 == nil) goto v25;
    v70 = stack[-1];
    v69 = qvalue(elt(env, 1)); /* rhs!* */
    v69 = qcar(v69);
    v69 = qcar(v69);
    fn = elt(env, 3); /* addinds */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    stack[0] = v69;
    v69 = qvalue(elt(env, 1)); /* rhs!* */
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v70 = qcar(v69);
    v69 = stack[-1];
    fn = elt(env, 4); /* evaluatecoeffts */
    v69 = (*qfn2(fn))(qenv(fn), v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    v70 = v69;
    if (v70 == nil) goto v34;
    v70 = v69;
    v69 = qvalue(elt(env, 1)); /* rhs!* */
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    v70 = stack[0];
    v69 = cons(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    stack[0] = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    v70 = stack[-1];
    v69 = qvalue(elt(env, 1)); /* rhs!* */
    v69 = qcdr(v69);
    v69 = CC_uterm(env, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    fn = elt(env, 5); /* plusdf */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    goto v10;

v10:
    qvalue(elt(env, 1)) = stack[-2]; /* rhs!* */
    { popv(4); return onevalue(v69); }

v34:
    v70 = stack[-1];
    v69 = qvalue(elt(env, 1)); /* rhs!* */
    v69 = qcdr(v69);
    v69 = CC_uterm(env, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-3];
    goto v10;

v25:
    v69 = qvalue(elt(env, 2)); /* nil */
    goto v10;
/* error exit handlers */
v112:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* rhs!* */
    popv(4);
    return nil;
}



/* Code for depend!-l */

static Lisp_Object CC_dependKl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-l");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v0;
/* end of prologue */

v15:
    v18 = stack[-1];
    if (v18 == nil) goto v51;
    v18 = stack[-1];
    v18 = qcar(v18);
    fn = elt(env, 3); /* simp */
    v16 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v18 = stack[0];
    fn = elt(env, 4); /* depend!-sq */
    v18 = (*qfn2(fn))(qenv(fn), v16, v18);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (v18 == nil) goto v55;
    v18 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v18); }

v55:
    v18 = stack[-1];
    v18 = qcdr(v18);
    stack[-1] = v18;
    goto v15;

v51:
    v18 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v18); }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for search4facf */

static Lisp_Object MS_CDECL CC_search4facf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v6,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "search4facf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for search4facf");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v6,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v7;
    stack[-3] = v6;
    stack[-4] = v0;
/* end of prologue */
    v36 = stack[-3];
    if (v36 == nil) goto v25;
    v36 = stack[-3];
    v36 = qcar(v36);
    stack[-5] = v36;
    goto v38;

v38:
    v36 = stack[-5];
    if (v36 == nil) goto v48;
    stack[-1] = stack[-4];
    v36 = stack[-3];
    stack[0] = qcdr(v36);
    v36 = stack[-5];
    v41 = qcar(v36);
    v36 = stack[-2];
    v36 = cons(v41, v36);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v36 = CC_search4facf(env, 3, stack[-1], stack[0], v36);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-6];
    v41 = v36;
    v36 = v41;
    if (!(v36 == nil)) { popv(7); return onevalue(v41); }
    v36 = stack[-5];
    v36 = qcdr(v36);
    stack[-5] = v36;
    goto v38;

v48:
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v36); }

v25:
    v41 = stack[-4];
    v36 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* tryfactorf */
        return (*qfn2(fn))(qenv(fn), v41, v36);
    }
/* error exit handlers */
v61:
    popv(7);
    return nil;
}



/* Code for setrow */

static Lisp_Object MS_CDECL CC_setrow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v6,
                         Lisp_Object v7, Lisp_Object v73,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v344, v345, v346;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "setrow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setrow");
#endif
    if (stack >= stacklimit)
    {
        push5(v5,v73,v7,v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v6,v7,v73,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v5;
    stack[-5] = v73;
    stack[-6] = v7;
    stack[-7] = v6;
    stack[-8] = v0;
/* end of prologue */
    v344 = stack[-8];
    v345 = Labsval(nil, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v344 = qvalue(elt(env, 1)); /* maxvar */
    v344 = (Lisp_Object)greaterp2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    v344 = v344 ? lisp_true : nil;
    env = stack[-10];
    if (v344 == nil) goto v273;
    v345 = (Lisp_Object)65; /* 4 */
    v344 = qvalue(elt(env, 1)); /* maxvar */
    v344 = times2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v344 = Lmkvect(nil, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    stack[-9] = v344;
    stack[0] = qvalue(elt(env, 2)); /* rowmin */
    v344 = qvalue(elt(env, 1)); /* maxvar */
    v344 = negate(v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    fn = elt(env, 7); /* max */
    v344 = (*qfn2(fn))(qenv(fn), stack[0], v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    stack[-3] = v344;
    goto v14;

v14:
    v345 = qvalue(elt(env, 3)); /* rowmax */
    v344 = qvalue(elt(env, 1)); /* maxvar */
    fn = elt(env, 8); /* min */
    v345 = (*qfn2(fn))(qenv(fn), v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v344 = stack[-3];
    v344 = difference2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v344 = Lminusp(nil, v344);
    env = stack[-10];
    if (v344 == nil) goto v13;
    v344 = stack[-9];
    qvalue(elt(env, 5)) = v344; /* codmat */
    v345 = (Lisp_Object)33; /* 2 */
    v344 = qvalue(elt(env, 1)); /* maxvar */
    v344 = times2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    qvalue(elt(env, 1)) = v344; /* maxvar */
    goto v273;

v273:
    v345 = stack[-8];
    v344 = (Lisp_Object)1; /* 0 */
    v344 = (Lisp_Object)lessp2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    v344 = v344 ? lisp_true : nil;
    env = stack[-10];
    if (v344 == nil) goto v132;
    stack[-1] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    stack[0] = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v344 = (Lisp_Object)65; /* 4 */
    v344 = Lmkvect(nil, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v344;
    goto v348;

v348:
    stack[0] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    v344 = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v346 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v344/(16/CELL)));
    v345 = (Lisp_Object)1; /* 0 */
    v344 = qvalue(elt(env, 6)); /* t */
    *(Lisp_Object *)((char *)v346 + (CELL-TAG_VECTOR) + ((int32_t)v345/(16/CELL))) = v344;
    stack[0] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    v344 = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v346 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v344/(16/CELL)));
    v345 = (Lisp_Object)33; /* 2 */
    v344 = stack[-7];
    *(Lisp_Object *)((char *)v346 + (CELL-TAG_VECTOR) + ((int32_t)v345/(16/CELL))) = v344;
    stack[0] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    v344 = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v346 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v344/(16/CELL)));
    v345 = (Lisp_Object)49; /* 3 */
    v344 = stack[-6];
    *(Lisp_Object *)((char *)v346 + (CELL-TAG_VECTOR) + ((int32_t)v345/(16/CELL))) = v344;
    stack[0] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    v344 = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    v346 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v344/(16/CELL)));
    v345 = (Lisp_Object)65; /* 4 */
    v344 = stack[-4];
    *(Lisp_Object *)((char *)v346 + (CELL-TAG_VECTOR) + ((int32_t)v345/(16/CELL))) = v344;
    v344 = nil;
    { popv(11); return onevalue(v344); }

v132:
    stack[-1] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    stack[0] = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v344 = (Lisp_Object)129; /* 8 */
    v344 = Lmkvect(nil, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v344;
    stack[0] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    v344 = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v346 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v344/(16/CELL)));
    v345 = (Lisp_Object)81; /* 5 */
    v344 = stack[-5];
    v344 = qcar(v344);
    *(Lisp_Object *)((char *)v346 + (CELL-TAG_VECTOR) + ((int32_t)v345/(16/CELL))) = v344;
    v344 = stack[-5];
    v344 = qcdr(v344);
    if (v344 == nil) goto v94;
    stack[0] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    v344 = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v346 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v344/(16/CELL)));
    v345 = (Lisp_Object)97; /* 6 */
    v344 = stack[-5];
    v344 = qcdr(v344);
    v344 = qcar(v344);
    *(Lisp_Object *)((char *)v346 + (CELL-TAG_VECTOR) + ((int32_t)v345/(16/CELL))) = v344;
    goto v348;

v94:
    stack[0] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-8];
    v344 = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v346 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v344/(16/CELL)));
    v345 = (Lisp_Object)97; /* 6 */
    v344 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v346 + (CELL-TAG_VECTOR) + ((int32_t)v345/(16/CELL))) = v344;
    goto v348;

v13:
    stack[-2] = stack[-9];
    stack[0] = stack[-3];
    v345 = (Lisp_Object)33; /* 2 */
    v344 = qvalue(elt(env, 1)); /* maxvar */
    v344 = times2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    stack[-1] = plus2(stack[0], v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    stack[0] = qvalue(elt(env, 5)); /* codmat */
    v345 = qvalue(elt(env, 1)); /* maxvar */
    v344 = stack[-3];
    v344 = plus2(v345, v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    v344 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v344/(16/CELL)));
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v344;
    v344 = stack[-3];
    v344 = add1(v344);
    nil = C_nil;
    if (exception_pending()) goto v347;
    env = stack[-10];
    stack[-3] = v344;
    goto v14;
/* error exit handlers */
v347:
    popv(11);
    return nil;
}



/* Code for !:mod!:units */

static Lisp_Object MS_CDECL CC_TmodTunits(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v6,
                         Lisp_Object v7, Lisp_Object v73, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v350, v116;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, ":mod:units");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :mod:units");
#endif
    if (stack >= stacklimit)
    {
        push4(v73,v7,v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v6,v7,v73);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v73;
    stack[-3] = v7;
    stack[-4] = v6;
    stack[-5] = v0;
/* end of prologue */

v22:
    v116 = stack[-4];
    v350 = (Lisp_Object)1; /* 0 */
    if (v116 == v350) goto v90;
    v116 = stack[-4];
    v350 = (Lisp_Object)17; /* 1 */
    if (v116 == v350) goto v17;
    v116 = stack[-5];
    v350 = stack[-4];
    v350 = quot2(v116, v350);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-7];
    stack[-6] = v350;
    stack[-1] = stack[-4];
    stack[0] = stack[-5];
    v116 = stack[-4];
    v350 = stack[-6];
    v350 = times2(v116, v350);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-7];
    stack[-4] = difference2(stack[0], v350);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-7];
    stack[0] = stack[-2];
    v116 = stack[-2];
    v350 = stack[-6];
    v350 = times2(v116, v350);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-7];
    v350 = difference2(stack[-3], v350);
    nil = C_nil;
    if (exception_pending()) goto v300;
    env = stack[-7];
    stack[-5] = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v350;
    goto v22;

v17:
    v116 = stack[-2];
    v350 = (Lisp_Object)1; /* 0 */
    v350 = (Lisp_Object)lessp2(v116, v350);
    nil = C_nil;
    if (exception_pending()) goto v300;
    v350 = v350 ? lisp_true : nil;
    env = stack[-7];
    if (v350 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v350 = stack[-2];
    v116 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(8);
    return plus2(v350, v116);

v90:
    v350 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v350); }
/* error exit handlers */
v300:
    popv(8);
    return nil;
}



/* Code for xpndwedge */

static Lisp_Object CC_xpndwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v302, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpndwedge");
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
    goto v10;

v10:
    v302 = stack[0];
    v302 = qcdr(v302);
    if (v302 == nil) goto v90;
    v302 = stack[0];
    v302 = qcar(v302);
    fn = elt(env, 1); /* partitop */
    v54 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v302 = stack[-1];
    v302 = cons(v54, v302);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    stack[-1] = v302;
    v302 = stack[0];
    v302 = qcdr(v302);
    stack[0] = v302;
    goto v10;

v90:
    v302 = stack[0];
    v302 = qcar(v302);
    fn = elt(env, 1); /* partitop */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    fn = elt(env, 2); /* mkunarywedge */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v54 = v302;
    goto v51;

v51:
    v302 = stack[-1];
    if (v302 == nil) { popv(3); return onevalue(v54); }
    v302 = stack[-1];
    v302 = qcar(v302);
    fn = elt(env, 3); /* wedgepf2 */
    v302 = (*qfn2(fn))(qenv(fn), v302, v54);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v54 = v302;
    v302 = stack[-1];
    v302 = qcdr(v302);
    stack[-1] = v302;
    goto v51;
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for store_edges */

static Lisp_Object CC_store_edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v41;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for store_edges");
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
    v36 = v0;
/* end of prologue */
    stack[-3] = v36;
    v36 = stack[-3];
    if (v36 == nil) goto v57;
    v36 = stack[-3];
    v36 = qcar(v36);
    v41 = v36;
    v41 = qcar(v41);
    v36 = qcdr(v36);
    v36 = cons(v41, v36);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v36 = ncons(v36);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    stack[-1] = v36;
    stack[-2] = v36;
    goto v90;

v90:
    v36 = stack[-3];
    v36 = qcdr(v36);
    stack[-3] = v36;
    v36 = stack[-3];
    if (v36 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v36 = stack[-3];
    v36 = qcar(v36);
    v41 = v36;
    v41 = qcar(v41);
    v36 = qcdr(v36);
    v36 = cons(v41, v36);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v36 = ncons(v36);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v36 = Lrplacd(nil, stack[0], v36);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v36 = stack[-1];
    v36 = qcdr(v36);
    stack[-1] = v36;
    goto v90;

v57:
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v36); }
/* error exit handlers */
v11:
    popv(5);
    return nil;
}



/* Code for subs2chkex */

static Lisp_Object CC_subs2chkex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v74, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2chkex");
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

v351:
    v144 = stack[0];
    if (v144 == nil) goto v5;
    v144 = stack[0];
    v144 = qcar(v144);
    v144 = qcdr(v144);
    fn = elt(env, 2); /* subs2chk */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    v74 = v144;
    if (v74 == nil) goto v65;
    v74 = stack[0];
    v74 = qcar(v74);
    v66 = qcar(v74);
    v74 = v144;
    v144 = stack[0];
    v144 = qcdr(v144);
    popv(2);
    return acons(v66, v74, v144);

v65:
    v144 = stack[0];
    v144 = qcdr(v144);
    stack[0] = v144;
    goto v351;

v5:
    v144 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v144); }
/* error exit handlers */
v121:
    popv(2);
    return nil;
}



/* Code for dfp!-rule!-found */

static Lisp_Object CC_dfpKruleKfound(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v68, v352, v48;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfp-rule-found");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v352 = v6;
    v48 = v0;
/* end of prologue */
    v68 = v48;
    v55 = elt(env, 1); /* dfp */
    v55 = Leqcar(nil, v68, v55);
    v55 = (v55 == nil ? lisp_true : nil);
    if (!(v55 == nil)) return onevalue(v55);
    v55 = v48;
    v55 = qcdr(v55);
    v55 = qcar(v55);
    v68 = v352;
        return Lneq(nil, v55, v68);
}



/* Code for get_mat */

static Lisp_Object CC_get_mat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    v120 = stack[-2];
    v63 = elt(env, 1); /* id */
    if (v120 == v63) goto v22;
    v63 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v63;
    goto v65;

v65:
    v63 = stack[-1];
    v120 = Llength(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    v63 = (Lisp_Object)1; /* 0 */
    v63 = (Lisp_Object)greaterp2(v120, v63);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v63 = v63 ? lisp_true : nil;
    env = stack[-4];
    if (v63 == nil) goto v68;
    v63 = stack[-3];
    if (!(v63 == nil)) goto v68;
    v120 = stack[-2];
    v63 = stack[-1];
    v63 = qcar(v63);
    v63 = qcar(v63);
    if (!(equal(v120, v63))) goto v52;
    v63 = stack[-1];
    v63 = qcar(v63);
    v63 = qcdr(v63);
    v63 = qcar(v63);
    stack[0] = v63;
    v63 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v63;
    goto v52;

v52:
    v63 = stack[-1];
    v63 = qcdr(v63);
    stack[-1] = v63;
    goto v65;

v68:
    v63 = stack[-3];
    if (!(v63 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v63 = elt(env, 4); /* "error in get_mat" */
    fn = elt(env, 5); /* rederr */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v188;
    v63 = nil;
    { popv(5); return onevalue(v63); }

v22:
    v63 = stack[-1];
    v63 = qcar(v63);
    v63 = qcdr(v63);
    v63 = qcar(v63);
    fn = elt(env, 6); /* get!+row!+nr */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 7); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v63);
    }
/* error exit handlers */
v188:
    popv(5);
    return nil;
}



/* Code for ofsf_lnegrel */

static Lisp_Object CC_ofsf_lnegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v62, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_lnegrel");
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
    v63 = v0;
/* end of prologue */
    v62 = v63;
    v301 = elt(env, 1); /* equal */
    if (v62 == v301) goto v5;
    v62 = v63;
    v301 = elt(env, 2); /* neq */
    if (v62 == v301) goto v23;
    v62 = v63;
    v301 = elt(env, 3); /* leq */
    if (v62 == v301) goto v39;
    v62 = v63;
    v301 = elt(env, 5); /* lessp */
    if (v62 == v301) goto v65;
    v62 = v63;
    v301 = elt(env, 6); /* geq */
    if (v62 == v301) goto v37;
    v62 = v63;
    v301 = elt(env, 4); /* greaterp */
    if (v62 == v301) goto v122;
    v301 = elt(env, 7); /* "ofsf_lnegrel: unknown operator " */
    v62 = v63;
    v301 = list2(v301, v62);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 8); /* rederr */
        return (*qfn1(fn))(qenv(fn), v301);
    }

v122:
    v301 = elt(env, 3); /* leq */
    { popv(1); return onevalue(v301); }

v37:
    v301 = elt(env, 5); /* lessp */
    { popv(1); return onevalue(v301); }

v65:
    v301 = elt(env, 6); /* geq */
    { popv(1); return onevalue(v301); }

v39:
    v301 = elt(env, 4); /* greaterp */
    { popv(1); return onevalue(v301); }

v23:
    v301 = elt(env, 1); /* equal */
    { popv(1); return onevalue(v301); }

v5:
    v301 = elt(env, 2); /* neq */
    { popv(1); return onevalue(v301); }
/* error exit handlers */
v120:
    popv(1);
    return nil;
}



/* Code for parseml */

static Lisp_Object MS_CDECL CC_parseml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "parseml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for parseml");
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
    v12 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v12;
    v61 = elt(env, 2); /* !! */
    v12 = (Lisp_Object)513; /* 32 */
    v12 = list2(v61, v12);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v12 = Lcompress(nil, v12);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    qvalue(elt(env, 3)) = v12; /* space */
    v12 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 4)) = v12; /* count */
    v12 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    qvalue(elt(env, 5)) = v12; /* ch */
    v12 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 6)) = v12; /* temp2 */
    fn = elt(env, 12); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v61 = qvalue(elt(env, 7)); /* char */
    v12 = elt(env, 8); /* (m a t h) */
    if (equal(v61, v12)) goto v154;
    v61 = elt(env, 9); /* "<math>" */
    v12 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 13); /* errorml */
    v12 = (*qfn2(fn))(qenv(fn), v61, v12);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    goto v32;

v32:
    fn = elt(env, 12); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    v61 = qvalue(elt(env, 7)); /* char */
    v12 = elt(env, 10); /* (!/ m a t h) */
    if (equal(v61, v12)) goto v35;
    v61 = elt(env, 11); /* "</math>" */
    v12 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 13); /* errorml */
    v12 = (*qfn2(fn))(qenv(fn), v61, v12);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    goto v37;

v37:
    v12 = stack[0];
    {
        popv(2);
        fn = elt(env, 14); /* aeval */
        return (*qfn1(fn))(qenv(fn), v12);
    }

v35:
    v12 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    goto v37;

v154:
    fn = elt(env, 15); /* mathml */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-1];
    stack[0] = v12;
    goto v32;
/* error exit handlers */
v31:
    popv(2);
    return nil;
}



/* Code for i2ps */

static Lisp_Object CC_i2ps(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v73;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2ps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v73 = v0;
/* end of prologue */
    return onevalue(v73);
}



/* Code for look_for_rational */

static Lisp_Object MS_CDECL CC_look_for_rational(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v6,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v342, v300, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "look_for_rational");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for look_for_rational");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v6,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v7;
    stack[-1] = v6;
    stack[-2] = v0;
/* end of prologue */
    v342 = stack[0];
    v300 = qcar(v342);
    v342 = elt(env, 1); /* sqrt */
    if (!(v300 == v342)) goto v66;
    v342 = stack[0];
    v342 = qcdr(v342);
    v300 = qcar(v342);
    v342 = stack[-1];
    if (!(equal(v300, v342))) goto v66;
    v117 = stack[-2];
    v300 = stack[-1];
    v342 = (Lisp_Object)33; /* 2 */
    {
        popv(4);
        fn = elt(env, 5); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v117, v300, v342);
    }

v66:
    v342 = stack[0];
    v300 = qcar(v342);
    v342 = elt(env, 2); /* expt */
    if (!(v300 == v342)) goto v183;
    v342 = stack[0];
    v342 = qcdr(v342);
    v300 = qcar(v342);
    v342 = stack[-1];
    if (!(equal(v300, v342))) goto v183;
    v342 = stack[0];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    fn = elt(env, 6); /* listp */
    v342 = (*qfn1(fn))(qenv(fn), v342);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-3];
    if (v342 == nil) goto v183;
    v342 = stack[0];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    v300 = qcar(v342);
    v342 = elt(env, 3); /* quotient */
    if (!(v300 == v342)) goto v183;
    v342 = stack[0];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    if (!(is_number(v342))) goto v183;
    v342 = stack[0];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    if (!(is_number(v342))) goto v183;
    v117 = stack[-2];
    v300 = stack[-1];
    v342 = stack[0];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    {
        popv(4);
        fn = elt(env, 5); /* look_for_rational1 */
        return (*qfnn(fn))(qenv(fn), 3, v117, v300, v342);
    }

v183:
    v342 = qvalue(elt(env, 4)); /* nil */
    { popv(4); return onevalue(v342); }
/* error exit handlers */
v159:
    popv(4);
    return nil;
}



/* Code for impartsq */

static Lisp_Object CC_impartsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v301, v62, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for impartsq");
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
    v21 = stack[0];
    v21 = qcar(v21);
    fn = elt(env, 1); /* splitcomplex */
    stack[-1] = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v21 = stack[0];
    v21 = qcdr(v21);
    fn = elt(env, 1); /* splitcomplex */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v301 = stack[-1];
    v62 = v301;
    v63 = qcar(v62);
    v62 = qcdr(v301);
    v301 = v21;
    v301 = qcar(v301);
    v21 = qcdr(v21);
    stack[-3] = v63;
    stack[-2] = v301;
    stack[-1] = v21;
    v301 = v62;
    v21 = stack[-2];
    fn = elt(env, 2); /* multsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v301, v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v301 = stack[-3];
    v21 = stack[-1];
    fn = elt(env, 2); /* multsq */
    v21 = (*qfn2(fn))(qenv(fn), v301, v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    fn = elt(env, 3); /* negsq */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v301 = stack[-2];
    v21 = stack[-2];
    fn = elt(env, 2); /* multsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v301, v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v301 = stack[-1];
    v21 = stack[-1];
    fn = elt(env, 2); /* multsq */
    v21 = (*qfn2(fn))(qenv(fn), v301, v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    v21 = (*qfn2(fn))(qenv(fn), stack[-2], v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    fn = elt(env, 5); /* invsq */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    {
        Lisp_Object v188 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v188, v21);
    }
/* error exit handlers */
v187:
    popv(5);
    return nil;
}



/* Code for !:quotient */

static Lisp_Object CC_Tquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v350, v116, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :quotient");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v116 = v6;
    stack[0] = v0;
/* end of prologue */
    v350 = stack[0];
    if (v350 == nil) goto v15;
    v115 = stack[0];
    v350 = (Lisp_Object)1; /* 0 */
    if (v115 == v350) goto v15;
    v350 = v116;
    if (v350 == nil) goto v17;
    v115 = v116;
    v350 = (Lisp_Object)1; /* 0 */
    if (v115 == v350) goto v17;
    v350 = stack[0];
    if (!(!consp(v350))) goto v111;
    v350 = v116;
    if (!(!consp(v350))) goto v111;
    v350 = qvalue(elt(env, 4)); /* dmode!* */
    if (v350 == nil) goto v8;
    v350 = v116;
    fn = elt(env, 7); /* !:recip */
    v350 = (*qfn1(fn))(qenv(fn), v350);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-1];
    v116 = v350;
    if (!consp(v116)) goto v353;
    v115 = stack[0];
    v116 = v350;
    v350 = elt(env, 5); /* times */
    {
        popv(2);
        fn = elt(env, 8); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v115, v116, v350);
    }

v353:
    v116 = stack[0];
    popv(2);
    return times2(v116, v350);

v8:
    v350 = stack[0];
    popv(2);
    return quot2(v350, v116);

v111:
    v115 = stack[0];
    v350 = elt(env, 6); /* quotient */
    {
        popv(2);
        fn = elt(env, 8); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v115, v116, v350);
    }

v17:
    v115 = elt(env, 2); /* poly */
    v116 = (Lisp_Object)193; /* 12 */
    v350 = elt(env, 3); /* "Zero divisor" */
    {
        popv(2);
        fn = elt(env, 9); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v115, v116, v350);
    }

v15:
    v350 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v350); }
/* error exit handlers */
v114:
    popv(2);
    return nil;
}



/* Code for matcheq */

static Lisp_Object CC_matcheq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matcheq");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v6;
    stack[-2] = v0;
/* end of prologue */
    v157 = stack[-2];
    if (v157 == nil) goto v15;
    v157 = stack[-1];
    if (v157 == nil) goto v15;
    v157 = stack[-2];
    if (is_number(v157)) goto v3;
    v157 = stack[-2];
    if (!consp(v157)) goto v34;
    v157 = stack[-1];
    if (!consp(v157)) goto v185;
    v157 = stack[-2];
    v157 = qcar(v157);
    if (!(!consp(v157))) goto v115;
    v157 = stack[-2];
    v160 = qcar(v157);
    v157 = stack[-1];
    v157 = qcar(v157);
    if (!(v160 == v157)) goto v115;
    v157 = stack[-2];
    v160 = qcar(v157);
    v157 = elt(env, 0); /* matcheq */
    stack[0] = get(v160, v157);
    env = stack[-4];
    v157 = stack[-2];
    v157 = qcdr(v157);
    stack[-2] = Lmkquote(nil, v157);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v157 = stack[-1];
    v157 = qcdr(v157);
    v157 = Lmkquote(nil, v157);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v157 = list3(stack[0], stack[-2], v157);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 6); /* eval */
        return (*qfn1(fn))(qenv(fn), v157);
    }

v115:
    v157 = qvalue(elt(env, 3)); /* !*exp */
    if (!(v157 == nil)) goto v358;
    v157 = stack[-1];
    v160 = qcar(v157);
    v157 = elt(env, 4); /* (plus difference) */
    v157 = Lmemq(nil, v160, v157);
    if (v157 == nil) goto v358;
    v157 = stack[-2];
    v160 = qcar(v157);
    v157 = elt(env, 5); /* diff */
    if (!(v160 == v157)) goto v358;
    v160 = stack[-2];
    v157 = stack[-1];
    {
        popv(5);
        fn = elt(env, 7); /* matchlinear */
        return (*qfn2(fn))(qenv(fn), v160, v157);
    }

v358:
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v157); }

v185:
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v157); }

v34:
    v160 = stack[-2];
    v157 = elt(env, 0); /* matcheq */
    stack[-3] = get(v160, v157);
    env = stack[-4];
    v157 = stack[-2];
    stack[0] = Lmkquote(nil, v157);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v157 = stack[-1];
    if (!consp(v157)) goto v50;
    v157 = stack[-1];
    goto v27;

v27:
    v157 = Lmkquote(nil, v157);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v157 = list3(stack[-3], stack[0], v157);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    fn = elt(env, 6); /* eval */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    v160 = v157;
    v157 = v160;
    if (!(v157 == nil)) { popv(5); return onevalue(v160); }
    v157 = qvalue(elt(env, 3)); /* !*exp */
    if (!(v157 == nil)) goto v142;
    v157 = stack[-1];
    v157 = Lconsp(nil, v157);
    env = stack[-4];
    if (v157 == nil) goto v142;
    v157 = stack[-1];
    v160 = qcar(v157);
    v157 = elt(env, 4); /* (plus difference) */
    v157 = Lmemq(nil, v160, v157);
    if (v157 == nil) goto v142;
    v160 = stack[-2];
    v157 = stack[-1];
    {
        popv(5);
        fn = elt(env, 7); /* matchlinear */
        return (*qfn2(fn))(qenv(fn), v160, v157);
    }

v142:
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v157); }

v50:
    v157 = stack[-1];
    v157 = ncons(v157);
    nil = C_nil;
    if (exception_pending()) goto v335;
    env = stack[-4];
    goto v27;

v3:
    v160 = stack[-2];
    v157 = stack[-1];
    if (equal(v160, v157)) goto v1;
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v157); }

v1:
    v157 = qvalue(elt(env, 2)); /* t */
    popv(5);
    return ncons(v157);

v15:
    v157 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v157); }
/* error exit handlers */
v335:
    popv(5);
    return nil;
}



/* Code for ev!-tades */

static Lisp_Object CC_evKtades(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-tades");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v10;

v10:
    v54 = stack[-1];
    if (v54 == nil) goto v72;
    v46 = qvalue(elt(env, 1)); /* ndim!* */
    v54 = stack[-1];
    v45 = qcar(v54);
    v54 = stack[0];
    v54 = Lassoc(nil, v45, v54);
    v54 = qcdr(v54);
    fn = elt(env, 2); /* binc */
    v45 = (*qfn2(fn))(qenv(fn), v46, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v54 = stack[-2];
    v54 = cons(v45, v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[-2] = v54;
    v54 = stack[-1];
    v54 = qcdr(v54);
    stack[-1] = v54;
    goto v10;

v72:
    stack[0] = stack[-2];
    v54 = (Lisp_Object)17; /* 1 */
    v54 = ncons(v54);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    {
        Lisp_Object v14 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v14, v54);
    }
/* error exit handlers */
v58:
    popv(4);
    return nil;
}



/* Code for !*sq2fourier */

static Lisp_Object CC_Hsq2fourier(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v353, v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sq2fourier");
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
    stack[0] = v0;
/* end of prologue */
    v353 = stack[0];
    v353 = qcar(v353);
    if (v353 == nil) goto v5;
    v353 = (Lisp_Object)49; /* 3 */
    v353 = Lmkvect(nil, v353);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    stack[-2] = v353;
    v20 = stack[-2];
    v19 = (Lisp_Object)1; /* 0 */
    v353 = stack[0];
    *(Lisp_Object *)((char *)v20 + (CELL-TAG_VECTOR) + ((int32_t)v19/(16/CELL))) = v353;
    v20 = stack[-2];
    v19 = (Lisp_Object)17; /* 1 */
    v353 = elt(env, 2); /* cos */
    *(Lisp_Object *)((char *)v20 + (CELL-TAG_VECTOR) + ((int32_t)v19/(16/CELL))) = v353;
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)33; /* 2 */
    fn = elt(env, 5); /* fs!:make!-nullangle */
    v353 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v353;
    v20 = stack[-2];
    v19 = (Lisp_Object)49; /* 3 */
    v353 = qvalue(elt(env, 1)); /* nil */
    *(Lisp_Object *)((char *)v20 + (CELL-TAG_VECTOR) + ((int32_t)v19/(16/CELL))) = v353;
    v19 = elt(env, 3); /* fourier */
    v353 = elt(env, 4); /* tag */
    v19 = get(v19, v353);
    v353 = stack[-2];
    popv(4);
    return cons(v19, v353);

v5:
    v353 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v353); }
/* error exit handlers */
v63:
    popv(4);
    return nil;
}



/* Code for dp_content */

static Lisp_Object CC_dp_content(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_content");
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
    v121 = stack[0];
    if (v121 == nil) goto v5;
    v121 = stack[0];
    fn = elt(env, 2); /* dp_lc */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    stack[-1] = v121;
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v4;

v4:
    v121 = stack[0];
    if (v121 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v121 = stack[-1];
    fn = elt(env, 3); /* bc_inv */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    if (!(v121 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v121 = stack[0];
    fn = elt(env, 2); /* dp_lc */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    fn = elt(env, 4); /* bc_gcd */
    v121 = (*qfn2(fn))(qenv(fn), stack[-1], v121);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    stack[-1] = v121;
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v4;

v5:
    v121 = (Lisp_Object)1; /* 0 */
    {
        popv(3);
        fn = elt(env, 5); /* bc_fi */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for test!-bool */

static Lisp_Object CC_testKbool(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for test-bool");
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
    v51 = v0;
/* end of prologue */
    v51 = qcar(v51);
    fn = elt(env, 1); /* boolean!-eval1 */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[0];
    v51 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[0];
    fn = elt(env, 2); /* simp!-prop */
    v51 = (*qfn1(fn))(qenv(fn), v51);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v51);
    }
/* error exit handlers */
v22:
    popv(1);
    return nil;
}



/* Code for all_index_lst */

static Lisp_Object CC_all_index_lst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_index_lst");
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
    goto v10;

v10:
    v61 = stack[-1];
    if (v61 == nil) goto v90;
    v61 = stack[-1];
    v61 = qcar(v61);
    v61 = qcdr(v61);
    stack[0] = v61;
    v61 = stack[0];
    v61 = qcar(v61);
    fn = elt(env, 3); /* listp */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    if (v61 == nil) goto v37;
    v61 = stack[0];
    v61 = qcar(v61);
    v30 = qcar(v61);
    v61 = elt(env, 1); /* list */
    if (!(v30 == v61)) goto v37;
    v61 = stack[0];
    v61 = qcdr(v61);
    v30 = v61;
    goto v1;

v1:
    v61 = stack[-2];
    v61 = cons(v30, v61);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    stack[-2] = v61;
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    goto v10;

v37:
    v61 = stack[0];
    v30 = v61;
    goto v1;

v90:
    v61 = qvalue(elt(env, 2)); /* nil */
    v30 = v61;
    goto v51;

v51:
    v61 = stack[-2];
    if (v61 == nil) { popv(4); return onevalue(v30); }
    v61 = stack[-2];
    v61 = qcar(v61);
    v61 = Lappend(nil, v61, v30);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-3];
    v30 = v61;
    v61 = stack[-2];
    v61 = qcdr(v61);
    stack[-2] = v61;
    goto v51;
/* error exit handlers */
v20:
    popv(4);
    return nil;
}



/* Code for baglistp */

static Lisp_Object CC_baglistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v53, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for baglistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v64 = v0;
/* end of prologue */
    v17 = v64;
    if (!consp(v17)) goto v5;
    v17 = v64;
    v53 = qcar(v17);
    v17 = elt(env, 2); /* list */
    v17 = (v53 == v17 ? lisp_true : nil);
    if (!(v17 == nil)) return onevalue(v17);
    v17 = v64;
    v17 = qcar(v17);
    v53 = elt(env, 3); /* bag */
        return Lflagp(nil, v17, v53);

v5:
    v17 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v17);
}



/* Code for !*sf2exb */

static Lisp_Object CC_Hsf2exb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v6)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *sf2exb");
#endif
    if (stack >= stacklimit)
    {
        push2(v6,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v1;

v1:
    v20 = stack[-1];
    v19 = stack[0];
    fn = elt(env, 1); /* degr */
    v20 = (*qfn2(fn))(qenv(fn), v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v19 = (Lisp_Object)1; /* 0 */
    if (v20 == v19) goto v22;
    v19 = stack[-1];
    v19 = qcar(v19);
    v19 = qcar(v19);
    v19 = qcdr(v19);
    v21 = ncons(v19);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v19 = stack[-1];
    v19 = qcar(v19);
    v20 = qcdr(v19);
    v19 = stack[-2];
    v19 = acons(v21, v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    stack[-2] = v19;
    v19 = stack[-1];
    v19 = qcdr(v19);
    stack[-1] = v19;
    goto v1;

v22:
    v19 = stack[-1];
    if (v19 == nil) goto v352;
    stack[0] = stack[-2];
    v19 = (Lisp_Object)1; /* 0 */
    v20 = ncons(v19);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v19 = stack[-1];
    v19 = cons(v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    v19 = ncons(v19);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-3];
    {
        Lisp_Object v303 = stack[0];
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v303, v19);
    }

v352:
    v19 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v19);
    }
/* error exit handlers */
v120:
    popv(4);
    return nil;
}



setup_type const u39_setup[] =
{
    {"algmodep",                CC_algmodep,    too_many_1,    wrong_no_1},
    {"ofsf_irl2atl",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_irl2atl},
    {"homogp",                  CC_homogp,      too_many_1,    wrong_no_1},
    {"cd_ordatp",               too_few_2,      CC_cd_ordatp,  wrong_no_2},
    {"sfpf",                    CC_sfpf,        too_many_1,    wrong_no_1},
    {"rfirst",                  CC_rfirst,      too_many_1,    wrong_no_1},
    {"dp=a2dpatom",             CC_dpMa2dpatom, too_many_1,    wrong_no_1},
    {"gd_gcasesimpl",           CC_gd_gcasesimpl,too_many_1,   wrong_no_1},
    {"mk_character",            CC_mk_character,too_many_1,    wrong_no_1},
    {"rnfloor*",                CC_rnfloorH,    too_many_1,    wrong_no_1},
    {"multsqpf",                too_few_2,      CC_multsqpf,   wrong_no_2},
    {"let2",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let2},
    {"simplog",                 CC_simplog,     too_many_1,    wrong_no_1},
    {"*s2arg",                  too_few_2,      CC_Hs2arg,     wrong_no_2},
    {"calc_world",              too_few_2,      CC_calc_world, wrong_no_2},
    {"hdiff",                   too_few_2,      CC_hdiff,      wrong_no_2},
    {"sep_tens_from_other",     CC_sep_tens_from_other,too_many_1,wrong_no_1},
    {"sc_repkern",              too_few_2,      CC_sc_repkern, wrong_no_2},
    {"lambda_l73kgz_9",         too_few_2,      CC_lambda_l73kgz_9,wrong_no_2},
    {"general-difference-mod-p",too_few_2,      CC_generalKdifferenceKmodKp,wrong_no_2},
    {"cl_simpl1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_simpl1},
    {"girationalize:",          CC_girationalizeT,too_many_1,  wrong_no_1},
    {"uterm",                   too_few_2,      CC_uterm,      wrong_no_2},
    {"depend-l",                too_few_2,      CC_dependKl,   wrong_no_2},
    {"search4facf",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_search4facf},
    {"setrow",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrow},
    {":mod:units",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_TmodTunits},
    {"xpndwedge",               CC_xpndwedge,   too_many_1,    wrong_no_1},
    {"store_edges",             CC_store_edges, too_many_1,    wrong_no_1},
    {"subs2chkex",              CC_subs2chkex,  too_many_1,    wrong_no_1},
    {"dfp-rule-found",          too_few_2,      CC_dfpKruleKfound,wrong_no_2},
    {"get_mat",                 too_few_2,      CC_get_mat,    wrong_no_2},
    {"ofsf_lnegrel",            CC_ofsf_lnegrel,too_many_1,    wrong_no_1},
    {"parseml",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_parseml},
    {"i2ps",                    CC_i2ps,        too_many_1,    wrong_no_1},
    {"look_for_rational",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_look_for_rational},
    {"impartsq",                CC_impartsq,    too_many_1,    wrong_no_1},
    {":quotient",               too_few_2,      CC_Tquotient,  wrong_no_2},
    {"matcheq",                 too_few_2,      CC_matcheq,    wrong_no_2},
    {"ev-tades",                too_few_2,      CC_evKtades,   wrong_no_2},
    {"*sq2fourier",             CC_Hsq2fourier, too_many_1,    wrong_no_1},
    {"dp_content",              CC_dp_content,  too_many_1,    wrong_no_1},
    {"test-bool",               CC_testKbool,   too_many_1,    wrong_no_1},
    {"all_index_lst",           CC_all_index_lst,too_many_1,   wrong_no_1},
    {"baglistp",                CC_baglistp,    too_many_1,    wrong_no_1},
    {"*sf2exb",                 too_few_2,      CC_Hsf2exb,    wrong_no_2},
    {NULL, (one_args *)"u39", (two_args *)"10589 9749103 1816174", 0}
};

/* end of generated code */
