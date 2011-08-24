
/* $destdir\u14.c        Machine generated C code */

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


/* Code for ibalp_var!-satlist */

static Lisp_Object CC_ibalp_varKsatlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-satlist");
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
    stack[-4] = v1;
    v28 = v0;
/* end of prologue */
    stack[-5] = v28;
    goto v30;

v30:
    v28 = stack[-5];
    if (v28 == nil) goto v31;
    v28 = stack[-5];
    v28 = qcar(v28);
    stack[-3] = v28;
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    if (!(v28 == nil)) goto v32;
    v28 = stack[-3];
    v28 = qcar(v28);
    stack[-2] = v28;
    goto v33;

v33:
    v28 = stack[-2];
    if (v28 == nil) goto v34;
    v28 = stack[-2];
    v28 = qcar(v28);
    stack[-1] = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    v28 = sub1(v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v28 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-2];
    v28 = qcdr(v28);
    stack[-2] = v28;
    goto v33;

v34:
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcar(v28);
    stack[-2] = v28;
    goto v36;

v36:
    v28 = stack[-2];
    if (v28 == nil) goto v37;
    v28 = stack[-2];
    v28 = qcar(v28);
    stack[-1] = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    v28 = sub1(v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-1];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v28 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-2];
    v28 = qcdr(v28);
    stack[-2] = v28;
    goto v36;

v37:
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    stack[-1] = v28;
    goto v38;

v38:
    v28 = stack[-1];
    if (v28 == nil) goto v39;
    v28 = stack[-1];
    v28 = qcar(v28);
    v29 = v28;
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    v29 = qcdr(v29);
    stack[0] = qcdr(v29);
    v29 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    fn = elt(env, 4); /* delq */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v38;

v39:
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v29 = qcdr(v28);
    v28 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    goto v32;

v32:
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    stack[0] = qcdr(v28);
    v29 = stack[-4];
    v28 = stack[-3];
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    v28 = cons(v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v28 = (*qfn2(fn))(qenv(fn), stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v28 = stack[-5];
    v28 = qcdr(v28);
    stack[-5] = v28;
    goto v30;

v31:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v28); }
/* error exit handlers */
v35:
    popv(7);
    return nil;
}



/* Code for quotfail1 */

static Lisp_Object MS_CDECL CC_quotfail1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "quotfail1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail1");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    v44 = v1;
    v45 = v0;
/* end of prologue */
    v43 = v45;
    if (v43 == nil) goto v30;
    v43 = v45;
    fn = elt(env, 2); /* quotf */
    v43 = (*qfn2(fn))(qenv(fn), v43, v44);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-1];
    v44 = v43;
    v43 = v44;
    if (!(v43 == nil)) { popv(2); return onevalue(v44); }
    v43 = stack[0];
    fn = elt(env, 3); /* errorf */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v43 = nil;
    { popv(2); return onevalue(v43); }

v30:
    v43 = qvalue(elt(env, 1)); /* polyzero */
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v46:
    popv(2);
    return nil;
}



/* Code for variableom */

static Lisp_Object CC_variableom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variableom");
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
    v48 = stack[0];
    v49 = Lintern(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = qvalue(elt(env, 1)); /* constantsom!* */
    v48 = Lassoc(nil, v49, v48);
    stack[-1] = v48;
    v48 = stack[-1];
    if (v48 == nil) goto v51;
    v48 = elt(env, 2); /* "<OMS " */
    fn = elt(env, 9); /* printout */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = elt(env, 3); /* "cd=""" */
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = stack[-1];
    v48 = qcdr(v48);
    v48 = qcar(v48);
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = elt(env, 4); /* """ " */
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = elt(env, 5); /* "name=""" */
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = stack[-1];
    v48 = qcdr(v48);
    v48 = qcdr(v48);
    v48 = qcar(v48);
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = elt(env, 6); /* """/>" */
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    goto v52;

v52:
    v48 = nil;
    { popv(3); return onevalue(v48); }

v51:
    v48 = stack[0];
    if (v48 == nil) goto v52;
    v48 = elt(env, 8); /* "<OMV " */
    fn = elt(env, 9); /* printout */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = elt(env, 5); /* "name=""" */
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = stack[0];
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v48 = elt(env, 6); /* """/>" */
    v48 = Lprinc(nil, v48);
    nil = C_nil;
    if (exception_pending()) goto v50;
    goto v52;
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for bcquot */

static Lisp_Object CC_bcquot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcquot");
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
    v61 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v61 == nil) goto v30;
    v61 = stack[0];
    v61 = Lmodular_reciprocal(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v61 = times2(stack[-1], v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v61);
    }

v30:
    v61 = qvalue(elt(env, 2)); /* !*vdpinteger */
    if (v61 == nil) goto v65;
    v63 = stack[-1];
    v62 = stack[0];
    v61 = elt(env, 3); /* quotientx */
    fn = elt(env, 8); /* bcint2op */
    v61 = (*qfnn(fn))(qenv(fn), 3, v63, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    if (!(v61 == nil)) { popv(3); return onevalue(v61); }
    v61 = qvalue(elt(env, 4)); /* !*exp */
    if (v61 == nil) goto v66;
    v61 = qvalue(elt(env, 6)); /* !*mcd */
    v61 = (v61 == nil ? lisp_true : nil);
    goto v67;

v67:
    if (v61 == nil) goto v68;
    v61 = stack[-1];
    v62 = qcar(v61);
    v61 = stack[0];
    v61 = qcar(v61);
    fn = elt(env, 9); /* quotf */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v62 = v61;
    goto v69;

v69:
    v61 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v62, v61);

v68:
    v61 = stack[-1];
    v62 = qcar(v61);
    v61 = stack[0];
    v61 = qcar(v61);
    fn = elt(env, 10); /* quotfx1 */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v62 = v61;
    goto v69;

v66:
    v61 = qvalue(elt(env, 5)); /* t */
    goto v67;

v65:
    v61 = stack[0];
    fn = elt(env, 11); /* invsq */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    {
        Lisp_Object v70 = stack[-1];
        popv(3);
        fn = elt(env, 12); /* multsq */
        return (*qfn2(fn))(qenv(fn), v70, v61);
    }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for bcneg */

static Lisp_Object CC_bcneg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcneg");
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
    v75 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v75 == nil) goto v43;
    v76 = stack[0];
    v75 = (Lisp_Object)1; /* 0 */
    v75 = Leqn(nil, v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-1];
    if (!(v75 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v76 = qvalue(elt(env, 2)); /* current!-modulus */
    v75 = stack[0];
    v75 = (Lisp_Object)(int32_t)((int32_t)v76 - (int32_t)v75 + TAG_FIXNUM);
    { popv(2); return onevalue(v75); }

v43:
    v75 = stack[0];
    v75 = qcar(v75);
    fn = elt(env, 3); /* negf */
    v76 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v67;
    v75 = stack[0];
    v75 = qcdr(v75);
    popv(2);
    return cons(v76, v75);
/* error exit handlers */
v67:
    popv(2);
    return nil;
}



/* Code for xord_gradlex */

static Lisp_Object CC_xord_gradlex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_gradlex");
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
    v83 = stack[-1];
    v50 = qcar(v83);
    v83 = (Lisp_Object)17; /* 1 */
    if (v50 == v83) goto v84;
    v83 = stack[0];
    v50 = qcar(v83);
    v83 = (Lisp_Object)17; /* 1 */
    if (v50 == v83) goto v6;
    v83 = stack[-1];
    stack[-2] = Llength(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v83 = stack[0];
    v83 = Llength(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    if (equal(stack[-2], v83)) goto v51;
    v83 = stack[-1];
    stack[-1] = Llength(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    v83 = stack[0];
    v83 = Llength(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v85;
    {
        Lisp_Object v58 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v58, v83);
    }

v51:
    v50 = stack[-1];
    v83 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v50, v83);
    }

v6:
    v83 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v83); }

v84:
    v83 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v83); }
/* error exit handlers */
v85:
    popv(4);
    return nil;
}



/* Code for delete!-dups */

static Lisp_Object CC_deleteKdups(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v59, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delete-dups");
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
    v67 = nil;
    goto v84;

v84:
    v76 = stack[0];
    if (v76 == nil) goto v87;
    v76 = stack[0];
    v59 = qcar(v76);
    v76 = stack[0];
    v76 = qcdr(v76);
    v76 = Lmember(nil, v59, v76);
    if (v76 == nil) goto v33;
    v76 = stack[0];
    v76 = qcdr(v76);
    stack[0] = v76;
    goto v84;

v33:
    v76 = stack[0];
    v76 = qcar(v76);
    v59 = v67;
    v76 = cons(v76, v59);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-1];
    v67 = v76;
    v76 = stack[0];
    v76 = qcdr(v76);
    stack[0] = v76;
    goto v84;

v87:
    v76 = v67;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v76);
    }
/* error exit handlers */
v88:
    popv(2);
    return nil;
}



/* Code for cut!:mt */

static Lisp_Object CC_cutTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cut:mt");
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
    v104 = stack[-2];
    v103 = elt(env, 1); /* !:rd!: */
    if (!consp(v104)) goto v26;
    v104 = qcar(v104);
    if (!(v104 == v103)) goto v26;
    v103 = stack[-2];
    v103 = qcdr(v103);
    v103 = (consp(v103) ? nil : lisp_true);
    v103 = (v103 == nil ? lisp_true : nil);
    goto v47;

v47:
    if (v103 == nil) goto v66;
    v103 = stack[-1];
    v103 = integerp(v103);
    if (v103 == nil) goto v60;
    v104 = stack[-1];
    v103 = (Lisp_Object)1; /* 0 */
    v103 = (Lisp_Object)greaterp2(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v103 = v103 ? lisp_true : nil;
    env = stack[-4];
    goto v106;

v106:
    if (v103 == nil) goto v18;
    v103 = stack[-2];
    v103 = qcdr(v103);
    v103 = qcar(v103);
    v103 = Labsval(nil, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    fn = elt(env, 4); /* msd */
    v104 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v103 = stack[-1];
    v104 = difference2(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    stack[-1] = v104;
    v103 = (Lisp_Object)1; /* 0 */
    v103 = (Lisp_Object)lesseq2(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v103 = v103 ? lisp_true : nil;
    env = stack[-4];
    if (!(v103 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v103 = stack[-2];
    v103 = qcdr(v103);
    stack[0] = qcar(v103);
    v103 = stack[-1];
    v103 = negate(v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v103 = stack[-2];
    v103 = qcdr(v103);
    v104 = qcdr(v103);
    v103 = stack[-1];
    v103 = plus2(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    {
        Lisp_Object v107 = stack[-3];
        Lisp_Object v108 = stack[0];
        popv(5);
        return list2star(v107, v108, v103);
    }

v18:
    stack[0] = (Lisp_Object)1; /* 0 */
    v104 = elt(env, 3); /* "Invalid argument to" */
    v103 = elt(env, 0); /* cut!:mt */
    v103 = list2(v104, v103);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    {
        Lisp_Object v109 = stack[0];
        popv(5);
        fn = elt(env, 5); /* error */
        return (*qfn2(fn))(qenv(fn), v109, v103);
    }

v60:
    v103 = qvalue(elt(env, 2)); /* nil */
    goto v106;

v66:
    v103 = qvalue(elt(env, 2)); /* nil */
    goto v106;

v26:
    v103 = qvalue(elt(env, 2)); /* nil */
    goto v47;
/* error exit handlers */
v105:
    popv(5);
    return nil;
}



/* Code for xread1 */

static Lisp_Object CC_xread1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v345, v346, v347;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xread1");
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
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v345 = qvalue(elt(env, 1)); /* commentlist!* */
    if (v345 == nil) goto v47;
    v345 = qvalue(elt(env, 1)); /* commentlist!* */
    stack[-1] = v345;
    v345 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v345; /* commentlist!* */
    goto v47;

v47:
    v345 = qvalue(elt(env, 3)); /* cursym!* */
    stack[-3] = v345;
    goto v81;

v81:
    v345 = stack[-3];
    if (!(symbolp(v345))) goto v82;
    v346 = stack[-3];
    v345 = elt(env, 4); /* !*lpar!* */
    if (v346 == v345) goto v73;
    v346 = stack[-3];
    v345 = elt(env, 5); /* !*rpar!* */
    if (v346 == v345) goto v348;
    v346 = stack[-3];
    v345 = elt(env, 6); /* infix */
    v345 = get(v346, v345);
    env = stack[-9];
    stack[-4] = v345;
    if (!(v345 == nil)) goto v349;
    v346 = stack[-3];
    v345 = elt(env, 7); /* delim */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v61;
    v346 = qvalue(elt(env, 3)); /* cursym!* */
    v345 = elt(env, 30); /* !*semicol!* */
    if (v346 == v345) goto v350;
    fn = elt(env, 57); /* eolcheck */
    v345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v350;

v350:
    v346 = stack[-3];
    v345 = elt(env, 50); /* !*colon!* */
    if (v346 == v345) goto v352;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v353;

v353:
    if (!(v345 == nil)) goto v354;
    v346 = stack[-3];
    v345 = elt(env, 53); /* nodel */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v355;
    v345 = stack[-7];
    if (v345 == nil) goto v356;
    v346 = stack[-7];
    v345 = elt(env, 28); /* group */
    if (v346 == v345) goto v357;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v358;

v358:
    if (!(v345 == nil)) goto v354;
    v345 = stack[-7];
    if (!(symbolp(v345))) goto v60;
    v346 = stack[-7];
    v345 = elt(env, 24); /* paren */
    if (v346 == v345) goto v359;
    v346 = stack[-7];
    v345 = elt(env, 23); /* struct */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    goto v360;

v360:
    if (v345 == nil) goto v60;
    v346 = elt(env, 55); /* "Too few right parentheses" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v60;

v60:
    v345 = stack[-4];
    if (v345 == nil) goto v361;
    v346 = elt(env, 27); /* "Improper delimiter" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v362;

v362:
    v345 = (Lisp_Object)1; /* 0 */
    stack[-4] = v345;
    goto v79;

v79:
    v345 = stack[-6];
    if (!(v345 == nil)) goto v363;
    v346 = elt(env, 27); /* "Improper delimiter" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v363;

v363:
    v345 = stack[-6];
    v345 = qcar(v345);
    stack[0] = v345;
    goto v80;

v80:
    v345 = stack[-6];
    v345 = qcdr(v345);
    stack[-6] = v345;
    v345 = stack[-6];
    if (v345 == nil) goto v364;
    v345 = stack[-6];
    v345 = qcar(v345);
    if (!consp(v345)) goto v365;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v366;

v366:
    if (v345 == nil) goto v367;
    v346 = elt(env, 34); /* "Missing operator" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v367;

v367:
    v345 = stack[-6];
    v346 = qcar(v345);
    v345 = stack[0];
    v345 = list2(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[0] = v345;
    goto v80;

v365:
    v345 = stack[-6];
    v345 = qcar(v345);
    v345 = Lsymbolp(nil, v345);
    env = stack[-9];
    v345 = (v345 == nil ? lisp_true : nil);
    goto v366;

v364:
    v346 = stack[0];
    v345 = stack[-8];
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-8] = v345;
    goto v26;

v26:
    v345 = stack[-5];
    if (v345 == nil) goto v368;
    v346 = stack[-4];
    v345 = stack[-5];
    v345 = qcar(v345);
    v345 = qcar(v345);
    v345 = (Lisp_Object)lessp2(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    v345 = v345 ? lisp_true : nil;
    env = stack[-9];
    if (!(v345 == nil)) goto v369;
    v346 = stack[-4];
    v345 = stack[-5];
    v345 = qcar(v345);
    v345 = qcar(v345);
    if (equal(v346, v345)) goto v370;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v371;

v371:
    if (!(v345 == nil)) goto v369;

v372:
    v347 = stack[-4];
    v346 = stack[-3];
    v345 = stack[-5];
    v345 = acons(v347, v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-5] = v345;
    v346 = stack[-3];
    v345 = elt(env, 25); /* !*comma!* */
    if (!(v346 == v345)) goto v86;
    v345 = stack[-5];
    v345 = qcdr(v345);
    if (!(v345 == nil)) goto v6;
    v345 = stack[-7];
    if (v345 == nil) goto v373;
    v346 = stack[-7];
    v345 = elt(env, 38); /* (lambda paren) */
    v345 = Lmemq(nil, v346, v345);
    if (!(v345 == nil)) goto v374;
    v346 = stack[-7];
    v345 = elt(env, 23); /* struct */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    goto v374;

v374:
    if (!(v345 == nil)) goto v6;

v43:
    v345 = stack[-8];
    v345 = qcdr(v345);
    if (v345 == nil) goto v375;
    v345 = elt(env, 56); /* "Please send hearn@rand.org your program!!" 
*/
    v345 = Lprint(nil, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v346 = elt(env, 27); /* "Improper delimiter" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    v345 = nil;
    { popv(10); return onevalue(v345); }

v375:
    v345 = stack[-8];
    v346 = qcar(v345);
    v345 = stack[-1];
    {
        popv(10);
        fn = elt(env, 59); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v346, v345);
    }

v6:
    fn = elt(env, 60); /* scan */
    v345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-3] = v345;
    goto v81;

v373:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v374;

v86:
    v345 = stack[-2];
    stack[-3] = v345;
    goto v81;

v369:
    v345 = stack[-8];
    v345 = qcdr(v345);
    v346 = qcar(v345);
    v345 = elt(env, 39); /* not */
    if (!consp(v346)) goto v376;
    v346 = qcar(v346);
    if (!(v346 == v345)) goto v376;
    v345 = stack[-5];
    v345 = qcar(v345);
    v347 = qcar(v345);
    v346 = elt(env, 40); /* member */
    v345 = elt(env, 6); /* infix */
    v345 = get(v346, v345);
    env = stack[-9];
    v345 = (Lisp_Object)geq2(v347, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    v345 = v345 ? lisp_true : nil;
    env = stack[-9];
    goto v377;

v377:
    if (v345 == nil) goto v378;
    v346 = elt(env, 41); /* "NOT" */
    v345 = elt(env, 42); /* "infix operator" */
    fn = elt(env, 61); /* typerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v378;

v378:
    v345 = stack[-8];
    v345 = qcdr(v345);
    v346 = qcar(v345);
    v345 = elt(env, 33); /* !*!*un!*!* */
    if (v346 == v345) goto v379;
    v345 = stack[-5];
    v345 = qcar(v345);
    stack[0] = qcdr(v345);
    v345 = stack[-8];
    v346 = qcar(v345);
    v345 = stack[-5];
    v345 = qcar(v345);
    v345 = qcdr(v345);
    if (!consp(v346)) goto v380;
    v346 = qcar(v346);
    if (!(v346 == v345)) goto v380;
    v345 = stack[-5];
    v345 = qcar(v345);
    v346 = qcdr(v345);
    v345 = elt(env, 35); /* nary */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    goto v381;

v381:
    if (v345 == nil) goto v382;
    v345 = stack[-8];
    v345 = qcdr(v345);
    v346 = qcar(v345);
    v345 = stack[-8];
    v345 = qcar(v345);
    v345 = qcdr(v345);
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v383;

v383:
    v345 = cons(stack[0], v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[0] = v345;
    goto v384;

v384:
    v345 = stack[-5];
    v345 = qcdr(v345);
    stack[-5] = v345;
    v346 = stack[0];
    v345 = stack[-8];
    v345 = qcdr(v345);
    v345 = qcdr(v345);
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-8] = v345;
    goto v26;

v382:
    v345 = stack[-8];
    v345 = qcdr(v345);
    v346 = qcar(v345);
    v345 = stack[-8];
    v345 = qcar(v345);
    v345 = list2(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v383;

v380:
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v381;

v379:
    v345 = stack[-8];
    v346 = qcar(v345);
    v345 = elt(env, 33); /* !*!*un!*!* */
    if (v346 == v345) goto v372;
    v345 = stack[-5];
    v345 = qcar(v345);
    v346 = qcdr(v345);
    v345 = stack[-8];
    v345 = qcar(v345);
    v345 = list2(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[0] = v345;
    goto v384;

v376:
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v377;

v370:
    v346 = stack[-3];
    v345 = stack[-5];
    v345 = qcar(v345);
    v345 = qcdr(v345);
    if (v346 == v345) goto v385;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v386;

v386:
    if (v345 == nil) goto v387;
    v345 = qvalue(elt(env, 13)); /* t */
    goto v371;

v387:
    v345 = stack[-5];
    v345 = qcar(v345);
    v346 = qcdr(v345);
    v345 = elt(env, 37); /* alt */
    v345 = get(v346, v345);
    env = stack[-9];
    goto v371;

v385:
    v346 = stack[-3];
    v345 = elt(env, 35); /* nary */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v388;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v386;

v388:
    v346 = stack[-3];
    v345 = elt(env, 36); /* right */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    v345 = (v345 == nil ? lisp_true : nil);
    goto v386;

v368:
    v346 = stack[-4];
    v345 = (Lisp_Object)1; /* 0 */
    if (v346 == v345) goto v43;
    else goto v372;

v361:
    v345 = stack[-8];
    if (v345 == nil) goto v389;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v390;

v390:
    if (v345 == nil) goto v362;
    v346 = qvalue(elt(env, 2)); /* nil */
    v345 = stack[-1];
    {
        popv(10);
        fn = elt(env, 59); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v346, v345);
    }

v389:
    v345 = stack[-6];
    if (v345 == nil) goto v391;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v390;

v391:
    v345 = stack[-5];
    v345 = (v345 == nil ? lisp_true : nil);
    goto v390;

v359:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v360;

v354:
    v346 = elt(env, 27); /* "Improper delimiter" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v60;

v357:
    v346 = stack[-3];
    v345 = elt(env, 54); /* (!*rsqbkt!* !*rcbkt!* !*rsqb!*) */
    v345 = Lmemq(nil, v346, v345);
    v345 = (v345 == nil ? lisp_true : nil);
    goto v358;

v356:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v358;

v355:
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v358;

v352:
    v346 = stack[-7];
    v345 = elt(env, 51); /* for */
    if (v346 == v345) goto v392;
    v345 = qvalue(elt(env, 52)); /* !*blockp */
    if (v345 == nil) goto v393;
    v345 = stack[-6];
    if (v345 == nil) goto v394;
    v345 = stack[-6];
    v345 = qcar(v345);
    if (!consp(v345)) goto v395;
    v345 = qvalue(elt(env, 13)); /* t */
    goto v353;

v395:
    v345 = stack[-6];
    v345 = qcdr(v345);
    goto v353;

v394:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v353;

v393:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v353;

v392:
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v353;

v61:
    v346 = stack[-3];
    v345 = elt(env, 8); /* stat */
    v345 = get(v346, v345);
    env = stack[-9];
    stack[-4] = v345;
    if (v345 == nil) goto v54;
    v346 = stack[-4];
    v345 = elt(env, 43); /* endstat */
    if (v346 == v345) goto v396;
    fn = elt(env, 57); /* eolcheck */
    v345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v396;

v396:
    v346 = stack[-3];
    v345 = elt(env, 44); /* go */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v397;
    v345 = qvalue(elt(env, 13)); /* t */
    goto v398;

v398:
    if (v345 == nil) goto v82;
    v346 = stack[-3];
    v345 = elt(env, 48); /* procedure */
    if (v346 == v345) goto v399;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v400;

v400:
    if (v345 == nil) goto v401;
    v345 = stack[-6];
    if (v345 == nil) goto v402;
    v345 = stack[-6];
    v345 = qcdr(v345);
    if (!(v345 == nil)) goto v403;
    v345 = qvalue(elt(env, 9)); /* !*reduce4 */
    if (!(v345 == nil)) goto v403;
    v345 = stack[-6];
    v345 = qcar(v345);
    fn = elt(env, 62); /* procstat1 */
    v345 = (*qfn1(fn))(qenv(fn), v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = ncons(v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-6] = v345;
    goto v404;

v404:
    v345 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v345;
    goto v47;

v403:
    v346 = elt(env, 49); /* "proc form" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v404;

v402:
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 62); /* procstat1 */
    v345 = (*qfn1(fn))(qenv(fn), v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = ncons(v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-6] = v345;
    goto v404;

v401:
    v346 = stack[-4];
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 63); /* lispapply */
    v346 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = stack[-6];
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-6] = v345;
    goto v404;

v399:
    v345 = qvalue(elt(env, 9)); /* !*reduce4 */
    goto v400;

v82:
    v345 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v345;
    goto v108;

v108:
    v346 = stack[-3];
    v345 = stack[-6];
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-6] = v345;
    v345 = stack[-3];
    if (is_number(v345)) goto v405;
    v346 = stack[-3];
    v345 = elt(env, 12); /* !:dn!: */
    if (!consp(v346)) goto v406;
    v346 = qcar(v346);
    if (!(v346 == v345)) goto v406;
    v345 = qvalue(elt(env, 13)); /* t */
    goto v407;

v407:
    if (!(v345 == nil)) goto v405;

v408:
    v346 = stack[-7];
    v345 = elt(env, 21); /* proc */
    if (v346 == v345) goto v409;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v410;

v410:
    if (v345 == nil) goto v6;
    v346 = elt(env, 22); /* "Syntax error in procedure header" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v6;

v409:
    v345 = stack[-6];
    v346 = Llength(nil, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = (Lisp_Object)33; /* 2 */
    v345 = (Lisp_Object)greaterp2(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    v345 = v345 ? lisp_true : nil;
    env = stack[-9];
    goto v410;

v405:
    v346 = stack[-2];
    v345 = qvalue(elt(env, 15)); /* !$eol!$ */
    if (v346 == v345) goto v411;
    v345 = qvalue(elt(env, 16)); /* nxtsym!* */
    fn = elt(env, 64); /* chknewnam */
    v345 = (*qfn1(fn))(qenv(fn), v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-2] = v345;
    if (symbolp(v345)) goto v412;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v413;

v413:
    if (v345 == nil) goto v408;
    v345 = elt(env, 20); /* times */
    qvalue(elt(env, 3)) = v345; /* cursym!* */
    goto v47;

v412:
    v346 = stack[-2];
    v345 = elt(env, 7); /* delim */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v414;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v413;

v414:
    v346 = stack[-2];
    v345 = elt(env, 17); /* switch!* */
    v345 = get(v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v415;
    v346 = stack[-2];
    v345 = elt(env, 18); /* !( */
    if (v346 == v345) goto v415;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v413;

v415:
    v346 = stack[-2];
    v345 = elt(env, 6); /* infix */
    v345 = get(v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v3;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v413;

v3:
    v345 = qvalue(elt(env, 19)); /* !*eoldelimp */
    if (v345 == nil) goto v5;
    v346 = stack[-2];
    v345 = qvalue(elt(env, 15)); /* !$eol!$ */
    v345 = (v346 == v345 ? lisp_true : nil);
    goto v416;

v416:
    v345 = (v345 == nil ? lisp_true : nil);
    goto v413;

v5:
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v416;

v411:
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v413;

v406:
    v346 = stack[-3];
    v345 = elt(env, 14); /* !:int!: */
    v345 = Leqcar(nil, v346, v345);
    env = stack[-9];
    goto v407;

v397:
    v346 = stack[-7];
    v345 = elt(env, 21); /* proc */
    if (v346 == v345) goto v417;
    v346 = stack[-4];
    v345 = elt(env, 45); /* endstatfn */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v418;
    v345 = qvalue(elt(env, 13)); /* t */
    goto v398;

v418:
    v346 = qvalue(elt(env, 16)); /* nxtsym!* */
    v345 = elt(env, 46); /* delchar */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v419;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v398;

v419:
    v346 = qvalue(elt(env, 16)); /* nxtsym!* */
    v345 = elt(env, 47); /* !, */
    v345 = (v346 == v345 ? lisp_true : nil);
    v345 = (v345 == nil ? lisp_true : nil);
    goto v398;

v417:
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v398;

v54:
    v345 = qvalue(elt(env, 9)); /* !*reduce4 */
    if (v345 == nil) goto v94;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v420;

v420:
    if (v345 == nil) goto v82;
    v346 = elt(env, 11); /* decstat */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 63); /* lispapply */
    v346 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = stack[-6];
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-6] = v345;
    goto v47;

v94:
    v346 = stack[-3];
    v345 = elt(env, 10); /* type */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    goto v420;

v349:
    fn = elt(env, 57); /* eolcheck */
    v345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v346 = stack[-3];
    v345 = elt(env, 25); /* !*comma!* */
    if (v346 == v345) goto v421;
    fn = elt(env, 60); /* scan */
    v345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-2] = v345;
    if (!consp(v345)) goto v422;
    v345 = qvalue(elt(env, 13)); /* t */
    goto v423;

v423:
    if (!(v345 == nil)) goto v41;
    v346 = stack[-2];
    v345 = elt(env, 5); /* !*rpar!* */
    if (v346 == v345) goto v424;
    v346 = stack[-2];
    v345 = elt(env, 25); /* !*comma!* */
    if (v346 == v345) goto v425;
    v346 = stack[-2];
    v345 = elt(env, 7); /* delim */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    goto v426;

v426:
    if (v345 == nil) goto v427;
    v345 = stack[-4];
    if (v345 == nil) goto v428;
    v345 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v345;
    goto v428;

v428:
    v346 = stack[-3];
    v345 = stack[-6];
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-6] = v345;
    goto v86;

v427:
    v346 = stack[-2];
    v345 = elt(env, 4); /* !*lpar!* */
    if (v346 == v345) goto v429;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v430;

v430:
    if (!(v345 == nil)) goto v81;

v41:
    v345 = stack[-6];
    if (!(v345 == nil)) goto v79;
    v346 = stack[-3];
    v345 = elt(env, 31); /* unary */
    v345 = get(v346, v345);
    env = stack[-9];
    stack[-3] = v345;
    if (!(v345 == nil)) goto v431;
    v346 = elt(env, 32); /* "Redundant operator" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v431;

v431:
    v346 = elt(env, 33); /* !*!*un!*!* */
    v345 = stack[-8];
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-8] = v345;
    goto v372;

v429:
    fn = elt(env, 57); /* eolcheck */
    v345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    if (v345 == nil) goto v432;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v430;

v432:
    fn = elt(env, 60); /* scan */
    v345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = qvalue(elt(env, 19)); /* !*eoldelimp */
    if (v345 == nil) goto v433;
    v346 = qvalue(elt(env, 3)); /* cursym!* */
    v345 = elt(env, 30); /* !*semicol!* */
    if (v346 == v345) goto v432;
    else goto v433;

v433:
    v345 = elt(env, 24); /* paren */
    v345 = CC_xread1(env, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-2] = v345;
    if (!consp(v345)) goto v434;
    v345 = stack[-2];
    v346 = qcar(v345);
    v345 = elt(env, 25); /* !*comma!* */
    if (v346 == v345) goto v435;
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v430;

v435:
    v346 = stack[-3];
    v345 = stack[-2];
    v345 = qcdr(v345);
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-3] = v345;
    goto v430;

v434:
    v345 = qvalue(elt(env, 2)); /* nil */
    goto v430;

v425:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v426;

v424:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v426;

v422:
    v345 = stack[-2];
    v345 = (is_number(v345) ? lisp_true : nil);
    if (!(v345 == nil)) goto v423;
    v346 = stack[-2];
    v345 = elt(env, 12); /* !:dn!: */
    if (!consp(v346)) goto v436;
    v346 = qcar(v346);
    if (!(v346 == v345)) goto v436;
    v345 = qvalue(elt(env, 13)); /* t */
    goto v423;

v436:
    v346 = stack[-2];
    v345 = elt(env, 14); /* !:int!: */
    v345 = Leqcar(nil, v346, v345);
    env = stack[-9];
    goto v423;

v421:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v423;

v348:
    v345 = stack[-7];
    if (v345 == nil) goto v437;
    v346 = stack[-7];
    v345 = elt(env, 28); /* group */
    if (v346 == v345) goto v438;
    v346 = stack[-7];
    v345 = elt(env, 21); /* proc */
    v345 = (v346 == v345 ? lisp_true : nil);
    goto v439;

v439:
    if (v345 == nil) goto v60;
    v346 = elt(env, 29); /* "Too many right parentheses" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v349;

v438:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v439;

v437:
    v345 = qvalue(elt(env, 13)); /* t */
    goto v439;

v73:
    fn = elt(env, 57); /* eolcheck */
    v345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v345;
    fn = elt(env, 60); /* scan */
    v346 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = elt(env, 5); /* !*rpar!* */
    if (v346 == v345) goto v74;
    v346 = stack[-6];
    v345 = elt(env, 23); /* struct */
    v345 = Lflagpcar(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v440;
    v345 = stack[-6];
    v345 = qcar(v345);
    v345 = CC_xread1(env, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-3] = v345;
    goto v441;

v441:
    v346 = stack[-7];
    v345 = elt(env, 23); /* struct */
    v345 = Lflagp(nil, v346, v345);
    env = stack[-9];
    if (v345 == nil) goto v442;
    v346 = stack[-3];
    v345 = elt(env, 25); /* !*comma!* */
    if (!consp(v346)) goto v443;
    v346 = qcar(v346);
    if (!(v346 == v345)) goto v443;
    v345 = stack[-3];
    v345 = qcdr(v345);
    goto v444;

v444:
    stack[-3] = v345;
    goto v108;

v443:
    v345 = stack[-3];
    v345 = ncons(v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v444;

v442:
    v346 = stack[-3];
    v345 = elt(env, 25); /* !*comma!* */
    if (!consp(v346)) goto v108;
    v346 = qcar(v346);
    if (!(v346 == v345)) goto v108;
    v345 = stack[-6];
    if (v345 == nil) goto v445;
    v345 = stack[-6];
    v347 = qcar(v345);
    v345 = stack[-3];
    v346 = qcdr(v345);
    v345 = stack[-6];
    v345 = qcdr(v345);
    v345 = acons(v347, v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-6] = v345;
    goto v6;

v445:
    v346 = stack[-7];
    v345 = elt(env, 26); /* lambda */
    if (v346 == v345) goto v108;
    v346 = elt(env, 27); /* "Improper delimiter" */
    v345 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 58); /* symerr */
    v345 = (*qfn2(fn))(qenv(fn), v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    goto v6;

v440:
    v345 = elt(env, 24); /* paren */
    v345 = CC_xread1(env, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-3] = v345;
    goto v441;

v74:
    v345 = stack[-6];
    if (v345 == nil) goto v6;
    v345 = stack[-6];
    v345 = qcar(v345);
    v346 = ncons(v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v345 = stack[-6];
    v345 = qcdr(v345);
    v345 = cons(v346, v345);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-6] = v345;
    goto v6;
/* error exit handlers */
v351:
    popv(10);
    return nil;
}



/* Code for mv!-domainlist!-!* */

static Lisp_Object CC_mvKdomainlistKH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist-*");
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
    goto v30;

v30:
    v44 = stack[0];
    if (v44 == nil) goto v114;
    v45 = stack[-1];
    v44 = stack[0];
    v44 = qcar(v44);
    v45 = times2(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v44 = stack[-2];
    v44 = cons(v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-2] = v44;
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[0] = v44;
    goto v30;

v114:
    v44 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v44);
    }
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for groeb!=better */

static Lisp_Object CC_groebMbetter(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v449, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=better");
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
    v449 = stack[-1];
    v449 = qcdr(v449);
    v68 = qcar(v449);
    v449 = stack[0];
    v449 = qcdr(v449);
    v449 = qcar(v449);
    v449 = (Lisp_Object)lessp2(v68, v449);
    nil = C_nil;
    if (exception_pending()) goto v100;
    v449 = v449 ? lisp_true : nil;
    env = stack[-2];
    if (v449 == nil) goto v42;
    v449 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v449); }

v42:
    v449 = stack[-1];
    v449 = qcdr(v449);
    v68 = qcar(v449);
    v449 = stack[0];
    v449 = qcdr(v449);
    v449 = qcar(v449);
    if (equal(v68, v449)) goto v67;
    v449 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v449); }

v67:
    v68 = stack[-1];
    v449 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v449 = (*qfn2(fn))(qenv(fn), v68, v449);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    stack[-1] = qcar(v449);
    v68 = stack[0];
    v449 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 3); /* pnth */
    v449 = (*qfn2(fn))(qenv(fn), v68, v449);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-2];
    v449 = qcar(v449);
    fn = elt(env, 4); /* mo_compare */
    v68 = (*qfn2(fn))(qenv(fn), stack[-1], v449);
    nil = C_nil;
    if (exception_pending()) goto v100;
    v449 = (Lisp_Object)1; /* 0 */
        popv(3);
        return Lleq(nil, v68, v449);
/* error exit handlers */
v100:
    popv(3);
    return nil;
}



/* Code for gperm3 */

static Lisp_Object CC_gperm3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v446, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm3");
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
    v446 = v1;
    v33 = v0;
/* end of prologue */

v30:
    v60 = v33;
    if (v60 == nil) { popv(2); return onevalue(v446); }
    v60 = v33;
    v60 = qcdr(v60);
    stack[0] = v60;
    v60 = v446;
    v446 = qcar(v33);
    v33 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* gperm2 */
    v33 = (*qfnn(fn))(qenv(fn), 3, v60, v446, v33);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    v446 = v33;
    v33 = stack[0];
    goto v30;
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for next!-random!-number */

static Lisp_Object MS_CDECL CC_nextKrandomKnumber(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v37, v36, v53;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "next-random-number");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for next-random-number");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v37 = qvalue(elt(env, 1)); /* unidev_next!* */
    v65 = (Lisp_Object)865; /* 54 */
    if (v37 == v65) goto v30;
    v65 = qvalue(elt(env, 1)); /* unidev_next!* */
    v65 = (Lisp_Object)((int32_t)(v65) + 0x10);
    qvalue(elt(env, 1)) = v65; /* unidev_next!* */
    goto v79;

v79:
    v37 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v65 = (Lisp_Object)865; /* 54 */
    if (v37 == v65) goto v42;
    v65 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v65 = (Lisp_Object)((int32_t)(v65) + 0x10);
    qvalue(elt(env, 2)) = v65; /* unidev_nextp!* */
    goto v23;

v23:
    v37 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v65 = qvalue(elt(env, 1)); /* unidev_next!* */
    v36 = *(Lisp_Object *)((char *)v37 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v37 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v65 = qvalue(elt(env, 2)); /* unidev_nextp!* */
    v65 = *(Lisp_Object *)((char *)v37 + (CELL-TAG_VECTOR) + ((int32_t)v65/(16/CELL)));
    v65 = (Lisp_Object)(int32_t)((int32_t)v36 - (int32_t)v65 + TAG_FIXNUM);
    v36 = v65;
    v65 = v36;
    v65 = ((intptr_t)(v65) < 0 ? lisp_true : nil);
    if (v65 == nil) goto v98;
    v37 = v36;
    v65 = qvalue(elt(env, 4)); /* randommodulus!* */
    v65 = (Lisp_Object)(int32_t)((int32_t)v37 + (int32_t)v65 - TAG_FIXNUM);
    v36 = v65;
    goto v98;

v98:
    v37 = qvalue(elt(env, 3)); /* unidev_vec!* */
    v53 = qvalue(elt(env, 1)); /* unidev_next!* */
    v65 = v36;
    *(Lisp_Object *)((char *)v37 + (CELL-TAG_VECTOR) + ((int32_t)v53/(16/CELL))) = v65;
    return onevalue(v36);

v42:
    v65 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v65; /* unidev_nextp!* */
    goto v23;

v30:
    v65 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v65; /* unidev_next!* */
    goto v79;
}



/* Code for general!-reduce!-mod!-p */

static Lisp_Object CC_generalKreduceKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-mod-p");
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
    v77 = stack[-1];
    if (v77 == nil) goto v119;
    v77 = stack[-1];
    if (!consp(v77)) goto v47;
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = (consp(v77) ? nil : lisp_true);
    goto v102;

v102:
    if (v77 == nil) goto v46;
    v77 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-number */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v48 = v77;
    v77 = v48;
    v77 = (Lisp_Object)zerop(v77);
    v77 = v77 ? lisp_true : nil;
    env = stack[-3];
    if (v77 == nil) { popv(4); return onevalue(v48); }
    v77 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v77); }

v46:
    v77 = stack[-1];
    v77 = qcar(v77);
    stack[-2] = qcar(v77);
    v77 = stack[-1];
    v77 = qcar(v77);
    v77 = qcdr(v77);
    stack[0] = CC_generalKreduceKmodKp(env, v77);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v77 = stack[-1];
    v77 = qcdr(v77);
    v77 = CC_generalKreduceKmodKp(env, v77);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    {
        Lisp_Object v97 = stack[-2];
        Lisp_Object v447 = stack[0];
        popv(4);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v97, v447, v77);
    }

v47:
    v77 = qvalue(elt(env, 2)); /* t */
    goto v102;

v119:
    v77 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v77); }
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for nonlnrsys */

static Lisp_Object CC_nonlnrsys(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonlnrsys");
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

v455:
    v60 = stack[-1];
    if (v60 == nil) goto v84;
    v60 = stack[-1];
    v43 = qcar(v60);
    v60 = stack[0];
    fn = elt(env, 2); /* nonlnr */
    v60 = (*qfn2(fn))(qenv(fn), v43, v60);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    if (!(v60 == nil)) { popv(3); return onevalue(v60); }
    v60 = stack[-1];
    v43 = qcdr(v60);
    v60 = stack[0];
    stack[-1] = v43;
    stack[0] = v60;
    goto v455;

v84:
    v60 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v60); }
/* error exit handlers */
v78:
    popv(3);
    return nil;
}



/* Code for crprcd */

static Lisp_Object CC_crprcd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v50;
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
    v83 = stack[0];
    v83 = qcdr(v83);
    v83 = qcar(v83);
    if (!consp(v83)) goto v84;
    v50 = elt(env, 1); /* !:rd!: */
    v83 = stack[0];
    v83 = qcdr(v83);
    v83 = qcar(v83);
    v83 = cons(v50, v83);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    goto v119;

v119:
    fn = elt(env, 2); /* convchk */
    stack[-1] = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    v83 = stack[0];
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    if (!consp(v83)) goto v72;
    v50 = elt(env, 1); /* !:rd!: */
    v83 = stack[0];
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    v83 = cons(v50, v83);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-2];
    goto v26;

v26:
    fn = elt(env, 2); /* convchk */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v57;
    v50 = stack[-1];
    popv(3);
    return cons(v50, v83);

v72:
    v83 = stack[0];
    v83 = qcdr(v83);
    v83 = qcdr(v83);
    goto v26;

v84:
    v83 = stack[0];
    v83 = qcdr(v83);
    v83 = qcar(v83);
    goto v119;
/* error exit handlers */
v57:
    popv(3);
    return nil;
}



/* Code for polynommultiplybyvariable */

static Lisp_Object CC_polynommultiplybyvariable(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynommultiplybyvariable");
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
    stack[-3] = nil;
    v89 = stack[-2];
    stack[0] = v89;
    goto v31;

v31:
    v89 = stack[0];
    v89 = qcar(v89);
    if (v89 == nil) goto v55;
    v89 = stack[0];
    v90 = qcar(v89);
    v89 = stack[-1];
    fn = elt(env, 2); /* monomgetvariabledegree */
    v90 = (*qfn2(fn))(qenv(fn), v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    v89 = (Lisp_Object)1; /* 0 */
    v89 = Leqn(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    if (v89 == nil) goto v449;
    v89 = stack[0];
    v90 = qcar(v89);
    v89 = stack[-3];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    stack[-3] = v89;
    v90 = stack[0];
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v90 = Lrplaca(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    v89 = stack[0];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = Lrplacd(nil, v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    goto v31;

v449:
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v31;

v55:
    v90 = qvalue(elt(env, 1)); /* nil */
    v89 = stack[-3];
    v89 = cons(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    stack[-3] = v89;
    v89 = stack[-3];
    v89 = Lreverse(nil, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    stack[-3] = v89;
    v89 = stack[-3];
    stack[0] = v89;
    goto v53;

v53:
    v89 = stack[0];
    v89 = qcar(v89);
    if (v89 == nil) goto v463;
    v89 = stack[0];
    v90 = qcar(v89);
    v89 = stack[-1];
    fn = elt(env, 3); /* monommultiplybyvariable */
    v89 = (*qfn2(fn))(qenv(fn), v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    env = stack[-4];
    v89 = stack[0];
    v89 = qcdr(v89);
    stack[0] = v89;
    goto v53;

v463:
    v90 = stack[-2];
    v89 = stack[-3];
    fn = elt(env, 4); /* polynomadd */
    v89 = (*qfn2(fn))(qenv(fn), v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v337;
    v89 = nil;
    { popv(5); return onevalue(v89); }
/* error exit handlers */
v337:
    popv(5);
    return nil;
}



/* Code for exptf */

static Lisp_Object CC_exptf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v464, v55, v342;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptf");
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
    v55 = stack[0];
    v464 = (Lisp_Object)1; /* 0 */
    v464 = (Lisp_Object)lessp2(v55, v464);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v464 = v464 ? lisp_true : nil;
    env = stack[-2];
    if (v464 == nil) goto v30;
    v342 = elt(env, 1); /* "exptf" */
    v55 = stack[-1];
    v464 = stack[0];
    v464 = list3(v342, v55, v464);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* errach */
        return (*qfn1(fn))(qenv(fn), v464);
    }

v30:
    v464 = stack[-1];
    if (!consp(v464)) goto v446;
    v464 = stack[-1];
    v464 = qcar(v464);
    v464 = (consp(v464) ? nil : lisp_true);
    goto v33;

v33:
    if (v464 == nil) goto v72;
    v55 = stack[-1];
    v464 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v55, v464);
    }

v72:
    v464 = qvalue(elt(env, 3)); /* !*exp */
    if (!(v464 == nil)) goto v49;
    v464 = stack[-1];
    fn = elt(env, 6); /* kernlp */
    v464 = (*qfn1(fn))(qenv(fn), v464);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    if (!(v464 == nil)) goto v49;
    v55 = stack[-1];
    v464 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* mksfpf */
        return (*qfn2(fn))(qenv(fn), v55, v464);
    }

v49:
    v55 = stack[-1];
    v464 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* exptf1 */
        return (*qfn2(fn))(qenv(fn), v55, v464);
    }

v446:
    v464 = qvalue(elt(env, 2)); /* t */
    goto v33;
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for cl_susiupdknowl */

static Lisp_Object MS_CDECL CC_cl_susiupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, Lisp_Object v27, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v58, v343, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_susiupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_susiupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v27,v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v40,v27);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v27;
    v85 = v40;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v31;

v31:
    v58 = stack[-1];
    if (v58 == nil) goto v24;
    v58 = stack[-1];
    v58 = qcar(v58);
    stack[-3] = v58;
    v58 = stack[-1];
    v58 = qcdr(v58);
    stack[-1] = v58;
    v99 = stack[-2];
    v343 = stack[-3];
    v58 = v85;
    v85 = stack[0];
    fn = elt(env, 4); /* cl_susiupdknowl1 */
    v85 = (*qfnn(fn))(qenv(fn), 4, v99, v343, v58, v85);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-4];
    v343 = v85;
    v58 = elt(env, 2); /* false */
    if (!(v343 == v58)) goto v31;
    v58 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v58;
    v58 = elt(env, 3); /* break */
    stack[-3] = v58;
    goto v31;

v24:
    v343 = stack[-3];
    v58 = elt(env, 3); /* break */
    if (!(v343 == v58)) { popv(5); return onevalue(v85); }
    v85 = elt(env, 2); /* false */
    { popv(5); return onevalue(v85); }
/* error exit handlers */
v100:
    popv(5);
    return nil;
}



/* Code for tobvarir */

static Lisp_Object CC_tobvarir(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v446;
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
    v33 = stack[-1];
    if (v33 == nil) goto v84;
    stack[-2] = elt(env, 1); /* bvar */
    v33 = stack[-1];
    v446 = qcar(v33);
    v33 = (Lisp_Object)17; /* 1 */
    stack[0] = list2(v446, v33);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-3];
    v33 = stack[-1];
    v33 = qcdr(v33);
    v33 = CC_tobvarir(env, v33);
    nil = C_nil;
    if (exception_pending()) goto v45;
    {
        Lisp_Object v78 = stack[-2];
        Lisp_Object v46 = stack[0];
        popv(4);
        return acons(v78, v46, v33);
    }

v84:
    v33 = nil;
    { popv(4); return onevalue(v33); }
/* error exit handlers */
v45:
    popv(4);
    return nil;
}



/* Code for bc2a */

static Lisp_Object CC_bc2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v0;
/* end of prologue */
    v26 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (!(v26 == nil)) return onevalue(v72);
    v26 = v72;
    v26 = qcar(v26);
    if (v26 == nil) goto v47;
    v26 = elt(env, 2); /* prepf */
    {
        fn = elt(env, 3); /* sqform */
        return (*qfn2(fn))(qenv(fn), v72, v26);
    }

v47:
    v26 = (Lisp_Object)1; /* 0 */
    return onevalue(v26);
}



/* Code for listdiff */

static Lisp_Object CC_listdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listdiff");
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
    v34 = v0;
/* end of prologue */

v84:
    v33 = stack[0];
    if (v33 == nil) { popv(2); return onevalue(v34); }
    v33 = v34;
    if (v33 == nil) goto v47;
    v33 = stack[0];
    v33 = qcar(v33);
    v34 = Ldelete(nil, v33, v34);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v84;

v47:
    v34 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v34); }
/* error exit handlers */
v60:
    popv(2);
    return nil;
}



/* Code for inttovec1 */

static Lisp_Object CC_inttovec1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inttovec1");
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
    v49 = stack[-1];
    v48 = (Lisp_Object)17; /* 1 */
    if (v49 == v48) goto v84;
    v48 = stack[-1];
    v49 = sub1(v48);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v48 = stack[0];
    v48 = qcdr(v48);
    fn = elt(env, 1); /* inttovec!-solve */
    v48 = (*qfn2(fn))(qenv(fn), v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    stack[-2] = v48;
    v48 = stack[0];
    v49 = qcar(v48);
    v48 = stack[-2];
    v48 = qcar(v48);
    stack[0] = difference2(v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v48 = stack[-1];
    v49 = sub1(v48);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v48 = stack[-2];
    v48 = CC_inttovec1(env, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v97;
    {
        Lisp_Object v447 = stack[0];
        popv(4);
        return cons(v447, v48);
    }

v84:
    v48 = stack[0];
    v48 = qcar(v48);
    popv(4);
    return ncons(v48);
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for cstimes */

static Lisp_Object CC_cstimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v447, v57, v85;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cstimes");
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
    v447 = v1;
    v57 = v0;
/* end of prologue */

v30:
    v97 = v57;
    if (v97 == nil) goto v114;
    v97 = v57;
    v85 = qcar(v97);
    v97 = (Lisp_Object)17; /* 1 */
    if (v85 == v97) goto v44;
    v97 = v57;
    v97 = qcdr(v97);
    stack[0] = v97;
    v97 = v57;
    v97 = qcar(v97);
    v97 = cons(v97, v447);
    nil = C_nil;
    if (exception_pending()) goto v343;
    env = stack[-1];
    v447 = v97;
    v97 = stack[0];
    v57 = v97;
    goto v30;

v44:
    v97 = v57;
    v97 = qcdr(v97);
    v57 = v97;
    goto v30;

v114:
    v97 = v447;
    if (v97 == nil) goto v82;
    v97 = v447;
    v97 = qcdr(v97);
    if (v97 == nil) goto v74;
    v97 = elt(env, 1); /* times */
    popv(2);
    return cons(v97, v447);

v74:
    v97 = v447;
    v97 = qcar(v97);
    { popv(2); return onevalue(v97); }

v82:
    v97 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v97); }
/* error exit handlers */
v343:
    popv(2);
    return nil;
}



/* Code for repasc */

static Lisp_Object MS_CDECL CC_repasc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v466;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "repasc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repasc");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v466 = nil;
    goto v101;

v101:
    v53 = stack[0];
    if (v53 == nil) goto v82;
    v54 = stack[-2];
    v53 = stack[0];
    v53 = qcar(v53);
    v53 = qcar(v53);
    if (equal(v54, v53)) goto v48;
    v53 = stack[0];
    v53 = qcar(v53);
    v54 = v466;
    v53 = cons(v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v466 = v53;
    v53 = stack[0];
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v101;

v48:
    stack[-3] = v466;
    v466 = stack[-2];
    v54 = stack[-1];
    v53 = stack[0];
    v53 = qcdr(v53);
    v53 = acons(v466, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    {
        Lisp_Object v64 = stack[-3];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v64, v53);
    }

v82:
    stack[0] = v466;
    v466 = elt(env, 1); /* "key" */
    v54 = stack[-2];
    v53 = elt(env, 2); /* "not found" */
    v53 = list3(v466, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v54 = v53;
    v53 = v54;
    qvalue(elt(env, 3)) = v53; /* errmsg!* */
    v53 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v53 == nil)) goto v78;
    v53 = v54;
    fn = elt(env, 6); /* lprie */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    goto v78;

v78:
    v53 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-4];
    v53 = nil;
    {
        Lisp_Object v70 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v70, v53);
    }
/* error exit handlers */
v96:
    popv(5);
    return nil;
}



/* Code for formsetq */

static Lisp_Object MS_CDECL CC_formsetq(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v53, v54, v466, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formsetq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v54 = v40;
    v466 = v1;
    v61 = v0;
/* end of prologue */
    v53 = v54;
    v36 = elt(env, 1); /* symbolic */
    if (v53 == v36) goto v34;
    v36 = v61;
    v53 = v466;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v36, v53, v54);
    }

v34:
    v36 = v61;
    v36 = qcdr(v36);
    v53 = qcar(v36);
    v36 = elt(env, 2); /* list */
    if (!consp(v53)) goto v24;
    v53 = qcar(v53);
    if (!(v53 == v36)) goto v24;
    v36 = v61;
    v53 = v466;
    {
        fn = elt(env, 5); /* formsetq1 */
        return (*qfnn(fn))(qenv(fn), 3, v36, v53, v54);
    }

v24:
    v36 = v61;
    v36 = qcdr(v36);
    v53 = qcar(v36);
    v36 = elt(env, 3); /* cons */
    if (!consp(v53)) goto v342;
    v53 = qcar(v53);
    if (!(v53 == v36)) goto v342;
    v36 = v61;
    v53 = v466;
    {
        fn = elt(env, 6); /* formsetq2 */
        return (*qfnn(fn))(qenv(fn), 3, v36, v53, v54);
    }

v342:
    v36 = v61;
    v53 = v466;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v36, v53, v54);
    }
}



/* Code for th_match */

static Lisp_Object CC_th_match(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for th_match");
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
    v45 = stack[-1];
    v44 = stack[0];
    fn = elt(env, 2); /* th_match0 */
    v44 = (*qfn2(fn))(qenv(fn), v45, v44);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    if (v44 == nil) goto v84;
    v44 = stack[-1];
    v44 = qcdr(v44);
    v44 = qcar(v44);
    fn = elt(env, 3); /* dl_get */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    stack[-1] = Llength(nil, v44);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v44 = stack[0];
    v44 = qcdr(v44);
    v44 = qcar(v44);
    fn = elt(env, 3); /* dl_get */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v44 = Llength(nil, v44);
    nil = C_nil;
    if (exception_pending()) goto v69;
    v44 = (equal(stack[-1], v44) ? lisp_true : nil);
    { popv(3); return onevalue(v44); }

v84:
    v44 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v44); }
/* error exit handlers */
v69:
    popv(3);
    return nil;
}



/* Code for general!-expt!-mod!-p */

static Lisp_Object CC_generalKexptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v450;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-expt-mod-p");
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
    v450 = v1;
    stack[0] = v0;
/* end of prologue */
    v22 = v450;
    v21 = (Lisp_Object)1; /* 0 */
    if (v22 == v21) goto v84;
    v22 = v450;
    v21 = (Lisp_Object)17; /* 1 */
    if (v22 == v21) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v22 = v450;
    v21 = (Lisp_Object)33; /* 2 */
    v21 = Ldivide(nil, v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    stack[-1] = v21;
    v22 = stack[0];
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = CC_generalKexptKmodKp(env, v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v450 = v21;
    v21 = v450;
    v22 = v450;
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v21 = (*qfn2(fn))(qenv(fn), v21, v22);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-2];
    v450 = v21;
    v21 = stack[-1];
    v22 = qcdr(v21);
    v21 = (Lisp_Object)1; /* 0 */
    if (v22 == v21) { popv(3); return onevalue(v450); }
    v22 = v450;
    v21 = stack[0];
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v21 = (*qfn2(fn))(qenv(fn), v22, v21);
    nil = C_nil;
    if (exception_pending()) goto v20;
    v450 = v21;
    { popv(3); return onevalue(v450); }

v84:
    v21 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v21); }
/* error exit handlers */
v20:
    popv(3);
    return nil;
}



/* Code for simpqg */

static Lisp_Object CC_simpqg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpqg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v102 = v31;
    v31 = elt(env, 1); /* qg */
    {
        fn = elt(env, 2); /* simpcv */
        return (*qfn2(fn))(qenv(fn), v102, v31);
    }
}



/* Code for revalx */

static Lisp_Object CC_revalx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v80;
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
    v80 = v0;
/* end of prologue */
    v79 = v80;
    if (!consp(v79)) goto v6;
    v79 = v80;
    v79 = qcar(v79);
    v79 = (consp(v79) ? nil : lisp_true);
    v79 = (v79 == nil ? lisp_true : nil);
    goto v106;

v106:
    if (v79 == nil) goto v41;
    v79 = v80;
    fn = elt(env, 2); /* prepf */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v458;
    env = stack[0];
    goto v119;

v119:
    {
        popv(1);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v79);
    }

v41:
    v79 = v80;
    goto v119;

v6:
    v79 = qvalue(elt(env, 1)); /* nil */
    goto v106;
/* error exit handlers */
v458:
    popv(1);
    return nil;
}



/* Code for setunion */

static Lisp_Object CC_setunion(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v87, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setunion");
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
    v87 = v0;
/* end of prologue */

v84:
    v51 = stack[0];
    if (v51 == nil) { popv(3); return onevalue(v87); }
    v51 = stack[0];
    v23 = qcar(v51);
    v51 = v87;
    v51 = Lmember(nil, v23, v51);
    if (v51 == nil) goto v72;
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[0] = v51;
    goto v84;

v72:
    stack[-1] = v87;
    v51 = stack[0];
    v51 = qcar(v51);
    v51 = ncons(v51);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v51 = Lappend(nil, stack[-1], v51);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v87 = v51;
    v51 = stack[0];
    v51 = qcdr(v51);
    stack[0] = v51;
    goto v84;
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for vdp_zero!? */

static Lisp_Object CC_vdp_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_zero?");
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
    v84 = v0;
/* end of prologue */
    fn = elt(env, 1); /* vdp_poly */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    errexit();
    v84 = (v84 == nil ? lisp_true : nil);
    return onevalue(v84);
}



/* Code for vdpred */

static Lisp_Object CC_vdpred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v466, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpred");
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
    v466 = stack[-3];
    v466 = qcdr(v466);
    v466 = qcdr(v466);
    v466 = qcdr(v466);
    v466 = qcar(v466);
    v466 = qcdr(v466);
    v466 = qcdr(v466);
    stack[-4] = v466;
    v466 = stack[-4];
    if (v466 == nil) goto v348;
    stack[-2] = elt(env, 1); /* vdp */
    v466 = stack[-4];
    stack[-1] = qcar(v466);
    v466 = stack[-4];
    v466 = qcdr(v466);
    stack[0] = qcar(v466);
    v61 = stack[-4];
    v466 = qvalue(elt(env, 2)); /* nil */
    v466 = list2(v61, v466);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v466 = list3star(stack[-2], stack[-1], stack[0], v466);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    stack[-4] = v466;
    v466 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v466 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v61 = stack[-3];
    v466 = elt(env, 4); /* sugar */
    fn = elt(env, 5); /* vdpgetprop */
    v61 = (*qfn2(fn))(qenv(fn), v61, v466);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v466 = v61;
    if (v61 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v61 = stack[-4];
    fn = elt(env, 6); /* gsetsugar */
    v466 = (*qfn2(fn))(qenv(fn), v61, v466);
    nil = C_nil;
    if (exception_pending()) goto v70;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v348:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v466 = qvalue(elt(env, 2)); /* nil */
    stack[0] = ncons(v466);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v61 = qvalue(elt(env, 2)); /* nil */
    v466 = qvalue(elt(env, 2)); /* nil */
    v466 = list2(v61, v466);
    nil = C_nil;
    if (exception_pending()) goto v70;
    {
        Lisp_Object v93 = stack[-2];
        Lisp_Object v17 = stack[-1];
        Lisp_Object v341 = stack[0];
        popv(6);
        return list3star(v93, v17, v341, v466);
    }
/* error exit handlers */
v70:
    popv(6);
    return nil;
}



/* Code for freeoffl */

static Lisp_Object CC_freeoffl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeoffl");
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

v455:
    v78 = stack[0];
    if (v78 == nil) goto v84;
    v46 = stack[-1];
    v78 = stack[0];
    v78 = qcar(v78);
    fn = elt(env, 3); /* freeoff */
    v78 = (*qfn2(fn))(qenv(fn), v46, v78);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    if (v78 == nil) goto v81;
    v46 = stack[-1];
    v78 = stack[0];
    v78 = qcdr(v78);
    stack[-1] = v46;
    stack[0] = v78;
    goto v455;

v81:
    v78 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v78); }

v84:
    v78 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v78); }
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for triviallcm */

static Lisp_Object MS_CDECL CC_triviallcm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v348, v349;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "triviallcm");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for triviallcm");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v40;
    v349 = v1;
    v348 = v0;
/* end of prologue */
    fn = elt(env, 1); /* xdiv */
    v349 = (*qfn2(fn))(qenv(fn), v349, v348);
    nil = C_nil;
    if (exception_pending()) goto v42;
    v348 = stack[0];
    v348 = (equal(v349, v348) ? lisp_true : nil);
    { popv(1); return onevalue(v348); }
/* error exit handlers */
v42:
    popv(1);
    return nil;
}



/* Code for listeval */

static Lisp_Object CC_listeval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v328, v318;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listeval");
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
    stack[-4] = v1;
    stack[0] = v0;
/* end of prologue */
    v39 = qvalue(elt(env, 1)); /* simpcount!* */
    v328 = add1(v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    qvalue(elt(env, 1)) = v328; /* simpcount!* */
    v39 = qvalue(elt(env, 2)); /* simplimit!* */
    v39 = (Lisp_Object)greaterp2(v328, v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    v39 = v39 ? lisp_true : nil;
    env = stack[-6];
    if (v39 == nil) goto v119;
    v39 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v39; /* simpcount!* */
    v39 = elt(env, 3); /* "Simplification recursion too deep" */
    v328 = v39;
    v39 = v328;
    qvalue(elt(env, 4)) = v39; /* errmsg!* */
    v39 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v39 == nil)) goto v86;
    v39 = v328;
    fn = elt(env, 12); /* lprie */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    goto v86;

v86:
    v39 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    goto v119;

v119:
    v39 = stack[0];
    if (!consp(v39)) goto v78;
    v39 = stack[0];
    v328 = qcar(v39);
    v39 = elt(env, 8); /* list */
    if (v328 == v39) goto v479;
    v39 = stack[0];
    v328 = qcar(v39);
    v39 = elt(env, 10); /* listfn */
    v39 = get(v328, v39);
    env = stack[-6];
    v328 = v39;
    v39 = v328;
    if (v39 == nil) goto v480;
    v318 = v328;
    v39 = stack[0];
    v328 = qcdr(v39);
    v39 = stack[-4];
    v39 = Lapply2(nil, 3, v318, v328, v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    goto v446;

v446:
    stack[0] = v39;
    v39 = qvalue(elt(env, 1)); /* simpcount!* */
    v39 = sub1(v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    qvalue(elt(env, 1)) = v39; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v480:
    v39 = elt(env, 11); /* "Illegal operation on lists" */
    v328 = v39;
    v39 = v328;
    qvalue(elt(env, 4)) = v39; /* errmsg!* */
    v39 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v39 == nil)) goto v317;
    v39 = v328;
    fn = elt(env, 12); /* lprie */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    goto v317;

v317:
    v39 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    v39 = nil;
    goto v446;

v479:
    stack[-5] = elt(env, 8); /* list */
    v39 = stack[0];
    v39 = qcdr(v39);
    stack[-3] = v39;
    v39 = stack[-3];
    if (v39 == nil) goto v481;
    v39 = stack[-3];
    v39 = qcar(v39);
    v328 = v39;
    v39 = stack[-4];
    fn = elt(env, 13); /* reval1 */
    v39 = (*qfn2(fn))(qenv(fn), v328, v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    stack[-1] = v39;
    stack[-2] = v39;
    goto v482;

v482:
    v39 = stack[-3];
    v39 = qcdr(v39);
    stack[-3] = v39;
    v39 = stack[-3];
    if (v39 == nil) goto v338;
    stack[0] = stack[-1];
    v39 = stack[-3];
    v39 = qcar(v39);
    v328 = v39;
    v39 = stack[-4];
    fn = elt(env, 13); /* reval1 */
    v39 = (*qfn2(fn))(qenv(fn), v328, v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    v39 = ncons(v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    v39 = Lrplacd(nil, stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[-1] = v39;
    goto v482;

v338:
    v39 = stack[-2];
    goto v70;

v70:
    v39 = cons(stack[-5], v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    goto v446;

v481:
    v39 = qvalue(elt(env, 9)); /* nil */
    goto v70;

v78:
    v328 = stack[0];
    v39 = elt(env, 6); /* avalue */
    v39 = get(v328, v39);
    env = stack[-6];
    v318 = v39;
    v328 = stack[0];
    v39 = elt(env, 7); /* share */
    v39 = Lflagp(nil, v328, v39);
    env = stack[-6];
    if (v39 == nil) goto v25;
    v39 = stack[0];
    fn = elt(env, 14); /* eval */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    v328 = v39;
    goto v66;

v66:
    v39 = stack[-4];
    v39 = CC_listeval(env, v328, v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    goto v446;

v25:
    v39 = v318;
    if (v39 == nil) goto v464;
    v39 = v318;
    v39 = qcdr(v39);
    v39 = qcar(v39);
    v328 = v39;
    goto v66;

v464:
    v328 = stack[0];
    v39 = elt(env, 8); /* list */
    fn = elt(env, 15); /* typerr */
    v39 = (*qfn2(fn))(qenv(fn), v328, v39);
    nil = C_nil;
    if (exception_pending()) goto v478;
    env = stack[-6];
    v328 = v39;
    goto v66;
/* error exit handlers */
v478:
    popv(7);
    return nil;
}



/* Code for indord2 */

static Lisp_Object CC_indord2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indord2");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v44 = stack[-1];
    v43 = stack[0];
    fn = elt(env, 1); /* indordp */
    v43 = (*qfn2(fn))(qenv(fn), v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v46;
    if (v43 == nil) goto v458;
    v44 = stack[-1];
    v43 = stack[0];
    popv(2);
    return list2(v44, v43);

v458:
    v44 = stack[0];
    v43 = stack[-1];
    popv(2);
    return list2(v44, v43);
/* error exit handlers */
v46:
    popv(2);
    return nil;
}



/* Code for my_freeof */

static Lisp_Object CC_my_freeof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v33, v446;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my_freeof");
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
    v33 = stack[0];
    v34 = stack[-1];
    fn = elt(env, 3); /* smember */
    v34 = (*qfn2(fn))(qenv(fn), v33, v34);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    if (v34 == nil) goto v6;
    v34 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v34); }

v6:
    v446 = qvalue(elt(env, 1)); /* depl!* */
    v33 = stack[-1];
    v34 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeofdepl */
        return (*qfnn(fn))(qenv(fn), 3, v446, v33, v34);
    }
/* error exit handlers */
v44:
    popv(3);
    return nil;
}



/* Code for map__edges */

static Lisp_Object CC_map__edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for map__edges");
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
    goto v30;

v30:
    v75 = stack[0];
    if (v75 == nil) goto v101;
    v75 = stack[0];
    v76 = qcar(v75);
    v75 = stack[-1];
    v75 = cons(v76, v75);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    stack[-1] = v75;
    v75 = stack[0];
    v75 = qcdr(v75);
    stack[0] = v75;
    goto v30;

v101:
    v75 = qvalue(elt(env, 1)); /* nil */
    v76 = v75;
    goto v106;

v106:
    v75 = stack[-1];
    if (v75 == nil) { popv(3); return onevalue(v76); }
    v75 = stack[-1];
    v75 = qcar(v75);
    fn = elt(env, 2); /* union_edges */
    v75 = (*qfn2(fn))(qenv(fn), v75, v76);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-2];
    v76 = v75;
    v75 = stack[-1];
    v75 = qcdr(v75);
    stack[-1] = v75;
    goto v106;
/* error exit handlers */
v66:
    popv(3);
    return nil;
}



/* Code for sfpx1 */

static Lisp_Object MS_CDECL CC_sfpx1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, Lisp_Object v27, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v494, v495, v415, v496;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "sfpx1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfpx1");
#endif
    if (stack >= stacklimit)
    {
        push4(v27,v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v40,v27);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v27;
    stack[-4] = v40;
    stack[-5] = v1;
    v415 = v0;
/* end of prologue */

v455:
    v494 = v415;
    if (!consp(v494)) goto v42;
    v494 = v415;
    v494 = qcar(v494);
    v494 = (consp(v494) ? nil : lisp_true);
    goto v41;

v41:
    if (v494 == nil) goto v73;
    v494 = qvalue(elt(env, 1)); /* t */
    { popv(8); return onevalue(v494); }

v73:
    v494 = v415;
    v494 = Lconsp(nil, v494);
    env = stack[-7];
    if (v494 == nil) goto v44;
    v494 = v415;
    v494 = qcar(v494);
    v495 = v415;
    v495 = qcdr(v495);
    stack[-2] = v495;
    v495 = v494;
    v495 = Lconsp(nil, v495);
    env = stack[-7];
    if (v495 == nil) goto v59;
    v495 = v494;
    v495 = qcdr(v495);
    stack[-6] = v495;
    v494 = qcar(v494);
    stack[0] = v494;
    v494 = stack[0];
    v494 = Lconsp(nil, v494);
    env = stack[-7];
    if (v494 == nil) goto v49;
    v494 = stack[0];
    v494 = qcar(v494);
    stack[-1] = v494;
    v494 = stack[-1];
    fn = elt(env, 3); /* assert_kernelp */
    v494 = (*qfn1(fn))(qenv(fn), v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    if (v494 == nil) goto v343;
    v494 = stack[0];
    v494 = qcdr(v494);
    stack[0] = v494;
    v495 = stack[-1];
    v494 = stack[-4];
    if (v495 == v494) goto v466;
    v494 = stack[-4];
    if (v494 == nil) goto v497;
    v495 = stack[-4];
    v494 = stack[-5];
    v494 = cons(v495, v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    stack[-5] = v494;
    goto v497;

v497:
    v494 = stack[-5];
    if (v494 == nil) goto v498;
    v495 = stack[-1];
    v494 = (Lisp_Object)17; /* 1 */
    stack[-3] = cons(v495, v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    v494 = stack[-5];
    v495 = qcar(v494);
    v494 = (Lisp_Object)17; /* 1 */
    v494 = cons(v495, v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    fn = elt(env, 4); /* ordpp */
    v494 = (*qfn2(fn))(qenv(fn), stack[-3], v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    if (v494 == nil) goto v498;
    v494 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v494); }

v498:
    stack[-3] = stack[-6];
    v495 = stack[-1];
    v494 = stack[-5];
    v415 = cons(v495, v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    v495 = qvalue(elt(env, 2)); /* nil */
    v494 = (Lisp_Object)1; /* 0 */
    v494 = CC_sfpx1(env, 4, stack[-3], v415, v495, v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    if (v494 == nil) goto v499;
    v415 = stack[-2];
    v496 = stack[-5];
    v495 = stack[-1];
    v494 = stack[0];
    stack[-5] = v496;
    stack[-4] = v495;
    stack[-3] = v494;
    goto v455;

v499:
    v494 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v494); }

v466:
    v495 = stack[0];
    v494 = stack[-3];
    v494 = (Lisp_Object)lessp2(v495, v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    v494 = v494 ? lisp_true : nil;
    env = stack[-7];
    if (v494 == nil) goto v36;
    stack[-1] = stack[-6];
    v495 = stack[-4];
    v494 = stack[-5];
    v415 = cons(v495, v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    v495 = qvalue(elt(env, 2)); /* nil */
    v494 = (Lisp_Object)1; /* 0 */
    v494 = CC_sfpx1(env, 4, stack[-1], v415, v495, v494);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-7];
    if (v494 == nil) goto v477;
    v415 = stack[-2];
    v496 = stack[-5];
    v495 = stack[-4];
    v494 = stack[0];
    stack[-5] = v496;
    stack[-4] = v495;
    stack[-3] = v494;
    goto v455;

v477:
    v494 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v494); }

v36:
    v494 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v494); }

v343:
    v494 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v494); }

v49:
    v494 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v494); }

v59:
    v494 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v494); }

v44:
    v494 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v494); }

v42:
    v494 = qvalue(elt(env, 1)); /* t */
    goto v41;
/* error exit handlers */
v5:
    popv(8);
    return nil;
}



/* Code for mo_neworder */

static Lisp_Object CC_mo_neworder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neworder");
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
    v52 = v0;
/* end of prologue */
    v52 = qcar(v52);
    fn = elt(env, 1); /* mo!=shorten */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    stack[0] = v52;
    fn = elt(env, 2); /* mo!=deglist */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v73;
    {
        Lisp_Object v74 = stack[0];
        popv(2);
        return cons(v74, v52);
    }
/* error exit handlers */
v73:
    popv(2);
    return nil;
}



/* Code for pv_times1 */

static Lisp_Object MS_CDECL CC_pv_times1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v40, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v446, v60, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pv_times1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times1");
#endif
    if (stack >= stacklimit)
    {
        push3(v40,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v40);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v60 = v40;
    stack[0] = v1;
    v446 = v0;
/* end of prologue */

v101:
    v43 = v446;
    if (v43 == nil) { popv(3); return onevalue(v60); }
    v43 = v446;
    v43 = qcdr(v43);
    stack[-1] = v43;
    v43 = qcar(v446);
    v446 = stack[0];
    fn = elt(env, 1); /* pv_times2 */
    v446 = (*qfnn(fn))(qenv(fn), 3, v43, v446, v60);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-2];
    v60 = v446;
    v446 = stack[-1];
    goto v101;
/* error exit handlers */
v78:
    popv(3);
    return nil;
}



/* Code for rootrnd */

static Lisp_Object CC_rootrnd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootrnd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v102 = v31;
    v31 = qvalue(elt(env, 1)); /* acc!# */
    {
        fn = elt(env, 2); /* rtrnda */
        return (*qfn2(fn))(qenv(fn), v102, v31);
    }
}



/* Code for quotient!-mod!-p */

static Lisp_Object CC_quotientKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v497, v476;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotient-mod-p");
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
    v14 = stack[-1];
    if (v14 == nil) goto v84;
    v14 = stack[-1];
    if (!consp(v14)) goto v82;
    v14 = stack[-1];
    v14 = qcar(v14);
    v14 = (consp(v14) ? nil : lisp_true);
    goto v81;

v81:
    if (v14 == nil) goto v102;
    v14 = stack[-1];
    fn = elt(env, 5); /* safe!-modular!-reciprocal */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-4];
    v497 = stack[-1];
    if (v497 == nil) goto v33;
    v497 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v497, v14);
    }

v33:
    v14 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v14; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v14); }

v102:
    v14 = stack[-2];
    if (v14 == nil) goto v76;
    v14 = stack[-2];
    if (!consp(v14)) goto v24;
    v14 = stack[-2];
    v14 = qcar(v14);
    v14 = (consp(v14) ? nil : lisp_true);
    goto v448;

v448:
    if (v14 == nil) goto v58;
    v14 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v14; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v14); }

v58:
    v14 = stack[-2];
    v14 = qcar(v14);
    v14 = qcar(v14);
    v497 = qcar(v14);
    v14 = stack[-1];
    v14 = qcar(v14);
    v14 = qcar(v14);
    v14 = qcar(v14);
    if (equal(v497, v14)) goto v22;
    v14 = stack[-2];
    v14 = qcar(v14);
    v14 = qcar(v14);
    v497 = qcar(v14);
    v14 = stack[-1];
    v14 = qcar(v14);
    v14 = qcar(v14);
    v14 = qcar(v14);
    fn = elt(env, 7); /* ordop */
    v14 = (*qfn2(fn))(qenv(fn), v497, v14);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-4];
    if (v14 == nil) goto v336;
    v14 = stack[-2];
    v14 = qcar(v14);
    stack[-3] = qcar(v14);
    v14 = stack[-2];
    v14 = qcar(v14);
    v497 = qcdr(v14);
    v14 = stack[-1];
    stack[0] = CC_quotientKmodKp(env, v497, v14);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-4];
    v14 = stack[-2];
    v497 = qcdr(v14);
    v14 = stack[-1];
    v14 = CC_quotientKmodKp(env, v497, v14);
    nil = C_nil;
    if (exception_pending()) goto v407;
    env = stack[-4];
    {
        Lisp_Object v503 = stack[-3];
        Lisp_Object v474 = stack[0];
        popv(5);
        fn = elt(env, 8); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v503, v474, v14);
    }

v336:
    v14 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v14; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v14); }

v22:
    v476 = stack[-2];
    v497 = stack[-1];
    v14 = stack[-1];
    v14 = qcar(v14);
    v14 = qcar(v14);
    v14 = qcar(v14);
    {
        popv(5);
        fn = elt(env, 9); /* xquotient!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 3, v476, v497, v14);
    }

v24:
    v14 = qvalue(elt(env, 2)); /* t */
    goto v448;

v76:
    v14 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v14); }

v82:
    v14 = qvalue(elt(env, 2)); /* t */
    goto v81;

v84:
    v14 = elt(env, 1); /* "B=0 IN QUOTIENT-MOD-P" */
    {
        popv(5);
        fn = elt(env, 10); /* errorf */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v407:
    popv(5);
    return nil;
}



/* Code for mml2om */

static Lisp_Object MS_CDECL CC_mml2om(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mml2om");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mml2om");
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
    fn = elt(env, 3); /* mml2ir */
    v52 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    stack[0] = v52;
    v52 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    v52 = elt(env, 2); /* "Intermediate representation: " */
    v52 = Lprinc(nil, v52);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    v52 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    v52 = stack[0];
    v52 = Lprint(nil, v52);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    v52 = stack[0];
    fn = elt(env, 5); /* ir2om */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v73;
    v52 = nil;
    { popv(2); return onevalue(v52); }
/* error exit handlers */
v73:
    popv(2);
    return nil;
}



/* Code for vevlcm */

static Lisp_Object CC_vevlcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v342, v56, v21;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevlcm");
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
    v21 = nil;
    goto v106;

v106:
    v342 = stack[-1];
    if (v342 == nil) goto v101;
    v342 = stack[0];
    if (v342 == nil) goto v101;
    v342 = stack[-1];
    v56 = qcar(v342);
    v342 = stack[0];
    v342 = qcar(v342);
    if (((int32_t)(v56)) > ((int32_t)(v342))) goto v458;
    v342 = stack[0];
    v342 = qcar(v342);
    goto v41;

v41:
    v56 = v21;
    v342 = cons(v342, v56);
    nil = C_nil;
    if (exception_pending()) goto v451;
    env = stack[-2];
    v21 = v342;
    v342 = stack[-1];
    v342 = qcdr(v342);
    stack[-1] = v342;
    v342 = stack[0];
    v342 = qcdr(v342);
    stack[0] = v342;
    goto v106;

v458:
    v342 = stack[-1];
    v342 = qcar(v342);
    goto v41;

v101:
    v342 = v21;
    v342 = Lnreverse(nil, v342);
    env = stack[-2];
    v21 = v342;
    v342 = stack[-1];
    if (v342 == nil) goto v25;
    v56 = v21;
    v342 = stack[-1];
    v342 = Lnconc(nil, v56, v342);
    nil = C_nil;
    if (exception_pending()) goto v451;
    v21 = v342;
    { popv(3); return onevalue(v21); }

v25:
    v342 = stack[0];
    if (v342 == nil) { popv(3); return onevalue(v21); }
    v56 = v21;
    v342 = stack[0];
    v342 = Lnconc(nil, v56, v342);
    nil = C_nil;
    if (exception_pending()) goto v451;
    v21 = v342;
    { popv(3); return onevalue(v21); }
/* error exit handlers */
v451:
    popv(3);
    return nil;
}



/* Code for oprinla */

static Lisp_Object CC_oprinla(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v457, v465, v448;
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
    v465 = v0;
/* end of prologue */
    v448 = v465;
    v457 = elt(env, 1); /* lapr */
    v457 = get(v448, v457);
    env = stack[0];
    v448 = v457;
    if (v457 == nil) goto v42;
    v457 = v448;
    fn = elt(env, 5); /* prin2la */
    v457 = (*qfn1(fn))(qenv(fn), v457);
    nil = C_nil;
    if (exception_pending()) goto v24;
    goto v30;

v30:
    v457 = nil;
    { popv(1); return onevalue(v457); }

v42:
    v448 = v465;
    v457 = elt(env, 2); /* prtch */
    v457 = get(v448, v457);
    env = stack[0];
    v448 = v457;
    if (v457 == nil) goto v44;
    v457 = v448;
    fn = elt(env, 5); /* prin2la */
    v457 = (*qfn1(fn))(qenv(fn), v457);
    nil = C_nil;
    if (exception_pending()) goto v24;
    goto v30;

v44:
    v448 = v465;
    v457 = elt(env, 3); /* lapop */
    v457 = get(v448, v457);
    env = stack[0];
    v448 = v457;
    if (v457 == nil) goto v59;
    v457 = v448;
    fn = elt(env, 5); /* prin2la */
    v457 = (*qfn1(fn))(qenv(fn), v457);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[0];
    v457 = elt(env, 4); /* !  */
    fn = elt(env, 5); /* prin2la */
    v457 = (*qfn1(fn))(qenv(fn), v457);
    nil = C_nil;
    if (exception_pending()) goto v24;
    goto v30;

v59:
    v457 = v465;
    fn = elt(env, 6); /* prinlatom */
    v457 = (*qfn1(fn))(qenv(fn), v457);
    nil = C_nil;
    if (exception_pending()) goto v24;
    goto v30;
/* error exit handlers */
v24:
    popv(1);
    return nil;
}



/* Code for fortexp */

static Lisp_Object CC_fortexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v102 = v31;
    v31 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* fortexp1 */
        return (*qfn2(fn))(qenv(fn), v102, v31);
    }
}



setup_type const u14_setup[] =
{
    {"ibalp_var-satlist",       too_few_2,      CC_ibalp_varKsatlist,wrong_no_2},
    {"quotfail1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_quotfail1},
    {"variableom",              CC_variableom,  too_many_1,    wrong_no_1},
    {"bcquot",                  too_few_2,      CC_bcquot,     wrong_no_2},
    {"bcneg",                   CC_bcneg,       too_many_1,    wrong_no_1},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"delete-dups",             CC_deleteKdups, too_many_1,    wrong_no_1},
    {"cut:mt",                  too_few_2,      CC_cutTmt,     wrong_no_2},
    {"xread1",                  CC_xread1,      too_many_1,    wrong_no_1},
    {"mv-domainlist-*",         too_few_2,      CC_mvKdomainlistKH,wrong_no_2},
    {"groeb=better",            too_few_2,      CC_groebMbetter,wrong_no_2},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"next-random-number",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nextKrandomKnumber},
    {"general-reduce-mod-p",    CC_generalKreduceKmodKp,too_many_1,wrong_no_1},
    {"nonlnrsys",               too_few_2,      CC_nonlnrsys,  wrong_no_2},
    {"crprcd",                  CC_crprcd,      too_many_1,    wrong_no_1},
    {"polynommultiplybyvariable",too_few_2,     CC_polynommultiplybyvariable,wrong_no_2},
    {"exptf",                   too_few_2,      CC_exptf,      wrong_no_2},
    {"cl_susiupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiupdknowl},
    {"tobvarir",                CC_tobvarir,    too_many_1,    wrong_no_1},
    {"bc2a",                    CC_bc2a,        too_many_1,    wrong_no_1},
    {"listdiff",                too_few_2,      CC_listdiff,   wrong_no_2},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"repasc",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_repasc},
    {"formsetq",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq},
    {"th_match",                too_few_2,      CC_th_match,   wrong_no_2},
    {"general-expt-mod-p",      too_few_2,      CC_generalKexptKmodKp,wrong_no_2},
    {"simpqg",                  CC_simpqg,      too_many_1,    wrong_no_1},
    {"revalx",                  CC_revalx,      too_many_1,    wrong_no_1},
    {"setunion",                too_few_2,      CC_setunion,   wrong_no_2},
    {"vdp_zero?",               CC_vdp_zeroW,   too_many_1,    wrong_no_1},
    {"vdpred",                  CC_vdpred,      too_many_1,    wrong_no_1},
    {"freeoffl",                too_few_2,      CC_freeoffl,   wrong_no_2},
    {"triviallcm",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_triviallcm},
    {"listeval",                too_few_2,      CC_listeval,   wrong_no_2},
    {"indord2",                 too_few_2,      CC_indord2,    wrong_no_2},
    {"my_freeof",               too_few_2,      CC_my_freeof,  wrong_no_2},
    {"map__edges",              CC_map__edges,  too_many_1,    wrong_no_1},
    {"sfpx1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sfpx1},
    {"mo_neworder",             CC_mo_neworder, too_many_1,    wrong_no_1},
    {"pv_times1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pv_times1},
    {"rootrnd",                 CC_rootrnd,     too_many_1,    wrong_no_1},
    {"quotient-mod-p",          too_few_2,      CC_quotientKmodKp,wrong_no_2},
    {"mml2om",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mml2om},
    {"vevlcm",                  too_few_2,      CC_vevlcm,     wrong_no_2},
    {"oprinla",                 CC_oprinla,     too_many_1,    wrong_no_1},
    {"fortexp",                 CC_fortexp,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u14", (two_args *)"1776 7626442 3204608", 0}
};

/* end of generated code */
