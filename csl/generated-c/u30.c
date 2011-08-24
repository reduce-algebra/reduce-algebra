
/* $destdir\u30.c        Machine generated C code */

/* Signature: 00000000 24-Aug-2011 */

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
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
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
#ifdef OLD_VERSION
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
#else 
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF ((Lisp_Object)(int32_t)0xff000402)
#endif  
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
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
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
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
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
extern char *C_stack_limit;
extern CSLbool restartp;
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
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
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
extern int csl_argc;
extern char **csl_argv;
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
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count;
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
#define validate_string(a) 
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


/* Code for ofsf_sacrel */

static Lisp_Object MS_CDECL CC_ofsf_sacrel(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10, v11, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_sacrel");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_sacrel");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v9 = v2;
    v11 = v1;
    v12 = v0;
/* end of prologue */
    v10 = v9;
    v9 = elt(env, 1); /* or */
    if (v10 == v9) goto v13;
    v9 = v12;
    v10 = v11;
    {
        fn = elt(env, 2); /* ofsf_sacrel!-and */
        return (*qfn2(fn))(qenv(fn), v9, v10);
    }

v13:
    v9 = v12;
    v10 = v11;
    {
        fn = elt(env, 3); /* ofsf_sacrel!-or */
        return (*qfn2(fn))(qenv(fn), v9, v10);
    }
}



/* Code for setfuncsnaryrd */

static Lisp_Object MS_CDECL CC_setfuncsnaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setfuncsnaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setfuncsnaryrd");
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
    fn = elt(env, 4); /* mathml */
    v17 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    stack[0] = v17;
    v17 = stack[0];
    v17 = Lconsp(nil, v17);
    env = stack[-1];
    if (v17 == nil) goto v20;
    v17 = stack[0];
    v17 = qcdr(v17);
    v17 = qcar(v17);
    if (v17 == nil) goto v20;
    v17 = stack[0];
    v17 = qcdr(v17);
    v17 = qcar(v17);
    v17 = qcar(v17);
    v17 = qcdr(v17);
    v17 = qcar(v17);
    v18 = Lintern(nil, v17);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v17 = elt(env, 1); /* multiset */
    if (!(v18 == v17)) goto v20;
    v17 = elt(env, 1); /* multiset */
    qvalue(elt(env, 2)) = v17; /* mmlatts */
    goto v20;

v20:
    v17 = stack[0];
    if (v17 == nil) goto v21;
    v17 = CC_setfuncsnaryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    {
        Lisp_Object v22 = stack[0];
        popv(2);
        return cons(v22, v17);
    }

v21:
    v17 = nil;
    { popv(2); return onevalue(v17); }
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for indexsymmetrize */

static Lisp_Object CC_indexsymmetrize(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v34, v35;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexsymmetrize");
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
    v33 = stack[-2];
    v34 = qcar(v33);
    v33 = elt(env, 1); /* indxsymmetrize */
    v33 = get(v34, v33);
    env = stack[-4];
    stack[-3] = v33;
    v33 = (Lisp_Object)17; /* 1 */
    stack[0] = v33;
    v34 = (Lisp_Object)17; /* 1 */
    v33 = stack[-2];
    v33 = qcdr(v33);
    v33 = cons(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    stack[-1] = v33;
    goto v37;

v37:
    v33 = stack[-3];
    if (v33 == nil) goto v10;
    v33 = stack[-3];
    v34 = qcar(v33);
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = Lapply1(nil, v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    stack[-1] = v33;
    v33 = stack[-1];
    if (v33 == nil) goto v38;
    v33 = stack[-1];
    v34 = qcar(v33);
    v33 = stack[0];
    v33 = times2(v34, v33);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-4];
    stack[0] = v33;
    v33 = stack[-3];
    v33 = qcdr(v33);
    stack[-3] = v33;
    goto v37;

v38:
    v33 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v33); }

v10:
    v35 = stack[0];
    v33 = stack[-2];
    v34 = qcar(v33);
    v33 = stack[-1];
    v33 = qcdr(v33);
    popv(5);
    return list2star(v35, v34, v33);
/* error exit handlers */
v36:
    popv(5);
    return nil;
}



/* Code for applsmacro */

static Lisp_Object MS_CDECL CC_applsmacro(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "applsmacro");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applsmacro");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-6] = v1;
    v99 = v0;
/* end of prologue */
    stack[-5] = nil;
    v98 = v99;
    v98 = qcdr(v98);
    v98 = qcar(v98);
    stack[-2] = v98;
    v98 = v99;
    v98 = qcdr(v98);
    v98 = qcdr(v98);
    v98 = qcar(v98);
    stack[-7] = v98;
    v98 = stack[-2];
    stack[0] = Llength(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = stack[-6];
    v98 = Llength(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    if (equal(stack[0], v98)) goto v101;
    v99 = elt(env, 1); /* "Argument mismatch for SMACRO" */
    v98 = stack[-1];
    v98 = list2(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v99 = v98;
    v98 = v99;
    qvalue(elt(env, 2)) = v98; /* errmsg!* */
    v98 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v98 == nil)) goto v28;
    v98 = v99;
    fn = elt(env, 7); /* lprie */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    goto v28;

v28:
    v98 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    goto v101;

v101:
    v98 = stack[-6];
    fn = elt(env, 8); /* no!-side!-effect!-listp */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    if (!(v98 == nil)) goto v33;
    v99 = stack[-2];
    v98 = stack[-7];
    fn = elt(env, 9); /* one!-entry!-listp */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    if (!(v98 == nil)) goto v33;
    v98 = stack[-2];
    v99 = Llength(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = (Lisp_Object)17; /* 1 */
    v98 = (Lisp_Object)greaterp2(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    v98 = v98 ? lisp_true : nil;
    env = stack[-8];
    if (v98 == nil) goto v15;
    v98 = stack[-2];
    stack[-4] = v98;
    v98 = stack[-4];
    if (v98 == nil) goto v102;
    v98 = stack[-4];
    v98 = qcar(v98);
    stack[0] = v98;
    v98 = elt(env, 5); /* g */
    v98 = Lgensym1(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = cons(stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    stack[-2] = v98;
    stack[-3] = v98;
    goto v103;

v103:
    v98 = stack[-4];
    v98 = qcdr(v98);
    stack[-4] = v98;
    v98 = stack[-4];
    if (v98 == nil) goto v104;
    stack[-1] = stack[-2];
    v98 = stack[-4];
    v98 = qcar(v98);
    stack[0] = v98;
    v98 = elt(env, 5); /* g */
    v98 = Lgensym1(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = cons(stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = Lrplacd(nil, stack[-1], v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = stack[-2];
    v98 = qcdr(v98);
    stack[-2] = v98;
    goto v103;

v104:
    v98 = stack[-3];
    goto v105;

v105:
    stack[0] = v98;
    v99 = stack[0];
    v98 = stack[-7];
    fn = elt(env, 10); /* subla!-q */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    stack[-7] = v98;
    v98 = stack[0];
    stack[-3] = v98;
    v98 = stack[-3];
    if (v98 == nil) goto v106;
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcdr(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    stack[-1] = v98;
    stack[-2] = v98;
    goto v107;

v107:
    v98 = stack[-3];
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[-3];
    if (v98 == nil) goto v108;
    stack[0] = stack[-1];
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcdr(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = Lrplacd(nil, stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v107;

v108:
    v98 = stack[-2];
    goto v109;

v109:
    stack[-2] = v98;
    goto v15;

v15:
    v98 = stack[-6];
    stack[-1] = v98;
    goto v110;

v110:
    v98 = stack[-1];
    if (v98 == nil) goto v111;
    v98 = stack[-1];
    v98 = qcar(v98);
    stack[0] = v98;
    v98 = stack[0];
    fn = elt(env, 11); /* no!-side!-effectp */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    if (!(v98 == nil)) goto v112;
    v98 = stack[-2];
    v99 = qcar(v98);
    v98 = stack[-7];
    fn = elt(env, 12); /* one!-entryp */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    if (!(v98 == nil)) goto v112;
    stack[-3] = stack[-5];
    v98 = stack[-2];
    v99 = qcar(v98);
    v98 = stack[0];
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = Lnconc(nil, stack[-3], v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    stack[-5] = v98;
    goto v113;

v113:
    v98 = stack[-2];
    v98 = qcdr(v98);
    stack[-2] = v98;
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v110;

v112:
    v98 = stack[-2];
    v99 = qcar(v98);
    v98 = stack[0];
    v98 = cons(v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v99 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = stack[-7];
    fn = elt(env, 10); /* subla!-q */
    v98 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    stack[-7] = v98;
    goto v113;

v111:
    v98 = stack[-5];
    if (v98 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    stack[-4] = elt(env, 6); /* lambda */
    v98 = stack[-5];
    stack[-3] = v98;
    v98 = stack[-3];
    if (v98 == nil) goto v114;
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    stack[-1] = v98;
    stack[-2] = v98;
    goto v115;

v115:
    v98 = stack[-3];
    v98 = qcdr(v98);
    stack[-3] = v98;
    v98 = stack[-3];
    if (v98 == nil) goto v116;
    stack[0] = stack[-1];
    v98 = stack[-3];
    v98 = qcar(v98);
    v98 = qcar(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = Lrplacd(nil, stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v115;

v116:
    v98 = stack[-2];
    v99 = v98;
    goto v117;

v117:
    v98 = stack[-7];
    stack[-3] = list3(stack[-4], v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = stack[-5];
    stack[-4] = v98;
    v98 = stack[-4];
    if (v98 == nil) goto v118;
    v98 = stack[-4];
    v98 = qcar(v98);
    v98 = qcdr(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    stack[-1] = v98;
    stack[-2] = v98;
    goto v119;

v119:
    v98 = stack[-4];
    v98 = qcdr(v98);
    stack[-4] = v98;
    v98 = stack[-4];
    if (v98 == nil) goto v120;
    stack[0] = stack[-1];
    v98 = stack[-4];
    v98 = qcar(v98);
    v98 = qcdr(v98);
    v98 = ncons(v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = Lrplacd(nil, stack[0], v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v119;

v120:
    v98 = stack[-2];
    goto v121;

v121:
    {
        Lisp_Object v122 = stack[-3];
        popv(9);
        return cons(v122, v98);
    }

v118:
    v98 = qvalue(elt(env, 4)); /* nil */
    goto v121;

v114:
    v98 = qvalue(elt(env, 4)); /* nil */
    v99 = v98;
    goto v117;

v106:
    v98 = qvalue(elt(env, 4)); /* nil */
    goto v109;

v102:
    v98 = qvalue(elt(env, 4)); /* nil */
    goto v105;

v33:
    v99 = stack[-2];
    v98 = stack[-6];
    fn = elt(env, 13); /* pair */
    v99 = (*qfn2(fn))(qenv(fn), v99, v98);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-8];
    v98 = stack[-7];
    {
        popv(9);
        fn = elt(env, 10); /* subla!-q */
        return (*qfn2(fn))(qenv(fn), v99, v98);
    }
/* error exit handlers */
v100:
    popv(9);
    return nil;
}



/* Code for reduce */

static Lisp_Object CC_reduce(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v22, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce");
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
    stack[-1] = v1;
    v19 = v0;
/* end of prologue */
    stack[0] = v19;
    v19 = qvalue(elt(env, 1)); /* !*yyy */
    if (v19 == nil) goto v125;
    v22 = stack[0];
    v19 = stack[-1];
    fn = elt(env, 3); /* reduce!-ratios */
    v19 = (*qfn2(fn))(qenv(fn), v22, v19);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    stack[0] = v19;
    goto v125;

v125:
    v19 = stack[-1];
    fn = elt(env, 4); /* set!-weights */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    stack[-2] = v19;
    v19 = qvalue(elt(env, 2)); /* !*xxx */
    if (v19 == nil) goto v127;
    v38 = stack[0];
    v22 = stack[-1];
    v19 = stack[-2];
    fn = elt(env, 5); /* reduce!-columns */
    v19 = (*qfnn(fn))(qenv(fn), 3, v38, v22, v19);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    stack[0] = v19;
    goto v127;

v127:
    v19 = qvalue(elt(env, 2)); /* !*xxx */
    if (v19 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v38 = stack[0];
    v22 = stack[-1];
    v19 = stack[-2];
    fn = elt(env, 6); /* reduce!-weights */
    v19 = (*qfnn(fn))(qenv(fn), 3, v38, v22, v19);
    nil = C_nil;
    if (exception_pending()) goto v126;
    stack[0] = v19;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v126:
    popv(4);
    return nil;
}



/* Code for fs!:make!-nullangle */

static Lisp_Object MS_CDECL CC_fsTmakeKnullangle(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v21, v129;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fs:make-nullangle");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:make-nullangle");
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
    v94 = (Lisp_Object)113; /* 7 */
    v94 = Lmkvect(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    stack[-1] = v94;
    v94 = (Lisp_Object)1; /* 0 */
    stack[0] = v94;
    goto v32;

v32:
    v21 = (Lisp_Object)113; /* 7 */
    v94 = stack[0];
    v94 = difference2(v21, v94);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    v94 = Lminusp(nil, v94);
    env = stack[-2];
    if (!(v94 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v129 = stack[-1];
    v21 = stack[0];
    v94 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v129 + (CELL-TAG_VECTOR) + ((int32_t)v21/(16/CELL))) = v94;
    v94 = stack[0];
    v94 = add1(v94);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-2];
    stack[0] = v94;
    goto v32;
/* error exit handlers */
v28:
    popv(3);
    return nil;
}



/* Code for red!=hide */

static Lisp_Object CC_redMhide(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hide");
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
    v131 = v0;
/* end of prologue */
    stack[-5] = v131;
    v131 = stack[-5];
    if (v131 == nil) goto v133;
    v131 = stack[-5];
    v131 = qcar(v131);
    stack[-1] = v131;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v131 = stack[-1];
    v131 = qcar(v131);
    fn = elt(env, 2); /* mo_neg */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v132 = (*qfn2(fn))(qenv(fn), stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v131 = stack[-1];
    v131 = qcdr(v131);
    v131 = cons(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    stack[-3] = v131;
    stack[-4] = v131;
    goto v37;

v37:
    v131 = stack[-5];
    v131 = qcdr(v131);
    stack[-5] = v131;
    v131 = stack[-5];
    if (v131 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-2] = stack[-3];
    v131 = stack[-5];
    v131 = qcar(v131);
    stack[-1] = v131;
    stack[0] = (Lisp_Object)-15; /* -1 */
    v131 = stack[-1];
    v131 = qcar(v131);
    fn = elt(env, 2); /* mo_neg */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    fn = elt(env, 3); /* mo_times_ei */
    v132 = (*qfn2(fn))(qenv(fn), stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v131 = stack[-1];
    v131 = qcdr(v131);
    v131 = cons(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v131 = ncons(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v131 = Lrplacd(nil, stack[-2], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-6];
    v131 = stack[-3];
    v131 = qcdr(v131);
    stack[-3] = v131;
    goto v37;

v133:
    v131 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v131); }
/* error exit handlers */
v134:
    popv(7);
    return nil;
}



/* Code for taylorp */

static Lisp_Object CC_taylorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v135, v136;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taylorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v136 = v0;
/* end of prologue */
    v135 = v136;
    if (!consp(v135)) goto v97;
    v135 = v136;
    v135 = qcar(v135);
    if (!consp(v135)) goto v128;
    v135 = v136;
    v135 = qcar(v135);
    v135 = qcar(v135);
    v136 = elt(env, 1); /* taylor */
        return Lflagp(nil, v135, v136);

v128:
    v135 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v135);

v97:
    v135 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v135);
}



/* Code for ofsf_at2ir */

static Lisp_Object CC_ofsf_at2ir(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v144, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_at2ir");
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
    stack[-3] = v1;
    v144 = v0;
/* end of prologue */
    v143 = v144;
    v143 = qcar(v143);
    stack[-4] = v143;
    v143 = v144;
    v143 = qcdr(v143);
    v143 = qcar(v143);
    stack[-2] = v143;
    stack[0] = v143;
    goto v13;

v13:
    v143 = stack[0];
    if (!consp(v143)) goto v128;
    v143 = stack[0];
    v143 = qcar(v143);
    v143 = (consp(v143) ? nil : lisp_true);
    goto v6;

v6:
    if (v143 == nil) goto v101;
    stack[-1] = stack[-2];
    v143 = stack[0];
    fn = elt(env, 3); /* negf */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    fn = elt(env, 4); /* addf */
    v143 = (*qfn2(fn))(qenv(fn), stack[-1], v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    stack[-2] = v143;
    v143 = stack[-2];
    fn = elt(env, 5); /* sfto_dcontentf */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    stack[-1] = v143;
    v144 = stack[-2];
    v143 = stack[-1];
    fn = elt(env, 6); /* quotf */
    v143 = (*qfn2(fn))(qenv(fn), v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    stack[-2] = v143;
    v144 = stack[0];
    v143 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    v144 = stack[-1];
    v143 = (Lisp_Object)17; /* 1 */
    v143 = cons(v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    fn = elt(env, 7); /* invsq */
    v143 = (*qfn1(fn))(qenv(fn), v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    fn = elt(env, 8); /* multsq */
    v143 = (*qfn2(fn))(qenv(fn), stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    stack[0] = v143;
    stack[-1] = stack[-2];
    v145 = stack[-3];
    v144 = stack[-4];
    v143 = stack[0];
    v143 = list2star(v145, v144, v143);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-5];
    v144 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v147 = stack[-1];
        popv(6);
        return list2star(v147, v143, v144);
    }

v101:
    v143 = stack[0];
    v143 = qcdr(v143);
    stack[0] = v143;
    goto v13;

v128:
    v143 = qvalue(elt(env, 1)); /* t */
    goto v6;
/* error exit handlers */
v146:
    popv(6);
    return nil;
}



/* Code for createsinglevariablemonom */

static Lisp_Object CC_createsinglevariablemonom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v21, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for createsinglevariablemonom");
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
    v94 = (Lisp_Object)17; /* 1 */
    v94 = Lmkvect(nil, v94);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-4];
    stack[-3] = v94;
    v129 = stack[-3];
    v21 = (Lisp_Object)1; /* 0 */
    v94 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v129 + (CELL-TAG_VECTOR) + ((int32_t)v21/(16/CELL))) = v94;
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)17; /* 1 */
    v129 = stack[-2];
    v21 = qvalue(elt(env, 1)); /* nil */
    v94 = qvalue(elt(env, 1)); /* nil */
    v94 = list2star(v129, v21, v94);
    nil = C_nil;
    if (exception_pending()) goto v30;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v94;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v30:
    popv(5);
    return nil;
}



/* Code for gigcdsq */

static Lisp_Object CC_gigcdsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gigcdsq");
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
    v34 = stack[-1];
    if (v34 == nil) goto v141;
    v35 = stack[0];
    v34 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* giintgcd */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    stack[-2] = v34;
    v35 = stack[-2];
    v34 = (Lisp_Object)17; /* 1 */
    if (v35 == v34) goto v151;
    v35 = stack[-1];
    v34 = stack[-2];
    fn = elt(env, 2); /* giintgcd */
    v35 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    stack[-2] = v35;
    v34 = (Lisp_Object)17; /* 1 */
    v34 = Lneq(nil, v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    goto v6;

v6:
    if (v34 == nil) goto v141;
    v35 = stack[-1];
    v34 = stack[-2];
    fn = elt(env, 3); /* quotf */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-3];
    stack[-1] = v34;
    v35 = stack[0];
    v34 = stack[-2];
    fn = elt(env, 3); /* quotf */
    v34 = (*qfn2(fn))(qenv(fn), v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v91;
    stack[0] = v34;
    goto v141;

v141:
    v35 = stack[-1];
    v34 = stack[0];
    popv(4);
    return cons(v35, v34);

v151:
    v34 = qvalue(elt(env, 1)); /* nil */
    goto v6;
/* error exit handlers */
v91:
    popv(4);
    return nil;
}



/* Code for pasf_dt */

static Lisp_Object CC_pasf_dt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v197, v198, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dt");
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
    v197 = stack[0];
    v196 = elt(env, 1); /* true */
    if (v197 == v196) goto v200;
    v197 = stack[0];
    v196 = elt(env, 3); /* false */
    v196 = (v197 == v196 ? lisp_true : nil);
    goto v133;

v133:
    if (!(v196 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v196 = stack[0];
    v196 = qcdr(v196);
    v196 = qcar(v196);
    fn = elt(env, 18); /* pasf_pdp */
    v196 = (*qfn1(fn))(qenv(fn), v196);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-1];
    v199 = v196;
    v197 = stack[0];
    v196 = elt(env, 1); /* true */
    if (v197 == v196) goto v28;
    v197 = stack[0];
    v196 = elt(env, 3); /* false */
    v196 = (v197 == v196 ? lisp_true : nil);
    goto v142;

v142:
    if (v196 == nil) goto v129;
    v196 = stack[0];
    goto v94;

v94:
    v198 = v196;
    v197 = v199;
    v196 = elt(env, 4); /* pdef */
    if (v197 == v196) goto v88;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v202;

v202:
    if (v196 == nil) goto v203;
    v196 = elt(env, 3); /* false */
    { popv(2); return onevalue(v196); }

v203:
    v197 = v199;
    v196 = elt(env, 7); /* ndef */
    if (v197 == v196) goto v204;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v86;

v86:
    if (v196 == nil) goto v205;
    v196 = elt(env, 3); /* false */
    { popv(2); return onevalue(v196); }

v205:
    v197 = v199;
    v196 = elt(env, 4); /* pdef */
    if (v197 == v196) goto v206;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v207;

v207:
    if (v196 == nil) goto v106;
    v196 = elt(env, 1); /* true */
    { popv(2); return onevalue(v196); }

v106:
    v197 = v199;
    v196 = elt(env, 7); /* ndef */
    if (v197 == v196) goto v208;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v209;

v209:
    if (v196 == nil) goto v210;
    v196 = elt(env, 1); /* true */
    { popv(2); return onevalue(v196); }

v210:
    v197 = v199;
    v196 = elt(env, 11); /* psdef */
    if (v197 == v196) goto v211;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v68;

v68:
    if (v196 == nil) goto v212;
    v196 = elt(env, 3); /* false */
    { popv(2); return onevalue(v196); }

v212:
    v197 = v199;
    v196 = elt(env, 13); /* nsdef */
    if (v197 == v196) goto v213;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v214;

v214:
    if (v196 == nil) goto v215;
    v196 = elt(env, 3); /* false */
    { popv(2); return onevalue(v196); }

v215:
    v197 = v199;
    v196 = elt(env, 11); /* psdef */
    if (v197 == v196) goto v216;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v62;

v62:
    if (v196 == nil) goto v217;
    v196 = elt(env, 1); /* true */
    { popv(2); return onevalue(v196); }

v217:
    v197 = v199;
    v196 = elt(env, 13); /* nsdef */
    if (v197 == v196) goto v218;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v219;

v219:
    if (v196 == nil) goto v220;
    v196 = elt(env, 1); /* true */
    { popv(2); return onevalue(v196); }

v220:
    v197 = v199;
    v196 = elt(env, 11); /* psdef */
    if (v197 == v196) goto v221;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v115;

v115:
    if (v196 == nil) goto v222;
    v197 = elt(env, 14); /* greaterp */
    v196 = stack[0];
    v196 = qcdr(v196);
    v196 = qcar(v196);
    v198 = qvalue(elt(env, 6)); /* nil */
    popv(2);
    return list3(v197, v196, v198);

v222:
    v197 = v199;
    v196 = elt(env, 13); /* nsdef */
    if (v197 == v196) goto v223;
    v196 = qvalue(elt(env, 6)); /* nil */
    goto v45;

v45:
    if (v196 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v197 = elt(env, 12); /* lessp */
    v196 = stack[0];
    v196 = qcdr(v196);
    v196 = qcar(v196);
    v198 = qvalue(elt(env, 6)); /* nil */
    popv(2);
    return list3(v197, v196, v198);

v223:
    v197 = v198;
    v196 = elt(env, 17); /* neq */
    v196 = (v197 == v196 ? lisp_true : nil);
    goto v45;

v221:
    v197 = v198;
    v196 = elt(env, 17); /* neq */
    v196 = (v197 == v196 ? lisp_true : nil);
    goto v115;

v218:
    v197 = v198;
    v196 = elt(env, 16); /* leq */
    v196 = (v197 == v196 ? lisp_true : nil);
    goto v219;

v216:
    v197 = v198;
    v196 = elt(env, 15); /* geq */
    v196 = (v197 == v196 ? lisp_true : nil);
    goto v62;

v213:
    v197 = v198;
    v196 = elt(env, 14); /* greaterp */
    v196 = (v197 == v196 ? lisp_true : nil);
    goto v214;

v211:
    v197 = v198;
    v196 = elt(env, 12); /* lessp */
    v196 = (v197 == v196 ? lisp_true : nil);
    goto v68;

v208:
    v197 = v198;
    v196 = elt(env, 10); /* (neq lessp leq) */
    v196 = Lmemq(nil, v197, v196);
    goto v209;

v206:
    v197 = v198;
    v196 = elt(env, 9); /* (neq greaterp geq) */
    v196 = Lmemq(nil, v197, v196);
    goto v207;

v204:
    v197 = v198;
    v196 = elt(env, 8); /* (equal greaterp geq) */
    v196 = Lmemq(nil, v197, v196);
    goto v86;

v88:
    v197 = v198;
    v196 = elt(env, 5); /* (equal lessp leq) */
    v196 = Lmemq(nil, v197, v196);
    goto v202;

v129:
    v196 = stack[0];
    v196 = qcar(v196);
    v196 = Lconsp(nil, v196);
    env = stack[-1];
    if (v196 == nil) goto v89;
    v196 = stack[0];
    v196 = qcar(v196);
    v196 = qcar(v196);
    goto v94;

v89:
    v196 = stack[0];
    v196 = qcar(v196);
    goto v94;

v28:
    v196 = qvalue(elt(env, 2)); /* t */
    goto v142;

v200:
    v196 = qvalue(elt(env, 2)); /* t */
    goto v133;
/* error exit handlers */
v201:
    popv(2);
    return nil;
}



/* Code for rl_surep */

static Lisp_Object CC_rl_surep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_surep");
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
    v101 = v1;
    v123 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_surep!* */
    v101 = list2(v123, v101);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    {
        Lisp_Object v6 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v6, v101);
    }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for setrd */

static Lisp_Object MS_CDECL CC_setrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setrd");
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
    v31 = elt(env, 1); /* (t y p e != s e t !$) */
    qvalue(elt(env, 2)) = v31; /* atts */
    stack[0] = elt(env, 3); /* list */
    fn = elt(env, 4); /* stats_getargs */
    v31 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v31 = cons(stack[0], v31);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v97 = v31;
    v31 = v97;
    stack[0] = qcar(v31);
    v31 = v97;
    v31 = qcdr(v31);
    fn = elt(env, 5); /* norepeat */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v96;
    {
        Lisp_Object v135 = stack[0];
        popv(2);
        return cons(v135, v31);
    }
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for ps!:zerop!: */

static Lisp_Object CC_psTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:zerop:");
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
    v148 = v0;
/* end of prologue */
    fn = elt(env, 2); /* ps!:value */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[0];
    v13 = v148;
    v148 = v13;
    if (is_number(v148)) goto v133;
    v148 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v148); }

v133:
    v148 = v13;
        popv(1);
        return Lzerop(nil, v148);
/* error exit handlers */
v32:
    popv(1);
    return nil;
}



/* Code for maxl */

static Lisp_Object CC_maxl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxl");
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
    goto v20;

v20:
    v28 = stack[0];
    if (v28 == nil) goto v37;
    v28 = stack[0];
    v150 = qcar(v28);
    v28 = stack[-1];
    v28 = cons(v150, v28);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    stack[-1] = v28;
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v20;

v37:
    v28 = (Lisp_Object)-159999; /* -10000 */
    v150 = v28;
    goto v224;

v224:
    v28 = stack[-1];
    if (v28 == nil) { popv(3); return onevalue(v150); }
    v28 = stack[-1];
    v28 = qcar(v28);
    fn = elt(env, 1); /* max */
    v28 = (*qfn2(fn))(qenv(fn), v28, v150);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-2];
    v150 = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v224;
/* error exit handlers */
v151:
    popv(3);
    return nil;
}



/* Code for assgnpri */

static Lisp_Object MS_CDECL CC_assgnpri(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v246, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assgnpri");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assgnpri");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v245 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v245; /* overflowed!* */
    qvalue(elt(env, 3)) = v245; /* testing!-width!* */
    v245 = stack[-2];
    if (!(v245 == nil)) goto v125;
    v245 = (Lisp_Object)1; /* 0 */
    stack[-2] = v245;
    goto v125;

v125:
    v245 = qvalue(elt(env, 4)); /* !*nero */
    if (v245 == nil) goto v148;
    v246 = stack[-2];
    v245 = (Lisp_Object)1; /* 0 */
    if (!(v246 == v245)) goto v148;
    v245 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v245); }

v148:
    v245 = qvalue(elt(env, 5)); /* !*tex */
    if (v245 == nil) goto v4;
    v217 = stack[-2];
    v246 = stack[-1];
    v245 = stack[0];
    {
        popv(5);
        fn = elt(env, 20); /* texpri */
        return (*qfnn(fn))(qenv(fn), 3, v217, v246, v245);
    }

v4:
    v245 = elt(env, 6); /* vecp */
    fn = elt(env, 21); /* getd */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    if (v245 == nil) goto v136;
    v245 = stack[-2];
    fn = elt(env, 6); /* vecp */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    if (v245 == nil) goto v136;
    v246 = stack[-2];
    v245 = elt(env, 7); /* mat */
    {
        popv(5);
        fn = elt(env, 22); /* vecpri */
        return (*qfn2(fn))(qenv(fn), v246, v245);
    }

v136:
    v245 = stack[-2];
    fn = elt(env, 23); /* getrtype */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    v217 = v245;
    if (v245 == nil) goto v109;
    v246 = v217;
    v245 = elt(env, 8); /* sprifn */
    v245 = Lflagp(nil, v246, v245);
    env = stack[-4];
    if (v245 == nil) goto v247;
    v245 = qvalue(elt(env, 9)); /* outputhandler!* */
    v245 = (v245 == nil ? lisp_true : nil);
    goto v24;

v24:
    if (v245 == nil) goto v109;
    v245 = stack[-1];
    if (v245 == nil) goto v248;
    v217 = elt(env, 12); /* setq */
    v245 = stack[-1];
    v246 = qcar(v245);
    v245 = stack[-2];
    v245 = list3(v217, v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    v246 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (v246 == nil) goto v249;
    v217 = qvalue(elt(env, 9)); /* outputhandler!* */
    v246 = elt(env, 13); /* maprin */
    v245 = Lapply2(nil, 3, v217, v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v250;

v250:
    v245 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v245); }

v249:
    v246 = qvalue(elt(env, 2)); /* overflowed!* */
    if (!(v246 == nil)) goto v250;
    v246 = v245;
    v245 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 24); /* maprint */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v250;

v248:
    v246 = v217;
    v245 = elt(env, 10); /* tag */
    v246 = get(v246, v245);
    env = stack[-4];
    v245 = elt(env, 11); /* prifn */
    v246 = get(v246, v245);
    env = stack[-4];
    v245 = stack[-2];
    v245 = Lapply1(nil, v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v250;

v109:
    v246 = stack[0];
    v245 = elt(env, 14); /* (first only) */
    v245 = Lmemq(nil, v246, v245);
    if (v245 == nil) goto v72;
    v245 = qvalue(elt(env, 15)); /* t */
    fn = elt(env, 25); /* terpri!* */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v72;

v72:
    v245 = stack[-1];
    fn = elt(env, 26); /* evalvars */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    stack[-1] = v245;
    v245 = qvalue(elt(env, 16)); /* !*fort */
    if (v245 == nil) goto v251;
    v217 = stack[-2];
    v246 = stack[-1];
    v245 = stack[0];
    fn = elt(env, 27); /* fvarpri */
    v245 = (*qfnn(fn))(qenv(fn), 3, v217, v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    v245 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v245); }

v251:
    v245 = stack[-1];
    if (v245 == nil) goto v252;
    stack[-3] = elt(env, 12); /* setq */
    v245 = stack[-2];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    v245 = Lnconc(nil, stack[-1], v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    v245 = cons(stack[-3], v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v69;

v69:
    v246 = qvalue(elt(env, 9)); /* outputhandler!* */
    if (v246 == nil) goto v253;
    v217 = qvalue(elt(env, 9)); /* outputhandler!* */
    v246 = elt(env, 13); /* maprin */
    v245 = Lapply2(nil, 3, v217, v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v173;

v173:
    v245 = stack[0];
    if (v245 == nil) goto v254;
    v246 = stack[0];
    v245 = elt(env, 17); /* first */
    v245 = (v246 == v245 ? lisp_true : nil);
    goto v215;

v215:
    if (v245 == nil) goto v63;
    v245 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v245); }

v63:
    v245 = qvalue(elt(env, 18)); /* !*nat */
    if (!(v245 == nil)) goto v168;
    v245 = elt(env, 19); /* "$" */
    fn = elt(env, 28); /* prin2!* */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v168;

v168:
    v245 = qvalue(elt(env, 18)); /* !*nat */
    v245 = (v245 == nil ? lisp_true : nil);
    fn = elt(env, 25); /* terpri!* */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    v245 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v245); }

v254:
    v245 = qvalue(elt(env, 15)); /* t */
    goto v215;

v253:
    v246 = qvalue(elt(env, 2)); /* overflowed!* */
    if (!(v246 == nil)) goto v173;
    v246 = v245;
    v245 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 24); /* maprint */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    goto v173;

v252:
    v245 = stack[-2];
    goto v69;

v247:
    v245 = qvalue(elt(env, 1)); /* nil */
    goto v24;
/* error exit handlers */
v166:
    popv(5);
    return nil;
}



/* Code for decimal2internal */

static Lisp_Object CC_decimal2internal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v126, v256;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for decimal2internal");
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
    v126 = stack[0];
    v193 = (Lisp_Object)1; /* 0 */
    v193 = (Lisp_Object)geq2(v126, v193);
    nil = C_nil;
    if (exception_pending()) goto v141;
    v193 = v193 ? lisp_true : nil;
    env = stack[-3];
    if (v193 == nil) goto v257;
    stack[-2] = elt(env, 1); /* !:rd!: */
    v126 = (Lisp_Object)161; /* 10 */
    v193 = stack[0];
    v193 = Lexpt(nil, v126, v193);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v126 = times2(stack[-1], v193);
    nil = C_nil;
    if (exception_pending()) goto v141;
    v193 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v130 = stack[-2];
        popv(4);
        return list2star(v130, v126, v193);
    }

v257:
    v256 = elt(env, 1); /* !:rd!: */
    v126 = stack[-1];
    v193 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v256, v126, v193);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v193 = stack[0];
    v193 = negate(v193);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    {
        Lisp_Object v23 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* divide!-by!-power!-of!-ten */
        return (*qfn2(fn))(qenv(fn), v23, v193);
    }
/* error exit handlers */
v141:
    popv(4);
    return nil;
}



/* Code for indexvp */

static Lisp_Object CC_indexvp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v0;
/* end of prologue */
    v123 = v124;
    if (!consp(v123)) goto v13;
    v123 = v124;
    v123 = qcar(v123);
    v124 = elt(env, 1); /* indexvar */
        return Lflagp(nil, v123, v124);

v13:
    v123 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v123);
}



/* Code for !*f2di */

static Lisp_Object CC_Hf2di(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v270, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *f2di");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v270 = v2;
    stack[-5] = v1;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v270; /* varlist */
    v270 = stack[-5];
    if (v270 == nil) goto v195;
    v270 = stack[-5];
    if (!consp(v270)) goto v101;
    v270 = stack[-5];
    v270 = qcar(v270);
    v270 = (consp(v270) ? nil : lisp_true);
    goto v32;

v32:
    if (v270 == nil) goto v271;
    v270 = qvalue(elt(env, 1)); /* varlist */
    stack[-3] = v270;
    v270 = stack[-3];
    if (v270 == nil) goto v150;
    v270 = (Lisp_Object)1; /* 0 */
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-1] = v270;
    stack[-2] = v270;
    goto v129;

v129:
    v270 = stack[-3];
    v270 = qcdr(v270);
    stack[-3] = v270;
    v270 = stack[-3];
    if (v270 == nil) goto v22;
    stack[0] = stack[-1];
    v270 = (Lisp_Object)1; /* 0 */
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = Lrplacd(nil, stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = stack[-1];
    v270 = qcdr(v270);
    stack[-1] = v270;
    goto v129;

v22:
    v270 = stack[-2];
    goto v21;

v21:
    fn = elt(env, 4); /* addgt */
    v60 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = stack[-5];
    v270 = cons(v60, v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    goto v20;

v20:
    qvalue(elt(env, 1)) = stack[-6]; /* varlist */
    { popv(8); return onevalue(v270); }

v150:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v21;

v271:
    v270 = stack[-5];
    v270 = qcar(v270);
    v270 = qcar(v270);
    v60 = qcar(v270);
    v270 = qvalue(elt(env, 1)); /* varlist */
    v270 = Lmember(nil, v60, v270);
    if (v270 == nil) goto v180;
    v270 = stack[-5];
    v270 = qcar(v270);
    v60 = qcdr(v270);
    v270 = qvalue(elt(env, 1)); /* varlist */
    stack[-4] = CC_Hf2di(env, v60, v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = qvalue(elt(env, 1)); /* varlist */
    stack[-3] = v270;
    v270 = stack[-3];
    if (v270 == nil) goto v238;
    v270 = stack[-3];
    v270 = qcar(v270);
    v60 = v270;
    v270 = stack[-5];
    v270 = qcar(v270);
    v270 = qcar(v270);
    v270 = qcar(v270);
    if (equal(v60, v270)) goto v207;
    v270 = (Lisp_Object)1; /* 0 */
    goto v186;

v186:
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-1] = v270;
    stack[-2] = v270;
    goto v272;

v272:
    v270 = stack[-3];
    v270 = qcdr(v270);
    stack[-3] = v270;
    v270 = stack[-3];
    if (v270 == nil) goto v71;
    stack[0] = stack[-1];
    v270 = stack[-3];
    v270 = qcar(v270);
    v60 = v270;
    v270 = stack[-5];
    v270 = qcar(v270);
    v270 = qcar(v270);
    v270 = qcar(v270);
    if (equal(v60, v270)) goto v273;
    v270 = (Lisp_Object)1; /* 0 */
    goto v274;

v274:
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = Lrplacd(nil, stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = stack[-1];
    v270 = qcdr(v270);
    stack[-1] = v270;
    goto v272;

v273:
    v270 = stack[-5];
    v270 = qcar(v270);
    v270 = qcar(v270);
    v270 = qcdr(v270);
    goto v274;

v71:
    v270 = stack[-2];
    goto v275;

v275:
    fn = elt(env, 4); /* addgt */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    fn = elt(env, 5); /* pdmult */
    v270 = (*qfn2(fn))(qenv(fn), stack[-4], v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[0] = v270;
    goto v213;

v213:
    v270 = stack[-5];
    v60 = qcdr(v270);
    v270 = qvalue(elt(env, 1)); /* varlist */
    v270 = CC_Hf2di(env, v60, v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    fn = elt(env, 6); /* psum */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    goto v20;

v207:
    v270 = stack[-5];
    v270 = qcar(v270);
    v270 = qcar(v270);
    v270 = qcdr(v270);
    goto v186;

v238:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v275;

v180:
    v270 = stack[-5];
    v270 = qcar(v270);
    v60 = qcdr(v270);
    v270 = qvalue(elt(env, 1)); /* varlist */
    stack[0] = CC_Hf2di(env, v60, v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = stack[-5];
    v270 = qcar(v270);
    v60 = qcar(v270);
    v270 = (Lisp_Object)17; /* 1 */
    v270 = cons(v60, v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    fn = elt(env, 7); /* pcmult */
    v270 = (*qfn2(fn))(qenv(fn), stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[0] = v270;
    goto v213;

v101:
    v270 = qvalue(elt(env, 3)); /* t */
    goto v32;

v195:
    v270 = qvalue(elt(env, 2)); /* nil */
    goto v20;
/* error exit handlers */
v62:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varlist */
    popv(8);
    return nil;
}



/* Code for nodum_varp */

static Lisp_Object CC_nodum_varp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nodum_varp");
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
    v193 = stack[0];
    fn = elt(env, 7); /* listp */
    v193 = (*qfn1(fn))(qenv(fn), v193);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    if (v193 == nil) goto v13;
    v193 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v193); }

v13:
    v126 = stack[0];
    v193 = elt(env, 2); /* dummy */
    v193 = Lflagp(nil, v126, v193);
    env = stack[-1];
    if (v193 == nil) goto v136;
    v193 = qvalue(elt(env, 1)); /* t */
    goto v200;

v200:
    if (v193 == nil) goto v38;
    v193 = qvalue(elt(env, 6)); /* nil */
    { popv(2); return onevalue(v193); }

v38:
    v193 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v193); }

v136:
    v193 = stack[0];
    fn = elt(env, 8); /* ad_splitname */
    v193 = (*qfn1(fn))(qenv(fn), v193);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    v126 = qcar(v193);
    v193 = qvalue(elt(env, 3)); /* g_dvbase */
    if (equal(v126, v193)) goto v96;
    v126 = elt(env, 4); /* !~dv */
    v193 = elt(env, 5); /* !~dva */
    v193 = list2(v126, v193);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    v193 = Lmember(nil, stack[0], v193);
    goto v200;

v96:
    v193 = qvalue(elt(env, 1)); /* t */
    goto v200;
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for balance_mod */

static Lisp_Object CC_balance_mod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v10;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for balance_mod");
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
    v10 = stack[-1];
    v9 = stack[-1];
    v10 = plus2(v10, v9);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-2];
    v9 = stack[0];
    v9 = (Lisp_Object)greaterp2(v10, v9);
    nil = C_nil;
    if (exception_pending()) goto v95;
    v9 = v9 ? lisp_true : nil;
    if (v9 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v10 = stack[-1];
    v9 = stack[0];
    popv(3);
    return difference2(v10, v9);
/* error exit handlers */
v95:
    popv(3);
    return nil;
}



/* Code for use!-berlekamp */

static Lisp_Object MS_CDECL CC_useKberlekamp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v299, v120, v300, v301, v302, v303, v304;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "use-berlekamp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for use-berlekamp");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v299 = qvalue(elt(env, 1)); /* dpoly */
    v299 = (Lisp_Object)((int32_t)(v299) - 0x10);
    stack[-3] = v299;
    v299 = stack[-3];
    v299 = Lmkvect(nil, v299);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-8];
    stack[-7] = v299;
    v299 = (Lisp_Object)1; /* 0 */
    stack[0] = v299;
    goto v127;

v127:
    v120 = stack[-3];
    v299 = stack[0];
    v299 = (Lisp_Object)(int32_t)((int32_t)v120 - (int32_t)v299 + TAG_FIXNUM);
    v299 = ((intptr_t)(v299) < 0 ? lisp_true : nil);
    if (v299 == nil) goto v5;
    v301 = stack[-6];
    v300 = stack[-5];
    v120 = qvalue(elt(env, 3)); /* poly!-vector */
    v299 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v299 = (*qfnn(fn))(qenv(fn), 4, v301, v300, v120, v299);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-8];
    stack[-5] = v299;
    v299 = (Lisp_Object)1; /* 0 */
    stack[-2] = v299;
    v299 = stack[-3];
    v299 = Lmkvect(nil, v299);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-8];
    stack[-1] = v299;
    v300 = stack[-1];
    v120 = (Lisp_Object)1; /* 0 */
    v299 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v300 + (CELL-TAG_VECTOR) + ((int32_t)v120/(16/CELL))) = v299;
    v299 = (Lisp_Object)17; /* 1 */
    stack[0] = v299;
    goto v84;

v84:
    v120 = stack[-3];
    v299 = stack[0];
    v299 = (Lisp_Object)(int32_t)((int32_t)v120 - (int32_t)v299 + TAG_FIXNUM);
    v299 = ((intptr_t)(v299) < 0 ? lisp_true : nil);
    if (v299 == nil) goto v305;
    v120 = stack[-7];
    v299 = stack[-3];
    {
        popv(9);
        fn = elt(env, 6); /* find!-null!-space */
        return (*qfn2(fn))(qenv(fn), v120, v299);
    }

v305:
    v120 = qvalue(elt(env, 4)); /* current!-modulus */
    v299 = qvalue(elt(env, 1)); /* dpoly */
    if (((int32_t)(v120)) > ((int32_t)(v299))) goto v306;
    v299 = (Lisp_Object)1; /* 0 */
    v301 = v299;
    goto v307;

v307:
    v299 = qvalue(elt(env, 4)); /* current!-modulus */
    v120 = (Lisp_Object)((int32_t)(v299) - 0x10);
    v299 = v301;
    v299 = (Lisp_Object)(int32_t)((int32_t)v120 - (int32_t)v299 + TAG_FIXNUM);
    v299 = ((intptr_t)(v299) < 0 ? lisp_true : nil);
    if (v299 == nil) goto v273;
    v299 = (Lisp_Object)1; /* 0 */
    v302 = v299;
    goto v308;

v308:
    v120 = stack[-2];
    v299 = v302;
    v299 = (Lisp_Object)(int32_t)((int32_t)v120 - (int32_t)v299 + TAG_FIXNUM);
    v299 = ((intptr_t)(v299) < 0 ? lisp_true : nil);
    if (v299 == nil) goto v309;
    v120 = stack[-2];
    v299 = qvalue(elt(env, 4)); /* current!-modulus */
    v299 = (Lisp_Object)(int32_t)((int32_t)v120 + (int32_t)v299 - TAG_FIXNUM);
    stack[-2] = v299;
    goto v310;

v310:
    v301 = stack[-4];
    v300 = stack[-2];
    v120 = qvalue(elt(env, 3)); /* poly!-vector */
    v299 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v299 = (*qfnn(fn))(qenv(fn), 4, v301, v300, v120, v299);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-8];
    stack[-2] = v299;
    v299 = (Lisp_Object)1; /* 0 */
    v304 = v299;
    goto v57;

v57:
    v120 = stack[-2];
    v299 = v304;
    v299 = (Lisp_Object)(int32_t)((int32_t)v120 - (int32_t)v299 + TAG_FIXNUM);
    v299 = ((intptr_t)(v299) < 0 ? lisp_true : nil);
    if (v299 == nil) goto v218;
    v120 = stack[-7];
    v299 = stack[0];
    v301 = *(Lisp_Object *)((char *)v120 + (CELL-TAG_VECTOR) + ((int32_t)v299/(16/CELL)));
    v300 = stack[0];
    v120 = stack[-7];
    v299 = stack[0];
    v120 = *(Lisp_Object *)((char *)v120 + (CELL-TAG_VECTOR) + ((int32_t)v299/(16/CELL)));
    v299 = stack[0];
    v120 = *(Lisp_Object *)((char *)v120 + (CELL-TAG_VECTOR) + ((int32_t)v299/(16/CELL)));
    v299 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v120) - int_of_fixnum(v299);
        if (w < 0) w += current_modulus;
        v299 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL))) = v299;
    v299 = stack[0];
    v299 = (Lisp_Object)((int32_t)(v299) + 0x10);
    stack[0] = v299;
    goto v84;

v218:
    v120 = stack[-7];
    v299 = v304;
    v303 = *(Lisp_Object *)((char *)v120 + (CELL-TAG_VECTOR) + ((int32_t)v299/(16/CELL)));
    v302 = stack[0];
    v301 = stack[-1];
    v300 = v304;
    v120 = stack[-4];
    v299 = v304;
    v299 = *(Lisp_Object *)((char *)v120 + (CELL-TAG_VECTOR) + ((int32_t)v299/(16/CELL)));
    *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL))) = v299;
    *(Lisp_Object *)((char *)v303 + (CELL-TAG_VECTOR) + ((int32_t)v302/(16/CELL))) = v299;
    v299 = v304;
    v299 = (Lisp_Object)((int32_t)(v299) + 0x10);
    v304 = v299;
    goto v57;

v309:
    v301 = stack[-4];
    v120 = qvalue(elt(env, 4)); /* current!-modulus */
    v299 = v302;
    v300 = (Lisp_Object)(int32_t)((int32_t)v120 + (int32_t)v299 - TAG_FIXNUM);
    v120 = stack[-1];
    v299 = v302;
    v299 = *(Lisp_Object *)((char *)v120 + (CELL-TAG_VECTOR) + ((int32_t)v299/(16/CELL)));
    *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL))) = v299;
    v299 = v302;
    v299 = (Lisp_Object)((int32_t)(v299) + 0x10);
    v302 = v299;
    goto v308;

v273:
    v300 = stack[-4];
    v120 = v301;
    v299 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v300 + (CELL-TAG_VECTOR) + ((int32_t)v120/(16/CELL))) = v299;
    v299 = v301;
    v299 = (Lisp_Object)((int32_t)(v299) + 0x10);
    v301 = v299;
    goto v307;

v306:
    v302 = stack[-1];
    v301 = stack[-2];
    v300 = stack[-6];
    v120 = stack[-5];
    v299 = stack[-4];
    fn = elt(env, 7); /* times!-in!-vector */
    v299 = (*qfnn(fn))(qenv(fn), 5, v302, v301, v300, v120, v299);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-8];
    stack[-2] = v299;
    goto v310;

v5:
    v299 = stack[-3];
    v299 = Lmkvect(nil, v299);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-8];
    v302 = v299;
    v299 = (Lisp_Object)1; /* 0 */
    v301 = v299;
    goto v30;

v30:
    v120 = stack[-3];
    v299 = v301;
    v299 = (Lisp_Object)(int32_t)((int32_t)v120 - (int32_t)v299 + TAG_FIXNUM);
    v299 = ((intptr_t)(v299) < 0 ? lisp_true : nil);
    if (v299 == nil) goto v27;
    v120 = stack[-7];
    v299 = stack[0];
    v300 = v302;
    *(Lisp_Object *)((char *)v120 + (CELL-TAG_VECTOR) + ((int32_t)v299/(16/CELL))) = v300;
    v299 = stack[0];
    v299 = (Lisp_Object)((int32_t)(v299) + 0x10);
    stack[0] = v299;
    goto v127;

v27:
    v300 = v302;
    v120 = v301;
    v299 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v300 + (CELL-TAG_VECTOR) + ((int32_t)v120/(16/CELL))) = v299;
    v299 = v301;
    v299 = (Lisp_Object)((int32_t)(v299) + 0x10);
    v301 = v299;
    goto v30;
/* error exit handlers */
v197:
    popv(9);
    return nil;
}



/* Code for rl_smrmknowl */

static Lisp_Object CC_rl_smrmknowl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smrmknowl");
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
    v101 = v1;
    v123 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smrmknowl!* */
    v101 = list2(v123, v101);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    {
        Lisp_Object v6 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v6, v101);
    }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for give!*position */

static Lisp_Object CC_giveHposition(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for give*position");
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
    v35 = (Lisp_Object)17; /* 1 */
    stack[-4] = v35;
    v35 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v35;
    goto v133;

v133:
    v35 = stack[-1];
    if (v35 == nil) goto v6;
    v35 = qvalue(elt(env, 1)); /* nil */
    goto v32;

v32:
    if (v35 == nil) goto v195;
    v131 = stack[-2];
    v35 = stack[-4];
    fn = elt(env, 5); /* pnth */
    v35 = (*qfn2(fn))(qenv(fn), v131, v35);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-5];
    v131 = qcar(v35);
    v35 = stack[-3];
    if (equal(v131, v35)) goto v12;
    v35 = stack[-4];
    v35 = add1(v35);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-5];
    stack[-4] = v35;
    goto v133;

v12:
    v35 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v35;
    goto v133;

v195:
    v35 = stack[-1];
    if (!(v35 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v35 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v35 == nil)) goto v141;
    v35 = elt(env, 4); /* "error in give position" */
    fn = elt(env, 6); /* lprie */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-5];
    goto v141;

v141:
    v35 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v311;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v6:
    stack[0] = stack[-4];
    v35 = stack[-2];
    v35 = Llength(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-5];
    v35 = (Lisp_Object)lesseq2(stack[0], v35);
    nil = C_nil;
    if (exception_pending()) goto v311;
    v35 = v35 ? lisp_true : nil;
    env = stack[-5];
    goto v32;
/* error exit handlers */
v311:
    popv(6);
    return nil;
}



/* Code for pasf_smordtable */

static Lisp_Object MS_CDECL CC_pasf_smordtable(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v26, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smordtable");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smordtable");
#endif
    if (stack >= stacklimit)
    {
        push4(v26,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v26);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v26;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v22 = stack[-1];
    v19 = stack[0];
    v19 = (Lisp_Object)lessp2(v22, v19);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v19 = v19 ? lisp_true : nil;
    env = stack[-4];
    if (v19 == nil) goto v96;
    v22 = stack[-3];
    v19 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); /* pasf_smordtable2 */
        return (*qfn2(fn))(qenv(fn), v22, v19);
    }

v96:
    v22 = stack[-1];
    v19 = stack[0];
    v19 = (Lisp_Object)greaterp2(v22, v19);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v19 = v19 ? lisp_true : nil;
    env = stack[-4];
    if (v19 == nil) goto v28;
    v22 = stack[-3];
    v19 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* pasf_smordtable1 */
        return (*qfn2(fn))(qenv(fn), v22, v19);
    }

v28:
    v19 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v19 == nil)) goto v255;
    v19 = elt(env, 2); /* "abused smordtable" */
    v19 = ncons(v19);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    fn = elt(env, 5); /* lprie */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-4];
    goto v255;

v255:
    v19 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v19 = nil;
    { popv(5); return onevalue(v19); }
/* error exit handlers */
v126:
    popv(5);
    return nil;
}



/* Code for dvfsf_simplat1 */

static Lisp_Object CC_dvfsf_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v256, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_simplat1");
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
    v126 = stack[-2];
    fn = elt(env, 4); /* dvfsf_op */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    v92 = v126;
    v256 = v92;
    v126 = elt(env, 1); /* equal */
    if (v256 == v126) goto v8;
    v256 = v92;
    v126 = elt(env, 3); /* neq */
    v126 = (v256 == v126 ? lisp_true : nil);
    goto v7;

v7:
    if (v126 == nil) goto v151;
    stack[0] = v92;
    v126 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2l */
    v256 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    v126 = stack[-1];
    {
        Lisp_Object v24 = stack[0];
        popv(5);
        fn = elt(env, 6); /* dvfsf_safield */
        return (*qfnn(fn))(qenv(fn), 3, v24, v256, v126);
    }

v151:
    stack[-3] = v92;
    v126 = stack[-2];
    fn = elt(env, 5); /* dvfsf_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    v126 = stack[-2];
    fn = elt(env, 7); /* dvfsf_arg2r */
    v256 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-4];
    v126 = stack[-1];
    {
        Lisp_Object v312 = stack[-3];
        Lisp_Object v89 = stack[0];
        popv(5);
        fn = elt(env, 8); /* dvfsf_saval */
        return (*qfnn(fn))(qenv(fn), 4, v312, v89, v256, v126);
    }

v8:
    v126 = qvalue(elt(env, 2)); /* t */
    goto v7;
/* error exit handlers */
v23:
    popv(5);
    return nil;
}



/* Code for minusrd */

static Lisp_Object MS_CDECL CC_minusrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minusrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for minusrd");
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
    fn = elt(env, 1); /* mathml */
    v97 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    stack[0] = v97;
    fn = elt(env, 1); /* mathml */
    v97 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    v16 = v97;
    if (v16 == nil) goto v125;
    v16 = stack[0];
    fn = elt(env, 2); /* alg_difference */
    v97 = (*qfn2(fn))(qenv(fn), v16, v97);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-1];
    stack[0] = v97;
    fn = elt(env, 3); /* lex */
    v97 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v135;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v125:
    v97 = stack[0];
    fn = elt(env, 4); /* alg_minus */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v135;
    stack[0] = v97;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v135:
    popv(2);
    return nil;
}



/* Code for freeof */

static Lisp_Object CC_freeof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof");
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
    v3 = stack[0];
    v136 = stack[-1];
    fn = elt(env, 2); /* smember */
    v136 = (*qfn2(fn))(qenv(fn), v3, v136);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    if (!(v136 == nil)) goto v25;
    v3 = stack[0];
    v136 = stack[-1];
    v4 = qvalue(elt(env, 1)); /* depl!* */
    v136 = Lassoc(nil, v136, v4);
    v136 = Lmember(nil, v3, v136);
    goto v25;

v25:
    v136 = (v136 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v136); }
/* error exit handlers */
v11:
    popv(3);
    return nil;
}



/* Code for matsm1 */

static Lisp_Object CC_matsm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v376, v377, v378;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm1");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    goto v224;

v224:
    v376 = stack[-8];
    if (v376 == nil) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v376 = stack[-8];
    v377 = qcar(v376);
    v376 = elt(env, 1); /* !*div */
    if (!consp(v377)) goto v127;
    v377 = qcar(v377);
    if (!(v377 == v376)) goto v127;
    v376 = stack[-8];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    v376 = qcar(v376);
    fn = elt(env, 19); /* matsm */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-2] = v376;
    v376 = stack[-2];
    v376 = qcar(v376);
    stack[0] = Llength(nil, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-1] = stack[0];
    v376 = stack[-2];
    v376 = Llength(nil, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    if (equal(stack[0], v376)) goto v41;
    v376 = elt(env, 10); /* "Non square matrix" */
    v377 = v376;
    v376 = v377;
    qvalue(elt(env, 7)) = v376; /* errmsg!* */
    v376 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v376 == nil)) goto v380;
    v376 = v377;
    fn = elt(env, 20); /* lprie */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v380;

v380:
    v376 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v381;

v381:
    v376 = qvalue(elt(env, 11)); /* subfg!* */
    stack[0] = v376;
    v376 = qvalue(elt(env, 4)); /* nil */
    qvalue(elt(env, 11)) = v376; /* subfg!* */
    v376 = stack[-9];
    if (v376 == nil) goto v382;
    v377 = elt(env, 2); /* mat */
    v376 = elt(env, 13); /* lnrsolvefn */
    v376 = get(v377, v376);
    env = stack[-10];
    stack[0] = v376;
    if (v376 == nil) goto v383;
    v377 = elt(env, 2); /* mat */
    v376 = elt(env, 13); /* lnrsolvefn */
    v378 = get(v377, v376);
    env = stack[-10];
    v377 = stack[-2];
    v376 = stack[-9];
    v376 = Lapply2(nil, 3, v378, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-9] = v376;
    goto v384;

v384:
    v376 = stack[0];
    qvalue(elt(env, 11)) = v376; /* subfg!* */
    v376 = stack[-9];
    stack[-7] = v376;
    v376 = stack[-7];
    if (v376 == nil) goto v385;
    v376 = stack[-7];
    v376 = qcar(v376);
    stack[-3] = v376;
    v376 = stack[-3];
    if (v376 == nil) goto v386;
    v376 = stack[-3];
    v376 = qcar(v376);
    v377 = v376;
    v376 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 15)) = v376; /* !*sub2 */
    v376 = v377;
    fn = elt(env, 21); /* subs2 */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-1] = v376;
    stack[-2] = v376;
    goto v387;

v387:
    v376 = stack[-3];
    v376 = qcdr(v376);
    stack[-3] = v376;
    v376 = stack[-3];
    if (v376 == nil) goto v388;
    stack[0] = stack[-1];
    v376 = stack[-3];
    v376 = qcar(v376);
    v377 = v376;
    v376 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 15)) = v376; /* !*sub2 */
    v376 = v377;
    fn = elt(env, 21); /* subs2 */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = Lrplacd(nil, stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = stack[-1];
    v376 = qcdr(v376);
    stack[-1] = v376;
    goto v387;

v388:
    v376 = stack[-2];
    goto v389;

v389:
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-5] = v376;
    stack[-6] = v376;
    goto v390;

v390:
    v376 = stack[-7];
    v376 = qcdr(v376);
    stack[-7] = v376;
    v376 = stack[-7];
    if (v376 == nil) goto v391;
    stack[-4] = stack[-5];
    v376 = stack[-7];
    v376 = qcar(v376);
    stack[-3] = v376;
    v376 = stack[-3];
    if (v376 == nil) goto v392;
    v376 = stack[-3];
    v376 = qcar(v376);
    v377 = v376;
    v376 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 15)) = v376; /* !*sub2 */
    v376 = v377;
    fn = elt(env, 21); /* subs2 */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-1] = v376;
    stack[-2] = v376;
    goto v393;

v393:
    v376 = stack[-3];
    v376 = qcdr(v376);
    stack[-3] = v376;
    v376 = stack[-3];
    if (v376 == nil) goto v394;
    stack[0] = stack[-1];
    v376 = stack[-3];
    v376 = qcar(v376);
    v377 = v376;
    v376 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 15)) = v376; /* !*sub2 */
    v376 = v377;
    fn = elt(env, 21); /* subs2 */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = Lrplacd(nil, stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = stack[-1];
    v376 = qcdr(v376);
    stack[-1] = v376;
    goto v393;

v394:
    v376 = stack[-2];
    goto v395;

v395:
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = Lrplacd(nil, stack[-4], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = stack[-5];
    v376 = qcdr(v376);
    stack[-5] = v376;
    goto v390;

v392:
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v395;

v391:
    v376 = stack[-6];
    goto v396;

v396:
    stack[-9] = v376;
    goto v195;

v195:
    v376 = stack[-8];
    v376 = qcdr(v376);
    stack[-8] = v376;
    goto v224;

v386:
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v389;

v385:
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v396;

v383:
    v377 = elt(env, 2); /* mat */
    v376 = elt(env, 12); /* inversefn */
    v377 = get(v377, v376);
    env = stack[-10];
    v376 = stack[-2];
    v377 = Lapply1(nil, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = stack[-9];
    fn = elt(env, 22); /* multm */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-9] = v376;
    goto v384;

v382:
    v377 = elt(env, 2); /* mat */
    v376 = elt(env, 12); /* inversefn */
    v377 = get(v377, v376);
    env = stack[-10];
    v376 = stack[-2];
    v376 = Lapply1(nil, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-9] = v376;
    goto v384;

v41:
    v376 = stack[-9];
    if (v376 == nil) goto v397;
    stack[0] = stack[-1];
    v376 = stack[-9];
    v376 = Llength(nil, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    if (equal(stack[0], v376)) goto v397;
    v376 = elt(env, 6); /* "Matrix mismatch" */
    v377 = v376;
    v376 = v377;
    qvalue(elt(env, 7)) = v376; /* errmsg!* */
    v376 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v376 == nil)) goto v398;
    v376 = v377;
    fn = elt(env, 20); /* lprie */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v398;

v398:
    v376 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v381;

v397:
    v376 = stack[-8];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    if (v376 == nil) goto v399;
    v376 = stack[-9];
    if (!(v376 == nil)) goto v195;
    v376 = stack[-1];
    fn = elt(env, 23); /* generateident */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-9] = v376;
    goto v195;

v399:
    v376 = stack[-2];
    v376 = qcdr(v376);
    if (v376 == nil) goto v400;
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v401;

v401:
    if (v376 == nil) goto v381;
    v376 = stack[-2];
    v376 = qcar(v376);
    v376 = qcar(v376);
    v376 = qcar(v376);
    if (!(v376 == nil)) goto v402;
    v376 = elt(env, 16); /* "Zero divisor" */
    v377 = v376;
    v376 = v377;
    qvalue(elt(env, 7)) = v376; /* errmsg!* */
    v376 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v376 == nil)) goto v403;
    v376 = v377;
    fn = elt(env, 20); /* lprie */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v403;

v403:
    v376 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v402;

v402:
    v376 = stack[-2];
    v376 = qcar(v376);
    v376 = qcar(v376);
    v377 = qcdr(v376);
    v376 = stack[-2];
    v376 = qcar(v376);
    v376 = qcar(v376);
    v376 = qcar(v376);
    v376 = cons(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-2] = v376;
    v376 = stack[-9];
    if (v376 == nil) goto v404;
    v377 = stack[-2];
    v376 = stack[-9];
    fn = elt(env, 24); /* multsm */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v405;

v405:
    stack[-9] = v376;
    goto v195;

v404:
    v376 = stack[-2];
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v405;

v400:
    v376 = stack[-2];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    v376 = (v376 == nil ? lisp_true : nil);
    goto v401;

v127:
    v376 = stack[-8];
    v376 = qcar(v376);
    if (!consp(v376)) goto v406;
    v376 = stack[-8];
    v376 = qcar(v376);
    v377 = qcar(v376);
    v376 = elt(env, 2); /* mat */
    if (v377 == v376) goto v133;
    v376 = stack[-8];
    v376 = qcar(v376);
    v377 = qcar(v376);
    v376 = elt(env, 3); /* matmapfn */
    v376 = Lflagp(nil, v377, v376);
    env = stack[-10];
    if (v376 == nil) goto v250;
    v376 = stack[-8];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    if (v376 == nil) goto v141;
    v376 = stack[-8];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    v376 = qcar(v376);
    fn = elt(env, 25); /* getrtype */
    v377 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = elt(env, 5); /* matrix */
    v376 = (v377 == v376 ? lisp_true : nil);
    goto v14;

v14:
    if (v376 == nil) goto v241;
    v376 = stack[-8];
    v377 = qcar(v376);
    v376 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 26); /* matrixmap */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    fn = elt(env, 19); /* matsm */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[0] = v376;
    goto v125;

v125:
    v376 = stack[-9];
    if (v376 == nil) goto v407;
    v376 = stack[-9];
    v376 = qcdr(v376);
    if (v376 == nil) goto v205;
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v306;

v306:
    if (v376 == nil) goto v209;
    v376 = stack[-9];
    v376 = qcar(v376);
    v377 = qcar(v376);
    v376 = stack[0];
    fn = elt(env, 24); /* multsm */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v305;

v305:
    stack[-9] = v376;
    goto v195;

v209:
    v377 = stack[0];
    v376 = stack[-9];
    fn = elt(env, 22); /* multm */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v305;

v205:
    v376 = stack[-9];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    v376 = (v376 == nil ? lisp_true : nil);
    goto v306;

v407:
    v376 = stack[0];
    goto v305;

v241:
    v376 = stack[-8];
    v376 = qcar(v376);
    v377 = qcar(v376);
    v376 = stack[-8];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    fn = elt(env, 27); /* lispapply */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[0] = v376;
    v377 = stack[0];
    v376 = elt(env, 2); /* mat */
    if (!consp(v377)) goto v125;
    v377 = qcar(v377);
    if (!(v377 == v376)) goto v125;
    v376 = stack[0];
    fn = elt(env, 19); /* matsm */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[0] = v376;
    goto v125;

v141:
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v14;

v250:
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v14;

v133:
    v376 = stack[-8];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    fn = elt(env, 28); /* lchk */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    if (!(v376 == nil)) goto v208;
    v376 = elt(env, 6); /* "Matrix mismatch" */
    v377 = v376;
    v376 = v377;
    qvalue(elt(env, 7)) = v376; /* errmsg!* */
    v376 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v376 == nil)) goto v232;
    v376 = v377;
    fn = elt(env, 20); /* lprie */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v232;

v232:
    v376 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v208;

v208:
    v376 = stack[-8];
    v376 = qcar(v376);
    v376 = qcdr(v376);
    stack[-7] = v376;
    v376 = stack[-7];
    if (v376 == nil) goto v408;
    v376 = stack[-7];
    v376 = qcar(v376);
    stack[-3] = v376;
    v376 = stack[-3];
    if (v376 == nil) goto v292;
    v376 = stack[-3];
    v376 = qcar(v376);
    fn = elt(env, 29); /* simp!* */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v377 = v376;
    v376 = qvalue(elt(env, 9)); /* !*exp */
    if (v376 == nil) goto v112;
    v376 = v377;
    goto v175;

v175:
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-1] = v376;
    stack[-2] = v376;
    goto v214;

v214:
    v376 = stack[-3];
    v376 = qcdr(v376);
    stack[-3] = v376;
    v376 = stack[-3];
    if (v376 == nil) goto v61;
    stack[0] = stack[-1];
    v376 = stack[-3];
    v376 = qcar(v376);
    fn = elt(env, 29); /* simp!* */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v377 = v376;
    v376 = qvalue(elt(env, 9)); /* !*exp */
    if (v376 == nil) goto v163;
    v376 = v377;
    goto v58;

v58:
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = Lrplacd(nil, stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = stack[-1];
    v376 = qcdr(v376);
    stack[-1] = v376;
    goto v214;

v163:
    v376 = v377;
    fn = elt(env, 30); /* offexpchk */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v58;

v61:
    v376 = stack[-2];
    goto v173;

v173:
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-5] = v376;
    stack[-6] = v376;
    goto v181;

v181:
    v376 = stack[-7];
    v376 = qcdr(v376);
    stack[-7] = v376;
    v376 = stack[-7];
    if (v376 == nil) goto v167;
    stack[-4] = stack[-5];
    v376 = stack[-7];
    v376 = qcar(v376);
    stack[-3] = v376;
    v376 = stack[-3];
    if (v376 == nil) goto v286;
    v376 = stack[-3];
    v376 = qcar(v376);
    fn = elt(env, 29); /* simp!* */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v377 = v376;
    v376 = qvalue(elt(env, 9)); /* !*exp */
    if (v376 == nil) goto v283;
    v376 = v377;
    goto v116;

v116:
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    stack[-1] = v376;
    stack[-2] = v376;
    goto v409;

v409:
    v376 = stack[-3];
    v376 = qcdr(v376);
    stack[-3] = v376;
    v376 = stack[-3];
    if (v376 == nil) goto v410;
    stack[0] = stack[-1];
    v376 = stack[-3];
    v376 = qcar(v376);
    fn = elt(env, 29); /* simp!* */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v377 = v376;
    v376 = qvalue(elt(env, 9)); /* !*exp */
    if (v376 == nil) goto v154;
    v376 = v377;
    goto v411;

v411:
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = Lrplacd(nil, stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = stack[-1];
    v376 = qcdr(v376);
    stack[-1] = v376;
    goto v409;

v154:
    v376 = v377;
    fn = elt(env, 30); /* offexpchk */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v411;

v410:
    v376 = stack[-2];
    goto v412;

v412:
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = Lrplacd(nil, stack[-4], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v376 = stack[-5];
    v376 = qcdr(v376);
    stack[-5] = v376;
    goto v181;

v283:
    v376 = v377;
    fn = elt(env, 30); /* offexpchk */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v116;

v286:
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v412;

v167:
    v376 = stack[-6];
    goto v308;

v308:
    stack[0] = v376;
    goto v125;

v112:
    v376 = v377;
    fn = elt(env, 30); /* offexpchk */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v175;

v292:
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v173;

v408:
    v376 = qvalue(elt(env, 4)); /* nil */
    goto v308;

v406:
    v378 = elt(env, 17); /* "Matrix" */
    v376 = stack[-8];
    v377 = qcar(v376);
    v376 = elt(env, 18); /* "not set" */
    v376 = list3(v378, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    v377 = v376;
    v376 = v377;
    qvalue(elt(env, 7)) = v376; /* errmsg!* */
    v376 = qvalue(elt(env, 8)); /* !*protfg */
    if (!(v376 == nil)) goto v413;
    v376 = v377;
    fn = elt(env, 20); /* lprie */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-10];
    goto v413;

v413:
    v376 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v379;
    v376 = nil;
    { popv(11); return onevalue(v376); }
/* error exit handlers */
v379:
    popv(11);
    return nil;
}



/* Code for newsym1 */

static Lisp_Object MS_CDECL CC_newsym1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v101;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "newsym1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newsym1");
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
    v32 = qvalue(elt(env, 1)); /* cindex!* */
    v32 = Lexplode(nil, v32);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    stack[0] = v32;
    v32 = qvalue(elt(env, 1)); /* cindex!* */
    v32 = add1(v32);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[-1];
    qvalue(elt(env, 1)) = v32; /* cindex!* */
    v101 = qvalue(elt(env, 2)); /* cname!* */
    v32 = stack[0];
    v32 = Lappend(nil, v101, v32);
    nil = C_nil;
    if (exception_pending()) goto v124;
        popv(2);
        return Lcompress(nil, v32);
/* error exit handlers */
v124:
    popv(2);
    return nil;
}



/* Code for den */

static Lisp_Object CC_den(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for den");
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
    v7 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[0];
    v8 = qcdr(v7);
    v7 = (Lisp_Object)17; /* 1 */
    v7 = cons(v8, v7);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v7);
    }
/* error exit handlers */
v148:
    popv(1);
    return nil;
}



/* Code for matsm */

static Lisp_Object CC_matsm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm");
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
    v22 = v0;
/* end of prologue */
    stack[-2] = nil;
    v38 = v22;
    v22 = elt(env, 1); /* matrix */
    fn = elt(env, 3); /* nssimp */
    v22 = (*qfn2(fn))(qenv(fn), v38, v22);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    stack[-1] = v22;
    goto v125;

v125:
    v22 = stack[-1];
    if (v22 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v22 = stack[-1];
    v22 = qcar(v22);
    v38 = v22;
    v22 = v38;
    stack[0] = qcar(v22);
    v22 = v38;
    v22 = qcdr(v22);
    fn = elt(env, 4); /* matsm1 */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    fn = elt(env, 5); /* multsm */
    v22 = (*qfn2(fn))(qenv(fn), stack[0], v22);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    v38 = stack[-2];
    if (v38 == nil) goto v21;
    v38 = stack[-2];
    fn = elt(env, 6); /* addm */
    v22 = (*qfn2(fn))(qenv(fn), v38, v22);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    goto v21;

v21:
    stack[-2] = v22;
    v22 = stack[-1];
    v22 = qcdr(v22);
    stack[-1] = v22;
    goto v125;
/* error exit handlers */
v126:
    popv(4);
    return nil;
}



/* Code for simpsetdiff */

static Lisp_Object CC_simpsetdiff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v414, v241;
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
    v102 = v0;
/* end of prologue */
    v414 = elt(env, 1); /* setdiff */
    fn = elt(env, 4); /* applysetop */
    v102 = (*qfn2(fn))(qenv(fn), v414, v102);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[0];
    v241 = v102;
    v102 = v241;
    v414 = qcar(v102);
    v102 = elt(env, 1); /* setdiff */
    if (v414 == v102) goto v15;
    v102 = v241;
    goto v4;

v4:
    fn = elt(env, 5); /* fkern */
    v414 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[0];
    v102 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* getpower */
    v414 = (*qfn2(fn))(qenv(fn), v414, v102);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[0];
    v102 = (Lisp_Object)17; /* 1 */
    v102 = cons(v414, v102);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[0];
    v414 = ncons(v102);
    nil = C_nil;
    if (exception_pending()) goto v248;
    v102 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v414, v102);

v15:
    v102 = v241;
    v102 = qcdr(v102);
    v414 = qcar(v102);
    v102 = v241;
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v102 = qcar(v102);
    if (equal(v414, v102)) goto v257;
    v102 = v241;
    v102 = qcdr(v102);
    v414 = qcar(v102);
    v102 = qvalue(elt(env, 3)); /* empty_set */
    v102 = (equal(v414, v102) ? lisp_true : nil);
    goto v255;

v255:
    if (v102 == nil) goto v91;
    v102 = qvalue(elt(env, 3)); /* empty_set */
    goto v4;

v91:
    v102 = v241;
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v414 = qcar(v102);
    v102 = qvalue(elt(env, 3)); /* empty_set */
    if (equal(v414, v102)) goto v132;
    v102 = v241;
    goto v4;

v132:
    v102 = v241;
    v102 = qcdr(v102);
    v102 = qcar(v102);
    goto v4;

v257:
    v102 = qvalue(elt(env, 2)); /* t */
    goto v255;
/* error exit handlers */
v248:
    popv(1);
    return nil;
}



/* Code for natnump */

static Lisp_Object CC_natnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for natnump");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v0;
/* end of prologue */
    v123 = v124;
    v123 = integerp(v123);
    if (v123 == nil) goto v25;
    v123 = (Lisp_Object)1; /* 0 */
        return Lgeq(nil, v124, v123);

v25:
    v123 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v123);
}



/* Code for mkforttab */

static Lisp_Object MS_CDECL CC_mkforttab(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v32;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkforttab");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkforttab");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    stack[0] = elt(env, 1); /* forttab */
    v32 = qvalue(elt(env, 2)); /* fortcurrind!* */
    v13 = (Lisp_Object)97; /* 6 */
    v13 = plus2(v32, v13);
    nil = C_nil;
    if (exception_pending()) goto v123;
    {
        Lisp_Object v124 = stack[0];
        popv(1);
        return list2(v124, v13);
    }
/* error exit handlers */
v123:
    popv(1);
    return nil;
}



/* Code for ev!-poles */

static Lisp_Object CC_evKpoles(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v12, v95, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-poles");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v94 = v1;
    v95 = v0;
/* end of prologue */

v46:
    v11 = v95;
    if (v11 == nil) goto v224;
    v11 = v95;
    v12 = qcar(v11);
    v11 = v94;
    v11 = Lassoc(nil, v12, v11);
    v12 = qcdr(v11);
    v11 = (Lisp_Object)1; /* 0 */
    if (!(v12 == v11)) return onevalue(v95);
    v11 = v95;
    v11 = qcdr(v11);
    v95 = v11;
    goto v46;

v224:
    v11 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v11);
}



/* Code for extract_vars */

static Lisp_Object CC_extract_vars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extract_vars");
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
    goto v46;

v46:
    v129 = stack[0];
    if (v129 == nil) goto v224;
    v129 = stack[0];
    v129 = qcar(v129);
    fn = elt(env, 2); /* raiseind!: */
    v29 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    v129 = elt(env, 1); /* variable */
    v129 = Lflagp(nil, v29, v129);
    env = stack[-2];
    if (v129 == nil) goto v12;
    v129 = stack[0];
    v29 = qcar(v129);
    v129 = stack[-1];
    v129 = cons(v29, v129);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-2];
    stack[-1] = v129;
    v129 = stack[0];
    v129 = qcdr(v129);
    stack[0] = v129;
    goto v46;

v12:
    v129 = stack[0];
    v129 = qcdr(v129);
    stack[0] = v129;
    goto v46;

v224:
    v129 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v129);
    }
/* error exit handlers */
v150:
    popv(3);
    return nil;
}



/* Code for f2df */

static Lisp_Object CC_f2df(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v191, v204;
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
    v85 = stack[0];
    if (!consp(v85)) goto v224;
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = (consp(v85) ? nil : lisp_true);
    goto v37;

v37:
    if (v85 == nil) goto v96;
    v191 = stack[0];
    v85 = (Lisp_Object)17; /* 1 */
    v85 = cons(v191, v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* dfconst */
        return (*qfn1(fn))(qenv(fn), v85);
    }

v96:
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = qcar(v85);
    v191 = qcar(v85);
    v85 = qvalue(elt(env, 2)); /* zlist */
    v85 = Lmember(nil, v191, v85);
    if (v85 == nil) goto v143;
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = qcar(v85);
    v204 = qcar(v85);
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = qcar(v85);
    v191 = qcdr(v85);
    v85 = qvalue(elt(env, 2)); /* zlist */
    fn = elt(env, 5); /* vp2df */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v204, v191, v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = qcdr(v85);
    v85 = CC_f2df(env, v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    fn = elt(env, 6); /* multdf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    v85 = stack[0];
    v85 = qcdr(v85);
    v85 = CC_f2df(env, v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    {
        Lisp_Object v104 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v104, v85);
    }

v143:
    v85 = stack[0];
    v85 = qcar(v85);
    v191 = qcar(v85);
    v85 = (Lisp_Object)17; /* 1 */
    v204 = cons(v191, v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    v191 = qvalue(elt(env, 3)); /* nil */
    v85 = (Lisp_Object)17; /* 1 */
    stack[-1] = acons(v204, v191, v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    v85 = stack[0];
    v85 = qcar(v85);
    v85 = qcdr(v85);
    v85 = CC_f2df(env, v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    fn = elt(env, 8); /* multdfconst */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    v85 = stack[0];
    v85 = qcdr(v85);
    v85 = CC_f2df(env, v85);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-2];
    {
        Lisp_Object v189 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v189, v85);
    }

v224:
    v85 = qvalue(elt(env, 1)); /* t */
    goto v37;
/* error exit handlers */
v272:
    popv(3);
    return nil;
}



setup_type const u30_setup[] =
{
    {"ofsf_sacrel",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_sacrel},
    {"setfuncsnaryrd",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_setfuncsnaryrd},
    {"indexsymmetrize",         CC_indexsymmetrize,too_many_1, wrong_no_1},
    {"applsmacro",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_applsmacro},
    {"reduce",                  too_few_2,      CC_reduce,     wrong_no_2},
    {"fs:make-nullangle",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_fsTmakeKnullangle},
    {"red=hide",                CC_redMhide,    too_many_1,    wrong_no_1},
    {"taylorp",                 CC_taylorp,     too_many_1,    wrong_no_1},
    {"ofsf_at2ir",              too_few_2,      CC_ofsf_at2ir, wrong_no_2},
    {"createsinglevariablemonom",CC_createsinglevariablemonom,too_many_1,wrong_no_1},
    {"gigcdsq",                 too_few_2,      CC_gigcdsq,    wrong_no_2},
    {"pasf_dt",                 CC_pasf_dt,     too_many_1,    wrong_no_1},
    {"rl_surep",                too_few_2,      CC_rl_surep,   wrong_no_2},
    {"setrd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrd},
    {"ps:zerop:",               CC_psTzeropT,   too_many_1,    wrong_no_1},
    {"maxl",                    CC_maxl,        too_many_1,    wrong_no_1},
    {"assgnpri",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_assgnpri},
    {"decimal2internal",        too_few_2,      CC_decimal2internal,wrong_no_2},
    {"indexvp",                 CC_indexvp,     too_many_1,    wrong_no_1},
    {"*f2di",                   too_few_2,      CC_Hf2di,      wrong_no_2},
    {"nodum_varp",              CC_nodum_varp,  too_many_1,    wrong_no_1},
    {"balance_mod",             too_few_2,      CC_balance_mod,wrong_no_2},
    {"use-berlekamp",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_useKberlekamp},
    {"rl_smrmknowl",            too_few_2,      CC_rl_smrmknowl,wrong_no_2},
    {"give*position",           too_few_2,      CC_giveHposition,wrong_no_2},
    {"pasf_smordtable",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smordtable},
    {"dvfsf_simplat1",          too_few_2,      CC_dvfsf_simplat1,wrong_no_2},
    {"minusrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minusrd},
    {"freeof",                  too_few_2,      CC_freeof,     wrong_no_2},
    {"matsm1",                  CC_matsm1,      too_many_1,    wrong_no_1},
    {"newsym1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_newsym1},
    {"den",                     CC_den,         too_many_1,    wrong_no_1},
    {"matsm",                   CC_matsm,       too_many_1,    wrong_no_1},
    {"simpsetdiff",             CC_simpsetdiff, too_many_1,    wrong_no_1},
    {"natnump",                 CC_natnump,     too_many_1,    wrong_no_1},
    {"mkforttab",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkforttab},
    {"ev-poles",                too_few_2,      CC_evKpoles,   wrong_no_2},
    {"extract_vars",            CC_extract_vars,too_many_1,    wrong_no_1},
    {"f2df",                    CC_f2df,        too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u30", (two_args *)"10843 3595744 146433", 0}
};

/* end of generated code */
