
/* $destdir/generated-c\u32.c Machine generated C code */

/* Signature: 00000000 21-Aug-2010 */

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


/* Code for splitcomplex */

static Lisp_Object CC_splitcomplex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for splitcomplex");
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
    v15 = qvalue(elt(env, 1)); /* kord!* */
    v14 = qvalue(elt(env, 2)); /* t */
    stack[-3] = qvalue(elt(env, 1)); /* kord!* */
    qvalue(elt(env, 1)) = v15; /* kord!* */
    stack[-2] = qvalue(elt(env, 3)); /* !*exp */
    qvalue(elt(env, 3)) = v14; /* !*exp */
    v15 = elt(env, 4); /* i */
    v14 = elt(env, 5); /* idvalfn */
    v14 = get(v15, v14);
    env = stack[-4];
    if (v14 == nil) goto v16;
    v14 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    goto v18;

v18:
    stack[-1] = v14;
    v14 = stack[-1];
    fn = elt(env, 7); /* take!-realpart */
    stack[0] = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v14 = stack[-1];
    fn = elt(env, 8); /* take!-impart */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v14 = cons(stack[0], v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-2]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v14); }

v16:
    v15 = elt(env, 4); /* i */
    v14 = stack[0];
    v14 = Lsmemq(nil, v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    if (v14 == nil) goto v19;
    v15 = elt(env, 4); /* i */
    v14 = qvalue(elt(env, 1)); /* kord!* */
    v14 = cons(v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    fn = elt(env, 9); /* setkorder */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    v14 = stack[0];
    fn = elt(env, 10); /* reorder */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    stack[0] = v14;
    goto v19;

v19:
    v14 = stack[0];
    fn = elt(env, 6); /* expand!-imrepart */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    fn = elt(env, 11); /* subs2 */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-4];
    goto v18;
/* error exit handlers */
v17:
    env = stack[-4];
    qvalue(elt(env, 3)) = stack[-2]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
}



/* Code for simpsetdiff */

static Lisp_Object CC_simpsetdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsetdiff");
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
    v35 = elt(env, 1); /* setdiff */
    fn = elt(env, 3); /* applysetop */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    v36 = v34;
    v34 = v36;
    v35 = qcar(v34);
    v34 = elt(env, 1); /* setdiff */
    if (v35 == v34) goto v38;
    v34 = v36;
    v35 = v34;
    goto v39;

v39:
    v34 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* mksp */
    v35 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    v34 = (Lisp_Object)17; /* 1 */
    v34 = cons(v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[0];
    v35 = ncons(v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v34 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v35, v34);

v38:
    v34 = v36;
    v34 = qcdr(v34);
    v35 = qcar(v34);
    v34 = v36;
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    if (equal(v35, v34)) goto v8;
    v34 = v36;
    v34 = qcdr(v34);
    v35 = qcar(v34);
    v34 = qvalue(elt(env, 2)); /* empty_set */
    if (equal(v35, v34)) goto v8;
    v34 = v36;
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v35 = qcar(v34);
    v34 = qvalue(elt(env, 2)); /* empty_set */
    if (equal(v35, v34)) goto v40;
    v34 = v36;
    goto v41;

v41:
    v35 = v34;
    goto v39;

v40:
    v34 = v36;
    v34 = qcdr(v34);
    v34 = qcar(v34);
    goto v41;

v8:
    v34 = qvalue(elt(env, 2)); /* empty_set */
    goto v41;
/* error exit handlers */
v37:
    popv(1);
    return nil;
}



/* Code for fctinsert */

static Lisp_Object CC_fctinsert(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctinsert");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v42;
    stack[-1] = v0;
/* end of prologue */
    v46 = stack[0];
    v16 = stack[-1];
    fn = elt(env, 1); /* freeof */
    v16 = (*qfn2(fn))(qenv(fn), v46, v16);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    if (v16 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v16 = stack[-1];
    fn = elt(env, 2); /* fctlength */
    v46 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    v16 = stack[0];
    {
        Lisp_Object v11 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fctins */
        return (*qfnn(fn))(qenv(fn), 3, v11, v46, v16);
    }
/* error exit handlers */
v10:
    popv(4);
    return nil;
}



/* Code for prsum */

static Lisp_Object CC_prsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prsum");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v42;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v6;

v6:
    v50 = stack[-1];
    if (v50 == nil) goto v7;
    v50 = stack[0];
    v50 = qcar(v50);
    if (v50 == nil) goto v45;
    v50 = stack[-1];
    v51 = qcar(v50);
    v50 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* to */
    v52 = (*qfn2(fn))(qenv(fn), v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v50 = stack[0];
    v51 = qcar(v50);
    v50 = stack[-2];
    v50 = acons(v52, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    stack[-2] = v50;
    v50 = stack[-1];
    v50 = qcdr(v50);
    stack[-1] = v50;
    v50 = stack[0];
    v50 = qcdr(v50);
    stack[0] = v50;
    goto v6;

v45:
    v50 = stack[-1];
    v50 = qcdr(v50);
    stack[-1] = v50;
    v50 = stack[0];
    v50 = qcdr(v50);
    stack[0] = v50;
    goto v6;

v7:
    v50 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v50);
    }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for tidysqrtf */

static Lisp_Object CC_tidysqrtf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v82, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tidysqrtf");
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
    v81 = stack[-1];
    if (!consp(v81)) goto v84;
    v81 = stack[-1];
    v81 = qcar(v81);
    if (!consp(v81)) goto v84;
    v81 = stack[-1];
    v81 = qcar(v81);
    v81 = qcar(v81);
    stack[-2] = v81;
    v81 = stack[-2];
    v82 = qcar(v81);
    v81 = elt(env, 1); /* i */
    if (!(v82 == v81)) goto v85;
    v82 = elt(env, 2); /* (sqrt -1) */
    v81 = stack[-2];
    v81 = qcdr(v81);
    fn = elt(env, 5); /* mksp */
    v81 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    stack[-2] = v81;
    goto v85;

v85:
    v81 = stack[-2];
    v82 = qcar(v81);
    v81 = elt(env, 3); /* sqrt */
    if (!consp(v82)) goto v87;
    v82 = qcar(v82);
    if (!(v82 == v81)) goto v87;
    v81 = stack[-2];
    v81 = qcdr(v81);
    v81 = Lonep(nil, v81);
    env = stack[-3];
    if (!(v81 == nil)) goto v87;
    v81 = stack[-2];
    v82 = qcdr(v81);
    v81 = (Lisp_Object)33; /* 2 */
    v81 = Ldivide(nil, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    stack[0] = v81;
    v81 = stack[-2];
    v81 = qcar(v81);
    v81 = qcdr(v81);
    v81 = qcar(v81);
    fn = elt(env, 6); /* simp */
    v82 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v81 = stack[0];
    v81 = qcar(v81);
    fn = elt(env, 7); /* exptsq */
    v81 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v83 = v81;
    v81 = stack[0];
    v82 = qcdr(v81);
    v81 = (Lisp_Object)1; /* 0 */
    if (v82 == v81) goto v20;
    stack[0] = v83;
    v81 = stack[-2];
    v82 = qcar(v81);
    v81 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* mksp */
    v82 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v81 = (Lisp_Object)17; /* 1 */
    v83 = cons(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v82 = qvalue(elt(env, 4)); /* nil */
    v81 = (Lisp_Object)17; /* 1 */
    v81 = acons(v83, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    fn = elt(env, 8); /* multsq */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v83 = v81;
    goto v20;

v20:
    v81 = v83;
    fn = elt(env, 9); /* tidysqrt */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v83 = v81;
    goto v88;

v88:
    stack[0] = v83;
    v81 = stack[-1];
    v81 = qcar(v81);
    v81 = qcdr(v81);
    v81 = CC_tidysqrtf(env, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    fn = elt(env, 8); /* multsq */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    stack[-2] = v81;
    stack[0] = stack[-2];
    v81 = stack[-1];
    v81 = qcdr(v81);
    v81 = CC_tidysqrtf(env, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    {
        Lisp_Object v89 = stack[0];
        popv(4);
        fn = elt(env, 10); /* addsq */
        return (*qfn2(fn))(qenv(fn), v89, v81);
    }

v87:
    v82 = stack[-2];
    v81 = (Lisp_Object)17; /* 1 */
    v83 = cons(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v82 = qvalue(elt(env, 4)); /* nil */
    v81 = (Lisp_Object)17; /* 1 */
    v81 = acons(v83, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v83 = v81;
    goto v88;

v84:
    v82 = stack[-1];
    v81 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v82, v81);
/* error exit handlers */
v86:
    popv(4);
    return nil;
}



/* Code for makeqn!-maybe */

static Lisp_Object MS_CDECL CC_makeqnKmaybe(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v22, v91;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeqn-maybe");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeqn-maybe");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v90;
    v22 = v42;
    v91 = v0;
/* end of prologue */
    if (!(v43 == nil)) return onevalue(v22);
    v43 = elt(env, 1); /* equal */
    return list3(v43, v91, v22);
}



/* Code for zfactor1 */

static Lisp_Object CC_zfactor1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v116, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zfactor1");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v42;
    stack[-4] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v84;

v84:
    v116 = stack[-4];
    v115 = (Lisp_Object)1; /* 0 */
    v115 = (Lisp_Object)lessp2(v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v115 = v115 ? lisp_true : nil;
    env = stack[-6];
    if (v115 == nil) goto v10;
    v117 = (Lisp_Object)-15; /* -1 */
    v116 = (Lisp_Object)17; /* 1 */
    v115 = stack[0];
    v115 = acons(v117, v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    stack[0] = v115;
    v115 = stack[-4];
    v115 = negate(v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    stack[-4] = v115;
    goto v84;

v10:
    v116 = stack[-4];
    v115 = (Lisp_Object)65; /* 4 */
    v115 = (Lisp_Object)lessp2(v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v115 = v115 ? lisp_true : nil;
    env = stack[-6];
    if (v115 == nil) goto v14;
    v116 = stack[-4];
    v115 = (Lisp_Object)17; /* 1 */
    v115 = cons(v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    v115 = ncons(v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    {
        Lisp_Object v119 = stack[0];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v119, v115);
    }

v14:
    stack[-5] = stack[0];
    v115 = qvalue(elt(env, 1)); /* !*primelist!* */
    stack[-2] = v115;
    v115 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v115;
    goto v76;

v76:
    v115 = stack[-2];
    if (v115 == nil) goto v120;
    v115 = stack[-2];
    v115 = qcar(v115);
    stack[0] = v115;
    v115 = stack[-2];
    v115 = qcdr(v115);
    stack[-2] = v115;
    goto v121;

v121:
    v116 = stack[-4];
    v115 = stack[0];
    v115 = Ldivide(nil, v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    v117 = v115;
    v116 = qcdr(v115);
    v115 = (Lisp_Object)1; /* 0 */
    if (v116 == v115) goto v23;
    v116 = stack[-4];
    v115 = (Lisp_Object)17; /* 1 */
    if (v116 == v115) goto v76;
    v116 = stack[0];
    v115 = stack[0];
    v116 = times2(v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    v115 = stack[-4];
    v115 = (Lisp_Object)greaterp2(v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v115 = v115 ? lisp_true : nil;
    env = stack[-6];
    if (v115 == nil) goto v76;
    v115 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v115;
    v116 = stack[-4];
    v115 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    stack[-1] = v115;
    v115 = (Lisp_Object)17; /* 1 */
    stack[-4] = v115;
    goto v76;

v23:
    v115 = v117;
    v115 = qcar(v115);
    stack[-4] = v115;
    v116 = stack[0];
    v115 = stack[-1];
    fn = elt(env, 4); /* add!-factor */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    stack[-1] = v115;
    goto v121;

v120:
    v116 = stack[-4];
    v115 = (Lisp_Object)17; /* 1 */
    if (v116 == v115) goto v122;
    v115 = stack[-3];
    if (v115 == nil) goto v123;
    v116 = stack[-4];
    v115 = stack[-1];
    fn = elt(env, 5); /* mcfactor!* */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    goto v124;

v124:
    {
        Lisp_Object v125 = stack[-5];
        popv(7);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v125, v115);
    }

v123:
    v117 = stack[-4];
    v116 = (Lisp_Object)17; /* 1 */
    v115 = stack[-1];
    v115 = acons(v117, v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-6];
    goto v124;

v122:
    v115 = stack[-1];
    goto v124;
/* error exit handlers */
v118:
    popv(7);
    return nil;
}



/* Code for mkrootsq */

static Lisp_Object CC_mkrootsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrootsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v42;
    stack[-1] = v0;
/* end of prologue */
    v144 = stack[-1];
    v143 = (Lisp_Object)17; /* 1 */
    if (v144 == v143) goto v2;
    v144 = stack[0];
    v143 = (Lisp_Object)33; /* 2 */
    if (!(v144 == v143)) goto v51;
    v144 = stack[-1];
    v143 = (Lisp_Object)-15; /* -1 */
    if (v144 == v143) goto v145;
    v144 = stack[-1];
    v143 = elt(env, 1); /* (minus 1) */
    if (!(equal(v144, v143))) goto v51;

v145:
    v143 = elt(env, 2); /* i */
    {
        popv(4);
        fn = elt(env, 8); /* simp */
        return (*qfn1(fn))(qenv(fn), v143);
    }

v51:
    v144 = stack[-1];
    v143 = elt(env, 3); /* expt */
    if (!consp(v144)) goto v146;
    v144 = qcar(v144);
    if (!(v144 == v143)) goto v146;
    v143 = stack[-1];
    v143 = qcdr(v143);
    v143 = qcdr(v143);
    v143 = qcar(v143);
    v143 = integerp(v143);
    if (v143 == nil) goto v146;
    v143 = qvalue(elt(env, 4)); /* !*precise_complex */
    if (!(v143 == nil)) goto v146;
    v143 = stack[-1];
    v143 = qcdr(v143);
    v144 = qcar(v143);
    v143 = stack[0];
    v144 = CC_mkrootsq(env, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    v143 = stack[-1];
    v143 = qcdr(v143);
    v143 = qcdr(v143);
    v143 = qcar(v143);
    {
        popv(4);
        fn = elt(env, 9); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v144, v143);
    }

v146:
    v143 = stack[-1];
    v143 = integerp(v143);
    if (v143 == nil) goto v148;
    v143 = stack[-1];
    v143 = Lminusp(nil, v143);
    env = stack[-3];
    if (!(v143 == nil)) goto v148;
    stack[-2] = stack[-1];
    v144 = stack[-1];
    v143 = qvalue(elt(env, 5)); /* factorbound!* */
    v143 = (Lisp_Object)lessp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v143 = v143 ? lisp_true : nil;
    env = stack[-3];
    if (!(v143 == nil)) goto v149;
    v143 = qvalue(elt(env, 6)); /* !*ifactor */
    goto v149;

v149:
    fn = elt(env, 10); /* zfactor1 */
    v143 = (*qfn2(fn))(qenv(fn), stack[-2], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    stack[-2] = v143;
    v144 = Llength(nil, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    v143 = (Lisp_Object)17; /* 1 */
    v143 = (Lisp_Object)greaterp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v143 = v143 ? lisp_true : nil;
    env = stack[-3];
    if (!(v143 == nil)) goto v150;
    v143 = stack[-2];
    v143 = qcar(v143);
    v144 = qcdr(v143);
    v143 = (Lisp_Object)17; /* 1 */
    v143 = (Lisp_Object)greaterp2(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v143 = v143 ? lisp_true : nil;
    env = stack[-3];
    if (!(v143 == nil)) goto v150;

v148:
    v144 = stack[0];
    v143 = (Lisp_Object)33; /* 2 */
    if (v144 == v143) goto v87;
    stack[-2] = elt(env, 3); /* expt */
    v118 = elt(env, 7); /* quotient */
    v144 = (Lisp_Object)17; /* 1 */
    v143 = stack[0];
    v143 = list3(v118, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    v143 = list3(stack[-2], stack[-1], v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    goto v61;

v61:
    stack[-2] = v143;
    v143 = stack[-2];
    fn = elt(env, 11); /* opmtch */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    v144 = v143;
    if (v143 == nil) goto v115;
    v143 = v144;
    {
        popv(4);
        fn = elt(env, 8); /* simp */
        return (*qfn1(fn))(qenv(fn), v143);
    }

v115:
    v144 = stack[-2];
    v143 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 12); /* mksq */
        return (*qfn2(fn))(qenv(fn), v144, v143);
    }

v87:
    v143 = stack[-1];
    fn = elt(env, 13); /* mksqrt */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    goto v61;

v150:
    v144 = stack[-2];
    v143 = stack[0];
    {
        popv(4);
        fn = elt(env, 14); /* mkrootsql */
        return (*qfn2(fn))(qenv(fn), v144, v143);
    }

v2:
    v143 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 15); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v143);
    }
/* error exit handlers */
v147:
    popv(4);
    return nil;
}



/* Code for formbool */

static Lisp_Object MS_CDECL CC_formbool(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181, v182, v183, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formbool");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formbool");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v42,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v90;
    stack[-3] = v42;
    stack[-4] = v0;
/* end of prologue */
    v181 = stack[-2];
    v180 = elt(env, 1); /* symbolic */
    if (v181 == v180) goto v145;
    v180 = stack[-4];
    if (!consp(v180)) goto v141;
    v180 = stack[-4];
    v181 = qcdr(v180);
    v180 = stack[-3];
    fn = elt(env, 9); /* intexprlisp */
    v180 = (*qfn2(fn))(qenv(fn), v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    if (v180 == nil) goto v139;
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 3); /* boolfn */
    v180 = get(v181, v180);
    env = stack[-6];
    if (!(v180 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v139:
    v180 = stack[-4];
    v180 = qcar(v180);
    if (!(symbolp(v180))) goto v110;
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 3); /* boolfn */
    v180 = get(v181, v180);
    env = stack[-6];
    if (v180 == nil) goto v110;
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 3); /* boolfn */
    stack[0] = get(v181, v180);
    env = stack[-6];
    v180 = stack[-4];
    v182 = qcdr(v180);
    v181 = stack[-3];
    v180 = stack[-2];
    fn = elt(env, 10); /* formclis */
    v180 = (*qfnn(fn))(qenv(fn), 3, v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    {
        Lisp_Object v186 = stack[0];
        popv(7);
        return cons(v186, v180);
    }

v110:
    v180 = stack[-4];
    v180 = qcar(v180);
    if (!(symbolp(v180))) goto v115;
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 4); /* boolean */
    v180 = Lflagp(nil, v181, v180);
    env = stack[-6];
    if (v180 == nil) goto v115;
    v180 = stack[-4];
    stack[0] = qcar(v180);
    v180 = stack[-4];
    v184 = qcdr(v180);
    v183 = stack[-3];
    v182 = stack[-2];
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 5); /* boolargs */
    v180 = Lflagp(nil, v181, v180);
    env = stack[-6];
    fn = elt(env, 11); /* formboollis */
    v180 = (*qfnn(fn))(qenv(fn), 4, v184, v183, v182, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    {
        Lisp_Object v187 = stack[0];
        popv(7);
        return cons(v187, v180);
    }

v115:
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 2); /* boolvalue!* */
    if (v181 == v180) goto v95;
    v180 = stack[-4];
    v181 = qcar(v180);
    v180 = elt(env, 7); /* where */
    if (v181 == v180) goto v188;
    stack[0] = elt(env, 2); /* boolvalue!* */
    v182 = stack[-4];
    v181 = stack[-3];
    v180 = stack[-2];
    fn = elt(env, 12); /* formc!* */
    v180 = (*qfnn(fn))(qenv(fn), 3, v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    {
        Lisp_Object v189 = stack[0];
        popv(7);
        return list2(v189, v180);
    }

v188:
    stack[-5] = elt(env, 2); /* boolvalue!* */
    stack[-1] = elt(env, 7); /* where */
    stack[0] = elt(env, 8); /* bool!-eval */
    v180 = stack[-4];
    v180 = qcdr(v180);
    v182 = qcar(v180);
    v181 = stack[-3];
    v180 = stack[-2];
    v180 = CC_formbool(env, 3, v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    v180 = list2(stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    v181 = Lmkquote(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    v180 = stack[-4];
    v180 = qcdr(v180);
    v180 = qcdr(v180);
    v180 = qcar(v180);
    v182 = list3(stack[-1], v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    v181 = stack[-3];
    v180 = stack[-2];
    fn = elt(env, 12); /* formc!* */
    v180 = (*qfnn(fn))(qenv(fn), 3, v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    {
        Lisp_Object v190 = stack[-5];
        popv(7);
        return list2(v190, v180);
    }

v95:
    v180 = elt(env, 6); /* "Too many formbools" */
    {
        popv(7);
        fn = elt(env, 13); /* rederr */
        return (*qfn1(fn))(qenv(fn), v180);
    }

v141:
    v181 = stack[-4];
    v180 = lisp_true;
    if (v181 == v180) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v180 = stack[-4];
    if (!(symbolp(v180))) goto v85;
    v181 = stack[-4];
    v180 = stack[-3];
    v180 = Latsoc(nil, v181, v180);
    if (!(v180 == nil)) goto v85;
    stack[0] = elt(env, 2); /* boolvalue!* */
    v182 = stack[-4];
    v181 = stack[-3];
    v180 = stack[-2];
    fn = elt(env, 12); /* formc!* */
    v180 = (*qfnn(fn))(qenv(fn), 3, v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    {
        Lisp_Object v191 = stack[0];
        popv(7);
        return list2(v191, v180);
    }

v85:
    v181 = elt(env, 2); /* boolvalue!* */
    v180 = stack[-4];
    popv(7);
    return list2(v181, v180);

v145:
    v182 = stack[-4];
    v181 = stack[-3];
    v180 = stack[-2];
    {
        popv(7);
        fn = elt(env, 14); /* formc */
        return (*qfnn(fn))(qenv(fn), 3, v182, v181, v180);
    }
/* error exit handlers */
v185:
    popv(7);
    return nil;
}



/* Code for ratpoly_ratp */

static Lisp_Object CC_ratpoly_ratp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v84;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ratp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v192 = v0;
/* end of prologue */
    v84 = v192;
    v84 = qcar(v84);
    v84 = (is_number(v84) ? lisp_true : nil);
    if (!(v84 == nil)) return onevalue(v84);
    v192 = qcar(v192);
    v192 = (v192 == nil ? lisp_true : nil);
    return onevalue(v192);
}



/* Code for conditionrd */

static Lisp_Object MS_CDECL CC_conditionrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "conditionrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conditionrd");
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
    fn = elt(env, 3); /* lex */
    v58 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    v43 = qvalue(elt(env, 1)); /* char */
    v58 = elt(env, 2); /* (r e l n) */
    if (equal(v43, v58)) goto v3;
    fn = elt(env, 4); /* mathml */
    v58 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    stack[0] = v58;
    goto v6;

v6:
    fn = elt(env, 3); /* lex */
    v58 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v91;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v3:
    fn = elt(env, 5); /* relnrd */
    v58 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-1];
    stack[0] = v58;
    goto v6;
/* error exit handlers */
v91:
    popv(2);
    return nil;
}



/* Code for scar */

static Lisp_Object CC_scar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scar");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v42;
    stack[-1] = v0;
/* end of prologue */

v194:
    v41 = stack[0];
    if (!consp(v41)) goto v2;
    v8 = stack[-1];
    v41 = stack[0];
    v41 = qcar(v41);
    if (equal(v8, v41)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v8 = stack[-1];
    v41 = stack[0];
    v41 = qcar(v41);
    v41 = CC_scar(env, v8, v41);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-2];
    if (!(v41 == nil)) { popv(3); return onevalue(v41); }
    v8 = stack[-1];
    v41 = stack[0];
    v41 = qcdr(v41);
    stack[-1] = v8;
    stack[0] = v41;
    goto v194;

v2:
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v41); }
/* error exit handlers */
v38:
    popv(3);
    return nil;
}



/* Code for spinnerprod */

static Lisp_Object MS_CDECL CC_spinnerprod(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, Lisp_Object v48,
                         Lisp_Object v1, Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v69, v138, v204;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "spinnerprod");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spinnerprod");
#endif
    if (stack >= stacklimit)
    {
        push6(v2,v1,v48,v90,v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v42,v90,v48,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    v203 = v1;
    v69 = v48;
    stack[-5] = v90;
    v138 = v42;
    v204 = v0;
/* end of prologue */
    stack[-6] = v69;
    v69 = stack[-6];
    stack[-3] = v69;
    v203 = qcdr(v203);
    stack[-1] = v203;
    goto v12;

v12:
    v203 = stack[-1];
    if (v203 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v203 = stack[-1];
    v203 = qcar(v203);
    v69 = v203;
    v203 = v69;
    v203 = qcar(v203);
    stack[-7] = v203;
    v203 = stack[-7];
    if (!(v203 == nil)) goto v142;
    v203 = (Lisp_Object)1; /* 0 */
    stack[-7] = v203;
    goto v142;

v142:
    v203 = v69;
    v203 = qcdr(v203);
    stack[-2] = v203;
    v203 = stack[-2];
    if (v203 == nil) goto v41;
    stack[0] = stack[-2];
    v203 = qvalue(elt(env, 1)); /* nil */
    v203 = ncons(v203);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    if (!(equal(stack[0], v203))) goto v15;

v41:
    v203 = (Lisp_Object)1; /* 0 */
    stack[-2] = v203;
    goto v15;

v15:
    v69 = stack[-7];
    v203 = stack[-5];
    v203 = (Lisp_Object)lesseq2(v69, v203);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v203 = v203 ? lisp_true : nil;
    env = stack[-8];
    if (v203 == nil) goto v29;
    v69 = stack[-7];
    v203 = stack[-4];
    v203 = Latsoc(nil, v69, v203);
    stack[-7] = v203;
    v203 = stack[-7];
    if (v203 == nil) goto v29;
    stack[0] = stack[-7];
    v203 = qvalue(elt(env, 1)); /* nil */
    v203 = ncons(v203);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    if (equal(stack[0], v203)) goto v29;
    stack[0] = elt(env, 2); /* plus */
    stack[-3] = stack[-6];
    v138 = elt(env, 3); /* times */
    v69 = stack[-2];
    v203 = stack[-7];
    v203 = qcdr(v203);
    v203 = list3(v138, v69, v203);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    v203 = list3(stack[0], stack[-3], v203);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-8];
    stack[-6] = v203;
    v203 = stack[-6];
    stack[-3] = v203;
    goto v29;

v29:
    v203 = stack[-1];
    v203 = qcdr(v203);
    stack[-1] = v203;
    goto v12;
/* error exit handlers */
v67:
    popv(9);
    return nil;
}



/* Code for findhc */

static Lisp_Object CC_findhc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v69;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findhc");
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
    v203 = v0;
/* end of prologue */
    stack[-4] = nil;
    v69 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v69; /* njsi */
    stack[-2] = v69;
    v69 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v69; /* jsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v69 = qvalue(elt(env, 5)); /* maxvar */
    v203 = plus2(v69, v203);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    v69 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    v203 = (Lisp_Object)65; /* 4 */
    v203 = *(Lisp_Object *)((char *)v69 + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    stack[-1] = v203;
    goto v44;

v44:
    v203 = stack[-1];
    if (v203 == nil) goto v84;
    v203 = stack[-1];
    v203 = qcar(v203);
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v69 = qvalue(elt(env, 5)); /* maxvar */
    v203 = qcar(v203);
    stack[-3] = v203;
    v203 = plus2(v69, v203);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    v69 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    v203 = (Lisp_Object)1; /* 0 */
    v203 = *(Lisp_Object *)((char *)v69 + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    if (v203 == nil) goto v78;
    v69 = stack[-3];
    v203 = qvalue(elt(env, 3)); /* jsi */
    v203 = cons(v69, v203);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    qvalue(elt(env, 3)) = v203; /* jsi */
    v203 = qvalue(elt(env, 1)); /* njsi */
    v203 = add1(v203);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    qvalue(elt(env, 1)) = v203; /* njsi */
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v69 = qvalue(elt(env, 5)); /* maxvar */
    v203 = stack[-3];
    v203 = plus2(v69, v203);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    v69 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    v203 = (Lisp_Object)17; /* 1 */
    v203 = *(Lisp_Object *)((char *)v69 + (CELL-TAG_VECTOR) + ((int32_t)v203/(16/CELL)));
    v203 = qcar(v203);
    v69 = qcar(v203);
    stack[0] = v69;
    v203 = stack[-2];
    v203 = (Lisp_Object)greaterp2(v69, v203);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v203 = v203 ? lisp_true : nil;
    env = stack[-5];
    if (v203 == nil) goto v78;
    v203 = stack[0];
    stack[-2] = v203;
    v203 = stack[-3];
    stack[-4] = v203;
    goto v78;

v78:
    v203 = stack[-1];
    v203 = qcdr(v203);
    stack[-1] = v203;
    goto v44;

v84:
    v203 = qvalue(elt(env, 3)); /* jsi */
    v203 = Lreverse(nil, v203);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    qvalue(elt(env, 3)) = v203; /* jsi */
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v106:
    popv(6);
    return nil;
}



/* Code for quotexf!* */

static Lisp_Object CC_quotexfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotexf*");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v42;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v6;

v6:
    v32 = stack[-2];
    if (v32 == nil) goto v7;
    v32 = stack[-2];
    v32 = qcar(v32);
    stack[0] = qcar(v32);
    v32 = stack[-2];
    v32 = qcar(v32);
    v31 = qcdr(v32);
    v32 = stack[-1];
    fn = elt(env, 1); /* quotfexf!*1 */
    v31 = (*qfn2(fn))(qenv(fn), v31, v32);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v32 = stack[-3];
    v32 = acons(stack[0], v31, v32);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    stack[-3] = v32;
    v32 = stack[-2];
    v32 = qcdr(v32);
    stack[-2] = v32;
    goto v6;

v7:
    v32 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v78:
    popv(5);
    return nil;
}



/* Code for f2df */

static Lisp_Object CC_f2df(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2df");
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
    v64 = stack[0];
    if (!consp(v64)) goto v44;
    v64 = stack[0];
    v64 = qcar(v64);
    if (!consp(v64)) goto v44;
    v64 = stack[0];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v65 = qcar(v64);
    v64 = qvalue(elt(env, 1)); /* zlist */
    v64 = Lmember(nil, v65, v64);
    if (v64 == nil) goto v23;
    v64 = stack[0];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v205 = qcar(v64);
    v64 = stack[0];
    v64 = qcar(v64);
    v64 = qcar(v64);
    v65 = qcdr(v64);
    v64 = qvalue(elt(env, 1)); /* zlist */
    fn = elt(env, 3); /* vp2df */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v205, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v64 = stack[0];
    v64 = qcar(v64);
    v64 = qcdr(v64);
    v64 = CC_f2df(env, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    fn = elt(env, 4); /* multdf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = CC_f2df(env, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    {
        Lisp_Object v137 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v137, v64);
    }

v23:
    v64 = stack[0];
    v64 = qcar(v64);
    v65 = qcar(v64);
    v64 = (Lisp_Object)17; /* 1 */
    v205 = cons(v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v65 = qvalue(elt(env, 2)); /* nil */
    v64 = (Lisp_Object)17; /* 1 */
    stack[-1] = acons(v205, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v64 = stack[0];
    v64 = qcar(v64);
    v64 = qcdr(v64);
    v64 = CC_f2df(env, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    fn = elt(env, 6); /* multdfconst */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v64 = stack[0];
    v64 = qcdr(v64);
    v64 = CC_f2df(env, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    {
        Lisp_Object v209 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v209, v64);
    }

v44:
    v65 = stack[0];
    v64 = (Lisp_Object)17; /* 1 */
    v64 = cons(v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* dfconst */
        return (*qfn1(fn))(qenv(fn), v64);
    }
/* error exit handlers */
v136:
    popv(3);
    return nil;
}



/* Code for matrixir */

static Lisp_Object MS_CDECL CC_matrixir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v177, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixir");
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
    fn = elt(env, 5); /* lex */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    fn = elt(env, 6); /* omobjs */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    v14 = v5;
    v5 = v14;
    v5 = qcdr(v5);
    v5 = qcar(v5);
    v5 = qcdr(v5);
    v5 = qcar(v5);
    v177 = qcar(v5);
    v5 = elt(env, 1); /* matrixcolumn */
    if (v177 == v5) goto v43;
    stack[0] = elt(env, 3); /* matrixrow */
    v5 = v14;
    fn = elt(env, 7); /* matrixelems */
    v177 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    v5 = qvalue(elt(env, 2)); /* nil */
    v5 = list2star(stack[0], v177, v5);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    v14 = v5;
    goto v51;

v51:
    v5 = elt(env, 4); /* matrix */
    v177 = qvalue(elt(env, 2)); /* nil */
    popv(2);
    return list2star(v5, v177, v14);

v43:
    stack[0] = elt(env, 1); /* matrixcolumn */
    v5 = v14;
    fn = elt(env, 7); /* matrixelems */
    v177 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    v5 = qvalue(elt(env, 2)); /* nil */
    v5 = list2star(stack[0], v177, v5);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    v14 = v5;
    goto v51;
/* error exit handlers */
v210:
    popv(2);
    return nil;
}



/* Code for dipdivmon */

static Lisp_Object MS_CDECL CC_dipdivmon(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipdivmon");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipdivmon");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v42,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v90;
    stack[-1] = v42;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v3;

v3:
    v202 = stack[-2];
    if (v202 == nil) goto v18;
    v202 = stack[-2];
    v30 = qcar(v202);
    v202 = stack[0];
    fn = elt(env, 1); /* evdif */
    v30 = (*qfn2(fn))(qenv(fn), v30, v202);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    v202 = stack[-3];
    v202 = cons(v30, v202);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    stack[-3] = v202;
    v202 = stack[-2];
    v202 = qcdr(v202);
    v30 = qcar(v202);
    v202 = stack[-1];
    fn = elt(env, 2); /* bcquot */
    v30 = (*qfn2(fn))(qenv(fn), v30, v202);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    v202 = stack[-3];
    v202 = cons(v30, v202);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-4];
    stack[-3] = v202;
    v202 = stack[-2];
    v202 = qcdr(v202);
    v202 = qcdr(v202);
    stack[-2] = v202;
    goto v3;

v18:
    v202 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v202);
    }
/* error exit handlers */
v5:
    popv(5);
    return nil;
}



/* Code for evalmember */

static Lisp_Object CC_evalmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v84 = v42;
    v44 = v0;
/* end of prologue */
    stack[0] = v44;
    fn = elt(env, 1); /* getrlist */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v193;
    v84 = Lmember(nil, stack[0], v84);
    { popv(1); return onevalue(v84); }
/* error exit handlers */
v193:
    popv(1);
    return nil;
}



/* Code for indordln */

static Lisp_Object CC_indordln(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v41;
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
    v41 = v0;
/* end of prologue */
    v25 = v41;
    if (v25 == nil) goto v1;
    v25 = v41;
    v25 = qcdr(v25);
    if (v25 == nil) { popv(2); return onevalue(v41); }
    v25 = v41;
    v25 = qcdr(v25);
    v25 = qcdr(v25);
    if (v25 == nil) goto v12;
    v25 = v41;
    stack[0] = qcar(v25);
    v25 = v41;
    v25 = qcdr(v25);
    v25 = CC_indordln(env, v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    {
        Lisp_Object v78 = stack[0];
        popv(2);
        fn = elt(env, 2); /* indordlad */
        return (*qfn2(fn))(qenv(fn), v78, v25);
    }

v12:
    v25 = v41;
    v25 = qcar(v25);
    v41 = qcdr(v41);
    v41 = qcar(v41);
    {
        popv(2);
        fn = elt(env, 3); /* indordl2 */
        return (*qfn2(fn))(qenv(fn), v25, v41);
    }

v1:
    v25 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v25); }
/* error exit handlers */
v9:
    popv(2);
    return nil;
}



/* Code for physopsubs */

static Lisp_Object CC_physopsubs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopsubs");
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
    stack[-2] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v212 = qvalue(elt(env, 2)); /* nil */
    v212 = ncons(v212);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-3];
    qvalue(elt(env, 1)) = v212; /* alglist!* */
    v212 = stack[-1];
    fn = elt(env, 11); /* physop2sq */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-3];
    stack[-1] = v212;
    v212 = qvalue(elt(env, 3)); /* physoplist!* */
    stack[0] = v212;
    goto v45;

v45:
    v212 = stack[0];
    if (v212 == nil) goto v38;
    v212 = stack[0];
    v212 = qcar(v212);
    v214 = v212;
    v213 = v214;
    v212 = elt(env, 4); /* rtype */
    v212 = Lremprop(nil, v213, v212);
    env = stack[-3];
    v213 = elt(env, 5); /* simpfn */
    v212 = elt(env, 6); /* simpiden */
    v212 = Lputprop(nil, 3, v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-3];
    v212 = stack[0];
    v212 = qcdr(v212);
    stack[0] = v212;
    goto v45;

v38:
    v213 = elt(env, 7); /* (dot) */
    v212 = elt(env, 8); /* physopfn */
    v212 = Lremflag(nil, v213, v212);
    env = stack[-3];
    v214 = elt(env, 9); /* dot */
    v213 = elt(env, 5); /* simpfn */
    v212 = elt(env, 6); /* simpiden */
    v212 = Lputprop(nil, 3, v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-3];
    v212 = stack[-1];
    fn = elt(env, 12); /* subs2 */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-3];
    stack[-1] = v212;
    v212 = stack[-1];
    fn = elt(env, 13); /* !*q2a */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-3];
    stack[-1] = v212;
    v212 = qvalue(elt(env, 3)); /* physoplist!* */
    stack[0] = v212;
    goto v215;

v215:
    v212 = stack[0];
    if (v212 == nil) goto v196;
    v212 = stack[0];
    v212 = qcar(v212);
    v214 = v212;
    v213 = v214;
    v212 = elt(env, 5); /* simpfn */
    v212 = Lremprop(nil, v213, v212);
    env = stack[-3];
    v213 = elt(env, 4); /* rtype */
    v212 = elt(env, 10); /* physop */
    v212 = Lputprop(nil, 3, v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-3];
    v212 = stack[0];
    v212 = qcdr(v212);
    stack[0] = v212;
    goto v215;

v196:
    v213 = elt(env, 9); /* dot */
    v212 = elt(env, 5); /* simpfn */
    v212 = Lremprop(nil, v213, v212);
    env = stack[-3];
    v213 = elt(env, 7); /* (dot) */
    v212 = elt(env, 8); /* physopfn */
    v212 = Lflag(nil, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-3];
    v212 = stack[-1];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    { popv(4); return onevalue(v212); }
/* error exit handlers */
v204:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for mapcarcar */

static Lisp_Object CC_mapcarcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8;
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
    v8 = v0;
/* end of prologue */
    stack[-3] = v8;
    v8 = stack[-3];
    if (v8 == nil) goto v192;
    v8 = stack[-3];
    v8 = qcar(v8);
    v8 = qcar(v8);
    v8 = ncons(v8);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    stack[-1] = v8;
    stack[-2] = v8;
    goto v3;

v3:
    v8 = stack[-3];
    v8 = qcdr(v8);
    stack[-3] = v8;
    v8 = stack[-3];
    if (v8 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v8 = stack[-3];
    v8 = qcar(v8);
    v8 = qcar(v8);
    v8 = ncons(v8);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v8 = Lrplacd(nil, stack[0], v8);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v8 = stack[-1];
    v8 = qcdr(v8);
    stack[-1] = v8;
    goto v3;

v192:
    v8 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v8); }
/* error exit handlers */
v51:
    popv(5);
    return nil;
}



/* Code for negex */

static Lisp_Object CC_negex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negex");
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
    goto v2;

v2:
    v141 = stack[-1];
    if (v141 == nil) goto v33;
    v141 = stack[-1];
    v141 = qcar(v141);
    stack[0] = qcar(v141);
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    fn = elt(env, 1); /* negf */
    v142 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v141 = stack[-2];
    v141 = acons(stack[0], v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    stack[-2] = v141;
    v141 = stack[-1];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v2;

v33:
    v141 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v141);
    }
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for generic_arguments */

static Lisp_Object CC_generic_arguments(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v12, v13;
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
    v80 = v0;
/* end of prologue */
    v13 = elt(env, 1); /* list */
    v12 = qcar(v80);
    v80 = elt(env, 2); /* generic_function */
    v80 = get(v12, v80);
    return cons(v13, v80);
}



/* Code for mksfpf */

static Lisp_Object CC_mksfpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksfpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v42;
    v69 = v0;
/* end of prologue */
    fn = elt(env, 4); /* mkprod */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-2];
    stack[-1] = v69;
    v138 = stack[0];
    v69 = (Lisp_Object)17; /* 1 */
    if (v138 == v69) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v69 = stack[-1];
    if (!consp(v69)) goto v19;
    v69 = stack[-1];
    v69 = qcar(v69);
    if (!consp(v69)) goto v19;
    v138 = stack[0];
    v69 = (Lisp_Object)1; /* 0 */
    v69 = (Lisp_Object)geq2(v138, v69);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v69 = v69 ? lisp_true : nil;
    env = stack[-2];
    if (v69 == nil) goto v176;
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = qcdr(v69);
    v69 = Lonep(nil, v69);
    env = stack[-2];
    if (v69 == nil) goto v176;
    v69 = stack[-1];
    v69 = qcdr(v69);
    if (!(v69 == nil)) goto v176;
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v138 = qcdr(v69);
    v69 = stack[0];
    v138 = times2(v138, v69);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-2];
    v69 = stack[-1];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = qcar(v69);
    stack[-1] = v138;
    stack[0] = v69;
    v138 = stack[0];
    v69 = qvalue(elt(env, 1)); /* asymplis!* */
    v69 = Lassoc(nil, v138, v69);
    v138 = v69;
    v69 = qvalue(elt(env, 2)); /* subfg!* */
    if (v69 == nil) goto v111;
    v69 = v138;
    if (v69 == nil) goto v111;
    v69 = v138;
    v138 = qcdr(v69);
    v69 = stack[-1];
    v69 = (Lisp_Object)lesseq2(v138, v69);
    nil = C_nil;
    if (exception_pending()) goto v216;
    v69 = v69 ? lisp_true : nil;
    env = stack[-2];
    if (v69 == nil) goto v111;
    v69 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v69); }

v111:
    v138 = stack[0];
    v69 = stack[-1];
    fn = elt(env, 5); /* mksp */
    v138 = (*qfn2(fn))(qenv(fn), v138, v69);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-2];
    v69 = (Lisp_Object)17; /* 1 */
    v69 = cons(v138, v69);
    nil = C_nil;
    if (exception_pending()) goto v216;
    popv(3);
    return ncons(v69);

v176:
    v138 = stack[-1];
    v69 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* exptf2 */
        return (*qfn2(fn))(qenv(fn), v138, v69);
    }

v19:
    v138 = stack[-1];
    v69 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v138, v69);
    }
/* error exit handlers */
v216:
    popv(3);
    return nil;
}



/* Code for get_char_group */

static Lisp_Object CC_get_char_group(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v6;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_char_group");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    v6 = qcar(v6);
    return onevalue(v6);
}



/* Code for ev_2a */

static Lisp_Object CC_ev_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    v192 = v18;
    v18 = qvalue(elt(env, 1)); /* dip_vars!* */
    {
        fn = elt(env, 2); /* ev_2a1 */
        return (*qfn2(fn))(qenv(fn), v192, v18);
    }
}



/* Code for matrixml */

static Lisp_Object CC_matrixml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixml");
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
    v41 = Llength(nil, v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    v25 = (Lisp_Object)17; /* 1 */
    if (v41 == v25) goto v6;
    v25 = elt(env, 1); /* "<matrix>" */
    fn = elt(env, 4); /* printout */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    v41 = qvalue(elt(env, 2)); /* indent */
    v25 = (Lisp_Object)49; /* 3 */
    v25 = plus2(v41, v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    qvalue(elt(env, 2)) = v25; /* indent */
    v25 = stack[0];
    fn = elt(env, 5); /* matrix_rows */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    v41 = qvalue(elt(env, 2)); /* indent */
    v25 = (Lisp_Object)49; /* 3 */
    v25 = difference2(v41, v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-1];
    qvalue(elt(env, 2)) = v25; /* indent */
    v25 = elt(env, 3); /* "</matrix>" */
    fn = elt(env, 4); /* printout */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    goto v2;

v2:
    v25 = nil;
    { popv(2); return onevalue(v25); }

v6:
    v25 = stack[0];
    fn = elt(env, 6); /* vectorml */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v9;
    goto v2;
/* error exit handlers */
v9:
    popv(2);
    return nil;
}



/* Code for addexptsdf */

static Lisp_Object CC_addexptsdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addexptsdf");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v42;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v6;

v6:
    v217 = stack[-1];
    if (v217 == nil) goto v7;
    v217 = stack[0];
    if (v217 == nil) goto v142;
    v217 = stack[-1];
    v92 = qcar(v217);
    v217 = stack[0];
    v217 = qcar(v217);
    fn = elt(env, 3); /* exptplus */
    v92 = (*qfn2(fn))(qenv(fn), v92, v217);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    v217 = stack[-2];
    v217 = cons(v92, v217);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[-2] = v217;
    v217 = stack[-1];
    v217 = qcdr(v217);
    stack[-1] = v217;
    v217 = stack[0];
    v217 = qcdr(v217);
    stack[0] = v217;
    goto v6;

v142:
    stack[0] = stack[-2];
    v217 = elt(env, 2); /* "Y too long" */
    fn = elt(env, 4); /* interr */
    v217 = (*qfn1(fn))(qenv(fn), v217);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    {
        Lisp_Object v93 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v93, v217);
    }

v7:
    v217 = stack[0];
    if (v217 == nil) goto v45;
    stack[0] = stack[-2];
    v217 = elt(env, 1); /* "X too long" */
    fn = elt(env, 4); /* interr */
    v217 = (*qfn1(fn))(qenv(fn), v217);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    {
        Lisp_Object v215 = stack[0];
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v215, v217);
    }

v45:
    v217 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v217);
    }
/* error exit handlers */
v40:
    popv(4);
    return nil;
}



/* Code for multup */

static Lisp_Object CC_multup(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47;
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
    v46 = v0;
/* end of prologue */
    v47 = (Lisp_Object)17; /* 1 */
    stack[0] = v46;
    goto v7;

v7:
    v46 = stack[0];
    if (v46 == nil) { popv(2); return onevalue(v47); }
    v46 = stack[0];
    v46 = qcar(v46);
    fn = elt(env, 2); /* multf */
    v46 = (*qfn2(fn))(qenv(fn), v47, v46);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-1];
    v47 = v46;
    v46 = stack[0];
    v46 = qcdr(v46);
    stack[0] = v46;
    goto v7;
/* error exit handlers */
v142:
    popv(2);
    return nil;
}



/* Code for gfftimes */

static Lisp_Object CC_gfftimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v28, v105;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfftimes");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v28 = v42;
    v105 = v0;
/* end of prologue */
    v17 = v105;
    v17 = qcar(v17);
    stack[-4] = v17;
    v17 = v105;
    v17 = qcdr(v17);
    stack[-3] = v17;
    v17 = v28;
    v17 = qcar(v17);
    stack[-2] = v17;
    v17 = v28;
    v17 = qcdr(v17);
    stack[-1] = v17;
    v28 = stack[-4];
    v17 = stack[-2];
    stack[0] = times2(v28, v17);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-5];
    v28 = stack[-3];
    v17 = stack[-1];
    v17 = times2(v28, v17);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-5];
    stack[0] = difference2(stack[0], v17);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-5];
    v28 = stack[-4];
    v17 = stack[-1];
    stack[-1] = times2(v28, v17);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-5];
    v28 = stack[-3];
    v17 = stack[-2];
    v17 = times2(v28, v17);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-5];
    v17 = plus2(stack[-1], v17);
    nil = C_nil;
    if (exception_pending()) goto v201;
    {
        Lisp_Object v218 = stack[0];
        popv(6);
        return cons(v218, v17);
    }
/* error exit handlers */
v201:
    popv(6);
    return nil;
}



/* Code for mv!-compact */

static Lisp_Object MS_CDECL CC_mvKcompact(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v174, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv-compact");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-compact");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v42,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v90;
    stack[-2] = v42;
    stack[-3] = v0;
/* end of prologue */

v194:
    v175 = stack[-3];
    if (v175 == nil) goto v18;
    v174 = stack[-3];
    v175 = stack[-2];
    fn = elt(env, 1); /* mv!-pow!-chk */
    v175 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    stack[-4] = v175;
    if (v175 == nil) goto v5;
    stack[0] = stack[-3];
    v174 = stack[-4];
    v175 = stack[-2];
    fn = elt(env, 2); /* mv!-pow!-mv!-!+ */
    v175 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    fn = elt(env, 3); /* mv!-compact2 */
    v175 = (*qfn2(fn))(qenv(fn), stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    stack[0] = v175;
    if (v175 == nil) goto v5;
    v103 = stack[0];
    v174 = stack[-2];
    v175 = stack[-1];
    stack[-3] = v103;
    stack[-2] = v174;
    stack[-1] = v175;
    goto v194;

v5:
    v174 = stack[-3];
    v175 = stack[-2];
    v175 = qcdr(v175);
    fn = elt(env, 1); /* mv!-pow!-chk */
    v175 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    stack[-4] = v175;
    if (v175 == nil) goto v69;
    v174 = stack[-4];
    v175 = stack[-2];
    v175 = qcar(v175);
    v175 = qcar(v175);
    fn = elt(env, 4); /* mv!-pow!-!+ */
    v174 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    stack[0] = v174;
    v175 = stack[-1];
    fn = elt(env, 5); /* mv!-pow!-assoc */
    v175 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    if (!(v175 == nil)) goto v69;
    v103 = stack[0];
    v174 = (Lisp_Object)1; /* 0 */
    v175 = stack[-3];
    stack[0] = acons(v103, v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    v174 = stack[-4];
    v175 = stack[-2];
    fn = elt(env, 2); /* mv!-pow!-mv!-!+ */
    v175 = (*qfn2(fn))(qenv(fn), v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    fn = elt(env, 3); /* mv!-compact2 */
    v175 = (*qfn2(fn))(qenv(fn), stack[0], v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    stack[0] = v175;
    if (v175 == nil) goto v69;
    v103 = stack[0];
    v174 = stack[-2];
    v175 = stack[-1];
    stack[-3] = v103;
    stack[-2] = v174;
    stack[-1] = v175;
    goto v194;

v69:
    v175 = stack[-3];
    stack[0] = qcdr(v175);
    v175 = stack[-3];
    v174 = qcar(v175);
    v175 = stack[-1];
    v175 = cons(v174, v175);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-5];
    stack[-3] = stack[0];
    stack[-1] = v175;
    goto v194;

v18:
    v175 = stack[-1];
    {
        popv(6);
        fn = elt(env, 6); /* mv!-reverse */
        return (*qfn1(fn))(qenv(fn), v175);
    }
/* error exit handlers */
v148:
    popv(6);
    return nil;
}



/* Code for groeb!=crita */

static Lisp_Object CC_groebMcrita(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v192;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=crita");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    v192 = v18;
    v18 = elt(env, 1); /* groeb!=testa */
    {
        fn = elt(env, 2); /* listminimize */
        return (*qfn2(fn))(qenv(fn), v192, v18);
    }
}



/* Code for simp!-prop */

static Lisp_Object CC_simpKprop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v157, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp-prop");
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
    stack[-2] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* propvars!* */
    qvalue(elt(env, 1)) = nil; /* propvars!* */
    v229 = stack[-2];
    v229 = qcdr(v229);
    stack[-4] = v229;
    v229 = stack[-4];
    if (v229 == nil) goto v21;
    v229 = stack[-4];
    v229 = qcar(v229);
    fn = elt(env, 14); /* reval */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    stack[-1] = v229;
    stack[-3] = v229;
    goto v84;

v84:
    v229 = stack[-4];
    v229 = qcdr(v229);
    stack[-4] = v229;
    v229 = stack[-4];
    if (v229 == nil) goto v46;
    stack[0] = stack[-1];
    v229 = stack[-4];
    v229 = qcar(v229);
    fn = elt(env, 14); /* reval */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v229 = Lrplacd(nil, stack[0], v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v229 = stack[-1];
    v229 = qcdr(v229);
    stack[-1] = v229;
    goto v84;

v46:
    v229 = stack[-3];
    goto v192;

v192:
    stack[-5] = v229;
    v157 = elt(env, 3); /* and */
    v229 = stack[-5];
    v229 = Lmember(nil, v157, v229);
    if (v229 == nil) goto v17;
    v229 = elt(env, 4); /* or */
    qvalue(elt(env, 5)) = v229; /* !'and */
    v229 = elt(env, 3); /* and */
    qvalue(elt(env, 6)) = v229; /* !'or */
    v229 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v229; /* !'true */
    v229 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 8)) = v229; /* !'false */
    goto v76;

v76:
    v229 = stack[-2];
    v157 = qcar(v229);
    v229 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v229 = (*qfn2(fn))(qenv(fn), v157, v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    fn = elt(env, 16); /* prepf */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    fn = elt(env, 14); /* reval */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v156 = v229;
    v157 = v156;
    v229 = (Lisp_Object)1; /* 0 */
    if (v157 == v229) goto v129;
    v229 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-4] = v229;
    goto v121;

v121:
    v229 = stack[-4];
    if (v229 == nil) goto v208;
    v229 = stack[-4];
    v229 = qcar(v229);
    stack[-3] = elt(env, 10); /* times */
    stack[-2] = v156;
    stack[-1] = qvalue(elt(env, 6)); /* !'or */
    stack[0] = v229;
    v157 = elt(env, 11); /* not */
    v229 = list2(v157, v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v157 = list3(stack[-1], stack[0], v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v229 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 15); /* simp!-prop1 */
    v229 = (*qfn2(fn))(qenv(fn), v157, v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    fn = elt(env, 16); /* prepf */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v229 = list3(stack[-3], stack[-2], v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    fn = elt(env, 14); /* reval */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v156 = v229;
    v229 = stack[-4];
    v229 = qcdr(v229);
    stack[-4] = v229;
    goto v121;

v208:
    v229 = v156;
    fn = elt(env, 17); /* simp!-prop!-dist */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v156 = v229;
    v157 = elt(env, 12); /* full */
    v229 = stack[-5];
    v229 = Lmember(nil, v157, v229);
    if (!(v229 == nil)) goto v230;
    v229 = v156;
    fn = elt(env, 18); /* simp!-prop2 */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v156 = v229;
    goto v230;

v230:
    v229 = v156;
    fn = elt(env, 19); /* simp!-prop!-form */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v156 = v229;
    v229 = v156;
    if (is_number(v229)) goto v123;
    v229 = v156;
    if (!consp(v229)) goto v231;
    v229 = elt(env, 13); /* boolean */
    v157 = v156;
    v229 = list2(v229, v157);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v156 = v229;
    goto v231;

v231:
    v157 = v156;
    v229 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 20); /* to */
    v157 = (*qfn2(fn))(qenv(fn), v157, v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v229 = (Lisp_Object)17; /* 1 */
    v156 = cons(v157, v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    v157 = qvalue(elt(env, 2)); /* nil */
    v229 = (Lisp_Object)17; /* 1 */
    v229 = acons(v156, v157, v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    goto v6;

v6:
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    { popv(8); return onevalue(v229); }

v123:
    v157 = v156;
    v229 = (Lisp_Object)17; /* 1 */
    v229 = cons(v157, v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    goto v6;

v129:
    v229 = qvalue(elt(env, 8)); /* !'false */
    fn = elt(env, 21); /* simp */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v160;
    env = stack[-7];
    goto v6;

v17:
    v229 = elt(env, 3); /* and */
    qvalue(elt(env, 5)) = v229; /* !'and */
    v229 = elt(env, 4); /* or */
    qvalue(elt(env, 6)) = v229; /* !'or */
    v229 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v229; /* !'true */
    v229 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 8)) = v229; /* !'false */
    goto v76;

v21:
    v229 = qvalue(elt(env, 2)); /* nil */
    goto v192;
/* error exit handlers */
v160:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* propvars!* */
    popv(8);
    return nil;
}



/* Code for makecoeffpairs */

static Lisp_Object MS_CDECL CC_makecoeffpairs(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, Lisp_Object v48, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v58, v43, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makecoeffpairs");
#endif
    if (stack >= stacklimit)
    {
        push4(v48,v90,v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v42,v90,v48);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v55 = v48;
    v58 = v90;
    v43 = v42;
    v22 = v0;
/* end of prologue */
    fn = elt(env, 1); /* makecoeffpairs1 */
    v55 = (*qfnn(fn))(qenv(fn), 4, v22, v43, v58, v55);
    errexit();
    v55 = qcdr(v55);
        return Lnreverse(nil, v55);
}



/* Code for mk!+equation */

static Lisp_Object CC_mkLequation(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v21, v80;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+equation");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v145 = v42;
    v21 = v0;
/* end of prologue */
    v80 = elt(env, 1); /* equal */
    return list3(v80, v21, v145);
}



/* Code for quotientml */

static Lisp_Object CC_quotientml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotientml");
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
    v92 = qcar(v92);
    if (!(is_number(v92))) goto v206;
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    if (!(is_number(v92))) goto v206;
    v92 = qvalue(elt(env, 1)); /* !*web */
    if (v92 == nil) goto v21;
    v92 = elt(env, 3); /* "<cn type=&quot;rational&quot;> " */
    fn = elt(env, 9); /* printout */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    goto v145;

v145:
    v92 = stack[0];
    v92 = qcar(v92);
    v92 = Lprinc(nil, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v92 = elt(env, 4); /* " <sep/> " */
    v92 = Lprinc(nil, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    v92 = Lprinc(nil, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v92 = elt(env, 5); /* " </cn>" */
    v92 = Lprinc(nil, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    goto v2;

v2:
    v92 = nil;
    { popv(2); return onevalue(v92); }

v21:
    v92 = elt(env, 2); /* "<cn type=""rational""> " */
    fn = elt(env, 9); /* printout */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    goto v145;

v206:
    v92 = elt(env, 6); /* "<apply><divide/>" */
    fn = elt(env, 9); /* printout */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v17 = qvalue(elt(env, 7)); /* indent */
    v92 = (Lisp_Object)49; /* 3 */
    v92 = plus2(v17, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    qvalue(elt(env, 7)) = v92; /* indent */
    v92 = stack[0];
    v92 = qcar(v92);
    fn = elt(env, 10); /* expression */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    fn = elt(env, 10); /* expression */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    v17 = qvalue(elt(env, 7)); /* indent */
    v92 = (Lisp_Object)49; /* 3 */
    v92 = difference2(v17, v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-1];
    qvalue(elt(env, 7)) = v92; /* indent */
    v92 = elt(env, 8); /* "</apply>" */
    fn = elt(env, 9); /* printout */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v105;
    goto v2;
/* error exit handlers */
v105:
    popv(2);
    return nil;
}



/* Code for mkdmoderr */

static Lisp_Object CC_mkdmoderr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkdmoderr");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v42;
    v19 = v0;
/* end of prologue */
    stack[-4] = elt(env, 1); /* lambda */
    stack[-2] = elt(env, 2); /* (!*x!*) */
    stack[-1] = elt(env, 3); /* dmoderr */
    stack[0] = Lmkquote(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v19 = stack[-3];
    v19 = Lmkquote(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-5];
    v19 = list3(stack[-1], stack[0], v19);
    nil = C_nil;
    if (exception_pending()) goto v47;
    {
        Lisp_Object v141 = stack[-4];
        Lisp_Object v142 = stack[-2];
        popv(6);
        return list3(v141, v142, v19);
    }
/* error exit handlers */
v47:
    popv(6);
    return nil;
}



/* Code for reduce!-ratios */

static Lisp_Object CC_reduceKratios(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-ratios");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v42;
    stack[-2] = v0;
/* end of prologue */

v192:
    v105 = stack[-2];
    v28 = stack[-1];
    fn = elt(env, 1); /* red!-ratios1 */
    v28 = (*qfn2(fn))(qenv(fn), v105, v28);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    stack[-3] = v28;
    if (v28 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v28 = stack[-3];
    v105 = qcar(v28);
    v28 = stack[-2];
    fn = elt(env, 2); /* mv!-domainlist!-!* */
    stack[0] = (*qfn2(fn))(qenv(fn), v105, v28);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v28 = stack[-3];
    v105 = qcdr(v28);
    v28 = stack[-1];
    fn = elt(env, 2); /* mv!-domainlist!-!* */
    v28 = (*qfn2(fn))(qenv(fn), v105, v28);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    fn = elt(env, 3); /* mv!-domainlist!-!- */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    stack[-3] = v28;
    v28 = stack[-2];
    fn = elt(env, 4); /* zeros */
    stack[0] = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v28 = stack[-3];
    fn = elt(env, 4); /* zeros */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-4];
    v28 = (Lisp_Object)geq2(stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v200;
    v28 = v28 ? lisp_true : nil;
    env = stack[-4];
    if (!(v28 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v105 = stack[-3];
    v28 = stack[-1];
    stack[-2] = v105;
    stack[-1] = v28;
    goto v192;
/* error exit handlers */
v200:
    popv(5);
    return nil;
}



/* Code for simpsqrt2 */

static Lisp_Object CC_simpsqrt2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrt2");
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
    v50 = stack[0];
    fn = elt(env, 2); /* minusf */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-1];
    if (v50 == nil) goto v8;
    v51 = stack[0];
    v50 = (Lisp_Object)-15; /* -1 */
    v50 = Leqn(nil, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-1];
    if (v50 == nil) goto v55;
    v50 = qvalue(elt(env, 1)); /* gaussiani */
    { popv(2); return onevalue(v50); }

v55:
    v50 = stack[0];
    fn = elt(env, 3); /* negf */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-1];
    v51 = v50;
    v50 = v51;
    if (is_number(v50)) goto v142;
    v50 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* simpsqrt3 */
        return (*qfn1(fn))(qenv(fn), v50);
    }

v142:
    stack[0] = qvalue(elt(env, 1)); /* gaussiani */
    v50 = v51;
    fn = elt(env, 4); /* simpsqrt3 */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-1];
    {
        Lisp_Object v179 = stack[0];
        popv(2);
        fn = elt(env, 5); /* multf */
        return (*qfn2(fn))(qenv(fn), v179, v50);
    }

v8:
    v50 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* simpsqrt3 */
        return (*qfn1(fn))(qenv(fn), v50);
    }
/* error exit handlers */
v178:
    popv(2);
    return nil;
}



/* Code for sfto_updecf */

static Lisp_Object CC_sfto_updecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_updecf");
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
    v13 = v0;
/* end of prologue */
    v12 = qvalue(elt(env, 1)); /* !*sfto_yun */
    if (v12 == nil) goto v2;
    v12 = v13;
    {
        popv(1);
        fn = elt(env, 4); /* sfto_yun!-updecf */
        return (*qfn1(fn))(qenv(fn), v12);
    }

v2:
    v12 = qvalue(elt(env, 2)); /* !*sfto_musser */
    if (v12 == nil) goto v45;
    v12 = v13;
    {
        popv(1);
        fn = elt(env, 5); /* sfto_musser!-updecf */
        return (*qfn1(fn))(qenv(fn), v12);
    }

v45:
    v12 = elt(env, 3); /* "sfto_updecf: select a decomposition method" 
*/
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* rederr */
        return (*qfn1(fn))(qenv(fn), v12);
    }
/* error exit handlers */
v55:
    popv(1);
    return nil;
}



/* Code for dvfsf_simplat1 */

static Lisp_Object CC_dvfsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v4, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v42;
    stack[-2] = v0;
/* end of prologue */
    v112 = stack[-2];
    fn = elt(env, 3); /* dvfsf_op */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v29 = v112;
    v4 = v29;
    v112 = elt(env, 1); /* equal */
    if (v4 == v112) goto v114;
    v4 = v29;
    v112 = elt(env, 2); /* neq */
    if (v4 == v112) goto v114;
    stack[-3] = v29;
    v112 = stack[-2];
    fn = elt(env, 4); /* dvfsf_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v112 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2r */
    v4 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v112 = stack[-1];
    {
        Lisp_Object v124 = stack[-3];
        Lisp_Object v217 = stack[0];
        popv(5);
        fn = elt(env, 6); /* dvfsf_saval */
        return (*qfnn(fn))(qenv(fn), 4, v124, v217, v4, v112);
    }

v114:
    stack[0] = v29;
    v112 = stack[-2];
    fn = elt(env, 4); /* dvfsf_arg2l */
    v4 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-4];
    v112 = stack[-1];
    {
        Lisp_Object v92 = stack[0];
        popv(5);
        fn = elt(env, 7); /* dvfsf_safield */
        return (*qfnn(fn))(qenv(fn), 3, v92, v4, v112);
    }
/* error exit handlers */
v210:
    popv(5);
    return nil;
}



/* Code for ev_mtest!? */

static Lisp_Object CC_ev_mtestW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v31, v25, v41, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_mtest?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v42;
    v41 = v0;
/* end of prologue */
    v32 = qvalue(elt(env, 1)); /* t */
    v8 = v32;
    goto v7;

v7:
    v32 = v41;
    if (v32 == nil) return onevalue(v8);
    v32 = v8;
    if (v32 == nil) return onevalue(v8);
    v32 = v41;
    v31 = qcar(v32);
    v32 = v25;
    v32 = qcar(v32);
    if (((int32_t)(v31)) < ((int32_t)(v32))) goto v55;
    v32 = v41;
    v32 = qcdr(v32);
    v41 = v32;
    v32 = v25;
    v32 = qcdr(v32);
    v25 = v32;
    goto v7;

v55:
    v32 = qvalue(elt(env, 2)); /* nil */
    v8 = v32;
    v41 = v32;
    goto v7;
}



/* Code for lowupperlimitml */

static Lisp_Object CC_lowupperlimitml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowupperlimitml");
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
    v114 = elt(env, 1); /* "<lowlimit>" */
    fn = elt(env, 7); /* printout */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = qcar(v114);
    fn = elt(env, 9); /* expression */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = elt(env, 4); /* "</lowlimit>" */
    fn = elt(env, 7); /* printout */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = elt(env, 5); /* "<uplimit>" */
    fn = elt(env, 7); /* printout */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 8); /* indent!* */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = stack[0];
    v114 = qcdr(v114);
    v114 = qcdr(v114);
    v114 = qcar(v114);
    fn = elt(env, 9); /* expression */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* indent!* */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v114 = elt(env, 6); /* "</uplimit>" */
    fn = elt(env, 7); /* printout */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v114 = nil;
    { popv(2); return onevalue(v114); }
/* error exit handlers */
v46:
    popv(2);
    return nil;
}



/* Code for ps!:mkpow */

static Lisp_Object MS_CDECL CC_psTmkpow(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v17, v28, v105;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:mkpow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:mkpow");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v42,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v90;
    v28 = v42;
    v105 = v0;
/* end of prologue */
    v17 = v28;
    v92 = (Lisp_Object)1; /* 0 */
    if (v17 == v92) goto v6;
    v17 = v28;
    v92 = (Lisp_Object)17; /* 1 */
    if (v17 == v92) goto v55;
    v92 = elt(env, 1); /* expt */
    v17 = v105;
    v92 = list3(v92, v17, v28);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-1];
    goto v13;

v13:
    v17 = stack[0];
    if (v17 == nil) goto v15;
    v28 = elt(env, 2); /* quotient */
    v17 = (Lisp_Object)17; /* 1 */
    v92 = list3(v28, v17, v92);
    nil = C_nil;
    if (exception_pending()) goto v93;
    popv(2);
    return ncons(v92);

v15:
    popv(2);
    return ncons(v92);

v55:
    v92 = v105;
    goto v13;

v6:
    v92 = (Lisp_Object)17; /* 1 */
    popv(2);
    return ncons(v92);
/* error exit handlers */
v93:
    popv(2);
    return nil;
}



/* Code for make_wedge_pair */

static Lisp_Object CC_make_wedge_pair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v75, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make_wedge_pair");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v42;
    stack[-2] = v0;
/* end of prologue */
    v75 = stack[-2];
    v146 = stack[-2];
    stack[0] = list2(v75, v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v146 = stack[-1];
    fn = elt(env, 5); /* xval */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    fn = elt(env, 6); /* xlcm */
    v146 = (*qfn2(fn))(qenv(fn), stack[0], v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    stack[-3] = v146;
    v146 = qvalue(elt(env, 1)); /* !*twosided */
    if (v146 == nil) goto v16;
    v146 = qvalue(elt(env, 2)); /* xtruncate!* */
    if (!(v146 == nil)) goto v16;

v41:
    v75 = stack[-2];
    v146 = stack[-1];
    fn = elt(env, 7); /* overall_factor */
    v146 = (*qfn2(fn))(qenv(fn), v75, v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    if (v146 == nil) goto v31;
    v146 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v146); }

v31:
    v146 = stack[-3];
    fn = elt(env, 8); /* mknwedge */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    fn = elt(env, 9); /* xdegreecheck */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    if (v146 == nil) goto v15;
    v146 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v146); }

v15:
    stack[0] = elt(env, 4); /* wedge_pair */
    v128 = stack[-2];
    v75 = (Lisp_Object)17; /* 1 */
    v146 = (Lisp_Object)17; /* 1 */
    v146 = list2star(v128, v75, v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v75 = ncons(v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    v146 = stack[-1];
    {
        Lisp_Object v23 = stack[-3];
        Lisp_Object v20 = stack[0];
        popv(5);
        return list4(v23, v20, v75, v146);
    }

v16:
    stack[0] = stack[-2];
    v146 = stack[-1];
    fn = elt(env, 5); /* xval */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v146 = Lmemq(nil, stack[0], v146);
    if (!(v146 == nil)) goto v41;
    v146 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v146); }
/* error exit handlers */
v24:
    popv(5);
    return nil;
}



/* Code for force!-to!-dm */

static Lisp_Object CC_forceKtoKdm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v108, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for force-to-dm");
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
    v108 = v0;
/* end of prologue */

v1:
    v111 = v108;
    if (!consp(v111)) goto v33;
    v111 = v108;
    v111 = qcar(v111);
    if (!consp(v111)) goto v33;
    v111 = v108;
    fn = elt(env, 6); /* prepf */
    v108 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v111 = elt(env, 1); /* "number" */
    {
        popv(2);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v108, v111);
    }

v33:
    v111 = v108;
    if (v111 == nil) goto v43;
    v111 = v108;
    if (is_number(v111)) goto v206;
    v111 = v108;
    v111 = Lconsp(nil, v111);
    env = stack[-1];
    if (v111 == nil) goto v14;
    v111 = v108;
    v109 = qcar(v111);
    v111 = qvalue(elt(env, 2)); /* dmode!* */
    if (equal(v109, v111)) { popv(2); return onevalue(v108); }
    else goto v14;

v14:
    v111 = v108;
    v111 = Lconsp(nil, v111);
    env = stack[-1];
    if (v111 == nil) goto v217;
    v111 = v108;
    v109 = qcar(v111);
    v111 = qvalue(elt(env, 2)); /* dmode!* */
    v111 = get(v109, v111);
    env = stack[-1];
    goto v124;

v124:
    v109 = v111;
    v111 = v109;
    if (v111 == nil) goto v208;
    stack[0] = v109;
    v111 = v108;
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    {
        Lisp_Object v205 = stack[0];
        popv(2);
        fn = elt(env, 8); /* apply */
        return (*qfn2(fn))(qenv(fn), v205, v111);
    }

v208:
    v111 = elt(env, 5); /* "conversion error with " */
    v111 = list2(v111, v108);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 9); /* rederr */
        return (*qfn1(fn))(qenv(fn), v111);
    }

v217:
    v111 = qvalue(elt(env, 4)); /* nil */
    goto v124;

v206:
    v109 = qvalue(elt(env, 2)); /* dmode!* */
    v111 = elt(env, 3); /* i2d */
    stack[0] = get(v109, v111);
    env = stack[-1];
    v111 = v108;
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    {
        Lisp_Object v149 = stack[0];
        popv(2);
        fn = elt(env, 8); /* apply */
        return (*qfn2(fn))(qenv(fn), v149, v111);
    }

v43:
    v111 = (Lisp_Object)1; /* 0 */
    v108 = v111;
    goto v1;
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for toolongassignp */

static Lisp_Object CC_toolongassignp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for toolongassignp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v3 = qcdr(v3);
    v3 = qcdr(v3);
    v3 = qcar(v3);
    {
        fn = elt(env, 1); /* toolongexpp */
        return (*qfn1(fn))(qenv(fn), v3);
    }
}



/* Code for dfdeg */

static Lisp_Object CC_dfdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v141;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfdeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v42;
    v141 = v0;
/* end of prologue */
    v47 = Lmember(nil, v47, v141);
    v141 = v47;
    if (v47 == nil) goto v2;
    v47 = v141;
    v47 = qcdr(v47);
    if (v47 == nil) goto v145;
    v47 = v141;
    v47 = qcdr(v47);
    v47 = qcar(v47);
    v47 = integerp(v47);
    if (v47 == nil) goto v145;
    v47 = v141;
    v47 = qcdr(v47);
    v47 = qcar(v47);
    return onevalue(v47);

v145:
    v47 = (Lisp_Object)17; /* 1 */
    return onevalue(v47);

v2:
    v47 = (Lisp_Object)1; /* 0 */
    return onevalue(v47);
}



/* Code for coeff_calc */

static Lisp_Object MS_CDECL CC_coeff_calc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v22, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff_calc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_calc");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v42,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v43 = v90;
    v22 = v42;
    v91 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* plus */
    fn = elt(env, 2); /* coeff1_calc */
    v43 = (*qfnn(fn))(qenv(fn), 3, v91, v22, v43);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v43 = cons(stack[0], v43);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v43);
    }
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for fs!:subang */

static Lisp_Object MS_CDECL CC_fsTsubang(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v42,
                         Lisp_Object v90, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v86, v89, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fs:subang");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:subang");
#endif
    if (stack >= stacklimit)
    {
        push3(v90,v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v42,v90);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v90;
    stack[-6] = v42;
    stack[-7] = v0;
/* end of prologue */
    v233 = stack[-7];
    if (v233 == nil) goto v6;
    v233 = (Lisp_Object)113; /* 7 */
    v233 = Lmkvect(nil, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-9];
    stack[-8] = v233;
    v86 = stack[-7];
    v233 = (Lisp_Object)33; /* 2 */
    v86 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    v233 = stack[-6];
    v233 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    stack[-4] = v233;
    v233 = (Lisp_Object)1; /* 0 */
    stack[-3] = v233;
    goto v8;

v8:
    v86 = (Lisp_Object)113; /* 7 */
    v233 = stack[-3];
    v233 = difference2(v86, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-9];
    v233 = Lminusp(nil, v233);
    env = stack[-9];
    if (v233 == nil) goto v112;
    v86 = stack[-7];
    v233 = (Lisp_Object)49; /* 3 */
    v89 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    v86 = stack[-6];
    v233 = stack[-5];
    stack[0] = CC_fsTsubang(env, 3, v89, v86, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-9];
    v86 = stack[-7];
    v233 = (Lisp_Object)17; /* 1 */
    v234 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    v89 = stack[-8];
    v86 = stack[-7];
    v233 = (Lisp_Object)1; /* 0 */
    v233 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    fn = elt(env, 2); /* make!-term */
    v233 = (*qfnn(fn))(qenv(fn), 3, v234, v89, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-9];
    {
        Lisp_Object v236 = stack[0];
        popv(10);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v236, v233);
    }

v112:
    v86 = stack[-3];
    v233 = stack[-6];
    if (equal(v86, v233)) goto v210;
    stack[-2] = stack[-8];
    stack[-1] = stack[-3];
    v86 = stack[-7];
    v233 = (Lisp_Object)33; /* 2 */
    v86 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    v233 = stack[-3];
    stack[0] = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    v89 = stack[-4];
    v86 = stack[-5];
    v233 = stack[-3];
    v233 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    v233 = times2(v89, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-9];
    v233 = plus2(stack[0], v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v233;
    goto v202;

v202:
    v233 = stack[-3];
    v233 = add1(v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-9];
    stack[-3] = v233;
    goto v8;

v210:
    stack[-1] = stack[-8];
    stack[0] = stack[-3];
    v89 = stack[-4];
    v86 = stack[-5];
    v233 = stack[-3];
    v233 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    v233 = times2(v89, v233);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v233;
    goto v202;

v6:
    v233 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v233); }
/* error exit handlers */
v235:
    popv(10);
    return nil;
}



/* Code for verify_tens_ids */

static Lisp_Object CC_verify_tens_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for verify_tens_ids");
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
    v30 = stack[-1];
    v30 = qcar(v30);
    v85 = v30;
    v30 = stack[-1];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    stack[0] = v30;
    v30 = v85;
    fn = elt(env, 4); /* extract_dummy_ids */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    fn = elt(env, 5); /* repeats */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    if (!(v30 == nil)) goto v22;
    v30 = stack[0];
    fn = elt(env, 4); /* extract_dummy_ids */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    fn = elt(env, 5); /* repeats */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    if (!(v30 == nil)) goto v22;
    v30 = qvalue(elt(env, 3)); /* t */
    { popv(4); return onevalue(v30); }

v22:
    stack[-2] = elt(env, 1); /* cantens */
    stack[0] = (Lisp_Object)33; /* 2 */
    v30 = stack[-1];
    v85 = qcar(v30);
    v30 = stack[-1];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v85 = list2(v85, v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    v30 = elt(env, 2); /* "are inconsistent lists of indices" */
    v30 = list2(v85, v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-3];
    fn = elt(env, 6); /* rerror */
    v30 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    v30 = nil;
    { popv(4); return onevalue(v30); }
/* error exit handlers */
v5:
    popv(4);
    return nil;
}



/* Code for ratlessp */

static Lisp_Object CC_ratlessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratlessp");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v12 = v42;
    v13 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ratdif */
    v12 = (*qfn2(fn))(qenv(fn), v13, v12);
    errexit();
    v13 = qcar(v12);
    v12 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v13, v12);
}



/* Code for add!-factor */

static Lisp_Object CC_addKfactor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v28, v105;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add-factor");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v42;
    stack[-1] = v0;
/* end of prologue */
    v17 = stack[0];
    v17 = Lconsp(nil, v17);
    env = stack[-2];
    if (v17 == nil) goto v142;
    v28 = stack[-1];
    v17 = stack[0];
    v17 = qcar(v17);
    v17 = qcar(v17);
    v17 = (Lisp_Object)greaterp2(v28, v17);
    nil = C_nil;
    if (exception_pending()) goto v215;
    v17 = v17 ? lisp_true : nil;
    env = stack[-2];
    if (v17 == nil) goto v19;
    v17 = qvalue(elt(env, 1)); /* nil */
    goto v1;

v1:
    v28 = v17;
    v17 = v28;
    if (v17 == nil) goto v4;
    stack[-1] = v28;
    v17 = v28;
    v17 = qcdr(v17);
    v17 = add1(v17);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-2];
    v17 = Lrplacd(nil, stack[-1], v17);
    nil = C_nil;
    if (exception_pending()) goto v215;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v4:
    v105 = stack[-1];
    v28 = (Lisp_Object)17; /* 1 */
    v17 = stack[0];
    popv(3);
    return acons(v105, v28, v17);

v19:
    v28 = stack[-1];
    v17 = stack[0];
    v17 = Lassoc(nil, v28, v17);
    goto v1;

v142:
    v17 = qvalue(elt(env, 1)); /* nil */
    goto v1;
/* error exit handlers */
v215:
    popv(3);
    return nil;
}



/* Code for equal!+matrices!+p */

static Lisp_Object CC_equalLmatricesLp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v102, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equal+matrices+p");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v42;
    stack[-1] = v0;
/* end of prologue */
    v102 = stack[-1];
    v104 = stack[0];
    fn = elt(env, 4); /* same!+dim!+squared!+p */
    v104 = (*qfn2(fn))(qenv(fn), v102, v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    if (v104 == nil) goto v220;
    v102 = (Lisp_Object)-15; /* -1 */
    v104 = (Lisp_Object)17; /* 1 */
    v102 = cons(v102, v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v104 = stack[0];
    fn = elt(env, 5); /* mk!+scal!+mult!+mat */
    v104 = (*qfn2(fn))(qenv(fn), v102, v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    fn = elt(env, 6); /* mk!+mat!+plus!+mat */
    v104 = (*qfn2(fn))(qenv(fn), stack[-1], v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    stack[0] = v104;
    v102 = qvalue(elt(env, 1)); /* nil */
    v104 = (Lisp_Object)17; /* 1 */
    v104 = cons(v102, v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v61 = v104;
    v104 = stack[0];
    stack[-3] = v104;
    goto v29;

v29:
    v104 = stack[-3];
    if (v104 == nil) goto v4;
    v104 = stack[-3];
    v104 = qcar(v104);
    stack[-2] = v104;
    goto v215;

v215:
    v104 = stack[-2];
    if (v104 == nil) goto v93;
    v104 = stack[-2];
    v104 = qcar(v104);
    v102 = v104;
    v104 = qvalue(elt(env, 2)); /* !*complex */
    if (v104 == nil) goto v111;
    stack[-1] = v61;
    stack[0] = v102;
    v104 = v102;
    fn = elt(env, 7); /* mk!+conjugate!+sq */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    fn = elt(env, 8); /* multsq */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    fn = elt(env, 9); /* addsq */
    v104 = (*qfn2(fn))(qenv(fn), stack[-1], v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v61 = v104;
    goto v146;

v146:
    v104 = stack[-2];
    v104 = qcdr(v104);
    stack[-2] = v104;
    goto v215;

v111:
    stack[0] = v61;
    v104 = v102;
    fn = elt(env, 8); /* multsq */
    v104 = (*qfn2(fn))(qenv(fn), v104, v102);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    fn = elt(env, 9); /* addsq */
    v104 = (*qfn2(fn))(qenv(fn), stack[0], v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v61 = v104;
    goto v146;

v93:
    v104 = stack[-3];
    v104 = qcdr(v104);
    stack[-3] = v104;
    goto v29;

v4:
    v104 = v61;
    fn = elt(env, 10); /* change!+sq!+to!+algnull */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-4];
    v102 = v104;
    v104 = (Lisp_Object)1; /* 0 */
    if (v102 == v104) goto v216;
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v104); }

v216:
    v104 = qvalue(elt(env, 3)); /* t */
    { popv(5); return onevalue(v104); }

v220:
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v104); }
/* error exit handlers */
v230:
    popv(5);
    return nil;
}



/* Code for mulpower */

static Lisp_Object CC_mulpower(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v42)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v85, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mulpower");
#endif
    if (stack >= stacklimit)
    {
        push2(v42,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v42);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v30 = v42;
    v85 = v0;
/* end of prologue */
    stack[0] = nil;
    fn = elt(env, 3); /* addexptsdf */
    v30 = (*qfn2(fn))(qenv(fn), v85, v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    stack[-1] = v30;
    v30 = qvalue(elt(env, 1)); /* sqrtlist */
    if (v30 == nil) goto v16;
    v85 = stack[-1];
    v30 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 4); /* reduceroots */
    v30 = (*qfn2(fn))(qenv(fn), v85, v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    stack[0] = v30;
    goto v16;

v16:
    v112 = stack[-1];
    v85 = (Lisp_Object)17; /* 1 */
    v30 = (Lisp_Object)17; /* 1 */
    v30 = list2star(v112, v85, v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    v30 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-2];
    stack[-1] = v30;
    v30 = stack[0];
    if (v30 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v85 = stack[-1];
    v30 = stack[0];
    fn = elt(env, 5); /* multdf */
    v30 = (*qfn2(fn))(qenv(fn), v85, v30);
    nil = C_nil;
    if (exception_pending()) goto v5;
    stack[-1] = v30;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v5:
    popv(3);
    return nil;
}



/* Code for rnfix!* */

static Lisp_Object CC_rnfixH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v193;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnfix*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v0;
/* end of prologue */
    v193 = v45;
    v193 = qcdr(v193);
    v193 = qcar(v193);
    v45 = qcdr(v45);
    v45 = qcdr(v45);
    return quot2(v193, v45);
}



/* Code for spmatlength */

static Lisp_Object CC_spmatlength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v27, v26, v211;
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
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v26 = v0;
/* end of prologue */
    v140 = v26;
    v140 = Lconsp(nil, v140);
    env = stack[-2];
    if (v140 == nil) goto v145;
    v140 = v26;
    goto v3;

v3:
    v27 = v140;
    v27 = qcdr(v27);
    v27 = qcdr(v27);
    v27 = qcar(v27);
    v27 = qcdr(v27);
    v211 = v27;
    v27 = v140;
    v140 = elt(env, 2); /* sparsemat */
    if (!consp(v27)) goto v41;
    v27 = qcar(v27);
    if (!(v27 == v140)) goto v41;
    v27 = elt(env, 6); /* list */
    v140 = v211;
    v140 = qcar(v140);
    v26 = v211;
    v26 = qcdr(v26);
    v26 = qcar(v26);
    popv(3);
    return list3(v27, v140, v26);

v41:
    stack[-1] = elt(env, 3); /* matrix */
    stack[0] = (Lisp_Object)33; /* 2 */
    v27 = elt(env, 4); /* "Matrix" */
    v140 = elt(env, 5); /* "not set" */
    v140 = list3(v27, v26, v140);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    fn = elt(env, 7); /* rerror */
    v140 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v140 = nil;
    { popv(3); return onevalue(v140); }

v145:
    v27 = v26;
    v140 = elt(env, 1); /* avalue */
    v140 = get(v27, v140);
    env = stack[-2];
    v140 = qcdr(v140);
    v140 = qcar(v140);
    goto v3;
/* error exit handlers */
v75:
    popv(3);
    return nil;
}



/* Code for tchscheme2 */

static Lisp_Object MS_CDECL CC_tchscheme2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "tchscheme2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tchscheme2");
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
    v113 = (Lisp_Object)1; /* 0 */
    stack[0] = v113;
    goto v45;

v45:
    v114 = qvalue(elt(env, 1)); /* rowmax */
    v113 = stack[0];
    v113 = difference2(v114, v113);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v113 = Lminusp(nil, v113);
    env = stack[-1];
    if (v113 == nil) goto v7;
    v113 = nil;
    { popv(2); return onevalue(v113); }

v7:
    v113 = stack[0];
    fn = elt(env, 3); /* removechild */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v113 = stack[0];
    fn = elt(env, 4); /* to!*scheme */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v113 = stack[0];
    v113 = add1(v113);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    stack[0] = v113;
    goto v45;
/* error exit handlers */
v46:
    popv(2);
    return nil;
}



/* Code for partitwedge */

static Lisp_Object CC_partitwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitwedge");
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
    v21 = v0;
/* end of prologue */
    v145 = v21;
    v145 = qcdr(v145);
    if (v145 == nil) goto v1;
    v145 = v21;
    fn = elt(env, 1); /* xpndwedge */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mkuniquewedge */
        return (*qfn1(fn))(qenv(fn), v145);
    }

v1:
    v145 = v21;
    v145 = qcar(v145);
    {
        popv(1);
        fn = elt(env, 3); /* partitop */
        return (*qfn1(fn))(qenv(fn), v145);
    }
/* error exit handlers */
v80:
    popv(1);
    return nil;
}



setup_type const u32_setup[] =
{
    {"splitcomplex",            CC_splitcomplex,too_many_1,    wrong_no_1},
    {"simpsetdiff",             CC_simpsetdiff, too_many_1,    wrong_no_1},
    {"fctinsert",               too_few_2,      CC_fctinsert,  wrong_no_2},
    {"prsum",                   too_few_2,      CC_prsum,      wrong_no_2},
    {"tidysqrtf",               CC_tidysqrtf,   too_many_1,    wrong_no_1},
    {"makeqn-maybe",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeqnKmaybe},
    {"zfactor1",                too_few_2,      CC_zfactor1,   wrong_no_2},
    {"mkrootsq",                too_few_2,      CC_mkrootsq,   wrong_no_2},
    {"formbool",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formbool},
    {"ratpoly_ratp",            CC_ratpoly_ratp,too_many_1,    wrong_no_1},
    {"conditionrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_conditionrd},
    {"scar",                    too_few_2,      CC_scar,       wrong_no_2},
    {"spinnerprod",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_spinnerprod},
    {"findhc",                  CC_findhc,      too_many_1,    wrong_no_1},
    {"quotexf*",                too_few_2,      CC_quotexfH,   wrong_no_2},
    {"f2df",                    CC_f2df,        too_many_1,    wrong_no_1},
    {"matrixir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixir},
    {"dipdivmon",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipdivmon},
    {"evalmember",              too_few_2,      CC_evalmember, wrong_no_2},
    {"indordln",                CC_indordln,    too_many_1,    wrong_no_1},
    {"physopsubs",              CC_physopsubs,  too_many_1,    wrong_no_1},
    {"mapcarcar",               CC_mapcarcar,   too_many_1,    wrong_no_1},
    {"negex",                   CC_negex,       too_many_1,    wrong_no_1},
    {"generic_arguments",       CC_generic_arguments,too_many_1,wrong_no_1},
    {"mksfpf",                  too_few_2,      CC_mksfpf,     wrong_no_2},
    {"get_char_group",          CC_get_char_group,too_many_1,  wrong_no_1},
    {"ev_2a",                   CC_ev_2a,       too_many_1,    wrong_no_1},
    {"matrixml",                CC_matrixml,    too_many_1,    wrong_no_1},
    {"addexptsdf",              too_few_2,      CC_addexptsdf, wrong_no_2},
    {"multup",                  CC_multup,      too_many_1,    wrong_no_1},
    {"gfftimes",                too_few_2,      CC_gfftimes,   wrong_no_2},
    {"mv-compact",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_mvKcompact},
    {"groeb=crita",             CC_groebMcrita, too_many_1,    wrong_no_1},
    {"simp-prop",               CC_simpKprop,   too_many_1,    wrong_no_1},
    {"makecoeffpairs",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs},
    {"mk+equation",             too_few_2,      CC_mkLequation,wrong_no_2},
    {"quotientml",              CC_quotientml,  too_many_1,    wrong_no_1},
    {"mkdmoderr",               too_few_2,      CC_mkdmoderr,  wrong_no_2},
    {"reduce-ratios",           too_few_2,      CC_reduceKratios,wrong_no_2},
    {"simpsqrt2",               CC_simpsqrt2,   too_many_1,    wrong_no_1},
    {"sfto_updecf",             CC_sfto_updecf, too_many_1,    wrong_no_1},
    {"dvfsf_simplat1",          too_few_2,      CC_dvfsf_simplat1,wrong_no_2},
    {"ev_mtest?",               too_few_2,      CC_ev_mtestW,  wrong_no_2},
    {"lowupperlimitml",         CC_lowupperlimitml,too_many_1, wrong_no_1},
    {"ps:mkpow",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTmkpow},
    {"make_wedge_pair",         too_few_2,      CC_make_wedge_pair,wrong_no_2},
    {"force-to-dm",             CC_forceKtoKdm, too_many_1,    wrong_no_1},
    {"toolongassignp",          CC_toolongassignp,too_many_1,  wrong_no_1},
    {"dfdeg",                   too_few_2,      CC_dfdeg,      wrong_no_2},
    {"coeff_calc",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff_calc},
    {"fs:subang",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTsubang},
    {"verify_tens_ids",         CC_verify_tens_ids,too_many_1, wrong_no_1},
    {"ratlessp",                too_few_2,      CC_ratlessp,   wrong_no_2},
    {"add-factor",              too_few_2,      CC_addKfactor, wrong_no_2},
    {"equal+matrices+p",        too_few_2,      CC_equalLmatricesLp,wrong_no_2},
    {"mulpower",                too_few_2,      CC_mulpower,   wrong_no_2},
    {"rnfix*",                  CC_rnfixH,      too_many_1,    wrong_no_1},
    {"spmatlength",             CC_spmatlength, too_many_1,    wrong_no_1},
    {"tchscheme2",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_tchscheme2},
    {"partitwedge",             CC_partitwedge, too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u32", (two_args *)"18874 4573300 2242674", 0}
};

/* end of generated code */
