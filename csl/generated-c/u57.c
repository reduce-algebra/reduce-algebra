
/* $destdir\u57.c        Machine generated C code */

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


/* Code for install!-patches */

static Lisp_Object CC_installKpatches(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for install-patches");
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
    v9 = v0;
/* end of prologue */
    v10 = v9;
    v8 = elt(env, 1); /* patches */
    if (v10 == v8) goto v11;
    v8 = elt(env, 3); /* patchfn */
    v8 = get(v9, v8);
    env = stack[-2];
    v9 = v8;
    if (v8 == nil) goto v12;
    stack[-1] = qvalue(elt(env, 4)); /* !*usermode */
    qvalue(elt(env, 4)) = nil; /* !*usermode */
    stack[0] = qvalue(elt(env, 5)); /* !*redefmsg */
    qvalue(elt(env, 5)) = nil; /* !*redefmsg */
    v8 = v9;
    v8 = ncons(v8);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    fn = elt(env, 6); /* eval */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    v8 = nil;
    qvalue(elt(env, 5)) = stack[0]; /* !*redefmsg */
    qvalue(elt(env, 4)) = stack[-1]; /* !*usermode */
    { popv(3); return onevalue(v8); }

v12:
    v8 = nil;
    { popv(3); return onevalue(v8); }

v11:
    v8 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v8); }
/* error exit handlers */
v13:
    env = stack[-2];
    qvalue(elt(env, 5)) = stack[0]; /* !*redefmsg */
    qvalue(elt(env, 4)) = stack[-1]; /* !*usermode */
    popv(3);
    return nil;
}



/* Code for rd!:quotient */

static Lisp_Object CC_rdTquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:quotient");
#endif
    if (stack >= stacklimit)
    {
        push2(v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v14;
    stack[-1] = v0;
/* end of prologue */
    v61 = stack[0];
    fn = elt(env, 13); /* !:zerop */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    if (v61 == nil) goto v4;
    v61 = elt(env, 1); /* "division by zero" */
    v62 = v61;
    v61 = v62;
    qvalue(elt(env, 2)) = v61; /* errmsg!* */
    v61 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v61 == nil)) goto v12;
    v61 = v62;
    fn = elt(env, 14); /* lprie */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v12;

v12:
    v61 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v61 = nil;
    { popv(5); return onevalue(v61); }

v4:
    v61 = qvalue(elt(env, 4)); /* nil */
    v62 = v61;
    v61 = qvalue(elt(env, 5)); /* !*!*roundbf */
    if (v61 == nil) goto v9;
    v61 = qvalue(elt(env, 4)); /* nil */
    goto v8;

v8:
    if (v61 == nil) goto v65;
    v61 = elt(env, 6); /* !:rd!: */
    popv(5);
    return cons(v61, v62);

v65:
    v62 = stack[-1];
    v61 = stack[0];
    fn = elt(env, 15); /* convprc2 */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    stack[-3] = v61;
    v61 = qvalue(elt(env, 7)); /* yy!! */
    stack[-2] = v61;
    v61 = stack[-3];
    if (!consp(v61)) goto v66;
    v61 = qvalue(elt(env, 4)); /* nil */
    goto v67;

v67:
    if (v61 == nil) goto v68;
    v62 = (Lisp_Object)1; /* 0 */
    v61 = elt(env, 8); /* "zero divisor in quotient" */
    fn = elt(env, 16); /* error */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v68;

v68:
    v61 = stack[-3];
    if (!consp(v61)) goto v69;
    v61 = stack[-2];
    v61 = qcdr(v61);
    v62 = qcar(v61);
    v61 = (Lisp_Object)1; /* 0 */
    if (v62 == v61) goto v70;
    v63 = stack[-3];
    v62 = stack[-2];
    v61 = qvalue(elt(env, 9)); /* !:bprec!: */
    fn = elt(env, 17); /* divide!: */
    v61 = (*qfnn(fn))(qenv(fn), 3, v63, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    fn = elt(env, 18); /* csl_normbf */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v71;

v71:
    v62 = v61;
    v61 = v62;
    if (!(!consp(v61))) { popv(5); return onevalue(v62); }
    v61 = elt(env, 6); /* !:rd!: */
    popv(5);
    return cons(v61, v62);

v70:
    v62 = (Lisp_Object)1; /* 0 */
    v61 = elt(env, 8); /* "zero divisor in quotient" */
    fn = elt(env, 16); /* error */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v71;

v69:
    stack[-1] = elt(env, 10); /* quotient */
    v61 = stack[-3];
    stack[0] = Lmkquote(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v61 = stack[-2];
    v61 = Lmkquote(nil, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v63 = list3(stack[-1], stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v62 = qvalue(elt(env, 4)); /* nil */
    v61 = qvalue(elt(env, 11)); /* !*backtrace */
    fn = elt(env, 19); /* errorset */
    v61 = (*qfnn(fn))(qenv(fn), 3, v63, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v62 = v61;
    v61 = v62;
    if (!consp(v61)) goto v72;
    v61 = v62;
    v61 = qcdr(v61);
    goto v73;

v73:
    if (v61 == nil) goto v74;
    fn = elt(env, 20); /* rndbfon */
    v61 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v61 = stack[-3];
    v61 = Lfloatp(nil, v61);
    env = stack[-4];
    if (v61 == nil) goto v75;
    v61 = stack[-3];
    fn = elt(env, 21); /* fl2bf */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    stack[0] = v61;
    goto v76;

v76:
    v61 = stack[-2];
    v61 = Lfloatp(nil, v61);
    env = stack[-4];
    if (v61 == nil) goto v77;
    v61 = stack[-2];
    fn = elt(env, 21); /* fl2bf */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v62 = v61;
    goto v78;

v78:
    v61 = qvalue(elt(env, 9)); /* !:bprec!: */
    fn = elt(env, 17); /* divide!: */
    v61 = (*qfnn(fn))(qenv(fn), 3, stack[0], v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    fn = elt(env, 18); /* csl_normbf */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v71;

v77:
    v61 = stack[-2];
    if (!consp(v61)) goto v79;
    v61 = stack[-2];
    goto v80;

v80:
    fn = elt(env, 18); /* csl_normbf */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v62 = v61;
    goto v78;

v79:
    v61 = stack[-2];
    v61 = integerp(v61);
    if (v61 == nil) goto v81;
    v63 = elt(env, 6); /* !:rd!: */
    v62 = stack[-2];
    v61 = (Lisp_Object)1; /* 0 */
    v61 = list2star(v63, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v80;

v81:
    v61 = stack[-2];
    fn = elt(env, 22); /* read!:num */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v80;

v75:
    v61 = stack[-3];
    if (!consp(v61)) goto v82;
    v61 = stack[-3];
    goto v83;

v83:
    fn = elt(env, 18); /* csl_normbf */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    stack[0] = v61;
    goto v76;

v82:
    v61 = stack[-3];
    v61 = integerp(v61);
    if (v61 == nil) goto v84;
    v63 = elt(env, 6); /* !:rd!: */
    v62 = stack[-3];
    v61 = (Lisp_Object)1; /* 0 */
    v61 = list2star(v63, v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v83;

v84:
    v61 = stack[-3];
    fn = elt(env, 22); /* read!:num */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    goto v83;

v74:
    v61 = v62;
    v61 = qcar(v61);
    goto v71;

v72:
    v61 = qvalue(elt(env, 12)); /* t */
    goto v73;

v66:
    v61 = stack[-2];
    v61 = (Lisp_Object)zerop(v61);
    v61 = v61 ? lisp_true : nil;
    env = stack[-4];
    goto v67;

v9:
    v61 = stack[-1];
    v61 = qcdr(v61);
    if (!consp(v61)) goto v85;
    v61 = qvalue(elt(env, 4)); /* nil */
    goto v8;

v85:
    v61 = stack[0];
    v61 = qcdr(v61);
    if (!consp(v61)) goto v86;
    v61 = qvalue(elt(env, 4)); /* nil */
    goto v8;

v86:
    v61 = stack[-1];
    v62 = qcdr(v61);
    v61 = stack[0];
    v61 = qcdr(v61);
    fn = elt(env, 23); /* safe!-fp!-quot */
    v61 = (*qfn2(fn))(qenv(fn), v62, v61);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-4];
    v62 = v61;
    goto v8;
/* error exit handlers */
v64:
    popv(5);
    return nil;
}



/* Code for partitindexvar */

static Lisp_Object CC_partitindexvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v242, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitindexvar");
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
    v241 = stack[-7];
    v241 = qcdr(v241);
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v4;
    v241 = stack[-4];
    v241 = qcar(v241);
    fn = elt(env, 7); /* revalind */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v242 = v241;
    v241 = v242;
    if (!consp(v241)) goto v56;
    v241 = v242;
    v241 = qcdr(v241);
    v241 = qcar(v241);
    if (is_number(v241)) goto v54;
    v241 = v242;
    goto v245;

v245:
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-2] = v241;
    stack[-3] = v241;
    goto v246;

v246:
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v247;
    stack[-1] = stack[-2];
    v241 = stack[-4];
    v241 = qcar(v241);
    fn = elt(env, 7); /* revalind */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v242 = v241;
    v241 = v242;
    if (!consp(v241)) goto v48;
    v241 = v242;
    v241 = qcdr(v241);
    v241 = qcar(v241);
    if (is_number(v241)) goto v248;
    v241 = v242;
    goto v249;

v249:
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = Lrplacd(nil, stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-2];
    v241 = qcdr(v241);
    stack[-2] = v241;
    goto v246;

v248:
    stack[0] = elt(env, 2); /* minus */
    v241 = v242;
    v241 = qcdr(v241);
    v241 = qcar(v241);
    fn = elt(env, 8); /* !*num2id */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = list2(stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v249;

v48:
    v241 = v242;
    if (is_number(v241)) goto v250;
    v241 = v242;
    goto v249;

v250:
    v241 = v242;
    v241 = Lminusp(nil, v241);
    env = stack[-9];
    if (v241 == nil) goto v251;
    stack[0] = elt(env, 2); /* minus */
    v241 = v242;
    v241 = Labsval(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    fn = elt(env, 8); /* !*num2id */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = list2(stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v249;

v251:
    v241 = v242;
    fn = elt(env, 8); /* !*num2id */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v249;

v247:
    v241 = stack[-3];
    goto v252;

v252:
    stack[0] = v241;
    v241 = stack[-7];
    fn = elt(env, 9); /* deg!*form */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-3] = v241;
    v241 = qvalue(elt(env, 3)); /* metricu!* */
    if (v241 == nil) goto v7;
    v241 = stack[0];
    stack[-2] = v241;
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = elt(env, 4); /* covariant */
    v241 = Lflagp(nil, v242, v241);
    env = stack[-9];
    if (!(v241 == nil)) goto v253;

v254:
    v241 = stack[-2];
    if (v241 == nil) goto v255;
    v241 = stack[-2];
    v241 = qcar(v241);
    if (!consp(v241)) goto v256;
    v241 = stack[-2];
    v241 = qcar(v241);
    v241 = qcdr(v241);
    v242 = qcar(v241);
    v241 = qvalue(elt(env, 3)); /* metricu!* */
    v241 = Latsoc(nil, v242, v241);
    v241 = (v241 == nil ? lisp_true : nil);
    goto v257;

v257:
    if (v241 == nil) goto v255;
    v241 = stack[-2];
    v242 = qcar(v241);
    v241 = stack[-6];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-6] = v241;
    v241 = stack[-2];
    v241 = qcar(v241);
    if (!consp(v241)) goto v258;
    v241 = stack[-2];
    v241 = qcar(v241);
    v241 = qcdr(v241);
    v242 = qcar(v241);
    v241 = stack[-8];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-8] = v241;
    goto v258;

v258:
    v241 = stack[-2];
    v241 = qcdr(v241);
    stack[-2] = v241;
    goto v254;

v255:
    v241 = stack[-2];
    if (v241 == nil) goto v7;
    v241 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v241;
    v241 = stack[-6];
    v241 = Lreverse(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-6] = v241;
    v241 = stack[-2];
    v241 = qcar(v241);
    v241 = qcdr(v241);
    v241 = qcar(v241);
    fn = elt(env, 10); /* getlower */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-4] = v241;
    goto v259;

v259:
    v241 = stack[-4];
    if (v241 == nil) { Lisp_Object res = stack[-5]; popv(10); return onevalue(res); }
    v241 = stack[-4];
    v241 = qcar(v241);
    stack[-3] = v241;
    v241 = stack[-7];
    stack[-1] = qcar(v241);
    stack[0] = stack[-6];
    v241 = stack[-3];
    v242 = qcar(v241);
    v241 = stack[-2];
    v241 = qcdr(v241);
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = Lappend(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = cons(stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[0] = CC_partitindexvar(env, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-3];
    v241 = qcdr(v241);
    fn = elt(env, 11); /* simp */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    fn = elt(env, 12); /* multpfsq */
    v242 = (*qfn2(fn))(qenv(fn), stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-5];
    fn = elt(env, 13); /* addpf */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-5] = v241;
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    goto v259;

v7:
    v241 = stack[0];
    fn = elt(env, 14); /* coposp */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    if (v241 == nil) goto v260;
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = elt(env, 6); /* indxsymmetries */
    v241 = get(v242, v241);
    env = stack[-9];
    v241 = (v241 == nil ? lisp_true : nil);
    goto v261;

v261:
    if (v241 == nil) goto v262;
    v241 = stack[-3];
    if (v241 == nil) goto v263;
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = stack[0];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    {
        popv(10);
        fn = elt(env, 15); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v241);
    }

v263:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = stack[0];
    v242 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksq */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = cons(stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    popv(10);
    return ncons(v241);

v262:
    v241 = stack[0];
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v264;
    v241 = stack[-4];
    v241 = qcar(v241);
    v242 = v241;
    v241 = v242;
    if (!consp(v241)) goto v265;
    v241 = v242;
    v241 = qcdr(v241);
    v241 = qcar(v241);
    goto v266;

v266:
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-1] = v241;
    stack[-2] = v241;
    goto v267;

v267:
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v268;
    stack[0] = stack[-1];
    v241 = stack[-4];
    v241 = qcar(v241);
    v242 = v241;
    v241 = v242;
    if (!consp(v241)) goto v269;
    v241 = v242;
    v241 = qcdr(v241);
    v241 = qcar(v241);
    goto v270;

v270:
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = Lrplacd(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-1];
    v241 = qcdr(v241);
    stack[-1] = v241;
    goto v267;

v269:
    v241 = v242;
    goto v270;

v268:
    v241 = stack[-2];
    goto v271;

v271:
    stack[0] = v241;
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = stack[0];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    fn = elt(env, 17); /* indexsymmetrize */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[0] = v241;
    v241 = stack[0];
    if (v241 == nil) goto v272;
    v241 = stack[0];
    v242 = qcar(v241);
    v241 = (Lisp_Object)-15; /* -1 */
    if (!(v242 == v241)) goto v273;
    v241 = qvalue(elt(env, 5)); /* t */
    stack[-5] = v241;
    goto v273;

v273:
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = qcdr(v241);
    stack[0] = v241;
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = elt(env, 4); /* covariant */
    v241 = Lflagp(nil, v242, v241);
    env = stack[-9];
    if (v241 == nil) goto v274;
    v241 = stack[0];
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v275;
    v241 = stack[-4];
    v241 = qcar(v241);
    v243 = v241;
    v242 = v243;
    v241 = stack[-8];
    v241 = Lmemq(nil, v242, v241);
    if (v241 == nil) goto v276;
    v241 = v243;
    goto v277;

v277:
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-1] = v241;
    stack[-2] = v241;
    goto v278;

v278:
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v279;
    stack[0] = stack[-1];
    v241 = stack[-4];
    v241 = qcar(v241);
    v243 = v241;
    v242 = v243;
    v241 = stack[-8];
    v241 = Lmemq(nil, v242, v241);
    if (v241 == nil) goto v280;
    v241 = v243;
    goto v281;

v281:
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = Lrplacd(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-1];
    v241 = qcdr(v241);
    stack[-1] = v241;
    goto v278;

v280:
    v241 = elt(env, 2); /* minus */
    v242 = v243;
    v241 = list2(v241, v242);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v281;

v279:
    v241 = stack[-2];
    goto v282;

v282:
    stack[0] = v241;
    goto v283;

v283:
    v241 = stack[-3];
    if (v241 == nil) goto v284;
    v241 = stack[-5];
    if (v241 == nil) goto v285;
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = stack[0];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    fn = elt(env, 15); /* mkupf */
    stack[0] = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v242 = (Lisp_Object)-15; /* -1 */
    v241 = (Lisp_Object)17; /* 1 */
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    {
        Lisp_Object v286 = stack[0];
        popv(10);
        fn = elt(env, 12); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v286, v241);
    }

v285:
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = stack[0];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    {
        popv(10);
        fn = elt(env, 15); /* mkupf */
        return (*qfn1(fn))(qenv(fn), v241);
    }

v284:
    v241 = stack[-5];
    if (v241 == nil) goto v287;
    stack[-1] = (Lisp_Object)17; /* 1 */
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = stack[0];
    v242 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksq */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[0] = v241;
    v241 = stack[0];
    v241 = qcar(v241);
    fn = elt(env, 18); /* negf */
    v242 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[0];
    v241 = qcdr(v241);
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = cons(stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    popv(10);
    return ncons(v241);

v287:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v241 = stack[-7];
    v242 = qcar(v241);
    v241 = stack[0];
    v242 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksq */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = cons(stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    popv(10);
    return ncons(v241);

v276:
    v241 = elt(env, 2); /* minus */
    v242 = v243;
    v241 = list2(v241, v242);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v277;

v275:
    v241 = qvalue(elt(env, 1)); /* nil */
    goto v282;

v274:
    v241 = qvalue(elt(env, 3)); /* metricu!* */
    if (v241 == nil) goto v288;
    v241 = qvalue(elt(env, 1)); /* nil */
    goto v289;

v289:
    if (v241 == nil) goto v290;
    v241 = stack[0];
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v291;
    v241 = stack[-4];
    v241 = qcar(v241);
    v242 = elt(env, 2); /* minus */
    v241 = list2(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-1] = v241;
    stack[-2] = v241;
    goto v292;

v292:
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v293;
    stack[0] = stack[-1];
    v241 = stack[-4];
    v241 = qcar(v241);
    v242 = elt(env, 2); /* minus */
    v241 = list2(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = Lrplacd(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-1];
    v241 = qcdr(v241);
    stack[-1] = v241;
    goto v292;

v293:
    v241 = stack[-2];
    goto v294;

v294:
    stack[0] = v241;
    goto v283;

v291:
    v241 = qvalue(elt(env, 1)); /* nil */
    goto v294;

v290:
    v241 = stack[0];
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v295;
    v241 = stack[-4];
    v241 = qcar(v241);
    v243 = v241;
    v242 = v243;
    v241 = stack[-8];
    v241 = Lmemq(nil, v242, v241);
    if (v241 == nil) goto v296;
    v241 = elt(env, 2); /* minus */
    v242 = v243;
    v241 = list2(v241, v242);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v297;

v297:
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-1] = v241;
    stack[-2] = v241;
    goto v298;

v298:
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    v241 = stack[-4];
    if (v241 == nil) goto v299;
    stack[0] = stack[-1];
    v241 = stack[-4];
    v241 = qcar(v241);
    v243 = v241;
    v242 = v243;
    v241 = stack[-8];
    v241 = Lmemq(nil, v242, v241);
    if (v241 == nil) goto v300;
    v241 = elt(env, 2); /* minus */
    v242 = v243;
    v241 = list2(v241, v242);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v301;

v301:
    v241 = ncons(v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = Lrplacd(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-1];
    v241 = qcdr(v241);
    stack[-1] = v241;
    goto v298;

v300:
    v241 = v243;
    goto v301;

v299:
    v241 = stack[-2];
    goto v302;

v302:
    stack[0] = v241;
    goto v283;

v296:
    v241 = v243;
    goto v297;

v295:
    v241 = qvalue(elt(env, 1)); /* nil */
    goto v302;

v288:
    v241 = stack[-7];
    v241 = qcdr(v241);
    v241 = qcar(v241);
    v241 = (consp(v241) ? nil : lisp_true);
    v241 = (v241 == nil ? lisp_true : nil);
    goto v289;

v272:
    v241 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v241); }

v265:
    v241 = v242;
    goto v266;

v264:
    v241 = qvalue(elt(env, 1)); /* nil */
    goto v271;

v260:
    v241 = qvalue(elt(env, 5)); /* t */
    goto v261;

v256:
    v241 = qvalue(elt(env, 5)); /* t */
    goto v257;

v253:
    v241 = stack[-2];
    if (v241 == nil) goto v303;
    v241 = stack[-2];
    v241 = qcar(v241);
    if (!consp(v241)) goto v304;
    v241 = qvalue(elt(env, 5)); /* t */
    goto v305;

v305:
    if (v241 == nil) goto v303;
    v241 = stack[-2];
    v242 = qcar(v241);
    v241 = stack[-6];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-6] = v241;
    v241 = stack[-2];
    v241 = qcar(v241);
    if (!(!consp(v241))) goto v306;
    v241 = stack[-2];
    v242 = qcar(v241);
    v241 = stack[-8];
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-8] = v241;
    goto v306;

v306:
    v241 = stack[-2];
    v241 = qcdr(v241);
    stack[-2] = v241;
    goto v253;

v303:
    v241 = stack[-2];
    if (v241 == nil) goto v7;
    v241 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v241;
    v241 = stack[-6];
    v241 = Lreverse(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-6] = v241;
    v241 = stack[-2];
    v241 = qcar(v241);
    fn = elt(env, 19); /* getupper */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-4] = v241;
    goto v307;

v307:
    v241 = stack[-4];
    if (v241 == nil) { Lisp_Object res = stack[-5]; popv(10); return onevalue(res); }
    v241 = stack[-4];
    v241 = qcar(v241);
    stack[-3] = v241;
    v241 = stack[-7];
    stack[-1] = qcar(v241);
    stack[0] = stack[-6];
    v242 = elt(env, 2); /* minus */
    v241 = stack[-3];
    v241 = qcar(v241);
    v242 = list2(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-2];
    v241 = qcdr(v241);
    v241 = cons(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = Lappend(nil, stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = cons(stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[0] = CC_partitindexvar(env, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-3];
    v241 = qcdr(v241);
    fn = elt(env, 11); /* simp */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    fn = elt(env, 12); /* multpfsq */
    v242 = (*qfn2(fn))(qenv(fn), stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = stack[-5];
    fn = elt(env, 13); /* addpf */
    v241 = (*qfn2(fn))(qenv(fn), v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    stack[-5] = v241;
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    goto v307;

v304:
    v241 = stack[-2];
    v242 = qcar(v241);
    v241 = qvalue(elt(env, 3)); /* metricu!* */
    v241 = Latsoc(nil, v242, v241);
    v241 = (v241 == nil ? lisp_true : nil);
    goto v305;

v54:
    stack[0] = elt(env, 2); /* minus */
    v241 = v242;
    v241 = qcdr(v241);
    v241 = qcar(v241);
    fn = elt(env, 8); /* !*num2id */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = list2(stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v245;

v56:
    v241 = v242;
    if (is_number(v241)) goto v308;
    v241 = v242;
    goto v245;

v308:
    v241 = v242;
    v241 = Lminusp(nil, v241);
    env = stack[-9];
    if (v241 == nil) goto v309;
    stack[0] = elt(env, 2); /* minus */
    v241 = v242;
    v241 = Labsval(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    fn = elt(env, 8); /* !*num2id */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    v241 = list2(stack[0], v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v245;

v309:
    v241 = v242;
    fn = elt(env, 8); /* !*num2id */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-9];
    goto v245;

v4:
    v241 = qvalue(elt(env, 1)); /* nil */
    goto v252;
/* error exit handlers */
v244:
    popv(10);
    return nil;
}



/* Code for mult_derivs */

static Lisp_Object CC_mult_derivs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v249, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mult_derivs");
#endif
    if (stack >= stacklimit)
    {
        push2(v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v14;
    v249 = v0;
/* end of prologue */
    stack[-5] = nil;
    v229 = stack[-4];
    if (v229 == nil) { popv(7); return onevalue(v249); }
    v229 = v249;
    if (v229 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v229 = v249;
    stack[-3] = v229;
    goto v318;

v318:
    v229 = stack[-3];
    if (v229 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v229 = stack[-3];
    v229 = qcar(v229);
    stack[-2] = v229;
    v229 = stack[-4];
    stack[-1] = v229;
    goto v56;

v56:
    v229 = stack[-1];
    if (v229 == nil) goto v245;
    v229 = stack[-1];
    v229 = qcar(v229);
    v48 = v229;
    v229 = stack[-2];
    v249 = qcar(v229);
    v229 = v48;
    v229 = qcar(v229);
    if (equal(v249, v229)) goto v319;
    v249 = v48;
    v229 = stack[-2];
    v249 = list2(v249, v229);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v229 = stack[-5];
    fn = elt(env, 2); /* union */
    v229 = (*qfn2(fn))(qenv(fn), v249, v229);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    stack[-5] = v229;
    goto v320;

v320:
    v229 = stack[-1];
    v229 = qcdr(v229);
    stack[-1] = v229;
    goto v56;

v319:
    v229 = v48;
    stack[0] = qcar(v229);
    v229 = v48;
    v249 = qcdr(v229);
    v229 = stack[-2];
    v229 = qcdr(v229);
    v229 = plus2(v249, v229);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v229 = cons(stack[0], v229);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v249 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    v229 = stack[-5];
    fn = elt(env, 2); /* union */
    v229 = (*qfn2(fn))(qenv(fn), v249, v229);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-6];
    stack[-5] = v229;
    goto v320;

v245:
    v229 = stack[-3];
    v229 = qcdr(v229);
    stack[-3] = v229;
    goto v318;
/* error exit handlers */
v40:
    popv(7);
    return nil;
}



/* Code for simpdfp */

static Lisp_Object CC_simpdfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v364, v365, v366, v367, v368;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdfp");
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
    stack[0] = v0;
/* end of prologue */
    v364 = stack[0];
    v365 = Llength(nil, v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v364 = (Lisp_Object)33; /* 2 */
    v364 = (Lisp_Object)lessp2(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    v364 = v364 ? lisp_true : nil;
    env = stack[-6];
    if (v364 == nil) goto v6;
    v365 = elt(env, 2); /* dfp */
    v364 = stack[0];
    v365 = cons(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v364 = elt(env, 11); /* "generic differential" */
    fn = elt(env, 12); /* typerr */
    v364 = (*qfn2(fn))(qenv(fn), v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    v364 = nil;
    { popv(7); return onevalue(v364); }

v6:
    v364 = stack[0];
    v364 = qcar(v364);
    fn = elt(env, 13); /* reval */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    stack[-5] = v364;
    v364 = stack[-5];
    v364 = Lconsp(nil, v364);
    env = stack[-6];
    if (v364 == nil) goto v85;
    v364 = stack[-5];
    v364 = qcar(v364);
    stack[-1] = v364;
    v364 = stack[0];
    v364 = qcdr(v364);
    v364 = qcar(v364);
    fn = elt(env, 13); /* reval */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v368 = v364;
    v365 = v368;
    v364 = qvalue(elt(env, 1)); /* frlis!* */
    v364 = Lmember(nil, v365, v364);
    if (v364 == nil) goto v310;
    v364 = qvalue(elt(env, 4)); /* nil */
    goto v247;

v247:
    if (v364 == nil) goto v224;
    stack[-4] = v368;
    v364 = stack[0];
    v364 = qcdr(v364);
    v364 = qcdr(v364);
    stack[-3] = v364;
    v364 = stack[-3];
    if (v364 == nil) goto v70;
    v364 = stack[-3];
    v364 = qcar(v364);
    fn = elt(env, 13); /* reval */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v364 = ncons(v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    stack[-1] = v364;
    stack[-2] = v364;
    goto v370;

v370:
    v364 = stack[-3];
    v364 = qcdr(v364);
    stack[-3] = v364;
    v364 = stack[-3];
    if (v364 == nil) goto v371;
    stack[0] = stack[-1];
    v364 = stack[-3];
    v364 = qcar(v364);
    fn = elt(env, 13); /* reval */
    v364 = (*qfn1(fn))(qenv(fn), v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v364 = ncons(v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v364 = Lrplacd(nil, stack[0], v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v364 = stack[-1];
    v364 = qcdr(v364);
    stack[-1] = v364;
    goto v370;

v371:
    v364 = stack[-2];
    goto v40;

v40:
    v364 = cons(stack[-4], v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v368 = v364;
    stack[0] = elt(env, 3); /* list */
    v365 = v368;
    v364 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 14); /* dfp!-normalize */
    v364 = (*qfn2(fn))(qenv(fn), v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v364 = cons(stack[0], v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v368 = v364;
    v365 = elt(env, 2); /* dfp */
    v364 = stack[-5];
    v366 = v368;
    v364 = list3(v365, v364, v366);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 15); /* simp */
        return (*qfn1(fn))(qenv(fn), v364);
    }

v70:
    v364 = qvalue(elt(env, 4)); /* nil */
    goto v40;

v224:
    v365 = stack[-1];
    v364 = elt(env, 5); /* generic_function */
    v364 = get(v365, v364);
    env = stack[-6];
    v367 = v364;
    v364 = qvalue(elt(env, 6)); /* t */
    v365 = v367;
    if (v365 == nil) goto v372;
    v366 = v368;
    v365 = elt(env, 3); /* list */
    if (!consp(v366)) goto v372;
    v366 = qcar(v366);
    if (!(v366 == v365)) goto v372;
    v365 = v368;
    v365 = qcdr(v365);
    v366 = v365;
    goto v373;

v373:
    v365 = v366;
    if (v365 == nil) goto v372;
    v365 = v366;
    v365 = qcar(v365);
    if (v364 == nil) goto v84;
    v364 = v367;
    v364 = Lmember(nil, v365, v364);
    goto v31;

v31:
    v365 = v366;
    v365 = qcdr(v365);
    v366 = v365;
    goto v373;

v84:
    v364 = qvalue(elt(env, 4)); /* nil */
    goto v31;

v372:
    if (v364 == nil) goto v374;
    v365 = v368;
    v364 = elt(env, 7); /* (list) */
    if (equal(v365, v364)) goto v74;
    v364 = v367;
    if (v364 == nil) goto v375;
    v365 = stack[-1];
    v364 = elt(env, 8); /* dfp_commute */
    v364 = Lflagp(nil, v365, v364);
    env = stack[-6];
    if (v364 == nil) goto v375;
    v364 = v367;
    stack[-1] = qvalue(elt(env, 9)); /* kord!* */
    qvalue(elt(env, 9)) = v364; /* kord!* */
    stack[0] = elt(env, 3); /* list */
    v364 = v368;
    v365 = qcdr(v364);
    v364 = elt(env, 10); /* ordp */
    fn = elt(env, 16); /* sort */
    v364 = (*qfn2(fn))(qenv(fn), v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v376;
    env = stack[-6];
    v364 = cons(stack[0], v364);
    nil = C_nil;
    if (exception_pending()) goto v376;
    env = stack[-6];
    v368 = v364;
    qvalue(elt(env, 9)) = stack[-1]; /* kord!* */
    goto v375;

v375:
    v365 = elt(env, 2); /* dfp */
    v364 = stack[-5];
    v366 = v368;
    v364 = list3(v365, v364, v366);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    stack[0] = v364;
    v365 = stack[0];
    v364 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 17); /* mksq */
        return (*qfn2(fn))(qenv(fn), v365, v364);
    }

v74:
    v365 = stack[-5];
    v364 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 17); /* mksq */
        return (*qfn2(fn))(qenv(fn), v365, v364);
    }

v374:
    v365 = qvalue(elt(env, 4)); /* nil */
    v364 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v365, v364);

v310:
    v365 = v368;
    v364 = elt(env, 3); /* list */
    v364 = Leqcar(nil, v365, v364);
    env = stack[-6];
    v364 = (v364 == nil ? lisp_true : nil);
    goto v247;

v85:
    v364 = stack[0];
    v364 = qcdr(v364);
    v365 = qcar(v364);
    v364 = qvalue(elt(env, 1)); /* frlis!* */
    v364 = Lmember(nil, v365, v364);
    if (v364 == nil) goto v377;
    v365 = elt(env, 2); /* dfp */
    v364 = stack[0];
    v365 = cons(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    v364 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 17); /* mksq */
        return (*qfn2(fn))(qenv(fn), v365, v364);
    }

v377:
    v365 = stack[-5];
    v364 = stack[0];
    v364 = qcdr(v364);
    v364 = qcar(v364);
    v364 = qcdr(v364);
    v364 = cons(v365, v364);
    nil = C_nil;
    if (exception_pending()) goto v369;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 18); /* simpdf */
        return (*qfn1(fn))(qenv(fn), v364);
    }
/* error exit handlers */
v376:
    env = stack[-6];
    qvalue(elt(env, 9)) = stack[-1]; /* kord!* */
    popv(7);
    return nil;
v369:
    popv(7);
    return nil;
}



/* Code for grk */

static Lisp_Object MS_CDECL CC_grk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v14,
                         Lisp_Object v122, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v382, v383, v384;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "grk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for grk");
#endif
    if (stack >= stacklimit)
    {
        push3(v122,v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v14,v122);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v122;
    stack[-8] = v14;
    v382 = v0;
/* end of prologue */

v385:
    v383 = v382;
    if (!consp(v383)) goto v60;
    v383 = v382;
    v383 = qcar(v383);
    v383 = (consp(v383) ? nil : lisp_true);
    goto v386;

v386:
    if (!(v383 == nil)) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    v383 = v382;
    v383 = qcar(v383);
    v383 = qcar(v383);
    v383 = qcar(v383);
    stack[-9] = v383;
    v383 = v382;
    stack[-6] = qcdr(v383);
    stack[-5] = stack[-8];
    v382 = qcar(v382);
    stack[-4] = qcdr(v382);
    stack[-3] = stack[-8];
    v382 = stack[-9];
    if (!consp(v382)) goto v387;
    v382 = stack[-9];
    v382 = qcdr(v382);
    stack[-2] = v382;
    goto v360;

v360:
    v382 = stack[-2];
    if (v382 == nil) goto v388;
    v382 = stack[-2];
    v382 = qcar(v382);
    fn = elt(env, 3); /* simp */
    v382 = (*qfn1(fn))(qenv(fn), v382);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-10];
    v383 = v382;
    v382 = v383;
    stack[-1] = qcar(v382);
    stack[0] = stack[-8];
    v382 = v383;
    v384 = qcdr(v382);
    v383 = stack[-8];
    v382 = stack[-7];
    v382 = CC_grk(env, 3, v384, v383, v382);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-10];
    v382 = CC_grk(env, 3, stack[-1], stack[0], v382);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-10];
    stack[-7] = v382;
    v382 = stack[-2];
    v382 = qcdr(v382);
    stack[-2] = v382;
    goto v360;

v388:
    v382 = stack[-9];
    v383 = qcar(v382);
    v382 = stack[-8];
    v382 = Lmember(nil, v383, v382);
    if (v382 == nil) goto v389;
    v383 = stack[-9];
    v382 = stack[-7];
    v382 = Lmember(nil, v383, v382);
    if (!(v382 == nil)) goto v389;
    v383 = stack[-9];
    v382 = stack[-7];
    v382 = cons(v383, v382);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-10];
    goto v362;

v362:
    v383 = CC_grk(env, 3, stack[-4], stack[-3], v382);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-10];
    v382 = stack[-6];
    stack[-8] = stack[-5];
    stack[-7] = v383;
    goto v385;

v389:
    v382 = stack[-7];
    goto v362;

v387:
    v382 = stack[-7];
    goto v362;

v60:
    v383 = qvalue(elt(env, 1)); /* t */
    goto v386;
/* error exit handlers */
v42:
    popv(11);
    return nil;
}



/* Code for ofsf_smmkatl!-and1 */

static Lisp_Object MS_CDECL CC_ofsf_smmkatlKand1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v14,
                         Lisp_Object v122, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v73, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_smmkatl-and1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl-and1");
#endif
    if (stack >= stacklimit)
    {
        push3(v122,v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v14,v122);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v122;
    stack[0] = v14;
    stack[-6] = v0;
/* end of prologue */
    v33 = stack[0];
    v73 = qcar(v33);
    v33 = (Lisp_Object)17; /* 1 */
    v33 = cons(v73, v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    stack[-7] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[-4] = v33;
    goto v4;

v4:
    v33 = stack[-4];
    if (v33 == nil) goto v399;
    v33 = stack[-4];
    v33 = qcar(v33);
    stack[0] = v33;
    v33 = stack[0];
    v73 = qcar(v33);
    v33 = stack[-5];
    if (equal(v73, v33)) goto v400;
    v33 = nil;
    goto v13;

v13:
    stack[-3] = v33;
    v33 = stack[-3];
    fn = elt(env, 4); /* lastpair */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    stack[-2] = v33;
    v33 = stack[-4];
    v33 = qcdr(v33);
    stack[-4] = v33;
    v33 = stack[-2];
    if (!consp(v33)) goto v4;
    else goto v5;

v5:
    v33 = stack[-4];
    if (v33 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v33 = stack[-4];
    v33 = qcar(v33);
    stack[0] = v33;
    v33 = stack[0];
    v73 = qcar(v33);
    v33 = stack[-5];
    if (equal(v73, v33)) goto v44;
    v33 = nil;
    goto v71;

v71:
    v33 = Lrplacd(nil, stack[-1], v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    v33 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    stack[-2] = v33;
    v33 = stack[-4];
    v33 = qcdr(v33);
    stack[-4] = v33;
    goto v5;

v44:
    v33 = stack[0];
    v33 = qcdr(v33);
    v73 = qcar(v33);
    v33 = elt(env, 2); /* (lessp greaterp) */
    v33 = Lmemq(nil, v73, v33);
    if (v33 == nil) goto v401;
    v33 = stack[-6];
    v72 = qcdr(v33);
    v33 = stack[0];
    v73 = qcdr(v33);
    v33 = stack[-7];
    fn = elt(env, 5); /* ofsf_smmkat!-and2 */
    v33 = (*qfnn(fn))(qenv(fn), 3, v72, v73, v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    v73 = v33;
    if (v33 == nil) goto v401;
    v33 = v73;
    v33 = ncons(v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    goto v71;

v401:
    v72 = elt(env, 3); /* and */
    v33 = stack[0];
    v73 = qcdr(v33);
    v33 = stack[-7];
    fn = elt(env, 6); /* ofsf_entry2at */
    v33 = (*qfnn(fn))(qenv(fn), 3, v72, v73, v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    v33 = ncons(v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    goto v71;

v400:
    v33 = stack[0];
    v33 = qcdr(v33);
    v73 = qcar(v33);
    v33 = elt(env, 2); /* (lessp greaterp) */
    v33 = Lmemq(nil, v73, v33);
    if (v33 == nil) goto v402;
    v33 = stack[-6];
    v72 = qcdr(v33);
    v33 = stack[0];
    v73 = qcdr(v33);
    v33 = stack[-7];
    fn = elt(env, 5); /* ofsf_smmkat!-and2 */
    v33 = (*qfnn(fn))(qenv(fn), 3, v72, v73, v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    v73 = v33;
    if (v33 == nil) goto v402;
    v33 = v73;
    v33 = ncons(v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    goto v13;

v402:
    v72 = elt(env, 3); /* and */
    v33 = stack[0];
    v73 = qcdr(v33);
    v33 = stack[-7];
    fn = elt(env, 6); /* ofsf_entry2at */
    v33 = (*qfnn(fn))(qenv(fn), 3, v72, v73, v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    v33 = ncons(v33);
    nil = C_nil;
    if (exception_pending()) goto v398;
    env = stack[-8];
    goto v13;

v399:
    v33 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v33); }
/* error exit handlers */
v398:
    popv(9);
    return nil;
}



/* Code for mk_character */

static Lisp_Object CC_mk_character(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v395;
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
    v68 = stack[-5];
    fn = elt(env, 2); /* get_group_in */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-6] = v68;
    v68 = stack[-6];
    fn = elt(env, 3); /* get!*elements */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-4] = v68;
    v68 = stack[-4];
    if (v68 == nil) goto v390;
    v68 = stack[-4];
    v68 = qcar(v68);
    stack[0] = v68;
    v395 = v68;
    v68 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v68 = (*qfn2(fn))(qenv(fn), v395, v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+trace */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v68 = list2(stack[0], v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v68 = ncons(v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    stack[-2] = v68;
    stack[-3] = v68;
    goto v235;

v235:
    v68 = stack[-4];
    v68 = qcdr(v68);
    stack[-4] = v68;
    v68 = stack[-4];
    if (v68 == nil) goto v320;
    stack[-1] = stack[-2];
    v68 = stack[-4];
    v68 = qcar(v68);
    stack[0] = v68;
    v395 = v68;
    v68 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v68 = (*qfn2(fn))(qenv(fn), v395, v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+trace */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v68 = list2(stack[0], v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v68 = ncons(v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v68 = Lrplacd(nil, stack[-1], v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-7];
    v68 = stack[-2];
    v68 = qcdr(v68);
    stack[-2] = v68;
    goto v235;

v320:
    v68 = stack[-3];
    goto v236;

v236:
    stack[0] = v68;
    v68 = stack[-6];
    v395 = ncons(v68);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v68 = stack[0];
        popv(8);
        return Lappend(nil, v395, v68);

v390:
    v68 = qvalue(elt(env, 1)); /* nil */
    goto v236;
/* error exit handlers */
v227:
    popv(8);
    return nil;
}



/* Code for cl_sacatlp */

static Lisp_Object CC_cl_sacatlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object v11, v202;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sacatlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v11 = v14;
    v202 = v0;
/* end of prologue */
    v11 = qvalue(elt(env, 1)); /* t */
    return onevalue(v11);
}



/* Code for bc_pmon */

static Lisp_Object CC_bc_pmon(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_pmon");
#endif
    if (stack >= stacklimit)
    {
        push2(v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v1 = v14;
    v2 = v0;
/* end of prologue */
    v3 = v2;
    v2 = v1;
    v1 = (Lisp_Object)17; /* 1 */
    v2 = acons(v3, v2, v1);
    nil = C_nil;
    if (exception_pending()) goto v408;
    env = stack[0];
    v3 = qvalue(elt(env, 1)); /* nil */
    v1 = (Lisp_Object)17; /* 1 */
    popv(1);
    return acons(v2, v3, v1);
/* error exit handlers */
v408:
    popv(1);
    return nil;
}



/* Code for tryfactorf */

static Lisp_Object CC_tryfactorf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v310, v409, v410;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tryfactorf");
#endif
    if (stack >= stacklimit)
    {
        push2(v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v14;
    stack[-1] = v0;
/* end of prologue */
    v228 = stack[0];
    fn = elt(env, 4); /* atomlis */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    if (v228 == nil) goto v112;
    v228 = stack[0];
    v228 = qcdr(v228);
    v228 = qcdr(v228);
    if (v228 == nil) goto v318;
    v228 = stack[0];
    v228 = qcdr(v228);
    v228 = qcdr(v228);
    v410 = qcar(v228);
    v228 = stack[0];
    v228 = qcdr(v228);
    v409 = qcar(v228);
    v228 = stack[0];
    v310 = qcar(v228);
    v228 = stack[-1];
    v228 = qcar(v228);
    v228 = qcar(v228);
    v228 = qcar(v228);
    fn = elt(env, 5); /* quadthroughf */
    v228 = (*qfnn(fn))(qenv(fn), 4, v410, v409, v310, v228);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    stack[0] = v228;
    goto v411;

v411:
    v310 = stack[0];
    v228 = elt(env, 2); /* failed */
    if (v310 == v228) goto v404;
    v310 = stack[-1];
    v228 = stack[0];
    fn = elt(env, 6); /* quotf */
    v228 = (*qfn2(fn))(qenv(fn), v310, v228);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    stack[-1] = v228;
    v228 = (v228 == nil ? lisp_true : nil);
    goto v319;

v319:
    if (v228 == nil) goto v50;
    v228 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v228); }

v50:
    v310 = stack[0];
    v228 = stack[-1];
    popv(3);
    return cons(v310, v228);

v404:
    v228 = qvalue(elt(env, 3)); /* t */
    goto v319;

v318:
    v228 = stack[0];
    v228 = qcdr(v228);
    v409 = qcar(v228);
    v228 = stack[0];
    v310 = qcar(v228);
    v228 = stack[-1];
    v228 = qcar(v228);
    v228 = qcar(v228);
    v228 = qcar(v228);
    fn = elt(env, 7); /* linethroughf */
    v228 = (*qfnn(fn))(qenv(fn), 3, v409, v310, v228);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-2];
    stack[0] = v228;
    goto v411;

v112:
    v228 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v228); }
/* error exit handlers */
v230:
    popv(3);
    return nil;
}



/* Code for svec */

static Lisp_Object MS_CDECL CC_svec(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v14,
                         Lisp_Object v122, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v406, v239, v362;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "svec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for svec");
#endif
    if (stack >= stacklimit)
    {
        push3(v122,v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v14,v122);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v122;
    stack[-1] = v14;
    stack[-2] = v0;
/* end of prologue */
    v57 = (Lisp_Object)33; /* 2 */
    v57 = Lmkvect(nil, v57);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v362 = v57;
    v239 = v362;
    v406 = (Lisp_Object)1; /* 0 */
    v57 = stack[-2];
    *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v406/(16/CELL))) = v57;
    v239 = v362;
    v406 = (Lisp_Object)17; /* 1 */
    v57 = stack[-1];
    *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v406/(16/CELL))) = v57;
    v239 = v362;
    v406 = (Lisp_Object)33; /* 2 */
    v57 = stack[0];
    *(Lisp_Object *)((char *)v239 + (CELL-TAG_VECTOR) + ((int32_t)v406/(16/CELL))) = v57;
    v57 = v362;
    {
        popv(4);
        fn = elt(env, 1); /* aeval */
        return (*qfn1(fn))(qenv(fn), v57);
    }
/* error exit handlers */
v86:
    popv(4);
    return nil;
}



/* Code for random_minus */

static Lisp_Object CC_random_minus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random_minus");
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
    v5 = v0;
/* end of prologue */
    fn = elt(env, 2); /* random */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-1];
    stack[0] = v5;
    v5 = (Lisp_Object)16001; /* 1000 */
    fn = elt(env, 2); /* random */
    v5 = (*qfn1(fn))(qenv(fn), v5);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-1];
    v5 = Levenp(nil, v5);
    env = stack[-1];
    if (v5 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v1 = elt(env, 1); /* minus */
    v5 = stack[0];
    v5 = list2(v1, v5);
    nil = C_nil;
    if (exception_pending()) goto v3;
    stack[0] = v5;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v3:
    popv(2);
    return nil;
}



/* Code for exformp */

static Lisp_Object CC_exformp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v349, v350, v413;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exformp");
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

v202:
    v349 = stack[0];
    if (v349 == nil) goto v6;
    v349 = stack[0];
    v349 = (is_number(v349) ? lisp_true : nil);
    goto v7;

v7:
    if (v349 == nil) goto v386;
    v349 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v349); }

v386:
    v349 = stack[0];
    if (!consp(v349)) goto v399;
    v349 = qvalue(elt(env, 2)); /* nil */
    goto v1;

v1:
    if (v349 == nil) goto v4;
    v349 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v349); }

v4:
    v349 = stack[0];
    if (!consp(v349)) goto v362;
    v349 = stack[0];
    v350 = qcar(v349);
    v349 = elt(env, 5); /* indexvar */
    v349 = Lflagp(nil, v350, v349);
    env = stack[-1];
    if (v349 == nil) goto v402;
    v349 = stack[0];
    v349 = qcdr(v349);
    v413 = Llength(nil, v349);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-1];
    v349 = stack[0];
    v350 = qcar(v349);
    v349 = elt(env, 6); /* ifdegree */
    v349 = get(v350, v349);
    v349 = Lassoc(nil, v413, v349);
    { popv(2); return onevalue(v349); }

v402:
    v349 = stack[0];
    v350 = qcar(v349);
    v349 = elt(env, 7); /* !*sq */
    if (v350 == v349) goto v414;
    v349 = stack[0];
    v350 = qcar(v349);
    v349 = elt(env, 9); /* (wedge d partdf hodge innerprod liedf) */
    v349 = Lmemq(nil, v350, v349);
    if (v349 == nil) goto v415;
    v349 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v349); }

v415:
    v349 = stack[0];
    v350 = qcar(v349);
    v349 = elt(env, 10); /* dname */
    v349 = get(v350, v349);
    env = stack[-1];
    if (v349 == nil) goto v44;
    v349 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v349); }

v44:
    v349 = stack[0];
    v349 = qcdr(v349);
    fn = elt(env, 11); /* lexformp */
    v349 = (*qfn1(fn))(qenv(fn), v349);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-1];
    v350 = v349;
    if (!(v349 == nil)) { popv(2); return onevalue(v350); }
    v349 = stack[0];
    v349 = qcar(v349);
    v349 = CC_exformp(env, v349);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-1];
    v350 = v349;
    if (!(v349 == nil)) { popv(2); return onevalue(v350); }
    v349 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v349); }

v414:
    v349 = stack[0];
    v349 = qcdr(v349);
    v349 = qcar(v349);
    v349 = qcar(v349);
    if (v349 == nil) goto v396;
    v349 = stack[0];
    v349 = qcdr(v349);
    v350 = qcar(v349);
    v349 = elt(env, 8); /* prepf */
    fn = elt(env, 12); /* sqform */
    v349 = (*qfn2(fn))(qenv(fn), v350, v349);
    nil = C_nil;
    if (exception_pending()) goto v392;
    env = stack[-1];
    goto v395;

v395:
    stack[0] = v349;
    goto v202;

v396:
    v349 = (Lisp_Object)1; /* 0 */
    goto v395;

v362:
    v349 = stack[0];
    v350 = elt(env, 4); /* fdegree */
    popv(2);
    return get(v349, v350);

v399:
    v350 = stack[0];
    v349 = qvalue(elt(env, 3)); /* frlis!* */
    v349 = Lmemq(nil, v350, v349);
    goto v1;

v6:
    v349 = qvalue(elt(env, 1)); /* t */
    goto v7;
/* error exit handlers */
v392:
    popv(2);
    return nil;
}



/* Code for tcar */

static Lisp_Object CC_tcar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v235;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tcar");
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
    v235 = v0;
/* end of prologue */
    v236 = v235;
    v236 = Lconsp(nil, v236);
    if (v236 == nil) return onevalue(v235);
    v236 = v235;
    v236 = qcar(v236);
    return onevalue(v236);
}



/* Code for getlower */

static Lisp_Object CC_getlower(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getlower");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v6 = qvalue(elt(env, 1)); /* metricd!* */
    v7 = Latsoc(nil, v7, v6);
    v7 = qcdr(v7);
    return onevalue(v7);
}



/* Code for mk_edge_name */

static Lisp_Object CC_mk_edge_name(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_edge_name");
#endif
    if (stack >= stacklimit)
    {
        push2(v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v14;
    stack[0] = v0;
/* end of prologue */
    v1 = qvalue(elt(env, 1)); /* n_edge */
    v1 = add1(v1);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-3];
    qvalue(elt(env, 1)) = v1; /* n_edge */
    v1 = stack[0];
    stack[-2] = Lexplode(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-3];
    v1 = qvalue(elt(env, 1)); /* n_edge */
    stack[0] = Lexplode(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-3];
    v1 = stack[-1];
    v1 = Lexplode(nil, v1);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-3];
    v1 = Lappend(nil, stack[0], v1);
    nil = C_nil;
    if (exception_pending()) goto v399;
    env = stack[-3];
    v1 = Lappend(nil, stack[-2], v1);
    nil = C_nil;
    if (exception_pending()) goto v399;
        popv(4);
        return Lcompress(nil, v1);
/* error exit handlers */
v399:
    popv(4);
    return nil;
}



/* Code for select_epsi_pairs */

static Lisp_Object CC_select_epsi_pairs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v361, v360;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for select_epsi_pairs");
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

v385:
    v361 = stack[0];
    if (v361 == nil) goto v11;
    v361 = stack[0];
    v361 = qcar(v361);
    stack[-1] = v361;
    v361 = stack[-1];
    v360 = Llength(nil, v361);
    nil = C_nil;
    if (exception_pending()) goto v417;
    env = stack[-2];
    v361 = (Lisp_Object)33; /* 2 */
    if (v360 == v361) goto v55;
    v361 = qvalue(elt(env, 1)); /* nil */
    goto v317;

v317:
    if (v361 == nil) goto v240;
    v361 = stack[0];
    v361 = qcdr(v361);
    v361 = CC_select_epsi_pairs(env, v361);
    nil = C_nil;
    if (exception_pending()) goto v417;
    {
        Lisp_Object v312 = stack[-1];
        popv(3);
        return cons(v312, v361);
    }

v240:
    v361 = stack[0];
    v361 = qcdr(v361);
    stack[0] = v361;
    goto v385;

v55:
    v361 = stack[-1];
    v361 = qcar(v361);
    v360 = qcdr(v361);
    v361 = stack[-1];
    v361 = qcdr(v361);
    v361 = qcar(v361);
    v361 = qcdr(v361);
    fn = elt(env, 2); /* cov_contp */
    v361 = (*qfn2(fn))(qenv(fn), v360, v361);
    nil = C_nil;
    if (exception_pending()) goto v417;
    env = stack[-2];
    goto v317;

v11:
    v361 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v361); }
/* error exit handlers */
v417:
    popv(3);
    return nil;
}



/* Code for pe_inv */

static Lisp_Object CC_pe_inv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v359, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pe_inv");
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
    v359 = stack[-3];
    fn = elt(env, 2); /* upbve */
    v359 = (*qfn1(fn))(qenv(fn), v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v359 = sub1(v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v359 = Lmkvect(nil, v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    stack[-4] = v359;
    v359 = (Lisp_Object)17; /* 1 */
    stack[-2] = v359;
    goto v4;

v4:
    v359 = stack[-3];
    fn = elt(env, 2); /* upbve */
    v58 = (*qfn1(fn))(qenv(fn), v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v359 = stack[-2];
    v359 = difference2(v58, v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v359 = Lminusp(nil, v359);
    env = stack[-5];
    if (!(v359 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v359 = stack[-2];
    v359 = sub1(v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v359 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v359/(16/CELL)));
    v58 = sub1(v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    v359 = stack[-2];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v58/(16/CELL))) = v359;
    v359 = stack[-2];
    v359 = add1(v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-5];
    stack[-2] = v359;
    goto v4;
/* error exit handlers */
v361:
    popv(6);
    return nil;
}



/* Code for nordp */

static Lisp_Object CC_nordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nordp");
#endif
    if (stack >= stacklimit)
    {
        push2(v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v14;
    v236 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ordp */
    v6 = (*qfn2(fn))(qenv(fn), v236, v6);
    errexit();
    v6 = (v6 == nil ? lisp_true : nil);
    return onevalue(v6);
}



/* Code for i_solve!-eval */

static Lisp_Object CC_i_solveKeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i_solve-eval");
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
    v192 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*i_solve */
    qvalue(elt(env, 2)) = v192; /* !*i_solve */
    v192 = v103;
    fn = elt(env, 3); /* r_solve!-eval */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*i_solve */
    { popv(2); return onevalue(v192); }
/* error exit handlers */
v386:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*i_solve */
    popv(2);
    return nil;
}



/* Code for general!-monic!-mod!-p */

static Lisp_Object CC_generalKmonicKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v377, v319, v404;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-monic-mod-p");
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
    v404 = v0;
/* end of prologue */
    v377 = v404;
    if (v377 == nil) goto v11;
    v377 = v404;
    if (!consp(v377)) goto v6;
    v377 = v404;
    v377 = qcar(v377);
    v377 = (consp(v377) ? nil : lisp_true);
    goto v7;

v7:
    if (v377 == nil) goto v1;
    v377 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v377); }

v1:
    v377 = v404;
    v377 = qcar(v377);
    v319 = qcdr(v377);
    v377 = (Lisp_Object)17; /* 1 */
    if (v319 == v377) { popv(2); return onevalue(v404); }
    v377 = v404;
    v377 = qcar(v377);
    v377 = qcdr(v377);
    if (!consp(v377)) goto v238;
    v377 = v404;
    v377 = qcar(v377);
    v377 = qcdr(v377);
    v377 = qcar(v377);
    v377 = (consp(v377) ? nil : lisp_true);
    goto v85;

v85:
    if (v377 == nil) goto v245;
    stack[0] = v404;
    v377 = v404;
    v377 = qcar(v377);
    v377 = qcdr(v377);
    fn = elt(env, 4); /* general!-modular!-reciprocal */
    v377 = (*qfn1(fn))(qenv(fn), v377);
    nil = C_nil;
    if (exception_pending()) goto v411;
    env = stack[-1];
    {
        Lisp_Object v357 = stack[0];
        popv(2);
        fn = elt(env, 5); /* general!-multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v357, v377);
    }

v245:
    v377 = elt(env, 3); /* "LC NOT NUMERIC IN GENERAL-MONIC-MOD-P" */
    {
        popv(2);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v377);
    }

v238:
    v377 = qvalue(elt(env, 2)); /* t */
    goto v85;

v6:
    v377 = qvalue(elt(env, 2)); /* t */
    goto v7;

v11:
    v377 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v377); }
/* error exit handlers */
v411:
    popv(2);
    return nil;
}



/* Code for split_non_linear_f */

static Lisp_Object MS_CDECL CC_split_non_linear_f(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v14,
                         Lisp_Object v122, Lisp_Object v93,
                         Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v426, v398, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "split_non_linear_f");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split_non_linear_f");
#endif
    if (stack >= stacklimit)
    {
        push5(v11,v93,v122,v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v14,v122,v93,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v11;
    stack[-5] = v93;
    stack[-6] = v122;
    stack[-7] = v14;
    v398 = v0;
/* end of prologue */

v386:
    v426 = v398;
    if (v426 == nil) { Lisp_Object res = stack[-4]; popv(10); return onevalue(res); }
    v426 = v398;
    if (!consp(v426)) goto v407;
    v426 = v398;
    v426 = qcar(v426);
    v426 = (consp(v426) ? nil : lisp_true);
    goto v390;

v390:
    if (v426 == nil) goto v237;
    v426 = stack[-6];
    if (v426 == nil) goto v319;
    stack[0] = stack[-4];
    stack[-1] = stack[-6];
    v426 = stack[-5];
    fn = elt(env, 3); /* multf */
    v426 = (*qfn2(fn))(qenv(fn), v426, v398);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    {
        Lisp_Object v428 = stack[0];
        Lisp_Object v429 = stack[-1];
        popv(10);
        fn = elt(env, 4); /* update_kc_list */
        return (*qfnn(fn))(qenv(fn), 3, v428, v429, v426);
    }

v319:
    v426 = stack[-5];
    fn = elt(env, 3); /* multf */
    v398 = (*qfn2(fn))(qenv(fn), v426, v398);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    v426 = stack[-4];
    v426 = qcar(v426);
    fn = elt(env, 5); /* addf */
    v398 = (*qfn2(fn))(qenv(fn), v398, v426);
    nil = C_nil;
    if (exception_pending()) goto v427;
    v426 = stack[-4];
    v426 = qcdr(v426);
    popv(10);
    return cons(v398, v426);

v237:
    v426 = v398;
    v426 = qcdr(v426);
    stack[-8] = v426;
    v426 = v398;
    v426 = qcar(v426);
    v426 = qcar(v426);
    v426 = qcar(v426);
    if (!consp(v426)) goto v229;
    v426 = v398;
    v426 = qcar(v426);
    v426 = qcar(v426);
    v426 = qcar(v426);
    v224 = qcar(v426);
    v426 = stack[-7];
    v426 = Lmember(nil, v224, v426);
    goto v354;

v354:
    if (!(v426 == nil)) goto v430;
    v426 = v398;
    v426 = qcar(v426);
    v426 = qcar(v426);
    v224 = qcar(v426);
    v426 = stack[-7];
    v426 = Lmember(nil, v224, v426);
    if (!(v426 == nil)) goto v430;
    v426 = v398;
    v426 = qcar(v426);
    stack[-3] = qcdr(v426);
    stack[-2] = stack[-7];
    stack[-1] = stack[-6];
    stack[0] = stack[-5];
    v426 = v398;
    v426 = qcar(v426);
    v398 = qcar(v426);
    v426 = (Lisp_Object)17; /* 1 */
    v426 = cons(v398, v426);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    v426 = ncons(v426);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    fn = elt(env, 3); /* multf */
    v398 = (*qfn2(fn))(qenv(fn), stack[0], v426);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    v426 = stack[-4];
    v426 = CC_split_non_linear_f(env, 5, stack[-3], stack[-2], stack[-1], v398, v426);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    goto v315;

v315:
    stack[-4] = v426;
    v426 = stack[-8];
    v398 = v426;
    goto v386;

v430:
    v426 = v398;
    v426 = qcar(v426);
    stack[-2] = qcdr(v426);
    stack[-1] = stack[-7];
    stack[0] = stack[-6];
    v426 = v398;
    v426 = qcar(v426);
    v426 = qcar(v426);
    v426 = ncons(v426);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    v224 = Lappend(nil, stack[0], v426);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    v398 = stack[-5];
    v426 = stack[-4];
    v426 = CC_split_non_linear_f(env, 5, stack[-2], stack[-1], v224, v398, v426);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-9];
    goto v315;

v229:
    v426 = qvalue(elt(env, 2)); /* nil */
    goto v354;

v407:
    v426 = qvalue(elt(env, 1)); /* t */
    goto v390;
/* error exit handlers */
v427:
    popv(10);
    return nil;
}



/* Code for rl_cput */

static Lisp_Object MS_CDECL CC_rl_cput(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v14,
                         Lisp_Object v122, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v419, v55, v8, v9;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_cput");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_cput");
#endif
    if (stack >= stacklimit)
    {
        push3(v122,v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v14,v122);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v419 = v122;
    v8 = v14;
    v9 = v0;
/* end of prologue */
    v55 = v419;
    v419 = v8;
    v419 = get(v55, v419);
    v55 = v419;
    v419 = v55;
    if (v419 == nil) goto v252;
    v419 = v9;
        return Lputprop(nil, 3, v419, v8, v55);

v252:
    v419 = nil;
    return onevalue(v419);
}



/* Code for ratpoly_fromsf */

static Lisp_Object CC_ratpoly_fromsf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_fromsf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v0;
/* end of prologue */
    v7 = v60;
    v60 = (Lisp_Object)17; /* 1 */
    return cons(v7, v60);
}



/* Code for simppsexplim */

static Lisp_Object CC_simppsexplim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v411, v357;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simppsexplim");
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
    v357 = v0;
/* end of prologue */
    v411 = qvalue(elt(env, 1)); /* ps!:exp!-lim */
    stack[0] = v411;
    v411 = v357;
    if (v411 == nil) goto v311;
    v411 = elt(env, 2); /* psexplim */
    fn = elt(env, 5); /* carx */
    v411 = (*qfn2(fn))(qenv(fn), v357, v411);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    fn = elt(env, 6); /* reval */
    v411 = (*qfn1(fn))(qenv(fn), v411);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v357 = v411;
    v411 = v357;
    v411 = integerp(v411);
    if (v411 == nil) goto v13;
    v411 = v357;
    goto v2;

v2:
    qvalue(elt(env, 1)) = v411; /* ps!:exp!-lim */
    goto v311;

v311:
    v357 = stack[0];
    v411 = (Lisp_Object)1; /* 0 */
    if (v357 == v411) goto v359;
    v357 = stack[0];
    v411 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v357, v411);

v359:
    v357 = qvalue(elt(env, 4)); /* nil */
    v411 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v357, v411);

v13:
    v411 = elt(env, 3); /* "integer" */
    fn = elt(env, 7); /* typerr */
    v411 = (*qfn2(fn))(qenv(fn), v357, v411);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    goto v2;
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for subeval0 */

static Lisp_Object CC_subeval0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v446, v447, v323, v324, v322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval0");
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
    stack[-2] = nil;
    stack[-1] = nil;
    goto v60;

v60:
    v446 = stack[-4];
    v446 = qcdr(v446);
    if (v446 == nil) goto v386;
    v446 = stack[-4];
    v447 = qcar(v446);
    v446 = elt(env, 2); /* equal */
    if (!consp(v447)) goto v9;
    v447 = qcar(v447);
    if (!(v447 == v446)) goto v9;
    v446 = stack[-4];
    v446 = qcar(v446);
    v446 = qcdr(v446);
    stack[0] = qcar(v446);
    v446 = stack[-4];
    v446 = qcar(v446);
    v446 = qcdr(v446);
    v446 = qcdr(v446);
    v446 = qcar(v446);
    fn = elt(env, 13); /* reval */
    v446 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-3] = v446;
    if (equal(stack[0], v446)) goto v390;
    v446 = stack[-4];
    v446 = qcar(v446);
    v323 = qcar(v446);
    v446 = stack[-4];
    v446 = qcar(v446);
    v446 = qcdr(v446);
    v447 = qcar(v446);
    v446 = stack[-3];
    v447 = list3(v323, v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v446 = stack[-5];
    v446 = cons(v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-5] = v446;
    goto v390;

v390:
    v446 = stack[-4];
    v446 = qcdr(v446);
    stack[-4] = v446;
    goto v60;

v9:
    v446 = stack[-4];
    v447 = qcar(v446);
    v446 = stack[-5];
    v446 = cons(v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-5] = v446;
    goto v390;

v386:
    v446 = stack[-5];
    if (v446 == nil) goto v313;
    v447 = stack[-5];
    v446 = stack[-4];
    fn = elt(env, 14); /* reversip2 */
    v446 = (*qfn2(fn))(qenv(fn), v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-4] = v446;
    v447 = stack[-4];
    v446 = qvalue(elt(env, 3)); /* sublist!* */
    v446 = Lmember(nil, v447, v446);
    if (v446 == nil) goto v248;
    v447 = elt(env, 4); /* sub */
    v446 = stack[-4];
    v446 = cons(v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    fn = elt(env, 15); /* fkern */
    v447 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v446 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* getpower */
    v447 = (*qfn2(fn))(qenv(fn), v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v446 = (Lisp_Object)17; /* 1 */
    v446 = cons(v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v447 = ncons(v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v446 = (Lisp_Object)17; /* 1 */
    v446 = cons(v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 17); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v446);
    }

v248:
    v447 = stack[-4];
    v446 = qvalue(elt(env, 3)); /* sublist!* */
    v446 = cons(v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    qvalue(elt(env, 3)) = v446; /* sublist!* */
    v446 = stack[-4];
    if (v446 == nil) goto v350;
    v446 = stack[-4];
    v446 = qcdr(v446);
    if (!(v446 == nil)) goto v349;

v350:
    v446 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v446 == nil)) goto v401;
    v446 = elt(env, 6); /* "SUB requires at least 2 arguments" */
    fn = elt(env, 18); /* lprie */
    v446 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    goto v401;

v401:
    v446 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    goto v349;

v349:
    v446 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 7)); /* !*evallhseqp */
    qvalue(elt(env, 7)) = v446; /* !*evallhseqp */
    goto v19;

v19:
    v446 = stack[-4];
    v446 = qcdr(v446);
    if (v446 == nil) goto v35;
    v446 = stack[-4];
    v446 = qcar(v446);
    fn = elt(env, 13); /* reval */
    v446 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    stack[-5] = v446;
    v446 = stack[-5];
    fn = elt(env, 19); /* getrtype */
    v447 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    v446 = elt(env, 8); /* list */
    if (v447 == v446) goto v22;
    v446 = stack[-5];
    if (!consp(v446)) goto v449;
    v446 = stack[-5];
    v447 = qcar(v446);
    v446 = elt(env, 9); /* equalopr */
    v446 = Lflagp(nil, v447, v446);
    env = stack[-6];
    if (v446 == nil) goto v80;
    v446 = stack[-5];
    v446 = qcdr(v446);
    v446 = qcdr(v446);
    if (v446 == nil) goto v450;
    v446 = stack[-5];
    v446 = qcdr(v446);
    v446 = qcdr(v446);
    v446 = qcdr(v446);
    v446 = (v446 == nil ? lisp_true : nil);
    goto v451;

v451:
    if (!(v446 == nil)) goto v83;
    v322 = elt(env, 10); /* "Syntax error:" */
    v446 = stack[-4];
    v324 = qcar(v446);
    v323 = elt(env, 11); /* "invalid" */
    v447 = qvalue(elt(env, 1)); /* nil */
    v446 = qvalue(elt(env, 12)); /* t */
    fn = elt(env, 20); /* msgpri */
    v446 = (*qfnn(fn))(qenv(fn), 5, v322, v324, v323, v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    goto v83;

v83:
    v446 = stack[-5];
    v446 = qcdr(v446);
    v446 = qcar(v446);
    stack[-3] = v446;
    v446 = stack[-3];
    fn = elt(env, 19); /* getrtype */
    v446 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    if (!(v446 == nil)) goto v452;
    v446 = stack[-3];
    fn = elt(env, 21); /* !*a2kwoweight */
    v446 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    stack[-3] = v446;
    goto v452;

v452:
    v446 = stack[-5];
    v446 = qcdr(v446);
    v446 = qcdr(v446);
    v446 = qcar(v446);
    fn = elt(env, 19); /* getrtype */
    v446 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    if (v446 == nil) goto v214;
    v323 = stack[-3];
    v446 = stack[-5];
    v446 = qcdr(v446);
    v446 = qcdr(v446);
    v447 = qcar(v446);
    v446 = stack[-1];
    v446 = acons(v323, v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    stack[-1] = v446;
    goto v453;

v453:
    v446 = stack[-4];
    v446 = qcdr(v446);
    stack[-4] = v446;
    goto v19;

v214:
    v323 = stack[-3];
    v446 = stack[-5];
    v446 = qcdr(v446);
    v446 = qcdr(v446);
    v447 = qcar(v446);
    v446 = stack[-2];
    v446 = acons(v323, v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    stack[-2] = v446;
    goto v453;

v450:
    v446 = qvalue(elt(env, 1)); /* nil */
    goto v451;

v80:
    v446 = qvalue(elt(env, 1)); /* nil */
    goto v451;

v449:
    v446 = qvalue(elt(env, 1)); /* nil */
    goto v451;

v22:
    v446 = stack[-5];
    v447 = qcdr(v446);
    v446 = stack[-4];
    v446 = qcdr(v446);
    v446 = Lappend(nil, v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v448;
    env = stack[-6];
    stack[-4] = v446;
    goto v19;

v35:
    qvalue(elt(env, 7)) = stack[0]; /* !*evallhseqp */
    v446 = stack[-4];
    v446 = qcar(v446);
    fn = elt(env, 22); /* aeval */
    v446 = (*qfn1(fn))(qenv(fn), v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    stack[-5] = v446;
    v447 = stack[-1];
    v446 = stack[-2];
    v447 = Lappend(nil, v447, v446);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-6];
    v446 = stack[-5];
    {
        popv(7);
        fn = elt(env, 23); /* subeval1 */
        return (*qfn2(fn))(qenv(fn), v447, v446);
    }

v313:
    v446 = stack[-4];
    v446 = qcar(v446);
    { popv(7); return onevalue(v446); }
/* error exit handlers */
v448:
    env = stack[-6];
    qvalue(elt(env, 7)) = stack[0]; /* !*evallhseqp */
    popv(7);
    return nil;
v209:
    popv(7);
    return nil;
}



/* Code for edsorlist */

static Lisp_Object CC_edsorlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v5;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edsorlist");
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
    v5 = v0;
/* end of prologue */
    v4 = v5;
    if (v4 == nil) goto v390;
    v4 = v5;
    v4 = qcar(v4);
    fn = elt(env, 3); /* getrtype */
    v5 = (*qfn1(fn))(qenv(fn), v4);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[0];
    v4 = elt(env, 1); /* eds */
    if (!(v5 == v4)) goto v390;
    v4 = elt(env, 1); /* eds */
    { popv(1); return onevalue(v4); }

v390:
    v4 = elt(env, 2); /* list */
    { popv(1); return onevalue(v4); }
/* error exit handlers */
v1:
    popv(1);
    return nil;
}



/* Code for addm1 */

static Lisp_Object MS_CDECL CC_addm1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v14,
                         Lisp_Object v122, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v402, v315, v313;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addm1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addm1");
#endif
    if (stack >= stacklimit)
    {
        push3(v122,v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v14,v122);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v122;
    stack[-1] = v14;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v103;

v103:
    v402 = stack[-2];
    if (v402 == nil) goto v235;
    v402 = qvalue(elt(env, 1)); /* nil */
    goto v236;

v236:
    if (v402 == nil) goto v7;
    v402 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v402);
    }

v7:
    v402 = stack[-2];
    if (v402 == nil) goto v399;
    v402 = stack[-1];
    v402 = (v402 == nil ? lisp_true : nil);
    goto v408;

v408:
    if (v402 == nil) goto v312;
    stack[0] = stack[-3];
    v402 = elt(env, 3); /* "Matrix mismatch" */
    v315 = v402;
    v402 = v315;
    qvalue(elt(env, 4)) = v402; /* errmsg!* */
    v402 = qvalue(elt(env, 5)); /* !*protfg */
    if (!(v402 == nil)) goto v378;
    v402 = v315;
    fn = elt(env, 7); /* lprie */
    v402 = (*qfn1(fn))(qenv(fn), v402);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-4];
    goto v378;

v378:
    v402 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-4];
    v402 = nil;
    {
        Lisp_Object v68 = stack[0];
        popv(5);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v68, v402);
    }

v312:
    v313 = stack[0];
    v402 = stack[-2];
    v315 = qcar(v402);
    v402 = stack[-1];
    v402 = qcar(v402);
    v315 = Lapply2(nil, 3, v313, v315, v402);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-4];
    v402 = stack[-3];
    v402 = cons(v315, v402);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-4];
    stack[-3] = v402;
    v402 = stack[-2];
    v402 = qcdr(v402);
    stack[-2] = v402;
    v402 = stack[-1];
    v402 = qcdr(v402);
    stack[-1] = v402;
    goto v103;

v399:
    v402 = qvalue(elt(env, 2)); /* t */
    goto v408;

v235:
    v402 = stack[-1];
    v402 = (v402 == nil ? lisp_true : nil);
    goto v236;
/* error exit handlers */
v247:
    popv(5);
    return nil;
}



/* Code for rep_edge_prop_ */

static Lisp_Object CC_rep_edge_prop_(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rep_edge_prop_");
#endif
    if (stack >= stacklimit)
    {
        push2(v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v14;
    stack[-1] = v0;
/* end of prologue */

v202:
    v2 = stack[-1];
    if (v2 == nil) goto v112;
    v2 = stack[-1];
    v3 = qcar(v2);
    v2 = stack[0];
    v2 = Lrplacd(nil, v3, v2);
    nil = C_nil;
    if (exception_pending()) goto v419;
    env = stack[-2];
    v2 = stack[-1];
    v2 = qcdr(v2);
    stack[-1] = v2;
    goto v202;

v112:
    v2 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v2); }
/* error exit handlers */
v419:
    popv(3);
    return nil;
}



/* Code for mod!* */

static Lisp_Object CC_modH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v14)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v238, v418;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod*");
#endif
    if (stack >= stacklimit)
    {
        push2(v14,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v14);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v14;
    stack[-1] = v0;
/* end of prologue */
    v238 = stack[0];
    fn = elt(env, 2); /* dpmat_coldegs */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-3];
    stack[-2] = qvalue(elt(env, 1)); /* cali!=degrees */
    qvalue(elt(env, 1)) = v238; /* cali!=degrees */
    v238 = stack[-1];
    fn = elt(env, 3); /* dp_neworder */
    v238 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v362;
    env = stack[-3];
    stack[-1] = v238;
    v238 = stack[0];
    fn = elt(env, 4); /* dpmat_list */
    stack[0] = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v362;
    env = stack[-3];
    v418 = (Lisp_Object)1; /* 0 */
    v238 = stack[-1];
    fn = elt(env, 5); /* bas_make */
    v238 = (*qfn2(fn))(qenv(fn), v418, v238);
    nil = C_nil;
    if (exception_pending()) goto v362;
    env = stack[-3];
    fn = elt(env, 6); /* red_redpol */
    v238 = (*qfn2(fn))(qenv(fn), stack[0], v238);
    nil = C_nil;
    if (exception_pending()) goto v362;
    env = stack[-3];
    stack[0] = v238;
    v238 = stack[0];
    v238 = qcar(v238);
    fn = elt(env, 7); /* bas_dpoly */
    v418 = (*qfn1(fn))(qenv(fn), v238);
    nil = C_nil;
    if (exception_pending()) goto v362;
    env = stack[-3];
    v238 = stack[0];
    v238 = qcdr(v238);
    v238 = cons(v418, v238);
    nil = C_nil;
    if (exception_pending()) goto v362;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* cali!=degrees */
    { popv(4); return onevalue(v238); }
/* error exit handlers */
v362:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* cali!=degrees */
    popv(4);
    return nil;
v239:
    popv(4);
    return nil;
}



/* Code for sep_tens_from_other */

static Lisp_Object CC_sep_tens_from_other(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v257;
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
    v224 = (Lisp_Object)17; /* 1 */
    v224 = (Lisp_Object)zerop(v224);
    v224 = v224 ? lisp_true : nil;
    env = stack[-5];
    if (v224 == nil) goto v252;
    v224 = qvalue(elt(env, 1)); /* nil */
    goto v60;

v60:
    stack[-2] = v224;
    goto v112;

v112:
    v224 = stack[-3];
    if (is_number(v224)) goto v2;
    v224 = stack[-3];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v224 = qcar(v224);
    if (!consp(v224)) goto v59;
    v224 = stack[-3];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v224 = qcar(v224);
    v257 = qcar(v224);
    v224 = elt(env, 2); /* translate1 */
    v224 = get(v257, v224);
    env = stack[-5];
    stack[-1] = v224;
    if (v224 == nil) goto v29;
    v224 = stack[-3];
    fn = elt(env, 4); /* fullcopy */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    stack[-3] = v224;
    v224 = stack[-3];
    v224 = qcar(v224);
    stack[0] = qcar(v224);
    v257 = stack[-1];
    v224 = stack[-3];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v224 = qcar(v224);
    v224 = Lapply1(nil, v257, v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    fn = elt(env, 5); /* setcar */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    goto v29;

v29:
    v224 = stack[-3];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v224 = qcar(v224);
    stack[0] = v224;
    fn = elt(env, 6); /* tensorp */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    if (v224 == nil) goto v38;
    v224 = stack[0];
    fn = elt(env, 7); /* no_dum_varp */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    if (v224 == nil) goto v47;
    v224 = stack[0];
    v224 = qcar(v224);
    if (!symbolp(v224)) v224 = nil;
    else { v224 = qfastgets(v224);
           if (v224 != nil) { v224 = elt(v224, 0); /* noncom */
#ifdef RECORD_GET
             if (v224 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v224 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v224 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v224 == SPID_NOPROP) v224 = nil; else v224 = lisp_true; }}
#endif
    goto v46;

v46:
    if (v224 == nil) goto v232;
    v224 = stack[-3];
    v224 = qcar(v224);
    v224 = qcar(v224);
    v257 = qcar(v224);
    v224 = stack[-4];
    v224 = cons(v257, v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    stack[-4] = v224;
    goto v407;

v407:
    v224 = stack[-3];
    v224 = qcar(v224);
    v224 = qcdr(v224);
    stack[-3] = v224;
    goto v112;

v232:
    stack[0] = stack[-2];
    v224 = stack[-3];
    v224 = qcar(v224);
    v257 = qcar(v224);
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v257, v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v224 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    fn = elt(env, 8); /* multf */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    stack[-2] = v224;
    goto v407;

v47:
    v224 = qvalue(elt(env, 3)); /* t */
    goto v46;

v38:
    stack[0] = stack[-2];
    v224 = stack[-3];
    v224 = qcar(v224);
    v257 = qcar(v224);
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v257, v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v224 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    fn = elt(env, 8); /* multf */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    stack[-2] = v224;
    goto v407;

v59:
    stack[0] = stack[-2];
    v224 = stack[-3];
    v224 = qcar(v224);
    v257 = qcar(v224);
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v257, v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    v224 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    fn = elt(env, 8); /* multf */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    env = stack[-5];
    stack[-2] = v224;
    goto v407;

v2:
    v224 = stack[-4];
    stack[0] = Lnreverse(nil, v224);
    env = stack[-5];
    v257 = stack[-2];
    v224 = stack[-3];
    v224 = (Lisp_Object)zerop(v224);
    v224 = v224 ? lisp_true : nil;
    env = stack[-5];
    if (v224 == nil) goto v397;
    v224 = qvalue(elt(env, 1)); /* nil */
    goto v13;

v13:
    fn = elt(env, 8); /* multf */
    v224 = (*qfn2(fn))(qenv(fn), v257, v224);
    nil = C_nil;
    if (exception_pending()) goto v456;
    {
        Lisp_Object v22 = stack[0];
        popv(6);
        return list2(v22, v224);
    }

v397:
    v224 = stack[-3];
    goto v13;

v252:
    v224 = (Lisp_Object)17; /* 1 */
    goto v60;
/* error exit handlers */
v456:
    popv(6);
    return nil;
}



/* Code for poly!-to!-vector */

static Lisp_Object CC_polyKtoKvector(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v379, v416, v400, v359;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for poly-to-vector");
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
    v400 = v0;
/* end of prologue */

v11:
    v379 = v400;
    if (!consp(v379)) goto v7;
    v379 = v400;
    v379 = qcar(v379);
    v379 = (consp(v379) ? nil : lisp_true);
    goto v60;

v60:
    if (v379 == nil) goto v10;
    stack[-1] = qvalue(elt(env, 2)); /* poly!-vector */
    stack[0] = (Lisp_Object)1; /* 0 */
    v379 = v400;
    fn = elt(env, 3); /* !*d2n */
    v379 = (*qfn1(fn))(qenv(fn), v379);
    nil = C_nil;
    if (exception_pending()) goto v59;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v379;
    { popv(2); return onevalue(v379); }

v10:
    v359 = qvalue(elt(env, 2)); /* poly!-vector */
    v379 = v400;
    v379 = qcar(v379);
    v379 = qcar(v379);
    v416 = qcdr(v379);
    v379 = v400;
    v379 = qcar(v379);
    v379 = qcdr(v379);
    *(Lisp_Object *)((char *)v359 + (CELL-TAG_VECTOR) + ((int32_t)v416/(16/CELL))) = v379;
    v379 = v400;
    v379 = qcdr(v379);
    v400 = v379;
    goto v11;

v7:
    v379 = qvalue(elt(env, 1)); /* t */
    goto v60;
/* error exit handlers */
v59:
    popv(2);
    return nil;
}



setup_type const u57_setup[] =
{
    {"install-patches",         CC_installKpatches,too_many_1, wrong_no_1},
    {"rd:quotient",             too_few_2,      CC_rdTquotient,wrong_no_2},
    {"partitindexvar",          CC_partitindexvar,too_many_1,  wrong_no_1},
    {"mult_derivs",             too_few_2,      CC_mult_derivs,wrong_no_2},
    {"simpdfp",                 CC_simpdfp,     too_many_1,    wrong_no_1},
    {"grk",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_grk},
    {"ofsf_smmkatl-and1",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKand1},
    {"mk_character",            CC_mk_character,too_many_1,    wrong_no_1},
    {"cl_sacatlp",              too_few_2,      CC_cl_sacatlp, wrong_no_2},
    {"bc_pmon",                 too_few_2,      CC_bc_pmon,    wrong_no_2},
    {"tryfactorf",              too_few_2,      CC_tryfactorf, wrong_no_2},
    {"svec",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_svec},
    {"random_minus",            CC_random_minus,too_many_1,    wrong_no_1},
    {"exformp",                 CC_exformp,     too_many_1,    wrong_no_1},
    {"tcar",                    CC_tcar,        too_many_1,    wrong_no_1},
    {"getlower",                CC_getlower,    too_many_1,    wrong_no_1},
    {"mk_edge_name",            too_few_2,      CC_mk_edge_name,wrong_no_2},
    {"select_epsi_pairs",       CC_select_epsi_pairs,too_many_1,wrong_no_1},
    {"pe_inv",                  CC_pe_inv,      too_many_1,    wrong_no_1},
    {"nordp",                   too_few_2,      CC_nordp,      wrong_no_2},
    {"i_solve-eval",            CC_i_solveKeval,too_many_1,    wrong_no_1},
    {"general-monic-mod-p",     CC_generalKmonicKmodKp,too_many_1,wrong_no_1},
    {"split_non_linear_f",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_split_non_linear_f},
    {"rl_cput",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_cput},
    {"ratpoly_fromsf",          CC_ratpoly_fromsf,too_many_1,  wrong_no_1},
    {"simppsexplim",            CC_simppsexplim,too_many_1,    wrong_no_1},
    {"subeval0",                CC_subeval0,    too_many_1,    wrong_no_1},
    {"edsorlist",               CC_edsorlist,   too_many_1,    wrong_no_1},
    {"addm1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_addm1},
    {"rep_edge_prop_",          too_few_2,      CC_rep_edge_prop_,wrong_no_2},
    {"mod*",                    too_few_2,      CC_modH,       wrong_no_2},
    {"sep_tens_from_other",     CC_sep_tens_from_other,too_many_1,wrong_no_1},
    {"poly-to-vector",          CC_polyKtoKvector,too_many_1,  wrong_no_1},
    {NULL, (one_args *)"u57", (two_args *)"12019 1494157 3073430", 0}
};

/* end of generated code */
