
/* $destdir/generated-c\u07.c Machine generated C code */

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


/* Code for isarb_compl */

static Lisp_Object CC_isarb_compl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4, v5;
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
    v4 = v0;
/* end of prologue */
    v3 = v4;
    v3 = Lconsp(nil, v3);
    env = stack[0];
    if (v3 == nil) goto v6;
    v3 = v4;
    v5 = qcar(v3);
    v3 = elt(env, 1); /* arbcomplex */
    if (v5 == v3) goto v7;
    v3 = v4;
    v3 = qcdr(v3);
    fn = elt(env, 4); /* multi_isarb_compl */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v8;
    goto v6;

v6:
    v3 = nil;
    { popv(1); return onevalue(v3); }

v7:
    v3 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v3; /* found_compl */
    goto v6;
/* error exit handlers */
v8:
    popv(1);
    return nil;
}



/* Code for fac!-part */

static Lisp_Object CC_facKpart(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v25;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fac-part");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */
    v25 = stack[-1];
    v24 = stack[0];
    if (equal(v25, v24)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = stack[-1];
    v24 = stack[0];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    if (equal(stack[-2], v24)) goto v27;
    v25 = stack[-1];
    v24 = stack[0];
    v25 = plus2(v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    v24 = (Lisp_Object)33; /* 2 */
    v24 = quot2(v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    stack[-2] = v24;
    v25 = stack[-1];
    v24 = stack[-2];
    stack[-1] = CC_facKpart(env, v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    v24 = stack[-2];
    v25 = add1(v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    v24 = stack[0];
    v24 = CC_facKpart(env, v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v28 = stack[-1];
        popv(4);
        return times2(v28, v24);
    }

v27:
    v25 = stack[-1];
    v24 = stack[0];
    popv(4);
    return times2(v25, v24);
/* error exit handlers */
v26:
    popv(4);
    return nil;
}



/* Code for reval1 */

static Lisp_Object CC_reval1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval1");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v9;
    stack[-2] = v0;
/* end of prologue */
    v106 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-3] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v106; /* varstack!* */
    v106 = stack[-2];
    if (v106 == nil) goto v109;
    v106 = stack[-2];
    v106 = Lstringp(nil, v106);
    env = stack[-4];
    if (v106 == nil) goto v110;
    v106 = stack[-2];
    goto v111;

v111:
    qvalue(elt(env, 1)) = stack[-3]; /* varstack!* */
    { popv(5); return onevalue(v106); }

v110:
    v106 = stack[-2];
    v106 = integerp(v106);
    if (v106 == nil) goto v1;
    v107 = qvalue(elt(env, 3)); /* dmode!* */
    v106 = elt(env, 4); /* convert */
    v106 = Lflagp(nil, v107, v106);
    env = stack[-4];
    if (v106 == nil) goto v112;
    v107 = stack[-2];
    v106 = stack[-1];
    fn = elt(env, 24); /* reval2 */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v112:
    v106 = stack[-2];
    goto v111;

v1:
    v106 = stack[-2];
    if (!consp(v106)) goto v19;
    v106 = stack[-2];
    v106 = qcar(v106);
    if (symbolp(v106)) goto v114;
    v107 = stack[-2];
    v106 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 25); /* errpri2 */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v115;

v115:
    v106 = stack[-2];
    fn = elt(env, 26); /* getrtype */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    stack[0] = v106;
    if (v106 == nil) goto v116;
    v107 = stack[0];
    v106 = elt(env, 7); /* evfn */
    v106 = get(v107, v106);
    env = stack[-4];
    v108 = v106;
    if (v106 == nil) goto v117;
    v107 = stack[-2];
    v106 = stack[-1];
    v106 = Lapply2(nil, 3, v108, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v117:
    stack[-2] = elt(env, 15); /* alg */
    stack[-1] = (Lisp_Object)1617; /* 101 */
    v107 = elt(env, 16); /* "Missing evaluation for type" */
    v106 = stack[0];
    v106 = list2(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    fn = elt(env, 27); /* rerror */
    v106 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v116:
    v106 = stack[-2];
    if (!consp(v106)) goto v118;
    v106 = stack[-2];
    v106 = qcdr(v106);
    if (!consp(v106)) goto v118;
    v106 = stack[-2];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    fn = elt(env, 26); /* getrtype */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    v108 = v106;
    if (v106 == nil) goto v118;
    v107 = v108;
    v106 = elt(env, 17); /* list */
    if (!(v107 == v106)) goto v119;
    v106 = stack[-2];
    v106 = qcdr(v106);
    v106 = qcdr(v106);
    if (!(v106 == nil)) goto v118;

v119:
    v107 = v108;
    v106 = elt(env, 18); /* aggregatefn */
    v106 = get(v107, v106);
    env = stack[-4];
    stack[0] = v106;
    if (v106 == nil) goto v118;
    v107 = stack[0];
    v106 = elt(env, 19); /* matrixmap */
    if (!(v107 == v106)) goto v120;
    v106 = stack[-2];
    v107 = qcar(v106);
    v106 = elt(env, 20); /* matmapfn */
    v106 = Lflagp(nil, v107, v106);
    env = stack[-4];
    if (!(v106 == nil)) goto v120;

v118:
    v107 = stack[-2];
    v106 = stack[-1];
    fn = elt(env, 24); /* reval2 */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v120:
    v106 = stack[-2];
    v107 = qcar(v106);
    v106 = elt(env, 21); /* boolean */
    v106 = Lflagp(nil, v107, v106);
    env = stack[-4];
    if (!(v106 == nil)) goto v118;
    v106 = qvalue(elt(env, 22)); /* !*listargs */
    if (!(v106 == nil)) goto v118;
    v106 = stack[-2];
    v107 = qcar(v106);
    v106 = elt(env, 23); /* listargp */
    v106 = Lflagp(nil, v107, v106);
    env = stack[-4];
    if (!(v106 == nil)) goto v118;
    v108 = stack[0];
    v107 = stack[-2];
    v106 = stack[-1];
    v106 = Lapply2(nil, 3, v108, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v114:
    v106 = stack[-2];
    v107 = qcar(v106);
    v106 = elt(env, 9); /* !*sq */
    if (v107 == v106) goto v121;
    v106 = stack[-2];
    v107 = qcar(v106);
    v106 = elt(env, 11); /* remember */
    v106 = Lflagp(nil, v107, v106);
    env = stack[-4];
    if (v106 == nil) goto v122;
    v107 = stack[-2];
    v106 = stack[-1];
    fn = elt(env, 28); /* rmmbreval */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v122:
    v106 = stack[-2];
    v107 = qcar(v106);
    v106 = elt(env, 12); /* opfn */
    v106 = Lflagp(nil, v107, v106);
    env = stack[-4];
    if (v106 == nil) goto v123;
    v106 = stack[-2];
    fn = elt(env, 29); /* opfneval */
    v107 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    v106 = stack[-1];
    v106 = CC_reval1(env, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v123:
    v106 = stack[-2];
    v107 = qcar(v106);
    v106 = elt(env, 13); /* psopfn */
    v106 = get(v107, v106);
    env = stack[-4];
    stack[0] = v106;
    if (v106 == nil) goto v124;
    v107 = stack[0];
    v106 = stack[-2];
    v106 = qcdr(v106);
    v106 = Lapply1(nil, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    stack[-2] = v106;
    v107 = stack[0];
    v106 = elt(env, 14); /* cleanupfn */
    v106 = get(v107, v106);
    env = stack[-4];
    stack[0] = v106;
    if (v106 == nil) goto v125;
    v108 = stack[0];
    v107 = stack[-2];
    v106 = stack[-1];
    v106 = Lapply2(nil, 3, v108, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    stack[-2] = v106;
    goto v125;

v125:
    v106 = stack[-2];
    goto v111;

v124:
    v106 = stack[-2];
    v106 = qcar(v106);
    fn = elt(env, 30); /* arrayp */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    if (v106 == nil) goto v115;
    v106 = stack[-2];
    fn = elt(env, 31); /* getelv */
    v107 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    v106 = stack[-1];
    v106 = CC_reval1(env, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v121:
    v106 = stack[-2];
    v106 = qcdr(v106);
    v106 = qcdr(v106);
    v106 = qcar(v106);
    if (v106 == nil) goto v126;
    v106 = qvalue(elt(env, 10)); /* !*resimp */
    if (!(v106 == nil)) goto v126;
    v106 = stack[-1];
    if (v106 == nil) goto v127;
    v106 = stack[-2];
    v106 = qcdr(v106);
    v106 = qcar(v106);
    fn = elt(env, 32); /* prepsqxx */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v127:
    v106 = stack[-2];
    goto v111;

v126:
    v107 = stack[-2];
    v106 = stack[-1];
    fn = elt(env, 24); /* reval2 */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v19:
    v106 = qvalue(elt(env, 5)); /* subfg!* */
    if (v106 == nil) goto v128;
    v106 = stack[-2];
    if (!(symbolp(v106))) goto v115;
    v107 = stack[-2];
    v106 = elt(env, 6); /* avalue */
    v106 = get(v107, v106);
    env = stack[-4];
    stack[0] = v106;
    if (v106 == nil) goto v115;
    v107 = stack[-2];
    v106 = qvalue(elt(env, 1)); /* varstack!* */
    v106 = Lmemq(nil, v107, v106);
    if (v106 == nil) goto v129;
    v106 = stack[-2];
    fn = elt(env, 33); /* recursiveerror */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v115;

v129:
    v107 = stack[-2];
    v106 = qvalue(elt(env, 1)); /* varstack!* */
    v106 = cons(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    qvalue(elt(env, 1)) = v106; /* varstack!* */
    v106 = stack[0];
    v107 = qcar(v106);
    v106 = elt(env, 7); /* evfn */
    v106 = get(v107, v106);
    env = stack[-4];
    v108 = v106;
    if (v106 == nil) goto v130;
    v107 = stack[-2];
    v106 = stack[-1];
    v106 = Lapply2(nil, 3, v108, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v130:
    v106 = stack[0];
    v106 = qcdr(v106);
    v107 = qcar(v106);
    v106 = stack[-1];
    v106 = CC_reval1(env, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v111;

v128:
    v106 = stack[-2];
    goto v111;

v109:
    v106 = qvalue(elt(env, 2)); /* nil */
    goto v111;
/* error exit handlers */
v113:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* varstack!* */
    popv(5);
    return nil;
}



/* Code for initbrsea */

static Lisp_Object MS_CDECL CC_initbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v130, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initbrsea");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initbrsea");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    v143 = (Lisp_Object)3201; /* 200 */
    stack[-2] = v143;
    v143 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v143;
    goto v110;

v110:
    v130 = qvalue(elt(env, 2)); /* rowmax */
    v143 = stack[-1];
    v143 = difference2(v130, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v143 = Lminusp(nil, v143);
    env = stack[-3];
    if (v143 == nil) goto v146;
    fn = elt(env, 8); /* redcodmat */
    v143 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v143 = qvalue(elt(env, 6)); /* codhisto */
    if (v143 == nil) goto v96;
    v143 = (Lisp_Object)1; /* 0 */
    stack[0] = v143;
    goto v12;

v12:
    v130 = (Lisp_Object)3201; /* 200 */
    v143 = stack[0];
    v143 = difference2(v130, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v143 = Lminusp(nil, v143);
    env = stack[-3];
    if (!(v143 == nil)) goto v147;
    v144 = qvalue(elt(env, 6)); /* codhisto */
    v130 = stack[0];
    v143 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v144 + (CELL-TAG_VECTOR) + ((int32_t)v130/(16/CELL))) = v143;
    v143 = stack[0];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[0] = v143;
    goto v12;

v147:
    v143 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v143; /* headhisto */
    v143 = (Lisp_Object)1; /* 0 */
    stack[0] = v143;
    goto v148;

v148:
    v130 = qvalue(elt(env, 2)); /* rowmax */
    v143 = stack[0];
    v143 = difference2(v130, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v143 = Lminusp(nil, v143);
    env = stack[-3];
    if (v143 == nil) goto v149;
    v143 = nil;
    { popv(4); return onevalue(v143); }

v149:
    v143 = stack[0];
    fn = elt(env, 9); /* inshisto */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v143 = stack[0];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[0] = v143;
    goto v148;

v96:
    v143 = stack[-2];
    v143 = Lmkvect(nil, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    qvalue(elt(env, 6)) = v143; /* codhisto */
    goto v147;

v146:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v130 = qvalue(elt(env, 5)); /* maxvar */
    v143 = stack[-1];
    v143 = plus2(v130, v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v130 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v143/(16/CELL)));
    v143 = (Lisp_Object)1; /* 0 */
    v143 = *(Lisp_Object *)((char *)v130 + (CELL-TAG_VECTOR) + ((int32_t)v143/(16/CELL)));
    if (v143 == nil) goto v150;
    v143 = stack[-1];
    fn = elt(env, 10); /* initwght */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    goto v150;

v150:
    v143 = stack[-1];
    v143 = add1(v143);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-1] = v143;
    goto v110;
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v134, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convchk");
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
    v151 = v0;
/* end of prologue */
    v134 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v134 == nil) goto v6;
    v134 = v151;
    if (!(!consp(v134))) { popv(1); return onevalue(v151); }
    v134 = v151;
    v134 = Lfloatp(nil, v134);
    env = stack[0];
    if (v134 == nil) goto v2;
    {
        popv(1);
        fn = elt(env, 3); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v151);
    }

v2:
    v134 = v151;
    if (!(!consp(v134))) goto v101;
    v134 = v151;
    v134 = integerp(v134);
    if (v134 == nil) goto v112;
    v152 = elt(env, 2); /* !:rd!: */
    v134 = v151;
    v151 = (Lisp_Object)1; /* 0 */
    v151 = list2star(v152, v134, v151);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[0];
    goto v101;

v101:
    {
        popv(1);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v151);
    }

v112:
    fn = elt(env, 5); /* read!:num */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[0];
    goto v101;

v6:
    v134 = v151;
    if (!consp(v134)) { popv(1); return onevalue(v151); }
    {
        popv(1);
        fn = elt(env, 6); /* bf2flck */
        return (*qfn1(fn))(qenv(fn), v151);
    }
/* error exit handlers */
v153:
    popv(1);
    return nil;
}



/* Code for optype */

static Lisp_Object CC_optype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for optype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v115 = v0;
/* end of prologue */
    v109 = elt(env, 1); /* !*optype!* */
    return get(v115, v109);
}



/* Code for ckpreci!# */

static Lisp_Object CC_ckpreciC(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v156, v151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckpreci#");
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
    v11 = stack[0];
    v11 = qcar(v11);
    fn = elt(env, 3); /* timesip */
    stack[-1] = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v11 = stack[0];
    v11 = qcdr(v11);
    v11 = qcar(v11);
    fn = elt(env, 3); /* timesip */
    v11 = (*qfn1(fn))(qenv(fn), v11);
    nil = C_nil;
    if (exception_pending()) goto v153;
    env = stack[-2];
    v151 = stack[-1];
    v156 = v11;
    v11 = qvalue(elt(env, 1)); /* !*complex */
    if (v11 == nil) goto v23;
    v11 = v151;
    if (v11 == nil) goto v21;
    v11 = v156;
    if (!(v11 == nil)) goto v21;
    v11 = stack[0];
    v11 = qcar(v11);
    v156 = qcdr(v11);
    v11 = stack[0];
    v11 = qcdr(v11);
    v11 = qcar(v11);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v156, v11);
    }

v21:
    v11 = v156;
    if (v11 == nil) goto v157;
    v11 = v151;
    if (!(v11 == nil)) goto v157;
    v11 = stack[0];
    v11 = qcdr(v11);
    v11 = qcar(v11);
    v156 = qcdr(v11);
    v11 = stack[0];
    v11 = qcar(v11);
    {
        popv(3);
        fn = elt(env, 4); /* ckprec2!# */
        return (*qfn2(fn))(qenv(fn), v156, v11);
    }

v157:
    v11 = nil;
    { popv(3); return onevalue(v11); }

v23:
    v11 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v11); }
/* error exit handlers */
v153:
    popv(3);
    return nil;
}



/* Code for mv!-pow!-mv!-term!-!+ */

static Lisp_Object CC_mvKpowKmvKtermKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-mv-term-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    v2 = v0;
/* end of prologue */
    v1 = v2;
    v2 = stack[0];
    v2 = qcar(v2);
    fn = elt(env, 1); /* mv!-pow!-!+ */
    v1 = (*qfn2(fn))(qenv(fn), v1, v2);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v2 = stack[0];
    v2 = qcdr(v2);
    popv(1);
    return cons(v1, v2);
/* error exit handlers */
v22:
    popv(1);
    return nil;
}



/* Code for dp_ecart */

static Lisp_Object CC_dp_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_ecart");
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
    v1 = stack[0];
    if (v1 == nil) goto v30;
    v1 = stack[0];
    fn = elt(env, 1); /* dp!=ecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    v1 = stack[0];
    fn = elt(env, 2); /* dp_lmon */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    fn = elt(env, 3); /* mo_ecart */
    v1 = (*qfn1(fn))(qenv(fn), v1);
    nil = C_nil;
    if (exception_pending()) goto v101;
    {
        Lisp_Object v150 = stack[-1];
        popv(3);
        return difference2(v150, v1);
    }

v30:
    v1 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v1); }
/* error exit handlers */
v101:
    popv(3);
    return nil;
}



/* Code for psum */

static Lisp_Object CC_psum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v176, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for psum");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v9;
    stack[-6] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v175 = stack[-6];
    if (v175 == nil) goto v178;
    v175 = stack[-5];
    if (!(v175 == nil)) goto v27;
    v175 = stack[-6];
    stack[-2] = v175;
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v27:
    v175 = stack[-5];
    if (v175 == nil) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    v175 = stack[-1];
    if (!(v175 == nil)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    v175 = stack[-5];
    v175 = qcar(v175);
    stack[0] = v175;
    v175 = stack[0];
    v175 = qcar(v175);
    stack[-7] = v175;
    goto v102;

v102:
    v175 = stack[-6];
    if (v175 == nil) goto v17;
    v176 = stack[-7];
    v175 = stack[-6];
    v175 = qcar(v175);
    v175 = qcar(v175);
    fn = elt(env, 3); /* dless */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    if (v175 == nil) goto v17;
    v175 = stack[-6];
    v176 = qcar(v175);
    v175 = stack[-3];
    v175 = cons(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-3] = v175;
    v175 = stack[-6];
    v175 = qcdr(v175);
    stack[-6] = v175;
    goto v102;

v17:
    v175 = stack[-6];
    if (v175 == nil) goto v98;
    v175 = stack[-6];
    v175 = qcar(v175);
    v177 = v175;
    v176 = stack[-7];
    v175 = v177;
    v175 = qcar(v175);
    if (equal(v176, v175)) goto v94;
    v176 = stack[0];
    v175 = stack[-3];
    v175 = cons(v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-3] = v175;
    goto v97;

v97:
    v175 = stack[-5];
    v175 = qcdr(v175);
    stack[-5] = v175;
    v175 = stack[-5];
    if (!(v175 == nil)) goto v27;
    v175 = stack[-3];
    v176 = Lreverse(nil, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v175 = stack[-6];
    v175 = Lappend(nil, v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-2] = v175;
    goto v27;

v94:
    v175 = v177;
    v176 = qcdr(v175);
    v175 = stack[0];
    v175 = qcdr(v175);
    fn = elt(env, 4); /* csum */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-4] = v175;
    stack[0] = stack[-4];
    fn = elt(env, 5); /* c_zero */
    v175 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    if (equal(stack[0], v175)) goto v93;
    v177 = stack[-7];
    v176 = stack[-4];
    v175 = stack[-3];
    v175 = acons(v177, v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-3] = v175;
    goto v93;

v93:
    v175 = stack[-6];
    v175 = qcdr(v175);
    stack[-6] = v175;
    v175 = stack[-6];
    if (v175 == nil) goto v97;
    else goto v97;

v98:
    v175 = stack[-3];
    v176 = Lreverse(nil, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    v175 = stack[-5];
    v175 = Lappend(nil, v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-8];
    stack[-2] = v175;
    v175 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v175;
    goto v27;

v178:
    v175 = stack[-5];
    stack[-2] = v175;
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
/* error exit handlers */
v179:
    popv(9);
    return nil;
}



/* Code for adddummy1a */

static Lisp_Object MS_CDECL CC_adddummy1a(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v9,
                         Lisp_Object v180, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "adddummy1a");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for adddummy1a");
#endif
    if (stack >= stacklimit)
    {
        push3(v180,v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v9,v180);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v180;
    v153 = v9;
    stack[-2] = v0;
/* end of prologue */

v29:
    v15 = v153;
    if (v15 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v15 = v153;
    v15 = qcdr(v15);
    stack[-3] = v15;
    v15 = stack[-1];
    if (v15 == nil) goto v27;
    v15 = stack[-1];
    v15 = qcar(v15);
    stack[0] = v15;
    goto v102;

v102:
    v15 = qcar(v153);
    v153 = stack[-2];
    v153 = qcdr(v153);
    fn = elt(env, 1); /* pappl_pv */
    v15 = (*qfn2(fn))(qenv(fn), v15, v153);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    v153 = stack[-1];
    if (v153 == nil) goto v182;
    v153 = stack[-1];
    v153 = qcdr(v153);
    goto v140;

v140:
    fn = elt(env, 2); /* insert_pv */
    v153 = (*qfn2(fn))(qenv(fn), v15, v153);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    v153 = cons(stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    stack[-1] = v153;
    v153 = stack[-3];
    goto v29;

v182:
    v153 = stack[-1];
    goto v140;

v27:
    v15 = stack[-2];
    v15 = qcar(v15);
    stack[0] = v15;
    goto v102;
/* error exit handlers */
v100:
    popv(5);
    return nil;
}



/* Code for general!-modular!-quotient */

static Lisp_Object CC_generalKmodularKquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-quotient");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v7 = v9;
    v23 = v0;
/* end of prologue */
    stack[0] = v23;
    fn = elt(env, 1); /* general!-modular!-reciprocal */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-1];
    {
        Lisp_Object v110 = stack[0];
        popv(2);
        fn = elt(env, 2); /* general!-modular!-times */
        return (*qfn2(fn))(qenv(fn), v110, v7);
    }
/* error exit handlers */
v159:
    popv(2);
    return nil;
}



/* Code for gizerop!: */

static Lisp_Object CC_gizeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gizerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v183 = v4;
    v183 = qcdr(v183);
    v3 = qcar(v183);
    v183 = (Lisp_Object)1; /* 0 */
    if (v3 == v183) goto v161;
    v183 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v183);

v161:
    v183 = v4;
    v183 = qcdr(v183);
    v3 = qcdr(v183);
    v183 = (Lisp_Object)1; /* 0 */
    v183 = (v3 == v183 ? lisp_true : nil);
    return onevalue(v183);
}



/* Code for rl_smmkatl */

static Lisp_Object MS_CDECL CC_rl_smmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v9,
                         Lisp_Object v180, Lisp_Object v170, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v184, v183, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rl_smmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smmkatl");
#endif
    if (stack >= stacklimit)
    {
        push4(v170,v180,v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v9,v180,v170);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v27 = v170;
    v184 = v180;
    v183 = v9;
    v3 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smmkatl!* */
    v27 = list4(v3, v183, v184, v27);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    {
        Lisp_Object v8 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v8, v27);
    }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for ev_comp */

static Lisp_Object CC_ev_comp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_comp");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v161 = v9;
    v158 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dip_sortevcomp!* */
    v161 = list2(v158, v161);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    {
        Lisp_Object v21 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v21, v161);
    }
/* error exit handlers */
v1:
    popv(2);
    return nil;
}



/* Code for symtabget */

static Lisp_Object CC_symtabget(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v187, v147, v11, v156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symtabget");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v156 = v9;
    v11 = v0;
/* end of prologue */
    v187 = v156;
    if (v187 == nil) goto v30;
    v187 = v11;
    if (!(v187 == nil)) goto v154;
    v187 = qvalue(elt(env, 1)); /* !*symboltable!* */
    v187 = qcar(v187);
    goto v154;

v154:
    v11 = v187;
    goto v30;

v30:
    v187 = v11;
    if (v187 == nil) goto v110;
    v147 = v156;
    v187 = elt(env, 2); /* (!*type!* !*params!* !*decs!*) */
    v187 = Lmemq(nil, v147, v187);
    if (v187 == nil) goto v157;
    v187 = v11;
    v147 = v156;
    return get(v187, v147);

v157:
    v147 = v156;
    v187 = elt(env, 3); /* !*decs!* */
    v187 = get(v11, v187);
    v187 = Lassoc(nil, v147, v187);
    return onevalue(v187);

v110:
    v187 = qvalue(elt(env, 1)); /* !*symboltable!* */
    return onevalue(v187);
}



/* Code for dim!<deg */

static Lisp_Object CC_dimRdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dim<deg");
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
    v183 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 4); /* deg!*farg */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    fn = elt(env, 5); /* negf */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    fn = elt(env, 6); /* addf */
    v183 = (*qfn2(fn))(qenv(fn), stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v3 = v183;
    v183 = v3;
    if (!(is_number(v183))) goto v150;
    v183 = v3;
    v183 = Lminusp(nil, v183);
    env = stack[-1];
    if (v183 == nil) goto v150;
    v183 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v183); }

v150:
    v183 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v183); }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for lessp!: */

static Lisp_Object CC_lesspT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lessp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v9;
    v109 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* greaterp!: */
        return (*qfn2(fn))(qenv(fn), v7, v109);
    }
}



/* Code for mv!-pow!-!+ */

static Lisp_Object CC_mvKpowKL(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-+");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v47;

v47:
    v185 = stack[-1];
    if (v185 == nil) goto v154;
    v185 = stack[-1];
    v139 = qcar(v185);
    v185 = stack[0];
    v185 = qcar(v185);
    v139 = plus2(v139, v185);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v185 = stack[-2];
    v185 = cons(v139, v185);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    stack[-2] = v185;
    v185 = stack[-1];
    v185 = qcdr(v185);
    stack[-1] = v185;
    v185 = stack[0];
    v185 = qcdr(v185);
    stack[0] = v185;
    goto v47;

v154:
    v185 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v185);
    }
/* error exit handlers */
v102:
    popv(4);
    return nil;
}



/* Code for rnquotient!: */

static Lisp_Object CC_rnquotientT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnquotient:");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */
    v146 = stack[-1];
    v146 = qcdr(v146);
    v104 = qcar(v146);
    v146 = stack[0];
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    stack[-2] = times2(v104, v146);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v146 = stack[-1];
    v146 = qcdr(v146);
    v104 = qcdr(v146);
    v146 = stack[0];
    v146 = qcdr(v146);
    v146 = qcar(v146);
    v146 = times2(v104, v146);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    {
        Lisp_Object v140 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v140, v146);
    }
/* error exit handlers */
v139:
    popv(4);
    return nil;
}



/* Code for exchk2 */

static Lisp_Object CC_exchk2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v93, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exchk2");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */

v47:
    v133 = stack[-1];
    if (v133 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-2] = v133;
    v133 = stack[-1];
    v133 = qcar(v133);
    v133 = qcdr(v133);
    fn = elt(env, 6); /* prepsqx */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v91 = v133;
    v93 = (Lisp_Object)17; /* 1 */
    if (v91 == v93) goto v4;
    v93 = qvalue(elt(env, 1)); /* !*nosqrts */
    if (v93 == nil) goto v134;
    v91 = elt(env, 2); /* expt */
    v93 = stack[-1];
    v93 = qcar(v93);
    v93 = qcar(v93);
    v133 = list3(v91, v93, v133);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v93 = v133;
    goto v2;

v2:
    v133 = stack[0];
    v133 = cons(v93, v133);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    stack[0] = v133;
    v133 = stack[-2];
    stack[-1] = v133;
    goto v47;

v134:
    v91 = v133;
    v93 = elt(env, 3); /* (quotient 1 2) */
    if (equal(v91, v93)) goto v100;
    v91 = v133;
    v93 = elt(env, 5); /* 0.5 */
    if (equal(v91, v93)) goto v136;
    v91 = elt(env, 2); /* expt */
    v93 = stack[-1];
    v93 = qcar(v93);
    v93 = qcar(v93);
    v133 = list3(v91, v93, v133);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v93 = v133;
    goto v2;

v136:
    v93 = elt(env, 4); /* sqrt */
    v133 = stack[-1];
    v133 = qcar(v133);
    v133 = qcar(v133);
    v133 = list2(v93, v133);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v93 = v133;
    goto v2;

v100:
    v93 = elt(env, 4); /* sqrt */
    v133 = stack[-1];
    v133 = qcar(v133);
    v133 = qcar(v133);
    v133 = list2(v93, v133);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v93 = v133;
    goto v2;

v4:
    v133 = stack[-1];
    v133 = qcar(v133);
    v133 = qcar(v133);
    v93 = v133;
    goto v2;
/* error exit handlers */
v143:
    popv(4);
    return nil;
}



/* Code for cgp_evlmon */

static Lisp_Object CC_cgp_evlmon(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_evlmon");
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
    v6 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_evlmon */
        return (*qfn1(fn))(qenv(fn), v6);
    }
/* error exit handlers */
v47:
    popv(1);
    return nil;
}



/* Code for checktag */

static Lisp_Object CC_checktag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checktag");
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
    v22 = v0;
/* end of prologue */
    v101 = qvalue(elt(env, 1)); /* char */
    if (equal(v101, v22)) goto v6;
    v101 = elt(env, 2); /* "Problem" */
    v22 = elt(env, 3); /* "problem" */
    fn = elt(env, 4); /* errorml */
    v22 = (*qfn2(fn))(qenv(fn), v101, v22);
    errexit();
    goto v6;

v6:
    v22 = nil;
    return onevalue(v22);
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v150;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevmaptozero1");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v101 = v9;
    stack[0] = v0;
/* end of prologue */

v6:
    v150 = stack[0];
    if (v150 == nil) { popv(2); return onevalue(v101); }
    v150 = stack[0];
    v150 = qcdr(v150);
    stack[0] = v150;
    v150 = (Lisp_Object)1; /* 0 */
    v101 = cons(v150, v101);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-1];
    goto v6;
/* error exit handlers */
v184:
    popv(2);
    return nil;
}



/* Code for addpf */

static Lisp_Object CC_addpf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v206, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addpf");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v9;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    goto v47;

v47:
    v205 = stack[-2];
    if (v205 == nil) goto v23;
    v205 = stack[-1];
    if (v205 == nil) goto v101;
    v205 = stack[-2];
    v205 = qcar(v205);
    v206 = qcar(v205);
    v205 = (Lisp_Object)17; /* 1 */
    if (v206 == v205) goto v14;
    v205 = stack[-1];
    v205 = qcar(v205);
    v206 = qcar(v205);
    v205 = (Lisp_Object)17; /* 1 */
    if (v206 == v205) goto v137;
    v205 = stack[-2];
    v205 = qcar(v205);
    v206 = qcar(v205);
    v205 = stack[-1];
    v205 = qcar(v205);
    v205 = qcar(v205);
    if (equal(v206, v205)) goto v208;
    v205 = stack[-2];
    v205 = qcar(v205);
    v206 = qcar(v205);
    v205 = stack[-1];
    v205 = qcar(v205);
    v205 = qcar(v205);
    fn = elt(env, 1); /* ordop */
    v205 = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    if (v205 == nil) goto v210;
    v205 = stack[-2];
    v206 = qcar(v205);
    v205 = stack[0];
    v205 = cons(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    stack[0] = v205;
    v205 = stack[-2];
    v205 = qcdr(v205);
    stack[-2] = v205;
    goto v47;

v210:
    v205 = stack[-1];
    v206 = qcar(v205);
    v205 = stack[0];
    v205 = cons(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    stack[0] = v205;
    v205 = stack[-1];
    v205 = qcdr(v205);
    stack[-1] = v205;
    goto v47;

v208:
    stack[-3] = stack[0];
    v205 = stack[-2];
    v205 = qcar(v205);
    v206 = qcdr(v205);
    v205 = stack[-1];
    v205 = qcar(v205);
    v205 = qcdr(v205);
    fn = elt(env, 2); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v205 = stack[-2];
    v206 = qcdr(v205);
    v205 = stack[-1];
    v205 = qcdr(v205);
    v205 = CC_addpf(env, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v206 = stack[0];
    v207 = v206;
    v207 = qcar(v207);
    if (v207 == nil) goto v171;
    v207 = stack[-2];
    v207 = qcar(v207);
    v207 = qcar(v207);
    v205 = acons(v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    goto v171;

v171:
    {
        Lisp_Object v211 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v211, v205);
    }

v137:
    v206 = stack[-1];
    v205 = stack[-2];
    fn = elt(env, 4); /* addmpf */
    v205 = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    {
        Lisp_Object v78 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v78, v205);
    }

v14:
    v206 = stack[-2];
    v205 = stack[-1];
    fn = elt(env, 4); /* addmpf */
    v205 = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    {
        Lisp_Object v79 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v79, v205);
    }

v101:
    v206 = stack[0];
    v205 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v206, v205);
    }

v23:
    v206 = stack[0];
    v205 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v206, v205);
    }
/* error exit handlers */
v209:
    popv(5);
    return nil;
}



/* Code for argnochk */

static Lisp_Object CC_argnochk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95, v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for argnochk");
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
    v94 = qvalue(elt(env, 1)); /* !*argnochk */
    if (v94 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v94 = stack[-5];
    v94 = qcar(v94);
    fn = elt(env, 9); /* argsofopr */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-7];
    stack[-6] = v94;
    if (v94 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    stack[0] = stack[-6];
    v94 = stack[-5];
    v94 = qcdr(v94);
    v94 = Llength(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-7];
    if (equal(stack[0], v94)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v94 = stack[-5];
    v95 = qcar(v94);
    v94 = elt(env, 2); /* simpfn */
    v94 = get(v95, v94);
    env = stack[-7];
    if (!(v94 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v94 = stack[-5];
    v95 = qcar(v94);
    v94 = elt(env, 3); /* psopfn */
    v94 = get(v95, v94);
    env = stack[-7];
    if (!(v94 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    stack[-4] = elt(env, 4); /* rlisp */
    stack[-3] = (Lisp_Object)177; /* 11 */
    v94 = stack[-5];
    stack[-2] = qcar(v94);
    stack[-1] = elt(env, 5); /* "called with" */
    v94 = stack[-5];
    v94 = qcdr(v94);
    stack[0] = Llength(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-7];
    v94 = stack[-5];
    v94 = qcdr(v94);
    v95 = Llength(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-7];
    v94 = (Lisp_Object)17; /* 1 */
    if (v95 == v94) goto v192;
    v94 = elt(env, 7); /* "arguments" */
    v190 = v94;
    goto v138;

v138:
    v95 = elt(env, 8); /* "instead of" */
    v94 = stack[-6];
    v94 = list3(v190, v95, v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-7];
    v94 = list3star(stack[-2], stack[-1], stack[0], v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    env = stack[-7];
    fn = elt(env, 10); /* rerror */
    v94 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[-3], v94);
    nil = C_nil;
    if (exception_pending()) goto v93;
    v94 = nil;
    { popv(8); return onevalue(v94); }

v192:
    v94 = elt(env, 6); /* "argument" */
    v190 = v94;
    goto v138;
/* error exit handlers */
v93:
    popv(8);
    return nil;
}



/* Code for pneg */

static Lisp_Object CC_pneg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pneg");
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
    v153 = v0;
/* end of prologue */
    stack[-4] = v153;
    v153 = stack[-4];
    if (v153 == nil) goto v109;
    v153 = stack[-4];
    v153 = qcar(v153);
    v15 = v153;
    v153 = v15;
    stack[0] = qcar(v153);
    v153 = v15;
    v153 = qcdr(v153);
    fn = elt(env, 2); /* cneg */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    v153 = cons(stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    stack[-2] = v153;
    stack[-3] = v153;
    goto v29;

v29:
    v153 = stack[-4];
    v153 = qcdr(v153);
    stack[-4] = v153;
    v153 = stack[-4];
    if (v153 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v153 = stack[-4];
    v153 = qcar(v153);
    v15 = v153;
    v153 = v15;
    stack[0] = qcar(v153);
    v153 = v15;
    v153 = qcdr(v153);
    fn = elt(env, 2); /* cneg */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    v153 = cons(stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    v153 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    v153 = Lrplacd(nil, stack[-1], v153);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-5];
    v153 = stack[-2];
    v153 = qcdr(v153);
    stack[-2] = v153;
    goto v29;

v109:
    v153 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v153); }
/* error exit handlers */
v174:
    popv(6);
    return nil;
}



/* Code for ordn */

static Lisp_Object CC_ordn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordn");
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
    v103 = v0;
/* end of prologue */
    v102 = v103;
    if (v102 == nil) goto v30;
    v102 = v103;
    v102 = qcdr(v102);
    if (v102 == nil) { popv(2); return onevalue(v103); }
    v102 = v103;
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    if (v102 == nil) goto v158;
    v102 = v103;
    stack[0] = qcar(v102);
    v102 = v103;
    v102 = qcdr(v102);
    v102 = CC_ordn(env, v102);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-1];
    {
        Lisp_Object v142 = stack[0];
        popv(2);
        fn = elt(env, 2); /* ordad */
        return (*qfn2(fn))(qenv(fn), v142, v102);
    }

v158:
    v102 = v103;
    v102 = qcar(v102);
    v103 = qcdr(v103);
    v103 = qcar(v103);
    {
        popv(2);
        fn = elt(env, 3); /* ord2 */
        return (*qfn2(fn))(qenv(fn), v102, v103);
    }

v30:
    v102 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v102); }
/* error exit handlers */
v141:
    popv(2);
    return nil;
}



/* Code for general!-modular!-reciprocal */

static Lisp_Object CC_generalKmodularKreciprocal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v187, v147, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-modular-reciprocal");
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
    v155 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v155 == nil) goto v17;
    v187 = stack[0];
    v155 = (Lisp_Object)1; /* 0 */
    v155 = (Lisp_Object)lessp2(v187, v155);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v155 = v155 ? lisp_true : nil;
    env = stack[-2];
    if (v155 == nil) goto v17;
    stack[-1] = qvalue(elt(env, 2)); /* current!-modulus */
    v187 = stack[0];
    v155 = qvalue(elt(env, 2)); /* current!-modulus */
    v147 = plus2(v187, v155);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v187 = (Lisp_Object)1; /* 0 */
    v155 = (Lisp_Object)17; /* 1 */
    {
        Lisp_Object v152 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v152, v147, v187, v155);
    }

v17:
    v11 = qvalue(elt(env, 2)); /* current!-modulus */
    v147 = stack[0];
    v187 = (Lisp_Object)1; /* 0 */
    v155 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 3); /* general!-reciprocal!-by!-gcd */
        return (*qfnn(fn))(qenv(fn), 4, v11, v147, v187, v155);
    }
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



/* Code for diff */

static Lisp_Object CC_diff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v9;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v29;

v29:
    v215 = stack[-3];
    if (!consp(v215)) goto v111;
    v215 = stack[-3];
    v215 = qcar(v215);
    if (!consp(v215)) goto v111;
    v215 = stack[-3];
    v215 = qcar(v215);
    v213 = qcar(v215);
    v215 = (Lisp_Object)17; /* 1 */
    v215 = cons(v213, v215);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    stack[0] = ncons(v215);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v215 = stack[-3];
    v215 = qcar(v215);
    v213 = qcdr(v215);
    v215 = stack[-2];
    v215 = CC_diff(env, v213, v215);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    fn = elt(env, 2); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v215);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v215 = stack[-3];
    v215 = qcar(v215);
    stack[0] = qcdr(v215);
    v215 = stack[-3];
    v215 = qcar(v215);
    v213 = qcar(v215);
    v215 = stack[-2];
    fn = elt(env, 3); /* diffp1 */
    v215 = (*qfn2(fn))(qenv(fn), v213, v215);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    fn = elt(env, 2); /* multf */
    v215 = (*qfn2(fn))(qenv(fn), stack[0], v215);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    fn = elt(env, 4); /* addf */
    v213 = (*qfn2(fn))(qenv(fn), stack[-1], v215);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v215 = stack[-4];
    v215 = cons(v213, v215);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    stack[-4] = v215;
    v215 = stack[-3];
    v215 = qcdr(v215);
    stack[-3] = v215;
    goto v29;

v111:
    v215 = qvalue(elt(env, 1)); /* nil */
    v213 = v215;
    goto v154;

v154:
    v215 = stack[-4];
    if (v215 == nil) { popv(6); return onevalue(v213); }
    v215 = stack[-4];
    v215 = qcar(v215);
    fn = elt(env, 4); /* addf */
    v215 = (*qfn2(fn))(qenv(fn), v215, v213);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-5];
    v213 = v215;
    v215 = stack[-4];
    v215 = qcdr(v215);
    stack[-4] = v215;
    goto v154;
/* error exit handlers */
v95:
    popv(6);
    return nil;
}



/* Code for wuorderp */

static Lisp_Object CC_wuorderp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v216, v217, v143, v130, v144;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wuorderp");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v130 = v9;
    v144 = v0;
/* end of prologue */
    v217 = nil;
    v216 = v144;
    v92 = v130;
    if (v216 == v92) goto v154;
    v92 = qvalue(elt(env, 2)); /* wukord!* */
    v143 = v92;
    goto v21;

v21:
    v92 = v143;
    if (v92 == nil) goto v1;
    v92 = v217;
    if (!(v92 == nil)) goto v1;
    v216 = v144;
    v92 = v143;
    v92 = qcar(v92);
    if (v216 == v92) goto v20;
    v216 = v130;
    v92 = v143;
    v92 = qcar(v92);
    if (v216 == v92) goto v25;
    v92 = v143;
    v92 = qcdr(v92);
    v143 = v92;
    goto v21;

v25:
    v216 = v144;
    v92 = v143;
    v92 = qcdr(v92);
    v92 = Lmemq(nil, v216, v92);
    if (v92 == nil) goto v173;
    v92 = elt(env, 4); /* no */
    goto v218;

v218:
    v217 = v92;
    goto v21;

v173:
    v92 = elt(env, 3); /* yes */
    goto v218;

v20:
    v216 = v130;
    v92 = v143;
    v92 = qcdr(v92);
    v92 = Lmemq(nil, v216, v92);
    if (v92 == nil) goto v156;
    v92 = elt(env, 3); /* yes */
    goto v141;

v141:
    v217 = v92;
    goto v21;

v156:
    v92 = elt(env, 4); /* no */
    goto v141;

v1:
    v92 = v217;
    if (v92 == nil) goto v219;
    v92 = v217;
    v216 = elt(env, 3); /* yes */
    v92 = (v92 == v216 ? lisp_true : nil);
    return onevalue(v92);

v219:
    v92 = v144;
    v216 = v130;
    v92 = Lorderp(nil, v92, v216);
    errexit();
    v92 = (v92 == nil ? lisp_true : nil);
    return onevalue(v92);

v154:
    v92 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v92);
}



/* Code for msappend */

static Lisp_Object CC_msappend(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v218;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msappend");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v9;
    v12 = v0;
/* end of prologue */
    stack[-5] = v12;
    v12 = stack[-5];
    if (v12 == nil) goto v7;
    v12 = stack[-5];
    v12 = qcar(v12);
    stack[0] = stack[-4];
    v218 = stack[-4];
    v12 = Lsublis(nil, v218, v12);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-6];
    v12 = Lappend(nil, stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-6];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-6];
    stack[-2] = v12;
    stack[-3] = v12;
    goto v111;

v111:
    v12 = stack[-5];
    v12 = qcdr(v12);
    stack[-5] = v12;
    v12 = stack[-5];
    if (v12 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v12 = stack[-5];
    v12 = qcar(v12);
    stack[0] = stack[-4];
    v218 = stack[-4];
    v12 = Lsublis(nil, v218, v12);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-6];
    v12 = Lappend(nil, stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-6];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-6];
    v12 = Lrplacd(nil, stack[-1], v12);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-6];
    v12 = stack[-2];
    v12 = qcdr(v12);
    stack[-2] = v12;
    goto v111;

v7:
    v12 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v12); }
/* error exit handlers */
v26:
    popv(7);
    return nil;
}



/* Code for ckrn1 */

static Lisp_Object CC_ckrn1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckrn1");
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
    v88 = stack[0];
    if (!consp(v88)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v88 = stack[0];
    v88 = qcar(v88);
    if (!consp(v88)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    else goto v160;

v160:
    v88 = stack[0];
    v88 = qcar(v88);
    v88 = qcdr(v88);
    v214 = CC_ckrn1(env, v88);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-2];
    v88 = stack[-1];
    fn = elt(env, 1); /* gck2 */
    v88 = (*qfn2(fn))(qenv(fn), v214, v88);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-2];
    stack[-1] = v88;
    v88 = stack[0];
    v88 = qcdr(v88);
    if (v88 == nil) goto v3;
    v88 = stack[0];
    v88 = qcdr(v88);
    if (!consp(v88)) goto v204;
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = qcar(v88);
    if (!consp(v88)) goto v204;
    v88 = stack[0];
    v88 = qcar(v88);
    v88 = qcar(v88);
    v214 = qcar(v88);
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = qcar(v88);
    v88 = qcar(v88);
    v88 = qcar(v88);
    if (!(v214 == v88)) goto v204;
    v88 = stack[0];
    v88 = qcdr(v88);
    stack[0] = v88;
    goto v160;

v204:
    v88 = stack[0];
    v88 = qcdr(v88);
    v214 = CC_ckrn1(env, v88);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-2];
    v88 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* gck2 */
        return (*qfn2(fn))(qenv(fn), v214, v88);
    }

v3:
    v88 = stack[0];
    v88 = qcar(v88);
    v88 = qcar(v88);
    v88 = qcar(v88);
    fn = elt(env, 2); /* noncomp */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-2];
    if (!(v88 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v88 = stack[0];
    v88 = qcar(v88);
    v214 = qcar(v88);
    v88 = stack[-1];
    v88 = cons(v214, v88);
    nil = C_nil;
    if (exception_pending()) goto v208;
    popv(3);
    return ncons(v88);
/* error exit handlers */
v208:
    popv(3);
    return nil;
}



/* Code for multiom */

static Lisp_Object CC_multiom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiom");
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
    v183 = stack[0];
    v3 = Llength(nil, v183);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v183 = (Lisp_Object)17; /* 1 */
    if (v3 == v183) goto v47;
    v183 = stack[0];
    v183 = qcar(v183);
    fn = elt(env, 2); /* objectom */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v183 = stack[0];
    v183 = qcdr(v183);
    v183 = CC_multiom(env, v183);
    nil = C_nil;
    if (exception_pending()) goto v5;
    goto v6;

v6:
    v183 = nil;
    { popv(2); return onevalue(v183); }

v47:
    v183 = stack[0];
    v183 = qcar(v183);
    fn = elt(env, 2); /* objectom */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v5;
    goto v6;
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for c!:extmult */

static Lisp_Object CC_cTextmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:extmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v9;
    stack[-2] = v0;
/* end of prologue */
    v224 = stack[-2];
    if (v224 == nil) goto v6;
    v224 = stack[-1];
    if (v224 == nil) goto v6;
    v114 = stack[-1];
    v224 = (Lisp_Object)17; /* 1 */
    if (v114 == v224) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v224 = stack[-2];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v114 = qcar(v224);
    v224 = stack[-1];
    v224 = qcar(v224);
    v224 = qcar(v224);
    fn = elt(env, 2); /* c!:ordexn */
    v224 = (*qfn2(fn))(qenv(fn), v114, v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v114 = v224;
    v224 = v114;
    if (v224 == nil) goto v200;
    v224 = v114;
    stack[0] = qcdr(v224);
    v224 = v114;
    v224 = qcar(v224);
    if (v224 == nil) goto v28;
    v224 = stack[-2];
    v224 = qcar(v224);
    v114 = qcdr(v224);
    v224 = stack[-1];
    v224 = qcar(v224);
    v224 = qcdr(v224);
    fn = elt(env, 3); /* c!:subs2multf */
    v224 = (*qfn2(fn))(qenv(fn), v114, v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    fn = elt(env, 4); /* negf */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    goto v155;

v155:
    v224 = cons(stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    stack[-3] = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v224 = stack[-2];
    v224 = qcar(v224);
    v114 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v224 = stack[-1];
    v224 = qcdr(v224);
    stack[0] = CC_cTextmult(env, v114, v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v224 = stack[-2];
    v114 = qcdr(v224);
    v224 = stack[-1];
    v224 = CC_cTextmult(env, v114, v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    fn = elt(env, 5); /* c!:extadd */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    {
        Lisp_Object v84 = stack[-3];
        popv(5);
        fn = elt(env, 5); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v84, v224);
    }

v28:
    v224 = stack[-2];
    v224 = qcar(v224);
    v114 = qcdr(v224);
    v224 = stack[-1];
    v224 = qcar(v224);
    v224 = qcdr(v224);
    fn = elt(env, 3); /* c!:subs2multf */
    v224 = (*qfn2(fn))(qenv(fn), v114, v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    goto v155;

v200:
    v224 = stack[-2];
    v224 = qcar(v224);
    v114 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v224 = stack[-1];
    v224 = qcdr(v224);
    stack[0] = CC_cTextmult(env, v114, v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v224 = stack[-2];
    v114 = qcdr(v224);
    v224 = stack[-1];
    v224 = CC_cTextmult(env, v114, v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    {
        Lisp_Object v85 = stack[0];
        popv(5);
        fn = elt(env, 5); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v85, v224);
    }

v6:
    v224 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v224); }
/* error exit handlers */
v225:
    popv(5);
    return nil;
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate0");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    v7 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v23 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v159;
    env = stack[-1];
    v7 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v23, v7);
    }
/* error exit handlers */
v159:
    popv(2);
    return nil;
}



/* Code for opnum!* */

static Lisp_Object CC_opnumH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v13, v24, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opnum*");
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
    v218 = v0;
/* end of prologue */
    stack[-1] = nil;
    v13 = v218;
    if (symbolp(v13)) goto v29;
    stack[0] = v218;
    fn = elt(env, 3); /* collectindices */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    fn = elt(env, 4); /* removeindices */
    v218 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-2];
    goto v29;

v29:
    v13 = v218;
    if (symbolp(v13)) goto v21;
    v13 = v218;
    v13 = qcar(v13);
    v25 = v13;
    v218 = qcdr(v218);
    stack[-1] = v218;
    goto v185;

v185:
    v24 = stack[-1];
    v13 = v25;
    v218 = elt(env, 2); /* opnum */
    v218 = get(v13, v218);
    env = stack[-2];
    v13 = Lassoc(nil, v24, v218);
    v218 = v13;
    if (v13 == nil) goto v128;
    v218 = qcdr(v218);
    { popv(3); return onevalue(v218); }

v128:
    v13 = qvalue(elt(env, 1)); /* nil */
    v24 = v25;
    v218 = elt(env, 2); /* opnum */
    v218 = get(v24, v218);
    v218 = Lassoc(nil, v13, v218);
    v218 = qcdr(v218);
    { popv(3); return onevalue(v218); }

v21:
    v25 = v218;
    goto v185;
/* error exit handlers */
v98:
    popv(3);
    return nil;
}



/* Code for quotfd */

static Lisp_Object CC_quotfd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v151, v134, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfd");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v151 = v9;
    v134 = v0;
/* end of prologue */
    v152 = v134;
    v156 = v151;
    if (equal(v152, v156)) goto v6;
    v152 = qvalue(elt(env, 1)); /* dmode!* */
    v156 = elt(env, 2); /* field */
    v156 = Lflagp(nil, v152, v156);
    env = stack[0];
    if (v156 == nil) goto v110;
    v156 = v134;
    {
        popv(1);
        fn = elt(env, 3); /* divd */
        return (*qfn2(fn))(qenv(fn), v156, v151);
    }

v110:
    v156 = v134;
    if (!consp(v156)) goto v17;
    v156 = v134;
    v156 = qcar(v156);
    if (!consp(v156)) goto v17;
    v156 = v134;
    {
        popv(1);
        fn = elt(env, 4); /* quotk */
        return (*qfn2(fn))(qenv(fn), v156, v151);
    }

v17:
    v156 = v134;
    {
        popv(1);
        fn = elt(env, 5); /* quotdd */
        return (*qfn2(fn))(qenv(fn), v156, v151);
    }

v6:
    v156 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v156); }
}



/* Code for getelv */

static Lisp_Object CC_getelv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getelv");
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
    v187 = v0;
/* end of prologue */
    v155 = v187;
    stack[-4] = qcar(v155);
    v155 = v187;
    v155 = qcdr(v155);
    stack[-3] = v155;
    v155 = stack[-3];
    if (v155 == nil) goto v1;
    v155 = stack[-3];
    v155 = qcar(v155);
    fn = elt(env, 2); /* reval_without_mod */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    stack[-1] = v155;
    stack[-2] = v155;
    goto v110;

v110:
    v155 = stack[-3];
    v155 = qcdr(v155);
    stack[-3] = v155;
    v155 = stack[-3];
    if (v155 == nil) goto v105;
    stack[0] = stack[-1];
    v155 = stack[-3];
    v155 = qcar(v155);
    fn = elt(env, 2); /* reval_without_mod */
    v155 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v155 = ncons(v155);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v155 = Lrplacd(nil, stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    v155 = stack[-1];
    v155 = qcdr(v155);
    stack[-1] = v155;
    goto v110;

v105:
    v155 = stack[-2];
    goto v29;

v29:
    v155 = cons(stack[-4], v155);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 3); /* getel */
        return (*qfn1(fn))(qenv(fn), v155);
    }

v1:
    v155 = qvalue(elt(env, 1)); /* nil */
    goto v29;
/* error exit handlers */
v152:
    popv(6);
    return nil;
}



/* Code for !*i2ar */

static Lisp_Object CC_Hi2ar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2ar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v115 = v0;
/* end of prologue */
    v109 = elt(env, 1); /* !:ar!: */
    return cons(v109, v115);
}



/* Code for wulessp!* */

static Lisp_Object CC_wulesspH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v185, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp*");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */
    v139 = stack[-1];
    v185 = stack[0];
    fn = elt(env, 3); /* wulessp */
    v185 = (*qfn2(fn))(qenv(fn), v139, v185);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    if (v185 == nil) goto v158;
    v185 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v185); }

v158:
    v139 = stack[0];
    v185 = stack[-1];
    fn = elt(env, 3); /* wulessp */
    v185 = (*qfn2(fn))(qenv(fn), v139, v185);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-2];
    if (v185 == nil) goto v4;
    v185 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v185); }

v4:
    v139 = stack[-1];
    v185 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* totallessp */
        return (*qfn2(fn))(qenv(fn), v139, v185);
    }
/* error exit handlers */
v17:
    popv(3);
    return nil;
}



/* Code for comfac */

static Lisp_Object CC_comfac(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comfac");
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
    v198 = qvalue(elt(env, 1)); /* dmode!* */
    v114 = elt(env, 2); /* field */
    v114 = Lflagp(nil, v198, v114);
    env = stack[-4];
    if (v114 == nil) goto v111;
    v114 = stack[-2];
    fn = elt(env, 4); /* lnc */
    v198 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    stack[-3] = v198;
    v114 = (Lisp_Object)17; /* 1 */
    if (v198 == v114) goto v111;
    v114 = stack[-3];
    fn = elt(env, 5); /* !:recip */
    v198 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v114 = stack[-2];
    fn = elt(env, 6); /* multd */
    v114 = (*qfn2(fn))(qenv(fn), v198, v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    stack[-2] = v114;
    goto v111;

v111:
    v114 = stack[-2];
    v114 = qcdr(v114);
    if (v114 == nil) goto v157;
    v114 = stack[-2];
    v114 = qcar(v114);
    v114 = qcdr(v114);
    stack[-3] = v114;
    v114 = stack[-2];
    v114 = qcar(v114);
    v114 = qcar(v114);
    v114 = qcar(v114);
    stack[-1] = v114;
    goto v47;

v47:
    v114 = stack[-2];
    v114 = qcdr(v114);
    stack[-2] = v114;
    v198 = stack[-2];
    v114 = stack[-1];
    fn = elt(env, 7); /* degr */
    v198 = (*qfn2(fn))(qenv(fn), v198, v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    v114 = (Lisp_Object)1; /* 0 */
    if (v198 == v114) goto v24;
    v114 = stack[-2];
    v114 = qcdr(v114);
    if (v114 == nil) goto v92;
    v114 = stack[-2];
    v114 = qcar(v114);
    v198 = qcdr(v114);
    v114 = stack[-3];
    fn = elt(env, 8); /* gcdf */
    v114 = (*qfn2(fn))(qenv(fn), v198, v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    stack[-3] = v114;
    goto v47;

v92:
    v114 = stack[-2];
    v114 = qcar(v114);
    stack[0] = qcar(v114);
    v198 = stack[-3];
    v114 = stack[-2];
    v114 = qcar(v114);
    v114 = qcdr(v114);
    fn = elt(env, 8); /* gcdf */
    v114 = (*qfn2(fn))(qenv(fn), v198, v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    {
        Lisp_Object v85 = stack[0];
        popv(5);
        return cons(v85, v114);
    }

v24:
    stack[0] = qvalue(elt(env, 3)); /* nil */
    v114 = stack[-2];
    if (!consp(v114)) goto v227;
    v114 = stack[-2];
    v114 = qcar(v114);
    if (!consp(v114)) goto v227;
    v114 = stack[-1];
    fn = elt(env, 9); /* noncomp */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    if (v114 == nil) goto v227;
    v114 = stack[-2];
    v114 = qcar(v114);
    v114 = qcar(v114);
    v114 = qcar(v114);
    fn = elt(env, 9); /* noncomp */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-4];
    if (v114 == nil) goto v227;
    v114 = (Lisp_Object)17; /* 1 */
    goto v138;

v138:
    {
        Lisp_Object v80 = stack[0];
        popv(5);
        return cons(v80, v114);
    }

v227:
    v198 = stack[-3];
    v114 = stack[-2];
    fn = elt(env, 8); /* gcdf */
    v114 = (*qfn2(fn))(qenv(fn), v198, v114);
    nil = C_nil;
    if (exception_pending()) goto v84;
    goto v138;

v157:
    v114 = stack[-2];
    v114 = qcar(v114);
    { popv(5); return onevalue(v114); }
/* error exit handlers */
v84:
    popv(5);
    return nil;
}



/* Code for rl_sacatlp */

static Lisp_Object CC_rl_sacatlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_sacatlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v161 = v9;
    v158 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacatlp!* */
    v161 = list2(v158, v161);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    {
        Lisp_Object v21 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v21, v161);
    }
/* error exit handlers */
v1:
    popv(2);
    return nil;
}



/* Code for objectom */

static Lisp_Object CC_objectom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for objectom");
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
    v19 = v0;
/* end of prologue */
    v142 = v19;
    v142 = Lconsp(nil, v142);
    env = stack[-1];
    if (v142 == nil) goto v102;
    v142 = v19;
    v20 = qcar(v142);
    v142 = qvalue(elt(env, 1)); /* ir2mml!* */
    v142 = Lassoc(nil, v20, v142);
    v20 = v142;
    if (v142 == nil) goto v185;
    v142 = v20;
    v142 = qcdr(v142);
    v142 = qcdr(v142);
    v142 = qcdr(v142);
    stack[0] = qcar(v142);
    v142 = v19;
    v142 = ncons(v142);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    fn = elt(env, 3); /* apply */
    v142 = (*qfn2(fn))(qenv(fn), stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v14;
    goto v47;

v47:
    v142 = nil;
    { popv(2); return onevalue(v142); }

v185:
    v142 = v19;
    fn = elt(env, 4); /* fnom */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v14;
    goto v47;

v102:
    v142 = v19;
    fn = elt(env, 5); /* basicom */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v14;
    goto v47;
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for initwght */

static Lisp_Object CC_initwght(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initwght");
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
    stack[-3] = v0;
/* end of prologue */
    v166 = (Lisp_Object)1; /* 0 */
    stack[-5] = v166;
    stack[0] = v166;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v164 = qvalue(elt(env, 2)); /* maxvar */
    v166 = stack[-3];
    v166 = plus2(v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    v164 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v166/(16/CELL)));
    v166 = (Lisp_Object)65; /* 4 */
    v166 = *(Lisp_Object *)((char *)v164 + (CELL-TAG_VECTOR) + ((int32_t)v166/(16/CELL)));
    stack[-4] = v166;
    goto v115;

v115:
    v166 = stack[-4];
    if (v166 == nil) goto v96;
    v166 = stack[-4];
    v166 = qcar(v166);
    stack[-2] = v166;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v164 = qvalue(elt(env, 2)); /* maxvar */
    v166 = stack[-2];
    v166 = qcar(v166);
    v166 = plus2(v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    v164 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v166/(16/CELL)));
    v166 = (Lisp_Object)1; /* 0 */
    v166 = *(Lisp_Object *)((char *)v164 + (CELL-TAG_VECTOR) + ((int32_t)v166/(16/CELL)));
    if (v166 == nil) goto v103;
    v166 = stack[-2];
    v166 = qcdr(v166);
    v166 = qcar(v166);
    fn = elt(env, 4); /* dm!-abs */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    fn = elt(env, 5); /* !:onep */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    if (!(v166 == nil)) goto v212;
    v166 = stack[-5];
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    stack[-5] = v166;
    goto v212;

v212:
    v166 = stack[0];
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    stack[0] = v166;
    goto v103;

v103:
    v166 = stack[-4];
    v166 = qcdr(v166);
    stack[-4] = v166;
    goto v115;

v96:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v164 = qvalue(elt(env, 2)); /* maxvar */
    v166 = stack[-3];
    v166 = plus2(v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v166/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v164 = (Lisp_Object)49; /* 3 */
    v166 = stack[-5];
    v166 = times2(v164, v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    v166 = plus2(stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-6];
    v166 = acons(stack[-2], stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v228;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v166;
    v166 = nil;
    { popv(7); return onevalue(v166); }
/* error exit handlers */
v228:
    popv(7);
    return nil;
}



/* Code for vecp */

static Lisp_Object CC_vecp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v94, v95, v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecp");
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
    v202 = v95;
    if (v202 == nil) goto v29;
    v202 = v95;
    if (is_number(v202)) goto v29;
    v202 = v95;
    if (!consp(v202)) goto v27;
    v202 = v95;
    v202 = Lthreevectorp(nil, v202);
    env = stack[0];
    if (v202 == nil) goto v139;
    v202 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v202); }

v139:
    v202 = v95;
    v202 = qcar(v202);
    v190 = v202;
    if (!(!consp(v202))) goto v174;
    v94 = v190;
    v202 = elt(env, 2); /* rtype */
    v94 = get(v94, v202);
    env = stack[0];
    v202 = elt(env, 3); /* !3vector */
    if (!(v94 == v202)) goto v174;
    v202 = v95;
    v202 = qcdr(v202);
    v202 = qcar(v202);
    {
        popv(1);
        fn = elt(env, 8); /* isvectorindex */
        return (*qfn1(fn))(qenv(fn), v202);
    }

v174:
    v94 = v190;
    v202 = elt(env, 5); /* vectorfn */
    v202 = Lflagp(nil, v94, v202);
    env = stack[0];
    if (v202 == nil) goto v203;
    v202 = qvalue(elt(env, 4)); /* t */
    { popv(1); return onevalue(v202); }

v203:
    v94 = v190;
    v202 = elt(env, 6); /* varithop */
    v202 = Lflagp(nil, v94, v202);
    env = stack[0];
    if (!(v202 == nil)) goto v138;
    v94 = v190;
    v202 = elt(env, 7); /* vectormapping */
    v202 = Lflagp(nil, v94, v202);
    env = stack[0];
    if (!(v202 == nil)) goto v138;
    v202 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v202); }

v138:
    v202 = v95;
    v202 = qcdr(v202);
    {
        popv(1);
        fn = elt(env, 9); /* hasonevector */
        return (*qfn1(fn))(qenv(fn), v202);
    }

v27:
    v94 = v95;
    v202 = elt(env, 2); /* rtype */
    v202 = get(v94, v202);
    env = stack[0];
    v94 = elt(env, 3); /* !3vector */
    v202 = (v202 == v94 ? lisp_true : nil);
    if (!(v202 == nil)) { popv(1); return onevalue(v202); }
    v202 = v95;
        popv(1);
        return Lthreevectorp(nil, v202);

v29:
    v202 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v202); }
}



/* Code for copy!-vector */

static Lisp_Object MS_CDECL CC_copyKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v9,
                         Lisp_Object v180, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v112, v141, v142, v19, v20, v18, v14;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "copy-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy-vector");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v180;
    v20 = v9;
    v18 = v0;
/* end of prologue */
    v103 = (Lisp_Object)1; /* 0 */
    v14 = v103;
    goto v23;

v23:
    v112 = v20;
    v103 = v14;
    v103 = (Lisp_Object)(int32_t)((int32_t)v112 - (int32_t)v103 + TAG_FIXNUM);
    v103 = ((intptr_t)(v103) < 0 ? lisp_true : nil);
    if (!(v103 == nil)) return onevalue(v20);
    v142 = v19;
    v141 = v14;
    v112 = v18;
    v103 = v14;
    v103 = *(Lisp_Object *)((char *)v112 + (CELL-TAG_VECTOR) + ((int32_t)v103/(16/CELL)));
    *(Lisp_Object *)((char *)v142 + (CELL-TAG_VECTOR) + ((int32_t)v141/(16/CELL))) = v103;
    v103 = v14;
    v103 = (Lisp_Object)((int32_t)(v103) + 0x10);
    v14 = v103;
    goto v23;
}



/* Code for reduce!-mod!-p */

static Lisp_Object CC_reduceKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-p");
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
    v139 = stack[-1];
    if (v139 == nil) goto v30;
    v139 = stack[-1];
    if (!consp(v139)) goto v111;
    v139 = stack[-1];
    v139 = qcar(v139);
    if (!consp(v139)) goto v111;
    v139 = stack[-1];
    v139 = qcar(v139);
    stack[-2] = qcar(v139);
    v139 = stack[-1];
    v139 = qcar(v139);
    v139 = qcdr(v139);
    stack[0] = CC_reduceKmodKp(env, v139);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    v139 = stack[-1];
    v139 = qcdr(v139);
    v139 = CC_reduceKmodKp(env, v139);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-3];
    {
        Lisp_Object v103 = stack[-2];
        Lisp_Object v112 = stack[0];
        popv(4);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v103, v112, v139);
    }

v111:
    v139 = stack[-1];
    v139 = Lmodular_number(nil, v139);
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v139);
    }

v30:
    v139 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v139); }
/* error exit handlers */
v102:
    popv(4);
    return nil;
}



/* Code for gintequiv!: */

static Lisp_Object CC_gintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v21, v22;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gintequiv:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v0;
/* end of prologue */
    v1 = v22;
    v1 = qcdr(v1);
    v21 = qcdr(v1);
    v1 = (Lisp_Object)1; /* 0 */
    if (v21 == v1) goto v30;
    v1 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v1);

v30:
    v1 = v22;
    v1 = qcdr(v1);
    v1 = qcar(v1);
    return onevalue(v1);
}



/* Code for mapins */

static Lisp_Object CC_mapins(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v17, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapins");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v47;

v47:
    v157 = stack[0];
    if (v157 == nil) goto v154;
    v17 = stack[-1];
    v157 = stack[0];
    v157 = qcar(v157);
    v157 = qcar(v157);
    v102 = cons(v17, v157);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    v157 = stack[0];
    v157 = qcar(v157);
    v17 = qcdr(v157);
    v157 = stack[-2];
    v157 = acons(v102, v17, v157);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    stack[-2] = v157;
    v157 = stack[0];
    v157 = qcdr(v157);
    stack[0] = v157;
    goto v47;

v154:
    v157 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v157);
    }
/* error exit handlers */
v142:
    popv(4);
    return nil;
}



/* Code for totallessp */

static Lisp_Object CC_totallessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totallessp");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v161 = v9;
    v158 = v0;
/* end of prologue */
    fn = elt(env, 2); /* totalcompare */
    v161 = (*qfn2(fn))(qenv(fn), v158, v161);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[0];
    v158 = elt(env, 1); /* less */
    v161 = (v161 == v158 ? lisp_true : nil);
    { popv(1); return onevalue(v161); }
/* error exit handlers */
v2:
    popv(1);
    return nil;
}



/* Code for exceeds!-order */

static Lisp_Object CC_exceedsKorder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exceeds-order");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */

v229:
    v134 = stack[-1];
    if (v134 == nil) goto v6;
    v134 = stack[0];
    v134 = qcar(v134);
    stack[-2] = v134;
    v134 = (Lisp_Object)1; /* 0 */
    v152 = v134;
    goto v101;

v101:
    v134 = stack[-2];
    if (v134 == nil) goto v4;
    v134 = stack[-2];
    v134 = qcar(v134);
    fn = elt(env, 2); /* tayexp!-plus2 */
    v134 = (*qfn2(fn))(qenv(fn), v134, v152);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    v152 = v134;
    v134 = stack[-2];
    v134 = qcdr(v134);
    stack[-2] = v134;
    goto v101;

v4:
    v134 = v152;
    v152 = v134;
    v134 = stack[-1];
    v134 = qcar(v134);
    fn = elt(env, 3); /* tayexp!-lessp */
    v134 = (*qfn2(fn))(qenv(fn), v152, v134);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-3];
    v134 = (v134 == nil ? lisp_true : nil);
    if (!(v134 == nil)) { popv(4); return onevalue(v134); }
    v134 = stack[-1];
    v152 = qcdr(v134);
    v134 = stack[0];
    v134 = qcdr(v134);
    stack[-1] = v152;
    stack[0] = v134;
    goto v229;

v6:
    v134 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v134); }
/* error exit handlers */
v10:
    popv(4);
    return nil;
}



/* Code for ibalp_var!-unset */

static Lisp_Object CC_ibalp_varKunset(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-unset");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v9;
    stack[-4] = v0;
/* end of prologue */
    v234 = stack[-4];
    v179 = qcdr(v234);
    v234 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v234 = (*qfn2(fn))(qenv(fn), v179, v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v234 = stack[-4];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v179 = qcdr(v234);
    v234 = (Lisp_Object)-15; /* -1 */
    fn = elt(env, 2); /* setcar */
    v234 = (*qfn2(fn))(qenv(fn), v179, v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v234 = stack[-4];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v179 = qcdr(v234);
    v234 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v234 = (*qfn2(fn))(qenv(fn), v179, v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v234 = stack[-4];
    v234 = qcar(v234);
    stack[-5] = v234;
    v179 = stack[-3];
    v234 = (Lisp_Object)17; /* 1 */
    v234 = Leqn(nil, v179, v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    if (v234 == nil) goto v10;
    v234 = stack[-4];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    goto v18;

v18:
    stack[-2] = v234;
    goto v24;

v24:
    v234 = stack[-2];
    if (v234 == nil) goto v221;
    v234 = stack[-2];
    v234 = qcar(v234);
    stack[-1] = v234;
    v179 = stack[-3];
    v234 = (Lisp_Object)17; /* 1 */
    v234 = Leqn(nil, v179, v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    if (v234 == nil) goto v92;
    v234 = stack[-1];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    stack[0] = qcdr(v234);
    v234 = stack[-1];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v234 = add1(v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v234 = (*qfn2(fn))(qenv(fn), stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v129;

v129:
    v234 = stack[-2];
    v234 = qcdr(v234);
    stack[-2] = v234;
    goto v24;

v92:
    v234 = stack[-1];
    v234 = qcdr(v234);
    stack[0] = qcdr(v234);
    v234 = stack[-1];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    v234 = add1(v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v234 = (*qfn2(fn))(qenv(fn), stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    goto v129;

v221:
    v179 = stack[-3];
    v234 = (Lisp_Object)1; /* 0 */
    v234 = Leqn(nil, v179, v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    if (v234 == nil) goto v199;
    v234 = stack[-4];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    goto v236;

v236:
    v179 = v234;
    v234 = stack[-5];
    fn = elt(env, 3); /* ibalp_unvar!-unsatlist */
    v234 = (*qfn2(fn))(qenv(fn), v179, v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    v234 = stack[-4];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    stack[0] = qcdr(v234);
    v234 = stack[-4];
    fn = elt(env, 4); /* ibalp_calcmom */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v234 = (*qfn2(fn))(qenv(fn), stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v235;
    v234 = nil;
    { popv(7); return onevalue(v234); }

v199:
    v234 = stack[-4];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    goto v236;

v10:
    v234 = stack[-4];
    v234 = qcdr(v234);
    v234 = qcdr(v234);
    v234 = qcar(v234);
    goto v18;
/* error exit handlers */
v235:
    popv(7);
    return nil;
}



/* Code for expression */

static Lisp_Object CC_expression(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v202, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expression");
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
    v94 = v0;
/* end of prologue */
    v149 = v94;
    if (!consp(v149)) goto v29;
    v149 = v94;
    v202 = qcar(v149);
    v149 = elt(env, 1); /* !:rd!: */
    if (v202 == v149) goto v7;
    v149 = v94;
    v202 = qcar(v149);
    v149 = qvalue(elt(env, 2)); /* unary!* */
    v149 = Lassoc(nil, v202, v149);
    v202 = v149;
    if (v149 == nil) goto v192;
    v149 = v202;
    v149 = qcdr(v149);
    v149 = qcdr(v149);
    v149 = qcar(v149);
    if (v149 == nil) goto v20;
    v149 = v202;
    v149 = qcdr(v149);
    stack[0] = qcar(v149);
    v149 = v94;
    v149 = qcdr(v149);
    v202 = qcdr(v202);
    v202 = qcdr(v202);
    v202 = qcar(v202);
    v149 = list2(v149, v202);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-1];
    fn = elt(env, 5); /* apply */
    v149 = (*qfn2(fn))(qenv(fn), stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v190;
    goto v47;

v47:
    v149 = nil;
    { popv(2); return onevalue(v149); }

v20:
    v149 = v202;
    v149 = qcdr(v149);
    stack[0] = qcar(v149);
    v149 = v94;
    v149 = qcdr(v149);
    v149 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-1];
    fn = elt(env, 5); /* apply */
    v149 = (*qfn2(fn))(qenv(fn), stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v190;
    goto v47;

v192:
    v149 = v94;
    v202 = qcar(v149);
    v149 = elt(env, 3); /* !*sq */
    if (v202 == v149) goto v204;
    v149 = v94;
    fn = elt(env, 6); /* operator_fn */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v190;
    goto v47;

v204:
    v149 = v94;
    v149 = qcdr(v149);
    v149 = qcar(v149);
    fn = elt(env, 7); /* prepsq */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-1];
    v149 = CC_expression(env, v149);
    nil = C_nil;
    if (exception_pending()) goto v190;
    goto v47;

v7:
    v149 = v94;
    fn = elt(env, 8); /* printout */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v190;
    goto v47;

v29:
    v149 = v94;
    fn = elt(env, 9); /* f4 */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v190;
    goto v47;
/* error exit handlers */
v190:
    popv(2);
    return nil;
}



/* Code for spmultm2 */

static Lisp_Object MS_CDECL CC_spmultm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v9,
                         Lisp_Object v180, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v250, v251, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spmultm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmultm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v180,v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v9,v180);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v249 = v180;
    stack[-10] = v9;
    stack[-11] = v0;
/* end of prologue */
    v250 = v249;
    v250 = qcdr(v250);
    v250 = qcar(v250);
    fn = elt(env, 2); /* mkempspmat */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[-12] = v249;
    v249 = stack[-11];
    v249 = qcdr(v249);
    v250 = qcar(v249);
    v249 = stack[-11];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    fn = elt(env, 3); /* empty */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    if (v249 == nil) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v249 = stack[-10];
    v249 = qcdr(v249);
    v250 = qcar(v249);
    v249 = stack[-10];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    fn = elt(env, 3); /* empty */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    if (v249 == nil) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v249 = stack[-11];
    v249 = qcdr(v249);
    v249 = qcar(v249);
    stack[-9] = v249;
    v249 = stack[-10];
    v249 = qcdr(v249);
    v249 = qcar(v249);
    stack[-8] = v249;
    v249 = (Lisp_Object)17; /* 1 */
    stack[-3] = v249;
    goto v204;

v204:
    v249 = stack[-11];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    v249 = qcdr(v249);
    v250 = qcar(v249);
    v249 = stack[-3];
    v249 = difference2(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    v249 = Lminusp(nil, v249);
    env = stack[-13];
    if (!(v249 == nil)) { Lisp_Object res = stack[-12]; popv(14); return onevalue(res); }
    v250 = stack[-9];
    v249 = stack[-3];
    fn = elt(env, 4); /* findrow */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[-7] = v249;
    v249 = stack[-7];
    if (v249 == nil) goto v94;
    v249 = (Lisp_Object)17; /* 1 */
    stack[-2] = v249;
    goto v143;

v143:
    v249 = stack[-10];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    v249 = qcdr(v249);
    v250 = qcar(v249);
    v249 = stack[-2];
    v249 = difference2(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    v249 = Lminusp(nil, v249);
    env = stack[-13];
    if (!(v249 == nil)) goto v94;
    v250 = stack[-8];
    v249 = stack[-2];
    fn = elt(env, 4); /* findrow */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[-6] = v249;
    v249 = stack[-6];
    if (v249 == nil) goto v233;
    v249 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 5); /* simp */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[-4] = v249;
    v249 = stack[-7];
    v249 = qcdr(v249);
    stack[-1] = v249;
    goto v253;

v253:
    v249 = stack[-1];
    if (v249 == nil) goto v254;
    v249 = stack[-1];
    v249 = qcar(v249);
    v250 = v249;
    v249 = v250;
    v249 = qcar(v249);
    v250 = qcdr(v250);
    v251 = v250;
    v250 = v249;
    v249 = stack[-6];
    v249 = Latsoc(nil, v250, v249);
    stack[-5] = v249;
    v249 = stack[-5];
    if (v249 == nil) goto v255;
    v249 = stack[-5];
    v249 = qcdr(v249);
    stack[-5] = v249;
    v249 = v251;
    fn = elt(env, 5); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    v249 = stack[-5];
    fn = elt(env, 5); /* simp */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    fn = elt(env, 6); /* multsq */
    v249 = (*qfn2(fn))(qenv(fn), stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[0] = v249;
    v250 = stack[-4];
    v249 = stack[0];
    fn = elt(env, 7); /* addsq */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[-4] = v249;
    goto v256;

v256:
    v249 = stack[-1];
    v249 = qcdr(v249);
    stack[-1] = v249;
    goto v253;

v255:
    v249 = stack[-4];
    stack[-4] = v249;
    goto v256;

v254:
    v249 = stack[-4];
    fn = elt(env, 8); /* mk!*sq */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[0] = v249;
    v250 = stack[0];
    v249 = (Lisp_Object)1; /* 0 */
    if (v250 == v249) goto v233;
    v251 = stack[-12];
    v250 = stack[-3];
    v249 = stack[-2];
    v66 = list3(v251, v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    v251 = stack[0];
    v250 = stack[-12];
    v249 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 9); /* letmtr3 */
    v249 = (*qfnn(fn))(qenv(fn), 4, v66, v251, v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    goto v233;

v233:
    v249 = stack[-2];
    v249 = add1(v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[-2] = v249;
    goto v143;

v94:
    v249 = stack[-3];
    v249 = add1(v249);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-13];
    stack[-3] = v249;
    goto v204;
/* error exit handlers */
v252:
    popv(14);
    return nil;
}



/* Code for mintype */

static Lisp_Object CC_mintype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mintype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v23 = v7;
    if (!consp(v23)) return onevalue(v7);
    v7 = qcar(v7);
    return onevalue(v7);
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v8, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for carx");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v8 = v9;
    v146 = v0;
/* end of prologue */
    v5 = v146;
    v5 = qcdr(v5);
    if (v5 == nil) goto v6;
    stack[-1] = elt(env, 1); /* alg */
    stack[0] = (Lisp_Object)81; /* 5 */
    v5 = elt(env, 2); /* "Wrong number of arguments to" */
    v5 = list2(v5, v8);
    nil = C_nil;
    if (exception_pending()) goto v186;
    env = stack[-2];
    {
        Lisp_Object v185 = stack[-1];
        Lisp_Object v139 = stack[0];
        popv(3);
        fn = elt(env, 3); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v185, v139, v5);
    }

v6:
    v5 = v146;
    v5 = qcar(v5);
    { popv(3); return onevalue(v5); }
/* error exit handlers */
v186:
    popv(3);
    return nil;
}



/* Code for trwrite */

static Lisp_Object CC_trwrite(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for trwrite");
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
    v19 = stack[0];
    v20 = qcar(v19);
    v19 = elt(env, 1); /* tracing */
    v19 = Lflagp(nil, v20, v19);
    env = stack[-1];
    if (v19 == nil) goto v29;
    v19 = elt(env, 3); /* "**in procedure: " */
    v19 = Lprinc(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcar(v19);
    v19 = Lprinc(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v19 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcdr(v19);
    stack[0] = v19;
    goto v3;

v3:
    v19 = stack[0];
    if (v19 == nil) goto v183;
    v19 = stack[0];
    v19 = qcar(v19);
    v19 = Lprinc(nil, v19);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    v19 = stack[0];
    v19 = qcdr(v19);
    stack[0] = v19;
    goto v3;

v183:
    v19 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v19 = nil;
    { popv(2); return onevalue(v19); }

v29:
    v19 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v19); }
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for quotk */

static Lisp_Object CC_quotk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v13, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotk");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */
    v218 = stack[-1];
    v218 = qcar(v218);
    v13 = qcdr(v218);
    v218 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v218 = (*qfn2(fn))(qenv(fn), v13, v218);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[-2] = v218;
    v218 = stack[-2];
    if (v218 == nil) goto v174;
    v218 = stack[-1];
    v218 = qcdr(v218);
    if (v218 == nil) goto v184;
    v218 = stack[-1];
    v13 = qcdr(v218);
    v218 = stack[0];
    fn = elt(env, 2); /* quotf1 */
    v218 = (*qfn2(fn))(qenv(fn), v13, v218);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    v13 = v218;
    v218 = v13;
    if (v218 == nil) goto v193;
    v218 = stack[-1];
    v218 = qcar(v218);
    v24 = qcar(v218);
    v218 = stack[-2];
    popv(4);
    return acons(v24, v218, v13);

v193:
    v218 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v218); }

v184:
    v218 = stack[-1];
    v218 = qcar(v218);
    v13 = qcar(v218);
    v218 = stack[-2];
    v218 = cons(v13, v218);
    nil = C_nil;
    if (exception_pending()) goto v98;
    popv(4);
    return ncons(v218);

v174:
    v218 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v218); }
/* error exit handlers */
v98:
    popv(4);
    return nil;
}



/* Code for simpdiff */

static Lisp_Object CC_simpdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdiff");
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
    v159 = stack[0];
    fn = elt(env, 1); /* ckpreci!# */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    v159 = stack[0];
    fn = elt(env, 2); /* simpcar */
    stack[-1] = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    v159 = stack[0];
    v159 = qcdr(v159);
    fn = elt(env, 3); /* simpminus */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    {
        Lisp_Object v158 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v158, v159);
    }
/* error exit handlers */
v161:
    popv(3);
    return nil;
}



/* Code for red!-ratios2 */

static Lisp_Object MS_CDECL CC_redKratios2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v9,
                         Lisp_Object v180, Lisp_Object v170, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v215, v213, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "red-ratios2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
    if (stack >= stacklimit)
    {
        push4(v170,v180,v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v9,v180,v170);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v170;
    stack[-2] = v180;
    stack[-3] = v9;
    stack[-4] = v0;
/* end of prologue */

v229:
    v208 = stack[-4];
    if (v208 == nil) goto v109;
    v215 = stack[-2];
    v208 = stack[-3];
    v208 = qcar(v208);
    stack[0] = times2(v215, v208);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-6];
    stack[-5] = stack[0];
    v215 = stack[-1];
    v208 = stack[-4];
    v208 = qcar(v208);
    v208 = times2(v215, v208);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-6];
    if (!(equal(stack[0], v208))) goto v204;
    v215 = stack[-5];
    v208 = (Lisp_Object)1; /* 0 */
    if (v215 == v208) goto v204;
    v215 = stack[-1];
    v208 = stack[-2];
    v215 = Lgcd(nil, v215, v208);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-6];
    v208 = stack[-1];
    v215 = Cremainder(v215, v208);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-6];
    v208 = (Lisp_Object)1; /* 0 */
    if (!(v215 == v208)) goto v204;
    v215 = stack[-1];
    v208 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* red!-lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v215, v208);
    }

v204:
    v208 = stack[-4];
    v171 = qcdr(v208);
    v208 = stack[-3];
    v213 = qcdr(v208);
    v215 = stack[-2];
    v208 = stack[-1];
    stack[-4] = v171;
    stack[-3] = v213;
    stack[-2] = v215;
    stack[-1] = v208;
    goto v229;

v109:
    v208 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v208); }
/* error exit handlers */
v148:
    popv(7);
    return nil;
}



/* Code for dv_skelhead */

static Lisp_Object CC_dv_skelhead(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelhead");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    v6 = qcar(v6);
    {
        fn = elt(env, 1); /* dv_cambhead */
        return (*qfn1(fn))(qenv(fn), v6);
    }
}



/* Code for removeg */

static Lisp_Object CC_removeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v9)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v261, v234, v179, v194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg");
#endif
    if (stack >= stacklimit)
    {
        push2(v9,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v9);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v9;
    stack[-1] = v0;
/* end of prologue */
    v261 = stack[-1];
    v234 = qcdr(v261);
    v261 = stack[0];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    fn = elt(env, 7); /* finde */
    v261 = (*qfn2(fn))(qenv(fn), v234, v261);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    stack[-2] = v261;
    v261 = stack[-2];
    v234 = qcar(v261);
    v261 = stack[0];
    if (!(v234 == v261)) goto v2;
    v261 = stack[-2];
    v234 = qcdr(v261);
    v261 = stack[0];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    fn = elt(env, 7); /* finde */
    v261 = (*qfn2(fn))(qenv(fn), v234, v261);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    stack[-2] = v261;
    goto v2;

v2:
    v261 = stack[-2];
    if (!(v261 == nil)) goto v141;
    v194 = elt(env, 1); /* "Free edge" */
    v261 = stack[0];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v179 = qcar(v261);
    v234 = elt(env, 2); /* "in vertex" */
    v261 = stack[0];
    v261 = list4(v194, v179, v234, v261);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    fn = elt(env, 8); /* cerror */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    goto v141;

v141:
    v261 = stack[-2];
    v261 = qcar(v261);
    stack[-2] = v261;
    v261 = stack[-2];
    v261 = qcdr(v261);
    v234 = qcar(v261);
    v261 = stack[-2];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    if (v234 == v261) goto v143;
    v261 = stack[-2];
    v261 = qcdr(v261);
    v234 = qcar(v261);
    v261 = stack[-2];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    if (v234 == v261) goto v143;
    v261 = stack[-2];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v234 = qcar(v261);
    v261 = stack[-2];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    v261 = qcar(v261);
    if (v234 == v261) goto v143;
    v261 = stack[-2];
    v234 = qcar(v261);
    v261 = elt(env, 4); /* qg */
    if (v234 == v261) goto v247;
    v261 = stack[-2];
    v234 = qcar(v261);
    v261 = elt(env, 5); /* g3 */
    if (v234 == v261) goto v231;
    v234 = elt(env, 6); /* "Invalid type of vertex" */
    v261 = stack[0];
    v261 = list2(v234, v261);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    fn = elt(env, 8); /* cerror */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v261 = nil;
    { popv(4); return onevalue(v261); }

v231:
    v179 = stack[-1];
    v234 = stack[0];
    v261 = stack[-2];
    {
        popv(4);
        fn = elt(env, 9); /* removeg2 */
        return (*qfnn(fn))(qenv(fn), 3, v179, v234, v261);
    }

v247:
    v179 = stack[-1];
    v234 = stack[0];
    v261 = stack[-2];
    {
        popv(4);
        fn = elt(env, 10); /* removeg1 */
        return (*qfnn(fn))(qenv(fn), 3, v179, v234, v261);
    }

v143:
    v234 = qvalue(elt(env, 3)); /* nil */
    v261 = (Lisp_Object)17; /* 1 */
    v261 = cons(v234, v261);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v206;
    popv(4);
    return ncons(v261);
/* error exit handlers */
v206:
    popv(4);
    return nil;
}



setup_type const u07_setup[] =
{
    {"isarb_compl",             CC_isarb_compl, too_many_1,    wrong_no_1},
    {"fac-part",                too_few_2,      CC_facKpart,   wrong_no_2},
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {"initbrsea",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_initbrsea},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"optype",                  CC_optype,      too_many_1,    wrong_no_1},
    {"ckpreci#",                CC_ckpreciC,    too_many_1,    wrong_no_1},
    {"mv-pow-mv-term-+",        too_few_2,      CC_mvKpowKmvKtermKL,wrong_no_2},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {"psum",                    too_few_2,      CC_psum,       wrong_no_2},
    {"adddummy1a",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_adddummy1a},
    {"general-modular-quotient",too_few_2,      CC_generalKmodularKquotient,wrong_no_2},
    {"gizerop:",                CC_gizeropT,    too_many_1,    wrong_no_1},
    {"rl_smmkatl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smmkatl},
    {"ev_comp",                 too_few_2,      CC_ev_comp,    wrong_no_2},
    {"symtabget",               too_few_2,      CC_symtabget,  wrong_no_2},
    {"dim<deg",                 CC_dimRdeg,     too_many_1,    wrong_no_1},
    {"lessp:",                  too_few_2,      CC_lesspT,     wrong_no_2},
    {"mv-pow-+",                too_few_2,      CC_mvKpowKL,   wrong_no_2},
    {"rnquotient:",             too_few_2,      CC_rnquotientT,wrong_no_2},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"cgp_evlmon",              CC_cgp_evlmon,  too_many_1,    wrong_no_1},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"addpf",                   too_few_2,      CC_addpf,      wrong_no_2},
    {"argnochk",                CC_argnochk,    too_many_1,    wrong_no_1},
    {"pneg",                    CC_pneg,        too_many_1,    wrong_no_1},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"general-modular-reciprocal",CC_generalKmodularKreciprocal,too_many_1,wrong_no_1},
    {"diff",                    too_few_2,      CC_diff,       wrong_no_2},
    {"wuorderp",                too_few_2,      CC_wuorderp,   wrong_no_2},
    {"msappend",                too_few_2,      CC_msappend,   wrong_no_2},
    {"ckrn1",                   CC_ckrn1,       too_many_1,    wrong_no_1},
    {"multiom",                 CC_multiom,     too_many_1,    wrong_no_1},
    {"c:extmult",               too_few_2,      CC_cTextmult,  wrong_no_2},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"opnum*",                  CC_opnumH,      too_many_1,    wrong_no_1},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"getelv",                  CC_getelv,      too_many_1,    wrong_no_1},
    {"*i2ar",                   CC_Hi2ar,       too_many_1,    wrong_no_1},
    {"wulessp*",                too_few_2,      CC_wulesspH,   wrong_no_2},
    {"comfac",                  CC_comfac,      too_many_1,    wrong_no_1},
    {"rl_sacatlp",              too_few_2,      CC_rl_sacatlp, wrong_no_2},
    {"objectom",                CC_objectom,    too_many_1,    wrong_no_1},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"vecp",                    CC_vecp,        too_many_1,    wrong_no_1},
    {"copy-vector",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_copyKvector},
    {"reduce-mod-p",            CC_reduceKmodKp,too_many_1,    wrong_no_1},
    {"gintequiv:",              CC_gintequivT,  too_many_1,    wrong_no_1},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"totallessp",              too_few_2,      CC_totallessp, wrong_no_2},
    {"exceeds-order",           too_few_2,      CC_exceedsKorder,wrong_no_2},
    {"ibalp_var-unset",         too_few_2,      CC_ibalp_varKunset,wrong_no_2},
    {"expression",              CC_expression,  too_many_1,    wrong_no_1},
    {"spmultm2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_spmultm2},
    {"mintype",                 CC_mintype,     too_many_1,    wrong_no_1},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"trwrite",                 CC_trwrite,     too_many_1,    wrong_no_1},
    {"quotk",                   too_few_2,      CC_quotk,      wrong_no_2},
    {"simpdiff",                CC_simpdiff,    too_many_1,    wrong_no_1},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"dv_skelhead",             CC_dv_skelhead, too_many_1,    wrong_no_1},
    {"removeg",                 too_few_2,      CC_removeg,    wrong_no_2},
    {NULL, (one_args *)"u07", (two_args *)"9410 6324060 5495682", 0}
};

/* end of generated code */
